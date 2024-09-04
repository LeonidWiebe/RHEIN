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


#include "rein.fdf"



void barover::clear(void)
{
	isdel = 0;
	isgnd = 0;
	inum = 0;
	btmov = FALSE;
	mdlTMatrix_getIdentity(&tmov);
}

barover::barover(void)
{
	clear();
}


void reininforef::clear(void)
{
	active = 0;
	prefrefn = 0;
	
	riropt.clear();
	riropt.resize(50);

	ends = 0;
	threads = 0;
	bface = 0;
	lim = 0;
}

reininforef::reininforef(void)
{
	riropt.resize(50);

	clear();
}

void reindata::clear(void)
{
	dattype = 0;
	datdiam = 0;
	datrunmet = 0;
	datlap[0] = 0; // beg, end, even
	datlap[1] = 0; // beg, end, even
	datlap[2] = 0; // beg, end, even
	datbdrad = 0; // bendrad - if 0 use fillet radius
	dattrm[0] = 0; // аналог term[2] ReinBar
	dattrm[1] = 0; // аналог term[2] ReinBar

	//vecAllocInt(&dattrmPar, 2);
	
	for (int i = 0; i < 10; i++)
	{
		dattrmPar[i][0] = 0;
		dattrmPar[i][1] = 0;
	}
	
	//dattrmPar[0][0] = 0;
	//dattrmPar[1][0] = 0;
	//dattrmPar[2][0] = 0;
	//dattrmPar[3][0] = 0;
	//dattrmPar[4][0] = 0;
	//dattrmPar[0][1] = 0;
	//dattrmPar[1][1] = 0;
	//dattrmPar[2][1] = 0;
	//dattrmPar[3][1] = 0;
	//dattrmPar[4][1] = 0;

	datposcalc = 0;
	datspace = 0;
	datoffset[0] = 0;
	datoffset[1] = 0;
}

reindata::reindata(void)
{
	//dattrmPar.resize(10);

	clear();
}


void _DVector3d::clear(void)
{
	mdlVec_zero(&org);
	mdlVec_zero(&end);
}


void reinview::clear(void)
{
	depth = 0.;
	mdlVec_zero(&point);
	mdlVec_zero(&normal);
	mdlVec_zero(&viewsize);
	for (int i = 0; i < 4; i++)
	{
		mdlVec_zero(&ptsBck[i]);
		mdlVec_zero(&ptsDpt[i]);
		mdlVec_zero(&ptsFnt[i]);
	}
	mdlRMatrix_getIdentity(&rm);
}

reinview::reinview(void)
{
	clear();
}


reindopinfo::reindopinfo()
{
	clear();
}

void reindopinfo::clear()
{
	for (int i = 0; i < 50; i++) dopopt[i] = 0;
	for (int i = 0; i < 50; i++) dopval[i] = 0.;
	for (int i = 0; i < 20; i++) strcpy(doptxt[i], "\0\0\0"); // ВНИМАТЕЛЬНЕЕ
}

//void reindopinfo::setLegacy(_ReinDopInfo* rdiP, bool bChangeSelf)
//{
//	if (bChangeSelf)
//	{
//		for (int i = 0; i < 50; i++) dopopt[i] = rdiP->dopopt[i];
//		for (int i = 0; i < 50; i++) dopval[i] = rdiP->dopval[i];
//		for (int i = 0; i < 20; i++) strncpy(doptxt[i], rdiP->doptxt[i], 100);
//	}
//	else
//	{
//		for (int i = 0; i < 50; i++) rdiP->dopopt[i] = dopopt[i];
//		for (int i = 0; i < 50; i++) rdiP->dopval[i] = dopval[i];
//		for (int i = 0; i < 20; i++) strncpy(rdiP->doptxt[i], doptxt[i], 100);
//	}
//}

void reinnoteset::clear()
{
	SCPY(sNoteUp, L(""));
	SCPY(sNoteDn, L(""));
	SCPY(sNoteUpFmt, L(""));
	SCPY(sNoteDnFmt, L(""));
	iNoteStyle = 0;
	iNoteDim = 0;
	SCPY(sNoteLevel, L(""));

	for (int i = 0; i < 10; i++) noteopt[i] = 0;
	for (int i = 0; i < 10; i++) noteval[i] = 0.;
	for (int i = 0; i < 10; i++) SCPY(notetxt[i], L(""));
}

//void reinnoteset::setLegacy(_ReinNoteSet* rdiP, bool bChangeSelf)
//{
//	if (bChangeSelf)
//	{
//		SCPY(sNoteUp, rdiP->sNoteUp);
//		SCPY(sNoteDn, rdiP->sNoteDn);
//		SCPY(sNoteUpFmt, rdiP->sNoteUpFmt);
//		SCPY(sNoteDnFmt, rdiP->sNoteDnFmt);
//		iNoteStyle = rdiP->iNoteStyle;
//		iNoteDim = rdiP->iNoteDim;
//		SCPY(sNoteLevel, rdiP->sNoteLevel);
//
//		for (int i = 0; i < 10; i++) noteopt[i] = rdiP->noteopt[i];
//		for (int i = 0; i < 10; i++) noteval[i] = rdiP->noteval[i];
//		for (int i = 0; i < 10; i++) SCNPY(notetxt[i], rdiP->notetxt[i], 100);
//	}
//	else
//	{
//		SCPY(rdiP->sNoteUp, sNoteUp);
//		SCPY(rdiP->sNoteDn, sNoteDn);
//		SCPY(rdiP->sNoteUpFmt, sNoteUpFmt);
//		SCPY(rdiP->sNoteDnFmt, sNoteDnFmt);
//		rdiP->iNoteStyle = iNoteStyle;
//		rdiP->iNoteDim = iNoteDim;
//		SCPY(rdiP->sNoteLevel, sNoteLevel);
//
//		for (int i = 0; i < 10; i++) rdiP->noteopt[i] = noteopt[i];
//		for (int i = 0; i < 10; i++) rdiP->noteval[i] = noteval[i];
//		for (int i = 0; i < 10; i++) SCNPY(rdiP->notetxt[i], notetxt[i], 100);
//	}
//}

reinnoteset::reinnoteset()
{
	clear();
}


void reinfillet::clear()
{
	radius = 0;
	radius_bend = 0;
	diamrif = 0.;
	arclen = 0;
}

reinfillet::reinfillet()
{
	clear();
}


reincalc::reincalc(void)
{
	clear();
}

void reincalc::clear(void)
{
	qty = 0;
	length[0] = 0.;
	length[1] = 0.;
	mainlen[0] = 0.;
	mainlen[1] = 0.;
	lencmn = 0.;
	width = 0.;
	mdlVec_zero(&vecX);
	mdlVec_zero(&vecY);
	mdlVec_zero(&vecZ);
	mdlRMatrix_getIdentity(&rm);
	for (int i = 0; i < 10; i++) dist[i] = 0.;
	iRSind = 0;
	iMLind = 0;
	rng.clear();
	mdlTMatrix_getIdentity(&tmRef);
	numRef = 0;
	mdlVec_zero(&dir[0]);
	mdlVec_zero(&dir[1]);
	cnt = 0;
	id = 0;
}

//void reincalc::setLegacy(_ReinCalc* rdiP, bool bChangeSelf)
//{
//	if (bChangeSelf)
//	{
//		qty = rdiP->qty;
//		length[0] = rdiP->length[0];
//		length[1] = rdiP->length[1];
//		mainlen[0] = rdiP->mainlen[0];
//		mainlen[1] = rdiP->mainlen[1];
//		lencmn = rdiP->lencmn;
//		width = rdiP->width;
//		vecX = rdiP->vecX;
//		vecY = rdiP->vecY;
//		vecZ = rdiP->vecZ;
//		rm = rdiP->rm;
//		tmRef = rdiP->tmRef;
//
//		for (int i = 0; i < 10; i++) 
//			dist[i] = rdiP->dist[i];
//
//		iRSind = rdiP->iRSind;
//		iMLind = rdiP->iMLind;
//
//		rng.org = rdiP->rng.org;
//		rng.end = rdiP->rng.end;
//
//		numRef = rdiP->numRef;
//		dir[0] = rdiP->dir[0];
//		dir[1] = rdiP->dir[1];
//		cnt = rdiP->cnt;
//		id = rdiP->id;
//	}
//	else
//	{
//		rdiP->qty = qty;
//		rdiP->length[0] = length[0];
//		rdiP->length[1] = length[1];
//		rdiP->mainlen[0] = mainlen[0];
//		rdiP->mainlen[1] = mainlen[1];
//		rdiP->lencmn = lencmn;
//		rdiP->width = width;
//		rdiP->vecX = vecX;
//		rdiP->vecY = vecY;
//		rdiP->vecZ = vecZ;
//		rdiP->rm = rm;
//		rdiP->tmRef = tmRef;
//
//		for (int i = 0; i < 10; i++)
//			rdiP->dist[i] = dist[i];
//
//		rdiP->iRSind = iRSind;
//		rdiP->iMLind = iMLind;
//
//		rdiP->rng.org = rng.org;
//		rdiP->rng.end = rng.end;
//
//		rdiP->numRef = numRef;
//		rdiP->dir[0] = dir[0];
//		rdiP->dir[1] = dir[1];
//		rdiP->cnt = cnt;
//		rdiP->id = id;
//	}
//}

void barpoint::clear(void)
{
	mdlVec_zero(&pVrtx);
	mdlVec_zero(&pVrtxNext);
	mdlVec_zero(&pDirX);
	mdlVec_zero(&pDirY);
	mdlVec_zero(&pDirZ);
	mdlVec_zero(&pArcCent);
	mdlVec_zero(&pArcPts[0]);
	mdlVec_zero(&pArcPts[1]);
	mdlVec_zero(&pElPoint);
	mdlVec_zero(&pEndPoint);
	bend_ang = 0;
	bend_len = 0;
	flg = 0;
	nmb = 0;
	bnd = 0;
}

barpoint::barpoint(void)
{
	clear();
}

void reinspace::vecclear(bool bResize)
{
}

void reinspace::clear(void)
{
	runmet = 0;
	diam = 0;
	space = 0;
	spacerad = 0;
	offset[0] = 0;
	offset[1] = 0;
	bendrad = 0;
	poscalc = 0;

	trm[0] = 0;
	trm[1] = 0;

	lap[0] = 0;
	lap[1] = 0;
	lap[2] = 0;

	vecAllocInt(&trmPar, 2);

	vecclear(true);

	segmIndex = 0;
	elemEDoffset = 0;

	for (int i = 0; i < 10; i++) pts_org[i].clear();
	for (int i = 0; i < 10; i++) pts_end[i].clear();
	pts_org_cnt = 0;
	pts_end_cnt = 0;

	bartype = 0;
	elid = 0;
	contnum = 0;

}

reinspace::reinspace(void)
{
	trmPar.resize(10);

	clear();
}

//void reinspace::setLegacy(_ReinSpace* rdiP, bool bChangeSelf)
//{
//	if (bChangeSelf)
//	{
//		runmet = rdiP->runmet;
//		diam = rdiP->diam;
//		space = rdiP->space;
//		spacerad = rdiP->spacerad;
//		offset[0] = rdiP->offset[0];
//		offset[1] = rdiP->offset[1];
//		bendrad = rdiP->bendrad;
//		poscalc = rdiP->poscalc;
//
//		CopyMemory(&trm, &rdiP->trm, sizeof(trm));
//		//CopyMemory(&trmPar, &rdiP->trmPar, sizeof(trmPar));
//		trmPar = rdiP->trmPar;
//		CopyMemory(&lap, rdiP->lap, sizeof(lap));
//
//		segmIndex = rdiP->segmIndex;
//		elemEDoffset = rdiP->segmIndex;
//
//		pts_org_cnt = rdiP->pts_org_cnt;
//		pts_end_cnt = rdiP->pts_end_cnt;
//
//		bartype = rdiP->bartype;
//		elid = rdiP->elid;
//		contnum = rdiP->contnum;
//	}
//	else
//	{
//		rdiP->runmet = runmet;
//		rdiP->diam = diam;
//		rdiP->space = space;
//		rdiP->spacerad = spacerad;
//		rdiP->offset[0] = offset[0];
//		rdiP->offset[1] = offset[1];
//		rdiP->bendrad = bendrad;
//		rdiP->poscalc = poscalc;
//
//		CopyMemory(&rdiP->trm, &trm, sizeof(trm));
//		CopyMemory(&rdiP->trmPar, &trmPar, sizeof(trmPar));
//		CopyMemory(&rdiP->lap, lap, sizeof(lap));
//
//		rdiP->segmIndex = segmIndex;
//		rdiP->elemEDoffset = segmIndex;
//
//		rdiP->pts_org_cnt = pts_org_cnt;
//		rdiP->pts_end_cnt = pts_end_cnt;
//
//		rdiP->bartype = bartype;
//		rdiP->elid = elid;
//		rdiP->contnum = contnum;
//	}
//
//	for (int i = 0; i < 10; i++)
//		pts_org[i].setLegacy(&rdiP->pts_org[i], bChangeSelf);
//
//	for (int i = 0; i < 10; i++)
//		pts_end[i].setLegacy(&rdiP->pts_end[i], bChangeSelf);
//
//}



void reininfo::clear()
{
	//ZeroMemory(&option, sizeof(option));
	option.clear();
	option.resize(20);

	lim = 0;
	ends = 0;
	bface = 0;
	run = 0;
	ttip = 0;
	bars = 0;
	b3d = 0;
	nodes = 0;
	threads = 0;

	rsVal.clear();
	rsOpt.clear();

	rcUnit.clear();
	//ZeroMemory(&aInfo, sizeof(aInfo));
}

reininfo::reininfo()
{
	clear();
}

//void reininfo::setLegacy(_ReinInfo* rdiP, bool bChangeSelf)
//{
//	if (bChangeSelf)
//	{
//		option = rdiP->option;
//		//CopyMemory(option, rdiP->option, sizeof(option));
//		lim = rdiP->lim;
//		ends = rdiP->ends;
//		bface = rdiP->bface;
//		run = rdiP->run;
//		ttip = rdiP->ttip;
//		bars = rdiP->bars;
//		b3d = rdiP->b3d;
//		nodes = rdiP->nodes;
//		threads = rdiP->threads;
//		//CopyMemory(&aInfo, &rdiP->aInfo, sizeof(aInfo));
//	}
//	else
//	{
//		rdiP->option = option;
//		rdiP->lim = lim;
//		rdiP->ends = ends;
//		rdiP->bface = bface;
//		rdiP->run = run;
//		rdiP->ttip = ttip;
//		rdiP->bars = bars;
//		rdiP->b3d = b3d;
//		rdiP->nodes = nodes;
//		rdiP->threads = threads;
//		//CopyMemory(&rdiP->aInfo, &aInfo, sizeof(aInfo));
//	}
//
//	rsVal.setLegacy(&rdiP->rsVal, bChangeSelf);
//	rsOpt.setLegacy(&rdiP->rsOpt, bChangeSelf);
//	rcUnit.setLegacy(&rdiP->rcUnit, bChangeSelf);
//
//}


