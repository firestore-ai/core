﻿#ifndef _BUILD_EDITOR_DEFINES_CROSSPLATFORM_H_
#define _BUILD_EDITOR_DEFINES_CROSSPLATFORM_H_

namespace NSEditorDefines
{

#define g_bDate1904 = false;

#define CellValueType_Number	0
#define CellValueType_String	1
#define CellValueType_Bool		2
#define CellValueType_Error		3

//NumFormat defines
#define	c_oAscNumFormatType_General		0
#define c_oAscNumFormatType_Custom		1
#define c_oAscNumFormatType_Text		2
#define c_oAscNumFormatType_Number		3
#define c_oAscNumFormatType_Integer		4
#define c_oAscNumFormatType_Scientific	5
#define c_oAscNumFormatType_Currency	6
#define c_oAscNumFormatType_Date		7
#define c_oAscNumFormatType_Time		8
#define c_oAscNumFormatType_Percent		9
#define c_oAscNumFormatType_Fraction	10
	 
#define c_oAscDrawingLayerType_BringToFront		0
#define c_oAscDrawingLayerType_SendToBack		1
#define c_oAscDrawingLayerType_BringForward		2
#define c_oAscDrawingLayerType_SendBackward		3

#define c_oAscTransactionState_No		-1
#define c_oAscTransactionState_Start	0
#define c_oAscTransactionState_Stop		1
							
#define c_oAscCellAnchorType_cellanchorAbsolute		0
#define c_oAscCellAnchorType_cellanchorOneCell		1
#define c_oAscCellAnchorType_cellanchorTwoCell		2

#define c_oAscChartDefines_defaultChartWidth		478
#define c_oAscChartDefines_defaultChartHeight		286
	
#define c_oAscLineDrawingRule_Left		0
#define c_oAscLineDrawingRule_Center	1
#define c_oAscLineDrawingRule_Right		2
#define c_oAscLineDrawingRule_Top		0
#define c_oAscLineDrawingRule_Bottom	2
	
#define align_Right		0
#define align_Left		1
#define align_Center	2
#define align_Justify	3

#define linerule_AtLeast	0
#define linerule_Auto		1
#define linerule_Exact		2

#define shd_Clear	0
#define shd_Nil		1

#define vertalign_Baseline		0
#define vertalign_SuperScript	1
#define vertalign_SubScript		2
#define hdrftr_Header			0x01
#define hdrftr_Footer			0x02

#define c_oAscChartTitleShowSettings_none			0
#define c_oAscChartTitleShowSettings_overlay		1
#define c_oAscChartTitleShowSettings_noOverlay		2

#define c_oAscChartHorAxisLabelShowSettings_none		0
#define c_oAscChartHorAxisLabelShowSettings_noOverlay	1

#define c_oAscChartVertAxisLabelShowSettings_none			0
#define c_oAscChartVertAxisLabelShowSettings_rotated		1
#define c_oAscChartVertAxisLabelShowSettings_vertical		2
#define c_oAscChartVertAxisLabelShowSettings_horizontal		3

#define c_oAscChartLegendShowSettings_none				0
#define c_oAscChartLegendShowSettings_left				1
#define c_oAscChartLegendShowSettings_top				2
#define c_oAscChartLegendShowSettings_right				3
#define c_oAscChartLegendShowSettings_bottom			4
#define c_oAscChartLegendShowSettings_leftOverlay		5
#define c_oAscChartLegendShowSettings_rightOverlay		6
#define c_oAscChartLegendShowSettings_layout			7

#define c_oAscChartDataLabelsPos_none			0
#define c_oAscChartDataLabelsPos_b				1
#define c_oAscChartDataLabelsPos_bestFit		2
#define c_oAscChartDataLabelsPos_ctr			3
#define c_oAscChartDataLabelsPos_inBase			4
#define c_oAscChartDataLabelsPos_inEnd			5
#define c_oAscChartDataLabelsPos_l				6
#define c_oAscChartDataLabelsPos_outEnd			7
#define c_oAscChartDataLabelsPos_r				8
#define c_oAscChartDataLabelsPos_t				9

#define c_oAscChartCatAxisSettings_none				0
#define c_oAscChartCatAxisSettings_leftToRight		1
#define c_oAscChartCatAxisSettings_rightToLeft		2
#define c_oAscChartCatAxisSettings_noLabels			3

#define c_oAscChartValAxisSettings_none				0
#define c_oAscChartValAxisSettings_byDefault		1
#define c_oAscChartValAxisSettings_thousands		2
#define c_oAscChartValAxisSettings_millions			3
#define c_oAscChartValAxisSettings_billions			4
#define c_oAscChartValAxisSettings_log				5

#define c_oAscAxisTypeSettings_vert		0
#define c_oAscAxisTypeSettings_hor		1

#define c_oAscGridLinesSettings_none		0
#define c_oAscGridLinesSettings_major		1
#define c_oAscGridLinesSettings_minor		2
#define c_oAscGridLinesSettings_majorMinor	3

#define c_oAscChartTypeSettings_barNormal				0
#define c_oAscChartTypeSettings_barStacked				1
#define c_oAscChartTypeSettings_barStackedPer			2
#define c_oAscChartTypeSettings_lineNormal				3
#define c_oAscChartTypeSettings_lineStacked				4
#define c_oAscChartTypeSettings_lineStackedPer			5
#define c_oAscChartTypeSettings_lineNormalMarker		6
#define c_oAscChartTypeSettings_lineStackedMarker		7
#define c_oAscChartTypeSettings_lineStackedPerMarker	8
#define c_oAscChartTypeSettings_pie						9
#define c_oAscChartTypeSettings_hBarNormal				10
#define c_oAscChartTypeSettings_hBarStacked				11
#define c_oAscChartTypeSettings_hBarStackedPer			12
#define c_oAscChartTypeSettings_areaNormal				13
#define c_oAscChartTypeSettings_areaStacked				14
#define c_oAscChartTypeSettings_areaStackedPer			15
#define c_oAscChartTypeSettings_doughnut				16
#define c_oAscChartTypeSettings_stock					17
#define c_oAscChartTypeSettings_scatter					18
#define c_oAscChartTypeSettings_scatterLine				19
#define c_oAscChartTypeSettings_scatterLineMarker		20
#define c_oAscChartTypeSettings_scatterMarker			21
#define c_oAscChartTypeSettings_scatterNone				22
#define c_oAscChartTypeSettings_scatterSmooth			23
#define c_oAscChartTypeSettings_scatterSmoothMarker		24
#define c_oAscChartTypeSettings_unknown					25

#define c_oAscValAxisRule_auto		0
#define c_oAscValAxisRule_fixed		1

#define c_oAscValAxUnits_none					0
#define c_oAscValAxUnits_BILLIONS				1
#define c_oAscValAxUnits_HUNDRED_MILLIONS		2
#define c_oAscValAxUnits_HUNDREDS				3
#define c_oAscValAxUnits_HUNDRED_THOUSANDS		4
#define c_oAscValAxUnits_MILLIONS				5
#define c_oAscValAxUnits_TEN_MILLIONS			6
#define c_oAscValAxUnits_TEN_THOUSANDS			7
#define c_oAscValAxUnits_TRILLIONS				8
#define c_oAscValAxUnits_CUSTOM					9
#define c_oAscValAxUnits_THOUSANDS				10

#define c_oAscTickMark_TICK_MARK_CROSS			0
#define c_oAscTickMark_TICK_MARK_IN				1
#define c_oAscTickMark_TICK_MARK_NONE			2
#define c_oAscTickMark_TICK_MARK_OUT			3

#define c_oAscTickLabelsPos_TICK_LABEL_POSITION_HIGH		0
#define c_oAscTickLabelsPos_TICK_LABEL_POSITION_LOW			1
#define c_oAscTickLabelsPos_TICK_LABEL_POSITION_NEXT_TO		2
#define c_oAscTickLabelsPos_TICK_LABEL_POSITION_NONE		3

#define c_oAscCrossesRule_auto			0
#define c_oAscCrossesRule_maxValue		1
#define c_oAscCrossesRule_value			2
#define c_oAscCrossesRule_minValue		3

#define c_oAscHorAxisType_auto			0
#define c_oAscHorAxisType_date			1
#define c_oAscHorAxisType_text			2

#define c_oAscBetweenLabelsRule_auto	0
#define c_oAscBetweenLabelsRule_manual	1

#define c_oAscLabelsPosition_byDivisions		0
#define c_oAscLabelsPosition_betweenDivisions	1

#define c_oAscAxisType_auto		0
#define c_oAscAxisType_date		1
#define c_oAscAxisType_text		2
#define c_oAscAxisType_cat		3
#define c_oAscAxisType_val		4

#define c_oAscHAnchor_Margin		0x00
#define c_oAscHAnchor_Page			0x01
#define c_oAscHAnchor_Text			0x02
#define c_oAscHAnchor_PageInternal	0xFF // только для внутреннего использования

#define c_oAscXAlign_Center			0x00
#define c_oAscXAlign_Inside			0x01
#define c_oAscXAlign_Left			0x02
#define c_oAscXAlign_Outside		0x03
#define c_oAscXAlign_Right			0x04

#define c_oAscYAlign_Bottom			0x00
#define c_oAscYAlign_Center			0x01
#define c_oAscYAlign_Inline			0x02
#define c_oAscYAlign_Inside			0x03
#define c_oAscYAlign_Outside		0x04
#define c_oAscYAlign_Top			0x05

#define c_oAscVAnchor_Margin		0x00
#define c_oAscVAnchor_Page			0x01
#define c_oAscVAnchor_Text			0x02

#define c_oAscRelativeFromH_Character		0x00
#define c_oAscRelativeFromH_Column			0x01
#define c_oAscRelativeFromH_InsideMargin	0x02
#define c_oAscRelativeFromH_LeftMargin		0x03
#define c_oAscRelativeFromH_Margin			0x04
#define c_oAscRelativeFromH_OutsideMargin	0x05
#define c_oAscRelativeFromH_Page			0x06
#define c_oAscRelativeFromH_RightMargin		0x07

#define c_oAscRelativeFromV_BottomMargin		0x00
#define c_oAscRelativeFromV_InsideMargin		0x01
#define c_oAscRelativeFromV_Line				0x02
#define c_oAscRelativeFromV_Margin				0x03
#define c_oAscRelativeFromV_OutsideMargin		0x04
#define c_oAscRelativeFromV_Page				0x05
#define c_oAscRelativeFromV_Paragraph			0x06
#define c_oAscRelativeFromV_TopMargin			0x07

// image wrap style
#define c_oAscWrapStyle_Inline			0
#define c_oAscWrapStyle_Flow			1

// math
#define c_oAscLimLoc_SubSup				0x00
#define c_oAscLimLoc_UndOvr				0x01

#define c_oAscMathJc_Center				0x00
#define c_oAscMathJc_CenterGroup		0x01
#define c_oAscMathJc_Left				0x02
#define c_oAscMathJc_Right				0x03

#define c_oAscTopBot_Bot				0x00
#define c_oAscTopBot_Top				0x01

#define c_oAscScript_DoubleStruck		0x00
#define c_oAscScript_Fraktur			0x01
#define c_oAscScript_Monospace			0x02
#define c_oAscScript_Roman				0x03
#define c_oAscScript_SansSerif			0x04
#define c_oAscScript_Script				0x05

#define c_oAscShp_Centered				0x00
#define c_oAscShp_Match					0x01

#define c_oAscSty_Bold					0x00
#define c_oAscSty_BoldItalic			0x01
#define c_oAscSty_Italic				0x02
#define c_oAscSty_Plain					0x03

#define c_oAscFType_Bar					0x00
#define c_oAscFType_Lin					0x01
#define c_oAscFType_NoBar				0x02
#define c_oAscFType_Skw					0x03

#define c_oAscBrkBin_After				0x00
#define c_oAscBrkBin_Before				0x01
#define c_oAscBrkBin_Repeat				0x02

#define c_oAscBrkBinSub_PlusMinus		0x00
#define c_oAscBrkBinSub_MinusPlus		0x01
#define c_oAscBrkBinSub_MinusMinus		0x02

// Толщина бордера
#define c_oAscBorderWidth_None			0	// 0px
#define c_oAscBorderWidth_Thin			1	// 1px
#define c_oAscBorderWidth_Medium		2	// 2px
#define c_oAscBorderWidth_Thick			3	// 3px

// Располагаются в порядке значимости для отрисовки
#define c_oAscBorderStyles_None					0
#define c_oAscBorderStyles_Double				1
#define c_oAscBorderStyles_Hair					2
#define c_oAscBorderStyles_DashDotDot			3
#define c_oAscBorderStyles_DashDot				4
#define c_oAscBorderStyles_Dotted				5
#define c_oAscBorderStyles_Dashed				6
#define c_oAscBorderStyles_Thin					7
#define c_oAscBorderStyles_MediumDashDotDot		8
#define c_oAscBorderStyles_SlantDashDot			9
#define c_oAscBorderStyles_MediumDashDot		10
#define c_oAscBorderStyles_MediumDashed			11
#define c_oAscBorderStyles_Medium				12
#define c_oAscBorderStyles_Thick				13

// PageOrientation
#define c_oAscPageOrientation_PagePortrait		1
#define c_oAscPageOrientation_PageLandscape		2

/**
 * lock types
 * @const
 */
#define c_oAscLockTypes_kLockTypeNone			1	// никто не залочил данный объект
#define c_oAscLockTypes_kLockTypeMine			2	// данный объект залочен текущим пользователем
#define c_oAscLockTypes_kLockTypeOther			3	// данный объект залочен другим(не текущим) пользователем
#define c_oAscLockTypes_kLockTypeOther2			4	// данный объект залочен другим(не текущим) пользователем (обновления уже пришли)
#define c_oAscLockTypes_kLockTypeOther3			5	// данный объект был залочен (обновления пришли) и снова стал залочен

#define c_oAscFormatPainterState_kOff			0
#define c_oAscFormatPainterState_kOn			1
#define c_oAscFormatPainterState_kMultiple		2

}

