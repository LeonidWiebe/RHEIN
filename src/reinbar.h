

#ifndef _REINBAR_H_
#define _REINBAR_H_


/// <summary>
/// вектор верщины сегмента стержня
/// </summary>
typedef struct reinvertvec
{
	reinvertvec(void);

	void clear(void);

	DVec3d tdir;     // вектор
	DVec3d tnorm;    // нормаль (рисунка) ....................................
} ReinVertVec;

/// <summary>
/// верщина сегмента стержня
/// </summary>
typedef struct reinvert
{
	reinvert(void);

	void clear(void);

	ReinVertVec rvv;

	DgnModelRefP mrp; // чтобы при расчете муфт пропускал самого себя
	DVec3d torg; // координаты с учетом матрицы референса
	int isin; // внутренняя или внешняя точка
	int pmqty; // колиество попаданий стержней при расчете переходных муфт
	int mpar; // расчет муфт + параметр отображения RFA_...
	int mdiam[2]; // для сравнения муфт, два диаметра для переходных муфт
	UInt32 fps; // file pos чтобы при расчете муфт пропускал самого себя
	int mblap; // муфта получена автоматически при превышении длины позиции + параметр для сохранения доп. элементов в SAVEPLOT
	int errors;
	double dpth;
} ReinVert;

/// <summary>
/// сегмент стержня
/// </summary>
typedef struct reinsegm
{
	reinsegm(void);

	void clear(void);

	ReinVert rv[2];      // вершины
	int bOutOfClip;
	long sgmrad; // радиус сегмента
	DVec3d sgmcent;
	DVec3d sgmnorm;
	DVec3d numpt; // точка где рисовать номер позиции
	DVec3d numpt2; // точка где рисовать номер позиции дополнительно если перекрывается кружком сечения
	DVec3d pSec; // точка где рисовать сечение при SAVEPLOT
	int bSec; // отрисовывается сечение на сегменте
} ReinSegm;

/*
typedef struct _barpoint
{
	DVec3d pVrtx; // точка вершина
	DVec3d pVrtxNext; // точка след. от вершины
	DVec3d pDirX; // вектор из вершины вдоль сегмента стержня
	DVec3d pDirY; // вектор из вершины в сторону центра загиба
	DVec3d pDirZ; // вектор из вершины normal
	DVec3d pArcCent; // точка центр загиба
	DVec3d pArcPts[2]; // точки на дуге (45°, 90° | 135° | 180°)
	DVec3d pEndPoint; // точка окончания загиба
	DVec3d pElPoint; // сосдений пойманный элемент как маяк построения загиба
	int bend_ang; // termPar[0][0/1]
	int bend_len; // termPar[1][0/1]
	long flg;
	int nmb;
	int bnd;
} _BarPoint;
*/

/// <summary>
/// точка стержня
/// </summary>
typedef struct barpoint
{
	barpoint(void);
	void clear(void);
	void calcBend(int diam);
	//void setLegacy(_BarPoint* rdiP, bool bChangeSelf);
	DVec3d pVrtx; // точка вершина
	DVec3d pVrtxNext; // точка след. от вершины
	DVec3d pDirX; // вектор из вершины вдоль сегмента стержня
	DVec3d pDirY; // вектор из вершины в сторону центра загиба
	DVec3d pDirZ; // вектор из вершины normal
	DVec3d pArcCent; // точка центр загиба
	DVec3d pArcPts[2]; // точки на дуге (45°, 90° | 135° | 180°)
	DVec3d pEndPoint; // точка окончания загиба
	DVec3d pElPoint; // сосдений пойманный элемент как маяк построения загиба
	int bend_ang; // termPar[0][0/1]
	int bend_len; // termPar[1][0/1]
	long flg;
	int nmb;
	int bnd;
} BarPoint;


/// <summary>
/// линейный контур
/// </summary>
typedef struct reindata
{
	reindata(void);
	void clear(void);

	int dattype;
	int datdiam;
	int datrunmet;
	int datlap[3]; // beg, end, even
	int datbdrad; // bendrad - if 0 use fillet radius
	int dattrm[2]; // аналог term[2] ReinBar
	//vector<vector<int>> dattrmPar;
	int dattrmPar[10][2];
	int datposcalc;
	double datspacef;
	int datoffset[2];
} ReinData;