void specline::clear(void)
{
	mdlVec_zero(&arp[0]);
	mdlVec_zero(&arp[1]);
	lev = 0;
	ggn = 0;
	smb.color = 0;
	smb.style = 0;
	smb.weight = 0;
}

specline::specline(void)
{
	clear();
}


void spectext::clear(void)
{
	mdlVec_zero(&p);
	lev = 0;
	ggn = 0;
	smb.color = 0;
	smb.style = 0;
	smb.weight = 0;
	maxwidth = 0.;

	wcscpy(txt, L"");

	//ZeroMemory(&tsp, sizeof(tsp));
	tsp.aspectRatio = 0.;
	tsp.mode = 0;
	tsp.size.height = 0.;
	tsp.size.width = 0.;

	short lnln = 0;


#if defined (MSVERSION) && (MSVERSION == 0xa00)
	tp.Initialize();
#else
	mdlTextStyle_getTextParamWideFromTCB(&tp, &tsp.size.width, &tsp.size.height, &lnln, 0);
#endif
}

/*
_TextParamWide::_TextParamWide(void)
{
	clear();
}

void _TextParamWide::clear(void)
{
	m.annotationScale = 0.;
	m.assocId = 0;
	m.backgroundBorder.x = 0.;
	m.backgroundBorder.y = 0.;
	m.backgroundColor = 0;
	m.backgroundFillColor = 0;
	m.backgroundStyle = 0;
	m.backgroundWeight = 0;
	m.characterSpacing = 0.;
	m.codePage_deprecated = 0;
	m.color = 0;
	//m.exFlags...
	//m.flags
	m.font = 0;
	m.
}
*/

spectext::spectext(void)
{
	clear();
}


void reinvertvec::clear(void)
{
	mdlVec_zero(&tdir);
	mdlVec_zero(&tnorm);
}

reinvertvec::reinvertvec(void)
{
	clear();
}



void reinvert::clear(void)
{
	rvv.clear();

	mdlVec_zero(&torg);

	mrp = NULL;
	isin = 0;
	pmqty = 0;
	mpar = 0;
	mdiam[0] = 0;
	mdiam[1] = 0;
	fps = 0;
	mblap = 0;
	errors = 0;
	dpth = 0.0;
}

reinvert::reinvert(void)
{
	clear();
}

void reinsegm::clear(void)
{
	rv[0].clear();
	rv[1].clear();

	mdlVec_zero(&sgmcent);
	mdlVec_zero(&numpt);
	mdlVec_zero(&numpt2);
	mdlVec_zero(&pSec);

	bOutOfClip = 0;
	sgmrad = 0;
	bSec = 0;
}

reinsegm::reinsegm(void)
{
	clear();
}


void reinpoint::clear(void)
{
	mdlVec_zero(&rpt);
	mdlVec_zero(&cent);
	rfa = 0;
}
void reinpoint::set(DVec3d p)
{
	clear();
	rpt = p;
}

void reinpoint::set(DVec3d p, long f)
{
	clear();
	rpt = p;
	rfa = f;
}

void reinpoint::set(DVec3d p, DVec3d c, long f)
{
	clear();
	rpt = p;
	cent = c;
	rfa = f;
}


reinpoint::reinpoint(void)
{
	clear();
}

reinpoint::reinpoint(DVec3d p)
{
	set(p);
}

reinpoint::reinpoint(DVec3d p, long f)
{
	set(p, f);
}


reinbar::reinbar(void)
{
	//termPar.resize(10);
	blen.resize(MAX_BAR_LENS);
	brad.resize(MAX_BAR_LENS);
	bang.resize(MAX_BAR_LENS);

	clear(); // memory reserve for points
}

void reinbar::lenclear(void)
{
	numlen = 0;

	vecAllocLong(&blen, 3);
	//ZeroMemory(blen, sizeof(blen));

	brad.clear();
	brad.resize(MAX_BAR_LENS);
	//ZeroMemory(brad, sizeof(brad));

	bang.clear();
	bang.resize(MAX_BAR_LENS);
	//for (int i = 0; i < MAX_BAR_LENS; i++) bang[i] = 0;
}

void reinbar::vecclear(bool bResize)
{
	numpts = 0;

	//if (bResize) 
	//	vecAllocInt(&termPar, 2); 
	//else 
	//	vecAllocInt(&termPar, 0);


	//ZeroMemory(apts, sizeof(apts));
	//ZeroMemory(cpxb, sizeof(cpxb));
	//ZeroMemory(cpxe, sizeof(cpxe));
	//ZeroMemory(rpts, sizeof(rpts));
	//ZeroMemory(cents, sizeof(cents));
	//ZeroMemory(rfa, sizeof(rfa));

	//vpt.clear();

	//apts.clear();
	//cpxb.clear();
	//cpxe.clear();
	//rfa.clear();
	//rpts.clear();
	//cents.clear();
}

void reinbar::clear(int memres)
{
	modrefP = NULL;

	bent[0].clear();
	bent[1].clear();

	lenclear();

	ffpos[0] = 0;
	ffpos[1] = 0;
	ffpos[2] = 0;
	ffpos[3] = 0;
	ffpos[4] = 0;

	lap[0] = 0;
	lap[1] = 0;
	lap[2] = 0;

	term[0] = 0;
	term[1] = 0;

	for (int i = 0; i < MAX_BAR_VERTICES; i++)
		sgts[i].clear();

	for (int i = 0; i < 10; i++)
	{
		termPar[i][0] = 0;
		termPar[i][1] = 0;
	}

	numsgts = 0;

	elemid = 0;
	axid = 0;
	brid = 0;
	bartype = 0;
	contnum = 0;
	numpts = 0;
	cnumpts = 0;

	length = 0.;

	diam = 0;
	space = 0;
	spacerad = 0;
	offset[0] = 0; // для построения на SURFACE_ELM
	offset[1] = 0; // для построения на SURFACE_ELM
	bendrad = 0;
	poscalc = 0; // набор позиций для их разделения в списке
	pnum = 0;
	runmet = 0;
	transp = 0; // transparency (inner/outer)
	segmIndex = 0; // индекс сегмента (0-based) для оси стержня
	elemEDoffset = 0; // MSElementDescr offset (получаем при указании на элемент) для оси стержня
	mainSgmIndex = 0; // индекс главного сегмента,  // будет использоваться когда в контроле будет арка в сегменте
	mainPtsIndex = 0; // индекс начальной точки главного сегмента (может плыть относительно mainSgmIndex)
	ilaps = 0; // дополнительный нахлест
	numRef = 0;
	inum = 0;
	isgmnum = 0;
	noplanar = 0;
	barflags = 0;
	grnd = false;

	mdlVec_zero(&v_enrm);
	mdlVec_zero(&v_pnrm);

	vecclear(true);

	if (memres)
	{
		//apts.reserve(memres); // точки для отрисовки 2D с учетом mainline (точка арки пока не на элементе)
		//cpxb.reserve(memres); // x compare points (from begin)
		//cpxe.reserve(memres); // x compare alternative points (from end)
		//rfa.reserve(memres); // флаг, указывающий на то что точка принадлежит арке
		//rpts.reserve(memres); // реальные точки стержня
		//cents.reserve(memres); // центры дуговых сегментов (если есть)
	}


}

reinbar::~reinbar(void)
{
	vecclear(false);
}


reinclash::reinclash(void)
{
	clear();
}

void reinclash::clear(void)
{
	iShtamp = 0;
	fpElem[0] = 0;
	fpElem[1] = 0;
	idElem3d[0] = 0;
	idElem3d[1] = 0;
	lvID[0] = LEVEL_NULL_ID;
	lvID[1] = LEVEL_NULL_ID;
	cdiam[0] = 0.;
	cdiam[1] = 0.;
	idist = 0;
	erefClsh = NULL;
	mdlVec_zero(&pt);
	//tedLnP = NULL;
	//tedPtP = NULL;
}


reincache::reincache(void)
{
	irefnum = 0;
	refpath = L"";
	elid = 0;
	mrP = NULL;
	pnum = 0;
	wcscpy(desc, L"");
}



//int reinelm::readFromString(wstring str, DgnModelRefP mrP)
//{
//	return readReinElmFromString(this, str, mrP);
//}



void reinaxis::clear(void)
{
	eleid = 0;
	inum = 0;
}

reinaxis::reinaxis(void)
{
	clear();
}


void reinpos::clear()
{
	bar.clear();
	bar_mem.clear();
	arefnum.clear();
	//ZeroMemory(arefnum, sizeof(arefnum));

	drawmode = 0; // опция отображения
	posID = 0;
	srtmID = 0;

	base_length = 0;
	base_qty = 0.;
	base_ms_min = 0;
	base_ms_max = 0;
	base_ms_mid = 0;

	file_length = 0;
	file_qty_p = 0;
	file_qty_rm = 0.;
	file_ms_min = 0;
	file_ms_max = 0;
	file_ms_mid = 0;

	bFromRef = false; // for show
	lap_qty = 0; // количество перехлестов
	muft_qty[0] = 0; // муфты или скобы, количество
	muft_qty[1] = 0; // муфты или скобы, количество
	pdID = 0; // posdefID
	pcatID = 0;

	pnum_cnd = 0;
	mapind = 0;

	//ZeroMemory(drawopt, sizeof(drawopt)); // опции отображения
	drawopt.clear();
	drawopt.resize(10);

	for (int i = 0; i < 5; i++) cmpopt[i] = 0;
	//ZeroMemory(cmpopt, sizeof(cmpopt));
}

reinpos::reinpos(void)
{
	drawopt.resize(10);

	clear();
}

reinpos::~reinpos(void)
{
	bar.clear();
	//arefnum.clear();
}


reinnote::reinnote(void)
{
	clear();
}

reinnote::~reinnote(void)
{
	clear();
}

void reinnote::clear()
{
	vBars.clear();
	mapNotePos.clear();
	SCPY(sNoteFmt, L(""));
	mdlVec_zero(&arNotePts[0]);
	mdlVec_zero(&arNotePts[1]);
	mdlVec_zero(&arNotePts[2]);
	mdlVec_zero(&arNotePts[3]);
	iNoteGGN = 0;
	iNoteLevID = LEVEL_NULL_ID;
	ielem = -1;
	bUpdate = false;
}


void catinfo::clear()
{
	projID = 0;
	catID = 0;
	catModID = 0;
	SCPY(dbase, L(""));
	SCPY(catname, L(""));
	SCPY(catmodname, L(""));
	SCPY(catfullname, L(""));
	bAutoCats = FALSE;
}

catinfo::catinfo()
{
	clear();
}


void reinprm::clear()
{
	lev = LEVEL_NULL_ID;

	bDel = 0;
	prmid = 0;

	mdlVec_zero(&pVec);

	for (int i = 0; i < MAX_REFNUM_PATH; i++) uival[i] = 0;
	for (int i = 0; i < 10; i++) ival[i] = 0;
	for (int i = 0; i < 10; i++) dval[i] = 0.;
	for (int i = 0; i < 10; i++) cnt[i] = 0;
	for (int i = 0; i < 10; i++) lval[i] = 0;

	SCPY(sval, L(""));
	wstr = L"";

	reP = NULL;

	mapprm.clear();
	sids.clear();
	slng.clear();
	vsnaps.clear();
	uints.clear();

	edP = NULL;
}

reinprm::reinprm()
{
	clear();
}

reinindex::reinindex()
{
	inplace = false;
	rei = 0;
}

void ReinModel::Init()
{
	modelP = NULL;
	//rmParentP = NULL;

	iClipVerts = 0;

	for (int a = 0; a < 2; a++)
	{
		for (int b = 0; b < 100; b++)
			mdlVec_zero(&arClipPts[a][b]);
	}

	elcount = 0;
	refscale = 1.0;
	iPosQty = 0;
	bCached = false;
	bRefPlus = false;

	refPrefsP = NULL;
	refPrefs.clear();
	//ZeroMemory(&refPrefs, sizeof(refPrefs));

	rnum = 0;


	arCurPos.clear();
	iPosIndex = -100;

	arMrP.clear();

	mapElms.clear();
	mapBars.clear();

	vExIds.clear();
	vExFps.clear();

	SCPY(rmname, L(""));

	if (tedSecP && mdlTransient_isValid(tedSecP))
	{
		mdlTransient_free(&tedSecP, 0);
	}
	tedSecP = NULL;

}

ReinModel::ReinModel()
{
	Init();
}

//////////////////////////////////////////
size_t ReinModel::getRefPath(deque<UInt32>* ar)
{

	int i = 0;
	UInt32 prm = rnum; // ref number of  current ReinModel

	if (ar == NULL) return 0;
		
	ar->clear();

	if (mdlModelRef_isActiveModel(modelP)) return 0;
	if (rnum == 0) return 0; // active

	ar->push_back(rnum);

	//rfP->file_id.providerID - projectwise path and doc guid

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ref file

	DgnAttachmentCP rfP;
	rfP = mdlRefFile_getInfo(modelP);
	if (rfP == NULL) return 0;

	DgnModelRefP mrParentP = rfP->GetParentModelRefP();

	while (mrParentP)
	{
		if (mdlRefFile_getIntegerParameters(&prm, REFERENCE_REFNUM, mrParentP) == SUCCESS)
		{
			ar->push_back(prm);
		}
		else
			break;

		rfP = mdlRefFile_getInfo(mrParentP);

		mrParentP = rfP->GetParentModelRefP();
	}

#else

	ReferenceFile* rfP;
	rfP = mdlRefFile_getInfo(modelP);
	if (rfP == NULL) return 0;

	ReferenceFile* rpP = mdlRefFile_getParent(rfP);

	while (rpP)
	{
		if (mdlRefFile_getParameters(&prm, REFERENCE_REFNUM, rpP->file_id.modelRef) == SUCCESS)
		{
			ar->push_back(prm);
		}
		else
			break;

		rpP = mdlRefFile_getParent(rpP);
	}
#endif


	return ar->size();
}

/////////////////////////////////////////
wstring ReinModel::getRefPathString(deque<UInt32>* arefP)
{

	wstring ws = L"";

	deque<UInt32> aref;

	if (arefP == NULL)
	{
		getRefPath(&aref);
		arefP = &aref;
	}


	MSWCH  locstr[50];

	for (deque<UInt32>::reverse_iterator it = arefP->rbegin(); it != arefP->rend(); ++it)
	{
		_swprintf(locstr, L"%u", *it);
		if (ws.length() > 0) ws.append(L"-");
		ws.append(locstr);
	}

	if (ws.length() > 0)
		return ws;
	else
		return L"0";



}



