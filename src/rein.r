
#include "vers.h"


#if defined (MSVERSION) && (MSVERSION == 0xa00) // includes

#include <Mstn\MdlApi\dlogids.r.h>
#include <Mstn\MicroStation.r.h>
#include <Mstn\MdlApi\dlogbox.r.h>
#include <Mstn\MdlApi\keys.r.h>
#include <Mstn\cmdlist.r.h>

#include <Mstn\MdlApi\rscdefs.r.h>
#include <Mstn\MdlApi\cmdclass.r.h>
//#include <Mstn\MdlApi\dlogbox.r.h>
#include <Mstn\cmdlist.r.h>

#include "reinccmd.h"


#else

#include <rscdefs.h>
#include <dlogbox.h>
#include <dlogids.h>
#include <cmdlist.h>
#include <keys.h>

#include "reincmd.h"


#endif

#include "rein.h"
#include "reinsgn.h"

#if defined (LANG_EN)
#include "reintxte.h"
#else
#include "reintxt.h"
#endif





//enum DllIds	{     DLLAPPID 	= 1, };

#define  DLLAPP_PRIMARY     1

/* associate app with dll */
DllMdlApp   DLLAPP_PRIMARY = 
    {
    L("rein"), L("rein")
    }


CmdItemListRsc ItemList_REIN_PLACE =
    {{
{{0.00*XC,0.5*YC,0,0}, OptionButton, 2, ON, 0, "", ""},
{{0.00*XC,2.0*YC,0,0}, OptionButton, 10, ON, 0, "", ""},
{{0.00*XC,3.5*YC,0,0}, OptionButton, 6, OFF, 0, "", ""},
{{0.00*XC,5.0*YC,0,0}, Text, 71, ON, 0, "", ""},
{{0.00*XC,6.5*YC,0,0}, Text, 72, ON, 0, "", ""},
{{0.00*XC,8.0*YC,0,0}, OptionButton, 73, ON, 0, "", ""},
{{0.00*XC,9.5*YC,0,0}, Text, 3, ON, 0, "", ""},
{{0.00*XC,11.0*YC,0,0}, Text, 4, ON, 0, "", ""},
{{0.00*XC,12.5*YC,0,0}, Text, 5, ON, 0, "", ""},
{{0.00*XC,14.0*YC,0,0}, Text, 15, ON, 0, "", ""},
//{{0.00*XC,15.5*YC,0,0}, Text, 21, ON, 0, "", ""},
//{{0.00*XC,17.0*YC,0,0}, Text, 23, ON, 0, "", ""},
//{{0.00*XC,18.5*YC,0,0}, Text, 22, ON, 0, "", ""},
	}};

#if defined (MSVERSION) && (MSVERSION == 0xa00) // cmd
CmdItemListRsc ItemList_REIN_POS_DRAW =
#else
CmdItemListRsc CMD_REIN_POS_DRAW =
#endif
    {{
{{0.00*XC,0.5*YC,0,0}, Text, 201, ON, 0, "", ""},
{{0.00*XC,2.0*YC,0,0}, Text, 202, ON, 0, "", ""},
{{0.00*XC,3.5*YC,0,0}, Text, 203, ON, 0, "", ""},
{{0.00*XC,5.0*YC,0,0}, Text, 204, ON, 0, "", ""},
{{0.00*XC,6.5*YC,0,0}, Text, 205, ON, 0, "", ""},
{{0.00*XC,8.0*YC,20*XC, 0}, ComboBox, COMBOBOXID_TextFontName, ON, 0, "Шрифт", ""},
{{0.00*XC,9.5*YC,0,0}, Text, TEXTID_TextHeight, ON, 0, "Высота текста", ""},
{{0.00*XC,11.0*YC,0,0}, Text, TEXTID_TextWidth, ON, 0, "Ширина текста", ""},
{{0.00*XC,12.5*YC,0,0}, ToggleButton, 260, ON, 0, "", ""},
{{0.00*XC,15.0*YC,20*XC,0}, Scale, 1, ON, 0, "", ""},
{{0.00*XC,17.5*YC,20*XC,0}, Scale, 2, ON, 0, "", ""},
	}};


DItem_ScaleRsc 1 = 
{ 
	NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
	NOHOOK, NOARG, 
	10.0, 90.0, 1.0, 5.0, 0, 
	SCALE_HASARROWS | SCALE_SHOWVALUE, "%.0lf", TXT_116, "skperhgt", "10%", "90%"
}; 

DItem_ScaleRsc 2 = 
{ 
	NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
	NOHOOK, NOARG, 
	10.0, 90.0, 1.0, 5.0, 0, 
	SCALE_HASARROWS | SCALE_SHOWVALUE, "%.0lf", TXT_117, "skperwdt", "10%", "90%"
}; 

DItem_ScaleRsc 3 = 
{ 
	NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
	NOHOOK, NOARG, 
	0.0, 1.0, 0.05, 0.1, 0, 
	SCALE_HASARROWS | SCALE_SHOWVALUE, "%.2f", TXT_118, "notetxtmrgn", "", ""
}; 


#if defined (MSVERSION) && (MSVERSION == 0xa00) // cmd
CmdItemListRsc ItemList_REIN_BARSET =
#else
CmdItemListRsc CMD_REIN_BARSET =
#endif
    {{
{{05.00*XC,0.50*YC,0,0}, OptionButton, 95, ON, 0, "", ""},
{{05.00*XC,2.00*YC,0,0}, ToggleButton, 252, ON, 0, "", ""},
{{05.00*XC,3.50*YC,0,0}, ToggleButton, 253, ON, 0, "", ""},
	}};


DItem_TextRsc TEXTID_BarOverMoveX =
{
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    HOOKID_DIALOG, NOARG,
    8, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED,
    "X:",
    "bmx"
};

DItem_ToggleButtonRsc TOGGLEID_BarOverMoveX =
{
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ibmx"
};

DItem_TextRsc TEXTID_BarOverMoveY =
{
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    HOOKID_DIALOG, NOARG,
    8, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED,
    "Y:",
    "bmy"
};

DItem_ToggleButtonRsc TOGGLEID_BarOverMoveY =
{
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ibmy"
};

DItem_TextRsc TEXTID_BarOverMoveZ =
{
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    HOOKID_DIALOG, NOARG,
    8, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED,
    "Z:",
    "bmz"
};

DItem_ToggleButtonRsc TOGGLEID_BarOverMoveZ =
{
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ibmz"
};

DItem_ToggleButtonRsc TOGGLEID_BarOverGround =
{
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_109,
    "igrnd"
};

DItem_ToggleButtonRsc TOGGLEID_LockGraphicGroup =
{
    NOCMD, MCMD, SYNONYMID_LockGraphicGroup, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_110,
    "tcb->fbfdcn.gglk"
}
extendedAttributes
{ {
{EXTATTR_FLYTEXT, TXT_104}, /* Appears in statusarea */
{EXTATTR_BALLOON, TXT_104}, /* Appears in pop-up */
} }
;



#if defined (MSVERSION) && (MSVERSION == 0xa00) // cmd
CmdItemListRsc ItemList_REIN_BAROVER =
#else
CmdItemListRsc CMD_REIN_BAROVER =
#endif
    {{
{{05.00 * XC,0.50 * YC,0,0}, OptionButton, OPTIONBUTTONID_BarOver, ON, 0, "", ""},

{{0.00 * XC,2.5 * YC,0,0}, Text, TEXTID_BarOverMoveX, ON, 0, "", ""},
{{12.0 * XC,2.5 * YC,0,0}, ToggleButton, TOGGLEID_BarOverMoveX, ON, 0, "", ""},

{{0.00 * XC,4.0 * YC,0,0}, Text, TEXTID_BarOverMoveY, ON, 0, "", ""},
{{12.0 * XC,4.0 * YC,0,0}, ToggleButton, TOGGLEID_BarOverMoveY, ON, 0, "", ""},

{{0.00 * XC,5.5 * YC,0,0}, Text, TEXTID_BarOverMoveZ, ON, 0, "", ""},
{{12.0 * XC,5.5 * YC,0,0}, ToggleButton, TOGGLEID_BarOverMoveZ, ON, 0, "", ""},

{{0.00 * XC,7.0 * YC,0,0}, ToggleButton, TOGGLEID_BarOverGround, ON, 0, "", ""},
    }};



#if defined (MSVERSION) && (MSVERSION == 0xa00) // cmd
CmdItemListRsc ItemList_REIN_BARVIEW =
#else
CmdItemListRsc CMD_REIN_BARVIEW =
#endif
    {{
{{05.00 * XC,0.50 * YC,0,0}, OptionButton, OPTIONBUTTONID_BarView, ON, 0, "", ""},
    }};


#if defined (MSVERSION) && (MSVERSION == 0xa00) // cmd
CmdItemListRsc ItemList_REIN_MODIFY =
#else
CmdItemListRsc CMD_REIN_MODIFY =
#endif
    {{
//...
{{0.00*XC,0.5*YC,0,0}, OptionButton, 51, ON, 0, "", ""},
{{16.0*XC,0.5*YC,0,0},		ToggleButton, 51, ON, 0, "", ""},
//{{16.0*XC,0.5*YC,0,0},		ToggleButton, 300, ON, 0, "", ""},
//...

{{0.00*XC,2.0*YC,0,0}, OptionButton, 2, ON, 0, "", ""},
{{16.0*XC,2.0*YC,0,0},		ToggleButton, 2, ON, 0, "", ""},

{{0.00*XC,3.5*YC,0,0}, OptionButton, 10, ON, 0, "", ""},
{{16.0*XC,3.5*YC,0,0},		ToggleButton, 10, ON, 0, "", ""},

{{0.00*XC,5.0*YC,0,0}, Text, 71, ON, 0, "", ""},
{{16.0*XC,5.0*YC,0,0},		ToggleButton, 71, ON, 0, "", ""},

{{0.00*XC,6.5*YC,0,0}, Text, 72, ON, 0, "", ""},
{{16.0*XC,6.5*YC,0,0},		ToggleButton, 72, ON, 0, "", ""},

{{0.00*XC,8.0*YC,0,0}, OptionButton, 73, ON, 0, "", ""},
{{16.0*XC,8.0*YC,0,0},		ToggleButton, 73, ON, 0, "", ""},

{{0.00*XC,9.5*YC,0,0}, Text, DLGITEM_TEXT_SPACE, ON, 0, "", ""},
//{{9.00*XC,9.5*YC,0,0}, Text, DLGITEM_TEXT_SPACE_2, ON, 0, "", ""},
{{16.0*XC,9.5*YC,0,0}, ToggleButton, 3, ON, 0, "", ""},

//...
{{0.00*XC,11.0*YC,0,0}, Text, 52, ON, 0, "", ""},
{{16.0*XC,11.0*YC,0,0},		ToggleButton, 52, ON, 0, "", ""},
//...

{{0.00*XC,12.5*YC,0,0}, Text, 4, ON, 0, "", ""},
{{16.0*XC,12.5*YC,0,0},		ToggleButton, 4, ON, 0, "", ""},

{{0.00*XC,14.0*YC,0,0}, Text, 5, ON, 0, "", ""},
{{16.0*XC,14.0*YC,0,0},		ToggleButton, 5, ON, 0, "", ""},

{{0.00*XC,15.5*YC,0,0}, Text, 15, ON, 0, "", ""},
{{12.0*XC,15.5*YC,0,0},		ToggleButton, TOGGLE_RepairBend, OFF, 0, "", ""},
{{16.0*XC,15.5*YC,0,0},		ToggleButton, 15, ON, 0, "", ""},

{{0.00*XC,17.0*YC,0,0},	OptionButton, 78, ON, 0, "", ""},
{{16.0*XC,17.0*YC,0,0},		ToggleButton, 78, ON, 0, "", ""},

{{0.00*XC,18.5*YC,0,0},	OptionButton, 11, ON, 0, "", ""},
{{16.0*XC,18.5*YC,0,0},		ToggleButton, 11, ON, 0, "", ""},

{{0.00*XC,20.0*YC,0,0},	OptionButton, 16, ON, 0, "", ""},
//{{0.00*XC,20.0*YC,0,0}, Text, 16, ON, 0, "", ""},
{{0.00*XC,20.0*YC,0,0}, OptionButton, ITEMID_TERMBEG, ON, 0, "", ""},
{{6.00*XC,20.0*YC,0,0}, Text, ITEMID_TERMBEG, ON, 0, "", ""},
{{16.0*XC,20.0*YC,0,0},		ToggleButton, 16, ON, 0, "", ""},

{{0.00*XC,21.5*YC,0,0},	OptionButton, 12, ON, 0, "", ""},
{{16.0*XC,21.5*YC,0,0},		ToggleButton, 12, ON, 0, "", ""},

{{0.00*XC,23.0*YC,0,0},	OptionButton, 18, ON, 0, "", ""},
//{{0.00*XC,23.0*YC,0,0}, Text, 18, ON, 0, "", ""},
{{0.00*XC,23.0*YC,0,0}, OptionButton, ITEMID_TERMEND, ON, 0, "", ""},
{{6.00*XC,23.0*YC,0,0}, Text, ITEMID_TERMEND, ON, 0, "", ""},
{{16.0*XC,23.0*YC,0,0},		ToggleButton, 18, ON, 0, "", ""},

//{{0.00*XC,20.0*YC,0,0},	OptionButton, 94, ON, 0, "", ""},
//{{16.0*XC,20.0*YC,0,0},		ToggleButton, 94, ON, 0, "", ""},

//{{0.00*XC,21.5*YC,0,0},	Text, 93, ON, 0, "", ""},
//{{16.0*XC,21.5*YC,0,0},		ToggleButton, 93, ON, 0, "", ""},

{{0.00*XC,24.5*YC,0,0}, Text, TEXTID_BarsForChange, ON, 0, "", ""},
//{{0.00*XC,15.5*YC,0,0}, Text, 23, ON, 0, "", ""},
//{{0.00*XC,17.0*YC,0,0}, Text, 22, ON, 0, "", ""},
//{{0.00*XC,18.5*YC,0,0}, ToggleButton, 7, ON, 0, "", ""},
{{6.0*XC,24.5*YC,0,0}, ToggleButton, TOGGLEID_LockGraphicGroup, ON, 0, "", ""},

	}};

//CmdItemListRsc ItemList_REIN_NOTE =
//    {{
//{{0.00*XC,0.5*YC,0,0}, ToggleButton, 56, ON, 0, "", ""},
//{{0.00*XC,2.0*YC,0,0}, ToggleButton, 57, ON, 0, "", ""},
//{{0.00*XC,3.5*YC,0,0}, ToggleButton, 206, ON, 0, "", ""},
//
//{{0.00*XC,5.5*YC,0,0}, ToggleButton, 205, ON, 0, "", ""},
//	}};


 DItem_ComboBoxRsc COMBOBOX_NoteUpFmt =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
    HOOKID_NOTECOMBO, NOARG,
    40, "", "", "", "", NOMASK,
    0, 5, 1, 0, 0, 
    COMBOATTR_AUTOADDNEWSTRINGS/* | COMBOATTR_SORT | COMBOATTR_LABELABOVE*/, 
    "up",
    "sNoteUpFmt",
	{
	{20*XC, 40, ALIGN_LEFT, ""},
	}
    };

 DItem_ToggleButtonRsc TOGGLE_NoteUpFmt =
     {
     NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
     NOHOOK, NOARG, NOMASK, NOINVERT,
     "",
     "iNoteUpFmt"
     };

 DItem_ComboBoxRsc COMBOBOX_NoteDnFmt =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
    HOOKID_NOTECOMBO, NOARG,
    40, "", "", "", "", NOMASK,
    0, 5, 1, 0, 0, 
    COMBOATTR_AUTOADDNEWSTRINGS/* | COMBOATTR_SORT | COMBOATTR_LABELABOVE*/, 
    "down",
    "sNoteDnFmt",
	{
	{20*XC, 40, ALIGN_LEFT, ""},
	}
    };

 DItem_ToggleButtonRsc TOGGLE_NoteDnFmt =
     {
     NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
     NOHOOK, NOARG, NOMASK, NOINVERT,
     "",
     "iNoteDnFmt"
     };

DItem_TextRsc TEXTID_NoteUp = 
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
    NOHOOK, NOARG, 
    40, "%s", "%s", "", "", NOMASK, 0, 
    "up",
    "sNoteUp"
    };