/// <summary>
/// стержень
/// </summary>
typedef struct reinbar
{
	reinbar(void);
	~reinbar(void);

	void clear(int memres = 0);
	void vecclear(bool bResize);
	void lenclear();

	// обработка массива gvpt
	void checkBarPoints(int bBends);

	// навесить на входящий элемент атрибут и добавить в файл
	XMLFragmentListP createReinBarXml();
	UInt32 createReinBarElement(MSElementDescr** edP, UInt32 fpos, DgnModelRefP mrP, int bAdd);


/// <summary>
/// создание стержня с целью сохранения в модели или перерасчета
/// </summary>
/// <param name="edP">
/// исходный элемент линия - ось для построения стержня,
/// bBarReady = FALSE - осевая линия, не может быть NULL, 
/// bBarReady = TRUE  - edP не используется и может быть NULL
/// </param>
/// <param name="bBarReady">FALSE - обнуление, чтение данных из edP и полный перерасчет, TRUE - перерасчет стержня, должны быть готовы rpts, rfa, numpts, bendrad стержня</param>
/// <param name="bAddElem">сохранять элемент в активную модель</param>
/// <param name="distP">дистанция смещения (NULL if no need)</param>
/// <param name="dirP">вектор смещения (NULL if no need)</param>
/// <param name="barnum">номер в контуре (0 if no need)</param>
/// <param name="barqty">количество стержней в контуре (0 if no need)</param>
/// <param name="lapbeg">разбежка в начале (0 if not exist)</param>
/// <param name="lapend">разбежка в конце (0 if not exist)</param>
/// <param name="bReinBar">только для команды DROP, default FALSE</param>
/// <returns></returns>
	int createBar(
		MSElementDescr* edP,	
		int bBarReady,	
		int bAddElem,	
		double* distP,	
		DVec3d* dirP,	
		int barnum,		
		int barqty,		
		int lapbeg,		
		int lapend,		
		int bReinBar = FALSE	
	);

	// создание и возвращение элемента в виде оси с загибами
	// должны быть готовы rpts, rfa, numpts, bendrad
	int createComplexBarAxisElem(
		// элемент (MSElementDescrP ...== NULL) на вход для возвращения
		// по звершении операций элемент должен быть освобожден (mdlElmdscr_freeAll())
		MSElementDescr** edPP,
		// шаблон элемента или NULL
		MSElement* elTemplateP = NULL	
	);

	// получение точек для отрисовки эскизов (apts)
	void getDrawPoints(
		DVec3d* pNormal,  // нормаль к плоскости стержня
		double* dScaleP
	);

	// получение точек сравнения
	void calcComparePoints(
		Transform* tmP, // для переменных сегментов - вертикальные или горизонтальные
		int bReverse,
		double* dScaleP
	);

	void fromReinData(ReinData* rdP);

	ELID saveReinData(ELID datelemid, void* v_relemP = NULL);

	void setReinDataString(WCH* str);

	long pnum; // номер позиции
	int diam; // диаметр стержня
	bool grnd; // является частью контура заземления

	ELID elemid; // ID хозяина (не хозяины а хозяева) - ReinSpace, ReinBar
	ELID axid; // ID оси - ReinAxis
	ELID brid; // bar ID (объемного стержня или ID референса для выноски)
	UInt32 ffpos[5];
	int bartype; // BT_...
	long contnum; // номер линии контура для последовательности точек при построении стержней
	int numpts; // количество точек - может меняться если обрезан клипом (rpts, sgts)
	int cnumpts; // количество точек - неизменно - для сравнения и отрисовки (apts, cpxb)
	int numsgts; // количество сегментов - зависит от наличия гнутых сегментов

	ELREF elref; // for bar sets

	//vector <ReinPoint> &vpt = gvpt; // задел на бдущее

	DVec3d apts[MAX_BAR_VERTICES]; // точки для отрисовки 2D с учетом mainline (точка арки пока не на элементе)
	Point3d cpxb[MAX_BAR_VERTICES]; // x compare points (from begin)
	Point3d cpxe[MAX_BAR_VERTICES]; // x compare alternative points (from end)
	DVec3d rpts[MAX_BAR_VERTICES]; // реальные точки стержня
	DVec3d cents[MAX_BAR_VERTICES]; // центры дуговых сегментов (если есть)
	long rfa[MAX_BAR_VERTICES]; // флаг, указывающий на то что точка принадлежит арке

	BarPoint bent[2]; // 

	//vector <DVec3d> apts; // точки для отрисовки 2D (эскиз) с учетом mainline (точка арки пока не на элементе)
	//vector <Point3d> cpxb; // x compare points (from begin)
	//vector <Point3d> cpxe; // x compare alternative points (from end)
	//vector <long> rfa; // флаг, указывающий на то что точка принадлежит арке
	//vector <DVec3d> rpts; // реальные точки стержня
	//vector <DVec3d> cents; // центры дуговых сегментов (если есть)

	// calc: длина сегмента, включая загибы
	// n - номер сегмента
	// blen[n][0] - минимальная, 
	// blen[n][1] - СУММА средних, 
	// blen[n][2] - максимальная
	vector <vector<long>> blen; 
	//long blen[MAX_BAR_LENS][3]; // segment lengths -> blen [segm index] [min | mid | max], qty -> reinbar.numlen

	vector <long> brad; // calc: bend radius
	//long brad[MAX_BAR_LENS];

	vector <double> bang; // calc: bend angle - between bar segments
	//double bang[MAX_BAR_LENS]; // угол между сегментами стержня

	int numlen;

	ReinSegm sgts[MAX_BAR_VERTICES];

	double length; // берется из элемента
	//int space; // для построения на SURFACE_ELM
	double spacef; // 
	int spacerad;
	int offset[2]; // для построения на SURFACE_ELM
	int bendrad; // радиус загиба
	int poscalc; // набор позиций для их разделения в списке
	int runmet;
	int transp; // transparency (inner/outer)
	int segmIndex; // индекс сегмента (0-based) для оси стержня
	int elemEDoffset; // MSElementDescr offset (получаем при указании на элемент) для оси стержня
	int mainSgmIndex; // индекс главного сегмента,  // будет использоваться когда в контроле будет арка в сегменте
	int mainPtsIndex; // индекс начальной точки главного сегмента (может плыть относительно mainSgmIndex)
	int ilaps; // дополнительный нахлест
	int lap[3];
	int term[2];
	//vector <vector<int>> termPar; // [10][2] // 0 - угол для загиба, 1 - длина загиба, 2 - тип для муфты
	int termPar[10][2];
	UInt32 numRef;
	DgnModelRefP modrefP;
	int inum; // порядковый номер в контуре
	int isgmnum;
	DVec3d v_enrm;
	DVec3d v_pnrm; // parent elem normal
	int noplanar; // новый метод сраввнения, включающий 3д стержни
	int barflags;
} ReinBar;