namespace NSEditorDefines
{
	
#define c_oAscZoomType_Current		0
#define c_oAscZoomType_FitWidth		1
#define c_oAscZoomType_FitPage		2

#define c_oAscAsyncActionType_Information			0
#define c_oAscAsyncActionType_BlockInteraction		1

#define c_oAscAsyncAction_Open					0	// открытие документа
#define c_oAscAsyncAction_Save					1
#define c_oAscAsyncAction_LoadDocumentFonts		2	// загружаем фонты документа (сразу после открытия)
#define c_oAscAsyncAction_LoadDocumentImages	3	// загружаем картинки документа (сразу после загрузки шрифтов)
#define c_oAscAsyncAction_ LoadFont				4	// подгрузка нужного шрифта
#define c_oAscAsyncAction_LoadImage				5	// подгрузка картинки
#define c_oAscAsyncAction_DownloadAs			6
#define c_oAscAsyncAction_Print					7	// конвертация в PDF и сохранение у пользователя
#define c_oAscAsyncAction_UploadImage			8
#define c_oAscAsyncAction_ApplyChanges			9	// применение изменений от другого пользователя.
#define c_oAscAsyncAction_PrepareToSave			10	// Подготовка к сохранению

//files type for Saving & DownloadAs
#define c_oAscFileType_INNER 		0x0041
#define c_oAscFileType_DOCX 		0x0041
#define c_oAscFileType_DOC 			0x0042
#define c_oAscFileType_ODT			0x0043
#define c_oAscFileType_RTF			0x0044
#define c_oAscFileType_TXT			0x0045
#define c_oAscFileType_HTML_ZIP 	0x0803
#define c_oAscFileType_MHT			0x0047
#define c_oAscFileType_PDF	 		0x0201
#define c_oAscFileType_EPUB 		0x0048
#define c_oAscFileType_FB2	 		0x0049
#define c_oAscFileType_MOBI 		0x004a
#define c_oAscFileType_DOCY 		0x1001

// Right = 0; Left = 1; Center = 2; Justify = 3;
#define c_oAscAlignType_LEFT		0
#define c_oAscAlignType_CENTER		1
#define c_oAscAlignType_RIGHT		2
#define c_oAscAlignType_JUSTIFY		3
#define c_oAscAlignType_TOP			4
#define c_oAscAlignType_MIDDLE		5
#define c_oAscAlignType_BOTTOM		6

#define c_oAscWrapStyle2_Inline			0
#define c_oAscWrapStyle2_Square			1
#define c_oAscWrapStyle2_Tight			2
#define c_oAscWrapStyle2_Through		3
#define c_oAscWrapStyle2_TopAndBottom	4
#define c_oAscWrapStyle2_Behind			5
#define c_oAscWrapStyle2_InFront		6

/*Error level & ID*/
#define c_oAscError_Level_Critical					-1
#define c_oAscError_Level_NoCritical				0

#define c_oAscError_ID_ServerSaveComplete			3
#define c_oAscError_ID_ConvertationProgress			2
#define c_oAscError_ID_DownloadProgress				1
#define c_oAscError_ID_No							0
#define c_oAscError_ID_Unknown						-1
#define c_oAscError_ID_ConvertationTimeout			-2
#define c_oAscError_ID_ConvertationError			-3
#define c_oAscError_ID_DownloadError				-4
#define c_oAscError_ID_UnexpectedGuid				-5
#define c_oAscError_ID_Database						-6
#define c_oAscError_ID_FileRequest					-7
#define c_oAscError_ID_FileVKey						-8
#define c_oAscError_ID_UplImageSize					-9
#define c_oAscError_ID_UplImageExt					-10
#define c_oAscError_ID_UplImageFileCount			-11
#define c_oAscError_ID_NoSupportClipdoard			-12
#define c_oAscError_ID_SplitCellMaxRows				-13
#define c_oAscError_ID_SplitCellMaxCols				-14
#define c_oAscError_ID_SplitCellRowsDivider			-15
#define c_oAscError_ID_CoAuthoringDisconnect		-18
#define c_oAscError_ID_ConvertationPassword			-19
#define c_oAscError_ID_VKeyEncrypt					-20
#define c_oAscError_ID_KeyExpire					-21
#define c_oAscError_ID_UserCountExceed				-22
#define c_oAscError_ID_MobileUnexpectedCharCount	-23

#define c_oAscTypeSelectElement_Paragraph			0
#define c_oAscTypeSelectElement_Table				1
#define c_oAscTypeSelectElement_Image				2
#define c_oAscTypeSelectElement_Header				3
#define c_oAscTypeSelectElement_Hyperlink			4
#define c_oAscTypeSelectElement_SpellCheck			5
#define c_oAscTypeSelectElement_Shape				6
#define c_oAscTypeSelectElement_Slide				7
#define c_oAscTypeSelectElement_Chart				8

#define c_oAscTableBordersType_LEFT					0
#define c_oAscTableBordersType_TOP					1
#define c_oAscTableBordersType_RIGHT				2
#define c_oAscTableBordersType_BOTTOM				3
#define c_oAscTableBordersType_VERTLINE				4
#define c_oAscTableBordersType_HORIZONTLINE			5
#define c_oAscTableBordersType_INSIDE				6
#define c_oAscTableBordersType_OUTSIDE				7
#define c_oAscTableBordersType_ALL					8

#define FONT_THUMBNAIL_HEIGHT						26

#define c_oAscStyleImage_Default					0
#define c_oAscStyleImage_Document					1

#define c_oAscLineDrawingRule_Left					0
#define c_oAscLineDrawingRule_Center				1
#define c_oAscLineDrawingRule_Right					2
#define c_oAscLineDrawingRule_Top					0
#define c_oAscLineDrawingRule_Bottom				2

// Chart defines
#define c_oAscChartType_line						0
#define c_oAscChartType_bar							1
#define c_oAscChartType_hbar						2
#define c_oAscChartType_area						3
#define c_oAscChartType_pie							4
#define c_oAscChartType_scatter						5
#define c_oAscChartType_stock						6

#define c_oAscChartSubType_normal					0
#define c_oAscChartSubType_stacked					1
#define c_oAscChartSubType_stackedPer				2

#define vertalign_Baseline			0
#define vertalign_SuperScript		1
#define vertalign_SubScript			2
#define hdrftr_Header				0x01
#define hdrftr_Footer				0x02

#define hdrftr_Default				0x01
#define hdrftr_Even					0x02
#define hdrftr_First				0x03

#define c_oAscTableSelectionType_Cell		0
#define c_oAscTableSelectionType_Row		1
#define c_oAscTableSelectionType_Column		2
#define c_oAscTableSelectionType_Table		3

#define linerule_AtLeast	0
#define linerule_Auto		1
#define linerule_Exact		2

#define shd_Clear			0
#define shd_Nil				1

#define c_oAscContextMenuTypes_Common				0	// Обычное контекстное меню
#define c_oAscContextMenuTypes_ChangeHdrFtr			1	// Специальное контестное меню для попадания в колонтитул

#define c_oAscMouseMoveDataTypes_Common				0
#define c_oAscMouseMoveDataTypes_Hyperlink			1
#define c_oAscMouseMoveDataTypes_LockedObject		2

#define c_oAscMouseMoveLockedObjectType_Common		0
#define c_oAscMouseMoveLockedObjectType_Header		1
#define c_oAscMouseMoveLockedObjectType_Footer		2

#define c_oAscCollaborativeMarksShowType_None				-1
#define c_oAscCollaborativeMarksShowType_All				0
#define c_oAscCollaborativeMarksShowType_LastChanges		1

#define c_oAscAlignH_Center		0x00
#define c_oAscAlignH_Inside		0x01
#define c_oAscAlignH_Left		0x02
#define c_oAscAlignH_Outside	0x03
#define c_oAscAlignH_Right		0x04

#define c_oAscChangeLevel_BringToFront			0x00
#define c_oAscChangeLevel_BringForward			0x01
#define c_oAscChangeLevel_SendToBack			0x02
#define c_oAscChangeLevel_BringBackward			0x03

#define c_oAscAlignV_Bottom						0x00
#define c_oAscAlignV_Center						0x01
#define c_oAscAlignV_Inside						0x02
#define c_oAscAlignV_Outside					0x03
#define c_oAscAlignV_Top						0x04

#define c_oAscVertAlignJc_Top					0x00
#define c_oAscVertAlignJc_Center				0x01
#define c_oAscVertAlignJc_Bottom				0x02

#define c_oAscTableLayout_AutoFit				0x00
#define c_oAscTableLayout_Fixed					0x01

#define c_oAscColor_COLOR_TYPE_SRGB				1
#define c_oAscColor_COLOR_TYPE_PRST				2
#define c_oAscColor_COLOR_TYPE_SCHEME			3

#define c_oAscFill_FILL_TYPE_BLIP				1
#define c_oAscFill_FILL_TYPE_NOFILL				2
#define c_oAscFill_FILL_TYPE_SOLID				3
#define c_oAscFill_FILL_TYPE_PATT				4
#define c_oAscFill_FILL_TYPE_GRAD				5

#define c_oAscFillGradType_GRAD_LINEAR			1
#define c_oAscFillGradType_GRAD_PATH			2

#define c_oAscFillBlipType_STRETCH				1
#define c_oAscFillBlipType_TILE					2

#define c_oAscStrokeType_STROKE_NONE			0
#define c_oAscStrokeType_STROKE_COLOR			1

#define c_oAscAlignShapeType_ALIGN_LEFT			0
#define c_oAscAlignShapeType_ALIGN_RIGHT		1
#define c_oAscAlignShapeType_ALIGN_TOP			2
#define c_oAscAlignShapeType_ALIGN_BOTTOM		3
#define c_oAscAlignShapeType_ALIGN_CENTER		4
#define c_oAscAlignShapeType_ALIGN_MIDDLE		5

#define c_oAscVerticalTextAlign_TEXT_ALIGN_BOTTOM		0	// (Text Anchor Enum ( Bottom ))
#define c_oAscVerticalTextAlign_TEXT_ALIGN_CTR			1	// (Text Anchor Enum ( Center ))
#define c_oAscVerticalTextAlign_TEXT_ALIGN_DIST			2	// (Text Anchor Enum ( Distributed ))
#define c_oAscVerticalTextAlign_TEXT_ALIGN_JUST			3	// (Text Anchor Enum ( Justified ))
#define c_oAscVerticalTextAlign_TEXT_ALIGN_TOP			4	// Top

#define c_oAscLineJoinType_Round				1
#define c_oAscLineJoinType_Bevel				2
#define c_oAscLineJoinType_Miter				3

#define c_oAscLineCapType_Flat					0
#define c_oAscLineCapType_Round					1
#define c_oAscLineCapType_Square				2

#define c_oAscLineBeginType_None				0
#define c_oAscLineBeginType_Arrow				1
#define c_oAscLineBeginType_Diamond				2
#define c_oAscLineBeginType_Oval				3
#define c_oAscLineBeginType_Stealth				4
#define c_oAscLineBeginType_Triangle			5

#define c_oAscLineBeginSize_small_small			0
#define c_oAscLineBeginSize_small_mid			1
#define c_oAscLineBeginSize_small_large			2
#define c_oAscLineBeginSize_mid_small			3
#define c_oAscLineBeginSize_mid_mid				4
#define c_oAscLineBeginSize_mid_large			5
#define c_oAscLineBeginSize_large_small			6
#define c_oAscLineBeginSize_large_mid			7
#define c_oAscLineBeginSize_large_large			8

#define TABLE_STYLE_WIDTH_PIX					70
#define TABLE_STYLE_HEIGHT_PIX					50

#define c_oAscDropCap_None						0
#define c_oAscDropCap_Drop						1
#define c_oAscDropCap_Margin					2

#define c_oAscSectionBreakType_NextPage			0x00
#define c_oAscSectionBreakType_OddPage			0x01
#define c_oAscSectionBreakType_EvenPage			0x02
#define c_oAscSectionBreakType_Continuous		0x03
#define c_oAscSectionBreakType_Column			0x04

}

