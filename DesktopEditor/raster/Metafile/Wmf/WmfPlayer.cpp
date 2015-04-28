#include "WmfPlayer.h"
#include "WmfFile.h"

namespace MetaFile
{
	CWmfPlayer::CWmfPlayer(CWmfFile* pFile) : m_pFile(pFile)
	{
		CWmfDC* pDC = new CWmfDC();
		if (!pDC)
		{
#ifdef NEW_WMF
			pFile->SetError();
#endif
			return;
		}

		m_pDC = pDC;
		m_vDCStack.push_back(pDC);
		m_ushIndex = 0;
	};
	CWmfPlayer::~CWmfPlayer()
	{
		for (int nIndex = 0; nIndex < m_vDCStack.size(); nIndex++)
		{
			CWmfDC* pDC = m_vDCStack.at(nIndex);
			delete pDC;
		}
		m_vDCStack.clear();

		for (CWmfObjectMap::iterator oIterator = m_mObjects.begin(); oIterator != m_mObjects.end(); oIterator++)
		{
			CWmfObjectBase* pOldObject = oIterator->second;
			delete pOldObject;
		}
		m_mObjects.clear();
	}
	void    CWmfPlayer::Clear()
	{
		for (int nIndex = 0; nIndex < m_vDCStack.size(); nIndex++)
		{
			CWmfDC* pDC = m_vDCStack.at(nIndex);
			delete pDC;
		}
		m_vDCStack.clear();

		for (CWmfObjectMap::iterator oIterator = m_mObjects.begin(); oIterator != m_mObjects.end(); oIterator++)
		{
			CWmfObjectBase* pOldObject = oIterator->second;
			delete pOldObject;
		}
		m_mObjects.clear();

		CWmfDC* pDC = new CWmfDC();
		if (!pDC)
		{
#ifdef NEW_WMF
			m_pFile->SetError();
#endif
			return;
		}

		m_pDC = pDC;
		m_vDCStack.push_back(pDC);
		m_ushIndex = 0;
		m_vAvailableIndexes.clear();
	}
	CWmfDC* CWmfPlayer::SaveDC()
	{
		if (!m_pDC)
		{
#ifdef NEW_WMF
			m_pFile->SetError();
#endif
			return NULL;
		}

		CWmfDC* pNewDC = m_pDC->Copy();
		if (!pNewDC)
		{
#ifdef NEW_WMF
			m_pFile->SetError();
#endif
			return NULL;
		}

		m_vDCStack.push_back(pNewDC);
		m_pDC = pNewDC;
		return pNewDC;
	}
	CWmfDC* CWmfPlayer::RestoreDC()
	{
		if (m_vDCStack.size() <= 1)
		{
#ifdef NEW_WMF
			m_pFile->SetError();
#endif
			return m_pDC;
		}

		CWmfDC* pDC = m_vDCStack.at(m_vDCStack.size() - 1);
		m_vDCStack.pop_back();
		delete pDC;

		pDC = m_vDCStack.at(m_vDCStack.size() - 1);
		m_pDC = pDC;
		return m_pDC;
	}
	CWmfDC* CWmfPlayer::GetDC()
	{
		return m_pDC;
	}
	void    CWmfPlayer::RegisterObject(CWmfObjectBase* pObject)
	{
		// ������ ���������� ��������� ������
		unsigned short ushIndex = m_ushIndex;
		int nAvailableIndex = -1;
		if (m_vAvailableIndexes.size() > 0)
		{
			for (std::size_t nIterator = 0; nIterator != m_vAvailableIndexes.size(); ++nIterator)
			{
				if (ushIndex > m_vAvailableIndexes[nIterator])
				{
					ushIndex = m_vAvailableIndexes[nIterator];
					nAvailableIndex = (int)nIterator;
				}
			}
		}

		CWmfObjectMap::const_iterator oPos = m_mObjects.find(ushIndex);
		if (m_mObjects.end() != oPos)
		{
			CWmfObjectBase* pOldObject = oPos->second;
			delete pOldObject;
			m_mObjects.erase(ushIndex);
		}

		m_mObjects.insert(std::pair<unsigned int, CWmfObjectBase*>(ushIndex, pObject));

		if (-1 != nAvailableIndex)
			m_vAvailableIndexes.erase(m_vAvailableIndexes.begin() + nAvailableIndex);

		if (ushIndex == m_ushIndex)
			m_ushIndex++;
	}
	void    CWmfPlayer::SelectObject(unsigned short ushIndex)
	{
		CWmfObjectMap::const_iterator oPos = m_mObjects.find(ushIndex);
		if (m_mObjects.end() != oPos)
		{
			CWmfObjectBase* pObject = oPos->second;

			switch (pObject->GetType())
			{
			case WMF_OBJECT_BRUSH: m_pDC->SetBrush((CWmfBrush*)pObject); break;
			case WMF_OBJECT_FONT: m_pDC->SetFont((CWmfFont*)pObject); break;
			case WMF_OBJECT_PEN: m_pDC->SetPen((CWmfPen*)pObject); break;
			case WMF_OBJECT_PALETTE: m_pDC->SetPalette((CWmfPalette*)pObject); break;
			case WMF_OBJECT_REGION: m_pDC->SetRegion((CWmfRegion*)pObject); break;
			}
		}
	}
	void    CWmfPlayer::SelectPalette(unsigned short ushIndex)
	{
		CWmfObjectMap::const_iterator oPos = m_mObjects.find(ushIndex);
		if (m_mObjects.end() != oPos)
		{
			CWmfObjectBase* pObject = oPos->second;
			if (WMF_OBJECT_PALETTE == pObject->GetType())
				m_pDC->SetPalette((CWmfPalette*)pObject);
		}
	}
	void    CWmfPlayer::DeleteObject(unsigned short ushIndex)
	{
		CWmfObjectMap::const_iterator oPos = m_mObjects.find(ushIndex);
		if (m_mObjects.end() != oPos)
		{
			CWmfObjectBase* pObject = oPos->second;

			for (int nIndex = 0; nIndex < m_vDCStack.size(); nIndex++)
			{
				CWmfDC* pDC = m_vDCStack.at(nIndex);

				switch (pObject->GetType())
				{
				case WMF_OBJECT_BRUSH: pDC->RemoveBrush((CWmfBrush*)pObject); break;
				case WMF_OBJECT_FONT: pDC->RemoveFont((CWmfFont*)pObject); break;
				case WMF_OBJECT_PEN: pDC->RemovePen((CWmfPen*)pObject); break;
				case WMF_OBJECT_PALETTE: pDC->RemovePalette((CWmfPalette*)pObject); break;
				case WMF_OBJECT_REGION: pDC->RemoveRegion((CWmfRegion*)pObject); break;
				}
			}

			delete pObject;
			m_mObjects.erase(ushIndex);
		}
	}

