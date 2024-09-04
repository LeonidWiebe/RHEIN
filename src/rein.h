


#ifndef _REIN_H_
#define _REIN_H_



#if defined (MSVERSION) && (MSVERSION == 0xa00)

#include <Mstn\MicroStation.r.h>
#include <Mstn\MdlApi\dlogids.r.h>

#define     TXTJUST_LT                  0       /* Left Top */
#define     TXTJUST_LC                  1       /* Left Center */
#define     TXTJUST_LB                  2       /* Left Bottom */
#define     TXTJUST_LMT                 3       /* Left Margin Top */
#define     TXTJUST_LMC                 4       /* Left Margin Center */
#define     TXTJUST_LMB                 5       /* Left Margin Bottom */
#define     TXTJUST_CT                  6       /* Center Top */
#define     TXTJUST_CC                  7       /* Center Center */
#define     TXTJUST_CB                  8       /* Center Bottom */
#define     TXTJUST_RMT                 9       /* Right Margin Top */
#define     TXTJUST_RMC                 10      /* Right Margin Center */
#define     TXTJUST_RMB                 11      /* Right Margin Bottom */
#define     TXTJUST_RT                  12      /* Right Top */
#define     TXTJUST_RC                  13      /* Right Center */
#define     TXTJUST_RB                  14      /* Right Bottom */




#endif



#if defined (MSVERSION) && (MSVERSION == 0xa00)
#define RTYPE_REIN        'rein'
#else
#define RTYPE_REIN			RTYPE ('r', 'e', 'i', 'n')
#endif

#define	RSCID_ReinPrefs		1
#define	RSCID_ReinDopPrefs		2
#define	RSCID_ReinBarPrefs		3
#define	RSCID_ReinNotePrefs		4

// double and float comparison
#define DBL_EPSILON     2.2204460492503131e-016 /* smallest such that 1.0+DBL_EPSILON != 1.0 */
#define FLT_EPSILON_1     1.192092896e-07        /* smallest such that 1.0+FLT_EPSILON != 1.0 */
#define FLT_EPSILON_2     1.192092896e-04        // сделано потому что иногда попадается > 1.192092896e-07 
#define EQ(x,v) (((v - FLT_EPSILON_2) < x) && (x <( v + FLT_EPSILON_2)))
#define EQQ(x,v,t) (((v - t) < x) && (x <( v + t)))

#define SGN(x) ((x > 0) ? 1 : ((x < 0) ? -1 : 1))


#define ItemList_REIN_PLACE          1
#define ItemList_REIN_POS_DRAW       2
#define ItemList_REIN_BARSET         3
#define ItemList_REIN_MODIFY         4
#define ItemList_REIN_NOTE           5
#define ItemList_REIN_BAROVER        7
#define ItemList_REIN_BARMOVE        8




#define REIN_TVTYPE_END						1 
#define REIN_TVTYPE_SKT						2 
#define REIN_TVTYPE_V_O						3 
#define REIN_TVTYPE_V_X						4 
#define REIN_TVTYPE_INT						5 

//
#define REIN_TERM_NONE						0 
#define REIN_TERM_BEND						1 
#define REIN_TERM_REZB						2 
#define REIN_TERM_MUFT						3 
#define REIN_TERM_SKOB						4 
#define REIN_TERM_SVAR						10 
#define REIN_TERM_PLAT						12
// добавка для значков в списке
#define REIN_TERM_TRMV						5  // засечка
#define REIN_TERM_TRMX						6  // крстик
#define REIN_TERM_TRMO						7  // нолик
#define REIN_TERM_TRMS						8  // сечение (исп.?)
#define REIN_TERM_SAVE						9  // (исп.?)
#define REIN_TERM_TRMI						11 // обрезан клипом
//

#define REIN_LISTB_EXST						0 
#define REIN_LISTB_POSN						1 
#define REIN_LISTB_EXCL						2 
#define REIN_LISTB_SHOW						3 
#define REIN_LISTB_TRMV						4 
#define REIN_LISTB_TRMX						5 
#define REIN_LISTB_TRMO						6 
#define REIN_LISTB_TRMS						7 
#define REIN_LISTB_DIAM						8 
#define REIN_LISTB_TRM0						9 
#define REIN_LISTB_TRM1						10 
#define REIN_LISTB_RUNM						11 
#define REIN_LISTB_VARL						12 
#define REIN_LISTB_RADI						13 
#define REIN_LISTB_LENG						14 
#define REIN_LISTB_SORT						15 
#define REIN_LISTB_QTYP						16 
#define REIN_LISTB_QTYR						17 
#define REIN_LISTB_LAPA						18 // количество нахлестов на позицию
#define REIN_LISTB_MUFT						19 // количество муфт на позицию
#define REIN_LISTB_SAVE						20 
#define REIN_LISTB_AROW						21 // array row
#define REIN_LISTB_NONE						22 

#define REIN_TRANSP_OUT						21 
#define REIN_TRANSP_INN						22 

#define REIN_PLOT_SPC			1
#define REIN_PLOT_SPC_ELM		2
#define REIN_PLOT_SPC_INNER		14
#define REIN_PLOT_BAR			3
#define REIN_PLOT_BAR_ELM		4
#define REIN_PLOT_TERM_BEND		5
#define REIN_PLOT_TERM_REZB		6
#define REIN_PLOT_TERM_MUFT		7
#define REIN_PLOT_TERM_SKOB		8
#define REIN_PLOT_TERM_SVAR		15
#define REIN_PLOT_AUX_X			9
#define REIN_PLOT_AUX_O			10
#define REIN_PLOT_AUX_V			11
#define REIN_PLOT_ELMSEC		12
#define REIN_PLOT_BAR3D			13
#define REIN_PLOT_POSNUM		16
#define REIN_PLOT_BAR_INVIS		17

//option[13], riropt[]
#define DISP_V			0 // using .ends
#define DISP_X			14 // dropt[2]
#define DISP_O			13 // dropt[3]
#define DISP_S			11 // dropt[4]

#define DROPT_A			0 // dropt[0] // show/hide
#define DROPT_V			1 // dropt[1]
#define DROPT_X			2 // dropt[2]
#define DROPT_O			3 // dropt[3]
#define DROPT_S			4 // dropt[4]

#define BLOCK_NON		0
#define BLOCK_CMN		1
#define BLOCK_INN		2
#define BLOCK_BAR		4
#define BLOCK_EXC		8
#define BLOCK_GND		16
#define BLOCK_6		32 // not used
#define BLOCK_7		64 // not used
#define BLOCK_8		128 // not used

#define REINEL_FLAG_BEND		1
#define REINEL_FLAG_FKOS		2 // кривая стыковка на филлете между сегментами (iFilKos)
#define REINEL_FLAG_RBND		4 // real bend (iCfgVar_BendNewDraw == 2)
#define REINEL_FLAG_NMCH		8 // no match aecosim elements
#define REINEL_FLAG_CTCH		16 // catched position

#define REINBAR_FLAG_CONT		1 // новый способ определения номера контура
//#define REINBAR_FLAG_....		2
//#define REINBAR_FLAG_....		4
//#define REINBAR_FLAG_....		8

#define REIN_NOTE_STEP_P1				0
#define REIN_NOTE_STEP_P2				1
#define REIN_NOTE_STEP_NOTE1			2
#define REIN_NOTE_STEP_NOTE2			3
#define REIN_NOTE_STEP_NOTE_FINISH		4
#define REIN_NOTE_STEP_UPDATE			-1

#define REIN_POSLIST_MODE_ENUM				0
#define REIN_POSLIST_MODE_NUMSAVE			1
#define REIN_POSLIST_MODE_DBSAVE			2
#define REIN_POSLIST_MODE_CACHED			3
#define REIN_POSLIST_MODE_DYNAMIC			4


//typedef struct intopt
//{
//    int val;
//	int opt;
//} IntOpt;
//
//typedef struct doubleopt
//{
//    double val;
//	int opt;
//} DblOpt;

//typedef struct reinang
//{
//	DVec3d pt;
//	double ang;
//	int ok;
//} ReinAng;

#if defined (MSVERSION) && (MSVERSION == 0xa00)


#define CMD_0x0e0300 0x0e03000000000000UI64
#define CMD_0x010100 0x0101000000000000UI64
#define CMD_0x010200 0x0102000000000000UI64
#define CMD_0x050101 0x0501010000000000UI64
#define CMD_0x050102 0x0501020000000000UI64
#define CMD_0x0C0300 0x0C03000000000000UI64 // move


