

#ifndef _REINSGN_H_
#define _REINSGN_H_


#define REIN_ELEM_ISO						1 // ось стержня
#define REIN_ELEM_BAR						2 // трехмерный стержень
#define REIN_ELEM_AXIS						3 // ReinBar
#define REIN_ELEM_RND						4 // развертка

#define REIN_MAIN_SPACE						1 
#define REIN_MAIN_BAR						2 

#define BT_AXIS						0 
#define BT_GIB						1 // flower
#define BT_SEC						2 // section
#define BT_PAR						3 // stream
#define BT_AUTO						4 

#define MAX_BAR_VERTICES				15
#define MAX_BAR_LENS					30

#define MAX_REFNUM_PATH					100

#define RFA_NONE						0
#define RFA_ARCP						1 // arc point
#define RFA_CIRP						2 // circle point
#define RFA_ENDP						4 // end point of visible clipped part
#define RFA_ENDC						8 // end point of bar
#define RFA_RELP						16 // флаг показывающий что точка сущетсвует в реальной оси, не точка обрезанная клипом
#define RFA_TELP						32 // точка обрезания клипом референса
#define RFA_ARCB						64 // ARC BEND - точка (предполагаемого?) загиба при соединении дугового сегмента

#define ROUND_STD						0 // ROUND_ANG
#define ROUND_ARC						1
#define ROUND_LIN						2




#if defined (MSVERSION) && (MSVERSION == 0xa00)

#define WCH WChar
#define WCHP WChar*
#define WCHCP WCharCP
#define WCHCP_ WCharCP
#define MSWCH WChar
#define MSWCHCP WCharCP
#define STRING wstring
#define BINT bool
#define IcnRsc IconRsc

#define CLIPDESC ClipVectorPtr
#define MSDLGP MSDialogP
#define MSWNDP MSWindowP
#define VIEWDRAW IViewDrawR

#define ISNULL(ptr) ptr ## .IsNull()
#define NOTNULL(ptr) ! ## ptr ## .IsNull()
#define GETPTR(ptr) ptr ## .get()

#define L(str) L##str
#define SCPY wcscpy
#define SCNPY wcsncpy
#define SCPW2M(dst,src,len) wcsncpy(dst,src,len)
#define SCPM2W(dst,src,len) wcsncpy(dst,src,len)
#define SCAT wcscat
#define SLEN wcslen
#define SPRN _swprintf
#define SCMP wcscmp
#define SCNP wcsncmp
#define SSTR wcsstr
#define STOUL wcstoul
#define STOI _wtoi
#define STOL _wtol
#define STOF _wtof
#define SSCAN swscanf
#define STOK wcstok
#define elementRef_isElementDeleted elementRef_isDeleted
#define mdlText_createWide mdlText_create

#define GETELDSCP GetElementDescrCP
#define GETELREF GetElementRef

#define ELHCP ElementHandleCP
#define ELH ElementHandle
#define VCNTXP ViewContextP

#define ELREF ElementRefP
#define ELID ElementId
#define LEVID LevelId
#define ELCLASS DgnElementClass
#define MSWideChar WChar

#define DRAWMODE DgnDrawMode
//#define DRAW_MODE_Normal DgnDrawMode::DRAW_MODE_Normal

#define MSINPUTQ_HEAD MSInputQueuePos::INPUTQ_HEAD

#define MESSAGE_WARNING OutputMessagePriority::Warning
#define MESSAGE_INFO OutputMessagePriority::Info
#define MESSAGE_ERROR OutputMessagePriority::Error

#define MESSAGE_ALERT_BALLOON OutputMessageAlert::Balloon
#define MESSAGE_ALERT_NONE OutputMessageAlert::None
#define MESSAGE_ALERT_DIALOG OutputMessageAlert::Dialog

#define MSGBOX_ICON_INFORMATION MessageBoxIconType::Information
#define MSGBOX_ICON_WARNING MessageBoxIconType::Warning
#define MSGBOX_ICON_QUESTION MessageBoxIconType::Question
#define MSGBOX_ICON_NOSYMBOL MessageBoxIconType::NoSymbol


#define TXTLINESPACING_EXACTFROMLINETOP 2
#define MSTextSize TextSizeParam

#define ComponentMode_None ComponentMode::None
//#define ELEMENT_CATEGORY_NONMODEL DgnModelSections::Dictionary