DItem_TextRsc TEXTID_NoteDn = 
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
    NOHOOK, NOARG, 
    40, "%s", "%s", "", "", NOMASK, 0, 
    "down",
    "sNoteDn"
    };

DItem_OptionButtonRsc  OPTIONBUTTONID_NoteStyle =
    {
    NOSYNONYM, NOHELP, MHELP, NOHOOK, NOARG,
    "",
    "iNoteStyle",
	{
	{NOTYPE, NOICON, NOCMD, LCMD, 0, NOMASK, ON, "full"},
	{NOTYPE, NOICON, NOCMD, LCMD, 1, NOMASK, ON, "simple"},
	{NOTYPE, NOICON, NOCMD, LCMD, 2, NOMASK, ON, "empty"},
	}
    };

 DItem_ComboBoxRsc COMBOBOX_NoteLevels =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
    HOOKID_LEVELCOMBO, NOARG,
    40, "", "", "", "", NOMASK,
    0, 5, 1, 0, 0, 
    COMBOATTR_READONLY /* | COMBOATTR_SORT | COMBOATTR_LABELABOVE*/, 
    "level",
    "sNoteLevel",
	{
	{20*XC, 40, ALIGN_LEFT, ""},
	}
    };

DItem_ToggleButtonRsc TOGGLE_NoteDim =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "arrow range",
    "iNoteDim"
    };

DItem_ToggleButtonRsc TOGGLE_NoteBarSet =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "outer bars",
    "iNoteBarSet"
    };


#if defined (MSVERSION) && (MSVERSION == 0xa00) // cmd
CmdItemListRsc ItemList_REIN_NOTE =
#else
CmdItemListRsc CMD_REIN_NOTE =
#endif
    {{
{{5.00*XC,0.5*YC,0,0}, ComboBox, COMBOBOX_NoteUpFmt, ON, 0, "", ""},
{{5.00*XC,2.0*YC,0,0}, ComboBox, COMBOBOX_NoteDnFmt, ON, 0, "", ""},
{{46.50*XC,0.5*YC,0,0}, ToggleButton, TOGGLE_NoteUpFmt, ON, 0, "", ""},
{{46.50*XC,2.0*YC,0,0}, ToggleButton, TOGGLE_NoteDnFmt, ON, 0, "", ""},

{{5.00*XC,3.5*YC,0,0}, OptionButton, OPTIONBUTTONID_NoteStyle, ON, 0, "", ""},
{{5.00*XC,5.0*YC,0,0}, ToggleButton, TOGGLE_NoteDim, ON, 0, "", ""},
{{5.00*XC,6.2*YC,0,0}, ToggleButton, TOGGLE_NoteBarSet, ON, 0, "", ""},

{{20.0 * XC,3.5*YC,28.0*XC,0}, ComboBox, COMBOBOX_NoteLevels, ON, 0, "", ""},
{{33.0*XC,6.2*YC,15*XC,0}, Scale, 3, ON, 0, "", ""},

{{5.00*XC,8.0*YC,0,0}, Text, TEXTID_NoteUp, OFF, 0, "", ""},
{{5.00*XC,9.5*YC,0,0}, Text, TEXTID_NoteDn, OFF, 0, "", ""},

    }};


//CmdItemListRsc ItemList_REIN_MIRROR =
//    {{
//{{0.00*XC,0.50*YC,0,0}, OptionButton, 7, ON, 0, "", ""},
//{{0.00*XC,2.00*YC,0,0}, ToggleButton, 54, ON, 0, "", ""},
//{{0.00*XC,3.50*YC,0,0}, ToggleButton, 55, ON, 0, "", ""},
//	}};


#if defined (STD_INTERFACE)


DialogBoxRsc DIALOG_TOOLBOX =
    {
    DIALOGATTR_TOOLBOXCOMMON,
    0, 0,
    NOHELP, MHELP, 
    HOOKID_TOOLBOX, NOPARENTID,
    "",
		{
		{{0, 0, 0, 0}, ToolBox, DIALOG_TOOLBOX, ON, 0, "", ""},
		}
    };

#endif

//DialogBoxRsc 3 =
//    {
//    DIALOGATTR_DEFAULT | DIALOGATTR_SINKABLE,
//    100, 100,
//    NOHELP, MHELP, 
//    HOOKID_BARIALOG, NOPARENTID,
//    "Конфигурация стержня",
//		{
//{{0.0,0.0,0,0}, Text, 31, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 32, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 33, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 34, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 35, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 36, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 37, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 38, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 39, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 40, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 41, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 42, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 43, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 44, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 45, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 46, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 47, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 48, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 49, ON, 0, "", ""},
//{{0.0,0.0,0,0}, Text, 50, ON, 0, "", ""},
//		}
//    };

/*
DialogBoxRsc    DLG_LICENSE =
    {
    DIALOGATTR_DEFAULT, 70*XC,23*YC,NOHELP,MHELP,NOHOOK,NOPARENTID, "License",
    {
    {{ 2.0 * XC, 1.0 * YC, 70 * XC, 0}, Label, 1, ON, ALIGN_LEFT | LABEL_FONT_BOLD | LABEL_WORDWRAP, "", ""},
    {{ 10.0 * XC, 20.0 * YC, BUTTON_STDWIDTH, 0}, PushButton, BUTTON_AGREE, ON, 0, "", ""},
	}
    };
*/


//{ {10 * XC, 20 * YC, BUTTON_STDWIDTH, 0}, PushButton, 7, ON, 0, "", "",


DialogBoxRsc    DLG_POSLIST =
    {
    DIALOGATTR_DEFAULT|DIALOGATTR_MOTIONTOITEMS, 95*XC,26.0*YC,NOHELP,MHELP,NOHOOK,NOPARENTID, TXT_1,
    {
    {{  0.8*XC, 3.5*YC, 0, 0},   ListBox, LISTBOX_POSITIONS, ON,0,"",""},
	//{{ 84.5*XC, 2.4*YC, 32.5*XC, 150}, Generic, 2, ON, 0, "", ""},
    {{ 12.0*XC, 0.5*YC, 23.0*XC, 0},   ComboBox, COMBOBOX_POSITIONS_REFS, ON, 0, "", ""},
    {{ 35.0*XC, 0.4*YC, 12.0*XC, 1.5*YC},   PushButton, BUTTON_POSLIST, ON, 0, "", ""},
    {{ 77.5*XC, 0.4*YC, 12.0*XC, 1.5*YC},   PushButton, BUTTON_POSNUM, ON, 0, "", ""},
    {{ 90.0*XC, 0.4*YC, 4.0*XC, 1.5*YC},   PushButton, BUTTON_DBSAVE, ON, 0, "", ""},
//{{90.0*XC,0.4*YC,0,0}, IconCmd, ICONCMDID_PlaceLineAA, ON, 2, "", "owner=\"REIN\""},
    {{ 50.0*XC, 0.4*YC, 12.0*XC, 1.5*YC},   PushButton, BUTTON_POSDRAW, ON, 0, "", ""},
	{{ 70.0*XC, 0.5*YC, 0, 0}, Text, 101, ON, 0, "", ""},
	{{ 1.0*XC, 25.0*YC, 90*XC, 1.5*YC}, Label, 1, ON, ALIGN_LEFT|LABEL_FONT_BOLD|LABEL_WORDWRAP, "", ""},
	//{{ 1.0*XC, 26.5*YC, 90*XC, 1.5*YC}, Label, 2, ON, ALIGN_LEFT|LABEL_FONT_BOLD|LABEL_WORDWRAP, "", ""},
    //{{0, 0, 0, 0}, PopupMenu, 1, HIDDEN, 0, "", ""} ,
	}
    };

//DialogBoxRsc    9 =
//    {
//    DIALOGATTR_DEFAULT|DIALOGATTR_MOTIONTOITEMS, 37*XC,27.0*YC,NOHELP,MHELP,NOHOOK,NOPARENTID,"Расчет муфт",
//    {
//    {{  0.8*XC, 3.5*YC, 0, 0},   ListBox,2,ON,0,"",""},
//    {{ 10.0*XC, 0.5*YC, 23.0*XC, 0},   ComboBox, 1, ON, 0, "", ""},
//    {{ 0.8*XC, 25.0*YC, 12.0*XC, 1.5*YC},   PushButton, 2, ON, 0, "", ""},
//	}
//    };



DialogBoxRsc    5 =
    {
    DIALOGATTR_DEFAULT, 61*XC,14.5*YC,NOHELP,MHELP,HOOKID_ANKERDIALOG,NOPARENTID, TXT_2,
    {
{{20.00*XC,0.5*YC,0,0}, OptionButton, 5, ON, 0, "", ""},
{{20.00*XC,2.0*YC,0,0}, Text, 60, ON, 0, "", ""},
{{20.00*XC,3.5*YC,0,0}, OptionButton, 3, ON, 0, "", ""},
{{20.00*XC,5.0*YC,0,0}, OptionButton, 4, ON, 0, "", ""},
//{{0,6.8*YC,0,0}, Separator, 0, ON, 0, "", ""},
{{20.00*XC,7.5*YC,0,0}, Text, 61, ON, 0, "", ""},
{{20.00*XC,9.0*YC,0,0}, Text, 62, ON, 0, "", ""},
{{20.00*XC,10.5*YC,0,0}, Text, 63, ON, 0, "", ""},
{{5.00*XC,12.0*YC,0,0}, PushButton, 1, OFF, 0, "", ""},
{{30.00*XC,0.5*YC, 15*YC, 12*YC}, Generic, 1, ON, 0, "", ""},
	}
    };

//StringList 1 =
//{
//  4,
//  {
//    { {0, 0, ICONID_ToggleOn14Pt, 0}, "V Row 22" },
//    { {0, 0, ICONID_ToggleOn14Pt, 0}, "W Row 23" },
//    { {0, 0, ICONID_ToggleOn14Pt, 0}, "X Row 24" },
//    { {0, 0, ICONID_ToggleOn14Pt, 0}, "Y Row 25" },
//    { {0, 0, ICONID_ToggleOn14Pt, 0}, "Z Row 26" },
//    { {0, 0, ICONID_ToggleOn14Pt, 0}, "Y Row 25" },
//    { {0, 0, ICONID_ToggleOn14Pt, 0}, "Z Row 26" },
//    { {0, 0, ICONID_ToggleOn14Pt, 0}, "Y Row 25" },
//    { {0, 0, ICONID_ToggleOn14Pt, 0}, "Z Row 26" },
//  }
//};

DItem_ComboBoxRsc COMBOBOX_POSITIONS_REFS =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
    HOOKID_REFCOMBO, NOARG,
    20, "", "", "", "", NOMASK,
    0, // Id of initial string list used 
	15, // Number of rows to show in list 
	1, // Gap between textedit & button 
	40*XC, // Width of dropdown listbox
	1, // Index of Column to get value from
    COMBOATTR_READONLY /* | COMBOATTR_SORT | COMBOATTR_LABELABOVE*/, 
    TXT_3,
    "",
{
{5*XC, 10, ALIGN_LEFT, ""},
{30*XC, 30, ALIGN_LEFT, ""},
}
    };


// "Расчет выпусков" // projecting reinforcement
DialogBoxRsc    8 =
    {
    DIALOGATTR_DEFAULT, 30*XC,12.0*YC,NOHELP,MHELP,HOOKID_ANKERDIALOG,NOPARENTID, TXT_4,
    {
{{16.00*XC,0.5*YC,0,0}, Text, 81, ON, 0, "", ""},
{{16.00*XC,2.0*YC,0,0}, Text, 82, ON, 0, "", ""},
{{05.00*XC,3.5*YC,0,0}, ToggleButton, 250, ON, 0, "", ""},
{{05.00*XC,5.0*YC,0,0}, ToggleButton, 251, ON, 0, "", ""},
{{20.00*XC,6.5*YC,0,0}, Text, 83, ON, 0, "", ""},
{{20.00*XC,8.0*YC,0,0}, Text, 84, ON, 0, "", ""},
{{10.00*XC,9.5*YC,0,0}, PushButton, 2, ON, 0, "", ""},
	}
    };


DialogBoxRsc    DLG_PRESENT =
    {
    DIALOGATTR_DEFAULT, 45*XC,25.0*YC,NOHELP,MHELP,HOOKID_SHOWOPTIONS,NOPARENTID, TXT_5,
    {
//{{20.0*XC,0.5*YC,20*XC,0}, OptionButton, OPTIONBUTTONID_PresOpt, ON, 0, "", ""},
{{20.0*XC,0.5*YC,23.0*XC,0}, ComboBox, COMBOBOX_SHOWPREF_REFS, ON, 0, "", ""},
{{1.0*XC,2.0*YC,0,0}, ToggleButton, ICONCMDID_rein_cont, ON, 0, "", ""},	//rInfo.option[2]	"Образующий элемент контура армирования"
{{1.0*XC,3.5*YC,0,0}, ToggleButton, ICONCMDID_rein_bars, ON, 0, "", ""},	//rInfo.option[4]	"Образующий элемент отдельного стержня"
{{1.0*XC,5.0*YC,0,0}, ToggleButton, ICONCMDID_rein_fcont, ON, 0, "", ""},	//rInfo.option[5]	"Производный элемент (ось стержня)"
{{2.5*XC,6.5*YC,0,0}, ToggleButton, ICONCMDID_rein_transp, ON, 0, "", ""},	//rInfo.option[1]	"Внутренние (прозрачные) стержни контура"
{{4.0*XC,8.0*YC,0,0}, ToggleButton, ICONCMDID_rein_trsec, ON, 0, "", ""},	//rInfo.option[17]	"Внутренние стержни для сечений"
{{2.5*XC,9.5*YC,0,0}, ToggleButton, ICONCMDID_rein_invis, ON, 0, "", ""},	//rInfo.option[18]	"Невидимые стержни пунктиром"
{{2.5*XC,11.0*YC,0,0}, ToggleButton, ICONCMDID_rein_secs, ON, 0, "", ""},	//rInfo.option[11]	"Сечения стержней"
{{24.5*XC,11.0*YC,0,0}, Text, ICONCMDID_rein_secs, ON, 0, "", ""},	//	                        "Сечения стержней"
{{30.5*XC,11.0*YC,0,0}, ToggleButton, ICONCMDID_rein_secprp, ON, 0, "", ""},//rInfo.option[12]	"Сечения стержней перп."
{{4.0*XC,12.5*YC,0,0}, ToggleButton, ICONCMDID_rein_rdsec, ON, 0, "", ""},	//rInfo.option[9]	"Реальный диаметр сечения"
{{2.5*XC,14.0*YC,0,0}, ToggleButton, ICONCMDID_rein_bounds, ON, 0, "", ""},	//rInfo.option[10]	"Контуры объёма стержня"
{{28.5*XC,14.0*YC,0,0}, ToggleButton, ICONCMDID_rein_vecs, ON, 0, "", ""},	//rInfo.lim	        "Стрелки"
{{2.5*XC,15.5*YC,0,0}, ToggleButton, ICONCMDID_rein_bends, ON, 0, "", ""},	//rInfo.option[8]	"Загибы"
{{14.5*XC,15.5*YC,0,0}, ToggleButton, ICONCMDID_rein_thread, ON, 0, "", ""},//rInfo.threads	    "резьба"
{{2.5*XC,17.0*YC,0,0}, ToggleButton, ICONCMDID_rein_ends, ON, 0, "", ""},	//rInfo.ends		"Засечки"
{{14.5*XC,17.0*YC,0,0}, ToggleButton, ICONCMDID_rein_aux_I, ON, 0, "", ""},	//rInfo.option[13]	"Отсечки"
{{26.5*XC,17.0*YC,0,0}, ToggleButton, ICONCMDID_rein_aux_X, ON, 0, "", ""},	//rInfo.option[14]	"Крестики"
{{26.5*XC,18.5*YC,0,0}, ToggleButton, ICONCMDID_rein_aux_O, ON, 0, "", ""},	//rInfo.option[13]	"Нолики"
{{2.5*XC,18.5*YC,0,0}, ToggleButton, ICONCMDID_rein_posnum, ON, 0, "", ""},	//rInfo.option[15]	"Номера позиций"
{{2.5*XC,20.0*YC,0,0}, ToggleButton, ICONCMDID_rein_color, ON, 0, "", ""},	//rInfo.option[19]	"Цвет элемента по диаметру"
{{2.5*XC,21.5*YC,0,0}, ToggleButton, ICONCMDID_rein_ground, ON, 0, "", ""},	//rInfo.option[3]	"CCGG"
{{23.5*XC,23.0*YC,0,0}, OptionButton, OPTIONBUTTONID_LineStyles, ON, 0, "", ""},
{{37.0*XC,22.0*YC,0,0}, PushButton, 6, OFF, 0, "", ""},
    }
    };


