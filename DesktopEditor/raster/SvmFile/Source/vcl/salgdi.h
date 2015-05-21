/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: salgdi.h,v $
 * $Revision: 1.30.20.5 $
 *
 * This file is part of OpenOffice.org.
 *
 * OpenOffice.org is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3
 * only, as published by the Free Software Foundation.
 *
 * OpenOffice.org is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3 along with OpenOffice.org.  If not, see
 * <http://www.openoffice.org/license.html>
 * for a copy of the LGPLv3 License.
 *
 ************************************************************************/

#ifndef _SV_SALGDI_H
#define _SV_SALGDI_H
#ifdef AVS
#include <vcl/sv.h>
#include <vcl/sallayout.hxx>
#include <vcl/salgdi.hxx>
#include <vcl/outfont.hxx>
#include <vcl/impfont.hxx>

#include "boost/scoped_ptr.hpp"
#include <hash_set>
#endif
#include "../vcl/salgdi.hxx"
#include "../vcl/outfont.hxx"
#include "../vcl/impfont.hxx"
#include "../vcl/sallayout.hxx"
#include "../vcl/salgtype.hxx"

#include <windows.h>

#include "../ASC/WinDefines.h"

#ifdef AVS
class ImplFontSelectData;
#endif
class ImplWinFontEntry;
#ifdef AVS
class ImplFontAttrCache;
#endif
// -----------
// - Defines -
// -----------

#define RGB_TO_PALRGB(nRGB) 		((nRGB)|0x02000000)
#define PALRGB_TO_RGB(nPalRGB)		((nPalRGB)&0x00ffffff)

// win32 platform specific options. Move them to the PMK file?

#define GCP_KERN_HACK
#define GNG_VERT_HACK

// win32 specific physically available font face
class ImplWinFontData : public SVMCore::ImplFontData
{

public:
                            ImplWinFontData( const ImplDevFontAttributes&,
                                int nFontHeight, WIN_BYTE eWinCharSet,
                                WIN_BYTE nPitchAndFamily  );
                            ~ImplWinFontData();

    virtual ImplFontData*   Clone() const;
    virtual ImplFontEntry*  CreateFontInstance( ImplFontSelectData& ) const;

    virtual sal_IntPtr      GetFontId() const;
    void                    SetFontId( sal_IntPtr nId ) { mnId = nId; }
    void                    UpdateFromHDC( HDC ) const;

    bool                    HasChar( sal_uInt32 cChar ) const;

    WIN_BYTE                GetCharSet() const          { return meWinCharSet; }
    WIN_BYTE                GetPitchAndFamily() const   { return mnPitchAndFamily; }

    bool                    IsGlyphApiDisabled() const  { return mbDisableGlyphApi; }

    bool                    SupportsKorean() const      { return mbHasKoreanRange; }
    bool                    SupportsCJK() const         { return mbHasCJKSupport; }
#ifdef AVS
    bool                    SupportsArabic() const      { return mbHasArabicSupport; }
    bool                    AliasSymbolsHigh() const    { return mbAliasSymbolsHigh; }
    bool                    AliasSymbolsLow() const     { return mbAliasSymbolsLow; }

    ImplFontCharMap*        GetImplFontCharMap() const;
    const Ucs2SIntMap* GetEncodingVector() const { return mpEncodingVector; }
    void SetEncodingVector( const Ucs2SIntMap* pNewVec ) const
    {
        if( mpEncodingVector )
            delete mpEncodingVector;
        mpEncodingVector = pNewVec;
    }
#endif
private:
    sal_IntPtr              mnId;

    // some members that are initalized lazily when the font gets selected into a HDC
    mutable bool                    mbDisableGlyphApi;
    mutable bool                    mbHasKoreanRange;
    mutable bool                    mbHasCJKSupport;
    mutable bool                    mbHasArabicSupport;
    mutable ImplFontCharMap*        mpUnicodeMap;
#ifdef AVS
    mutable const Ucs2SIntMap*      mpEncodingVector;
#endif
    // TODO: get rid of the members below needed to work with the Win9x non-unicode API
    BYTE*                   mpFontCharSets;     // all Charsets for the current font (used on W98 for kerning)
    BYTE                    mnFontCharSetCount; // Number of Charsets of the current font; 0 - if not queried
    WIN_BYTE                meWinCharSet;
    WIN_BYTE                mnPitchAndFamily;
    bool                    mbAliasSymbolsHigh;
    bool                    mbAliasSymbolsLow;

private:
    void                    ReadCmapTable( HDC ) const;
    void                    ReadOs2Table( HDC ) const;
#ifdef AVS
#ifdef GNG_VERT_HACK
    void                    ReadGsubTable( HDC ) const;