#define REFLOGICAL(rfP) rfP ## ->GetLogicalName()

#define DRAW_PURPOSE_FenceAccept DrawPurpose::FenceAccept
#define DRAW_PURPOSE_GenerateThumbnail DrawPurpose::GenerateThumbnail
#define DRAW_PURPOSE_Plot DrawPurpose::Plot
#define DRAW_PURPOSE_Update DrawPurpose::Update
#define DRAW_PURPOSE_ForceRedraw DrawPurpose::ForceRedraw
#define DRAW_PURPOSE_UpdateHealing DrawPurpose::UpdateHealing
#define DRAW_PURPOSE_Pick DrawPurpose::Pick
#define LevelElementAccess_All LevelElementAccess::All
#define ELEMENT_CATEGORY_GRAPHICS DgnModelSections::GraphicElements

#define DIMTYPE_SIZE_ARROW DimensionType::SizeArrow

#define VIEW_LEVEL_DISPLAY_TYPE_NORMAL ViewLevelDisplayType::Normal
#define VIEW_INGLOBALCOORDS DgnCoordSystem::Root
#define COORDSYS_Root DgnCoordSystem::Root

#define CFGVAR_LEVEL_USER DgnPlatform::ConfigurationVariableLevel::User

#define DIMTYPE_NOTE DimensionType::Note


#define FOPENA(pth) _wfopen(pth, L"a")
#define FOPENW(pth) _wfopen(pth, L"w")
#define FOPENR(pth) _wfopen(pth, L"r")
#define FCLOSE fclose
#define FDELETE _wremove
#define FGETS(s,q,f) fgetws (s, q, f)

#define PRINTF wprintf
#define SETCOLOR SetIndexedLineColorTBGR

//#define VECPTR(v) v ## ._Ptr

#define SetIndLineColor SetIndexedLineColorTBGR


#define   func_pma(a,b) a ## (b
#define   func_amp(a,b) a ## (&b
#define   func_ast(a,b) a ## (b

#define PD(output) output ## .
#define PDA(output,func) output ## . ## func(

//#define MAP unordered_map
//#define MAP map

#define mdlKISolid_beginCurrTrans mdlSolid_beginCurrTrans
#define mdlKISolid_makeCuboid mdlSolid_makeCuboid
#define mdlKISolid_bodyToElement mdlSolid_bodyToElement
#define mdlKISolid_endCurrTrans mdlSolid_endCurrTrans
#define mdlKISolid_freeBody mdlSolid_freeBody

#define mdlOutput_messageCenterW mdlOutput_messageCenter


#else // v8i

#define CmdHandler void (__cdecl *)(char *)
#define CommandTable Table

#define WCH char
#define WCHP char*
#define WCHCP const char*
#define WCHCP_ char*
#define MSWCH MSWChar
#define MSWCHCP MSWCharCP
#define STRING string
#define BINT BoolInt
//#define Int64 __int64
#define IcnRsc void

#define CLIPDESC ClipDescrP
#define MSDLGP DialogBox*
#define MSWNDP GuiWindowP
#define VIEWDRAW IViewDrawP

#define ISNULL(ptr) ptr ## ==NULL
#define NOTNULL(ptr) ptr ## !=NULL
#define GETPTR(ptr) ptr

#define L(str) str
#define SCPY strcpy
#define SCNPY strncpy
#define SCPW2M(dst,src,len) mdlCnv_convertUnicodeToMultibyte(src, -1, dst, len)
#define SCPM2W(dst,src,len) mdlCnv_convertMultibyteToUnicode(src, -1, dst, len)
#define SCAT strcat
#define SLEN strlen
#define SPRN sprintf
#define SCMP strcmp
#define SCNP strncmp
#define SSTR strstr
#define STOUL strtoul
#define STOI atoi
#define STOL atol
#define STOF atof
#define SSCAN sscanf
#define STOK strtok

#define RscId int
#define RscType int
#define InfoField long

#define GETELDSCP GetElemDescrCP
#define GETELREF GetElemRef

#define ELHCP ElemHandleCP
#define ELH Bentley::Ustn::Element::ElemHandle
#define VCNTXP IViewContextP