//extern "C"
//{
//	DLLEXPORT char sLogMes[5000];
//	DLLEXPORT int iDebug;
//
//}

#ifdef _REIN_H_



/// <summary>
/// настройка отображения
/// </summary>
typedef struct reinexcl
{
	wstring ref;
	int ind;
} ReinExcl;

/// <summary>
/// настройка поведения стержня
/// </summary>
typedef struct reinlap
{
	long lapID;
	long projID;
	int diameter;
	int lapValue;
	int maxlen;
	int bend[2]; // work, free
	int bendrad;
	int muft;
	long isrtmID;
	long imatID;
} ReinLap;



/// <summary>
/// анкер (не исп)
/// </summary>
typedef struct ankerinfo
{
	int diam; // диаметр
	int arm;  // класс арматуры
	int bet;  // класс бетона
	int wall; // толщина стены
	int anklen; // длина анкеровки
	int applen; // длина загнутой части стержня без закругления
	int apprad; // длина загнутой части стержня + радиус закругления
	int anksegm; // индекс текстового поля в окошке конфигурации (+100)
} AnkerInfo;


/// <summary>
/// настройка референса
/// </summary>
typedef struct reininforef
{
	reininforef(void);
	void clear(void);

	int active;
	int prefrefn;
	vector<int> riropt;
	int ends;
	int threads;
	int bface;
	int lim;
} ReinInfoRef;


/// <summary>
/// расчетная нагрузка (не исп)
/// </summary>
typedef struct loadnode
{
	DVec3d org;
	long vertind[4];
} LoadNode;

/// <summary>
/// расчетная нагрузка (не исп)
/// </summary>
typedef struct loadvert
{
	double vals[15];
} LoadVert;

/// <summary>
/// настройки отдельного стержня контура
/// </summary>
typedef struct barover
{
	barover(void);
	void clear(void);

	int isdel;
	int isgnd; // заземление
	int inum; // порядковый номер в контуре
	int btmov; // is transformed
	Transform tmov; // 
} BarOver;

/// <summary>
/// аналог DVector3d
/// </summary>
typedef struct _DVector3d
{
	void clear();
	DVec3d org;
	DVec3d end;
} _DVector3d;