#else // v8i


#define CMD_0x0e0300 0x0e030000
#define CMD_0x010100 0x01010000
#define CMD_0x010200 0x01020000
#define CMD_0x050101 0x05010100 // surface by extrusion
#define CMD_0x050102 0x05010200 // surface by revolution
#define CMD_0x0C0300 0x0C030000 // move


#endif


#define IF_IT if (it != setstr.end())
#define IF_IT_end if (it == setstr.end())
#define IF_IT_nxt if (it != setstr.end()) ++it;
#define SETSTR_BEGIN_ITER deque<wstring>::iterator it = setstr.begin()






//TYPE = scalar
//KEY = 33
//COLUMN = 5
//PRI = Required Reinforcement
//SEC = Top X
#define LI_REQ_TOP_X    	    5

//TYPE = scalar
//KEY = 33
//COLUMN = 7
//PRI = Required Reinforcement
//SEC = Top Y
#define LI_REQ_TOP_Y    	    7

//TYPE = scalar
//KEY = 33
//COLUMN = 4
//PRI = Required Reinforcement
//SEC = Bottom X
#define LI_REQ_BOT_X    	    4

//TYPE = scalar
//KEY = 33
//COLUMN = 6
//PRI = Required Reinforcement
//SEC = Bottom Y
#define LI_REQ_BOT_Y    	    6

//TYPE = scalar
//KEY = 33
//COLUMN = 3
//PRI = Shell Shear Reinforcement
//SEC = Asw / S
#define LI_SHEAR_ASW    	    3

//TYPE = scalar
//KEY = 33
//COLUMN = 2
//PRI = Shell Shear Reinforcement
//SEC = Max step
#define LI_SHEAR_STP    	    2

//TYPE = scalar
//KEY = 33
//COLUMN = 8
//PRI = Min bar diameter
//SEC = Bottom X
#define LI_MIN_BOT_X    	    8

//TYPE = scalar
//KEY = 33
//COLUMN = 9
//PRI = Min bar diameter
//SEC = Top X
#define LI_MIN_TOP_X    	    9

//TYPE = scalar
//KEY = 33
//COLUMN = 10
//PRI = Min bar diameter
//SEC = Bottom Y
#define LI_MIN_BOT_Y    	    10

//TYPE = scalar
//KEY = 33
//COLUMN = 11
//PRI = Min bar diameter
//SEC = Top Y
#define LI_MIN_TOP_Y    	    11

/*
TYPE = scalar
KEY = 34
COLUMN = 5
PRI = Bar Reinforcement
SEC = As1

TYPE = scalar
KEY = 34
COLUMN = 4
PRI = Bar Reinforcement
SEC = As

TYPE = scalar
KEY = 34
COLUMN = 7
PRI = Bar Reinforcement
SEC = As1 dop

TYPE = scalar
KEY = 34
COLUMN = 6
PRI = Bar Reinforcement
SEC = As dop

TYPE = scalar
KEY = 34
COLUMN = 2
PRI = Bar Shear Reinforcement
SEC = Asw / S

TYPE = scalar
KEY = 34
COLUMN = 3
PRI = Bar Shear Reinforcement
SEC = Max step

TYPE = scalar
KEY = 34
COLUMN = 8
PRI = Min bar diameter
SEC = Bottom X

TYPE = scalar
KEY = 34
COLUMN = 9
PRI = Min bar diameter
SEC = Top X

TYPE = scalar
KEY = 34
COLUMN = 10
PRI = Min bar diameter
SEC = Bottom Y

TYPE = scalar
KEY = 34
COLUMN = 11
PRI = Min bar diameter
SEC = Top Y

TYPE = scalar
KEY = 34
COLUMN = 12
PRI = Bar Reinforcement
SEC = As summary 
*/




// IconCmd
#define ICONCMDID_space_place    	    1
#define ICONCMDID_space_modify   	    2
#define ICONCMDID_rein_linestring	    4
#define ICONCMDID_ismodel        	    7
#define ICONCMDID_ismodel2        	    21
#define ICONCMDID_rein_chlap			8
#define ICONCMDID_rein_ungrab        	9
#define ICONCMDID_rein_bar   		    10
#define ICONCMDID_rein_list      	    11
#define ICONCMDID_rein_anker      	    12
//#define ICONCMDID_rein_mirror       	14
#define ICONCMDID_rein_side       		18
#define ICONCMDID_rein_flags       		19
#define ICONCMDID_rein_note       		20
#define ICONCMDID_rein_note2       		22