/*
//////////////////////////////////////////
// возвращает обратный путь, для рефа 5->3->7 массив: [0] = 7, [1] = 3, [2] = 5
int ReinModel::getRefPath(UInt32* ar) // 
{
	int i = 0;
	UInt32 prm = rnum; // ref number of  current ReinModel

	//ZeroMemory(ar, sizeof(curPos.arefnum));

	if (mdlModelRef_isActiveModel(modelP)) return 0;
	if (rnum == 0) return 0; // active

	ar[i++] = rnum;

	//rfP->file_id.providerID - projectwise path and doc guid

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ref file

	DgnAttachmentCP rfP;
	rfP = mdlRefFile_getInfo(modelP);
	if (rfP == NULL) return 0;

	DgnModelRefP mrParentP = rfP->GetParentModelRefP();

	while (mrParentP)
	{
		if (mdlRefFile_getIntegerParameters(&prm, REFERENCE_REFNUM, mrParentP) == SUCCESS)
			ar[i++] = prm;
		else
			break;

		rfP = mdlRefFile_getInfo(mrParentP);

		mrParentP = rfP->GetParentModelRefP();
	}

#else

	ReferenceFile* rfP;
	rfP = mdlRefFile_getInfo(modelP);
	if (rfP == NULL) return 0;

	ReferenceFile* rpP = mdlRefFile_getParent(rfP);

	while (rpP)
	{
		if (mdlRefFile_getParameters(&prm, REFERENCE_REFNUM, rpP->file_id.modelRef) == SUCCESS)
			ar[i++] = prm;
		else
			break;

		rpP = mdlRefFile_getParent(rpP);
	}
#endif


	return i;

}
*/

/*
//////////////////////////////////////////////////
void ReinModel::getRefPath(vector<UInt32> &path) // отказались от векторов тк подозрение на вылет в коннекте
{

	//writeLogIn(__FUNCTION__, 0);

	path.clear();

	if (rnum == 0) return; // active

	path.push_back(rnum);

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ref file
	DgnAttachmentCP rfP;

	rfP = mdlRefFile_getInfo(modelP);

	if (rfP == NULL) return;

	DgnModelRefP mrParentP = rfP->GetParentModelRefP();

	//DgnAttachmentCP rpP = mdlRefFile_getParent(rfP);

	while (mrParentP)
	{

		UInt32 prm;

		if (mdlRefFile_getIntegerParameters(&prm, REFERENCE_REFNUM, mrParentP) == SUCCESS)
			path.insert(path.begin(), prm);
		else
			break;

		//rpP = mdlRefFile_getParent(rpP);

		rfP = mdlRefFile_getInfo(modelP);

		mrParentP = rfP->GetParentModelRefP();

	}
#else
	ReferenceFile* rfP;

	rfP = mdlRefFile_getInfo(modelP);

	//rfP->file_id.providerID - projectwise path and doc guid

	if (rfP == NULL) return;

	ReferenceFile* rpP = mdlRefFile_getParent(rfP);

	while (rpP)
	{

		UInt32 prm;

		if (mdlRefFile_getParameters(&prm, REFERENCE_REFNUM, rpP->file_id.modelRef) == SUCCESS)
			path.insert(path.begin(), prm);
		else
			break;

		rpP = mdlRefFile_getParent(rpP);

	}


#endif

	//writeLogOut(__FUNCTION__, 0);

}
*/



/////////////////////////////////////////
UInt32 ReinModel::getExFpCount(int iDpth)
{
	UInt32 icnt = 0;

	for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); it != arMrP.end(); ++it)
	{
		icnt = icnt + it->second.getExFpCount(iDpth - 1);
	}

	for (map<UInt32, bool>::iterator it = vExFps.begin(); it != vExFps.end(); ++it)
	{
		if (it->second) icnt++;
	}

	//return icnt + (UInt32)vExFps.size();
	return icnt;
}

/////////////////////////////////////////////
UInt32 ReinModel::getExIdCount(int iDpth)
{
	UInt32 icnt = 0;

	for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); it != arMrP.end(); ++it)
	{
		icnt = icnt + it->second.getExIdCount(iDpth - 1);
	}

	for (map<ELID, bool>::iterator it = vExIds.begin(); it != vExIds.end(); ++it)
	{
		if (it->second) icnt++;
	}

	//return icnt + (UInt32)vExIds.size();
	return icnt;
}

/////////////////////////////////////////
UInt32 ReinModel::getElemCount(int iDpth) // -1 unlimited
{
	UInt32 icnt = 0;

	writeLogIn(__FUNCTION__, 0);

	for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); iDpth != 0 && it != arMrP.end(); ++it)
		//for (int i = 0; iDpth != 0 && i < MAX_REF_SLOT; i++)
	{
		icnt = icnt + it->second.getElemCount(iDpth - 1);
	}

	if (iDebug) sprintf(sLogMes, "return %i+%i = %i\n", icnt, elcount, icnt + elcount); writeLog(0, 0);
	writeLogOut(__FUNCTION__, 0);


	return icnt + elcount;
}


////////////////////////////////////////
//  ===== ReinModel CONSTRUCTOR ===== //
////////////////////////////////////////
void ReinModel::Init(DgnModelRefP mrP, long reinelemcnt)
{
	Init();

	modelP = mrP;

	writeLogIn(__FUNCTION__, 0);
	if (iDebug) sprintf(sLogMes, "reinelem cnt = %i\n", reinelemcnt); writeLog(0, 0);

	if (mdlRefFile_getDoubleParameters(&refscale, REFERENCE_SCALE, mrP) != SUCCESS)
		refscale = 1.0;

	//rmParentP = rmPrntP;

	if (mdlModelRef_isActiveModel(mrP))
		mdlModelRef_getFileName(mrP, rmname, 500); // берет неправильное имя если референс выключен

	//if (rnum == 2)
	//	int a = 0;

#if defined (MSVERSION) && (MSVERSION == 0x8b0) // in future

	ReferenceFileP rfP = mdlRefFile_getInfo(mrP);
	if (rfP)
	{
		rnum = getRefNum(mrP);

		// получение плоскостей клипа
		// железный алгоритм, потрачено несколкьо дней

		SCPY(rmname, rfP->file_id.fullFileSpec);

		if (iDebug) sprintf(sLogMes, "get clip planes...\n"); writeLog(0, 0);

		DVec3d pz[2];
		DVec3d org[3];
		RotMatrix rm;
		DVec3d pts[2][100];

		for (int a = 0; a < 2; a++)
		{
			for (int b = 0; b < 100; b++)
				mdlVec_zero(&pts[a][b]);
		}

		// эксперименты...
		if (mdlSystem_getCfgVar(0, L("REIN_REF_CLIPVOLUME"), 0) == SUCCESS)
		{
			ELID viewid = 0;
			int st = mdlRefFile_getParameters(&viewid, REFERENCE_SAVEDVIEWELEMENTID, mrP); // 18087912+ 18087885-

			if (st == SUCCESS && viewid > 0)
			{

				Transform tmSheet;

				st = mdlTMatrix_masterToReference(&tmSheet, mrP);

				//rfP->display.

				if (st == SUCCESS)
				{

					MSWChar vname[100];

					ElementRef eref = dgnCache_findElemByID(mdlModelRef_getCache(mrP), viewid);


					if (eref)
					{
						DVec3d   origin;
						DVec3d   delta;
						DVec3d   target;
						DVec3d   zer;
						DVec3d   nrm;
						double  dZ[2] = { 0. };
						ViewFlags  flags;
						RotMatrix rm;
						UInt32 ptsqty;
						DPoint2d cp[10];
						BINT b[2];


						MSElementDescr* edpRS = NULL;
						CLIPDESC cdP = NULL;

						//mdlElement_read(&elShape, mrP, elementRef_getFilePos(eref));

						//mdlElmdscr_getByElemRef(&edpRS, eref, mrP, FALSE, 0);

						//if (mdlLinkage_getClipBoundaryLinkage(&rm, &origin, &b[0], &dZ[0], &b[1], &dZ[1], &ptsqty, cp, 10, &elShape) == SUCCESS)
						//if (edpRS && mdlClip_fromElement(&cdP, edpRS, 1, 0, 0) == SUCCESS)
						//{
						//	if (edpRS)
						//		mdlElmdscr_freeAll(&edpRS);
						//}


						ElementRef erefs[100];

						int numdep = mdlDependency_getDependentElementRefs(erefs, viewid, mrP, 100);

						for (int i = 0; i < numdep; i++)
						{
							//ELID id = elementRef_getElemID(erefs[i]);

							//mdlElement_read(&elShape, mrP, elementRef_getFilePos(erefs[i]));

							//if (mdlLinkage_getClipBoundaryLinkage(&rm, &origin, &b[0], &dZ[0], &b[1], &dZ[1], &ptsqty, cp, 10, &elShape) == SUCCESS)

							//Bentley::Ustn::Element::ElemHandle elh(&elShape, mrP);

							//Bentley::Ustn::IViewClipObject vo;

							//st = vo.FromElement(elh);

							//co.GetClipObject(elh);


							//if (st == SUCCESS)
							//{
							//	int a = vo.GetNumPoints();
							//	double sz = vo.GetWidth();
							//}

							//======================================

							//mdlElmdscr_getByElemRef(&edpRS, erefs[i], mrP, FALSE, 0);
							//if (edpRS)
							//{

							//	if (mdlClip_fromElement(&cdP, edpRS, 1, 0, 0) == SUCCESS)
							//	{
							//		mdlClip_free(&cdP);
							//	}

							//	mdlElmdscr_freeAll(&edpRS);

							//}

						}






						{
							MSElementDescr* edNamedViewP = NULL;
							mdlElmdscr_getByElemRef(&edNamedViewP, eref, mrP, FALSE, 0);

							if (edNamedViewP)
							{
								//ViewInfoP viP = NULL;

								mdlVec_zero(&target);

								int st = mdlView_extractNamedView(vname, 0, 0, &origin, &delta, &dZ[0], &flags, &rm, 0, edNamedViewP);

								mdlRMatrix_getInverse(&rm, &rm);

								mdlRMatrix_multiplyPoint(&delta, &rm);

								mdlVec_add(&delta, &delta, &origin);

								//if (mdlView_extractElmdscr(&viP, 0, edP) == SUCCESS)
								//{
								//	mdlViewInfo_getActiveZ (&activeZ, viP);
								//	
								//	mdlViewInfo_free(&viP);
								//}

								mdlVec_zero(&zer);

								//mdlRMatrix_getRowVector(&nrm, &rm, 2);
								mdlRMatrix_getColumnVector(&nrm, &rm, 2);

								mdlVec_projectPointToPlane(&target, &zer, &delta, &nrm);

								//dShift = mdlVec_magnitude(&target);

								if (st == SUCCESS)
								{
									//sprintf(s, "Prepare print ready, saved view: %S, point on sec plane %.0f,%.0f,%.0f, shift=%.0f", vname
									//	, mdlCnv_uorsToMasterUnits(target.x)
									//	, mdlCnv_uorsToMasterUnits(target.y)
									//	, mdlCnv_uorsToMasterUnits(target.z)
									//	, mdlCnv_uorsToMasterUnits(dShift)
									//);

									//sprintf(s, "Prepare print ready, saved view: %S", vname 
									//	);
								}
								else
								{
									//sprintf(s, "Prepare print ready, but cannot get view properties", vname);
								}

								//mdlOutput_messageCenter(MESSAGE_INFO, s, s, 0);


								mdlElmdscr_freeAll(&edNamedViewP);
							}
							//else
							//	mdlOutput_messageCenter(MESSAGE_WARNING, "Prepare print warning: cannot read view element", "", 0);
						}




					}
					//else
					//	mdlOutput_messageCenter(MESSAGE_WARNING, "Prepare print warning: cannot find view element by id", "", 0);


				}

			}
		}


		if (rfP->clip.clip_vertices > 0)
		{
			/*
			DRange3d r3d;
			double dist;

			Transform tmSheet;
			RotMatrix rm;


			mdlTMatrix_referenceToMaster(&tmSheet, mrP);

			mdlRMatrix_fromTMatrix(&rm, &tmSheet);

			int res = Bentley::Ustn::DetailingSymbolManager::ComputeCalloutClipExtentsFromReference(r3d, &dist, rm, mrP);
			if (res == SUCCESS)
			{
				mdlVec_fromDPoint3d(&pz[0], &r3d.low);
				mdlVec_fromDPoint3d(&pz[1], &r3d.high);

				mdlLine_create(&elShape, &c3w9s0, pz);
				mdlTransient_addElement(0, &elShape, 1, 0x00ff, DRAW_MODE_Normal, 0, 1, 1);
			}*/


			//printf("-----------------\n");
			for (int i = 0; i < rfP->clip.clip_vertices && iClipVerts < 100; i++)
			{
				//printf("%f %f \n", rfP->clip.clipP[i].x, rfP->clip.clipP[i].y);
				mdlVec_fromXY(&pts[0][iClipVerts], rfP->clip.clipP[i].x, rfP->clip.clipP[i].y);
				mdlVec_fromXY(&pts[1][iClipVerts], rfP->clip.clipP[i].x, rfP->clip.clipP[i].y);
				iClipVerts++;
			}


			// раздвигаем плоскости
			mdlVec_fromXYZ(&pz[0], 0., 0., rfP->clip.zFront);
			mdlVec_fromXYZ(&pz[1], 0., 0., rfP->clip.zBack);

			mdlVec_addPointArray(pts[0], &pz[0], iClipVerts);
			mdlVec_addPointArray(pts[1], &pz[1], iClipVerts);

			// масштабируем
			for (int i = 0; i < iClipVerts; i++)
			{
				mdlVec_scaleInPlace(&pts[0][i], 1. / rfP->display.scale);
				mdlVec_scaleInPlace(&pts[1][i], 1. / rfP->display.scale);
			}

			// поворачиваем клип
			rm = rfP->clip.rotation;
			//mdlRMatrix_getInverse(&rm, &rfP->clip.rotation);
			mdlRMatrix_multiplyPointArray(pts[0], &rm, iClipVerts);
			mdlRMatrix_multiplyPointArray(pts[1], &rm, iClipVerts);

			// получаем смещения (org[2] - которое можно менять в окошке референсов)
			mdlVec_fromXYZ(&org[0], rfP->display.mast_org.x, rfP->display.mast_org.y, rfP->display.mast_org.z);
			mdlVec_fromXYZ(&org[1], rfP->display.ref_org.x, rfP->display.ref_org.y, rfP->display.ref_org.z);
			mdlRMatrix_multiplyPoint(&org[1], &rfP->display.trns_mtrx);
			mdlVec_subtract(&org[2], &org[1], &org[0]);

			// смещаем
			mdlVec_addPointArray(pts[0], &org[2], iClipVerts);
			mdlVec_addPointArray(pts[1], &org[2], iClipVerts);

			mdlVec_addPointArray(pts[0], &org[0], iClipVerts);
			mdlVec_addPointArray(pts[1], &org[0], iClipVerts);

			// двигаем
			//if (rfP->display.fd_opts.rotateClipping)
			{
				mdlRMatrix_getInverse(&rm, &rfP->display.trns_mtrx);

				mdlRMatrix_multiplyPointArray(pts[0], &rm, iClipVerts);
				mdlRMatrix_multiplyPointArray(pts[1], &rm, iClipVerts);
			}

			//mdlShape_create(&elShape, &c3w9s0, pts[0], iClipVerts, 0);
			//mdlTransient_addElement(0, &elShape, 1, 0x00ff, DRAW_MODE_Normal, 0, 1, 1);
			//mdlShape_create(&elShape, &c3w9s0, pts[1], iClipVerts, 0);
			//mdlTransient_addElement(0, &elShape, 1, 0x00ff, DRAW_MODE_Normal, 0, 1, 1);
		}

		int b = 0;
		for (int a = 0; b < iClipVerts && a < 2; a++)
		{
			for (int b = 0; b < 100; b++)
				arClipPts[a][b] = pts[a][b];
		}

		if (iDebug) sprintf(sLogMes, "got %i clip planes\n", iClipVerts); writeLog(0, 0);

	}

#else

	DgnAttachmentP rfP = mdlRefFile_getInfo(mrP);

	if (rfP && rfP->IsClipped())
	{
		ELID id = rfP->GetClipElementId();
		ELREF eref = getElemRefByID(mrP, id);

		MSElementDescrP       edP = NULL;
		mdlElmdscr_getByElemRef(&edP, eref, mrP, FALSE, 0);

		mdlElmdscr_freeAll(&edP);


	}

#endif

	mdlFile_parseName(rmname, 0, 0, rmname, 0);


	if (reinelemcnt < 0)
	{
		if (iDebug) sprintf(sLogMes, "go to count ReinElms with reset...\n"); writeLog(0, 0);

		getReinElmCount(TRUE, mrP, &elcount); // fpmax

	}
	else
		elcount = reinelemcnt; // заранее посчитано

	if (iDebug) sprintf(sLogMes, "elcount = %u\n", elcount); writeLog(0, 0);


	//if (elcount > 0)
	//{
	//	UInt32 fpmx = mdlModelRef_getEof (mrP);
	//	if (fpmx >= FILEPOS_LOC) indmax = fpmx - FILEPOS_LOC;
	//}


	//sprintf(sLogMes, "indmax = %u\n", indmax); writeLog(0, 0);


	DgnModelRefP  modelRef;
	ModelRefIteratorP  iterator;

	// выключенные референсы также грузить (или вкл. галку в опциях)
	// если включена развертка то всегда грузить референсы
	if (getCfgVar(NULL, L("RONDO_APP_VERSION")) == SUCCESS)
		mdlModelRef_loadReferenceModels(mrP, 1, 1, 1);

	mdlModelRefIterator_create(&iterator, mrP, MRITERATE_PrimaryChildRefs, 0);

	// создание структуры всех референсов (каскадом)
	if (iDebug) sprintf(sLogMes, "creating inner ReinModels...\n"); writeLog(0, 0);

	while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
	{
		UInt32 elcnt = 0;
		UInt32 rn = getRefNum(modelRef);

		if (iDebug) sprintf(sLogMes, "ref %u, getReinElmCount with reset...\n", rn); writeLog(0, 0);

		getReinElmCount(TRUE, modelRef, &elcnt);

		if (iDebug) sprintf(sLogMes, "elcnt = %u\n", elcnt); writeLog(0, 0);

		//if (elcnt > 0) // мастера могут быть без арматуры
		{

			if (iDebug) sprintf(sLogMes, "new ReinModel(%u)...\n", elcnt); writeLog(0, 0);

			//arMrP[rn] = new ReinModel(modelRef, elcnt, this); // происходит отработка конструктора

			ReinModel rm(modelRef, elcnt);
			arMrP.insert(pair<UInt32, ReinModel>(rn, rm));

			if (iDebug) sprintf(sLogMes, "new ReinModel allocated\n"); writeLog(0, 0);

			//fpmx = mdlModelRef_getEof (modelRef); // делает в конструкторе
			//if (fpmx >= FILEPOS_LOC) arMrP[rn]->indmax = fpmx - FILEPOS_LOC;

			//testing path string
			//wstring ws = arMrP[rn].getRefPathString();
			//ReinModel* rmP = curRM->getRM(ws);
			//printf("%u   %u   %S   %u   %s\n", rn, rm.rnum, ws.c_str(), rmP->rnum, rmP->rmname);

		}

	}

	if (iDebug) sprintf(sLogMes, "end creating inner ReinModels\n"); writeLog(0, 0);

	mdlModelRefIterator_free(&iterator);

	// reserve memory
	//if (elcount < 1000)
	//	vecElms.reserve(2000);
	//else
	//	vecElms.reserve(elcount * 2);


	writeLogOut(__FUNCTION__, 0);


}

/////////////////////////////////////////////////////////
ReinModel::ReinModel(DgnModelRefP mrP, long reinelemcnt)
{
	Init(mrP, reinelemcnt);
}


///////////////////////////////
ReinModel::~ReinModel(void)
{

	//if (w)
	//{
	//	mapElms.clear();
	//	vecElms.clear();
	//	vExIds.clear();
	//	vExFps.clear();
	//	delete w;
	//}

	writeLogIn(__FUNCTION__, 0);

	//for (int i = 0; i < MAX_REF_SLOT; i++)
	//for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); it != arMrP.end(); ++it)
	//{
	//	sprintf(sLogMes, "delete arMrP[%i]...\n", i); writeLog(0, 0);
	//	it->second.arMrP.clear();
	//}

	arMrP.clear();


	arCurPos.clear(); //x


//	if (updb)
//		upst = ups_db_close(updb, 0);

	//if (arRefPrefs) delete arRefPrefs;
	refPrefsP = NULL;

	if (tedSecP && mdlTransient_isValid(tedSecP))
	{
		mdlTransient_free(&tedSecP, 0);
	}
	tedSecP = NULL;

	if (iDebug) sprintf(sLogMes, "clear exclude vectors...\n"); writeLog(0, 0);
	vExIds.clear();
	vExFps.clear();

	//mapClash.clear();

	writeLogOut(__FUNCTION__, 0);

}

///////////////////////////////////////////
ReinModel* ReinModel::getRM(DgnModelRefP mrP)
{
	ReinModel* rmRetP = NULL;

	if (mrP == NULL) return NULL;

	if (mrP == modelP) return this;

	for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); it != arMrP.end(); ++it)
		//for (int i = 0; i < MAX_REF_SLOT; i++)
	{
		if (it->second.modelP == mrP)
		{
			rmRetP = &it->second;
		}

		if (rmRetP) break;
	}

	if (rmRetP == NULL)
	{
		for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); it != arMrP.end(); ++it)
			//for (int i = 0; i < MAX_REF_SLOT; i++)
		{
			rmRetP = it->second.getRM(mrP);

			if (rmRetP) break;
		}
	}


	return rmRetP;
}

//void barpoint::setLegacy(_BarPoint* rdiP, bool bChangeSelf)
//{
//	if (bChangeSelf)
//	{
//		pVrtx = rdiP->pVrtx;
//		pVrtxNext = rdiP->pVrtxNext;
//		pDirX = rdiP->pDirX;
//		pDirY = rdiP->pDirY;
//		pDirZ = rdiP->pDirZ;
//		pArcCent = rdiP->pArcCent;
//		pArcPts[0] = rdiP->pArcPts[0];
//		pArcPts[1] = rdiP->pArcPts[1];
//		pElPoint = rdiP->pElPoint;
//		pEndPoint = rdiP->pEndPoint;
//
//		bend_ang = rdiP->bend_ang;
//		bend_len = rdiP->bend_len;
//		flg = rdiP->flg;
//		nmb = rdiP->nmb;
//		bnd = rdiP->bnd;
//	}
//	else
//	{
//		rdiP->pVrtx = pVrtx;
//		rdiP->pVrtxNext = pVrtxNext;
//		rdiP->pDirX = pDirX;
//		rdiP->pDirY = pDirY;
//		rdiP->pDirZ = pDirZ;
//		rdiP->pArcCent = pArcCent;
//		rdiP->pArcPts[0] = pArcPts[0];
//		rdiP->pArcPts[1] = pArcPts[1];
//		rdiP->pElPoint = pElPoint;
//		rdiP->pEndPoint = pEndPoint;
//
//		rdiP->bend_ang = bend_ang;
//		rdiP->bend_len = bend_len;
//		rdiP->flg = flg;
//		rdiP->nmb = nmb;
//		rdiP->bnd = bnd;
//	}
//}

//////////////////////////////////////////////////////////
void barpoint::calcBend(int diam)
{

	DVec3d p, pp;
	double pf, dst, bndrad;
	RotMatrix rm, rmm;

	// вектор из вершины вдоль сегмента
	mdlVec_subtract(&pDirX, &pVrtx, &pVrtxNext);
	mdlVec_normalize2(&pDirX);

	// вторая точка линии параллельно pDirX, первая - pElPoint
	mdlVec_add(&p, &pElPoint, &pDirX);

	// проекция вершины стержня на линию
	mdlVec_projectPointToLine(&pp, &pf, &pVrtx, &pElPoint, &p);

	// вектор из вершины к центру загиба
	mdlVec_subtract(&pDirY, &pp, &pVrtx);
	mdlVec_normalize2(&pDirY);

	// вектор из вершины нормаль
	mdlVec_crossProduct(&pDirZ, &pDirX, &pDirY);
	mdlVec_normalize2(&pDirZ);

	// расстояние до спроецированной точки
	dst = mdlVec_distance(&pp, &pVrtx); //

	// радиус гиба для rbSrc->diam
	bndrad = mdlCnv_masterUnitsToUors(fillets[diam].radius_bend);

	// получаем центр загиба
	mdlVec_interpolate(&pArcCent, &pVrtx, bndrad / dst, &pp);

	mdlRMatrix_fromRowVectors(&rm, &pDirX, &pDirY, &pDirZ);
	//mdlRMatrix_getIdentity(&rm);

	// первая точка дуги 45°
	mdlRMatrix_rotate(&rmm, &rm, 0., 0., fc_piover4);
	mdlVec_fromRotMatrixRow(&pArcPts[0], &rmm, 0);
	//mdlVec_multiplyRotMatrixDVec3d(&pArcPts[0], &rmm, &pDirX);
	mdlVec_scaleToLengthInPlace(&pArcPts[0], bndrad);
	mdlVec_addInPlace(&pArcPts[0], &pArcCent);

	// вторая точка дуги 90°
	if (bend_ang == 90)
	{
		mdlVec_scaleToLength(&pArcPts[1], &pDirX, bndrad);
		mdlVec_addInPlace(&pArcPts[1], &pArcCent);

		double bndlen = mdlCnv_masterUnitsToUors(bend_len) - bndrad * fc_piover2;
		DVec3d v;
		mdlVec_scaleToLength(&v, &pDirY, bndlen);
		mdlVec_add(&pEndPoint, &pArcPts[1], &v);
	}

	// третья точка дуги 135°
	if (bend_ang == 135)
	{
		mdlRMatrix_rotate(&rmm, &rm, 0., 0., -fc_piover4);
		mdlVec_fromRotMatrixRow(&pArcPts[1], &rmm, 0);
		mdlVec_scaleToLengthInPlace(&pArcPts[1], bndrad);
		mdlVec_addInPlace(&pArcPts[1], &pArcCent);

		double bndlen = mdlCnv_masterUnitsToUors(bend_len) - (bndrad * fc_piover2 + bndrad * fc_piover4);
		DVec3d v;
		mdlVec_negate(&v, &pDirX);
		mdlVec_addInPlace(&v, &pDirY);
		mdlVec_scaleToLengthInPlace(&v, bndlen);
		mdlVec_add(&pEndPoint, &pArcPts[1], &v);
	}

	// четвертая точка дуги 180°
	if (bend_ang == 180)
	{
		mdlVec_scaleToLength(&pArcPts[1], &pDirY, bndrad);
		mdlVec_addInPlace(&pArcPts[1], &pArcCent);

		double bndlen = mdlCnv_masterUnitsToUors(bend_len) - bndrad * fc_pi;
		DVec3d v;
		mdlVec_negate(&v, &pDirX);
		mdlVec_scaleToLengthInPlace(&v, bndlen);
		mdlVec_add(&pEndPoint, &pArcPts[1], &v);
	}


}


