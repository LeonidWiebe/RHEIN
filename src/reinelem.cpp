// PART OF ME

/*
	RHEIN
	Copyright (C) 2023  LEONID WIEBE
	mailto:wleo@ya.ru

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#include	"StdAfx.h"

#include	"vers.h"


//#include <string.h>
//#include <windows.h>


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

#include "reinccmd.h"


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
	extern char*		ustnTaskIdP;
}	//	extern C
#endif

#include    <deprecated8_9.fdf>

#include "reincmd.h"


#endif


using namespace std;

#if defined (OBD)
#include <tfapi\CatalogCollection.h>
#include <tfapi\BuildingEditElemHandle.h>
#endif

//#include "Psapi.h"

#pragma warning(disable:4101) // unreferenced local variable
#pragma warning(disable:4189) // local variable is initialized but not referenced
//#pragma warning(disable:4018) // signed/unsigned mismatch
//#pragma warning(disable:4267) // conversion from 'size_t' to 'int', possible loss of data


//#include    <GPArray.h>
//#include <ups/upscaledb.h>

#include "rein.h"
#include "reinsgn.h"
#include "reinbar.h"
#include "reinelem.h"

#if defined (LANG_EN)
#include "reintxte.h"
#else
#include "reintxt.h"
#endif

#include "reinvers.h"


#include "reinfunc.h"




void reinelement::clear(void)
{
	rb.clear();
	rs.clear();
	rd.clear();

	fpRS = 0;
	idRS = 0;
	modelRef = NULL;
	iLevelMask = 0;

	mapOvers.clear();
}

reinelement::reinelement(void)
{
	clear();
}

////Add RIO
//// DELETE
// void drawRoundBras( vector<ReinBar> &vBars) // Отрисовка новых стержней по surface
// {
// 	static MSElement newBarLine;
// 	unsigned int countBars = vBars.size();

// 	for(int i_bar = 0; i_bar < countBars; ++i_bar )
// 	{
// 		if( SUCCESS == mdlLineString_create(&newBarLine, NULL, vBars[i_bar].rpts, vBars[i_bar].numpts ) )
// 		{
// 			mdlElement_display (&newBarLine, DRAW_MODE_Normal);
// 			mdlElement_add (&newBarLine);
// 		}
// 	} 
// }
///////////

int reinelement::calcSurfRevolution
(
	MSElementDescr *pedBar, 					// [ IN] // pointer on elem descriptor of boundary profile (bar)
	DPoint3d *pCentSurf, 						// [ IN] // центр окружности закругления surface-а
	double surfSwan, 							// [ IN] // sweep angle // in radian // угол развертки suface, радианная мера surface-а
	vector<ReinBar> &vBars,						// [OUT] // ссылка на контейнер стержней
	DgnModelRefP mrP,							// [ IN] // model reference
	DVec3d *pAxis								// [ IN] // suface axis
)
{
	if( !vBars.empty() ){
		vBars.clear();
	}

	///////////>>>>>>>>>>>>>>>>
	// Transform saveTransfMatr;
	// mdlTMatrix_getIdentity(&saveTransfMatr);
	// mdlElmdscr_orientationExt( &saveTransfMatr, pedBar, mrP );
	// //mdlElmdscr_transform(pedBar, &saveTransfMatr);

	// RotMatrix saveRotMatr;
	// mdlRMatrix_getIdentity(&saveRotMatr);
	// mdlRMatrix_fromTMatrix( &saveRotMatr, &saveTransfMatr );

	// DVec3d trueAxis;
	// mdlVec_fromXYZ(&trueAxis, 0.,0.,1.);
	// RotMatrix trueRorMat;
	// mdlRMatrix_getIdentity(&trueRorMat);
	// mdlRMatrix_fromRotationAboutAxis( &trueRorMat, &trueAxis, 0);

	// Transform trueTransfMatr;
	// mdlTMatrix_getIdentity(&trueTransfMatr);
	// mdlTMatrix_fromRMatrix(&trueTransfMatr, &trueRorMat);
	// int ret_stat = mdlElmdscr_transform(pedBar, &trueTransfMatr);
	/////////////><<<<<<<<<<<<<<<<<<<<<<

	int pointsCount = mdlLinear_getPointCount( &pedBar->el ); // count points of profile bar
	if( pointsCount > 0 )
	{
		DPoint3d linearPoints[ MAX_BAR_VERTICES ]; // array for point of surface profile (bar) 

		mdlLinear_extract( linearPoints, &pointsCount, &pedBar->el, mrP );

		double step_rad = rs.spacerad; // Радиус, по которому отмеряется шаг (rs.space)
		if(  step_rad <= 0 )
		{
			// Поиск длины минимальной дуги (которая ближе к центру) 
			step_rad = mdlVec_distance( pCentSurf, &linearPoints[0] ); // step_rad = first rad from bar points
			for( int i=1; i<pointsCount; ++i ) // i=0 on previous step
			{
				const double radiusPnt = mdlVec_distance (pCentSurf, &linearPoints[i]);
				if( radiusPnt < step_rad ){
					step_rad = radiusPnt; // set new MIN radius
				}
			}
		}
		double phi_offset = mdlCnv_masterUnitsToUors( static_cast<double>( rs.offset[0] ) ) / step_rad; // phi_offset - угол смещения в радианах // offset[0] - смещение от начала (длина)
		int signCoef_phi = surfSwan >= 0 ? 1 : -1;

		double step_arcLen = mdlCnv_masterUnitsToUors( rs.spacef ); // Длина дуги шага в uors
		// double step_angle = (step_arcLen*180.) / fc_pi*step_rad;	// полная формула угла дуги, в градусах
		double step_angle = step_arcLen / step_rad; // угол шага, после приведения к радианам, получилась формула: a = L/R 

		unsigned int countBars = static_cast<int>( ( abs(surfSwan) - abs(phi_offset) ) / step_angle ) +1; // деление без остатка (приведение к int) // количество стержней влезающих в контур suface

		for( UInt32 iter_bar = 0; iter_bar < countBars; iter_bar++ ) 
		{
			ReinBar tmp_bar;

			copySpaceData(&rs, &tmp_bar, TRUE, 0, 0);

			tmp_bar.numpts = pointsCount;

			for( int i_point=0; i_point < pointsCount; ++i_point )
			{
				const DPoint3d *pPnt = &linearPoints[i_point]; // pointer on current bar point

				DVec3d tmp_new_point; // new coords for current bar point
				
				// 2D // НЕ ИСПОЛЬЗУЕТСЯ ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				// DPoint3d pArcCent = pCentSurf; // По идее, у каждой точки (linearPoints[i_point]) есть свой Arc, центр которого и нужен
				// const double radiusPnt = mdlVec_distance (pArcCent, pPnt); //  radius for 3D
				// tmp_new_point.x = pArcCent->x + radiusPnt * cos( step_angle * iter_bar );
				// tmp_new_point.y = pArcCent->y + radiusPnt * sin( step_angle * iter_bar );
				// tmp_new_point.z = pArcCent->z; // Что с Z ??? можно брать от центра соответствующего Arc-а, при условии что Z константа (одна плоскость)
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				// 3D ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				const double radiusPnt = mdlVec_distance (pCentSurf, pPnt); //  radius of sphere // must be R >= 0
				if( radiusPnt > 0 )
				{
					// Величины сферы по XYZ ////////////////
					double tmp_X = pPnt->x - pCentSurf->x; // величина X (от центра закругления surface-а)
					double tmp_Y = pPnt->y - pCentSurf->y; // величина Y (от центра закругления surface-а)
					double tmp_Z = pPnt->z - pCentSurf->z; // величина Z (от центра закругления surface-а)

					// Углы в сферических координатах
					double theata = atan( sqrt( pow(tmp_X,2) + pow(tmp_Y,2) ) / tmp_Z );	// in radian // зенит (угол по вертикали) 
					double theata_abs = abs( theata ); // absolute value of theata // must be 0d(0r) <= theata <= 180d(fc_pi)
					// double theata_degree = theata * 180/fc_pi; // in degrees //debug
					int signCoef_Z = theata > 0 ? 1 : -1;
					
					if( sin(theata) != 0 ) //if( theata != 0 && theata != fc_pi )
					{
						double phi = atan( tmp_Y/tmp_X ) + (step_angle * iter_bar + phi_offset) * signCoef_phi;	// in radian // азимут (угол по горизонтали) // 0d(0r) <= phi <=360d(2*fc_pi)
						// double phi_degree = phi * 180/fc_pi; // in degrees //debug
						
						// Вообще-то не влияет, так и отрицательное значения  угла phi даёт аналогичный результат (как и у соответствующего положительного)
						// if(phi<0)
						// {
						// 	phi = 2*fc_pi + phi; // т.е. отнять, чтобы получить положительнаый угол
						// 	phi_degree = phi * 180/fc_pi;
						// }

						// Новые координаты точки в декартовой системе координат
						tmp_new_point.x = pCentSurf->x + radiusPnt * sin(theata_abs) * cos(phi);
						tmp_new_point.y = pCentSurf->y + radiusPnt * sin(theata_abs) * sin(phi);
						tmp_new_point.z = pCentSurf->z + radiusPnt * cos(theata_abs) * signCoef_Z;
					}
					else{
						// Угол phi НЕ определён при sin(theta)==0, то же самое что и  theata==0d(0r) или theata==180d(fc_pi)
						tmp_new_point.x = pCentSurf->x;
						tmp_new_point.y = pCentSurf->y;
						tmp_new_point.z = pCentSurf->z + radiusPnt * cos(theata);
					}
				}
				else{
					// Углы theata и phi НЕ определены при R==0, получается точка в центре сферы
					tmp_new_point.x = pCentSurf->x;
					tmp_new_point.y = pCentSurf->y;
					tmp_new_point.z = pCentSurf->z;
				}
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				//> TEST transform>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
				DVec3d rotate_point = tmp_new_point;
				rotate_point.x -= pCentSurf->x;
				rotate_point.y -= pCentSurf->y;
				rotate_point.z -= pCentSurf->z;

				// Transform barTransMatrix;
				// mdlTMatrix_getIdentity( &barTransMatrix );
				RotMatrix barRotMatrix;
				mdlRMatrix_getIdentity( &barRotMatrix );
				
				// mdlElmdscr_orientationExt( &barTransMatrix, pedBar, mrP );
				
				// mdlRMatrix_fromTMatrix( &barRotMatrix, &barTransMatrix );
				// // DVec3d negateAxis;
				// // mdlVec_negate(&negateAxis, pAxis);
				// DVec3d trueAxis;
				// mdlVec_fromXYZ(&trueAxis, 0.,0.,1.);
				// DVec3d newAxis;
				// double rotAngle = mdlVec_angleAndAxisOfRotationFromVectorToVector(&newAxis, pAxis, &trueAxis);
				mdlRMatrix_fromRotationAboutAxis( &barRotMatrix, pAxis, pAxis->z >= 0 ? 0 : -surfSwan ); //
				// // mdlRMatrix_getInverse ( &barRotMatrix, &barRotMatrix );
				mdlRMatrix_rotatePointArray( &rotate_point, &barRotMatrix, 1 );
				
				rotate_point.x += pCentSurf->x;
				rotate_point.y += pCentSurf->y;
				rotate_point.z += pCentSurf->z;
				tmp_new_point = rotate_point;
				////> TEST transform <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
				

				tmp_bar.rpts[i_point] = tmp_new_point;	// adding new point to array
			}

			vBars.push_back(tmp_bar);
		}
	}

	// DRAW new lines // DELETE
	//if( !vBars.empty() ){
	//	drawRoundBras(vBars);
	//}
	//////////////////////

	return SUCCESS;
}