DialogBoxRsc    DLG_SKETCH =
    {
    DIALOGATTR_DEFAULT, 47*XC, 19*YC, NOHELP, MHELP, NOHOOK, NOPARENTID,TXT_6,
    {
	{{ 0.5*XC, 0.5*YC, 46*XC, 18*YC}, Generic, 3, ON, 0, "", ""},
    }
    };


DItem_ListBoxRsc      LISTBOX_POSITIONS =
    {
    NOHELP, MHELP, HOOKID_LISTBOX, NOARG, 
		LISTATTR_SORTCOLUMNS |
		LISTATTR_GRID | 
		LISTATTR_DYNAMICSCROLL | 
		LISTATTR_COLHEADINGBORDERS | 
		LISTATTR_RESIZABLECOLUMNS | 
		LISTATTR_DRAWPREFIXICON | 
		LISTATTR_INDEPENDENTCOLS | 
		LISTATTR_COLOREDROWS, 
		18,0, "",
    	{
	{3*XC,10,ALIGN_CENTER | LISTCOLATTR_NOSORT, ""}, // 0 (REIN_LISTB_EXST)
	{5*XC,10,ALIGN_CENTER | LISTCOLATTR_EDITABLE,"N"}, // 1
	{3*XC,0,ALIGN_CENTER | LISTCOLATTR_NOHIGHLIGHT | LISTCOLATTR_NOSORT ,"@"}, // 2
	{3*XC,0,ALIGN_CENTER | LISTCOLATTR_NOHIGHLIGHT | LISTCOLATTR_NOSORT ,"x"}, // 3
	{3*XC,0,ALIGN_CENTER | LISTCOLATTR_NOHIGHLIGHT | LISTCOLATTR_NOSORT ,""}, // 4
	{3*XC,0,ALIGN_CENTER | LISTCOLATTR_NOHIGHLIGHT | LISTCOLATTR_NOSORT ,""}, // 5
	{3*XC,0,ALIGN_CENTER | LISTCOLATTR_NOHIGHLIGHT | LISTCOLATTR_NOSORT ,""}, // 6
	{3*XC,0,ALIGN_CENTER | LISTCOLATTR_NOHIGHLIGHT | LISTCOLATTR_NOSORT ,""}, // 7
	{5*XC,10,ALIGN_CENTER,"d"}, // 8
	{4*XC,0,ALIGN_CENTER ,"<-"}, // 9
	{4*XC,0,ALIGN_CENTER ,"->"}, // 10
	{4*XC,0,ALIGN_CENTER ,TXT_7}, // 11
	{4*XC,0,ALIGN_CENTER ,TXT_8}, // 12
	{4*XC,0,ALIGN_CENTER ,TXT_9}, // 13
	{7*XC,10,ALIGN_CENTER,TXT_10}, // 14
	{10*XC,10,ALIGN_CENTER | LISTCOLATTR_NEVERSHOW,""}, // REIN_LISTB_SORT для сортировки
	{6*XC,10,ALIGN_CENTER,TXT_11}, // 16
	{7*XC,10,ALIGN_CENTER,TXT_12}, // 17
	{7*XC,10,ALIGN_CENTER,TXT_13}, // 18
	{9*XC,10,ALIGN_CENTER /*| LISTCOLATTR_EDITABLE*/,TXT_14}, // 19
	{3*XC,10,ALIGN_CENTER | LISTCOLATTR_NOSORT, ""}, // 20
	{5*XC,10,ALIGN_CENTER | LISTCOLATTR_NEVERSHOW,""}, // REIN_LISTB_AROW номер в массиве
	{2*XC,10,ALIGN_CENTER | LISTCOLATTR_NOSORT, ""}, // 22
   		}
    };

//DItem_ListBoxRsc      2 = 
//    {
//    NOHELP, MHELP, NOHOOK, NOARG, 
//		//LISTATTR_SORTCOLUMNS |
//		LISTATTR_GRID | 
//		LISTATTR_DYNAMICSCROLL | 
//		LISTATTR_COLHEADINGBORDERS | 
//		//LISTATTR_RESIZABLECOLUMNS | 
//		LISTATTR_DRAWPREFIXICON | 
//		LISTATTR_INDEPENDENTCOLS | 
//		LISTATTR_COLOREDROWS, 
//		18,0, "",
//    	{
//	{5*XC,10,ALIGN_CENTER, ""}, // 
//	{25*XC,10,ALIGN_CENTER, "Name"}, // 
//   		}
//    };


#if defined (STD_INTERFACE)


DItem_ToolBoxRsc DIALOG_TOOLBOX =
    {
    NOHELP, MHELP, NOHOOK, NOARG, 0, "Арматурщина",
	{
		{{ 0, 0, 0, 0}, IconPopup, ICONCMDID_ismodel2, ON, 0, "", "owner=\"REIN\""},
		{{ 0, 0, 0, 0}, IconCmd, ICONCMDID_rein_flags, ON, 0, "", "owner=\"REIN\""},
		{{ 0, 0, 0, 0}, IconCmd, ICONCMDID_space_modify, ON, 1, "", "owner=\"REIN\""},
		{{ 0, 0, 0, 0}, IconCmd, ICONCMDID_rein_bar, ON, 1, "", "owner=\"REIN\""},
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
        {{ 0, 0, 0, 0}, IconCmd, 37, ON, 1, "", "owner=\"3DTOOLS\""}, // ICONCMDID_SurfaceProject 37, keyin:  CONSTRUCT SURFACE PROJECTION 
#else
#endif
		{{ 0, 0, 0, 0}, IconCmd, ICONCMDID_rein_list, ON, 1, "", "owner=\"REIN\""},
		{{ 0, 0, 0, 0}, IconCmd, ICONCMDID_rein_chlap, ON, 1, "", "owner=\"REIN\""},
		{{ 0, 0, 0, 0}, IconCmd, ICONCMDID_rein_note, ON, 2, "", "owner=\"REIN\""},
		{{ 0, 0, 0, 0}, IconCmd, ICONCMDID_rein_note2, ON, 2, "", "owner=\"REIN\""},
//#if defined (MSVERSION) && (MSVERSION == 0x8b0)
//#endif
	}
};
	

#endif

DItem_GenericRsc 1= 
{ 
	NOHELP, MHELP, NOHOOK, NOARG 
}; 

DItem_GenericRsc 2= 
{ 
	NOHELP, MHELP, HOOKID_POSITION, NOARG 
}; 

DItem_GenericRsc 3= 
{ 
	NOHELP, MHELP, HOOKID_POSITION, NOARG 
}; 




DItem_PushButtonRsc 1= 
{ 
	DEFAULT_BUTTON, NOHELP, MHELP, 
	HOOKID_ANKER_BTN, NOARG, NOCMD, LCMD, "", TXT_15 
}

DItem_PushButtonRsc 2= 
{ 
	DEFAULT_BUTTON, NOHELP, MHELP, 
	NOHOOK, NOARG, CMD_REIN_BARENDS, LCMD, "", TXT_16 
}

DItem_PushButtonRsc BUTTON_POSLIST= 
{ 
	0, NOHELP, MHELP, 
	NOHOOK, NOARG, CMD_REIN_LIST, LCMD, "noreload", TXT_17 
}


DItem_PushButtonRsc BUTTON_DBSAVE= 
{ 
	0, NOHELP, MHELP, 
	NOHOOK, NOARG, CMD_REIN_POS_DBSAVE, LCMD, "", TXT_18 
}

DItem_PushButtonRsc BUTTON_POSNUM =
{ 
	0, NOHELP, MHELP, 
	NOHOOK, NOARG, CMD_REIN_POS_DBSAVE, LCMD, "posnum", TXT_18_0
}


DItem_PushButtonRsc BUTTON_POSDRAW=
{ 
	0, NOHELP, MHELP, 
	NOHOOK, NOARG, CMD_REIN_POS_DRAW, LCMD, "", TXT_19 
}

DItem_PushButtonRsc 6= 
{ 
	0, NOHELP, MHELP, 
	NOHOOK, NOARG, CMD_REIN_REFPDEL, LCMD, "", "reset" 
}


DItem_PushButtonRsc BUTTON_AGREE =
{
    DEFAULT_BUTTON , NOHELP, MHELP,
    NOHOOK, NOARG, CMD_REIN_PLACE, LCMD, "", "Agree"
}


#if defined (STD_INTERFACE)

DItem_PulldownMenuRsc 8889 =
{
 NOHELP, OHELPTASKIDCMD, NOHOOK, ON | ALIGN_LEFT, TXT_20,
 {
  {TXT_41, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN SAVEPLOT REFS"},
  {TXT_42, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN SAVEPLOT NOREFS"},
 }
};





DItem_PulldownMenuRsc 8888 =
{
 NOHELP, OHELPTASKIDCMD, NOHOOK, ON | ALIGN_LEFT, TXT_20,
 {
  {TXT_21, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN TOOLBOX"},
  {TXT_44, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN RELOAD NOREGEN"},
  {"Найти коллизии для текущего вида", NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN DUPS"},

  {"-", NOACCEL, ON, 0, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, NOCMD, MTASKID, ""},

  {"Разбить линейный контур", NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN DROP"},

  {"-", NOACCEL, ON, 0, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, NOCMD, MTASKID, ""},

  {"Удалить привязку к каталогу Offtake", NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "RCAT RCAT REMOVE"},

  {"-", NOACCEL, ON, 0, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, NOCMD, MTASKID, ""},
/*
  {TXT_40, NOACCEL, ON, NOMARK, 0, // PulldownMenu,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN SAVEPLOT"},
  {TXT_43, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN SAVEPLOT CLEAR"},

  {"-", NOACCEL, ON, 0, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, NOCMD, MTASKID, ""},
*/
  {TXT_22, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN MUFT ACT"},
  {TXT_23, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN MUFT"},
  {TXT_24, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN CAGES"},
  {TXT_25, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN BARENDS DIALOG"},

  {"-", NOACCEL, ON, 0, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, NOCMD, MTASKID, ""},

  //{"Построение контура по точкам", NOACCEL, ON, NOMARK, 0,
  //   NOSUBMENU, NOHELP, MHELP,
  //   NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN PLACE"},

  {TXT_26, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN RELOAD"},

  {"-", NOACCEL, ON, 0, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, NOCMD, MTASKID, ""},

  //{"Сохранить позиции в базе данных", NOACCEL, ON, NOMARK, 0,
  //   NOSUBMENU, NOHELP, MHELP,
  //   NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN POS DBSAVE"},
  //{TXT_27, NOACCEL, ON, NOMARK, 0,
  //   NOSUBMENU, NOHELP, MHELP,
  //  NOHOOK, 0, CMD_MDL_LOAD, MTASKID, "REINUP"},

  {"Показать версию приложения", NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN VERSION"},

  {TXT_28, NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_UNLOAD, MTASKID, "REIN"},
 }
};

#endif

DItem_OptionButtonRsc  OPTIONBUTTONID_LineStyles =
{
NOSYNONYM, NOHELP, MHELP,
NOHOOK, OPTNBTNATTR_NEWSTYLE,
    TXT_98, "linestyle",
{
{NOTYPE, NOICON, CMD_REIN_DRAWENDS, LCMD, -1, NOMASK, ON, "no display"},
{Icon, ICONID_LineStyle0, CMD_REIN_DRAWENDS, LCMD, 0, NOMASK, ON, "~0"},
{Icon, ICONID_LineStyle1, CMD_REIN_DRAWENDS, LCMD, 1, NOMASK, ON, "~1"},
{Icon, ICONID_LineStyle2, CMD_REIN_DRAWENDS, LCMD, 2, NOMASK, ON, "~2"},
{Icon, ICONID_LineStyle3, CMD_REIN_DRAWENDS, LCMD, 3, NOMASK, ON, "~3"},
{Icon, ICONID_LineStyle4, CMD_REIN_DRAWENDS, LCMD, 4, NOMASK, ON, "~4"},
{Icon, ICONID_LineStyle5, CMD_REIN_DRAWENDS, LCMD, 5, NOMASK, ON, "~5"},
{Icon, ICONID_LineStyle6, CMD_REIN_DRAWENDS, LCMD, 6, NOMASK, ON, "~6"},
{Icon, ICONID_LineStyle7, CMD_REIN_DRAWENDS, LCMD, 7, NOMASK, ON, "~7"},
//{Icon, ICONID_LineStyleCustom, CMD_DIALOG_LSTYLESETUP, MCMD, 0, NOMASK,
//ON, "~c"},
//{Icon, ICONID_LineStyleEdit, CMD_DIALOG_LSTYLEEDIT, MCMD, 0, NOMASK,
//ON, "~e"},
}
};


//DItem_TextRsc 1 = 
//    {
//		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
//		HOOKID_DIALOG, NOARG, 
//		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
//		"Погонные метры",
//		"runmet"
//    };

DItem_TextRsc 2 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		TXT_29,
		"diam"
    };

//DItem_TextRsc DLGITEM_TEXT_SPACE = 
//    {
//		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
//		HOOKID_DIALOG, NOARG, 
//		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
//		TXT_30,
//		"space"
//    };

DItem_TextRsc DLGITEM_TEXT_SPACE = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%.1f", "%f", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		TXT_30,
		"spacef"
    };

//DItem_TextRsc DLGITEM_TEXT_SPACE_2 = 
//    {
//		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
//		HOOKID_DIALOG, NOARG, 
//		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
//		"x",
//		"space2"
//    }
//extendedAttributes
//{ {
//{EXTATTR_FLYTEXT,TXT_111}, /* Appears in statusarea */
//{EXTATTR_BALLOON, TXT_111}, /* Appears in pop-up */
//} }
//;

DItem_TextRsc 4 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		TXT_31,
		"offset"
    };

DItem_TextRsc 5 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		TXT_32,
		"offset2"
    };

DItem_TextRsc 15 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		TXT_33,
		"bendrad"
    };

DItem_TextRsc 16 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		4, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		TXT_34,
		"termAngBeg"
    };

DItem_OptionButtonRsc ITEMID_TERMBEG =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_DIALOG, OPTNBTNATTR_NEWSTYLE, TXT_34, "termAngBeg",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 180, NOMASK, ON, "U"},
			{NOTYPE, NOICON, NOCMD, MCMD, 135, NOMASK, ON, "V"},
			{NOTYPE, NOICON, NOCMD, MCMD, 90, NOMASK, ON, "L"},
			{NOTYPE, NOICON, NOCMD, MCMD, -90, NOMASK, ON, "-L"},
			{NOTYPE, NOICON, NOCMD, MCMD, -135, NOMASK, ON, "-V"},
			{NOTYPE, NOICON, NOCMD, MCMD, -180, NOMASK, ON, "-U"},
		}
    };

DItem_TextRsc ITEMID_TERMBEG =
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		4, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		"",
		"termLenBeg"
    };

DItem_TextRsc 18 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		4, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		TXT_34,
		"termAngEnd"
    };

DItem_OptionButtonRsc ITEMID_TERMEND =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_DIALOG, OPTNBTNATTR_NEWSTYLE, TXT_34, "termAngEnd",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 180, NOMASK, ON, "U"},
			{NOTYPE, NOICON, NOCMD, MCMD, 135, NOMASK, ON, "V"},
			{NOTYPE, NOICON, NOCMD, MCMD, 90, NOMASK, ON, "L"},
			{NOTYPE, NOICON, NOCMD, MCMD, -90, NOMASK, ON, "-L"},
			{NOTYPE, NOICON, NOCMD, MCMD, -135, NOMASK, ON, "-V"},
			{NOTYPE, NOICON, NOCMD, MCMD, -180, NOMASK, ON, "-U"},
		}
    };


DItem_TextRsc ITEMID_TERMEND =
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		4, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		"",
		"termLenEnd"
    };


DItem_TextRsc TEXTID_BarsForChange =
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_READONLYCOPY, 
		TXT_35,
		"iSelBars"
    };

DItem_TextRsc 101 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_READONLYCOPY, 
		TXT_36,
		"iMuftQty"
    };




DItem_TextRsc 22 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_READONLYCOPY, 
		TXT_37,
		"qty"
    };