/////////////////////////////////
// получение точек сравнения
void reinbar::calcComparePoints(
	Transform* tmP, // для переменных сегментов - вертикальные или горизонтальные
	int bReverse,
	double* dScaleP
)
{

	DVec3d pBeg;
	//DVec3d pEnd;
	DVec3d pBarNrm;

	double dVarSegmLen = 1000.;
	double dVarSegmLenLap = 1000.;


	// если значения разбежки lap[0] и lap[1] равны то позиция будет одна
	if (iCfgVar_PosCalc_Laps) dVarSegmLenLap += (double)lap[0] + (double)lap[1]; // для различия по четности

	//DVec3d calcTrPts[MAX_BAR_VERTICES];
	//DVec3d calcPts[MAX_BAR_VERTICES];
	//DVec3d calcPtsX[MAX_BAR_VERTICES];
	//long calcRfa[MAX_BAR_VERTICES];
	//int calcF[MAX_BAR_VERTICES]; // флаги для переменных сегментов, 1 - гориз., 2 - верт.

	for (int b = 0; b < MAX_BAR_VERTICES; b++)
	{
		mdlVec_zero(&calcTrPts[b]);
		mdlVec_zero(&calcPts[b]);
		mdlVec_zero(&calcPtsX[b]);
		calcRfa[b] = 0;
		calcF[b] = 0;
	}


	cnumpts = numpts;

	DgnModelRefP mrLocP = NULL;
	if (modrefP) mrLocP = modrefP; else mrLocP = ACTIVEMODEL;





	if (numpts == 2)
	{
		calcPts[1].x = mdlVec_distance(&rpts[0], &rpts[1]);
	}
	else
	{
		if (bReverse)
		{
			int j = numpts - 1;

			for (int i = 0; i < numpts; i++)
			{
				if (rfa[j] & RFA_ARCP || rfa[j] & RFA_CIRP) // ставим центр дуги
					calcPts[i] = cents[j];
				else
					calcPts[i] = rpts[j];

				calcRfa[i] = rfa[j];

				j--;
			}
		}
		else
		{
			for (int i = 0; i < numpts; i++)
			{
				if (rfa[i] & RFA_ARCP || rfa[i] & RFA_CIRP) // ставим центр дуги
					calcPts[i] = cents[i];
				else
					calcPts[i] = rpts[i];

				calcRfa[i] = rfa[i];
			}
		}
	}



	for (int i = 0; i < numpts; i++)
	{
		mdlCnv_UORToMaster(&calcPts[i].x, calcPts[i].x, mrLocP);
		mdlCnv_UORToMaster(&calcPts[i].y, calcPts[i].y, mrLocP);
		mdlCnv_UORToMaster(&calcPts[i].z, calcPts[i].z, mrLocP);

		calcTrPts[i] = calcPts[i];
	}


	if (tmP)
		mdlTMatrix_transformPointArray(calcTrPts, tmP, numpts);




	if (numpts == 2)
	{
		if (coordIsEqual(calcTrPts[0].z, calcTrPts[1].z, FALSE)) calcF[0] = 1;

		if (coordIsEqual(calcTrPts[0].x, calcTrPts[1].x, FALSE) &&
			coordIsEqual(calcTrPts[0].y, calcTrPts[1].y, FALSE)) calcF[0] = 2;
	}
	else
	{

		for (int i = 0; i < numpts; i++) // numpts == cnumpts
		{

			// флаги для сегм. перем. длины
			if (i < numpts - 1 &&
				!(calcRfa[i] & RFA_ARCP || calcRfa[i] & RFA_CIRP) &&
				!(calcRfa[i + 1] & RFA_ARCP || calcRfa[i + 1] & RFA_CIRP)
				)
			{
				if (coordIsEqual(calcTrPts[i].z, calcTrPts[i + 1].z, FALSE))
				{// горизонтальная
					calcF[i] = 1;
				}

				if (coordIsEqual(calcTrPts[i].x, calcTrPts[i + 1].x, FALSE) &&
					coordIsEqual(calcTrPts[i].y, calcTrPts[i + 1].y, FALSE))
				{// вертикальная
					calcF[i] = 2;
				}
			}
		}
	}



	if (runmet == 2)
	{
		for (int i = 0; i < numpts; i++)
		{
			if (calcF[i] == 1) // горизонтальный
			{
				if (i == 0 || i == numpts - 2)
					setSegmLength(calcPts, numpts, i, dVarSegmLenLap);
				else
					setSegmLength(calcPts, numpts, i, dVarSegmLen);
			}
		}
	}

	if (runmet == 3)
	{
		for (int i = 0; i < numpts; i++)
		{
			if (calcF[i] == 2) // верт
			{
				if (i == 0 || i == numpts - 2)
					setSegmLength(calcPts, numpts, i, dVarSegmLenLap);
				else
					setSegmLength(calcPts, numpts, i, dVarSegmLen);
			}
		}
	}



	pBeg = calcPts[0];

	mdlVec_subtractPointArray(calcPts, &pBeg, numpts);

	pBeg = calcPts[1];





	if (noplanar == 2)
	{
		DVec3d vec;

		for (int i = 1; i < numpts - 1; i++)
		{
			mdlVec_subtractPoint(&vec, &calcPts[i + 1], &calcPts[i]);
			if (mdlVec_areParallel(&vec, &pBeg) == FALSE) break;
		}

		mdlVec_crossProduct(&pBarNrm, &pBeg, &vec);
	}
	else
	{
		pBarNrm = v_enrm;
	}



	getBarUnrotatedPoints(calcPtsX, calcPts, &pBarNrm, numpts, 0, 0, dScaleP); // x


	// angle
	//double dang;
	//dang = mdlVec_angleXY(&pBeg);



	//for (int i = 0; i < numpts; i++)
	//{
	//	mdlVec_rotateXYInPlace (&calcPts[i], -dang);
	//}

	for (int i = 0; i < numpts; i++)
	{
		if (bReverse)
		{
			cpxe[i].x = (int)roundex(calcPtsX[i].x);
			cpxe[i].y = (int)roundex(calcPtsX[i].y);
			cpxe[i].z = (int)roundex(calcPtsX[i].z);
		}
		else
		{
			cpxb[i].x = (int)roundex(calcPtsX[i].x);
			cpxb[i].y = (int)roundex(calcPtsX[i].y);
			cpxb[i].z = (int)roundex(calcPtsX[i].z);
		}
	}


	//Point3d v;

	//if (bReverse)
	//{
	//	cpxe.clear();

	//	for (int i = 0; i < numpts; i++)
	//	{

	//		v.x = (int)roundex(calcPtsX[i].x);
	//		v.y = (int)roundex(calcPtsX[i].y);
	//		v.z = (int)roundex(calcPtsX[i].z);

	//		cpxe.push_back(v);
	//	}
	//}
	//else
	//{
	//	cpxb.clear();

	//	for (int i = 0; i < numpts; i++)
	//	{
	//		v.x = (int)roundex(calcPtsX[i].x);
	//		v.y = (int)roundex(calcPtsX[i].y);
	//		v.z = (int)roundex(calcPtsX[i].z);

	//		cpxb.push_back(v);
	//	}
	//}


}



/////////////////////////////////////////
// проверка, сжатие вектора точек и перевод его в массив
void reinbar::checkBarPoints(int bBends)
{

	//size_t i = 0;
	ReinPoint rp;

	// уборка маленьких расстояний
	for (vector<ReinPoint>::iterator it = gvpt.begin(); it != gvpt.end() && gvpt.size() > 2;)
		//for (i = 0; i < gvpt.size() - 1 && gvpt.size() > 2;)
	{
		//ReinPoint* vP = &gvpt[i];
		//ReinPoint* vPn = &gvpt[i + 1];
		vector<ReinPoint>::iterator itn = it;
		itn++;

		if (itn == gvpt.end()) break;

		double dst = mdlVec_distance(&(it->rpt), &(itn->rpt));

		int res = ERROR;
		
		if (modrefP) res = mdlCnv_masterToUOR(&dst, dst, modrefP);

		if (res == SUCCESS && dst < (double)iCfgVar_MinSegment)
		{
			//gvpt.erase(gvpt.begin() + i + 1);
			gvpt.erase(itn); // delete second point
		}
		else
		{
			it++;
			//i++;
		}
	}

	// точки сложного дугового стержня
	//i = 0;

	//while (rbSrc && vItP < vpt.end() - 1)
	for (vector<ReinPoint>::iterator it = gvpt.begin(); it != gvpt.end();)
		//for (size_t a = 0; gvpt.size() > 0 && a < gvpt.size() - 1;)
	{
		//ReinPoint* vP = &gvpt[a];

		int a = distance(gvpt.begin(), it);

		//if (vP->rfa & RFA_ARCB) // арка
		if (it->rfa & RFA_ARCB) // арка
		{
			if (noplanar == 0) // на плоских доп. точка не нужна
			{
				//gvpt.erase(gvpt.begin() + a);
				gvpt.erase(it);
			}
			else
			{
				if ((a == 1) // arc start is clear
					|| (a == gvpt.size() - 2)) // arc end is clear
				{
					//gvpt.erase(gvpt.begin() + a);
					gvpt.erase(it);
				}
				else
				{
					//a++;
					++it;
				}
			}
		}
		else
		{
			//a++;
			++it;
		}
	}

	// 
	if (iCfgVar_BendNewDraw == 2 && bBends)
	{
		if (axid == 0 // только для несозданных элементов
			&& term[0] == REIN_TERM_BEND)
		{
			bent[0].clear();

			//vpt.front() // first element in the vector
			bent[0].pVrtx = gvpt[0].rpt;
			bent[0].pVrtxNext = gvpt[1].rpt;
			bent[0].bend_ang = termPar[0][0];
			bent[0].bend_len = termPar[1][0];
			if (bent[0].bend_len == 0) bent[0].bend_len = diam * 6; // ?

			if (gvpt.size() > 2)
				bent[0].pElPoint = gvpt[2].rpt; // если не стяжка то гнемся в плоскости элемента
			else
				findReinElmsAroundPoint(&bent[0]); // <- rbSrc->pElPoint

			//if (rbSrc->bent[0].bnd) ... если поймал элемент
			bent[0].calcBend(diam);

			// вставку точек перенести в reinCreateComplexBarAxis2 ???
			rp.set(bent[0].pArcPts[0], RFA_ARCP);
			gvpt.insert(gvpt.begin(), rp);
			rp.set(bent[0].pArcPts[1]);
			gvpt.insert(gvpt.begin(), rp);
			rp.set(bent[0].pEndPoint);
			gvpt.insert(gvpt.begin(), rp);

		}
		if (axid == 0  // только для несозданных элементов
			&& term[1] == REIN_TERM_BEND)
		{
			bent[1].clear();

			//vpt.back() // last element in the vector
			bent[1].pVrtx = gvpt[gvpt.size() - 1].rpt;
			bent[1].pVrtxNext = gvpt[gvpt.size() - 2].rpt;
			bent[1].bend_ang = termPar[0][1];
			bent[1].bend_len = termPar[1][1];
			if (bent[1].bend_len == 0) bent[1].bend_len = diam * 6; // ?

			if (gvpt.size() > 2)
				bent[1].pElPoint = gvpt[gvpt.size() - 3].rpt; // если не стяжка то гнемся в плоскости элемента
			else if (bent[0].bnd)
			{
				// ставим ту же точку чтобы загиб был в той же плосоксти
				bent[1].pElPoint = bent[0].pElPoint;
			}
			else
			{
				findReinElmsAroundPoint(&bent[1]); // <- rbSrc->pElPoint
			}

			bent[1].calcBend(diam);

			//rbSrc->termPar[0][1] // угол - 90,135,180, м.б. со знаком
			//rbSrc->termPar[1][1] // длина загиба

			rp.set(bent[1].pArcPts[0], RFA_ARCP);
			gvpt.push_back(rp);
			rp.set(bent[1].pArcPts[1]);
			gvpt.push_back(rp);
			rp.set(bent[1].pEndPoint);
			gvpt.push_back(rp);
		}
	}


	// REPAIR BEND POINTS
	if (iCfgVar_BarBendRepair)
	{
		//while (removeArcPoints()) {}

		for (vector<ReinPoint>::iterator it = gvpt.begin(); it != gvpt.end(); ++it)
		{
			UInt32 i = distance(gvpt.begin(), it);

			if (it->rfa & RFA_ARCP && i > 1 && i < gvpt.size() - 2)
			{
				// lets repair....
				DVec3d ptmp[5];
				DVec3d prp[4];

				vector<ReinPoint>::iterator it1 = it;
				it1--;
				ptmp[1] = it1->rpt;
				it1--;
				ptmp[0] = it1->rpt;

				// point for erase
				it1++;

				vector<ReinPoint>::iterator it2 = it;
				it2++;
				ptmp[2] = it2->rpt;
				it2++;
				ptmp[3] = it2->rpt;

				// point for erase
				it2--;

				mdlVec_subtract(&prp[0], &ptmp[1], &ptmp[0]);
				mdlVec_subtract(&prp[1], &ptmp[1], &it->cent);

				mdlVec_subtract(&prp[2], &ptmp[2], &ptmp[3]);
				mdlVec_subtract(&prp[3], &ptmp[2], &it->cent);

				// check of perpendicularity of bend axis and nearest segment
				if (mdlVec_arePerpendicular(&prp[0], &prp[1]) && mdlVec_arePerpendicular(&prp[2], &prp[3]))
				{
					if (mdlVec_intersectXYZLines(&ptmp[4], 0, 0, &ptmp[0], &ptmp[1], &ptmp[2], &ptmp[3], 0.) == SUCCESS)
					{
						ReinPoint p;
						p.set(ptmp[4]);
						gvpt[i] = p;
						gvpt.erase(it1); // it2 also shifted
						it2--; // turn back
						gvpt.erase(it2);
					}
				}

			}
		}

	}

	numpts = (int)gvpt.size();

	if (numpts >= MAX_BAR_VERTICES)
	{
		_swprintf(wss, L"elem axis id = %I64u id = %I64u has points = %u", this->axid, this->elemid, (UInt32)gvpt.size());
		mdlOutput_messageCenterW(MESSAGE_ERROR, wss, wss, MESSAGE_ALERT_NONE);
		numpts = MAX_BAR_VERTICES;
	}


	for (int i = 0; i < numpts; i++)
	{
		rpts[i] = gvpt[i].rpt;
		cents[i] = gvpt[i].cent;
		rfa[i] = gvpt[i].rfa;
	}

	gvpt.clear(); // больше не нужен

}

int reinbar::createComplexBarAxisElem(MSElementDescr** edPP, MSElement* elTemplateP)
{
	int ret = SUCCESS;
	int rad = 0;

	if (bendrad > 0)
		rad = bendrad;
	else
		rad = getBendRadius(this, NULL);

	mdlComplexChain_createHeader(&eCell, 0, 0);
	eCell.hdr.dhdr.props.b.s = 0; // make snappable
	mdlElmdscr_new(edPP, 0, &eCell);

	int cnt = reinCreateComplexBarAxis2(edPP, 0, rpts, rfa, numpts, rad, elTemplateP, NULL, FALSE);

	return ret;
}

///////////////////////////