/// <summary>
/// плоскость
/// </summary>
typedef struct reinview
{
	reinview(void);
	void clear(void);
	DVec3d ptsBck[4];
	DVec3d ptsDpt[4];
	DVec3d ptsFnt[4];
	DVec3d	point; // точка на активной глубине в центре вида
	DVec3d	normal;
	double depth; // акт. глубина
	RotMatrix rm;
	DVec3d viewsize;
} ReinView;


//typedef struct _reinnoteset
//{
//	WCH sNoteUp[100];
//	WCH sNoteDn[100];
//	WCH sNoteUpFmt[100];
//	WCH sNoteDnFmt[100];
//	int iNoteStyle;
//	int iNoteDim;
//	WCH sNoteLevel[100];
//	// dop
//	int noteopt[10];
//	double noteval[10];
//	WCH notetxt[10][100]; // 10 строк по 100 символов
//} _ReinNoteSet;

/// <summary>
/// настройки выноски
/// </summary>
typedef struct reinnoteset
{
	reinnoteset();
	void clear();
	//void setLegacy(_ReinNoteSet* rdiP, bool bChangeSelf);
	WCH sNoteUp[100];
	WCH sNoteDn[100];
	WCH sNoteUpFmt[100];
	WCH sNoteDnFmt[100];
	int iNoteStyle;
	int iNoteDim;
	WCH sNoteLevel[100];
	// dop
	int noteopt[10];
	double noteval[10];
	WCH notetxt[10][100]; // 10 строк по 100 символов
} ReinNoteSet;

/// <summary>
/// закругление стержня
/// </summary>
typedef struct reinfillet
{
	reinfillet();
	void clear();
	int radius;
	int radius_bend; // для загибов
	double diamrif;
	int arclen;
} ReinFillet;


//typedef struct _reincalc
//{
//	int qty; // bars quantity
//	double length[2]; // length min/max
//	double mainlen[2]; // main segment length min/max
//	double lencmn; // common bar length
//	double width; // space width
//	DVec3d vecX; // исп. для получения rm
//	DVec3d vecY; // исп. для получения rm
//	DVec3d vecZ; // исп. для получения vecY
//	RotMatrix rm;
//	double dist[10];
//	int iRSind; // segment index для точек контура ReinSpace
//	int iMLind; // main line index для стержней ReinSpace
//	_DVector3d rng;
//	Transform tmRef;
//	UInt32 numRef;
//	DVec3d dir[2]; // основной направляющий элемент
//	int cnt; // vertex qty
//	ELID id;
//} _ReinCalc;


/// <summary>
/// рассчитанные данные
/// </summary>
typedef struct reincalc
{
	reincalc();
	void clear();
	//void setLegacy(_ReinCalc* rdiP, bool bChangeSelf);
	int qty; // bars quantity
	double length[2]; // length min/max
	double mainlen[2]; // main segment length min/max
	double lencmn; // common bar length
	double width; // space width
	DVec3d vecX; // исп. для получения rm
	DVec3d vecY; // исп. для получения rm
	DVec3d vecZ; // исп. для получения vecY
	RotMatrix rm;
	double dist[10];
	int iRSind; // segment index для точек контура ReinSpace
	int iMLind; // main line index для стержней ReinSpace
	_DVector3d rng;
	Transform tmRef;
	UInt32 numRef;
	DVec3d dir[2]; // основной направляющий элемент
	int cnt; // vertex qty
	ELID id;
} ReinCalc;

/*
typedef struct _reinspace
{
	int runmet;
	int diam;
	int space;
	int spacerad;
	int offset[2];
	int bendrad;
	int poscalc; // для расчета позиций (iposcalc) id 78
	int trm[2]; // аналог term[2] ReinBar
	//int trmPar[10][2]; // terminator parameter
	vector<vector<int>> trmPar;
	int lap[3];
	int segmIndex; // индекс сегмента (0-based) для контура ReinSpace
	int elemEDoffset; // MSElementDescr offset (получаем при указании на элемент) для контура ReinSpace
	_BarPoint pts_org[10];
	_BarPoint pts_end[10];
	int pts_org_cnt;
	int pts_end_cnt;
	int bartype;
	ELID elid;
	int contnum;
	//ElementID id_end[10];
	//int id_org_cnt;
	//int id_end_cnt;
} _ReinSpace;
*/

