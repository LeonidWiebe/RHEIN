#include "StdAfx.h"
#include "vers.h"

#if defined (MSVERSION) && (MSVERSION == 0xa00) // INCLUDE


//#include <string.h>
//#include <windows.h>

#include <unordered_map>


#include <DgnPlatform\DgnPlatformAPI.h>
#include <Mstn/MdlApi/MdlApi.h>

#include <Bentley/BeStringUtilities.h>
#include <DgnPlatform/DgnECManager.h>

#include    <Mstn/MdlApi/mdl.h>

USING_NAMESPACE_BENTLEY
USING_NAMESPACE_BENTLEY_DGNPLATFORM
USING_NAMESPACE_BENTLEY_MSTNPLATFORM
USING_NAMESPACE_BENTLEY_MSTNPLATFORM_ELEMENT

#include <Mstn/MdlApi/msrmgr.h>
#include <DgnPlatform/Tcb/tcb.r.h>    
#include <DgnView/DgnElementSetTool.h>
#include    <Bentley/BeFileName.h>
#include    <Mstn/MdlApi/mssystem.fdf>
#include    <Mstn/MdlApi/msselect.fdf>
#include    <Mstn/MdlApi/msstate.fdf>
#include    <Mstn/MdlApi/msmisc.fdf>
#include    <Mstn/MdlApi/msinput.fdf>
#include    <Mstn/PSolid/mssolid.h>
#include    <Mstn/PSolid/mssolid.fdf>
#include    <Mstn/MdlApi/mscnv.fdf>
#include    <Mstn/MdlApi/mscurrtr.fdf>
#include    <Mstn/MdlApi/mstmatrx.fdf>
#include    <Mstn/MdlApi/msrmatrx.fdf>
#include    <Mstn/MdlApi/mselmdsc.fdf>
#include    <Mstn/MdlApi/mselemen.fdf>
#include    <Mstn/MdlApi/msparse.fdf>
#include    <Mstn/MdlApi/mscell.fdf>
#include    <Mstn/MdlApi/msoutput.fdf>
#include    <Mstn/MdlApi/msacs.fdf>
#include    <Mstn/MdlApi/msvba.fdf>
#include    <Mstn/MdlApi/elementref.h>
#include    <Mstn/MdlApi/msdialog.fdf>
#include    <Mstn/MdlApi/msreffil.fdf>
#include    <Mstn/MdlApi/msfile.fdf>
#include    <Mstn/MdlApi/mdllib.fdf>
#include    <Mstn/MdlApi/msview.fdf>
#include    <Mstn/MdlApi/mdlerrs.r.h>
#include    <Mstn/MdlApi/msmodel.fdf>
#include    <Mstn/MdlApi/mstrnsnt.fdf>

#include    <Mstn/Tools/mstxtfil.h>

//#include    <DgnPlatform/DgnPlatform.r.h>
#include    <DgnPlatform/xmlfragment.h>
#include    <DgnPlatform/DisplayStyleManager.h>

#include    <Mstn/MdlApi/mdlxmltoolslink.fdf>

#include    <Mstn/MdlApi/msscancrit.fdf>
#include    <Mstn/MdlApi/mdlxml.fdf>
#include    <Mstn/MdlApi/mscexpr.fdf>
#include    <Mstn/MdlApi/ditemlib.fdf>
#include    <Mstn/MdlApi/msritem.fdf>
#include    <Mstn/MdlApi/mslocate.fdf>
#include    <Mstn/MdlApi/msundo.fdf>
#include    <Mstn/MdlApi/msdgnmodelref.fdf>
//#include    <Mstn/MdlApi/msdarray.fdf>
#include    <Mstn/MdlApi/mswindow.fdf>
#include    <Mstn/MdlApi/msvec.fdf>
//#include    <Mstn/MdlApi/msdgncache.fdf>
#include    <Mstn/MdlApi/msstring.fdf>
#include    <Mstn/MdlApi/leveltable.fdf>
#include    <Mstn/MdlApi/msbsplin.fdf>
#include    <Mstn/MdlApi/changetrack.fdf>
#include    <Mstn/MdlApi/listmodel.fdf>
#include    <Mstn/MdlApi/msimage.fdf>
#include    <Mstn/MdlApi/msmdlmesh.fdf>
#include    <Mstn/MdlApi/msbitmask.fdf>
#include    <Mstn/MdlApi/dlogman.fdf>
#include    <Mstn/MdlApi/dlogids.r.h>
#include    <Mstn/MdlApi/msassoc.fdf>
#include    <Mstn/MdlApi/rdbmslib.fdf>
#include    <Mstn/MdlApi/dlmsys.fdf>