int reinbar::createBar(
	MSElementDescr* edP,
	int bBarReady,
	int bAddElem,
	double* distP,
	DVec3d* dirP,
	int barnum,
	int barqty,
	int lapbeg,
	int lapend,
	int bReinBar // for DROP
)
{
	MSElementDescr* edpChain = NULL;
	MSElementDescr* edpBar = NULL;


	ReinBar rb = *this; //if (rbP) rb = *rbP;
	ReinBar* rbOkP = NULL;


	double dBarRadiusUors;
	double dFilletRadiusUors;
	double len;
	//double drad[2] = {0.,0.}; // радиус закругленного стержня (ARC_ELM)

	//ELID idAssoc = 0;

	//const BitMask  *levelMaskP = NULL;
	//UInt32 levelID;
	int iLvlMask = 0;
	//int iSktMask = 0;

	UInt32 fp = 0;
	UInt32 fpbar = 0;

	UInt32 lev = 0;
	UInt32 ggn = 0;
	UInt32 clr = 0;

	//Transform tmRef;
	//Transform* tmRefP = NULL;


	double ailap[2] = { 0,0 }; // на одиночном стержне тоже будем записывать разбежку в атрибут, но обрезать не будем
	double dlap[2] = { 0.,0. };



	//if (mrP && mdlModelRef_is3D(mrP) == FALSE) return SUCCESS; // used ACTIVEMODEL

	if (mdlSystem_findMdlDesc(L("BATCHCONVERT")) != NULL) return SUCCESS;

	if (edP == NULL && bBarReady == FALSE) return ERROR;

	if (bBarReady)
		rbOkP = this;
	else
		rbOkP = &rb;


	if (barnum > 0) // номер стержня (контур)
	{
		if (lapbeg) ailap[0] = lapbeg;
		if (lapend) ailap[1] = lapend;

		if (lapbeg) dlap[0] = mdlCnv_masterUnitsToUors(lapbeg);
		if (lapend) dlap[1] = mdlCnv_masterUnitsToUors(lapend);
	}


	writeLogIn(__FUNCTION__, 0);
	if (iDebug) sprintf(sLogMes, "bBarReady = %i\n", bBarReady); writeLog(0, 0);

	//if (mrP && getRefNum(mrP) > 0)
	//{
	//	mdlTMatrix_referenceToMaster(&tmRef, mrP);
	//	tmRefP = &tmRef;
	//}


	//printf("%i\n", barnum);

	if (edP)
	{
		mdlElmdscr_getProperties(&lev, &ggn, 0, 0, 0, 0, 0, 0, edP);
		mdlElement_getSymbology(&clr, 0, 0, &edP->el);

		//iLvlMask = reinGetLevelMask(edP, 0, mrP);

		fp = mdlElmdscr_getFilePos(edP);
	}


	//re.clear();

	//re.rs.diam = diam;
	//re.rs.runmet = runmet;
	//re.fpRS = fp;
	//re.idRS = elemid; // для объемного стержня
	//re.modelRef = mrP;
	//re.iLevelMask = iLvlMask;


	dBarRadiusUors = mdlCnv_masterUnitsToUors(diam / 2.);

	dFilletRadiusUors = mdlCnv_masterUnitsToUors(getBendRadius(this, 0));


	// создание оси стержня edpChain
	//===================================================
	double dPrm[2] = { 0.,0. };

	if (bBarReady) // from calcSpace
	{
		mdlComplexChain_createHeader(&eCell, 0, 0);
		mdlElmdscr_new(&edpChain, 0, &eCell);

		if (ailap[0]) setLap(rpts, numpts, dlap[0], 0);
		if (ailap[1]) setLap(rpts, numpts, dlap[1], 1);

		//DVec3d* vpP = &rpts[0];
		//if (ailap[0]) setLap(vpP, numpts, dlap[0], 0);
		//if (ailap[1]) setLap(vpP, numpts, dlap[1], 1);

		//numpts = reinCreateBarAxis(&edpChain, 0, rpts, numpts, getBendRadius..., NULL, mrP, FALSE);

		if (bReinBar) // create bar from DROP cmd
		{
			if (bAddElem)
			{
				rbOkP->bartype = BT_AXIS;

				MSElement* elTmplP = &c0w0s0;
				if (edP) elTmplP = &edP->el;

				rbOkP->numpts = reinCreateComplexBarAxis2(&edpChain, 0,
					rpts, rfa, numpts, 0, elTmplP, 0, 0);

				if (edpChain) rbOkP->createReinBarElement(&edpChain, 0, 0, TRUE);
			}

			writeLogOut(__FUNCTION__, 0);

			return SUCCESS;
		}
		else
		{
			rbOkP->numpts = reinCreateComplexBarAxis2(&edpChain, 0,
				rpts, rfa, numpts, getBendRadius(this, 0), &c0w0s0);
		}

	}
	else
	{

		// ==== РАЗБЕЖКА =============================
		DVec3d ptLap[2];
		//MSBsplineCurve crv;
		double lenn;

		// edP - элемент линия - ось для построения стержня

		mdlMeasure_linearProperties(&lenn, 0, 0, 0, 0, 0, 0, 0, edP, -1);

		mdlElmdscr_pointAtDistance(&ptLap[0], 0, dlap[0], edP, 0);
		mdlElmdscr_pointAtDistance(&ptLap[1], 0, lenn - dlap[1], edP, 0);

		mdlBspline_convertToCurve(&crv, edP);

		mdlBspline_minimumDistanceToCurve(0, 0, &dPrm[0], &ptLap[0], &crv);
		mdlBspline_minimumDistanceToCurve(0, 0, &dPrm[1], &ptLap[1], &crv);

		mdlBspline_freeCurve(&crv);


		if (ailap[0])
			mdlElmdscr_generatePartial(&edP, edP, dPrm[0], 1.0, TRUE);

		if (ailap[1])
			mdlElmdscr_generatePartial(&edP, edP, 0., dPrm[1], TRUE);
		// ======================================

		if (edP == NULL)
		{
			writeLogOut(__FUNCTION__, "if (edP == NULL) ");
			return SUCCESS; // по разбежке
		}


		//===============================
		getComlexBarPoints(edP, rbOkP,
			TRUE, // обнулить
			NULL, TRUE, TRUE); // update mainline

		// сдвиг стержня на свое место в раскладке
		if (distP && dirP)
		{
			DVec3d p = *dirP;
			mdlVec_scaleToLengthInPlace(&p, *distP);
			//mdlVec_addPointArray(rbOkP->rpts, &p, rbOkP->numpts);
			//mdlVec_addPointArray(rbOkP->cents, &p, rbOkP->numpts);

			for (vector<ReinPoint>::iterator it = gvpt.begin(); it != gvpt.end(); ++it)
				//for (size_t i = 0; i < gvpt.size(); i++)
			{
				mdlVec_addInPlace(&it->rpt, &p);
				mdlVec_addInPlace(&it->cent, &p);
			}
		}

		rbOkP->checkBarPoints(TRUE);
		//===============================

		mdlComplexChain_createHeader(&eCell, 0, 0);
		mdlElmdscr_new(&edpChain, 0, &eCell);

		rbOkP->numpts = reinCreateComplexBarAxis2(&edpChain, 0,
			rbOkP->rpts, rbOkP->rfa, rbOkP->numpts, getBendRadius(rbOkP, 0), &c0w0s0);


	}

	BarPoint* bpOneP = NULL;
	BarPoint* bpTwoP = NULL;

	if (rbOkP->term[0] == REIN_TERM_BEND) bpOneP = &rbOkP->bent[0];
	if (rbOkP->term[1] == REIN_TERM_BEND) bpTwoP = &rbOkP->bent[1];

	//===================================================


	//if (rbOkP->segmIndex >= (rbOkP->numsgts))
	//	iMainLine = rbOkP->numsgts - 1;
	//else
	//	iMainLine = rbOkP->segmIndex + rbOkP->elemEDoffset;

	//if (iMainLine < 0) iMainLine = 0;


	if (bAddElem && edpChain == NULL)
	{
		writeLogOut(__FUNCTION__, "if (bAddElem && edpChain == NULL) ");
		return SUCCESS;
	}


	//rbOkP->rad[0] = (int)roundex(mdlCnv_uorsToMasterUnits(drad[0]));
	//rbOkP->rad[1] = (int)roundex(mdlCnv_uorsToMasterUnits(drad[1]));


	// получение точек ReinBar
	if (bBarReady == FALSE // edP != NULL
		&& rb.numpts > 0)
	{


		int res = mdlElmdscr_extractNormal(&rb.v_enrm, 0, edP, &pZ);
		if (rb.noplanar != 2)
		{
			if (res == SUCCESS)
				rb.noplanar = 0;
			else
				rb.noplanar = 1;
		}
		else
		{
			if (res == SUCCESS)
				rb.noplanar = 0;
			else
				rb.noplanar = 2;
		}


		rb.cnumpts = rb.numpts;

		rb.elemid = elemid;
		rb.diam = diam;
		rb.runmet = runmet;
		rb.segmIndex = rbOkP->segmIndex;
		rb.elemEDoffset = rbOkP->elemEDoffset;
		rb.mainSgmIndex = rbOkP->mainSgmIndex;
		rb.mainPtsIndex = rbOkP->mainPtsIndex;

		rb.modrefP = edP->h.dgnModelRef;
		rb.numRef = getRefNum(edP->h.dgnModelRef);

		rb.term[0] = term[0];
		rb.term[1] = term[1];

		for (int i = 0; i < 10; i++)
		{
			rb.termPar[i][0] = termPar[i][0];
			rb.termPar[i][1] = termPar[i][1];
		}

		rb.getDrawPoints(&rb.v_enrm, NULL); // поворачиваем отн. начала mainline

		//barCalcComparePoints(&rb, TRUE, NULL);
		rb.calcComparePoints(NULL, 0, 0);
		rb.calcComparePoints(NULL, 1, 0);

	}




	mdlMeasure_linearProperties(&len, 0, 0, 0, 0, 0, 0, 0, edpChain, -1);

	len = mdlCnv_uorsToMasterUnits(len);

	rbOkP->length = len;


	func_amp(mdlElmdscr_setSymbology, edpChain), & clr, 0, 0, 0);


	if (isReinElemInner(barnum, barqty, lap[0], lap[1], grnd))
	{
		if (iCfgVar_Transp_Elm_Inn >= 0) mdlElmdscr_setTransparency(&edpChain, (double)iCfgVar_Transp_Elm_Inn * 0.01);
		rbOkP->transp = REIN_TRANSP_INN;
	}
	else
	{
		if (iCfgVar_Transp_Elm_Out >= 0) mdlElmdscr_setTransparency(&edpChain, (double)iCfgVar_Transp_Elm_Out * 0.01);
		rbOkP->transp = REIN_TRANSP_OUT;
	}



	updateReinBarSegments(rbOkP, 0, bpOneP, bpTwoP);


	if (bAddElem)
	{

		BINT iVisible = TRUE;
		rbOkP->axid = reinCreateBarAxisLine(NULL, rbOkP, iVisible, lev); // acht: создание оси ReinAxis

		fpbar = reinSweepBarByPath(rbOkP, diam, 0, 0, edpChain, barnum, &lev, NULL, 0.0);

		if (rbOkP->term[0] == REIN_TERM_PLAT)
		{
			MSElementDescr* edPlate1 = makePlate(20, 90, 90,
				rbOkP->rpts[0],
				rbOkP->sgts[0].rv[0].rvv.tdir);

			if (edPlate1)
			{
				UInt32 fpp = xmlAddReinElmdAttr(
					&edPlate1,
					rbOkP->elemid,
					REIN_ELEM_BAR,
					rbOkP, // no saved points
					&lev,
					ACTIVEMODEL, // add to file
					&ggn,
					TRUE, // locked
					0, // lap
					TRUE, // visible
					barnum // порядковый номер в области
				);

				mdlElmdscr_freeAll(&edPlate1);
			}
		}
		if (rbOkP->term[1] == REIN_TERM_PLAT)
		{
			MSElementDescr* edPlate1 = makePlate(20, 90, 90,
				rbOkP->rpts[rbOkP->numpts - 1],
				rbOkP->sgts[rbOkP->numsgts - 1].rv[1].rvv.tdir);

			if (edPlate1)
			{
				UInt32 fpp = xmlAddReinElmdAttr(
					&edPlate1,
					rbOkP->elemid,
					REIN_ELEM_BAR,
					rbOkP, // no saved points
					&lev,
					ACTIVEMODEL, // add to file
					&ggn,
					TRUE, // locked
					0, // lap
					TRUE, // visible
					barnum // порядковый номер в области
				);

				mdlElmdscr_freeAll(&edPlate1);
			}
		}

	}



	UInt32 fpp = 0;


	int ilap = 0;
	if (lapbeg > 0) ilap = lapbeg;
	if (lapend > 0) ilap = -lapend;


	// REIN_ELEM_ISO
	if (bAddElem)
	{
		fpp = xmlAddReinElmdAttr(
			&edpChain,
			rbOkP->elemid,
			REIN_ELEM_ISO,
			rbOkP,
			&lev,
			ACTIVEMODEL,
			&ggn,
			FALSE, // not locked - open for manipulation
			ilap,
			TRUE, // visible
			barnum
		);
	}

	//insertCurBarsMember2(rbOkP, edpChain, fpp, NULL); // see iterateReloadBarsData()

	if (edpChain) mdlElmdscr_freeAll(&edpChain);


	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;
}




////////////////////////////////
UInt32 reinbar::createReinBarElement(MSElementDescr** edP, UInt32 fpos, DgnModelRefP mrP, int bAdd)
{

	MSWCH wstr[100];
	char str[100];
	XMLFragmentListP    pCurrent = NULL;
	int status;
	UInt32 fp = 0;
	MSElementDescr* edp = NULL;

	if (edP == NULL) return fp;

	edp = *edP;

	pCurrent = createReinBarXml();

	if (pCurrent)
	{

		// при копировании из ReinSpace и создании ReinBar атрибуты копируются, удаляем...
		//mdlXMLFragmentList_stripFromElement(&edp->el, &appID, &appTypeOrgPoints, NULL, NULL);
		//mdlXMLFragmentList_stripFromElement(&edp->el, &appID, &appTypeEndPoints, NULL, NULL);
		//mdlXMLFragmentList_stripFromElement(&edp->el, &appID, &appTypeReinSpace, NULL, NULL);
		//mdlXMLFragmentList_stripFromElement(&edp->el, &appID, &appTypeReinElm, NULL, NULL);
		//mdlXMLFragmentList_stripFromElement(&edp->el, &appID, &appTypeReinBar, NULL, NULL);
		mdlXMLFragmentList_stripAllFromElement(NULL, &edp->el);

		status = mdlXMLFragmentList_attachToElement(&pCurrent, &edp, TRUE);

		if (bAdd)
		{
			if (fpos > 0)
			{
#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX att
				//attachECInstance(edp, rbP, L"ReinBar");
#endif

				fp = mdlElmdscr_rewrite(edp, NULL, fpos);
				if (fp == 0)
				{
					//SPRN(s, L("mdlElmdscr_rewrite - > mdlErrno = %i"), mdlErrno);
					//mdlDialog_dmsgsPrint(s);
				}
			}
			else
			{
				fp = mdlElmdscr_add(edp);
				if (fp == 0)
				{
					//SPRN(s, L("mdlElmdscr_add - > mdlErrno = %i"), mdlErrno);
					//mdlDialog_dmsgsPrint(s);
				}

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX att
				//attachECInstance(edp, rbP, L"ReinBar");
#endif
			}

			mdlElmdscr_display(edp, MASTERFILE, DRAW_MODE_Normal);

		}
	}

	return fp;

}



////////////////////////////////
XMLFragmentListP reinbar::createReinBarXml()
{

	MSWCH wstr[200];
	char str[200];
	XMLFragmentListP    pCurrent = NULL;
	int status;



	int trmp[6] = { 0 };
	//ZeroMemory(trmp, sizeof(trmp));

	if (term[0] == REIN_TERM_BEND)
	{
		trmp[0] = termPar[0][0];
		trmp[2] = termPar[1][0];
	}
	if (term[1] == REIN_TERM_BEND)
	{
		trmp[1] = termPar[0][1];
		trmp[3] = termPar[1][1];
	}
	if (term[0] == REIN_TERM_MUFT)
	{
		trmp[4] = termPar[2][0];
	}
	if (term[1] == REIN_TERM_MUFT)
	{
		trmp[5] = termPar[2][1];
	}

	if (space == 0) space = iSpaceDefault; // no space2

	_swprintf(wstr, L"REINBAR;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%I64u;%i;%i;%i;%i",
		runmet,
		diam,
		segmIndex,
		elemEDoffset,
		space, // аргументы потом используются когда создается SURFACE_ELM
		offset[0],
		-offset[1], // для совместимости хранится с отриц. значением
		lap[0],
		lap[1],
		lap[2],
		term[0],
		term[1],
		trmp[0],
		trmp[1],
		trmp[2],
		trmp[3],
		trmp[4],
		trmp[5],
		bendrad,
		bartype,
		spacerad,
		elemid, // ReinData parent element
		contnum, // номер последовательности построения
		poscalc,
		barflags, // флаги
		grnd
	);



	//status = mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 100);

	pCurrent = mdlXMLFragmentList_construct(wstr, NULL, appID, appTypeReinBar);

	return pCurrent;

}

//////////////////////////////////////////
void reinbar::fromReinData(ReinData* rdP)
{
	if (rdP == NULL) return;

	bartype = rdP->dattype;
	diam = rdP->datdiam;
	runmet = rdP->datrunmet;
	bendrad = rdP->datbdrad;
	poscalc = rdP->datposcalc;
	space = rdP->datspace;
	lap[0] = rdP->datlap[0];
	lap[1] = rdP->datlap[1];
	lap[2] = rdP->datlap[2];
	term[0] = rdP->dattrm[0];
	term[1] = rdP->dattrm[1];
	offset[0] = rdP->datoffset[0];
	offset[1] = rdP->datoffset[1];

	for (int i = 0; i < 10; i++)
	{
		termPar[i][0] = rdP->dattrmPar[i][0];
		termPar[i][1] = rdP->dattrmPar[i][1];
	}

	//termPar[0][0] = rdP->dattrmPar[0][0];
	//termPar[1][0] = rdP->dattrmPar[1][0];
	//termPar[2][0] = rdP->dattrmPar[2][0];
	//termPar[3][0] = rdP->dattrmPar[3][0];
	//termPar[4][0] = rdP->dattrmPar[4][0];
	//termPar[0][1] = rdP->dattrmPar[0][1];
	//termPar[1][1] = rdP->dattrmPar[1][1];
	//termPar[2][1] = rdP->dattrmPar[2][1];
	//termPar[3][1] = rdP->dattrmPar[3][1];
	//termPar[4][1] = rdP->dattrmPar[4][1];

}


