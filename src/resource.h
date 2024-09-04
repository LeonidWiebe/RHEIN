//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by rein8i.rc

// version increment from
// https://stackoverflow.com/questions/638053/how-to-increment-visual-studio-build-number-using-c

#include "vers.h"
#include "reinvers.h"

#define STRINGIZE2(s) #s
#define STRINGIZE(s) STRINGIZE2(s)

#define VERSION_MAJOR             VERSAPP
#define VERSION_MINOR             VERSMAJ
#define VERSION_REVISION          VERSMID
#define VERSION_BUILD             VERSMIN

#if SVN_LOCAL_MODIFICATIONS
   #define VERSION_MODIFIER "M"
#else
   #define VERSION_MODIFIER
#endif

#define VER_FILE_VERSION   VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION, VERSION_BUILD
#define VER_FILE_VERSION_STR        STRINGIZE(VERSION_MAJOR)        \
"." STRINGIZE(VERSION_MINOR)    \
"." STRINGIZE(VERSION_REVISION) \
"." STRINGIZE(VERSION_BUILD)    \

#define VER_PRODUCT_VERSION         VER_FILE_VERSION
#define VER_PRODUCT_VERSION_STR     VER_FILE_VERSION_STR

#define VER_FILE_DESCR_STR        STRINGIZE(VER_FILE_DESCR)

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NEXT_RESOURCE_VALUE        101
#define _APS_NEXT_COMMAND_VALUE         40001
#define _APS_NEXT_CONTROL_VALUE         1001
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif


