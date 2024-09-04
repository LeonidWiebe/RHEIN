
#if defined (D_CONNECT)
#define MSVERSION 0xa00
//#define STD_INTERFACE
//#define VER_FILE_DESCR Addin for MicroStation CONNECT (x64)
//#define VER_FILE_DESCR Addin for OpenBuildings CONNECT (x64)
#else
#define MSVERSION 0x8b0
#define STD_INTERFACE

#if defined (AECOSIM)
//#define VER_FILE_DESCR Addin for AECOsim SELECTSeries 6 (x86)
#else
//#define VER_FILE_DESCR Addin for MicroStation V8i (x86)
#endif

#endif

//#define LANG_EN
//#define LANG_RU

