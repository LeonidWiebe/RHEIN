/*----------------------------------------------------------------------+
|									|
|   Include Files   							|
|									|
+----------------------------------------------------------------------*/

#include "vers.h"
#include "rein.h"



#if defined (MSVERSION) && (MSVERSION == 0xa00) // includes

#include <Mstn\MdlApi\rscdefs.r.h>
#include <Mstn\MdlApi\cmdclass.r.h>
#include <Mstn\cmdlist.r.h>

#define COMMANDID_REIN_PLACE          1
#define COMMANDID_REIN_POS_DRAW       2
#define COMMANDID_REIN_BARSET         3
#define COMMANDID_REIN_MODIFY         4
#define COMMANDID_REIN_NOTE           5
#define COMMANDID_REIN_SIDE           6
#define COMMANDID_REIN_BAROVER        7

#else

#include <rscdefs.h>
//#include <dlogbox.h>
//#include <cmdlist.h>
#include <cmdclass.h>


#define CommandTable Table

#endif


#define	CT_NONE		    0
#define CT_REIN  	    1
#define CT_CMDS		    2
#define CT_PLACE		3
#define CT_SPLOT		4
#define CT_BARENDS		5
#define CT_POS			6



CommandTable CT_REIN =
{
    {  1, CT_CMDS, PARAMETERS, NONE, "REIN"},
};

// !!! ПРИ ДОБАВЛЕНИИ НОВОЙ КОМАНДЫ НЕ ЗАБЫВАТЬ ПРО ЕЁ НОМЕР !!!
CommandTable CT_CMDS =
{
    {  1, CT_NONE, INHERIT, NONE, "PLACE"
#if defined (MSVERSION) && (MSVERSION == 0xa00) // cmd
	, COMMANDID_REIN_PLACE, ItemList_REIN_PLACE
#endif
	},
    {  2, CT_NONE, INHERIT, NONE, "MODIFY"
#if defined (MSVERSION) && (MSVERSION == 0xa00) // cmd
	, COMMANDID_REIN_MODIFY, ItemList_REIN_MODIFY
#endif
	},
    {  3, CT_NONE, INHERIT, NONE, "NOTE"
#if defined (MSVERSION) && (MSVERSION == 0xa00) // cmd
	, COMMANDID_REIN_NOTE, ItemList_REIN_NOTE
#endif
	},
    {  4, CT_NONE, INHERIT, HID , "TOOLTIP"},
    {  5, CT_NONE, INHERIT, NONE, "TOOLBOX"},
    {  6, CT_NONE, INHERIT, NONE, "VERSION"},
    {  7, CT_NONE, INHERIT, NONE , "RELOAD"},
    {  8, CT_NONE, INHERIT, HID , "DRAW3D"},
    {  9, CT_NONE, INHERIT, NONE , "CHLAP"}, // изменение четности разбежки
    {  10, CT_NONE, INHERIT, NONE , "UNGRAB"},
    {  11, CT_NONE, INHERIT, NONE , "BAR"},
    {  12, CT_NONE, INHERIT, NONE , "LIST"},
    {  13, CT_NONE, INHERIT, NONE , "PLANE"},
    {  14, CT_NONE, INHERIT, NONE , "ANKER"},
    {  15, CT_NONE, INHERIT, HID , "NODES"},
    {  16, CT_NONE, INHERIT, NONE , "MIRROR"},
    {  17, CT_NONE, INHERIT, NONE , "LOADS"}, // определение требуемого диаметра
    {  18, CT_NONE, INHERIT, HID , "DRAWENDS"},
    {  19, CT_NONE, INHERIT, HID , "MUFT"}, // расчет количества муфт
    {  20, CT_NONE, INHERIT, HID , "DRAWCONT"},
    {  21, CT_NONE, INHERIT, NONE , "SIDE"},
    {  22, CT_NONE, INHERIT, NONE , "FRONT"},
    {  23, CT_NONE, INHERIT, NONE , "FLAGS"},
    {  24, CT_NONE, INHERIT, HID , "DRAWBARS"},
    {  25, CT_NONE, INHERIT, HID , "FILEBARS"},
    {  26, CT_NONE, INHERIT, HID , "REFPDEL"},
    {  27, CT_NONE, INHERIT, HID , "LOGOPEN"},
    {  28, CT_NONE, INHERIT, HID , "LOGCLOSE"},
    {  29, CT_NONE, INHERIT, HID , "MUFTSHOW"},
    {  30, CT_NONE, INHERIT, HID , "CAGES"}, // расчет количества муфт
    {  31, CT_NONE, INHERIT, HID , "HPINFO"},
    {  32, CT_BARENDS, INHERIT, NONE , "BARENDS"}, // расчет количества выпусков
    {  33, CT_NONE, INHERIT, HID , "BARSET"},
    {  34, CT_POS, INHERIT, NONE , "POS"},
    {  35, CT_SPLOT, INHERIT, NONE , "SAVEPLOT"},
    {  36, CT_NONE, INHERIT, NONE , "DUPS"},
    {  37, CT_NONE, INHERIT, HID , "HPDEL"},
    {  38, CT_NONE, INHERIT, NONE , "DROP"}, // 
    {  39, CT_NONE, INHERIT, NONE , "MERGE"}, // 
    {  40, CT_NONE, INHERIT, NONE , "VISIT"}, // показать скрытые элементы и снова скрыть
    {  41, CT_NONE, INHERIT, NONE , "BAROVER"}, // переопределение данных стержня в контуре (в т.ч. удаление)
    {  42, CT_NONE, INHERIT, NONE , "CONCRETE"},
};


CommandTable CT_SPLOT =
{
    {  1, CT_NONE, INHERIT, NONE, "CLEAR"},
    {  2, CT_NONE, INHERIT, NONE, "REFS"},
};

CommandTable CT_BARENDS =
{
    {  1, CT_NONE, INHERIT, NONE, "DIALOG"},
};

CommandTable CT_POS =
{
    {  1, CT_NONE, INHERIT, NONE, "CLEAR"}, // удаляет данные по позициям из файла
    {  2, CT_NONE, INHERIT, NONE, "SAVE"}, // сохраняет все позиции
    {  3, CT_NONE, INHERIT, NONE, "DBLOAD"}, // загружает позиции из базы
    {  4, CT_NONE, INHERIT, NONE, "DBSAVE"}, // сохраняет позиции в базе
    {  5, CT_NONE, INHERIT, NONE, "DRAW"}, // 
    {  6, CT_NONE, INHERIT, NONE, "ENUM"}, // пронумеровать
    {  7, CT_NONE, INHERIT, NONE, "CATCH"}, // пронумеровать
};


