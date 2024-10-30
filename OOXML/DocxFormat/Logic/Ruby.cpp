#include "RunContent.h"
#include "Ruby.h"

#include "../../PPTXFormat/Logic/Xfrm.h"
#include "../../DocxFormat/Logic/Run.h"

namespace OOX
{
	namespace Logic
	{
        CRubyProperty::CRubyProperty() 
        {

        }   
        CRubyProperty::~CRubyProperty() 
        {

        }
        CRubyProperty::CRubyProperty(const XmlUtils::CXmlNode& oNode) 
        {
            fromXML( (XmlUtils::CXmlNode &)oNode );
        }
        CRubyProperty::CRubyProperty(const XmlUtils::CXmlLiteReader& oReader) 
        {
            fromXML( (XmlUtils::CXmlLiteReader &)oReader );
        }
        const CRubyProperty& CRubyProperty::operator =(const XmlUtils::CXmlNode& oNode)
        {
            fromXML( (XmlUtils::CXmlNode &)oNode );
            return *this;
        }
        const CRubyProperty& CRubyProperty::operator =(const XmlUtils::CXmlLiteReader& oReader)
        {
            fromXML( (XmlUtils::CXmlLiteReader &)oReader );
            return *this;
        }
        void CRubyProperty::fromXML(XmlUtils::CXmlLiteReader& oReader)
        {
            if ( oReader.IsEmptyNode() )
                return;

            int nParentDepth = oReader.GetDepth();
            while ( oReader.ReadNextSiblingNode(nParentDepth) ) 
            {
                std::wstring sName = oReader.GetName();
                if ( L"w:rubyAlign" == sName ) 
                    m_oRubyAlign = oReader;
                else if ( L"w:hps" == sName ) 
                    m_oHps = oReader;
                else if ( L"w:hpsRaise" == sName) 
                    m_oHpsRaise = oReader;
                else if ( L"w:hpsBaseText" == sName ) 
                    m_oHpsBaseText = oReader;
                else if ( L"w:lid" == sName ) 
                    m_oLid = oReader;                
            }
        }
        void CRubyProperty::fromXML(XmlUtils::CXmlNode& oNode)
        {
            if ( L"w:rubyPr" != oNode.GetName() )
                return;
            
            XmlUtils::CXmlNode oChild;

            if (oNode.GetNode( L"w:rubyAlign", oChild))
                m_oRubyAlign = oChild;
            
            if (oNode.GetNode( L"w:hps", oChild))
                m_oHps = oChild;
            
            if (oNode.GetNode( L"w:hpsRaise", oChild))
                m_oHpsRaise = oChild;
            
            if (oNode.GetNode( L"w:hpsBaseText", oChild))
                m_oHpsBaseText = oChild;
            
            if (oNode.GetNode( L"w:lid", oChild))   
                m_oLid = oChild;
        }
        void CRubyProperty::toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const
        {
            if (!pWriter) return;

            pWriter->WriteString(toXML());
        }
        std::wstring CRubyProperty::toXML() const
        {
            std::wstring sResult = L"<w:rubyPr>";

            if (m_oRubyAlign.IsInit())   {
                sResult += L"<w:rubyAlign ";
                sResult += m_oRubyAlign->ToString();
                sResult += L" />";
            }
            if (m_oHps.IsInit())         sResult += m_oHps->ValNode(L"w:hps");
            if (m_oHpsRaise.IsInit())    sResult += m_oHpsRaise->ValNode(L"w:hpsRaise");
            if (m_oHpsBaseText.IsInit()) sResult += m_oHpsBaseText->ValNode(L"w:hpsBaseText");
            if (m_oLid.IsInit())         sResult += m_oLid->ValNode(L"w:lid");

            sResult += L"</w:rubyPr>";            
            return sResult;
        }
        void CRubyProperty::Clear()
        {
            m_oRubyAlign.reset();
            m_oHps.reset();
            m_oHpsRaise.reset();
            m_oHpsBaseText.reset();
            m_oLid.reset();            
        }
        bool CRubyProperty::IsNoEmpty() 
        {
            return m_oRubyAlign.IsInit() || m_oHps.IsInit() || m_oHpsRaise.IsInit() || m_oHpsBaseText.IsInit() || m_oLid.IsInit();
        }
        const CRubyProperty CRubyProperty::Merge(const CRubyProperty& oPrev, const CRubyProperty& oCurrent)
        {
            CRubyProperty oResult;

            oResult.m_oRubyAlign = Merge(oPrev.m_oRubyAlign, oCurrent.m_oRubyAlign);
            oResult.m_oHps = Merge(oPrev.m_oHps, oCurrent.m_oHps);
            oResult.m_oHpsRaise = Merge(oPrev.m_oHpsRaise, oCurrent.m_oHpsRaise);
            oResult.m_oHpsBaseText = Merge(oPrev.m_oHpsBaseText, oCurrent.m_oHpsBaseText);
            oResult.m_oLid = Merge(oPrev.m_oLid, oCurrent.m_oLid);

            return oResult;
        }
        EElementType CRubyProperty::getType() const
        {
            return et_w_rubyPr;
        }