    typedef std::hash_set<sal_UCS4> UcsHashSet;
    mutable UcsHashSet      maGsubTable;
    mutable bool            mbGsubRead;
public:
    bool                    HasGSUBstitutions( HDC ) const;
    bool                    IsGSUBstituted( sal_UCS4 ) const;
#endif // GNG_VERT_HACK
#endif
};


// -------------------
// - SalGraphicsData -
// -------------------

class WinSalGraphics : public SalGraphics
{
public:
	HDC 					mhDC;				// HDC
#ifndef AVS_INSERT
	HBITMAP 				mhBmp;					// Memory Bitmap
	HBITMAP 				mhDefBmp;				// Default Bitmap

	HDC 					mhDC0;				//CACHED_HDC_1        0
	HDC 					mhDC1;				//CACHED_HDC_2        1
	HDC 					mhDC2;				//CACHED_HDC_DRAW     2

	HBITMAP 				mhDefBmp0;				//CACHED_HDC_1        0
	HBITMAP 				mhDefBmp1;				//CACHED_HDC_2        1
	HBITMAP 				mhDefBmp2;				//CACHED_HDC_DRAW     2

HDC ImplGetCachedDC( ULONG nID, HBITMAP hBmp = 0 );
void ImplReleaseCachedDC( ULONG nID );
void SetOutputSizePixel( const Size& rNewSize);
#endif

	HWND					mhWnd;				// Window-Handle, when Window-Graphics
	HFONT					mhFonts[ MAX_FALLBACK ];        // Font + Fallbacks
    const ImplWinFontData*  mpWinFontData[ MAX_FALLBACK ];  // pointer to the most recent font face
    ImplWinFontEntry*       mpWinFontEntry[ MAX_FALLBACK ]; // pointer to the most recent font instance

    float                   mfFontScale;        // allows metrics emulation of huge font sizes
	HPEN					mhPen;				// Pen
	HBRUSH					mhBrush;			// Brush
	HRGN					mhRegion;			// Region Handle
	HPEN					mhDefPen;			// DefaultPen
	HBRUSH					mhDefBrush; 		// DefaultBrush
	HFONT					mhDefFont;			// DefaultFont
	HPALETTE				mhDefPal;			// DefaultPalette
	COLORREF				mnPenColor; 		// PenColor
	COLORREF				mnBrushColor;		// BrushColor
	COLORREF				mnTextColor;		// TextColor
	RGNDATA*				mpClipRgnData;		// ClipRegion-Data
	RGNDATA*				mpStdClipRgnData;	// Cache Standard-ClipRegion-Data
	RECT*					mpNextClipRect; 	// Naechstes ClipRegion-Rect
	BOOL					mbFirstClipRect;	// Flag for first cliprect to insert
	LOGFONTA*				mpLogFont;			// LOG-Font which is currently selected (only W9x)
#ifdef AVS
	ImplFontAttrCache*		mpFontAttrCache;	// Cache font attributes from files in so/share/fonts
#endif
	BYTE*					mpFontCharSets; 	// All Charsets for the current font
	BYTE					mnFontCharSetCount; // Number of Charsets of the current font; 0 - if not queried
	BOOL					mbFontKernInit; 	// FALSE: FontKerns must be queried
	KERNINGPAIR*			mpFontKernPairs;	// Kerning Pairs of the current Font
	ULONG					mnFontKernPairCount;// Number of Kerning Pairs of the current Font
	int 					mnPenWidth; 		// Linienbreite
	BOOL					mbStockPen; 		// is Pen a stockpen
	BOOL					mbStockBrush;		// is Brush a stcokbrush
	BOOL					mbPen;				// is Pen (FALSE == NULL_PEN)
	BOOL					mbBrush;			// is Brush (FALSE == NULL_BRUSH)
	BOOL					mbPrinter;			// is Printer
	BOOL					mbVirDev;			// is VirDev
	BOOL					mbWindow;			// is Window
	BOOL					mbScreen;			// is Screen compatible
	bool					mbXORMode;			// _every_ output with RasterOp XOR