namespace NSEditorApi
{

#define LINK_PROPERTY_INT(memberName)					\
	inline int get_##memberName()						\
	{													\
		return m_n##memberName;							\
	}													\
	inline void put_##memberName(const int& newVal)		\
	{													\
		m_n##memberName = newVal;						\
	}

#define LINK_PROPERTY_DOUBLE(memberName)				\
	inline double get_##memberName()					\
	{													\
		return m_d##memberName;							\
	}													\
	inline void put_##memberName(const double& newVal)	\
	{													\
		m_d##memberName = newVal;						\
	}

#define LINK_PROPERTY_BOOL(memberName)					\
	inline bool get_##memberName()						\
	{													\
		return m_b##memberName;							\
	}													\
	inline void put_##memberName(const bool& newVal)	\
	{													\
		m_b##memberName = newVal;						\
	}

#define LINK_PROPERTY_BYTE(memberName)					\
	inline unsigned char get_##memberName()				\
	{													\
		return m_n##memberName;							\
	}													\
	inline void put_##memberName(const unsigned char& newVal)	\
	{															\
		m_n##memberName = newVal;								\
	}

#define LINK_PROPERTY_STRING(memberName)						\
	inline std::wstring get_##memberName()						\
	{															\
		return m_s##memberName;									\
	}															\
	inline void put_##memberName(const std::wstring& newVal)	\
	{															\
		m_s##memberName = newVal;								\
	}
#define LINK_PROPERTY_STRINGA(memberName)						\
	inline std::string get_##memberName()						\
	{															\
		return m_s##memberName;									\
	}															\
	inline void put_##memberName(const std::string& newVal)		\
	{															\
		m_s##memberName = newVal;								\
	}

// JS
#define LINK_PROPERTY_INT_JS(memberName)								\
	inline js_wrapper<int>& get_##memberName()							\
	{																	\
		return m_n##memberName;											\
	}																	\
	inline void put_##memberName(const int& newVal)						\
	{																	\
		m_n##memberName = newVal;										\
	}																	\
	inline void put_##memberName(const js_wrapper<int>& newVal)			\
	{																	\
		m_n##memberName = newVal;										\
	}

#define LINK_PROPERTY_DOUBLE_JS(memberName)								\
	inline js_wrapper<double>& get_##memberName()						\
	{																	\
		return m_d##memberName;											\
	}																	\
	inline void put_##memberName(const double& newVal)					\
	{																	\
		m_d##memberName = newVal;										\
	}																	\
	inline void put_##memberName(const js_wrapper<double>& newVal)		\
	{																	\
		m_d##memberName = newVal;										\
	}

#define LINK_PROPERTY_BOOL_JS(memberName)								\
	inline js_wrapper<bool>& get_##memberName()							\
	{																	\
		return m_b##memberName;											\
	}																	\
	inline void put_##memberName(const bool& newVal)					\
	{																	\
		m_b##memberName = newVal;										\
	}																	\
	inline void put_##memberName(const js_wrapper<bool>& newVal)		\
	{																	\
		m_b##memberName = newVal;										\
	}

#define LINK_PROPERTY_BYTE_JS(memberName)								\
	inline js_wrapper<unsigned char>& get_##memberName()				\
	{																	\
		return m_n##memberName;											\
	}																	\
	inline void put_##memberName(const unsigned char& newVal)			\
	{																	\
		m_n##memberName = newVal;										\
	}																	\
	inline void put_##memberName(const js_wrapper<unsigned char>& newVal)		\
	{																	\
		m_n##memberName = newVal;										\
	}

#define LINK_PROPERTY_STRING_JS(memberName)									\
	inline js_wrapper<std::wstring>& get_##memberName()						\
	{																		\
		return m_s##memberName;												\
	}																		\
	inline void put_##memberName(const std::wstring& newVal)				\
	{																		\
		m_s##memberName = newVal;											\
	}																		\
	inline void put_##memberName(const js_wrapper<std::wstring>& newVal)	\
	{																		\
		m_s##memberName = newVal;											\
	}

#define LINK_PROPERTY_STRINGA_JS(memberName)								\
	inline js_wrapper<std::string>& get_##memberName()						\
	{																		\
		return m_s##memberName;												\
	}																		\
	inline void put_##memberName(const std::string& newVal)					\
	{																		\
		m_s##memberName = newVal;											\
	}																		\
	inline void put_##memberName(const js_wrapper<std::string>& newVal)		\
	{																		\
		m_s##memberName = newVal;											\
	}

#define LINK_PROPERTY_OBJECT_JS(objectType, memberName)						\
	inline js_wrapper<objectType>& get_##memberName()						\
	{																		\
		return m_o##memberName;												\
	}																		\
	inline void put_##memberName(const js_wrapper<objectType>& newVal)		\
	{																		\
		m_o##memberName = newVal;											\
	}																		\
	inline void put_##memberName(objectType* newVal)						\
	{																		\
		m_o##memberName = newVal;											\
	}

template<typename Type>
class js_wrapper
{
protected:
	Type* m_pPointer;
	bool m_bIsNull;

public:
	js_wrapper()
	{
		m_pPointer = NULL;
		m_bIsNull = false;
	}
	js_wrapper(const js_wrapper<Type>& oOther)
	{
		m_pPointer = NULL;
		
		if (oOther.m_bIsNull)
			m_bIsNull = true;
		else
		{
			m_bIsNull = false;

			if ( NULL != oOther.m_pPointer )
				m_pPointer = new Type( (const Type&)*(oOther.m_pPointer) );
		}
	}
	js_wrapper(Type* pOther)
	{
		m_pPointer = pOther;
		m_bIsNull = false;
	}
	virtual ~js_wrapper()
	{
		if (NULL != m_pPointer)
			delete m_pPointer;
	}

public:
	inline Type& operator*()  { return *m_pPointer; }
	inline Type* operator->() { return  m_pPointer; }