// ToggleIcon
#define ICONCMDID_rein_iso       	    101
#define ICONCMDID_rein_3d        	    102
#define ICONCMDID_rein_ends       		103
#define ICONCMDID_rein_cont       		104
#define ICONCMDID_rein_vecs       		105
#define ICONCMDID_rein_nodes       	    106
#define ICONCMDID_rein_bars       	    107
#define ICONCMDID_rein_fcont       		108
//#define ICONCMDID_rein_fbars       	    109
#define ICONCMDID_rein_load       	    110
#define ICONCMDID_rein_snap       	    111
#define ICONCMDID_rein_bounds      	    112
//#define ICONCMDID_rein_refbars     	    113
#define ICONCMDID_rein_mufts     	    114
#define ICONCMDID_rein_secs     	    115
#define ICONCMDID_rein_rdsec     	    116
#define ICONCMDID_rein_bends     	    117
#define ICONCMDID_rein_transp     	    118
#define ICONCMDID_rein_aux_O       		119
#define ICONCMDID_rein_aux_X       		120
#define ICONCMDID_rein_posnum      		121
#define ICONCMDID_rein_trsec     	    122
#define ICONCMDID_rein_invis     	    123
#define ICONCMDID_rein_color     	    124
#define ICONCMDID_rein_aux_I       		125
#define ICONCMDID_rein_thread     	    126
#define ICONCMDID_rein_secprp     	    127
#define ICONCMDID_rein_ground      		128


#define BAR_JOINT_DEF       	    0
#define BAR_JOINT_LAP       	    1
#define BAR_JOINT_RING       	    2
#define BAR_JOINT_POOL       	    3

#define TXT_ICSM_REIN_LIST            	    "rein_list"
#define TXT_ICLG_REIN_CHLAP            	    "rein_chlap"
#define TXT_ICSM_REIN_VECS            	    "rein_vecs"
#define TXT_ICSM_SPACE_PLACE          	    "space_place"
#define TXT_ICLG_REIN_MIRROR          	    "rein_mirror"
#define TXT_ICSM_REIN_UNGRAB          	    "rein_ungrab"
#define TXT_ICLG_TOOLTIP              	    "tooltip"
#define TXT_ICSM_REIN_CONT            	    "rein_cont"
#define TXT_ICSM_REIN_CHLAP            	    "rein_chlap"
#define TXT_ICLG_REIN_LIST            	    "rein_list"
#define TXT_ICSM_REIN_SIDE            	    "rein_side"
#define TXT_ICSM_TOOLTIP              	    "tooltip"
#define TXT_ICLG_SPACE_PLACE          	    "space_place"
#define TXT_ICLG_REIN_UNGRAB          	    "rein_ungrab"
#define TXT_ICSM_REIN_ENDS            	    "rein_ends"
#define TXT_ICSM_REIN_MIRROR          	    "rein_mirror"
#define TXT_ICLG_REIN_ISO             	    "rein_iso"
#define TXT_ICLG_REIN_ANKER           	    "rein_anker"
#define TXT_ICLG_REIN_NODES           	    "rein_nodes"
#define TXT_ICLG_REIN_BAR             	    "rein_bar"
#define TXT_ICLG_REIN_FLAGS           	    "rein_flags"
#define TXT_ICSM_REIN_LINESTRING      	    "rein_linestring"
#define TXT_ICSM_SPACE_MODIFY         	    "space_modify"
#define TXT_ICSM_REIN_ANKER           	    "rein_anker"
#define TXT_ICSM_REIN_NODES           	    "rein_nodes"
#define TXT_ICSM_REIN_BAR             	    "rein_bar"
#define TXT_ICSM_REIN_ISO             	    "rein_iso"
#define TXT_ICLG_SPACE_MODIFY         	    "space_modify"
#define TXT_ICLG_REIN_LINESTRING      	    "rein_linestring"
#define TXT_ICSM_REIN_FLAGS           	    "rein_flags"
#define TXT_ICLG_REIN_3D              	    "rein_3d"
#define TXT_ICSM_REIN_3D              	    "rein_3d"
#define TXT_ICLG_REIN_NOTE            	    "rein_note"
#define TXT_ICSM_REIN_NOTE            	    "rein_note"