#include    <Mstn/MdlApi/msbrepcommon.r.h>

#include <Mstn\MdlApi\SettingsActivator.h>

#include    <Mstn\MdlApi\deprecated10_0.fdf>

#include <PSolid/PSolidCoreAPI.h>

#include <Mstn/ISessionMgr.h>

#include    <Mstn/MdlApi/msdisplaypath.h>

#include <Mstn/cmdlist.r.h>
#include <DgnView/AccuDraw.h>

#include    <Mstn/MdlApi/msrsrc.fdf>
#include    <Mstn/MdlApi/msscan.fdf>


EditElementHandle eeh;

DSegment3d       locSegmVector;


#elif defined (MSVERSION) && (MSVERSION == 0x8b0)

#include <MicroStationAPI.h>
#include <DisplayStyleManager.h>
#include <Interface/ISessionMgr.h>

#include <symboldef.h> 
#include <Interface/inamedview.h> 
#include <Interface/element/ViewElementHandlerSubTypes.h> 

#include    <mdl.h>
#include    <mssystem.fdf>
#include    <msselect.fdf>
#include    <msstate.fdf>
#include    <msmisc.fdf>
#include    <msinput.fdf>
#include    <mskisolid.fdf>
#include    <mscnv.fdf>
#include    <mscurrtr.fdf>
#include    <mstmatrx.fdf>
#include    <msrmatrx.fdf>
#include    <mselmdsc.fdf>
#include    <mselemen.fdf>
#include    <msparse.fdf>
#include    <mscell.fdf>
#include    <msoutput.fdf>
#include    <msacs.fdf>
#include    <msvba.fdf>
#include    <elementref.h>
#include    <msdialog.fdf>
#include    <msreffil.fdf>
#include    <msfile.fdf>
#include    <mdllib.fdf>
#include    <msview.fdf>
#include    <math.h>
#include    <mdlerrs.h>
#include    <msmodel.fdf>
#include    <mstrnsnt.fdf>
#include    <mdlxmltoolslink.fdf>
#include    <msscancrit.fdf>
#include    <mdlxml.fdf>
#include    <mscexpr.fdf>
#include    <ditemlib.fdf>
#include    <msritem.fdf>
#include    <mslocate.fdf>
#include    <msundo.fdf>
#include    <msdgnmodelref.fdf>
#include    <msdarray.fdf>
#include    <mswindow.fdf>
#include    <msvec.fdf>
#include    <msdgncache.fdf>
#include    <msstring.fdf>
#include    <leveltable.fdf>
#include    <msbsplin.fdf>
#include    <changetrack.fdf>
#include    <listmodel.fdf>
#include    <msimage.fdf>
#include    <msmdlmesh.fdf>
#include    <bitmask.fdf>
#include    <dlogman.fdf>
#include    <dlogids.h>
#include    <msassoc.fdf>
#include    <rdbmslib.fdf>
#include    <dlmsys.fdf>
#include    <msnamedgroup.fdf>
#include    <msdependency.fdf>

#include    <FontManager.h>

#include    <msdisplaypath.h>