	inline Type& operator*() const  { return *m_pPointer; }
	inline Type* operator->() const { return  m_pPointer; }

	inline const Type& get()const { return  *m_pPointer; } 
	inline Type& get() { return  *m_pPointer; }

public:
	js_wrapper<Type>& operator=(const js_wrapper<Type> &oOther)
	{
		if (NULL != m_pPointer)
		{
			delete m_pPointer;
			m_pPointer = NULL;
		}

		if (oOther.m_bIsNull)
			m_bIsNull = true;
		else
		{
			m_bIsNull = false;

			if ( NULL != oOther.m_pPointer )
				m_pPointer = new Type( (const Type&)*(oOther.m_pPointer) );
		}
		return *this;
	}
	js_wrapper<Type>& operator=(Type* pType)
	{
		if (NULL != m_pPointer)
			delete m_pPointer;

		m_pPointer	= pType;
		m_bIsNull = false;
		return *this;
	}
	js_wrapper<Type>& operator=(const Type& oSrc)
	{
		if (NULL != m_pPointer)
			delete m_pPointer;

		m_pPointer	= new Type(oSrc);
		m_bIsNull = false;
		return *this;
	}

public:
	inline bool IsNull() const
	{ 
		return m_bIsNull;
	}
	inline bool IsUndefined() const
	{ 
		return (NULL == m_pPointer);
	}
	inline bool IsInit() const
	{
		return ((NULL != m_pPointer) && !m_bIsNull);
	}
	inline void SetNull()
	{
		m_bIsNull = true;
	}
};

}

#endif //_BUILD_EDITOR_DEFINES_CROSSPLATFORM_H_