    // remember RGB values for SetLineColor/SetFillColor
	SalColor                maLineColor;
    SalColor                maFillColor;

    HFONT                   ImplDoSetFont( ImplFontSelectData* i_pFont, float& o_rFontScale, HFONT& o_rOldFont );

public:
    WinSalGraphics();
    virtual ~WinSalGraphics();

protected:
	virtual SVMCore::BOOL		unionClipRegion( long nX, long nY, long nWidth, long nHeight );
#ifdef AVS
    virtual bool                unionClipRegion( const ::basegfx::B2DPolyPolygon& );
#endif
    // draw --> LineColor and FillColor and RasterOp and ClipRegion
    virtual void		drawPixel( long nX, long nY );
    virtual void		drawPixel( long nX, long nY, SalColor nSalColor );
    virtual void		drawLine( long nX1, long nY1, long nX2, long nY2 );
    virtual void		drawRect( long nX, long nY, long nWidth, long nHeight );
    virtual void		drawPolyLine( ULONG nPoints, const SalPoint* pPtAry );
    virtual void		drawPolygon( ULONG nPoints, const SalPoint* pPtAry );
	virtual void		drawPolyPolygon( sal_uInt32 nPoly, const sal_uInt32* pPoints, PCONSTSALPOINT* pPtAry );
#ifdef AVS
    virtual bool        drawPolyPolygon( const ::basegfx::B2DPolyPolygon&, double fTransparency );
    virtual bool        drawPolyLine( const ::basegfx::B2DPolygon&, const ::basegfx::B2DVector& rLineWidth, basegfx::B2DLineJoin);
#endif
    virtual sal_Bool	drawPolyLineBezier( ULONG nPoints, const SalPoint* pPtAry, const BYTE* pFlgAry );
    virtual sal_Bool	drawPolygonBezier( ULONG nPoints, const SalPoint* pPtAry, const BYTE* pFlgAry );
    virtual sal_Bool	drawPolyPolygonBezier( sal_uInt32 nPoly, const sal_uInt32* pPoints, const SalPoint* const* pPtAry, const BYTE* const* pFlgAry );
#ifdef AVS
    // CopyArea --> No RasterOp, but ClipRegion
    virtual void		copyArea( long nDestX, long nDestY, long nSrcX, long nSrcY, long nSrcWidth,
                                  long nSrcHeight, USHORT nFlags );
#endif
    // CopyBits and DrawBitmap --> RasterOp and ClipRegion
    // CopyBits() --> pSrcGraphics == NULL, then CopyBits on same Graphics
    virtual void		copyBits( const SalTwoRect* pPosAry, SalGraphics* pSrcGraphics );

    virtual void		drawBitmap( const SalTwoRect* pPosAry, const SalBitmap& rSalBitmap );

    virtual void		drawBitmap( const SalTwoRect* pPosAry,
                                    const SalBitmap& rSalBitmap,
                                    SalColor nTransparentColor );
    virtual void		drawBitmap( const SalTwoRect* pPosAry,
                                    const SalBitmap& rSalBitmap,
                                    const SalBitmap& rTransparentBitmap );

    virtual void		drawMask( const SalTwoRect* pPosAry,
                                  const SalBitmap& rSalBitmap,
                                  SalColor nMaskColor );

    virtual SalBitmap*	getBitmap( long nX, long nY, long nWidth, long nHeight );
    virtual SalColor	getPixel( long nX, long nY );
#ifdef AVS
    // invert --> ClipRegion (only Windows or VirDevs)
    virtual void		invert( long nX, long nY, long nWidth, long nHeight, SalInvert nFlags);
    virtual void		invert( ULONG nPoints, const SalPoint* pPtAry, SalInvert nFlags );

    virtual BOOL		drawEPS( long nX, long nY, long nWidth, long nHeight, void* pPtr, ULONG nSize );