//DItem_TextRsc 23 = 
//    {
//		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
//		HOOKID_DIALOG, NOARG, 
//		5, "%.3lf", "%f", "", "", NOMASK, TEXT_READONLYCOPY, 
//		"Длина макс.",
//		"lenmax"
//    };


//=======================================

DItem_TextRsc 201 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		TXT_38,
		"skhgt"
    };

DItem_TextRsc 202 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		TXT_39,
		"skwdt1"
    };

DItem_TextRsc 203 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"Ширина эскиза",
		"skwdt2"
    };

DItem_TextRsc 204 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"Интервал столбцов",
		"skgap"
    };

DItem_TextRsc 205 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, 0, 
		"Макс кол-во строк",
		"skrows"
    };

//=======================================

DItem_TextRsc ICONCMDID_rein_secs = 
    {
		CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		3, "%ld", "%ld", "", "", NOMASK, 0, 
		"",
		"barface"
    };

//=======================================


DItem_TextRsc 31 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen31"
    };
DItem_TextRsc 32 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen32"
    };
DItem_TextRsc 33 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen33"
    };
DItem_TextRsc 34 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen34"
    };
DItem_TextRsc 35 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen35"
    };
DItem_TextRsc 36 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen36"
    };
DItem_TextRsc 37 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen37"
    };
DItem_TextRsc 38 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen38"
    };
DItem_TextRsc 39 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen39"
    };
DItem_TextRsc 40 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen40"
    };



DItem_TextRsc 41 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen41"
    };
DItem_TextRsc 42 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen42"
    };
DItem_TextRsc 43 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen43"
    };
DItem_TextRsc 44 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen44"
    };
DItem_TextRsc 45 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen45"
    };
DItem_TextRsc 46 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen46"
    };
DItem_TextRsc 47 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen47"
    };
DItem_TextRsc 48 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen48"
    };
DItem_TextRsc 49 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen49"
    };
DItem_TextRsc 50 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_BARSEGM, NOARG, 
		5, "%.0lf", "%f", "", "", NOMASK, 0, 
		"",
		"segmlen50"
    };


//=======================================

//DItem_TextRsc 51 = 
//    {
//		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
//		HOOKID_DIALOG, NOARG, 
//		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
//		"Защ. слой в начале",
//		"covbeg"
//    };
//
//DItem_TextRsc 52 = 
//    {
//		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
//		HOOKID_DIALOG, NOARG, 
//		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
//		"Защ. слой контура",
//		"covface"
//    };
//
//DItem_TextRsc 53 = 
//    {
//		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
//		HOOKID_DIALOG, NOARG, 
//		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
//		"Защ. слой в конце",
//		"covend"
//    };


//=======================================

DItem_TextRsc 71 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
        TXT_94,
		"lapbeg"
    };

DItem_TextRsc 72 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
        TXT_95,
		"lapend"
    };


//=======================================

DItem_TextRsc 81 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		NOHOOK, NOARG, 
		10, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		"Нижний уровень",
		"barendslow"
    };

DItem_TextRsc 82 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		NOHOOK, NOARG, 
		10, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		"Верхний уровень",
		"barendshigh"
    };

DItem_TextRsc 83 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		NOHOOK, NOARG, 
		10, "%ld", "%ld", "", "", NOMASK, TEXT_READONLY, 
		"Количество выпусков:",
		"barendsqty"
    };

DItem_TextRsc 84 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		NOHOOK, NOARG, 
		10, "%ld", "%ld", "", "", NOMASK, TEXT_READONLY, 
		"Окончания с резьбой:",
		"barcapsqty"
    };

//=======================================

DItem_TextRsc 60 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_ANKER_VAL, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		"Вынос стержня (A)",
		"awall"
    };

DItem_TextRsc 61 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		NOHOOK, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		"Длина анкеровки (B)",
		"anklen"
    };

DItem_TextRsc 62 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		NOHOOK, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		"Загиб прямой (C)",
		"applen"
    };

DItem_TextRsc 63 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		NOHOOK, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		"Загиб полный (D)",
		"apprad"
    };


//DItem_TextRsc 93 = 
//    {
//		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
//		HOOKID_DIALOG, NOARG, 
//		4, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
//		"Радиус гиба",
//		"bendrad"
//    };


//=======================================


DItem_TextRsc TEXTID_Space = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_LISTCELL, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
		"",
		"ipnsave" // pos number to save
    };


DItem_ToggleButtonRsc 10 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "irunmet"
    };

DItem_ToggleButtonRsc 2 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "idiam"
    };

DItem_ToggleButtonRsc DLGITEM_TEXT_SPACE =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ispace"
    };

DItem_ToggleButtonRsc 4 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ioffset"
    };

DItem_ToggleButtonRsc 5 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ioffset2"
    };

DItem_ToggleButtonRsc 15 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ibendrad"
    };

DItem_ToggleButtonRsc TOGGLE_RepairBend =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "irepbend"
    }
extendedAttributes
{ {
{EXTATTR_FLYTEXT,TXT_102}, /* Appears in statusarea */
{EXTATTR_BALLOON, TXT_103}, /* Appears in pop-up */
} }
;

DItem_ToggleButtonRsc 16 = // 17 нет так галка для двух полей
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "itermPrmBeg"
    };

DItem_ToggleButtonRsc 18 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "itermPrmEnd"
    };

DItem_ToggleButtonRsc 20 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "свободный загиб",
    "itermFree"
    };

///////////////////////////////////

DItem_ToggleButtonRsc 205 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "Длина в скобках",
    "ilength"
    };

//DItem_ToggleButtonRsc 206 =
//    {
//    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "Крайние стержни",
//    "ilimits"
//    };


IconRsc 222 = { 12, 12, FORMAT_MONOBITMAP, BLACK_INDEX, "", { 0x00, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00, 0x80, 0x08, 0x01, 0x02, 0x10, 0x1a, 0x00, 0xe0, 0x04, 0x00, 0x00, } };


DItem_ToggleButtonRsc 250 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "включая референсы",
    "barendsrefs"
    };

DItem_ToggleButtonRsc 251 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "подсветить стержни",
    "barendshil"
    };


DItem_ToggleButtonRsc 252 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_93,
    "barsetdim"
    };

DItem_ToggleButtonRsc 253 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_93_1,
    "barsetall"
    };


DItem_ToggleButtonRsc 260 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "не поворачивать стержень",
    "drawvedrealbar"
    };


DItem_ToggleButtonRsc 300 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "группировка",
    "ggnum"
    };


//DItem_ToggleButtonRsc 94 =
//    {
//    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "",
//    "ibendrad"
//    };

//DItem_ToggleButtonRsc 93 =
//    {
//    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "",
//    "ibendopt"
//    };


//DItem_ToggleButtonRsc 7 =
//    {
//    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "Обнов. геом.",
//    "iupdconf"
//    };


DItem_ToggleButtonRsc 8 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "icover"
    };

DItem_ToggleButtonRsc 11 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "itermbeg"
    };

DItem_ToggleButtonRsc 12 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "itermend"
    };


DItem_ToggleButtonRsc 51 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "inewbars"
    };

DItem_ToggleButtonRsc 52 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ispacerad"
    };

DItem_ToggleButtonRsc 78 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "iposcalc"
    };



DItem_ToggleButtonRsc 71 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ilapbeg"
    };

DItem_ToggleButtonRsc 72 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ilapend"
    };

DItem_ToggleButtonRsc 73 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "",
    "ilapeven"
    };



DItem_ToggleButtonRsc 54 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_58,
    "mirorg"
    };

DItem_ToggleButtonRsc 55 =
    {
    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_57,
    "mirend"
    };


DItem_ToggleButtonRsc ICONCMDID_rein_ground =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_56,
    "iShowGnd"
    };



DItem_ToggleButtonRsc ICONCMDID_rein_posnum =
    {
    CMD_REIN_DRAWENDS, LCMD, ICONCMDID_rein_ends, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_55,
    "iShowPosNum"
    };


DItem_ToggleButtonRsc ICONCMDID_rein_ends =
    {
    CMD_REIN_DRAWENDS, LCMD, ICONCMDID_rein_ends, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_54,
    "iShowAux_V"
    };

DItem_SynonymsRsc ICONCMDID_rein_ends =
    {
    	{
	{ToggleButton,	ICONCMDID_rein_ends},
	{ToggleIcon,	ICONCMDID_rein_ends},
	}
    };


DItem_ToggleButtonRsc ICONCMDID_rein_aux_O =
    {
    CMD_REIN_DRAWENDS, LCMD, ICONCMDID_rein_ends, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_53,
    "iShowAux_O"
    };

DItem_ToggleButtonRsc ICONCMDID_rein_aux_X =
    {
    CMD_REIN_DRAWENDS, LCMD, ICONCMDID_rein_ends, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_52,
    "iShowAux_X"
    };

DItem_ToggleButtonRsc ICONCMDID_rein_aux_I =
    {
    CMD_REIN_DRAWENDS, LCMD, ICONCMDID_rein_ends, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_51,
    "iShowAux_I"
    };

DItem_ToggleButtonRsc ICONCMDID_rein_secs =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_50,
    "iShowSecs"
    };

DItem_ToggleButtonRsc ICONCMDID_rein_secprp =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_49,
    "iShowSecsPerp"
    };



DItem_ToggleButtonRsc ICONCMDID_rein_transp =
    {
    CMD_REIN_DRAWENDS, LCMD, ICONCMDID_rein_transp, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_48,
    "iShowTransp"
    };

DItem_ToggleButtonRsc ICONCMDID_rein_trsec =
    {
    CMD_REIN_DRAWENDS, LCMD, ICONCMDID_rein_transp, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_47,
    "iShowTranSec" // 
	};

DItem_SynonymsRsc ICONCMDID_rein_transp =
    {
    	{
	{ToggleButton,	ICONCMDID_rein_transp},
	{ToggleButton,	ICONCMDID_rein_trsec},
	}
    };



DItem_ToggleButtonRsc ICONCMDID_rein_invis =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_46,
    "iShowInvisible"
    };

DItem_ToggleButtonRsc ICONCMDID_rein_color =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_45_prz_clrbydiam,
    "iShowByColor"
    };


DItem_ToggleButtonRsc ICONCMDID_rein_rdsec =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_62,
    "iSecRealDiam"
    };

DItem_ToggleButtonRsc ICONCMDID_rein_bends =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_63,
    "iShowBends"
    };

DItem_ToggleButtonRsc ICONCMDID_rein_thread =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_64,
    "iShowThread"
    };




DItem_ToggleButtonRsc ICONCMDID_rein_vecs =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_65,
    "iShowArrows"
    };


DItem_ToggleButtonRsc ICONCMDID_rein_cont =
    {
    CMD_REIN_DRAWENDS, LCMD, ICONCMDID_rein_cont, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_61,
    "iShowCont"
    };
DItem_SynonymsRsc ICONCMDID_rein_cont =
    {
    	{
	{ToggleButton,	ICONCMDID_rein_cont},
	{ToggleIcon,	ICONCMDID_rein_cont},
	}
    };


//DItem_ToggleButtonRsc ICONCMDID_rein_load =
//    {
//    CMD_REIN_DRAWCONT, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "Удалять дублирующиеся позиции",
//    "iDeleteDups"
//    };

//DItem_ToggleButtonRsc ICONCMDID_rein_snap =
//    {
//    CMD_REIN_DRAWCONT, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "Возможен захват вспомогательных элементов",
//    "iShowSnap"
//    };

DItem_ToggleButtonRsc ICONCMDID_rein_bounds =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_66,
    "iShowBounds"
    };

//DItem_ToggleButtonRsc ICONCMDID_rein_refbars =
//    {
//    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "Использовать данные арматуры из референсов",
//    "iBarsFromRefs"
//    };

//DItem_ToggleButtonRsc ICONCMDID_rein_mufts =
//    {
//    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "Муфты,скобы",
//    "iShowMufts"
//    };


DItem_ToggleButtonRsc ICONCMDID_rein_iso =
    {
    CMD_REIN_RELOAD, LCMD, ICONCMDID_rein_iso, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "Переходные оси стержней",
    ""
    };
DItem_SynonymsRsc ICONCMDID_rein_iso =
    {
    	{
	{ToggleButton,	ICONCMDID_rein_iso},
	{ToggleIcon,	ICONCMDID_rein_iso},
	}
    };


DItem_ToggleButtonRsc ICONCMDID_rein_nodes =
    {
    CMD_REIN_NODES, LCMD, ICONCMDID_rein_nodes, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    "Узлы расчетной модели",
    "iShowLoadNodes"
    };
DItem_SynonymsRsc ICONCMDID_rein_nodes =
    {
    	{
	{ToggleButton,	ICONCMDID_rein_nodes},
	{ToggleIcon,	ICONCMDID_rein_nodes},
	}
    };



DItem_ToggleButtonRsc ICONCMDID_rein_bars =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_67,
    "iShowBars"
    };


DItem_ToggleButtonRsc ICONCMDID_rein_fcont =
    {
    CMD_REIN_DRAWENDS, LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, NOARG, NOMASK, NOINVERT,
    TXT_68,
    "iFileIso"
    };


//DItem_ToggleButtonRsc ICONCMDID_rein_fbars =
//    {
//    CMD_REIN_FILEBARS, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "Реальные трёхмерные стержни",
//    "iFileBars"
//    };
//


//DItem_ToggleButtonRsc 106 =
//    {
//    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "Арматурные стержни",
//    "iRealBars"
//    };
//
//DItem_ToggleButtonRsc 107 =
//    {
//    NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
//    NOHOOK, NOARG, NOMASK, NOINVERT,
//    "Арматурные стержни",
//    "iRealSpaces"
//    };












//DItem_OptionButtonRsc 1 =
//    {
//		NOSYNONYM, NOHELP, LHELPCMD, NOHOOK, OPTNBTNATTR_NEWSTYLE, "Заш.слой", "cover",
//		{
//			{NOTYPE, NOICON, NOCMD, MCMD, -1, NOMASK, ON, "верх"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, "нет"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, "вниз"},
//		}
//    };



DItem_OptionButtonRsc 2 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_OPTION_DIAM, OPTNBTNATTR_NEWSTYLE, TXT_69, "diam",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 8, NOMASK, ON, "8"},
			{NOTYPE, NOICON, NOCMD, MCMD, 10, NOMASK, ON, "10"},
			{NOTYPE, NOICON, NOCMD, MCMD, 12, NOMASK, ON, "12"},
			{NOTYPE, NOICON, NOCMD, MCMD, 16, NOMASK, ON, "16"},
			{NOTYPE, NOICON, NOCMD, MCMD, 20, NOMASK, ON, "20"},
			{NOTYPE, NOICON, NOCMD, MCMD, 25, NOMASK, ON, "25"},
			{NOTYPE, NOICON, NOCMD, MCMD, 28, NOMASK, ON, "28"},
			{NOTYPE, NOICON, NOCMD, MCMD, 32, NOMASK, ON, "32"},
			{NOTYPE, NOICON, NOCMD, MCMD, 36, NOMASK, ON, "36"},
			{NOTYPE, NOICON, NOCMD, MCMD, 40, NOMASK, ON, "40"},
		}
    };

DItem_OptionButtonRsc 10 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_DIALOG, OPTNBTNATTR_NEWSTYLE, TXT_70, "runmet",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, TXT_70_1},
			{NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, TXT_70_2},
			{NOTYPE, NOICON, NOCMD, MCMD, 2, NOMASK, ON, TXT_70_3},
			{NOTYPE, NOICON, NOCMD, MCMD, 3, NOMASK, ON, TXT_70_4},
		}
    };

DItem_OptionButtonRsc 11 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_OPTION_TERM, OPTNBTNATTR_NEWSTYLE, TXT_74, "termbeg",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_NONE, NOMASK, ON, " "},
			{NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_BEND, NOMASK, ON, TXT_75},
			{NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_REZB, NOMASK, ON, TXT_76},
			{NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_MUFT, NOMASK, ON, TXT_77},
			{NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_SKOB, NOMASK, ON, TXT_78},
			{NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_SVAR, NOMASK, ON, TXT_79},
			{NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_PLAT, NOMASK, ON, TXT_80},
		}
    };