/// <summary>
/// область раскладки
/// </summary>
typedef struct reinspace
{
	reinspace(void);

	void clear(void);
	void vecclear(bool bResize);

	//void setLegacy(_ReinSpace* rdiP, bool bChangeSelf);

	int runmet;
	int diam;
	int diam2; // diameter to remember
	int space; // for option
	double spacef;
	//int space2; // для поперечной арматуры
	int spacerad;
	int offset[2];
	int bendrad;
	int poscalc; // для расчета позиций (iposcalc) id 78
	int trm[2]; // аналог term[2] ReinBar

	vector<vector<int>> trmPar; //[10] [2] 0 - угол для загиба, 1 - длина загиба, 2 - тип для муфты
	//int trmPar[10][2]; // terminator parameter

	int lap[3];
	int segmIndex; // индекс сегмента (0-based) для контура ReinSpace
	int elemEDoffset; // MSElementDescr offset (получаем при указании на элемент) для контура ReinSpace
	BarPoint pts_org[10];
	BarPoint pts_end[10];
	int pts_org_cnt;
	int pts_end_cnt;
	int bartype;
	ELID elid;
	int contnum;
	//ElementID id_end[10];
	//int id_org_cnt;
	//int id_end_cnt;
} ReinSpace;

/*
typedef struct _reininfo
{
	int lim; // отображение стрелок
	int ends; // отображение засечек и торцов (вести перерасчет и создание трансиентов)
	int bface; // переопределяющий параметр dCfgVar_BarFace
	int run; // на обозначении в тексте присутствует длина в скобках
	int ttip; // отображение окна эскиза
	int bars; // количество выделенных стержней
	int b3d; // отображение стержней в 3D
	int nodes; // отображение узлов расчетной модели
	int threads; // отображение резьбы

	vector<int> option;
	//int option[20]; // option[0] - создание нового стержня или нет
					// option[1] - отображать внутренние производные элементы контура (с прозрачностью)
					// option[2] - отображать элемент контура ReinSpace или нет
					// option[3] - display only CCGG bars (old use: закругленные стержни при команде _SIDE)
					// option[4] - отображать элемент ReinBar или нет
					// option[5] - отображать производные элементы
					// option[6] - сохранять 3d стержни
					// option[7] - включен/отключен палетка с кнопками
					// option[8] - отображать загибы
					// option[9] - отображать сечения
					// option[10] - показывать контуры стержня
					// option[11] - показывать сечения
					// option[12] - показывать сечения только если перпендикулярность виду
					// option[13] - показать нолики
					// option[14] - показать крестики
					// option[15] - показать номера позиций
					// option[16] - отображение стержня
					// option[17] - отображать внутренние стержни контура, которые в виде сечений
					// option[18] - отображать невидимые стержни пунктиром
					// option[19] - отображать цветом по значению диаметра

	_ReinCalc rcUnit;
	_ReinSpace rsVal;
	_ReinSpace rsOpt;
	//AnkerInfo aInfo;
} _ReinInfo;
*/

/// <summary>
/// настройки
/// </summary>
typedef struct reininfo
{
	reininfo(void);

	void clear(void);

	//void setLegacy(_ReinInfo* rdiP, bool bChangeSelf);

	int lim; // отображение стрелок
	int ends; // отображение засечек и торцов (вести перерасчет и создание трансиентов)
	int bface; // переопределяющий параметр dCfgVar_BarFace
	int run; // на обозначении в тексте присутствует длина в скобках
	int ttip; // отображение окна эскиза
	int bars; // количество выделенных стержней
	int b3d; // отображение стержней в 3D
	int nodes; // отображение узлов расчетной модели
	int threads; // отображение резьбы

	vector<int> option;
	//int option[20]; // option[0] - создание нового стержня или нет
					// option[1] - отображать внутренние производные элементы контура (с прозрачностью)
					// option[2] - отображать элемент контура ReinSpace или нет
					// option[3] - display only CCGG bars (old use: закругленные стержни при команде _SIDE)
					// option[4] - отображать элемент ReinBar или нет
					// option[5] - отображать производные элементы
					// option[6] - сохранять 3d стержни
					// option[7] - включен/отключен палетка с кнопками
					// option[8] - отображать загибы
					// option[9] - отображать сечения
					// option[10] - показывать контуры стержня
					// option[11] - показывать сечения
					// option[12] - показывать сечения только если перпендикулярность виду
					// option[13] - показать нолики
					// option[14] - показать крестики
					// option[15] - показать номера позиций
					// option[16] - отображение стержня
					// option[17] - отображать внутренние стержни контура, которые в виде сечений
					// option[18] - отображать невидимые стержни пунктиром
					// option[19] - отображать цветом по значению диаметра

	ReinCalc rcUnit;
	ReinSpace rsVal;
	ReinSpace rsOpt;
	//AnkerInfo aInfo;
} ReinInfo;