    // native widget rendering methods that require mirroring
    virtual BOOL        hitTestNativeControl( ControlType nType, ControlPart nPart, const Region& rControlRegion,
                                              const Point& aPos, SalControlHandle& rControlHandle, BOOL& rIsInside );
    virtual BOOL        drawNativeControl( ControlType nType, ControlPart nPart, const Region& rControlRegion,
                                           ControlState nState, const ImplControlValue& aValue, SalControlHandle& rControlHandle,
                                           const rtl::OUString& aCaption );
    virtual BOOL        drawNativeControlText( ControlType nType, ControlPart nPart, const Region& rControlRegion,
                                               ControlState nState, const ImplControlValue& aValue,
                                               SalControlHandle& rControlHandle, const rtl::OUString& aCaption );
    virtual BOOL        getNativeControlRegion( ControlType nType, ControlPart nPart, const Region& rControlRegion, ControlState nState,
                                                const ImplControlValue& aValue, SalControlHandle& rControlHandle, const rtl::OUString& aCaption,
                                                Region &rNativeBoundingRegion, Region &rNativeContentRegion );
#endif
    virtual bool		drawAlphaBitmap( const SalTwoRect&,
                                         const SalBitmap& rSourceBitmap,
                                         const SalBitmap& rAlphaBitmap );
    virtual bool		drawAlphaRect( long nX, long nY, long nWidth, long nHeight, sal_uInt8 nTransparency );
#ifdef AVS
public:
    // public SalGraphics methods, the interface to teh independent vcl part

    // get device resolution
    virtual void			GetResolution( long& rDPIX, long& rDPIY );
#endif
    // get the depth of the device
    virtual USHORT			GetBitCount();
#ifdef AVS
    // get the width of the device
    virtual long			GetGraphicsWidth() const;
#endif
    // set the clip region to empty
    virtual void			ResetClipRegion();
    // begin setting the clip region, add rectangles to the
    // region with the UnionClipRegion call
    virtual void			BeginSetClipRegion( ULONG nCount );
    // all rectangles were added and the clip region should be set now
    virtual void			EndSetClipRegion();

    // set the line color to transparent (= don't draw lines)
    virtual void			SetLineColor();
    // set the line color to a specific color
    virtual void			SetLineColor( SalColor nSalColor );
    // set the fill color to transparent (= don't fill)
    virtual void			SetFillColor();
    // set the fill color to a specific color, shapes will be
    // filled accordingly
    virtual void          	SetFillColor( SalColor nSalColor );
    // enable/disable XOR drawing
    virtual void			SetXORMode( bool bSet, bool );
    // set line color for raster operations
    virtual void			SetROPLineColor( SalROPColor nROPColor );
    // set fill color for raster operations
    virtual void			SetROPFillColor( SalROPColor nROPColor );
    // set the text color to a specific color
    virtual void			SetTextColor( SalColor nSalColor );

    // set the font
    virtual USHORT         SetFont( ImplFontSelectData*, int nFallbackLevel );
    // get the current font's etrics
    virtual void			GetFontMetric( ImplFontMetricData* );
    // get kernign pairs of the current font
    // return only PairCount if (pKernPairs == NULL)
    virtual ULONG			GetKernPairs( ULONG nPairs, ImplKernPairData* pKernPairs );
#ifdef AVS
    // get the repertoire of the current font
    virtual ImplFontCharMap* GetImplFontCharMap() const;
#endif
    // graphics must fill supplied font list
    virtual void			GetDevFontList( ImplDevFontList* );
#ifdef AVS
    // graphics should call ImplAddDevFontSubstitute on supplied
    // OutputDevice for all its device specific preferred font substitutions
    virtual void			GetDevFontSubstList( OutputDevice* );
    virtual bool			AddTempDevFont( ImplDevFontList*, const String& rFileURL, const String& rFontName );
    // CreateFontSubset: a method to get a subset of glyhps of a font
    // inside a new valid font file
    // returns TRUE if creation of subset was successfull
    // parameters: rToFile: contains a osl file URL to write the subset to
    //             pFont: describes from which font to create a subset
    //             pGlyphIDs: the glyph ids to be extracted
    //             pEncoding: the character code corresponding to each glyph
    //             pWidths: the advance widths of the correspoding glyphs (in PS font units)
    //             nGlyphs: the number of glyphs
    //             rInfo: additional outgoing information
    // implementation note: encoding 0 with glyph id 0 should be added implicitly
    // as "undefined character"
    virtual BOOL			CreateFontSubset( const rtl::OUString& rToFile,
                                              const ImplFontData*,
                                              long* pGlyphIDs,
                                              sal_uInt8* pEncoding,
                                              sal_Int32* pWidths,
                                              int nGlyphs,
                                              FontSubsetInfo& rInfo // out parameter
                                              );