DItem_OptionButtonRsc 12 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_OPTION_TERM, OPTNBTNATTR_NEWSTYLE, TXT_74_1, "termend",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_NONE, NOMASK, ON, " "},
            {NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_BEND, NOMASK, ON, TXT_75},
            {NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_REZB, NOMASK, ON, TXT_76},
            {NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_MUFT, NOMASK, ON, TXT_77},
            {NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_SKOB, NOMASK, ON, TXT_78},
            {NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_SVAR, NOMASK, ON, TXT_79},
            {NOTYPE, NOICON, NOCMD, MCMD, REIN_TERM_PLAT, NOMASK, ON, TXT_80},
        }
    };


DItem_OptionButtonRsc 16 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_OPTION_TERM, OPTNBTNATTR_NEWSTYLE, TXT_81, "termMTpBeg",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, TXT_81_1},
			{NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, TXT_81_2},
			{NOTYPE, NOICON, NOCMD, MCMD, 2, NOMASK, ON, TXT_81_3},
			{NOTYPE, NOICON, NOCMD, MCMD, 3, NOMASK, ON, TXT_81_4},
		}
    };

DItem_OptionButtonRsc 18 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_OPTION_TERM, OPTNBTNATTR_NEWSTYLE, TXT_81, "termMTpEnd",
		{
            {NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, TXT_81_1},
            {NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, TXT_81_2},
            {NOTYPE, NOICON, NOCMD, MCMD, 2, NOMASK, ON, TXT_81_3},
            {NOTYPE, NOICON, NOCMD, MCMD, 3, NOMASK, ON, TXT_81_4},
        }
    };


//#define BT_AXIS						0 
//#define BT_GIB						1 
//#define BT_SEC						2 
//#define BT_PAR						3 
//#define BT_AUTO						4 


DItem_OptionButtonRsc 51 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_OPTION_TERM, OPTNBTNATTR_NEWSTYLE, TXT_82, "rbartype",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, BT_AXIS, NOMASK, ON, TXT_82_1},
			{NOTYPE, NOICON, NOCMD, MCMD, BT_AUTO, NOMASK, ON, TXT_82_2},
			{NOTYPE, NOICON, NOCMD, MCMD, BT_GIB, NOMASK, ON, TXT_82_3},
			{NOTYPE, NOICON, NOCMD, MCMD, BT_SEC, NOMASK, ON, TXT_82_4},
			{NOTYPE, NOICON, NOCMD, MCMD, BT_PAR, NOMASK, ON, TXT_82_5},
		}
    };

DItem_TextRsc 52 = 
    {
		NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP, 
		HOOKID_DIALOG, NOARG, 
		5, "%ld", "%ld", "", "", NOMASK, TEXT_ALWAYSBEVELED, 
        TXT_83,
		"spacerad"
    };



DItem_OptionButtonRsc 78 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_DIALOG, OPTNBTNATTR_NEWSTYLE, TXT_84, "poscalc",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, TXT_84_1},
			{NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, "1"},
			{NOTYPE, NOICON, NOCMD, MCMD, 2, NOMASK, ON, "2"},
			{NOTYPE, NOICON, NOCMD, MCMD, 3, NOMASK, ON, "3"},
			{NOTYPE, NOICON, NOCMD, MCMD, 4, NOMASK, ON, "4"},
			{NOTYPE, NOICON, NOCMD, MCMD, 5, NOMASK, ON, "5"},
			{NOTYPE, NOICON, NOCMD, MCMD, 6, NOMASK, ON, "6"},
			{NOTYPE, NOICON, NOCMD, MCMD, 7, NOMASK, ON, "7"},
			{NOTYPE, NOICON, NOCMD, MCMD, 8, NOMASK, ON, "8"},
			{NOTYPE, NOICON, NOCMD, MCMD, 9, NOMASK, ON, "9"},
			{NOTYPE, NOICON, NOCMD, MCMD, 10, NOMASK, ON, "10"},
			{NOTYPE, NOICON, NOCMD, MCMD, 11, NOMASK, ON, "11"},
			{NOTYPE, NOICON, NOCMD, MCMD, 12, NOMASK, ON, "12"},
			{NOTYPE, NOICON, NOCMD, MCMD, 13, NOMASK, ON, "13"},
			{NOTYPE, NOICON, NOCMD, MCMD, 14, NOMASK, ON, "14"},
			{NOTYPE, NOICON, NOCMD, MCMD, 15, NOMASK, ON, "15"},
			{NOTYPE, NOICON, NOCMD, MCMD, 16, NOMASK, ON, "16"},
			{NOTYPE, NOICON, NOCMD, MCMD, 17, NOMASK, ON, "17"},
			{NOTYPE, NOICON, NOCMD, MCMD, 18, NOMASK, ON, "18"},
			{NOTYPE, NOICON, NOCMD, MCMD, 19, NOMASK, ON, "19"},
			{NOTYPE, NOICON, NOCMD, MCMD, 20, NOMASK, ON, "20"},
		}
    };




DItem_OptionButtonRsc 6 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, NOHOOK, OPTNBTNATTR_NEWSTYLE, "Соединения", "",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, BAR_JOINT_DEF, NOMASK, ON, "по умолч."},
			{NOTYPE, NOICON, NOCMD, MCMD, BAR_JOINT_LAP, NOMASK, ON, "нахлёст"},
			{NOTYPE, NOICON, NOCMD, MCMD, BAR_JOINT_RING, NOMASK, ON, "муфты"},
			{NOTYPE, NOICON, NOCMD, MCMD, BAR_JOINT_POOL, NOMASK, ON, "сварка"},
		}
    };


DItem_OptionButtonRsc 73 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_DIALOG, OPTNBTNATTR_NEWSTYLE, TXT_85, "lapeven",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, TXT_85_1},
			{NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, TXT_85_2},
		}
    };

DItem_OptionButtonRsc 7 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, NOHOOK, OPTNBTNATTR_NEWSTYLE, "Относительно", "mirdir",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, "вдоль"},
			{NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, "поперек"},
		}
    };


DItem_OptionButtonRsc 95 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, NOHOOK, OPTNBTNATTR_NEWSTYLE, TXT_86, "barset",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, TXT_86_1},
			{NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, TXT_86_2},
			{NOTYPE, NOICON, NOCMD, MCMD, 2, NOMASK, ON, TXT_86_3},
		}
    };

DItem_OptionButtonRsc OPTIONBUTTONID_BarOver =
{
    NOSYNONYM, NOHELP, LHELPCMD, NOHOOK, OPTNBTNATTR_NEWSTYLE, TXT_87, "bact",
    {
        {NOTYPE, NOICON, NOCMD, MCMD, BARVIEW_ACTION_STD, NOMASK, ON, TXT_87_1},
        //{NOTYPE, NOICON, NOCMD, MCMD, BAROVER_ACTION_GROUND, NOMASK, ON, ""},
        {NOTYPE, NOICON, NOCMD, MCMD, BAROVER_ACTION_DELETE, NOMASK, ON, TXT_87_2},
        {NOTYPE, NOICON, NOCMD, MCMD, BAROVER_ACTION_RESET, NOMASK, ON, TXT_87_3},
    }
};

DItem_OptionButtonRsc OPTIONBUTTONID_BarView =
{
    NOSYNONYM, NOHELP, LHELPCMD, NOHOOK, OPTNBTNATTR_NEWSTYLE, TXT_87, "bview",
    {
        {NOTYPE, NOICON, NOCMD, MCMD, BARVIEW_ACTION_STD, NOMASK, ON, TXT_87_4},
    }
};


DItem_OptionButtonRsc OPTIONBUTTONID_PresOpt =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_OPTION_PREF, OPTNBTNATTR_NEWSTYLE, TXT_59, "saveinfo",
		{
		}
    };


DItem_ComboBoxRsc COMBOBOX_SHOWPREF_REFS =
{
NOCMD, LCMD, NOSYNONYM, NOHELP, MHELP,
HOOKID_SHOWREFCOMBO, NOARG,
20, "", "", "", "", NOMASK,
0, // Id of initial string list used 
15, // Number of rows to show in list 
1, // Gap between textedit & button 
40 * XC, // Width of dropdown listbox
1, // Index of Column to get value from
COMBOATTR_READONLY /* | COMBOATTR_SORT | COMBOATTR_LABELABOVE*/,
TXT_59,
"",
{
{5 * XC, 10, ALIGN_LEFT, ""},
{30 * XC, 30, ALIGN_LEFT, ""},
}
};


//DItem_OptionButtonRsc 94 =
//    {
//		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_OPTION_TERM, OPTNBTNATTR_NEWSTYLE, "Радиус гиба", "bendopt",
//		{
//			{NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, "станд."},
//			{NOTYPE, NOICON, NOCMD, MCMD, 5, NOMASK, ON, "5"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 10, NOMASK, ON, "10"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 15, NOMASK, ON, "15"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 20, NOMASK, ON, "20"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 25, NOMASK, ON, "25"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 30, NOMASK, ON, "30"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 35, NOMASK, ON, "35"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 40, NOMASK, ON, "40"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 45, NOMASK, ON, "45"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 50, NOMASK, ON, "50"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 55, NOMASK, ON, "55"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 60, NOMASK, ON, "60"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 65, NOMASK, ON, "65"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 70, NOMASK, ON, "70"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 75, NOMASK, ON, "75"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 80, NOMASK, ON, "80"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 85, NOMASK, ON, "85"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 90, NOMASK, ON, "90"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 95, NOMASK, ON, "95"},
//			{NOTYPE, NOICON, NOCMD, MCMD, 100, NOMASK, ON, "100"},
//		}
//    };



//#define BAR_JOINT_DEF       	    0
//#define BAR_JOINT_LAP       	    1
//#define BAR_JOINT_RING       	    2
//#define BAR_JOINT_POOL       	    3




//408		6
//409		8
//410		10
//411		12
//412		14
//413		16
//414		18
//415		20
//416		22
//417		25
//418		28
//419		32
//420		36
//421		40
//422		45
//423		50
//424		55


DItem_OptionButtonRsc 5 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_ANKER_VAL, OPTNBTNATTR_NEWSTYLE, "Диаметр стержня", "adiam",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 16, NOMASK, ON, "16"},
			{NOTYPE, NOICON, NOCMD, MCMD, 20, NOMASK, ON, "20"},
			{NOTYPE, NOICON, NOCMD, MCMD, 25, NOMASK, ON, "25"},
			{NOTYPE, NOICON, NOCMD, MCMD, 28, NOMASK, ON, "28"},
			{NOTYPE, NOICON, NOCMD, MCMD, 32, NOMASK, ON, "32"},
			{NOTYPE, NOICON, NOCMD, MCMD, 36, NOMASK, ON, "36"},
			{NOTYPE, NOICON, NOCMD, MCMD, 40, NOMASK, ON, "40"},
		}
    };



DItem_OptionButtonRsc 3 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_ANKER_VAL, OPTNBTNATTR_NEWSTYLE, "Класс бетона", "abet",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, "B10"},
			{NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, "B15"},
			{NOTYPE, NOICON, NOCMD, MCMD, 2, NOMASK, ON, "B20"},
			{NOTYPE, NOICON, NOCMD, MCMD, 3, NOMASK, ON, "B25"},
			{NOTYPE, NOICON, NOCMD, MCMD, 4, NOMASK, ON, "B30"},
			{NOTYPE, NOICON, NOCMD, MCMD, 5, NOMASK, ON, "B35"},
			{NOTYPE, NOICON, NOCMD, MCMD, 6, NOMASK, ON, "B40"},
			{NOTYPE, NOICON, NOCMD, MCMD, 7, NOMASK, ON, "B45"},
			{NOTYPE, NOICON, NOCMD, MCMD, 8, NOMASK, ON, "B50"},
			{NOTYPE, NOICON, NOCMD, MCMD, 9, NOMASK, ON, "B55"},
			{NOTYPE, NOICON, NOCMD, MCMD, 10, NOMASK, ON, "B60"},
		}
    };


DItem_OptionButtonRsc 4 =
    {
		NOSYNONYM, NOHELP, LHELPCMD, HOOKID_ANKER_VAL, OPTNBTNATTR_NEWSTYLE, "Класс арматуры", "aarm",
		{
			{NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, "A240"},
			{NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, "A300"},
			{NOTYPE, NOICON, NOCMD, MCMD, 2, NOMASK, ON, "A400"},
			{NOTYPE, NOICON, NOCMD, MCMD, 3, NOMASK, ON, "A500"},
			{NOTYPE, NOICON, NOCMD, MCMD, 3, NOMASK, ON, "B500"},
		}
    };

DItem_PulldownMenuRsc 1 =
{
 NOHELP, OHELPTASKIDCMD, NOHOOK, ON | ALIGN_LEFT, "Select",
 {
  {"pos enum", NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN POS ENUM"},
  {"pos enum force", NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN POS ENUM FORCE"},
  {"pos enum save", NOACCEL, ON, NOMARK, 0,
     NOSUBMENU, NOHELP, MHELP,
     NOHOOK, 0, CMD_MDL_KEYIN, MTASKID, "REIN REIN POS ENUM SAVE"},
 }
};

DItem_PopupMenuRsc 1= 
{ 
	NOHELP, LHELP, NOHOOK, NOARG, 0, PulldownMenu, 1 
}; 




//DItem_PopupMenuRsc 741 = 
//    {
//    NOHELP, LHELP, NOHOOK, NOARG, 0,
//    PulldownMenu, 852    
//    };
//
//
//DItem_PulldownMenuRsc 852 = 
//    {
//    NOHELP, OHELPTASKIDCMD,
//    HOOKID_PDMMultiListTests,
//    ON | ALIGN_LEFT, "Select",
//{	
//{"Select top", NOACCEL, ON,  NOMARK, 0, NOSUBMENU,
//		    NOHELP, OHELPTASKIDCMD,
//		    NOHOOK, 1,
//		    NOCMD, OTASKID, ""},
//}
//    };


MessageList 1 =
{
    {
    {1,	    TXT_88			},
    }
};




DItem_IconCmdRsc ICONCMDID_rein_bar =
{
NOHELP, MHELP, 0,
CMD_REIN_BAROVER, OTASKID, "", ""
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
,{}
#endif
}
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT,TXT_89}, /* Appears in statusarea */
{EXTATTR_BALLOON, TXT_89}, /* Appears in pop-up */
}}
;

DItem_IconCmdRsc ICONCMDID_space_modify =
{
NOHELP, MHELP, 0,
CMD_REIN_MODIFY, OTASKID, "", ""
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
,{}
#endif
}
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT, TXT_90}, /* Appears in statusarea */
{EXTATTR_BALLOON, TXT_90}, /* Appears in pop-up */
}}
;
 

//DItem_IconCmdRsc ICONCMDID_rein_mirror =
//{
//NOHELP, MHELP, 0,
//CMD_REIN_MIRROR, OTASKID, "", "",
//{
//}
//}
//extendedAttributes 
//{{ 
//{EXTATTR_FLYTEXT,"Зеркалить"}, /* Appears in statusarea */ 
//{EXTATTR_BALLOON, "Зеркалить"}, /* Appears in pop-up */ 
//}}
//;
//
//DItem_IconCmdRsc ICONCMDID_space_place =
//{
//NOHELP, MHELP, 0,
//CMD_REIN_PLACE, OTASKID, "", "",
//{
//}
//}
//extendedAttributes 
//{{ 
//{EXTATTR_FLYTEXT,"Арматура"}, /* Appears in statusarea */ 
//{EXTATTR_BALLOON, "Арматура"}, /* Appears in pop-up */ 
//}}
//;
//
//DItem_IconCmdRsc ICONCMDID_rein_side =
//{
//NOHELP, MHELP, 0,
//CMD_REIN_SIDE, OTASKID, "", "",
//{
//}
//}
//extendedAttributes 
//{{ 
//{EXTATTR_FLYTEXT,"Разместить стержень"}, /* Appears in statusarea */ 
//{EXTATTR_BALLOON, "Разместить стержень"}, /* Appears in pop-up */ 
//}}
//;
//


//DItem_IconCmdRsc ICONCMDID_rein_note =
//{
//	NOHELP, MHELP, 0, CMD_REIN_BARSET, OTASKID, "", "",
//	{
//		{ { 16 * XC, GENY(1), 10 * XC, 0 }, Text, "Note",ON,0,"","" },
//	}
//};

//DItem_IconCmdRsc ICONCMDID_rein_note =
//{
//	NOHELP, MHELP, 0, CMD_REIN_BARSET, OTASKID, "", "",
//};

DItem_IconCmdRsc ICONCMDID_rein_flags =
{
NOHELP, MHELP, 0,
CMD_REIN_FLAGS, OTASKID, "", ""
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
,{}
#endif
}
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT, TXT_91}, /* Appears in statusarea */
{EXTATTR_BALLOON, TXT_91}, /* Appears in pop-up */
}}
;