#include    <cmdlist.h>
#include    <accudraw.h>

#include    <msrsrc.fdf>
#include    <msscan.fdf>


//#include	"ViewTrans.h"
//#include    "ViewMonitor.h"


#if !defined (mdl)
extern "C"
{
	//	Alias for ustnTaskId if compiling native code C or C++
	//	Link with mdlbltin.lib
	extern char* ustnTaskIdP;
}	//	extern C
#endif

#include    <deprecated8_9.fdf>

DVector3d       locSegmVector;

#endif

using namespace std;



#include "rein.h"
#include "reinsgn.h"
#include "reinbar.h"
#include "reinelem.h"


time_t tloc[3] = { 0,0,0 };

//==================================
//==================================
int iModelVers = 4; // MODEL VERSION
int iModelVersInFile = 3; // MODEL VERSION
//==================================
//==================================
int bModelOutOfDate = FALSE;
int bModelCheckRefs = FALSE;

int bUseDB = 0;

UInt32 curggn = 0;

int bRef = 0;

//Transform tmFromRef;
//RotMatrix rmFromRef;

ReinElement* reFoundP = NULL;
ReinBar* rbFoundP = NULL;

vector<long> arPos(10);
vector<long> arPosCount(10); // количество стержней на контуре
long iPosCount;

vector<vector<long>> arPosQty(10); // arPosQty[10][4]

//ReinPos* curPosP = NULL;
char sArCurPosPtsC[500];
char sArCurPosPtsA[500];
UInt32 curPos_rn = 0; // номер слота референса
wstring curPos_refpath = L"0"; // путь из слотов референсов
long curPos_ind = 0; // текущий индекс в arCurPos
//int curPos_rnn = 0; // номер слота вложенного референса
int ipnsave = 0;
WCH sCurPos[5000];
//MSWCH wsCurPos[5000];

//WCH sCurRef[500];

CatInfo curCat;

ReinElm reCopyFrom;
Transform tmCopySrc;
Transform tmCopyDst;

ReinElm* reNoteP[2];
//DVec3d curNote.arNotePts[4];
ReinNote curNote;

int iModePosCatch = 0;

int iModelType = MODTYPE_NONE; // was bIsModel
//char sModelType[10];
//long iOfftCatID = 0;
//long iOfftProjID = 0;
//long iLapMaxLen = 11700; // mm

DVec3d pts[MAX_VERTICES];
DVec3d ptsBar[MAX_BAR_VERTICES];
DVec3d ptsUnRotCompare[MAX_BAR_VERTICES];
DVec3d ptsUnRotForDraw[MAX_BAR_VERTICES];
long ptsFlag[MAX_BAR_VERTICES];

//RotMatrix arViewRM[8];
ReinView arViewPlanes[8];
//double arViewDepth[8] = { 0.,0.,0.,0.,0.,0.,0.,0. };
//DVec3d arViewDelta[8];

int BRYS = FALSE;

TransDescrP arTransNodes = NULL;
TransDescrP arTransMufts = NULL;

short	ats[MAX_ATTRIBSIZE];
int		atlen;

int optmir[3] = { 1,1,0 };

int hTimer = 0;
UInt32 iDblClickFP = 0;

//MSElementUnion arViewShapes[8];

ELID elidDisplayCopy = 0;
ELID elidReinBar = 0;

int iSketchScale[2];
UInt32 iSketchBarWeight = 2;
UInt32 iSketchTxtWeight = 1;

int	timerHandle;

//UInt32    arFP[MAX_UPD_ELEMS];
//ELID arID[MAX_UPD_ELEMS];
ELID arElemID[MAX_BAR_VERTICES];

//UInt32 iFPcount;
//UInt32 iIDcount;
UInt32 iElemIDcount;

int iNewRefNum = FALSE;

//UInt32    arHideFP[MAX_UPD_HIDE_ELEMS][MAX_REF_SLOT];
//UInt32	  arHideFPcount[MAX_REF_SLOT];