	CWmfDC::CWmfDC()
	{				   
		m_pBrush       = &m_oDefaultBrush;
		m_pPen         = &m_oDefaultPen;
		m_pPalette     = NULL;
		m_pFont        = NULL;
		m_pRegion      = NULL;
		m_ushMapMode   = MM_TEXT;
		m_dPixelWidth  = 1;
		m_dPixelHeight = 1;
		m_oWindow.Init();
		m_oViewport.Init();
	}
	CWmfDC::~CWmfDC()
	{

	}
	CWmfDC*        CWmfDC::Copy()
	{
		CWmfDC* pNewDC = new CWmfDC();
		if (!pNewDC)
			return NULL;

		pNewDC->m_pBrush       = (m_pBrush == &m_oDefaultBrush ? &pNewDC->m_oDefaultBrush : m_pBrush);
		pNewDC->m_pPen         = (m_pPen == &m_oDefaultPen ? &pNewDC->m_oDefaultPen : m_pPen);
		pNewDC->m_pPalette     = m_pPalette;
		pNewDC->m_pFont        = m_pFont;
		pNewDC->m_pRegion      = m_pRegion;
		pNewDC->m_ushMapMode   = m_ushMapMode;
		pNewDC->m_dPixelWidth  = m_dPixelWidth;
		pNewDC->m_dPixelHeight = m_dPixelHeight;
		pNewDC->m_oWindow.Copy(m_oWindow);
		pNewDC->m_oViewport.Copy(m_oViewport);

		return pNewDC;
	}
	void           CWmfDC::SetBrush(CWmfBrush* pBrush)
	{
		m_pBrush = pBrush;
	}
	void           CWmfDC::RemoveBrush(CWmfBrush* pBrush)
	{
		if (pBrush == m_pBrush)
			m_pBrush = NULL;
	}
	CWmfBrush*     CWmfDC::GetBrush()
	{
		return m_pBrush;
	}
	void           CWmfDC::SetPen(CWmfPen* pPen)
	{
		m_pPen = pPen;
	}
	void           CWmfDC::RemovePen(CWmfPen* pPen)
	{
		if (m_pPen == pPen)
			m_pPen = NULL;
	}
	CWmfPen*       CWmfDC::GetPen()
	{
		return m_pPen;
	}
	void           CWmfDC::SetPalette(CWmfPalette* pPalette)
	{
		m_pPalette = pPalette;
	}
	void           CWmfDC::RemovePalette(CWmfPalette* pPalette)
	{
		if (m_pPalette == pPalette)
			m_pPalette = NULL;
	}
	CWmfPalette*   CWmfDC::GetPalette()
	{
		return m_pPalette;
	}
	void           CWmfDC::SetFont(CWmfFont* pFont)
	{
		m_pFont = pFont;
	}
	void           CWmfDC::RemoveFont(CWmfFont* pFont)
	{
		if (m_pFont == pFont)
			m_pFont = NULL;
	}
	CWmfFont*      CWmfDC::GetFont()
	{
		return m_pFont;
	}
	void           CWmfDC::SetRegion(CWmfRegion* pRegion)
	{
		m_pRegion = pRegion;
	}
	void           CWmfDC::RemoveRegion(CWmfRegion* pRegion)
	{
		if (m_pRegion == pRegion)
			m_pRegion = NULL;
	}
	CWmfRegion*    CWmfDC::GetRegion()
	{
		return m_pRegion;
	}
	void           CWmfDC::SetMapMode(unsigned short ushMapMode)
	{
		m_ushMapMode = ushMapMode;

		switch (m_ushMapMode)
		{
		case MM_TEXT: // 1 unit = 1pt
		{
			SetPixelWidth(1);
			SetPixelHeight(1);
			break;
		}
		case MM_LOMETRIC: // 1 unit = 0.1mm
		{
			double dPixel = 0.1 * 72 / 25.4;
			SetPixelWidth(dPixel);
			SetPixelHeight(dPixel);
			break;
		}
		case MM_HIMETRIC: // 1 unit = 0.01mm
		{
			double dPixel = 0.01 * 72 / 25.4;
			SetPixelWidth(dPixel);
			SetPixelHeight(dPixel);
			break;
		}
		case MM_LOENGLISH: // 1 unit = 0.01 inch
		{
			double dPixel = 0.01 * 72;
			SetPixelWidth(dPixel);
			SetPixelHeight(dPixel);
			break;
		}
		case MM_HIENGLISH: // 1 unit = 0.001 inch
		{
			double dPixel = 0.001 * 72;
			SetPixelWidth(dPixel);
			SetPixelHeight(dPixel);
			break;
		}
		case MM_TWIPS: // 1 unit = 1/1440 inch
		{
			SetPixelWidth(0.05);
			SetPixelHeight(0.05);
			break;
		}
		case MM_ISOTROPIC:
		case MM_ANISOTROPIC:
		{
			UpdatePixelMetrics();
			break;
		}
		}
	}
	unsigned int   CWmfDC::GetMapMode()
	{
		return m_ushMapMode;
	}
	double         CWmfDC::GetPixelWidth()
	{
		return m_dPixelWidth;
	}
	double         CWmfDC::GetPixelHeight()
	{
		return m_dPixelHeight;
	}
	void           CWmfDC::SetPixelWidth(double dW)
	{
		m_dPixelWidth = dW;
	}
	void           CWmfDC::SetPixelHeight(double dH)
	{
		m_dPixelHeight = dH;
	}
	TWmfWindow*    CWmfDC::GetWindow()
	{
		return &m_oWindow;
	}
	void           CWmfDC::SetWindowOrg(short shX, short shY)
	{
		m_oWindow.x = shX;
		m_oWindow.y = shY;
		UpdatePixelMetrics();
	}
	void           CWmfDC::SetWindowExt(short shW, short shH)
	{
		m_oWindow.w = shW;
		m_oWindow.h = shH;
		UpdatePixelMetrics();
	}
	void           CWmfDC::SetWindowOff(short shX, short shY)
	{
		m_oWindow.x += shX;
		m_oWindow.y += shY;
		UpdatePixelMetrics();
	}
	void           CWmfDC::SetWindowScale(double dX, double dY)
	{
		m_oWindow.w = (short)(m_oWindow.w * dX);
		m_oWindow.h = (short)(m_oWindow.h * dY);
		UpdatePixelMetrics();
	}
	TWmfWindow*    CWmfDC::GetViewport()
	{
		return &m_oViewport;
	}
	void           CWmfDC::SetViewportOrg(short shX, short shY)
	{
		m_oViewport.x = shX;
		m_oViewport.y = shY;
		UpdatePixelMetrics();
	}
	void           CWmfDC::SetViewportExt(short shW, short shH)
	{
		m_oViewport.w = shW;
		m_oViewport.h = shH;
		UpdatePixelMetrics();
	}
	void           CWmfDC::SetViewportOff(short shX, short shY)
	{
		m_oViewport.x += shX;
		m_oViewport.y += shY;
		UpdatePixelMetrics();
	}
	void           CWmfDC::SetViewportScale(double dX, double dY)
	{
		m_oViewport.w = (short)(m_oViewport.w * dX);
		m_oViewport.h = (short)(m_oViewport.h * dY);
		UpdatePixelMetrics();
	}
	bool           CWmfDC::UpdatePixelMetrics()
	{
		unsigned short ushMapMode = m_ushMapMode;
		if (MM_ISOTROPIC == ushMapMode)
		{
			if (0 == m_oWindow.w || 0 == m_oViewport.w)
				return false;

			double dPixel = (double)m_oViewport.w / (double)m_oWindow.w;
			SetPixelHeight(dPixel);
			SetPixelWidth(dPixel);
		}
		else if (MM_ANISOTROPIC == ushMapMode)
		{
			double dPixelX = (double)m_oViewport.w / (double)m_oWindow.w;
			double dPixelY = (double)m_oViewport.h / (double)m_oWindow.h;

			SetPixelWidth(dPixelX);
			SetPixelHeight(dPixelY);
		}

		return true;
	}
	void           CWmfDC::SetTextColor(TWmfColor& oColor)
	{
		m_oTextColor = oColor;
	}
	TWmfColor&     CWmfDC::GetTextColor()
	{
		return m_oTextColor;
	}
	void           CWmfDC::SetTextBgColor(TWmfColor& oColor)
	{
		m_oTextBgColor = oColor;
	}
	TWmfColor&     CWmfDC::GetTextBgColor()
	{
		return m_oTextBgColor;
	}
	TWmfPointS&    CWmfDC::GetCurPos()
	{
		return m_oCurPos;
	}
	void           CWmfDC::SetCurPos(TWmfPointS& oPoint)
	{
		m_oCurPos = oPoint;
	}
	void           CWmfDC::SetCurPos(short shX, short shY)
	{
		m_oCurPos.x = shX;
		m_oCurPos.y = shY;
	}
	void           CWmfDC::SetTextBgMode(unsigned short ushMode)
	{
		m_ushTextBgMode = ushMode;
	}
	unsigned short CWmfDC::GetTextBgMode()
	{
		return m_ushTextBgMode;
	}
	void           CWmfDC::SetLayout(unsigned short ushLayout)
	{
		m_ushLayout = ushLayout;
	}
	unsigned short CWmfDC::GetLayout()
	{
		return m_ushLayout;
	}
	void           CWmfDC::SetPolyFillMode(unsigned short ushMode)
	{
		m_ushPolyFillMode = ushMode;
	}
	unsigned short CWmfDC::GetPolyFillMode()
	{
		return m_ushPolyFillMode;
	}
	void           CWmfDC::SetRop2Mode(unsigned short ushMode)
	{
		m_ushRop2Mode = ushMode;
	}
	unsigned short CWmfDC::GetRop2Mode()
	{
		return m_ushRop2Mode;
	}
	void           CWmfDC::SetStretchBltMode(unsigned short ushMode)
	{
		m_ushStretchBltMode = ushMode;
	}
	unsigned short CWmfDC::GetStretchBltMode()
	{
		return m_ushStretchBltMode;
	}
	void           CWmfDC::SetTextAlign(unsigned short ushTextAlign)
	{
		m_ushTextAlign = ushTextAlign;
	}
	unsigned short CWmfDC::GetTextAlign()
	{
		return m_ushTextAlign;
	}
	void           CWmfDC::SetCharSpacing(unsigned short ushCharSpacing)
	{
		m_ushCharSpacing = ushCharSpacing;
	}
	unsigned short CWmfDC::GetCharSpacing()
	{
		return m_ushCharSpacing;
	}
}