/*
DItem_IconCmdRsc ICONCMDID_PlaceLineAA= 
{ 
	NOHELP, MHELP, 0, CMD_PLACE_LINE_ANGLE, MTASKID, "", "", 
	{ 
	   {{16*XC, GENY(1), 10*XC, 0}, Text, TEXTID_ActiveAngle,ON,0,"",""}, 
	} 
};
*/

DItem_IconCmdRsc ICONCMDID_rein_note =
{
NOHELP, MHELP, 0,
CMD_REIN_BARSET, OTASKID, "", ""
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
,{}
#endif
}
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT,TXT_107}, /* Appears in statusarea */
{EXTATTR_BALLOON, TXT_107}, /* Appears in pop-up */
}}
;


DItem_IconCmdRsc ICONCMDID_rein_note2 =
{
NOHELP, MHELP, 0,
CMD_REIN_NOTE, OTASKID, "", ""
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
,{}
#endif
}
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT,TXT_108}, /* Appears in statusarea */
{EXTATTR_BALLOON, TXT_108}, /* Appears in pop-up */
}}
;


DItem_IconCmdRsc ICONCMDID_rein_list =
{
	NOHELP, MHELP, 0,
	CMD_REIN_LIST, OTASKID, "reload", ""
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
    ,	{	}
#endif
}
extendedAttributes
{ {
	{ EXTATTR_FLYTEXT,TXT_105 }, /* Appears in statusarea */
	{ EXTATTR_BALLOON, TXT_105 }, /* Appears in pop-up */
	} }
;



DItem_IconCmdRsc ICONCMDID_rein_chlap =
{
NOHELP, MHELP, 0,
CMD_REIN_CHLAP, OTASKID, "", ""
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
    ,{
    }
#endif
}
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT,TXT_106}, /* Appears in statusarea */
{EXTATTR_BALLOON, TXT_106}, /* Appears in pop-up */
}}
;

//DItem_IconCmdRsc ICONCMDID_rein_ungrab =
//{
//NOHELP, MHELP, 0,
//CMD_REIN_UNGRAB, OTASKID, "", "",
//{
//}
//}
//extendedAttributes 
//{{ 
//{EXTATTR_FLYTEXT,"Сброс параметров стержня"}, /* Appears in statusarea */ 
//{EXTATTR_BALLOON, "Сброс параметров стержня"}, /* Appears in pop-up */ 
//}}
//;

//DItem_IconCmdRsc ICONCMDID_rein_bar =
//{
//NOHELP, MHELP, 0,
//CMD_REIN_BAR, OTASKID, "", "",
//{
//}
//}
//extendedAttributes 
//{{ 
//{EXTATTR_FLYTEXT,"Конфигурация стержня"}, /* Appears in statusarea */ 
//{EXTATTR_BALLOON, "Конфигурация стержня"}, /* Appears in pop-up */ 
//}}
//;

//DItem_IconCmdRsc ICONCMDID_rein_anker =
//{
//NOHELP, MHELP, 0,
//CMD_REIN_ANKER, OTASKID, "", "",
//{
//}
//}
//extendedAttributes 
//{{ 
//{EXTATTR_FLYTEXT,"Анкеровка"}, /* Appears in statusarea */ 
//{EXTATTR_BALLOON, "Анкеровка"}, /* Appears in pop-up */ 
//}}
//;

//DItem_IconCmdRsc ICONCMDID_rein_linestring =
//{
//NOHELP, MHELP, 0,
//CMD_REIN_LINESTRING, OTASKID, "", "",
//{
//}
//}
//extendedAttributes 
//{{ 
//{EXTATTR_FLYTEXT,"По эскизу"}, /* Appears in statusarea */ 
//{EXTATTR_BALLOON, "По эскизу"}, /* Appears in pop-up */ 
//}}
//;


//CmdItemListRsc CMD_REIN_PLACE =
//    {{
//    }};
//CmdItemListRsc CMD_REIN_MODIFY =
//    {{
//    }};
//CmdItemListRsc CMD_REIN_LINESTRING =
//    {{
//    }};


#if defined (STD_INTERFACE)


DItem_ToggleIconRsc ICONCMDID_ismodel = // NU, see ICONCMDID_ismodel2
    {
    CMD_REIN_MODE, //commandNumber; 
	LCMD, //commandSource; 
	NOSYNONYM,//synonymsId; 
    NOHELP, //helpInfo; 
	LHELP, //helpSource; 
	NOHOOK, //itemHookId; 
	NOARG,//itemHookArg;
    NOMASK, //mask; 
	NOINVERT,//invertFlag; 
	0,
	ICONCMDID_ismodel,
	0,
    "",//
    ""//
    }
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT,"Трехмерная модель"}, // Appears in statusarea 
{EXTATTR_BALLOON, "Трехмерная модель"}, // Appears in pop-up 
}}
;

DItem_IconPopupRsc ICONCMDID_ismodel2 = 
{
    NOCMD,
    LCMD,
    NOSYNONYM,//synonymsId; 
    NOHELP, //helpInfo; 
    LHELP, //helpSource; 
    NOHOOK, //itemHookId; 
    NOARG, //itemHookArg;
    ICONPOPUPATTR_NOTOGGLE | ICONPOPUPATTR_CONNECTED | ICONPOPUPATTR_LABELONSIDE, // ICONPOPUPATTR_CONNECTED, ICONPOPUPATTR_PADCORNER, ICONPOPUPATTR_NOTOGGLE, ICONPOPUPATTR_PADBOTTOM, ICONPOPUPATTR_NOLABEL, ICONPOPUPATTR_NORESTOREFOCUS
    0, // ICONCMDID_ismodel, // iconId
    0, // iconType
    NOMASK, //mask
    0, // invertFlag
    RTYPE_ComboBox, // itemType: RTYPE_ComboBox, // RTYPE_PopupMenu, RTYPE_Container,  RTYPE_DialogItemList
    COMBOBOX_MODEL, // itemId
    "",//
    "" //
}
//extendedAttributes
//{ {
//{EXTATTR_FLYTEXT,"Трехмерная модель"}, // Appears in statusarea 
//{EXTATTR_BALLOON, "Трехмерная модель"}, // Appears in pop-up 
//} }
;


#endif


/*
DItem_OptionButtonRsc ICONCMDID_ismodel2 =
{
    NOSYNONYM, NOHELP, LHELPCMD, NOHOOK, OPTNBTNATTR_NEWSTYLE , "Model", "",
    {
        {NOTYPE, NOICON, NOCMD, MCMD, 0, NOMASK, ON, "aaa"},
        {NOTYPE, NOICON, NOCMD, MCMD, 1, NOMASK, ON, "sss"},
        {NOTYPE, NOICON, NOCMD, MCMD, 2, NOMASK, ON, "ddd"},
        {NOTYPE, NOICON, NOCMD, MCMD, 3, NOMASK, ON, "fff"},
        {NOTYPE, NOICON, NOCMD, MCMD, 3, NOMASK, ON, "ggg"},
    }
};
*/
/*
DItem_PulldownOptionMenuRsc ICONCMDID_ismodel2 =
{
NOSYNONYM, NOHELP, LHELPCMD, NOHOOK,
ON | ALIGN_LEFT,
"Model",
"", // Access string would go here
{
    {NOTYPE, NOICON, NOCMD, LCMD, 0, NOMASK, ON, "aaaaa" },
    {NOTYPE, NOICON, NOCMD, LCMD, 1, NOMASK, ON, "sssss" },
    {NOTYPE, NOICON, NOCMD, LCMD, 2, NOMASK, ON, "ddddd" },
}
};
*/

DItem_ToggleIconRsc ICONCMDID_rein_ends =
    {
    CMD_REIN_DRAWENDS, //commandNumber; 
	LCMD, //commandSource; 
	ICONCMDID_rein_ends,//synonymsId; 
    NOHELP, //helpInfo; 
	LHELP, //helpSource; 
	HOOKID_TOGGLE_DRAW, //itemHookId; 
	NOARG,//itemHookArg;
    NOMASK, //mask; 
	NOINVERT,//invertFlag; 
	0,
	ICONCMDID_rein_ends,
	0,
    "",//
    "iShowAux_V"//
    }
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT,"Вспомогательные обозначения стержней"}, // Appears in statusarea 
{EXTATTR_BALLOON, "Вспомогательные обозначения стержней"}, // Appears in pop-up 
}}
;


DItem_ToggleIconRsc ICONCMDID_rein_cont =
    {
    CMD_REIN_DRAWENDS, //commandNumber; 
	LCMD, //commandSource; 
	ICONCMDID_rein_cont,//synonymsId; 
    NOHELP, //helpInfo; 
	LHELP, //helpSource; 
	HOOKID_TOGGLE_DRAW, //itemHookId; 
	NOARG,//itemHookArg;
    NOMASK, //mask; 
	NOINVERT,//invertFlag; 
	0,
	ICONCMDID_rein_cont,
	0,
    "",//
    "iShowCont"//
    }
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT,"Отображать контуры расположения арматуры"}, // Appears in statusarea 
{EXTATTR_BALLOON, "Отображать контуры расположения арматуры"}, // Appears in pop-up 
}}
;


DItem_ToggleIconRsc ICONCMDID_rein_iso =
    {
    CMD_REIN_RELOAD, //commandNumber; 
	LCMD, //commandSource; 
	ICONCMDID_rein_iso,//synonymsId; 
    NOHELP, //helpInfo; 
	LHELP, //helpSource; 
	HOOKID_TOGGLE_DRAW, //itemHookId; 
	NOARG,//itemHookArg;
    NOMASK, //mask; 
	NOINVERT,//invertFlag; 
	0,
	ICONCMDID_rein_iso,
	0,
    "",//
    ""//
    }
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT,"Показывать оси арматуры"}, // Appears in statusarea 
{EXTATTR_BALLOON, "Показывать оси арматуры"}, // Appears in pop-up 
}}
;




DItem_ToggleIconRsc ICONCMDID_rein_nodes =
    {
    CMD_REIN_NODES, //commandNumber; 
	LCMD, //commandSource; 
	ICONCMDID_rein_nodes,//synonymsId; 
    NOHELP, //helpInfo; 
	LHELP, //helpSource; 
	HOOKID_TOGGLE_DRAW, //itemHookId; 
	NOARG,//itemHookArg;
    NOMASK, //mask; 
	NOINVERT,//invertFlag; 
	0,
	ICONCMDID_rein_nodes,
	0,
    "",//
    "iShowLoadNodes"//
    }
extendedAttributes 
{{ 
{EXTATTR_FLYTEXT,"Показывать узлы расчетной модели"}, // Appears in statusarea 
{EXTATTR_BALLOON, "Показывать узлы расчетной модели"}, // Appears in pop-up 
}}
;

#if defined (STD_INTERFACE)


/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdLarge Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------
IconCmdLargeRsc ICONCMDID_space_place =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_SPACE_PLACE,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };*/
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdLarge Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------*/
IconCmdLargeRsc ICONCMDID_space_modify =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_SPACE_MODIFY,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0,11, 0, 0,11,  7, 7,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0,11, 0, 0,11,  7, 1, 7,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  7, 7, 7, 7, 7,  7, 1, 1, 7,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  7, 1, 1, 1, 1,  1, 1, 1, 1, 7,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  7, 1, 1, 1, 1,  1, 1, 1, 1, 1,  7,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  7, 1, 1, 1, 1,  1, 1, 1, 1, 7,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  7, 7, 7, 7, 7,  7, 1, 1, 7,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0,11, 0, 0,11,  7, 1, 7,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0,11, 0, 0,11,  7, 7,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };
	
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdLarge Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------
IconCmdLargeRsc ICONCMDID_rein_linestring =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_REIN_LINESTRING,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 7, 7, 7,  7, 7,11,11,11, 11,11,11,11,11,  1, 1,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 7, 4, 4,  4, 7, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 7, 4, 7,  4, 7, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 7, 4, 4,  4, 7, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 7, 7, 7,  7, 7,11,11,11, 11,11,11,11,11,  1, 1,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,10,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,10,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,10,11,10, 11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,10,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,10,11,11,11, 11,11,11,11,11, 11,
    11,11,10,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,10,11,11,11, 11,11,11,11,11, 11,
    11,11,10,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,10,10,10,10, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };*/
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdLarge Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------
IconCmdLargeRsc ICONCMDID_rein_iso =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_REIN_ISO,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 11, 0,11, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11, 0,11, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,10, 0,10,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,10,  0,10, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,10, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11, 0, 0, 0,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };*/
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdLarge Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------*/
IconCmdLargeRsc ICONCMDID_rein_3d =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_REIN_3D,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0, 0,11, 11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,11,  0,11, 0,11,11, 11,11,11,11,11, 11,11,11,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,11,  0,11, 0,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,10,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0,  0,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11, 0,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11, 0,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11, 0, 0,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11, 0,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11, 0,11, 0, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11, 0,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdLarge Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------*/
IconCmdLargeRsc ICONCMDID_ismodel =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_TOOLTIP,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,10, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,10, 7, 0,  7, 0, 7, 0, 7,  0, 7, 0, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,10, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,10, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,10, 7, 7,  7, 7, 0, 0, 0,  7, 0, 7, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,10, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0, 10,11,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0,  0,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0,  7, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0,  7, 7, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0,  7, 7, 7, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0,  7, 7, 7, 7, 0, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0,  7, 7, 7, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0,  0, 0, 7, 7, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,10, 0, 7, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11, 0, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };

/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdLarge Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------*/
IconCmdLargeRsc ICONCMDID_rein_chlap =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_REIN_CHLAP,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,12,  1,11,11,11,11, 11,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11,11,11,12,  1,11, 0,10,11, 11,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11,11,11,12,  1,11, 0,10,11, 11,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11,11,11,12,  1,11, 0,10,11, 11,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11,11,11,12,  1,11, 0,10,11, 11,11,11,11,12,  1,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11,11,11,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}    };


/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdLarge Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------
IconCmdLargeRsc ICONCMDID_rein_ungrab =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_REIN_UNGRAB,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,11,  0,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11, 4, 4,11, 11,11,11,11,11,  4, 4,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11,11, 4, 4, 11,11,11,11, 4,  4,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11,11,11, 4,  4,11,11, 4, 4, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11,11,11,11,  4, 4, 4, 4,11, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11,11,11,11, 11, 4, 4,11,11, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0,11,11,11,11,  4, 4, 4, 4,11, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11,  0, 0,11,11, 4,  4,11,11, 4, 4, 11,11, 0, 0, 0,  0,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11, 4, 4, 11,11,11,11, 4,  4,11,10,10,10, 10,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11, 4, 4,11, 11,11,11,11,11,  4, 4,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,10, 10,10,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };
	*/
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdLarge Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------*/
//IconCmdLargeRsc ICONCMDID_rein_bar =
//    {
//    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, "",
//{
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,11,  0,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0,11,11,11,11,  1, 1, 1, 1,11, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0,11,11,11, 1,  1,11,11, 1, 1, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0,11,11,11, 1, 11,11,11,11, 1, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0,11,11,11,11, 11,11,11, 1, 1, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0,11,11,11,11, 11,11, 1, 1,11, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0,11,11,11,11, 11, 1, 1,11,11, 11,11,11,11,11,  0,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0, 0,11,11,11, 11,11,11,11,11, 11,11, 0, 0, 0,  0,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11, 1, 1,11,11, 11,11,10,10,10, 10,10,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11, 1, 1,11,11, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11, 0,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,10,10, 10,10,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//
//}
//    };