        //--------------------------------------------------------------------------------
		// CRuby 17.3.3.25 (Part 1)
		//--------------------------------------------------------------------------------

		CRuby::CRuby(OOX::Document *pMain) : WritingElement(pMain) {}
		CRuby::~CRuby() {}
		void CRuby::fromXML(XmlUtils::CXmlNode& oNode)
		{
			XmlUtils::CXmlNode oChild;

            if ( oNode.GetNode( L"w:rubyPr", oChild) )
                m_oRubyPr = oChild;
            
            if (oNode.GetNode( L"w:rt", oChild)) 
            {
                if ( oChild.GetNode( L"w:r", oChild) )
                    m_oRubyText = oChild;
            }
            
            if (oNode.GetNode( L"w:rubyBase", oChild))
            {
                if ( oChild.GetNode( L"w:r", oChild) )
                    m_oRubyBase = oChild;
            }
		}
		void CRuby::fromXML(XmlUtils::CXmlLiteReader& oReader)
		{
			if ( oReader.IsEmptyNode() )
                return;

            int nParentDepth = oReader.GetDepth();
            while(oReader.ReadNextSiblingNode(nParentDepth))
            {
                std::wstring sName = oReader.GetName();
                if ( L"w:rubyPr" == sName )
                {
                    m_oRubyPr = new CRubyProperty(oReader);
                }
                else if ( L"w:rt" == sName )
                {
                    oReader.ReadNextSiblingNode(oReader.GetDepth());
                    if ( L"w:r" == oReader.GetName() )
                    {
                        m_oRubyText = new CRun(WritingElement::m_pMainDocument);
                        m_oRubyText = oReader;
                    }
                }
                else if ( L"w:rubyBase" == sName )
                {
                    oReader.ReadNextSiblingNode(oReader.GetDepth());
                    if ( L"w:r" == oReader.GetName() )                    
                    {
                        m_oRubyBase = new CRun(WritingElement::m_pMainDocument);
                        m_oRubyBase = oReader;
                    }
                }
            }				
		}
        
		std::wstring CRuby::toXML() const
		{
            std::wstring sResult = _T("<w:ruby>");

            sResult += m_oRubyPr->toXML();

            sResult += _T("<w:rt>");
            sResult += m_oRubyText->toXML();
            sResult += _T("</w:rt>");

            sResult += _T("<w:rubyBase>");
            sResult += m_oRubyBase->toXML();
            sResult += _T("</w:rubyBase>");

            sResult += _T("</w:ruby>");
			return sResult;
		}
		EElementType CRuby::getType() const
		{
			return et_w_ruby;
		}
    } // namespace Logic
} // namespace OOX