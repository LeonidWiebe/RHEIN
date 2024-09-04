/*----------------------------------------------------------------------+
|																		|
| Additional material provided by LA Solutions Ltd. 2010				|
| www.la-solutions.co.uk												|
| Example code: no copyright claimed									|
|																		|
| Copyright 1993-2001, Bentley Systems, Incorporated, 					|
| All rights reserved.													|
|																		|
|																		|
| Limited permission is hereby granted to reproduce and modify this		|
| copyrighted material provided that the resulting code is used only in |
| conjunction with Bentley Systems products under the terms of the		|
| license agreement provided therein, and that this notice is retained	|
| in its entirety in any such reproduction or modification.				|
|																		|
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|                                                                       |
|   ViewTransients - ViewTransients source code. 						|
|                                                                       |
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|                                                                       |
|   Include Files                                                       |
|                                                                       |
+----------------------------------------------------------------------*/

// stdafx.h : include file for standard system C++ include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once


//#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <string.h>
//#include <xstring/xstring.h>
#include <algorithm>
#include <vector>
#include <deque>

#include <iostream>
#include <fstream>

//	Order of #inclusion of Bentley files is critical: #include MicroStationAPI.h first
//#include <MicroStationAPI.h>
//#include "MessageTracer.h" // из ViewTransients

//typedef	std::vector<DPoint3d>			DPoint3dVector;
//typedef DPoint3dVector::iterator		DPoint3dIterator;
//typedef DPoint3dVector::const_iterator	DPoint3dConstIterator;