/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdSmall Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------
IconCmdSmallRsc ICONCMDID_space_place =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_SPACE_PLACE,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 11,11,11,
    11,11,11,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11,  0,11,11,11, 0, 11,11,11, 0,11, 11,11, 0,11,10, 11,11,11,
    11,11,11,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,10, 11,11,11,
    11,11,11,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };
	*/
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdSmall Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------*/
IconCmdSmallRsc ICONCMDID_space_modify =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_SPACE_MODIFY,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0, 0,11, 0,  0,11, 0, 0,11,  7, 7,11,11,11,  0,11, 0,11, 0, 11, 0,11,
    11, 0, 0,11, 0,  0,11, 0, 0,11,  7, 1, 7,11,11,  0,11, 0,11, 0, 11, 0,11,
    11, 0, 0,11, 0,  7, 7, 7, 7, 7,  7, 1, 1, 7,11,  0,11, 0,11, 0, 11, 0,11,
    11, 0, 0,11, 0,  7, 1, 1, 1, 1,  1, 1, 1, 1, 7,  0,11, 0,11, 0, 11, 0,11,
    11, 0, 0,11, 0,  7, 1, 1, 1, 1,  1, 1, 1, 1, 1,  7,11, 0,11, 0, 11, 0,11,
    11, 0, 0,11, 0,  7, 1, 1, 1, 1,  1, 1, 1, 1, 7,  0,11, 0,11, 0, 11, 0,11,
    11, 0, 0,11, 0,  7, 7, 7, 7, 7,  7, 1, 1, 7,11,  0,11, 0,11, 0, 11, 0,11,
    11, 0, 0,11, 0,  0,11, 0, 0,11,  7, 1, 7,11,11,  0,11, 0,11, 0, 11, 0,11,
    11, 0, 0,11, 0,  0,11, 0, 0,11,  7, 7,11,11,11,  0,11, 0,11, 0, 11, 0,11,
    11, 0, 0,11, 0,  0,11, 0, 0,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };
	
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdSmall Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------
IconCmdSmallRsc ICONCMDID_rein_linestring =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_LINESTRING,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11, 7, 7, 7,  7, 7,11,11,11, 11,11,11,11,11,  1, 1,11,11,11, 11,11,11,
    11,11, 7, 4, 4,  4, 7, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1,11, 11,11,11,
    11,11, 7, 4, 7,  4, 7, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1,11,11,
    11,11, 7, 4, 4,  4, 7, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1,11, 11,11,11,
    11,11, 7, 7, 7,  7, 7,11,11,11, 11,11,11,11,11,  1, 1,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0,11,11, 11,11,11,
    11,11,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,10,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 11,11,11,
    11,11,10,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,10,11,10, 11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,
    11,11,10,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,10,11,
    11,11,10,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,10,11,
    11,11,10,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,10,11,
    11,11,11,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,10,10,10,10, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };
	*/
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdSmall Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------
IconCmdSmallRsc ICONCMDID_rein_iso =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_ISO,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11, 0,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11, 0,11, 11,11,11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 11, 0,11, 0,11,  0,11,11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11, 0,11, 0,11,  0,11,11,
    11, 0,11, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11, 0,11,  0,11,11,
    11, 0,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,11,  0,11,11,
    11, 0,10, 0,10,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11,  0,11,11,
    11,11,11, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11,11,
    11,11,11, 0,10,  0,10, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,
    11,11,11,11,11,  0,11, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  0,10, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 0, 0, 0,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };
	*/
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdSmall Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------
IconCmdSmallRsc ICONCMDID_rein_3d =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_3D,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,11,11, 11,11,11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0,11, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,
    11, 0, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0, 0,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0,11,11, 11,11,11,
    11,11, 0, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,10,11,11, 11,11,11,
    11,11, 0, 0,11, 11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 11,11,11,
    11,11,11, 0,11,  0,11, 0,11,11, 11,11,11,11,11, 11,11,11,11,10, 11,11,11,
    11,11,11, 0,11,  0,11, 0,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,10,
    11,11,11,11, 0,  0,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  0,11, 0,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  0,11, 0,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11, 0, 0,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 0,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 0,11, 0, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,
    11,11,11,11,11, 11,11,11, 0,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,
    11,11,11,11,11, 11,11,11,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };
	*/
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdSmall Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------*/
IconCmdSmallRsc ICONCMDID_ismodel =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_TOOLTIP,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,11,11,
    11,11,11,11,11, 11,11,10, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,
    11,11,11,11,11, 11,11,10, 7, 0,  7, 0, 7, 0, 7,  0, 7, 0, 7, 7, 10,11,11,
    11,11,11,11,11, 11,11,10, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,
    11,11,11,11,11, 11,11,10, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,
    11,11,11,11,11, 11,11,10, 7, 7,  7, 7, 0, 0, 0,  7, 0, 7, 7, 7, 10,11,11,
    11,11,11,11,11, 11,11,10, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,
    11,11,11,11, 0, 10,11,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,11,11,
    11,11,11,11, 0,  0,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0,  7, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0,  7, 7, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0,  7, 7, 7, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0,  7, 7, 7, 7, 0, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0,  7, 7, 7, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0,  0, 0, 7, 7, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,10, 0, 7, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 0, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };

/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdSmall Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------*/
IconCmdSmallRsc ICONCMDID_rein_chlap =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_CHLAP,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,
    11,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,11,12,  1,11,11,
    11,11,11,11,11, 11,11,11,11,12,  1,11,11,11,11, 11,11,11,11,12,  1,11,11,
    11,11, 0,10,11, 11,11,11,11,12,  1,11, 0,10,11, 11,11,11,11,12,  1,11,11,
    11,11, 0,10,11, 11,11,11,11,12,  1,11, 0,10,11, 11,11,11,11,12,  1,11,11,
    11,11, 0,10,11, 11,11,11,11,12,  1,11, 0,10,11, 11,11,11,11,12,  1,11,11,
    11,11, 0,10,11, 11,11,11,11,12,  1,11, 0,10,11, 11,11,11,11,12,  1,11,11,
    11,11, 0,10,11, 11,11,11,11,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,
    11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11, 0,10,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };

/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdSmall Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------
IconCmdSmallRsc ICONCMDID_rein_ungrab =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_UNGRAB,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,
    11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,11,  0,10,11,
    11,11,11,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,10,11,
    11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,10,11,
    11,11,11,11,11,  0,11, 4, 4,11, 11,11,11,11,11,  4, 4,11,11,11,  0,10,11,
    11,11,11,11,11,  0,11,11, 4, 4, 11,11,11,11, 4,  4,11,11,11,11,  0,10,11,
    11,11,11,11,11,  0,11,11,11, 4,  4,11,11, 4, 4, 11,11,11,11,11,  0,10,11,
    11,11,11,11,11,  0,11,11,11,11,  4, 4, 4, 4,11, 11,11,11,11,11,  0,10,11,
    11,11,11,11,11,  0,11,11,11,11, 11, 4, 4,11,11, 11,11,11,11,11,  0,10,11,
    11,11,11,11,11,  0,11,11,11,11,  4, 4, 4, 4,11, 11,11,11,11,11,  0,10,11,
    11,11,11,11,11,  0, 0,11,11, 4,  4,11,11, 4, 4, 11,11, 0, 0, 0,  0,10,11,
    11,11,11,11,11, 11,11,11, 4, 4, 11,11,11,11, 4,  4,11,10,10,10, 10,10,11,
    11,11,11,11,11, 11,11, 4, 4,11, 11,11,11,11,11,  4, 4,11, 0,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,10, 11,11,11,
    11,11, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,10, 11,11,11,
    11,11, 0,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 11,11,11,
    11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,10,10, 10,10,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };
	*/
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdSmall Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------*/
//IconCmdSmallRsc ICONCMDID_rein_bar =
//    {
//    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_BAR,
//{
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,
//    11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,11,  0,10,11,
//    11,11,11,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,10,11,
//    11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,10,11,
//    11,11,11,11,11,  0,11,11,11,11,  1, 1, 1, 1,11, 11,11,11,11,11,  0,10,11,
//    11,11,11,11,11,  0,11,11,11, 1,  1,11,11, 1, 1, 11,11,11,11,11,  0,10,11,
//    11,11,11,11,11,  0,11,11,11, 1, 11,11,11,11, 1, 11,11,11,11,11,  0,10,11,
//    11,11,11,11,11,  0,11,11,11,11, 11,11,11, 1, 1, 11,11,11,11,11,  0,10,11,
//    11,11,11,11,11,  0,11,11,11,11, 11,11, 1, 1,11, 11,11,11,11,11,  0,10,11,
//    11,11,11,11,11,  0,11,11,11,11, 11, 1, 1,11,11, 11,11,11,11,11,  0,10,11,
//    11,11,11,11,11,  0, 0,11,11,11, 11,11,11,11,11, 11,11, 0, 0, 0,  0,10,11,
//    11,11,11,11,11, 11,11,11,11,11, 11, 1, 1,11,11, 11,11,10,10,10, 10,10,11,
//    11,11,11,11,11, 11,11,11,11,11, 11, 1, 1,11,11, 11,11,11, 0,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,10, 11,11,11,
//    11,11, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,10, 11,11,11,
//    11,11, 0,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 11,11,11,
//    11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,10,10, 10,10,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//
//}
//    };

IconCmdSmallRsc ICONCMDID_rein_list =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_LIST,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,
    11, 0, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 0,11, 0,11, 11,11,11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,
    11, 0, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 0,11, 11,11,11,
    11, 0, 7,10,10, 10, 7,10,10, 7, 10,10,10,10, 7, 10,10, 7, 0,11, 11,11,11,
    11, 0, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 0,11, 11,11,11,
    11, 0, 7,10,10, 10, 7,10,10, 7, 10,10,10,10, 7, 10,10, 7, 0,11, 11,11,11,
    11, 0, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 0,11, 11,11,11,
    11, 0, 7,10,10, 10, 7,10,10, 7, 10,10,10,10, 7, 10,10, 7, 0,11, 11,11,11,
    11, 0, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 0,11, 11,11,11,
    11, 0, 7,10,10, 10, 7,10,10, 7, 10,10,10,10, 7, 10,10, 7, 0,11, 11,11,11,
    11, 0, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 0,11, 11,11,11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,
    11,11,11,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0, 11,11, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,
    11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 0,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,
    11,11,11,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };


IconCmdLargeRsc ICONCMDID_rein_list =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_REIN_LIST,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 0,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 7,10,10, 10, 7,10,10, 7, 10,10,10,10, 7, 10,10, 7, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 7,10,10, 10, 7,10,10, 7, 10,10,10,10, 7, 10,10, 7, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 7,10,10, 10, 7,10,10, 7, 10,10,10,10, 7, 10,10, 7, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 7,10,10, 10, 7,10,10, 7, 10,10,10,10, 7, 10,10, 7, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7,  7, 7, 7, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0, 11,11, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11, 0,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };
	
IconCmdSmallRsc ICONCMDID_rein_bar =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, DGREY_INDEX, TXT_ICSM_REIN_ANKER,
{
    //11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11, 9, 9, 9, 9,  9, 9,11,
    //11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,
    //11,11,11,11, 9, 11, 0,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,11,
    //11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11, 9, 9, 9, 9,  9, 9,11,
    //11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0,10,11, 0, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0,10, 0,10, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0, 0,10,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11,10,11,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,
    //11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11, 7, 7, 7,  7, 7,11,11,11, 11,11,11,11,11,  1, 1,11,11,11, 11,11,11,
    11,11, 7, 4, 4,  4, 7, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1,11, 11,11,11,
    11,11, 7, 4, 7,  4, 7, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1,11,11,
    11,11, 7, 4, 4,  4, 7, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1,11, 11,11,11,
    11,11, 7, 7, 7,  7, 7,11,11,11, 11,11,11,11,11,  1, 1,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0,11,11, 11,11,11,
    11,11,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,10,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 11,11,11,
    11,11,10,11,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,10,11,10, 11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,
    11,11,10,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,10,11,
    11,11,10,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,10,11,
    11,11,10,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,10,11,
    11,11,11,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,10, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,10,10,10,10, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
}
    };

/*
IconCmdLargeRsc ICONCMDID_rein_bar =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, DGREY_INDEX, TXT_ICLG_REIN_ANKER,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11, 9, 9, 9, 9,  9, 9,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,10,10, 10,10,10,10,10, 10,10,10,10,10, 10,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11, 9, 9, 9, 9,  9, 9,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,11, 0, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10, 0,10, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0, 0,10,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11, 0,10,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11,10,11,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 9, 11,11,11,11,11, 11,11,11,11,11, 11, 9,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };
*/	
/*

IconCmdSmallRsc ICONCMDID_rein_nodes =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_NODES,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,10,10,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 10,13,13,13,13, 10,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,10,13, 13, 3, 3, 3, 3, 13,13,11,11,11, 11,11,11,
    11,11,11,11,11, 11,13,13, 3, 3,  3, 3, 3, 3, 3,  3, 3,13,10,11, 11,11,11,
    11,11,11,10,13, 13, 3, 3, 3, 3,  3, 3, 3, 3, 3,  3, 3, 3, 3,13, 11,11,11,
    11,11,10,13, 3,  3, 3, 3, 3, 3,  3, 3, 3, 3, 3,  3, 3, 3, 3,13, 13,10,11,
    11,11,13,14,13, 13, 3, 3, 3, 3,  3, 3, 3, 3, 3,  3, 3,13,10,15, 15,10,11,
    11,11,14, 2, 2, 14,13,13, 3, 3,  3, 3, 3, 3, 3, 13,15,15, 4, 4,  4,10,11,
    11,11,14, 2, 2,  2, 2,14,13,13,  3, 3,13,13,15,  4, 4, 4, 4, 4,  4,10,11,
    11,11,10, 2, 2,  2, 2, 2, 2,14, 13,10,15, 4, 4,  4, 4, 4, 4, 4,  4,10,11,
    11,11,13, 2, 2,  2, 2, 2, 2, 2, 15, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,
    11,11,13, 2, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,
    11,11,14, 2, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,
    11,11,17, 2, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,
    11,11,13, 2, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,
    11,11,14, 2, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,
    11,11,10,14, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4, 15,10,11,
    11,11,11,10,14,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4,15, 10,11,11,
    11,11,11,11,11, 10,14, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4,15,10,11, 11,11,11,
    11,11,11,11,11, 11,10,14, 2, 2, 17, 4, 4, 4,15, 10,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,10,17, 15,15,15,10,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 10,10,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };


IconCmdLargeRsc ICONCMDID_rein_nodes =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_REIN_NODES,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,10,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 10,13,13,13,13, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,10,13, 13, 3, 3, 3, 3, 13,13,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,13,13, 3, 3,  3, 3, 3, 3, 3,  3, 3,13,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,13, 13, 3, 3, 3, 3,  3, 3, 3, 3, 3,  3, 3, 3, 3,13, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,10,13, 3,  3, 3, 3, 3, 3,  3, 3, 3, 3, 3,  3, 3, 3, 3,13, 13,10,11,11,11, 11,11,11,11,11, 11,
    11,11,13,14,13, 13, 3, 3, 3, 3,  3, 3, 3, 3, 3,  3, 3,13,10,15, 15,10,11,11,11, 11,11,11,11,11, 11,
    11,11,14, 2, 2, 14,13,13, 3, 3,  3, 3, 3, 3, 3, 13,15,15, 4, 4,  4,10,11,11,11, 11,11,11,11,11, 11,
    11,11,14, 2, 2,  2, 2,14,13,13,  3, 3,13,13,15,  4, 4, 4, 4, 4,  4,10,11,11,11, 11,11,11,11,11, 11,
    11,11,10, 2, 2,  2, 2, 2, 2,14, 13,10,15, 4, 4,  4, 4, 4, 4, 4,  4,10,11,11,11, 11,11,11,11,11, 11,
    11,11,13, 2, 2,  2, 2, 2, 2, 2, 15, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,11,11, 11,11,11,11,11, 11,
    11,11,13, 2, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,11,11, 11,11,11,11,11, 11,
    11,11,14, 2, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,11,11, 11,11,11,11,11, 11,
    11,11,17, 2, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,11,11, 11,11,11,11,11, 11,
    11,11,13, 2, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,11,11, 11,11,11,11,11, 11,
    11,11,14, 2, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,10,11,11,11, 11,11,11,11,11, 11,
    11,11,10,14, 2,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4, 4, 15,10,11,11,11, 11,11,11,11,11, 11,
    11,11,11,10,14,  2, 2, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4, 4, 4,15, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 10,14, 2, 2, 2, 17, 4, 4, 4, 4,  4, 4,15,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,10,14, 2, 2, 17, 4, 4, 4,15, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,10,17, 15,15,15,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 10,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };
	*/

//IconCmdSmallRsc ICONCMDID_rein_mirror =
//    {
//    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_MIRROR,
//{
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,
//    11,11,11,11,11, 11,11,11, 0, 0,  0,11,11,11,11, 11,11, 0, 0,11, 11,11,11,
//    11,11,11,11,11, 11,11, 0, 0, 0, 11,11,11,11,11, 11,11, 0, 0,11, 11,11,11,
//    11,11,11,11,11, 11, 0, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11,  0, 0, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11, 0, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11, 0, 0, 0, 0,  0, 0,11, 0, 0,  0, 0,11, 0, 0,  0, 0,11, 0, 0,  0, 0,11,
//    11,10,10,10,10, 10,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 10,10,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,10,10,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,10,10,10, 11,11,11,11,11, 11,11,10,10,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,10,10, 10,11,11,11,11, 11,11,10,10,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,10, 10,10,10,10,10, 10,10,10,10,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 10,10,10,10,10, 10,10,10,10,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//
//}
//    };