//////////////////////////
// получение точек для отрисовки эскизов (apts)
void reinbar::getDrawPoints(
	DVec3d* pNrmP,  // нормаль к плоскости стержня
	double* dScaleP
)
{

	DVec3d pNrm;
	//DVec3d ptsCalc[MAX_BAR_VERTICES];


	if (noplanar == 2)
	{
		DVec3d vec;
		DVec3d pBeg;

		mdlVec_subtractPoint(&pBeg, &rpts[1], &rpts[0]);

		for (int i = 1; i < numpts - 1; i++)
			//for (size_t i = 1; i < rpts.size() - 1; i++)
		{
			mdlVec_subtractPoint(&vec, &rpts[i + 1], &rpts[i]);
			if (mdlVec_areParallel(&vec, &pBeg) == FALSE) break;
		}

		mdlVec_crossProduct(&pNrm, &pBeg, &vec);
	}
	else
	{
		pNrm = *pNrmP;
	}

	for (int i = 0; i < numpts; i++) // numpts == cnumpts
	//for (size_t i = 0; i < rpts.size(); i++) // numpts == cnumpts
	{
		//if (rfa[i] == 1)
		//	ptsCalc[i] = cents[i];
		//else
		ptsCalc[i] = rpts[i]; // ставим точку на арке
	}



	if (EQ(pNrm.z, 0.)) // horizontal
		getBarUnrotatedPoints(ptsUnRotForDraw, ptsCalc, &pNrm, numpts, mainPtsIndex, 1, dScaleP);
	else
		getBarUnrotatedPoints(ptsUnRotForDraw, ptsCalc, &pNrm, numpts, mainPtsIndex, 0, dScaleP);

	//if (EQ(pNrm.z, 0.)) // horizontal
	//	getBarUnrotatedPoints(ptsUnRotForDraw, ptsCalc, &pNrm, rpts.size(), mainPtsIndex, 1, dScaleP);
	//else
	//	getBarUnrotatedPoints(ptsUnRotForDraw, ptsCalc, &pNrm, rpts.size(), mainPtsIndex, 0, dScaleP);


	//apts.clear();

	for (int i = 0; i < numpts; i++) // numpts == cnumpts
	//for (size_t i = 0; i < rpts.size(); i++) // numpts == cnumpts
	{
		//DVec3d apt;

		apts[i].x = (mdlCnv_uorsToMasterUnits(ptsUnRotForDraw[i].x)); // roundex() ненадо!
		apts[i].y = (mdlCnv_uorsToMasterUnits(ptsUnRotForDraw[i].y));
		apts[i].z = (mdlCnv_uorsToMasterUnits(ptsUnRotForDraw[i].z));


		//apt.x = (mdlCnv_uorsToMasterUnits(ptsUnRotForDraw[i].x)); // roundex() ненадо!
		//apt.y = (mdlCnv_uorsToMasterUnits(ptsUnRotForDraw[i].y));
		//apt.z = (mdlCnv_uorsToMasterUnits(ptsUnRotForDraw[i].z));

		//apts.push_back(apt);
	}

}


///////////////////////////////////////////////////
void ReinModel::delRefPrefs(int iDpth)
{
	for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); iDpth != 0 && it != arMrP.end(); ++it)
		//for (int i = 0; iDpth != 0 && i < MAX_REF_SLOT; i++)
	{
		it->second.delRefPrefs(iDpth - 1);
	}

	//if (arRefPrefs) delete arRefPrefs;
	refPrefsP = NULL;

}

////////////////////////////////////////////////////
ReinInfoRef* ReinModel::getRefPrefs()
{

	if (refPrefsP) return refPrefsP; // current ref

	deque <UInt32> aref;
	//UInt32 aref[MAX_REFNUM_PATH]; // обратный путь, для рефа 5->3->7 массив: [0] = 7, [1] = 3, [2] = 5
	//deque <UInt32>* arefP = &aref;

	ReinInfoRef* riP = &rInfoRef;

	if (curRM->refPrefsP) riP = curRM->refPrefsP;


	wstring spth = getRefPathString();

	ReinModel* rmP = curRM->getRM(spth);

	if (rmP && rmP->refPrefsP)
	{
		return rmP->refPrefsP;
	}

	/*
	getRefPath(&aref);

	for (deque<UInt32>::iterator it = aref.begin(); it != aref.end(); ++it)
	{
		ReinModel* rmP = curRM->getRM(*it);

		if (rmP && rmP->refPrefsP)
		{
			return rmP->refPrefsP;
		}
	}

	while (arefP[0] > 0)
	{
		ReinModel* rmP = curRM->getRM(aref);

		if (rmP && rmP->refPrefsP)
		{
			return rmP->refPrefsP;
		}

		//aref.pop_back(); // сокращаем путь, следующий родитель
		arefP++; // shift pointer
	}*/

	return riP;

}

///////////////////////
//UInt32 ReinModel::getIndMax()
//{
//	if (rnum == 0)
//		return MAX_FP_ELEMS - 1;
//	else
//		return indmax;
//
//}
/*
///////////////////////////////////////////////
ReinModel* ReinModel::getRM(UInt32* arn)
{

	ReinModel* rmRetP = this;

	if (arn == NULL) return this;

	if (arn[0] == 0) return curRM;

	int start = 0;

	for (int i = 0; i < MAX_REFNUM_PATH; i++)
	{
		if (arn[i] == 0)
		{
			start = i;
			break;
		}
	}

	for (int i = start; i >= 0; i--)
	{
		if (arn[i])
		{
			UInt32 ind = arn[i];

			MAP<UInt32, ReinModel>::iterator itt = rmRetP->arMrP.find(ind);

			if (itt != rmRetP->arMrP.end()) // found
			{
				// получили ссылку на модель для поиска далее вглубь
				//rmRetP = &(rmRetP->arMrP[ind]); // ссылка на подмодель для следующй итерации
				rmRetP = &(itt->second);
			}
			else
			{
				// путь обрывается?
				break;
			}

		}
	}


	return rmRetP;

}*/

/////////////////////////////////////////////////
ReinModel* ReinModel::getRM(wstring ws)
{
	//if (ws == L"") return this;
	//if (ws == L"0") return this; // see getRM(aref);
	
	ReinModel* rmRetP = this;

	MSWCH str[500];

	wcscpy(str, ws.c_str());

	MSWCH* wtok = NULL;

	deque <UInt32> aref;

	wtok = wcstok(str, L"-");
	while (wtok)
	{
		UInt32 rn = wcstoul(wtok, 0, 0);
		//aref.push_back(rn); // push_front???push_back
		aref.push_front(rn); // не push_back, оттестировано
		wtok = wcstok(NULL, L"-");
	}

	rmRetP = getRM(aref);

	return rmRetP;
}

/////////////////////////////////////////////////
ReinModel* ReinModel::getRM(deque <UInt32> &aref)
{

	ReinModel* rmRetP = this;

	if (aref.size() == 0) return rmRetP;
	if (aref.back() == 0) return rmRetP;  // обратный массив

	 // проход справа налево
	for (deque<UInt32>::reverse_iterator it = aref.rbegin(); it != aref.rend(); ++it)
	//for (size_t i = 0; i < aref.size(); i++)
	{
		UInt32 ind = *it;

		if (ind == 0) break; // криминал, там не должно быть нулей, хы-хы-хы

		MAP<UInt32, ReinModel>::iterator itt = rmRetP->arMrP.find(ind);

		if (itt != rmRetP->arMrP.end()) // found
		{
			// получили ссылку на модель для поиска далее вглубь
			rmRetP = &(rmRetP->arMrP[ind]); // ссылка на подмодель для следующй итерации
		}
		else
		{
			// путь обрывается?
			break;
		}
	}


	return rmRetP;

}


//////////////////////////////////////////
ReinModel* ReinModel::getRM(UInt32 rn) // поиск по одному номеру - используется в окошке позиций
{

	ReinModel* rmRetP = NULL;

	if (rn == 0) return this;

	for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); it != arMrP.end(); ++it)
		//for (int i = 0; i < MAX_REF_SLOT; i++)
	{
		if (it->first == rn) return &it->second;
	}

	//if (rmRetP == NULL)
	//{
	//	for (int i = 0; i < MAX_REF_SLOT; i++)
	//	{
	//		if (arMrP[i])
	//		{
	//			rmRetP = arMrP[i]->getRM(rn);

	//			if (rmRetP) break;
	//		}
	//	}	
	//}

	return NULL;

}


/////////////////////
long ReinModel::getPosByNum(long pnum)
{
	for (MAP<long, ReinPos>::iterator itt = curRM->arCurPos.begin(); itt != curRM->arCurPos.end(); ++itt)
	{
		if (itt->second.bar.pnum == pnum)
			return itt->first;
	}

	return 0;
}


/////////////////////
void ReinModel::setCached(bool bSetCached)
{
	bCached = bSetCached;
	for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); it != arMrP.end(); ++it)
	{
		it->second.setCached(bSetCached);
	}

}

//////////////////////////////////////////////////
ReinElm* ReinModel::findElementByFP(UInt32 fp)
{

	ReinElm* reP = NULL;

	for (MAP<UInt32, ReinElm>::iterator it = mapElms.begin(); it != mapElms.end(); ++it)
	{
		if (it->second.bel.ffpos[REIN_ELEM_ISO] == fp)
		{
			reP = &(it->second);
			break;
		}
	}

	if (reP) return reP;

	for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); it != arMrP.end(); ++it)
	{
		reP = it->second.findElementByFP(fp);

		if (reP) break;
	}

	
	return reP;

}

//////////////////////////////////////////////////
ReinElm* ReinModel::getReinElm(UInt32 fp)
{
	//ReinIndex ri;

	//if (vecElms.size() == 0) return NULL;
	if (mapElms.size() == 0) return NULL;

	MAP<UInt32, ReinElm>::iterator it = mapElms.find(fp);
	if (it != mapElms.end()) // found
		return &(it->second);


	//try
	//{
	//	//ri = mapElms[fp]; // no exception
	//	return &(mapElms.at(fp)); // exception
	//}
	//catch (...)
	//{
	//	return NULL;
	//}


	return NULL;

	//if (fp >= FILEPOS_LOC) fploc = fp - FILEPOS_LOC;

	//if (fploc > getIndMax()) 
	//{
	//	//if (bFlag == FALSE) mdlDialog_dmsgsPrint(L"ОШИБКА - превышен лимит памяти для отображения элементов (indmax)\n");
	//	//bFlag = TRUE;
	//	return NULL;
	//}

	//return arCurElms[fploc];

}



//////////////////////////////////////////////////////////////////////
/// <summary>
/// reload Bars data
/// </summary>
void ReinModel::reloadCurBars(bool bScan, bool bUpdateListBox, int iDepth, int iLoadRefs)
{
	ScanCriteria* scP;
	int             status;
	UShort          typeMask[6];

	//if (bNoLoad) return;

	if (elemCount < 0) return;

	DgnModelRefP mrP = modelP;

	if (mrP == NULL) return;

	writeLogIn(__FUNCTION__, 0);

	//mdlTMatrix_referenceToMaster (&tmFromRef, mrP);

	elemIterCount2 = 0;

	enumCount = 0;

	//====================

	//CatInfo ci;
	getCatInfo(&mrci, mrP, mdlModelRef_isActiveModel(mrP));

	if (iCfgVar_PosListMerge 
		&& curRM->mrci.catID > 0 && curRM->mrci.catID == mrci.catID 
		&& rnum > 0)
	{
		bRefPlus = true;
	}

	//====================

	//UInt32 arf[MAX_REFNUM_PATH];
	//int rfcnt = getRefPath(arf);

	scanFilePositions(this, mrP);

	//====================

	BINT bload = TRUE; // flag - turn on/off load data


	if (bScan)
	{
		/*
				if (updb)
					ups_db_close(updb, 0);

				upcnt++;

				// CREATE UPS DB
				//==========================================================
				upst = ups_env_create_db(upenv, &(updb), upcnt, 0, 0);
				//==========================================================
		*/

		//vecElms.clear();
		mapElms.clear();
		mapBars.clear();

		iClashShtamp++;
		/*
				UInt32 memloc = getIndMax() + 10;

				if (iDebug) sprintf(sLogMes, "memloc = %u (max fpos)\n", memloc); writeLog(0, 0);

				if (arCurElms)
				{
					for (int i = 0; i <= getIndMax(); i++)
					{
						if (arCurElms[i])
						{
							//if (arCurElms[i]->bMemGlobal == false)
							{
								if (iDebug) sprintf(sLogMes, "delete arCurElms[%i]...\n", i); writeLog(0, 0);
								delete arCurElms[i];
							}
							arCurElms[i] = NULL;
						}
					}

					if (iDebug) sprintf(sLogMes, "delete[] arCurElms[]...\n"); writeLog(0, 0);
					delete[] arCurElms;
					arCurElms = NULL;
				}

				//=============================
				//=============================
				if (iDebug) sprintf(sLogMes, "create new array: arCurElms = new _ReinElm* [%i]...\n", memloc); writeLog(0, 0);
				//=============================
				//=============================
		*/
		//=============================
		//mdlCnv_convertUnicodeToMultibyte(rmname, -1, tbi.msgText2, 256);
		deque <UInt32> aref;
		//UInt32 aref[MAX_REFNUM_PATH]; // обратный путь, для рефа 5->3->7 массив: [0] = 7, [1] = 3, [2] = 5
		tbi.msgText2[0] = 0x0;
		size_t refcnt = getRefPath(&aref);

		WCH stxt[100];
		for (deque<UInt32>::reverse_iterator it = aref.rbegin(); it != aref.rend(); ++it)
		//for (int i = refcnt - 1; i >= 0; i--)
		{
			SPRN(stxt, L("[ %u ]"), *it);
			if (SLEN(tbi.msgText2) > 0) SCAT(tbi.msgText2, L(" -> "));
			SCAT(tbi.msgText2, stxt);
		}
		SPRN(stxt, L(", q-ty %u"), elcount);
		SCAT(tbi.msgText2, stxt);
		//=============================

		if (iLoadRefs < 0) // turn off
		{
			bload = FALSE;
		}
		else if (iLoadRefs == 0) // by option
		{
			mdlRefFile_getBooleanParameters(&bload, REFERENCE_DISPLAYRASTERREFS, mrP);
		}
		// else 
		//	bload = TRUE;

		if (bload)
		{
			// ОТСЕИВАНИЕ REIN_ELEM_BAR происходит по типу элемента
			for (UShort a = 0; a < 6; a++) typeMask[a] = 0;

			typeMask[0] = TMSK0_LINE | TMSK0_ARC | TMSK0_LINE_STRING | TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;
			typeMask[1] = TMSK1_BSPLINE_CURVE;  // для результата развертки

			if (iDebug) sprintf(sLogMes, "begin scan...\n"); writeLog(0, 0);

			scP = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)iterateLoadReinBars, &mrci);
			status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
			mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
			status = mdlScanCriteria_setModel(scP, mrP);
			status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
			status = mdlScanCriteria_free(scP);

			if (iDebug) sprintf(sLogMes, "end scan\n"); writeLog(0, 0);

		}



	}
	else
	{
		long i = 0;

		if (mapElms.size() > 10000 && arCurPos.size() > 300)
			dlgProgressP = mdlDialog_completionBarOpen(TXT_115);

		for (MAP<UInt32, ReinElm>::iterator it = mapElms.begin(); it != mapElms.end(); ++it)
		{
			ReinElm* reP = &(it->second);
			int dirout = 0;

			if (reP)
			{
				ReinPos* rpP = NULL;

				ReinModel* rmSrchP = this;
				if (this->bRefPlus) rmSrchP = curRM;

				for (MAP<long, ReinPos>::iterator itt = rmSrchP->arCurPos.begin(); itt != rmSrchP->arCurPos.end(); ++itt)
				{
					ReinPos* rpItP = &itt->second;

					if (barsEqual(&reP->bel, &rpItP->bar, &dirout))
					{
						rpP = rpItP;
						break;
					}
				}

				if (iDebug) sprintf(sLogMes, "set position...\n"); writeLog(0, 0);
				setPosition(rpP, reP, this, dirout);
			}

			if (dlgProgressP)
			{
				int sz = (int)mapElms.size();
				if (sz)
				{
					mdlDialog_completionBarUpdate(dlgProgressP, 0, i * 100 / sz);
					WaitMessage();
					i++;
				}
			}

		}

		if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);

	}

	if (bload && iDepth > 0)
	{
		for (MAP<UInt32, ReinModel>::iterator it = arMrP.begin(); it != arMrP.end(); ++it)
		{
			// выключенные референсы грузятся в ReinModel::Init()

			it->second.reloadCurBars(bScan, bUpdateListBox && (it->first == curPos_ind), iDepth - 1, iLoadRefs);
		}
	}



	setPosArrayInfo(this, bScan);

	//mdlUtil_quickSort(arCurPos[rn], iCurPos[rn], sizeof(ReinPos), sortReinPos);

	if (bUpdateListBox) updateListBoxPos(TRUE);



	writeLogOut(__FUNCTION__, 0);


}