int shift[2] = { -1,-1 };

RscFileHandle   rfHandle = NULL;

ReinModel curRMod;

int updevents[100];

deque<STRING> possort;

//============================================
//ReinModel curRMod;
ReinModel* curRM = &curRMod;
//============================================
ReinAxis raxis;
ReinElm arelm;
ReinElm crelm;
ReinElm drelm;
ReinElm urelm;
DVec3d ptsCalc[MAX_BAR_VERTICES];
DVec3d calcTrPts[MAX_BAR_VERTICES];
DVec3d calcPts[MAX_BAR_VERTICES];
DVec3d calcPtsX[MAX_BAR_VERTICES];
DVec3d calcCPts[MAX_BAR_VERTICES];
DVec3d calcCPta[MAX_BAR_VERTICES];
long calcRfa[MAX_BAR_VERTICES];
int calcF[MAX_BAR_VERTICES]; // флаги для переменных сегментов, 1 - гориз., 2 - верт.
DVec3d ptstmp[MAX_BAR_VERTICES];
//ReinSpace rrs;
ReinElement rrelem;
ReinBar rrb;
DVec3d arPtsX[MAX_BAR_VERTICES];
DVec3d arPtsO[MAX_BAR_VERTICES];
double arDepthX[MAX_BAR_VERTICES];
double arDepthO[MAX_BAR_VERTICES];
MSBsplineCurve crv;
MSBsplineCurve dcrv[2];
//============================================

//UInt32   arCurUpdateFP[MAX_UPD_ELEMS];
//DgnModelRefP   arCurUpdateMR[MAX_UPD_ELEMS];
UInt32   iCurUpdateCount = 0;

UInt32 iBarEndsCount = 0;
UInt32 iBarCapsCount = 0;

ReinInfo	 rInfo;
MSWCH strReinInfo[10010];

//ReinInfo	 rInfoPref;
ReinInfo	 rInfoFile;

ReinDopInfo	 rDopInfo;
MSWCH strReinDopInfo[10010];

ReinDopInfo	 rDopInfoPref;

ReinDopInfo	 rBarOverInfo;
MSWCH strBarOverInfo[10010];

ReinBar      rBarInfo;

ReinInfoRef rInfoRef;



double dCfgVar_CoverEdge;
double dCfgVar_CoverFace;
double dCfgVar_BarFace; // from REIN_BAR_FACE
//double dCfgVar_BarSign;
double dCfgVar_PosNumSize;
double dCfgVar_BarViewScale;
double dCfgVar_BarMaxLength;
double dCfgVar_BarSecScale;

double dCfgVar_SketchHgt;
double dCfgVar_SketchWdtNum;
double dCfgVar_SketchWdtDrw;
double dCfgVar_SketchGap;

int iCfgVar_PosCalc_Groups = 1; // учитывать именованые группы при группировке позиций
int iCfgVar_PosCalc_Laps = 1; // учитывать четность разбежки при группировке позиций
int iCfgVar_BarBendTypeAuto = 0; // тип линии контура автоматически
int iCfgVar_BarCompare_3d = FALSE; // трехмерное сравнение позиций
int iCfgVar_NullFillet = TRUE; // нулеовй филлет
int iCfgVar_BendNewDraw = 0; // 1 - новая отрисовка загиба, 2 - честный загиб
int iCfgVar_UseGhostContour = 1; // 
int iCfgVar_SpaceHoldLine = FALSE; // держать шаг стержней при косом вытягивании поверхности
int iCfgVar_SortPlus = FALSE; // sort by parameters
int iCfgVar_SectionPoints = FALSE; // make transient section points
int iCfgVar_ProjectID_Override = 0; // override projectID for srtmID and matID when poslist db save

int iCfgVar_Class_Elm = 0;
int iCfgVar_Class_Spc = 0;
int iCfgVar_Class_Bar = 0;