//IconCmdLargeRsc ICONCMDID_rein_mirror =
//    {
//    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_REIN_MIRROR,
//{
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11, 0, 0,  0,11,11,11,11, 11,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11, 0, 0, 0, 11,11,11,11,11, 11,11, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11, 0, 0, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11,  0, 0, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11, 0, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11, 0, 0, 0, 0,  0, 0,11, 0, 0,  0, 0,11, 0, 0,  0, 0,11, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,
//    11,10,10,10,10, 10,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 10,10,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,10,10,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,10,10,10, 11,11,11,11,11, 11,11,10,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,10,10, 10,11,11,11,11, 11,11,10,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,10, 10,10,10,10,10, 10,10,10,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 10,10,10,10,10, 10,10,10,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
//
//}
//    };

/*
IconCmdSmallRsc ICONCMDID_rein_ends =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_ENDS,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 4, 4,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11, 4,11,11, 4, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11, 4,11,11, 4, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11, 4,11,11, 4, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  4,11,11,11,11,  4,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  4,11,11,11,11,  4,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  4,11,11,11,11,  4,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  4,11,10,10,10,  4,10,10,10,10, 10,10,10,11,11, 11,11,11,
    11,11,11,11,11,  4,11,10,10,10,  4,10,10,10,10, 10,10,10,11,11, 11,11,11,
    11,11,11,11,11,  4,11,11,11,11,  4,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  4,11,11,11,11,  4,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  4,11,11,11,11,  4,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11, 4,11,11, 4, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11, 4,11,11, 4, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11, 4,11,11, 4, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 4, 4,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };

IconCmdSmallRsc ICONCMDID_rein_cont =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_CONT,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,11,11, 11,11,11,
    11,11,11,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11, 0,11,11,11, 11,11,11,
    11,11,11,11, 0, 11,10,10,10,10, 10,10,10,10,10, 11, 0,11,10,11, 11,11,11,
    11,11,11,11, 0, 11,10,11,11,11, 11,11,11,11,11, 11, 0,11,10,11, 11,11,11,
    11,11,11,11, 0, 11,10,11,11,11, 11,11,11,11,11, 11, 0,11,10,11, 11,11,11,
    11,11,11,11, 0, 11,10,11,11,11, 11,11,11,11,11, 11, 0,11,10,11, 11,11,11,
    11,11,11,11, 0, 11,10,11,11,11, 11,11,11,11,11, 11, 0,11,10,11, 11,11,11,
    11,11,11,11, 0, 11,10,11,11,11, 11,11,11,11,11, 11, 0,11,10,11, 11,11,11,
    11,11,11,11, 0, 11,10,11,11,11, 11,11,11,11,11, 11, 0,11,10,11, 11,11,11,
    11,11,11,11, 0, 11,10,11,11,11, 11,11,11,11,11, 11, 0,11,10,11, 11,11,11,
    11,11,11,11, 0, 11,10,11,11,11, 11,11,11,11,11, 11, 0,11,10,11, 11,11,11,
    11,11,11,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11, 0,11,10,11, 11,11,11,
    11,11,11,11, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,10,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,10,11, 11,11,11,
    11,11,11,11,11, 11,10,10,10,10, 10,10,10,10,10, 10,10,10,10,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };

//IconCmdSmallRsc ICONCMDID_rein_vecs =
//    {
//    23, 23, ICONFORMAT_FIXEDCOLORS, MGREY_INDEX, TXT_ICSM_REIN_VECS,
//{
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11, 4, 4,11,11, 11,11,11,11,11, 11, 4, 4,11,11, 11,11,11,11,11, 11,11,11,
//    11, 4, 4, 4,11, 11,11,11,11,11,  4, 4, 4,11,11, 11,11,11,11,11, 11,11,11,
//    11,11, 4, 4, 4, 11,11,11,11, 4,  4, 4,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11, 4, 4,  4,11,11, 4, 4,  4,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11, 4,  4, 4, 4, 4, 4, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11,  4, 4, 4, 4,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11,11,  4, 4, 4, 4,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11,11, 4,  4, 4, 4, 4, 4, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11,11, 4, 4,  4,11,11, 4, 4,  4,11,11,11,11, 11,11,11,11,11, 11,11,11,
//    11,11, 4, 4, 4, 11,11,11,11, 4,  4, 4,11,11, 4,  4, 4,11,11,11, 11,11,11,
//    11, 4, 4, 4,11, 11,11,11,11,11,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4, 11,11,11,
//    11, 4, 4,11,11, 11,11,11,11,11,  4, 4, 4, 4,11, 11,11, 4, 4, 4,  4,11,11,
//    11,11,11,11,11, 11,11,11,11,11,  4, 4,11,11,11, 11,11,11,11, 4,  4,11,11,
//    11,11,11,11,11, 11,11,11,11, 4,  4, 4,11,11,11, 11,11,11,11, 4,  4, 4,11,
//    11,11,11,11,11, 11,11,11,11, 4,  4,11,11,11,11, 11,11,11,11,11,  4, 4,11,
//    11,11,11,11,11, 11,11,11,11, 4,  4,11,11,11,11, 11,11,11,11,11,  4, 4,11,
//    11,11,11,11,11, 11,11,11,11, 4,  4, 4,11,11,11, 11,11,11,11, 4,  4, 4,11,
//    11,11,11,11,11, 11,11,11,11,11,  4, 4,11,11,11, 11,11,11,11, 4,  4,11,11,
//    11,11,11,11,11, 11,11,11,11,11,  4, 4, 4, 4,11, 11,11, 4, 4, 4,  4,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11, 4, 4, 4, 4,  4, 4, 4, 4, 4, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 4,  4, 4,11,11,11, 11,11,11,
//    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
//
//}
//    };

IconCmdSmallRsc ICONCMDID_rein_side =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_SIDE,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11, 0, 0, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11, 0, 0, 0, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11, 0,11, 0, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,10, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11, 0, 0,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11, 0, 0,11,11, 11,11,11,
    11,11,11,11,11, 11,10, 0, 0, 0,  0, 0, 0, 0, 0,  0,10,11,11,11, 11,11,11,
    11,11,11,11,11,  0, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,10, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11, 0, 0,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11, 0, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };
	*/
IconCmdLargeRsc ICONCMDID_rein_flags =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_REIN_FLAGS,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,10, 10,11,11,11,11, 11,10,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0, 3,  3,10,10,11,11, 10, 3, 3,10,10, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0, 3,  3, 3, 3,10,10,  3, 3, 3, 3, 3, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0, 3,  3, 3, 3, 3, 3,  3, 3, 3, 3, 3, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0, 3,  3, 3, 3, 0,10, 10, 3, 3, 3, 3,  3,10,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0, 3,  3, 3, 3, 0, 7,  7,10,10, 3, 3, 10, 7, 7,10,10, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0, 3,  3, 3, 3, 0, 7,  7, 7, 7,10,10,  7, 7, 7, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,10, 10, 3, 3, 0, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,11, 11,10,10, 0, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,11, 11,11,11, 0, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,11, 11,11,11, 0, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,11, 11,11,11, 0,10, 10, 7, 7, 7, 7,  7,10,10, 7, 7, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,11, 11,11,11, 0,11, 11,10,10, 7, 7, 10,11,11,10,10, 10,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,11, 11,11,11, 0,11, 11,11,11,10,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };


IconCmdSmallRsc ICONCMDID_rein_flags =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_FLAGS,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11, 0,10, 10,11,11,11,11, 11,10,10,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11, 0, 3,  3,10,10,11,11, 10, 3, 3,10,10, 10,11,11,11,11, 11,11,11,
    11,11,11, 0, 3,  3, 3, 3,10,10,  3, 3, 3, 3, 3, 10,11,11,11,11, 11,11,11,
    11,11,11, 0, 3,  3, 3, 3, 3, 3,  3, 3, 3, 3, 3, 10,11,11,11,11, 11,11,11,
    11,11,11, 0, 3,  3, 3, 3, 0,10, 10, 3, 3, 3, 3,  3,10,10,11,11, 11,11,11,
    11,11,11, 0, 3,  3, 3, 3, 0, 7,  7,10,10, 3, 3, 10, 7, 7,10,10, 10,11,11,
    11,11,11, 0, 3,  3, 3, 3, 0, 7,  7, 7, 7,10,10,  7, 7, 7, 7, 7, 10,11,11,
    11,11,11, 0,10, 10, 3, 3, 0, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,
    11,11,11, 0,11, 11,10,10, 0, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,
    11,11,11, 0,11, 11,11,11, 0, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,
    11,11,11, 0,11, 11,11,11, 0, 7,  7, 7, 7, 7, 7,  7, 7, 7, 7, 7, 10,11,11,
    11,11,11, 0,11, 11,11,11, 0,10, 10, 7, 7, 7, 7,  7,10,10, 7, 7, 10,11,11,
    11,11,11, 0,11, 11,11,11, 0,11, 11,10,10, 7, 7, 10,11,11,10,10, 10,11,11,
    11,11,11, 0,11, 11,11,11, 0,11, 11,11,11,10,10, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
    };
	
/*----------------------------------------------------------------------+
|                                                                       |
|    IconCmdLarge Item Resource 			    	|
|                                                                       |
+----------------------------------------------------------------------*/
IconCmdLargeRsc ICONCMDID_rein_note =
    {
    31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICLG_REIN_NOTE,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,10, 0, 0,  0,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0, 0, 0,  0, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11, 0, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11,10, 0, 11,11,11,11,11,  0,10,11,11,11, 11,11, 0,10,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,10, 0,11, 11,11,11,11,11, 11, 0, 0, 0,11, 11,11,11, 0,10,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,10, 0,11, 11,11,11,11,11, 11, 0, 0, 0,11, 11,11,11, 0,10,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11,10, 0, 11,11,11,11,11, 11,11, 0,11,11, 11,11, 0,10,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
    };


IconCmdSmallRsc ICONCMDID_rein_note =
    {
    23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_NOTE,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11, 0,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11, 0, 11, 0,11, 0,11, 11,11,11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 11, 0,11, 0,11,  0,11,11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11, 0,11, 0,11,  0,11,11,
    11, 0,11, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11, 0,11,  0,11,11,
    11, 0,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11, 0,11,  0,11,11,
    11, 0,10, 0,10,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0,11,  0,11,11,
    11,11,11, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11,  0,11,11,
    11,11,11, 0,10,  0,10, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,
    11,11,11,11,11,  0,11, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11,  0,10, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 0, 0, 0,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
}
    };
	
IconCmdSmallRsc ICONCMDID_rein_note2 =
{
23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, TXT_ICSM_REIN_LINESTRING,
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11, 0,11,  0,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,10, 0, 0,  0,10,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0, 0, 0, 0,  0, 0,10,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11, 0,10,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11, 0,10, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11, 0, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11, 0,11,10, 0, 11,11,11,11,11,  0,10,11,11,11, 11,11, 0,10,11,  0,11,11,
    11, 0,10, 0,11, 11,11,11,11,11, 11, 0, 0, 0,11, 11,11,11, 0,10,  0,11,11,
    11, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0,11,11,
    11, 0,10, 0,11, 11,11,11,11,11, 11, 0, 0, 0,11, 11,11,11, 0,10,  0,11,11,
    11, 0,11,10, 0, 11,11,11,11,11, 11,11, 0,11,11, 11,11, 0,10,11,  0,11,11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,
    11, 0,11,11,11, 11,11,11,11,11, 11,11, 0,11,11, 11,11,11,11,11,  0,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
}
};


/*
IconCmdLargeRsc ICONCMDID_embdb_note =
{
31, 31, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, "note",
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11,  0,11,11,11, 0, 11,11, 0, 0, 0, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11,  0, 0,11, 0, 0, 11, 0,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11,  0,11,11,11, 0, 11, 0,11,11,11,  0,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11,  0,11,11,11, 0, 11,11, 0, 0, 0, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,10,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,10, 0, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,10, 0,10, 11,11,11,11, 0,  0, 0, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,10, 0,10,11, 11,11,11,11, 0, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 10, 0,10,11,11, 11,11,11,11, 0, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0, 0, 0,  0,10,11,11,11, 11,11,11,11, 0, 11,11,11, 0,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11, 0,  0, 0, 0,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11, 0, 0, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,

}
};

IconCmdSmallRsc ICONCMDID_embdb_note =
{
23, 23, ICONFORMAT_FIXEDCOLORS, BLACK_INDEX, "note",
{
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11,  0,11,11,11, 0, 11,11, 0, 0, 0, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11,  0, 0,11, 0, 0, 11, 0,11,11,11,  0,11,11,
    11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11,  0,11, 0,11, 0, 11, 0,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11,  0,11,11,11, 0, 11, 0,11,11,11,  0,11,11,
    11,11,11,11,11, 11,11,11,11,11,  0,11,11,11, 0, 11,11, 0, 0, 0, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,10,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0,11,
    11,11,11,11,11, 11,11,11,10, 0, 10,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,10, 0,10, 11,11,11,11, 0,  0, 0, 0,11,11, 11,11,11,
    11,11,11,11,11, 11,10, 0,10,11, 11,11,11,11, 0, 11,11,11, 0,11, 11,11,11,
    11,11,11,11,11, 10, 0,10,11,11, 11,11,11,11, 0, 11,11,11, 0,11, 11,11,11,
    11,11, 0, 0, 0,  0,10,11,11,11, 11,11,11,11, 0, 11,11,11, 0,11, 11,11,11,
    11, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11, 0,  0, 0, 0,11,11, 11,11,11,
    11, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11, 0, 11,11,11,11,11, 11,11,11,
    11, 0, 0, 0, 0,  0,11,11,11,11, 11,11,11,11, 0, 11,11,11,11,11, 11,11,11,
    11,11, 0, 0, 0, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,
    11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,11,11, 11,11,11,

}
};

*/


StringList STRLIST_MODEL =
{
    1,
    {
    { {0}, "Drawing" },
    { {0}, "Model" },
    { {0}, "Cage" },
    }
};




DItem_ComboBoxRsc COMBOBOX_MODEL = // used in ICONCMDID_ismodel2
    {
    CMD_REIN_MODE, 
    LCMD, NOSYNONYM, NOHELP, MHELP,
    NOHOOK, // HOOKID_Combo_Model, 
    NOARG,
    20, "", "", "", "", NOMASK,
    STRLIST_MODEL, // Id of initial string list used 
	3, // Number of rows to show in list 
	1, // Gap between textedit & button 
	10*XC, // Width of dropdown listbox
	0, // Index of Column to get value from
    COMBOATTR_READONLY | COMBOATTR_INDEXISVALUE, // | COMBOATTR_SORT | COMBOATTR_LABELABOVE, COMBOATTR_DRAWPREFIXICON, 
    //COMBOATTR_READONLY, // | COMBOATTR_SORT | COMBOATTR_LABELABOVE, 
    "", // label
    "isModel", // access str
        {
            {10, 20, ALIGN_LEFT, ""},
        }
    };

#endif

/*

DItem_OptionButtonRsc 100 =
{
NOSYNONYM, NOHELP, MHELP, NOHOOK, NOARG, "",
"",
{
{Icon, ICONID_LineStyle0, NOCMD, LCMD, 0, NOMASK, ON, ""},
{Icon, ICONID_LineStyle1, NOCMD, LCMD, 1, NOMASK, ON, ""},
{Icon, ICONID_LineStyle2, NOCMD, LCMD, 2, NOMASK, ON, ""},
{Icon, ICONID_LineStyle3, NOCMD, LCMD, 3, NOMASK, ON, ""},
{Icon, ICONID_LineStyle4, NOCMD, LCMD, 4, NOMASK, ON, ""},
{Icon, ICONID_LineStyle5, NOCMD, LCMD, 5, NOMASK, ON, ""},
{Icon, ICONID_LineStyle6, NOCMD, LCMD, 6, NOMASK, ON, ""},
{Icon, ICONID_LineStyle7, NOCMD, LCMD, 7, NOMASK, ON, ""},
}
};
*/