/// <summary>
/// дополнительные настройки
/// </summary>

/*
typedef struct _reindopinfo
{
	int dopopt[50];
	double dopval[50];
	char doptxt[20][100]; // 20 строк по 100 символов
} _ReinDopInfo;
*/
typedef struct reindopinfo
{
	reindopinfo();
	void clear();
	//void setLegacy(_ReinDopInfo* rdiP, bool bChangeSelf);

	int dopopt[50];
	double dopval[50];
	char doptxt[20][100]; // 20 строк по 100 символов
} ReinDopInfo;



/// <summary>
/// линия спецификации
/// </summary>
typedef struct specline
{
	specline();

	void clear();

	DVec3d arp[2];
	Symbology smb;
	UInt32 lev;
	UInt32 ggn;
} SpecLine;

/*
typedef struct _TextParamWide
{
	_TextParamWide();
	void clear();
	TextParamWide m;
};
*/
/// <summary>
/// текст спецификации
/// </summary>
typedef struct spectext
{
	spectext();

	void clear();

	MSWCH txt[200];
	DVec3d p;
	TextSizeParam tsp;
	TextParamWide tp;
	Symbology smb;
	UInt32 lev;
	UInt32 ggn;
	double maxwidth;
} SpecText;


/// <summary>
/// точка стержня
/// </summary>
typedef struct reinpoint
{
	reinpoint();
	reinpoint(DVec3d p);
	reinpoint(DVec3d p, long f);

	void clear();

	void set(DVec3d p);
	void set(DVec3d p, long f);
	void set(DVec3d p, DVec3d c, long f);

	DVec3d rpt; // реальные точки стержня
	DVec3d cent; // центры дуговых сегментов (если есть)
	long rfa; // флаг, указывающий на то что точка принадлежит арке
} ReinPoint;

/// <summary>
/// коллизии
/// </summary>
typedef struct reinclash
{
	reinclash(void);
	void clear();
	UInt32 iShtamp; // идентификатор
	UInt32 fpElem[2];
	ELID idElem3d[2];
	LEVID lvID[2];
	UInt32 idist;
	double cdiam[2];
	ELREF erefClsh;
	DVec3d pt;
	//UInt32 fpTDLine;
	//UInt32 fpTDPoint;
	//TransDescrP tedLnP;
	//TransDescrP tedPtP;
} ReinClash;

/// <summary>
/// кэширование
/// </summary>


//extern "C" 
//{
	//DLLEXPORT 
	typedef struct reincache
	{
		reincache(void);

		int irefnum; // legacy
		wstring refpath;
		ELID elid;
		ELREF elref;
		DgnModelRefP mrP;
		UInt32 pnum;
		MSWCH desc[500];

	} ReinCache;
//}

typedef pair<UInt32, UInt32> UInt32pair;
typedef pair<ELID, int> RelmPair;


typedef struct reinbarset
{
	reinbarset(void);

	void clear(void);

	bool loadBarSetInfo(MSElementDescr* edP);
	bool getIdentChars(MSWCH* wstr, int bForSave);
	wstring getMapIdentString();

	void saveBarSetInfo();

	int bsdrawmode;
	//long	bsset;
	long	bsnum;
	ELID	bseid;
	deque<UInt32> aref;

	//wstring wstrsave;

	DgnModelRefP mrP;
	ELREF bselref; // for hilite

	bool bMustUpdate; // для масовых операций, например fence

	bool bFromRef; // элемент barset пришел из референса или нет

} ReinBarSet;



/// <summary>
/// ось стержня
/// </summary>
typedef struct reinaxis
{
	reinaxis(void);
	void clear(void);

	ELID eleid; // элемент ReinBar или ReinSpace
	int inum; // порядковый номер в контуре
} ReinAxis;