#define HOOKID_DIALOG						1
#define HOOKID_TOGGLE_DRAW					2
//#define HOOKID_BARIALOG						3
#define HOOKID_LISTBOX						4
#define HOOKID_LISTCELL						5
#define HOOKID_BARSEGM						0 // NOT USING
#define HOOKID_ANKER_VAL					7
#define HOOKID_ANKER_BTN					8
#define HOOKID_ANKERDIALOG					9
#define HOOKID_LICENSE				10
#define HOOKID_OPTION_TERM					11
#define HOOKID_SHOWOPTIONS					12
#define HOOKID_POSITION						13
#define HOOKID_REFCOMBO						14
#define HOOKID_TOOLBOX						15
#define HOOKID_LINSTCOMBO					16
#define HOOKID_OPTION_PREF					17
#define HOOKID_OPTION_DIAM					18
#define HOOKID_NOTECOMBO					19
#define HOOKID_LEVELCOMBO					20
#define HOOKID_SHOWREFCOMBO					21
//#define HOOKID_Combo_Model					19


#define DLG_LICENSE						50
#define DIALOG_TOOLBOX					2
#define DLG_POSLIST						4
#define DLG_PRESENT						6
#define DLG_SKETCH						7
#define DLG_BARENDS						8

#define TEXTID_BarsForChange				21
#define TEXTID_Space						100
#define TEXTID_BarOverMoveX					301
#define TEXTID_BarOverMoveY					302
#define TEXTID_BarOverMoveZ					303
#define TOGGLEID_PrmEnd				18
#define TOGGLEID_BarOverMoveX				301
#define TOGGLEID_BarOverMoveY				302
#define TOGGLEID_BarOverMoveZ				303
#define TOGGLEID_BarOverGround				304
//#define TOGGLEID_LockGraphicGroup			305 // already defined

#define ITEMID_TERMBEG						516
#define ITEMID_TERMEND						518

#define TOGGLEID_ShowGround					58

#define TEXTID_NoteUp						401
#define TEXTID_NoteDn						402

#define COMBOBOX_NoteUpFmt					411
#define COMBOBOX_NoteDnFmt					412
#define COMBOBOX_NoteLevels					413

#define OPTIONBUTTONID_BarOver				97
#define OPTIONBUTTONID_NoteStyle			401
#define OPTIONBUTTONID_LineStyles			1001
#define OPTIONBUTTONID_PresOpt				96

#define TOGGLE_NoteDim						401
#define TOGGLE_NoteBarSet					402
#define TOGGLE_NoteUpFmt						403
#define TOGGLE_NoteDnFmt						404
#define TOGGLE_RepairBend						500

//#define CMN_Diameter						2
//#define CMN_RunMet						10
//#define CMN_BendRad						15
//#define CMN_LapBeg						71
//#define CMN_LapEnd						72
//#define CMN_LapEvn						73

#define MAX_REF_SLOT						500
//#define MAX_REF_ALL							1000
#define MAX_UPD_HIDE_ELEMS					10000
#define MAX_UPD_ELEMS						1000000
#define MAX_FP_ELEMS						10000000
#define MAX_POS_NUMS						2000

#define LISTBOX_POSITIONS	1
#define COMBOBOX_POSITIONS_REFS	1
#define COMBOBOX_MODEL	2
#define COMBOBOX_SHOWPREF_REFS	3
#define STRLIST_MODEL	2
#define BUTTON_POSLIST	3
#define BUTTON_DBSAVE	4
#define BUTTON_POSDRAW	5
#define BUTTON_AGREE	7

#define DLGITEM_TEXT_SPACE		3
//#define DLGITEM_TEXT_SPACE_2	309

#define MODTYPE_NONE						0
#define MODTYPE_COMMON						1
#define MODTYPE_CAGE						2
#define MODTYPE_ASSEMBLY					10

#define BAROVER_ACTION_MOVE					0
#define BAROVER_ACTION_RESET				1
#define BAROVER_ACTION_DELETE				2
//#define BAROVER_ACTION_GROUND				3 // заземление

#define BARSET_GAP				10

//#define FILEPOS_LOC						4000000

//#define REIN_TEST

#endif 