int iCfgVar_SymbStyle_Spc = 3;
int iCfgVar_SymbWeight_Elm = 2;
int iCfgVar_SymbColor_Elm = -1;

int iCfgVar_CbUpdateElement = 1;

int iCfgVar_PosListMerge = 0; // общий лист позиций если catID для ReinModel одинаковый
int iRefLvl = 0;

extern int iCfgVar_Transp_Elm_Out = -1;
int iCfgVar_Transp_Elm_Inn = -1;

double dCfgVar_FilletRadiusKoef; // если отрицательный, использовать fillets[diam].radius
double dCfgVar_FilletRadiusKoefDef;
int iCfgVar_FilletStartingDiam;
double dCfgVar_BarBendLengthRoundSnap; // снап округления длины дуги загиба стержня 
double dCfgVar_BarLineLengthRoundSnap; // снап округления длины стержня 
double dCfgVar_MuftWdtKoef = 0.75;
double dCfgVar_MuftHgtKoef = 1.5;


//int iCfgVar_DiamRifDelta; 

int iCfgVar_ComparisonTol = 5; // для сравнения позиций
int iCfgVar_MuftTol = 10; // расстояние между стержнями при определении переходных муфт

int iCfgVar_MinSegment = 10; // минимальная длина сегмента (если меньше - точка удаляется)

int iCfgVar_MuftLapType = 1; // тип муфты которая ставится на стыке стержней когда длина позиции больше 11700
int iCfgVar_NewMuftDraw = FALSE; // муфта и резьба рисуется как муфта со сдвигом - так чтобы центр прямоугольника оказался на конце стержня
int iCfgVar_MuftTypeEnabled[3] = { 1,1,1 }; // тип муфты вкл/выкл

vector<int> arPlotCfgVar(50); // значения: 1 - печатать, 0 - по общ. настройкам, -1 - не печатать

//int iCfgVar_ViewCacheMode = 1; // REIN_VIEW_CACHE_MODE
//int iCfgVar_ViewCacheWorkShow = 1; // REIN_VIEW_CACHE_SHOW

int iCfgVar_EnableOptions = 0;

int iCfgVar_CheckDups = 1;

int iCfgVar_Clash_Mode = 2;
//#0 - не проверять,
//#1 - проверять всегда,
//#2 - проверять только при манипуляции с элементами(не проверять при загрузке файла)

int iCfgVar_Clash_Tol = 5; // tolerance

char sCfgVar_PicAnker[1000];
char sCfgVar_LoadsNodes[300];
char sCfgVar_LoadsValues[300];

double dLoadNodeSpacing = 1000.; // mm

int iCfgVar_Ground_Clr = -1;
int iCfgVar_Ground_Wgt = -1;

int iCfgVar_BarBendRepair = 0;
int iCfgVar_BarBendNotchDiam = 20;

//double dDupTol = 5.;
double dDupTol = 50.; // mm (сначала было 5., изменено на 50. для коллизий)

int	     nSearchTypes;
int	     searchType[10];

UShort appID = (UShort)18792; // 22875 for spbaep, max 65535

//UShort appTypeReinSpace =	(UShort)879345;
//UShort appTypeReinBar =		(UShort)879343;
//UShort appTypeOrgPoints =	(UShort)879341;
//UShort appTypeEndPoints =	(UShort)879342;
//UShort appTypeReinElm =		(UShort)879344;
//UShort appTypeBarPoints =	(UShort)879347;
//UShort appTypeBarVerts =	(UShort)879350;
//UShort appTypeIsModel =		(UShort)879348; // версия
//UShort appTypeTrans =		(UShort)879349;