/// <summary>
/// позиция спецификации
/// </summary>
typedef struct reinpos
{
	reinpos();
	~reinpos();

	void clear();
	void clearCalc();

	//bool getIdentChars(MSWCH* wstr, int bForSave);
	//wstring getMapIdentString();

	//reinpos operator=(const reinpos & other);

	ReinBar bar;
	ReinBar bar_mem; // запоминать при изменениях

	//vector<UInt32>arefnum;
	//UInt32 arefnum[MAX_REFNUM_PATH];
	deque<UInt32> arefnum;

	int drawmode; // опция отображения
	long posID;
	long srtmID;
	
	long base_length; // saved value: file_length, not using
	double base_qty; // saved value: file_qty_p or file_qty_rm
	long base_ms_min; // saved value: file_ms_min
	long base_ms_max; // saved value: file_ms_max
	long base_ms_mid; // saved value: file_ms_mid

	long file_length; // not using
	long file_qty_p; // calc: quantity
	double file_qty_rm; // calc: quantity in run meters
	long file_ms_min; // calc: min length
	long file_ms_max; // calc: max length
	long file_ms_mid; // calc: mid length

	int lap_qty; // calc: lap quantity (количество перехлестов)
	int muft_qty[2]; // calc: couplings and etc
	int pdID; // posdefID
	UInt32 pcatID; // каталог

	long pnum_cnd; // кандидат на присовение номера позиции
	long mapind; // source map index for sorted map

	//UInt32 refs[50];
	//int refcnt;
	vector<int>drawopt; // опции отображения DROPT_
	//int drawopt[10];
	int cmpopt[5]; // compare options
	Point3d cmppt; // point for sort in positions list

	bool bPosXml;
	bool bUpdate;

} ReinPos;



/// <summary>
/// выноска
/// </summary>
typedef struct reinnote
{
	reinnote();
	~reinnote();

	void clear();

	WCH sNoteFmt[100];

	vector<ReinBar>vBars;
	map<long, ReinPos> mapNotePos;

	// curNote.arNotePts, curNoteSet...

	DVec3d arNotePts[4]; // 0 - first bar, 1 - second bar, 2 - first note point

	UInt32 iNoteGGN;
	LEVID iNoteLevID;

	int ielem; // как из элементов - размер, линия, текст сверху или снизу

	bool bUpdate;

} ReinNote;


/// <summary>
/// catalog info
/// </summary>
typedef struct catinfo
{
	catinfo();
	void clear();
	void clearPosCalc();
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
	int getPositionsFromDom(XmlDomRef dom);
#endif
	UInt32 projID;
	UInt32 catID; // ID корневого каталога для основной модели
	UInt32 catModID; // ID каталога для модели, который определяется по имени модели из отношений view_object_catalog
	WCH dbase[50];
	WCH catname[200];
	WCH catmodname[200];
	WCH catfullname[1000];
	BINT bAutoCats;

	map<long, ReinPos> arCurPos;
	long iPosIndex; // index for position with num=0
	deque<wstring> dqlvnm; // deque of level names

	int iActive;
} CatInfo;

/// <summary>
/// not using
/// </summary>
typedef struct reinindex
{
	reinindex(void);
	bool inplace;
	UInt32 rei;
} ReinIndex;

#endif


/// <summary>
/// информация об элементе 
/// </summary>
#ifdef _REIN_H_
extern "C"
DLLEXPORT
#endif
typedef struct reinelm
{

	int type; // REIN_ELEM_...

#ifdef _REIN_H_
	DLLEXPORT
#endif
	reinelm(void);

#ifdef _REIN_H_
	DLLEXPORT
#endif
	~reinelm(void);

#ifdef _REIN_H_
	DLLEXPORT
#endif
	void clear(int memres = 0);

	//reinelm operator=( const reinelm & other );

	//int readFromString(STRING str, DgnModelRefP mrP);

	//bool bMemGlobal;
	ReinBar bel; // not transformed
	ReinBar tel; // trasfomed
	int iClip;
	bool bClip;
	long arNum; // arCurPos position (posnum or < 0)
	int drwopt[7];
	int elemflags; // REINEL_FLAG_...
	int modvers; // modelversion
	UInt32 fpDup; // дубликат
	ELREF relmref;
	int bTransientInProgress;

	wstring relmLevName; // level name, use only for position search
	wstring relmSpecName;

#ifdef _REIN_H_
	DLLEXPORT
#endif
	int getElmFromString(wstring str, DgnModelRefP mrP);

#ifdef _REIN_H_
	DLLEXPORT
#endif
	int getElmFromElement(MSElementCP el, DgnModelRefP mrP);

//#ifdef _REIN_H_
//	DLLEXPORT
//#endif
//	int getElmFromElement(ELID elid);

#ifdef _REIN_H_
	DLLEXPORT
#endif
	wstring getReinElmLevName(bool bUpdateMember);


} ReinElm;


#ifdef _REIN_H_



