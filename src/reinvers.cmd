echo #define VERSAPP %VAPP% > .\reinvers.h
echo #define VERSMAJ %VMAJ% >> .\reinvers.h
echo #define VERSMID %VMID% >> .\reinvers.h
echo #define VERSMIN %VMIN% >> .\reinvers.h
echo #define VERDATE L"%DATE%" >> .\reinvers.h
echo #define VERTIME L"%TIME%" >> .\reinvers.h
echo #define VER_FILE_DESCR %VER_FILE_DESCR% >> .\reinvers.h

if %1 == e (
echo #define AFX_RESOURCE_DLL >> .\reinvers.h
echo #define AFX_TARG_ENU >> .\reinvers.h
)

if %1 == r (
echo #define AFX_RESOURCE_DLL >> .\reinvers.h
echo #define AFX_TARG_RUS >> .\reinvers.h
)