UShort appTypeReinSpace = 27377;
UShort appTypeReinBar = 27375;
UShort appTypeOrgPoints = 27373;
UShort appTypeEndPoints = 27374;
UShort appTypeReinElm = 27376;
UShort appTypeBarPoints = 27379;
UShort appTypeBarVerts = 27382;
UShort appTypeIsModel = 27380;
UShort appTypeReinCache = 27383;
UShort appTypeReinAssem = 27381;
UShort appTypeBarOver = 27384;
UShort appTypeReinNote = 27385;

UShort appTypeCatInfo = (UShort)8793;
UShort appTypeReinAxis = (UShort)8794;
UShort appTypeHidePos = (UShort)8795; // [refnum]
UShort appTypeBarSet = (UShort)8796; // [refnum]
UShort appTypeReinPos = (UShort)8798; // сохра позиции в файле
UShort appTypeSegment = (UShort)8799; // запись параметров сегмента на REINELEM
UShort appTypeReinData = (UShort)8800; // данные REINLINE
//UShort appTypeReinLine =	(UShort)8801; // линия определяющая точки позиций
UShort appTypeShowInfo = (UShort)8802; // [refnum] сохранение настроек отображения

UShort appTypeRndResult = (UShort)202; // настройка для элементов арматуры, получаемой в программе разверток

//ArrayObjectHdr* daCurBars = NULL; // массив элементов референсов с точками, учитывающими clip boundary
// сделан исключительно потому что функции mdlClip_... в хуке callbackUpdateElement() вызывают сброс трансформа и клипа
// побороть не получилось, поэтому создаем массив точек обрезанных элементов заранее
//UInt32 iCurBarsCount = 0;

RscFileHandle   rfRein = NULL;

vector<LoadNode> daCurLoadNodes;
vector<LoadVert> daCurLoadVerts;
//vector<ReinPos> daCurBarSet;
vector<ReinExcl> daCurPosExcl; // исп. только для сохранения галок при перегрузке списка
vector<ReinPos> daCurPosHide;
vector<ReinLap> daBaseLaps;
vector<ReinVert> daMufts;
vector<SpecLine> daDrawLines;
vector<SpecText> daDrawTexts;

map <wstring, ReinPos> mapBarSet;
map <STRING, ReinPrm> mapSimPos;

MSWCH sset[10000];
deque<wstring> setstr;

map <UInt32, CatInfo> mapCats;

//vector<SpecText> daDrawCells;
//ArrayObjectHdr* daDrawCells = NULL;

//ArrayObjectHdr* daCurPosBase = NULL;
//ArrayObjectHdr* daCurPosAll = NULL;

CatInfo catPosXml;

//BINT bPosSepByRefs = FALSE;

//vector<ReinBar> vCurBars;

//DVec3d* arLoadVerts = NULL;

BINT bLoadsOk = FALSE; // параметры расчета загружены нормально или нет

// параметры для отрисовки спецификации
double dTextRightX = 0.;

DVec3d pZero; // zero
DVec3d pZ; // 0 0 1

RotMatrix rmIdent;
RotMatrix rmIso;

ScanCriteria* pIterScanCrit = NULL; // для iterateReloadBarsData()

MSElementDescr* edpRot = NULL; // элемент, получаемы при LOCATE, в котором убран поворот и смещение
MSElementDescr* edpShapeForPoints = NULL;

DgnModelRefP mrPlot = NULL;


long muftqtyext[50][50][10]; // количество переменных муфт для каждого диаметра и типа
long skobqtyext[50][50]; // количество скоб 
long skobqtydop[50][50]; // количество вкладок для скоб  

//DVec3d arDataLinePts[1000][MAX_BAR_VERTICES];
//int arDataLinePtsQty[1000];

ReinBar arDataBars[1000]; // производные стержни линейного контура
//vector<ReinBar>arDataBars(500); // производные элементы

ReinBar arDataPreps[MAX_BAR_VERTICES]; // образующие элементы линейного контура
//vector<ReinBar>arDataPreps(MAX_BAR_VERTICES); // предварительно считываемые образующие элементы