/// <summary>
/// модель (активная или референсы)
/// </summary>
typedef struct ReinModel
{
	ReinModel(DgnModelRefP mrP, long reinelemcnt);
	ReinModel(void);
	~ReinModel(void);

	void Init();
	void Init(DgnModelRefP mrP, long reinelemcnt);

	//ReinModel* rmParentP;

	int iClipVerts;
	DVec3d arClipPts[2][100];

	ReinElm* getReinElm(UInt32 fp);
	ReinElm* findReinElm(ELID prntid, ELID axid); // from mapElms
	ReinElm* findElementByFP(UInt32 fp);
	ReinInfoRef* getRefPrefs();
	void delRefPrefs(int iDpth);
	ReinModel* getRM(DgnModelRefP mrP);
	ReinModel* getRM(UInt32 rn);
	ReinModel* getRM(deque <UInt32> &aref);
	ReinModel* getRM(wstring ws);
	ReinModel* getRMbyID(UInt32 rmid);
	//ReinModel* getRM(UInt32* aref);
	void reloadCurBars(bool bScan, bool bUpdateListBox, int iDepth, int iLoadRefs, bool bScanPos = true);
	//UInt32 getIndMax();
	UInt32 getElemCount(int iDpth);
	long getPosByNum(long pnum);
	ReinPos* getReinPosByNum(long pnum);
	void setCached(bool bSetCached);
	void updateModelElmNumbers(bool bSkipIfLot, map<long, ReinPos>* arCurPosP = NULL);

	//int getRefPath(UInt32* ar);
	size_t getRefPath(deque<UInt32>* ar);
	wstring getRefPathString(deque<UInt32>* arefP = NULL);
	//void getRefPath(vector<UInt32> &path);

	UInt32 getExFpCount(int iDpth);
	UInt32 getExIdCount(int iDpth);

	UInt32 getBarSetSize();

	DgnModelRefP modelP;

	UInt32 elcount;
	bool bCached;
	bool bMissed;
	//bool bRefPlus; // catID совпадает с тем что в ACTIVEMODEL

	double refscale;

	//Wrap* w;

	//ups_db_t *updb = NULL;

	//ReinPos* arPos = NULL;

	map<long, ReinPos>& getPosMap(ReinElm* reP = NULL);
	CatInfo& getCat(ReinElm* reP = NULL);

	//vector<ReinPos> arCurPos; //x
	//ReinPos arCurPos[1000];
	//int iPosQty; // for mem alloc
	//long iPosIndex; // index for position with num=0

	ReinInfoRef* refPrefsP;
	ReinInfoRef refPrefs;

	UInt32 rnum;
	UInt32 rmid; // ReinModel id, identificator for current loaded session
	//int prnum; // parent ref num

	//UInt32 indmax;

	//ReinModel* arMrP[MAX_REF_SLOT];
	map<UInt32, ReinModel> arMrP;

	map<UInt32, ReinElm> mapElms;
	map<ELID, UInt32> mapBars;
	//map<ELID, ReinPos> mapBarSet;

	map <wstring, ReinBarSet> mapBarSet;

	//vector<ReinElm> vecElms;
	//vector<ELID> vExIds;
	//vector<UInt32> vExFps;
	map<ELID,bool> vExIds;
	map<UInt32,bool> vExFps;

	WCH rmname[500];

	TransDescrP tedSecP; // section transient points to snap
	//TransDescrP tedCntP; // contour transients
	map<UInt32, TransDescrP> mapTedCntP;

	CatInfo mrci; // modelref database catalog info

	//	map <UInt32, ReinClash> mapClash; // точки коллизий

//private:
	//map<long, ReinPos> arCurPos; // see mrci

} ReinModel;

/// <summary>
/// параметр проверки модели
/// </summary>
typedef struct reinprm
{
	reinprm(void);
	void clear();

	LEVID lev;
	//deque <UInt32> uival;	
	UInt32 uival[MAX_REFNUM_PATH]; // aref
	int ival[10];
	long lval[10];
	double dval[10];
	UInt32 cnt[10];
	BINT bDel;
	ELID prmid; // elem id
	DVec3d pVec;

	WCH sval[500];
	wstring wstr;

	ReinElm* reP;
	ReinPos* rpP;
	ReinBarSet* bsP;

	map <long, reinprm> mapprm;
	set <ELID> sids;
	set <long> slng;
	vector <DVec3d> vsnaps;
	deque <UInt32> uints;

	MSElementDescrP edP;
	DgnModelRefP mrP;
	UInt32 fp;

} ReinPrm;

#endif

extern "C" DLLEXPORT long mdlRein_getPosNum(ELID elemid);
extern "C" DLLEXPORT ReinElm * mdlRein_getReinElm(UInt32 fp);


#endif