#define PFElemOperation MdlFunctionP
#define StateFunc_DataPoint MdlFunctionP
#define StateFunc_Reset MdlFunctionP
#define MdlFunc_Accept MdlFunctionP
#define StateFunc_SimpleDynamics MdlFunctionP
#define MdlFunc_Show MdlFunctionP
#define MdlFunc_Clean MdlFunctionP
#define PFToolsSortCompare MdlFunctionP

#define mdlRefFile_getDoubleParameters mdlRefFile_getParameters
#define mdlRefFile_getBooleanParameters mdlRefFile_getParameters
#define mdlRefFile_setBooleanParameters mdlRefFile_setParameters
#define mdlRefFile_getInt64Parameters  mdlRefFile_getParameters
#define mdlRefFile_getIntegerParameters  mdlRefFile_getParameters

#define mdlListCell_setInfoFieldInt32 mdlListCell_setInfoField

#define DgnAttachmentP ReferenceFile*
#define REFLOGICAL(rfP) rfP ## ->attach.logicalName

#define FOPENA(pth) mdlTextFile_open(pth, TEXTFILE_APPEND)
#define FOPENW(pth) mdlTextFile_open(pth, TEXTFILE_WRITE)
#define FOPENR(pth) mdlTextFile_open(pth, TEXTFILE_READ)
#define FCLOSE mdlTextFile_close
#define FDELETE remove
#define FGETS(s,q,f) mdlTextFile_getString (s, q, f, TEXTFILE_DEFAULT)

#define PRINTF printf

#define SETCOLOR SetIndexedLineColor

//#define VECPTR(v) v ## ._Myptr

#define ELREF ElementRef
#define ELID ElementID
#define LEVID LevelID
#define ELCLASS int
#define DRAWMODE MstnDrawMode
//#define DRAW_MODE_Normal NORMALDRAW
//#define DRAW_MODE_Erase ERASE
#define MSINPUTQ_HEAD 0
#define CommandNumber UInt32
#define RedrawElems Bentley::Ustn::RedrawElems
#define LevelElementAccess UShort
#define LevelElementAccess_All 0

#define ComponentMode_None 0

#define UnloadProgramReason int


/*   Text Justifications   */
//#define     TXTJUST_LT                  0       /* Left Top */
//#define     TXTJUST_LC                  1       /* Left Center */
//#define     TXTJUST_LB                  2       /* Left Bottom */
//#define     TXTJUST_LMT                 3       /* Left Margin Top */
//#define     TXTJUST_LMC                 4       /* Left Margin Center */
//#define     TXTJUST_LMB                 5       /* Left Margin Bottom */
//#define     TXTJUST_CT                  6       /* Center Top */
//#define     TXTJUST_CC                  7       /* Center Center */
//#define     TXTJUST_CB                  8       /* Center Bottom */
//#define     TXTJUST_RMT                 9       /* Right Margin Top */
//#define     TXTJUST_RMC                 10      /* Right Margin Center */
//#define     TXTJUST_RMB                 11      /* Right Margin Bottom */
//#define     TXTJUST_RT                  12      /* Right Top */
//#define     TXTJUST_RC                  13      /* Right Center */
//#define     TXTJUST_RB                  14      /* Right Bottom */
//
//#define     TXTJUST_LU                  15      /* Left Cap */
//#define     TXTJUST_LD                  16      /* Left Descender */
//#define     TXTJUST_LMU                 17      /* Left Margin Cap */
//#define     TXTJUST_LMD                 18      /* Left Margin Descender */
//#define     TXTJUST_CU                  19      /* Center Cap */
//#define     TXTJUST_CD                  20      /* Center Descender */
//#define     TXTJUST_RMU                 21      /* Right Margin Cap */
//#define     TXTJUST_RMD                 22      /* Right Margin Descender */
//#define     TXTJUST_RU                  23      /* Right Cap */
//#define     TXTJUST_RD                  24      /* Right Descender */
//#define     TXTJUST_NONE                127     /* no justfication */
#define TextElementJustification int

#define   func_pma(a,b) a ## (&b
#define   func_amp(a,b) a ## (b
#define   func_ast(a,b) a ## (*b

#define PD(output) output ## ->
#define PDA(output,func) output ## -> ## func(&

//#define MAP map

#define SetIndLineColor SetIndexedLineColor

#define BODY_TAG KIBODY*

#endif






#endif