////////////////////////////////
ELID reinbar::saveReinData(ELID datelemid)
{
	ELID elid = 0;
	MSElementDescr* pXmlFragmentElement = NULL;
	int status;
	XMLFragmentListP pCurrent = NULL;

	writeLogIn(__FUNCTION__, 0);

	//=========================================

	setReinDataString(sCurPos);
	//sprintf(sLogMes, "data string '%s'\n", sCurPos); writeLog(0, 0);

	SCPM2W(wss, sCurPos, 5000);

	pCurrent = mdlXMLFragmentList_construct(wss, NULL, appID, appTypeReinData);

	// create new one
	status = mdlXMLFragmentList_createXMLElementDescriptor(&pXmlFragmentElement, &pCurrent, TRUE);

	if (NULL != pXmlFragmentElement)
	{

		UInt32 fp;

		if (datelemid == 0)
		{
			fp = mdlElmdscr_add(pXmlFragmentElement);
			elid = mdlElement_getID(&pXmlFragmentElement->el);
		}
		else
		{
			ELREF eref = getElemRefByID(ACTIVEMODEL, datelemid);

			if (eref)
			{
				ReinData rd;
				MSElementDescr* edp = NULL;

				mdlElmdscr_getByElemRef(&edp, eref, ACTIVEMODEL, FALSE, 0);

				if (edp && readReinDataFromElmd(&rd, edp, this) == SUCCESS)
				{
					mdlElmdscr_rewrite(pXmlFragmentElement, NULL, mdlElmdscr_getFilePos(edp));
					elid = mdlElement_getID(&pXmlFragmentElement->el);
					mdlElmdscr_freeAll(&edp);
				}
			}
		}

		mdlElmdscr_freeAll(&pXmlFragmentElement);

		//scanFileReinData(ACTIVEMODEL); // или просто добавлять
	}

	if (iDebug) sprintf(sLogMes, "return %I64u\n", elid); writeLog(0, 0);
	writeLogOut(__FUNCTION__, 0);

	elemid = elid;

	return elid;

}

//////////////////////////////////////////////
void reinbar::setReinDataString(WCH* str)
{

	int trmp[6] = { 0 };
	//ZeroMemory(trmp, sizeof(trmp));

	if (term[0] == REIN_TERM_BEND)
	{
		trmp[0] = termPar[0][0];
		trmp[2] = termPar[1][0];
	}
	if (term[1] == REIN_TERM_BEND)
	{
		trmp[1] = termPar[0][1];
		trmp[3] = termPar[1][1];
	}
	if (term[0] == REIN_TERM_MUFT)
	{
		trmp[4] = termPar[2][0];
	}
	if (term[1] == REIN_TERM_MUFT)
	{
		trmp[5] = termPar[2][1];
	}

	int datt = 1;
	if (bartype != BT_AXIS) datt = bartype;

	if (space == 0) space = iSpaceDefault;

	SPRN(str, L("%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i"),
		diam,			// 0
		runmet,		// 1
		lap[0],		// 2
		lap[1],		// 3
		lap[2],		// 4
		bendrad,		// 5
		term[0],		// 6
		term[1],		// 7
		trmp[0],			// 8
		trmp[1],			// 9
		trmp[2],			// 10
		trmp[3],			// 11
		trmp[4],			// 12
		trmp[5],			// 13
		datt,				// 14
		poscalc,		// 15
		space,			// 16
		offset[0],		// 17
		offset[1]		// 18 минус поставить когда будет сделана отработка
	);

}

/////////////////////////
reinelm::reinelm(void)
{
	clear(3);
}
reinelm::~reinelm(void)
{
	clear();
}

//////////////////////////////
void reinelm::clear(int memres)
{
	bel.clear(memres);
	tel.clear(memres);

	type = 0; // REIN_ELEM_...
	iClip = 0;
	bClip = false;
	arNum = 0; // arCurPos position
	elemflags = 0; // REINEL_FLAG_...
	modvers = 0; // modelversion
	fpDup = 0; // дубликат
	relmref = NULL;

	//if (tedP)	mdlTransient_free(&tedP, 1);
	//tedP = NULL;

	bTransientInProgress = FALSE;

	for (int i = 0; i < 7; i++) { drwopt[i] = 0; }
}

////////////////////////////////////////////////////////////////
#ifdef _REIN_H_
extern "C"
DLLEXPORT
#endif
int reinelm::getElmFromString(wstring str, DgnModelRefP mrP)
{

	clear();

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;

	if (*it != L"REINELEM") return ERROR;

	// parent id
	IF_IT_nxt IF_IT_end return ERROR;
	if (swscanf(it->c_str(), L"%I64u", &bel.elemid) != 1) return ERROR;

	// 02 type
	IF_IT_nxt IF_IT_end return ERROR;
	type = _wtoi(it->c_str());

	// 03 diam
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.diam = _wtoi(it->c_str());

	// 04 runmet
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.runmet = _wtoi(it->c_str());

	// 05 transp
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.transp = _wtoi(it->c_str());

	// 06 numpts
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.numpts = _wtoi(it->c_str());
	bel.cnumpts = bel.numpts;

	// 07 mainSgmIndex
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.mainSgmIndex = _wtoi(it->c_str());
	if (bel.mainSgmIndex < 0) bel.mainSgmIndex = 0;
	if (bel.mainSgmIndex >= MAX_BAR_VERTICES) bel.mainSgmIndex = MAX_BAR_VERTICES - 2;

	// 08 mainPtsIndex
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.mainPtsIndex = _wtoi(it->c_str());
	if (bel.mainPtsIndex < 0) bel.mainPtsIndex = 0;
	if (bel.mainPtsIndex >= MAX_BAR_VERTICES) bel.mainPtsIndex = MAX_BAR_VERTICES - 1;

	// 09 inum
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.inum = _wtoi(it->c_str());

	// 10 term
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.term[0] = _wtoi(it->c_str());

	// 11 term
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.term[1] = _wtoi(it->c_str());

	int par = 0;

	// 12 termPar
	IF_IT_nxt IF_IT_end return SUCCESS;
	{
		par = _wtoi(it->c_str());
		if (par >= -180 && par <= 180) bel.termPar[0][0] = par; else bel.termPar[0][0] = 0;
	}

	// 13 termPar
	IF_IT_nxt IF_IT_end return SUCCESS;
	{
		par = _wtoi(it->c_str());
		if (par >= -180 && par <= 180) bel.termPar[0][1] = par; else bel.termPar[0][1] = 0;
	}

	// 14 termPar
	IF_IT_nxt IF_IT_end return SUCCESS;
	{
		par = _wtoi(it->c_str());
		if (par >= 0) bel.termPar[1][0] = par; else bel.termPar[1][0] = 0;
	}

	// 15 termPar
	IF_IT_nxt IF_IT_end return SUCCESS;
	{
		par = _wtoi(it->c_str());
		if (par >= 0) bel.termPar[1][1] = par; else bel.termPar[1][1] = 0;
	}

	// 16 termPar
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.termPar[2][0] = _wtoi(it->c_str());

	// 17 termPar
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.termPar[2][1] = _wtoi(it->c_str());

	// 18 axid
	IF_IT_nxt IF_IT_end return SUCCESS;
	{
		if (swscanf(it->c_str(), L"%I64u", &bel.axid) != 1) bel.axid = 0;
	}

	// 19 modvers
	IF_IT_nxt IF_IT_end return SUCCESS;
	modvers = _wtoi(it->c_str());

	if (mrP
		&& modvers != iModelVers
		&& (bModelCheckRefs == TRUE || mdlModelRef_isActiveModel(mrP)))
	{
		bModelOutOfDate = TRUE;
	}

	// 20 bendrad
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.bendrad = _wtoi(it->c_str());

	// 21 bartype
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.bartype = _wtoi(it->c_str());

	// 22 poscalc
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.poscalc = _wtoi(it->c_str());

	int ilap = 0;

	// 23 ilap
	IF_IT_nxt IF_IT_end return SUCCESS;
	ilap = _wtoi(it->c_str());

	if (ilap > 0) bel.lap[0] = ilap;
	if (ilap < 0) bel.lap[1] = -ilap;

	// 24 noplanar
	IF_IT_nxt IF_IT_end return SUCCESS;
	bel.noplanar = _wtoi(it->c_str());

	// 25 element flags
	IF_IT_nxt IF_IT_end return SUCCESS;
	elemflags = _wtoi(it->c_str());

	// 26 3d bar if exists
	IF_IT_nxt IF_IT_end return SUCCESS;
	{
		if (swscanf(it->c_str(), L"%I64u", &bel.brid) != 1) bel.brid = 0;
		//bel.ffpos[REIN_ELEM_BAR] = STOI(token); // bar ElementId
	}

	// 27 ground
	IF_IT_nxt IF_IT_end return SUCCESS;
	{
		int a = _wtoi(it->c_str());
		bel.grnd = (a != 0);
	}

	if (!(elemflags & REINEL_FLAG_BEND)) // старый метод отрисовки загибов
	{
		// по умолчанию
		if (bel.termPar[0][0] == 0) bel.termPar[0][0] = 180;
		if (bel.termPar[0][1] == 0) bel.termPar[0][1] = -180;
		if (bel.termPar[1][0] == 0) bel.termPar[1][0] = getReinLapBend(bel.diam, 0);
		if (bel.termPar[1][1] == 0) bel.termPar[1][1] = getReinLapBend(bel.diam, 0);
	}

	return SUCCESS;


}

////////////////////////////////////////////////////////////////
#ifdef _REIN_H_
extern "C" DLLEXPORT
#endif
int reinelm::getElmFromElement(MSElementCP elP, DgnModelRefP mrP)
{

	int res = SUCCESS;

	XMLFragmentListP  oXMLFragmentList = NULL;


	writeLogIn(__FUNCTION__, 0);


	if (iDebug) { sprintf(sLogMes, "start to clear reP\n"); writeLog(0, 0); }
	clear();
	if (iDebug) { sprintf(sLogMes, "end clear reP\n"); writeLog(0, 0); }

	//__try
	{
		/*

		if (!mdlElement_hasXMLFragmentAttachment((MSElementP)elP, &appID, &appTypeReinElm))
		{
			//sprintf(sLogMes, "element has no xml attached\n"); writeLog(0, 0);
			res = ERROR;
		}*/
		//else
		//{
		//	sprintf(sLogMes, "element has xml attached\n"); writeLog(0, 0);
		//}

		if (res == SUCCESS && mdlXMLFragmentList_extractFromElementByAppIDAndType(&oXMLFragmentList, (MSElementP)elP,
			&appID, &appTypeReinElm) == SUCCESS)
		{
			XMLFragmentP  pXMLFragment;
			MSWCH* wtxt;
			//WCH ctxt[500];

			pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

			if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
			{
				wstring str(wtxt);

				res = getElmFromString(str, mrP); //func read ReinElm From String call

				mdlXMLFragmentList_free(&oXMLFragmentList);
			}
			else
			{
				//sprintf(sLogMes, "can not get xml from xml fragment\n"); writeLog(0, 0);
				res = ERROR;
			}

		}
		else
		{
			//sprintf(sLogMes, "can not extract xml from element\n"); writeLog(0, 0);
			res = ERROR;
		}

		if (mrP) bel.modrefP = mrP;

		if (res == SUCCESS && bel.transp < 10)
		{
			if (EQ(mdlElement_getTransparency(elP), 0.9)) // для совместимости когда еще не было transp
				bel.transp = REIN_TRANSP_INN;
			else
				bel.transp = REIN_TRANSP_OUT;
		}



		//if (mdlElement_getType(elP) == ARC_ELM)
		//{
		//	double drad[2];
		//	mdlArc_extract(0, 0, 0, &drad[0], &drad[1], 0, 0, elP);
		//	bel.rad[0] = (int)roundex(mdlCnv_uorsToMasterUnits(drad[0]));
		//	bel.rad[1] = (int)roundex(mdlCnv_uorsToMasterUnits(drad[1]));
		//}

		//writeLogOut(__FUNCTION__, 0);
	}
	//__except (filterException(GetExceptionCode(), GetExceptionInformation()))
	//{
	//	res = ERROR;
	//}

	writeLogOut(__FUNCTION__, 0);

	return res;



}

/////////////////////////////////////////////////////////////////
extern "C" DLLEXPORT long mdlRein_getPosNum(ELID elemid)
{

	ELREF eref = getElemRefByID(ACTIVEMODEL, elemid);

	if (eref == NULL) return 0;

	UInt32 fp = elementRef_getFilePos(eref);

	ReinElm* reP = curRM->getReinElm(fp);

	if (reP)
	{
		return reP->bel.pnum;
	}

	return 0;
}

/////////////////////////////////////////////////////////////////
extern "C" DLLEXPORT ReinElm* mdlRein_getReinElm(UInt32 fp)
{
	return curRM->getReinElm(fp);;
}