//ReinBar arDataCopy[MAX_BAR_VERTICES];

int arDataNums[MAX_BAR_VERTICES]; // количество точек на образующем элементе, через которые проходят пересекающие его производные элементы
//vector<int>arDataNums(MAX_BAR_VERTICES);

LoadVert arDataSpaces[MAX_BAR_VERTICES]; // шаг для образующего элемента, так как он может отличаться в случае переллельного построения (BT_PAR)
//vector<double>arDataSpaces(MAX_BAR_VERTICES);

int iDataCopyCount = 0; // количество предварительно выделенных
ELID dataCopyNewElemID = 0;

int iBarTypeAuto = 0;

int bFlag = FALSE;

int ilev = 0; // level for log

int ankers[5][11] =
{
	{64, 48, 40, 34, 31, 28, 26, 24, 22, 21, 20},
	{48, 36, 30, 26, 23, 21, 19, 18, 17, 16, 15},
	{63, 47, 39, 34, 31, 27, 25, 24, 22, 21, 20},
	{78, 58, 48, 41, 38, 33, 31, 29, 27, 26, 24},
	{93, 69, 58, 49, 45, 40, 37, 35, 32, 31, 29}
};


ReinSpace rsMon;     //for callbackElementUpdating{}
//ReinCalc rcMon;      //for callbackElementUpdating{}

TrackBarInfo tbi;
UInt32 elemCount;
UInt32 elemCount2;
UInt32 elemCount3;
UInt32 elemCount4;
UInt32 elemIterCount;
UInt32 elemIterCount2;
UInt32 elemIterCount3;
UInt32 elemIterCount4;
ReinVert rvMuftScan[2];

UInt32 iDataElemCount = 0; // arDataPreps.size()
UInt32 iDataBarsCount = 0; // arDataBars.size()


UInt32 posCount;
UInt32 enumCount = 0;

//TextSizeParam txtSize   = { TXT_BY_TILE_SIZE, { 100., 
//					150. }, 1.  };
//

//typedef struct textParam
//    {
//    UInt32	font;
//    int		just;
//    int		style;
//    int		viewIndependent;
//    } TextParam;

#if defined (MSVERSION) && (MSVERSION == 0xa00)
TextParamWide     txtParam[9];
//{	// инициализация в коде
//	{ 1025, TextElementJustification::LeftTop, 0, FALSE },
//	{ 1025, TextElementJustification::LeftMiddle, 0, FALSE },
//	{ 1025, TextElementJustification::LeftBaseline, 0, FALSE },
//	{ 1025, TextElementJustification::CenterTop, 0, FALSE },
//	{ 1025, TextElementJustification::CenterMiddle, 0, FALSE },
//	{ 1025, TextElementJustification::CenterBaseline, 0, FALSE },
//	{ 1025, TextElementJustification::RightTop, 0, FALSE },
//	{ 1025, TextElementJustification::RightMiddle, 0, FALSE },
//	{ 1025, TextElementJustification::RightBaseline, 0, FALSE }
//};
#else
TextParam     txtParam[9] =
{
{ 1025, TXTJUST_LT, 0, FALSE },
{ 1025, TXTJUST_LC, 0, FALSE },
{ 1025, TXTJUST_LB, 0, FALSE },
{ 1025, TXTJUST_CT, 0, FALSE },
{ 1025, TXTJUST_CC, 0, FALSE },
{ 1025, TXTJUST_CC, 0, FALSE },
{ 1025, TXTJUST_RT, 0, FALSE },
{ 1025, TXTJUST_RC, 0, FALSE },
{ 1025, TXTJUST_RB, 0, FALSE }
};
#endif





ReinFillet fillets[100];

int iSketchFilletRadius = 0;

int		iListColsNum = 23;


char tooltip[500];
int bTT = 0;