    // GetFontEncodingVector: a method to get the encoding map Unicode
	// to font encoded character; this is only used for type1 fonts and
    // may return NULL in case of unknown encoding vector
    // if ppNonEncoded is set and non encoded characters (that is type1
    // glyphs with only a name) exist it is set to the corresponding
    // map for non encoded glyphs; the encoding vector contains -1
    // as encoding for these cases
    virtual const Ucs2SIntMap* GetFontEncodingVector( const ImplFontData*, const Ucs2OStrMap** ppNonEncoded );

    // GetEmbedFontData: gets the font data for a font marked
    // embeddable by GetDevFontList or NULL in case of error
    // parameters: pFont: describes the font in question
    //             pWidths: the widths of all glyphs from char code 0 to 255
    //                      pWidths MUST support at least 256 members;
    //             rInfo: additional outgoing information
    //             pDataLen: out parameter, contains the byte length of the returned buffer
    virtual const void*	GetEmbedFontData( const ImplFontData*,
                                          const sal_Ucs* pUnicodes,
                                          sal_Int32* pWidths,
                                          FontSubsetInfo& rInfo,
                                          long* pDataLen );
    // frees the font data again
    virtual void			FreeEmbedFontData( const void* pData, long nDataLen );
    virtual void            GetGlyphWidths( const ImplFontData*,
                                            bool bVertical,
                                            Int32Vector& rWidths,
                                            Ucs2UIntMap& rUnicodeEnc );
	virtual int             GetMinKashidaWidth();
#endif
    virtual SvmBOOL                    GetGlyphBoundRect( long nIndex, SvmRectangle& );
#ifdef AVS
    virtual BOOL                    GetGlyphOutline( long nIndex, ::basegfx::B2DPolyPolygon& );
#endif
    virtual SalLayout*              GetTextLayout( ImplLayoutArgs&, int nFallbackLevel );
#ifdef AVS
    virtual void					 DrawServerFontLayout( const ServerFontLayout& );

    virtual bool            supportsOperation( OutDevSupportType ) const;
    // Query the platform layer for control support
    virtual BOOL IsNativeControlSupported( ControlType nType, ControlPart nPart );

    virtual SystemGraphicsData GetGraphicsData() const;
#endif
};
#ifdef AVS
// Init/Deinit Graphics
void	ImplSalInitGraphics( WinSalGraphics* mpData );
void	ImplSalDeInitGraphics( WinSalGraphics* mpData );
void	ImplUpdateSysColorEntries();
int 	ImplIsSysColorEntry( SalColor nSalColor );
void    ImplGetLogFontFromFontSelect( HDC hDC, const ImplFontSelectData*,
            LOGFONTW&, bool bTestVerticalAvail );

// -----------
// - Defines -
// -----------
#endif
#define MAX_64KSALPOINTS	((((USHORT)0xFFFF)-8)/sizeof(POINTS))

// -----------
// - Inlines -
// -----------

// #102411# Win's GCP mishandles kerning => we need to do it ourselves
// SalGraphicsData::mpFontKernPairs is sorted by
inline bool ImplCmpKernData( const KERNINGPAIR& a, const KERNINGPAIR& b )
{
    if( a.wFirst < b.wFirst )
        return true;
    if( a.wFirst > b.wFirst )
        return false;
    return (a.wSecond < b.wSecond);
}

// called extremely often from just one spot => inline
inline bool ImplWinFontData::HasChar( sal_uInt32 cChar ) const
{
    if( mpUnicodeMap->HasChar( cChar ) )
        return true;
    // second chance to allow symbol aliasing
    if( mbAliasSymbolsLow && ((cChar-0xF000) <= 0xFF) )
        cChar -= 0xF000;
    else if( mbAliasSymbolsHigh && (cChar <= 0xFF) )
        cChar += 0xF000;
    return mpUnicodeMap->HasChar( cChar );
}

#endif // _SV_SALGDI_H