#if defined (MSVERSION) && (MSVERSION == 0xa00)
unsigned __int64 iAC = 0;
#else
int iAC = 0;
#endif
int iACStep = REIN_NOTE_STEP_P1;

DVec3d pInt; // intersection for note placing
DVec3d pBar; // bar point
DVec3d pExt[3][2]; // extension lines

DVec3d ptsLine[2];

DVec3d ptsShape[42];

UInt32 filePosRein = 0;
UInt32 filePosReinBar = 0;
UInt32 filePosReinSpace = 0;
UInt32 filePosReinSurf = 0;
UInt32 filePosReinFrom = 0;
//UInt32 filePosReinOver = 0;

BOOL bDropReinData = false;

int iReinBarSelectedQty = 0;

UInt32 filePosRSElementOffset = 0;
DgnModelRefP curElemModelRef;


MSElementDescr* edCopyP = NULL;
MSElementDescr* edBarCopyP = NULL;

int posNumMax = 0;

int       locVertexIndex;
int       locSegmIndex;

BINT bCopyFromRef = FALSE;


UInt32 lvlReinId = 0;
UInt32 lvlTextId = 0;

char sLineLens[200];
char sArcLens[200];

DPoint3d arLinPts[100];
long arLineLens[100];
long arLineRads[100];
double arLineAngs[100];
int arArcLens[100];
int iNumLens = 0;
int iNumTxtPts = 0;

WCH s[5000];
WCH ss[5000];
WCH sss[5000];
MSWCH wss[5000];
MSWCH wLog[5000];
//MSWCH wsread[5000];


UInt32 lvlSaveID = 0; // level for saveplot

bool bNoLoad = false;

//UInt32 fpmax = 0;

DVec3d arpg[1000]; // array points global
long arlg[1000]; // array long global

StatusInt gst = 0;

int iCfgVar_SavedViewClip = 1;
int iCfgVar_LoadRefsOnStart = 1;


ReinNoteSet curNoteSet;
MSWCH strCurNoteSet[10010];

//RscFileHandle   rfHandle = NULL;

int iSpaceDefault = 200; // шаг по умолчанию

int bSketchPoint = 0;
double dSketchPointX = 0.;
double dSketchPointY = 0.;
double dSketchPointZ = 0.;

int iEmpty = 0;

int iDebug = 0;

//#if defined (MSVERSION) && (MSVERSION == 0xa00)
ofstream fileLog;
//#else
//FILE* fileLog = NULL;
//#endif

WCH sFileLog[300];
char sLog[5000];
char sLogMes[5000];
char sLogMesOut[5000];


LEVID levClash = 0; // слой для элементов коллизий



//ReferenceFile refFile;


map<RelmPair, ReinPos> mapPosMem;

map<UInt32pair, ReinClash> mapClash; // д.б. парный ключ...
UInt32 iClashShtamp = 0; // идентификатор коллизии


TransDescrP tedBarsP = NULL;



MSElement c0w0s0;
MSElement c0w1s0;
MSElement c0w1s0_nofill;
MSElement c0w0s1;
MSElement c0w0s2;
MSElement c3w1s0;
MSElement c3w5s0;
MSElement c3w9s0;
MSElement c0w0s4;

MSElement el;
MSElement eCell;
MSElement elCl;
MSElement elAr[2];
MSElement elCr;
MSElement elTxt[2];
MSElement elExt[3];

MSElement elLine;
MSElement elMon;
MSElement elForTT;
MSElement elTmp;
MSElement elShape;
MSElement elBar[3];

MSElement elTest;
MSElement elLocate;


MSElement el1;
MSElement el2;
MSElement el3;

MSElement elSpec;



MSDLGP dlgProgressP = NULL;

bool bExportSolids = false;

vector<ReinPoint> gvpt;

ReinPos curPos;

//Transform tmRefGlob;
//Transform tmRevGlob;
DgnModelRefP mrRefPlotFromP = NULL;

