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

#if defined(AECOSIM)

#include <tfapi\CatalogCollection.h>
#include <tfapi\BuildingEditElemHandle.h>
#include <tfapi\ListModelHelper.h>
//#include <tfapi\interface/ElemHandle.h>
//#include <tfapi\interface/ILocate.h>

#include <tfapi\mdltfmodelref.fdf>
#include <tfapi\mdltfframe.fdf>
#include <tfapi\mdltfwstring.fdf>
#include <tfapi\mdltfprojection.fdf>
#include <tfapi\mdltfcelllib.fdf>
#include <tfapi\mdltfform.fdf>
#include <tfapi\mdltflform.fdf>
#include <tfapi\mdltffrform.fdf>
#include <tfapi\mdltfperfo.fdf>
#include <tfapi\mdltfpoly.fdf>
#include <tfapi\mdltfglobal.fdf>
#include <tfapi\mdltfpartref.fdf>
#include <tfapi\mdltfbrep.fdf>
#include <tfapi\mdltfslform.fdf>
#include <tfapi\mdltfstprop.fdf>
#include <mstn\XmlTools\mdlxmltools.fdf>
#endif

#include "reinccmd.h"


#elif defined (MSVERSION) && (MSVERSION == 0x8b0)

#include <MicroStationAPI.h>
#include <DisplayStyleManager.h>
#include <Interface/ISessionMgr.h>

#include <symboldef.h> 
#include <Interface/inamedview.h> 
#include <Interface/element/ViewElementHandlerSubTypes.h> 

#if defined(AECOSIM)

#include <buildingeditelemhandle.h>
#include <CatalogCollection.h>
#include <ListModelHelper.h>
#include <interface/ElemHandle.h>
#include <interface/ILocate.h>

#endif


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

#if defined(AECOSIM)
#include <mdltfmodelref.fdf>
#include <mdltfframe.fdf>
#include <mdltfwstring.fdf>
#include <mdltfprojection.fdf>
#include <mdltfcelllib.fdf>
#include <mdltfform.fdf>
#include <mdltflform.fdf>
#include <mdltffrform.fdf>
#include <mdltfperfo.fdf>
#include <mdltfpoly.fdf>
#include <mdltfglobal.fdf>
#include <mdltfpartref.fdf>
#include <mdltfbrep.fdf>
#include <mdltfslform.fdf>
#include <mdltfstprop.fdf>
#include <mdlxmltools.fdf>
#endif

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

//ViewMonitor	g_oViewMonitor;

#include "reinfunc.h"


///////////////////////////////////////////////////////////
void myClip_free(CLIPDESC clipP, MSElementDescrP* edClipPP)
{

	if (edClipPP && iCfgVar_SavedViewClip)
	{
		if (*edClipPP) mdlElmdscr_freeAll(edClipPP);
	}

	if (ISNULL(clipP)) return; // tipa sam osvobodit

#if defined (MSVERSION) && (MSVERSION == 0x8b0)
	mdlClip_free(&clipP);
#endif
}

///////////////////////////////////////////////////
ELREF getElemRefByID(DgnModelRefP mrP, ELID id)
{

	ELREF eref = NULL;

#if defined (MSVERSION) && (MSVERSION == 0xa00) 
	if (SUCCESS == eeh.FindByID(id, mrP)) eref = eeh.GetElementRef();
#else
	eref = dgnCache_findElemByID (mdlModelRef_getCache(mrP), id);
#endif

	return eref;
}

///////////////////////////////////////////////////
ELREF getElemRefByFPos(DgnModelRefP mrP, UInt32 fp, int bSkipDeleted)
{

	ELREF eref = NULL;

#if defined (MSVERSION) && (MSVERSION == 0xa00) 
	eref = mdlModelRef_getElementRef(mrP, fp);
#else
	eref = dgnCache_findElemByFilePos(mdlModelRef_getCache(mrP), fp, bSkipDeleted);
#endif

	return eref;
}




///////////////////////////////////////////
int getCfgVar(
	WCH* val // may be NULL
	, WCH* nam)
{
	int ret = SUCCESS;

#if defined (MSVERSION) && (MSVERSION == 0xa00) 

	WString cfgvar;
	ret = mdlSystem_getCfgVar(&cfgvar, nam);
	if (ret == SUCCESS)
	{
		if (val) SCPY(val, cfgvar.c_str());
	}
#else

	char* cfgvar = NULL;
	cfgvar = mdlSystem_getExpandedCfgVar(nam);

	if (cfgvar == NULL)
		ret = ERROR;
	else
	{
		if (val) SCPY(val, cfgvar);
		mdlSystem_freeCfgVarBuffer(cfgvar);

	}

#endif

	return ret;
}

int getCfgVarEx(WCH* valP, MSWCH* nam)
{
	WCH wnam[100];

	SCPW2M(wnam, nam, 100);

	return getCfgVar(valP, wnam);
}


//////////////////////////
void printLogLine(char* sline, int id, char* strdop, int icmnt)
{
	int i;

//#if defined (MSVERSION) && (MSVERSION == 0xa00)

	if (!fileLog.is_open()) return;

	if (sline)
	{
		if (sline[strlen(sline) - 1] == '\n')
			sline[strlen(sline) - 1] = '\0';
	}
	else
		return;

	for (i = 0; i < ilev; i++)
		fileLog.write("\t", 1);

	if (icmnt)
		sprintf(sLogMesOut, "<!-- %s -->\n\0\0", sline);
	else if (id > 0 && strdop)
		sprintf(sLogMesOut, "<%s arg=\"%s\" time=\"%lld\" >\n\0\0", sline, strdop, (long long)tloc[2]);
	else if (id > 0 && strdop == NULL)
		sprintf(sLogMesOut, "<%s time=\"%lld\" >\n\0\0", sline, (long long)tloc[2]);
	else if (id < 0)
	{
		if (strdop && strlen(strdop) > 0)
		{
			fileLog.write("\t", 1); // add tab to line

			sprintf(sLogMesOut, "<exit arg=\"%s\" time=\"%lld\" />\n\0\0", strdop, (long long)tloc[2]);
			fileLog.write(sLogMesOut, strlen(sLogMesOut));

			for (i = 0; i < ilev; i++) // repeat
				fileLog.write("\t", 1);
		}

		sprintf(sLogMesOut, "</%s >\n\0\0", sline); // time не добавляется так как xml хуже работает
	}
	else if (id == 0 && strdop)
		sprintf(sLogMesOut, "<%s arg=\"%s\" time=\"%lld\" />\n\0\0", sline, strdop, (long long)tloc[2]);
	else if (id == 0 && strdop == NULL)
		sprintf(sLogMesOut, "<%s time=\"%lld\" />\n\0\0", sline, (long long)tloc[2]);

	fileLog.write(sLogMesOut, strlen(sLogMesOut));


//#else

	//if (fileLog == NULL) return;

	//fprintf(fileLog, "%i ", tloc[2]);

	//for (i = 0; i < ilev; i++)
	//	fprintf(fileLog, "\t");

//#endif

}


/*
//////////////////////////
void printLogLinePrefix()
{
	int i;

#if defined (MSVERSION) && (MSVERSION == 0xa00)

	if (!fileLog.is_open()) return;

	//char sloc[50];
	//sprintf(sloc, "%lld \0\0", (long long)tloc[2]);
	//fileLog.write(sloc, strlen(sloc));

	for (i = 0; i < ilev; i++)
		fileLog.write("\t", 1);

	char* sloc = "< ";
	fileLog.write(sloc, strlen(sloc));

#else

	if (fileLog == NULL) return;

	fprintf(fileLog, "%i ", tloc[2]);

	for (i = 0; i < ilev; i++)
		fprintf(fileLog, "\t");

#endif

}

//////////////////////////
void printLogLineSuffix()
{
	int i;

#if defined (MSVERSION) && (MSVERSION == 0xa00)

	if (!fileLog.is_open()) return;

	char sloc[50];
	sprintf(sloc, " time=\"%lld\" >\n\0\0", (long long)tloc[2]);
	fileLog.write(sloc, strlen(sloc));

#else

	//if (fileLog == NULL) return;

	//fprintf(fileLog, "%i ", tloc[2]);

	//for (i = 0; i < ilev; i++)
	//	fprintf(fileLog, "\t");

#endif

}
*/


////////////////////////////
void closeLogFile()
{
	if (iDebug == 0) return;

//#if defined (MSVERSION) && (MSVERSION == 0xa00)
	if (fileLog.is_open())
	{
		fileLog.close();
	}
//#else
//	if (fileLog != NULL)
//	{
//		mdlTextFile_close(fileLog);
//		fileLog = NULL;
//	}
//#endif
}


////////////////////////////
void openLogFile(int bAppend)
{
	if (iDebug == 0) return;

	closeLogFile();

//#if defined (MSVERSION) && (MSVERSION == 0xa00)
	if (bAppend)
		fileLog.open(sFileLog, ofstream::app);
	else
	{
		fileLog.open(sFileLog, ofstream::out);

		char* hdr = "<?xml version=\"1.0\" encoding=\"Windows-1251\"?>\n";

		if (fileLog.is_open()) fileLog.write(hdr, strlen(hdr));
	}
//#else
//	if (bAppend)
//		fileLog = mdlTextFile_open (sFileLog , TEXTFILE_APPEND);
//	else
//		fileLog = mdlTextFile_open (sFileLog , TEXTFILE_WRITE);
//#endif


	//if (fileLog == NULL)
	//	mdlOutput_printf(MSG_MESSAGE, "Error opening log file %s\n", sName);

	if (bAppend == FALSE) ilev = 0;

}


////////////////////////////////
void writeLog(char* str, int ld, char* strdop, int icmnt)
{

//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//	return;
//#endif
	/*
	int i;
	stringstream str(stringstream::out | stringstream::binary);

	for (i = 0; i < 1000; i++)
	{
		str << i << " " << (i % 2) << " " << i + 100 << endl;
	}
	ofstream datFile;
	datFile.open("test.dat", ofstream::binary);
	datFile.write(str.str().c_str(), str.str().length());
	datFile.close();
*/


	if (iDebug == 0) return;

	if (updevents[0] == 2) 
		return;
	

	char* sstr = str;
    
    tloc[0] = clock();
    
    tloc[2] = tloc[0] - tloc[1];
    
    tloc[1] = tloc[0];
    
	
	if (str == NULL) sstr = sLogMes;

	if (iDebug == 2) openLogFile(TRUE);
	

//#if defined (MSVERSION) && (MSVERSION == 0xa00)
	if (fileLog.is_open())
	{
		if (ld < 0 && ilev > 0) ilev += ld; // always += ld 

		printLogLine(sstr, ld, strdop, icmnt);

		//fileLog.write(sstr, strlen(sstr));

		if (ld > 0) ilev += ld;
	}
//#else
//	if (fileLog) 
//	{
//		if (ld < 0 && ilev > 0) ilev += ld; // always += ld 
//		
//		printLogLinePrefix();
//		
//		fprintf(fileLog, sstr);
//		
//		if (ld > 0) ilev += ld;
//	}
//#endif
	
	
	
	if (iDebug == 2) closeLogFile();
	
	
}

////////////////////////////////////
void writeLogW(MSWCH* wstr, int ld)
{
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//	return;
//#endif

	if (iDebug == 0) return;

	if (wstr)
	{
		mdlCnv_convertUnicodeToMultibyte(wstr, -1, sLogMes, 1000);
		writeLog(0, ld);
	}

}

////////////////////////////////
void writeLogIn(char* sFuncName, char* str)
{
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//	return;
//#endif

	if (iDebug == 0) return;

	sprintf(sLog, "%s()", sFuncName);

	//if (str)
	//{
	//	strcat(sLog, " - ");
	//	strcat(sLog, str);

	//strcat(sLog, "\n");

	writeLog(sLog, 1, str);
}

////////////////////////////////
void writeLogOut(char* sFuncName, char* str, int bReset)
{
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//	return;
//#endif

	if (iDebug == 0) return;

	sprintf(sLog, "%s()", sFuncName);

	//if (str)
	//{
	//	strcat(sLog, " - ");
	//	strcat(sLog, str);
	//}
	//strcat(sLog, "\n");

	writeLog(sLog, -1, str);

	if (bReset && updevents[0] == 2) updevents[0] = 1; // вкл лог обратно если выключен

}



//////////////////////
void copySpaceData(ReinSpace* rsP, ReinBar* rbP, int bSpaceToBar, ReinSpace* rsOptP, int iCopySegmIndex)
{
	copySpaceData(rsP, rbP, bSpaceToBar, rsOptP, iCopySegmIndex, FALSE);
}

/////////////////////////////////////////////////////
void copySpaceData(ReinSpace* rsP, ReinBar* rbP, int bSpaceToBar, ReinSpace* rsOptP, int iCopySegmIndex, int bIncrContNum)
{

	//rbP->runmet, 
	//rbP->diam,
	//rbP->segmIndex,
	//rbP->elemEDoffset,
	//rbP->space, // аргументы используются если создается SURFACE_ELM
	//rbP->offset[0],
	//rbP->offset[1],
	//rbP->lap[0],
	//rbP->lap[1],
	//rbP->lap[2]
	//rbP->term[0],
	//rbP->term[1],
	//rbP->termPar[0][0]
	//rbP->termPar[0][1]
	//rbP->termPar[1][0]
	//rbP->termPar[1][1]
	//rbP->termPar[2][0]
	//rbP->termPar[2][1]

	writeLogIn(__FUNCTION__, 0);


	if (bSpaceToBar)
	{
		rbP->clear();

		rbP->bartype = rsP->bartype;
		rbP->elemid = rsP->elid;

		if (bIncrContNum) rsP->contnum += 100;
		rbP->contnum = rsP->contnum;

		rbP->runmet = rsP->runmet;
		rbP->diam = rsP->diam;

		//rbP->space = rsP->space;
		rbP->spacef = rsP->spacef;
		//rbP->space2 = rsP->space2;
		rbP->spacerad = rsP->spacerad;
		rbP->bendrad = rsP->bendrad;
		rbP->poscalc = rsP->poscalc;

		rbP->offset[0] = rsP->offset[0];
		rbP->offset[1] = rsP->offset[1];

		rbP->lap[0] = rsP->lap[0];
		rbP->lap[1] = rsP->lap[1];
		rbP->lap[2] = rsP->lap[2];

		rbP->term[0] = rsP->trm[0];
		rbP->term[1] = rsP->trm[1];

		for (int i = 0; i < 10; i++)
		{
			rbP->termPar[i][0] = rsP->trmPar[i][0];
			rbP->termPar[i][1] = rsP->trmPar[i][1];
		}

		//rbP->termPar[0][1] = rsP->trmPar[0][1];
		//rbP->termPar[1][0] = rsP->trmPar[1][0];
		//rbP->termPar[1][1] = rsP->trmPar[1][1];
		//rbP->termPar[2][0] = rsP->trmPar[2][0];
		//rbP->termPar[2][1] = rsP->trmPar[2][1];

		if (iCopySegmIndex)
		{
			rbP->segmIndex = rsP->segmIndex;
			rbP->elemEDoffset = rsP->elemEDoffset;
		}
		else
		{
			rbP->segmIndex = rsP->pts_org_cnt;
			rbP->elemEDoffset = 0;
		}
	}
	else
	{
		if (rsOptP == NULL) rsP->clear();

		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->bartype)) 
		{
			rsP->bartype = rbP->bartype;
			rsP->elid = rbP->elemid;
			rsP->contnum = rbP->contnum;
		}

		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->runmet)) rsP->runmet = rbP->runmet;
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->diam)) rsP->diam = rbP->diam;

		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->space)) rsP->spacef = rbP->spacef; //rsP->space2 = rbP->space2;
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->spacerad)) rsP->spacerad = rbP->spacerad;
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->bendrad)) rsP->bendrad = rbP->bendrad;
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->poscalc)) rsP->poscalc = rbP->poscalc;

		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->offset[0])) rsP->offset[0] = rbP->offset[0];
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->offset[1])) rsP->offset[1] = rbP->offset[1];

		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->lap[0])) rsP->lap[0] = rbP->lap[0];
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->lap[1])) rsP->lap[1] = rbP->lap[1];
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->lap[2])) rsP->lap[2] = rbP->lap[2];

		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->trm[0])) rsP->trm[0] = rbP->term[0];
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->trm[1])) rsP->trm[1] = rbP->term[1];

		// исп. только rsOptP->trmPar[0], т.к. галка одна
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->trmPar[0][0])) rsP->trmPar[0][0] = rbP->termPar[0][0];
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->trmPar[0][1])) rsP->trmPar[0][1] = rbP->termPar[0][1];
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->trmPar[0][0])) rsP->trmPar[1][0] = rbP->termPar[1][0];
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->trmPar[0][1])) rsP->trmPar[1][1] = rbP->termPar[1][1];
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->trmPar[0][0])) rsP->trmPar[2][0] = rbP->termPar[2][0];
		if (rsOptP == NULL || (rsOptP != NULL && !rsOptP->trmPar[0][1])) rsP->trmPar[2][1] = rbP->termPar[2][1];

		if (iCopySegmIndex)
		{
			rsP->segmIndex = rbP->segmIndex;
			rsP->elemEDoffset = rbP->elemEDoffset;
		}
		else
		{
			rbP->segmIndex = 0;
			rbP->elemEDoffset = 0;
		}


	}

	writeLogOut(__FUNCTION__, 0);


}


#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX

/////////////////
bool checkProps( // NU
	WCharP attr,
	WCharP digit,
	DgnECInstancePtr instNew,
	DgnECInstancePtr instOld,
	MSElementDescr*       newEdP
)
{
	WChar atrName[100];
	WChar atrName2[100];
	wcscpy(atrName, attr);
	wcscat(atrName, digit);

	EditElementHandle eh(newEdP, false, true);

	WCharP list[] = { L"ReinBendType", L"ReinMuftType", L"ReinBendRezb", L"ReinBendSkob", L"ReinBendSvar" };

	ECN::ECValue v;
	ECN::ECValue vv;
	bool bShon = false;

	if (instNew->GetValue(v, atrName) == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success &&
		instOld->GetValue(vv, atrName) == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
	{
		if (v.GetInteger() != vv.GetInteger())
		{
			vv.SetInteger(0);

			for (int i = 0; i < 5; i++)
			{
				wcscpy(atrName2, list[i]);
				wcscat(atrName2, digit);

				if (wcscmp(atrName, atrName2) != 0)
				{
					if (instNew->SetValue(atrName2, vv) == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
						instNew->ScheduleWriteChanges(eh);
				}
			}

			bShon = true;
		}
	}


	return bShon;
}


/////////////////////
UInt32 checkAttribModel( // NU
	WCharP schemaName,
	WCharP className,
	DgnModelP  dmP
)
{


	/*
	FindInstancesScopePtr scopeNew = FindInstancesScope::CreateScope(*mrP, FindInstancesScopeOption(DgnECHostType::Model));
	if (!scopeNew.IsValid()) return ret;

	ECQueryPtr query = ECQuery::CreateQuery(schemaName, className);
	if (!query.IsValid()) return ret;

	DgnECInstanceIterable iterableNew = Bentley::DgnPlatform::DgnECManager::GetManager().FindInstances(*scopeNew, *query);

	if (ISNULL(iterableNew)) return ret;

	DgnECInstanceIterable::const_iterator itNew = iterableNew.begin();

	if (*itNew == NULL) return ret;

	DgnECInstancePtr instNew = *itNew;

	if (instNew.IsValid())
		ret = 1;
*/

	return 0;
}

/////////////////////
DgnECInstancePtr getECInstance(
	WCharP schemaName,
	WCharP className,
	MSElementDescrP       edP
)
{
	DgnECInstancePtr ret;

	if (edP == NULL) return ret;

	ElementHandle elemNew(edP, false, true);

	if (elemNew.GetElementRef() == NULL) return ret;

	FindInstancesScopePtr scopeNew = FindInstancesScope::CreateScope(elemNew, FindInstancesScopeOption(DgnECHostType::Element));
	if (!scopeNew.IsValid()) return ret;

	ECQueryPtr query = ECQuery::CreateQuery(schemaName, className);
	if (!query.IsValid()) return ret;

	DgnECInstanceIterable iterableNew = Bentley::DgnPlatform::DgnECManager::GetManager().FindInstances(*scopeNew, *query);

	if (ISNULL(iterableNew)) return ret;

	DgnECInstanceIterable::const_iterator itNew = iterableNew.begin();
	
	return *itNew;

	//if (instNew.IsValid())
	//{
		//DgnElementECInstanceCP eiP = instNew->GetAsElementInstance();

		//ret = eiP->GetLocalId();

		//ECN::ECClassCR instClassNew = instNew->GetClass();

		//ECN::ECPropertyP propP = instClassNew.GetPropertyP(L"ReinBendType1");

		//for (ECN::ECPropertyIterable::const_iterator it_local = properties.begin(); it_local != properties.end(); ++it_local)
		//{
		//	ECN::ECValue v;
		//	ECN::ECPropertyCP pProp = (*it_local);
		//	if (SUCCESS == instance->GetValue(v, pProp->GetName().c_str()))
		//		classText += pProp->GetName() + WString(L"  ") + v.ToString() + WString(L"\n");
		//	
		//	
		//}

		
		//bool bShon = checkProps(L"ReinBendType", L"1", instNew, instOld, newEdP);
		//if (!bShon) bShon = checkProps(L"ReinMuftType", L"1", instNew, instOld, newEdP);
		//if (!bShon) bShon = checkProps(L"ReinBendRezb", L"1", instNew, instOld, newEdP);
		//if (!bShon) bShon = checkProps(L"ReinBendSkob", L"1", instNew, instOld, newEdP);
		//if (!bShon) bShon = checkProps(L"ReinBendSvar", L"1", instNew, instOld, newEdP);

		//bShon = checkProps(L"ReinBendType", L"2", instNew, instOld, newEdP);
		//if (!bShon) bShon = checkProps(L"ReinMuftType", L"2", instNew, instOld, newEdP);
		//if (!bShon) bShon = checkProps(L"ReinBendRezb", L"2", instNew, instOld, newEdP);
		//if (!bShon) bShon = checkProps(L"ReinBendSkob", L"2", instNew, instOld, newEdP);
		//if (!bShon) bShon = checkProps(L"ReinBendSvar", L"2", instNew, instOld, newEdP);
		
	//}

	//return ret;

}

#endif

////////////////////////////
int myClip_getRefBoundary(
	CLIPDESC* clipPP,
	DgnModelRefP       mrP,
	MSElementDescrP* edClipPP, // предполагаемый элемент клипа, надо потом освободить если получен клип
	int       view
)
{
	int ret = ERROR;
	//ClipDescrP clipP = *clipPP;


	ELID viewid = 0;
	int st = mdlRefFile_getInt64Parameters(&viewid, REFERENCE_SAVEDVIEWELEMENTID, mrP); // 18087912+ 18087885-

	if (st == SUCCESS && viewid > 0 && edClipPP && iCfgVar_SavedViewClip)
	{
		ELREF eref = getElemRefByID(mrP, viewid);
		

		if (eref)
		{
			mdlElmdscr_getByElemRef(edClipPP, eref, mrP, FALSE, 0);

			if (*edClipPP)
			{
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
					ret = mdlClip_fromElement(clipPP, *edClipPP, 1, 0, view);
#else
					ret = mdlClip_fromElement(*clipPP, *edClipPP, true, view);
#endif

				if (ret != SUCCESS) mdlElmdscr_freeAll(edClipPP);
			}

			if (ret != SUCCESS)
			{
				ELREF erefs[100];

				int numdep = mdlDependency_getDependentElementRefs(erefs, viewid, mrP, 100);

				for (int i = 0; ret != SUCCESS && i < numdep; i++)
				{
					mdlElmdscr_getByElemRef(edClipPP, erefs[i], mrP, FALSE, 0);

					if (*edClipPP)
					{
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
						ret = mdlClip_fromElement(clipPP, *edClipPP, 1, 0, view);
#else
						ret = mdlClip_fromElement(*clipPP, *edClipPP, true, view);
#endif

						if (ret != SUCCESS) mdlElmdscr_freeAll(edClipPP);
					}
				}
			}
		}
	}

	if (ret != SUCCESS)
	{
		ret = func_pma(mdlClip_getRefBoundary, *clipPP), mrP, view);
	}

	return ret;

}



/////////////////////////////////
extern "C" DLLEXPORT void cmdReinPlace(
char	*unparsedP
)
//cmdNumber   CMD_REIN_PLACE
{

/*
	iAC = CMD_REIN_PLACE;
	iACStep = 1;

	setDefaultStyles();

	syncToolbox();

	mdlState_startPrimitive ((StateFunc_DataPoint) reinPlacePoint, (StateFunc_Reset)mdlState_startDefaultCommand, 1, NULL);

	mdlAccuSnap_enableSnap(TRUE);

	MSDLGP db = mdlDialog_find(DLG_LICENSE, NULL);

	if (db)
	{
		//rDopInfo.dopopt[15] = 1;

		
		mdlSystem_defineCfgVar(L("REIN_LICENSE_AGREED"), L("1"), CFGVAR_LEVEL_USER);
		mdlSystem_rewriteCfgVarFile(0, L("REIN_LICENSE_AGREED"), L("1"));

		mdlDialog_closeCommandQueue(db);
	}

*/


}


/*

/////////////////////////////////
// NOT USING
int scanBarSetFenceHilite(
MSElementDescr  *edInP,
int* step,
ScanCriteria    *pScanCriteria					
)
{
	BINT bOver;
	CLIPDESC clipP = NULL;
	DgnModelRefP mrP = mdlScanCriteria_getModel(pScanCriteria);
	MSElementDescr* edP = NULL;
	BINT bInside = FALSE;


	ReinModel* rmP = curRM->getRM(mrP);
	
	if (rmP == NULL) return SUCCESS;

	//int refnum = getRefNum(mrP);

	//vector<UInt32> aref;
	//UInt32 aref[MAX_REFNUM_PATH]; // обратный путь, для рефа 5->3->7 массив: [0] = 7, [1] = 3, [2] = 5
	deque<UInt32> aref;
	size_t refcnt = rmP->getRefPath(&aref);


	//printf("%i %i\n", bInside, bOver);

	ReinElm relm;

	//mdlElmdscr_show(edInP, "  ");

	if (readReinElmIso(&relm, edInP, FALSE, FALSE) != SUCCESS)
		return SUCCESS;

	writeLogIn(__FUNCTION__, 0);

	if (aref.size() > 0) // ref
	//if (aref[0] > 0) // ref
	{
		mdlElmdscr_readToMaster(&edP, mdlElmdscr_getFilePos(edInP), mrP, 0, 0);
	}
	else
		edP = edInP;

	if (func_pma(mdlClip_getFence,clipP)) == SUCCESS)
		bInside = mdlClip_isElemInside(&bOver, edP, GETPTR(clipP), tcb->lstvw, FALSE);
	else
		bInside = TRUE;

	if (bInside && mdlElement_isEffectivelyVisible(&edP->el, mrP, tcb->lstvw))
	{

		if (*step == 0) 
			mdlLocate_hiliteElement (edInP->h.elementRef, mrP);
		else
		{

			curPos.drawmode = rInfo.option[16];
			curPos.bar.inum = relm.bel.inum;

			curPos.arefnum = aref;

			curPos.bar.elemid = relm.bel.elemid;

			for (map <wstring, ReinPos>::iterator rpItP = mapBarSet.begin(); rpItP != mapBarSet.end(); ++rpItP)
			//for (UInt32 i = 0; i < daCurBarSet.size(); i++)
			{
				//ReinPos* rpItP = &(daCurBarSet[i]);

				if (rpItP->second.bar.inum == relm.bel.inum &&
					rpItP->second.bar.elemid == relm.bel.elemid &&
					refPathsEQ(rpItP->second.arefnum, aref))
				{
					if (rpItP->second.bFromRef == false && // not from ref
						*step > 0)
					{
						deleteBarSetInfo(&rpItP->second, FALSE, FALSE);

						mapBarSet.erase(rpItP);
					}

					if (*step < 0)
					{
						mdlLocate_hiliteElement (edInP->h.elementRef, mrP);
					}
				}
			}

			if (*step > 0 && curPos.drawmode > 0) saveBarSetInfo(&curPos);

		}

	}

	if (aref.size() > 0 && edP)
	{
		mdlElmdscr_freeAll(&edP);
	}

	myClip_free(clipP, NULL);

	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;
}*/

////////////////////////////
int fenceContent(int* stepP)
{
	DgnModelRefP mrP;

	UInt32 filePos = mdlElement_getFilePos(FILEPOS_CURRENT, &mrP);

	ReinModel* rmP = curRM->getRM(mrP);

	if (rmP == NULL) return SUCCESS;

	deque<UInt32> aref;
	size_t refcnt = rmP->getRefPath(&aref);


	ReinElm relm;

	MSElementDescr* edInP = NULL;

	if (filePos && aref.size() > 0) // only ref
	{
		mdlElmdscr_readToMaster(&edInP, filePos, mrP, 0, 0);
	}


	if (edInP == NULL) return SUCCESS;



	if (readReinElmIso(&relm, edInP, FALSE, FALSE) == SUCCESS)
	{
		writeLogIn(__FUNCTION__, 0);

		//printf("  %u\n", filePos);

		ReinPos p;

		p.bar.modrefP = mrP;
		p.bar.elref = edInP->h.elementRef;

		p.bar.elemid = relm.bel.elemid;
		p.bar.inum = relm.bel.inum;

		p.arefnum = aref;

		if (iACStep == 0)
		{
			wstring str = p.getMapIdentString();

			map <wstring, ReinPos>::iterator it = curRM->mapBarSet.find(str); // 

			if (it != curRM->mapBarSet.end()) // found
			{
				it->second.bar.modrefP = mrP;
				it->second.bar.elref = edInP->h.elementRef;

				it->second.bUpdate = true;
			}
			else
			{
				p.bUpdate = true;

				curRM->mapBarSet[str] = p;
			}


		}
		//else if (iACStep == 1)
		//{
		//	for (map <wstring, ReinPos>::iterator rpItP = mapBarSet.begin(); rpItP != mapBarSet.end(); ++rpItP)
		//	{
		//		if (rpItP->second.bar.inum == relm.bel.inum &&
		//			rpItP->second.bar.elemid == relm.bel.elemid &&
		//			refPathsEQ(rpItP->second.arefnum, aref))
		//		{
		//			if (rpItP->second.bFromRef == false)
		//			{
		//				//rpItP->second.bUpdate = true;

		//				//deleteBarSetInfo(&rpItP->second, FALSE, FALSE);

		//				//if (rInfo.option[16])
		//				//{
		//				//	rpItP->second.drawmode = rInfo.option[16];
		//				//	saveBarSetInfo(&rpItP->second, FALSE);
		//				//}
		//				//else
		//				//	mapBarSet.erase(rpItP);
		//			}
		//		}
		//	}
		//}




		writeLogOut(__FUNCTION__, 0);
	}

	mdlElmdscr_freeAll(&edInP);

	return 0;
}

////////////////////////////////////
void barSetFenceProcess(int step)
{

	writeLogIn(__FUNCTION__, 0);

	if (step <= 0) mdlLocate_clearHilited(TRUE);
	
	//if (step == 0) mdlState_startPrimitive (
	//	(StateFunc_DataPoint)reinLocatePoint, 
	//	(StateFunc_Reset)mdlState_startDefaultCommand, 
	//	1, 0);

	
	//==================================
	// РАБОТАЕТ ТОЛБКО OVERLAP (VOID не тестировал)
	//==================================
	if (step == 0)
	{
		mdlState_startFenceCommand(
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
			(MdlFunctionP)fenceContent, // works as reinLocatePoint
#else
			(StateFunc_FenceContentOp)fenceContent, // works as reinLocatePoint
#endif
			NULL,
			(StateFunc_DataPoint)reinLocatePoint, 
			(StateFunc_Reset)mdlState_startDefaultCommand, 
			1, 0, FENCE_CLIP_ORIG);

		mdlFence_process(0); // only hilite, set bUpdate flags, runs fenceContent()

		for (map<wstring, ReinPos>::iterator rpItP = curRM->mapBarSet.begin(); rpItP != curRM->mapBarSet.end(); ++rpItP)
		{
			if (rpItP->second.bUpdate && rpItP->second.bar.elref && rpItP->second.bar.modrefP)
				mdlLocate_hiliteElement(rpItP->second.bar.elref, rpItP->second.bar.modrefP);
		}

	}
	else if (step == 1)
	{
		//mdlFence_process(0); // runs fenceContent()

		for (map <wstring, ReinPos>::iterator rpItP = curRM->mapBarSet.begin(); rpItP != curRM->mapBarSet.end(); ++rpItP)
		{
			if (rpItP->second.bUpdate)
			{
				deleteBarSetInfo(&rpItP->second, FALSE, FALSE);

				if (rInfo.option[16])
				{
					rpItP->second.drawmode = rInfo.option[16];

					saveBarSetInfo(&rpItP->second, FALSE);

					rpItP->second.bUpdate = false;
				}
				else
					curRM->mapBarSet.erase(rpItP);

			}
		}
	}

	/*
	ScanCriteria    *scP = NULL;
	UShort          typeMask[6];
	int status;
	
	for (UShort a = 0; a < 6; a++) typeMask[a] = 0;
	typeMask[0] = TMSK0_LINE | TMSK0_ARC | TMSK0_LINE_STRING | TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;


	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanBarSetFenceHilite, &step);
	status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
	status = mdlScanCriteria_setModel (scP, ACTIVEMODEL);
	mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);
	status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
	status = mdlScanCriteria_free (scP);


	// референсы
	{
		ModelRefIteratorP  iterator;
		DgnModelRefP	modelRef;

		mdlModelRefIterator_create (&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, -1); // nested

		while (NULL != (modelRef = mdlModelRefIterator_getNext (iterator)))
		{

			BINT isOn = FALSE;
			mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
			if (!isOn) continue;

			scP = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
			status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanBarSetFenceHilite, &step);
			status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
			status = mdlScanCriteria_setModel (scP, modelRef);
			mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);
			status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
			status = mdlScanCriteria_free (scP);

		}

		mdlModelRefIterator_free (&iterator);

	}
*/
	if (step > 0) 
	{
		// reloadHidingPositions(); // pushed after element save

		mdlState_startDefaultCommand();
	}


	writeLogOut(__FUNCTION__, 0);


}



/////////////////////////
MSDLGP findToolBox()
{
	MSDLGP dbP;

	if (NULL != (dbP = mdlDialog_find (DIALOGID_ToolSettings, NULL)))
		return dbP;
	else
		return NULL;
}

///////////////////
void syncToolbox()
{
	MSDLGP dbP;

	if (NULL != (dbP = findToolBox()))
	{
		mdlDialog_itemsSynch(dbP);
	}
}

/*
/////////////////////////////////////
UInt32  iterateElmdSketchTextSave   ( // using in reinSideDynamics()
MSElement       *element,   //  => element to act upon 
void            *params,    //  => passed from original call 
int             operation,  //  => why you were called 
UInt32           offset,     //  => offset from header 
MSElementDescr  *elemDscrP  //  => element descr 
)
{
	mdlElement_add(element);

	return 0;
}
*/


///////////////////////////
int iterateElmdGetElmOffset    (
MSElement       *element,   //  => element to act upon 
void            *params,    //  => passed from original call 
int             operation,  //  => why you were called 
UInt32           offset,     //  => offset from header 
MSElementDescr  *elemDscrP  //  => element descr 
)
{
	UInt32 fp1 = mdlElmdscr_getFilePos(elemDscrP);
	UInt32 fp2 = *(UInt32*)params;

	if (fp1 == fp2) 
		return offset;
	else
		return 0;
}

/////////////////////////////////////////////
int reinProcessReinBar(MSElementDescr**  edp, int view, UInt32 elEDoffset)
{
	ReinElement       relem ; 
	//ReinBar       rb ; 
	MSElementDescr*  edpRS = *edp;
	//DialogBox *dbP;

	writeLogIn(__FUNCTION__, 0);

	rInfo.option[0] = 0;

	if (readReinBarFromElement(&relem, edpRS, TRUE) == SUCCESS)
	{
		copySpaceData(&rInfo.rsVal, &relem.rb, FALSE, &rInfo.rsOpt, TRUE);

		// возможно следует сделать новую комагнду чтобы можно было поменять главный сегмент
		// сейчас если mainline определен, его поменять нельзя, закоментарено:
		//rInfo.rsVal.segmIndex = locSegmIndex;
		//rInfo.rsVal.elemEDoffset = elEDoffset;

		// было сделано для синхронизации ReinCalc
		//if (iAC == CMD_REIN_MODIFY || iAC == CMD_REIN_SIDE)
		//{
		//	rb.createBar(edpRS, edpRS->h.dgnModelRef, FALSE, FALSE, NULL, NULL, 0, 1, 0, 0);
		//	//mdlLocate_clearHilited(TRUE);
		//}

		rInfo.option[0] = 1;
		
		rrelem.mapOvers = relem.mapOvers;

		syncToolbox();

		if (!mdlModelRef_isActiveModel(curElemModelRef)) startModify();
	}
	else // пустой элемент, идет создание стержня
	{
		if (rInfo.rsVal.bartype != BT_AXIS)  // если идет создание контура, то увеличиваем номер сортировки
			rInfo.rsVal.contnum += 100;

		rInfo.rsVal.segmIndex = locSegmIndex;
		rInfo.rsVal.elemEDoffset = elEDoffset;
		
		enableItems(NULL, RTYPE_ToggleButton, FALSE);
	}

	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;

}

/////////////////////////////////////////////
void reinGoPlaces(ReinSpace* rsP) // NU
{
}



/////////////////////////////////////////////
int reinProcessReinSpace(MSElementDescr** edp, int view, UInt32 elEDoffset, UInt32 fpSurf)
{
	//ReinSpace       rs ; 
	ReinElement       relem;
	MSElementDescr*  edpRS = *edp;
	//int num;
	//DialogBox *dbP;

	writeLogIn(__FUNCTION__, 0);

	if (readReinSpaceFromElmd(&relem, edpRS, TRUE) == SUCCESS)
	{
		rInfo.rsVal.bartype = BT_AXIS;
		if (!rInfo.rsOpt.runmet) rInfo.rsVal.runmet = relem.rs.runmet;
		if (!rInfo.rsOpt.diam) rInfo.rsVal.diam = relem.rs.diam;
		if (!rInfo.rsOpt.space) rInfo.rsVal.spacef = relem.rs.spacef; //rInfo.rsVal.space2 = relem.rs.space2;}
		if (!rInfo.rsOpt.offset[0]) rInfo.rsVal.offset[0] = relem.rs.offset[0];
		if (!rInfo.rsOpt.offset[1]) rInfo.rsVal.offset[1] = relem.rs.offset[1];
		if (!rInfo.rsOpt.bendrad) rInfo.rsVal.bendrad = relem.rs.bendrad;
		if (!rInfo.rsOpt.poscalc) rInfo.rsVal.poscalc = relem.rs.poscalc;
		if (!rInfo.rsOpt.lap[0]) rInfo.rsVal.lap[0] = relem.rs.lap[0];
		if (!rInfo.rsOpt.lap[1]) rInfo.rsVal.lap[1] = relem.rs.lap[1];
		if (!rInfo.rsOpt.lap[2]) rInfo.rsVal.lap[2] = relem.rs.lap[2];
		if (!rInfo.rsOpt.trm[0]) rInfo.rsVal.trm[0] = relem.rs.trm[0];
		if (!rInfo.rsOpt.trm[1]) rInfo.rsVal.trm[1] = relem.rs.trm[1];

		// исп. только rsOpt.trmPar[0], т.к. галка одна
		if (!rInfo.rsOpt.trmPar[0][0]) rInfo.rsVal.trmPar[0][0] = relem.rs.trmPar[0][0]; 
		if (!rInfo.rsOpt.trmPar[0][1]) rInfo.rsVal.trmPar[0][1] = relem.rs.trmPar[0][1];
		if (!rInfo.rsOpt.trmPar[0][0]) rInfo.rsVal.trmPar[1][0] = relem.rs.trmPar[1][0];
		if (!rInfo.rsOpt.trmPar[0][1]) rInfo.rsVal.trmPar[1][1] = relem.rs.trmPar[1][1];
		if (!rInfo.rsOpt.trmPar[0][0]) rInfo.rsVal.trmPar[2][0] = relem.rs.trmPar[2][0];
		if (!rInfo.rsOpt.trmPar[0][1]) rInfo.rsVal.trmPar[2][1] = relem.rs.trmPar[2][1];

		rInfo.rsVal.elemEDoffset = relem.rs.elemEDoffset;
		rInfo.rsVal.segmIndex = relem.rs.segmIndex;

		rrelem.mapOvers = relem.mapOvers;

		if (fpSurf > 0) 
		{
			syncToolbox();
			return SUCCESS;
		}
		else if (iAC == CMD_REIN_MODIFY || iAC == CMD_REIN_UNGRAB)
		{
			reinCalcSpace(0, edpRS, &relem.rs, 0, edpRS->h.dgnModelRef, FALSE, FALSE, FALSE);
			syncToolbox();
			if (!mdlModelRef_isActiveModel(curElemModelRef)) startModify();
		}
		else if (iAC == CMD_REIN_LOADS)
		{
			reinCalcSpace(0, edpRS, &relem.rs, 0, edpRS->h.dgnModelRef, FALSE, FALSE, FALSE);
		}
		else if (iAC == CMD_REIN_SIDE ||
				iAC == CMD_REIN_FRONT)
		{
			rInfo.rsVal = relem.rs;
			reinCalcSpace(0, edpRS, &relem.rs, 0, edpRS->h.dgnModelRef, FALSE, FALSE, FALSE);

		}
		else if (iAC == CMD_REIN_PLANE)
		{
			reinGoPlaces(&relem.rs); // ??
		}
		else
			startModify();

	}
	else if (iAC == CMD_REIN_MODIFY || iAC == CMD_REIN_UNGRAB)
	{
		rInfo.rsVal.elemEDoffset = elEDoffset;
		rInfo.rsVal.segmIndex = locSegmIndex;
	}
	else
		startModify();

	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;


}


////////////////////////////////////
void reinLocateShowElem(DPoint3dCP point, int view)
{
	MSElementDescr* edpRS = NULL;
	int type;
	UInt32 elEDoffset = 0;
	ReinElm   re;
	//ReinBar rb;
	int ret;



	//DisplayPathP dpP = mdlLocate_getCurrPath();
	//for (int i = 0; i < mdlDisplayPath_getCount(dpP); ++i)
	//{
	//	ElementRef  eref = mdlDisplayPath_getElem(dpP, i);
	//}

	ReinCache prm;

	//filePosRein = mdlElement_getFilePos(FILEPOS_CURRENT, &curElemModelRef);
	// неа

	if (!vElemLoc.empty())
	{
		printf("eeee tak delo ne poidet");
		return;
	}


	filePosRein = mdlLocate_findElement(point, view, FALSE, ComponentMode_None, TRUE);
	curElemModelRef = mdlLocate_getCurrModelRef();

	prm.pnum = filePosRein;
	prm.mrP = curElemModelRef;


	while (prm.pnum)
	{
		vElemLoc.push_back(prm);

		prm.pnum = mdlLocate_findElement(point, view, TRUE, ComponentMode_None, TRUE);
		prm.mrP = mdlLocate_getCurrModelRef();

	}

	// не то
	//prm.fp = mdlElement_getFilePos(FILEPOS_CURRENT, &prm.mrP);
	//while (prm.fp)
	//{
	//	vElemLoc.push_back(prm);
	//	prm.fp = mdlElement_getFilePos(FILEPOS_NEXT_ELE, &prm.mrP);
	//}

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	filePosRSElementOffset = mdlLocate_getComponentOffset();
#else
	filePosRSElementOffset = mdlLocate_getCurrElemFilePos();
#endif

	filePosReinBar = 0;
	filePosReinSpace = 0;
	filePosReinSurf = 0;

	if (vElemLoc.empty()) return;
	if (filePosRein == 0) return; // old
	//if (filePosRSElementOffset == 0) 	return;


	LOGIN



	if (iAC == CMD_REIN_BARSET || iAC == CMD_REIN_BARVIEW
		|| iAC == CMD_REIN_BAROVER
		)
	{
		if (mdlElmdscr_read(&edpRS, filePosRein, curElemModelRef, 0, 0) == 0)
		{
			startModify();
			RETURN_LOGOUT
		}

		if (iAC == CMD_REIN_BARSET || iAC == CMD_REIN_BARVIEW)
		{
			if (readReinElmIso(&re, edpRS, FALSE, FALSE) == SUCCESS)
			{
				filePosReinSpace = filePosRein;
			}
			else
				startModify();
		}
		else if (iAC == CMD_REIN_BAROVER)
		{
			// предполагаем что это space (для сброса), если окажется стержень, то потом переназначим
			filePosReinSpace = filePosRein;
		}

		mdlElmdscr_freeAll(&edpRS);
		RETURN_LOGOUT
	}



	if (mdlModelRef_isActiveModel(curElemModelRef) == FALSE)
	{
		vElemLoc.clear();
		filePosRein = 0;
		filePosRSElementOffset = 0;
		mdlLocate_clearHilited(TRUE);
		startModify();
		RETURN_LOGOUT
	}


	if (mdlElmdscr_read(&edpRS, filePosRein, curElemModelRef, 0, 0) == 0)
	{
		RETURN_LOGOUT
	}

	if (edpRS == NULL)
	{
		RETURN_LOGOUT
	}

	//type = mdlElement_getType(&edpRS->el); // ниже

	// если указан ReinElm (вспомогательное построение)
	if (readReinElmIso(&re, edpRS, FALSE, FALSE) == SUCCESS)
	{

		ELREF eref;

		eref = getElemRefByID(MASTERFILE, re.bel.elemid);


		if (eref)
		{

			DPoint3d prng[4];
			ScanRange sr;

			mdlElmdscr_computeRange(&prng[0], &prng[1], edpRS, NULL);

			sr.xlowlim = (Int64)(prng[0].x - mdlCnv_masterUnitsToUors(dDupTol));
			sr.ylowlim = (Int64)(prng[0].y - mdlCnv_masterUnitsToUors(dDupTol));
			sr.zlowlim = (Int64)(prng[0].z - mdlCnv_masterUnitsToUors(dDupTol));

			sr.xhighlim = (Int64)(prng[1].x + mdlCnv_masterUnitsToUors(dDupTol));
			sr.yhighlim = (Int64)(prng[1].y + mdlCnv_masterUnitsToUors(dDupTol));
			sr.zhighlim = (Int64)(prng[1].z + mdlCnv_masterUnitsToUors(dDupTol));

			mdlElmdscr_freeAll(&edpRS);

			mdlElmdscr_getByElemRef(&edpRS, eref, MASTERFILE, FALSE, 0);
			if (edpRS)
			{
				filePosRein = mdlElmdscr_getFilePos(edpRS);
#if defined (MSVERSION) && (MSVERSION == 0xa00)
				filePosRSElementOffset = 0;
#else
				filePosRSElementOffset = filePosRein;
#endif
				//filePosReinSurf = mdlElement_getHeaderFilePos(filePosRein, MASTERFILE);
				//if (filePosReinSurf == filePosRein) filePosReinSurf = 0;

				ReinElement relem;

				if (readReinSpaceFromElmd(&relem, edpRS, 0) == SUCCESS)
				{
					mdlLocate_changeCurrPath(filePosRein, MASTERFILE);

					mdlLocate_hilitePath(mdlLocate_getCurrPath());

#if defined (MSVERSION) && (MSVERSION == 0xa00)
					filePosRSElementOffset = mdlLocate_getComponentOffset();
#else
					filePosRSElementOffset = mdlLocate_getCurrElemFilePos();
#endif

					if (mdlElmdscr_read(&edpRS, filePosRein, curElemModelRef, 0, 0) == 0)
					{
						RETURN_LOGOUT
					}
				}
				else if (readReinDataFromElmd(&relem, edpRS, 0) == SUCCESS)
				{
					//RETURN_LOGOUT

					mdlElmdscr_freeAll(&edpRS);

					ScanCriteria* pScanCriteria;
					int status;

					ReinPrm prm;
					prm.prmid = re.bel.elemid;

					pScanCriteria = mdlScanCriteria_create();
					status = mdlScanCriteria_setReturnType(pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
					status = mdlScanCriteria_setElmDscrCallback(pScanCriteria, (PFScanElemDscrCallback)scanFindBars, &prm);
					status = mdlScanCriteria_setModel(pScanCriteria, ACTIVEMODEL);
					mdlXML_addXMLFragmentAttachmentScanTest(pScanCriteria, &appID, &appTypeReinBar);
					status = mdlScanCriteria_setRangeTest(pScanCriteria, &sr); // СУПЕР
					status = mdlScanCriteria_scan(pScanCriteria, NULL, NULL, NULL);
					status = mdlScanCriteria_free(pScanCriteria);

					if (!prm.uints.empty())
					{
						for (deque<UInt32>::iterator it = prm.uints.begin(); it != prm.uints.end(); ++it)
						{

							mdlLocate_changeCurrPath(*it, MASTERFILE);

							filePosRein = *it;
#if defined (MSVERSION) && (MSVERSION == 0xa00)
							filePosRSElementOffset = 0;
#else
							filePosRSElementOffset = filePosRein;
#endif

							break;
						}

						mdlLocate_hilitePath(mdlLocate_getCurrPath());

						if (mdlElmdscr_read(&edpRS, filePosRein, curElemModelRef, 0, 0) == 0)
						{
							RETURN_LOGOUT
						}
					}
					else
					{
						RETURN_LOGOUT
					}

				}
			}
		}
		else
		{
			// элемент находится в референсе?
			RETURN_LOGOUT
		}
	}



	type = mdlElement_getType(&edpRS->el);

	if (iDebug) sprintf(sLogMes, "element type = %i\n", type); writeLog(0, 0);


	if (type == SURFACE_ELM)
	{
		MSElementDescr*  edpBar = NULL;
		DVec3d p;
		double d;
		//DVec3d pCent;
		//DVec3d pAxis;
		//double swan = 0.;
		int res = mdlSurface_extractExtrusionExt(&edpBar, &p, &d, edpRS, TRUE);
		if (res == SUCCESS)
		{
			filePosReinSurf = mdlElmdscr_getFilePos(edpRS);
		}
		else
		{
			res = ERROR;
			//mdlSurface_extractRevolution2(&edpBar, &pCent, &pAxis, &swan, edpRS);
			//if (res == SUCCESS) filePosReinSurf = mdlElmdscr_getFilePos(edpRS);
		}
		if (edpBar) mdlElmdscr_freeAll(&edpBar);
	}
	else if (type == SHAPE_ELM) // вернул контур шейпа 17.11.2023
	{
		filePosReinSurf = filePosRein;
	}



	if (filePosRein == 0) 	RETURN_LOGOUT
	//if (filePosRSElementOffset == 0) 	RETURN_LOGOUT


	locVertexIndex = 0;
	locSegmIndex = 0;

	if (mdlLocate_Linear_getParameters(&locSegmVector, &locVertexIndex, &locSegmIndex) != SUCCESS)
	{
		//mdlDialog_dmsgsPrint ("reinLocateShowElem(), mdlLocate_Linear_getParameters returs error");
		//RETURN_LOGOUT
	}





	if (
		(iAC == CMD_REIN_MODIFY || 
			iAC == CMD_REIN_SIDE || 
			iAC == CMD_REIN_DROP
			) 
		&&
		(type == LINE_ELM ||
			type == ARC_ELM ||
			type == ELLIPSE_ELM ||
			type == LINE_STRING_ELM ||
			type == CMPLX_STRING_ELM)
		)
	{
		filePosReinBar = filePosRein;
		filePosReinSpace = 0;
	}
	else
	{
		filePosReinBar = 0;
		filePosReinSpace = filePosRein;
	}

	//printf("show %i\n", filePosReinSpace);



#if defined (MSVERSION) && (MSVERSION == 0xa00)
	if ((filePosReinSpace > 0 && filePosRSElementOffset > 0) || filePosReinBar > 0)
	{
		elEDoffset = filePosRSElementOffset;
#else
	if ((filePosReinSpace > 0 && filePosRSElementOffset > 0 && filePosReinSpace != filePosRSElementOffset) || filePosReinBar > 0)
	{
		elEDoffset = mdlElmdscr_operation(edpRS, iterateElmdGetElmOffset, &filePosRSElementOffset, ELMD_ELEMENT);
#endif
	}
	else
		elEDoffset = 0;

	//mdlSystem_enterDebug();

	//printf("elEDoffset = %i    locSegmIndex = %i\n", elEDoffset, locSegmIndex);

	//DialogBox* dbP = findToolBox();
	//if (dbP && rDopInfo.dopopt[8] == FALSE)
	//{
	//	DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, 51, 0);
	//	if (diP) mdlDialog_itemSetEnabledState(dbP, diP->itemIndex, FALSE, TRUE);
	//}


	if (filePosReinBar)
	{
		ret = reinProcessReinBar(&edpRS, mdlLocate_getHitView(), elEDoffset);
	}
	else
	{
		ret = reinProcessReinSpace(&edpRS, mdlLocate_getHitView(), elEDoffset, filePosReinSurf);
	}

	mdlElmdscr_freeAll(&edpRS);

	if (ret != SUCCESS) 
	{
		startModify();
		RETURN_LOGOUT
	}

	if (iAC == CMD_REIN_SIDE
		|| iAC == CMD_REIN_FRONT
		|| iAC == CMD_REIN_CHLAP
		|| iAC == CMD_REIN_DROP
		)
	{
		reinLocatePoint(0, 0);
	}
	else
	{
		mdlOutput_prompt(L("Подтвердите модификацию элемента или Отмените (перебор элементов)"));
	}


	writeLogOut(__FUNCTION__, 0);


}

/*
/////////////////////////
int iterateCheckBarForLoads(
MSElement       *element,   //  => element to act upon 
void            *params,    //  => passed from original call 
int             operation,  //  => why you were called 
UInt32           offset,     //  => offset from header 
MSElementDescr  *elemDscrP  //  => element descr 
)
{

	//MSBsplineCurve  crv;
	int num, res, i, a;
	double dReqX[4] = {0.,0.,0.,0.};
	double dReqY[4] = {0.,0.,0.,0.};
	static int ofs;
	double* arReq = (double*)params;

	if (offset == 0) 
		ofs = 0;
	else
		ofs++;


	if (daCurLoadNodes == NULL) return SUCCESS;

	num = mdlDArray_nMembers(daCurLoadNodes);

	if (num == 0) return SUCCESS;

	res = mdlBspline_convertToCurve(&crv, elemDscrP);

	if (res == SUCCESS)
	{
		double dist;

		for (a = 0; a < num; a++)
		{
			LoadNode* lnP = (LoadNode*)mdlDArray_getMemberP(daCurLoadNodes, a);

			if (mdlBspline_minimumDistanceToCurve (&dist, 0, 0, &lnP->org, &crv) == SUCCESS)
			{
				if (dist < mdlCnv_masterUnitsToUors(2000.))
				{
					LoadVert* lvP;

					for (i = 0; i < 4; i++)
					{
						lvP = (LoadVert*)mdlDArray_getMemberP(daCurLoadVerts, lnP->vertind[i]);
						if (lvP > 0)
						{
							if (lvP->vals[LI_REQ_TOP_X] > lvP->vals[LI_REQ_BOT_X])
								if (dReqX[i] < lvP->vals[LI_REQ_TOP_X]) dReqX[i] = lvP->vals[LI_REQ_TOP_X];
							else
								if (dReqX[i] < lvP->vals[LI_REQ_BOT_X]) dReqX[i] = lvP->vals[LI_REQ_BOT_X];

							if (lvP->vals[LI_REQ_TOP_Y] > lvP->vals[LI_REQ_BOT_Y])
								if (dReqY[i] < lvP->vals[LI_REQ_TOP_Y]) dReqY[i] = lvP->vals[LI_REQ_TOP_Y];
							else
								if (dReqY[i] < lvP->vals[LI_REQ_BOT_Y]) dReqY[i] = lvP->vals[LI_REQ_BOT_Y];

						}

					}
				}
			}

			mdlDialog_trackBarUpdateDisplayInfo(&tbi);
			WaitMessage();
		}



		tbi.percentComplete1 = (long)(((double)(ofs+1)/arReq[2])*100.);
		mdlDialog_trackBarUpdateDisplayInfo(&tbi);
		WaitMessage();

		//printf("%i  %f\n", ofs, arReq[2]);

		mdlUtil_sortDoubles(dReqX, 4, 0);
		mdlUtil_sortDoubles(dReqY, 4, 0);

		if (arReq[0] < dReqX[0]) arReq[0] = dReqX[0];
		if (arReq[1] < dReqY[0]) arReq[1] = dReqY[0];


		mdlBspline_freeCurve(&crv);
	}


	return SUCCESS;
}

*/




//////////////////////////////////////////////////////
int iterateReinBarFindByID(ReinBar* rbP, ReinBar* rbPtoFind)
{
	

	if (rbPtoFind && rbP)
	{
		if (rbP->diam == 0) return FALSE;

		if (rbP->elemid == rbPtoFind->elemid && rbP->modrefP == rbPtoFind->modrefP)
		{
			rbFoundP = rbP;
			return TRUE;
		}
	}

	return FALSE;

}

/////////////////////////////////
void scanCancel(void* prm)
{
	elemCount = -1;
}

/////////////////////////////////
int scanProcessing(void* prm)
{
	return 0;
}


/*
/////////////////////////////////////////////
// REPAIR...
void reinSpaceLoads(UInt32 fpos, DgnModelRefP mrP)
{

	UInt32 fp = 0;
	MSElementDescr* edp = NULL;
	MSElementDescr* edpBars = NULL;
	int ret;

	if (fpos == 0) return;
	if (mrP == NULL) mrP = MASTERFILE;

	fp = mdlElmdscr_readToMaster(&edp, fpos, mrP, 0, 0);

	if (edp)
	{
		//ELID id = mdlElement_getID (&edp->el);

		reFoundP = NULL;
		//mdlDArray_processAll(daCurElements, &id, 0, iterateBarsFind);


		if (reFoundP != NULL)
		{
			//ret = mdlTransient_returnElemDescr(&edpBars, reFoundP->tedIsoP);

			ret = ERROR;


			if (ret == SUCCESS)
			{
				double arReqA[3] = {0.,0.,0.};
				double qty;
				double arReqD[2];
				int n = 0;



				//printf("++++++++++++++++++++\n");

				ZeroTrackBar(&tbi);
				strcpy(tbi.msgText1, "Расчет диаметров арматуры");
				tbi.update = UPDATE_Percent1 | UPDATE_Msg1;
				tbi.percentComplete1 = 0;

				// количество
				mdlElmdscr_operation(edpBars, iterateCheckBarGetCount, &n, ELMD_HDRS_ONCE);
				arReqA[2] = (double)n;

				mdlDialog_dmsgsClear();

				if (n > 0)
				{
					mdlDialog_trackBarStartProcessing(NULL, NULL, NULL, NULL, NULL, 0, &tbi, NULL);

					// перебираем каждый стержень
					mdlElmdscr_operation(edpBars, iterateCheckBarForLoads, arReqA, ELMD_HDRS_ONCE);

					mdlDialog_trackBarStopProcessing();


					sprintf(s, "required area: Ax = %f, Ay = %f", arReqA[0], arReqA[1]);
					mdlDialog_dmsgsPrint(s);

					qty = dLoadNodeSpacing / mdlCnv_masterUnitsToUors(rInfo.rsVal.space);

					arReqD[0] = 2 * sqrt((arReqA[0] / qty) / fc_pi);
					arReqD[1] = 2 * sqrt((arReqA[1] / qty) / fc_pi);

					sprintf(s, "required diameter on %i bars: Dx = %f, Dy = %f", (int)qty, arReqD[0], arReqD[1]);
					mdlDialog_dmsgsPrint(s);
				}
				else
				{
					mdlDialog_dmsgsPrint(L("no bars..."));
				}
				
				//printf("--------------------\n");
			}

		}

		mdlElmdscr_freeAll(&edp);
	}


}
*/

////////////////////////////////////////////
int	reinChangeSelected(
							DVec3d    *ptP,
							int	    view)
{

	int cnt = 0;

	if (mdlSelect_isActive())
	{

		int		numSelected; 
		DgnModelRefP*	fileNums;
		UInt32* filePositions;
		MSElementDescr	*edP = NULL;
		//ReinSpace rs;
		ReinElement relem;
		ReinBar rb;
		//ReinElm re;

		mdlSelect_returnPositions (&filePositions, &fileNums, &numSelected);

		for (int i = 0; i < numSelected; i++) 
		{
			if (mdlModelRef_isActiveModel(fileNums[i]) == FALSE) continue;

			mdlElmdscr_readToMaster (&edP, filePositions[i], fileNums[i], FALSE, NULL);
			if (edP)
			{

				if (readReinSpaceFromElmd(&relem, edP, FALSE) == SUCCESS)
				{
					if (rInfo.rsOpt.runmet)    relem.rs.runmet = rInfo.rsVal.runmet;
					if (rInfo.rsOpt.diam)      relem.rs.diam = rInfo.rsVal.diam;
					if (rInfo.rsOpt.space) relem.rs.spacef = rInfo.rsVal.spacef; //relem.rs.space2 = rInfo.rsVal.space2;}
					if (rInfo.rsOpt.offset[0]) relem.rs.offset[0] = rInfo.rsVal.offset[0];
					if (rInfo.rsOpt.offset[1]) relem.rs.offset[1] = rInfo.rsVal.offset[1];
					if (rInfo.rsOpt.bendrad)       relem.rs.bendrad = rInfo.rsVal.bendrad;
					if (rInfo.rsOpt.poscalc)       relem.rs.poscalc = rInfo.rsVal.poscalc;
					if (rInfo.rsOpt.lap[0])    relem.rs.lap[0] = rInfo.rsVal.lap[0];
					if (rInfo.rsOpt.lap[1])    relem.rs.lap[1] = rInfo.rsVal.lap[1];
					if (rInfo.rsOpt.lap[2])    relem.rs.lap[2] = rInfo.rsVal.lap[2];
					if (rInfo.rsOpt.trm[0])   relem.rs.trm[0] = rInfo.rsVal.trm[0];
					if (rInfo.rsOpt.trm[1])   relem.rs.trm[1] = rInfo.rsVal.trm[1];

					// исп. только rsOpt.trmPar[0], т.к. галка одна
					if (rInfo.rsOpt.trmPar[0][0]) relem.rs.trmPar[0][0] = rInfo.rsVal.trmPar[0][0];
					if (rInfo.rsOpt.trmPar[0][1]) relem.rs.trmPar[0][1] = rInfo.rsVal.trmPar[0][1];
					if (rInfo.rsOpt.trmPar[0][0]) relem.rs.trmPar[1][0] = rInfo.rsVal.trmPar[1][0];
					if (rInfo.rsOpt.trmPar[0][1]) relem.rs.trmPar[1][1] = rInfo.rsVal.trmPar[1][1];
					if (rInfo.rsOpt.trmPar[0][0]) relem.rs.trmPar[2][0] = rInfo.rsVal.trmPar[2][0];
					if (rInfo.rsOpt.trmPar[0][1]) relem.rs.trmPar[2][1] = rInfo.rsVal.trmPar[2][1];

					//rInfo.rsVal.elemEDoffset = relem.rs.elemEDoffset;
					//rInfo.rsVal.segmIndex = relem.rs.segmIndex;

					UInt32 fp = createReinSpaceElement(&edP, &relem.rs, filePositions[i], fileNums[i], FALSE, TRUE, &relem);

					if (fp) cnt++;

				}

				if (readReinBarFromElement(&rb, edP, TRUE) == SUCCESS)
				{
					if (rInfo.rsOpt.runmet)    rb.runmet = rInfo.rsVal.runmet;
					if (rInfo.rsOpt.diam)      rb.diam = rInfo.rsVal.diam;
					if (rInfo.rsOpt.space) rb.spacef = rInfo.rsVal.spacef; // no space2
					if (rInfo.rsOpt.offset[0]) rb.offset[0] = rInfo.rsVal.offset[0];
					if (rInfo.rsOpt.offset[1]) rb.offset[1] = rInfo.rsVal.offset[1];
					if (rInfo.rsOpt.bendrad)       rb.bendrad = rInfo.rsVal.bendrad;
					if (rInfo.rsOpt.poscalc)       rb.poscalc = rInfo.rsVal.poscalc;
					if (rInfo.rsOpt.lap[0])    rb.lap[0] = rInfo.rsVal.lap[0];
					if (rInfo.rsOpt.lap[1])    rb.lap[1] = rInfo.rsVal.lap[1];
					if (rInfo.rsOpt.lap[2])    rb.lap[2] = rInfo.rsVal.lap[2];
					if (rInfo.rsOpt.trm[0])   rb.term[0] = rInfo.rsVal.trm[0];
					if (rInfo.rsOpt.trm[1])   rb.term[1] = rInfo.rsVal.trm[1];

					// исп. только rsOpt.trmPar[0], т.к. галка одна
					if (rInfo.rsOpt.trmPar[0][0]) rb.termPar[0][0] = rInfo.rsVal.trmPar[0][0];
					if (rInfo.rsOpt.trmPar[0][1]) rb.termPar[0][1] = rInfo.rsVal.trmPar[0][1];
					if (rInfo.rsOpt.trmPar[0][0]) rb.termPar[1][0] = rInfo.rsVal.trmPar[1][0];
					if (rInfo.rsOpt.trmPar[0][1]) rb.termPar[1][1] = rInfo.rsVal.trmPar[1][1];
					if (rInfo.rsOpt.trmPar[0][0]) rb.termPar[2][0] = rInfo.rsVal.trmPar[2][0];
					if (rInfo.rsOpt.trmPar[0][1]) rb.termPar[2][1] = rInfo.rsVal.trmPar[2][1];

					UInt32 fp = rb.createReinBarElement(&edP, filePositions[i], fileNums[i], TRUE);

					if (fp) cnt++;

				}

				mdlElmdscr_freeAll(&edP);


			}
		}

		dlmSystem_mdlFree(fileNums);
		dlmSystem_mdlFree(filePositions);

	}

	mdlOutput_printf(MSG_PROMPT, L("Изменено элементов: %i"), cnt);

	return SUCCESS;
}

////////////////////////////////
int isModifyOptionChanged()
{
	if (rInfo.rsOpt.diam) return 1;
	if (rInfo.rsOpt.runmet) return 1;
	if (rInfo.rsOpt.lap[0]) return 1;
	if (rInfo.rsOpt.lap[1]) return 1;
	if (rInfo.rsOpt.lap[2]) return 1;

	if (rInfo.rsOpt.space) return 1;
	if (rInfo.rsOpt.spacerad) return 1;

	if (rInfo.rsOpt.offset[0]) return 1;
	if (rInfo.rsOpt.offset[1]) return 1;

	if (rInfo.rsOpt.bendrad) return 1;

	if (rInfo.rsOpt.poscalc) return 1;

	if (rInfo.rsOpt.trm[0]) return 1;
	if (rInfo.rsOpt.trm[1]) return 1;

	if (rInfo.rsOpt.trmPar[0][0]) return 1;
	if (rInfo.rsOpt.trmPar[0][1]) return 1;

	return 0;

}



/////////////////////////////////////////////
int	reinLocatePoint(
							DVec3d    *ptP,
							int	    view)
{



	if (iAC == CMD_REIN_BARSET && mdlFence_isDefined())
	{

		iACStep = 1;

		barSetFenceProcess(iACStep); // save, update mapBarSet, start def cmd

		mdlLocate_clearHilited(TRUE);

		return SUCCESS;
	}

	if (filePosRein == 0) 	return SUCCESS;
	//if (filePosRSElement == 0) 	return SUCCESS;

/*
	if (iAC == CMD_REIN_SIDE)
	{
		iACStep = 1;
#if defined (MSVERSION) && (MSVERSION == 0xa00)
		StateCallback::SetComplexDynamicsFunction((StateFunc_ComplexDynamics)reinSideDynamics);
		StateCallback::SetDataPointFunction((StateFunc_DataPoint)reinSidePoint);
#else
		mdlState_setFunction(STATE_COMPLEX_DYNAMICS, reinSideDynamics);
		mdlState_setFunction(STATE_DATAPOINT, reinSidePoint);

#endif
		return SUCCESS;
	}
*/
	writeLogIn(__FUNCTION__, 0);


	// >>>>>> PROCESS ...........

	if (filePosReinSpace > 0) // apply changes
	{

		mdlLocate_clearHilited(TRUE);

		if (iAC == CMD_REIN_LOADS)
		{
			//reinSpaceLoads(filePosReinSpace, curElemModelRef);
		}
		else if (iAC == CMD_REIN_BAROVER)
		{
			reinSetOverInSpace(rBarOverInfo.dopopt[21]);
		}
		else if (iAC == CMD_REIN_BARSET)
		{
			if (!vElemLoc.empty())
			{
				int bPlaceDim = rDopInfo.dopopt[6];

				for (vector<ReinCache>::iterator it = vElemLoc.begin(); it != vElemLoc.end(); ++it)
				{
					reinSetBarInSpace(ptP, it->pnum, it->mrP, rInfo.option[16], bPlaceDim);
					bPlaceDim = FALSE; // хватит
				}

			}

			//reinSetBarInSpace(ptP, filePosRein, curElemModelRef, rInfo.option[16], rDopInfo.dopopt[6]);
		}
		else if (iAC == CMD_REIN_CHLAP)
		{
			rInfo.rsVal.lap[2] = !rInfo.rsVal.lap[2];

			reinSpaceElmdCreate(filePosReinSpace, curElemModelRef, NULL, FALSE);
		}
		else if (isModifyOptionChanged())
		{
			int bUpdConf = FALSE;

			if (iAC == CMD_REIN_UNGRAB) bUpdConf = TRUE;

			reinSpaceElmdCreate(filePosReinSpace, curElemModelRef, NULL, bUpdConf);
		}
		else if (filePosReinSurf > 0)
		{
			reinSpaceElmdCreate(filePosReinSurf, curElemModelRef, NULL, FALSE);
		}

	}

	if (filePosReinBar > 0 
			&& (!(iAC == CMD_REIN_BAROVER && rBarOverInfo.dopopt[21] == BAROVER_ACTION_RESET)) // идет сброс на линейном контуре, не трогаем
			&& (
				rInfo.option[0] == 0 // если пустой стержень или
				|| isModifyOptionChanged() // если выделена хотя бы одна галка
				|| iAC == CMD_REIN_DROP
				|| iAC == CMD_REIN_BAROVER
			)
		) // apply changes
	{
		ReinBar rb;
		MSElementDescr* edp = NULL;

		// copy space data to bar
		copySpaceData(&rInfo.rsVal, &rb, TRUE, NULL, TRUE);

		if (iAC == CMD_REIN_DROP) bDropReinData = TRUE;

		if (iAC == CMD_REIN_BAROVER) rb.grnd = (rBarOverInfo.dopopt[22] != 0);

		if (rb.bartype != BT_AXIS) // также сохранять ReinData если поменялась, остальные параметры сохранять в элементе
		{ // create data
			rb.saveReinData(rb.elemid, &rrelem);

			rb.barflags |= REINBAR_FLAG_CONT;

			rrelem.mapOvers.clear(); // global element clear;
		}

		mdlLocate_clearHilited(TRUE);

		if (mdlElmdscr_read(&edp, filePosReinBar, MASTERFILE, FALSE, 0) > 0)
		{
			rb.createReinBarElement(&edp, filePosReinBar, MASTERFILE, TRUE);

			rInfo.rsVal.elid = rb.elemid;
			//mdlElmdscr_freeAll(&edp);
		}

	}

	startModify();

	writeLogOut(__FUNCTION__, 0);

	//GUID MyGuid;
	//HRESULT hr = CoCreateGuid(&MyGuid);

	return SUCCESS;
}


/////////////////////////////////////////////
void	reinLocateReset()
{

	//mdlSystem_enterDebug();

	MSDLGP dbP = findToolBox();
	if (dbP)
	{
		DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, 51, 0);
		if (diP) mdlDialog_itemSetEnabledState(dbP, diP->itemIndex, TRUE, TRUE);
	}


	//if (filePosRein == 0)
	//{
	//	mdlLocate_clearHilited(TRUE);
	//	if (edpRot) mdlElmdscr_freeAll(&edpRot);
	//	mdlState_setFunction(STATE_COMPLEX_DYNAMICS, NULL);
	//	mdlState_setFunction(STATE_DATAPOINT, NULL);
	//	mdlState_setFunction(STATE_RESET, NULL);
	//	iAC = 0;
	//	mdlState_startDefaultCommand();
	//}
	//else
	{
		startModify();
	}



}


/////////////////////////
void startModify()
{


	writeLogIn(__FUNCTION__, 0);

	setDefaultStyles();

	filePosRein = 0;
	filePosReinBar = 0;
	filePosReinSpace = 0;

	vElemLoc.clear();

	bDropReinData = FALSE;

	rInfo.rcUnit.clear();

	if (edpRot) mdlElmdscr_freeAll(&edpRot);


    mdlLocate_init ();

	mdlLocate_noElemAllowLocked();
	//mdlLocate_noElemNoLocked();

    mdlLocate_setElemSearchMask (nSearchTypes, searchType);


	//mdlState_startPrimitive (reinLocatePoint, reinLocateReset, 1, 0);

	mdlState_startModifyCommand(
		(StateFunc_Reset)reinLocateReset, 
		(MdlFunc_Accept)reinLocatePoint, 
		(StateFunc_SimpleDynamics)NULL,
		(MdlFunc_Show)reinLocateShowElem, 
		(MdlFunc_Clean)NULL,
		0, 0, false, 0);


	mdlOutput_prompt(L("Укажите элемент или Отмените (выход из команды)"));

	mdlLocate_setCursor();

	writeLogOut(__FUNCTION__, 0);

	enableItems(NULL, RTYPE_ToggleButton, TRUE);

}


/////////////////////////////////
int scanMuftCount(
MSElementDescr  *edP,
long            *elemCountP,
ScanCriteria    *pScanCriteria					
)
{
	ReinElm relm;

	//mdlElmdscr_show(edP, "  ");

	if (readReinElmIso(&relm, edP, FALSE, FALSE) == SUCCESS) 
	{
		elemCount2++;

		if (elemCountP == NULL) return SUCCESS;

		if (relm.bel.term[0] == REIN_TERM_MUFT)
		{
			(*elemCountP)++;
		}

		if (relm.bel.term[1] == REIN_TERM_MUFT)
		{
			(*elemCountP)++;
		}

		if (relm.bel.term[0] == REIN_TERM_SKOB) 
		{
			(*elemCountP)++;
		}

		if (relm.bel.term[1] == REIN_TERM_SKOB) 
		{
			(*elemCountP)++;
		}

		ReinLap* rlP = getReinLap(relm.bel.diam);
		// добавление муфты при превышении длины
		if (rlP && rlP->muft)
		{
			(*elemCountP) += (int)floor((relm.bel.length - iCfgVar_MuftTol) / rlP->maxlen); // 11700.1
		}

	}

	return SUCCESS;

}


/////////////////////////////////
int scanReinCache(
MSElementDescr  *edP,
ReinPrm         *prmP, // NOT NULL
ScanCriteria    *pScanCriteria					
)
{

	BINT iDel = FALSE;
	//int iRefNum = 0;
	ReinCache rch;
	int iWhatToDo = 0;

	if (prmP) iWhatToDo = prmP->ival[0];

	if (readReinCacheFromElement(&rch, &edP->el) == SUCCESS)
	{
		ELREF eref = NULL;
		ReinModel* rmP = curRM->getRM(rch.refpath);
		if (rmP) eref = getElemRefByID(rmP->modelP, rch.elid);

		if (iWhatToDo < 0 && rch.refpath == prmP->wstr)
			mdlElmdscr_undoableDelete(0, elementRef_getFilePos (edP->h.elementRef), TRUE);

		if (eref) // если найден исходный элемент
		{
			if (iWhatToDo > 0 && rch.refpath == prmP->wstr)
			{
				prmP->cnt[0]++; // counter
			}

			if (iWhatToDo == 0)
			{
				rmP->setCached(true);
			}
		}
	}

	return SUCCESS;
}

/////////////////////////////////
int scanModelCountWithRefClip(
MSElementDescr  *edP,
long            *elemCountP,
ScanCriteria    *pScanCriteria					
)
{
	ReinElm relm;

	//mdlElmdscr_show(edP, "  ");

	MSElementDescr  *edLocP = NULL;
	DgnModelRefP mrP = mdlScanCriteria_getModel(pScanCriteria);

	writeLogIn(__FUNCTION__, 0);
	mdlElmdscr_readToMaster(&edLocP, mdlElmdscr_getFilePos(edP), mrP, 0, 0);

	if (relm.getElmFromElement(&edP->el, mrP) == SUCCESS)
	{

		if (mdlModelRef_isActiveModel(mrP))
		{
			(*elemCountP)++;
		}
		else
		{
			CLIPDESC clipP = NULL;
			MSElementDescr* edpClip = NULL;
			int view = 0;

			int r = myClip_getRefBoundary(&clipP, mrP, &edpClip, view);
			//int r = func_pma(mdlClip_getRefBoundary,clipP), mrP, view);

			if (r == SUCCESS 
				&& NOTNULL(clipP)
				)
			{
				BINT over;
				BINT isin = mdlClip_isElemInside(&over, edLocP, GETPTR(clipP), view, TRUE);

				if (isin)
					relm.iClip = over; // over == 0 or 1
				else
					relm.iClip = -1; // outside

				myClip_free(clipP, &edpClip);
			}

			if (relm.iClip != -1) (*elemCountP)++;
		}

	}

	if (edLocP) mdlElmdscr_freeAll(&edLocP);

	writeLogOut(__FUNCTION__, 0);
	return SUCCESS;
}

/////////////////////////////////
int scanModelCount(
MSElementDescr  *edP,
long            *elemCountP,
ScanCriteria    *pScanCriteria					
)
{
	ReinElm relm;

	//mdlElmdscr_show(edP, "  ");

	if (relm.getElmFromElement(&edP->el, mdlScanCriteria_getModel(pScanCriteria)) == SUCCESS)
	{
		(*elemCountP)++;
	}

	return SUCCESS;
}

/////////////////////////////////////////////////////////////
int getReducers(DgnModelRefP mrP, ReinVert* rvP, ScanRange* srP)
{

	writeLogIn(__FUNCTION__, 0);

	ScanCriteria    *scP = NULL;
	UShort          typeMask[6];
	int status;
	
	for (UShort a = 0; a < 6; a++) typeMask[a] = 0;
    typeMask[0] = TMSK0_LINE | TMSK0_ARC | TMSK0_LINE_STRING | TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;

	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanMuftCountExt, rvP);
	status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
	mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);
	if (srP) mdlScanCriteria_setRangeTest(scP, srP);
	status = mdlScanCriteria_setModel (scP, mrP);
	status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
	status = mdlScanCriteria_free (scP);

	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;

}


//////////////////////
// func get ReinElm count
UInt32 getReinElmCount(int bReset, DgnModelRefP mrP, UInt32* elemCountP)
{

	writeLogIn(__FUNCTION__, 0);

	ScanCriteria    *scP = NULL;
	UShort          typeMask[6];
	int status;

	if (bReset) (*elemCountP) = 0;
	
	for (UShort a = 0; a < 6; a++) typeMask[a] = 0;
    typeMask[0] = TMSK0_LINE | TMSK0_ARC | TMSK0_LINE_STRING | TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;

	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanModelCountWithRefClip, elemCountP);
	status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
	mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);
	status = mdlScanCriteria_setModel (scP, mrP);
	status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
	status = mdlScanCriteria_free (scP);

	if (iDebug) sprintf(sLogMes, "elemCountP = %u\n", *elemCountP); writeLog(0, 0);
	writeLogOut(__FUNCTION__, 0);

	return 0;
}

#if defined (MSVERSION) && (MSVERSION == 0xa00)
int workFunc(void* prm) { 	return 0; }
void completionFunc(int a, void* prm) {}
void cancelFunc(void* prm) { WaitMessage(); }
#else
int workFunc() { return 0; }
void completionFunc() {}
void cancelFunc() { WaitMessage(); }
#endif

///////////////////////////////
// func reload CurBars All
void reloadCurBarsAll(int iLoadRefs) // загрузка элементов референсов для информации по clip boundary
{
	//ScanCriteria    *scP = NULL;
	//UShort          typeMask[6];
	//int status;

	//if (bNoLoad) return;

	curPos_rn = 0;
	curPos_refpath = L"0";

	int iDepth = 2;

	//if (iLoadRefs == -1) iDepth = 0;

	bReloadInProgress = TRUE;

	writeLogIn(__FUNCTION__, 0);


	ZeroTrackBar(&tbi);
	//tbi.update = UPDATE_Percent1 | UPDATE_Msg1;
	tbi.update = UPDATE_Percent1 | UPDATE_Percent2 | UPDATE_Msg1 | UPDATE_Msg2;
	//strcpy(tbi.msgText1, "Загрузка данных арматуры");

	elemIterCount = 0;
	elemCount = 0;

	bModelOutOfDate = FALSE;
	bModelCheckRefs = FALSE;


	//if (curRM) 
	//{
	//	sprintf(sLogMes, "delete curRM...\n"); writeLog(0, 0);
	//	delete curRM;
	//}


	//ReinModel rm(ACTIVEMODEL, -1);

	if (iDebug) sprintf(sLogMes, "curRMod.Init...\n"); writeLog(0, 0, 0, 1);

	curRMod.Init(ACTIVEMODEL, -1);

	//curRMod = crm;

	//curRM = &curRMod;



	if (iDebug) sprintf(sLogMes, "create daCurPosExcl...\n"); writeLog(0, 0, 0, 1);


	daCurPosExcl.clear();


	if (iDebug) sprintf(sLogMes, "get elem count with depth %i ... \n", iDepth); writeLog(0, 0, 0, 1);

	elemCount = curRM->getElemCount(iDepth);

	//sprintf(sLogMes, "curRM element count = %i, allocate...\n", elemCount); writeLog(0, 0);
	//=============================
	//if (curElms) delete[] curElms;
	//curElms = new ReinElm[elemCount];
	//iCurElmsCount = elemCount;
	//=============================
	//sprintf(sLogMes, "allocate completed\n"); writeLog(0, 0);

	SPRN(tbi.msgText1, TXT_99, iDepth, elemCount);

	//===========================================================================
	if (elemCount)
		dlgProgressP = mdlDialog_completionBarOpen(tbi.msgText1);
		//mdlDialog_trackBarStartProcessing(
		//	workFunc,
		//	NULL,
		//	completionFunc,
		//	cancelFunc,
		//	NULL, 
		//	FALSE, 
		//	&tbi, 
		//	L("Арматурщина"));

//int(*workFuncP)(void*),      /* => work function pointer     */
//void           *funcParmsP,             /* => function parameters       */
//void(*completionFuncP)(int, void*),/* => completion function pointer*/
//void(*cancelFuncP)(void*),     /* => cancel function pointer   */
//WCharCP         cancelMessage,          /* => cancel confirmation msg   */
//int             stackedCompletionBars,  /* => double track bars if true */
//TrackBarInfo   *trackBarInfoP,          /* => track bar data            */
//WCharCP         windowTitle             /* => track bar window title    */
//
	
	writeLog("================================", 0, 0, 1);
	writeLog("================================", 0, 0, 1);
	if (iDebug) sprintf(sLogMes, "START LOAD DATA curRM.reloadCurBars(iDepth = %i) ... \n", iDepth); writeLog(0, 0, 0, 1);
	writeLog("================================", 0, 0, 1);
	writeLog("================================", 0, 0, 1);

	//==========================================================================
	//==========================================================================
	curRM->reloadCurBars(true, true, iDepth, iLoadRefs); // iDepth must be set by variable
	//==========================================================================
	//==========================================================================

	getReinCacheCount();


/*

	// каркасы - вложенные референсы
	{
		ModelRefIteratorP  it2;
		DgnModelRefP	mr2;

		mdlModelRefIterator_create (&it2, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, 1);

		while (NULL != (mr2 = mdlModelRefIterator_getNext (it2)))
		{
			int iselem = FALSE;
			mdlRefFile_getParameters(&iselem, REFERENCE_TREAT_AS_ELEMENT, mr2);
			if (iselem == FALSE) continue; // только каркасы
			
			reloadCurBars(mr2, true, false);
		}
	}

*/


	//if (elemCount) mdlDialog_trackBarStopProcessing();
	if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);
	//===========================================================================


	//{
	//	ReinBar* rbP;
	//	printf(">>>>>>>>>>>>>>  %i <<<<<<<<<<<<<<<<<<\n", iCurBarsCount);
	//	for (UInt32 ii = 0; ii < iCurBarsCount; ii++)
	//	{
	//		rbP = (ReinBar*)mdlDArray_getMemberP(daCurBars, ii);
	//		printf("%i %i %i\n", ii+1, rbP->numRef, rbP->space);
	//	}
	//}

	//char sss[100];
	//sprintf(sss, "загружено %i элементов с clip boundary", iCurBarsCount);

	//mdlOutput_messageCenter(OutputMessagePriority::Warning, sss, sss, FALSE);



#if defined (MSVERSION) && (MSVERSION == 0x8b0)
	mdlInput_sendKeyin(L("MDL KEYIN RCAT RCAT UPDATE"), 0, MSINPUTQ_HEAD, 0);
#else
	mdlInput_sendSynchronizedKeyin(L"MDL KEYIN RCAT RCAT UPDATE", false, MSINPUTQ_HEAD, 0);
#endif

	bReloadInProgress = FALSE;


	writeLogOut(__FUNCTION__, 0);


}




/////////////////////////////////
int getReinCacheCount(wstring* refpathP)
{

	ScanCriteria* scP = NULL;
	int status;

	//elemIterCount2 = 0;

	ReinPrm prm;

	if (refpathP)
	{
		prm.ival[0] = 1; // count
		prm.wstr = *refpathP;
	}


	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanReinCache, &prm);
	status = mdlScanCriteria_setDrawnElements(scP);
	status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
	status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
	status = mdlScanCriteria_free(scP);

	if (refpathP)
	{
		ReinModel* rmP = curRM->getRM(*refpathP);
		if (rmP)
		{
			rmP->setCached((prm.cnt[0] > 0));
		}
	}
	else
	{
		curRM->setCached(false);
	}


	return prm.cnt[0];
}






///////////////////////////////////////////////////////////////////
DgnModelRefP getOrCreateModel(MSWCH* modname, DgnModelRefP mrWhereP)
{
	DgnModelRefP mrP = NULL;
	int res = ERROR;

	if (mrWhereP == NULL) return NULL;

	res = mdlModelRef_createWorkingByName(&mrP, mdlModelRef_getDgnFile(mrWhereP), modname, TRUE, FALSE);

	if (res == SUCCESS && mrP)
		return mrP;

	res = mdlDgnFileObj_createModel(&mrP, mdlModelRef_getDgnFile(mrWhereP), mrWhereP, modname, 0, 0, 0);

	if (res == SUCCESS && mrP)
		return mrP;

	return NULL;

}

/////////////////////////////////
int scanElemCount(
	MSElementDescr* edP,
	void* prm,
	ScanCriteria* pScanCriteria
)
{
	elemCount4++;

	return 0;
}

/////////////////////////////////
int scanElemPointInside(
	MSElementDescr* edP,
	ReinPrm* prm,
	ScanCriteria* pScanCriteria
)
{

#if defined (AECOSIM)

	int type = 0;
	int bInside = FALSE;
	TFBrepList* pBrepNode = NULL;
	WCH sval[500] = L("");
	WCH sval2[500] = L("");

	if (prm == NULL) return 0;


	ELID id = mdlElement_getID(&edP->el); // стена

	if (id == prm->prmid) // та же конструкция, и мы уже в ней
		return 0;

	//MSElementDescrP eddP = edP->h.firstElem;

	TFFormRecipeList* flP = NULL;
	if (mdlTFFormRecipeList_constructFromElmdscr(&flP, edP) == BSISUCCESS)
	{
		double dCorrectParam = 0.;
		TFFormRecipe* fP = mdlTFFormRecipeList_getFormRecipe(flP);

		//const char* cn = mdlTFFormRecipe_getClassName(fP);
		//const char* pfn = mdlTFWString_getCharString (mdlTFFormRecipe_getPartFamilyName(fP));

		if (fP)
		{
			type = mdlTFFormRecipe_getType(fP);

			if (type == TF_STRUCTURAL_ELM
				|| type == TF_FREE_FORM_ELM
				)
			{
				TFFormRecipeFree* linP = (TFFormRecipeFree*)fP;
				TFStructProp* spP = (TFStructProp*)mdlTFFormRecipeFree_getStructProp(linP);
				if (spP)
				{
					WCHCP ssec = mdlTFStructProp_getSectionName(spP);
					SCPY(sval, ssec);
				}
			}
			else if (type == TF_LINEAR_FORM_ELM)
			{
				TFFormRecipeLinear* linP = (TFFormRecipeLinear*)fP;
				int res = mdlTFFormRecipeLinear_getThickness(linP, &dCorrectParam);
				if (res == SUCCESS)
				{
					SPRN(sval, L("%.0f"), mdlCnv_uorsToMasterUnits(dCorrectParam));
				}
			}
			else if (type == TF_SLAB_FORM_ELM)
			{
				TFFormRecipeSlab* linP = (TFFormRecipeSlab*)fP;
				int res = mdlTFFormRecipeSlab_getThickness(linP, &dCorrectParam);
				if (res == SUCCESS)
				{
					SPRN(sval, L("%.0f"), mdlCnv_uorsToMasterUnits(dCorrectParam));
				}
			}
			else
			{
				SPRN(sval, L("type%i"), type);
			}

		}

		mdlTFFormRecipeList_free(&flP);
	}
	

	prm->ival[0] = type;

	SPRN(sval2, L(";%s"), sval); // на случай если тип не обнаружит


	if (type &&
		mdlTFBrepList_constructFromElmdscr2(
		&pBrepNode,
		edP,
		mdlScanCriteria_getModel(pScanCriteria)) == BSISUCCESS)
	{

		TFFormRecipe* fP = mdlTFFormRecipeList_getFormRecipe(flP);

		TFBrep* pBrep = mdlTFBrepList_getBrep(pBrepNode);

		if (pBrep)
		{

			UShort i = 0;
			UShort ii = 0;
			XMLFragmentListP  oXMLFragmentList = NULL;
			WCH xmltxt[500];


			//printf("=============================\n");
			//printf("=============================\n");

/*
			<DataGroupInstances guid = "{196D124A-FB24-4DAA-B590-892F4D197297}">
				<DataGroup appType = "APP" catalogType = "ConcreteWalls" catalogItem = "10UCB Wall int C35/45 XS1 G2400" / >
			< / DataGroupInstances>
			___________________________                                                                                             
			<ConcreteExposure XC = "XC3" XD = "N/A" XS = "N/A" XF = "XF1" XA = "N/A" / >
			___________________________                                                                                             
			<ConcreteProperties C = "C35/45" G = "2400" D = "Normal" WT = "false" FCC = "Composition 1" CCW = "0.30 mm" SC = "MUO B" OSTC = "0.17" MM = "Cast in-situ" APC = "PS" EC = "3" RC = "B500C" CC = "1" / >
			___________________________                                                                                             
			<ObjectMaterial PartDefinition = "Concrete_Standart::Walls" / >
			___________________________                                                                                             
			<ObjectSpaceBounding IsSpaceBounding = "true" / >
			___________________________                                                                                             
			<ObjectThermalTransmittance IsExternal = "false" IsBelowGrade = "false" / >
			___________________________                                                                                             
			<ReinforcementSlab ASRO = "" ASRU = "" ASSO = "" ASSU = "" ASW = "" / >
			___________________________                                                                                             
			<StructProp StructNumber = "72" StructCode = "50UCB99_WL0072" ShortCode = "WL0072" FC = "REI120" SC = "2" NSC = "2" / >
			___________________________                                                                                             
			<WallGeometry Curved = "false" / >
			___________________________                                                                                             
			<WallQuantities LengthLeft = "100000.000000" LengthCenter = "115000.000000" LengthRight = "130000.000000" AreaLeftGross = "33999999999.998665" AreaCenterGross = "39099999999.997391" AreaRightGross = "44199999999.996109" AreaLeftNet = "33999999999.998650" AreaCenterNet = "39099999999.997391" AreaRightNet = "44199999999.996170" GrossVolume = "1563999999999900.000000" NetVolume = "1563999999999900.000000" / >
			___________________________
			<Wall_Application Width = "40000.000000" Height = "340000.000000" / >
			___________________________
			<Wall_Common Type = "Wall" IsCompound = "false" PartitionType = "" Cavity = "" / >

*/

			if (mdlXMLFragmentList_extractFromElementByAppIDAndType(&oXMLFragmentList, &edP->el, &i, &ii) == SUCCESS)
			{
				XMLFragmentListP pCurrent = NULL;
				for (pCurrent = oXMLFragmentList; pCurrent; pCurrent = mdlXMLFragmentList_getNext(pCurrent))
				{
					MSWChar* wtxt = NULL;
					XMLFragmentP  pXMLFragment = mdlXMLFragmentList_getXMLFragment(pCurrent);

					mdlXMLFragment_getText(&wtxt, pXMLFragment);

					SCPW2M(xmltxt, wtxt, 500);

					WCH seps[] = L("\"");
					WCH* token;

					token = STOK(xmltxt, seps);
					while (token)
					{
						if (SCMP(token, L(" catalogType=")) == 0)
						{
							token = STOK(NULL, seps);
							
							SCPY(sval2, token);
							SCAT(sval2, L(";"));
							SCAT(sval2, sval);

							break;
						}

						token = STOK(NULL, seps);
					}

					//printf("%S\n", wtxt);
					//printf("___________________________\n");

				}

				mdlXMLFragmentList_free(&oXMLFragmentList); // <<< oXMLFragmentList
			}

			//printf("=============================\n");
			//printf("=============================\n");



/*
			// очень замедляет работу эта штука...
			Bentley::Building::Elements::BuildingEditElemHandle beeh(edP->h.elementRef, edP->h.dgnModelRef);


			if (beeh.IsValid())
			{
				//int res = beeh.LoadDataGroupFromDisk();
				CCatalogCollection cc = beeh.GetCatalogCollection();

				if (cc.GetCatalogCollectionMap().size() > 0)
				{
					SCPW2M(sval2, cc.BeginC()->first.c_str(), 500);
					SCAT(sval2, sval);
				}

				SCAT(sval2, sval);
				for (CCatalogCollection::CCollectionConst_iterator it = cc.BeginC(); it != cc.EndC(); ++it)
				{
					for (CCatalogSchemaCollectionT::CSCollectionConst_iterator itt = it->second->BeginC(); itt != it->second->EndC(); ++itt)
					{
						for (CCatalogSchemaItemCollectionT::CSICollectionConst_iterator ittt = itt->second->BeginC(); ittt != itt->second->EndC(); ++ittt)
						{
							CCatalogSchemaItemT* pSchemaItem = *ittt;

							wstring s1 = pSchemaItem->GetCatalogInstanceName();
							wstring s2 = pSchemaItem->GetCatalogItemName();
							wstring s3 = pSchemaItem->GetSchemaName();
							wstring s4 = pSchemaItem->GetValue();

							wstring s5 = pSchemaItem->GetColumnName();
							wstring s6 = pSchemaItem->GetTableName();


							XmlDomRef dom;

							cc.BuildDom(&dom);

							mdlXMLDom_save(dom, FILESPEC_LOCAL, L"d:/dom.xml", L"AAA", L"BBB", L"Windows-1251", 0, 1, 1);

							mdlXMLDom_free(dom);

							return 1;
						}
					}
				}
			}

*/

			if (prm)
				bInside = mdlTFBrep_pointIsInside(pBrep, &prm->pVec);
			else
				bInside = FALSE;

			//if (bInside) printf("%i = %.2f %.2f %.2f\n", bInside, pCheckP->x, pCheckP->y, pCheckP->z);
		}

		mdlTFBrepList_free(&pBrepNode);

	}


	if (bInside)
	{
		STRING str(sval2);

		map <STRING, ReinPrm>::iterator it = mapSimPos.find(str);

		if (it == mapSimPos.end()) // found
		{
			ReinPrm rm; // clear() in constructor
			mapSimPos.insert(pair<STRING, ReinPrm>(str, rm));
			it = mapSimPos.find(str);
		}

		it->second.mapprm[prm->reP->bel.pnum].lval[0] = prm->reP->bel.pnum;

		it->second.mapprm[prm->reP->bel.pnum].uival[0]++;

		it->second.mapprm[prm->reP->bel.pnum].dval[0] += prm->reP->bel.length;

		prm->prmid = id;

	}






#endif

	return 0;
}



/////////////////////////////////
int scanReinElmExport(
	MSElementDescr* edP,
	//NamedGroupP ngP,
	DgnModelRefP mrP,
	ScanCriteria* pScanCriteria
)
{
	MSWCH wstr[100];
	//ReinElm relm;

	//int res = 0;

	if (
		//mdlElement_isVisible(&edP->el) == FALSE && 
		//crelm.getElmFromElement(&edP->el, mdlScanCriteria_getModel(pScanCriteria)) == SUCCESS)
		readReinElmIso(&crelm, edP, TRUE, TRUE) == SUCCESS)
	{
		/*
		if (crelm.type == REIN_ELEM_BAR)
		{
			int locked = TRUE;
			//ELID id = 0;
			mdlElmdscr_setVisible(edP, TRUE);
			//mdlElmdscr_setProperties(edP, 0, 0, 0, &locked, 0, 0, 0, 0);

			mdlXMLFragmentList_stripAllFromElement(NULL, &edP->el);

			_swprintf(wstr, L"REINASSEMBLY");
			XMLFragmentListP  pCurrent = mdlXMLFragmentList_construct(wstr, NULL, appID, appTypeReinAssem);
			mdlXMLFragmentList_attachToElement(&pCurrent, &edP, TRUE);

			mdlElmdscr_copy(&edP, ACTIVEMODEL, mrP, NULL);


			//id = mdlElement_getID(&edP->el);
			//mdlElmdscr_rewrite(edP, 0, mdlElmdscr_getFilePos(edP));
			//res = mdlNamedGroup_addMember(ngP, id, ACTIVEMODEL, NGMEMBERFLAG_GROUPPROPAGATEALWAYS);
		}
		*/

		if (crelm.type == REIN_ELEM_ISO) makeAssemblyElem(&crelm, edP, NULL, mrP, bExportSolids);

	}

	/*
	if (dlgProgressP)
	{
		elemIterCount4++;
		mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)(((double)elemIterCount4 / (double)elemCount4) * 100.));
		WaitMessage();
	}
	*/


	return 0;
}

/////////////////////////////////
int scanCageElmExport(
	MSElementDescr* edP,
	MSElementDescr** edpCagePP,
	ScanCriteria* pScanCriteria
)
{
	MSWCH wstr[100];

	//int res = 0;

	MSElementDescr* edpCageP = *edpCagePP;

	if (
		//mdlElement_isVisible(&edP->el) == FALSE && 
		crelm.getElmFromElement(&edP->el, mdlScanCriteria_getModel(pScanCriteria)) == SUCCESS)
	{
		if (crelm.type == REIN_ELEM_ISO) makeAssemblyElem(&crelm, edP, edpCagePP, NULL, bExportSolids);
	}
	else
	{
		MSElementDescr* newEdPP = NULL;
		mdlElmdscr_duplicate(&newEdPP, edP);
		mdlElmdscr_appendDscr(*edpCagePP, newEdPP);
	}

	/*
	if (dlgProgressP)
	{
		elemIterCount4++;
		mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)(((double)elemIterCount4 / (double)elemCount4) * 100.));
		WaitMessage();
	}
	*/


	return 0;
}


/////////////////////////////////////////////////////////
void getReinInfoFromString(ReinNoteSet& ri, MSWCH* str)
{
	setstr.clear();

	if (readFromString("getReinInfoFromString(ReinNoteSet...", &setstr, str, 
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//		L'\n',
//#else
		L"\n",
//#endif
		wcslen(str) + 10) != SUCCESS) return;

	if (setstr.empty()) return;

	for (SETSTR_BEGIN_ITER; it != setstr.end(); it++)
	{
		if (it->find(L"noteopt[") != string::npos)
		{
			int index = _wtoi(it->substr(wcslen(L"noteopt["), 3).c_str());
			ri.noteopt[index] = _wtoi(it->substr(wcslen(L"noteopt[000]=")).c_str());
		}

		if (it->find(L"noteval[") != string::npos)
		{
			int index = _wtoi(it->substr(wcslen(L"noteval["), 3).c_str());
			ri.noteval[index] = _wtof(it->substr(wcslen(L"noteval[000]=")).c_str());
		}

		if (it->find(L"iNoteDim=") != string::npos)
			ri.iNoteDim = _wtoi(it->substr(wcslen(L"iNoteDim=")).c_str());

		if (it->find(L"iNoteStyle=") != string::npos)
			ri.iNoteStyle = _wtoi(it->substr(wcslen(L"iNoteStyle=")).c_str());

		if (it->find(L"sNoteDn=") != string::npos)
			SCPW2M(ri.sNoteDn, it->substr(wcslen(L"sNoteDn=")).c_str(),100);

		if (it->find(L"sNoteDnFmt=") != string::npos)
			SCPW2M(ri.sNoteDnFmt, it->substr(wcslen(L"sNoteDnFmt=")).c_str(), 100);

		if (it->find(L"sNoteUp=") != string::npos)
			SCPW2M(ri.sNoteUp, it->substr(wcslen(L"sNoteUp=")).c_str(),100);

		if (it->find(L"sNoteUpFmt=") != string::npos)
			SCPW2M(ri.sNoteUpFmt, it->substr(wcslen(L"sNoteUpFmt=")).c_str(), 100);

		if (it->find(L"sNoteLevel=") != string::npos)
			SCPW2M(ri.sNoteLevel, it->substr(wcslen(L"sNoteLevel=")).c_str(), 100);


	}


}

/////////////////////////////////////////////////////////
void getReinInfoFromString(ReinDopInfo& ri, MSWCH* str)
{

	setstr.clear();

	if (readFromString("getReinInfoFromString(ReinDopInfo...", &setstr, str,
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//		L'\n',
//#else
		L"\n",
//#endif
		wcslen(str) + 10) != SUCCESS) return;

	if (setstr.empty()) return;

	for (SETSTR_BEGIN_ITER; it != setstr.end(); it++)
	{
		if (it->find(L"rDopInfo.dopopt[") != string::npos)
		{
			int index = _wtoi(it->substr(wcslen(L"rDopInfo.dopopt["), 3).c_str());
			ri.dopopt[index] = _wtoi(it->substr(wcslen(L"rDopInfo.dopopt[000]=")).c_str());
		}
		if (it->find(L"rDopInfo.dopval[") != string::npos)
		{
			int index = _wtoi(it->substr(wcslen(L"rDopInfo.dopval["), 3).c_str());
			ri.dopval[index] = _wtof(it->substr(wcslen(L"rDopInfo.dopval[000]=")).c_str());
		}
	}

	if (rDopInfo.dopval[6] < 0.01) rDopInfo.dopval[6] = 0.2;

}



/////////////////////////////////////////////////////////
void getReinInfoFromString(ReinInfo& ri, MSWCH* str)
{

	setstr.clear();

	if (readFromString("getReinInfoFromString(ReinInfo...", &setstr, str,
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//		L'\n',
//#else
		L"\n",
//#endif
		wcslen(str) + 10) != SUCCESS) return;

	if (setstr.empty()) return;

	for (SETSTR_BEGIN_ITER; it != setstr.end(); it++)
	{
		if (it->find(L"rInfo.option[") != string::npos)
		{
			int index = _wtoi(it->substr(wcslen(L"rInfo.option["), 3).c_str());
			ri.option[index] = _wtoi(it->substr(wcslen(L"rInfo.option[000]=")).c_str());
		}

		if (it->find(L"rInfo.b3d=") != string::npos)
			ri.b3d = _wtoi(it->substr(wcslen(L"rInfo.b3d=")).c_str());

		if (it->find(L"rInfo.bars=") != string::npos)
			ri.b3d = _wtoi(it->substr(wcslen(L"rInfo.bars=")).c_str());

		if (it->find(L"rInfo.bface=") != string::npos)
			ri.b3d = _wtoi(it->substr(wcslen(L"rInfo.bface=")).c_str());

		if (it->find(L"rInfo.ends=") != string::npos)
			ri.b3d = _wtoi(it->substr(wcslen(L"rInfo.ends=")).c_str());

		if (it->find(L"rInfo.lim=") != string::npos)
			ri.b3d = _wtoi(it->substr(wcslen(L"rInfo.lim=")).c_str());

		if (it->find(L"rInfo.nodes=") != string::npos)
			ri.b3d = _wtoi(it->substr(wcslen(L"rInfo.nodes=")).c_str());

		if (it->find(L"rInfo.run=") != string::npos)
			ri.b3d = _wtoi(it->substr(wcslen(L"rInfo.run=")).c_str());

		if (it->find(L"rInfo.threads=") != string::npos)
			ri.b3d = _wtoi(it->substr(wcslen(L"rInfo.threads=")).c_str());

		if (it->find(L"rInfo.ttip=") != string::npos)
			ri.b3d = _wtoi(it->substr(wcslen(L"rInfo.ttip=")).c_str());


		if (it->find(L"rInfo.rsVal.runmet=") != string::npos)
			ri.rsVal.runmet = _wtoi(it->substr(wcslen(L"rInfo.rsVal.runmet=")).c_str());

		if (it->find(L"rInfo.rsVal.diam=") != string::npos)
			ri.rsVal.diam = _wtoi(it->substr(wcslen(L"rInfo.rsVal.diam=")).c_str());

		if (it->find(L"rInfo.rsVal.space=") != string::npos)
		{
			//ri.rsVal.space = _wtoi(it->substr(wcslen(L"rInfo.rsVal.space=")).c_str());
			ri.rsVal.spacef = _wtof(it->substr(wcslen(L"rInfo.rsVal.space=")).c_str());
		}
		//if (it->find(L"rInfo.rsVal.space2=") != string::npos)
		//	ri.rsVal.space2 = _wtoi(it->substr(wcslen(L"rInfo.rsVal.space2=")).c_str());

		if (it->find(L"rInfo.rsVal.bendrad=") != string::npos)
			ri.rsVal.bendrad = _wtoi(it->substr(wcslen(L"rInfo.rsVal.bendrad=")).c_str());

		if (it->find(L"rInfo.rsVal.offset[0]=") != string::npos)
			ri.rsVal.offset[0] = _wtoi(it->substr(wcslen(L"rInfo.rsVal.offset[0]=")).c_str());

		if (it->find(L"rInfo.rsVal.offset[1]=") != string::npos)
			ri.rsVal.offset[1] = _wtoi(it->substr(wcslen(L"rInfo.rsVal.offset[1]=")).c_str());

		if (it->find(L"rInfo.rsVal.poscalc=") != string::npos)
			ri.rsVal.poscalc = _wtoi(it->substr(wcslen(L"rInfo.rsVal.poscalc=")).c_str());
	}

}

/////////////////////////////////////////////////////////
void setReinInfoString(ReinNoteSet& ri, wstring* wstr)
{

	MSWCH str[500];

	wstr->clear();

	for (int i = 0; i < 10; i++)
	{
		if (ri.noteopt[i] < -10000 || ri.noteopt[i] > 10000)
			ri.noteopt[i] = 1;

		_swprintf(str, L"noteopt[%03d]=%i\n", i, ri.noteopt[i]);
		wstr->append(str);
	}

	for (int i = 0; i < 10; i++)
	{
		_swprintf(str, L"noteval[%03d]=%0.5f\n", i, ri.noteval[i]);
		wstr->append(str);
	}

	_swprintf(str, L"iNoteDim=%i\n", ri.iNoteDim);
	wstr->append(str);

	_swprintf(str, L"iNoteStyle=%i\n", ri.iNoteStyle);
	wstr->append(str);

#if defined (MSVERSION) && (MSVERSION == 0x8b0)
	_swprintf(str, L"sNoteDn=%S\n", ri.sNoteDn);
	wstr->append(str);

	_swprintf(str, L"sNoteDnFmt=%S\n", ri.sNoteDnFmt);
	wstr->append(str);

	_swprintf(str, L"sNoteUp=%S\n", ri.sNoteUp);
	wstr->append(str);

	_swprintf(str, L"sNoteUpFmt=%S\n", ri.sNoteUpFmt);
	wstr->append(str);

	_swprintf(str, L"sNoteLevel=%S\n", ri.sNoteLevel);
	wstr->append(str);

#else
	_swprintf(str, L"sNoteDn=%s\n", ri.sNoteDn);
	wstr->append(str);

	_swprintf(str, L"sNoteDnFmt=%s\n", ri.sNoteDnFmt);
	wstr->append(str);

	_swprintf(str, L"sNoteUp=%s\n", ri.sNoteUp);
	wstr->append(str);

	_swprintf(str, L"sNoteUpFmt=%s\n", ri.sNoteUpFmt);
	wstr->append(str);

	_swprintf(str, L"sNoteLevel=%s\n", ri.sNoteLevel);
	wstr->append(str);

#endif


}

/////////////////////////////////////////////////////////
void setReinInfoString(ReinDopInfo& ri, wstring* wstr)
{

	MSWCH str[500];

	wstr->clear();

	for (int i = 0; i < 50; i++)
	{
		if (ri.dopopt[i] < -10000 || ri.dopopt[i] > 10000)
			ri.dopopt[i] = 1;

		_swprintf(str, L"rDopInfo.dopopt[%03d]=%i\n", i, ri.dopopt[i]);
		wstr->append(str);
	}

	for (int i = 0; i < 50; i++)
	{
		_swprintf(str, L"rDopInfo.dopval[%03d]=%.5f\n", i, ri.dopval[i]);
		wstr->append(str);
	}

	//for (int i = 0; i < 20; i++)
	//{
	//	_swprintf(str, L"rDopInfo.dopopt[%03d]=%s\n", i, ri.doptxt[i]);
	//	wstr->append(str);
	//}

}

/////////////////////////////////////////////////////////
void setReinInfoString(ReinInfo &ri, wstring* wstr)
{

	writeLogIn(__FUNCTION__, 0);

	MSWCH str[500];

	wstr->clear();

	for (int i = 0; i < 20; i++)
	{
		if (ri.option[i] < -10000 || ri.option[i] > 10000)
			ri.option[i] = 1;

		_swprintf(str, L"rInfo.option[%03d]=%i\n", i, ri.option[i]);
		wstr->append(str);
	}

	_swprintf(str, L"rInfo.b3d=%i\n", ri.b3d);
	wstr->append(str);

	_swprintf(str, L"rInfo.bars=%i\n", ri.bars);
	wstr->append(str);

	_swprintf(str, L"rInfo.bface=%i\n", ri.bface);
	wstr->append(str);

	_swprintf(str, L"rInfo.ends=%i\n", ri.ends);
	wstr->append(str);

	_swprintf(str, L"rInfo.lim=%i\n", ri.lim);
	wstr->append(str);

	_swprintf(str, L"rInfo.nodes=%i\n", ri.nodes);
	wstr->append(str);

	_swprintf(str, L"rInfo.run=%i\n", ri.run);
	wstr->append(str);

	_swprintf(str, L"rInfo.threads=%i\n", ri.threads);
	wstr->append(str);

	_swprintf(str, L"rInfo.ttip=%i\n", ri.ttip);
	wstr->append(str);


	_swprintf(str, L"rInfo.rsVal.runmet=%i\n", ri.rsVal.runmet);
	wstr->append(str);

	_swprintf(str, L"rInfo.rsVal.diam=%i\n", ri.rsVal.diam);
	wstr->append(str);

	_swprintf(str, L"rInfo.rsVal.space=%.1f\n", ri.rsVal.spacef);
	wstr->append(str);
	//_swprintf(str, L"rInfo.rsVal.space2=%i\n", ri.rsVal.space2);
	//wstr->append(str);

	_swprintf(str, L"rInfo.rsVal.bendrad=%i\n", ri.rsVal.bendrad);
	wstr->append(str);

	_swprintf(str, L"rInfo.rsVal.offset[0]=%i\n", ri.rsVal.offset[0]);
	wstr->append(str);

	_swprintf(str, L"rInfo.rsVal.offset[1]=%i\n", ri.rsVal.offset[1]);
	wstr->append(str);

	_swprintf(str, L"rInfo.rsVal.poscalc=%i\n", ri.rsVal.poscalc);
	wstr->append(str);

	writeLogOut(__FUNCTION__, 0);

}


////////////////////////////////////////////////
void setRienInfoDefaults()
{
	writeLogIn(__FUNCTION__, 0);

	rInfo.clear();

	rInfo.option[7] = TRUE;
	rInfo.ttip = TRUE;

	rInfo.rsVal.runmet = 0;
	rInfo.rsVal.diam  = 20;
	//rInfo.rsVal.space  = iSpaceDefault;
	rInfo.rsVal.spacef  = (double)iSpaceDefault;
	//rInfo.rsVal.space2  = iSpaceDefault;
	rInfo.rsVal.bendrad  = 0;
	rInfo.rsVal.offset[0] = 50;
	rInfo.rsVal.offset[1] = 0;
	rInfo.rsVal.poscalc  = 0;

	rInfo.rsVal.trmPar[2][0] = iCfgVar_MuftLapType;
	rInfo.rsVal.trmPar[2][1] = iCfgVar_MuftLapType;

	//rInfo.aInfo.diam = 20;
	//rInfo.aInfo.arm = 2;
	//rInfo.aInfo.bet = 2;
	//rInfo.aInfo.wall = 600;

	rInfo.option[2] = 1;
	rInfo.option[4] = 1;
	rInfo.option[5] = 1;
	rInfo.option[11] = 1;
	rInfo.option[12] = 0;
	rInfo.ends = 1;
	rInfo.option[13] = 1;
	rInfo.option[14] = 1;
	rInfo.lim = 0;
	
	rInfo.option[0] = 0;

	rDopInfo.dopval[6] = 0.2;

	writeLogOut(__FUNCTION__, 0);

}
/*
/////////////////////////////////
int loadNodesData()
{

	char* ssv;
	FILE* fN = NULL;
	FILE* fL = NULL;
	WCH ls[200];
	long ind;
	LoadNode* liP = NULL;
	LoadVert* lvP = NULL;
	int ret = SUCCESS;

	DVec3d pOrg;

	mdlVec_zero(&pOrg);

	if (getCfgVarEx (ls, L"REIN_DATA_LOADS_ORIGIN_X", 200) == SUCCESS)
		pOrg.x = atof(ls);

	if (getCfgVarEx (ls, L"REIN_DATA_LOADS_ORIGIN_Y", 200) == SUCCESS)
		pOrg.y = atof(ls);



	if (mdlVec_pointOffDesignPlane(&pOrg))
		mdlVec_zero(&pOrg);


	ssv = mdlSystem_getExpandedCfgVar (L"REIN_DATA_LOADS_NODES");
	if (ssv)
	{
		strcpy(sCfgVar_LoadsNodes, ssv);
		mdlSystem_freeCfgVarBuffer(ssv);
	}
	else
	{
		sCfgVar_LoadsNodes[0] = 0x0;
		return ERROR;
	}


	ssv = mdlSystem_getExpandedCfgVar (L"REIN_DATA_LOADS_VALUES");
	if (ssv)
	{
		strcpy(sCfgVar_LoadsValues, ssv);
		mdlSystem_freeCfgVarBuffer(ssv);
	}
	else
	{
		sCfgVar_LoadsValues[0] = 0x0;
		return ERROR;
	}



	fN = mdlTextFile_open(sCfgVar_LoadsNodes, TEXTFILE_READ);
	if (fN == NULL) return ERROR;

	fL = mdlTextFile_open(sCfgVar_LoadsValues, TEXTFILE_READ);
	if (fL == NULL)
	{
		if (fN) mdlTextFile_close(fN);
		return ERROR;
	}



	//if (daCurLoadNodes) mdlDArray_destroy(daCurLoadNodes);
	//daCurLoadNodes = mdlDArray_create (sizeof (ArrayObjectHdr), sizeof(LoadNode), 0, 0, 0); 

daCurLoadNodes.clear();

	if (daCurLoadVerts) mdlDArray_destroy(daCurLoadVerts);
	daCurLoadVerts = mdlDArray_create (sizeof (ArrayObjectHdr), sizeof(LoadVert), 0, 0, 0); 


	dLoadNodeSpacing = mdlCnv_masterUnitsToUors(dLoadNodeSpacing);


	while(mdlTextFile_getString(ls, 200, fN, TEXTFILE_DEFAULT))
	{

		if (ls[0] == ' ' && ls[1] == '3') break;

		if (ls[0] == ' ' && ls[1] == '1')
		{
			char seps[]   = " ";
			char *token;

			liP = (LoadNode*)mdlDArray_insertMembers(daCurLoadNodes, 0, 1, -1);

			//ZeroMemory(liP, sizeof(LoadNode));

			if (mdlTextFile_getString(ls, 200, fN, TEXTFILE_DEFAULT) == NULL) 
			{
				ret = ERROR;
				break;
			}


			token = strtok( ls, seps );
			if (token == NULL )	continue;
			liP->org.x = mdlCnv_masterUnitsToUors(pOrg.x + atof(token) * 1000.);

			token = strtok( NULL, seps );
			if( token == NULL )	continue;
			liP->org.y = mdlCnv_masterUnitsToUors(pOrg.y + atof(token) * 1000.);

			token = strtok( NULL, seps );
			if( token == NULL )	continue;
			liP->org.z = mdlCnv_masterUnitsToUors(atof(token) * 1000.);

			ind = -1;


		}


		if (ls[0] == ' ' && ls[1] == '2')
		{


			ind = atol(&ls[2]) - 1;

			if (ind >= mdlDArray_nMembers(daCurLoadNodes))
			{
				// неверный способ
				mdlDialog_dmsgsPrint(L"error reading calculation data");
				ret = ERROR;
				break;
			}

			// запоминаем
			liP = (LoadNode*)mdlDArray_getMemberP(daCurLoadNodes, ind);

			// пропускаем строчку
			if (mdlTextFile_getString(ls, 200, fN, TEXTFILE_DEFAULT) == NULL)
			{
				ret = ERROR;
				break;
			}


		}
		else if (liP != NULL && ind >= 0)
		{

			char seps[]   = " ";
			char *token;

			token = strtok( ls, seps );
			if (token == NULL )	continue;
			liP->vertind[0] = atol(token);

			token = strtok( NULL, seps );
			if( token == NULL )	continue;
			liP->vertind[1] = atol(token);

			token = strtok( NULL, seps );
			if( token == NULL )	continue;
			liP->vertind[2] = atol(token);

			token = strtok( NULL, seps );
			if( token == NULL )	continue;
			liP->vertind[3] = atol(token);

			//if (ind < 100 || ind > 3000)
			//	printf("%i  %f %f %f  %i %i %i %i\n", 
			//	ind+1, 
			//	liP->org.x, liP->org.y, liP->org.z, 
			//	liP->vertind[0], liP->vertind[1], liP->vertind[2],liP->vertind[3] );

		}


	}

	ind = -1;

	while(mdlTextFile_getString(ls, 200, fL, TEXTFILE_DEFAULT))
	{
		if (atol(ls) == 1) ind = 0;


		if (ind >= 0)
		{
			lvP = (LoadVert*)mdlDArray_insertMembers(daCurLoadVerts, 0, 1, -1);

			//ZeroMemory(lvP, sizeof(LoadVert));

			if (mdlTextFile_getString(ls, 200, fL, TEXTFILE_DEFAULT) == NULL) 
			{
				ret = ERROR;
				break;
			}

			lvP->vals[6] = atof(&ls[13*5]);
			ls[13*5] = 0x0;

			lvP->vals[5] = atof(&ls[13*4]);
			ls[13*4] = 0x0;

			lvP->vals[4] = atof(&ls[13*3]);
			ls[13*3] = 0x0;

			lvP->vals[3] = atof(&ls[13*2]);
			ls[13*2] = 0x0;

			lvP->vals[2] = atof(&ls[13*1]);
			ls[13*1] = 0x0;

			lvP->vals[1] = atof(&ls[13*0]);



			if (mdlTextFile_getString(ls, 200, fL, TEXTFILE_DEFAULT) == NULL) 
			{
				ret = ERROR;
				break;
			}

			lvP->vals[12] = atof(&ls[13*5]);
			ls[13*5] = 0x0;

			lvP->vals[11] = atof(&ls[13*4]);
			ls[13*4] = 0x0;

			lvP->vals[10] = atof(&ls[13*3]);
			ls[13*3] = 0x0;

			lvP->vals[9] = atof(&ls[13*2]);
			ls[13*2] = 0x0;

			lvP->vals[8] = atof(&ls[13*1]);
			ls[13*1] = 0x0;

			lvP->vals[7] = atof(&ls[13*0]);

			//printf("%i  %f %f %f %f\n", 
			//	ind+1, 
			//	lvP->vals[LI_REQ_BOT_X], lvP->vals[LI_REQ_BOT_Y], lvP->vals[LI_REQ_TOP_X], lvP->vals[LI_REQ_TOP_Y]);

			ind++;
		}


	}





	if (fN) mdlTextFile_close(fN);
	if (fL) mdlTextFile_close(fL);




	//====================================================
	//{
	//	int i;
	//	arLoadVerts = calloc(sizeof(DVec3d), mdlDArray_nMembers(daCurLoadNodes));
	//	for (i = 0; i < mdlDArray_nMembers(daCurLoadNodes); i++)
	//	{
	//		LoadNode* lnP = mdlDArray_getMemberP(daCurLoadNodes, i);
	//		arLoadVerts[i] = lnP->org;
	//	}
	//}
	//====================================================





	return ret;


}

*/

//////////////////
void loadSchemaFile(bool bImportIfNotFound, WCHCP sModInst)
{
	/*
#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX
	ECN::ECSchemaPtr schemaHolder;

	DgnFileP dfP = ISessionMgr::GetActiveDgnFile();
	DgnModelP dmP = ISessionMgr::GetActiveDgnModelP();
	DgnModelRefP mrP = ACTIVEMODEL;

	if (dfP == NULL) return;
	if (dmP == NULL) return;
	if (mrP == NULL) return;


	WCH  path[500];

	if (getCfgVar(path, L("REIN_SCHEMA_PATH")) != SUCCESS)
	{
		// message?
		return;
	}


	// read schema file
	ECN::SchemaReadStatus st = Bentley::DgnPlatform::DgnECManager::GetManager().ReadSchemaFromXmlFile(schemaHolder, path, NULL);

	if (st != ECN::SchemaReadStatus::SCHEMA_READ_STATUS_Success)
	{
		// message?
		return;
	}


	// try to update
	SchemaUpdateStatus ust = Bentley::DgnPlatform::DgnECManager::GetManager().UpdateSchema(*schemaHolder, *dfP, false);

	if (ust != SchemaUpdateStatus::SCHEMAUPDATE_Success && bImportIfNotFound)
	{
		// import
		SchemaImportStatus ist = Bentley::DgnPlatform::DgnECManager::GetManager().ImportSchema(*schemaHolder, *dfP, false, true);
	}

	//UInt32 cnt = schemaHolder->GetRefCount();

	if (sModInst == NULL) return;

	ECN::ECClassCP  ecClass = schemaHolder->GetClassCP(sModInst);

	if (ecClass == NULL) return;

	DgnECInstanceEnablerP enablerP = Bentley::DgnPlatform::DgnECManager::GetManager().ObtainInstanceEnabler(*ecClass, *dfP);
	//DgnECInstanceEnablerP enablerP = Bentley::DgnPlatform::DgnECManager::GetManager().ObtainInstanceEnablerByName(L"ReinSchema", className, *dfP);

	if (enablerP)
	{

		bool bExist = false;
		ECN::ECInstanceList il;
		Bentley::DgnPlatform::DgnECManager::GetManager().ReadECInstancesFromModel(il, *dmP);

		for (UInt32 i = 0; i < il.size(); i++)
		{
			ECN::ECClassCR c = il[i]->GetClass();
			if (c.GetName() == sModInst)
				bExist = true;
		}

		if (!bExist)
		{
			ECN::StandaloneECInstanceR wipInstance = enablerP->GetSharedWipInstance();

			wipInstance.SetValue(L"DisplayForming", ECN::ECValue(true));
			wipInstance.SetValue(L"DisplayDerived", ECN::ECValue(true));

			DgnECInstancePtr firstInstance;
			DgnECInstanceStatus status = enablerP->CreateInstanceOnModel(&firstInstance, wipInstance, *dmP);
		}


	}
#endif
*/
}


/////////////////////////////////
void setDefaultStyles()
{
	UInt32       color0 = 0;
	UInt32       color3 = 3;

	UInt32       weight0 = 0;
	UInt32       weight1 = 1;
	UInt32       weight5 = 5;
	UInt32       weight9 = 9;

	Int32       style0 = 0; 
	Int32       style1 = 1; 
	Int32       style2 = 2; 
	Int32       style4 = 4; 

	DVec3d p[3];
	//char v[10];
	char* ssv;

	writeLogIn(__FUNCTION__, 0);

	for (int b = 0; b < 3; b++)
		mdlVec_zero(&p[b]);

	rInfo.rcUnit.clear();

	curPos.clear();
	//curPosP = NULL;


	rInfo.rsVal.segmIndex = 0;
	rInfo.rsVal.elemEDoffset = 0;

	//printf("%i\n", mdlModelRef_is3D(MASTERFILE));

	if (iDebug) sprintf(sLogMes, "creating shapes...\n"); writeLog(0, 0);
	mdlShape_create (&c0w1s0, NULL, p, 3, 1);
	mdlShape_create (&c0w1s0_nofill, NULL, p, 3, 0);
	mdlShape_create (&c0w0s0, NULL, p, 3, 1);
	mdlShape_create (&c0w0s1, NULL, p, 3, 1);
	mdlShape_create (&c0w0s2, NULL, p, 3, 1);
	mdlShape_create (&c3w1s0, NULL, p, 3, 1);
	mdlShape_create (&c0w0s4, NULL, p, 3, 1);
	mdlShape_create (&c3w5s0, NULL, p, 3, 1);
	mdlShape_create (&c3w9s0, NULL, p, 3, 1);

	if (iDebug) sprintf(sLogMes, "set shapes symbology...\n"); writeLog(0, 0);
	mdlElement_setSymbology(&c0w1s0, &color0, &weight1, &style0);
	mdlElement_setSymbology(&c0w1s0_nofill, &color0, &weight1, &style0);
	mdlElement_setSymbology(&c0w0s0, &color0, &weight0, &style0);
	mdlElement_setSymbology(&c0w0s1, &color0, &weight0, &style1);
	mdlElement_setSymbology(&c0w0s2, &color0, &weight0, &style2);
	mdlElement_setSymbology(&c3w1s0, &color3, &weight1, &style0);
	mdlElement_setSymbology(&c0w0s4, &color0, &weight0, &style4);
	mdlElement_setSymbology(&c3w5s0, &color3, &weight5, &style0);
	mdlElement_setSymbology(&c3w9s0, &color3, &weight9, &style0);



	if (iDebug) sprintf(sLogMes, "mdlRMatrix_getIdentity\n"); writeLog(0, 0);
	mdlRMatrix_getIdentity(&rmIdent);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	txtParam[0].font = 1025;
	txtParam[0].just = TextElementJustification::LeftTop;
	txtParam[0].viewIndependent = FALSE;

	txtParam[1].font = 1025;
	txtParam[1].just = TextElementJustification::LeftMiddle;
	txtParam[1].viewIndependent = FALSE;

	txtParam[2].font = 1025;
	txtParam[2].just = TextElementJustification::LeftBaseline;
	txtParam[2].viewIndependent = FALSE;

	txtParam[3].font = 1025;
	txtParam[3].just = TextElementJustification::CenterTop;
	txtParam[3].viewIndependent = FALSE;

	txtParam[4].font = 1025;
	txtParam[4].just = TextElementJustification::CenterMiddle;
	txtParam[4].viewIndependent = FALSE;

	txtParam[5].font = 1025;
	txtParam[5].just = TextElementJustification::CenterBaseline;
	txtParam[5].viewIndependent = FALSE;

	txtParam[6].font = 1025;
	txtParam[6].just = TextElementJustification::RightTop;
	txtParam[6].viewIndependent = FALSE;

	txtParam[7].font = 1025;
	txtParam[7].just = TextElementJustification::RightMiddle;
	txtParam[7].viewIndependent = FALSE;

	txtParam[8].font = 1025;
	txtParam[8].just = TextElementJustification::RightBaseline;
	txtParam[8].viewIndependent = FALSE;
#endif
	//	{ 1025, TextElementJustification::LeftTop, 0, FALSE },
	//	{ 1025, TextElementJustification::LeftMiddle, 0, FALSE },
	//	{ 1025, TextElementJustification::LeftBaseline, 0, FALSE },
	//	{ 1025, TextElementJustification::CenterTop, 0, FALSE },
	//	{ 1025, TextElementJustification::CenterMiddle, 0, FALSE },
	//	{ 1025, TextElementJustification::CenterBaseline, 0, FALSE },
	//	{ 1025, TextElementJustification::RightTop, 0, FALSE },
	//	{ 1025, TextElementJustification::RightMiddle, 0, FALSE },
	//	{ 1025, TextElementJustification::RightBaseline, 0, FALSE }


	WCH    v[500];

	//if (getCfgVarEx(v, L"REIN_BAR_JOINT_MODE", 10) == SUCCESS)
	//	iCfgVar_JointMode = atoi(v);
	//else
	//	iCfgVar_JointMode = BAR_JOINT_RING;

	//if (getCfgVarEx(v, L"REIN_BAR_JOINT_DIAM", 10) == SUCCESS)
	//	iCfgVar_JointDiam = atoi(v);
	//else
	//	iCfgVar_JointDiam = 28;


	//REIN_SKETCH_CELL_HEIGHT		: 4000
	//REIN_SKETCH_CELL_WIDTH1		: 1000
	//REIN_SKETCH_CELL_WIDTH2		: 7000
	//REIN_SKETCH_CELL_GAP		: 1600

	//double dCfgVar_SketchHgt;
	//double dCfgVar_SketchWdtNum;
	//double dCfgVar_SketchWdtDrw;
	//double dCfgVar_SketchGap;


	if (getCfgVar(v, L("REIN_SKETCH_CELL_HEIGHT")) == SUCCESS)
		dCfgVar_SketchHgt = STOF(v);
	else
		dCfgVar_SketchHgt = 4000.;

	if (getCfgVar(v, L("REIN_SKETCH_CELL_WIDTH1")) == SUCCESS)
		dCfgVar_SketchWdtNum = STOF(v);
	else
		dCfgVar_SketchWdtNum = 1000.;

	if (getCfgVar(v, L("REIN_SKETCH_CELL_WIDTH2")) == SUCCESS)
		dCfgVar_SketchWdtDrw = STOF(v);
	else
		dCfgVar_SketchWdtDrw = 7000.;

	if (getCfgVar(v, L("REIN_SKETCH_CELL_GAP")) == SUCCESS)
		dCfgVar_SketchGap = STOF(v);
	else
		dCfgVar_SketchGap = 1600.;


	if (EQQ(rDopInfo.dopval[0], 0., 0.01)) rDopInfo.dopval[0] = dCfgVar_SketchHgt;
	if (EQQ(rDopInfo.dopval[4], 0., 0.01)) rDopInfo.dopval[1] = dCfgVar_SketchWdtNum;
	if (EQQ(rDopInfo.dopval[2], 0., 0.01)) rDopInfo.dopval[2] = dCfgVar_SketchWdtDrw;
	if (EQQ(rDopInfo.dopval[3], 0., 0.01)) rDopInfo.dopval[3] = dCfgVar_SketchGap;
	if (rDopInfo.dopopt[8] < 0) rDopInfo.dopopt[8] = 0;


	



	if (getCfgVar(v, L("REIN_MUFT_THREAD_SHIFT")) == SUCCESS)
		iCfgVar_NewMuftDraw = STOI(v);
	else
		iCfgVar_NewMuftDraw = FALSE;




	if (getCfgVar(v, L("REIN_BAR_SEC_SCALE")) == SUCCESS)
		dCfgVar_BarSecScale = STOF(v);
	else
		dCfgVar_BarSecScale = 15.;



	if (getCfgVar(v, L("REIN_BEND_DRAW")) == SUCCESS)
		iCfgVar_BendNewDraw = STOI(v);
	else
		iCfgVar_BendNewDraw = 0;


	if (getCfgVarEx(v, L"REIN_COMPARISON_3D") == SUCCESS)
		iCfgVar_BarCompare_3d = STOI(v);
	else
		iCfgVar_BarCompare_3d = FALSE;


	if (getCfgVarEx(v, L"REIN_USE_NULL_FILLET") == SUCCESS)
		iCfgVar_NullFillet = STOI(v);
	else
		iCfgVar_NullFillet = TRUE;


	if (getCfgVarEx(v, L"REIN_SPACE_HOLD_LINE") == SUCCESS)
		iCfgVar_SpaceHoldLine = STOI(v);
	else
		iCfgVar_SpaceHoldLine = FALSE;

	if (getCfgVarEx(v, L"REIN_POS_SORT_BY_PARAMETERS") == SUCCESS)
		iCfgVar_SortPlus = STOI(v);
	else
		iCfgVar_SortPlus = FALSE;

	if (getCfgVarEx(v, L"REIN_REF_BAR_SECTION_SNAP") == SUCCESS)
		iCfgVar_SectionPoints = STOI(v);
	else
		iCfgVar_SectionPoints = FALSE;

	if (getCfgVarEx(v, L"REIN_BARSET_REF_NESTING") == SUCCESS)
		iCfgVar_BarSetRefNesting = STOI(v);
	else
		iCfgVar_BarSetRefNesting = -1;



	if (getCfgVarEx(v, L"REIN_POS_USE_LAP_PARITY") == SUCCESS)
		iCfgVar_PosCalc_Laps = STOI(v);
	else
		iCfgVar_PosCalc_Laps = FALSE;

	if (getCfgVarEx(v, L"REIN_BAR_BENDTYPE_AUTOMATIC") == SUCCESS)
		iCfgVar_BarBendTypeAuto = STOI(v);
	else
		iCfgVar_BarBendTypeAuto = FALSE;

	if (getCfgVarEx(v, L"REIN_BAR_USE_GHOST_CONTOUR") == SUCCESS)
		iCfgVar_UseGhostContour = STOI(v);
	else
		iCfgVar_UseGhostContour = TRUE;






	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_SYMB_STYLE_SPC)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_SYMB_STYLE_SPC") == SUCCESS)
		iCfgVar_SymbStyle_Spc = STOI(v);
	else
		iCfgVar_SymbStyle_Spc = 3;

	if (getCfgVarEx(v, L"REIN_SYMB_WEIGHT_ELM") == SUCCESS)
		iCfgVar_SymbWeight_Elm = STOI(v);
	else
		iCfgVar_SymbWeight_Elm = 2;

	if (getCfgVarEx(v, L"REIN_SYMB_COLOR_ELM") == SUCCESS)
	{
		if (SCMP(v, L("BYLEVEL")) == 0)
			iCfgVar_SymbColor_Elm = -2;
		else
			iCfgVar_SymbColor_Elm = STOI(v);
	}
	else
		iCfgVar_SymbColor_Elm = -1;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_CONSTR_SPC)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_CONSTR_SPC") == SUCCESS)
		iCfgVar_Class_Spc = STOI(v);
	else
		iCfgVar_Class_Spc = -1;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_CONSTR_BAR)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_CONSTR_BAR") == SUCCESS)
		iCfgVar_Class_Bar = STOI(v);
	else
		iCfgVar_Class_Bar = -1;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_CONSTR_ELM)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_CONSTR_ELM") == SUCCESS)
		iCfgVar_Class_Elm = STOI(v);
	else
		iCfgVar_Class_Elm = -1;


	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_TRANSP_ELM_OUT)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_TRANSP_ELM_OUT") == SUCCESS)
		iCfgVar_Transp_Elm_Out = STOI(v);
	else
		iCfgVar_Transp_Elm_Out = -1;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_TRANSP_ELM_INN)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_TRANSP_ELM_INN") == SUCCESS)
		iCfgVar_Transp_Elm_Inn = STOI(v);
	else
		iCfgVar_Transp_Elm_Inn = -1;


	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_FILLET_RADIUS_D)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_FILLET_RADIUS_D") == SUCCESS)
		dCfgVar_FilletRadiusKoef = STOF(v);
	else
		dCfgVar_FilletRadiusKoef = -1.;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_FILLET_RADIUS_D_DEFAULT)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_FILLET_RADIUS_D_DEFAULT") == SUCCESS)
		dCfgVar_FilletRadiusKoefDef = STOF(v);
	else
		dCfgVar_FilletRadiusKoefDef = 0.;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_FILLET_STARTING_D)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_FILLET_STARTING_D") == SUCCESS)
		iCfgVar_FilletStartingDiam = STOI(v);
	else
		iCfgVar_FilletStartingDiam = 20;

	if (iCfgVar_FilletStartingDiam < 0) iCfgVar_FilletStartingDiam = 0;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_BAR_BEND_ROUND_SNAP)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_BAR_BEND_ROUND_SNAP") == SUCCESS)
		dCfgVar_BarBendLengthRoundSnap = STOF(v);
	else
		dCfgVar_BarBendLengthRoundSnap = 10.;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_BAR_LINE_ROUND_SNAP)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_BAR_LINE_ROUND_SNAP") == SUCCESS)
		dCfgVar_BarLineLengthRoundSnap = STOF(v);
	else
		dCfgVar_BarLineLengthRoundSnap = 5.;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_MUFT_WIDTH_COEF)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_MUFT_WIDTH_COEF") == SUCCESS)
		dCfgVar_MuftWdtKoef = STOF(v);
	else
		dCfgVar_MuftWdtKoef = 0.75;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_MUFT_HEIGHT_COEF)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_MUFT_HEIGHT_COEF") == SUCCESS)
		dCfgVar_MuftHgtKoef = STOF(v);
	else
		dCfgVar_MuftHgtKoef = 1.5;

	//sprintf(sLogMes, "getCfgVarEx(REIN_BAR_DIAMRIF_DELTA)\n"); writeLog(0, 0);
	//if (getCfgVarEx(v, "REIN_BAR_DIAMRIF_DELTA") == SUCCESS)
	//	iCfgVar_DiamRifDelta = STOI(v);
	//else
	//	iCfgVar_DiamRifDelta = 10;

	//if (iCfgVar_DiamRifDelta < 0) iCfgVar_DiamRifDelta = 0;


	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_COMPARISON_TOL)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_COMPARISON_TOL") == SUCCESS)
		iCfgVar_ComparisonTol = STOI(v);
	else
		iCfgVar_ComparisonTol = 5;


	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_COMPARISON_TOL)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_REDUCERS_SCAN_TOL") == SUCCESS)
		iCfgVar_MuftTol = STOI(v);
	else
		iCfgVar_MuftTol = 10;


	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_MIN_SEGMENT)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_MIN_SEGMENT") == SUCCESS)
		iCfgVar_MinSegment = STOI(v);
	else
		iCfgVar_MinSegment = 1; // было 10, но глючит когда масштаб реф-са больше 10


	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_MUFT_LAP_TYPE)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_MUFT_LAP_TYPE") == SUCCESS)
		iCfgVar_MuftLapType = STOI(v);
	else
		iCfgVar_MuftLapType = 1; // позиционная

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_MUFT_TYPE_0_ENABLED)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_MUFT_TYPE_0_ENABLED") == SUCCESS)
		iCfgVar_MuftTypeEnabled[0] = STOI(v);
	else
		iCfgVar_MuftTypeEnabled[0] = 1;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_MUFT_TYPE_1_ENABLED)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_MUFT_TYPE_1_ENABLED") == SUCCESS)
		iCfgVar_MuftTypeEnabled[1] = STOI(v);
	else
		iCfgVar_MuftTypeEnabled[1] = 1;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_MUFT_TYPE_2_ENABLED)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_MUFT_TYPE_2_ENABLED") == SUCCESS)
		iCfgVar_MuftTypeEnabled[2] = STOI(v);
	else
		iCfgVar_MuftTypeEnabled[2] = 1;


	if (getCfgVarEx(v, L"REIN_OPTIONS_ENABLE") == SUCCESS)
		iCfgVar_EnableOptions = STOI(v);
	else
		iCfgVar_EnableOptions = FALSE;



	if (getCfgVarEx(v, L"REIN_BAR_CHECK_DUPLICATES") == SUCCESS)
		iCfgVar_CheckDups = STOI(v);
	else
		iCfgVar_CheckDups = 1;

	if (getCfgVarEx(v, L"REIN_BAR_CHECK_CLASH") == SUCCESS)
		iCfgVar_Clash_Mode = STOI(v);
	else
		iCfgVar_Clash_Mode = 2;

	if (getCfgVarEx(v, L"REIN_BAR_CLASH_TOLERANCE") == SUCCESS)
		iCfgVar_Clash_Tol = STOI(v);
	else
		iCfgVar_Clash_Tol = 5;



	if (getCfgVarEx(v, L"REIN_BAR_GROUND_WEIGHT") == SUCCESS)
		iCfgVar_Ground_Wgt = STOI(v);
	else
		iCfgVar_Ground_Wgt = 5;

	if (getCfgVarEx(v, L"REIN_BAR_GROUND_COLOR") == SUCCESS)
		iCfgVar_Ground_Clr = STOI(v);
	else
		iCfgVar_Ground_Clr = 45;


	if (getCfgVarEx(v, L"REIN_BAR_BEND_REPAIR") == SUCCESS)
		iCfgVar_BarBendRepair = STOI(v);
	else
		iCfgVar_BarBendRepair = 0;


	if (getCfgVarEx(v, L"REIN_POSITION_CATCH") == SUCCESS)
		iModePosCatch = STOI(v);
	else
		iModePosCatch = 0;


	if (getCfgVarEx(v, L"REIN_POSLIST_MERGE") == SUCCESS)
	{
		iCfgVar_PosListMerge = STOI(v);
		iRefLvl = 1;
	}
	else
	{
		iCfgVar_PosListMerge = 0;
		iRefLvl = 0;
	}


	if (getCfgVarEx(v, L"REIN_DISPLAY_NOTCH_STARTING_D") == SUCCESS)
		iCfgVar_BarBendNotchDiam = STOI(v);
	else
		iCfgVar_BarBendNotchDiam = 20;


	if (getCfgVarEx(v, L"REIN_REF_SAVEDVIEW_CLIPVOLUME") == SUCCESS)
		iCfgVar_SavedViewClip = STOI(v);
	else
		iCfgVar_SavedViewClip = 0;

	if (getCfgVarEx(v, L"REIN_LOAD_REFERENCES_ONSTART") == SUCCESS)
		iCfgVar_LoadRefsOnStart = STOI(v);
	else
		iCfgVar_LoadRefsOnStart = 1;


	//REIN_DISPLAY_NOTCH_DIAMS
	//if (getCfgVar(v, L("REIN_DISPLAY_NOTCH_DIAMS")) == SUCCESS)
	//{
	//	WCH seps[] = L(",");
	//	WCH* token;
	//	token = STOK(v, seps);
	//	if (token) token = STOK(NULL, seps);
	//	for (int i = 1; token; i++)
	//	{
	//		laps[i] = STOUL(token, 0, 0);
	//		token = STOK(NULL, seps);
	//	}
	//}



	if (iCfgVar_EnableOptions == FALSE)
	{
		//rInfo.option[2] = 1;
		rInfo.option[4] = 1;
		rInfo.option[5] = 1;
	}


	arPlotCfgVar.clear();
	arPlotCfgVar.resize(50);

	if (getCfgVarEx(v, L"REIN_PLOT_SPC") == SUCCESS) arPlotCfgVar[REIN_PLOT_SPC] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_SPC_ELM") == SUCCESS) arPlotCfgVar[REIN_PLOT_SPC_ELM] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_SPC_INNER") == SUCCESS) arPlotCfgVar[REIN_PLOT_SPC_INNER] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_BAR") == SUCCESS) arPlotCfgVar[REIN_PLOT_BAR] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_BAR_ELM") == SUCCESS) arPlotCfgVar[REIN_PLOT_BAR_ELM] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_TERM_BEND") == SUCCESS) arPlotCfgVar[REIN_PLOT_TERM_BEND] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_TERM_REZB") == SUCCESS) arPlotCfgVar[REIN_PLOT_TERM_REZB] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_TERM_MUFT") == SUCCESS) arPlotCfgVar[REIN_PLOT_TERM_MUFT] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_TERM_SKOB") == SUCCESS) arPlotCfgVar[REIN_PLOT_TERM_SKOB] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_TERM_SVAR") == SUCCESS) arPlotCfgVar[REIN_PLOT_TERM_SVAR] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_AUX_X") == SUCCESS) arPlotCfgVar[REIN_PLOT_AUX_X] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_AUX_O") == SUCCESS) arPlotCfgVar[REIN_PLOT_AUX_O] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_AUX_V") == SUCCESS) arPlotCfgVar[REIN_PLOT_AUX_V] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_ELMSEC") == SUCCESS) arPlotCfgVar[REIN_PLOT_ELMSEC] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_BAR3D") == SUCCESS) arPlotCfgVar[REIN_PLOT_BAR3D] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_POSNUM") == SUCCESS) arPlotCfgVar[REIN_PLOT_POSNUM] = STOI(v);
	if (getCfgVarEx(v, L"REIN_PLOT_BAR_INVIS") == SUCCESS) arPlotCfgVar[REIN_PLOT_BAR_INVIS] = STOI(v);

	ReinInfo ri;
	ri = rInfo;

	ri.option[1] = 1;	//REIN_DISPLAY_INNER_CMN		: 1	# Внутренние (прозрачные) стержни контура
	ri.option[17] = 1;	//REIN_DISPLAY_INNER_SEC		: 1	# Внутренние стержни для сечений
	ri.option[18] = 0;	//REIN_DISPLAY_INVISIBLE_DASH	: 0	# Невидимые стержни пунктиром
	ri.option[11] = 1;	//REIN_DISPLAY_SEC_SHOW			: 1	# Сечения стержней
	ri.option[9] = 0;	//REIN_DISPLAY_SEC_REAL_DIAM	: 0	# Реальный диаметр сечения
	ri.option[10] = 0;	//REIN_DISPLAY_BAR_3D			: 0	# Контуры объёма стержня
	ri.option[8] = 1;	//REIN_DISPLAY_SHOW_BENDS		: 1	# Загибы
	ri.ends = 1;		//REIN_DISPLAY_SHOW_NOTCH		: 1	# Засечки
	ri.option[14] = 1;	//REIN_DISPLAY_SHOW_X			: 1	# Крестики
	ri.option[13] = 1;	//REIN_DISPLAY_SHOW_O			: 1	# Нолики
	ri.option[15] = 0;	//REIN_DISPLAY_POS_NUMBERS		: 0	# Номера позиций
	ri.option[19] = 0;	//REIN_DISPLAY_COLOR_BY_DIAM	: 0	# Цвет элемента по диаметру
	ri.threads = 1;		//REIN_DISPLAY_THREAD_COUP		: 1	# Резьба как муфта при печати
	ri.bface = 0;		//REIN_DISPLAY_SEC_SIZE			: 0	# Переопределение размера сечения
	ri.lim = 0;			// Стрелки
	ri.option[12] = 0;

	if (getCfgVarEx(v, L"REIN_DISPLAY_INNER_CMN") == SUCCESS)		ri.option[1] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_INNER_SEC") == SUCCESS)		ri.option[17] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_INVISIBLE_DASH") == SUCCESS)	ri.option[18] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_SEC_SHOW") == SUCCESS)		ri.option[11] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_SEC_REAL_DIAM") == SUCCESS)	ri.option[9] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_BAR_3D") == SUCCESS)			ri.option[10] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_SHOW_BENDS") == SUCCESS)		ri.option[8] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_SHOW_NOTCH") == SUCCESS)		ri.ends = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_SHOW_X") == SUCCESS)			ri.option[14] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_SHOW_O") == SUCCESS)			ri.option[13] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_POS_NUMBERS") == SUCCESS)	ri.option[15] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_COLOR_BY_DIAM") == SUCCESS)	ri.option[19] = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_THREAD_COUP") == SUCCESS)	ri.threads = STOI(v);
	if (getCfgVarEx(v, L"REIN_DISPLAY_SEC_SIZE") == SUCCESS)		ri.bface = STOI(v);

	copyRefPrefsToRef(&rInfoRef, &ri);



	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_POSNUM_SIZE)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_POSNUM_SIZE") == SUCCESS)
		dCfgVar_PosNumSize = mdlCnv_masterUnitsToUors(STOF(v));
	else
		dCfgVar_PosNumSize = mdlCnv_masterUnitsToUors(20.);

		
	// ====== old =======
	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_BAR_FACE)\n"); writeLog(0, 0);
	//if (getCfgVarEx(v, L"REIN_BAR_FACE") == SUCCESS)
	//	dCfgVar_BarFace = mdlCnv_masterUnitsToUors(STOF(v));
	//else
	//	dCfgVar_BarFace = mdlCnv_masterUnitsToUors(25.);
	if (getCfgVarEx(v, L"REIN_BAR_FACE") == SUCCESS)
		dCfgVar_BarFace = STOF(v);
	else
		dCfgVar_BarFace = 25.;


	//sprintf(sLogMes, "getCfgVarEx(REIN_BAR_SIGN)\n"); writeLog(0, 0);
	//if (getCfgVarEx(v, L"REIN_BAR_SIGN") == SUCCESS)
	//	dCfgVar_BarSign = mdlCnv_masterUnitsToUors(STOF(v));
	//else
	//	dCfgVar_BarSign = mdlCnv_masterUnitsToUors(50.);


	// ====== new =======
	//if (getCfgVarEx(v, L"REIN_BAR_FACE_MU") == SUCCESS)
	//	dCfgVar_BarFace = mdlCnv_masterUnitsToUors(STOF(v));
	//else
	//	dCfgVar_BarFace = mdlCnv_masterUnitsToUors(25.);
	// ==================

	//if (getCfgVarEx(v, L"REIN_BAR_VIEW_SCALE") == SUCCESS)
	//	dCfgVar_BarViewScale = STOF(v);
	//else
	//	dCfgVar_BarViewScale = 4.;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_DRAW_LEVEL_SIGN)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_DRAW_LEVEL_SIGN") == SUCCESS)
		lvlTextId = STOUL(v, 0, 0);
	else
		lvlTextId = 51;

	if (iDebug) sprintf(sLogMes, "getCfgVarEx(REIN_DRAW_LEVEL_BARS)\n"); writeLog(0, 0);
	if (getCfgVarEx(v, L"REIN_DRAW_LEVEL_BARS") == SUCCESS)
		lvlReinId = STOUL(v, 0, 0);
	else
		lvlReinId = 52;

	//if (getCfgVarEx(v, L"REIN_CONCRETE_COVER_EDGE") == SUCCESS)
	//	dCfgVar_CoverEdge = STOF(v);
	//else
	//	dCfgVar_CoverEdge = 50.;

	//if (getCfgVarEx(v, L"REIN_CONCRETE_COVER_FACE") == SUCCESS)
	//	dCfgVar_CoverFace = STOF(v);
	//else
	//	dCfgVar_CoverFace = 20.;


	if (iDebug) sprintf(sLogMes, "mdlSystem_getExpandedCfgVar(REIN_PIC_ANKER)\n"); writeLog(0, 0);
	
	//if (getCfgVarEx(v, L"REIN_PIC_ANKER") == SUCCESS)
	//{
	//	wcstombs(sCfgVar_PicAnker, v, 1000);
	//}
	//else
	//	strcpy(sCfgVar_PicAnker, "\0");


	if (iDebug) sprintf(sLogMes, "sCfgVar_PicAnker = '%s'\n", sCfgVar_PicAnker); writeLog(0, 0);



	if (iDebug) sprintf(sLogMes, "mdlLevel_getIdFromCode\n"); writeLog(0, 0);
	if (mdlLevel_getIdFromCode(&lvlTextId, MASTERFILE, lvlTextId) != SUCCESS) lvlTextId = 0;
	if (mdlLevel_getIdFromCode(&lvlReinId, MASTERFILE, lvlReinId) != SUCCESS) lvlReinId = 0;

	for (int i = 0; i < 100; i++) fillets[i].clear();

	//fillets[8].radius = 18;	    fillets[6].arclen = 0;	fillets[6].diamrif = 12;
	//fillets[10].radius = 22;	fillets[6].arclen = 0;	fillets[6].diamrif = 15;
	//fillets[12].radius = 26;	fillets[6].arclen = 0;	fillets[6].diamrif = 18;
	//fillets[16].radius = 34;	fillets[6].arclen = 0;	fillets[6].diamrif = 25;

	if (iDebug) sprintf(sLogMes, "set fillets values...\n"); writeLog(0, 0);
	// исп. для расчета анкеровки
	{
	fillets[20].arclen = 160;
	fillets[25].arclen = 200;
	fillets[28].arclen = 220;
	fillets[32].arclen = 250;
	fillets[36].arclen = 290;
	fillets[40].arclen = 320;
	}


	for (int i = 0; i < 100; i++)
	{
		fillets[i].diamrif = (double)i * 1.1;
	}

	fillets[6].diamrif = 7.;
	fillets[8].diamrif = 9.;
	fillets[10].diamrif = 11.3;
	fillets[12].diamrif = 13.5;
	fillets[16].diamrif = 18.;
	fillets[20].diamrif = 22.;
	fillets[25].diamrif = 27.;
	fillets[28].diamrif = 30.5;
	fillets[32].diamrif = 34.5;
	fillets[36].diamrif = 39.5;
	fillets[40].diamrif = 43.5;



	for (int i = 0; i < 100; i++)
	{
		fillets[i].radius = (int)(dCfgVar_FilletRadiusKoefDef * (double)i);
	}

	for (int i = 0; i < 17; i++)
		fillets[i].radius_bend = (int)(2.5 * (double)i);

	for (int i = 17; i < 100; i++)
		fillets[i].radius_bend = (int)(5. * (double)i);



	if (dCfgVar_FilletRadiusKoef < 0.) // перем не определена
	{

		fillets[20].radius = 100;
		fillets[25].radius = 125;
		fillets[28].radius = 140;
		fillets[32].radius = 160;
		fillets[36].radius = 180;
		fillets[40].radius = 200;

		for (int i = iCfgVar_FilletStartingDiam; i < 100; i++)
		{
			ReinLap* rlP = getReinLap(i);
			if (rlP && rlP->bendrad > 0)
			{
				fillets[i].radius = rlP->bendrad;
			}
		}

	}
	else
	{

		for (int i = iCfgVar_FilletStartingDiam; i < 100; i++)
		{
			fillets[i].radius = (int)(dCfgVar_FilletRadiusKoef * (double)i);
		}

		//fillets[25].radius = (int)(dCfgVar_FilletRadiusKoef * 25.);
		//fillets[28].radius = (int)(dCfgVar_FilletRadiusKoef * 28.);
		//fillets[32].radius = (int)(dCfgVar_FilletRadiusKoef * 32.);
		//fillets[36].radius = (int)(dCfgVar_FilletRadiusKoef * 36.);
		//fillets[40].radius = (int)(dCfgVar_FilletRadiusKoef * 40.);
	}



	updateViewArrays();

	writeLogOut(__FUNCTION__, 0);

}





/////////////////////////
void updateAllViews()
{

	for (int i = 0; i < MAX_VIEWS; i++)
	{
		if (mdlView_isActive(i)) mdlView_updateSingle(i);
	}
}





/////////////////////////////
void drawBarsTable(DVec3d* ptP, UInt32* iCountP)
{

	int rad = 0;
	MSElementDescr* edpR = NULL; // real bar
	MSElementDescr* edpSk = NULL; // for sketch
	MSElementDescr* edpText = NULL;
	DVec3d pt;
	DVec3d ptt;
	Transform tm;
	int rowqty = 0;
	int cnt = 0; // row counter
	int ccol = 0; // current col


	writeLogIn(__FUNCTION__, 0);


	ReinModel* rmP = curRM->getRM(curPos_refpath);

	if (rmP == NULL)
	{
		writeLogOut(__FUNCTION__, "rmP == NULL");
		return;
	}

	//if (ptP == NULL && iCountP == NULL) return; // debug %) 

	//if (curPos_rn > 0 && curRM->arMrP[curPos_rn] == NULL) return;

	if (ptP) pt = *ptP;
	if (ptP) ptt = *ptP;

	if (iCountP) 
		*iCountP = 0;
	else
	{
		if (rDopInfo.dopopt[8] > 0)
			rowqty = rDopInfo.dopopt[8];
		else
			rowqty = elemCount;
	}

	double colwdt[3];
	double rowhgt;

	rowhgt = mdlCnv_masterUnitsToUors(rDopInfo.dopval[0]);
	colwdt[0] = mdlCnv_masterUnitsToUors(rDopInfo.dopval[1]);
	colwdt[1] = mdlCnv_masterUnitsToUors(rDopInfo.dopval[2]);
	colwdt[2] = mdlCnv_masterUnitsToUors(rDopInfo.dopval[3]);




	for (map<long, ReinPos>::iterator it = rmP->getPosMap().begin(); it != rmP->getPosMap().end(); ++it)
	{
		ReinPos* rpP = &it->second;

		//for (long i = 0; i < mdlDArray_nMembers(daCurPosAll) ; i++)
		//for (long i = 0; i < rmP->iPosQty; i++)
		//{
		//ReinPos* rpP = (ReinPos*)mdlDArray_getMemberP(daCurPosAll, i);
		//int bFound = checkPos(rpP, NULL);
		//if (!bFound && curPos_refind >= 0) continue;

		bool bdo = true;

		for (vector<ReinExcl>::iterator rexP = daCurPosExcl.begin(); rexP != daCurPosExcl.end(); ++rexP)
		{
			bdo = false;
			if (rpP->mapind == rexP->ind)
			{
				bdo = true;
				break;
			}
		}

		if (!bdo) continue;

		if (rpP->bar.cnumpts == 2 
			&& getTrueEnd(&rpP->bar, 0) == REIN_TERM_NONE 
			&& getTrueEnd(&rpP->bar, 1) == REIN_TERM_NONE
			) 
			continue;

		if (iCountP) 
		{
			(*iCountP)++;
			continue;
		}

		if (rpP->bar.bendrad > 0)
			rad = rpP->bar.bendrad;
		else
			rad = getBendRadius(&rpP->bar, 0);

		// text
		mdlCell_create(&eCell, NULL, NULL, FALSE);
		mdlElmdscr_new (&edpText, NULL, &eCell);

		// real bar
		//=====================
		
		mdlComplexChain_createHeader(&eCell, 0, 0);
		mdlElmdscr_new(&edpR, 0, &eCell);

		DVec3d ptsSk[MAX_BAR_VERTICES];

		for (int j = 0; j < rpP->bar.cnumpts; j++)
		//for (size_t j = 0; j < rpP->bar.apts.size(); j++)
		{
			ptsSk[j].x = mdlCnv_masterUnitsToUors(rpP->bar.apts[j].x); // построение арко по точке на элементе
			ptsSk[j].y = mdlCnv_masterUnitsToUors(rpP->bar.apts[j].y);
			ptsSk[j].z = mdlCnv_masterUnitsToUors(rpP->bar.apts[j].z);
		}

		if (rpP->bar.noplanar == 2) mdlRMatrix_multiplyPointArray(ptsSk, &rmIso, rpP->bar.cnumpts);

		reinCreateComplexBarAxis2(&edpR, 0, ptsSk, rpP->bar.rfa, rpP->bar.cnumpts, rad, &c0w1s0, NULL, TRUE);

		//getSegms(edpR, &rpP->bar);


		// bar for sketch
		//=====================

		mdlComplexChain_createHeader(&eCell, 0, 0);
		mdlElmdscr_new(&edpSk, 0, &eCell);

		//if (rpP->bar.pnum == 5)
		//	printf("");

		prepareSketchPoints(
			ptsSk, 
			rpP->bar.cnumpts, 
			(colwdt[0] + colwdt[1]) * rDopInfo.dopval[5] * 0.01, 
			rowhgt * rDopInfo.dopval[4] * 0.01, 
			(rpP->bar.noplanar == 0 && rDopInfo.dopopt[10] == 0)
			);


		int cnt2 = reinCreateComplexBarAxis2(&edpSk, &edpText, ptsSk, rpP->bar.rfa, rpP->bar.cnumpts, rad, &c0w1s0, &rpP->bar, TRUE);

		if (ptP == NULL && iCountP == NULL)
		{
			writeLogOut(__FUNCTION__, "ptP == NULL && iCountP == NULL");
			return; // debug %)
		}
		else
		{
			pt.x = ptP->x + colwdt[0] + colwdt[1]/2. + ccol * (colwdt[0] + colwdt[1] + colwdt[2]);
			pt.y = ptP->y - rowhgt/2. - rowhgt * cnt;

			ptt.x = ptP->x + colwdt[0]/2. + ccol * (colwdt[0] + colwdt[1] + colwdt[2]);
			ptt.y = pt.y;
		}


		mdlTMatrix_getIdentity(&tm);
		mdlTMatrix_setTranslation(&tm, &pt);

		func_amp(mdlElmdscr_transform,edpSk), &tm);
		func_amp(mdlElmdscr_transform,edpText), &tm);

		func_amp(mdlElmdscr_setProperties,edpSk), 0, &curggn, 0, 0, 0, 0, 0, 0);
		func_amp(mdlElmdscr_setProperties,edpText), 0, &curggn, 0, 0, 0, 0, 0, 0);

		mdlElmdscr_add(edpSk);

		//mdlElmdscr_add(edpText);
		MSElementDescr* pComponent = edpText->h.firstElem;
		while (pComponent)
		{
			MSElementDescr* edpT = NULL;
			mdlElmdscr_duplicateSingle(&edpT, pComponent);
			mdlElmdscr_add(edpT);
			mdlElmdscr_freeAll(&edpT);
			pComponent = pComponent->h.next;
		}

		DVec3d ptv[4];
		mdlElmdscr_extractEndPoints(&ptv[2], &ptv[0], &ptv[3], &ptv[1], edpSk, ACTIVEMODEL);

		mdlElmdscr_freeAll(&edpSk);
		mdlElmdscr_freeAll(&edpR);
		mdlElmdscr_freeAll(&edpText);
#if defined (MSVERSION) && (MSVERSION == 0xa00) // text
		TextParamWide tp;
		tp.Initialize();

		//tp.font = 1025;
		tp.just = TextElementJustification::CenterMiddle;
		//tp.style = 0;
		tp.viewIndependent = 0;

		TextSizeParam tsp;
		tsp.mode = TXT_BY_TILE_SIZE;
		ActiveParams::GetValue(tsp.size.height, ActiveDoubleParams::ACTIVEPARAM_TEXTHEIGHT);
		ActiveParams::GetValue(tp.font, ActiveUInt32Params::ACTIVEPARAM_FONT);
		tsp.size.width = tsp.size.height * 0.8;

		RotMatrix rmm;
		mdlRMatrix_getIdentity(&rmm);

		MSWCH txt[100];
		_swprintf(txt, L"%i", rpP->bar.pnum);
		mdlText_create(&el2, &c0w1s0, txt, &ptt, &rmm, &tsp, &tp, 0, 0);
#else
		TextParam tp;

		//tp.font = 1025;
		tp.just = 7;
		tp.style = 0;
		tp.viewIndependent = 0;

		TextSizeParam tsp;
		tsp.mode = TXT_BY_TILE_SIZE;
		mdlParams_getActive(&tsp.size.height, ACTIVEPARAM_TEXTHEIGHT);
		mdlParams_getActive(&tp.font, ACTIVEPARAM_FONT);
		tsp.size.width = tsp.size.height * 0.8;

		sprintf(s, "%i", rpP->bar.pnum);
		mdlText_create(&el2, &c0w1s0, s, &ptt, &tsp, 0, &tp, 0);
#endif
		mdlElement_setProperties(&el2, 0, &curggn, 0, 0, 0, 0, 0, 0);
		mdlElement_add(&el2);

		DVec3d ptd[5];
		Transform tmm;
		RotMatrix rm;


		if (rpP->bar.term[0] == REIN_TERM_MUFT || rpP->bar.term[0] == REIN_TERM_REZB)
		{

			for (int b = 0; b < 5; b++)
				mdlVec_zero(&ptd[b]);

			double an = mdlVec_angleXY(&ptv[0]);

			mdlRMatrix_fromAngle(&rm, an);

			//for (int i = 0; i < 5; i++)
			//{
			//	ptd[i] = ptsSk[0];
			//}

			ptd[0].x -= tsp.size.height/2.;
			ptd[0].y -= tsp.size.height/4.;

			ptd[1].x += tsp.size.height/2.;
			ptd[1].y -= tsp.size.height/4.;

			ptd[2].x += tsp.size.height/2.;
			ptd[2].y += tsp.size.height/4.;

			ptd[3].x -= tsp.size.height/2.;
			ptd[3].y += tsp.size.height/4.;

			ptd[4].x -= tsp.size.height/2.;
			ptd[4].y -= tsp.size.height/4.;

			mdlRMatrix_multiplyPointArray(ptd, &rm, 5);

			mdlShape_create(&el2, 0, ptd, 5, 0);

			mdlTMatrix_translate(&tmm, &tm, ptsSk[0].x, ptsSk[0].y, ptsSk[0].z);

			//mdlEllipse_create(&el2, 0, &ptsSk[0], tsp.size.height/2., tsp.size.height/2., NULL, 1);
			mdlElement_transform(&el2, &el2, &tmm);
			mdlElement_setProperties(&el2, 0, &curggn, 0, 0, 0, 0, 0, 0);
			mdlElement_add(&el2);
		}

		if (rpP->bar.term[1] == REIN_TERM_MUFT || rpP->bar.term[1] == REIN_TERM_REZB)
		{

			for (int b = 0; b < 5; b++)
				mdlVec_zero(&ptd[b]);

			double an = mdlVec_angleXY(&ptv[1]);

			mdlRMatrix_fromAngle(&rm, an);

			//for (int i = 0; i < 5; i++)
			//{
			//	ptd[i] = ptsSk[0];
			//}

			ptd[0].x -= tsp.size.height/2.;
			ptd[0].y -= tsp.size.height/4.;

			ptd[1].x += tsp.size.height/2.;
			ptd[1].y -= tsp.size.height/4.;

			ptd[2].x += tsp.size.height/2.;
			ptd[2].y += tsp.size.height/4.;

			ptd[3].x -= tsp.size.height/2.;
			ptd[3].y += tsp.size.height/4.;

			ptd[4].x -= tsp.size.height/2.;
			ptd[4].y -= tsp.size.height/4.;

			mdlRMatrix_multiplyPointArray(ptd, &rm, 5);

			mdlShape_create(&el2, 0, ptd, 5, 0);

			mdlTMatrix_translate(&tmm, &tm, ptsSk[rpP->bar.cnumpts-1].x, ptsSk[rpP->bar.cnumpts-1].y, ptsSk[rpP->bar.cnumpts-1].z);

			//mdlEllipse_create(&el2, 0, &ptsSk[rpP->bar.cnumpts-1], tsp.size.height/2., tsp.size.height/2., NULL, 1);
			mdlElement_transform(&el2, &el2, &tmm);
			mdlElement_setProperties(&el2, 0, &curggn, 0, 0, 0, 0, 0, 0);
			mdlElement_add(&el2);
		}


		cnt++;

		if (cnt >= rowqty) 
		{
			cnt = 0;
			ccol++;
		}

	}

	writeLogOut(__FUNCTION__, 0);

}

/////////////////////////////////////
void	reinSketchTable(
DVec3d    *pt,
int view
)
{
	if (pt == NULL) return; // debug %)

	writeLogIn(__FUNCTION__, 0);

	curggn = mdlSystem_updateGraphicGroup();

	reinSketchDynamics(pt, view, DRAW_MODE_Normal);

	drawBarsTable(pt, NULL);

	mdlState_startDefaultCommand();

	writeLogOut(__FUNCTION__, 0);
}



/////////////////////////////////////////
void reinSketchDynamics( 
DVec3d*  pt,  
int  view,  
DRAWMODE  drawMode  )
{

	DVec3d shapepts[10];
	DVec3d linpts[2];

	writeLogIn(__FUNCTION__, 0);


	for (int b = 0; b < 10; b++)
		mdlVec_zero(&shapepts[b]);

	for (int b = 0; b < 2; b++)
		mdlVec_zero(&linpts[b]);

	//... ....... рисуем рамку

	double rowhgt = mdlCnv_masterUnitsToUors(rDopInfo.dopval[0]);
	double hgt;
	double wdt;
	double colwdt[2];
	double colint = mdlCnv_masterUnitsToUors(rDopInfo.dopval[3]);
	UInt32 colqty;
	UInt32 rowqty;

	colwdt[0] = mdlCnv_masterUnitsToUors(rDopInfo.dopval[1]);
	colwdt[1] = mdlCnv_masterUnitsToUors(rDopInfo.dopval[2]);


	if (rDopInfo.dopopt[8] > 0)
		rowqty = rDopInfo.dopopt[8];
	else
		rowqty = posCount;

	if (posCount == 0) return;
	if (rowqty == 0) return;


	if (rowqty > posCount) rowqty = posCount;

	colqty = posCount / rowqty;
	if (posCount % rowqty) colqty++;


	hgt = rowqty * rowhgt;
	wdt = colqty * (colwdt[0] + colwdt[1]) + (colqty - 1) * colint;

	shapepts[0] = *pt;
	shapepts[1] = *pt;

	//if (drawMode == NORMALDRAW)
	//{
	//	printf("");
	//}

	

	for(UInt32 i = 0; i < colqty; i++)
	{
		linpts[0].y = pt->y;
		linpts[1].y = pt->y;
		linpts[0].x = shapepts[0].x;
		linpts[1].x = shapepts[1].x + colwdt[0] + colwdt[1];
		linpts[0].z = shapepts[0].z;
		linpts[1].z = shapepts[1].z;

		for(UInt32 j = 0; j <= rowqty; j++)
		{
			mdlLine_create(&el, NULL, linpts);
			mdlElement_display(&el, drawMode);
			if (drawMode == DRAW_MODE_Normal) {mdlElement_setProperties(&el, 0, &curggn, 0, 0, 0, 0, 0, 0); mdlElement_add(&el);}

			linpts[0].y -= rowhgt;
			linpts[1].y -= rowhgt;
		}

		shapepts[0].y = pt->y;
		shapepts[1].y = pt->y - hgt;

		mdlLine_create(&el, NULL, shapepts);
		mdlElement_display(&el, drawMode);
		if (drawMode == DRAW_MODE_Normal) {mdlElement_setProperties(&el, 0, &curggn, 0, 0, 0, 0, 0, 0); mdlElement_add(&el);}

		shapepts[0].x += colwdt[0];
		shapepts[1].x += colwdt[0];

		mdlLine_create(&el, NULL, shapepts);
		mdlElement_display(&el, drawMode);
		if (drawMode == DRAW_MODE_Normal) {mdlElement_setProperties(&el, 0, &curggn, 0, 0, 0, 0, 0, 0); mdlElement_add(&el);}

		shapepts[0].x += colwdt[1];
		shapepts[1].x += colwdt[1];

		mdlLine_create(&el, NULL, shapepts);
		mdlElement_display(&el, drawMode);
		if (drawMode == DRAW_MODE_Normal) {mdlElement_setProperties(&el, 0, &curggn, 0, 0, 0, 0, 0, 0); mdlElement_add(&el);}

		shapepts[0].x += colint;
		shapepts[1].x += colint;


	}

	writeLogOut(__FUNCTION__, 0);


}


/////////////////////////////////
// func: save db
void posSaveDB(
char	*unparsedP
)
{
	WCH strSQL[1000];
	int res;
	long partID = 0;
	long posID = 0;
	long propID = 0;

	long srtm[100];

	srtm[6] = 408;
	srtm[8] = 409;
	srtm[10] = 410;
	srtm[12] = 411;
	srtm[14] = 412;
	srtm[16] = 413;
	srtm[18] = 414;
	srtm[20] = 415;
	srtm[22] = 416;
	srtm[25] = 417;
	srtm[28] = 418;
	srtm[32] = 419;
	srtm[36] = 420;
	srtm[40] = 421;
	srtm[45] = 422;
	srtm[50] = 423;
	srtm[55] = 424;

	ReinLap* rlP = getReinLap(6);

	

	//if (daCurPosAll == NULL) loadAllPositions(TRUE);
	//else if (mdlDArray_nMembers(daCurPosAll) == 0) loadAllPositions(TRUE);

	//int imode = getPosListMode();

	//if (imode == REIN_POSLIST_MODE_ENUM)
	//{
	//	cmdPosEnum("");
	//	dialogPosList_checkButton(NULL);
	//	return;
	//}
	//else if (imode == REIN_POSLIST_MODE_NUMSAVE)
	//{
	//	cmdPosEnum("save");
	//	dialogPosList_checkButton(NULL);
	//	return;
	//}
	if (curCat.catModID == 0) 
	{
		//mdlDialog_openMessageBox (DIALOGID_MsgBoxOK, 
		//	L("Необходимо назначить модели каталог базы данных!\nСохранение не выполнено."), 
		//	MSGBOX_ICON_WARNING);

		dialogPosList_checkButton(NULL);

		return;
	}
	


	bool bReplaceAll = true;

	for (map<long, ReinPos>::iterator it = curRM->getPosMap().begin(); it != curRM->getPosMap().end(); ++it)
	{
		ReinPos* rpP = &(it->second);
		if (rpP->bar.pnum != 0) bReplaceAll = false;
	}


	if (connectDB() == SUCCESS)
	{

		WCH  sql[1000];
		WCH  scatpath[2000];

		CursorID ci;
		MS_sqlda    sqlda;

		SPRN(sql, L("select dbo.getPath2(7,%u,0)"), curCat.catModID);

		int r = mdlDB_openCursorWithID (&ci, sql);

		if (r == SUCCESS)
		{
			while (mdlDB_fetchRowByID  (&sqlda, ci) != QUERY_FINISHED)
			{
				SCPY(scatpath, sqlda.value[0]);
				break;
			}

			mdlDB_closeCursorByID (ci);
			mdlDB_freeSQLDADescriptor (&sqlda);

			SPRN(s, L("Сохранение позиций в\n%s"), scatpath);
			if (bReplaceAll) SCAT(s, L("\nВсе позиции будут перезаписаны!"));

			if (mdlDialog_openMessageBox(DIALOGID_MsgBoxOKCancel, s, MSGBOX_ICON_QUESTION) == ACTIONBUTTON_CANCEL)
				return;

		}
		else
		{
			SPRN(s, L("error int sql: %s"), sql);
			mdlDialog_dmsgsPrint(s);
			mdlDialog_openMessageBox (DIALOGID_MsgBoxOK, 
				L("Ошибка при подключении к каталогу\nСохранение не выполнено."), 
				MSGBOX_ICON_WARNING);
			return;
		}
	
		
	}
	else
	{
		mdlDialog_openMessageBox (DIALOGID_MsgBoxOK, 
			L("Не подключиться к базе данных\nСохранение не выполнено."), 
			MSGBOX_ICON_WARNING);
		return;
	}




	if (bReplaceAll)
	{
		SPRN(strSQL, L("DELETE FROM [r_position_property] WHERE posID IN (SELECT posID FROM [view_position] WHERE catID = %i)"), curCat.catModID);
		res = mdlDB_processSQL(strSQL);
		if (res != SUCCESS) return;

		SPRN(strSQL, L("DELETE FROM [position] WHERE partID IN (SELECT partID FROM [part] WHERE catID = %i)"), curCat.catModID);
		res = mdlDB_processSQL(strSQL);
		if (res != SUCCESS) return;

		SPRN(strSQL, L("DELETE FROM [part] WHERE catID = %i"), curCat.catModID);
		res = mdlDB_processSQL(strSQL);
		if (res != SUCCESS) return;
	}


	ZeroTrackBar(&tbi);
	tbi.update = UPDATE_Percent1 | UPDATE_Msg1;


	SCPY(tbi.msgText1, TXT_119);

	dlgProgressP = mdlDialog_completionBarOpen(TXT_119);
	//mdlDialog_trackBarStartProcessing(NULL, NULL, NULL, NULL, L("Отменено"), 0, &tbi, L(""));

	UInt32 i = 0;

	for (map<long, ReinPos>::iterator it = curRM->getPosMap().begin(); it != curRM->getPosMap().end(); ++it,i++)
	{

		WCH v[20];
		
		ReinPos* rpP = &it->second;

		long posnum = rpP->bar.pnum;


		partID = 0;


		//if (rpP->file_qty_p == 0) continue; // skip missing


		if (bReplaceAll == false) 
		{
			if (rpP->bar.pnum == 0) continue;

			// проверка part
			SPRN(strSQL, L("SELECT partID from [part] where partName = '%i' and catID = %i and deleted = 0"), 
				rpP->bar.pnum, curCat.catModID);
			if (mdlDB_sqlQuery(s, strSQL) == SUCCESS)
				partID = STOUL(s, 0, 0);
		}
		else
		{
			posnum = it->first;

			if (rpP->bar.runmet == 1)
				rpP->base_qty = rpP->file_qty_rm;
			else
				rpP->base_qty = rpP->file_qty_p;
		}




		int bBlocked = FALSE;


		if (partID == 0)
		{
			SPRN(v, L("%0*i"), 5 , posnum);
			SPRN(strSQL, L("INSERT INTO [part] (partName, catID, partdefID, partSortNumber) VALUES ('%i',%i,%i,'%s')"),
													posnum, curCat.catModID, 5, v);

			res = mdlDB_processSQL(strSQL);

			if (res == SUCCESS)
			{
				mdlDB_sqlQuery(s, L("SELECT SCOPE_IDENTITY()"));
				partID = STOUL(s, 0, 0);
			}
			else
			{
				mdlDialog_dmsgsPrint(L("error while saving part record"));
				continue;
			}
		}
		else
		{
			SPRN(strSQL, L("SELECT partMainPosEP from [part] where partID = %i"), partID);
			if (mdlDB_sqlQuery(s, strSQL) == SUCCESS)
				bBlocked = STOUL(s, 0, 0);
		}


		if (bBlocked) continue; // блокировано для обновления



		if (partID == 0)  // не получен part
		{
			mdlDialog_dmsgsPrint(L("error while saving part record"));
			continue;
		}



		//double qty = 0.;
		long srtmID = getReinLapSrtmID(rpP->bar.diam, srtm[rpP->bar.diam]);
		long matID = getReinLapMatID(rpP->bar.diam, 0);
		int bSk = 1;


		//if (rpP->bar.diam >= 12)
		//	matID = 12;
		//else
		//	matID = 11;

		if ((rpP->bar.runmet == 1 || rpP->bar.cnumpts <= 2) &&
			(rpP->bar.term[0] == REIN_TERM_NONE || rpP->bar.term[0] == REIN_TERM_SKOB) &&
			(rpP->bar.term[1] == REIN_TERM_NONE || rpP->bar.term[1] == REIN_TERM_SKOB)) bSk = 0;


		SPRN(strSQL, L("DELETE FROM [position] WHERE partID = %i"), partID);
		res = mdlDB_processSQL(strSQL);

		if (res != SUCCESS) 
		{
			mdlDialog_dmsgsPrint(L("error while deleting position record"));
			continue;
		}

		posID = 0;

		// проверка position
		//sprintf(strSQL, "SELECT top 1 posID from [position] where partID = %i order by posID desc", partID);
		//mdlDB_sqlQuery(s, strSQL);
		//posID = atol(s);


		//if (posID == 0)
		if (rpP->file_qty_p > 0) // если 0 то отсутствует
		{
			SPRN(strSQL, L("INSERT INTO [position] (partID, srtmID, posQuantity, matID, posNumber, posSketch) VALUES (%i,%i,%.1f,%i,%i,%i)"),
													partID, srtmID, rpP->base_qty, matID, 1, bSk);

			res = mdlDB_processSQL(strSQL);

			if (res == SUCCESS)
			{
				mdlDB_sqlQuery(s, L("SELECT SCOPE_IDENTITY()"));
				posID = STOL(s);
			}
			else
			{
				mdlDialog_dmsgsPrint(L("error while inserting position record"));
				continue;
			}
		}
		//else
		//{
		//	sprintf(strSQL, "UPDATE [position] set srtmID=%i, posQuantity=%.5f, matID=%i, posNumber=%i, posSketch=%i WHERE posID = %i", 
		//											srtm[rpP->bar.diam], rpP->base_qty, matID, 1, bSk, posID);
		//	res = mdlDB_processSQL(strSQL);
		//}

		if (posID > 0)
		{


			SPRN(strSQL, L("DELETE FROM [r_position_property] WHERE posID = %i"), posID);
			res = mdlDB_processSQL(strSQL);

			if (res != SUCCESS)
			{
				mdlDialog_dmsgsPrint(L("error while deleting position property"));
				continue;
			}

			propID = 0;


			// проверка property
			//sprintf(strSQL, "SELECT top 1 relID from [r_position_property] where posID = %i", posID);
			//mdlDB_sqlQuery(s, strSQL);
			//propID = atol(s);

			//if (propID > 0)
			//{
			//	if (rpP->bar.runmet == 0) 
			//	{
			//		sprintf(strSQL, "UPDATE [r_position_property] SET length = %i, lenmin = NULL, lenmax = NULL WHERE relID = %i", 
			//											rpP->base_ms_mid, propID);
			//	}
			//	else if (rpP->bar.runmet == 1) 
			//	{
			//		sprintf(strSQL, "UPDATE [r_position_property] SET length = NULL, lenmin = NULL, lenmax = NULL WHERE relID = %i", 
			//											propID);
			//	}
			//	else if (rpP->bar.runmet > 1) 
			//	{
			//		sprintf(strSQL, "UPDATE [r_position_property] SET length = %i, lenmin = %i, lenmax = %i WHERE relID = %i", 
			//											rpP->base_ms_mid, rpP->base_ms_min, rpP->base_ms_max, propID);
			//	}
			//}
			//else
			{
				if (rpP->bar.runmet == 0)
				{
					SPRN(strSQL, L("INSERT INTO [r_position_property] (posID, length) VALUES (%i,%i)"),
						posID, rpP->file_ms_mid);
				}
				else if (rpP->bar.runmet == 1)
				{
					SPRN(strSQL, L("INSERT INTO [r_position_property] (posID) VALUES (%i)"),
						posID);
				}
				else if (rpP->bar.runmet > 1)
				{
					SPRN(strSQL, L("INSERT INTO [r_position_property] (posID, length, lenmin, lenmax) VALUES (%i,%i,%i,%i)"),
						posID, rpP->file_ms_mid, rpP->file_ms_min, rpP->file_ms_max);
				}

			}

			res = mdlDB_processSQL(strSQL);

			if (res != SUCCESS)
			{
				mdlDialog_dmsgsPrint(L("error while inserting position property"));
				continue;
			}

			if (propID == 0 && res == SUCCESS)
			{
				mdlDB_sqlQuery(s, L("SELECT SCOPE_IDENTITY()"));
				propID = STOL(s);
			}

		}

		// окончания

		SPRN(strSQL, L("DELETE FROM [r_part_reinsketch] WHERE partID = %i"), partID);
		res = mdlDB_processSQL(strSQL);

		if (res != SUCCESS) mdlDialog_dmsgsPrint(L("error while saving sketch"));

		if (posID > 0)
		{

			int trmp[4] = { 0 };
			//ZeroMemory(trmp, sizeof(trmp));
			setBarTermPar6to4(trmp, &rpP->bar);

			SPRN(strSQL, L("INSERT INTO [r_part_reinsketch] (partID, "));
			SCAT(strSQL, L("sketchStartType, sketchStartAngle, sketchStartLength, "));
			SCAT(strSQL, L("sketchEndType, sketchEndAngle, sketchEndLength) "));

			SPRN(s, L("VALUES (%i,%i,%i,%i,%i,%i,%i)"),
				partID,
				rpP->bar.term[0], trmp[0], trmp[2],
				rpP->bar.term[1], trmp[1], trmp[3]
			);

			SCAT(strSQL, s);


			res = mdlDB_processSQL(strSQL);

			if (res != SUCCESS)
			{
				mdlDialog_dmsgsPrint(L("error in query"));
				mdlDialog_dmsgsPrint(strSQL);
			}

		}

		// точки

		SPRN(strSQL, L("DELETE FROM [r_part_reinpoints] WHERE partID = %i"), partID);
		res = mdlDB_processSQL(strSQL);

		if (res != SUCCESS) 
		{
			mdlDialog_dmsgsPrint(L("error in query"));
			mdlDialog_dmsgsPrint(strSQL);
		}


		if (posID > 0)
		{

			for (int a = 0; a < rpP->bar.cnumpts; a++)
			{

				int isMn = 0;
				int isCn = 0;

				if (a == rpP->bar.mainPtsIndex) isMn = 1;
				if (rpP->bar.runmet > 1) isCn = isMn;

				SCPY(strSQL, L("INSERT INTO [r_part_reinpoints] (partID, xd,yd,zd, x,y,z, xa,ya,za, isMain, isOk, isCont, onArc) "));

				//if (a >= rpP->bar.rfa.size()) break;
				//if (a >= rpP->bar.apts.size()) break;
				//if (a >= rpP->bar.cpxb.size()) break;
				//if (a >= rpP->bar.cpxe.size()) break;

				int i_rfa = 0;
				if (rpP->bar.rfa[a] & RFA_ARCP || rpP->bar.rfa[a] & RFA_CIRP) i_rfa = RFA_ARCP;

				SPRN(s, L("VALUES (%i, %.2f,%.2f,%.2f, %i,%i,%i, %i,%i,%i, %i,%i,%i,%i)"),
					partID,
					rpP->bar.apts[a].x, rpP->bar.apts[a].y, rpP->bar.apts[a].z,
					rpP->bar.cpxb[a].x, rpP->bar.cpxb[a].y, rpP->bar.cpxb[a].z,
					rpP->bar.cpxe[a].x, rpP->bar.cpxe[a].y, rpP->bar.cpxe[a].z,
					isMn, 1, isCn, i_rfa);

				SCAT(strSQL, s);

				res = mdlDB_processSQL(strSQL);

				if (res != SUCCESS)
				{
					mdlDialog_dmsgsPrint(L("error in query"));
					mdlDialog_dmsgsPrint(strSQL);
				}

			}

		}

		tbi.percentComplete1 = (long)(((double)i/(double)curRM->getPosMap().size())*100.);
		//tbi.percentComplete1 = (long)(((double)i/(double)curRM->iPosQty)*100.);
		//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
		if (dlgProgressP) mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)tbi.percentComplete1);
		WaitMessage();

	}


	//mdlDialog_trackBarStopProcessing();
	if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);

}




/////////////////////////////////
extern "C" DLLEXPORT void cmdPosCatch(
	char* unparsedP
)
//cmdNumber   CMD_REIN_POS_CATCH
{

	string str(unparsedP);
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);



	if (
		str.compare("ON") == 0
		|| str.compare("1") == 0
		)
	{
		iModePosCatch = 1;
	}
	else if (
		str.compare("OFF") == 0
		|| str.compare("0") == 0
		)
	{
		iModePosCatch = 0;
		mapPosMem.clear();
	}

	if (iModePosCatch)
	{
		mdlOutput_messageCenter(MESSAGE_INFO, TXT_114, TXT_112, MESSAGE_ALERT_BALLOON);
	}
	else
	{
		mdlOutput_messageCenter(MESSAGE_INFO, TXT_114, TXT_113, MESSAGE_ALERT_BALLOON);
	}

}

/////////////////////////////////
extern "C" DLLEXPORT void cmdPosEnum(
	char* unparsedP
)
//cmdNumber   CMD_REIN_POS_ENUM
{

	MSDLGP dbP = mdlDialog_find(DLG_POSLIST, NULL);

	if (dbP == NULL) return;

	DialogItem* pListBoxItem = NULL;
	ListModel* pListModel = NULL;
	int row, col;

	bool bForce = false; // присваивать номер в том числе и на те позиции что номер уже имеют
	bool bSave = false;
	bool bByCheck = false;

	if (unparsedP && strlen(unparsedP) > 0)
	{
		if (strcmp(unparsedP, "force") == 0) bForce = true;
		if (strcmp(unparsedP, "save") == 0) bSave = true;
	}


	if (NULL == (pListBoxItem = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ListBox, 1, 0)))
		return;

	if (NULL == (pListModel = mdlDialog_listBoxGetListModelP(pListBoxItem->rawItemP)))
		return;

	if (curPos_rn > 0) // reference
		return;


	if (curRM->getExFpCount(0) > 0)
	{
		bByCheck = true;
		//bForce = true; // перенумеровываем имеющиеся (при этом может начаться дублирование)
	}


	if (bSave)
	{
		int a = 0;

		dlgProgressP = mdlDialog_completionBarOpen(TXT_119);

		for (map<long, ReinPos>::iterator itt = curRM->getPosMap().begin(); itt != curRM->getPosMap().end(); ++itt)
		{

			if (itt->second.pnum_cnd > 0 
				//&& !EQ(itt->second.base_qty, 0.) // ...
				&& itt->second.file_qty_p > 0 // сохраняем только те что есть в файле
				//&& itt->second.bar.poscalc == 0 // сохраняем только общий набор
				&& itt->second.bar.pnum != itt->second.pnum_cnd // если тот же номер - не трогаем
				)
			{
				if (itt->second.bar.pnum > 0) // если перезапись - удаляем
					deleteFilePosition(itt->second.bar.pnum);

				itt->second.bar.pnum = itt->second.pnum_cnd;

				if (savePosition(&itt->second, FALSE, TRUE) == SUCCESS)
				{
					// меняем знак - признак что уже сохранено
					itt->second.pnum_cnd = -itt->second.pnum_cnd;
				}

				int sz = (int)curRM->getPosMap().size();

				if (dlgProgressP 
					&& sz // в итерации всегда > 0, но на всякий случай
					)
				{
					mdlDialog_completionBarUpdate(dlgProgressP, 0, a * 100 / sz);
					WaitMessage();
					a++;
				}
			}
		}

		if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);


		daCurPosExcl.clear();
		curRM->vExFps.clear();
		curRM->vExIds.clear();

		for (int i = 0; i < mdlListModel_getRowCount(pListModel); i++)
		{
			ListRow* pListRow = mdlListModel_getRowAtIndex(pListModel, i);
			if (mdlListRow_getStatus(pListRow) == LISTCELLATTR_DISABLED)  continue;

			ListCell* pListCell = mdlListModel_getCellAtIndexes(pListModel, i, REIN_LISTB_POSN);
			long ii = myListCell_getInfoFieldInt32(pListCell, 0, &gst);

			if (gst != SUCCESS) continue;

			map<long, ReinPos>::iterator it = curRM->getPosMap().find(ii);

			if (it != curRM->getPosMap().end()) // found
			{
				if (it->second.pnum_cnd < 0) // только что сохранено
				{
					it->second.pnum_cnd = 0;
					ListCell* pListCell2 = mdlListModel_getCellAtIndexes(pListModel, i, REIN_LISTB_POSN);
					BSIColorDescr* clr = mdlWindow_systemColorGet(SYSCOLOR_FIXED_BLACK);
					mdlListCell_setColorDescr(pListCell2, clr);
					mdlListCell_setFontIndex(pListCell2, FONT_INDEX_BOLD);
				}

				// REIN_LISTB_EXCL

				RscId  iIcon;
				RscType iIconType;

				ListCell* pListCellch = mdlListModel_getCellAtIndexes(pListModel, i, REIN_LISTB_EXCL);
				mdlListCell_getIcon(pListCellch, &iIcon, &iIconType, NULL);

				if (iIcon == ICONID_ToggleOn14Pt)
					mdlListCell_setIcon(pListCellch, ICONID_ToggleOff14Pt, RTYPE_Icon, NULL);

			}

		}

		enumCount = 0;

	}
	else
	{
		long cnt = 1;
		enumCount = 0;

		for (int i = 0; i < mdlListModel_getRowCount(pListModel); i++)
		{

			ListRow* pListRow = mdlListModel_getRowAtIndex(pListModel, i);
			if (mdlListRow_getStatus(pListRow) == LISTCELLATTR_DISABLED)  continue;

			ListCell* pListCell = mdlListModel_getCellAtIndexes(pListModel, i, REIN_LISTB_POSN);
			long ii = myListCell_getInfoFieldInt32(pListCell, 0, &gst);

			if (gst != SUCCESS) continue;

			if (bByCheck)
			{
				RscId  iIcon;
				RscType iIconType;

				ListCell* pListCellch = mdlListModel_getCellAtIndexes(pListModel, i, REIN_LISTB_EXCL);
				mdlListCell_getIcon(pListCellch, &iIcon, &iIconType, NULL);

				//пропускаем невыделенные
				if (iIcon != ICONID_ToggleOn14Pt)	continue;

				if (enumCount == 0 && ii > 0) // первый номер с первой галки 
				{
					cnt = ii;
				}
			}

			map<long, ReinPos>::iterator it = curRM->getPosMap().find(ii);

			if (it != curRM->getPosMap().end()) // found
			{
				//if (it->second.bar.poscalc == 0)
				{
					it->second.pnum_cnd = it->second.bar.pnum;

					if (it->second.bar.pnum == 0 || bForce)
					{
						if (!bForce) // == 0
						{
							while (curRM->getPosByNum(cnt)) // проверяем нет ли уже таких
							{
								cnt++;
							}
						}

						it->second.pnum_cnd = cnt;
						enumCount++;

						WCH v[20];
						SPRN(v, L("%i"), it->second.pnum_cnd);
						mdlListCell_setDisplayText(pListCell, v);

						mdlListCell_setDoubleValue(pListCell, (double)it->second.pnum_cnd);

						BSIColorDescr* clr = mdlWindow_systemColorGet(SYSCOLOR_FIXED_MGREY);
						mdlListCell_setColorDescr(pListCell, clr);
					}

					cnt++;

				}
			}
		}
	}



	mdlDialog_listBoxDrawContents(pListBoxItem->rawItemP, -1, REIN_LISTB_POSN);
	mdlDialog_listBoxDrawContents(pListBoxItem->rawItemP, -1, REIN_LISTB_EXCL);

	curRM->updateModelElmNumbers(true);



}




/////////////////////////
// ReinBar* rbP,				// if not NULL -> add ReinElm xml fragment AND ADD TO FILE
// int diameter,				//  => bar diameter
// int iRadiusOption,			//  => hier wissen wir, welchen Radius zu verwenden ist
// DgnModelRefP mrInP,			//  => model ref where add (if NULL use active)
// MSElementDescr* edPathP,		//  => path
// int barnum,					// bar number (for ReinElm xml fragment)
// UInt32* ilevP				// level
// MSElementDescr** edElemOutPP // elem descr to return if not null
// double dShellUor				// shell in uors (if 0.0 - no shell)
/////////////////////////
UInt32 reinSweepBarByPath(
ReinBar* rbP,
int diameter,
int iRadiusOption,
DgnModelRefP mrInP,
MSElementDescr *edPathP,
int barnum,
UInt32* ilevP,
MSElementDescr** edElemOutPP,
double dShellUor
)
{
	//MSBsplineCurve       curve;
	DVec3d pOrg, pTng;
	int ret;
	double rad;
	RotMatrix rm;
	//RotMatrix rmref;
	MSElementDescrP edpShape = NULL;
	//MSElementDescrP edpBar = NULL;
	//BODY_TAG kb_shape  = NULL;
	//BODY_TAG kb_path  = NULL;
	Transform tm;
	DVec3d pTriad[3];
	UInt32 fpp = 0;
	DgnModelRefP mrP = mrInP;
	DgnModelRefP mrAddP = NULL;
	int btrns = 1;

	if (mrP == NULL) mrP = ACTIVEMODEL;

	if (edElemOutPP == NULL)
		mrAddP = ACTIVEMODEL;
	else
		mrAddP = NULL;
	
	if (iRadiusOption == 0)
		mdlCnv_masterToUOR(&rad, fillets[diameter].diamrif / 2., mrP);
	else if (iRadiusOption == 1)
		mdlCnv_masterToUOR(&rad, (double)(diameter / 2), mrP);
	//else if (iRadiusOption == 2)
	//	...

	// получаем точку в начале
	mdlElmdscr_pointAtDistance(&pOrg, &pTng, 0., edPathP, 0);

	//{
	//	mdlBspline_convertToCurve(&curve, edPathP);
	//	mdlBspline_evaluateCurvePoint(&pOrg, &pTng, &curve, 0.);
	//	mdlBspline_freeCurve(&curve);
	//}

	//mdlSystem_enterDebug();


	mdlVec_getNormalizedTriad(&pTng, &pTriad[0], &pTriad[1], &pTriad[2]);
	//mdlRMatrix_fromRowVectors(&rm, &pTriad[0], &pTriad[1], &pTriad[2]);
	mdlRMatrix_fromColumnVectors(&rm, &pTriad[0], &pTriad[1], &pTriad[2]);

	//mdlRMatrix_fromNormalVector(&rm, &pTng);
	mdlTMatrix_fromRMatrix(&tm, &rm);

	//if (reP->rc.numRef)
	//{
	//	mdlRMatrix_fromTMatrix(&rmref, &reP->rc.tmRef);
	//	mdlRMatrix_invert(&rmref, &rmref);
	//	mdlTMatrix_rotateByRMatrix(&tm, &tm, &rmref);
	//}

	mdlTMatrix_setTranslation(&tm, &pOrg);

	mdlEllipse_create(&elShape, 0, &pZero, rad, rad, 0, 0);


	mdlElement_transform(&elShape, 0, &tm);

	//mdlElement_add(&elShape);

#if defined (MSVERSION) && (MSVERSION == 0xa00) // SOLID BAR

	ElementHandle ehShape(&elShape, mrP);
	ElementHandle ehPath(edPathP, false, false, mrP);
	CurveVectorPtr  crvShape = ICurvePathQuery::ElementToCurveVector(ehShape);
	CurveVectorPtr  crvPath = ICurvePathQuery::ElementToCurveVector(ehPath);
	
	ISolidKernelEntityPtr bar;
	BentleyStatus st = SolidUtil::Create::BodyFromSweep(bar, *crvShape.get(), *crvPath.get(), 
		*mrP, false, false, false, 0, 0, 0, 0); // dShellUor

	EditElementHandle ehBar;


	if (st != BentleyStatus::SUCCESS)
	{
		//printf("mdlSolid_bodyToElement returns %i\n", ret);
	}
	else
	{
		if (SolidUtil::Convert::BodyToElement(ehBar, *bar.get(), 0, *mrP) == BentleyStatus::SUCCESS)
		{
			//UInt32 lev;
			UInt32 ggn;
			mdlElmdscr_getProperties( 0, &ggn, 0, 0, 0, 0, 0, 0, edPathP);

			edpShape = ehBar.GetElementDescrP();
			
			if (rbP)
				fpp = xmlAddReinElmdAttr(
					&edpShape, 
					rbP->elemid,
					REIN_ELEM_BAR, 
					rbP, // no saved points
					ilevP,
					mrAddP, // add to file
					&ggn, 
					TRUE, // locked
					0,
					TRUE, // visible
					barnum // порядковый номер в области
					);
			else
			{
				if (ilevP) func_amp(mdlElmdscr_setProperties, edpShape), ilevP, 0, 0, 0, 0, 0, 0, 0);
			}
		}

		//mdlElmdscr_display (edpShape, MASTERFILE, NORMALDRAW);

		//if (rInfo.option[6])
		//{

		//}
		
		//if (rInfo.b3d)
		//	reP->tedBarP = mdlTransient_addElemDescr(reP->tedBarP, edpShape,  1, 0x00ff, NORMALDRAW, 0, 0, 1);


	}

#else

	//KIBODY* kb_bar  = NULL;
	KIBODY* kb_shape  = NULL;
	KIBODY* kb_path  = NULL;

	mdlElmdscr_new(&edpShape, 0, &elShape);

	mdlKISolid_beginCurrTrans(mrP);
	//=====================================================

	mdlCurrTrans_invScaleDoubleArray(&dShellUor, &dShellUor, 1);

	ret = mdlKISolid_elementToBody(&kb_shape, edpShape, mrP);

	if (ret == SUCCESS)
	{
		ret = mdlKISolid_elementToBody(&kb_path, edPathP, mrP);

		if (ret == SUCCESS)
		{
			ret = mdlKISolid_sweepBodyWire(&kb_shape, kb_path, NULL, dShellUor, TRUE, mrP);

			if (ret == SUCCESS)
			{
				ret = mdlKISolid_bodyToElementD(&edpShape, kb_shape, 1, 4, &c0w1s0, mrP, TRUE);

				if (ret != SUCCESS)
					wcscpy(wLog, L"cannot create element from body, func mdlKISolid_bodyToElementD");
			}
			else
				wcscpy(wLog, L"cannot create sweep body, func mdlKISolid_sweepBodyWire");
		}
		else if (rbP)    //if (ret == 547) // наложение, rbP чтобы не уходил в рекурсию
		{
			MSElementDescr* pCmp = edPathP->h.firstElem;

			if (btrns)
			{
				mdlKISolid_endCurrTrans();
				btrns = 0;
			}
			

			if (pCmp)
			{
				mdlCell_create(&eCell, 0, 0, 0);
				mdlElmdscr_new(&edpShape, NULL, &eCell);

				while (pCmp)
				{
					MSElementDescr* edp = NULL;
					MSElementDescr* edp2 = NULL;

					mdlElmdscr_duplicateSingle(&edp2, pCmp);

					reinSweepBarByPath(NULL, diameter, iRadiusOption, mrInP, edp2, barnum, ilevP, &edp, dShellUor);

					mdlElmdscr_freeAll(&edp2);

					if (edp) mdlElmdscr_appendDscr(edpShape, edp);

					pCmp = pCmp->h.next;
				}
			}

			ret = 0;

		}
		//else
		//	wcscpy(wLog, L"cannot create path element, func mdlKISolid_elementToBody");
	}
	else
	{
		//pOrg
		wcscpy(wLog, L"cannot create round profile, func mdlKISolid_elementToBody");


	}


	//mdlKISolid_simplifyBody(&kb_shape, TRUE);

	//MSElementDescrP edpShape2 = NULL;


	if (ret == SUCCESS)
	{
		if (rbP)
		{
			//UInt32 lev;
			UInt32 ggn;
			mdlElmdscr_getProperties(0, &ggn, 0, 0, 0, 0, 0, 0, edPathP);
			fpp = xmlAddReinElmdAttr(
				&edpShape,
				rbP->elemid,
				REIN_ELEM_BAR,
				rbP, // no saved points
				ilevP,
				mrAddP, // add to file
				&ggn,
				TRUE, // locked
				0, // lap
				TRUE, // visible
				barnum // порядковый номер в области
			);

		}
		else
		{
			if (ilevP) mdlElmdscr_setProperties(edpShape, ilevP, 0, 0, 0, 0, 0, 0, 0);
		}

		//if (rInfo.b3d)
		//	reP->tedBarP = mdlTransient_addElemDescr(reP->tedBarP, edpShape,  1, 0x00ff, NORMALDRAW, 0, 0, 1);

		mdlKISolid_freeBody(kb_shape);
		if (kb_path != NULL) mdlKISolid_freeBody(kb_path);
	}
	else
	{
		if (rbP) 
			_swprintf(wss, L"elem id = %I64u create solid bar error, %s", rbP->elemid, wLog);
		else
			_swprintf(wss, L"create solid bar error, %s", wLog);

		mdlOutput_messageCenterW(MESSAGE_ERROR, wss, wss, MESSAGE_ALERT_BALLOON);
	}

	//if (edElemOutPP) 
	//	*edElemOutPP = edpBar;
	//else
	//	mdlElmdscr_freeAll(&edpBar);

	//=====================================================
	if (btrns) mdlKISolid_endCurrTrans();


#endif

	//mdlElmdscr_freeAll(&edpShape);
	if (edElemOutPP) 
		*edElemOutPP = edpShape;
	else
		mdlElmdscr_freeAll(&edpShape);

	//if (edpShape2) mdlElmdscr_freeAll(&edpShape2);


	if (fpp > 0 && rbP)
	{
		ELREF eref = getElemRefByFPos(mrP, fpp, TRUE);
		//MSElementDescrP edpShape1 = NULL;
		//mdlElmdscr_read(&edpShape1, fpp, mrP, 0, 0);
		if (eref)
		{
			rbP->ffpos[REIN_ELEM_BAR] = fpp;
			rbP->brid = elementRef_getElemID(eref);
			//mdlElmdscr_freeAll (&edpShape1);
		}
	}


	return fpp;
}



/////////////////////////////////
extern "C" DLLEXPORT void cmdDrawNodes(
char	*unparsedP
)
//cmdNumber   CMD_REIN_NODES
{
/*

	int num = 0;

	if (arTransNodes) {mdlTransient_free(&arTransNodes, TRUE); arTransNodes = NULL;}

	if (loadNodesData() == SUCCESS) 
	{
		bLoadsOk = TRUE;
	}
	else
		return;



	if (daCurLoadNodes == NULL) return;

	num = mdlDArray_nMembers(daCurLoadNodes);

	if (num == 0) return;


	if (rInfo.nodes)
	{
		int i;

		for (i = 0; i < num; i++)
		{
			DVec3d p[2];
			LoadNode* liP = (LoadNode*)mdlDArray_getMemberP(daCurLoadNodes, i);

			p[0] = liP->org;
			p[1] = liP->org;

			mdlLine_create(&el, &c0w1s0, p);

			arTransNodes = mdlTransient_addElement(arTransNodes, &el, TRUE, 0xff, NORMALDRAW, 0, 0, 1);

		}

		//{
		//	int res;
		//	MSElementDescr* edp = NULL;
		//	res = mdlMesh_newCoordinateBlock(&edp, &c0w1s0, arLoadVerts, mdlDArray_nMembers(daCurLoadNodes), FALSE);
		//	arTransNodes = mdlTransient_addElemDescr(arTransNodes, edp, TRUE, 0xff, NORMALDRAW, 0, 0, 1);
		//}
	}


*/

}



////////////////////////////////////////
void  callbackViewCommands  ( 
BINT       starting  
)
{
	if (starting == FALSE)
	{
		//reinRedrawSpaces(NORMALDRAW);
	}
}





//////////////////////////////////////////
int setElemDescrTooltip(
				  ReinBar* rbP, 
				  ReinSpace* rsP, 
				  MSWCH*   description,
				  double dlent,
				  int iselem,
				  MSWCH* fName,
				  MSWCH* mName,
				  MSWCH* levName,
				  long rad,
				  MSWCH*   dopdescr
				  )
{

	//MSElementDescr* edP = NULL;
	int i;
	char slev[MAX_LEVEL_NAME_LENGTH];
	char spos[500];
	char sdia[500];
	char srad[500];
	//char slen[50];
	char slenr[500];
	char sspa[500];
	//int len;
	int ret = ERROR;
	//int res = SUCCESS;
	char strm[500];


	long ilent = 0;

	if (!EQ(dlent, 0.)) ilent = roundExt(dlent, ROUND_LIN);

	if (iselem)
	{
		char mname[MAX_MODEL_NAME_LENGTH];
		mdlCnv_convertUnicodeToMultibyte(mName, -1, mname, MAX_MODEL_NAME_LENGTH);
		sprintf(spos, "изделие %s",  mname);
	}
	else
	{
		if (iPosCount == 0)
			strcpy(spos, TXT_97);
		else if (iPosCount == 1)
			sprintf(spos, "позиция %i", arPos[0]);
		else if (iPosCount > 1)
		{
			sprintf(spos, "позиции: %i", arPos[0]);

			for (i = 1; i < iPosCount; i++)
			{
				sprintf(sdia, ",%i", arPos[i]);
				strcat(spos, sdia);
			}
		}

		int rm = 0;
		if (rbP) rm = rbP->runmet;
		if (rsP) rm = rsP->runmet;

		if (rm == 0) 
			strcat(spos, TXT_96_1);
		else if (rm == 1) 
			strcat(spos, TXT_96_2);
		else if (rm == 2) 
			strcat(spos, TXT_96_3);
		else if (rm == 3) 
			strcat(spos, TXT_96_4);
	}



	sprintf(sdia, "\nфайл\t%S : %S", fName, mName);
	strcat(spos, sdia);

	mdlCnv_convertUnicodeToMultibyte(levName, -1, slev, MAX_LEVEL_NAME_LENGTH);
	sprintf(sdia, "\nслой\t%s", slev);
	strcat(spos, sdia);

	if (rad > 0) 
	{
		sprintf(srad, "\nрадиус\t%i", rad);
		strcat(spos, srad);
	}


	if (arPosQty[0][2] == arPosQty[0][3])
		sprintf(slenr, "%i", arPosQty[0][2]);
	else
		sprintf(slenr, "%i-%i", arPosQty[0][2], arPosQty[0][3]);



	if (iPosCount == 1)
	{
		sprintf(sdia, "\nкол. %i/%i, длина %s", arPosQty[0][0], arPosQty[0][1], slenr);
		strcat(spos, sdia);
	}

	if (iPosCount > 1)
	{
		sprintf(sdia, "\nп.%i - кол. %i/%i, длина %s", arPos[0], arPosQty[0][0], arPosQty[0][1], slenr);
		strcat(spos, sdia);

		if (arPosQty[1][2] == arPosQty[1][3])
			sprintf(slenr, "%i", arPosQty[1][2]);
		else
			sprintf(slenr, "%i-%i", arPosQty[1][2], arPosQty[1][3]);

		sprintf(sdia, "\nп.%i - кол. %i/%i, длина %s", arPos[1], arPosQty[1][0], arPosQty[1][1], slenr);
		strcat(spos, sdia);
	}



	if (rsP)
	{
		char str[1000];
		MSWCH wstr[1000];

		sprintf(sdia, "\nдиаметр %i", rsP->diam);
		if (ilent > 0) sprintf(slenr, "\nдлина %i", ilent);
		sprintf(sspa, "\nшаг %.1f", rsP->spacef);

		strcpy(str, spos);

		strcat(str, sdia);
		if (ilent > 0) strcat(str, slenr);
		strcat(str, sspa);

		if (rsP->lap[0] || rsP->lap[1])
		{
			sprintf(sspa, "\nразбежка %i <-> %i", rsP->lap[0], rsP->lap[1]);
			if (rsP->lap[2] == 0) strcat(sspa, ", четная"); else  strcat(sspa, ", нечетная");
			strcat(str, sspa);
		}

		if (rsP->spacerad > 0)
		{
			sprintf(sspa, "\nрадиус шага %i", rsP->spacerad);
			strcat(str, sspa);
		}

		sprintf(sspa, "\nотступы -> %i - %i <-", rsP->offset[0], rsP->offset[1]);
		strcat(str, sspa);

		//if (rsP->runmet == 0) 
		//	strcat(str, "\nштуки");
		//else if (rsP->runmet == 1) 
		//{
		//	strcat(str, "\nпогонные метры");
		//}
		//else if (rsP->runmet > 1) 
		//	strcat(str, "\nпеременная длина");


		if (rsP->trm[0] == REIN_TERM_BEND)
		{
			sprintf(sspa, "\nзагиб %i", rsP->trmPar[1][0]);
			strcpy(strm, sspa);
		}
		else if (rsP->trm[0] == REIN_TERM_REZB)
			strcpy(strm, "\nрезьба");
		else if (rsP->trm[0] == REIN_TERM_MUFT)
			strcpy(strm, "\nмуфта");
		else if (rsP->trm[0] == REIN_TERM_SKOB)
			strcpy(strm, "\nскоба");
		else if (rsP->trm[0] == REIN_TERM_SVAR)
			strcpy(strm, "\nсварка");
		else if (rsP->trm[0] == REIN_TERM_PLAT)
			strcpy(strm, "\nплашка");
		else
			strcpy(strm, "\n-");

		if (rsP->trm[0] == REIN_TERM_MUFT && rsP->trmPar[2][0] == 1) strcat(strm, " (п)");
		if (rsP->trm[0] == REIN_TERM_MUFT && rsP->trmPar[2][0] == 2) strcat(strm, " (пс)");
		if (rsP->trm[0] == REIN_TERM_MUFT && rsP->trmPar[2][0] == 3) strcat(strm, " (обж)");

		if (rsP->trm[1] == REIN_TERM_BEND)
		{
			sprintf(sspa, " / загиб %i", rsP->trmPar[1][1]);
			strcat(strm, sspa);
		}
		else if (rsP->trm[1] == REIN_TERM_REZB)
			strcat(strm, " / резьба");
		else if (rsP->trm[1] == REIN_TERM_MUFT)
			strcat(strm, " / муфта");
		else if (rsP->trm[1] == REIN_TERM_SKOB)
			strcat(strm, " / скоба");
		else if (rsP->trm[1] == REIN_TERM_SVAR)
			strcat(strm, " / сварка");
		else if (rsP->trm[1] == REIN_TERM_PLAT)
			strcat(strm, " / плашка");
		else
			strcat(strm, " / - ");

		if (rsP->trm[1] == REIN_TERM_MUFT && rsP->trmPar[2][1] == 1) strcat(strm, " (п)");
		if (rsP->trm[1] == REIN_TERM_MUFT && rsP->trmPar[2][1] == 2) strcat(strm, " (пс)");
		if (rsP->trm[1] == REIN_TERM_MUFT && rsP->trmPar[2][1] == 3) strcat(strm, " (обж)");


		if (rsP->trm[0] != REIN_TERM_NONE || rsP->trm[1] != REIN_TERM_NONE)
			strcat(str, strm);


		mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 1000);

        wcscpy (description, wstr);

		ret = SUCCESS;

	}
	else if (rbP)
	{
		char str[1000];
		MSWCH wstr[1000];

		sprintf(sdia, "\nдиаметр %i", rbP->diam);
		//if (rad > 0) sprintf(srad, "\nрадиус %i", rad);
		if (ilent > 0) sprintf(slenr, "\nдлина %i", ilent);

		sprintf(sspa, "\nшаг %.1f", rbP->spacef);

		strcpy(str, spos);

		strcat(str, sdia);

		//if (rad > 0) strcat(str, srad);

		if (ilent > 0) strcat(str, slenr);


		if (rbP->bartype != BT_AXIS && (int)rbP->spacef > 0) strcat(str, sspa);



		if (rbP->lap[0] || rbP->lap[1])
		{
			sprintf(sspa, "\nразбежка %i <-> %i", rbP->lap[0], rbP->lap[1]);
			if (rbP->lap[2] == 0) strcat(sspa, ", четная"); else  strcat(sspa, ", нечетная");
			strcat(str, sspa);
		}

		if (rbP->spacerad > 0)
		{
			sprintf(sspa, "\nрадиус шага %i", rbP->spacerad);
			strcat(str, sspa);
		}

		sprintf(sspa, "\nотступы -> %i - %i <-", rbP->offset[0], rbP->offset[1]);
		strcat(str, sspa);


		//if (rbP->runmet == 0) 
		//	strcat(str, "\nштуки");
		//else if (rbP->runmet == 1) 
		//	strcat(str, "\nпогонные метры");
		//else if (rbP->runmet > 1) 
		//	strcat(str, "\nпеременная длина");
			
		if (rbP->term[0] == REIN_TERM_BEND)
		{
			sprintf(sspa, "\nзагиб %i", rbP->termPar[1][0]);
			strcpy(strm, sspa);
		}
		else if (rbP->term[0] == REIN_TERM_REZB)
			strcpy(strm, "\nрезьба");
		else if (rbP->term[0] == REIN_TERM_MUFT)
			strcpy(strm, "\nмуфта");
		else if (rbP->term[0] == REIN_TERM_SKOB)
			strcpy(strm, "\nскоба");
		else if (rbP->term[0] == REIN_TERM_SVAR)
			strcpy(strm, "\nсварка");
		else if (rbP->term[0] == REIN_TERM_PLAT)
			strcpy(strm, "\nплашка");
		else
			strcpy(strm, "\n-");

		if (rbP->term[0] == REIN_TERM_MUFT && rbP->termPar[2][0] == 1) strcat(strm, " (п)");
		if (rbP->term[0] == REIN_TERM_MUFT && rbP->termPar[2][0] == 2) strcat(strm, " (пс)");
		if (rbP->term[0] == REIN_TERM_MUFT && rbP->termPar[2][0] == 3) strcat(strm, " (обж)");



		if (rbP->term[1] == REIN_TERM_BEND)
		{
			sprintf(sspa, " / загиб %i", rbP->termPar[1][1]);
			strcat(strm, sspa);
		}
		else if (rbP->term[1] == REIN_TERM_REZB)
			strcat(strm, " / резьба");
		else if (rbP->term[1] == REIN_TERM_MUFT)
			strcat(strm, " / муфта");
		else if (rbP->term[1] == REIN_TERM_SKOB)
			strcat(strm, " / скоба");
		else if (rbP->term[1] == REIN_TERM_SVAR)
			strcat(strm, " / сварка");
		else if (rbP->term[1] == REIN_TERM_PLAT)
			strcat(strm, " / плашка");
		else
			strcat(strm, " / - ");

		if (rbP->term[1] == REIN_TERM_MUFT && rbP->termPar[2][1] == 1) strcat(strm, " (п)");
		if (rbP->term[1] == REIN_TERM_MUFT && rbP->termPar[2][1] == 2) strcat(strm, " (пс)");
		if (rbP->term[1] == REIN_TERM_MUFT && rbP->termPar[2][1] == 3) strcat(strm, " (обж)");



		if (rbP->term[0] != REIN_TERM_NONE || rbP->term[1] != REIN_TERM_NONE)
			strcat(str, strm);


		mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 1000);

        wcscpy (description, wstr);


		ret = SUCCESS;
	}

	if (ret == SUCCESS) wcscat (description, dopdescr);


	return ret;

}



int filterException(int code, PEXCEPTION_POINTERS ex) 
{
	return EXCEPTION_EXECUTE_HANDLER;
}



///////////////////////////////
//void timerExpired(
//int	userArg,
//int	timerHandle
//)
//{
//
//}

//////////////////////
void sync_curPos() // use from vba
{

	char seps[]   = ";";
	char *token;

	token = strtok( sArCurPosPtsC, seps );

	for (int i = 0; token && i < curPos.bar.cnumpts; i++)
	{
		token = strtok( NULL, seps );
		if (token == NULL )	break;
		curPos.bar.cpxb[i].x = atol(token);

		token = strtok( NULL, seps );
		if( token == NULL )	break;
		curPos.bar.cpxb[i].y = atol(token);
	}


	token = strtok( sArCurPosPtsA, seps );

	for (int i = 0; token && i < curPos.bar.cnumpts; i++)
	{
		token = strtok( NULL, seps );
		if (token == NULL )	break;
		curPos.bar.cpxe[i].x = atol(token);

		token = strtok( NULL, seps );
		if( token == NULL )	break;
		curPos.bar.cpxe[i].y = atol(token);
	}

	if (curPos.bar.term[0] == REIN_TERM_MUFT) curPos.bar.termPar[2][0] = curPos.bar.termPar[0][0];
	if (curPos.bar.term[1] == REIN_TERM_MUFT) curPos.bar.termPar[2][1] = curPos.bar.termPar[0][1];

}



/////////////////////////
void drawViewLine(
	DVec3d* pP, 
	VIEWDRAW output,
	ReinElm* relmP, 
	DVec3d* pNormP, 
	int i, int vi, int nump)
{
	DVec3d pCross;
	RotMatrix rmX;
	Transform tm;
	DVec3d ppp[10];

	if (nump > 10) nump = 10;

	for (int ii = 0; ii < nump; ii++)
	{
		ppp[ii] = pP[ii];
	}

	if (pNormP)
	{
		mdlVec_crossProduct(&pCross, &relmP->bel.sgts[i].rv[vi].rvv.tdir, pNormP);
		mdlRMatrix_from3Points(&rmX, &pZero, &relmP->bel.sgts[i].rv[vi].rvv.tdir, &pCross);
		mdlTMatrix_fromRMatrix(&tm, &rmX);
	}
	else
	{
		mdlTMatrix_getIdentity(&tm);
	}

	mdlTMatrix_setTranslation(&tm, &relmP->bel.sgts[i].rv[vi].torg);

	mdlTMatrix_transformPointArray(ppp, &tm, nump);
	
	PD(output)DrawLineString3d(nump, ppp, NULL);
}

/////////////////////////
void drawViewLine(
	DVec3d* pP, 
	VIEWDRAW output,
	ReinElm* relmP,
	DVec3d* pNormP, 
	int i, int vi)
{
	drawViewLine(pP, output, relmP, pNormP, i, vi, 2);
}



/////////////////////////////////
int drawSegmEnd( 
	ELHCP elemIterP,
	ViewContextP context, 
	int reserv,
	ReinElm* relmP, 
	DVec3d* pNormP, 
	DVec3d* pElmNormP, 
	int i, 
	int vi, // start or end
	bool bPlot, // процесс отображения на печати
	int iDrwMode,
	ReinModel* rmP,
	ReinInfoRef* rirP,
	double dBarSign
	)
{
	int ret = 0;

	VIEWDRAW	output 	= context->GetIViewDraw ();

	DVec3d ppp[10];

	double diam = mdlCnv_masterUnitsToUors(relmP->bel.diam);

	bool b[6];

	bool bMuftDraw = false;
	bool bBarEnd = false;

	//double dBarSign = dCfgVar_BarSign / rmP->refscale;
	//if (arRefPrefs->bface > 0) dBarSign = mdlCnv_masterUnitsToUors(arRefPrefs->bface);


	//ReinInfoRef* rirP = rmP->getRefPrefs();


	//if (relmP->bel.ffpos[REIN_ELEM_ISO] == 4002815)
	//	__asm nop;


	b[0] =	(
				(bPlot && // идет печать
					(arPlotCfgVar[REIN_PLOT_AUX_V] == 1 || // всегда печатать
						(rirP->ends && arPlotCfgVar[REIN_PLOT_AUX_V] == 0) // галка засечек
					)
				) 
		|| 
				(!bPlot && // не печать
					rirP->ends // галка засечек
				)
			) 
		&& 
			(relmP->drwopt[1] == FALSE);

	b[1] = ((bPlot && (arPlotCfgVar[REIN_PLOT_TERM_BEND] == 1 || (rirP->riropt[8] && arPlotCfgVar[REIN_PLOT_TERM_BEND] == 0))) || 
			(!bPlot && rirP->riropt[8]));

	b[2] = ((bPlot && (arPlotCfgVar[REIN_PLOT_TERM_REZB] == 1 || (/*rirP->threads && */arPlotCfgVar[REIN_PLOT_TERM_REZB] == 0))) || 
			(!bPlot /*&& rirP->threads*/));

	b[3] = ((bPlot && (arPlotCfgVar[REIN_PLOT_TERM_MUFT] == 1 || (/*rirP->riropt[12] && */arPlotCfgVar[REIN_PLOT_TERM_MUFT] == 0))) || 
			(!bPlot /*&& rirP->riropt[12]*/));

	b[4] = ((bPlot && (arPlotCfgVar[REIN_PLOT_TERM_SKOB] == 1 || (/*rirP->riropt[12] && */arPlotCfgVar[REIN_PLOT_TERM_SKOB] == 0))) || 
			(!bPlot /*&& rirP->riropt[12]*/));

	b[5] = ((bPlot && (arPlotCfgVar[REIN_PLOT_TERM_SVAR] == 1 || (/*rirP->riropt[12] && */arPlotCfgVar[REIN_PLOT_TERM_SVAR] == 0))) || 
			(!bPlot /*&& rirP->riropt[12]*/));


	int bPerp = mdlVec_arePerpendicular(pNormP, &relmP->bel.sgts[i].rv[vi].rvv.tdir);
	int bParr = mdlVec_areParallel(pNormP, &relmP->bel.sgts[i].rv[vi].rvv.tdir);

	if ((i == relmP->bel.numsgts-1 && vi == 1) || (i == 0 && vi == 0)) bBarEnd = true;

	if (iCfgVar_NewMuftDraw)
		bMuftDraw = ((relmP->bel.term[vi] == REIN_TERM_REZB && bPlot && rirP->threads) || relmP->bel.term[vi] == REIN_TERM_MUFT);
	else
		bMuftDraw = (relmP->bel.term[vi] == REIN_TERM_MUFT);

	//if (bPerp && relmP->bel.termclip[vi] && b[0])
	if (!bParr && bPerp && relmP->bel.sgts[i].rv[vi].mpar & RFA_ENDC
		//&& b[0]
		//&& relmP->drwopt[4] == FALSE
		&& rDopInfo.dopopt[12]
		) // обрезан клипом (-|)
	{

		// попытка нарисовать ломаную... не пущает клип
		for (int bb = 0; bb < 10; bb++)
			mdlVec_zero(&ppp[bb]);

		ppp[0].x = 0.;
		ppp[1].x = dBarSign / 10.;
		ppp[2].x = 0.;
		ppp[3].x = 0.;
		ppp[4].x = dBarSign / 10.;

		ppp[0].y = dBarSign / 2.;
		ppp[1].y = dBarSign / 4.;
		ppp[2].y = 0.;
		ppp[3].y = -dBarSign / 4.;
		ppp[4].y = -dBarSign / 2.;

		//ClipPlaneSet cp;

		//ClipPlaneSetCP cpP = context->GetRangePlanes();


		//cp.planes[0].distance += dCfgVar_BarSign/10.;
		//cp.planes[1].distance -= dCfgVar_BarSign/10.;
		//cp.planes[2].distance += dCfgVar_BarSign/10.;
		//cp.planes[3].distance += dCfgVar_BarSign/10.;

		//output.PushTransClip(0, &cp, false);
		drawViewLine(ppp, output, relmP, pNormP, i, vi, 5);
		//output.PopTransClip();


		//ppp[0].y -= dCfgVar_BarSign / 5.;
		//ppp[1].y += dCfgVar_BarSign / 5.;

		//drawViewLine(ppp, output, relmP, pNormP, i, vi);


		ret = REIN_TERM_TRMI;
	}
	//else if (bPerp && (relmP->bel.sgts[i].rv[vi].mpar == 0 || relmP->bel.sgts[i].rv[vi].mpar & RFA_ENDP) && relmP->bel.term[vi] == 0 && b[0])
	else if (bPerp 
		&& (relmP->bel.sgts[i].rv[vi].mpar & RFA_ENDP) 
		&& relmP->bel.term[vi] == 0 
		&& bBarEnd 
		&& b[0]
		&& relmP->bel.diam >= iCfgVar_BarBendNotchDiam
		)
	{

		for (int a = 0; a < 10; a++)
			mdlVec_zero(&ppp[a]);

		ppp[1].y += dBarSign;

		if (relmP->bel.ilaps) // окружность < >
			ppp[1].x -= dBarSign * 2;
		else
			ppp[1].x += dBarSign * 2;

		drawViewLine(ppp, output, relmP, pNormP, i, vi);

		ret = REIN_TERM_TRMV;

	}
	else if (/*bPerp && */relmP->bel.term[vi] == REIN_TERM_BEND && bBarEnd && b[1] 
		&& !(iCfgVar_BendNewDraw == 2)
		)
	{

		double d = diam * 5 * SGN(relmP->bel.termPar[0][vi]); //(R=2.5D) signed
		double dd = mdlCnv_masterUnitsToUors(relmP->bel.termPar[1][vi]) - fabs(d); // д.б. 6D

		if (relmP->elemflags & REINEL_FLAG_BEND && relmP->bel.cnumpts > 2) // новая отрисовка
		{
			double vecang;
			DVec3d nrm; // нормаль элемента
			DVec3d vec; // получаемый вектор, указывающий направление загиба (90°) 
			RotMatrix rm[2];
			DVec3d ttdir;

			if (vi == 0)
			{
				vecang = mdlVec_angleBetweenVectors(&relmP->bel.sgts[0].rv[0].rvv.tdir, 
													&relmP->bel.sgts[1].rv[0].rvv.tdir);

				if (mdlVec_areParallel(&relmP->bel.sgts[0].rv[0].rvv.tdir, &relmP->bel.sgts[1].rv[0].rvv.tdir))
				{
					nrm = relmP->bel.v_enrm;
				}
				else
				{
					mdlVec_crossProduct(&nrm, &relmP->bel.sgts[0].rv[0].rvv.tdir, 
														&relmP->bel.sgts[1].rv[0].rvv.tdir);
				}


				mdlVec_crossProduct(&vec, &nrm, &relmP->bel.sgts[0].rv[0].rvv.tdir);

				ttdir = relmP->bel.sgts[0].rv[0].rvv.tdir;
			}
			else
			{
				vecang = mdlVec_angleBetweenVectors(&relmP->bel.sgts[relmP->bel.numsgts-1].rv[1].rvv.tdir, 
													&relmP->bel.sgts[relmP->bel.numsgts-2].rv[1].rvv.tdir);

				if (mdlVec_areParallel(&relmP->bel.sgts[relmP->bel.numsgts-1].rv[1].rvv.tdir, &relmP->bel.sgts[relmP->bel.numsgts-2].rv[1].rvv.tdir))
				{
					nrm = relmP->bel.v_enrm;
				}
				else
				{
					mdlVec_crossProduct(&nrm, &relmP->bel.sgts[relmP->bel.numsgts-1].rv[1].rvv.tdir, 
														&relmP->bel.sgts[relmP->bel.numsgts-2].rv[1].rvv.tdir);
				}


				mdlVec_crossProduct(&vec, &nrm, &relmP->bel.sgts[relmP->bel.numsgts-1].rv[1].rvv.tdir);
				
				ttdir = relmP->bel.sgts[relmP->bel.numsgts-1].rv[1].rvv.tdir;
			}

			//if (vecang < fc_pi)
			//{
			//	int a = 0;
			//}

			for (int a = 0; a < 10; a++)
				mdlVec_zero(&ppp[a]);

			mdlVec_scaleToLength(&ppp[1], &vec, d); // первый кусок загиба

			drawViewLine(ppp, output, relmP, NULL, i, vi);

			double rtan = (180 - relmP->bel.termPar[0][vi]) * fc_piover180;
			mdlRMatrix_fromRowVectors(&rm[0], &ttdir, &vec, &nrm);
			mdlRMatrix_fromRotationAboutAxis(&rm[1], &nrm, rtan);
			mdlRMatrix_multiply(&rm[0], &rm[0], &rm[1]);
			mdlVec_fromRotMatrixRow(&vec, &rm[0], 0); // получили направление второго куска (ед. вектор)
			ppp[0] = ppp[1];
			mdlVec_scaleToLength(&vec, &vec, dd); //  получили второй кусок (вектор)
			mdlVec_addPoint(&ppp[1], &ppp[1], &vec);

			drawViewLine(ppp, output, relmP, NULL, i, vi);

		}
		else
		{
			int iK = 0; // коэф./флаг - учитывает поворот вида

			if (pElmNormP)
			{
				double an = mdlVec_angleBetweenVectors(pNormP, pElmNormP);

				if (EQ(an, fc_pi)) iK = 1; else iK = -1;

			}
			else
				iK = -1;


			if (iK
				//&& mdlVec_areParallel(pElmNormP, pNormP) // отобр. только на чертеже
				)
			{
				if (mdlVec_areParallel(pElmNormP, pNormP) == FALSE) d /= 5.;
				
				for (int a = 0; a < 10; a++)
					mdlVec_zero(&ppp[a]);

				ppp[0].y += d * iK;

				drawViewLine(ppp, output, relmP, pNormP, i, vi);

				for (int a = 0; a < 10; a++)
					mdlVec_zero(&ppp[a]);

				ppp[0].y += d * iK;
				ppp[1].y += (d + dd * (sin(relmP->bel.termPar[0][vi] * fc_piover180))) * iK; // degree to rad
				ppp[1].x -= dd * cos(relmP->bel.termPar[0][vi] * fc_piover180); // degree to rad

				drawViewLine(ppp, output, relmP, pNormP, i, vi);

			}
		}

		ret = REIN_TERM_BEND; // загиб делаем потом и нормальный

	}
	else if (/*bPerp &&*/ !bParr && relmP->bel.term[vi] == REIN_TERM_REZB && bBarEnd && b[2] && !bMuftDraw)
	{

		//ppp[0].y += dCfgVar_BarSign;
		//ppp[1].y -= dCfgVar_BarSign;
		////ppp[0].x += dCfgVar_BarSign; // наклонный штрих
		//ppp[1].x += dCfgVar_BarSign ;
		//drawViewLine(ppp, output, relmP, pNormP, i, vi);
		//ppp[0].x += dCfgVar_BarSign ;
		//ppp[1].x += dCfgVar_BarSign ;
		//drawViewLine(ppp, output, relmP, pNormP, i, vi);
		//ppp[0].x += dCfgVar_BarSign ;
		//ppp[1].x += dCfgVar_BarSign ;
		//drawViewLine(ppp, output, relmP, pNormP, i, vi);

		DVec3d p[10];
		double dRad = dBarSign * dCfgVar_MuftWdtKoef * 0.8;
		DVec3d pdit[2];
		RotMatrix rm;
		mdlRMatrix_fromNormalVector (&rm, &relmP->bel.sgts[i].rv[vi].rvv.tdir);
		mdlVec_fromRotMatrixRow(&pdit[0], &rm, 0);
		mdlVec_fromRotMatrixRow(&pdit[1], &rm, 1);

		mdlVec_scaleToLength(&p[0], &relmP->bel.sgts[i].rv[vi].rvv.tdir, dBarSign * 1.2);
		mdlVec_scaleToLength(&p[1], &relmP->bel.sgts[i].rv[vi].rvv.tdir, dBarSign * 0.6);
		mdlVec_scaleToLength(&p[2], &relmP->bel.sgts[i].rv[vi].rvv.tdir, dBarSign * 0.0);
		mdlVec_scaleToLength(&p[3], &relmP->bel.sgts[i].rv[vi].rvv.tdir, -dBarSign * 0.6);
		mdlVec_scaleToLength(&p[4], &relmP->bel.sgts[i].rv[vi].rvv.tdir, -dBarSign * 1.2);

		mdlVec_addPoint(&p[0], &relmP->bel.sgts[i].rv[vi].torg, &p[0]);
		mdlVec_addPoint(&p[1], &relmP->bel.sgts[i].rv[vi].torg, &p[1]);
		mdlVec_addPoint(&p[2], &relmP->bel.sgts[i].rv[vi].torg, &p[2]);
		mdlVec_addPoint(&p[3], &relmP->bel.sgts[i].rv[vi].torg, &p[3]);
		mdlVec_addPoint(&p[4], &relmP->bel.sgts[i].rv[vi].torg, &p[4]);

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ???

		OvrMatSymbP ovrMatSymb = context->GetOverrideMatSymb();
		//int clr = ovrMatSymb->GetLineColorIndex();

		ovrMatSymb->SetIndexedLineColorTBGR(relmP->bel.termPar[2][vi], 0);
		if (relmP->bel.modrefP && mdlModelRef_isActiveModel(relmP->bel.modrefP) || iDrwMode == 1)
		{
		ovrMatSymb->SetTransparentLineColor(50);
		ovrMatSymb->SetTransparentFillColor(50);
		}

		output.ActivateOverrideMatSymb(ovrMatSymb);
		context->CookElemDisplayParams(*elemIterP);

		DEllipse3d ell[5];
		//el = FromScaledVectors(&p[0], &pdit[0], &pdit[1], dRad, dRad);
		ell[0] = DEllipse3d::FromCenterNormalRadius(p[0], relmP->bel.sgts[i].rv[vi].rvv.tdir, dRad);
		ell[1] = DEllipse3d::FromCenterNormalRadius(p[1], relmP->bel.sgts[i].rv[vi].rvv.tdir, dRad);
		ell[2] = DEllipse3d::FromCenterNormalRadius(p[2], relmP->bel.sgts[i].rv[vi].rvv.tdir, dRad);
		ell[3] = DEllipse3d::FromCenterNormalRadius(p[3], relmP->bel.sgts[i].rv[vi].rvv.tdir, dRad);
		ell[4] = DEllipse3d::FromCenterNormalRadius(p[4], relmP->bel.sgts[i].rv[vi].rvv.tdir, dRad);

		output.DrawArc3d(ell[0], true, false, 0);
		output.DrawArc3d(ell[1], true, false, 0);
		output.DrawArc3d(ell[2], true, false, 0);
		output.DrawArc3d(ell[3], true, false, 0);
		output.DrawArc3d(ell[4], true, false, 0);
		//output.DrawArc3d(&p[1], 0, &pdit[0], &pdit[1], dRad, dRad, 0, 0, false, 0);
		//output.DrawArc3d(&p[2], 0, &pdit[0], &pdit[1], dRad, dRad, 0, 0, false, 0);
		//output.DrawArc3d(&p[3], 0, &pdit[0], &pdit[1], dRad, dRad, 0, 0, false, 0);
		//output.DrawArc3d(&p[4], 0, &pdit[0], &pdit[1], dRad, dRad, 0, 0, false, 0);
#else

		OvrMatSymbP ovrMatSymb = context->GetOverrideMatSymb();
		//int clr = ovrMatSymb->GetLineColorIndex();

		ovrMatSymb->SetIndexedLineColor(relmP->bel.termPar[2][vi], 0);
		if (relmP->bel.modrefP && mdlModelRef_isActiveModel(relmP->bel.modrefP) || iDrwMode == 1)
		{
			ovrMatSymb->SetTransparentLineColor(50);
			ovrMatSymb->SetTransparentFillColor(50);
		}

		output->ActivateOverrideMatSymb(ovrMatSymb);
		context->CookElemDisplayParams(*elemIterP);

		output->DrawArc3d(&p[0], 0, &pdit[0], &pdit[1], dRad, dRad, 0, 0, false, 0);
		output->DrawArc3d(&p[1], 0, &pdit[0], &pdit[1], dRad, dRad, 0, 0, false, 0);
		output->DrawArc3d(&p[2], 0, &pdit[0], &pdit[1], dRad, dRad, 0, 0, false, 0);
		output->DrawArc3d(&p[3], 0, &pdit[0], &pdit[1], dRad, dRad, 0, 0, false, 0);
		output->DrawArc3d(&p[4], 0, &pdit[0], &pdit[1], dRad, dRad, 0, 0, false, 0);


#endif
		ret = REIN_TERM_REZB; // все равно не выводится на печать

	}
	else if (/*bPerp && !bParr &&*/ relmP->bel.term[vi] == REIN_TERM_PLAT && bBarEnd && b[2] && !bMuftDraw)
	{

		DVec3d p[2];
		double dWdt = mdlCnv_masterUnitsToUors(90.);
		double dThk = mdlCnv_masterUnitsToUors(20.);
		DVec3d pdit[2];
		RotMatrix rm;
		mdlRMatrix_fromNormalVector(&rm, &relmP->bel.sgts[i].rv[vi].rvv.tdir);
		mdlVec_fromRotMatrixRow(&pdit[0], &rm, 0);
		mdlVec_fromRotMatrixRow(&pdit[1], &rm, 1);

		mdlVec_scaleToLength(&p[0], &relmP->bel.sgts[i].rv[vi].rvv.tdir, 0.);
		mdlVec_scaleToLength(&p[1], &relmP->bel.sgts[i].rv[vi].rvv.tdir, -dThk);

		mdlVec_addPoint(&p[0], &relmP->bel.sgts[i].rv[vi].torg, &p[0]);
		mdlVec_addPoint(&p[1], &relmP->bel.sgts[i].rv[vi].torg, &p[1]);



		OvrMatSymbP ovrMatSymb = context->GetOverrideMatSymb();

		ovrMatSymb->SetIndLineColor(relmP->bel.termPar[2][vi], 0);

		if (relmP->bel.modrefP && mdlModelRef_isActiveModel(relmP->bel.modrefP) || iDrwMode == 1)
		{
			ovrMatSymb->SetTransparentLineColor(50);
			ovrMatSymb->SetTransparentFillColor(50);
		}


#if defined (MSVERSION) && (MSVERSION == 0xa00) // ???
		output.ActivateOverrideMatSymb(ovrMatSymb);
		context->CookElemDisplayParams(*elemIterP);
		output.DrawBox(pdit[0], pdit[1], p[0], p[1], dWdt, dWdt, dWdt, dWdt, true);
#else
		output->ActivateOverrideMatSymb(ovrMatSymb);
		context->CookElemDisplayParams(*elemIterP);
		output->DrawBox(&pdit[0], &pdit[1], &p[0], &p[1], dWdt, dWdt, dWdt, dWdt, true);
#endif

		ret = REIN_TERM_PLAT; // все равно не выводится на печать

	}
	else if (bPerp && relmP->bel.term[vi] == REIN_TERM_SVAR && bBarEnd && b[5])
	{
		for (int a = 0; a < 10; a++)
			mdlVec_zero(&ppp[a]);

		RotMatrix rm;
		mdlRMatrix_fromNormalVector(&rm, &relmP->bel.sgts[i].rv[vi].rvv.tdir);

		mdlVec_fromRotMatrixRow(&ppp[0], &rm, 0);
		mdlVec_fromRotMatrixRow(&ppp[1], &rm, 2);

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ???
		DEllipse3d ell;
		ell = DEllipse3d::FromScaledVectors(relmP->bel.sgts[i].rv[vi].torg, 
			ppp[0], ppp[1], dBarSign, dBarSign / 2., 0., 1.);

		output.DrawArc3d(ell, true, true, 0);
#else
		output->DrawArc3d (&relmP->bel.sgts[i].rv[vi].torg, NULL, &ppp[0], &ppp[1], dBarSign, dBarSign / 2., NULL, NULL, true, NULL);
#endif

		ret = REIN_TERM_SVAR; // все равно не выводится на печать

	}
	else if (
		(mdlModelRef_isActiveModel(relmP->bel.modrefP) && !bParr && bMuftDraw && bBarEnd && b[3])
		|| (!mdlModelRef_isActiveModel(relmP->bel.modrefP) && bPerp && bMuftDraw && bBarEnd && b[3])
		)
	{

		for (int a = 0; a < 10; a++)
			mdlVec_zero(&ppp[a]);

		//ppp[0].y += dCfgVar_BarSign;
		//ppp[1].y -= dCfgVar_BarSign;
		//drawViewLine(ppp, output, relmP, pNormP, i, vi);
		//ppp[0].x += dCfgVar_BarSign * 3;
		//ppp[1].x += dCfgVar_BarSign * 3;
		//drawViewLine(ppp, output, relmP, pNormP, i, vi);
		//ppp[0].y += dCfgVar_BarSign;
		//ppp[1].y += dCfgVar_BarSign;
		//ppp[1].x += dCfgVar_BarSign * 3;
		//drawViewLine(ppp, output, relmP, pNormP, i, vi);
		//ppp[0].y -= dCfgVar_BarSign;
		//ppp[1].y -= dCfgVar_BarSign;
		//ppp[1].x += dCfgVar_BarSign * 3;
		//drawViewLine(ppp, output, relmP, pNormP, i, vi);

		RotMatrix rm;
		mdlRMatrix_fromNormalVector(&rm, &relmP->bel.sgts[i].rv[vi].rvv.tdir);
		DVec3d p[10];

		mdlVec_fromRotMatrixRow(&ppp[0], &rm, 0);
		mdlVec_fromRotMatrixRow(&ppp[1], &rm, 1);

		if (iCfgVar_NewMuftDraw)
		{
			mdlVec_scaleToLength(&p[0], &relmP->bel.sgts[i].rv[vi].rvv.tdir, dBarSign * dCfgVar_MuftHgtKoef);
			mdlVec_scaleToLength(&p[1], &relmP->bel.sgts[i].rv[vi].rvv.tdir, -dBarSign * dCfgVar_MuftHgtKoef);
		}
		else
		{
			mdlVec_scaleToLength(&p[0], &relmP->bel.sgts[i].rv[vi].rvv.tdir, dBarSign * 3.0);
			mdlVec_scaleToLength(&p[1], &relmP->bel.sgts[i].rv[vi].rvv.tdir, -dBarSign * 0.0);
		}

		mdlVec_addPoint(&p[0], &relmP->bel.sgts[i].rv[vi].torg, &p[0]);
		mdlVec_addPoint(&p[1], &relmP->bel.sgts[i].rv[vi].torg, &p[1]);

		OvrMatSymbP ovrMatSymb = context->GetOverrideMatSymb();
		//int clr = ovrMatSymb->GetLineColorIndex();

		ovrMatSymb->SetIndLineColor(relmP->bel.termPar[2][vi], 0);

		if (relmP->bel.modrefP && mdlModelRef_isActiveModel(relmP->bel.modrefP) || iDrwMode == 1)
		{
			ovrMatSymb->SetTransparentLineColor(50);
			ovrMatSymb->SetTransparentFillColor(50);
		}


#if defined (MSVERSION) && (MSVERSION == 0xa00) // ???
		output.ActivateOverrideMatSymb(ovrMatSymb);
		context->CookElemDisplayParams(*elemIterP);
		output.DrawCone(p[0], p[1], dBarSign * dCfgVar_MuftWdtKoef, dBarSign * dCfgVar_MuftWdtKoef, true);
#else
		output->ActivateOverrideMatSymb(ovrMatSymb);
		context->CookElemDisplayParams(*elemIterP);
		output->DrawCone(&ppp[0], &ppp[1], &p[0], &p[1], dBarSign * dCfgVar_MuftWdtKoef, dBarSign * dCfgVar_MuftWdtKoef, true);
#endif
		//ret = REIN_TERM_MUFT; 
		ret = relmP->bel.term[vi]; // REIN_TERM_MUFT или REIN_TERM_REZB

	}
	else if (bPerp && relmP->bel.term[vi] == REIN_TERM_SKOB && bBarEnd && b[4])
	{

		for (int a = 0; a < 10; a++)
			mdlVec_zero(&ppp[a]);

		ppp[0].y += dBarSign * dCfgVar_MuftWdtKoef;
		ppp[1].y += dBarSign * dCfgVar_MuftWdtKoef;

		if (iCfgVar_NewMuftDraw)
		{
			ppp[0].x += dBarSign * dCfgVar_MuftHgtKoef;
			ppp[1].x -= dBarSign * dCfgVar_MuftHgtKoef;
		}
		else
		{
			ppp[1].x += dBarSign * 3;
		}

		drawViewLine(ppp, output, relmP, pNormP, i, vi);

		for (int a = 0; a < 10; a++)
			mdlVec_zero(&ppp[a]);

		ppp[0].y -= dBarSign * dCfgVar_MuftWdtKoef;
		ppp[1].y -= dBarSign * dCfgVar_MuftWdtKoef;

		if (iCfgVar_NewMuftDraw)
		{
			ppp[0].x += dBarSign * dCfgVar_MuftHgtKoef;
			ppp[1].x -= dBarSign * dCfgVar_MuftHgtKoef;
		}
		else
		{
			ppp[1].x += dBarSign * 3;
		}

		drawViewLine(ppp, output, relmP, pNormP, i, vi);

		ret = REIN_TERM_SKOB;

	}

	return ret;

}



/////////////////////////////////////////////////////////////
void drawReinElm(
	ELHCP elemIterP,
	MSElementDescrH newEdPP,
	MSElementDescrCP edp, 
	ReinModel* rmP, 
	ReinElm* reP,
	ViewportP viewPortP, 
	VCNTXP context,
	UInt32 iBlock,
	bool bPlot,
	Transform* tmP,
	int iDrwMode,
	ReinInfoRef* rirP,
	DrawPurpose drawPurpose
	)
{
	//ReinElm drelm; // not transformed, for work in current transform
	//ReinElm relt;
	double dDepth = -150.;
	//DVec3d arPtsX[MAX_BAR_VERTICES];
	//DVec3d arPtsO[MAX_BAR_VERTICES];
	//double arDepthX[MAX_BAR_VERTICES];
	//double arDepthO[MAX_BAR_VERTICES];
	int iPtsCntX = 0;
	int iPtsCntO = 0;
	DVec3d pElmNorm;
	DVec3d* pElmNormP = NULL;
	RotMatrix rm;
	//double q[4];

	RotMatrix rmTm;

	MSElementDescr* edpAx = NULL;
	//MSElementDescr* edpAxTrns = NULL;


	DgnModelRefP mrP = edp->h.dgnModelRef;

	bool bRondo = false;
	bRondo = (reP->type == REIN_ELEM_RND);

	//MSElementDescr* edpRef = NULL;
	//UInt32 ffpp = 0;

	//writeLogIn(__FUNCTION__, 0); // drawReinElm

	int mask = reinGetLevelMask(edp, 0, 0);

	int view = viewPortP->GetViewNumber();

	//Transform tmLF;
	//context->GetLocalToFrustumTrans(&tmLF, 0);

	drelm = *reP;
	
	

	if (mask & (1<<view))
	{
		//Transform tm;
		
		DVec3d pvec[2][2];
		DVec3d ppp[2];
		DVec3d pViewNormZ;
		DVec3d pViewNormY;
		DVec3d pViewNormX;
		DVec3d pView;
		int insideView[2][50];
		double dist = mdlCnv_masterUnitsToUors((double)drelm.bel.diam / 2.);
		double distrif = mdlCnv_masterUnitsToUors(fillets[drelm.bel.diam].diamrif / 2.);
		int bFound = FALSE;
		
		RotMatrixCP rmViewP = viewPortP->GetRotMatrix();

		mdlVec_fromRotMatrixRow (&pViewNormZ, rmViewP, 2);
		mdlVec_fromRotMatrixRow (&pViewNormY, rmViewP, 1);
		mdlVec_fromRotMatrixRow (&pViewNormX, rmViewP, 0);


		
		Transform* tmRefP = NULL;
		Transform* tmRefInvP = NULL;




		//checkClipAxis(&drelm.bel, &relt.bel, edp, mrP, view);



		//ELREF eref = viewPortP->GetClipBoundElementRef();
		//if (eref)
		//{
		//	MSElementDescr* edpClip = NULL;
		//	mdlElmdscr_getByElemRef (&edpClip, eref, mrP, FALSE, 0);
		//	mdlElmdscr_freeAll(&edpClip);
		//}



		//if (tmP) // для cell
		//{
		//	context->PushActiveTransform(*tmP); // v8i - PushActiveTransform(tmP)
		//	mdlRMatrix_fromTMatrix(&rmTm, tmP);
		//	mdlRMatrix_normalize(&rmTm, &rmTm); // убираем масштаб
		//}


		if (mdlModelRef_isActiveModel(mrP) == FALSE)
		{
			Transform tmRef;
			Transform tmRef2;
			mdlTMatrix_referenceToMaster(&tmRef2, mrP);
			tmRefP = &tmRef;
			mdlTMatrix_masterToReference(&tmRef, mrP); // обратная
			tmRefInvP = &tmRef2;

			RotMatrix rm0;
			RotMatrix rm2;
			//RotMatrix rm3;

			mdlRMatrix_fromTMatrix(&rm0, tmRefP);

			mdlRMatrix_normalize(&rm0, &rm0); // убираем масштаб

			mdlRMatrix_invert(&rm2, &rm0);
			mdlRMatrix_multiply(&rm2, rmViewP, &rm2);

			mdlVec_fromRotMatrixRow (&pViewNormZ, &rm2, 2);
			mdlVec_fromRotMatrixRow (&pViewNormY, &rm2, 1);
			mdlVec_fromRotMatrixRow (&pViewNormX, &rm2, 0);

			//ffpp = mdlElmdscr_getFilePos(edp);
			//if (ffpp)
			//{
			//	mdlElmdscr_readToMaster(&edpRef, ffpp, mrP, 0, 0);
			//}

		}


		
		//ElemDisplayParamsP dpP = context->GetCurrentDisplayParams();
		//dpP->m_transparency = 0;

		VIEWDRAW output = context->GetIViewDraw ();
		//ReinInfoRef* rirP = rmP->getRefPrefs();


		double dSecRad = 0.;
		
		if (rirP->riropt[9]) // если отображать реальный диаметр сечения
		{
			//if (fillets[drelm.bel.diam].diamrif > 0)
			//{
				dSecRad = mdlCnv_masterUnitsToUors((double)fillets[drelm.bel.diam].diamrif / 2.);
			//}
			//else
			//{
			//	dSecRad = mdlCnv_masterUnitsToUors((double)drelm.bel.diam / 2.);
			//}
		}
		else
		{
			if (rirP->bface > 0)
				dSecRad = mdlCnv_masterUnitsToUors(rirP->bface);
			else
				dSecRad = mdlCnv_masterUnitsToUors(dCfgVar_BarFace);
		}





		// исп. pViewNormZ чтобы был виден загиб со всех сторон на прямом стержне
		if (mdlElmdscr_extractNormal(&pElmNorm, NULL, edp, &pViewNormZ) == SUCCESS) 
			pElmNormP = &pElmNorm;
		else
			pElmNormP = &drelm.bel.v_enrm;


		// объемный контур стержня
		//====================================
		/*
		if ((bPlot && (arPlotCfgVar[REIN_PLOT_BAR3D] == 1 || (rirP->riropt[10] && arPlotCfgVar[REIN_PLOT_BAR3D] == 0))) || 
			(!bPlot && rirP->riropt[10])
			)
		{
			MSElementDescr* edBarP = NULL;
			MSElementDescr* edBar2P = NULL;

			if (iCfgVar_UseGhostContour == FALSE
				&& drelm.bel.ffpos[REIN_ELEM_BAR]  // ELID
					)
			{
				ELID barid = (ELID)drelm.bel.ffpos[REIN_ELEM_BAR];
				ELREF barref = getElemRefByID(mrP, barid);
				if (barref)
				{
					mdlElmdscr_getByElemRef (&edBarP, barref, mrP, FALSE, 0);
					if (edBarP)
					{
						//mdlElement_setTransparency(&elForTT, 0.0);
						//mdlElement_setSymbology(&elForTT, &bc, 0, 0);
						mdlElmdscr_setVisible(edBarP, TRUE);
						ELH elh1(edBarP, false);
						context->VisitElemHandle(elh1, false, false);
						mdlElmdscr_freeAll(&edBarP);
					}
				}
			}
			else
			{

				DVec3d pN[3];
				Transform tm[2];
				MSElementDescr* edLineOneP = NULL;
				MSElementDescr* edLineTwoP = NULL;

				pN[0] = pViewNormY;
				
				int ret = SUCCESS;

				//if (edpRef && mdlElmdscr_extractNormal(&pN[1], NULL, edpRef, &pN[0]) != SUCCESS)
				//	pN[1] = pN[0];
				//else
				//{
					if (edp && mdlElmdscr_extractNormal(&pN[1], NULL, edp, &pN[0]) != SUCCESS)
						pN[1] = pN[0];
				//}

				mdlVec_scaleToLengthInPlace(&pN[1], distrif);
				mdlVec_negate(&pN[2], &pN[1]);

				mdlTMatrix_getIdentity(&tm[0]);
				mdlTMatrix_getIdentity(&tm[1]);
				mdlTMatrix_setTranslation(&tm[0], &pN[1]);
				mdlTMatrix_setTranslation(&tm[1], &pN[2]);

				OvrMatSymbP ovrMatSymb = context->GetOverrideMatSymb();
				if (rirP->riropt[19]) // цвет по диаметру
				{
					ovrMatSymb->SETCOLOR(drelm.bel.diam, 0);
				}
				else
				{
					UInt32 clr;
					mdlElement_getSymbology(&clr, 0, 0, &edp->el);
					ovrMatSymb->SETCOLOR(clr, 0);
				}
				PD(output)ActivateOverrideMatSymb(ovrMatSymb);

				//if (mdlElmdscr_signedOffset(newEdPP, edp, distrif, &pN[0]) == SUCCESS) // если замена прошла успешно (глючит)
				{
					if (mdlElmdscr_signedOffset(&edLineOneP, edp, distrif, &pN[0]) == SUCCESS)
					{
						//MSBsplineCurve crv;
						if (mdlBspline_convertToCurve(&crv, edLineOneP) == SUCCESS)
							PDA(output, DrawBSplineCurve)crv, false);

						//ret = mdlElmdscr_extractEndPoints(&pte[0][0], 0, &pte[1][0], 0, *newEdPP, mrP);
						mdlElmdscr_freeAll(&edLineOneP);
					}

					if (mdlElmdscr_signedOffset(&edLineTwoP, edp, -distrif, &pN[0]) == SUCCESS)
					{
						//MSBsplineCurve crv;
						if (mdlBspline_convertToCurve(&crv, edLineTwoP) == SUCCESS)
							PDA(output,DrawBSplineCurve)crv, false);

						//ret = mdlElmdscr_extractEndPoints(&pte[0][1], 0, &pte[1][1], 0, edLineTwoP, mrP);
						mdlElmdscr_freeAll(&edLineTwoP);
					}

					mdlElmdscr_duplicate(&edLineOneP, edp);
					mdlElmdscr_duplicate(&edLineTwoP, edp);

					if (func_amp(mdlElmdscr_transform,edLineOneP), &tm[0]) == SUCCESS)
					{
						//MSBsplineCurve crv;
						if (mdlBspline_convertToCurve(&crv, edLineOneP) == SUCCESS)
							PDA(output, DrawBSplineCurve)crv, false);

						//ret = mdlElmdscr_extractEndPoints(&pte[2][0], 0, &pte[3][0], 0, edLineOneP, mrP);
					}
					if (func_amp(mdlElmdscr_transform,edLineTwoP), &tm[1]) == SUCCESS)
					{
						//MSBsplineCurve crv;
						if (mdlBspline_convertToCurve(&crv, edLineTwoP) == SUCCESS)
							PDA(output, DrawBSplineCurve)crv, false);

						//ret = mdlElmdscr_extractEndPoints(&pte[2][1], 0, &pte[3][1], 0, edLineTwoP, mrP);
					}

					mdlElmdscr_freeAll(&edLineOneP);
					mdlElmdscr_freeAll(&edLineTwoP);

					//PD(output)DrawLineString3d(2, pte[0], NULL);
					//PD(output)DrawLineString3d(2, pte[1], NULL);
					//PD(output)DrawLineString3d(2, pte[2], NULL);
					//PD(output)DrawLineString3d(2, pte[3], NULL);

				}
		
				// окончания контуров стержней
				//=========================================
				//RotMatrix rm;
				TextSizeParam tsp;
				TextParam tp;

				tsp.mode = TXT_BY_TILE_SIZE;
				tsp.size.width = dist;
				tsp.size.height = dist;

				tp.font = 0;
				tp.just = (TextElementJustification)0;
				tp.viewIndependent = 0;

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ???

				tp.lineStyle_deprecated = 0;

				//mdlRMatrix_fromNormalVector(&rm, &drelm.bel.sgts[0].rv[0].rvv.tdir);
				//mdlVec_fromRotMatrixRow(&pvec[0][0], &rm, 0);
				//mdlVec_fromRotMatrixRow(&pvec[0][1], &rm, 1);

				DEllipse3d ell[2];

				ell[0] = DEllipse3d::FromCenterNormalRadius(
					drelm.bel.sgts[0].rv[0].torg, 
					drelm.bel.sgts[0].rv[0].rvv.tdir, 
					dist);
				ell[1] = DEllipse3d::FromCenterNormalRadius(
					drelm.bel.sgts[0].rv[0].torg, 
					drelm.bel.sgts[0].rv[0].rvv.tdir, 
					distrif);

				output.DrawArc3d(ell[0], true, false, 0);
				output.DrawArc3d(ell[1], true, false, 0);

				//output.DrawArc3d(&drelm.bel.sgts[0].rv[0].torg, 0, &pvec[0][0], &pvec[0][1], dist, dist, 0, 0, false, 0);
				//output.DrawArc3d(&drelm.bel.sgts[0].rv[0].torg, 0, &pvec[0][0], &pvec[0][1], distrif, distrif, 0, 0, false, 0);

				//mdlRMatrix_fromNormalVector(&rm, &drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].rvv.tdir);
				//mdlVec_fromRotMatrixRow(&pvec[1][0], &rm, 0);
				//mdlVec_fromRotMatrixRow(&pvec[1][1], &rm, 1);

				ell[0] = DEllipse3d::FromCenterNormalRadius(
					drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].torg,
					drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].rvv.tdir,
					dist);
				ell[1] = DEllipse3d::FromCenterNormalRadius(
					drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].torg,
					drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].rvv.tdir,
					distrif);

				output.DrawArc3d(ell[0], true, false, 0);
				output.DrawArc3d(ell[1], true, false, 0);

				//output.DrawArc3d(&drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].torg, 0, &pvec[1][0], &pvec[1][1], dist, dist, 0, 0, false, 0);
				//output.DrawArc3d(&drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].torg, 0, &pvec[1][0], &pvec[1][1], distrif, distrif, 0, 0, false, 0);
#else

				tp.style = 0;

				mdlRMatrix_fromNormalVector(&rm, &drelm.bel.sgts[0].rv[0].rvv.tdir);

				mdlVec_fromRotMatrixRow(&pvec[0][0], &rm, 0);
				mdlVec_fromRotMatrixRow(&pvec[0][1], &rm, 1);

				output->DrawArc3d(&drelm.bel.sgts[0].rv[0].torg, 0, &pvec[0][0], &pvec[0][1], dist, dist, 0, 0, false, 0);
				output->DrawArc3d(&drelm.bel.sgts[0].rv[0].torg, 0, &pvec[0][0], &pvec[0][1], distrif, distrif, 0, 0, false, 0);

				mdlRMatrix_fromNormalVector(&rm, &drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].rvv.tdir);

				mdlVec_fromRotMatrixRow(&pvec[1][0], &rm, 0);
				mdlVec_fromRotMatrixRow(&pvec[1][1], &rm, 1);

				output->DrawArc3d(&drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].torg, 0, &pvec[1][0], &pvec[1][1], dist, dist, 0, 0, false, 0);
				output->DrawArc3d(&drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].torg, 0, &pvec[1][0], &pvec[1][1], distrif, distrif, 0, 0, false, 0);


#endif
				
				//mdlText_create(&elForTT, NULL, "ku", &drelm.bel.sgts[drelm.bel.numsgts - 1].rv[1].torg, &tsp, NULL, &tp, NULL);
				//Bentley::Ustn::Element::ElemHandle elh(&elForTT, ACTIVEMODEL);
				//context->VisitElemHandle(elh, false, false);

			}
		
		}
	
		*/

		//printf("   >>>>>>>>>>>  reinelm  tr=%.1f / %.1f", mdlElement_getTransparency(elp), dpP->m_transparency);
		//printf("     %.0f  %.0f  %.0f\n", drelm.bel.rpts[0].x, drelm.bel.rpts[0].y, drelm.bel.rpts[0].z);

		//OvrMatSymbP ovrMatSymb = context->GetOverrideMatSymb ();
		//ovrMatSymb->SetTransparentLineColor(50);
		//ovrMatSymb->SetTransparentFillColor(50);

		//output.ActivateOverrideMatSymb(ovrMatSymb);



		bool bX = ((bPlot && (arPlotCfgVar[REIN_PLOT_AUX_X] == 1 || (rirP->riropt[14] && arPlotCfgVar[REIN_PLOT_AUX_X] == 0))) || 
					(!bPlot && rirP->riropt[DISP_X])) && (reP->drwopt[DROPT_X] == FALSE);

		bool bO = ((bPlot && (arPlotCfgVar[REIN_PLOT_AUX_O] == 1 || (rirP->riropt[13] && arPlotCfgVar[REIN_PLOT_AUX_O] == 0))) || 
					(!bPlot && rirP->riropt[DISP_O])) && (reP->drwopt[DROPT_O] == FALSE);

		bool bS = ((bPlot && (arPlotCfgVar[REIN_PLOT_ELMSEC] == 1 || (rirP->riropt[11] && arPlotCfgVar[REIN_PLOT_ELMSEC] == 0))) || 
					(!bPlot && rirP->riropt[DISP_S])) && (reP->drwopt[DROPT_S] == FALSE);


		// обнуление mblap
		for (int i = 0; reP && i < drelm.bel.numsgts; i++)
		{
			reP->bel.sgts[i].rv[0].mblap = 0;
			reP->bel.sgts[i].rv[1].mblap = 0;
		}


		// расчет крестиков/ноликов
		//========================================
		for (int i = 0; !bRondo && i < drelm.bel.numsgts; i++)
		{

			// по идее надо бы проверять более тщательно,
			// но пока остановимся на этом варианте, так как 
			// практически нет случаев разного использвания опций FRONT_CLIP и BACK_CLIP
			if (mdlView_getDisplayControl(VIEWCONTROL_NO_FRONT_CLIP, view) &&
				mdlView_getDisplayControl(VIEWCONTROL_NO_BACK_CLIP, view)
				)
			{
				insideView[0][i] =  TRUE;
				insideView[1][i] =  TRUE;
			}
			else
			{
				// functions to repair
				insideView[0][i] = testIsPointInsideView2(&drelm.bel.sgts[i].rv[0].torg, context, &pViewNormZ);
				insideView[1][i] = testIsPointInsideView2(&drelm.bel.sgts[i].rv[1].torg, context, &pViewNormZ);
			}

			if (drelm.bel.sgts[i].bOutOfClip) 
			{
				insideView[0][i] = FALSE;
				insideView[1][i] = FALSE;
			}

			if (i > 0 && drelm.bel.sgts[i-1].bOutOfClip) 
			{
				insideView[0][i] = FALSE;
			}

			if (i < (drelm.bel.numsgts) && drelm.bel.sgts[i+1].bOutOfClip)
			{
				insideView[1][i] = FALSE;
			}

			//testVecInsideRefClip(

			//if (reP->bel.ffpos[REIN_ELEM_ISO] == 4000126)
			//	bFlag = TRUE;

			if (insideView[0][i])
			{
				if (drelm.bel.sgts[i].rv[0].isin 
					|| (drelm.bel.sgts[i].rv[0].mdiam[0] == REIN_TERM_BEND && rirP->riropt[8]))
				{
					int bGot = FALSE;

					double an = mdlVec_angleBetweenVectors(&pViewNormZ, &drelm.bel.sgts[i].rv[0].rvv.tnorm);

					viewPortP->RootToView(&pView, &drelm.tel.sgts[i].rv[0].torg, 1); // transformed
					
					//printf("0 - %i - %.2f  %.2f  %.2f\n", i, pView.x, pView.y, pView.z);

					if (reP) reP->bel.sgts[i].rv[0].dpth = pView.z;
					
					if (EQ(an, fc_pi))
					{
						arPtsX[iPtsCntX] = drelm.bel.sgts[i].rv[0].torg;
						arDepthX[iPtsCntX] = pView.z;
						iPtsCntX++;
						bGot = TRUE;
						if (reP) reP->bel.sgts[i].rv[0].mblap = REIN_TERM_TRMX;
					}
					else if (EQ(an, 0.))
					{
						arPtsO[iPtsCntO] = drelm.bel.sgts[i].rv[0].torg;
						arDepthO[iPtsCntO] = pView.z;
						iPtsCntO++;
						bGot = TRUE;
						if (reP) reP->bel.sgts[i].rv[0].mblap = REIN_TERM_TRMO;
					}

					if (bGot)
					{
						if (iPtsCntO <= 1 && iPtsCntX <= 1) 
							dDepth = pView.z;
						else
						{
							if (!EQ(dDepth, pView.z) && dDepth < pView.z) dDepth = pView.z;
						}
					}
				}
				else // крайняя точка
				{
					//DVec3d pCross;
					//RotMatrix rmX;

					//if (mdlVec_arePerpendicular(&pViewNormZ, &drelm.bel.sgts[i].rv[0].rvv.tdir))
					//{
					//	if (iBlock == BLOCK_NON) drawSegmEnd(elemIterP, context, &drelm, &pViewNormZ, pElmNormP, i, 0, bPlot);
					//}

				}
			}
		
			if (insideView[1][i])
			{
				if (drelm.bel.sgts[i].rv[1].isin 
					|| (drelm.bel.sgts[i].rv[1].mdiam[0] == REIN_TERM_BEND && rirP->riropt[8]))
				{
					int bGot = FALSE;

					double an = mdlVec_angleBetweenVectors(&pViewNormZ, &drelm.bel.sgts[i].rv[1].rvv.tnorm);

					viewPortP->RootToView(&pView, &drelm.tel.sgts[i].rv[1].torg, 1); // transformed
					
					//printf("1 - %i - %.2f  %.2f  %.2f\n", i, pView.x, pView.y, pView.z);

					if (reP) reP->bel.sgts[i].rv[1].dpth = pView.z;

					if (EQ(an, fc_pi))
					{
						arPtsX[iPtsCntX] = drelm.bel.sgts[i].rv[1].torg;
						arDepthX[iPtsCntX] = pView.z;
						iPtsCntX++;
						bGot = TRUE;
						if (reP) reP->bel.sgts[i].rv[1].mblap = REIN_TERM_TRMX;
					}
					else if (EQ(an, 0.))
					{
						arPtsO[iPtsCntO] = drelm.bel.sgts[i].rv[1].torg;
						arDepthO[iPtsCntO] = pView.z;
						iPtsCntO++;
						bGot = TRUE;
						if (reP) reP->bel.sgts[i].rv[1].mblap = REIN_TERM_TRMO;
					}

					if (bGot)
					{
						if (iPtsCntO <= 1 && iPtsCntX <= 1) 
							dDepth = pView.z;
						else
						{
							if (!EQ(dDepth, pView.z) && dDepth < pView.z) dDepth = pView.z;
						}
					}

				}
				else // крайняя точка
				{

					//DVec3d pCross;
					//RotMatrix rmX;

					//if (mdlVec_arePerpendicular(&pViewNormZ, &drelm.bel.sgts[i].rv[1].rvv.tdir))
					//{
					//	if (iBlock == BLOCK_NON) drawSegmEnd(elemIterP, context, &drelm, &pViewNormZ, pElmNormP, i, 1, bPlot);
					//}
				}
			}
		}

		// подгонка, чтобы не печаталось при разной глубине
		for (int i = 0; reP && i < drelm.bel.numsgts; i++)
		{
			if (!EQ(reP->bel.sgts[i].rv[0].dpth, dDepth)) reP->bel.sgts[i].rv[0].mblap = 0;
			if (!EQ(reP->bel.sgts[i].rv[1].dpth, dDepth)) reP->bel.sgts[i].rv[1].mblap = 0;
		}
		//========================================


					//if (drelm.bel.pnum == 126)
					//	int a = 0;


		// сечения
		//========================================
		if (bS && !bRondo && /*iPtsCntO == 0 && iPtsCntX == 0 &&*/
			(
				iBlock == BLOCK_NON
				//|| iBlock == BLOCK_INN // чтобы сечения внутренних стержней были всегда видны
				|| (iBlock == BLOCK_INN && rirP->riropt[17]) // чтобы сечения внутренних стержней были всегда видны
				)
			)
		{

			//ReferenceFileP rfP = mdlRefFile_getInfo(mrP);

			ReinModel* rmodP = curRM->getRM(mrP);

			if (rmodP)
			{
				/*
				// проверка плоскостей клипа, должны совпадать с clip boundary

				int res = mdlShape_create(&elForTT, 0, rmodP->arClipPts[0], rmodP->iClipVerts, 0);
				Bentley::Ustn::Element::ElemHandle elh1(&elForTT, ACTIVEMODEL);
				context->VisitElemHandle(elh1, false, false);
				//mdlElement_add(&elForTT);

				res = mdlShape_create(&elForTT, 0, rmodP->arClipPts[1], rmodP->iClipVerts, 0);
				Bentley::Ustn::Element::ElemHandle elh12(&elForTT, ACTIVEMODEL);
				context->VisitElemHandle(elh12, false, false);
				//mdlElement_add(&elForTT);
				*/

			}



			for (int i = 0; i < drelm.bel.numsgts; i++)
			{
				double ann[2];
				DVec3d pOrg;
				int bPerp = FALSE;
				drelm.bel.sgts[i].bSec = FALSE;
				if (reP) reP->bel.sgts[i].bSec = FALSE;

				//if (mdlVec_areParallel(&drelm.bel.sgts[i].rv[0].rvv.tdir, &pViewNormZ) && 
				//	mdlVec_areParallel(&drelm.bel.sgts[i].rv[1].rvv.tdir, &pViewNormZ)) bPerp = TRUE;

				ann[0] = mdlVec_angleBetweenVectors(&drelm.bel.sgts[i].rv[0].rvv.tdir, &pViewNormZ);
				ann[1] = mdlVec_angleBetweenVectors(&drelm.bel.sgts[i].rv[1].rvv.tdir, &pViewNormZ);

				if ((EQQ(ann[0], fc_pi, 0.001) || EQQ(ann[0], 0., 0.001)) &&
					(EQQ(ann[1], fc_pi, 0.001) || EQQ(ann[1], 0., 0.001)))
					bPerp = TRUE;

				//mdlRMatrix_fromNormalVector (&rm, &drelm.bel.sgts[i].rv[0].rvv.tdir);
				//mdlRMatrix_fromNormalVector (&rm, &pViewNormZ);
				//mdlRMatrix_toQuat (q, &rm);

				if (
						/// работа этого набора условий проверена, все условия необходимы и работают
						(insideView[0][i] == FALSE
							|| (drelm.bel.sgts[i].rv[0].isin == FALSE && drelm.bel.sgts[i].rv[0].mdiam[0] == 0)
						) &&
						(insideView[1][i] == FALSE
							|| (drelm.bel.sgts[i].rv[1].isin == FALSE && drelm.bel.sgts[i].rv[1].mdiam[0] == 0)
						)
						&& drelm.bel.sgts[i].bOutOfClip == FALSE // bOutOfClip проверенный параметр, не убирать
						&& (bPerp || rirP->riropt[12]) // ПЕРПЕНДИКУЛЯРНОСТЬ ВИДУ
					)
				{
					//double an[2];
					//an[0] = mdlVec_angleBetweenVectors(&pViewNormZ, &drelm.bel.sgts[i].rv[0].rvv.tdir);
					//an[1] = mdlVec_angleBetweenVectors(&pViewNormZ, &drelm.bel.sgts[i].rv[1].rvv.tdir);

					// точка сечения
					testActiveZPoint(rmodP, &drelm.bel.sgts[i], view, context, &pOrg, ann[0], 0.5, &pViewNormZ);
					// точки для текста позиции
					testActiveZPoint(rmodP, &drelm.bel.sgts[i], view, context, &drelm.bel.sgts[i].numpt, ann[0], 0.55, &pViewNormZ);
					testActiveZPoint(rmodP, &drelm.bel.sgts[i], view, context, &drelm.bel.sgts[i].numpt2, ann[0], 0.45, &pViewNormZ);


					//printf("%.0f,%.0f,%.0f\n", mdlCnv_uorsToMasterUnits(pOrg.x), mdlCnv_uorsToMasterUnits(pOrg.y), mdlCnv_uorsToMasterUnits(pOrg.z));

					//if (EQ(an[0], 0.) || EQ(an[0],fc_pi) || EQ(an[1],0.) || EQ(an[1],fc_pi))
					{
						ppp[0] = pViewNormY;
						ppp[1] = pViewNormX;

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ???
						DEllipse3d ell;
						ell = DEllipse3d::FromCenterNormalRadius(pOrg, pViewNormZ, dSecRad);
						output.DrawArc3d(ell, true, true, 0);
#else


						//if (drawPurpose == 5)
						//{
						//OvrMatSymbP ovrMatSymb = context->GetOverrideMatSymb();
						//ovrMatSymb->SetIndexedLineColor(viewPortP->GetHiliteColor(),0);
						//output->ActivateOverrideMatSymb(ovrMatSymb);
						//context->CookElemDisplayParams(*elemIterP);
						//}

						// SECTION
						output->DrawArc3d(&pOrg, 0, &ppp[0], &ppp[1], dSecRad, dSecRad, NULL, NULL, true, NULL);
						//printf("xy=%.0f,%.0f,%.0f   xy=%.0f,%.0f,%.0f\n", 
						//	mdlCnv_uorsToMasterUnits(pOrg.x),
						//	mdlCnv_uorsToMasterUnits(pOrg.y),
						//	mdlCnv_uorsToMasterUnits(pOrg.z),
						//	mdlCnv_uorsToMasterUnits(drelm.bel.sgts[i].numpt.x),
						//	mdlCnv_uorsToMasterUnits(drelm.bel.sgts[i].numpt.y),
						//	mdlCnv_uorsToMasterUnits(drelm.bel.sgts[i].numpt.z)
						//	);
#endif


						drelm.bel.sgts[i].pSec = pOrg;
						drelm.bel.sgts[i].bSec = TRUE;

						if (reP) reP->bel.sgts[i].pSec = pOrg;
						if (reP) reP->bel.sgts[i].bSec = TRUE;

					}
				}
			}


		}


		double dBarFace = dCfgVar_BarFace;
		if (rirP && rirP->bface > 0) dBarFace = rirP->bface;
		if (rmP && rmP->modelP) mdlCnv_masterToUOR(&dBarFace, dBarFace, rmP->modelP);

		//dBarFace /= rmP->refscale;


		// крестики
		//========================================
		for (int i = 0; !bRondo && i < iPtsCntX && iBlock == BLOCK_NON && bX; i++)
		{
			RotMatrix rmm;

			//mdlRMatrix_fromColumnVectors(&rmm, &pViewNormX, &pViewNormY, &pViewNormZ);
			mdlRMatrix_fromRowVectors(&rmm, &pViewNormX, &pViewNormY, &pViewNormZ);
			mdlRMatrix_invert(&rmm, &rmm);

			if (EQ(arDepthX[i], dDepth))
			{
				for (int b = 0; b < 2; b++)	mdlVec_zero(&ppp[b]);

				ppp[0].x -= dBarFace;
				ppp[0].y -= dBarFace;
				ppp[1].x += dBarFace;
				ppp[1].y += dBarFace;
				mdlRMatrix_multiplyPointArray(ppp, &rmm, 2);
				if (tmP) mdlRMatrix_multiplyPointArray(ppp, &rmTm, 2);
				mdlVec_addPointArray(ppp, &arPtsX[i], 2);
				
				PD(output)DrawLineString3d(2, ppp, NULL);


				for (int b = 0; b < 2; b++)	mdlVec_zero(&ppp[b]);

				ppp[0].x -= dBarFace;
				ppp[0].y += dBarFace;
				ppp[1].x += dBarFace;
				ppp[1].y -= dBarFace;
				mdlRMatrix_multiplyPointArray(ppp, &rmm, 2);
				if (tmP) mdlRMatrix_multiplyPointArray(ppp, &rmTm, 2);
				mdlVec_addPointArray(ppp, &arPtsX[i], 2);
				
				PD(output)DrawLineString3d(2, ppp, NULL);

			}
		}


		// нолики
		//========================================
		for (int i = 0; !bRondo && i < iPtsCntO && iBlock == BLOCK_NON && bO; i++)
		{
			if (EQ(arDepthO[i], dDepth))
			{
#if defined (MSVERSION) && (MSVERSION == 0xa00) // ???
				DEllipse3d ell;
				ell = DEllipse3d::FromCenterNormalRadius(arPtsO[i], pViewNormZ, dBarFace);
				output.DrawArc3d(ell, true, true, 0);
#else
				output->DrawArc3d(&arPtsO[i], NULL, &pViewNormY, &pViewNormX, dBarFace, dBarFace, NULL, NULL, true, NULL);
#endif
			}
		}



		// отрисовка окончаний
		//========================================

		for (int i = 0; !bRondo && i < drelm.bel.numsgts; i++)
		{
			if (drelm.bel.sgts[i].bOutOfClip == FALSE)
			{
				if (!drelm.bel.sgts[i].rv[0].isin
					//|| drelm.bel.sgts[i].rv[0].mpar & ( RFA_ENDC )
					)
				{
					if (iBlock == BLOCK_NON) 
					{
						int prm = drawSegmEnd(elemIterP, context, 0, &drelm, &pViewNormZ, pElmNormP, i, 0, bPlot, iDrwMode, rmP, rirP, dBarFace * 2.);
						if (reP) reP->bel.sgts[i].rv[0].mblap = prm;
					}
				}
			
				if (!drelm.bel.sgts[i].rv[1].isin
					//|| drelm.bel.sgts[i].rv[1].mpar & ( RFA_ENDC )
					)
				{
					if (iBlock == BLOCK_NON) 
					{
						int prm = drawSegmEnd(elemIterP, context, 0, &drelm, &pViewNormZ, pElmNormP, i, 1, bPlot, iDrwMode, rmP, rirP, dBarFace * 2.);
						if (reP) reP->bel.sgts[i].rv[1].mblap = prm;
					}
				}
			}
		}
		
		// или так
		// ===============
		//{
		//	int i = 0;

		//	if ((insideView[0][i] && !drelm.bel.sgts[i].rv[0].isin)
		//		|| drelm.bel.sgts[i].rv[0].mpar
		//		)
		//	{
		//		if (iBlock == BLOCK_NON) 
		//		{
		//			int prm = drawSegmEnd(elemIterP, context, &drelm, &pViewNormZ, pElmNormP, i, 0, bPlot, iDrwMode, refnum);
		//			if (reP) reP->bel.sgts[i].rv[0].mblap = prm;
		//		}
		//	}

		//	i = drelm.bel.numsgts - 1;

		//	if ((insideView[1][i] && !drelm.bel.sgts[i].rv[1].isin)
		//		|| drelm.bel.sgts[i].rv[1].mpar
		//		)
		//	{
		//		if (iBlock == BLOCK_NON) 
		//		{
		//			int prm = drawSegmEnd(elemIterP, context, &drelm, &pViewNormZ, pElmNormP, i, 1, bPlot, iDrwMode, refnum);
		//			if (reP) reP->bel.sgts[i].rv[1].mblap = prm;
		//		}
		//	}
		//}
		// ===============

		// номера позиции
		//========================================
		if (rirP->riropt[15] && iBlock == BLOCK_NON && !(bPlot && arPlotCfgVar[REIN_PLOT_POSNUM] == -1))
		{
			for (int i = 0; i < drelm.bel.numsgts; i++)
			{

				if (drelm.bel.pnum > 0 && drelm.bel.sgts[i].bOutOfClip == FALSE)
				{
					UInt32 clr = 0;
					UInt32* clrP = NULL;

					if (drelm.elemflags & REINEL_FLAG_CTCH)
					{
						clr = 3;
						clrP = &clr;
					}

					DVec3d pOrg;
					//mdlVec_interpolate(&pOrg, &drelm.bel.sgts[i].rv[0].torg, 0.1, &drelm.bel.sgts[i].rv[1].torg);
					//drawPosNum(drelm.bel.pnum, &pOrg, context);

					if (drelm.bel.sgts[i].sgmrad > 0)
					{
						//mdlElmdscr_pointAtDistance(&pOrg, 0, mdlCnv_masterUnitsToUors(drelm.bel.length) / 2., edp, 0);
						pOrg = drelm.bel.sgts[i].numpt;
					}
					else
					{
						mdlVec_interpolate(&pOrg, &drelm.bel.sgts[i].rv[0].torg, 0.5, &drelm.bel.sgts[i].rv[1].torg);
					}

					if (drelm.bel.sgts[i].bSec)
					{
						drawPosNum(drelm.bel.pnum, &drelm.bel.sgts[i].numpt, context, rmViewP, tmRefP, tmRefInvP, mrP, clrP);
						drawPosNum(drelm.bel.pnum, &drelm.bel.sgts[i].numpt2, context, rmViewP, tmRefP, tmRefInvP, mrP, clrP);
					}
					else
						drawPosNum(drelm.bel.pnum, &pOrg, context, rmViewP, tmRefP, tmRefInvP, mrP, clrP);

					//mdlVec_addPoint(&pOrg, &pOrg, &pViewNormZ);
					//mdlVec_subtractPoint(&pOrg, &pOrg, &pViewNormZ);

				}
			}
		}



		//int posn = 0;

		//if (posn > 0)
		//{
		//	TextStringCR ts;
		//	output.DrawTextString(..............
		//}

		//if (tmP) // for cell
		//{
		//	context->PopTransformClip(); // v8i - context->PopCoordSys();
		//}

		if (mdlModelRef_isActiveModel(mrP) == FALSE)
		{
			//Transform tmRef;
			//mdlTMatrix_referenceToMaster(&tmRef, mrP);
		}
		

		//if (edpAx) mdlElmdscr_freeAll(&edpAx);
		//if (edpAxTrns) mdlElmdscr_freeAll(&edpAxTrns);
		
	}
	else
	{
		//printf("\n", mdlElmdscr_getFilePos(edp), mdlElement_getType(elp), drawPurpose);
	}

	//if (edpRef) mdlElmdscr_freeAll(&edpRef);

	//writeLogOut(__FUNCTION__, 0); // drawReinElm




}


////////////////////////////////
void drawPosNum(int pnum, DVec3d* pOrgP, VCNTXP context, RotMatrixCP rmP, Transform* tmP, Transform* tmRevP, DgnModelRefP mrP, UInt32* clrP)
{
	WCH spos[10];
	TextSizeParam tsp;
	double dist = dCfgVar_PosNumSize;

	if (pnum <= 0) return;

	tsp.mode = TXT_BY_TILE_SIZE;
	tsp.size.width = dist * 0.8;
	tsp.size.height = dist;

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	TextParamWide tp;
	tp.Initialize();
#else
	TextParam tp;
#endif
	UInt32 bc = 255;

	tp.font = 1;
	tp.just = (TextElementJustification)7;
	//tp.style = 0;
	tp.viewIndependent = 0;

	if (iModePosCatch)
		SPRN(spos, L("-%i-"), pnum);
	else
		SPRN(spos, L("%i"), pnum);

	RotMatrix rm = *rmP;


	if (tmP)
	{
		RotMatrix rmm;
		mdlRMatrix_fromTMatrix(&rm, tmP);
		mdlRMatrix_normalize(&rm, &rm); // scale ok
		mdlRMatrix_getInverse(&rmm, (RotMatrix*)rmP);
		mdlRMatrix_multiply(&rm, &rm, &rmm);
	}
	else
		mdlRMatrix_getInverse(&rm, (RotMatrix*)rmP);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	mdlText_create(&elExt[0], &c3w9s0, spos, pOrgP, &rm, &tsp, &tp, NULL, ACTIVEMODEL);
	mdlText_create(&elExt[1], &c0w1s0, spos, pOrgP, &rm, &tsp, &tp, NULL, ACTIVEMODEL);
#else
	mdlText_create(&elExt[0], &c3w9s0, spos, pOrgP, &tsp, &rm, &tp, NULL);
	mdlText_create(&elExt[1], &c0w1s0, spos, pOrgP, &tsp, &rm, &tp, NULL);
#endif

	mdlElement_setTransparency(&elExt[0], 0.0);
	mdlElement_setTransparency(&elExt[1], 0.0);

	mdlElement_setSymbology(&elExt[0], &bc, 0, 0);
	if (clrP) mdlElement_setSymbology(&elExt[1], clrP, 0, 0);

	ELH elh1(&elExt[0], ACTIVEMODEL);
	context->VisitElemHandle(elh1, false, false);

	ELH elh2(&elExt[1], ACTIVEMODEL);
	context->VisitElemHandle(elh2, false, false);
}




////////////////////////////////
void drawPosNum_(int pnum, DVec3d* pOrgP, VCNTXP context, RotMatrixCP rmP, Transform* tmP, Transform* tmRevP, DgnModelRefP mrP)
{
	WCH spos[10];
	TextSizeParam tsp;
	double dist = dCfgVar_PosNumSize;

	//if (pnum == 5)
	//	__asm nop;

	//if (pnum == 1)
	//	__asm nop;

	//if (pnum <= 0) return;


	//int itc = mdlCurrTrans_getCount();

	DVec3d ptm = *pOrgP;
	DVec3d ptmRev = *pOrgP;
	mdlTMatrix_transformPoint(&ptmRev, tmRevP);

	//mdlVec_projectPointToPlane(&ptm, &ptm, &pZero, &pZ);
	mdlVec_projectPointToPlane(&ptmRev, &ptmRev, &pZero, &pZ);

	ptm = ptmRev;

	mdlTMatrix_transformPoint(&ptm, tmP);


	tsp.mode = TXT_BY_TILE_SIZE
		//| TXT_NO_TRANSFORM
		;
	tsp.size.width = dist * 0.8;
	tsp.size.height = dist;

	VIEWDRAW	output = context->GetIViewDraw();

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	TextParamWide tp;
	tp.Initialize();
#else
	TextParam tp;
#endif
	UInt32 bc = 255;

	tp.font = 1;
	tp.just = (TextElementJustification)7;
	//tp.just = (TextElementJustification)5;
	//tp.style = 0;
	tp.viewIndependent = 1;

	SPRN(spos, L("%i"), pnum);

	RotMatrix rm = *rmP;

	
	//if (tmP
	//	//&& mdlModelRef_is3D(ACTIVEMODEL)
	//	)
	//{
	//	RotMatrix rmm;
	//	mdlRMatrix_fromTMatrix(&rm, tmP);
	//	mdlRMatrix_normalize(&rm, &rm); // scale ok
	//	mdlRMatrix_getInverse(&rmm, (RotMatrix*)rmP);
	//	mdlRMatrix_multiply(&rm, &rm, &rmm);
	//}
	//else
	//	mdlRMatrix_getInverse(&rm, (RotMatrix*)rmP);

	DVec3d p = *pOrgP;

	//if (!mdlModelRef_is3D(ACTIVEMODEL))
	//	mdlRMatrix_fromTMatrix(&rm, tmP);


	//if (!mdlModelRef_is3D(ACTIVEMODEL))
	//{
	//	//mdlRMatrix_getIdentity(&rm);
	//	mdlRMatrix_fromView(&rm, 0, 1);
	//}


#if defined (MSVERSION) && (MSVERSION == 0xa00)
	mdlText_create(&elExt[0], &c3w9s0, spos, pOrgP, &rm, &tsp, &tp, NULL, ACTIVEMODEL);
	mdlText_create(&elExt[1], &c0w1s0, spos, pOrgP, &rm, &tsp, &tp, NULL, ACTIVEMODEL);
#else
	//p.z = 0.;
	//mdlText_create(&elExt[0], &c3w9s0, spos, &p, &tsp, 0, &tp, NULL);
	//mdlText_create(&elExt[1], &c0w1s0, spos, &p, &tsp, 0, &tp, NULL);
	mdlText_create(&elExt[0], &c3w9s0, spos, &ptm, &tsp, 0, &tp, NULL);
	mdlText_create(&elExt[1], &c0w1s0, spos, &ptm, &tsp, 0, &tp, NULL);

	elExt[1].text_2d.origin.x = ptm.x;
	elExt[1].text_2d.origin.y = ptm.y;

	//context->PopCoordSys();
	context->DrawElementRange(&elExt[1]);


	//output->DrawTextString(ts);

#endif

	//if (!mdlModelRef_is3D(ACTIVEMODEL))	mdlElement_transform(&elExt[0], &elExt[0], tmRevP);
	//if (!mdlModelRef_is3D(ACTIVEMODEL))	mdlElement_transform(&elExt[1], &elExt[1], tmRevP);

	mdlElement_setTransparency(&elExt[0], 0.0);
	mdlElement_setTransparency(&elExt[1], 0.0);

	mdlElement_setSymbology(&elExt[0], &bc, 0, 0);

	
	//if (!mdlModelRef_is3D(ACTIVEMODEL))
	//{
	//	MSElementDescr* edP = NULL;
	//	MSElementDescr* ed2P = NULL;
	//	mdlElmdscr_new(&edP, 0, &elExt[0]);
	//	mdlElmdscr_convertTo2D(&ed2P, edP, 0, tmRevP, mrP, ACTIVEMODEL, 0);
	//	//mdlElmdscr_convertTo3D(&ed2P, edP, 0, 0., tmRevP, mrP, ACTIVEMODEL);
	//	//mdlElmdscr_add(ed2P);
	//	ELH elh1(ed2P, false);
	//	context->VisitElemHandle(elh1, false, false);
	//	mdlElmdscr_freeAll(&edP);
	//	mdlElmdscr_freeAll(&ed2P);
	//}
	//else
	//{
	//	ELH elh1(&elExt[0], mrP);
	//	context->VisitElemHandle(elh1, false, false);
	//}
	


	if (!mdlModelRef_is3D(ACTIVEMODEL))
	{


		//context->PushActiveTransform(tmP);

		//RotMatrix rmm;
		//Transform tm;
		//mdlTMatrix_getIdentity(&tm);
		//mdlTMatrix_rotateByAngles(&tm, &tm, 0., 0., fc_piover2);
		//mdlRMatrix_fromTMatrix(&rmm, tmRevP);
		//mdlTMatrix_fromRMatrix(&tm, &rmm);
		//MSElementDescr* edP = NULL;
		//MSElementDescr* ed2P = NULL;


		//mdlText_getElementDescrWithModelRef(&edP, &elExt[1].text_2d, &rm, mrP);
		//mdlElmdscr_new(&edP, 0, &elExt[1]);
		// 
		//int res = mdlElmdscr_convertTo2D(&ed2P, edP, 0, tmRevP, mrP, ACTIVEMODEL, 0);
		//int res = mdlElmdscr_convertTo3D(&ed2P, edP, FIXEDDEPTH, 0., tmRevP, ACTIVEMODEL, mrP);
		//mdlElmdscr_add(ed2P);
		//mdlElmdscr_add(edP);

		//context->DrawElementRange(&elExt[1]);


		ELH elh1(&elExt[1], ACTIVEMODEL);
		//ELH elh1(ed2P, false);


		//context->PopCoordSys();
		//context->PopCoordSys();
		context->VisitElemHandle(elh1, false, false);

		//mdlElmdscr_freeAll(&edP);
		//mdlElmdscr_freeAll(&ed2P);
	}
	else
	{
		ELH elh1(&elExt[1], mrP);
		context->VisitElemHandle(elh1, false, false);
	}
}



/*
///////////////////////////////
bool checkPosExcl(int refn, int ind)
{
	for (int ii = 0; daCurPosExcl && ii < mdlDArray_nMembers(daCurPosExcl); ii++)
	{
		ReinExcl* rexP = (ReinExcl*)mdlDArray_getMemberP(daCurPosExcl, ii);

		if (rexP && rexP->ind == ind && rexP->ref == refn)
		{
			return true;
		}
	}
	return false;
}
*/



//////////////////////////////////////////////////////////////////////////
int createDim(MSElement* dim, DVec3d* points, int numps, int bAdd)
//(
//MSElement  *dim,	     /* <= Dimension element		       */
//DPoint3d     	*points,     /* => Line start and end points	       */
//int    	     	view,	     /* => View number for dim text orientation*/
//ULong	    	lineTag	     /* => Zero or tag (Unique ID) of line     */
//)
{

    RotMatrix    rMatrix;
    //AssocPoint   assocPoint;
    DimParamText dimText;
    DimParamTemplate dimTerm;
    //DimParamGeometry dimGeom;
    //DimParamMisc dimMisc;
    DVec3d     xVector, yVector, zVector, yPoint;
    double    	 height, margin;
	//DVec3d     	points[3];
	int view = tcb->lstvw;

	DVec3d dimpts[4];

	dimpts[0] = points[0];
	dimpts[1] = points[2]; // need to correct
	dimpts[2] = points[1];

    /*-------------------------------------------------------------------
    If lineTag IS NOT zero, it was set by writeBaseElement() and we need
    to create and insert associative points.
    If lineTag IS zero, there is no tag for associations and we need to
    insert standard points into the dimension.

    The required points for a size dimension are:
    0 - Base of first witness line
	1 - Base of second witness line
    -------------------------------------------------------------------*/

	//DgnDimStyleP        dimStyle ;
	//dimStyle = dgnDimStyle_getActiveFromModelRef ( ACTIVEMODEL ) ;

	//mdlDimStyle_setIntegerProp ( dimStyle, DIMSTYLE_VALUE_Terminator_Arrowhead_Open,
	//						   DIMSTYLE_PROP_Terminator_Arrowhead_INTEGER ) ;

	//points[0].x = 0.;
	//points[0].y = 0.;
	//points[0].z = 0.;

	//points[1].x = 0.;
	//points[1].y = 0.;
	//points[1].z = 50000.;

	//points[2].x = 0.;
	//points[2].y = 0.;
	//points[2].z = 100000.;

    if (mdlDim_create (dim, NULL, NULL, DIMTYPE_SIZE_ARROW, view))
		return (ERROR);


	for (int i = 0; i < numps; i++)
	{
		mdlDim_insertPoint (dim, dimpts + i,  NULL, -1, POINT_STD
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
			,ACTIVEMODEL
#endif
		);
	}



    /*-------------------------------------------------------------------
    We want the dimension to follow the line in a logical manner and we
    also want it to react properly to the DIMENSION AXIS (alignment)
    setting. So, rather than using the inverse of the view rotation matrix
    as the dimension rotation matrix, use mdlDim_defineRotMatrix(). To do
    this we need a third point, on the dimension Y axis (witness line).
    Use the two points of the line to define an X axis. Use the Z vector
    from the current view to define the Z axis. Then take the cross
    product of the Z and X to determine the Y axis. 
    -------------------------------------------------------------------*/
    mdlVec_computeNormal (&xVector, points + 1, points);
    mdlView_getParameters (NULL, NULL, NULL, &rMatrix, NULL, view);
    mdlRMatrix_getRowVector (&zVector, &rMatrix, 2);
    mdlVec_crossProduct (&yVector, &zVector, &xVector);

    /*-------------------------------------------------------------------
    Create a point on the dimension Y axis by projecting any distance
    out the Y vector defined above. Pass this point and the line points
    to mdlDim_defineRotMatrix. The proper rotation matrix is created and
    inserted into the dimension and a copy is returned in rMatrix;
    -------------------------------------------------------------------*/
    mdlVec_projectPoint (&yPoint, points, &yVector, fc_1);
    mdlDim_defineRotMatrix (&rMatrix, dim, points, &yPoint, points + 1);

    /*-------------------------------------------------------------------
    Now set the height so that the dimension does not interfere with the
    line. Make the shortest witness line at least three times the length
    of the dimension text height.
    -------------------------------------------------------------------*/
    mdlDim_getParam (&dimText, dim, DIMPARAM_TEXT);
    margin = dimText.height * 1.0;



    /*-------------------------------------------------------------------
    Find the distance along the dimension Y axis between the two end
    points of the line.	Use the distance + "margin" as the dimension height
    making sure that the minimum is "margin".
    -------------------------------------------------------------------*/
    mdlRMatrix_getColumnVector (&yVector, &rMatrix, 1);
    mdlVec_subtractPoint (&yPoint, points + 1, points);
    height = mdlVec_dotProduct (&yVector, &yPoint) + margin;
    if (height <= margin) height = margin;



	DimStrings          Dstr ;

#if defined (MSVERSION) && (MSVERSION == 0x8b0)
	strcpy ( Dstr.primary.single, " \0\0\0" ) ;
#else
	//ZeroMemory(&Dstr, sizeof(Dstr));
#endif

	for (int i = 0; i < numps-1; i++)
	{
		mdlDim_setStrings ( dim, i, &Dstr ) ;
	}



	mdlDim_getParam(&dimTerm, dim, DIMPARAM_TEMPLATE);
	//mdlDim_getParam(&dimGeom, dim, DIMPARAM_GEOMETRY);
	//mdlDim_getParam(&dimMisc, dim, DIMPARAM_MISC);

	/* 0-None,1-Arrow,2-Stroke,3-Circle,4-Dot   */
	dimTerm.firstTerm = 1;
	dimTerm.leftTerm = 1;
	dimTerm.rightTerm = 1;
	dimTerm.jointTerm = 4;

	//dimMisc.stacked = 0;

	//dimGeom.witExtend = 0.;
	//dimGeom.witOffset = 0.;
	//dimGeom.stackOffset = 0;

	mdlDim_setParam(dim, &dimTerm, DIMPARAM_TEMPLATE);
	//mdlDim_setParam(dim, &dimGeom, DIMPARAM_GEOMETRY);
	//mdlDim_setParam(dim, &dimMisc, DIMPARAM_MISC);


	//mdlDim_setExtensionLine (dim, 0, TRUE);
	//mdlDim_setExtensionLine (dim, 1, TRUE);
	//mdlDim_setExtensionLine (dim, 2, TRUE);


    mdlDim_setHeight (dim, 0., 0);


	mdlDim_validate (dim);


	if (bAdd)
	{
		mdlElement_setProperties(dim, &curNote.iNoteLevID, &curNote.iNoteGGN, NULL, NULL, NULL, NULL, NULL, NULL);

		MSElementDescr* edP = NULL;
		mdlElmdscr_new(&edP, 0, dim);
		xmlAddNoteInfo(&curNote, curNoteSet.sNoteUpFmt, &edP, 0);
		mdlElmdscr_add(edP);
		mdlElmdscr_freeAll(&edP);

		//mdlElement_add  (dim);
	}



	return SUCCESS;

}



////////////////////
void showLicense()
{

	WCH    v[50];
	if (getCfgVar(v, L("REIN_LICENSE_AGREED")) == SUCCESS)
		return;


	
/*

	//if (!rDopInfo.dopopt[15])
	{
		if (rfHandle)
		{
			MSDLGP db = mdlDialog_open(rfHandle, DLG_LICENSE);
			if (db)
			{
				mdlDialog_fontIndexSet(db, 1);
*/

				SCPY(ss, L("RHEIN - application for design\n"));
				SCAT(ss, L("               of concrete reinforcement\n"));
				SCAT(ss, L("Copyright(C) 2023  LEONID WIEBE\n"));
				SCAT(ss, L("mailto : wleo@ya.ru\n\n"));
				SCAT(ss, L("This program is free software:\n"));
				SCAT(ss, L("you can redistribute it and/or modify it\n"));
				SCAT(ss, L("under the terms of the GNU General\n"));
				SCAT(ss, L("Public License as published\n"));
				SCAT(ss, L("by the Free Software Foundation,\n"));
				SCAT(ss, L("either version 3 of the License,\n"));
				SCAT(ss, L("or (at your option) any later version.\n\n"));
				SCAT(ss, L("This program is distributed in\n"));
				SCAT(ss, L("the hope that it will be useful,\n"));
				SCAT(ss, L("but WITHOUT ANY WARRANTY;\n"));
				SCAT(ss, L("without even the implied warranty\n"));
				SCAT(ss, L("of MERCHANTABILITY or FITNESS\n"));
				SCAT(ss, L("FOR A PARTICULAR PURPOSE.\n"));
				SCAT(ss, L("See the GNU General Public License for more details.\n\n"));
				SCAT(ss, L("You should have received a copy\n"));
				SCAT(ss, L("of the GNU General Public License\n"));
				SCAT(ss, L("along with this program.\n"));
				SCAT(ss, L("If not, see https://www.gnu.org/licenses/."));
				SCAT(ss, L("\n\nIf you agree, press YES button."));

				int res = mdlDialog_openMessageBox(DIALOGID_MsgBoxYesNo, ss, MSGBOX_ICON_INFORMATION);

				if (res == ACTIONBUTTON_YES)
				{
					mdlSystem_defineCfgVar(L("REIN_LICENSE_AGREED"), L("1"), CFGVAR_LEVEL_USER);
					mdlSystem_rewriteCfgVarFile(0, L("REIN_LICENSE_AGREED"), L("1"));
				}
				else
				{
				}

/*

				DialogItem* diP = mdlDialog_itemGetByTypeAndId(db, RTYPE_Label, 1, 0);
				if (diP)
				{
					BINT bch;
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
					mdlDialog_rItemValueSet(&bch, 0, 0, ss, diP->rawItemP);
#else
					MSValueDescr vv;
					vv.GetWChar(curNoteSet.sNoteUpFmt, 100);
					mdlDialog_rItemValueSet(&bch, vv, diP->rawItemP);
#endif
				}
			}
		}
	}


*/





}


#if defined (STD_INTERFACE)


//////////////////////////////////
void hookToolBox(
		DialogMessage   *dmP	/* => a ptr to a dialog item message */
)
{

	writeLogIn(__FUNCTION__, 0);

    dmP->msgUnderstood = TRUE;
    switch (dmP->messageType)
	{

		case DIALOG_MESSAGE_CREATE: 
		{ 
			break; 
		} 
		case DIALOG_MESSAGE_UPDATE: 
		{ 
			break; 
		} 
		case DIALOG_MESSAGE_INIT:
        {
			WCH str[100];

			SPRN(str, L("Rhein v%u.%u"), VERSMID, VERSMIN);
			if (bNoLoad) SCAT(str, L(" (no data mode)"));
			if (iDebug) SCAT(str, L(" (debug)"));
			if (iBeta) SCAT(str, L(" (testing)"));

			//if (iCfgVar_BarCompare_3d > 0)
			mdlWindow_titleSet((MSWNDP)dmP->db, str);
			//else
			//	mdlWindow_titleSet((MSWNDP)dmP->db, L("Rein 2D"));

			toolBoxComboSync();

			break;
        }
		default:
			dmP->msgUnderstood = FALSE;
			break;
	}

	writeLogOut(__FUNCTION__, 0);

}

#endif

//////////////////////////////////
void hookAnkerDialog(
		DialogMessage   *dmP	/* => a ptr to a dialog item message */
)
{

    dmP->msgUnderstood = TRUE;
    switch (dmP->messageType)
	{

		case DIALOG_MESSAGE_CREATE: 
		{ 
			dmP->u.create.interests.updates = TRUE; 
			break; 
		} 
		case DIALOG_MESSAGE_UPDATE: 
		{ 
			//drawPreview(dmP->db);
			break; 
		} 
		case DIALOG_MESSAGE_INIT:
        {
			break;
        }
		default:
			dmP->msgUnderstood = FALSE;
			break;
	}

}

///////////////////////////////////
void enableItems(MSDLGP dbP, int rtype, BINT isEnabled, BINT bResetValue)
{
	if (dbP == NULL) dbP = findToolBox();

	if (dbP == NULL) return;

	int num = mdlDialog_itemsGetNumberOf(dbP);

	for (int i = 0; i < num; i++)
	{
		DialogItem* diP = mdlDialog_itemGetByIndex(dbP, i);

		if (mdlDialog_itemIsValid (diP))
		{
			if (diP->type == rtype)
			{
				//if (bResetValue) mdlDialog_set

				mdlDialog_itemSetEnabledState(dbP, diP->itemIndex, isEnabled, TRUE);
			}
		}
	}
}

//////////////////////////////////
void hookShowOptions(
		DialogMessage   *dmP	/* => a ptr to a dialog item message */
)
{

    dmP->msgUnderstood = TRUE;
    switch (dmP->messageType)
	{

		case DIALOG_MESSAGE_CREATE: 
		{ 
			break; 
		} 
		case DIALOG_MESSAGE_UPDATE: 
		{ 
			break; 
		} 
		case DIALOG_MESSAGE_INIT:
        {
			if (iCfgVar_EnableOptions == FALSE)
			{
				//rInfo.option[2] = 1;
				rInfo.option[4] = 1;
				rInfo.option[5] = 1;

				//mdlDialog_itemSetEnabledState(dmP->db, 1, FALSE, TRUE);
				mdlDialog_itemSetEnabledState(dmP->db, 2, FALSE, TRUE);
				mdlDialog_itemSetEnabledState(dmP->db, 3, FALSE, TRUE);
			}

			syncShowInfo();

			break;
        }
		default:
			dmP->msgUnderstood = FALSE;
			break;
	}

}

///////////////////////////////
void    hookListCellEditor
(
DialogItemMessage   *dimP
)
{
    dimP->msgUnderstood = TRUE;


    switch (dimP->messageType)
    {
		case DITEM_MESSAGE_CREATE:
        {
			if (curPos.bar.modrefP != ACTIVEMODEL)
			{
			}
			break;
        }

		case DITEM_MESSAGE_QUEUECOMMAND:
        {
			MSDLGP pDb;
            DialogItem      *pListBoxItem;
			int rowI, colI;

            if (NULL == (pDb = mdlDialog_find (DLG_POSLIST, NULL)))
                break;
            if (NULL == (pListBoxItem = mdlDialog_itemGetByTypeAndId (pDb, RTYPE_ListBox, 1, 0)))
                break;

			//mdlDialog_hookItemSendUserMsg (pListBoxItem->rawItemP, 0, 0);

			//if (reFoundP->rc.numRef == 0)
			//{
			//	reFoundP->rs.space = posList.pnum;

			//	reinSpaceElmdCreate(reFoundP->fpRS, MASTERFILE, &reFoundP->rs, FALSE);

			//	updateListBoxPos();

			//}

			if (ipnsave == curPos.bar.pnum) break;
				 

			ListModel* pModel = mdlDialog_listBoxGetListModelP (pListBoxItem->rawItemP);
			mdlDialog_listBoxGetEditCell (&rowI, &colI, pListBoxItem->rawItemP);
			ListCell*  pCell = mdlListModel_getCellAtIndexes (pModel, rowI, colI);

			long ind = myListCell_getInfoFieldInt32(pCell, 0, &gst);

			if (ipnsave == 0 && curPos.bar.pnum > 0) // обнуление позиции
			{
				deleteFilePosition(curPos.bar.pnum);
				
				ReinPos* rpP = curRM->getReinPosByNum(curPos.bar.pnum);
				//map<long, ReinPos>::iterator it = curRM->getPosMap().find(curPos.bar.pnum);
				if (rpP) // found
				{
					//if (curRM->getPosMap()[rp.bar.pnum].file_qty_p == 0) 
					rpP->bar.pnum = 0;
				}
				


				//if (curPosP) curPosP->bar.pnum = 0;
				mdlListCell_setDisplayText(pCell, L(""));
				mdlListCell_setDoubleValue(pCell, 0.);

				curRM->updateModelElmNumbers(true);
				
				break;
			}
			else if (ipnsave < 0)
			{
				curPos.bar.pnum = 0;
				mdlListCell_setDisplayText(pCell, L(""));
				Point2d pp;
				mdlWindow_pointToGlobal(&pp, (MSWNDP)dimP->db, &dimP->dialogItemP->rect.corner);
				mdlWindow_showBalloonTooltip(
					L("неправильный номер"),
					MESSAGE_WARNING,
					L(""), &pp, 0, 2000, FALSE, 0, 0, 0);
				break;
			}

			if (checkFilePosition(ipnsave))
			{
				if (curPos.bar.pnum == 0) 
					mdlListCell_setDisplayText(pCell, L(""));
				else
				{
					WCH v[20];
					SPRN(v, L("%i"), curPos.bar.pnum);
					mdlListCell_setDisplayText(pCell, v);
					mdlListCell_setDoubleValue(pCell, (double)curPos.bar.pnum);
				}

				Point2d pp;
				mdlWindow_pointToGlobal(&pp, (MSWNDP)dimP->db, &dimP->dialogItemP->rect.corner);
				mdlWindow_showBalloonTooltip(
					L("уже есть такая"),
					MESSAGE_WARNING,
					L(""), &pp, 0, 2000, FALSE, 0, 0, 0);
				break;
			}

			// ===== напроверялись, сохраняем... ======

			long oldposnum = curPos.bar.pnum;
			curPos.bar.pnum = ipnsave;

			if (savePosition(&curPos, FALSE, TRUE) == SUCCESS)
			{
				if (gst == SUCCESS)
				{
					curRM->getPosMap().erase(ind);
					/*
					map<long, ReinPos>::iterator it = curRM->getPosMap().find(ind);
					if (it != curRM->getPosMap().end()) // found
					{
						if (ind < 0) // удаляем непронумерованный элемент
							curRM->getPosMap().erase(ind);
						else if (ind > 0)
						{
							if (ind == oldposnum)
							{
								curRM->getPosMap().erase(ind);
							}
							//else
								// этого быть не может...?
						}
					}
					*/
				}

				if (ipnsave > 0 && oldposnum > 0) // обнуление позиции
					deleteFilePosition(oldposnum);

				WCH v[20];
				SPRN(v, L("%i"), curPos.bar.pnum);
				mdlListCell_setDisplayText(pCell, v);
				mdlListCell_setDoubleValue(pCell, (double)curPos.bar.pnum);
				mdlListCell_setInfoFieldInt32(pCell, 0, curPos.bar.pnum);

				curRM->getPosMap()[curPos.bar.pnum] = curPos;

				curRM->updateModelElmNumbers(true);
			}


        
			break;
        }

		default:
			dimP->msgUnderstood = FALSE;
			break;
    }
}

//////////////////////////////////
void hookAnkerButton(// NU
		DialogItemMessage   *dimP
)
{

    dimP->msgUnderstood = TRUE;

    switch (dimP->messageType)
	{
	case DITEM_MESSAGE_QUEUECOMMAND:
		{



			break;
		}
	default:
	    dimP->msgUnderstood = FALSE;
	    break;
	}

}

///////////////////////////////////////
int myDialog_itemSetValue(MSDLGP db, DialogItem* diP, long v)
{
	int res = ERROR;

	if (diP)
	{
#if defined (MSVERSION) && (MSVERSION == 0xa00) // dialog items
		int ft;
		bool vc;
		MSValueDescr  vu;
		res = mdlDialog_itemGetValue(vu, db, diP->itemIndex);
		vu.SetLong(v);
		if (res == SUCCESS) res = mdlDialog_itemSetValue(&vc, vu, db, diP->itemIndex);
		if (res == SUCCESS) mdlDialog_itemSetState(&vc, db, diP->itemIndex);
#else
		int ft;
		BoolInt vc;
		ValueUnion vu;
		res = mdlDialog_itemGetValue(&ft, &vu, 0, db, diP->itemIndex, 0);
		vu.sLongFormat = v;
		if (res == SUCCESS) res = mdlDialog_itemSetValue(&vc, ft, &vu, 0, db, diP->itemIndex);
		if (res == SUCCESS) mdlDialog_itemSetState(&vc, db, diP->itemIndex);
#endif
	}

	return res;

}

/////////////////////////////
void setToggleOn(MSDLGP dbP, int id)
{

	if (id > 500) id -= 500;

	DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, id, 0);

	//if (diP == NULL)
	//{
	//	id -= 300; // space2
	//	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, id, 0);
	//}

	myDialog_itemSetValue(dbP, diP, 1);

}

//////////////////////////////////
void hookModifyDialog(
		DialogItemMessage   *dimP
)
{

    dimP->msgUnderstood = TRUE;

	//printf("%i\n", dimP->messageType);

    switch (dimP->messageType)
	{
	case DITEM_MESSAGE_INIT:
	    {
			//printf("===========\n");
			//DialogItem* diP = NULL;
			//diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_Text, DLGITEM_TEXT_SPACE_2, 0);
			//if (diP)
			//{ // space2 серым цветом
			//	BSIColorDescr* clr = mdlWindow_systemColorGet(SYSCOLOR_WINDOWS_BTNFACE);
			//	mdlDialog_itemSetColor(dimP->db, diP->itemIndex, DITEM_COLORTYPE_BACKGROUND, clr);
			//}

			
			break;
		}
	case DITEM_MESSAGE_QUEUECOMMAND:
		{
			if (mdlDialog_itemGetType(dimP->dialogItemP) != RTYPE_OptionButton) break;
			setToggleOn(dimP->db, dimP->dialogItemP->id);
			break;
		}
	case DITEM_MESSAGE_POSTKEYSTROKE:
		{
			if (mdlDialog_itemGetType(dimP->dialogItemP) != RTYPE_Text) break;
			setToggleOn(dimP->db, dimP->dialogItemP->id);
			break;
		}
	default:
	    dimP->msgUnderstood = FALSE;
	    break;
	}

}


//////////////////////////////////
void hookAnkerChange(
		DialogItemMessage   *dimP
)
{

    dimP->msgUnderstood = TRUE;

    switch (dimP->messageType)
	{
	case DITEM_MESSAGE_INIT:
	    {
			//reinCalcAnker();
			break;
		}
	case DITEM_MESSAGE_QUEUECOMMAND:
		{
			//reinCalcAnker();
			mdlDialog_itemsSynch(dimP->db);
			break;
		}
	default:
	    dimP->msgUnderstood = FALSE;
	    break;
	}

}


/*
//////////////////////////////////
void hookLicenseButton(
		DialogItemMessage   *dimP
)
{
    dimP->msgUnderstood = TRUE;

    switch (dimP->messageType)
	{
	case DITEM_MESSAGE_CREATE:
	    {
			break;
	    }
	case DITEM_MESSAGE_BUTTON:
		{
			break;
		}
	default:
	    dimP->msgUnderstood = FALSE;
	    break;
        }

}
*/


//////////////////////////////////
void hookToggleDraw(
		DialogItemMessage   *dimP	/* => a ptr to a dialog item message */
)
{


    dimP->msgUnderstood = TRUE;


	//if (dimP->messageType == DITEM_MESSAGE_CREATE) mdlDialog_dmsgsPrint("DITEM_MESSAGE_CREATE");
	//if (dimP->messageType == DITEM_MESSAGE_INIT ) mdlDialog_dmsgsPrint("DITEM_MESSAGE_INIT");
	//if (dimP->messageType == DITEM_MESSAGE_DESTROY) mdlDialog_dmsgsPrint("DITEM_MESSAGE_DESTROY");
	//if (dimP->messageType == DITEM_MESSAGE_SYNCHRONIZE) mdlDialog_dmsgsPrint("DITEM_MESSAGE_SYNCHRONIZE");
	//if (dimP->messageType == DITEM_MESSAGE_FOCUSIN) mdlDialog_dmsgsPrint("DITEM_MESSAGE_FOCUSIN");
	//if (dimP->messageType == DITEM_MESSAGE_FOCUSOUT) mdlDialog_dmsgsPrint("DITEM_MESSAGE_FOCUSOUT");
	//if (dimP->messageType == DITEM_MESSAGE_KEYSTROKE) mdlDialog_dmsgsPrint("DITEM_MESSAGE_KEYSTROKE");
	//if (dimP->messageType == DITEM_MESSAGE_POSTKEYSTROKE) mdlDialog_dmsgsPrint("DITEM_MESSAGE_POSTKEYSTROKE");
	//if (dimP->messageType == DITEM_MESSAGE_GETSTATE) mdlDialog_dmsgsPrint("DITEM_MESSAGE_GETSTATE");
	//if (dimP->messageType == DITEM_MESSAGE_SETSTATE) mdlDialog_dmsgsPrint("DITEM_MESSAGE_SETSTATE");
	//if (dimP->messageType == DITEM_MESSAGE_STATECHANGED) mdlDialog_dmsgsPrint("DITEM_MESSAGE_STATECHANGED");
	//if (dimP->messageType == DITEM_MESSAGE_QUEUECOMMAND) mdlDialog_dmsgsPrint  ("DITEM_MESSAGE_QUEUECOMMAND");


//<< 21 DITEM_MESSAGE_GETSTATE
//<< 22 DITEM_MESSAGE_SYNCHRONIZE

//>> 23 DITEM_MESSAGE_SETSTATE
//>> 24 DITEM_MESSAGE_QUEUECOMMAND


	//if (dimP->dialogItemP->id == ICONCMDID_rein_iso)

    switch (dimP->messageType)
	{
	case DITEM_MESSAGE_INIT:
	    {
			break;
	    }
	case DITEM_MESSAGE_SETSTATE:
		{
			break;
		}
	case DITEM_MESSAGE_QUEUECOMMAND:
		{
			mdlDialog_itemSynchOthers(dimP->dialogItemP->rawItemP);
			break;
		}
	case DITEM_MESSAGE_SYNCHRONIZE:
		{
			break;
		}
	default:
	    dimP->msgUnderstood = FALSE;
	    break;
        }

}

/////////////////////////////////////////
// func: create space element
UInt32	reinSpaceElmdCreate(UInt32 fpos, DgnModelRefP mrP, ReinSpace* rsP, int bUpdateConfig, ReinElement* reP)
{

	UInt32 fp;
	ReinSpace rs;
	ReinSpace* rsLocP = &rs;;
	MSElementDescr* edp = NULL;

	rs.clear();

	if (rsP == NULL && reP == NULL)
	{
		rs.runmet = rInfo.rsVal.runmet;
		rs.diam = rInfo.rsVal.diam;
		//rs.space = rInfo.rsVal.space;
		rs.spacef = rInfo.rsVal.spacef;
		//rs.space2 = rInfo.rsVal.space2;
		rs.offset[0] = rInfo.rsVal.offset[0];
		rs.offset[1] = rInfo.rsVal.offset[1];
		rs.bendrad = rInfo.rsVal.bendrad;
		rs.poscalc = rInfo.rsVal.poscalc;
		rs.elemEDoffset = rInfo.rsVal.elemEDoffset;
		rs.segmIndex = rInfo.rsVal.segmIndex;
		//rs.cov[0] = rInfo.rsVal.cov[0];
		//rs.cov[1] = rInfo.rsVal.cov[1];
		//rs.cov[2] = rInfo.rsVal.cov[2];
		rs.lap[0] = rInfo.rsVal.lap[0];
		rs.lap[1] = rInfo.rsVal.lap[1];
		rs.lap[2] = rInfo.rsVal.lap[2];
		rs.trm[0] = rInfo.rsVal.trm[0];
		rs.trm[1] = rInfo.rsVal.trm[1];
		rs.trmPar = rInfo.rsVal.trmPar;
		//rs.trmPar[0][0] = rInfo.rsVal.trmPar[0][0];
		//rs.trmPar[0][1] = rInfo.rsVal.trmPar[0][1];
		//rs.trmPar[1][0] = rInfo.rsVal.trmPar[1][0];
		//rs.trmPar[1][1] = rInfo.rsVal.trmPar[1][1];
		//rs.trmPar[2][0] = rInfo.rsVal.trmPar[2][0];
		//rs.trmPar[2][1] = rInfo.rsVal.trmPar[2][1];

		rs.pts_org_cnt = rInfo.rsVal.pts_org_cnt;
		for (int i = 0; i < rs.pts_org_cnt; i++) rs.pts_org[i] = rInfo.rsVal.pts_org[i];

		rs.pts_end_cnt = rInfo.rsVal.pts_end_cnt;
		for (int i = 0; i < rs.pts_end_cnt; i++) rs.pts_end[i] = rInfo.rsVal.pts_end[i];
	}
	else if (rsP && reP == NULL)
	{
		rs = *rsP;
	}
	else if (reP)
	{
		rsLocP = &reP->rs;
	}
	else
		return 0;


	if (fpos == 0) 
		mdlShape_create(&el, &c0w0s0, ptsShape, 4, 0);


	if (fpos > 0)
		fp = mdlElmdscr_read(&edp, fpos, mrP, 0, 0);
	else
		mdlElmdscr_new(&edp, NULL, &el);

	if (reP == NULL) reP = &rrelem; // only for bar overrides

	fp = createReinSpaceElement(&edp, rsLocP, fpos, mrP, bUpdateConfig, TRUE, reP);

	rrelem.mapOvers.clear(); // global element clear;

	mdlElmdscr_freeAll(&edp);

    return fp;
}

/*
//////////////////////////////////////////////////////
int iterateDisplayReinMains( // NU
MSElementDescr  *edP,
void            *args,
ScanCriteria    *pScanCriteria
)
{

	ReinSpace rs;
	ReinBar rb;
	//ReinBar* rbP;

	ELID elid = 0;
	BINT bVisible = TRUE;
	BINT bModify = FALSE;
	int iType = 0;

	ELID* ar = (ELID*)args;


	if (args != NULL) 
	{
		elid = ar[0];
		iType = (int)ar[1];
		bVisible = (BINT)ar[2];
	}

	if ((iType == 0 || iType == REIN_MAIN_SPACE) && readReinSpaceFromElmd(&rs, edP, FALSE) == SUCCESS)
	{
		if (elid == 0)
		{
			bModify = TRUE;
		}
		else
		{
			if (elid == mdlElement_getID(&edP->el)) bModify = TRUE;
		}

	}
	else if ((iType == 0 || iType == REIN_MAIN_BAR) && readReinBarFromElement(&rb, edP, TRUE) == SUCCESS)
	{
		if (elid == 0)
		{
			bModify = TRUE;
		}
		else
		{
			if (elid == mdlElement_getID(&edP->el)) bModify = TRUE;
		}
	}


	BRYS = TRUE; // чтобы не отрабатывал событие
	if (bModify) 
	{
		
		if (!bVisible)
			mdlElmdscr_display(edP, edP->h.dgnModelRef, DRAW_MODE_Erase);

		mdlElmdscr_setVisible(edP, bVisible);
		mdlElmdscr_rewrite(edP, edP, mdlElmdscr_getFilePos(edP));

		if (bVisible)
			mdlElmdscr_displayInSelectedViews(edP, edP->h.dgnModelRef, DRAW_MODE_Normal, reinGetLevelMask(edP, 0, 0));
	}
	BRYS = FALSE;

	return SUCCESS;

}
*/
///////////////////////////////////
int iterateDeleteReinElms( // удаляет элементы ReinElm и ReinAxis - по id или все
MSElementDescr  *edP,
void            *args,
ScanCriteria    *pScanCriteria
)
{

	ReinElm re;
	ReinAxis ra;
	//ReinElm* reP;
	int res = -1;

	ELID elid = 0;


	ELID* ar = (ELID*)args;

	if (args != NULL) 
	{
		elid = ar[0];
	}

	
	writeLogIn(__FUNCTION__, 0);

	DgnModelRefP mrP = mdlScanCriteria_getModel(pScanCriteria);

	UInt32 fpos = mdlElmdscr_getFilePos(edP);
	//if (fpos == 4023042)
	//	int a = 0;

	if (elid == 0) // только для регенерации
	{
		//int ilck1 = 0;
		//int ilck2 = 0;
		//mdlElement_getLock(&ilck1, &ilck2, mdlScanCriteria_getModel(pScanCriteria), &edP->el);

		if (isLevelLocked(edP, mrP))
		{
			if (iDebug) sprintf(sLogMes, "element level is locked, returnung"); writeLog(0, 0);
			writeLogOut(__FUNCTION__, 0);
			return SUCCESS;
		}
	}


	if (re.getElmFromElement(&edP->el, mrP) == SUCCESS)
	{

		if (iDebug) sprintf(sLogMes, "getElmFromElement() SUCCESS, re.bel.elemid == %I64u, checking...\n", re.bel.elemid); writeLog(0, 0, 0, 1);

		if (elid == 0)
		{
			res = mdlElmdscr_undoableDelete(edP, fpos, TRUE);
			if (iDebug) sprintf(sLogMes, "deleting result = %i\n", res); writeLog(0, 0);
		}
		else if (elid > 0)
		{
			if (elid == re.bel.elemid)
			{
				res = mdlElmdscr_undoableDelete(edP, fpos, TRUE);
				if (iDebug) sprintf(sLogMes, "deleting result = %i\n", res); writeLog(0, 0);
			}
		}
	}

	if (readReinAxisFromElement(&ra, &edP->el) == SUCCESS)
	{

		if (iDebug) sprintf(sLogMes, "readReinAxisFromElement() SUCCESS, ra.eleid == %I64u, checking...\n", ra.eleid); writeLog(0, 0, 0, 1);

		if (elid == 0)
		{
			res = mdlElmdscr_undoableDelete(edP, fpos, TRUE);
			if (iDebug) sprintf(sLogMes, "deleting result = %i\n", res); writeLog(0, 0);
		}
		else if (elid > 0)
		{
			if (elid == ra.eleid)
			{
				res = mdlElmdscr_undoableDelete(edP, fpos, TRUE);
				if (iDebug) sprintf(sLogMes, "deleting result = %i\n", res); writeLog(0, 0);
			}
		}
	}

	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;


}


///////////////////////////////////
int scanAxisElem(
	MSElementDescr* edP,
	ReinPrm* prm,
	ScanCriteria* pScanCriteria
)
{

	//LEVID lid;
	//mdlElmdscr_getProperties(&lid, 0, 0, 0, 0, 0, 0, 0, edP);
	//if (!mdlLevel_isActive(lid)) return SUCCESS;

	UInt32 fp = mdlElmdscr_getFilePos(edP);
	UInt32 fpp = 0;
	DgnModelRefP mrP = mdlScanCriteria_getModel(pScanCriteria);

	ReinAxis ra;
	if (readReinAxisFromElement(&ra, &edP->el) == SUCCESS)
	{
		ELREF eref = getElemRefByID(mrP, ra.eleid);
		if (eref == NULL) // lost axis
		{
			if (prm->bDel)
			{
				if (mdlElmdscr_undoableDelete(edP, elementRef_getFilePos(edP->h.elementRef), FALSE) == SUCCESS)
					prm->cnt[0]++; // lost axes deleted
			}
			else
			{
				func_amp(mdlElmdscr_setProperties, edP), & prm->lev, 0, 0, 0, 0, 0, 0, 0);

				mdlElmdscr_setVisible(edP, TRUE);
				fpp = mdlElmdscr_rewriteByModelRef(edP, NULL, fp, mrP);

				if (fpp && fpp == fp) 
					prm->cnt[1]++; // rewrite not changed size
				else if (fpp)
					prm->cnt[2]++; // rewrite changed size
				else
					prm->cnt[3]++; // error rewrite
			}
		}
		else // norm axis
		{
			if (elementRef_isElementDeleted(eref))
				prm->cnt[4]++; // norm axis deleted
			else
				prm->cnt[5]++; // norm axis
		}

		prm->cnt[6]++; // common axes
	}

	prm->cnt[7]++; // common elements


	//printf(".", enumCount);

	return SUCCESS;
}

//////////////////////////////////////////////////
void combAxisElem(BINT bDelete)
{

	ScanCriteria* scP;
	int             status;

	ReinPrm prm;

	prm.bDel = bDelete;

	if (prm.bDel == FALSE)
	{
		prm.lev = getOrCreateLevel(ACTIVEMODEL, L"_Lost_elements", false);

		if (prm.lev == LEVEL_NULL_ID)
		{
			mdlDialog_dmsgsPrint(L("cannot create/find lost elements level"));
			return;
		}

		mdlDialog_dmsgsPrint(L("======== scan for move to level ... ==========="));
	}
	else
		mdlDialog_dmsgsPrint(L("======== scan to delete ... ==========="));


	scP = mdlScanCriteria_create();
	//status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	//status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanAxisElem, &prm);
	//status = mdlScanCriteria_setDrawnElements(scP);
	//mdlScanCriteria_setElementCategory(scP, ELEMENT_CATEGORY_GRAPHICS);
	mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinAxis);
	//status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
	//status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
	status = mdlScanCriteria_scanAllModelsOfFile(scP, 
		(PFScanElemDscrCallback)scanAxisElem, &prm, ELEMENT_CATEGORY_GRAPHICS, mdlModelRef_getDgnFile(ACTIVEMODEL));
	status = mdlScanCriteria_free(scP);

	mdlDialog_dmsgsPrint(L("================================"));

	SPRN(s, L(" %u lost axes deleted"), prm.cnt[0]);
	mdlDialog_dmsgsPrint(s);

	SPRN(s, L(" %u lost axes rewrite not changed size"), prm.cnt[1]);
	mdlDialog_dmsgsPrint(s);

	SPRN(s, L(" %u lost axes rewrite changed size"), prm.cnt[2]);
	mdlDialog_dmsgsPrint(s);

	SPRN(s, L(" %u lost axes error rewrite"), prm.cnt[3]);
	mdlDialog_dmsgsPrint(s);

	SPRN(s, L(" %u found norm axes deleted"), prm.cnt[4]);
	mdlDialog_dmsgsPrint(s);

	SPRN(s, L(" %u found norm axes"), prm.cnt[5]);
	mdlDialog_dmsgsPrint(s);

	SPRN(s, L(" %u common axes"), prm.cnt[6]);
	mdlDialog_dmsgsPrint(s);

	SPRN(s, L(" %u common elements"), prm.cnt[7]);
	mdlDialog_dmsgsPrint(s);

}




///<summary>
/// запуск скана на удаление производных элементов.
/// <para>удаляются типы appTypeReinAxis, appTypeReinElm</para>
/// 
/// <param name="ELID id"></param>
/// <param name="int bBrys"/>
/// <param name="ScanRange* srP"/>
/// <param name="DgnModelRefP mrInP"/>
///</summary>
void deleteReinElms(ELID id, int bBrys, ScanRange* srP, DgnModelRefP mrInP)
{
	// 
	ScanCriteria    *scP;
	int             status;
	//UShort          typeMask[6];
	ELID ids[2];
	ScanRange sr;
	DVec3d prng[2];

	DgnModelRefP mrP = ACTIVEMODEL;

	if (mrInP) mrP = mrInP;
	
	writeLogIn(__FUNCTION__, 0);

	if (bBrys) BRYS = TRUE;

	ids[0] = id;
	//ids[1] = ...;

	//for (UShort a = 0; a < 6; a++) typeMask[a] = 0;

 //   typeMask[0] = TMSK0_LINE | 
	//				TMSK0_ARC | 
	//				TMSK0_CELL_HEADER |
	//				TMSK0_LINE_STRING | 
	//				TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;

	bScanInProgress = TRUE;

	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)iterateDeleteReinElms, ids);
	//status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
	status = mdlScanCriteria_setDrawnElements(scP);
	mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinAxis);
	if (srP) status = mdlScanCriteria_setRangeTest(scP, srP); // супер
	status = mdlScanCriteria_setModel (scP, mrP);
	status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
	status = mdlScanCriteria_free (scP);

	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)iterateDeleteReinElms, ids);
	//status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
	status = mdlScanCriteria_setDrawnElements(scP);
	mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);
	if (srP) status = mdlScanCriteria_setRangeTest(scP, srP); // супер
	status = mdlScanCriteria_setModel (scP, mrP);
	status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
	status = mdlScanCriteria_free (scP);

	bScanInProgress = FALSE;


	if (bBrys) BRYS = FALSE;

	
	writeLogOut(__FUNCTION__, 0);



}


////////////////////////////////////////////////////////////
//int readReinElmFromElement(ReinElm* reP, MSElementCP elP, DgnModelRefP mrP)
//{
//
//}

////////////////////////////////////////////////////////
int checkDaArrayPoints(vector<BarPoint> &daPoints, vector<BarPoint> &daClipPoints, ReinBar* rbP)
{

	for(int i = 0; i < rbP->numpts; i++)
	{
		int bFound = FALSE;

		for (vector<BarPoint>::iterator bpP = daPoints.begin(); bpP != daPoints.end(); ++bpP)
		//for(int ii = 0; ii < daPoints.size(); ii++)
		{
			//BarPoint* bpP = &daPoints[ii];

			if (rbP->rfa[i] & RFA_ARCP)
			{
				if (pointIsEqual(&rbP->cents[i], &bpP->pArcCent, 0))
				{
					bFound = TRUE;
					bpP->flg |= RFA_TELP;
					if (i == 0) bpP->flg |= RFA_ENDP;
					if (i == rbP->numpts-1) bpP->flg |= RFA_ENDP;
					break;
				}
			}
			else
			{
				//printf("%i %.0f %.0f %.0f    %.0f %.0f %.0f\n", i, rbP->rpts[i].x, rbP->rpts[i].y, rbP->rpts[i].z, bpP->pVrtx.x, bpP->pVrtx.y, bpP->pVrtx.z);

				if (pointIsEqual(&rbP->rpts[i], &bpP->pVrtx, 0))
				{
					bFound = TRUE;
					bpP->flg |= RFA_TELP;
					if (i == 0) bpP->flg |= RFA_ENDP;
					if (i == rbP->numpts-1) bpP->flg |= RFA_ENDP;
					break;
				}
			}

		}

		if (bFound == FALSE)
		{
			BarPoint bp;
			bp.clear();
			bp.pVrtx = rbP->rpts[i];
			bp.flg = RFA_TELP;
			bp.flg |= RFA_ENDC;
			daClipPoints.push_back(bp);
		}
	}

	return SUCCESS;
}

////////////////////////////////////////////////////////////
int readReinElmIso(ReinElm* reP, MSElementDescr* edP, int bLoadAxis, int bUpdVecs)
{
	return readReinElmIso(reP, edP, bLoadAxis, bUpdVecs, edP->h.dgnModelRef);
}


////////////////////////////////////////////////////////////
//func read ReinElm From Elmd - чтение из элемента только типа REIN_ELEM_ISO
int readReinElmIso(ReinElm* reP, MSElementDescr* edP, int bLoadAxis, int bUpdVecs, DgnModelRefP mrP)
{
	XMLFragmentListP  oXMLFragmentList = NULL;
	int ret = SUCCESS;
	int view = 0;
	int clip_strange = FALSE;
	//DVec3d pEdges[MAX_BAR_VERTICES];
	Transform* tmRefP = NULL;
	Transform tmRef;


	if (reP == NULL) return ERROR;
	if (edP == NULL) return ERROR;

	writeLogIn(__FUNCTION__, 0);

	bool bbb = false;

	//File = 14, Pos = 
	//if (mdlElmdscr_getFilePos(edP) == 4088402)
	//	bbb = true;

	//printf("%u\n", mdlElmdscr_getFilePos(edP));

	ret = reP->getElmFromElement(&edP->el, mrP);

	//if (mdlElement_getID(&edP->el) == 111)
	//	int a = 0;

	reP->bel.modrefP = mrP;
	reP->bel.numRef = getRefNum(mrP);
	reP->bel.ffpos[reP->type] = mdlElmdscr_getFilePos(edP);

	if (ret != SUCCESS || reP->type != REIN_ELEM_ISO)
	{
		writeLogOut(__FUNCTION__, 0);
		return ret;
	}


	ReinModel* rmP = curRM->getRM(mrP);
	if (rmP == NULL) rmP = curRM;

	if (iDebug) sprintf(sLogMes, "mdlMeasure_linearProperties\n"); writeLog(0, 0);

	int res = mdlMeasure_linearProperties(&reP->bel.length, 0, 0, 0, 0, 0, 0, 0, edP, -1);
	mdlCnv_UORToMaster(&reP->bel.length, reP->bel.length, mrP);
	//printf("%f|%u", reP->bel.length, mdlElmdscr_getFilePos(edP));

	if (iDebug) sprintf(sLogMes, "FILEPOS = %u, REFNUM = %u, LENGTH = %.0f\n", reP->bel.ffpos[REIN_ELEM_ISO], reP->bel.numRef, reP->bel.length); writeLog(0, 0, 0, 1);

	//printf("%u\n", reP->bel.ffpos[REIN_ELEM_ISO]);

	double dScale = 1.;
	double* dScaleP = NULL;

	if (mdlModelRef_isActiveModel(mrP) == FALSE)
	{
		mdlTMatrix_masterToReference(&tmRef, mrP);
		tmRefP = &tmRef;

		RotMatrix rm;
		mdlRMatrix_fromTMatrix(&rm, &tmRef);

		// return TRUE if the matrix is constructed of rotation and uniform scale. FALSE if non-uniform scale.
		if (mdlRMatrix_isXRotationYRotationZRotationScale(&rm, 0, 0, 0, &dScale) == FALSE)
		{
			mdlRefFile_getDoubleParameters (&dScale, REFERENCE_SCALE, mrP);
			dScale = 1. / dScale;
		}

		if (!EQ(dScale, 1.))
		{
			dScaleP = &dScale;
		}
	}
	
	MSElementDescr* edpAx = NULL;

	if (bLoadAxis)
	{
		if (reP->bel.axid > 0)
		{
			ELREF eref = getElemRefByID(mrP, reP->bel.axid);

			if (eref)
			{
				int t = elementRef_getElemType(eref);

				if (!(t == LINE_ELM
					|| t == LINE_STRING_ELM
					|| t == ARC_ELM
					|| t == ELLIPSE_ELM
					|| t == SHAPE_ELM // ???
					|| t == CMPLX_STRING_ELM
					|| t == CMPLX_SHAPE_ELM
					))
				{
					_swprintf(wss, L"axis id = %I64u has element type = %i", reP->bel.axid, t);
					mdlOutput_messageCenterW(MESSAGE_ERROR, wss, wss, MESSAGE_ALERT_NONE);
				}


				UInt32 fp = elementRef_getFilePos(eref);
				//mdlElmdscr_read(&edpAx, fp, mrP, FALSE, 0);
				mdlElmdscr_readToMaster(&edpAx, fp, mrP, FALSE, 0);

				if (edpAx) 
				{
					mdlElmdscr_setVisible(edpAx, TRUE); // иначе не берет _mdlClip_element

					//==================================
					getComlexBarPoints(edpAx, &reP->bel, 
						TRUE, // обнулить
						NULL, FALSE, TRUE);

					reP->bel.checkBarPoints(FALSE);
					//==================================
				}
				else ret = ERROR;
			}
			else ret = ERROR;
		}
		else ret = ERROR;
	}

	if (ret != SUCCESS)
	{
		writeLogOut(__FUNCTION__, 0);
		return ret;
	}

	if (!bLoadAxis && ret == SUCCESS)
	{
		writeLogOut(__FUNCTION__, 0);
		return ret;
	}


	int ikos = FALSE;
	getSegms(edP, &reP->bel, &ikos);

	if (ikos) 
		reP->elemflags |= REINEL_FLAG_FKOS;


	if (reP->bel.mainPtsIndex >= reP->bel.numpts)  // иногда бывает так... почему - пока не понял
		reP->bel.mainPtsIndex = reP->bel.numpts - 1;


	for(int i = 0; i < reP->bel.numpts; i++)
	{
		// real point from axis element
		reP->bel.rfa[i] |= RFA_RELP;
		//reP->bel.vpt[i].rfa |= RFA_RELP; // vpt only for first read

		// for start OR end point set visible clipped part
		if (i == 0 || i == reP->bel.numpts - 1)
		{
			reP->bel.rfa[i] |= RFA_ENDP;
			//reP->bel.vpt[i].rfa |= RFA_ENDP; // vpt only for first read
		}
	}

	// получили rpts/rfa, трансформаированные если референс, но не обрезанные

	//mdlLineString_create(&elTmp, NULL, reP->bel.rpts, reP->bel.numpts);
	//mdlElement_add(&elTmp);

	reP->bel.getDrawPoints(&reP->bel.v_enrm, dScaleP);

	// получили apts - точки для отрисовки на эскизе

	//====================
	//barCalcComparePoints(&reP->bel, TRUE, tmRefP); // опцию в аргументы!
	reP->bel.calcComparePoints(tmRefP, 0, dScaleP);
	reP->bel.calcComparePoints(tmRefP, 1, dScaleP);
	//====================

	// образующий
	ELREF eref = getElemRefByID(mrP, reP->bel.elemid);

	if (eref)
	{
		MSElementDescr* edpPrnt = NULL;

		mdlElmdscr_readToMaster(&edpPrnt, elementRef_getFilePos(eref), mrP, 0, 0);
		if (edpPrnt)
		{
			if (mdlElmdscr_extractNormal(&reP->bel.v_pnrm, 0, edpPrnt, &pZ) != SUCCESS)
				mdlVec_zero(&reP->bel.v_pnrm);
				//reP->bel.v_pnrm = pZ;

			mdlElmdscr_freeAll(&edpPrnt);
		}
	}
	//====================
	reP->tel = reP->bel;
	//====================

	if (edpAx && mdlModelRef_isActiveModel(mrP) == FALSE)
	{
		CLIPDESC clipP = NULL;
		MSElementDescr* edpClip = NULL;

		//int r = func_pma(mdlClip_getRefBoundary,clipP), mrP, view);
		int r = myClip_getRefBoundary(&clipP, mrP, &edpClip, view);

		BINT isOn = FALSE;
		mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, mrP);

		if (r == SUCCESS && NOTNULL(clipP))
		{
			MSElementDescr* edpClip1 = NULL;
			//MSElementDescr* edpClip2 = NULL;

			int rr = mdlClip_element(&edpClip1, 0, edpAx, mrP, GETPTR(clipP), view);

			// =================================================
			// Полученный edpAx - обрезанный клипом элемент оси
			// он может состоять из обрезанных кусков (линий),
			// которые разбросаны в пространстве, но принадлежат одному элементу edpAx
			// =================================================

			if (edpClip1 != NULL)
			{
				if (edpClip1 != edpAx) // edpClip1 dublicated from edpAx and clipped
				{
					edpAx = edpClip1;
					reP->iClip = 1; // обрезан клипом
				}
				else
					reP->iClip = 0; // полностью внутри

			}
			else
			{
				BINT over;
				BINT isin = mdlClip_isElemInside(&over, edpAx, GETPTR(clipP), 0, TRUE);

				if (isin)
				{
					if (over) reP->iClip = 1; else reP->iClip = 0; // over == 0 or 1
					reP->bClip = true; // clip is strange -> edpClip1 == NULL, but element is inside
				}
				else
					reP->iClip = -1; // outside
			}

			myClip_free(clipP, &edpClip);
		}


		//mdlElmdscr_add(edpAx);

		if (reP->iClip == 1 && reP->bClip == false)
		{
			// здесь numpts может меняться и далее отличаться от cnumpts

			vector<BarPoint> daPoints;
			vector<BarPoint> daClipPoints; // точки где клипом прерывается элемент
			
			//ArrayObjectHdr* daPoints = NULL;
			//ArrayObjectHdr* daClipPoints = NULL;
			//daPoints = mdlDArray_create (sizeof (ArrayObjectHdr), sizeof(BarPoint), 0, 0, 0); 
			//daClipPoints = mdlDArray_create (sizeof (ArrayObjectHdr), sizeof(BarPoint), 0, 0, 0); 

			for(int i = 0; i < reP->bel.numpts; i++)
			{
				BarPoint bp;
				bp.clear();
				bp.pVrtx = reP->bel.rpts[i];
				bp.flg = reP->bel.rfa[i];

				if (reP->bel.rfa[i] & RFA_ARCP)	
					bp.pArcCent = reP->bel.cents[i];

				daPoints.push_back(bp);
			}

			//==================================
			getComlexBarPoints(edpAx, &reP->tel, 
				TRUE, // обнулить
				NULL, FALSE, FALSE);

			reP->tel.checkBarPoints(FALSE);
			//==================================

			checkDaArrayPoints(daPoints, daClipPoints, &reP->tel);


			MSElementDescr*  edpNext = edpAx->h.next;
			while (edpNext != NULL) // обрезка получилась из нескольких частей
			{ 
				//=====================================
				getComlexBarPoints(edpNext, &reP->tel, 
					TRUE, // обнулить
					NULL, FALSE, FALSE);

				reP->tel.checkBarPoints(FALSE);
				//=====================================

				checkDaArrayPoints(daPoints, daClipPoints, &reP->tel);

				edpNext = edpNext->h.next;
			}

			//mdlLineString_create(&elTmp, NULL, reP->tel.rpts, reP->tel.numpts);
			//mdlElement_add(&elTmp);

			//==========================================
			// доводка daPoints => tel.rpts
			{
				for (vector<BarPoint>::iterator bpDopP = daClipPoints.begin(); bpDopP != daClipPoints.end(); ++bpDopP)
				//for(int ii = 0; ii < daClipPoints.size(); ii++)
				{
					int bLost = TRUE;
					//BarPoint* bpDopP = &daClipPoints[ii];

					for (vector<BarPoint>::iterator bpP_0 = daPoints.begin(); bpP_0 != daPoints.end(); ++bpP_0)
					//for(int i = 0; i < daPoints.size() - 1; i++) // -1 -> get two members
					{
						DVec3d vec[2];
						//BarPoint* bpP[3];
						//bpP[0] = &daPoints[i];
						//bpP[1] = &daPoints[i + 1];

						vector<BarPoint>::iterator bpP_1 = bpP_0;
						++bpP_1;
						if (bpP_1 == daPoints.end()) break;


						if (bpP_1->flg & RFA_ARCP || bpP_1->flg & RFA_CIRP) // арка / круг
						{
							//bpP[2] = &daPoints[i + 2]; не используется
							// или
							//vector<BarPoint>::iterator bpP_2 = bpP_1;
							//++bpP_2;
							//if (bpP_2 != daPoints.end())
							//{
							//}

							//DVec3d parc[3];
							//parc[0] = bpP[0]->pVrtx;
							//parc[1] = bpP[1]->pVrtx;
							//parc[2] = bpP[2]->pVrtx;
							//mdlArc_createByPoints(&elTmp, 0, parc);

							//double drad[2];
							//drad[0] = mdlVec_distance(&bpP[0]->pVrtx, &bpP[1]->pArcCent);
							//drad[1] = mdlVec_distance(&bpDopP->pVrtx, &bpP[1]->pArcCent);

							//if (EQQ(drad[0], drad[1], 0.01))
							{
								BarPoint b = *bpDopP;

								bLost = FALSE;
								//daPoints.push_back(b); // insert!
								daPoints.insert(bpP_1, b);
								//daPoints.insert(daPoints.begin() + i + 1, b);
								break;
							}
							//i++;
							++bpP_0; //  ?????? after insert
						}
						else
						{
							mdlVec_subtractPoint(&vec[0], &bpP_0->pVrtx, &bpDopP->pVrtx);
							mdlVec_subtractPoint(&vec[1], &bpP_1->pVrtx, &bpDopP->pVrtx);

							double ugol = mdlVec_angleBetweenVectors(&vec[0], &vec[1]);

							if (EQQ(ugol, fc_pi, 0.01))
							{
								BarPoint b = *bpDopP;

								bLost = FALSE;
								//daPoints.push_back(b); // insert!
								daPoints.insert(bpP_1, b);
								//daPoints.insert(daPoints.begin() + i + 1, b);
								break;
							}
						}
					}


					if (bLost)
					{

						ReinModel* rmmP = curRM->getRM(reP->bel.modrefP);

						deque<UInt32> aref;
						//UInt32 aref[MAX_REFNUM_PATH]; // обратный путь, для рефа 5->3->7 массив: [0] = 7, [1] = 3, [2] = 5
						rmmP->getRefPath(&aref);

						MSWCH  fpath[500] = L"";
						MSWCH  fName[300];

						for (deque<UInt32>::reverse_iterator it = aref.rbegin(); it != aref.rend(); ++it)
						//for (int i = refcnt - 1; i >= 0; i--)
						{
							_swprintf(fName, L"[%u]", *it);
							if (wcslen(fpath) > 0) wcscat(fpath, L"->");
							wcscat(fpath, fName);
						}

						_swprintf(fName, L"RHEIN error: lost point at element fp=%u ref=%s", reP->bel.ffpos[REIN_ELEM_ISO], fpath);
						if (daPoints.size() > 0)
						{
							_swprintf(fpath, L"xy=%.0f,%.0f,%.0f",
								mdlCnv_uorsToMasterUnits(daPoints.begin()->pVrtx.x),
								mdlCnv_uorsToMasterUnits(daPoints.begin()->pVrtx.y),
								mdlCnv_uorsToMasterUnits(daPoints.begin()->pVrtx.z)
							);
						}
						else
							wcscpy(fpath, fName);

						mdlOutput_messageCenterW(MESSAGE_ERROR, fName, fpath, MESSAGE_ALERT_NONE);

						MSElementDescr* edpAxErr = NULL;
						UInt32 clr = 3;
						UInt32 wgt = 10;
						mdlElmdscr_duplicate(&edpAxErr, edpAx);
						func_amp(mdlElmdscr_setSymbology, edpAxErr), &clr, 0, &wgt, 0);
						xmlAddCacheInfo(reP, &edpAxErr, fName, false, rmmP);
						TransDescrP tedP = mdlTransient_addElemDescr(NULL, edpAxErr, TRUE, 0x00ff, DRAW_MODE_Normal, 1, 0, 0);
					}
				}

				// точка на кружке сечения стержня для привязки
				// ================================================
				if (iCfgVar_SectionPoints
					&& isOn // для включенных референсов
					&& reP->tel.numpts == 2) // проверка - точка или нет
				{
					DVec3d pVec;
					DVec3d pViewNrm;
					RotMatrix rm;

					mdlVec_subtractPoint(&pVec, &reP->tel.rpts[0], &reP->tel.rpts[1]);

					mdlView_getParameters(NULL, NULL, NULL, &rm, NULL, 0);
					mdlRMatrix_getRowVector(&pViewNrm, &rm, 2);

					int bParr = mdlVec_areParallel(&pVec, &pViewNrm);

					if (bParr)
					{

						MSElementDescr* edpAxClip = NULL;
						//UInt32 clr = 3;
						//UInt32 wgt = 10;

						//mdlLine_create(&elTmp, &c3w9s0, reP->tel.rpts);

						//printf("xy=%.0f,%.0f,%.0f   xy=%.0f,%.0f,%.0f\n",
						//	mdlCnv_uorsToMasterUnits(reP->tel.rpts[0].x),
						//	mdlCnv_uorsToMasterUnits(reP->tel.rpts[0].y),
						//	mdlCnv_uorsToMasterUnits(reP->tel.rpts[0].z),
						//	mdlCnv_uorsToMasterUnits(reP->tel.rpts[1].x),
						//	mdlCnv_uorsToMasterUnits(reP->tel.rpts[1].y),
						//	mdlCnv_uorsToMasterUnits(reP->tel.rpts[1].z)
						//);



						MSElementDescr* edpNxt = edpAx;
						while (edpNxt != NULL) // обрезка получилась из нескольких частей
						{
							DVec3d ptmp[2];
							int nm = 0;

							//mdlElmdscr_duplicateSingle(&edpAxClip, edpNxt); на некторых элементах не срабатывает xmlAddCacheInfo

							if (mdlLinear_extract(ptmp, &nm, &edpNxt->el, mrP) == SUCCESS)
							{
								mdlLine_create(&elTmp, &c0w0s0, ptmp);

								mdlElmdscr_new(&edpAxClip, 0, &elTmp);

								//func_amp(mdlElmdscr_setSymbology, edpAxClip), & clr, 0, & wgt, 0);

								MSWCH str[100];
								_swprintf(str, L"#####%u", reP->bel.ffpos[REIN_ELEM_ISO]);

								xmlAddCacheInfo(reP, &edpAxClip, str, false, rmP);

								// добавление точки чтобы можно было привязываться к сечению на разрезе
								rmP->tedSecP = mdlTransient_addElemDescr(rmP->tedSecP, edpAxClip, TRUE, 0x00ff, DRAW_MODE_Normal, 1, 0, 0); // ПРИВЯЗКА К СЕЧЕНИЮ
								//mdlElmdscr_add(edpAxClip);

								mdlElmdscr_freeAll(&edpAxClip);

								//MSElementDescr* edp = NULL;
								//mdlTransient_returnElemDescr(&edp, tedP);
								//reP->tel.ffpos[REIN_ELEM_RND] = mdlElmdscr_getFilePos(edp);

								//reP->tel.ffpos[REIN_ELEM_RND] = elementRef_getFilePos(mdlTransient_getLastElementRef(tedP));
							}


							edpNxt = edpNxt->h.next;
						}



					}

				}
				// ================================================

				reP->tel.numpts = 0;
				//reP->tel.rpts.clear();
				//reP->tel.cents.clear();
				//reP->tel.rfa.clear();

				for (vector<BarPoint>::iterator bpP = daPoints.begin(); bpP != daPoints.end(); ++bpP)
				//for(int i = 0; i < daPoints.size(); i++)
				{
					//BarPoint* bpP = &daPoints[i];
					// 
					//reP->tel.rpts.push_back(bpP->pVrtx);
					//reP->tel.cents.push_back(bpP->pArcCent);
					//reP->tel.rfa.push_back(bpP->flg);
					reP->tel.rpts[reP->tel.numpts] = bpP->pVrtx;
					reP->tel.rfa[reP->tel.numpts] = bpP->flg;
					reP->tel.numpts++;
				}

				//reP->tel.numpts = daPoints.size();
			}
			//==========================================

			//mdlLineString_create(&elTmp, NULL, reP->tel.rpts, reP->tel.numpts);
			//mdlElement_add(&elTmp);

			// обратный трансформ - переводим координаты клипнутой оси в систему ее родного файла
			// ===========================
			reP->bel = reP->tel;
			mdlTMatrix_transformPointArray(reP->bel.rpts, &tmRef, reP->bel.numpts);
			//for (size_t i = 0; i < reP->bel.rpts.size(); i++)
			//{
			//	mdlTMatrix_transformPoint(&(reP->bel.rpts[i]), &tmRef);
			//}


			// ===========================

			daClipPoints.clear();
			daPoints.clear();

			// проверка
			//mdlLineString_create(&elTmp, NULL, reP->tel.rpts, reP->tel.numpts);
			//mdlElement_add(&elTmp);

		}
		else// if (reP->iClip == 0) // элемент полностью внутри клипа
		{
			mdlTMatrix_transformPointArray(reP->bel.rpts, &tmRef, reP->bel.numpts);
			//for (size_t i = 0; i < reP->bel.rpts.size(); i++)
			//{
			//	mdlTMatrix_transformPoint(&(reP->bel.rpts[i]), &tmRef);
			//}
		}
	}


	if (edpAx) mdlElmdscr_freeAll(&edpAx);

	if (bUpdVecs && reP->iClip != -1)
	{
		updateReinBarSegments(&reP->bel, reP->iClip);
		updateReinBarSegments(&reP->tel, reP->iClip);
	}

	writeLogOut(__FUNCTION__, 0);

	return ret;

}


////////////////////////////////////////////////////////////
int readReinAxisFromElement(ReinAxis* raP, MSElementCP elP)
{
	XMLFragmentListP  oXMLFragmentList = NULL;

	raP->clear();
	//ZeroMemory(raP, sizeof(ReinAxis));

	if (!mdlElement_hasXMLFragmentAttachment((MSElementP)elP, &appID, &appTypeReinAxis)) return ERROR;

	if (mdlXMLFragmentList_extractFromElementByAppIDAndType (&oXMLFragmentList, (MSElementP)elP,
				&appID, &appTypeReinAxis) == SUCCESS)
	{
		XMLFragmentP  pXMLFragment;
		MSWCH* wtxt;
		//char ctxt[500];
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);
			//mdlCnv_convertUnicodeToMultibyte(wtxt, -1, ctxt, 500);
			if (readReinAxisFromString(raP, wstr) != SUCCESS)
				return ERROR;
			mdlXMLFragmentList_free(&oXMLFragmentList);
		}
		else
			return ERROR;
	}
	else
		return ERROR;

	return SUCCESS;
}


////////////////////////////////////////////////////////////
//int readReinBarFromElement(ReinElement* relemP, MSElementDescrCP edpBar, int bClear)
//{
//	return readReinBarFromElement(&relemP, edpBar, bClear, TRUE, relemP);
//}

////////////////////////////////////////////////////////////
int readReinBarFromElement(ReinBar* rbP, MSElementDescrCP edpBar, int bClear)
{

	if (rbP == NULL) return ERROR;
	if (edpBar == NULL) return ERROR;

	writeLogIn(__FUNCTION__, 0); // readReinBarFromElement in

	//int iInstSuccess = ERROR;
	XMLFragmentListP  oXMLFragmentList = NULL;

	int ret = SUCCESS;

	if (bClear) rbP->clear();

	/*
	#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX
		DgnECInstancePtr insP = getECInstance(L"ReinSchema", L"ReinBar", edpBar);
		if (insP.IsValid())
		{
			iInstSuccess = readFromECInstance(rbP, insP);
		}
	#endif
	*/
	//if (iInstSuccess != SUCCESS)
	{

		try
		{
			//sprintf(sLogMes, "mdlElement_hasXMLFragmentAttachment(...)\n"); writeLog(0, 0);

			MSElementP elP = (MSElementP) & (edpBar->el);

			if (mdlElement_hasXMLFragmentAttachment(elP, &appID, &appTypeReinBar))
			{
				if (mdlXMLFragmentList_extractFromElementByAppIDAndType(&oXMLFragmentList, elP,
					&appID, &appTypeReinBar) == SUCCESS)
				{
					//sprintf(sLogMes, "mdlXMLFragmentList_extractFromElementByAppIDAndType success\n"); writeLog(0, 0);

					XMLFragmentP  pXMLFragment;
					MSWCH* wtxt;
					//WCH ctxt[500];
					pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

					if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
					{
						if (iDebug) sprintf(sLogMes, "xmlfragment text=\"%S\"\n", wtxt); writeLog(0, 0);

						//SCPW2M(ctxt, wtxt, 500);
						//sprintf(sLogMes, "mdlXMLFragmentList_free(...)\n"); writeLog(0, 0);

						//sprintf(sLogMes, "readReinBarFromString(...)\n"); writeLog(0, 0);

						wstring wstr(wtxt);

						if (readReinBarFromString(rbP, wstr) != SUCCESS)
							ret = ERROR;

						mdlXMLFragmentList_free(&oXMLFragmentList);
					}
					else
						ret = ERROR;

				}
				else
				{
					//sprintf(sLogMes, "mdlXMLFragmentList_extractFromElementByAppIDAndType error\n"); writeLog(0, 0);
					ret = ERROR;
				}
			}
			else
			{
				//sprintf(sLogMes, "mdlElement_hasXMLFragmentAttachment return false\n"); writeLog(0, 0);
				ret = ERROR;
			}
		}
		catch (int e)
		{
			//sprintf(sLogMes, "catched exception, e = %i\n", e); writeLog(0, 0);
			ret = e;
		}

		if (ret)
		{
			//sprintf(sLogMes, "error reading xml fragment\n"); writeLog(0, 0);
			writeLogOut(__FUNCTION__, 0); // readReinBarFromElement return error
			return ret;
		}

	}




	rbP->ffpos[REIN_ELEM_AXIS] = mdlElmdscr_getFilePos(edpBar);

	//sprintf(sLogMes, "rbP->ffpos[REIN_ELEM_AXIS] == %u\n", rbP->ffpos[REIN_ELEM_AXIS]); writeLog(0, 0);
	//sprintf(sLogMes, "rbP->bartype == %i\n", rbP->bartype); writeLog(0, 0);
	//sprintf(sLogMes, "rbP->elemid == %I64u\n", rbP->elemid); writeLog(0, 0);


	return ret;
}

////////////////////////////////////////////////////////////
int readReinBarFromElement(ReinElement* relemP, MSElementDescrCP edpBar, int bClear, int bReadData)
{

	if (readReinBarFromElement(&(relemP->rb), edpBar, bClear) != SUCCESS)
		return ERROR;


	if (bReadData && relemP->rb.bartype != BT_AXIS && relemP->rb.elemid > 0)
	{
		ELREF eref = getElemRefByID(edpBar->h.dgnModelRef, relemP->rb.elemid);


		if (eref)
		{
			//ReinElement relem;
			MSElementDescr* edp = NULL;

			//sprintf(sLogMes, "mdlElmdscr_getByElemRef(...)\n"); writeLog(0, 0);
			mdlElmdscr_getByElemRef (&edp, eref, edpBar->h.dgnModelRef, FALSE, 0);

			//sprintf(sLogMes, "readReinDataFromElmd(...)\n"); writeLog(0, 0);
			if (edp)
			{
				if (readReinDataFromElmd(relemP, edp, &(relemP->rb)) == SUCCESS)
					relemP->rb.fromReinData(&relemP->rd);

				mdlElmdscr_freeAll(&edp);

			}
		}
	}

	writeLogOut(__FUNCTION__, 0); // readReinBarFromElement out

	return SUCCESS;

}

////////////////////////////////////////////////////////////
int readReinSpaceFromElmd(ReinElement* reP, MSElementDescrCP edP, int bReadPoints)
{
	int iInstSuccess = ERROR;
	/*
#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX

	DgnECInstancePtr insP = getECInstance(L"ReinSchema", L"ReinSpace", edP);
	if (insP.IsValid())
	{
		iInstSuccess = readFromECInstance(rsP, insP);
	}

#endif
*/
	if (iInstSuccess != SUCCESS)
		return readReinSpaceFromElement(reP, &edP->el, bReadPoints);
	else
		return SUCCESS;

}

////////////////////////////////////////////////////////////
int readReinSpaceFromElement(ReinElement* reP, MSElementCP elP, int bReadPoints)
{
	XMLFragmentListP  oXMLFragmentList = NULL;

	int ret = ERROR;

	ReinSpace* rsP = &reP->rs;

	//try
	//{
		if (!mdlElement_hasXMLFragmentAttachment((MSElementP)elP, &appID, &appTypeReinSpace))
			return ERROR;
	//}
	//catch (...)
	//{
	//	return ERROR;
	//}


	if (mdlXMLFragmentList_extractFromElementByAppIDAndType (&oXMLFragmentList, (MSElementP)elP,
				&appID, &appTypeReinSpace) == SUCCESS)
	{
		XMLFragmentP  pXMLFragment;
		MSWCH* wtxt;
		WCH ctxt[500];
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);
		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);
			ret = readReinSpaceFromString(rsP, wstr);
			mdlXMLFragmentList_free(&oXMLFragmentList);
		}

	}
	else
		return ret;

	rsP->elid = mdlElement_getID(elP);
	reP->idRS = mdlElement_getID(elP);

	if (bReadPoints)
	{
		rsP->pts_org_cnt = readPointsFromElement(rsP->pts_org, (MSElementP)elP, &appTypeOrgPoints);
		rsP->pts_end_cnt = readPointsFromElement(rsP->pts_end, (MSElementP)elP, &appTypeEndPoints);
	}

	readBarOversFromElement(reP, (MSElementP)elP);

	return ret;

}

////////////////////////////////////////////////////////////
// func in readBarOversFromElement
int readBarOversFromElement(ReinElement* reP, MSElement* elP)
{
	int cnt = 0;
	int fcnt = 0;
	int status;
	XMLFragmentListP  oXMLFragmentList = NULL;
	XMLFragmentListP    pCurrent = NULL;
	WCH ctxt[500];
	BarOver bo;

	reP->mapOvers.clear();

	if (!mdlElement_hasXMLFragmentAttachment(elP, &appID, &appTypeBarOver)) return 0;

	if (mdlXMLFragmentList_extractFromElementByAppIDAndType(&oXMLFragmentList, elP,
		&appID, &appTypeBarOver) != SUCCESS) return 0;

	fcnt = mdlXMLFragmentList_getCount(oXMLFragmentList);

	XMLFragmentP  pXMLFragment = NULL;
	MSWCH* wtxt = NULL;

	for (int i = 0; i < fcnt; i++)
	{

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		XmlFragmentPtr xptr = oXMLFragmentList->GetFragmentAtIndex(i);
		if (xptr.IsValid()) pXMLFragment = xptr.get();
#else
		status = mdlXMLFragmentList_getNode(&pCurrent, oXMLFragmentList, i);
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(pCurrent);
#endif
		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);
			if (readBarOverFromString(&bo, wstr) == SUCCESS)
			{
				reP->mapOvers[bo.inum] = bo;
				cnt++;
			}
		}
	}

	mdlXMLFragmentList_free(&oXMLFragmentList);


	return cnt;
}

////////////////////////////////////////////////////////////
int readPointsFromElement(BarPoint* arPtsOut,  MSElement* elP, UShort* appTypeP )
{
	XMLFragmentListP  oXMLFragmentList = NULL;
	int cnt, i, status, pcnt;
	XMLFragmentListP    pCurrent;
	BarPoint bp;
	WCH ctxt[500];

	if (!mdlElement_hasXMLFragmentAttachment(elP, &appID, appTypeP)) return 0;


	if (mdlXMLFragmentList_extractFromElementByAppIDAndType (&oXMLFragmentList, elP, 
					&appID, appTypeP) != SUCCESS) return 0;


	cnt = mdlXMLFragmentList_getCount (oXMLFragmentList);
	pcnt = 0;

	//XmlDomRef xd;
	//if (mdlXMLFragmentList_createXmlDom(&xd, oXMLFragmentList, L"ReinPoints") == SUCCESS)
	//{
	//	mdlXMLDom_free(xd);
	//}

	XMLFragmentP  pXMLFragment = NULL;
	MSWCH* wtxt = NULL;
	
	for (i = 0; i < cnt; i++)
	{

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		XmlFragmentPtr xptr = oXMLFragmentList->GetFragmentAtIndex(i);
		if (xptr.IsValid()) pXMLFragment = xptr.get();
#else
		status = mdlXMLFragmentList_getNode (&pCurrent, oXMLFragmentList, i);
		pXMLFragment = mdlXMLFragmentList_getXMLFragment (pCurrent);
#endif
		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);
			if (readPointFromString(&bp, wstr) == SUCCESS)
			{
				arPtsOut[pcnt] = bp;
				pcnt++;
			}
		}
	}
	
	mdlXMLFragmentList_free(&oXMLFragmentList);

	return pcnt;
	

}

/////////////////////////////////////////////
int readBarOverFromString(BarOver* boP, wstring str)
{

	if (boP == NULL) return ERROR;
	boP->clear();

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	if (*it != L"BAROVER") return ERROR;

	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->inum = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->isdel = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->btmov = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[0][0] = _wtof(it->c_str());
	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[0][1] = _wtof(it->c_str());
	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[0][2] = _wtof(it->c_str());
	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[0][3] = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[1][0] = _wtof(it->c_str());
	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[1][1] = _wtof(it->c_str());
	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[1][2] = _wtof(it->c_str());
	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[1][3] = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[2][0] = _wtof(it->c_str());
	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[2][1] = _wtof(it->c_str());
	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[2][2] = _wtof(it->c_str());
	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->tmov.form3d[2][3] = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	boP->isgnd = _wtoi(it->c_str());



/*



	WCH seps[] = L(";");
	WCH* token;

	if (str == NULL) return ERROR;
	if (SLEN(str) == 0) return ERROR;
	if (boP == NULL) return ERROR;

	token = STOK(str, seps);
	if (token == NULL)	return ERROR;
	if (SCNP(token, L("BAROVER"), SLEN(L("BAROVER"))) != 0) return ERROR;

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	boP->inum = STOI(token);

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	boP->isdel = STOI(token);

	token = STOK(NULL, seps);
	if (token != NULL)	boP->btmov = STOI(token); else boP->btmov = FALSE;

	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[0][0] = STOF(token);
	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[0][1] = STOF(token);
	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[0][2] = STOF(token);
	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[0][3] = STOF(token);

	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[1][0] = STOF(token);
	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[1][1] = STOF(token);
	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[1][2] = STOF(token);
	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[1][3] = STOF(token);

	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[2][0] = STOF(token);
	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[2][1] = STOF(token);
	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[2][2] = STOF(token);
	token = STOK(NULL, seps);	if (token != NULL)	boP->tmov.form3d[2][3] = STOF(token);

	token = STOK(NULL, seps);
	if (token != NULL)	boP->isgnd = STOI(token); else boP->isgnd = FALSE;
	*/

	return SUCCESS;

}

/////////////////////////////////////////////
int readNoteFromString(ReinNote* rnP, wstring str)
{

	if (rnP == NULL) return ERROR;
	rnP->clear();

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	if (*it != L"REINNOTE") return ERROR;

	IF_IT_nxt IF_IT_end return ERROR;
	SCPW2M(rnP->sNoteFmt, it->c_str(), 100);

	IF_IT_nxt IF_IT_end return ERROR;
	rnP->arNotePts[0].x = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return ERROR;
	rnP->arNotePts[0].y = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return ERROR;
	rnP->arNotePts[0].z = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return ERROR;
	rnP->arNotePts[1].x = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return ERROR;
	rnP->arNotePts[1].y = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return ERROR;
	rnP->arNotePts[1].z = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rnP->ielem = _wtoi(it->c_str());






	/*


	WCH seps[] = L(";");
	WCH* token;


	if (str == NULL) return ERROR;
	if (SLEN(str) == 0) return ERROR;

	token = STOK(str, seps);
	if (token == NULL)	return ERROR;
	if (SCNP(token, L("REINNOTE"), SLEN(L("REINNOTE"))) != 0) return ERROR;

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	SCPY(rnP->sNoteFmt, token);

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	rnP->arNotePts[0].x = STOF(token);

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	rnP->arNotePts[0].y = STOF(token);

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	rnP->arNotePts[0].z = STOF(token);

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	rnP->arNotePts[1].x = STOF(token);

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	rnP->arNotePts[1].y = STOF(token);

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	rnP->arNotePts[1].z = STOF(token);

	token = STOK(NULL, seps);
	if (token != NULL)
		rnP->ielem = STOI(token);
		*/

	return SUCCESS;

}

////////////////////////////////////////////////////////////
int readReinNoteFromElement(
	ReinNote* rnP,
	MSElement* elP
)
{
	XMLFragmentListP  oXMLFragmentList = NULL;

	if (!mdlElement_hasXMLFragmentAttachment(elP, &appID, &appTypeReinNote)) return ERROR;

	if (mdlXMLFragmentList_extractFromElementByAppIDAndType(
		&oXMLFragmentList, elP, &appID, &appTypeReinNote) == SUCCESS)
	{
		XMLFragmentP  pXMLFragment;
		MSWCH* wtxt;
		WCH ctxt[500];

		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);
			mdlXMLFragmentList_free(&oXMLFragmentList);

			if (readNoteFromString(rnP, wstr) == SUCCESS)
			{
				mdlElement_getProperties(&(rnP->iNoteLevID), &(rnP->iNoteGGN), 0, 0, 0, 0, 0, 0, elP);
				return SUCCESS;
			}
		}

	}
	else
		return ERROR;

	return ERROR;
}

/////////////////////////////////////////////////////////////////
int xmlAddNoteInfo(ReinNote* rnP, WCH* strNoteFmt, MSElementDescr** edpP, int ielem, bool bClear)
{

	WCH str[200];
	WCH* strNoteFmtLoc;
	MSWCH wstr[200];
	XMLFragmentListP    pCurrent = NULL;
	int status;
	MSElementDescr* edp;

	if (rnP == NULL) return 0;
	if (edpP == NULL) return 0;

	if (strNoteFmt) strNoteFmtLoc = strNoteFmt; else strNoteFmtLoc = rnP->sNoteFmt;

	edp = *edpP;

	// delete if exists
	if (bClear) mdlXMLFragmentList_stripFromElementByAppIDAndType(NULL, &edp->el, &appID, &appTypeReinNote);

	SPRN(str, L("REINNOTE;%s;%.0f;%.0f;%.0f;%.0f;%.0f;%.0f;%i"),
		strNoteFmtLoc,
		rnP->arNotePts[0].x,
		rnP->arNotePts[0].y,
		rnP->arNotePts[0].z,
		rnP->arNotePts[1].x,
		rnP->arNotePts[1].y,
		rnP->arNotePts[1].z,
		ielem
	);

	SCPM2W(wstr, str, 200);

	pCurrent = mdlXMLFragmentList_construct(wstr, NULL, appID, appTypeReinNote);

	if (pCurrent)	status = mdlXMLFragmentList_attachToElement(&pCurrent, edpP, TRUE);


	// add elem array...... [refid, parent elemid, barnum]
	// .. ..................


	return status;

}


/////////////////////////////////////////////
int readPointFromString(BarPoint* ptP, wstring str)
{

	if (ptP == NULL) return ERROR;
	ptP->clear();

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	if (*it != L"REINPOINT") return ERROR;

	IF_IT_nxt IF_IT_end return ERROR;
	ptP->pVrtx.x = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return ERROR;
	ptP->pVrtx.y = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return ERROR;
	ptP->pVrtx.z = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	ptP->flg = _wtol(it->c_str());



	/*

	WCH seps[]   = L(";");
	WCH *token;


	if (str == NULL) return ERROR;
	if (SLEN(str) == 0) return ERROR;

	token = STOK( str, seps );
	if (token == NULL )	return ERROR;
	if (SCNP(token, L("REINPOINT"), SLEN(L("REINPOINT"))) != 0) return ERROR;

	token = STOK( NULL, seps );
	if( token == NULL )	return ERROR;
	ptP->pVrtx.x = STOF(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return ERROR;
	ptP->pVrtx.y = STOF(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return ERROR;
	ptP->pVrtx.z = STOF(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	ptP->flg = STOL(token);
*/

	return SUCCESS;

}

/////////////////////////////////////////////////////////////////////
int readBarPointsFromElement(ReinBar* rbP, MSElement* elP)
{
	XMLFragmentListP  oXMLFragmentList = NULL;
	int cnt = 0, i = 0, status = 0, pcnt = 0;
	XMLFragmentListP    pCurrent;
	//WCH ctxt[500];

	if (!mdlElement_hasXMLFragmentAttachment(elP, &appID, &appTypeBarPoints)) return 0;

	if (mdlXMLFragmentList_extractFromElementByAppIDAndType (&oXMLFragmentList, elP, 
				&appID, &appTypeBarPoints) != SUCCESS) return 0;


	cnt = mdlXMLFragmentList_getCount (oXMLFragmentList);
	pcnt = 0;
	
	XMLFragmentP  pXMLFragment = NULL;

	//rbP->apts.clear();
	//rbP->cpxb.clear();
	//rbP->cpxe.clear();
	//rbP->rfa.clear();

	//rbP->apts.reserve(cnt);
	//rbP->cpxb.reserve(cnt);
	//rbP->cpxe.reserve(cnt);
	//rbP->rfa.reserve(cnt);


	for (i = 0; i < cnt; i++)
	{
		MSWCH* wtxt = NULL;
		wstring wstr = L"";

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		XmlFragmentPtr xptr = oXMLFragmentList->GetFragmentAtIndex(i);
		if (xptr.IsValid()) pXMLFragment = xptr.get();
#else
		status = mdlXMLFragmentList_getNode(&pCurrent, oXMLFragmentList, i);
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(pCurrent);
#endif
		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstr = wtxt;

			status = readBarPointFromString(rbP, pcnt, wstr);

			if (status == SUCCESS)
			{
				//rbP->apts.push_back(v);
				//rbP->cpxb.push_back(pb);
				//rbP->cpxe.push_back(pe);
				//rbP->rfa.push_back(rfa);
				pcnt++;
			}
		}
	}

	mdlXMLFragmentList_free(&oXMLFragmentList);

	//return rbP->apts.size();
	return pcnt;

}


//////////////////////////////////////////////////////////////////
int readBarPointFromString(ReinBar* rbP, int index, wstring str)
{

	if (rbP == NULL) return ERROR;

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	if (*it != L"BARPOINT") return ERROR;

	IF_IT_nxt IF_IT
	rbP->apts[index].x = _wtof(it->c_str());

	IF_IT_nxt IF_IT
	rbP->apts[index].y = _wtof(it->c_str());

	IF_IT_nxt IF_IT
	rbP->apts[index].z = _wtof(it->c_str());


	IF_IT_nxt IF_IT
	rbP->cpxb[index].x = _wtoi(it->c_str());

	IF_IT_nxt IF_IT
	rbP->cpxb[index].y = _wtoi(it->c_str());

	IF_IT_nxt IF_IT
	rbP->cpxb[index].z = _wtoi(it->c_str());


	IF_IT_nxt IF_IT
	rbP->cpxe[index].x = _wtoi(it->c_str());

	IF_IT_nxt IF_IT
	rbP->cpxe[index].y = _wtoi(it->c_str());

	IF_IT_nxt IF_IT
	rbP->cpxe[index].z = _wtoi(it->c_str());




	IF_IT_nxt IF_IT
	rbP->rfa[index] = _wtol(it->c_str());







	/*


	WCH seps[] = L(";");
	WCH *token;
	int ret = SUCCESS;

	if (str == NULL) return 1;
	if (SLEN(str) == 0) return 1;

	token = STOK(str, seps);
	if (token == NULL)	return 1;
	if (SCNP(token, L("BARPOINT"), SLEN(L("BARPOINT"))) != 0) return 1;

	token = STOK(NULL, seps);
	if (token != NULL)	rbP->apts[index].x = STOF(token);

	token = STOK(NULL, seps);
	if (token != NULL)	rbP->apts[index].y = STOF(token);

	token = STOK(NULL, seps);
	if (token != NULL)	rbP->apts[index].z = STOF(token);


	token = STOK(NULL, seps);
	if (token != NULL)	rbP->cpxb[index].x = STOI(token);

	token = STOK(NULL, seps);
	if (token != NULL)	rbP->cpxb[index].y = STOI(token);

	token = STOK(NULL, seps);
	if (token != NULL)	rbP->cpxb[index].z = STOI(token);


	token = STOK(NULL, seps);
	if (token != NULL)	rbP->cpxe[index].x = STOI(token);

	token = STOK(NULL, seps);
	if (token != NULL)	rbP->cpxe[index].y = STOI(token);

	token = STOK(NULL, seps);
	if (token != NULL)	rbP->cpxe[index].z = STOI(token);




	token = STOK(NULL, seps);
	if (token != NULL)	rbP->rfa[index] = STOI(token);
	*/

	return SUCCESS;
}




////////////////////////////////////////////////////////////
int readReinBarFromElem(ReinBar* rbP, MSElementCP elBarP)
{

	if (rbP == NULL) return ERROR;
	if (elBarP == NULL) return ERROR;

	writeLogIn(__FUNCTION__, 0); // readReinBarFromElem in

	int iInstSuccess = ERROR;
	XMLFragmentListP  oXMLFragmentList = NULL;

	rbP->clear();

	if (iInstSuccess != SUCCESS)
	{
		int ret = SUCCESS;

		try
		{
			if (mdlElement_hasXMLFragmentAttachment((MSElementP)elBarP, &appID, &appTypeReinBar))
			{
				if (mdlXMLFragmentList_extractFromElementByAppIDAndType(&oXMLFragmentList, (MSElementP)elBarP,
					&appID, &appTypeReinBar) == SUCCESS)
				{
					XMLFragmentP  pXMLFragment;
					MSWCH* wtxt;
					//WCH ctxt[500];
					pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

					if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
					{
						//SCPW2M(ctxt, wtxt, 500);

						if (readReinBarFromString(rbP, wtxt) != SUCCESS)
							ret = ERROR;

						mdlXMLFragmentList_free(&oXMLFragmentList);
					}
					else
						ret = ERROR;

				}
				else
				{
					ret = ERROR;
				}
			}
			else
			{
				ret = ERROR;
			}
		}
		catch (int e)
		{
			ret = e;
		}

		if (ret)
		{
			writeLogOut(__FUNCTION__, 0); // readReinBarFromElem return error
			return ret;
		}

	}


	writeLogOut(__FUNCTION__, 0); // readReinBarFromElem out

	return SUCCESS;

}


///////////////////////////////////////////////////
//func read ReinElm From String
//int readReinElmFromString(ReinElm* reP, wstring str, DgnModelRefP mrP)
//{




/*



#if defined (MSVERSION) && (MSVERSION == 0x8b0)

	char ctxt[1000];

	mdlCnv_convertUnicodeToMultibyte(str.c_str(), -1, ctxt, 1000);

	WCH seps[] = L(";");
	WCH* token;

	if (ctxt == NULL) return ERROR;
	if (SLEN(ctxt) == 0) return ERROR;

	token = STOK(ctxt, seps);
	if (token == NULL)	return ERROR;
	if (SCNP(token, L("REINELEM"), SLEN(L("REINELEM"))) != 0) return ERROR;

	// parent id
	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	if (SSCAN(token, L("%I64u"), &reP->bel.elemid) != 1) return ERROR;

	// 02 type
	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	reP->type = STOI(token);

	// 03 diam
	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	reP->bel.diam = STOI(token);

	// 04 runmet
	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	reP->bel.runmet = STOI(token);

	// 05 transp
	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	reP->bel.transp = STOI(token);

	// 06 numpts
	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	reP->bel.numpts = STOI(token);
	reP->bel.cnumpts = reP->bel.numpts;

	// 07 mainSgmIndex
	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	reP->bel.mainSgmIndex = STOI(token);
	if (reP->bel.mainSgmIndex < 0) reP->bel.mainSgmIndex = 0;
	if (reP->bel.mainSgmIndex >= MAX_BAR_VERTICES) reP->bel.mainSgmIndex = MAX_BAR_VERTICES - 2;

	// 08 mainPtsIndex
	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	reP->bel.mainPtsIndex = STOI(token);
	if (reP->bel.mainPtsIndex < 0) reP->bel.mainPtsIndex = 0;
	if (reP->bel.mainPtsIndex >= MAX_BAR_VERTICES) reP->bel.mainPtsIndex = MAX_BAR_VERTICES - 1;

	// 09 inum
	token = STOK(NULL, seps);
	if (token != NULL)
		reP->bel.inum = STOI(token);

	// 10 term
	token = STOK(NULL, seps);
	if (token != NULL)
		reP->bel.term[0] = STOI(token);

	// 11 term
	token = STOK(NULL, seps);
	if (token != NULL)
		reP->bel.term[1] = STOI(token);

	int par = 0;

	// 12 termPar
	token = STOK(NULL, seps);
	if (token != NULL)
	{
		par = STOI(token);
		if (par >= -180 && par <= 180) reP->bel.termPar[0][0] = par; else reP->bel.termPar[0][0] = 0;
	}

	// 13 termPar
	token = STOK(NULL, seps);
	if (token != NULL)
	{
		par = STOI(token);
		if (par >= -180 && par <= 180) reP->bel.termPar[0][1] = par; else reP->bel.termPar[0][1] = 0;
	}

	// 14 termPar
	token = STOK(NULL, seps);
	if (token != NULL)
	{
		par = STOI(token);
		if (par >= 0) reP->bel.termPar[1][0] = par; else reP->bel.termPar[1][0] = 0;
	}

	// 15 termPar
	token = STOK(NULL, seps);
	if (token != NULL)
	{
		par = STOI(token);
		if (par >= 0) reP->bel.termPar[1][1] = par; else reP->bel.termPar[1][1] = 0;
	}

	// 16 termPar
	token = STOK(NULL, seps);
	if (token != NULL)
	{
		reP->bel.termPar[2][0] = STOI(token);
	}

	// 17 termPar
	token = STOK(NULL, seps);
	if (token != NULL)
	{
		reP->bel.termPar[2][1] = STOI(token);
	}


	// 18 axid
	token = STOK(NULL, seps);
	if (token != NULL)
	{
		if (SSCAN(token, L("%I64u"), &reP->bel.axid) != 1) reP->bel.axid = 0;
	}

	// 19 modvers
	token = STOK(NULL, seps); // model version
	if (token == NULL)
		reP->modvers = 0;
	else
		reP->modvers = STOI(token);

	if (mrP
		&& reP->modvers != iModelVers
		&& (bModelCheckRefs == TRUE || mdlModelRef_isActiveModel(mrP)))
	{
		bModelOutOfDate = TRUE;
	}

	// 20 bendrad
	token = STOK(NULL, seps);
	if (token != NULL)
		reP->bel.bendrad = STOI(token);

	// 21 bartype
	token = STOK(NULL, seps);
	if (token != NULL)
		reP->bel.bartype = STOI(token);

	// 22 poscalc
	token = STOK(NULL, seps);
	if (token != NULL)
		reP->bel.poscalc = STOI(token);

	int ilap = 0;

	// 23 ilap
	token = STOK(NULL, seps);
	if (token != NULL)
		ilap = STOI(token);

	if (ilap > 0) reP->bel.lap[0] = ilap;
	if (ilap < 0) reP->bel.lap[1] = -ilap;

	// 24 noplanar
	token = STOK(NULL, seps);
	if (token != NULL)
		reP->bel.noplanar = STOI(token);

	// 25 element flags
	token = STOK(NULL, seps);
	if (token != NULL)
		reP->elemflags = STOI(token);

	// 26 3d bar if exists
	token = STOK(NULL, seps);
	if (token != NULL)
	{
		if (SSCAN(token, L("%I64u"), &reP->bel.brid) != 1) reP->bel.brid = 0;
		//reP->bel.ffpos[REIN_ELEM_BAR] = STOI(token); // bar ElementId
	}

	// 27 ground
	token = STOK(NULL, seps);
	if (token != NULL)
	{
		int a = STOI(token);
		reP->bel.grnd = (a != 0);
	}


#else

	wstringstream wstm(str);

	wstring wtok;

	if (!getline(wstm, wtok, L';')) return ERROR;
	if (wtok != L"REINELEM") return ERROR;

	// 01 parent id
	if (!getline(wstm, wtok, L';')) return ERROR;
	//reP->bel.elemid = wcstoull(wtok, 0, 0);
	if (swscanf(wtok.c_str(), L"%I64u", &reP->bel.elemid) != 1) return ERROR;
		
	// 02 type
	if (!getline(wstm, wtok, L';')) return ERROR;
	reP->type = _wtoi(wtok.c_str());

	// 03 diam
	if (!getline(wstm, wtok, L';')) return SUCCESS;
	reP->bel.diam = _wtoi(wtok.c_str());

	// 04 runmet
	if (!getline(wstm, wtok, L';')) return SUCCESS;
	reP->bel.runmet = _wtoi(wtok.c_str());

	// 05 transp
	if (!getline(wstm, wtok, L';')) return SUCCESS;
	reP->bel.transp = _wtoi(wtok.c_str());

	// 06 numpts
	if (!getline(wstm, wtok, L';')) return SUCCESS;
	reP->bel.numpts = _wtoi(wtok.c_str());
	reP->bel.cnumpts = reP->bel.numpts;

	// 07 mainSgmIndex
	if (!getline(wstm, wtok, L';')) return SUCCESS;
	reP->bel.mainSgmIndex = _wtoi(wtok.c_str());
	if (reP->bel.mainSgmIndex < 0) reP->bel.mainSgmIndex = 0;
	if (reP->bel.mainSgmIndex >= MAX_BAR_VERTICES) reP->bel.mainSgmIndex = MAX_BAR_VERTICES - 2;

	// 08 mainPtsIndex
	if (!getline(wstm, wtok, L';')) return SUCCESS;
	reP->bel.mainPtsIndex = _wtoi(wtok.c_str());
	if (reP->bel.mainPtsIndex < 0) reP->bel.mainPtsIndex = 0;
	if (reP->bel.mainPtsIndex >= MAX_BAR_VERTICES) reP->bel.mainPtsIndex = MAX_BAR_VERTICES - 1;

	// 09 inum
	if (getline(wstm, wtok, L';'))
		reP->bel.inum = _wtoi(wtok.c_str());

	// 10 term
	if (getline(wstm, wtok, L';'))
		reP->bel.term[0] = _wtoi(wtok.c_str());

	// 11 term
	if (getline(wstm, wtok, L';'))
		reP->bel.term[1] = _wtoi(wtok.c_str());

	int par = 0;

	// 12 termPar
	if (getline(wstm, wtok, L';'))
	{
		par = _wtoi(wtok.c_str());
		if (par >= -180 && par <= 180) reP->bel.termPar[0][0] = par; else reP->bel.termPar[0][0] = 0;
	}

	// 13 termPar
	if (getline(wstm, wtok, L';'))
	{
		par = _wtoi(wtok.c_str());
		if (par >= -180 && par <= 180) reP->bel.termPar[0][1] = par; else reP->bel.termPar[0][1] = 0;
	}

	// 14 termPar
	if (getline(wstm, wtok, L';'))
	{
		par = _wtoi(wtok.c_str());
		if (par >= 0) reP->bel.termPar[1][0] = par; else reP->bel.termPar[1][0] = 0;
	}

	// 15 termPar
	if (getline(wstm, wtok, L';'))
	{
		par = _wtoi(wtok.c_str());
		if (par >= 0) reP->bel.termPar[1][1] = par; else reP->bel.termPar[1][1] = 0;
	}

	// 16 termPar
	if (getline(wstm, wtok, L';'))
	{
		reP->bel.termPar[2][0] = _wtoi(wtok.c_str());
	}

	// 17 termPar
	if (getline(wstm, wtok, L';'))
	{
		reP->bel.termPar[2][1] = _wtoi(wtok.c_str());
	}

	// 18 axid
	if (getline(wstm, wtok, L';'))
	{
		if (swscanf(wtok.c_str(), L("%I64u"), &reP->bel.axid) != 1) reP->bel.axid = 0;
	}


	// 19 modvers
	if (getline(wstm, wtok, L';'))
		reP->modvers = _wtoi(wtok.c_str());
	else
		reP->modvers = 0;

	if (mrP
		&& reP->modvers != iModelVers
		&& (bModelCheckRefs == TRUE || mdlModelRef_isActiveModel(mrP)))
	{
		bModelOutOfDate = TRUE;
	}

	// 20 bendrad
	if (getline(wstm, wtok, L';'))
		reP->bel.bendrad = _wtoi(wtok.c_str());

	// 21 bartype
	if (getline(wstm, wtok, L';'))
		reP->bel.bartype = _wtoi(wtok.c_str());

	// 22 poscalc
	if (getline(wstm, wtok, L';'))
		reP->bel.poscalc = _wtoi(wtok.c_str());

	// 23 ilap
	int ilap = 0;

	if (getline(wstm, wtok, L';'))
		ilap = _wtoi(wtok.c_str());

	if (ilap > 0) reP->bel.lap[0] = ilap;
	if (ilap < 0) reP->bel.lap[1] = -ilap;

	// 24 noplanar
	if (getline(wstm, wtok, L';'))
		reP->bel.noplanar = _wtoi(wtok.c_str());

	// 25 element flags
	if (getline(wstm, wtok, L';'))
		reP->elemflags = _wtoi(wtok.c_str());

	// 26 3d bar if exists
	if (getline(wstm, wtok, L';'))
	{
		if (swscanf(wtok.c_str(), L("%I64u"), &reP->bel.brid) != 1) reP->bel.brid = 0;
		//reP->bel.ffpos[REIN_ELEM_BAR] = _wtoi(token); // bar ElementId
	}

	// 27 ground
	if (getline(wstm, wtok, L';'))
	{
		int a = _wtoi(wtok.c_str());
		reP->bel.grnd = (a != 0);
	}

#endif

*/



//}



#if defined (MSVERSION) && (MSVERSION == 0x8b0)

/////////////////////////////////////////////////
int readFromString(char* func, deque<wstring>* setP, wstring wstr, wchar_t* sep, size_t iLenChk)
{

	//MSWCH wsep[5];
	//wcscpy(wsep, sep.c_str());

	if (wstr.size() == 0) return ERROR;

	if (wstr.size() > iLenChk)
	{
		WCH str[1000];
		SPRN(str, L("readFromString() alert, string length %I64u\n"), wstr.size());
		mdlOutput_messageCenter(MESSAGE_ERROR, L("readFromString() alert"), str, MESSAGE_ALERT_BALLOON);

		return ERROR;
	}

	size_t ln = wstr.size() + 10;

	MSWCH* dups = new MSWCH[ln];
	//vector<MSWCH> dups(ln);

	wcsncpy(dups, wstr.c_str(), ln - 5);
	//wcsncpy(sset, wstr.c_str(), ln - 5);

	MSWCH* wtok = NULL;

	wtok = wcstok(dups, sep);
	while (wtok)
	{
		wstring locstr(wtok);
		setP->push_back(locstr);
		wtok = wcstok(NULL, sep);
	}

	delete [] dups;
	//dups.clear();

#else

/////////////////////////////////////////////////
int readFromString(char* func, deque<wstring>*setP, wstring wstr, wchar_t* sep, size_t iLenChk)
{
	if (wstr.length() == 0) return ERROR;

	wstringstream wstm(wstr);

	wstring wtok;

	while (getline(wstm, wtok, sep[0]))
	{
		setP->push_back(wtok);
	}


#endif

	if (setP->empty()) return ERROR;

	return SUCCESS;

}


//////////////////////////////////////////////////
int readReinAxisFromString(ReinAxis* raP, wstring str)
{
	if (raP == NULL) return ERROR;

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	if (*it != L"REINAXIS") return ERROR;

	IF_IT_nxt IF_IT_end return ERROR;
	if (swscanf(it->c_str(), L"%I64u", &raP->eleid) != 1) return ERROR;

	IF_IT_nxt IF_IT_end return SUCCESS;
	raP->inum = _wtoi(it->c_str());



//#if defined (MSVERSION) && (MSVERSION == 0x8b0)
//
//	char ctxt[1000];
//
//	mdlCnv_convertUnicodeToMultibyte(str.c_str(), -1, ctxt, 1000);
//
//
//	char seps[]   = ";";
//	char *token;
//
//	if (strlen(ctxt) == 0) return ERROR;
//
//	token = strtok(ctxt, seps );
//	if (token == NULL )	return ERROR;
//	if (strncmp(token, "REINAXIS", strlen("REINAXIS")) != 0) return ERROR;
//
//	token = strtok( NULL, seps );
//	if( token == NULL )	return ERROR;
//	if (sscanf(token, "%I64u", &raP->eleid) != 1) return ERROR;
//
//	token = strtok( NULL, seps );
//	if( token == NULL )	return SUCCESS;
//	raP->inum = atoi(token);
//
//	//token = strtok( NULL, seps );
//	//if( token == NULL ) return SUCCESS;
//	//raP->... = atoi(token);
//
//#else
//
//	wstringstream wstm(str);
//
//	wstring wtok;
//
//	if (!getline(wstm, wtok, L';')) return ERROR;
//	if (wtok != L"REINAXIS") return ERROR;
//
//	if (!getline(wstm, wtok, L';')) return ERROR;
//	if (swscanf(wtok.c_str(), L"%I64u", &raP->eleid) != 1) return ERROR;
//
//	if (!getline(wstm, wtok, L';')) return ERROR;
//	raP->inum = _wtoi(wtok.c_str());
//
//#endif

	return SUCCESS;
}


#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX
//////////////////////////////////////////////////
int readFromECInstance(ReinSpace* rsP, DgnECInstancePtr insP)
{

	if (rsP == NULL) return ERROR;
	if (!insP.IsValid()) return ERROR;

	rsP->clear();

	ECN::ECValue v;

	if (insP->GetValue(v, L"ReinBarDiameter") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->diam = v.GetInteger();
	else
		return ERROR;

	if (rsP->diam == 0) return ERROR;


	if (insP->GetValue(v, L"ReinBarLenType") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->runmet = v.GetInteger();

	if (rsP->runmet > 3) rsP->runmet = 3;


	if (insP->GetValue(v, L"ReinBarSpacing") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->spacef = v.GetDouble();

	if ((int)rsP->spacef == 0) rsP->spacef = (double)iSpaceDefault;


	if (insP->GetValue(v, L"ReinBarOffset1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->offset[0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinBarOffset2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->offset[1] = v.GetInteger();

	//if (rsP->offset[1] > 0) rsP->offset[1] = 0;
	if (rsP->offset[1] < 0) rsP->offset[1] = -rsP->offset[1]; // для совместимости значение хранится с отриц. значением


	if (insP->GetValue(v, L"ReinLap") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->lap[2] = v.GetInteger();

	if (insP->GetValue(v, L"ReinLap1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->lap[0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinLap2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->lap[1] = v.GetInteger();


	if (insP->GetValue(v, L"ReinTerm1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->trm[0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinTerm2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->trm[1] = v.GetInteger();


	// по умолчанию
	//rsP->trmPar[0][0] = 180;
	//rsP->trmPar[0][1] = -180;
	//rsP->trmPar[1][0] = getReinLapBend(rsP->diam, 0);
	//rsP->trmPar[1][1] = getReinLapBend(rsP->diam, 0);

	if (insP->GetValue(v, L"ReinBendType1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->trmPar[0][0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinBendType2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->trmPar[0][1] = v.GetInteger();

	if (insP->GetValue(v, L"ReinBendLen1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->trmPar[1][0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinBendLen2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->trmPar[1][1] = v.GetInteger();

	if (insP->GetValue(v, L"ReinMuftType1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->trmPar[2][0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinMuftType2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->trmPar[2][1] = v.GetInteger();


	if (insP->GetValue(v, L"ReinBarBend") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->bendrad = v.GetInteger();

	if (insP->GetValue(v, L"ReinPosSet") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->poscalc = v.GetInteger();



	// этих нету в REINSPACE

	//if (insP->GetValue(v, L"ReinSpaceType") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
	//	rsP->bartype = v.GetInteger();

	//if (insP->GetValue(v, L"ReinSpacingRad") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
	//	rsP->spacerad = v.GetInteger();



	if (insP->GetValue(v, L"ReinBarSegmIndex") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->segmIndex = v.GetInteger();

	if (insP->GetValue(v, L"ReinBarEDOffset") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rsP->elemEDoffset = v.GetInteger();



	return SUCCESS;
}

//////////////////////////////////////////////////
int readFromECInstance(ReinBar* rbP, DgnECInstancePtr insP)
{

	if (rbP == NULL) return ERROR;
	if (!insP.IsValid()) return ERROR;

	rbP->clear();

	ECN::ECValue v;

	if (insP->GetValue(v, L"ReinBarDiameter") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->diam = v.GetInteger();	
	else 
		return ERROR;

	if (rbP->diam == 0) return ERROR;

	if (insP->GetValue(v, L"ReinBarLenType") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success)
		rbP->runmet = v.GetInteger();

	if (rbP->runmet > 3) rbP->runmet = 3;

	if (insP->GetValue(v, L"ReinBarSpacing") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->spacef = v.GetDouble();

	if ((int)rbP->spacef == 0) rbP->spacef = (double)iSpaceDefault;

	if (insP->GetValue(v, L"ReinBarOffset1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->offset[0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinBarOffset2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->offset[1] = v.GetInteger();

	//if (rbP->offset[1] > 0) rbP->offset[1] = 0;
	if (rbP->offset[1] < 0) rbP->offset[1] = -rbP->offset[1]; // для совместимости значение хранится с отриц. значением

	if (insP->GetValue(v, L"ReinLap") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->lap[2] = v.GetInteger();

	if (insP->GetValue(v, L"ReinLap1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->lap[0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinLap2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->lap[1] = v.GetInteger();

	if (insP->GetValue(v, L"ReinTerm1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->term[0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinTerm2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->term[1] = v.GetInteger();

	// по умолчанию
	//rbP->termPar[0][0] = 180;
	//rbP->termPar[0][1] = -180;
	//rbP->termPar[1][0] = getReinLapBend(rbP->diam, 0);
	//rbP->termPar[1][1] = getReinLapBend(rbP->diam, 0);

	if (insP->GetValue(v, L"ReinBendType1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->termPar[0][0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinBendType2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->termPar[0][1] = v.GetInteger();

	if (insP->GetValue(v, L"ReinBendLen1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->termPar[1][0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinBendLen2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->termPar[1][1] = v.GetInteger();

	if (insP->GetValue(v, L"ReinMuftType1") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->termPar[2][0] = v.GetInteger();

	if (insP->GetValue(v, L"ReinMuftType2") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->termPar[2][1] = v.GetInteger();



	if (insP->GetValue(v, L"ReinBarBend") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->bendrad = v.GetInteger();

	if (insP->GetValue(v, L"ReinSpaceType") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->bartype = v.GetInteger();

	if (insP->GetValue(v, L"ReinSpacingRad") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->spacerad = v.GetInteger();

	if (insP->GetValue(v, L"ReinPosSet") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->poscalc = v.GetInteger();



	if (insP->GetValue(v, L"ReinContNum") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->contnum = v.GetInteger();

	//if (insP->GetValue(v, L"ReinBarFlags") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		if (rbP->bartype) rbP->barflags |= REINBAR_FLAG_CONT; // set is contour

	if (insP->GetValue(v, L"ReinElementID") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->elemid = (ElementId)v.GetLong();


	if (insP->GetValue(v, L"ReinBarSegmIndex") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->segmIndex = v.GetInteger();

	if (insP->GetValue(v, L"ReinBarEDOffset") == ECN::ECObjectsStatus::ECOBJECTS_STATUS_Success) 
		rbP->elemEDoffset = v.GetInteger();




	return SUCCESS;
}
#endif


//////////////////////////////////////////////////
int readReinBarFromString(ReinBar* rbP, wstring str)
{

	if (rbP == NULL) return ERROR;
	rbP->clear();

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	if (*it != L"REINBAR") return ERROR;

	IF_IT_nxt IF_IT_end return ERROR;
	rbP->runmet = _wtoi(it->c_str());
	if (rbP->runmet > 3) rbP->runmet = 3; // 1

	IF_IT_nxt IF_IT_end return ERROR;
	rbP->diam = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->segmIndex = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->elemEDoffset = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	//rbP->space = _wtoi(it->c_str());
	rbP->spacef = _wtof(it->c_str());
	if ((int)rbP->spacef == 0) rbP->spacef = (double)iSpaceDefault; // 5

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->offset[0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->offset[1] = _wtoi(it->c_str());
	if (rbP->offset[1] > 0) rbP->offset[1] = 0;
	if (rbP->offset[1] < 0) rbP->offset[1] = -rbP->offset[1]; // для совместимости значение хранится с отриц. значением

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->lap[0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->lap[1] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS; // 10
	rbP->lap[2] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->term[0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->term[1] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->termPar[0][0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->termPar[0][1] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->termPar[1][0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->termPar[1][1] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->termPar[2][0] = _wtoi(it->c_str()); // 17

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->termPar[2][1] = _wtoi(it->c_str()); // 18

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->bendrad = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->bartype = _wtoi(it->c_str()); // 20

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->spacerad = _wtoi(it->c_str()); // 21

	IF_IT_nxt IF_IT_end return SUCCESS;
	if (rbP->bartype != BT_AXIS) // 22
	{
		if (swscanf(it->c_str(), L"%I64u", &rbP->elemid) != 1) return SUCCESS;
	}

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->contnum = _wtoi(it->c_str()); // 23

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->poscalc = _wtoi(it->c_str()); // 24

	IF_IT_nxt IF_IT_end return SUCCESS;
	rbP->barflags = _wtoi(it->c_str()); // 25

	IF_IT_nxt IF_IT_end return SUCCESS;
	int a = _wtoi(it->c_str());
	rbP->grnd = (a != 0); // 26


/*


#if defined (MSVERSION) && (MSVERSION == 0x8b0)

	char ctxt[1000];

	mdlCnv_convertUnicodeToMultibyte(str.c_str(), -1, ctxt, 1000);

	WCH seps[]   = L(";");
	WCH *token;

	// если нет сохраненных, берем активные
	//copySpaceData(&rInfo.rsVal, rbP, TRUE, NULL, FALSE);

	// а эти обнуляем
	//rbP->lap[0] = 0;
	//rbP->lap[1] = 0;
	//rbP->lap[2] = 0;
	//rbP->term[0] = REIN_TERM_NONE;
	//rbP->term[1] = REIN_TERM_NONE;
	//rbP->bartype = BT_AXIS; // по умолчанию ось
	//rbP->elemid = 0;
	//rbP->contnum = 0;
	//rbP->poscalc = 0;


	if (SLEN(ctxt) == 0) return ERROR;

	token = STOK(ctxt, seps );
	if (token == NULL )	return ERROR;
	if (SCNP(token, L("REINBAR"), SLEN(L("REINBAR"))) != 0) return ERROR;

	token = STOK( NULL, seps );
	if( token == NULL )	return ERROR;
	rbP->runmet = STOI(token);
	if (rbP->runmet > 3) rbP->runmet = 3; // 1

	token = STOK( NULL, seps );
	if( token == NULL )	return ERROR;
	rbP->diam = STOI(token); // 2

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->segmIndex = STOI(token); // 3

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->elemEDoffset = STOI(token); // 4

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->space = STOI(token);
	if (rbP->space == 0) rbP->space = iSpaceDefault; // 5

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->offset[0] = STOI(token); // 6

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->offset[1] = STOI(token); // 7
	if (rbP->offset[1] > 0) rbP->offset[1] = 0;
	if (rbP->offset[1] < 0) rbP->offset[1] = -rbP->offset[1]; // для совместимости значение хранится с отриц. значением

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->lap[0] = STOI(token); // 8

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->lap[1] = STOI(token); // 9

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->lap[2] = STOI(token); // 10

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->term[0] = STOI(token); // 11

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->term[1] = STOI(token); // 12


	// по умолчанию
	//rbP->termPar[0][0] = 180;
	//rbP->termPar[0][1] = -180;
	//rbP->termPar[1][0] = getReinLapBend(rbP->diam, 0);
	//rbP->termPar[1][1] = getReinLapBend(rbP->diam, 0);

	token = STOK( NULL, seps );
	if( token != NULL )
		rbP->termPar[0][0] = STOI(token);

	token = STOK( NULL, seps );
	if( token != NULL )
		rbP->termPar[0][1] = STOI(token);

	token = STOK( NULL, seps );
	if( token != NULL )
		rbP->termPar[1][0] = STOI(token);

	token = STOK( NULL, seps );
	if( token != NULL )
		rbP->termPar[1][1] = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->termPar[2][0] = STOI(token); // 17

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->termPar[2][1] = STOI(token); // 18

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->bendrad = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->bartype = STOI(token); // 20

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rbP->spacerad = STOI(token); // 21

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	if (rbP->bartype != BT_AXIS) // 22
	{
		if (SSCAN(token, L("%I64u"), &rbP->elemid) != 1) return SUCCESS;
	}

	token = STOK( NULL, seps );
	if( token != NULL )	rbP->contnum = STOI(token); // 23

	token = STOK( NULL, seps );
	if( token != NULL )	rbP->poscalc = STOI(token); // 24

	token = STOK( NULL, seps );
	if( token != NULL )	rbP->barflags = STOI(token); else rbP->barflags = 0; // 25

	token = STOK( NULL, seps );
	if (token != NULL)
	{
		int a = STOI(token);
		rbP->grnd = (a != 0); // 26
	}
	else
		rbP->grnd = false;
	
#else

	wstringstream wstm(str);

	wstring wtok;

	if (!getline(wstm, wtok, L';')) return ERROR;
	if (wtok != L"REINBAR") return ERROR;


	if (!getline(wstm, wtok, L';')) return ERROR; // 1
	rbP->runmet = _wtoi(wtok.c_str());
	if (rbP->runmet > 3) rbP->runmet = 3;

	if (!getline(wstm, wtok, L';')) return ERROR; // 2
	rbP->diam = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return ERROR; // 3
	rbP->segmIndex = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 4
	rbP->elemEDoffset = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 5
	rbP->space = _wtoi(wtok.c_str());
	if (rbP->space == 0) rbP->space = iSpaceDefault;

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 6
	rbP->offset[0] = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 7
	rbP->offset[1] = _wtoi(wtok.c_str());
	if (rbP->offset[1] > 0) rbP->offset[1] = 0;
	if (rbP->offset[1] < 0) rbP->offset[1] = -rbP->offset[1]; // для совместимости значение хранится с отриц. значением

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 8
	rbP->lap[0] = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 9
	rbP->lap[1] = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 10
	rbP->lap[2] = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 11
	rbP->term[0] = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 12
	rbP->term[1] = _wtoi(wtok.c_str());


	// по умолчанию
	//rbP->termPar[0][0] = 180;
	//rbP->termPar[0][1] = -180;
	//rbP->termPar[1][0] = getReinLapBend(rbP->diam, 0);
	//rbP->termPar[1][1] = getReinLapBend(rbP->diam, 0);

	if (getline(wstm, wtok, L';'))
		rbP->termPar[0][0] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rbP->termPar[0][1] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rbP->termPar[1][0] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rbP->termPar[1][1] = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 17
	rbP->termPar[2][0] = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 18
	rbP->termPar[2][1] = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS;
	rbP->bendrad = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 20
	rbP->bartype = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 21
	rbP->spacerad = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return SUCCESS; // 22
	if (rbP->bartype != BT_AXIS)
	{
		if (swscanf(wtok.c_str(), L("%I64u"), &rbP->elemid) != 1) return SUCCESS;
	}

	if (getline(wstm, wtok, L';'))
		rbP->contnum = _wtoi(wtok.c_str());  // 23

	if (getline(wstm, wtok, L';'))
		rbP->poscalc = _wtoi(wtok.c_str()); // 24

	if (getline(wstm, wtok, L';'))
		rbP->barflags = _wtoi(wtok.c_str()); else rbP->barflags = 0; // 25

	if (getline(wstm, wtok, L';')) // 26
	{
		int a = _wtoi(wtok.c_str());
		rbP->grnd = (a != 0);
	}
	else
		rbP->grnd = false;


#endif

*/

	return SUCCESS;

}






/////////////////////////////////////////////
int readReinSpaceFromString(ReinSpace* rsP, wstring str)
{

	if (rsP == NULL) return ERROR;
	rsP->clear();

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	if (*it != L"REINSPACE") return ERROR;

	IF_IT_nxt IF_IT_end return ERROR;
	rsP->runmet = _wtoi(it->c_str());
	if (rsP->runmet > 3) rsP->runmet = 3; // 1

	IF_IT_nxt IF_IT_end return ERROR;
	rsP->diam = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return ERROR;
	//rsP->space = _wtoi(it->c_str());
	rsP->spacef = _wtof(it->c_str());
	if ((int)rsP->spacef == 0) rsP->spacef = (double)iSpaceDefault;

	IF_IT_nxt IF_IT_end return ERROR;
	rsP->offset[0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->elemEDoffset = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->segmIndex = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->lap[0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->lap[1] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->lap[2] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS; // 10
	rsP->bendrad = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->offset[1] = _wtoi(it->c_str());
	if (rsP->offset[1] > 0) rsP->offset[1] = 0;
	if (rsP->offset[1] < 0) rsP->offset[1] = -rsP->offset[1]; // для совместимости значение хранится с отриц. значением

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->trm[0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->trm[1] = _wtoi(it->c_str());


	// по умолчанию
	//rsP->trmPar[0][0] = 180;
	//rsP->trmPar[0][1] = -180;
	//rsP->trmPar[1][0] = getReinLapBend(rsP->diam, 0);
	//rsP->trmPar[1][1] = getReinLapBend(rsP->diam, 0);

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->trmPar[0][0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->trmPar[0][1] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->trmPar[1][0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->trmPar[1][1] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->trmPar[2][0] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	rsP->trmPar[2][1] = _wtoi(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS; // 20
	rsP->poscalc = _wtoi(it->c_str());

	//IF_IT_nxt IF_IT_end return SUCCESS;
	//rsP->space2 = _wtoi(it->c_str());
	//if (rsP->space2 <= 0) rsP->space2 = iSpaceDefault;


/*


#if defined (MSVERSION) && (MSVERSION == 0x8b0)

	WCH seps[]   = L(";");
	WCH *token;

	char ctxt[1000];
	mdlCnv_convertUnicodeToMultibyte(str.c_str(), -1, ctxt, 1000);

	if (ctxt == NULL) return ERROR;
	if (SLEN(ctxt) == 0) return ERROR;

	token = STOK(ctxt, seps );
	if (token == NULL )	return ERROR;
	if (SCNP(token, L("REINSPACE"), SLEN(L("REINSPACE"))) != 0) return ERROR;

	token = STOK( NULL, seps );
	if( token == NULL )	return ERROR;
	rsP->runmet = STOI(token);
	if (rsP->runmet > 3) rsP->runmet = 3;

	token = STOK( NULL, seps );
	if( token == NULL )	return ERROR;
	rsP->diam = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return ERROR;
	rsP->space = STOI(token);
	if (rsP->space == 0) rsP->space = iSpaceDefault;

	token = STOK( NULL, seps );
	if( token == NULL )	return ERROR;
	rsP->offset[0] = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->elemEDoffset = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->segmIndex = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->lap[0] = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->lap[1] = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->lap[2] = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->bendrad = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->offset[1] = STOI(token);
	if (rsP->offset[1] > 0) rsP->offset[1] = 0;
	if (rsP->offset[1] < 0) rsP->offset[1] = -rsP->offset[1]; // для совместимости значение хранится с отриц. значением

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->trm[0] = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->trm[1] = STOI(token);


	// по умолчанию
	//rsP->trmPar[0][0] = 180;
	//rsP->trmPar[0][1] = -180;
	//rsP->trmPar[1][0] = getReinLapBend(rsP->diam, 0);
	//rsP->trmPar[1][1] = getReinLapBend(rsP->diam, 0);

	token = STOK( NULL, seps );
	if( token != NULL )
		rsP->trmPar[0][0] = STOI(token);

	token = STOK( NULL, seps );
	if( token != NULL )
		rsP->trmPar[0][1] = STOI(token);

	token = STOK( NULL, seps );
	if( token != NULL )
		rsP->trmPar[1][0] = STOI(token);

	token = STOK( NULL, seps );
	if( token != NULL )
		rsP->trmPar[1][1] = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->trmPar[2][0] = STOI(token);

	token = STOK( NULL, seps );
	if( token == NULL )	return SUCCESS;
	rsP->trmPar[2][1] = STOI(token);

	token = STOK( NULL, seps );
	if( token != NULL )	rsP->poscalc = STOI(token);

#else

	wstringstream wstm(str);

	wstring wtok;

	if (!getline(wstm, wtok, L';')) return ERROR;
	if (wtok != L"REINSPACE") return ERROR;

	if (!getline(wstm, wtok, L';')) return ERROR;
	rsP->runmet = _wtoi(wtok.c_str());
	if (rsP->runmet > 3) rsP->runmet = 3;

	if (!getline(wstm, wtok, L';')) return ERROR;
	rsP->diam = _wtoi(wtok.c_str());

	if (!getline(wstm, wtok, L';')) return ERROR;
	rsP->space = _wtoi(wtok.c_str());
	if (rsP->space == 0) rsP->space = iSpaceDefault;

	if (!getline(wstm, wtok, L';')) return ERROR;
	rsP->offset[0] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->elemEDoffset = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->segmIndex = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->lap[0] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->lap[1] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->lap[2] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->bendrad = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
	{
		rsP->offset[1] = _wtoi(wtok.c_str());
		if (rsP->offset[1] > 0) rsP->offset[1] = 0;
		if (rsP->offset[1] < 0) rsP->offset[1] = -rsP->offset[1]; // для совместимости значение хранится с отриц. значением
	}

	if (getline(wstm, wtok, L';'))
		rsP->trm[0] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->trm[1] = _wtoi(wtok.c_str());


	// по умолчанию
	//rsP->trmPar[0][0] = 180;
	//rsP->trmPar[0][1] = -180;
	//rsP->trmPar[1][0] = getReinLapBend(rsP->diam, 0);
	//rsP->trmPar[1][1] = getReinLapBend(rsP->diam, 0);

	if (getline(wstm, wtok, L';'))
		rsP->trmPar[0][0] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->trmPar[0][1] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->trmPar[1][0] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->trmPar[1][1] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->trmPar[2][0] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->trmPar[2][1] = _wtoi(wtok.c_str());

	if (getline(wstm, wtok, L';'))
		rsP->poscalc = _wtoi(wtok.c_str());



#endif

*/

	return SUCCESS;

}


#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX


//////////////////////
bool attachECInstance(
	MSElementDescrP edP,   // elem where add
	ReinBar* rbP,
	WCharP className
)
{
	bool ret = false;

	ElementHandle elemNew(edP, false, true);
	EditElementHandle elem(edP, false, true);

	if (elemNew.GetElementRef() == NULL)
	{
		mdlOutput_messageCenter(MESSAGE_ERROR,
			L"WARNING: attachECInstance got null element ref", L"", OutputMessageAlert::Balloon);
		return false;
	}

	DgnFileP dfP = ISessionMgr::GetActiveDgnFile();
	DgnModelP dmP = ISessionMgr::GetActiveDgnModelP();
	DgnECInstanceEnablerP enablerP = Bentley::DgnPlatform::DgnECManager::GetManager().ObtainInstanceEnablerByName(
		L"ReinSchema", className, *dfP);
	
	if (enablerP == NULL) return ret;

	
	ECN::StandaloneECInstanceR wipInstance = enablerP->GetSharedWipInstance();


	wipInstance.SetValue(L"ReinBarDiameter", ECN::ECValue(rbP->diam));
	wipInstance.SetValue(L"ReinBarLenType", ECN::ECValue(rbP->runmet));

	if (rbP->bendrad) wipInstance.SetValue(L"ReinBarBend", ECN::ECValue(rbP->bendrad));
	if (rbP->poscalc) wipInstance.SetValue(L"ReinPosSet", ECN::ECValue(rbP->poscalc));

	if (rbP->term[0]) wipInstance.SetValue(L"ReinTerm1", ECN::ECValue(rbP->term[0]));
	if (rbP->term[1]) wipInstance.SetValue(L"ReinTerm2", ECN::ECValue(rbP->term[1]));

	if (rbP->term[0] == REIN_TERM_BEND)
	{
		wipInstance.SetValue(L"ReinBendType1", ECN::ECValue(rbP->termPar[0][0]));
		wipInstance.SetValue(L"ReinBendLen1", ECN::ECValue(rbP->termPar[1][0]));
	}

	if (rbP->term[1] == REIN_TERM_BEND)
	{
		wipInstance.SetValue(L"ReinBendType2", ECN::ECValue(rbP->termPar[0][1]));
		wipInstance.SetValue(L"ReinBendLen2", ECN::ECValue(rbP->termPar[1][1]));
	}

	if (rbP->term[0] == REIN_TERM_MUFT)
		wipInstance.SetValue(L"ReinMuftType1", ECN::ECValue(rbP->termPar[2][0]));

	if (rbP->term[1] == REIN_TERM_MUFT)
		wipInstance.SetValue(L"ReinMuftType2", ECN::ECValue(rbP->termPar[2][1]));


	//wipInstance.SetValue(L"ReinBarFlags", ECN::ECValue(rbP->barflags));

	wipInstance.SetValue(L"ReinBarSegmIndex", ECN::ECValue(rbP->segmIndex));
	wipInstance.SetValue(L"ReinBarEDOffset", ECN::ECValue(rbP->elemEDoffset));


	if (wcscmp(className, L"ReinSpace") == 0
		|| wcscmp(className, L"ReinCont") == 0
		)
	{
		wipInstance.SetValue(L"ReinBarSpacing", ECN::ECValue(rbP->spacef));
		wipInstance.SetValue(L"ReinLap", ECN::ECValue(rbP->lap[2]));

		if (rbP->lap[0]) wipInstance.SetValue(L"ReinLap1", ECN::ECValue(rbP->lap[0]));
		if (rbP->lap[1]) wipInstance.SetValue(L"ReinLap2", ECN::ECValue(rbP->lap[1]));

		if (rbP->offset[0]) wipInstance.SetValue(L"ReinBarOffset1", ECN::ECValue(rbP->offset[0]));
		if (rbP->offset[1]) wipInstance.SetValue(L"ReinBarOffset2", ECN::ECValue(rbP->offset[1]));


	}

	if (wcscmp(className, L"ReinCont") == 0)
	{
		wipInstance.SetValue(L"ReinContourType", ECN::ECValue(rbP->bartype));
		wipInstance.SetValue(L"ReinSpacingRad", ECN::ECValue(rbP->spacerad));
	}

	if (wcscmp(className, L"ContElem") == 0)
	{
		wipInstance.SetValue(L"ReinContNum", ECN::ECValue(rbP->contnum));
		wipInstance.SetValue(L"ReinElementID", ECN::ECValue((Int64)rbP->elemid));
	}






	UInt32 id = 0;

	//DgnECInstancePtr insP = getECInstance(L"ReinSchema", className, edP);

	//if (insP.IsValid())
	//{
	//	DgnElementECInstanceCP eiP = insP->GetAsElementInstance();
	//	id = eiP->GetLocalId();
	//}



	if (id > 0)
	{
		DgnModelRefP mrP = ACTIVEMODEL;
		DgnElementECInstancePtr firstInstance;
		enablerP->ScheduleReplaceInstanceOnElement(&firstInstance, wipInstance, *mrP, elem, id);

	}
	else
	{
		DgnElementECInstancePtr firstInstance;
		DgnECInstanceStatus status = enablerP->CreateInstanceOnElement(&firstInstance, wipInstance, elemNew);

	}

	return ret;
}
#endif


/////////////////////////////////////////////////////////////
UInt32 xmlAddReinElmdAttr(
			MSElementDescrP* edPP,   // elem where add
			ELID prid,
			int type, // ReinElm type REIN_ELEM_...
			ReinBar* rbP,
			UInt32* lev,
			DgnModelRefP mrToAddP,
			UInt32* ggN,
			BINT bLocked,
			int iLap,
			BINT bVisible,
			int iNumber
			)
{

	MSElementDescr* edP = NULL;
	MSWCH str[1000];
	MSWCH wstr[1000];
	int status = SUCCESS;
	XMLFragmentListP    pCurrent = NULL;
	UInt32 fp = 0;
	ELID barid = 0; // ELID
	ReinBar rb; // cleared in constr
	ReinBar* rbSaveP;
	int elflags = 0;
	int noplanar = 0;

	if (bRef) return 0;

	if (edPP == NULL) return 0;
	if (prid == 0) return 0;

	edP = *edPP;

	//ZeroMemory(&rb, sizeof(ReinBar));
	

	if (rbP) 
		rbSaveP = rbP;
	else
		rbSaveP = &rb;


	int trmp[6] = { 0 };
	//ZeroMemory(trmp, sizeof(trmp));


	if (rbP->term[0] == REIN_TERM_BEND)
	{
		trmp[0] = rbSaveP->termPar[0][0];
		trmp[2] = rbSaveP->termPar[1][0];
	}
	if (rbP->term[1] == REIN_TERM_BEND)
	{
		trmp[1] = rbSaveP->termPar[0][1];
		trmp[3] = rbSaveP->termPar[1][1];
	}
	if (rbP->term[0] == REIN_TERM_MUFT)
	{
		trmp[4] = rbSaveP->termPar[2][0];
	}
	if (rbP->term[1] == REIN_TERM_MUFT)
	{
		trmp[5] = rbSaveP->termPar[2][1];
	}


	if (rbSaveP && type == REIN_ELEM_ISO) barid = rbSaveP->brid;
	
	/*
	if (type == REIN_ELEM_BAR)
	{
#if defined (MSVERSION) && (MSVERSION == 0xa00)
		DgnFileP dfP = ISessionMgr::GetActiveDgnFile();
		int ind = DisplayStyleManager::GetIndexForDisplayStyle(L"Transparent", dfP);
		mdlElement_setDisplayStyle(&edP->el, ind);
#else
		DgnCacheP dfP = Bentley::Ustn::ISessionMgr::GetActiveDgnCache();
		wstring dsname = L"Transparent";
		int ind = Bentley::Ustn::DisplayStyleManager::GetIndexForDisplayStyle(*dsname.c_str(), dfP->GetMSDgnFile());
		mdlElement_setDisplayStyle(&edP->el, ind);
#endif
	}
	*/

	if (iCfgVar_BarCompare_3d) noplanar = 2;
	if (iCfgVar_BendNewDraw) elflags |= REINEL_FLAG_BEND;
	if (iCfgVar_BendNewDraw == 2) elflags |= REINEL_FLAG_RBND; // честный загиб

	if (rbSaveP->mainPtsIndex >= rbSaveP->numpts)  // иногда бывает так... почему - пока не понял
		rbSaveP->mainPtsIndex = rbSaveP->numpts - 1;


	_swprintf(str, L"REINELEM;%I64u;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%I64u;%i;%i;%i;%i;%i;%i;%i;%I64u;%i", 
			prid,
			type,
			rbSaveP->diam,
			rbSaveP->runmet,
			rbSaveP->transp,
			rbSaveP->numpts, // numpts == cnumpts
			rbSaveP->mainSgmIndex,
			rbSaveP->mainPtsIndex,
			iNumber, // порядовый номер в области или 0 для ReinBar
			rbSaveP->term[0],
			rbSaveP->term[1],
			trmp[0],
			trmp[1],
			trmp[2],
			trmp[3],
			trmp[4],
			trmp[5],
			rbSaveP->axid,
			iModelVers,
			rbSaveP->bendrad,
			rbSaveP->bartype,
			rbSaveP->poscalc,
			iLap, // разбежка, полож. - вначале, отриц. - в конце
			noplanar, // noplanar == 2 -> новый метод сравнения (3д)
			elflags, // element flags
			barid, // ELID for 3d bar element
			rbSaveP->grnd
		);

	if (iDebug) sprintf(sLogMes, "ReinElm string: %S\n", str); writeLog(0, 0);

	//mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 500);
	pCurrent = mdlXMLFragmentList_construct (str, NULL, appID, appTypeReinElm); 
	status = mdlXMLFragmentList_attachToElement(&pCurrent, &edP, TRUE);

	if (status)
	{
		mdlDialog_dmsgsPrint(L("_xmlAddReinElmdAttr() - _mdlXMLFragmentList_attachToElement() unsuccessful"));
		return 0;
	}


	//if (type == REIN_ELEM_ISO && bAddToFile) 
	//{
	//	xmlAddBarPoints(rbP, &edP);
	//	
	//	for (int i = 0; i < rbP->numsgts; i++)
	//	{
	//		xmlAddBarVerts(&rbP->sgts[i].rv[0], &edP, i, 0);
	//		xmlAddBarVerts(&rbP->sgts[i].rv[1], &edP, i, 1);
	//	}
	//}

	//if (bVisible && bAddToFile) mdlElmdscr_displayInSelectedViews(edP, MASTERFILE, NORMALDRAW, iLvlMask);

	if (lev) func_amp(mdlElmdscr_setProperties,edP), lev, 0, 0, 0, 0, 0, 0, 0);
	if (ggN) func_amp(mdlElmdscr_setProperties,edP), 0, ggN, 0, 0, 0, 0, 0, 0);
	if (bLocked) func_amp(mdlElmdscr_setProperties,edP), 0, 0, 0, &bLocked, 0, 0, 0, 0);
	
	// для одиночных стержней производный элемент невидимый
	//if (iNumber == 0 && type == REIN_ELEM_ISO) 
	//{
	//	//if (rbP) rbP->tdBar = mdlTransient_addElemDescr(rbP->tdBar, edP, TRUE, 0xff, NORMALDRAW, FALSE, FALSE, TRUE);
	//	mdlElmdscr_setVisible(edP, FALSE);
	//}
	//else
		mdlElmdscr_setVisible(edP, bVisible);


	//if (idAssocP) 
	//{
	//	ELID eid;
	//	status = mdlAssoc_tagElementDescr(&eid, &edP, 0, MASTERFILE, 0);
	//	mdlAssoc_tagElementValue(
	//}

	//mdlSystem_enterDebug();

	//if (status)
	//	mdlDialog_dmsgsPrint(L("_xmlAddReinElmdAttr() - _mdlAssoc_tagElementValue() unsuccessful"));


	//BRYS = TRUE; // чтобы не отрабатывал событие
	if (mrToAddP) fp = mdlElmdscr_addByModelRef(edP, mrToAddP);
	//BRYS = FALSE;

	//attachECInstance(edP, rbSaveP, L"ReinBar"); // "ReinDerived"

	//printf("%i\n", fp);

	if (iDebug) sprintf(sLogMes, "ReinElm added, fp = %u\n", fp); writeLog(0, 0);

	// замена в массиве отображения
	//for (UInt32 i = 0; i < iIDcount; i++)
	//{
	//	if (prid == arID[i])
	//	{
	//		arFP[iFPcount] = fp;
	//		iFPcount++;
	//	}
	//}

	for (map<ELID,bool>::iterator it = curRM->vExIds.begin() ; it != curRM->vExIds.end(); ++it)
	{
		if (prid == it->first && it->second)
		{
			curRM->vExFps[fp] = true;
		}
	}



	return fp;

}

/////////////////////////////////////////////////////////////////
int xmlAddBarPoints(ReinBar* rbP, MSElementDescr** edpP)
{

	MSWCH wstr[200];
	WCH str[200];
	XMLFragmentListP    pCurrent = NULL;
	XMLFragmentListP    pCurrentTmp = NULL;
	XMLFragmentP    pFrgm = NULL;
	int status;
	MSElementDescr* edp;
	int cnt = 0;

	if (rbP == NULL) return 0;
	if (edpP == NULL) return 0;

	edp = *edpP;
		
	writeLogIn(__FUNCTION__, 0);

	//if (rbP->apts.size() != rbP->cpxb.size()) { printf("kernel panic!");  return 0; }
	//if (rbP->apts.size() != rbP->cpxe.size()) { printf("kernel panic!"); return 0; }
	//if (rbP->apts.size() != rbP->rfa.size()) { printf("kernel panic!"); return 0; }

	//======================================

	for (int i = 0; i < rbP->numpts; i++) // numpts == cnumpts
	//for (size_t i = 0; i < rbP->apts.size(); i++) // numpts == cnumpts
	{

		int i_rfa = 0;
		if (rbP->rfa[i] & RFA_ARCP || rbP->rfa[i] & RFA_CIRP) i_rfa = RFA_ARCP;

		_swprintf(wstr, L"BARPOINT;%.7f;%.7f;%.7f;%i;%i;%i;%i;%i;%i;%i",
				rbP->apts[i].x,		// 0
				rbP->apts[i].y,		// 1
				rbP->apts[i].z,		// 2
				rbP->cpxb[i].x, 	// 3
				rbP->cpxb[i].y,		// 4
				rbP->cpxb[i].z,		// 5
				rbP->cpxe[i].x, 	// 6
				rbP->cpxe[i].y,		// 7
				rbP->cpxe[i].z,		// 8
				i_rfa				// 9
				);

		//SCPM2W(wstr, str, 200);

		pCurrentTmp = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeBarPoints); 

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		pFrgm = mdlXMLFragmentList_getXMLFragment(pCurrentTmp);
		mdlXMLFragmentList_append (&pCurrent, pFrgm);
#else
        if (pCurrent)
            mdlXMLFragmentList_append (&pCurrent, pCurrentTmp);
        else
            pCurrent = pCurrentTmp;
#endif
		_swprintf(wss, L"%s\n", wstr); writeLogW(wss, 0);

		cnt++;

	}

	if (pCurrent)
		status = mdlXMLFragmentList_attachToElement(&pCurrent, edpP, TRUE);

	if (iDebug) sprintf(sLogMes, "cnt = %i\n", cnt); writeLog(0, 0);
	writeLogOut(__FUNCTION__, 0);

	return cnt;

}


//////////////////////////////////////////////////
int readReinClashFromString(ReinClash* raP, wstring str)
{

	if (raP == NULL) return ERROR;
	if (str.length() == 0) return ERROR;

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	SETSTR_BEGIN_ITER;
	if (*it != L"BARCLASH") return ERROR;

	IF_IT_nxt IF_IT_end return SUCCESS;
	raP->cdiam[0] = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	raP->cdiam[1] = _wtof(it->c_str());

	IF_IT_nxt IF_IT_end return SUCCESS;
	raP->fpElem[0] = wcstoul(it->c_str(),0,0);

	IF_IT_nxt IF_IT_end return SUCCESS;
	raP->fpElem[1] = wcstoul(it->c_str(),0,0);

	IF_IT_nxt IF_IT_end return SUCCESS;
	raP->idist = wcstoul(it->c_str(),0,0);

	IF_IT_nxt IF_IT_end return SUCCESS;
	raP->lvID[0] = wcstoul(it->c_str(),0,0);

	IF_IT_nxt IF_IT_end return SUCCESS;
	raP->lvID[1] = wcstoul(it->c_str(),0,0);

	IF_IT_nxt IF_IT_end return SUCCESS;
	if (swscanf(it->c_str(), L"%I64u", &raP->idElem3d[0]) != 1) return SUCCESS;

	IF_IT_nxt IF_IT_end return SUCCESS;
	if (swscanf(it->c_str(), L"%I64u", &raP->idElem3d[1]) != 1) return SUCCESS;


	/*

	WCH seps[] = L(";");
	WCH* token;


	token = STOK(str, seps);
	if (token == NULL)	return ERROR;
	if (SCNP(token, L("BARCLASH"), SLEN(L("BARCLASH"))) != 0) return ERROR;

	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	raP->cdiam[0] = STOF(token);

	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	raP->cdiam[1] = STOF(token);

	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	raP->fpElem[0] = STOUL(token,0,0);

	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	raP->fpElem[1] = STOUL(token, 0, 0);

	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	raP->idist = STOUL(token, 0, 0);

	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	raP->lvID[0] = STOUL(token, 0, 0);

	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	raP->lvID[1] = STOUL(token, 0, 0);

	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	//raP->idElem3d[0] = STOUL(token,0,0);
	if (SSCAN(token, L("%I64u"), &raP->idElem3d[0]) != 1) return SUCCESS;

	token = STOK(NULL, seps);
	if (token == NULL)	return SUCCESS;
	//raP->idElem3d[1] = STOUL(token, 0, 0);
	if (SSCAN(token, L("%I64u"), &raP->idElem3d[1]) != 1) return SUCCESS;
	*/


	return SUCCESS;
}


////////////////////////////////////////////////////////////
int readReinClashFromElement(ReinClash* rcP, MSElement* elP)
{
	XMLFragmentListP  oXMLFragmentList = NULL;

	rcP->clear();

	if (!mdlElement_hasXMLFragmentAttachment(elP, &appID, &appTypeBarOver)) return ERROR;

	if (mdlXMLFragmentList_extractFromElementByAppIDAndType(&oXMLFragmentList, elP,
		&appID, &appTypeBarOver) == SUCCESS)
	{
		XMLFragmentP  pXMLFragment;
		MSWCH* wtxt;
		//WCH ctxt[500];
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);
			if (readReinClashFromString(rcP, wstr) != SUCCESS)
				return ERROR;

			mdlXMLFragmentList_free(&oXMLFragmentList);
		}
	}
	else
		return ERROR;

	return SUCCESS;
}

///////////////////////////////////////////////////////////
int xmlAddClash(ReinClash* rcP, MSElementDescr** edpP)
{

	MSWCH wstr[500];
	XMLFragmentListP    pCurrent = NULL;
	int status;


	_swprintf(wstr, L"BARCLASH;%.10f;%.10f;%u;%u;%u;%u;%u;%I64u;%I64u"
		, rcP->cdiam[0]
		, rcP->cdiam[1]
		, rcP->fpElem[0]
		, rcP->fpElem[1]
		, rcP->idist
		, rcP->lvID[0]
		, rcP->lvID[1]
		, rcP->idElem3d[0]
		, rcP->idElem3d[1]
	);

	pCurrent = mdlXMLFragmentList_construct(wstr, NULL, appID, appTypeBarOver);

	if (pCurrent)
		status = mdlXMLFragmentList_attachToElement(&pCurrent, edpP, TRUE);

	return status;

}



///////////////////////////////////////////////////////////
int xmlAddBarOverrides(ReinElement* reP, MSElementDescr** edpP)
{

	MSWCH wstr[500];
	char str[500];
	XMLFragmentListP    pCurrentTmp = NULL;
	XMLFragmentListP    pCurrent = NULL;
	int status;
	int cnt = 0;


	for (map<int, BarOver>::iterator it = reP->mapOvers.begin(); it != reP->mapOvers.end(); ++it)
	{
		_swprintf(wstr, L"BAROVER;%i;%i;%i;%.10f;%.10f;%.10f;%.10f;%.10f;%.10f;%.10f;%.10f;%.10f;%.10f;%.10f;%.10f;%i"
			, it->second.inum
			, it->second.isdel
			, it->second.btmov
			, it->second.tmov.form3d[0][0]
			, it->second.tmov.form3d[0][1]
			, it->second.tmov.form3d[0][2]
			, it->second.tmov.form3d[0][3]
			, it->second.tmov.form3d[1][0]
			, it->second.tmov.form3d[1][1]
			, it->second.tmov.form3d[1][2]
			, it->second.tmov.form3d[1][3]
			, it->second.tmov.form3d[2][0]
			, it->second.tmov.form3d[2][1]
			, it->second.tmov.form3d[2][2]
			, it->second.tmov.form3d[2][3]
			, it->second.isgnd
		);

		pCurrentTmp = mdlXMLFragmentList_construct(wstr, NULL, appID, appTypeBarOver);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		XMLFragmentP pFrgm = mdlXMLFragmentList_getXMLFragment(pCurrentTmp);
		mdlXMLFragmentList_append(&pCurrent, pFrgm);
#else
		if (pCurrent)
			mdlXMLFragmentList_append(&pCurrent, pCurrentTmp);
		else
			pCurrent = pCurrentTmp;
#endif

		cnt++;

	}

	if (pCurrent)
		status = mdlXMLFragmentList_attachToElement(&pCurrent, edpP, TRUE);

	return cnt;

}

///////////////////////////////////////////////////////////
int xmlAddSpacePoints(ReinSpace* rsP, MSElementDescr** edpP)
{

	MSWCH wstr[100];
	char str[100];
	XMLFragmentListP    pCurrentOrg = NULL;
	XMLFragmentListP    pCurrentEnd = NULL;
	XMLFragmentListP    pCurrentTmp = NULL;
	XMLFragmentP    pFrgm = NULL;
	int status;
	int i;
	MSElementDescr* edp;
	int cnt = 0;

	if (rsP == NULL) return 0;
	if (edpP == NULL) return 0;

	edp = *edpP;
		

	// origin points
	//======================================

	for (i = 0; i < rsP->pts_org_cnt; i++)
	{
		_swprintf(wstr, L"REINPOINT;%.03f;%.03f;%.03f;%i",
				rsP->pts_org[i].pVrtx.x, 
				rsP->pts_org[i].pVrtx.y, 
				rsP->pts_org[i].pVrtx.z,
				rsP->pts_org[i].flg
				);

		//status = mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 100);

		pCurrentTmp = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeOrgPoints); 

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		pFrgm = mdlXMLFragmentList_getXMLFragment(pCurrentTmp);
        mdlXMLFragmentList_append (&pCurrentOrg, pFrgm);
#else
        if (pCurrentOrg)
            mdlXMLFragmentList_append (&pCurrentOrg, pCurrentTmp);
        else
            pCurrentOrg = pCurrentTmp;
#endif

		cnt++;
	}

	if (pCurrentOrg)
		status = mdlXMLFragmentList_attachToElement(&pCurrentOrg, edpP, TRUE);



	// end points
	//======================================

	for (i = 0; i < rsP->pts_end_cnt; i++)
	{
		sprintf(str, "REINPOINT;%.03f;%.03f;%.03f;%i",
				rsP->pts_end[i].pVrtx.x, 
				rsP->pts_end[i].pVrtx.y, 
				rsP->pts_end[i].pVrtx.z,
				rsP->pts_end[i].flg
				);

		status = mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 100);

		pCurrentTmp = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeEndPoints); 

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		pFrgm = mdlXMLFragmentList_getXMLFragment(pCurrentTmp);
        mdlXMLFragmentList_append (&pCurrentOrg, pFrgm);
#else
        if (pCurrentOrg)
            mdlXMLFragmentList_append (&pCurrentOrg, pCurrentTmp);
        else
            pCurrentOrg = pCurrentTmp;
#endif

		cnt++;

	}

	if (pCurrentEnd)
		status = mdlXMLFragmentList_attachToElement(&pCurrentEnd, edpP, TRUE);


	return cnt;

}


////////////////////////////////
UInt32 createReinSpaceElement(MSElementDescr** edP, ReinSpace* rsP, UInt32 fpos, DgnModelRefP mrP, int bUpdateConfig, int bAdd, ReinElement* reP)
{

	MSWCH wstr[200];
	char str[200];
	XMLFragmentListP    pCurrent = NULL;
	int status;
	UInt32 fp = 0;
	MSElementDescr* edp = NULL;


	if (edP == NULL) return fp;


	edp = *edP;


	writeLogIn(__FUNCTION__, 0);
	if (iDebug) sprintf(sLogMes, "fpos = %u\n", fpos); writeLog(0, 0);

	int trmp[6] = { 0 };
	//ZeroMemory(trmp, sizeof(trmp));

	if (rsP->trm[0] == REIN_TERM_BEND)
	{
		trmp[0] = rsP->trmPar[0][0];
		trmp[2] = rsP->trmPar[1][0];
	}
	if (rsP->trm[1] == REIN_TERM_BEND)
	{
		trmp[1] = rsP->trmPar[0][1];
		trmp[3] = rsP->trmPar[1][1];
	}
	if (rsP->trm[0] == REIN_TERM_MUFT)
	{
		trmp[4] = rsP->trmPar[2][0];
	}
	if (rsP->trm[1] == REIN_TERM_MUFT)
	{
		trmp[5] = rsP->trmPar[2][1];
	}

	if ((int)rsP->spacef == 0) rsP->spacef = (double)iSpaceDefault;
	//if (rsP->space2 <= 0) rsP->space2 = iSpaceDefault;

	if (rsP != NULL)
	{
		_swprintf(wstr, L"REINSPACE;%i;%i;%.1f;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i",
			rsP->runmet, 
			rsP->diam,
			rsP->spacef, 
			rsP->offset[0],
			rsP->elemEDoffset,
			rsP->segmIndex,
			rsP->lap[0],
			rsP->lap[1],
			rsP->lap[2],
			rsP->bendrad,
			-rsP->offset[1],
			rsP->trm[0],
			rsP->trm[1],
			trmp[0],
			trmp[1],
			trmp[2],
			trmp[3],
			trmp[4],
			trmp[5],
			rsP->poscalc,
			0 // reserved
			);
	}
	else
	{
		_swprintf(wstr, L"REINSPACE;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i",
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	}


	//_swprintf(wss, L"created space config '%s'\n", wstr); writeLogW(wss, 0);

	//status = mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 100);


	pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeReinSpace); 

	if (pCurrent)
	{

		if (iDebug) sprintf(sLogMes, "created xml fragment\n"); writeLog(0, 0);

#if defined (MSVERSION) && (MSVERSION == 0xa00) // xml
		mdlXMLFragmentList_stripFromElementByAppIDAndType(NULL, &edp->el, &appID, &appTypeReinSpace);
		mdlXMLFragmentList_stripFromElementByAppIDAndType(NULL, &edp->el, &appID, &appTypeBarOver);
		if (bUpdateConfig) mdlXMLFragmentList_stripFromElementByAppIDAndType(NULL, &edp->el, &appID, &appTypeOrgPoints);
		if (bUpdateConfig) mdlXMLFragmentList_stripFromElementByAppIDAndType(NULL, &edp->el, &appID, &appTypeEndPoints);
#else
		mdlXMLFragmentList_stripFromElement(&edp->el, &appID, &appTypeReinSpace, NULL, NULL);
		mdlXMLFragmentList_stripFromElement(&edp->el, &appID, &appTypeBarOver, NULL, NULL);
		if (bUpdateConfig) mdlXMLFragmentList_stripFromElement(&edp->el, &appID, &appTypeOrgPoints, NULL, NULL);
		if (bUpdateConfig) mdlXMLFragmentList_stripFromElement(&edp->el, &appID, &appTypeEndPoints, NULL, NULL);

#endif

		status = mdlXMLFragmentList_attachToElement(&pCurrent, &edp, TRUE);

		if (status == SUCCESS && bAdd)
		{
			int cnt = 0;
			ReinBar rb;
			copySpaceData(rsP, &rb, TRUE, NULL, 0); // for ECInstance

			if (iDebug) sprintf(sLogMes, "attach xml to element success\n"); writeLog(0, 0);

			if (bUpdateConfig) cnt = xmlAddSpacePoints(rsP, &edp);
			//printf("cnt = %i\n", cnt);
			
			if (iDebug) {
				if (cnt > 0) sprintf(sLogMes, "added %i points\n", cnt); writeLog(0, 0);
			}

			if (reP) xmlAddBarOverrides(reP, &edp);

			if (fpos > 0)
			{
#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX att
				//attachECInstance(edp, &rb, L"ReinSpace");
#endif

				fp = mdlElmdscr_rewrite(edp, NULL, fpos);
				if (fp == 0)
				{
					//SPRN(s, L("mdlElmdscr_rewrite - > mdlErrno = %i"), mdlErrno);
					if (iDebug) sprintf(sLogMes, "mdlElmdscr_rewrite() failed, mdlErrno=%i\n", mdlErrno); writeLog(0, 0);
					//mdlDialog_dmsgsPrint(s);
				}
			}
			else
			{
				fp = mdlElmdscr_add(edp);
				if (fp == 0)
				{
					//SPRN(s, L("mdlElmdscr_add - > mdlErrno = %i"), mdlErrno);
					if (iDebug) sprintf(sLogMes, "mdlElmdscr_add() failed, mdlErrno=%i\n", mdlErrno); writeLog(0, 0);
					//mdlDialog_dmsgsPrint(s);
				}

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX att
				//attachECInstance(edp, &rb, L"ReinSpace");
#endif
			}



			mdlElmdscr_display(edp, MASTERFILE, DRAW_MODE_Normal);

		}
		else if (status != SUCCESS)
		{
			if (iDebug) sprintf(sLogMes, "attach xml to element failed\n"); writeLog(0, 0);
		}
	}

	if (iDebug) sprintf(sLogMes, "return %u\n", fp); writeLog(0, 0);
	writeLogOut(__FUNCTION__, 0);

	return fp;

}
/*
///////////////////////////////////
int iterateClashElms( // 
	ElementRef eref, 
	void* callbackArg, 
	ScanCriteriaP scP
)
{
	TransDescrP tedP = mdlTransientElemRef_getTDP(eref);

	if (tedP) mdlTransient_free(&tedP, TRUE);

	return SUCCESS;
}
*/

///////////////////
// func: clear all clashes
// todo: view process
void clearClash(int view) // -1 - all views
{

	writeLogIn(__FUNCTION__, 0);

	if (mapClash.size() > 50)
		dlgProgressP = mdlDialog_completionBarOpen(L("Очистка маркеров коллизий..."));

	size_t cnt = 0;
	size_t cntt = mapClash.size();

	for (map<UInt32pair, ReinClash>::iterator it = mapClash.begin(); it != mapClash.end(); ++it)
	//for (const auto& entry : mapClash)
	{
		//MSElementDescr* edP = mdlTransientElemRef_getEDP(it->second.erefClsh);
		TransDescrP tedP = mdlTransientElemRef_getTDP(it->second.erefClsh);

		if (tedP) mdlTransient_free(&tedP, FALSE);

		//mapClash.erase(it);

		if (dlgProgressP)
		{
			mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)(((double)cnt / (double)cntt) * 100.));
			WaitMessage();
		}

		cnt++;

		//if (edP && view >= 0)
		//{
		//	//if (mdlElement_isEffectivelyVisible(&edP->el, TRANSIENT_MODELREF, view))
		//	//	__asm nop;
		//	//else
		//	//	__asm nop;
		//}
	}


	mapClash.clear();

	if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);








	/*
	MSElementDescr* edP;
	UInt32      scanBuf[1024], eofPos, filePos, realPos;
	int         scanWords, status, i, numAddr;
	bool         threeD = true;
	//ViewFlags       viewflags;
	RotMatrix       rotMatrix;
	Dpoint3d        origin, extent;
	ScanCriteria* scP;

	mdlView_getParameters(&origin, NULL, &extent, &rotMatrix, NULL, view);

	if (tcb->ndices == 2) threeD = false;

	//viewflags.patterns = TRUE;
	//viewflags.on_off = TRUE;
	//viewflags.constructs = TRUE;
	//viewflags.dimens = TRUE;
	//viewflags.fast_text = TRUE;
	//viewflags.line_wghts = FALSE;
	//viewflags.fast_cell = FALSE;
	//viewflags.text_nodes = FALSE;
	//viewflags.ed_fields = FALSE;
	//viewflags.grid = FALSE;
	//viewflags.lev_symb = FALSE;
	//viewflags.def = FALSE;


	DgnModelRefP mrP = TRANSIENT_MODELREF;

	scP = mdlScanCriteria_create();
	mdlScanCriteria_setReturnType(scP, MSSCANCRIT_RETURN_FILEPOS, FALSE, TRUE);
	//mdlScanCriteria_setViewRangeTest(scP, view, mrP);
	mdlScanCriteria_setModel(scP, mrP);
	mdlScanCriteria_setStartFilePos(scP, 0);

	eofPos = mdlElement_getFilePos(FILEPOS_EOF, NULL);
	filePos = 0L;
	realPos = 0L;

	scanWords = sizeof(scanBuf) / sizeof(short);

	do
	{
		status = mdlScanCriteria_scan(scP, scanBuf, &scanWords, 0);
		numAddr = scanWords / sizeof(short);

		for (i = 0; i < numAddr; i++)
		{
			if (scanBuf[i] >= eofPos)
				break;

			if (scanBuf[i] < realPos)
				continue;

			//if (mdlElmdscr_read(&edP, scanBuf[i], 0, FALSE, &realPos) != 0)
			//{
			//	mdlElmdscr_displayToWindow((MSWindow*)dbP, &diP->rect, &viewflags, edP, &rotMatrix, &origin, &extent, threeD, -1);
			//	mdlElmdscr_freeAll(&edP);
			//}
		}

	} while (status == BUFF_FULL);

	*/
	

	/*
	ScanCriteria* scP;
	int             status;


	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMREF, FALSE, TRUE);
	status = mdlScanCriteria_setElemRefCallback(scP, (PFScanElemRefCallback)iterateClashElms, 0);
	status = mdlScanCriteria_setDrawnElements(scP);
	status = mdlScanCriteria_setStartFilePos(scP, 200);
	status = mdlScanCriteria_setModel(scP, TRANSIENT_MODELREF);

	//if (view >= 0) 
	//	status = mdlScanCriteria_setViewRangeTest(scP, view, TRANSIENT_MODELREF);

	status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
	status = mdlScanCriteria_free(scP);

*/


	writeLogOut(__FUNCTION__, 0);


}


/////////////////////////////////////////////
// очистка стержней и их данных
void clearBarsData(int bDelete)
{

	writeLogIn(__FUNCTION__, 0);
	if (iDebug) sprintf(sLogMes, "bDelete = %i \n", bDelete); writeLog(0, 0);



	if (bDelete)
	{
		clearClash(-1);

		deleteReinElms(0, TRUE, NULL);

		//mdlSystem_compressDgnFile();

		//DgnCacheP a = mdlModelRef_getCache(ACTIVEMODEL);
		//a->Empty();

	}

	writeLogOut(__FUNCTION__, 0);


}



/////////////////////////////////////////////
// перегрузка данных, включая регенерацию
// iREType - по типу, пока не работает, перегружается всё
void reloadBarsData(int iREType, int bRegen, int iStep)
{


	ScanCriteria    *scP;
	int             status;
	UShort          typeMask[6];
	//ELID elidView[8];
	//int i;


	iElemIDcount = 0;


	writeLogIn(__FUNCTION__, 0);
	if (iDebug) sprintf(sLogMes, "iREType = %i  bRegen = %i \n", iREType, bRegen); writeLog(0, 0);

	posNumMax = 0; // for correct posNumMax updating

	bRef = FALSE;

	if (bRegen && (iStep == 0 || iStep == 1)) clearBarsData(bRegen);

	if (bRegen && iStep == 4) combAxisElem(FALSE);

	if (bRegen && iStep == 5) combAxisElem(TRUE);

	if (bRegen && (iStep == 0 || iStep == 2))
	{

		for (UShort a = 0; a < 6; a++) typeMask[a] = 0;

		typeMask[0] = TMSK0_SHAPE | 
						TMSK0_CMPLX_SHAPE | 
						TMSK0_LINE | 
						TMSK0_ARC | 
						TMSK0_LINE_STRING | 
						TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;

		typeMask[1] = TMSK1_SURFACE;

		//mdlTMatrix_getIdentity (&tmFromRef);
		//mdlRMatrix_getIdentity(&rmFromRef);



		if (iDebug) sprintf(sLogMes, "load active file...\n"); writeLog(0, 0);

		BRYS = TRUE; // при регенерации заполнение данных проводим позже

		scP = mdlScanCriteria_create ();
		pIterScanCrit = scP;
		status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
		status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)iterateReloadBarsData, &bRegen);
		status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));

		status = mdlScanCriteria_setModel (scP,MASTERFILE);
		status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
		status = mdlScanCriteria_free (scP);
		pIterScanCrit = NULL;


		// todo reload - проверка на рудимент - зачем референсы для регенерации?
		{
			ModelRefIteratorP  iterator;
			DgnModelRefP	modelRef;

			mdlModelRefIterator_create (&iterator, MASTERFILE, MRITERATE_PrimaryChildRefs, 0);


			if (iDebug) sprintf(sLogMes, "load references...\n"); writeLog(0, 0);

			while (NULL != (modelRef = mdlModelRefIterator_getNext (iterator)))
			{

				BINT isOn = FALSE;
				mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
				if (isOn == FALSE) continue;

				bRef = TRUE;

				//{
				//	DVec3d pr[2];
				//	mdlVec_zero(&pr[0]);
				//	pr[1] = rfP->display.mast_org;
				//	mdlLine_create(&el, &c3w1s0, pr);
				//	mdlElement_display(&el, NORMALDRAW);
				//	pr[1] = rfP->display.ref_org;
				//	mdlLine_create(&el, &c0w1s0, pr);
				//	mdlElement_display(&el, NORMALDRAW);
				//}

				//mdlTMatrix_referenceToMaster (&tmFromRef, modelRef);
				//mdlRMatrix_fromTMatrix(&rmFromRef, &tmFromRef);


				scP = mdlScanCriteria_create ();
				pIterScanCrit = scP;
				status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
				status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)iterateReloadBarsData, &bRegen);
				status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));

				//mdlScanCriteria_setReferenceFile(scP,rfP);
				status = mdlScanCriteria_setModel (scP,modelRef);
				status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
				status = mdlScanCriteria_free (scP);
				pIterScanCrit = NULL;

			}

			
			mdlModelRefIterator_free (&iterator);

		}


	}


	//mdlTMatrix_getIdentity (&tmFromRef);
	//mdlRMatrix_getIdentity(&rmFromRef);

	bRef = FALSE;


	BRYS = FALSE;


	if (iStep == 0 || bRegen == FALSE)
	{
		reloadCurBarsAll(TRUE); // always with references

		//reloadHidingPositions(); everythin already loaded before us

		syncShowInfo();
	}



	iElemIDcount = 0;



	//{
	//	int num1, ii;
	//	ReinElement* reP1;
	//	num1 = mdlDArray_nMembers(daCurElements);
	//	printf(">>>>>>>>>>>>>>  %i <<<<<<<<<<<<<<<<<<\n", num1);
	//	for (ii = 0; ii < num1; ii++)
	//	{
	//		reP1 = mdlDArray_getMemberP(daCurElements, ii);
	//		printf("%i %i\n", ii+1, reP1->idRS);
	//	}
	//}


	
	writeLogOut(__FUNCTION__, 0);


}

/**
* удаляет производные элементы,
* принадлежащие элементу edP (1-й аргумент)
* @param MSElementDescr edP - образующий элемент
* @param int bUseScanRange - ограничить скан
* @return void
*/
void reinBarsDataDel(
MSElementDescr  *edP, // образующий элемент
int bUseScanRange // ограничить скан
)
{

	ELID id;
	//int i, num;
	//ReinElement* reP;
	//ReinBar* rpP;
	//int ii;

	writeLogIn(__FUNCTION__, 0);


	if (edP == NULL) return;

	id = mdlElement_getID(&edP->el);
	if (id == 0) return;

	ReinModel* rmP = curRM;

	if (bUseScanRange) 
	{
		ScanRange sr;
		DVec3d prng[2];
		int cnt = 0;

		for (map<UInt32, ReinElm>::iterator it = rmP->mapElms.begin(); it != rmP->mapElms.end(); ++it)
		//for (UInt32 i = 0; rmP && i < rmP->vecElms.size(); i++)
		{
			ReinElm* reP = &(it->second);

			if (reP && id == reP->bel.elemid)
			{
				MSElementDescr* edpTmp = NULL;
				mdlElmdscr_read(&edpTmp, reP->bel.ffpos[REIN_ELEM_ISO], ACTIVEMODEL, 0, 0);
				if (edpTmp)
				{
					ScanRange srTmp;

					mdlElmdscr_computeRange(&prng[0], &prng[1], edpTmp, NULL);
					mdlElmdscr_freeAll(&edpTmp);

					if (cnt == 0)
					{
						sr.xlowlim = (Int64)(prng[0].x - mdlCnv_masterUnitsToUors(dDupTol));
						sr.ylowlim = (Int64)(prng[0].y - mdlCnv_masterUnitsToUors(dDupTol));
						sr.zlowlim = (Int64)(prng[0].z - mdlCnv_masterUnitsToUors(dDupTol));

						sr.xhighlim = (Int64)(prng[1].x + mdlCnv_masterUnitsToUors(dDupTol));
						sr.yhighlim = (Int64)(prng[1].y + mdlCnv_masterUnitsToUors(dDupTol));
						sr.zhighlim = (Int64)(prng[1].z + mdlCnv_masterUnitsToUors(dDupTol));
					}
					else
					{
						srTmp.xlowlim = (Int64)(prng[0].x - mdlCnv_masterUnitsToUors(dDupTol));
						srTmp.ylowlim = (Int64)(prng[0].y - mdlCnv_masterUnitsToUors(dDupTol));
						srTmp.zlowlim = (Int64)(prng[0].z - mdlCnv_masterUnitsToUors(dDupTol));

						srTmp.xhighlim = (Int64)(prng[1].x + mdlCnv_masterUnitsToUors(dDupTol));
						srTmp.yhighlim = (Int64)(prng[1].y + mdlCnv_masterUnitsToUors(dDupTol));
						srTmp.zhighlim = (Int64)(prng[1].z + mdlCnv_masterUnitsToUors(dDupTol));

						if (srTmp.xlowlim < sr.xlowlim) sr.xlowlim = srTmp.xlowlim;
						if (srTmp.ylowlim < sr.ylowlim) sr.ylowlim = srTmp.ylowlim;
						if (srTmp.zlowlim < sr.zlowlim) sr.zlowlim = srTmp.zlowlim;

						if (srTmp.xhighlim > sr.xhighlim) sr.xhighlim = srTmp.xhighlim;
						if (srTmp.yhighlim > sr.yhighlim) sr.yhighlim = srTmp.yhighlim;
						if (srTmp.zhighlim > sr.zhighlim) sr.zhighlim = srTmp.zhighlim;
					}


					cnt++;

				}
			}
		}

		deleteReinElms(id, FALSE, &sr);
/*
			ups_cursor_t *cursor;
			ups_record_t rec;
			ups_key_t key;

			//ZeroMemory(&key, sizeof(key));
			//ZeroMemory(&rec, sizeof(rec));

			upst = ups_cursor_create(&cursor, rmP->updb, 0, 0);

			if (upst == UPS_SUCCESS)
			{
				upst = ups_cursor_move(cursor, &key, &rec, UPS_CURSOR_FIRST);
				if (upst == UPS_SUCCESS)
				{
					do 
					{
						ReinElm* relmP = (ReinElm*)rec.data;


						upst = ups_cursor_move(cursor, &key, &rec, UPS_CURSOR_NEXT);

					} while (upst == UPS_SUCCESS);
				}
				ups_cursor_close(cursor);
			}

*/
	}
	else
	{
		deleteReinElms(id, FALSE, NULL); // работает медленно, не должно использоваться
	}


	writeLogOut(__FUNCTION__, 0);

}

//////////////////////////////////////////////////////
int reinCreateTangentArc(DVec3d* pArcPts, DVec3d* pLnPts, DVec3d* pt, double radius, int i, int bAnker)
{

	writeLogIn(__FUNCTION__, 0);


	//DVec3d pArcPts[3];
	DVec3d pps[3];
	DVec3d pTan;
	DVec3d p[2];
	DVec3d pTanFrom;
	MSElementDescr* edp;
	RotMatrix rm;

	mdlRMatrix_getIdentity(&rm);


	//printf("%i  %i  \n", i, cnt);

	if (i==0)
	{
		pps[0] = pt[2];
		pps[1] = pt[1];
		pps[2] = pt[0];
	}
	else
	{
		pps[0] = pt[0];
		pps[1] = pt[1];
		pps[2] = pt[2];
	}

	pTanFrom = pps[2];

	mdlVec_subtract(&pArcPts[0], &pps[0], &pps[1]);
	mdlVec_subtract(&pArcPts[1], &pps[2], &pps[1]);

	mdlVec_crossProduct(&pArcPts[2], &pArcPts[0], &pArcPts[1]);
	mdlVec_crossProduct(&pArcPts[1], &pArcPts[2], &pArcPts[0]);

	mdlRMatrix_fromNormalVector(&rm, &pArcPts[2]);

	mdlVec_scaleToLengthInPlace(&pArcPts[0], radius);
	mdlVec_scaleToLengthInPlace(&pArcPts[1], radius);



	mdlVec_addPoint(&pArcPts[2], &pArcPts[0], &pArcPts[1]); // в центр

	if (bAnker)
	{
		double dAnkLen = mdlVec_distance(&pps[1], &pps[2]) - fc_pi * radius;

		mdlVec_addPoint(&pArcPts[2], &pArcPts[2], &pArcPts[1]);

		mdlVec_scaleToLength(&pLnPts[0], &pArcPts[0], dAnkLen);
		mdlVec_addInPlace(&pLnPts[0], &pArcPts[2]);
		mdlVec_addInPlace(&pLnPts[0], &pps[1]);

		mdlVec_addInPlace(&pArcPts[0], &pps[1]);
		mdlVec_addInPlace(&pArcPts[1], &pps[1]);
		mdlVec_addInPlace(&pArcPts[2], &pps[1]);

		pLnPts[1] = pArcPts[2];

		//mdlLine_create(&el, &c3w5s0, pLnPts);
		//mdlElement_display(&el, NORMALDRAW);

		//mdlArc_createByPoints (&elTmp, &c3w5s0, pArcPts);
		//mdlElement_display(&elTmp, NORMALDRAW);

	}
	else
	{
		mdlVec_addPoint(&pArcPts[2], &pArcPts[2], &pArcPts[0]);

		mdlVec_addInPlace(&pArcPts[0], &pps[1]);
		mdlVec_addInPlace(&pArcPts[1], &pps[1]);
		mdlVec_addInPlace(&pArcPts[2], &pps[1]);



		mdlArc_createByPoints (&elTmp, &c3w5s0, pArcPts);
		//mdlCircle_createBy3Pts(&elTmp, &c3w1s0, pArcPts, 0);
		//mdlElement_display(&elTmp, NORMALDRAW);

		mdlElmdscr_new(&edp, 0, &elTmp);


		if (mdlProject_tangent(&pTan, &p[0], &p[1], edp, edp->h.dgnModelRef, &pTanFrom, &rm, &pArcPts[2], 100.) == SUCCESS)
		{
			//DVec3d pln[2];
			//pln[0] = pTan;
			//pln[1] = pTanFrom;
			//mdlLine_create(&el, &c3w1s0, pln);
			//mdlElement_display(&el, NORMALDRAW);
		}
		else
		{
			writeLogOut(__FUNCTION__, "mdlProject_tangent not success");
			return ERROR;
		}

		mdlElmdscr_freeAll(&edp);

		//mdlArc_createByPoints (&elTmp, &c3w5s0, pArcPts);
		////mdlCircle_createBy3Pts(&elTmp, &c3w1s0, pArcPts, 0);
		//mdlElement_display(&elTmp, NORMALDRAW);

		pArcPts[2] = pTan;
	}



	if (i==0)
	{
		DVec3d ptmp = pArcPts[0];
		pArcPts[0] = pArcPts[2];
		pArcPts[2] = ptmp;
	}

	writeLogOut(__FUNCTION__, 0);


	return SUCCESS;
}

//////////////////////////////////////////////////////
int reinCreateFilletArc(double* angP, double* otstP, DVec3d* pOut, DVec3d* pt, DVec3d* pTxt, double radius)
{
	//mdlElmdscr_spaceFillet ??? новая! попробовать!

	//DVec3d pta[3];
	DVec3d vec[2];
	DVec3d vecsum;
	double ang[2]; 
	double dist[2]; 
	double otst; 
	double otn[2]; 
	DVec3d pX; 
	DVec3d pY; 
	double distcent;
	//MSElementDescr* edpChain = *edPP;

	mdlVec_fromXYZ(&pX, 1., 0., 0.);
	mdlVec_fromXYZ(&pY, 0., -1., 0.);



	dist[0] = mdlVec_distance(&pt[0], &pt[1]);
	dist[1] = mdlVec_distance(&pt[1], &pt[2]);


	mdlVec_subtract(&vec[0], &pt[0], &pt[1]);
	mdlVec_subtract(&vec[1], &pt[2], &pt[1]);


	ang[0] = mdlVec_signedAngleBetweenVectors(&vec[1], &pX, &pY);
	ang[1] = mdlVec_signedAngleBetweenVectors(&vec[0], &vec[1], &pY);
	//ang[0] = mdlVec_angleBetweenVectors(&vec[1], &pX);
	//ang[1] = mdlVec_angleBetweenVectors(&vec[0], &vec[1]);


	if (angP) *angP = ang[1];

	//otst = radius / tan( fabs(ang[1]/2.));
	//distcent = radius / sin( fabs(ang[1]/2.));
	if (!EQ(ang[1], 0.)) otst = radius / tan( fabs(ang[1]/2.)); else  return ERROR;
	if (!EQ(ang[1], 0.)) distcent = radius / sin( fabs(ang[1]/2.)); else  return ERROR;

	if (otstP) *otstP = otst;

	otn[0] = otst / dist[0];
	otn[1] = otst / dist[1];

	//if (otn[0] > 0.5) return ERROR;
	//if (otn[1] > 0.5) return ERROR;


	if (EQ(otn[0], 0.)) return ERROR;
	if (EQ(otn[1], 0.)) return ERROR;

	mdlVec_scaleToLength(&vec[0], &vec[0], otst);
	mdlVec_scaleToLength(&vec[1], &vec[1], otst);

	mdlVec_addPoint(&vecsum, &vec[0], &vec[1]);
	mdlVec_scaleToLength(&vecsum, &vecsum, distcent - radius);

	//printf("%f %f %f\n", vecsum.x, vecsum.y, vecsum.z);

	if (pTxt) 
	{
		*pTxt = vecsum;
		mdlVec_negateInPlace(pTxt);
	}

	if (pOut)
	{
		mdlVec_addPoint(&pOut[1], &pt[1], &vecsum);
		mdlVec_addPoint(&pOut[0], &pt[1], &vec[0]);
		mdlVec_addPoint(&pOut[2], &pt[1], &vec[1]);
	}



	return SUCCESS;
}
/*
/////////////////////
int reinCreateComplexBarAxis ( // NU
MSElementDescr **edPchn, //out (reinelm)
MSElementDescr *elmdP, // in (reinbar)
int irad,
DVec3d* arPts // out
) 
{ 
	double rad = mdlCnv_masterUnitsToUors((double)irad);
	MSElementDescr* edpChn = *edPchn; 
	MSElementDescr* edpCur = NULL; 
	MSElementDescr* edpNext = NULL; 
	MSElementDescr* edp[2] = {0,0}; // partials
	DVec3d p;
	int bAddCur = FALSE;
	int cnt = 0;
	DVec3d pOrg[2];
	DVec3d pEnd[2];
	DVec3d pOrgTng[2];
	DVec3d pEndTng[2];

	mdlVec_zero(&p);

	//mdlElmdscr_show(edpChn, "  ");

	if (elmdP == NULL) return 0;

    if (elmdP->h.isHeader) 
	{
		cnt = reinCreateComplexBarAxis(&edpChn, elmdP->h.firstElem, irad, arPts); 
		return cnt;
	}

	edpCur = elmdP;
	edpNext = elmdP->h.next;


	//mdlSystem_enterDebug();


   while (edpNext != NULL)
   { 
		DVec3d pIntt;
		//MSBsplineCurve  dcrv[2];
		MSBsplineCurve  crvArc;
		RotMatrix rm;
		  
		mdlBspline_convertToCurve(&dcrv[0], edpCur);
		mdlBspline_convertToCurve(&dcrv[1], edpNext);


		bAddCur = mdlElmdscr_extractEndPoints(&pOrg[0], &pOrgTng[0], &pEnd[0], &pEndTng[0], edpCur, MASTERFILE);
		bAddCur = mdlElmdscr_extractEndPoints(&pOrg[1], &pOrgTng[1], &pEnd[1], &pEndTng[1], edpNext, MASTERFILE);
		
		if (cnt == 0)
		{
			arPts[cnt] = pOrg[0];
			cnt++;
		}
		arPts[cnt] = pEnd[0];
		cnt++;

		//mdlSystem_enterDebug();

		if (irad == 0) bAddCur = TRUE;

		if (!bAddCur && mdlVec_equalTolerance(&pEnd[0], &pOrg[1], 10.))
		{
			DVec3d pCross;
			DVec3d pVertVecs[3];


			mdlVec_crossProduct(&pCross, &pEndTng[0], &pOrgTng[1]);
			mdlVec_getNormalizedTriad (&pCross, &pVertVecs[0], &pVertVecs[1], &pVertVecs[2]);
			mdlRMatrix_fromColumnVectors(&rm, &pVertVecs[0], &pVertVecs[1], &pVertVecs[2]);
			mdlVec_interpolate(&pIntt, &pEndTng[0], 0.5, &pOrgTng[1]);
			mdlVec_scaleToLength(&pIntt, &pIntt, rad);
			mdlVec_negateInPlace(&pIntt);
			mdlVec_addPoint(&p, &pIntt, &pEnd[0]);
		}

		//mdlSystem_enterDebug();

		if (irad == 0) bAddCur = TRUE;

		if (!bAddCur) bAddCur = mdlVec_areParallel(&pEndTng[0], &pOrgTng[1]);

		if (!bAddCur) bAddCur = mdlElmdscr_fillet(&elMon, &elmdP->el, edpCur, edpNext, rad, &p, &rm);

		  if (!bAddCur)
		  {

				//int res;
				double param[2], dist[2];
				DVec3d pt[3]; // точки для построения правильной арки
				DVec3d ptArc[2];
				MSElementDescr* edpArc;


				mdlElmdscr_new(&edpArc, 0, &elMon);

				bAddCur = mdlArc_extract(ptArc, 0, 0, 0, 0, 0, 0, &elMon);

				if (!bAddCur) bAddCur = mdlBspline_convertToCurve(&crvArc, edpArc);

				mdlBspline_evaluateCurvePoint(&pt[1], 0, &crvArc, 0.5);

				mdlElmdscr_freeAll(&edpArc);
				if (!bAddCur) mdlBspline_freeCurve(&crvArc);


				if (!bAddCur)
				{
					// проверяем какая точка ближе
					bAddCur = mdlBspline_minimumDistanceToCurve(&dist[0], 0, 0, &ptArc[0], &dcrv[0]);
					bAddCur = mdlBspline_minimumDistanceToCurve(&dist[1], 0, 0, &ptArc[1], &dcrv[0]);

					if (dist[0] < dist[1])
					{
						bAddCur = mdlBspline_minimumDistanceToCurve(&dist[0], &pt[0], &param[0], &ptArc[0], &dcrv[0]);
						bAddCur = mdlBspline_minimumDistanceToCurve(&dist[1], &pt[2], &param[1], &ptArc[1], &dcrv[1]);
					}
					else
					{
						bAddCur = mdlBspline_minimumDistanceToCurve(&dist[0], &pt[0], &param[0], &ptArc[1], &dcrv[0]);
						bAddCur = mdlBspline_minimumDistanceToCurve(&dist[1], &pt[2], &param[1], &ptArc[0], &dcrv[1]);
					}

					if (!bAddCur) bAddCur = mdlArc_createByPoints(&elMon, &elmdP->el, pt);

					if (!bAddCur)
					{
						

						//printf("%f   %f\n", param[0], param[1]);

						bAddCur = mdlElmdscr_generatePartial(&edp[0], edpCur, 0., param[0], TRUE);

						if (!bAddCur)
						{
							mdlElmdscr_appendDscr(edpChn, edp[0]);
							mdlElmdscr_appendElement(edpChn, &elMon);
						}

						bAddCur = mdlElmdscr_generatePartial(&edp[1], edpNext, param[1], 1., TRUE);

						if (!bAddCur)
						{
							edpCur = edp[1];
						}
					}
				}
		  }
		  
		// если не прошло, то добавляем имеющийся
		if (bAddCur)
		{
			mdlElmdscr_appendElement(edpChn, &edpCur->el);
			edpCur = edpNext;
		}


		mdlBspline_freeCurve(&dcrv[0]);
		mdlBspline_freeCurve(&dcrv[1]);


		edpNext = edpNext->h.next;
	}


	bAddCur = mdlElmdscr_extractEndPoints(&pOrg[0], &pOrgTng[0], &pEnd[0], &pEndTng[0], edpCur, MASTERFILE);

	// берем конечную точку последнего сегмента
	arPts[cnt] = pEnd[0];
	cnt++;


	mdlElmdscr_appendElement(edpChn, &edpCur->el);


	return cnt;

} 
*/



//////////////////////////
void getBarUnrotatedPoints(
DVec3d* ptsOut,
DVec3d* ptsIn,
DVec3d* pNormal,  // нормаль к плоскости стержня
int nump,
int indPointRotateAbout,
int bStayIfVert, // 
double* dScaleP
)
{
	DVec3d vect[3];
	RotMatrix rmv;
	
	for (int i = 0; i < nump; i++) ptsOut[i] = ptsIn[i];

	mdlVec_subtractPointArray(ptsOut, &ptsIn[indPointRotateAbout], nump); // начало в нулевую точку

	vect[2] = *pNormal;

	if (bStayIfVert) // чтобы положение на эскизе соответствовало реальному положению
	{
		mdlVec_getNormalizedTriad(&vect[2], &vect[0], &vect[1], &vect[2]);
	}
	else
	{
		vect[0] = ptsOut[indPointRotateAbout + 1];

		mdlVec_normalize(&vect[0]); // x

		mdlVec_crossProduct(&vect[1], &vect[2], &vect[0]);

		mdlVec_normalize(&vect[1]); // y
	}






	mdlRMatrix_from3Points(&rmv, &pZero, &vect[0], &vect[1]);

	mdlRMatrix_getInverse(&rmv, &rmv);

	mdlRMatrix_multiplyPointArray (ptsOut, &rmv, nump);

	for (int i = 0; dScaleP && i < nump; i++)
	{
		mdlVec_scaleInPlace(&ptsOut[i], *dScaleP);
	}

}

/////////////////////////////////////////
void setLap(
			DVec3d* barpts, 
			int ptnum, 
			double dlap,
			int ilap // 0 - begin, 1 - end
			)
{
	int i;
	double bardist[MAX_BAR_VERTICES] = {0.}; // for (i = 0; i < MAX_BAR_VERTICES; i++) bardist[i] = 0.;
	//int barlap[MAX_BAR_VERTICES];
	//double dist;
	DVec3d pVec;
	int cnt = 0;

	

	for (i = 0; i < ptnum - 1; i++)
	{
		bardist[i] = mdlVec_distance(&barpts[i], &barpts[i + 1]);
	}


	if (ilap == 0 && dlap < bardist[0])
	{
		mdlVec_subtractPoint(&pVec, &barpts[1], &barpts[0]);
		mdlVec_scaleToLengthInPlace(&pVec, dlap);
		mdlVec_addInPlace(&barpts[0], &pVec);
	}


	if (ilap == 1 && dlap < bardist[ptnum-2])
	{
		mdlVec_subtractPoint(&pVec, &barpts[ptnum-2], &barpts[ptnum-1]);
		mdlVec_scaleToLengthInPlace(&pVec, dlap);
		mdlVec_addInPlace(&barpts[ptnum-1], &pVec);
	}


}

///////////////////////////
int getComponentPoints(MSElementDescr* edp, ReinBar* rbP, int* elemIndexP, int bUpdateMainLine)
{
	//DVec3d ptstmp[MAX_BAR_VERTICES];
	int typ = mdlElement_getType(&edp->el);
	int numn = 0;
	ReinPoint rp;
	DVec3d v;

	//int bFirstPoint = (rbP->numpts == 0);
	int bFirstPoint = (gvpt.size() == 0);


	if (typ == ARC_ELM || typ == ELLIPSE_ELM)
	{
		DVec3d cent;
		DVec3d ptp[3];
		double drad[2];
		double dan[2];
		double len = 0.;

		if (bFirstPoint == FALSE) 
		{
			rbP->isgmnum++;
		}

		if (mdlArc_extract(ptp, &dan[0], &dan[1], &drad[0], &drad[1], 0, &cent, &edp->el) == SUCCESS)
		{
			//==============
			////rbP->rpts.push_back(ptp[0]);// start
			////rbP->cents.push_back(pZero); // for arcs
			////rbP->rfa.push_back(0);
			////rbP->numpts = rbP->rpts.size();

			rp.set(ptp[0]);
			gvpt.push_back(rp);
			//rbP->rpts[rbP->numpts] = ptp[0]; // start
			//rbP->numpts++;

			len = ((drad[0] + drad[1]) / 2.) * fabs(dan[1]);

			if (typ == ARC_ELM)
			{
				double deln = 0.;
				int res = mdlCnv_masterToUOR(&deln, fillets[rbP->diam].radius, ACTIVEMODEL);

				if (res == SUCCESS)
				{
					////mdlElmdscr_pointAtDistance(&v, 0, deln * 1.3, edp, 0); // по идее надо бы высчитать по хорде
					////rbP->rpts.push_back(v);
					////rbP->cents.push_back(pZero);
					////rbP->rfa.push_back(RFA_ARCB);
					////rbP->numpts = rbP->rpts.size();

					//mdlElmdscr_pointAtDistance(&rbP->rpts[rbP->numpts], 0, deln * 1.3, edp, 0); // по идее надо бы высчитать по хорде
					mdlElmdscr_pointAtDistance(&v, 0, deln * 1.3, edp, 0); // по идее надо бы высчитать по хорде
					rp.set(v, RFA_ARCB);
					gvpt.push_back(rp);
					//rbP->rfa[rbP->numpts] = RFA_ARCB;
					//rbP->numpts++;
				}

				////mdlElmdscr_pointAtDistance(&v, 0, len / 2., edp, 0);
				////rbP->rpts.push_back(v);
				////rbP->cents.push_back(cent); // cent from extract
				////rbP->rfa.push_back(RFA_ARCP); // точка на дуге
				////rbP->numpts = rbP->rpts.size();

				//mdlElmdscr_pointAtDistance(&rbP->rpts[rbP->numpts], 0, len / 2., edp, 0);
				mdlElmdscr_pointAtDistance(&v, 0, len / 2., edp, 0);
				rp.set(v, cent, RFA_ARCP);
				gvpt.push_back(rp);
				//rbP->rfa[rbP->numpts] = RFA_ARCP; // точка на дуге
				//rbP->cents[rbP->numpts] = cent;
				//rbP->numpts++;

				if (res == SUCCESS)
				{
					//mdlElmdscr_pointAtDistance(&v, 0, (len - deln * 1.3), edp, 0);
					//rbP->rpts.push_back(v);
					//rbP->cents.push_back(pZero);
					//rbP->rfa.push_back(RFA_ARCB);
					//rbP->numpts = rbP->rpts.size();

					//mdlElmdscr_pointAtDistance(&rbP->rpts[rbP->numpts], 0, (len - deln * 1.3), edp, 0);
					mdlElmdscr_pointAtDistance(&v, 0, (len - deln * 1.3), edp, 0);
					rp.set(v, RFA_ARCB);
					gvpt.push_back(rp);
					//rbP->rfa[rbP->numpts] = RFA_ARCB;
					//rbP->numpts++;
				}

				////rbP->rpts.push_back(ptp[1]);// 
				////rbP->cents.push_back(pZero); // 
				////rbP->rfa.push_back(0);
				////rbP->numpts = rbP->rpts.size();

				rp.set(ptp[1]);
				gvpt.push_back(rp);
				//rbP->rpts[rbP->numpts] = ptp[1];
				//rbP->numpts++;

			}
			else // ELLIPSE_ELM
			{
				////mdlElmdscr_pointAtDistance(&v, 0, len / 4., edp, 0); // сделано 4. вместо 2. для окружности
				////rbP->rpts.push_back(v);// 
				////rbP->cents.push_back(cent); // cent from extract
				////rbP->rfa.push_back(RFA_CIRP);
				////rbP->numpts = rbP->rpts.size();

				//mdlElmdscr_pointAtDistance(&rbP->rpts[rbP->numpts], 0, len / 4., edp, 0); // сделано 4. вместо 2. для окружности
				mdlElmdscr_pointAtDistance(&v, 0, len / 4., edp, 0); // сделано 4. вместо 2. для окружности
				rp.set(v, cent, RFA_CIRP);
				gvpt.push_back(rp);
				//rbP->rfa[rbP->numpts] = RFA_CIRP;
				//rbP->cents[rbP->numpts] = cent;
				//rbP->numpts++;

				ReinLap* rlP = getReinLap(rbP->diam);
				if (rlP && rlP->muft)
				{
					len = len - dCfgVar_BarFace * 0.2;
					rbP->term[0] = REIN_TERM_MUFT;
					rbP->term[1] = REIN_TERM_REZB;
				}
				else if (rlP)
					len = mdlCnv_masterUnitsToUors(rlP->lapValue);
				else
				{
					len = len - dCfgVar_BarFace * 0.2;
				}

				////mdlElmdscr_pointAtDistance(&v, 0, len, edp, 0);
				////rbP->rpts.push_back(v);// 
				////rbP->cents.push_back(cent); // cent from extract
				////rbP->rfa.push_back(RFA_CIRP);
				////rbP->numpts = rbP->rpts.size();

				//mdlElmdscr_pointAtDistance(&rbP->rpts[rbP->numpts], 0, len, edp, 0);
				mdlElmdscr_pointAtDistance(&v, 0, len, edp, 0);
				rp.set(v);
				gvpt.push_back(rp);
				//rbP->numpts++;

				rbP->ilaps = 1; // флаг - точка на окр.
			}


		

			//=====
			if (bUpdateMainLine && (*elemIndexP) == (rbP->elemEDoffset - 1)) 
			{
				//rbP->mainPtsIndex = rbP->numpts - 3 - rbP->isgmnum;
				rbP->mainPtsIndex = (int)gvpt.size() - 3 - rbP->isgmnum;
			}
			//=====

		}
	}
	else if (mdlLinear_extract(ptstmp, &numn, &edp->el, edp->h.dgnModelRef) == SUCCESS)
	{

		if (bFirstPoint == FALSE) rbP->isgmnum++;

		for (int i = 0; i < numn; i++)
		{
			// сегменты
			if (i > 0)
			{
				//=====
				if (bUpdateMainLine && 
					(
						rbP->elemEDoffset == 0 || // когда просто элемент
						(*elemIndexP) == (rbP->elemEDoffset - 1)
					) && // сложный элемент, офсет начинается с 1
					(i - 1) == rbP->segmIndex
					) 
				{
					//rbP->mainPtsIndex = rbP->numpts - 1 - rbP->isgmnum;
					rbP->mainPtsIndex = (int)gvpt.size() - 1 - rbP->isgmnum;
				}
				//=====

			}


			// точки
			////rbP->rpts.push_back(ptstmp[i]);// 
			////rbP->cents.push_back(pZero);// 
			////rbP->rfa.push_back(0);

			rp.set(ptstmp[i]);
			gvpt.push_back(rp);
			//rbP->rpts[rbP->numpts] = ptstmp[i];
			//rbP->numpts++;

		}

	}

	(*elemIndexP)++;

	//rbP->numpts = rbP->rpts.size();

	return 0;


}

////////////////////////////////////
// get Comlex Bar Points - сбор точек в вектор vpt (И ВСЁ)
int getComlexBarPoints(MSElementDescr* edp, ReinBar* rbP, int bReset, int* elemIndexP, int bUpdateMainLine, int bGetAngles)
{

	int elemIndex = 0;

	if (elemIndexP == NULL) elemIndexP = &elemIndex;

	if (bReset)
	{
		rbP->numpts = 0;
		rbP->numsgts = 0;

		//ZeroMemory(rbP->rpts, sizeof(rbP->rpts));
		//ZeroMemory(rbP->rfa, sizeof(rbP->rfa));
		//ZeroMemory(rbP->cents, sizeof(rbP->cents));
		//ZeroMemory(rbP->sgts, sizeof(rbP->sgts));

		gvpt.clear();

		//rbP->rpts.clear();
		//rbP->cents.clear();
		//rbP->rfa.clear();
		//rbP->sgts.clear();

		int res = mdlElmdscr_extractNormal(&rbP->v_enrm, 0, edp, &pZ);
		if (rbP->noplanar != 2)
		{
			if (res == SUCCESS)
				rbP->noplanar = 0;
			else
				rbP->noplanar = 1;
		}
		else
		{
			if (res == SUCCESS)
				rbP->noplanar = 0;
			else
				rbP->noplanar = 2; // для трехмерного сравнения
		}
	}

	int angcnt = 0;

	if (edp->h.isHeader)
	{
		MSElementDescr* pComponent = edp->h.firstElem;

		while (pComponent)
		{
			if (pComponent->h.isHeader) 
				getComlexBarPoints(pComponent, rbP,  // РЕКУРСИЯ (без обнуления)
					FALSE, // не обнулять
					elemIndexP, bUpdateMainLine, FALSE);
			else
				getComponentPoints(pComponent, rbP, elemIndexP, bUpdateMainLine);

			if (bGetAngles && pComponent->h.next)
			{
				DVec3d p[2];
				int res;
				rbP->bang[angcnt] = 0.;
				res = mdlElmdscr_extractEndPoints(0, 0, 0, &p[0], pComponent, edp->h.dgnModelRef);
				if (res = SUCCESS) res = mdlElmdscr_extractEndPoints(0, &p[1], 0, 0, pComponent->h.next, edp->h.dgnModelRef);
				if (res = SUCCESS) rbP->bang[angcnt] = mdlVec_angleBetweenVectors(&p[0], &p[1]) * fc_180overpi;
				angcnt++;
			}

			pComponent = pComponent->h.next;
		}
	}
	else
	{
		getComponentPoints(edp, rbP, elemIndexP, bUpdateMainLine);
	}



	return 0;

}

//////////////////////////////////////////////
int getBendRadius(ReinBar* rbP, ReinSpace* rsP)
{

	int radi = 0;

	if (rbP)
	{
		if (rbP->bendrad > 0)
			radi = rbP->bendrad;
		else
			radi = fillets[rbP->diam].radius;
	}

	if (rsP)
	{
		if (rsP->bendrad > 0)
			radi = rsP->bendrad;
		else
			radi = fillets[rsP->diam].radius;
	}


	return radi;

}



/////////////////////////////////////////////
void createLineText(
			MSElementDescr** edpT,
			DVec3d* arTwoVerts, // arTwoVerts[2]
			DVec3d* ptText,
			long iText,
			long iTextDop,
			Transform* tmP,
			Transform* tmRefP,
			MSElementDescr* edpBar,
			WCH* txtPrefix1 = NULL,
			WCH* txtPrefix2 = NULL,
			DVec3d* ptArcPoint = NULL
			)
{
	DVec3d pTxt;
	DVec3d pVec;
	DVec3d pOfs;
	DVec3d pOfs2;
	RotMatrix rm;
	RotMatrix rm2;
	Transform tm;
	double an = 0.;
	double an2 = 0.;
	double an3 = 0.; // для радиуса и угла
	double th;
	MSElementDescr* edpText = NULL;
	DVec3d* pTxtP = NULL;
	int iTxtParam = 4;

	if (iText == 0) return;
	if (edpT != NULL) edpText = *edpT;

	//mdlVec_interpolate(&pTxt, &arTwoVerts[0], 0.5, &arTwoVerts[1]);

	//if (ptText == NULL)
	//	pTxtP = &pTxt;
	//else
		pTxtP = ptText;

	mdlTMatrix_getIdentity(&tm);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	ActiveParams::GetValue(th, ActiveDoubleParams::ACTIVEPARAM_TEXTHEIGHT);
	ActiveParams::GetValue(txtParam[4].font, ActiveUInt32Params::ACTIVEPARAM_FONT);
#else
	mdlParams_getActive(&th, ACTIVEPARAM_TEXTHEIGHT);
	mdlParams_getActive(&txtParam[4].font, ACTIVEPARAM_FONT);
#endif

	mdlVec_subtractPoint(&pVec, &arTwoVerts[1], &arTwoVerts[0]);
	if (txtPrefix1 == NULL) // угол и радиус не поворачиваем (todo...)
		an = mdlVec_angleXY(&pVec); // поворот текста вдоль загиба

	if (EQ(an, -fc_piover2) || fabs(an) > fc_piover2) an += fc_pi;
	//an2 = mdlVec_angleXY(&pVec) + fc_piover2; // если такст вдоль линии должен быть внутри эскиза
	an2 = mdlVec_angleXY(&pVec) + fc_piover2*3; // текст снаружи
	an3 = mdlVec_angleXY(&pVec) + fc_piover2;



	//printf("%i   %f %f\n", iText, mdlVec_angleXY(&pVec), an);

	//{ 0, TXTJUST_LT, 0, FALSE },
	//{ 1, TXTJUST_LC, 0, FALSE },
	//{ 2, TXTJUST_LB, 0, FALSE },
	//{ 3, TXTJUST_CT, 0, FALSE },
	//{ 4, TXTJUST_CC, 0, FALSE },
	//{ 5, TXTJUST_CC, 0, FALSE },
	//{ 6, TXTJUST_RT, 0, FALSE },
	//{ 7, TXTJUST_RC, 0, FALSE },
	//{ 8, TXTJUST_RB, 0, FALSE }

	if (txtPrefix1)
	{
		if (an3 > 0. && an3 < fc_piover2)
			iTxtParam = 2;
		else if (an3 < 0. && an3 > -fc_piover2)
			iTxtParam = 0;
		else if (an3 < fc_pi && an3 > fc_piover2)
			iTxtParam = 8;
		else
			iTxtParam = 6;

	}



	mdlRMatrix_fromAngle(&rm, an);
	mdlRMatrix_fromAngle(&rm2, an2);

	mdlVec_fromRotMatrixColumn(&pOfs, &rm2, 0);

	if (txtPrefix1)
	{
		mdlVec_negateInPlace(&pOfs);
		pOfs2 = pOfs;
		mdlVec_scaleToLengthInPlace(&pOfs, th/2.);
		mdlVec_scaleToLengthInPlace(&pOfs2, th/4.);
	}
	else
		mdlVec_scaleToLengthInPlace (&pOfs, th);

	mdlTMatrix_setTranslation(&tm, &pOfs);

	WCH txt[50];

	if (txtPrefix1 && txtPrefix2)
	{
		if (iText > 0 && iTextDop > 0)
			SPRN(txt, L("%s%i, %s%i°"), txtPrefix1, iText, txtPrefix2, iTextDop);
		else if (iText > 0 && iTextDop == 0)
			SPRN(txt, L("%s%i"), txtPrefix1, iText);
		else if (iText == 0 && iTextDop > 0)
			SPRN(txt, L("%s%i"), txtPrefix2, iTextDop);
	}
	else
	{
		if (iText == iTextDop)
			SPRN(txt, L("%i"), iText);
		else
			SPRN(txt, L("%i-%i"), iText, iTextDop);
	}
	

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	mdlText_create(&elTxt[0], NULL, txt, pTxtP, &rm, NULL, &txtParam[iTxtParam], NULL, NULL);
#else
	mdlText_create(&elTxt[0], NULL, txt, pTxtP, NULL, &rm, &txtParam[iTxtParam], NULL);
#endif

	mdlElement_transform(&elTxt[0], &elTxt[0], &tm);
	if (tmP) mdlElement_transform(&elTxt[0], &elTxt[0], tmP);
	if (tmRefP) mdlElement_transform(&elTxt[0], &elTxt[0], tmRefP);

	if (edpBar && txtPrefix1 == NULL)
	{
		DVec3d shpts[10];
		if (mdlText_extractShape(shpts, 0, &elTxt[0], 0, 0) == SUCCESS)
		{
			int res = mdlShape_create(&el3, 0, shpts, 4, 0);
			//mdlElement_add(&el3);
			MSElementDescr* edp = NULL;
			mdlElmdscr_new(&edp, 0, &el3);

			MSElementDescr* pComponent = edpBar->h.firstElem;
			while (pComponent)
			{
				DVec3d p[2];

				if (mdlIntersect_allBetweenElms(0, p, 2, edp, pComponent, 0, 10.) != 0)
				{
					mdlTMatrix_getIdentity(&tm);
					an2 = an2 + fc_pi;
					mdlRMatrix_fromAngle(&rm2, an2);
					mdlVec_fromRotMatrixColumn(&pOfs, &rm2, 0);
					mdlVec_scaleToLengthInPlace (&pOfs, th);
					mdlTMatrix_setTranslation(&tm, &pOfs);

					//sprintf(s, "%i", iText);
#if defined (MSVERSION) && (MSVERSION == 0xa00)
					mdlText_create(&elTxt[0], NULL, txt, pTxtP, &rm, NULL, &txtParam[4], NULL, NULL);
#else
					mdlText_create(&elTxt[0], NULL, txt, pTxtP, NULL, &rm, &txtParam[4], NULL);
#endif

					mdlElement_transform(&elTxt[0], &elTxt[0], &tm);
					if (tmP) mdlElement_transform(&elTxt[0], &elTxt[0], tmP);
					if (tmRefP) mdlElement_transform(&elTxt[0], &elTxt[0], tmRefP);

					break;

				}

				pComponent = pComponent->h.next;
			}


			//mdlElmdscr_add(edp);
			mdlElmdscr_freeAll(&edp);
		}
	}


	if (txtPrefix1 && ptArcPoint)
	{
		DPoint3d p[2];
		p[0] = *ptText;
		p[1] = *ptArcPoint;
		mdlVec_addInPlace(&p[0], &pOfs2);
		mdlVec_addInPlace(&p[1], &pOfs2);
		mdlLine_create(&elTmp, &c0w0s0, p);

		mdlElmdscr_appendElement(edpText, &elTmp);
	}


	mdlElmdscr_appendElement(edpText, &elTxt[0]);

}


////////////////////////
int reinCreateComplexBarAxis2(
	MSElementDescr** edp,
	MSElementDescr** edpT, // later - ReinPos* ???
	vector <DVec3d> &vecPts,
	vector<long> &vrfa,
	int cnt_,
	int radius,
	MSElement* elTmplP,
	ReinBar* rbP,
	int bZeroFillet
)
{
	int i = 0;
	int ii = 0;

	writeLogIn(__FUNCTION__, 0);

	for (vector<DVec3d>::iterator it = vecPts.begin(); it != vecPts.end(); ++it)
	//for (size_t i = 0; i < vecPts.size() && i < 1000; i++)
	{
		if (i < 1000) arpg[i++] = *it;
	}

	for (vector<long>::iterator it = vrfa.begin(); it != vrfa.end(); ++it)
	//for (size_t i = 0; i < vrfa.size() && i < 1000; i++)
	{
		if (i < 1000) arlg[ii++] = *it;
	}

	int cnt = (int)vecPts.size();

	if (cnt > 1000) cnt = 1000;

	return reinCreateComplexBarAxis2(edp, edpT, arpg, arlg, cnt, radius, elTmplP, rbP, bZeroFillet);

	writeLogOut(__FUNCTION__, 0);

}

////////////////////////
int reinCreateComplexBarAxis2(
	MSElementDescr** edp,
	MSElementDescr** edpT, // later - ReinPos* ???
	vector <DVec3d> &vecPts,
	vector<long> &vrfa,
	int cnt_,
	int radius,
	MSElement* elTmplP
)
{
	return reinCreateComplexBarAxis2(edp, edpT, vecPts, vrfa, cnt_, radius, elTmplP, NULL, iCfgVar_NullFillet);
}


////////////////////////
//int reinCreateComplexBarAxis2(
//	MSElementDescr** edp,
//	MSElementDescr** edpT, // later - ReinPos* ???
//	DVec3d* arPtsP,
//	vector<long> &vrfa,
//	int cnt,
//	int radius,
//	MSElement* elTmplP,
//	ReinBar* rbP,
//	int bZeroFillet
//)
//{
//
//	for (size_t i = 0; i < vrfa.size() && i < 1000; i++)
//		arlg[i] = vrfa[i];
//
//	return reinCreateComplexBarAxis2(edp, edpT, arPtsP, arlg, cnt, radius, elTmplP, rbP, bZeroFillet);
//}


////////////////////////
int reinCreateComplexBarAxis2(
			MSElementDescr** edp,
			MSElementDescr** edpT, // later - ReinPos* ???
			DVec3d* arPtsP,
			long* rfa,
			int cnt,
			int radius,
			MSElement* elTmplP
			)
{
	return reinCreateComplexBarAxis2(edp, edpT, arPtsP, rfa, cnt, radius, elTmplP, NULL, iCfgVar_NullFillet);
}


//////////////////////////////////////////////////////////////////
// func create note
void createNote(MSElement* elP, DVec3d* arPnt, int numPnt, WCH* txt, MSWCH* sDimStyleName)
{
	if (elP == NULL) return;

	DgnDimStyleP        pDimStyle1 = NULL;

	if (sDimStyleName)
	{
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
			if (mdlDimStyle_getByName(pDimStyle1,
			sDimStyleName, //L"REIN_note_arrow_open",
			NULL,
			DIMSTYLE_SEARCH_DEFAULT) != SUCCESS)
#endif
			pDimStyle1 = NULL;
	}


	if (pDimStyle1 == NULL)
	{
		pDimStyle1 = mdlDimStyle_getActive();

		/*
		
		mdlDimStyle_setIntegerProp(pDimStyle1,
			DIMSTYLE_VALUE_Terminator_Type_Arrow, // DIMSTYLE_VALUE_Terminator_Type_Dot
			DIMSTYLE_PROP_Terminator_Note_INTEGER);

		mdlDimStyle_setIntegerProp(pDimStyle1,
			DIMSTYLE_VALUE_Terminator_Arrowhead_Open, // DIMSTYLE_VALUE_Terminator_Arrowhead_Filled
			DIMSTYLE_PROP_Terminator_Arrowhead_INTEGER);

		//mdlDimStyle_setIntegerProp(mdlDimStyle_getActive(), 
		//	DIMSTYLE_VALUE_MLNote_TextRotation_Horizontal,
		//	DIMSTYLE_PROP_MLNote_TextRotation_INTEGER);

		//mdlDimStyle_setIntegerProp(mdlDimStyle_getActive(), 
		//	DIMSTYLE_VALUE_MLNote_FrameType_None,
		//	DIMSTYLE_PROP_MLNote_FrameType_INTEGER);

		//mdlDimStyle_setIntegerProp(mdlDimStyle_getActive(), 
		//	DIMSTYLE_VALUE_MLNote_Justification_Dynamic,
		//	DIMSTYLE_PROP_MLNote_Justification_INTEGER);

		//mdlDimStyle_setIntegerProp(mdlDimStyle_getActive(), 
		//	DIMSTYLE_VALUE_MLNote_VerticalJustification_Center,
		//	DIMSTYLE_PROP_MLNote_VerticalJustification_INTEGER);

		mdlDimStyle_setDoubleProp(pDimStyle1, 0.5, DIMSTYLE_PROP_Terminator_Width_DOUBLE);
		mdlDimStyle_setDoubleProp(pDimStyle1, 0.5, DIMSTYLE_PROP_Terminator_Height_DOUBLE);

		mdlDimStyle_setBoolIntProp(pDimStyle1,
			0,
			DIMSTYLE_PROP_MLNote_ShowLeader_BOOLINT);

			*/
	}
	else
	{
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
		mdlDimStyle_setActive(pDimStyle1);
#endif
	}

	mdlDim_create(elP, &c0w0s0, NULL, DIMTYPE_NOTE, tcb->lstvw);


	for (int i = 0; i < numPnt; i++)
	{
		mdlDim_insertPoint(elP, &arPnt[i], NULL, -1, POINT_STD
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
			, ACTIVEMODEL
#endif
		);
	}




	if (txt)
	{


		//typedef struct
		//{
		//	double width;	     	/* Character width			    */
		//	double height;	     	/* Character height			    */
		//	UInt32 font;	     	/* Font number				    */
		//	UInt32 color;	     	/* Text color				    */
		//	UInt32 weight;	     	/* Text weight				    */
		//	byte   useColor;		/* TRUE  - use color from this structure    */
		//				/* FALSE - use color from display header    */
		//	byte   useWeight;		/* TRUE  - use weight from this structure   */
		//				/* FALSE - use weight from display header   */
		//	byte   noMasterUnits1;      /* Display primary sub-units only	    */
		//	byte   noMasterUnits2;      /* Display secondary sub-units only	    */
		//	byte   hasAltFormat1;       /* Use DimAltFmtBlock for primay units      */
		//	byte   hasAltFormat2;       /* Use DimAltFmtBlock for secondary units   */
		//} DimParamText;

		//DimParamText dpt;
		//memset(&dpt, 0, sizeof(DimParamText));
		//dpt.font = 1025;
		//dpt.height = 3.;
		//dpt.width = 3.;
		//mdlDim_setParam(&elTmp, &dpt, DIMPARAM_TEXT);


		//typedef union
		//{
		//	struct		    	       /* Dimension with main string and    */
		//	{			       /*    plus/minus type tolerances	    */
		//		char main[MAX_DIMSTRING];
		//		char plus[MAX_DIMSTRING];
		//		char minus[MAX_DIMSTRING];
		//	} pmtol;
		//	struct		   	       /* Dimension with upper and lower    */
		//	{			       /*    limits only		    */
		//		char upper[MAX_DIMSTRING];
		//		char lower[MAX_DIMSTRING];
		//	} limit;
		//	char single[MAX_DIMSTRING];	       /* Dimension without tolerance	    */
		//} DimStringUnion;

		//typedef struct
		//{
		//	DimStringUnion  primary;	       /* Primary dimension strings	    */
		//	DimStringUnion  secondary;	       /* Secondary dimension strings used  */
		//					   /*    only with dual dimensions	    */
		//} DimStrings;	

		DimStrings ds;
		DimStringConfig dsc;

		//memset(&ds, 0, sizeof(DimStrings));
		mdlDim_getStrings(&ds, &dsc, elP, 0);
		mdlDim_getStrings(&ds, &dsc, elP, 1);


#if defined (MSVERSION) && (MSVERSION == 0x8b0)
		// как это работает в коннекте пока не понял
		strcpy(ds.primary.single, txt);
#endif

		mdlDim_setStrings(elP, 0, &ds);

	}


	mdlDim_validate(elP);



}



/////////////////////
void createNote(MSElementDescr** edpT, DVec3d* p1, DVec3d* p2, WCH* txt)
{

	MSElementDescr* edpText = NULL;

	if (edpT != NULL) edpText = *edpT;

	DVec3d ptmp[2];
	ptmp[0] = *p1;
	ptmp[1] = *p2;

	createNote(&elTmp, ptmp, 2, txt, NULL);

	mdlElmdscr_appendElement(edpText, &elTmp);

}


////////////////////////
int reinCreateComplexBarAxis2(
			MSElementDescr** edp,
			MSElementDescr** edpT, // later - ReinPos* ???
			DVec3d* arPtsP,
			long* rfa,
			int cnt,
			int radius,
			MSElement* elTmplP,
			ReinBar* rbP,
			int bZeroFillet
			)
{
	MSElementDescr* edpChain = NULL;
	MSElementDescr* edpText = NULL;
	double dFilletRadiusUors = mdlCnv_masterUnitsToUors(radius);
	MSElement* elTmpl = NULL;
	int res = 0;
	int bAdd = FALSE;
	double dlen;
	long ilen[2];
	double drad[2];
	long irad = 0;
	double dfilang; // fillet angle
	int iangcnt = 0;
	DVec3d ddd[4]; // для налезающих филлетов
	DVec3d ddq[4]; // для налезающих филлетов
	int iFilKos = FALSE;
	DVec3d pCnt;

	if (*edp == NULL) return cnt;
	if (edpT != NULL) edpText = *edpT;

	//printf("=========\n");


	if (elTmplP) 
		elTmpl = elTmplP;
	else
		elTmpl = &c0w0s0;

	//if (iCfgVar_MinSegment) cnt = checkBarPoints(arPtsP, NULL, rfa, cnt);

	writeLogIn(__FUNCTION__, 0);
	if (iDebug) sprintf(sLogMes, "cnt = %i\n", cnt); writeLog(0, 0);

	// для получения загиба через fillet
	MSElementDescr* edpOne = NULL; 
	MSElementDescr* edpTwo = NULL;

	/*
	if (iCfgVar_BendNewDraw == 2)
	{
		if (rbP->term[0] == REIN_TERM_BEND)
		{
			// добавляем точку в начало arPtsP, rfa, cnt++
			// ...
		}
		if (rbP->term[1] == REIN_TERM_BEND)
		{
			// добавляем точку в конец  arPtsP, rfa, cnt++
			// ...
		}
	}
	*/

	// создаем векторы и добавляем точки из bent

	int elcnt = 0;

	// simple arc/circle for bar axis
	if (cnt == 3 && radius == -1 && (rfa[1] & RFA_ARCP || rfa[1] & RFA_CIRP))
	{
		mdlElmdscr_freeAll(edp);

		if (rfa[1] & RFA_ARCP)
		{
			mdlArc_createByPoints(&elLine, elTmpl, arPtsP);
		}
		else if (rfa[1] & RFA_CIRP)
		{
			mdlCircle_createBy3Pts(&elLine, elTmpl, arPtsP, 0);
		}

		mdlElmdscr_new(edp, 0, &elLine);

		res = 1;
	}

	
	edpChain = *edp;


	for (int i = 0; res == 0 && i < cnt - 1;)
	{

		DVec3d pcent;
		DVec3d* pcentP = NULL;

		if (edpTwo)
		{
			//if (edpOne) mdlElmdscr_freeAll(&edpOne);

			edpOne = edpTwo;
			edpTwo = NULL;

			if (rfa[i + 1] & RFA_ARCP || rfa[i + 1] & RFA_CIRP)
			{
				i = i + 2;
			}
			else
			{
				i = i + 1;
			}

		}
		else
		{
			if (rfa[i + 1] & RFA_ARCP)
			{
				mdlArc_createByPoints(&elLine, elTmpl, &arPtsP[i]);
				mdlArc_extract(0, 0, 0, 0, 0, 0, &pcent, &elLine);
				mdlVec_interpolate(&pcent, &pcent, 0.5, &arPtsP[i+1]);
				if (edpT) pcentP = &pcent;
				i = i + 2;
			}
			else if (rfa[i + 1] & RFA_CIRP)
			{
				mdlCircle_createBy3Pts(&elLine, elTmpl, &arPtsP[i], 0);
				i = i + 2;
			}
			else
			{
				mdlLine_create(&elLine, elTmpl, &arPtsP[i]);
				i = i + 1;
			}

			mdlElmdscr_new(&edpOne, 0, &elLine);

		}


		//mdlElmdscr_appendDscr(edpChain, edpOne);


		if (i < cnt - 1)
		{
			if (rfa[i + 1] & RFA_ARCP)
			{
				mdlArc_createByPoints(&elLine, elTmpl, &arPtsP[i]);
				mdlArc_extract(0, 0, 0, 0, 0, 0, &pcent, &elLine);
				mdlVec_interpolate(&pcent, &pcent, 0.5, &arPtsP[i+1]);
				if (edpT) pcentP = &pcent;
			}
			else if (rfa[i + 1] & RFA_CIRP)
			{
				mdlCircle_createBy3Pts(&elLine, elTmpl, &arPtsP[i], 0);
			}
			else
			{
				mdlLine_create(&elLine, elTmpl, &arPtsP[i]);
			}

			mdlElmdscr_new(&edpTwo, 0, &elLine);
		}

		bAdd = FALSE;
		MSElementDescr* edpF = NULL;

		if (edpOne && edpTwo) 
		{
			DVec3d pp[4];
			DVec3d p[4];
			DVec3d ppp;
			RotMatrix rm;

			mdlElmdscr_extractEndPoints(&p[0], &p[1], &pp[0], &pp[1], edpOne, ACTIVEMODEL);
			mdlElmdscr_extractEndPoints(&pp[2], &pp[3], &p[2], &p[3], edpTwo, ACTIVEMODEL);

			mdlVec_addPoint(&ppp, &pp[1], &pp[3]);
			mdlVec_negateInPlace(&ppp);
			mdlVec_scaleToLengthInPlace(&ppp, mdlVec_distance(&p[0], &p[2]) / 10.);
			mdlVec_addPoint(&ppp, &pp[0], &ppp);

			mdlRMatrix_from3Points(&rm, &pp[0], &p[0], &p[2]);
			mdlRMatrix_invert(&rm, &rm);
			//mdlRMatrix_getIdentity(&rm);

			if (mdlVec_areParallel(&pp[1], &pp[3]) == FALSE && radius > 0)
			{
				//DVec3d pppp[2];
				//pppp[0] = ppp;
				//pppp[1] = ppp;
				//mdlLine_create(&elTmp, &c3w9s0, pppp);
				//reinCreateBarAxisLine(&elTmp, NULL, TRUE); // рисует точку
				//printf("%.0f,%.0f,%.0f\n", mdlCnv_uorsToMasterUnits(ppp.x), mdlCnv_uorsToMasterUnits(ppp.y), mdlCnv_uorsToMasterUnits(ppp.z));

				mdlVec_scaleToLengthInPlace(&pp[1], mdlVec_distance(&p[0], &p[2]) / 10.);
				mdlVec_scaleToLengthInPlace(&pp[3], mdlVec_distance(&p[0], &p[2]) / 10.);
				mdlVec_addInPlace(&pp[0], &pp[1]);
				mdlVec_addInPlace(&pp[2], &pp[3]);

				//if (mdlElmdscr_spaceFillet(&edpF, elTmpl, edpTwo, edpOne, dFilletRadiusUors, &ppp) == SUCCESS)
				if (mdlElmdscr_fillet(&elTmp, elTmpl, edpTwo, edpOne, dFilletRadiusUors, &ppp, &rm) == SUCCESS)
				{
					double dst[2];
					DVec3d pt[2];
					double prm[2];
					mdlElmdscr_new(&edpF, 0, &elTmp);

					//MSBsplineCurve  dcrv[2];
					mdlBspline_convertToCurve(&dcrv[0], edpOne);
					mdlBspline_convertToCurve(&dcrv[1], edpTwo);

					mdlElmdscr_extractEndPoints(&ddd[0], &ddd[1], &ddd[2], &ddd[3], edpF, ACTIVEMODEL);

					dfilang = mdlVec_angleBetweenVectors(&ddd[1], &ddd[3]) * fc_180overpi;

					mdlBspline_minimumDistanceToCurve(&dst[0], &pt[0], &prm[0], &ddd[0], &dcrv[0]);
					mdlBspline_minimumDistanceToCurve(&dst[1], &pt[1], &prm[1], &ddd[2], &dcrv[1]);

					mdlBspline_freeCurve(&dcrv[0]);
					mdlBspline_freeCurve(&dcrv[1]);
					mdlElmdscr_freeAll(&edpF);

					//res = mdlElmdscr_partialDelete(&edpOne, NULL, edpOne, &dd[0], NULL, &pp[0], -1);
					//res = mdlElmdscr_partialDelete(&edpTwo, NULL, edpTwo, &dd[2], NULL, &pp[2], -1);

					mdlElmdscr_generatePartial(&edpOne, edpOne, 0.0, prm[0], TRUE);
					mdlElmdscr_generatePartial(&edpTwo, edpTwo, prm[1], 1.0, TRUE);

					//{
					//	DVec3d qqq[2];
					//	DVec3d www[2];
					//	qqq[0] = dd[0];
					//	qqq[1] = pp[0];
					//	www[0] = dd[2];
					//	www[1] = pp[2];
					//	mdlLine_create(&elTmp, NULL, qqq);
					//	reinCreateBarAxisLine(&elTmp, NULL, TRUE);
					//	mdlLine_create(&elTmp, NULL, www);
					//	reinCreateBarAxisLine(&elTmp, NULL, TRUE);
					//}

					bAdd = TRUE;
				}
			}
			else if (bZeroFillet)
			{
				DVec3d pq[2];
				pq[0] = pp[0];
				pq[1] = pp[2];
				mdlArc_create(&elTmp, elTmpl, pq, 0., 0., NULL, 0., 0.); // нулевая арка
				dfilang = mdlVec_angleBetweenVectors(&pp[1], &pp[3]) * fc_180overpi;
				bAdd = TRUE;
			}
		}


	//if (curPos.bar.pnum == 166)
	//{
	//	printf("");
	//}

		//=====================================
		if (edpOne) // edpOne м.б. NULL если обрезан филлетами до нуля
		{
			MSWCH ws[50];
			XMLFragmentListP    pCurrent = NULL;

			ilen[0] = 0;
			ilen[1] = 0;

			if (mdlElement_getType(&edpOne->el) == ARC_ELM || mdlElement_getType(&edpOne->el) == ELLIPSE_ELM)
			{
				wcscpy(ws, L"ARC");
				if (mdlArc_extract(0, 0, 0, &drad[0], &drad[1], 0, 0, &edpOne->el) != SUCCESS)
				{
					drad[0] = 0.;
					drad[1] = 0.;
					//ZeroMemory(drad, sizeof(drad));
				}

				if (mdlCnv_UORToMaster(&drad[0], (drad[0] + drad[1]) / 2., ACTIVEMODEL) != SUCCESS) drad[0] = 0.;

				if (rbP)
					irad = rbP->brad[elcnt];
				else
					irad = roundExt(drad[0], ROUND_LIN);
			}
			else
			{
				wcscpy(ws, L"LINE");
				irad = 0;
			}

			if (rbP)
			{
				ilen[0] = rbP->blen[elcnt][0];
				ilen[1] = rbP->blen[elcnt][2];
			}
			else if (mdlMeasure_linearProperties(&dlen, 0, 0, 0, 0, 0, 0, 0, edpOne, -1) == SUCCESS)
			{
				if (mdlCnv_UORToMaster(&dlen, dlen, ACTIVEMODEL) == SUCCESS)
					ilen[0] = ilen[1] = roundExt(dlen, ROUND_LIN);
				else
					ilen[0] = ilen[1] = -1;
			}
			else
				ilen[0] = ilen[1] = -1;

			MSWCH wstr[100];

			_swprintf(wstr, L"%s;%i;%i;%i", ws, ilen[0], irad, ilen[1]);

			//SCPM2W(ws, s, 50); // for v8i
			pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeSegment);
			mdlXMLFragmentList_attachToElement(&pCurrent, &edpOne, TRUE);
		
			//=====================================
			mdlElmdscr_appendDscr(edpChain, edpOne);
			elcnt++;
			//=====================================

			if (edpText && rbP->runmet != 1)
			{
				DVec3d pText;
				DVec3d p[4];
				mdlElmdscr_extractEndPoints(&p[0], &p[2], &p[1], &p[3], edpOne, ACTIVEMODEL);
				//MSBsplineCurve crv;
				if (mdlBspline_convertToCurve(&crv, edpOne) == SUCCESS)
				{
					mdlBspline_evaluateCurvePoint(&pText, 0, &crv, 0.5);
					mdlBspline_freeCurve(&crv);
				}

				if (pcentP && !rbP->brad.empty())
				{
					WCH str[50];
					SPRN(str, L("R %d"), rbP->brad[0]);
					createNote(&edpText, &pText, pcentP, str); // todo 0 -> "R"
				}

				createLineText(&edpText, p, &pText, ilen[0], ilen[1], NULL, NULL, edpChain);

			}
		
		
		}
		else // стыковка филлетов
		{
			if (pointIsEqual(&ddq[2], &ddd[0], FALSE) == FALSE) // кривая стыковка
			{
				iFilKos = TRUE;
			}
		}

		ddq[0] = ddd[0];
		ddq[1] = ddd[1];
		ddq[2] = ddd[2];
		ddq[3] = ddd[3];


		if (bAdd) 
		{
			MSWCH wstr[50];
			XMLFragmentListP    pCurrent = NULL;
			MSElementDescr* edpF2 = NULL;

			mdlElmdscr_new(&edpF2, 0, &elTmp); // предварительрно созданная арка

			ilen[0] = 0;
			ilen[1] = 0;

			if (rbP)
			{
				ilen[0] = rbP->blen[elcnt][0];
				ilen[1] = rbP->blen[elcnt][2];
			}
			else if (mdlMeasure_linearProperties(&dlen, 0, 0, 0, 0, 0, 0, 0, edpF2, -1) == SUCCESS)
			{
				if (mdlCnv_UORToMaster(&dlen, dlen, ACTIVEMODEL) == SUCCESS)
					ilen[0] = ilen[1] = roundExt(dlen, ROUND_ARC);
				else
					ilen[0] = ilen[1] = -1;
			}
			else
				ilen[0] = ilen[1] = -1;


			if (rbP)
				irad = rbP->brad[elcnt];
			else
				irad = radius;

			if (rbP)
				dfilang = rbP->bang[elcnt];


			if (EQQ(dfilang, 180., 0.05)) dfilang = 0.;

			_swprintf(wstr, L"FILLET;%i;%i;%.5f;%i", ilen[0], irad, dfilang, iFilKos); // length, radius, angle, кривой

			//SCPM2W(ws, s, 50);
			pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeSegment);
			mdlXMLFragmentList_attachToElement(&pCurrent, &edpF2, TRUE);

			//=====================================
			mdlElmdscr_appendDscr(edpChain, edpF2);
			elcnt++;
			//=====================================

			if (edpText && rbP->runmet != 1)
			{
				DVec3d pText;
				DVec3d p[4];
				mdlElmdscr_extractEndPoints(&p[0], &p[2], &p[1], &p[3], edpF2, ACTIVEMODEL);
				//MSBsplineCurve crv;
				if (mdlBspline_convertToCurve(&crv, edpF2) == SUCCESS)
				{
					mdlBspline_evaluateCurvePoint(&pText, 0, &crv, 0.5);
					mdlBspline_freeCurve(&crv);
				}

				long iang = roundExt(dfilang, ROUND_STD);
				if (iang == 90) iang = 0;
				createLineText(&edpText, p, &pText, ilen[0], ilen[1], NULL, NULL, edpChain);

				if (mdlArc_extract(0, 0, 0, 0, 0, 0, &pCnt, &elTmp) != SUCCESS)
					pCnt = pText;

				//createLineText(&edpText, p, &pCnt, irad, iang, NULL, NULL, edpChain, L("R "), L("A "), &pText);
				
				WCH str[20];
				if (iang > 0)
					SPRN(str, L("R %d, A %d°"), irad, iang);
				else
					SPRN(str, L("R %d"), irad);

				mdlVec_interpolate(&pCnt, &pText, 3.0, &pCnt);
				createNote(&edpText, &pText, &pCnt, str);
			}

		}
	}



	//if (edpOne) mdlElmdscr_freeAll(&edpOne);
	//if (edpTwo) mdlElmdscr_freeAll(&edpTwo);


	if (elTmpl && edpChain)
	{
		UInt32 lvl;
		Symbology smb;
		mdlElement_getSymbology(&smb.color, 0, &smb.style, elTmpl);
		mdlElement_getProperties(&lvl, 0, 0, 0, 0, 0, 0, 0, elTmpl);

		func_amp(mdlElmdscr_setSymbology,edpChain), &smb.color, &smb.style, 0, 0);
		func_amp(mdlElmdscr_setProperties,edpChain), &lvl, 0, 0, 0, 0, 0, 0, 0);
	}


	writeLogOut(__FUNCTION__, 0);

	return cnt;
}

/*
/////////////////////////////////////////////
int reinCreateBarAxis( // use in reinSideDynamics
			MSElementDescr** edp,
			MSElementDescr** edpT,
			DVec3d* arP,
			int cnt,
			int radius,
			Transform* tmP,
			DgnModelRefP mrP,
			int bUseActiveSymb
			)
{
	int iArcCnt = 0;
	int iLineCnt = 0;
	RotMatrix rmTxt;
	Transform tmTxt;
	Transform tmRef;
	Transform* tmRefP = NULL;

	MSElementDescr* edpChain = *edp;
	MSElementDescr* edpText = NULL;
	int i;
	double dFilletRadiusUors = mdlCnv_masterUnitsToUors(radius);
	MSElement* elTmpl = NULL;

	if (edpChain == NULL) return cnt;

	if (edpT != NULL) edpText = *edpT;

	if (mrP && getRefNum(mrP) > 0)
	{
		mdlTMatrix_referenceToMaster(&tmRef, mrP);
		tmRefP = &tmRef;
	}



	if (bUseActiveSymb) 
		elTmpl = NULL;
	else
		elTmpl = &c0w0s0;


	if (iCfgVar_MinSegment) cnt = checkBarPoints(arP, NULL, NULL, cnt, NULL);


	for (i = 0; i < cnt - 1; i++)
	{
		DVec3d pt[2];
		DVec3d pLast;
		DVec3d pArc[3];
		DVec3d pTxt;
		int bPoint = FALSE;
		//int bAnk = TRUE;
		double ang = 0.;
		double th = 0.;

		if (i < (cnt-2) && radius > 0)
		{
			if (reinCreateFilletArc(&ang, NULL, pArc, &arP[i], &pTxt, dFilletRadiusUors) != SUCCESS)
				bPoint = TRUE;

			mdlTMatrix_getIdentity(&tmTxt);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
			ActiveParams::GetValue(th, ActiveDoubleParams::ACTIVEPARAM_TEXTHEIGHT);
#else
			mdlParams_getActive(&th, ACTIVEPARAM_TEXTHEIGHT);
#endif

			mdlVec_scaleToLengthInPlace(&pTxt, th);
			mdlTMatrix_setTranslation(&tmTxt, &pTxt);

			//printf(" >> i = %i, ang = %f   bPoint = %i\n", i, ang, bPoint);
		}
		else
			bPoint = TRUE;

		
		//// создание загиба если угол меньше 45°
		//if (
		//	bPoint == TRUE && 
		//	radius > 0 &&
		//	cnt > 2 &&
		//	(i == 0 || i == cnt - 3) &&  // если начало или конец, промежуток пока отрабатывает неправильно
		//	(fabs(ang) < fc_piover4) // если угол меньше 45°
		//	)
		//{
		//	DVec3d pLn[2];
		//	//mdlSystem_enterDebug();
		//	if (reinCreateTangentArc(pArc, pLn, &arP[i], dFilletRadiusUors, i, bAnk) == SUCCESS)
		//	{
		//		if (bAnk)
		//		{
		//			if (i == 0) 
		//				arP[i] = pLn[0]; // заполнение значения для выражения pt[0] = arP[i];
		//			else
		//				arP[i+2] = pLn[0]; // заполнение значения для выражения pt[1] = arP[i+1]; 
		//		}
		//		bPoint = FALSE;
		//	}
		//}

		if (i == 0) 
			pt[0] = arP[i];
		else
			pt[0] = pLast;


		if (bPoint == TRUE)
			pt[1] = arP[i+1];
		else
			pt[1] = pArc[0];



		mdlLine_create(&elLine, elTmpl, pt);
		if (tmP) mdlElement_transform(&elLine, &elLine, tmP);
		if (tmRefP) mdlElement_transform(&elLine, &elLine, tmRefP);


		if (bPoint == FALSE)
		{
			mdlArc_createByPoints(&elMon, elTmpl, pArc);

			// проверка - вектор конца линии и начала арки должны совпадать
			//	{
			//		DVec3d pLineDir;
			//		DVec3d pArcDir;
			//		MSElementDescr* edpLine = NULL;
			//		MSElementDescr* edpArc = NULL;
			//		mdlElmdscr_new(&edpLine, 0, &elLine);
			//		mdlElmdscr_new(&edpArc, 0, &elMon);
			//		mdlElmdscr_extractEndPoints(0, 0, 0, &pLineDir, edpLine, 0);
			//		mdlElmdscr_extractEndPoints(0, &pArcDir, 0, 0, edpArc, 0);
			//		mdlElmdscr_freeAll(&edpLine);
			//		mdlElmdscr_freeAll(&edpArc);

			//		double an = mdlVec_angleBetweenVectors(&pLineDir, &pArcDir);

			//		if (fabs(an) < (fc_pi - 0.1) || fabs(an) > (fc_pi + 0.1))
			//		{
			//			pt[1] = arP[i+1];
			//			mdlLine_create(&elLine, elTmpl, pt);
			//			if (tmP) mdlElement_transform(&elLine, &elLine, tmP);
			//			if (tmRefP) mdlElement_transform(&elLine, &elLine, tmRefP);
			//			bPoint = TRUE;
			//		}
			//	}


		}



		mdlElmdscr_appendElement(edpChain, &elLine);
		if (edpText) createLineText(&edpText, pt, NULL, arLineLens[iLineCnt], arLineLens[iLineCnt], tmP, tmRefP, 0);
		iLineCnt++;


		if (bPoint == TRUE)
		{
			pLast = pt[1];
		}
		else
		{

			if (edpText)
			{
				DVec3d pTng;
				MSElementDescr* edpArc;
				double an;

				mdlElmdscr_new(&edpArc, NULL, &elMon);

				mdlElmdscr_distanceAtPoint (0, 0, &pTng, edpArc, &pArc[1], NULL);

				an = mdlVec_angleXY(&pTng);
				if (fabs(an) > fc_piover2) mdlVec_negateInPlace(&pTng);

				mdlRMatrix_fromXVector(&rmTxt, &pTng);
				mdlRMatrix_getInverse(&rmTxt, &rmTxt);

				mdlElmdscr_freeAll(&edpArc);
			}


			if (tmP) mdlElement_transform(&elMon, &elMon, tmP);
			if (tmRefP) mdlElement_transform(&elMon, &elMon, tmRefP);
			mdlElmdscr_appendElement(edpChain, &elMon);

			if (edpText)
			{
				SPRN(s, L("%i"), arArcLens[iArcCnt++]);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
				mdlText_create(&elTxt[0], NULL, s, &pArc[1], &rmTxt, NULL, &txtParam[4], NULL, NULL);
#else
				mdlText_create(&elTxt[0], NULL, s, &pArc[1], NULL, &rmTxt, &txtParam[4], NULL);
#endif

				mdlElement_transform(&elTxt[0], &elTxt[0], &tmTxt);
				if (tmP) mdlElement_transform(&elTxt[0], &elTxt[0], tmP);
				if (tmRefP) mdlElement_transform(&elTxt[0], &elTxt[0], tmRefP);
				mdlElmdscr_appendElement(edpText, &elTxt[0]);
			}

			pLast = pArc[2];
		}

	}

	return cnt;

}
//////////////////////////////////////////////////////
void reinCalcAnker()
{
	double dlen;

	rInfo.aInfo.anklen = ankers[rInfo.aInfo.arm][rInfo.aInfo.bet] * rInfo.aInfo.diam;


	//mdlSystem_enterDebug();

	// округление
	//===================================
	dlen = (rInfo.aInfo.anklen + 9) / 10;
	rInfo.aInfo.anklen = (int)(dlen * 10.);
	//===================================

	rInfo.aInfo.applen = rInfo.aInfo.anklen - fillets[rInfo.aInfo.diam].arclen - (rInfo.aInfo.wall - fillets[rInfo.aInfo.diam].radius);

	if (rInfo.aInfo.applen < 0) rInfo.aInfo.applen = 0;

	if (rInfo.aInfo.applen > 0)
		rInfo.aInfo.apprad = rInfo.aInfo.applen + fillets[rInfo.aInfo.diam].radius;
	else
		rInfo.aInfo.apprad = 0;


}
*/

/////////////////////////////////////////
int reinGetLevelMask(MSElementDescrCP edP, UInt32 fp, DgnModelRefP mrP)
{
	BitMaskCP  levelMaskP = NULL;
	
	UInt32 levelID;
	int iLvlMask = 0;
	int i;
	MSElementDescrP edp = NULL;

	if (edP) 
	{
		edp = (MSElementDescrP)edP;
	}
	else if (edP == NULL && fp > 0) 
	{
		if (mdlElmdscr_read(&edp, fp, mrP, FALSE, 0) == 0) return 0;
	}
	else
		return 0;

	if (edp->h.dgnModelRef == NULL && mrP == NULL) 
	{
		return 0;
	}
	else if (edp->h.dgnModelRef != NULL && mrP == NULL)
	{
		mrP = edp->h.dgnModelRef;
	}

	mdlElmdscr_getProperties(&levelID, 0, 0, 0, 0, 0, 0, 0, edp);

	for (i = 0; i < MAX_VIEWS; i++)
	{
		int msk = 0;
		levelMaskP = mdlView_getLevelDisplayMask(mrP, i,
			VIEW_LEVEL_DISPLAY_TYPE_NORMAL);
		msk = mdlBitMask_testBit(levelMaskP, levelID - 1);

		iLvlMask = iLvlMask | (msk << i);
	}

	if (edP == NULL && edp) mdlElmdscr_freeAll(&edp);

	return iLvlMask;


}



///////////////////////////////////
void setReinVertNorm(ReinBar* rbP, ReinVert* rvP, ReinVert* rvNearP)
{
	DVec3d cross;
	ReinVertVec* rvvP = &rvP->rvv;
	ReinVertVec* rvNvP = &rvNearP->rvv;

	writeLogIn(__FUNCTION__, 0);

	double an = mdlVec_angleBetweenVectors(&rvvP->tdir, &rvNvP->tdir);

	if (EQ(an, fc_pi)) rvP->isin = FALSE;

	mdlVec_crossProduct(&cross, &rvvP->tdir, &rvNvP->tdir);
	mdlVec_crossProduct(&rvvP->tnorm, &cross, &rvvP->tdir);
	mdlVec_normalize2(&rvvP->tnorm);
	
	if (iDebug) sprintf(sLogMes, "rvvP->tnorm  %.3f %.3f %.3f\n", rvvP->tnorm.x, rvvP->tnorm.y, rvvP->tnorm.z); writeLog(0, 0);

	writeLogOut(__FUNCTION__, 0);

}


double roundex( double v ){ return floor( v + .5 ); }


//////////////////////////////////////////////////////
int reinCalcSpaceData(
MSElementDescr  *edP,
ReinSpace* rsP,
ReinCalc* rcP,
int bReserved,
int bAddElem 
)
{


	ReinElement re;

	ReinBar rb;

	int evencnt[2] = {0,0};


	Transform tm;
	//MSElementDescr* edpRot;
	double d;
	double w;
	int cnt = 0;
	UInt32 fp;
	//int bLast = FALSE; // последний стержень 

	//_DVector3d range;
	RotMatrix rm;
	DVec3d pb[2];
	//MSElementDescr* edp;
	//MSElementDescr* edpChain0;
	//MSElementDescr* edpChain;
	//MSElementDescr* edpSketch;


	//DVec3d* arP;
	//DVec3d pv[3];
	int i;

	//const BitMask  *levelMaskP = NULL;
	//UInt32 levelID;
	int iLvlMask = 0;
	//int iSktMask = 0;

	double dFilletRadiusUors;
	double dBarRadiusUors;

	//int elClass = CONSTRUCTION_CLASS; 

	//ELID idAssoc = 0;


	UInt32 lev;
	#if MSVERSION == 0x850 // ???
		int ggn;
	#else
		UInt32 ggn;
	#endif
	UInt32 clr = 0;

	int cqty = 0; // расчетное количество - предполагаемое количество стержней



	
	//printf("reinCalcSpaceData\n");


	if (edP == NULL) return ERROR;
	if (rsP == NULL) return ERROR;
	if (rcP == NULL) return ERROR;


	//if (edP->h.isValid == FALSE) return; // by undo = 0


	re.clear();


	//iLvlMask = reinGetLevelMask(edP, 0, 0);






	fp = mdlElmdscr_getFilePos(edP);
	//printf("mdlElmdscr_getFilePos = %i\n", fp);
	if (fp == 0) return  ERROR;

	// temp ==================
	//rsP->id_org[0] = 218679;
	//rsP->id_end[0] = 218681;
	//rsP->id_org_cnt = 1;
	//rsP->id_end_cnt = 1;
	// temp ==================


	re.rs = *rsP;
	re.fpRS = fp;
	re.idRS = mdlElement_getID(&edP->el);
	re.modelRef = edP->h.dgnModelRef;
	re.iLevelMask = iLvlMask;



	rcP->rng.clear();

	if (edpRot) mdlElmdscr_freeAll(&edpRot);

	mdlElmdscr_duplicate (&edpRot, edP);

	

	mdlTMatrix_getIdentity(&tm);
	mdlTMatrix_setTranslation(&tm, &pts[0]);
	mdlTMatrix_getInverse(&tm, &tm);
	func_amp(mdlElmdscr_transform,edpRot), &tm);

	mdlTMatrix_getIdentity(&tm);
	mdlTMatrix_fromRMatrix(&tm, &rcP->rm);
	mdlTMatrix_getInverse(&tm, &tm);
	func_amp(mdlElmdscr_transform,edpRot), &tm);

	//if (rcP->numRef)
	//{
	//	mdlTMatrix_getInverse(&tm, &rcP->tmRef);
	//	mdlElmdscr_transform(edpRot, &tm);
	//}


	mdlTMatrix_getIdentity(&tm);//-
	mdlTMatrix_setTranslation(&tm, &pts[0]);//-
	mdlTMatrix_rotateByRMatrix(&tm, &tm, &rcP->rm);//-



	mdlVec_subtractPoint(&pb[0], &pts[rcP->iRSind], &pts[0]);//-
	mdlVec_subtractPoint(&pb[1], &pts[rsP->segmIndex], &pts[0]);//-
	mdlRMatrix_invert(&rm, &rcP->rm);//-
	mdlRMatrix_multiplyPoint(&pb[0], &rm);//-
	mdlRMatrix_multiplyPoint(&pb[1], &rm);//-

	//mdlElmdscr_display (edpRot, edpRot->h.dgnModelRef, NORMALDRAW);

	//{
	//	int res;
	//	MSBsplineCurve  curve1;

	//	res = mdlBspline_convertToCurve(&curve1, edpRot);

	//	if (res == SUCCESS)
	//	{
	//		mdlElmdscr_freeAll(&edpRot);

	//		mdlBspline_createCurve(&edpRot, &edP->el, &curve1);

	//		mdlBspline_freeCurve(&curve1);
	//	}
	//	else
	//	{
	//		printf("mdlBspline_convertToCurve returns %i\n", res);
	//	}
	//}




	dBarRadiusUors = mdlCnv_masterUnitsToUors(rsP->diam / 2.);


	dFilletRadiusUors = mdlCnv_masterUnitsToUors(getBendRadius(0, rsP));


	mdlRMatrix_getIdentity(&rm);
	mdlElmdscr_computeRange(&rcP->rng.org, &rcP->rng.end, edpRot, &rm);

	rcP->width = mdlCnv_uorsToMasterUnits(rcP->rng.end.y - rcP->rng.org.y);
	rcP->dist[0] = rsP->offset[0];

	d = rcP->rng.org.y + mdlCnv_masterUnitsToUors(rsP->offset[0]);


	rcP->qty = 0;
	rcP->lencmn = 0.;


	evencnt[1] = rsP->lap[2];


	//w = rcP->rng.end.y; // ширина
	w = fabs(rcP->rng.end.y - rcP->rng.org.y); // ширина



	if ((int)rsP->spacef > 0) cqty = (int)
		(
			(w - mdlCnv_masterUnitsToUors(rsP->offset[0])) / mdlCnv_masterUnitsToUors(rsP->spacef) 
			+ 1.
		);


	//mdlSystem_enterDebug();

	while(d < w || EQ(d,w))
	{
		//double len;
		//DVec3d pvec[2];


		evencnt[1] = !evencnt[1];
		evencnt[0] = !evencnt[1];


		mdlElmdscr_getProperties(&lev, &ggn, 0, 0, 0, 0, 0, 0, edP);
		mdlElement_getSymbology(&clr, 0, 0, &edP->el);



		// расчет точек стержня
		// ==================================================
		cnt = reinCalcSpacePoints(edpRot, 
									rsP, 
									rcP, 
									d, 
									ptsBar, 
									ptsUnRotCompare, 
									ptsUnRotForDraw, 
									TRUE,                       // full bar
									evencnt[0] * rsP->lap[0],  // laps
									evencnt[1] * rsP->lap[1]
									);
		// ==================================================


		//printf(" ###############################\n");
		//for (i = 0; i < cnt; i++)
		//{
		//	printf("x=%.0f y=%.0f z=%.0f\n", ptsBar[i].x, ptsBar[i].y, ptsBar[i].z);
		//}




		if (cnt) // если есть точки
		{

			// сохраняем данные отдельного стержня для расчета позиций
			rb.numpts = cnt;//
			rb.cnumpts = cnt;//
			rb.elemid = re.idRS;//
			rb.diam = rsP->diam;//
			rb.runmet = rsP->runmet;//

			rb.lap[0] = rsP->lap[0];
			rb.lap[1] = rsP->lap[1];
			rb.lap[2] = rsP->lap[2];

			rb.term[0] = rsP->trm[0];
			rb.term[1] = rsP->trm[1];

			for (int a = 0; a < 10; a++)
			{
				rb.termPar[a][0] = rsP->trmPar[a][0];
				rb.termPar[a][1] = rsP->trmPar[a][1];
			}
			//rb.termPar[0][1] = rsP->trmPar[0][1];
			//rb.termPar[1][0] = rsP->trmPar[1][0];
			//rb.termPar[1][1] = rsP->trmPar[1][1];
			//rb.termPar[2][0] = rsP->trmPar[2][0];
			//rb.termPar[2][1] = rsP->trmPar[2][1];

			rb.modrefP = edP->h.dgnModelRef;
			rb.numRef = rcP->numRef;//..

			rb.segmIndex = rcP->iMLind;//
			rb.mainSgmIndex = rcP->iMLind;//
			rb.mainPtsIndex = rcP->iMLind;//
			//rb.haslap = rsP->lap[0] || rsP->lap[1];//

			for (i = 0; i < rb.numpts; i++) // numpts == cnumpts
			//for (i = 0; i < rb.rpts.size() && i < rb.apts.size(); i++) // numpts == cnumpts
			{
				rb.apts[i].x = (mdlCnv_uorsToMasterUnits(ptsUnRotForDraw[i].x));
				rb.apts[i].y = (mdlCnv_uorsToMasterUnits(ptsUnRotForDraw[i].y));

				rb.rpts[i] = ptsBar[i];
				rb.rfa[i] = 0;
			}

			barCalcComparePoints(&rb, FALSE, NULL);

			//========================================
			rb.createBar(edP,                   // reinCalcSpaceData()
						TRUE,                      // данные ReinBar готовы, пересчитывать ненадо
						bAddElem,                  // сохранять элемент или нет
						0, 0,                      // без смещения
						rcP->qty + 1, cqty,        // номер, количество
						0, 0 // laps
						);
			//========================================

			rcP->qty++;

		}


		rcP->dist[2] = mdlCnv_uorsToMasterUnits(d);

		d += mdlCnv_masterUnitsToUors(rsP->spacef);


		//printf("%i %i\n", rcP->qty, bLast);

	}


	rcP->dist[1] = (double)rsP->offset[0] + rsP->spacef * (rcP->qty - 1);

	rcP->cnt = cnt;

	//printf("%i %i\n", rcP->qty, cqty);
	


	return SUCCESS;


}

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ECX callback
////////////////////////////////////
void  callbackAttrChanged(
	XAttributeHandleCP xAttr, 
	DgnPlatform::ChangeTrackInfo *info, 
	bool *cantBeUndoneFlag
)
{
	UInt32 sz = xAttr->GetSize();

}
#endif



//////////////////////////////////////////////////////
int reinCalcSurfRevolution(
						MSElementDescr* edpBar, // may be complex element, full calculation
						ReinElement* reP,
						DVec3d* pCent, // center point
						DVec3d* pAxis, // ось вращения
						double swan, // sweep angle
						ELID prid,
						DgnModelRefP mrP
						)
{

	int cqty = 0;
	int evencnt[2] = { 0,0 };
	ReinBar rb;
	//DVec3d pCnt;
	double ddyn = 0.;
	double dspace = 0.;
	double doffs[2];
	double ddiam = 0.;
	double dend = 0.;
	int num = 0;
	DVec3d pBarNorm;

	ReinSpace* rsP = &reP->rs;

	copySpaceData(rsP, &rb, TRUE, NULL, TRUE);

	rb.modrefP = mrP;

	evencnt[1] = rb.lap[2];

	if (mdlElmdscr_extractNormal(&pBarNorm, 0, edpBar, pAxis) != SUCCESS) return SUCCESS;

	writeLogIn(__FUNCTION__, 0);

	int bPerp = mdlVec_arePerpendicular(&pBarNorm, pAxis);

	if (!bPerp)
	{
		mdlOutput_messageCenterW(MESSAGE_ERROR, L"Палочки должны быть попендикулярны", L"", MESSAGE_ALERT_BALLOON);
		writeLogOut(__FUNCTION__, 0);
	}

	// rsP->space // минимальный радиус, вроде как
	// радиус шага
	int isprad = rsP->spacerad;
	if (isprad == 0)
	{

	}




	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;
}

//////////////////////////////////////////////////////
int reinCalcSurfExtrusion(
						MSElementDescr* edpBar, // may be complex element
						ReinElement* reP,
						DVec3d* pDir,
						double dist,
						ELID prid,
						DgnModelRefP mrP
						)
{

	int cqty = 0;
	int evencnt[2] = {0,0};
	ReinBar rb;
	//DVec3d pCnt;
	double ddyn = 0.;
	double dspace = 0.;
	double doffs[2];
	double ddiam = 0.;
	double dend = 0.;
	int num = 0;
	DVec3d pBarNorm;

	ReinSpace* rsP = &reP->rs;

	copySpaceData(rsP, &rb, TRUE, NULL, TRUE);

	rb.modrefP = mrP;

	evencnt[1] = rb.lap[2];

	if (mdlElmdscr_extractNormal(&pBarNorm, 0, edpBar, pDir) != SUCCESS) return SUCCESS;

	writeLogIn(__FUNCTION__, 0);

	double dan = mdlVec_angleBetweenVectors(pDir, &pBarNorm);
	if (dan > fc_piover2) dan = fabs(dan - fc_pi);

	// correct space according to angle
	if (iCfgVar_SpaceHoldLine)
		dspace = mdlCnv_masterUnitsToUors(rb.spacef) / cos(dan);
	else
		dspace = mdlCnv_masterUnitsToUors(rb.spacef);

	doffs[0] = mdlCnv_masterUnitsToUors(rb.offset[0]) / cos(dan);
	doffs[1] = mdlCnv_masterUnitsToUors(rb.offset[1]) / cos(dan);
	ddiam = mdlCnv_masterUnitsToUors(fillets[rb.diam].diamrif) / cos(dan);

	//===================================================

	ddyn = doffs[0];

	while(ddyn < dist)
	{
		dend = dist - ddyn;
		ddyn += dspace;
		cqty++;
	}


	if (cqty == 0) 
	{
		writeLogOut(__FUNCTION__, "cqty == 0");
		return ERROR;
	}
		//__asm nop;

	if (rb.offset[1] > 0 && dend > (doffs[1] + ddiam)) cqty++;



	//cqty = (int)
	//	(
	//		(dist - doffs[0]) / mdlCnv_masterUnitsToUors(rb.space) 
	//		+ 1.
	//	);

	//===================================================

	ddyn = doffs[0];


	while(ddyn < dist)
	{
		dend = dist - ddyn;

		if (dend < doffs[1]) ddyn = dist - doffs[1];

		evencnt[1] = !evencnt[1];
		evencnt[0] = !evencnt[1];

		rb.elemid = prid;

		num++;

		map<int, BarOver>::iterator it = reP->mapOvers.begin();
		it = reP->mapOvers.find(num);

		if (!(							// not (exist and deleted)
			it != reP->mapOvers.end()	// found
			&& it->second.isdel			// deleted
			))
		{
			bool bFree = false;
			MSElementDescr* edpBar2 = NULL;

			if (it != reP->mapOvers.end() && it->second.btmov)		// transformed
			{
				mdlElmdscr_duplicate(&edpBar2, edpBar);
				func_amp(mdlElmdscr_transform, edpBar2), & it->second.tmov);
				bFree = true;
			}
			else
				edpBar2 = edpBar;

			if (it != reP->mapOvers.end())
				rb.grnd = (it->second.isgnd != 0);
			else
				rb.grnd = false;

			rb.createBar(edpBar2,                     // from iterateReloadBarsData() - SURFACE_ELM
				FALSE,                    // пересчитать
				TRUE,                     // сохранить
				&ddyn, pDir,	              // смещение
				num, cqty,              // номер, количество
				evencnt[0] * rb.lap[0],   // laps
				evencnt[1] * rb.lap[1]
			);

			if (bFree) mdlElmdscr_freeAll(&edpBar2);
		}

		if (dend < doffs[1]) break;

		ddyn += dspace;
	}

	// до. стержень по отступу от конца
	if (rb.offset[1] > 0 && dend > (doffs[1] + ddiam))
	{
		ddyn = dist - doffs[1];

		evencnt[1] = !evencnt[1];
		evencnt[0] = !evencnt[1];

		num++;

		map<int, BarOver>::iterator it = reP->mapOvers.begin();
		it = reP->mapOvers.find(num);

		if (!(							// not (exist and deleted)
			it != reP->mapOvers.end()	// found
			&& it->second.isdel			// deleted
			))
		{
			bool bFree = false;
			MSElementDescr* edpBar2 = NULL;
			if (it != reP->mapOvers.end() && it->second.btmov)		// transformed
			{
				mdlElmdscr_duplicate(&edpBar2, edpBar);
				func_amp(mdlElmdscr_transform, edpBar2), & it->second.tmov);
				bFree = true;
			}
			else
				edpBar2 = edpBar;


			if (it != reP->mapOvers.end())
				rb.grnd = (it->second.isgnd != 0);
			else
				rb.grnd = false;

			rb.createBar(edpBar2,                     // from iterateReloadBarsData() - SURFACE_ELM
				FALSE,                    // пересчитать
				TRUE,                     // сохранить
				&ddyn, pDir,	              // смещение
				num, cqty,              // номер, количество
				evencnt[0] * rb.lap[0],   // laps
				evencnt[1] * rb.lap[1]
			);
			if (bFree) mdlElmdscr_freeAll(&edpBar2);
		}
	}

	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;
}


///////////////////////
bool isLevelDisplayed(MSElementDescr* edP, DgnModelRefP mrP, ReinElm* reP)
{
	LEVID lid = 0;
	BINT bdsp = FALSE;

	int res = ERROR;
	MSElementDescr* eddP = edP;

	// цикл так как на смартсолиде на верхнем элементе слоя нет
	while (res != SUCCESS && eddP != NULL)
	{
		mdlElmdscr_getProperties(&lid, 0, 0, 0, 0, 0, 0, 0, eddP);
		res = mdlLevel_getDisplay(&bdsp, mrP, lid);
		eddP = eddP->h.firstElem;

		if (reP && iCfgVar_PosListMerge == 2)
		{
			MSWCH levName[512];
			int st = mdlLevel_getName(levName, 512, mrP, lid);
			if (st == SUCCESS)
				reP->relmLevName = levName;
		}
	}

	if (res != SUCCESS)
		return true; // default
	else if (bdsp)
		return true;

	return false;

}


///////////////////////
bool isLevelLocked(MSElementDescr* edP, DgnModelRefP mrP)
{
	LEVID lid = 0;
	LevelElementAccess lac = LevelElementAccess_All;

	int res = ERROR;
	MSElementDescr* eddP = edP;

	// цикл так как на смартсолиде на верхнем элементе слоя нет
	while (res != SUCCESS && eddP != NULL)
	{
		mdlElmdscr_getProperties(&lid, 0, 0, 0, 0, 0, 0, 0, eddP);
		res = mdlLevel_getElementAccess(&lac, mrP, lid);
		eddP = eddP->h.firstElem;
	}

	if (res == SUCCESS && lac != LevelElementAccess_All)// == LEVEL_ELEMENT_ACCESS_LOCKED)
	{
		return true;
	}

	return false;

}


//////////////////////////////////////////////////////
//реакция на изменение элемента в режиме добавление/удаление: 
//образующего: 
//	add:	ReinSpace	SURFACE_ELM - reinCalcSurfExtrusion()
//				else - reinCalcSpace()
//		ReinBar		!axis - reinCreateDataBars()
//				axis - createBar()
//	del:	reinBarsDataDel()
//производного: 
//	add:	insertCurBarsMember2()
//	del:	mapElms.erase();
int iterateReloadBarsData(
MSElementDescr  *edP,
int            *args,
ScanCriteria    *pScanCriteria // use pIterScanCrit
)
{
	//ReinSpace rs;
	ReinElement relem;
	ReinBar rb;
	ReinElm re;
	int bAdd = TRUE;
	int bFileChange = FALSE;
	int bRegen = FALSE;
	CLIPDESC clipP = NULL;
	int view = 0;
	int res = 0;


	int tp;
	MSElementDescr* edpBar = NULL;
	DVec3d pDir;
	//DVec3d pCnt;
	double dist;
	//double angle;
	double d = 0.;

	
	writeLogIn(__FUNCTION__, 0);



	if (pIterScanCrit == NULL) // file changing
	{
		if (args != NULL) 
		{
			bAdd = args[0];
		}

		if (iDebug) sprintf(sLogMes, "bAdd = %i   \n", bAdd); writeLog(0, 0);

		bFileChange = TRUE;
	}
	else
	{
		if (args != NULL) bRegen = args[0];

		if (bRegen)
		{
			//int ilck1 = 0;
			//int ilck2 = 0;
			//mdlElement_getLock(&ilck1, &ilck2, mdlScanCriteria_getModel(pScanCriteria), &edP->el);
			if (isLevelLocked(edP, mdlScanCriteria_getModel(pScanCriteria)))
			{
				if (iDebug) sprintf(sLogMes, "element level is locked, returnung"); writeLog(0, 0);
				writeLogOut(__FUNCTION__, 0);
				return SUCCESS;
			}
		}
	}



	if (mdlModelRef_isActiveModel(edP->h.dgnModelRef) == FALSE)
	{
		MSElementDescr* edpClip = NULL;

		//int r = func_pma(mdlClip_getRefBoundary,clipP), edP->h.dgnModelRef, view);
		int r = myClip_getRefBoundary(&clipP, edP->h.dgnModelRef, &edpClip, view);


		if (r == SUCCESS && NOTNULL(clipP))
		{
			BINT bOverLap, bInside;
			MSElementDescr* edpOnce = NULL;
			Transform tm;

			mdlElmdscr_duplicate(&edpOnce, edP);

			mdlTMatrix_referenceToMaster (&tm, edP->h.dgnModelRef); // scale!

			func_amp(mdlElmdscr_transform,edpOnce), &tm);

			bInside = mdlClip_isElemInside(&bOverLap, edpOnce, GETPTR(clipP), view, TRUE);

			if (iDebug) sprintf(sLogMes, "mdlClip_isElemInside\n"); writeLog(0, 0);

			mdlElmdscr_freeAll(&edpOnce);
			myClip_free(clipP, &edpClip);

			if (!bInside) 
			{
				writeLogOut(__FUNCTION__, "if (bInside == false) ");
				return SUCCESS;
			}
		}
	}
	


	tp = mdlElement_getType(&edP->el);
	
	// ============ SURFACE =============
	if (tp == SURFACE_ELM)
	{

		//mdlSystem_enterDebug();

		DVec3d pCent;
		DVec3d pAxis;
		double swan = 0.;
		MSElementDescr* edpXt = NULL;

		//res = mdlSurface_extractExtrusion(&edpBar, &pDir, &dist, edP); // не работает при косой поверхности
		int resExt = mdlSurface_extractExtrusionExt(&edpBar, &pDir, &dist, edP, TRUE);
		int resRev = mdlSurface_extractRevolution2(&edpBar, &pCent, &pAxis, &swan, edP);

		//if (edpXt) mdlElmdscr_freeAll(&edpXt);

		//if (filePosReinFrom > 0)
		//{
		//	mdlElmdscr_read(&edpBar, filePosReinFrom, ACTIVEMODEL, 0, 0);
		//}

		
		//if (res == SUCCESS && readReinBarFromElement(&rb, edpBar, TRUE) == SUCCESS) 
		if (edpBar && (resExt == SUCCESS || resRev == SUCCESS) && 
			readReinSpaceFromElmd(&relem, edP, FALSE) == SUCCESS)
		{

			if (bAdd && resExt == SUCCESS)
			{
				reinCalcSurfExtrusion(edpBar, &relem, &pDir, dist, mdlElement_getID(&edP->el), ACTIVEMODEL);
			}
			else if (bAdd && resRev == SUCCESS)
			{
				//reinCalcSurfRevolution(edpBar, &relem, &pCent, &pAxis, swan, mdlElement_getID(&edP->el), ACTIVEMODEL);

				vector<ReinBar> newbars;
				relem.calcSurfRevolution( edpBar, &pCent, swan, newbars, ACTIVEMODEL, &pAxis ); // вычисление точек стержней для surface-а

				int i = 0;
				for (vector<ReinBar>::iterator it = newbars.begin(); it != newbars.end(); ++it)
				{
					it->createBar(NULL, TRUE, TRUE, 0, 0, i, (int)newbars.size(), 0, 0);
					i++;
				}
			}
			else
			{
				reinBarsDataDel(edP, TRUE);
			}

		}


		if (edpBar) mdlElmdscr_freeAll(&edpBar);

	}
	else if (tp == CELL_HEADER_ELM)
	{
		//mdlElmdscr_operation (edP, elmFunc, args, ELMD_ELEMENT);
	}

	// ==================================
	

	else if (readReinSpaceFromElmd(&relem, edP, TRUE) == SUCCESS)
	{

		ReinCalc rc;

		//mdlSystem_enterDebug();

		if (iDebug) sprintf(sLogMes, "_readReinSpaceFromElement() SUCCESS\n"); writeLog(0, 0);

		if (bAdd)
		{
			if (iDebug) sprintf(sLogMes, "-->> _reinCalcSpace(...)\n"); writeLog(0, 0);
			reinCalcSpace(NULL, edP, &relem.rs, &rc, edP->h.dgnModelRef, TRUE, TRUE, TRUE);

			//if (bFileChange) reinUpdateBarFacesAllViews(NORMALDRAW, edP->h.dgnModelRef, mdlElement_getID(&edP->el));
		}
		else
		{
			reinBarsDataDel(edP, TRUE);
		}

	}
	else if (readReinBarFromElement(&rb, edP, TRUE) == SUCCESS)
	{
	
		if (iDebug) sprintf(sLogMes, "_readReinBarFromElement() SUCCESS\n"); writeLog(0, 0);

		if (rb.bartype != BT_AXIS && rb.elemid > 0) // образующая ось
		{
			bool bShon = false;
			ELREF eref = getElemRefByID(ACTIVEMODEL, rb.elemid);

			for (UInt32 i = 0; pIterScanCrit != NULL && i < iElemIDcount; i++)
			{
				if (arElemID[i] == rb.elemid) bShon = true;
			}

			if (eref && !bShon)
			{
				//ReinData rd;
				MSElementDescr* edp;

				mdlElmdscr_getByElemRef (&edp, eref, ACTIVEMODEL, FALSE, 0);

				if (edp)
				{
					if (readReinDataFromElmd(&relem, edp, &rb) == SUCCESS)
					{
						//if (!bAdd) 
							reinBarsDataDel(edp, TRUE); // ReinData
						//if (bAdd) 
							reinCreateDataBars(bAdd, &relem, &rb, edP);
					}

					mdlElmdscr_freeAll(&edp);

					if (pIterScanCrit != NULL) // regen
						arElemID[iElemIDcount++] = rb.elemid;
				}
			}

			if (bAdd)
				iterateLoadReinBars(edP, 0, 0); // add
			else
			{
				map<UInt32, TransDescrP>::iterator it = curRM->mapTedCntP.find(mdlElmdscr_getFilePos(edP));

				if (it != curRM->mapTedCntP.end()) // found
				{
					if (it->second && mdlTransient_isValid(it->second))
					{
						mdlTransient_free(&it->second, TRUE);
						it = curRM->mapTedCntP.erase(it);
					}
				}
			}

		}
		else
		{
			if (bAdd)
			{
				rb.elemid = mdlElement_getID(&edP->el);
				rb.modrefP = edP->h.dgnModelRef;

				if (iDebug) sprintf(sLogMes, "-->> _reinCreateBar(...)\n"); writeLog(0, 0);
				rb.createBar(edP, FALSE, TRUE, NULL, NULL, 0, 1, rb.lap[0], rb.lap[1]);
				
				//if (bFileChange) reinUpdateBarFacesAllViews(NORMALDRAW, edP->h.dgnModelRef, mdlElement_getID(&edP->el));
			}
			else
			{
				reinBarsDataDel(edP, TRUE);
			}
		}




	}
	else if (re.getElmFromElement(&edP->el, edP->h.dgnModelRef) == SUCCESS && bRegen == FALSE)
	{

		if (iDebug) sprintf(sLogMes, "re.getElmFromElement() SUCCESS\n"); writeLog(0, 0);

		if (bAdd)
		{
			ReinElm rrelm;

			iClashShtamp++;

			if (readReinElmIso(&rrelm, edP, TRUE, TRUE) == SUCCESS)
				//&& rrelm.type == REIN_ELEM_ISO)
				//isLevelDisplayed не нужен так как манипуляции могут быть только с включенным слоем
				insertCurBarsMember2(&rrelm, edP, 0, NULL, -1); // func insert CurBars Member2 call
		}
		else
		{
			//UInt32 rn = getModelRefNum(edP->h.dgnModelRef);
			ReinModel* rmP = curRM->getRM(edP->h.dgnModelRef);
			UInt32 fpv = mdlElmdscr_getFilePos(edP);


			if (fpv && rmP)
			{
				ReinElm* reP = rmP->getReinElm(fpv);

				if (reP)
				{
					ReinElm* reDupP = rmP->getReinElm(reP->fpDup);
					if (reDupP) reDupP->fpDup = 0;

					// запоминаем позицию
					// диаметр стержня возможно поменяется, но позиция должна быть сохранена
					if (iModePosCatch && reP->bel.pnum)
					{ 
						map<long, ReinPos>::iterator it = rmP->getPosMap().find(reP->bel.pnum);

						if (it != rmP->getPosMap().end()) // found
						{
							RelmPair m_pair;

							m_pair = make_pair(reP->bel.elemid, reP->bel.inum);

							mapPosMem[m_pair] = it->second;
						}
					}

					//if (reP->tedP)
					//{
					//	if (mdlTransient_isValid(reP->tedP)) mdlTransient_free(&reP->tedP, 1);
					//	reP->tedP = NULL;
					//}

					removeClashByFP(fpv, 0, FALSE);

					rmP->mapElms.erase(fpv);
					//rmP->vecElms.erase(rmP->vecElms.begin() + index);
				}


				//delete rmP->arCurElms[fpv];
				//rmP->arCurElms[fpv] = NULL;
			}
		}
	}

	// catalog info added by app RCAT
	if (tp == DGNSTORE_HDR && bAdd)
	{
		XMLFragmentListP  oXMLFragmentList = NULL;
		oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

		if (oXMLFragmentList)
		{
			UShort ii = 0;

			XMLFragmentP        pXMLFragment;
			pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

			if (mdlXMLFragment_getAppType(&ii, pXMLFragment) == SUCCESS)
			{
				if (ii == appTypeCatInfo)
				{
					getCatInfo(&curCat, ACTIVEMODEL, false, false);

					//CatInfo ci;

					//if (scanCheckCatInfo(edP, &ci, NULL) == SUCCESS)
					//{
					//	curCat = ci;
					//}
				}
			}

			mdlXMLFragmentList_free(&oXMLFragmentList);

		}
	}


	writeLogOut(__FUNCTION__, 0);


	return SUCCESS;
}

//////////////////////////////////////////////////////
int iterateRedrawSpaces(
MSElementDescr  *edP,
void            *args,
ScanCriteria    *pScanCriteria
)
{
	//ReinSpace rs;
	ReinElement relem;
	int dm = *(int*)args;


	if (readReinSpaceFromElmd(&relem, edP, FALSE) == SUCCESS)
	{
		mdlElmdscr_display(edP, edP->h.dgnModelRef, dm);
	}

	return SUCCESS;
}



/////////////////////////////////////////
int extractComponentLinearByIndex ( 
MSElementDescr *elmdP ,
ReinCalc** rcPP,
DVec3d* arPts,
int elEDoffset
) 
{ 
	int num = 0, res = 0;
	ReinCalc* rcP = NULL;
	MSElementDescr *edCmpP = NULL;
	MSBsplineCurve  curve1;

	if (rcPP) rcP = *rcPP;

	//mdlSystem_enterDebug();


	if (elEDoffset >= 0)
		edCmpP = mdlElmdscr_atOffset (elmdP, elEDoffset, elmdP->h.dgnModelRef);
	else
	{
		//mdlSystem_enterDebug();
		edCmpP = elmdP;
	}

	if (edCmpP == NULL) return 0;


	res = mdlBspline_convertToCurve(&curve1, edCmpP);


	if (res == SUCCESS)
	{
		if (arPts)
		{
			for (int i = 0; i < curve1.params.numPoles; i++)
			{
				//arPts[i] = curve1.poles[i];
				mdlVec_fromDPoint3d(&arPts[i], &curve1.poles[i]);
			}
		}

		if (rcP) mdlBspline_extractCurveNormal(&rcP->vecZ, 0, 0, &curve1);

		num = curve1.params.numPoles;

		mdlBspline_freeCurve(&curve1);

	}
	else
		num = 0; // error


	//res = mdlElmdscr_stroke(&arP, &num, edCmpP, 0.1);



	//printf("res = %i ============================\n", res);

	//if (res == 0)
	//{
	//	int i;
	//	for (i=0;i<num;i++)
	//	{
	//		printf("%f  %f  %f\n", arPts[i].x, arPts[i].y, arPts[i].z);
	//	}
	//}
	//mdlSystem_enterDebug();
		

	return num;
} 



//////////////////////////////////
UInt32 getRefNum(DgnModelRefP mrP)
{

	UInt32 prm = 0;

	if (mdlRefFile_getIntegerParameters(&prm, REFERENCE_REFNUM, mrP) != SUCCESS)
		prm = 0;
/*
#if defined (MSVERSION) && (MSVERSION == 0xa00) // ref file
	UInt32 prm;
	//REFERENCE_REFNUM

	if (mdlRefFile_getIntegerParameters(&prm, REFERENCE_REFNUM, mrP) == SUCCESS)
		return prm;
	else
		return 0;
#else
	ReferenceFile* rfP;

	rfP = mdlRefFile_getInfo(mrP);

	if (rfP != NULL)
		return rfP->file_id.referenceNum;
	else
		return 0;

#endif
*/
	return prm;

}


/////////////////////////////////////////////////////
int reinCalcSpace(
						 MSElement* elP, // simple shape element, simple calculation
						 MSElementDescr* edP, // may be complex element, full calculation
						 ReinSpace* rsP,  
						 ReinCalc* rcP, 
						 DgnModelRefP mrP, 
						 int bUors,
						 int bReserved,
						 int bAddElem
						 )
{
	int num = 0, i;
	double m_space = 0.;
	double m_offset = 0.;
	
	MSElementDescr* edpFP = NULL;

	ReinSpace* rsPt;


	DVec3d pNorm;
	


	if (elP == NULL && edP == NULL) return ERROR;
	if (rcP == NULL) rcP = &rInfo.rcUnit;
	if (mrP == NULL) mrP = MASTERFILE;

	if (rsP == NULL)
		rsPt = &rInfo.rsVal;
	else
		rsPt = rsP;

	//printf("%f %f    ", space, offset);

	if (mdlModelRef_isActiveModel(mrP))
	{
		mdlTMatrix_getIdentity(&rcP->tmRef);
		rcP->numRef = 0;
	}
	else
	{
		mdlTMatrix_referenceToMaster (&rcP->tmRef, mrP);
		rcP->numRef = getRefNum(mrP);
	}


	if (bUors)
	{
		mdlCnv_masterToUOR(&m_space, rsPt->spacef, mrP);
		mdlCnv_masterToUOR(&m_offset, rsPt->offset[0], mrP);
	}
	else
	{
		m_space = rsPt->spacef;
		m_offset = rsPt->offset[0];
	}



	if (edP == NULL)
	{
		rcP->id = 0;
		mdlElmdscr_new(&edpFP, NULL, elP);
	}
	else
	{
		rcP->id = mdlElement_getID(&edP->el); // for note attributes - не исп., команды Note нет
		edpFP = edP;
	}


	num = extractComponentLinearByIndex(edpFP, &rcP, pts, rsPt->elemEDoffset);

	//mdlSystem_enterDebug();

	mdlVec_fromXYZ(&pNorm, 0., 0., 1.);
	mdlElmdscr_extractNormal (&rcP->vecZ, NULL, edpFP, &pNorm);

	rcP->dir[0] = pts[0];
	rcP->dir[1] = pts[1];




	if (edP == NULL && edpFP) mdlElmdscr_freeAll(&edpFP);



	// common calculations

	if (rsPt->segmIndex + 1 >= num) rcP->iRSind = 0; else rcP->iRSind = rsPt->segmIndex + 1;

	rcP->iMLind = rsPt->pts_org_cnt;


	mdlVec_subtractPoint(&rcP->vecX, &pts[rcP->iRSind], &pts[rsPt->segmIndex]);
	mdlVec_crossProduct(&rcP->vecY, &rcP->vecZ, &rcP->vecX);
	mdlRMatrix_from3Points(&rcP->rm, &pZero, &rcP->vecX, &rcP->vecY);
	mdlRMatrix_orthoNormalize(&rcP->rm, &rcP->rm);
	mdlVec_normalize(&rcP->vecX);
	mdlVec_normalize(&rcP->vecY);
	mdlVec_normalize(&rcP->vecZ);



	// simple shape element calculation
	if (edP == NULL) 
	{
		rcP->length[0] = mdlVec_distance(&pts[0], &pts[1]); // uors
		rcP->length[1] = rcP->length[0];
		rcP->lencmn = rcP->length[0];

		if (rsPt->pts_org_cnt > 0) rcP->lencmn += mdlVec_magnitude(&rsPt->pts_org[0].pVrtx);
		if (rsPt->pts_end_cnt > 0) rcP->lencmn += mdlVec_magnitude(&rsPt->pts_end[0].pVrtx);

		for (i = 1; i < (rsPt->pts_org_cnt); i++)
			rcP->lencmn += mdlVec_distance(&rsPt->pts_org[i].pVrtx, &rsPt->pts_org[i+1].pVrtx);

		for (i = 1; i < (rsPt->pts_end_cnt); i++)
			rcP->lencmn += mdlVec_distance(&rsPt->pts_end[i].pVrtx, &rsPt->pts_end[i+1].pVrtx);

		if (bUors == FALSE) mdlCnv_UORToMaster(&rcP->length[0], rcP->length[0], mrP);
		if (bUors == FALSE) mdlCnv_UORToMaster(&rcP->length[1], rcP->length[1], mrP);
		if (bUors == FALSE) mdlCnv_UORToMaster(&rcP->lencmn, rcP->lencmn, mrP);

		// if line
		if (num <= 2) return SUCCESS; 
		//if (mdlElement_getType(elP) != SHAPE_ELM) return SUCCESS;

		rcP->width = mdlVec_distance(&pts[1], &pts[2]); // uors
		if (bUors == FALSE) mdlCnv_UORToMaster(&rcP->width, rcP->width, mrP);



		//{
		//	char s1[100];
		//	char s2[100];
		//	char s3[100];
		//	mdlString_fromPoint(s1, &rcP->vecX, 0);
		//	mdlString_fromPoint(s2, &rcP->vecY, 0);
		//	mdlString_fromPoint(s3, &rcP->vecZ, 0);
		//	printf("%s   %s   %s\n", s1, s2, s3);
		//}


		if (m_space > 1.)
			rcP->qty = (int)((rcP->width - m_offset) / m_space + 1.);
		else
			rcP->qty = 0;


		rcP->dist[0] = m_offset;
		rcP->dist[1] = m_offset + m_space * (rcP->qty - 1);

	}
	else // complex calc
	{
		reinCalcSpaceData(edP, rsPt, rcP, bReserved, bAddElem);
	}

	if (bUors)
	{
		mdlCnv_masterToUOR(&rcP->dist[0], rcP->dist[0], mrP);
		mdlCnv_masterToUOR(&rcP->dist[1], rcP->dist[1], mrP);
	}


	syncToolbox();

	return SUCCESS;
}


MSElement elemview;

////////////////////////////
int buildViewShape(
int view, 
int drawmode
)
{

	Transform tr;
	DVec3d  corners[2];
	MSWindow* wnd;
	int bViewRotated = FALSE;
	int bViewChanged = FALSE;
	RotMatrix rmView;
	double an;

	DVec3d shapePoints[4];

	DVec3d ptsBck[4];
	DVec3d ptsDpt[4]; // аналогичен shapePoints
	DVec3d ptsFnt[4];

    DVec3d origin;
    DVec3d center;
    //DVec3d delta;
	double   activeZ = arViewPlanes[view].depth;
	DVec3d norm = arViewPlanes[view].normal;

	Point2d slt;
	Point2d srb;

    DVec3d lt; // left top
    DVec3d rb; // right bottom


	int ii;

	BSIRect rect;

	if (!(wnd = mdlWindow_viewWindowGet(view))) return FALSE;


	
	writeLogIn(__FUNCTION__, 0);

	if (iDebug) sprintf(sLogMes, "view = %i\n", view); writeLog(0, 0);

	mdlView_getViewRectangle(&rect, wnd, VIEW_INGLOBALCOORDS);
	slt.x = rect.origin.x + 7;
	slt.y = rect.origin.y + 7;
	srb.x = rect.corner.x - 7;
	srb.y = rect.corner.y - 7;

	mdlView_screenToPoint  ( &lt, &slt, view, VIEW_INGLOBALCOORDS);
	mdlView_screenToPoint  ( &rb, &srb, view, VIEW_INGLOBALCOORDS);
	mdlView_getParameters  ( &origin , &center , &arViewPlanes[view].viewsize, &rmView , &arViewPlanes[view].depth , view );

	if (
		EQ(rmView.form3d[0][0], arViewPlanes[view].rm.form3d[0][0]) &&
		EQ(rmView.form3d[1][0], arViewPlanes[view].rm.form3d[1][0]) &&
		EQ(rmView.form3d[2][0], arViewPlanes[view].rm.form3d[2][0]) &&
		EQ(rmView.form3d[0][1], arViewPlanes[view].rm.form3d[0][1]) &&
		EQ(rmView.form3d[1][1], arViewPlanes[view].rm.form3d[1][1]) &&
		EQ(rmView.form3d[2][1], arViewPlanes[view].rm.form3d[2][1]) &&
		EQ(rmView.form3d[0][2], arViewPlanes[view].rm.form3d[0][2]) &&
		EQ(rmView.form3d[1][2], arViewPlanes[view].rm.form3d[1][2]) &&
		EQ(rmView.form3d[2][2], arViewPlanes[view].rm.form3d[2][2])
		)
		bViewRotated = FALSE;
	else
		bViewRotated = TRUE;



	mdlVec_zero(&ptsBck[0]);
	mdlVec_zero(&ptsBck[1]);
	ptsBck[1].x = arViewPlanes[view].viewsize.x;
	mdlVec_zero(&ptsBck[2]);
	ptsBck[2].x = arViewPlanes[view].viewsize.x;
	ptsBck[2].y = arViewPlanes[view].viewsize.y;
	mdlVec_zero(&ptsBck[3]);
	ptsBck[3].y = arViewPlanes[view].viewsize.y;

	for (ii = 0; ii < 4; ii++)
	{
		ptsDpt[ii] = ptsBck[ii];
		ptsDpt[ii].z = arViewPlanes[view].depth;
		ptsFnt[ii] = ptsBck[ii];
		ptsFnt[ii].z = arViewPlanes[view].viewsize.z;
	}





	arViewPlanes[view].rm = rmView;

	// operations for getting of view rectangle
	//===========================================
	// get corners without offset
	corners[0].x = lt.x - center.x;
	corners[0].y = lt.y - center.y;
	corners[0].z = lt.z - center.z;
	corners[1].x = rb.x - center.x;
	corners[1].y = rb.y - center.y;
	corners[1].z = rb.z - center.z;

	// get transform
	mdlTMatrix_fromRMatrix(&tr, &arViewPlanes[view].rm);

	// rotate new view origin
	mdlTMatrix_transformPointArray(corners, &tr, 2);

	shapePoints[0].x = corners[0].x; // left
	shapePoints[0].y = corners[1].y; // bottom
	shapePoints[0].z = corners[0].z; // view depth

	shapePoints[1].x = corners[0].x; // left
	shapePoints[1].y = corners[0].y; // top
	shapePoints[1].z = corners[0].z; // view depth

	shapePoints[2].x = corners[1].x; // right
	shapePoints[2].y = corners[0].y; // top
	shapePoints[2].z = corners[0].z; // view depth

	shapePoints[3].x = corners[1].x; // right
	shapePoints[3].y = corners[1].y; // bottom
	shapePoints[3].z = corners[0].z; // view depth

	// invert matrix for returning
	mdlRMatrix_invert(&arViewPlanes[view].rm, &arViewPlanes[view].rm);

	// get transform
	mdlTMatrix_fromRMatrix(&tr, &arViewPlanes[view].rm);

	// get view rectangle
	mdlTMatrix_transformPointArray(shapePoints, &tr, 4);


	mdlTMatrix_transformPointArray(ptsBck, &tr, 4);
	mdlTMatrix_transformPointArray(ptsDpt, &tr, 4);
	mdlTMatrix_transformPointArray(ptsFnt, &tr, 4);



	// offset rect. to his own place
	for (ii = 0; ii < 4; ii++)
	{
		mdlVec_addPoint(&(shapePoints[ii]), &(shapePoints[ii]), &center);

		mdlVec_addPoint(&(arViewPlanes[view].ptsBck[ii]), &(ptsBck[ii]), &origin);
		mdlVec_addPoint(&(arViewPlanes[view].ptsDpt[ii]), &(ptsDpt[ii]), &origin);
		mdlVec_addPoint(&(arViewPlanes[view].ptsFnt[ii]), &(ptsFnt[ii]), &origin);

	}

	arViewPlanes[view].point = shapePoints[0];

	mdlVec_fromRotMatrixRow(&arViewPlanes[view].normal, &arViewPlanes[view].rm, 2);

	an = mdlVec_angleBetweenVectors(&arViewPlanes[view].normal, &norm);

	
	//if (mdlVec_areParallel(&arViewPlanes[view].normal, &norm) == FALSE ||
	//	!EQ(an, 0.) ||
	//	!EQ(activeZ, arViewPlanes[view].depth)
	//	)
	{
		bViewChanged = TRUE;
	}


	

	//===========================================

	//printf("==== view %i shape ========\n", view);
	//printf("1 - %.1f %.1f %.1f\n", shapePoints[0].x, shapePoints[0].y, shapePoints[0].z);
	//printf("2 - %.1f %.1f %.1f\n", shapePoints[1].x, shapePoints[1].y, shapePoints[1].z);
	//printf("3 - %.1f %.1f %.1f\n", shapePoints[2].x, shapePoints[2].y, shapePoints[2].z);
	//printf("4 - %.1f %.1f %.1f\n", shapePoints[3].x, shapePoints[3].y, shapePoints[3].z);


	// create shape
	//mdlShape_create(&arViewShapes[view], NULL, shapePoints, 4, 0);

	//{
	//	mdlShape_create(&elemview, NULL, shapePoints, 4, 0);
	//	if (drawmode >= 0) mdlElement_display(&elemview, (MstnDrawMode)drawmode);
	//	mdlElement_add(&elemview);
	//}

	//if (drawmode >= 0) mdlElement_display(&arViewShapes[view], drawmode);

	//printf("updated view shape %i\n", view);


	
	
	writeLogOut(__FUNCTION__, 0);

	return bViewChanged;
}

///////////////////
void updateViewArrays()
{

	int i;

	for (i = 0; i < 8; i++)
	{
		if (mdlView_isActive(i)) buildViewShape(i, -1);
	}

	
}


/*
/////////////////////////////////////////
int callbackViewPlot( int plotEvent, MSWindow* wP)
{
	//printf("plot event %i\n", plotEvent);

	char fname[300];

    if (plotEvent == PLOTUPDATE_PRE)
	{
		//open...
		mdlModelRef_getFileName(ACTIVEMODEL, fname, 300);

		strlwr(fname);

		char* s = strstr(fname, ".dgn");

		if (s)
		{
			s[0] = 0x0;

			strcat(fname, "_plot.dgn");

			try
			{
				mdlWorkDgn_createFile(&mrPlot, fname, DGNFILE_FORMAT_V8, ACTIVEMODEL, SEED_CopyDefaultData, 0, 0, TRUE);
			}
			catch (int e)
			{
			}

		}

	}
	else if (plotEvent == PLOTUPDATE_FINISHED)
	{
		//close
		try
		{
			if (mrPlot) mdlWorkDgn_closeFile(mrPlot);
		}
		catch (int e)
		{
		}
	}


	return SUCCESS;
}
*/




////////////////////////////////////////////////////////
int reinSetLap(BarPoint* arBPts, DVec3d* p, int bOrg, int bcnt, double dlap, int radius)
{

	writeLogIn(__FUNCTION__, 0);

	double dist = 0.;
	double otst = 0.;
	double rad = mdlCnv_masterUnitsToUors(radius);
	int i;
	int acnt = bcnt;
	DVec3d ptc;

	DVec3d arp[11];

	double dLen = mdlVec_distance(&p[0], &p[1]);

	if (bcnt == 0) 
		dist = dLen;
	else if (bcnt == 1) 
		dist = mdlVec_distance(&arBPts[0].pVrtx, &pZero);
	else
	{
		if (bOrg)
			dist = mdlVec_distance(&arBPts[0].pVrtx, &arBPts[1].pVrtx);
		else
			dist = mdlVec_distance(&arBPts[bcnt-1].pVrtx, &arBPts[bcnt-2].pVrtx);
	}

	//mdlSystem_enterDebug();


	if (bOrg)
	{

		for (i = 0; i < acnt; i++)
		{
			arp[i] = arBPts[i].pVrtx;
		}

		arp[acnt].x = 0.;
		arp[acnt].y = 0.;
		arp[acnt].z = 0.;

		acnt++;

		arp[acnt].x = dLen;
		arp[acnt].y = 0.;
		arp[acnt].z = 0.;

		acnt++;

		if (bcnt) reinCreateFilletArc(0, &otst, 0, &arp[0], 0, rad);
		//printf("org %.0f\n", mdlCnv_uorsToMasterUnits(otst));
	}
	else
	{

		for (i = 2; i < acnt + 2; i++)
		{
			arp[i] = arBPts[i - 2].pVrtx;
		}

		arp[0].x = -dLen;
		arp[0].y = 0.;
		arp[0].z = 0.;

		acnt++;

		arp[1].x = 0.;
		arp[1].y = 0.;
		arp[1].z = 0.;

		acnt++;

		if (bcnt) reinCreateFilletArc(0, &otst, 0, &arp[acnt - 3], 0, rad);
		//printf("end %.0f\n", mdlCnv_uorsToMasterUnits(otst));
	}


	//mdlSystem_enterDebug();


	if ((dist - otst) > dlap)
	{
		dist = dist - dlap;

		if (bOrg)
		{
			if (bcnt)
			{
				ptc = arp[0];
				mdlVec_subtractInPlace(&ptc, &arp[1]);
				mdlVec_scaleToLengthInPlace(&ptc, dist);
				mdlVec_addInPlace(&ptc, &arp[1]);
				arBPts[0].pVrtx = ptc;
			}
			else
			{
				p[1].x += dlap;
			}

		}
		else
		{
			if (bcnt)
			{
				ptc = arp[acnt-1];
				mdlVec_subtractInPlace(&ptc, &arp[acnt-2]);
				mdlVec_scaleToLengthInPlace(&ptc, dist);
				mdlVec_addInPlace(&ptc, &arp[acnt-2]);
				arBPts[bcnt-1].pVrtx = ptc;
			}
			else
			{
				p[0].x -= dlap;
			}
		}

		//. . ........
		// потом все равно обрезать по generatePartial
	}

	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;
}




//////////////////////////////////////////////////////
int reinCalcSpacePoints(
MSElementDescr  *edpRotR, // converted to curve
ReinSpace* rsP,
ReinCalc* rcP, // range must be ready
double d, // distance
DVec3d* arPoints,
DVec3d* arPtsUnRot,
DVec3d* arPtsDraw,
int bFullBar,
int lapbeg,
int lapend
)
{
	int cnt;
	RotMatrix rm;
	Transform tm;
	DVec3d pb[2];
	DVec3d p[2]; // for intersection line
	MSElementDescr* edp;
	int num; // number of intersections from function
	int i,b,a;
	//int k[3];
	double dAngleRad = 0.;
	int org_cnt = rsP->pts_org_cnt;
	int end_cnt = rsP->pts_end_cnt;
	double dlap[2] = {0.,0.};
	BarPoint porg[10];
	BarPoint pend[10];
	BarPoint* orgP;
	BarPoint* endP;


	writeLogIn(__FUNCTION__, 0);


	if (lapbeg) dlap[0] = mdlCnv_masterUnitsToUors(lapbeg);
	if (lapend) dlap[1] = mdlCnv_masterUnitsToUors(lapend);


	if (bFullBar == FALSE)
	{
		cnt = 2;
		org_cnt = 0;
		end_cnt = 0;
	}
	else
		cnt = 2 + (rsP->pts_org_cnt + rsP->pts_end_cnt);

	//dAngleRad = rsP->rot * fc_piover180;



	// main points of reinspace
	mdlVec_subtractPoint(&pb[0], &pts[rcP->iRSind], &pts[0]);
	mdlVec_subtractPoint(&pb[1], &pts[rsP->segmIndex], &pts[0]);
	mdlRMatrix_invert(&rm, &rcP->rm);
	mdlRMatrix_multiplyPoint(&pb[0], &rm);
	mdlRMatrix_multiplyPoint(&pb[1], &rm);

	// prepare tm for points
	mdlTMatrix_getIdentity(&tm);
	mdlTMatrix_setTranslation(&tm, &pts[0]);
	mdlTMatrix_rotateByRMatrix(&tm, &tm, &rcP->rm);

	//printf("reinCalcSpacePoints\n");
	//printf("%.0f   %.0f   %.0f\n", d, rcP->rng.end.y, fabs(d - rcP->rng.end.y));


	if ((rsP->offset[0] == 0 && rcP->qty == 0) || EQ(d, rcP->rng.org.y)) // если точно по направляющему стержню
	{
		p[0] = pb[0];
		p[1] = pb[1];
		num = 2;
	}
	else if (fabs(d - rcP->rng.end.y) < 10.) // если сопадает с правой гранью
	{
		//mdlSystem_enterDebug();

		p[0] = pb[0];
		p[1] = pb[1];
		p[0].y += (rcP->rng.end.y - rcP->rng.org.y);
		p[1].y += (rcP->rng.end.y - rcP->rng.org.y);
		num = 2;
	}
	else // иначе рассчитываем пересечение
	{
		p[0].x = rcP->rng.org.x;
		p[0].y = d;
		p[0].z = 0.;

		p[1].x = rcP->rng.end.x;
		p[1].y = d;
		p[1].z = 0.;

		mdlLine_create(&elMon, NULL, p);
		mdlElmdscr_new(&edp, NULL, &elMon);
		//============================================================
		num = mdlIntersect_allBetweenElms(0, p, 2, edpRotR, edp, 0, 0);
		//============================================================
		mdlElmdscr_freeAll(&edp);
	}

	if (p[0].x < p[1].x)
	{
		DVec3d ppp;
		ppp = p[0];
		p[0] = p[1];
		p[1] = ppp;
	}

	//if (rsP->cov[0] < 0) k[0] = -1; else k[0] = 1;
	//if (rsP->cov[1] < 0) k[1] = -1; else k[1] = 1;
	//if (rsP->cov[2] < 0) k[2] = -1; else k[2] = 1;

	// защитный слой
	// ===================================
	//if (rsP->cov[0])
	//{
	//	if (rsP->pts_org_cnt)
	//		p[1].x += k[0] * (mdlCnv_masterUnitsToUors(abs(rsP->cov[0])) + mdlCnv_masterUnitsToUors(fillets[rsP->diam].diamrif) / 2.);
	//	else
	//		p[1].x += mdlCnv_masterUnitsToUors(rsP->cov[0]);
	//}

	//if (rsP->cov[1])
	//{
	//	p[1].z += k[1] * (mdlCnv_masterUnitsToUors(abs(rsP->cov[1])) + mdlCnv_masterUnitsToUors(fillets[rsP->diam].diamrif) / 2.);
	//	p[0].z += k[1] * (mdlCnv_masterUnitsToUors(abs(rsP->cov[1])) + mdlCnv_masterUnitsToUors(fillets[rsP->diam].diamrif) / 2.);
	//}

	//if (rsP->cov[2])
	//{
	//	if (rsP->pts_end_cnt)
	//		p[0].x -= k[2] * (mdlCnv_masterUnitsToUors(abs(rsP->cov[2])) + mdlCnv_masterUnitsToUors(fillets[rsP->diam].diamrif) / 2.);
	//	else
	//		p[0].x -= mdlCnv_masterUnitsToUors(rsP->cov[2]);
	//}
	// ===================================

	
	//orgP = rsP->pts_org;
	//endP = rsP->pts_end;

	orgP = porg;
	endP = pend;

	for (i = 0; i < 10; i++) porg[i] = rsP->pts_org[i];
	for (i = 0; i < 10; i++) pend[i] = rsP->pts_end[i];


	if (lapbeg) reinSetLap(porg, p, 1, org_cnt, dlap[0], getBendRadius(0, rsP));
	if (lapend) reinSetLap(pend, p, 0, end_cnt, dlap[1], getBendRadius(0, rsP));


	// создание точек оси
	//===========================================
	if (num > 0 || (num == 0 && rsP->offset[0] == 0 && rcP->qty == 0)) // если есть точки
	{
		//printf("org qty = %i\n", org_cnt);
	
		for (i = 0; i < org_cnt; i++)
		{
			//if (rsP->rot)
			//{
			//	arPoints[i].y = d + orgP[i].p.y * sin(dAngleRad);
			//	arPoints[i].x = p[1].x + orgP[i].p.x;
			//	arPoints[i].z = p[1].z + orgP[i].p.y * cos(dAngleRad);
			//}
			//else
			//{
				arPoints[i].y = d;
				arPoints[i].x = p[1].x + orgP[i].pVrtx.x;
				arPoints[i].z = p[1].z + orgP[i].pVrtx.y;

				//printf("rsP->pts_org[%i].pVrtx.x = %f   rsP->pts_org[%i].pVrtx.y = %f\n", i, rsP->pts_org[i].pVrtx.x, i, rsP->pts_org[i].pVrtx.y);
			//}


			if (arPtsUnRot) // точки без поворота для ReinPositions
			{
				arPtsUnRot[i].x = p[1].x + orgP[i].pVrtx.x;
				arPtsUnRot[i].y = p[1].z + orgP[i].pVrtx.y;
				arPtsUnRot[i].z = 0.;
			}


		}


		arPoints[i] = p[1];
		if (arPtsUnRot) {arPtsUnRot[i].x = arPoints[i].x; arPtsUnRot[i].y = arPoints[i].z; arPtsUnRot[i].z = 0.;}
		i++;

		arPoints[i] = p[0];
		if (arPtsUnRot) {arPtsUnRot[i].x = arPoints[i].x; arPtsUnRot[i].y = arPoints[i].z; arPtsUnRot[i].z = 0.;}
		i++;

		if (rcP) // длина основного сегмента
		{
			double ml;

			ml = mdlCnv_uorsToMasterUnits(mdlVec_distance(&p[0], &p[1]));

			if (rcP->qty == 0)
			{
				rcP->mainlen[0] = ml;
				rcP->mainlen[1] = ml;
			}
			else
			{
				if (ml < rcP->mainlen[0]) rcP->mainlen[0] = ml;
				if (ml > rcP->mainlen[1]) rcP->mainlen[1] = ml;
			}

		}

		//printf("end qty = %i\n", end_cnt);

		b = 0;
		for (a = i; a < i + end_cnt; a++)
		{
			//if (rsP->rot)
			//{
			//	arPoints[a].y = d + endP[b].p.y * sin(dAngleRad);
			//	arPoints[a].x = p[0].x + endP[b].p.x;
			//	arPoints[a].z = p[0].z + endP[b].p.y * cos(dAngleRad);
			//}
			//else
			//{
				arPoints[a].y = d;
				arPoints[a].x = p[0].x + endP[b].pVrtx.x;
				arPoints[a].z = p[0].z + endP[b].pVrtx.y;

				//printf("rsP->pts_end[%i].pVrtx.x = %f   rsP->pts_end[%i].pVrtx.y = %f\n", b, rsP->pts_end[b].pVrtx.x, b, rsP->pts_end[b].pVrtx.y);
			//}

			if (arPtsUnRot) // точки без поворота для ReinPositions
			{
				arPtsUnRot[a].x = p[0].x + endP[b].pVrtx.x;
				arPtsUnRot[a].y = p[0].z + endP[b].pVrtx.y;
				arPtsUnRot[a].z = 0.;
			}

			b++;
		}

	}
	else
		cnt = 0;
	//===========================================


	if (arPtsDraw)
	{
		for (i = 0; i < cnt; i++) arPtsDraw[i] = arPtsUnRot[i];

		mdlVec_subtractPointArray(arPtsDraw, &arPtsUnRot[org_cnt], cnt); // начало в точку начала направляющего элемента

		//printf("  %f  ========================\n", d);
		//for (i=0;i<cnt;i++)
		//{
		//	printf("%f  %f  %f\n", ppp[i].x, ppp[i].y, ppp[i].z);
		//}
	}


	if (arPtsUnRot)
	{
		double an;
		RotMatrix rmv;
		mdlVec_subtractPointArray(arPtsUnRot, &arPtsUnRot[0], cnt); // начало в нулевую точку
		an = mdlVec_angleXY (&arPtsUnRot[1]); // угол по вектору первого сегмента
		mdlRMatrix_fromAngle(&rmv, an);
		mdlRMatrix_invert(&rmv, &rmv);
		mdlRMatrix_multiplyPointArray (arPtsUnRot, &rmv, cnt);
	}

	for (i = 0; i < cnt; i++)
	{
		mdlTMatrix_transformPoint(&arPoints[i], &tm);
		if (rcP->numRef) mdlTMatrix_transformPoint(&arPoints[i], &rcP->tmRef);
	}


	writeLogOut(__FUNCTION__, 0);

	return cnt;
}
/*
////////////////////////////////////////
void drawPreview(
	MSDLGP dbP
)
{
    int		    screen;
    byte	    *rawImageP, *subImageP;
    Point2d	    destSize;
    DialogItem	    *diP;
	Point2d       inSize; 
	
	BSIRect	    rectangle;
	MSWindow* wnd = mdlDialog_getNETDockingParentWindow(dbP);


    if (NULL ==
       (diP = mdlDialog_itemGetByTypeAndId (dbP, RTYPE_Generic, 1, 0)))
	return;


	writeLogIn(__FUNCTION__, 0);

    rectangle = diP->rect;
    mdlDialog_rectDrawBeveled (dbP, &rectangle, FALSE, TRUE);
    mdlDialog_rectInset (&rectangle, 2, 2);


    destSize.x = rectangle.corner.x - rectangle.origin.x + 1;
    destSize.y = rectangle.corner.y - rectangle.origin.y + 1;


    screen = mdlWindow_screenNumGet (wnd);

	if (SUCCESS == mdlImage_readFileToRGB (&rawImageP,
						&inSize,
						sCfgVar_PicAnker,
						-1, NULL,
						mdlImage_checkStop))
	{
		if (NULL != (subImageP =
		    	(byte*)malloc (mdlImage_memorySize (&destSize, IMAGEFORMAT_RGBSeperate))))
			{
				mdlImage_extractSubImage (subImageP, &destSize,
							rawImageP, &inSize,
							NULL, IMAGEFORMAT_RGBSeperate);

//#define	INGR_ORIENT_UpperLeftVertical		0
//#define INGR_ORIENT_UpperRightVertical		1
//#define INGR_ORIENT_LowerLeftVertical		2
//#define INGR_ORIENT_LowerRightVertical		3
//#define	INGR_ORIENT_UpperLeftHorizontal		4
//#define INGR_ORIENT_UpperRightHorizontal	5
//#define INGR_ORIENT_LowerLeftHorizontal		6
//#define INGR_ORIENT_LowerRightHorizontal	7

				mdlImage_convertToUpperLeftHorizontal (&subImageP, &destSize,
								INGR_ORIENT_UpperLeftHorizontal,
								IMAGEFORMAT_RGBSeperate,
								mdlImage_checkStop);

				mdlWindow_rgbDataDraw (wnd, &rectangle,
						destSize.x, subImageP,
						DITHERMODE_ErrorDiffusion,
						TRUECOLOR_Seperate, NULL);

				mdlImage_freeImage (subImageP, &destSize, IMAGEFORMAT_RGBSeperate);
			}
		mdlImage_freeImage (rawImageP, &inSize, IMAGEFORMAT_RGBSeperate);
	}

	writeLogOut(__FUNCTION__, 0);

}
*/
///////////////////////////////////////////////////////////
// do not use in callback of element update, mdlClip_* breaks current transfotm
int testVecInsideRefClip(DgnModelRefP mrP, DVec3d* pTest1P, DVec3d* pTest2P, int view)
{


	DVec3d p[2];
	MSElementDescr* edp = NULL;
	MSElementDescr* edpClip = NULL;
	BINT bInside = TRUE;
	BINT bOver = FALSE;
	CLIPDESC clipP = NULL;

	//int r = func_pma(mdlClip_getRefBoundary, clipP), mrP, view);
	int r = myClip_getRefBoundary(&clipP, mrP, &edpClip, view);

	if (r != SUCCESS || ISNULL(clipP)) return TRUE;

	//writeLogIn(__FUNCTION__, 0);

	p[0] = *pTest1P;

	if (pTest2P)
		p[1] = *pTest2P;
	else
		p[1] = *pTest1P;

	mdlLine_create(&elTest, NULL, p);

	mdlElmdscr_new(&edp, NULL, &elTest);

	if (edp)
	{
		bInside = mdlClip_isElemInside(&bOver, edp, GETPTR(clipP), view, TRUE);
	
		myClip_free(clipP, &edpClip);
		mdlElmdscr_freeAll(&edp);
	}


	//writeLogOut(__FUNCTION__, 0);

	return bInside;
}

int iNewSec = 0;

////////////////////////////////////////////////////////////////
int testActiveZPoint(ReinModel* rmodP, ReinSegm* sgmP, int view, VCNTXP context, DVec3d* pZZ, double an, double param, DVec3d* pViewNrm)
{

	writeLogIn(__FUNCTION__, 0);

	DPoint3d vbxpts[8];
	context->GetViewport()->GetViewBox(vbxpts, COORDSYS_Root, false);
	ViewFlagsCP vfP = context->GetViewport()->GetViewFlags();


	//double actZ;
	//mdlView_getParameters(0, 0, 0, 0, &actZ, view);


	DVec3d vpts[2];
	DVec3d spts[2];
	DVec3d prjpt[2];
	double prjfr[2];

	if (rmodP->iClipVerts > 0) // референс клип
	{
		vpts[0] = rmodP->arClipPts[0][0];
		vpts[1] = rmodP->arClipPts[1][0];
	}
	else
	{

		if (iNewSec)
		{
			vpts[0] = arViewPlanes[view].ptsFnt[0];
			vpts[1] = arViewPlanes[view].ptsBck[0];
		}
		else
		{
			if (vfP->noFrontClip && vfP->noBackClip)
			{
				mdlVec_interpolate(pZZ, &sgmP->rv[0].torg, param, &sgmP->rv[1].torg);
				if (iDebug) writeLogOut(__FUNCTION__, "if (cps->nPlanes != 6)");
				return TRUE;
			}
			else
			{
	#if defined (MSVERSION) && (MSVERSION == 0x8b0) // ClipPlaneSetCP
				ClipPlaneSetCP cps = context->GetRangePlanes();
				if (cps->nPlanes != 6) return TRUE;
				mdlVec_scaleToLength(&vpts[0], &cps->planes[4].normal, cps->planes[4].distance);
				mdlVec_scaleToLength(&vpts[1], &cps->planes[5].normal, cps->planes[5].distance);
	#else
				mdlVec_projectPointToPlane(&vpts[0], &pZero, &vbxpts[0], pViewNrm);
				mdlVec_projectPointToPlane(&vpts[1], &pZero, &vbxpts[4], pViewNrm);
	#endif
			}
		}


	}


	if (iNewSec)
	{

		mdlVec_subtract(&prjpt[0], &sgmP->rv[1].torg, &sgmP->rv[0].torg);

		if (sgmP->sgmrad)
		{

			DVec3d pnts[5];
			int res = SUCCESS;

			// пересекаем плосости дуги и вида
			res = mdlVec_planePlaneIntersect(&pnts[0], &pnts[1], &sgmP->sgmcent, &sgmP->sgmnorm, &arViewPlanes[view].ptsDpt[0], &arViewPlanes[view].normal);

			if (res == SUCCESS)
			{
				// строим элемент линии
				mdlVec_normalize2(&pnts[1]);
				mdlVec_scale(&pnts[2], &pnts[1], mdlCnv_masterUnitsToUors((double)sgmP->sgmrad) * 10.);
				mdlVec_negate(&pnts[3], &pnts[1]);
				mdlVec_scale(&pnts[3], &pnts[3], mdlCnv_masterUnitsToUors((double)sgmP->sgmrad) * 10.);
				mdlVec_addInPlace(&pnts[2], &pnts[0]);
				mdlVec_addInPlace(&pnts[3], &pnts[0]);
				res = mdlLine_create(&elAr[0], 0, &pnts[2]);

				MSElementDescr* ed1 = NULL;
				if (res == SUCCESS) mdlElmdscr_new(&ed1, 0, &elAr[0]);

				// строим элемент дуги
				pnts[0] = sgmP->rv[0].torg;
				pnts[1] = sgmP->sgmcent;
				pnts[2] = sgmP->rv[1].torg;
				res = mdlArc_createByCenter(&elAr[1], 0, pnts, 0, 0, view);

				MSElementDescr* ed2 = NULL;
				if (res == SUCCESS) mdlElmdscr_new(&ed2, 0, &elAr[1]);

				// пересекаем линию и дугу
				if (ed1 && ed2) res = mdlIntersect_allBetweenElms(0, pnts, 5, ed1, ed2, 0, 0);

				if (ed1) mdlElmdscr_freeAll(&ed1);
				if (ed2) mdlElmdscr_freeAll(&ed2);

				if (res == SUCCESS)
				{
					*pZZ = pnts[0];
				}
			}

		}
		else
		{
			mdlVec_linePlaneIntersectParameter(&spts[0], &prjfr[0], &sgmP->rv[0].torg, &prjpt[0], &arViewPlanes[view].ptsFnt[0], &arViewPlanes[view].normal);
			mdlVec_linePlaneIntersectParameter(&spts[1], &prjfr[1], &sgmP->rv[0].torg, &prjpt[0], &arViewPlanes[view].ptsBck[0], &arViewPlanes[view].normal);

			mdlVec_interpolate(pZZ, &spts[0], param, &spts[1]);
		}

	}
	else
	{
		if (mdlVec_projectPointToLine(&prjpt[0], &prjfr[0], &vpts[0], &sgmP->rv[0].torg, &sgmP->rv[1].torg) != SUCCESS) return TRUE;
		if (mdlVec_projectPointToLine(&prjpt[1], &prjfr[1], &vpts[1], &sgmP->rv[0].torg, &sgmP->rv[1].torg) != SUCCESS) return TRUE;

		// убрана корректировка prjfr так как иногда редко теряет отображение

		//if (EQ(prjfr[0], 0.) || EQ(prjfr[0], 1.) || (prjfr[0] > 0. && prjfr[0] < 1.0))
		spts[0] = prjpt[0];
		//else
		//{
		//	if EQ(an, fc_pi) spts[0] = sgmP->rv[1].torg; else  spts[0] = sgmP->rv[0].torg;
		//}


		//if (EQ(prjfr[1], 0.) || EQ(prjfr[1], 1.) || (prjfr[1] > 0. && prjfr[1] < 1.0))
		spts[1] = prjpt[1];
		//else
		//{
		//	if EQ(an, fc_pi) spts[1] = sgmP->rv[0].torg; else  spts[1] = sgmP->rv[1].torg;
		//}

		mdlVec_interpolate(pZZ, &spts[0], param, &spts[1]);

	}




	writeLogOut(__FUNCTION__, 0);

	return TRUE;
}


///////////////////////////////////////////////////////////
int testSegmentInView(DVec3d* pTestFrstP, DVec3d* pTestScndP, ViewportP viewPortP, Transform* tmP, DVec3d* pActDepP)
{

	DVec3d       origin;
	DVec3d       delta;
	RotMatrix rm;
	DVec3d test[2];
	double actZ;

	writeLogIn(__FUNCTION__, 0);

	test[0] = *pTestFrstP;
	test[1] = *pTestScndP;


	delta = *(DVec3d*)(viewPortP->GetViewDelta());
	origin = *(DVec3d*)(viewPortP->GetViewOrigin());
	actZ = viewPortP->GetActiveZRoot();
	rm = *(RotMatrix*)(viewPortP->GetRotMatrix());

	//mdlView_getParameters(&origin, NULL, &delta, &rm, &actZ, view);

	mdlRMatrix_multiplyPointArray(test, &rm, 2);
	mdlRMatrix_multiplyPoint(&origin, &rm);


	if (origin.x > test[0].x && origin.x > test[1].x) return FALSE;
	if (origin.x + delta.x < test[0].x && origin.x + delta.x < test[1].x) return FALSE;

	if (origin.y > test[0].y && origin.y > test[1].y) return FALSE;
	if (origin.y + delta.y < test[0].y && origin.y + delta.y < test[1].y) return FALSE;

	if (origin.z > test[0].z && origin.z > test[1].z) return FALSE;
	if (origin.z + delta.z < test[0].z && origin.z + delta.z < test[1].z) return FALSE;

	test[0].z = (test[0].z + test[1].z) / 2.;
	test[0].z = origin.z + actZ;

	mdlRMatrix_invert(&rm, &rm);

	mdlRMatrix_multiplyPoint(&test[0], &rm);

	*pActDepP = test[0];

	if (tmP)
	{
		mdlTMatrix_transformPoint(pActDepP, tmP);
	}

	if (iDebug) sprintf(sLogMes, "_testSegmentInView() - points are inside view %i\n", viewPortP->GetViewNumber()); writeLog(0, 0);

	writeLogOut(__FUNCTION__, 0);

	return TRUE;
}



///////////////////////////////////////////////////////////
int testIsPointInsideView2(DVec3d* pTestP, VCNTXP context, DVec3d* pViewNrm)
{
	int ret = FALSE;

	//writeLogIn(__FUNCTION__, 0); // testIsPointInsideView2

	DPoint3d vbxpts[8];
	context->GetViewport()->GetViewBox(vbxpts, COORDSYS_Root, false);

	ViewFlagsCP vfP = context->GetViewport()->GetViewFlags();


	if (vfP->noFrontClip && vfP->noBackClip)
	{
		if (iDebug) sprintf(sLogMes, "noFrontClip && noBackClip, returning TRUE\n"); writeLog(0, 0);
		//writeLogOut(__FUNCTION__, 0); // testIsPointInsideView2
		return TRUE;
	}


	DVec3d vpts[2];
	DVec3d prjpt;
	double prjfr;


#if defined (MSVERSION) && (MSVERSION == 0x8b0) // ClipPlaneSetCP
	ClipPlaneSetCP cps = context->GetRangePlanes();
	if (cps->nPlanes != 6) ret = TRUE;
	mdlVec_scaleToLength(&vpts[0], &cps->planes[4].normal, cps->planes[4].distance);
	mdlVec_scaleToLength(&vpts[1], &cps->planes[5].normal, cps->planes[5].distance);
#else
	mdlVec_projectPointToPlane(&vpts[0], &pZero, &vbxpts[0], pViewNrm);
	mdlVec_projectPointToPlane(&vpts[1], &pZero, &vbxpts[4], pViewNrm);
#endif

	if (mdlVec_projectPointToLine(&prjpt, &prjfr, pTestP, &vpts[0], &vpts[1]) != SUCCESS) ret = TRUE;

	if (EQ(prjfr, 0.) || EQ(prjfr, 1.) || (prjfr > 0. && prjfr < 1.0)) ret = TRUE;

	if (iDebug) sprintf(sLogMes, "testIsPointInsideView2() returning %i\n", ret); writeLog(0, 0);

	// writeLogOut(__FUNCTION__, 0); // testIsPointInsideView2

	return ret;

}



/////////////////////////////
void updateReinBarSegments(
					   ReinBar* rbP, // rbP->rpts[] должен быть готов для обработки
					   int iClip // обрезан клипом или нет
						,BarPoint* bpBendOneP
						,BarPoint* bpBendTwoP
					   )
{
	UInt32 refn = 0;


	if (rbP == NULL) return;

	rbP->numsgts = 0;

	if (rbP->numpts == 0) return;

	writeLogIn(__FUNCTION__, 0);
	if (iDebug) sprintf(sLogMes, "numpts = %i\n", rbP->numpts); writeLog(0, 0);


	int iRadSgmNum = 0;


	//if (rbP->pnum == 117)
	//	int a = 0;



	for (int i = 0; i < rbP->numpts - 1; i++)
	{

		//rbP->cents
		if (rbP->rfa[i + 1] & RFA_ARCP || rbP->rfa[i + 1] & RFA_CIRP)
		{

			RotMatrix rm1, rm2;
			DVec3d pCross;
			mdlVec_crossProduct3Points(&pCross, &rbP->rpts[i + 1], &rbP->rpts[i], &rbP->rpts[i + 2]);
			mdlVec_normalize2(&pCross);

			if (iClip == 0)
			{
				rbP->sgts[rbP->numsgts].rv[0].isin = !(i == 0);
				rbP->sgts[rbP->numsgts].rv[1].isin = !(i == (rbP->numpts - 3));
			}
			else //if (iClip != 0)
			{
				rbP->sgts[rbP->numsgts].rv[0].isin = !(rbP->rfa[i] & RFA_ENDP);
				rbP->sgts[rbP->numsgts].rv[1].isin = !(rbP->rfa[i + 2] & RFA_ENDP);
			}

			if (rbP->rfa[i + 1] & RFA_ARCP || rbP->rfa[i + 1] & RFA_CIRP)
			{
				//mdlVec_extractPolygonNormal(&pCross, &rbP->sgts[rbP->numsgts].sgmcent, &rbP->rpts[i], 3);

				rbP->sgts[rbP->numsgts].sgmrad = (long) mdlCnv_uorsToMasterUnits(roundex(CalcRad2(
																			&rbP->rpts[i], 
																			&pCross,
																			&rbP->sgts[rbP->numsgts].sgmcent // return sgmcent
																			)));

				rbP->sgts[rbP->numsgts].numpt = rbP->rpts[i + 1]; // точка посередине (а надо пересечение с видом!)

				rbP->sgts[rbP->numsgts].sgmnorm = pCross;

				//mdlLineString_create(&elTmp, NULL, &rbP->rpts[i], 3);
				//mdlElement_add(&elTmp);

			}
			//else // ??
			//{
			//	rbP->sgts[rbP->numsgts].sgmcent = rbP->rpts[i + 1];
			//	rbP->sgts[rbP->numsgts].sgmrad = (long)roundex(
			//						mdlCnv_uorsToMasterUnits(
			//								mdlVec_distance(
			//									&rbP->rpts[i + 1], 
			//									&rbP->rpts[i]
			//									)));
			//}

			//rbP->rad[0] = rbP->sgts[rbP->numsgts].sgmrad;
			//rbP->rad[1] = rbP->sgts[rbP->numsgts].sgmrad;
			iRadSgmNum++;

			rbP->sgts[rbP->numsgts].rv[0].torg = rbP->rpts[i];
			rbP->sgts[rbP->numsgts].rv[1].torg = rbP->rpts[i + 2];

			rbP->sgts[rbP->numsgts].rv[0].rvv.tdir = rbP->rpts[i];
			rbP->sgts[rbP->numsgts].rv[1].rvv.tdir = rbP->rpts[i + 2];

			mdlVec_subtractInPlace(&rbP->sgts[rbP->numsgts].rv[0].rvv.tdir, &rbP->sgts[rbP->numsgts].sgmcent);
			mdlVec_subtractInPlace(&rbP->sgts[rbP->numsgts].rv[1].rvv.tdir, &rbP->sgts[rbP->numsgts].sgmcent);

			mdlRMatrix_fromRotationAboutAxis(&rm1, &pCross, fc_piover2);
			mdlRMatrix_fromRotationAboutAxis(&rm2, &pCross, -fc_piover2);

			mdlVec_multiplyRotMatrixDVec3d(&rbP->sgts[rbP->numsgts].rv[0].rvv.tdir, &rm1, &rbP->sgts[rbP->numsgts].rv[0].rvv.tdir);
			mdlVec_multiplyRotMatrixDVec3d(&rbP->sgts[rbP->numsgts].rv[1].rvv.tdir, &rm2, &rbP->sgts[rbP->numsgts].rv[1].rvv.tdir);

			rbP->sgts[rbP->numsgts].rv[0].mpar = rbP->rfa[i];
			rbP->sgts[rbP->numsgts].rv[1].mpar = rbP->rfa[i + 2];

			rbP->sgts[rbP->numsgts].bOutOfClip = FALSE;

			if (
				((rbP->rfa[i] & RFA_RELP) && !(rbP->rfa[i] & RFA_TELP) 
				&& (rbP->rfa[i + 2] & RFA_RELP) && !(rbP->rfa[i + 2] & RFA_TELP))
				|| (rbP->rfa[i] & RFA_ENDC && !(rbP->rfa[i + 2] & RFA_TELP))
				|| (!(rbP->rfa[i] & RFA_TELP) && rbP->rfa[i + 2] & RFA_ENDC)
				)
			{
				if (iClip == 1) rbP->sgts[rbP->numsgts].bOutOfClip = TRUE;
			}

			i++;
		}
		else
		{
			if (iClip == 0)
			{
				rbP->sgts[rbP->numsgts].rv[0].isin = !(i == 0);
				rbP->sgts[rbP->numsgts].rv[1].isin = !(i == (rbP->numpts - 2));
			}
			else //if (iClip != 0)
			{
				rbP->sgts[rbP->numsgts].rv[0].isin = !(rbP->rfa[i] & RFA_ENDP);
				rbP->sgts[rbP->numsgts].rv[1].isin = !(rbP->rfa[i + 1] & RFA_ENDP);
			}

			rbP->sgts[rbP->numsgts].sgmrad = 0;

			rbP->sgts[rbP->numsgts].rv[0].torg = rbP->rpts[i];
			rbP->sgts[rbP->numsgts].rv[1].torg = rbP->rpts[i + 1];

			rbP->sgts[rbP->numsgts].rv[0].rvv.tdir = rbP->sgts[rbP->numsgts].rv[1].torg;
			mdlVec_subtractInPlace(&rbP->sgts[rbP->numsgts].rv[0].rvv.tdir, &rbP->sgts[rbP->numsgts].rv[0].torg);

			rbP->sgts[rbP->numsgts].rv[1].rvv.tdir = rbP->sgts[rbP->numsgts].rv[0].torg;
			mdlVec_subtractInPlace(&rbP->sgts[rbP->numsgts].rv[1].rvv.tdir, &rbP->sgts[rbP->numsgts].rv[1].torg);

			rbP->sgts[rbP->numsgts].rv[0].mpar = rbP->rfa[i];
			rbP->sgts[rbP->numsgts].rv[1].mpar = rbP->rfa[i + 1];

			rbP->sgts[rbP->numsgts].bOutOfClip = FALSE;

			if (
				((rbP->rfa[i] & RFA_RELP) && !(rbP->rfa[i] & RFA_TELP) 
				&& (rbP->rfa[i + 1] & RFA_RELP) && !(rbP->rfa[i + 1] & RFA_TELP))
				|| (rbP->rfa[i] & RFA_ENDC && !(rbP->rfa[i + 1] & RFA_TELP))
				|| (!(rbP->rfa[i] & RFA_TELP) && rbP->rfa[i + 1] & RFA_ENDC)
				)
			{
				if (iClip == 1) rbP->sgts[rbP->numsgts].bOutOfClip = TRUE;
			}
		}

		mdlVec_normalize2(&rbP->sgts[rbP->numsgts].rv[0].rvv.tdir);
		mdlVec_normalize2(&rbP->sgts[rbP->numsgts].rv[1].rvv.tdir);


		rbP->numsgts++;

		if (rbP->numsgts == MAX_BAR_VERTICES)
		{
			_swprintf(wss, L"elem axis id = %I64u id = %I64u has maximum number of segments", rbP->axid, rbP->elemid);
			mdlOutput_messageCenterW(MESSAGE_ERROR, wss, wss, MESSAGE_ALERT_NONE);
			break;
		}


	}


	//if (iRadSgmNum > 1) rbP->rad[0] = 0;
	//if (iRadSgmNum > 1) rbP->rad[1] = 0;

	// крестики/нолики для загибов
	for (int i = 0; i < rbP->numsgts && rbP->numsgts > 1; i++)
	{
		DVec3d nrm, vec;

		rbP->sgts[i].rv[0].mdiam[0] = 0;
		rbP->sgts[i].rv[1].mdiam[0] = 0;

		if (i == 0 && rbP->term[0] == REIN_TERM_BEND)
		{
			double vecang = mdlVec_angleBetweenVectors(&rbP->sgts[0].rv[0].rvv.tdir, 
												&rbP->sgts[1].rv[0].rvv.tdir);


			if (mdlVec_areParallel(&rbP->sgts[0].rv[0].rvv.tdir, &rbP->sgts[1].rv[0].rvv.tdir))
			{
				nrm = rbP->v_enrm;
			}
			else
			{
				mdlVec_crossProduct(&nrm, &rbP->sgts[0].rv[0].rvv.tdir, 
													&rbP->sgts[1].rv[0].rvv.tdir);
			}


			mdlVec_crossProduct(&vec, &nrm, &rbP->sgts[0].rv[0].rvv.tdir);

			rbP->sgts[i].rv[0].rvv.tnorm = vec;
			rbP->sgts[i].rv[0].mdiam[0] = REIN_TERM_BEND;

		}
		
		if (i == rbP->numsgts - 1 && rbP->term[1] == REIN_TERM_BEND)
		{
			double vecang = mdlVec_angleBetweenVectors(&rbP->sgts[rbP->numsgts-1].rv[1].rvv.tdir, 
												&rbP->sgts[rbP->numsgts-2].rv[1].rvv.tdir);


			if (mdlVec_areParallel(&rbP->sgts[rbP->numsgts-1].rv[1].rvv.tdir, &rbP->sgts[rbP->numsgts-2].rv[1].rvv.tdir))
			{
				nrm = rbP->v_enrm;
			}
			else
			{
				mdlVec_crossProduct(&nrm, &rbP->sgts[rbP->numsgts-1].rv[1].rvv.tdir, 
													&rbP->sgts[rbP->numsgts-2].rv[1].rvv.tdir);
			}


			mdlVec_crossProduct(&vec, &nrm, &rbP->sgts[rbP->numsgts-1].rv[1].rvv.tdir);

			rbP->sgts[i].rv[1].rvv.tnorm = vec;
			rbP->sgts[i].rv[1].mdiam[0] = REIN_TERM_BEND;
			
		}
		
	}




	for (int i = 0; i < rbP->numsgts; i++)
	{
		if (rbP->sgts[i].rv[0].isin) setReinVertNorm(rbP, &rbP->sgts[i].rv[0], &rbP->sgts[i - 1].rv[1]);
		if (rbP->sgts[i].rv[1].isin) setReinVertNorm(rbP, &rbP->sgts[i].rv[1], &rbP->sgts[i + 1].rv[0]);
	}
	

	if (iDebug) sprintf(sLogMes, "numpts = %i\n", rbP->numpts); writeLog(0, 0);
	writeLogOut(__FUNCTION__, 0);

}

/////////////////////////////////
int iterateLoadReinSpaces(
	MSElementDescr* edP,
	void* prm,
	ScanCriteria* pScanCriteria
)
{

	//DgnCacheP dfP = Bentley::Ustn::ISessionMgr::GetActiveDgnCache();
	//MSDgnFileP fileP = dfP->GetMSDgnFile();
	//wstring dsname = L"Wireframe";

	//int ind = Bentley::Ustn::DisplayStyleManager::GetIndexForDisplayStyle(*dsname.c_str(), fileP);

	//mdlElement_setDisplayStyle(&edP->el, ind);

	mdlElmdscr_rewrite(edP, 0, mdlElmdscr_getFilePos(edP));


	return SUCCESS;
}


/////////////////////////////////
int iterateLoadReinBars(
	MSElementDescr* edP,
	void* prm,
	ScanCriteria* pScanCriteria
)
{
	ReinBar rb;
	if (readReinBarFromElement(&rb, edP, 0) != SUCCESS) return 0;

	if (rb.bartype == BT_AXIS) return 0; // only for contours

	WCH* sVarName = L("REIN_DISPLAY_LINCONT_ARROWS");
	WCH  sVarValue[10];

	if (getCfgVar(sVarValue, sVarName) == SUCCESS)
	//if (mdlSystem_getCfgVar(sVarValue, sVarName, 10) == SUCCESS)
	{
		if (STOI(sVarValue) == 0)
			return 1; // end scan
	}
	else
		return 1; // end scan

	// create transients
	//========================================================

	MSElementDescr* edpB = edP;
	DVec3d pdst[2];
	DVec3d ptmp[3];

	UInt32 fp = mdlElmdscr_getFilePos(edpB);

	double dspace = mdlCnv_masterUnitsToUors(rb.offset[0]);
	ReinModel* rmP = curRM->getRM(edP->h.dgnModelRef);

	int res = mdlElmdscr_pointAtDistance(&pdst[0], &pdst[1], dspace, edpB, 0);

	while (rmP && res == SUCCESS)
	{
		double dgap = mdlCnv_masterUnitsToUors(dCfgVar_BarFace);// *(mdlCnv_masterUnitsToUors(50000.) / pdst[0].z);


		mdlVec_scaleInPlace(&pdst[1], dgap);
		mdlVec_add(&pdst[1], &pdst[0], &pdst[1]);
		mdlCone_create(&elTmp, &c0w0s0, 0, dgap/4., &pdst[0], &pdst[1], 0);

		UInt32 levelID = LEVEL_NULL_ID;
		mdlElmdscr_getProperties(&levelID, 0, 0, 0, 0, 0, 0, 0, edP);


		MSElementDescr* edpA = NULL;

		mdlElmdscr_new(&edpA, 0, &elTmp);

		func_amp(mdlElmdscr_setProperties, edpA), & levelID, 0, 0, 0, 0, 0, 0, 0);


		MSWCH str[100];
		_swprintf(str, L"@@@@@%u", fp);

		erelm.clear();
		xmlAddCacheInfo(&erelm, &edpA, str, false, rmP);

		//ReinInfoRef* rirP = rmP->getRefPrefs();
		//if (rirP && rirP->lim) // не фурычит т.к. не синхронизировано
		rmP->mapTedCntP[fp] = mdlTransient_addElemDescr(rmP->mapTedCntP[fp], edpA, FALSE, 0x00ff, DRAW_MODE_Normal, 1, 0, 0);

		dspace += mdlCnv_masterUnitsToUors(rb.spacef);

		res = mdlElmdscr_pointAtDistance(&pdst[0], &pdst[1], dspace, edpB, 0);
	}
	//========================================================

	return SUCCESS;
}

/////////////////////////////////
int iterateLoadReinElms(
MSElementDescr  *edP,
CatInfo*            ciP,
ScanCriteria    *pScanCriteria
)
{

	//ClipDescrP clipP = NULL;
	int view = 0;
	//MSElementDescr* edpAx = NULL;

	writeLogIn(__FUNCTION__, 0);

	urelm.clear();

	ReinModel* rmP = curRM->getRM(edP->h.dgnModelRef);

	UInt32 elemCountLoc = rmP->elcount;

	//FILE* fff = fopen("d:/__act.txt", "a");
	//if (fff)
	//{
	//	fprintf(fff, "%I64u\n", mdlElement_getID(&edP->el));
	//	fclose(fff);
	//}

	//Element ID: 138072
	//if (mdlElement_getID(&edP->el) == 138325)
	//	int a = 0;

	int t = mdlElement_getType(&edP->el);

	int ret = readReinElmIso(&urelm, edP, TRUE, TRUE);

	if (ret != SUCCESS && t == BSPLINE_CURVE_ELM) // для результата развертки
	{
		ret = readReinElmIso(&urelm, edP, FALSE, FALSE);
	}


	if (ret == SUCCESS)
	{
		if (iDebug) sprintf(sLogMes, "readReinElmIso() SUCCESS, type = %i, iClip = %i\n", urelm.type, urelm.iClip); writeLog(0, 0, 0, 1);


		if (urelm.iClip != -1) // если элемент не за гранью
		{
			if (elemCount)
			{
				elemIterCount++;
				elemIterCount2++;
				tbi.percentComplete1 = (long)(((double)elemIterCount / (double)elemCount) * 100.);
				tbi.percentComplete2 = (long)(((double)elemIterCount2 / (double)elemCountLoc) * 100.);
				//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
				if (dlgProgressP)
				{
					mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)tbi.percentComplete1);
					WaitMessage();
				}
			}

			if (iDebug) sprintf(sLogMes, "elemIterCount = %u\n", elemIterCount); writeLog(0, 0);

			//if (urelm.type == REIN_ELEM_ISO)
			if (isLevelDisplayed(edP, mdlScanCriteria_getModel(pScanCriteria), &urelm))
				insertCurBarsMember2(&urelm, edP, 0, ciP, elemIterCount - 1); // func insert CurBars Member2 call
		}

	}


	writeLogOut(__FUNCTION__, 0);


	return 0;


}


//////////////////////////////////////////////////////
int scanCheckIsModel(
MSElementDescr  *edP,
int            *bDelete,
ScanCriteria    *pScanCriteria
)
{
	int res;

	writeLogIn(__FUNCTION__, 0);

	if (*bDelete == TRUE)
	{
		res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos (edP->h.elementRef), FALSE);
	}
	else
	{
		ReinPrm prm;

		if (getModelInfo(edP, &prm) == SUCCESS)
		{
			iModelVersInFile = prm.ival[0];
			iNewRefNum = prm.ival[1];
			iModelType = prm.ival[2];

			if (iDebug) sprintf(sLogMes, "success: modvers %i refnum %i modtype %i\n", iModelVersInFile, iNewRefNum, iModelType); writeLog(0, 0);
		}
		else
		{
			iModelType = MODTYPE_COMMON;
			if (iDebug) sprintf(sLogMes, "not found: modvers %i refnum %i modtype %i\n", iModelVersInFile, iNewRefNum, iModelType); writeLog(0, 0);
		}

		/*
		XMLFragmentListP  oXMLFragmentList = NULL;

		//MSWCH seps[]   = L";";
		//MSWCH *token;

		oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

		if (oXMLFragmentList)
		{
			XMLFragmentP        pXMLFragment;
			MSWCH* wtxt;
			//MSWCH ctxt[50];
			pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

			// if (pXMLFragment && 
			// mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
			{
				wstring wstr(wtxt);

				mdlXMLFragmentList_free(&oXMLFragmentList);

				vector<wstring> setstr;
				setstr.reserve(5);

				if (readFromString(__FUNCTION__, &setstr, wstr) == SUCCESS)
				{
					vector<wstring>::iterator it = setstr.begin();
					IF_IT
						iModelVersInFile = _wtoi(it->c_str());

					IF_IT_nxt
					IF_IT
						iNewRefNum = _wtoi(it->c_str());
					else 
						iNewRefNum = FALSE;

					IF_IT_nxt
					IF_IT
						iModelType = _wtoi(it->c_str());
					else
						iModelType = MODTYPE_COMMON;
				}

				//token = wcstok( ctxt, seps );
				//if (token != NULL )	iModelVersInFile = _wtoi(token);

				//token = wcstok( NULL, seps );
				//if (token != NULL )	iNewRefNum = _wtoi(token); else iNewRefNum = FALSE;

				//token = wcstok( NULL, seps );
				//if (token != NULL )	iModelType = _wtoi(token); else iModelType = MODTYPE_COMMON;

				
			}

		}
		*/
	}

	writeLogOut(__FUNCTION__, 0);

    return SUCCESS;
}

//////////////////////////////////////////////////////
int scanDeleteHidePos(
MSElementDescr  *edP,
ReinPos            *rpP,
ScanCriteria    *pScanCriteria
)
{
	int res;

	long nump = 0;
	long numr = 0;
	wstring numstr;
	//long numrr = 0;


	XMLFragmentListP  oXMLFragmentList = NULL;

	UInt32 fp = mdlElmdscr_getFilePos(edP);

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		//MSWCH ctxt[1500];
		//MSWCH seps[]   = L"|";
		//MSWCH *token;

		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);

			setstr.clear();

			if (readFromString(__FUNCTION__, &setstr, wstr,
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//				L'|'
//#else
				L"|"
//#endif
			) == SUCCESS)
			{
				SETSTR_BEGIN_ITER;
				IF_IT nump = _wtol(it->c_str()); // pos num

				IF_IT_nxt
				IF_IT numr = _wtol(it->c_str()); // ref num

				IF_IT_nxt
				IF_IT numstr = *it; // ref path

				if (numr < 0) numr = 0;
			}


			/*
			wcsncpy(ctxt, wtxt, 1500);

			token = wcstok( ctxt, seps );
			if (token != NULL)	nump = _wtol(token);

			token = wcstok( NULL, seps );
			if (token != NULL)	numr = _wtol(token);
			if (numr < 0) numr = 0;

			*/

			//token = wcstok( NULL, seps );
			//if (token != NULL)	numrr = _wtol(token);
			//if (numrr < 0) numrr = 0;

			mdlXMLFragmentList_free(&oXMLFragmentList);

		}


	}
	else // MDLERR_LINKAGENOTFOUND
		return ERROR;


	if (nump == 0) return ERROR;

	//string s = "MyString";
	//size_t h1 = std::hash<string>{}(s); // only c11


	//if (*bAll)
	//{
	//	if (curPos_rn == numr) // curPos_rnn...
	//		res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos (edP->h.elementRef), FALSE);
	//}
	//else
	//{
		if (curPos_refpath == numstr && rpP->bar.pnum == nump)
			res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos (edP->h.elementRef), FALSE);
	//}


    return SUCCESS;
}



//////////////////////////////////////////////////////
int scanDeleteBarSet(
MSElementDescr  *edP,
ReinPrm            *prmP,
ScanCriteria    *pScanCriteria
)
{
	int res;

	long set = 0;
	long inum = 0;
	UInt32 ref = 0;
	//vector <UInt32> aref; => prm.uival[]
	//UInt32 aref[MAX_REFNUM_PATH];
	//ZeroMemory(aref, sizeof(aref));
	UInt32 refcnt = 0;
	ELID eid = 0;

	ReinPrm prm;

	if (getBarSetInfo(edP, &prm) == SUCCESS)
	{
		set = prm.lval[0];
		inum = prm.lval[1];
		ref = prm.cnt[0];
		refcnt = prm.cnt[1];
		eid = prm.prmid;
	}

	/*
	wstring str = L"";

	XMLFragmentListP  oXMLFragmentList = NULL;

	UInt32 fp = mdlElmdscr_getFilePos(edP);

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		MSWCH ctxt[1500];
		MSWCH seps[]   = L"|";
		MSWCH *token;
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		//if (pXMLFragment && 
		//	mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wcsncpy(ctxt, wtxt, 1500);
			str = wtxt;

			token = wcstok( ctxt, seps );
			if (token != NULL)	set = _wtol(token);

			token = wcstok( NULL, seps );
			if (token != NULL)	inum = _wtol(token);

			token = wcstok( NULL, seps );
			if (token != NULL)	ref = _wtol(token);

			token = wcstok( NULL, seps );
			if (token != NULL)
			{
				if (swscanf(token, L"%I64u", &eid) != 1) return ERROR;

				// VERSION 2
				token = wcstok( NULL, seps );

				//while(token && aref.size() < 100)
				//{
				//	if (token != NULL)	
				//	{
				//		UInt32 v = wcstoul(token,0,0);
				//		//aref.push_back(v);
				//		aref.insert(aref.begin(), v); // вставляем в начало -- для совместимости, так как традиционно родители были справа, и сохраняются тоже в таком порядке
				//	}
				//	token = wcstok( NULL, seps );
				//}

				while (token && refcnt < MAX_REFNUM_PATH)
				{
					if (token != NULL)
					{
						aref[refcnt] = wcstoul(token, 0, 0);
						refcnt++;
					}
					token = wcstok(NULL, seps);
				}

			}

			mdlXMLFragmentList_free(&oXMLFragmentList);

		}
		else
			return ERROR;

	}
	else // MDLERR_LINKAGENOTFOUND
		return ERROR;

*/

	if (prmP->ival[0])
	{
		res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos (edP->h.elementRef), FALSE);
		if (res == SUCCESS) elemIterCount2++;
	}
	//else if (refcnt == 0) // for VERSION 1
	//{
	//	if (curPos.arefnum[0] == ref && // not curPos_rn...
	//		curPos.bar.inum == inum && curPos.bar.elemid == eid)
	//	{
	//		res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos (edP->h.elementRef), FALSE);
	//		if (res == SUCCESS) elemIterCount2++;
	//	}
	//}
	else
	{
		if (prmP->rpP &&
			refPathsEQ(prmP->rpP->arefnum, prm.uints) &&
			prmP->rpP->bar.inum == inum &&
			prmP->rpP->bar.elemid == eid)
		{
			res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos (edP->h.elementRef), FALSE);
			if (res == SUCCESS)
			{
				elemIterCount2++;

				if (prmP->ival[1]) // delete from map
				{
					wstring str = prmP->rpP->getMapIdentString();

					map <wstring, ReinPos>::iterator it = curRM->mapBarSet.find(str);
					if (it != curRM->mapBarSet.end()) // found
					{
						curRM->mapBarSet.erase(it);
						/*
						// todo relmP->drwopt[0]
						for (map<UInt32, ReinElm>::iterator it = rmP->mapElms.begin(); it != rmP->mapElms.end(); ++it)
						{
							if (inum == it->second.bel.inum && eid == it->second.bel.elemid)
							{
								it->second.drwopt[0] = set + BARSET_GAP;
							}
						}
						*/
					}
				}
			}
		}
	}


    return SUCCESS;
}

//////////////////////////////////////////////////////////
int refPathsEQ(UInt32* a1, UInt32* a2)
{

	for (int i = 0; i < MAX_REFNUM_PATH; i++)
	{
		if (a1[i] == 0 && a2[i] == 0) break;

		if (a1[i] != a2[i]) return FALSE;

	}
	return TRUE;

}

//////////////////////////////////
int refPathsEQ(deque <UInt32> &a1, deque <UInt32> &a2)
{

	if (a1.empty() && a2.empty()) return TRUE;
	if (a1.empty() && a2.size() == 1 && a2.back() == 0) return TRUE; // обратный массив
	if (a2.empty() && a1.size() == 1 && a1.back() == 0) return TRUE;

	if (a1.size() != a2.size()) return FALSE;

	deque<UInt32>::iterator it1 = a1.begin();
	deque<UInt32>::iterator it2 = a2.begin();

	while (it1 != a1.end() && it2 != a2.end())
	//for (int i = 0; i < a1.size(); i++)
	{
		if (*it1 != *it2) return FALSE;

		++it1;
		++it2;
	}
	return TRUE;
}


//////////////////////////////////////////////////////
int scanJustDeleteElement(
MSElementDescr  *edP,
void            *args,
ScanCriteria    *pScanCriteria
)
{
	int res;

	res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos (edP->h.elementRef), FALSE);

    return SUCCESS;
}


//////////////////////////////////////////////////
int readCatInfoFromString(CatInfo* ciP, wstring str)
{
	if (ciP == NULL) return ERROR;

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str,
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//		L'|'
//#else
		L"|"
//#endif
	) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	IF_IT_end return ERROR;
	SCPW2M(ciP->dbase, it->c_str(), 50);

	IF_IT_nxt IF_IT_end return ERROR;
	ciP->projID = wcstoul(it->c_str(),0,0);

	IF_IT_nxt IF_IT_end return ERROR;
	ciP->catID = wcstoul(it->c_str(),0,0);

	IF_IT_nxt IF_IT_end return ERROR;
	SCPW2M(ciP->catname, it->c_str(), 200);

	IF_IT_nxt IF_IT_end return ERROR;
	SCPW2M(ciP->catfullname, it->c_str(), 1000);

	IF_IT_nxt IF_IT_end return SUCCESS;
	ciP->bAutoCats = (wcstoul(it->c_str(),0,0) != 0);

	return SUCCESS;

}

//////////////////////////////////////////////////////
int scanCheckCatInfo(
MSElementDescr  *edP,
CatInfo*         ciP,
ScanCriteria    *pScanCriteria
)
{

	//int ret = SUCCESS;

	writeLogIn(__FUNCTION__, 0);



	XMLFragmentListP  oXMLFragmentList = NULL;

	UInt32 fp = mdlElmdscr_getFilePos(edP);


	//res = mdlXMLFragmentList_extractFromElement (&oXMLFragmentList, &edP->el );

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	//if (res == SUCCESS)
	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		//WCH ctxt[1500];
		//WCH seps[]   = L("|");
		//WCH *token;

		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);
			mdlXMLFragmentList_free(&oXMLFragmentList);

			if (readCatInfoFromString(ciP, wstr) != SUCCESS)
			{
				writeLogOut(__FUNCTION__, 0);
				return ERROR;
			}

			//token = STOK( ctxt, seps );
			//if (token != NULL)	SCPY(ciP->dbase, token);

			//token = STOK( NULL, seps );
			//if (token != NULL)	ciP->projID = STOL(token);

			//token = STOK( NULL, seps );
			//if (token != NULL)	ciP->catID = STOL(token);

			//token = STOK( NULL, seps );
			//if (token != NULL)	SCPY(ciP->catname, token);

			//token = STOK( NULL, seps );
			//if (token != NULL)	SCPY(ciP->catfullname, token);

			//token = STOK( NULL, seps );
			//if (token != NULL)	ciP->bAutoCats = (STOL(token) != 0);
		}
		else
		{
			writeLogOut(__FUNCTION__, 0);
			return ERROR;
		}

	}
	else // MDLERR_LINKAGENOTFOUND
	{
		writeLogOut(__FUNCTION__, 0);
		return ERROR;
	}



	writeLogOut(__FUNCTION__, 0);

    return SUCCESS;
}




//////////////////////////////////////////////////////
int scanCheckReinLevelElement(
	MSElementDescr* edP,
	int* bDelete,
	ScanCriteria* pScanCriteria
)
{
	int res;

	if (*bDelete == TRUE)
	{
		res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos(edP->h.elementRef), FALSE);
	}
	else
	{
	}

	return SUCCESS;
}


/////////////////////////////////////////////////////
void getLevelsString(ReinModel& rm, wstring* wstrP, set<wstring>* setlevP)
{

	set<wstring> setlev;


	for (map<UInt32, ReinElm>::iterator it = rm.mapElms.begin(); it != rm.mapElms.end(); ++it)
	{

		wstring wsLevName = it->second.getReinElmLevName(false);

		if (wsLevName.length() > 0)
		{
			if (setlevP == NULL) 
				setlev.insert(wsLevName);
			else
				setlevP->insert(wsLevName);
		}

	}

	for (map<UInt32, ReinModel>::iterator itt = rm.arMrP.begin(); itt != rm.arMrP.end(); ++itt)
	{

		if (setlevP == NULL)
			getLevelsString(itt->second, wstrP, &setlev);
		else
			getLevelsString(itt->second, wstrP, setlevP);

	}

	if (setlevP == NULL)
	{
		for (set<wstring>::iterator it = setlev.begin(); it != setlev.end(); ++it)
		{

			if ((*wstrP).length() > 0) (*wstrP).append(L"|");

			(*wstrP).append(*it);

		}
	}


}


//////////////////////////////////////////////////////
int scanGetModelLevels(
	MSElementDescr* edP,
	wstring* wstrP,
	ScanCriteria* pScanCriteria
)
{

	XMLFragmentListP  oXMLFragmentList = NULL;

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);

			mdlXMLFragmentList_free(&oXMLFragmentList);

			*wstrP = wstr;

		}
		else
			return ERROR;
	}
	else
		return ERROR;


	return SUCCESS;
}


//////////////////////////
wstring getReinModelLevelsString(DgnModelRefP mrP)
{

	wstring ret = L"";

	ScanCriteria* pScanCriteria;
	int status;

	pScanCriteria = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(pScanCriteria, (PFScanElemDscrCallback)scanGetModelLevels, &ret);
	status = mdlScanCriteria_setModel(pScanCriteria, mrP);
	mdlXML_addXMLFragmentElementScanTest(pScanCriteria, &appID, &appTypeReinLevels);
	status = mdlScanCriteria_scan(pScanCriteria, NULL, NULL, NULL);
	status = mdlScanCriteria_free(pScanCriteria);

	return ret;
}


///////////////////////////////////////////////////////////////////////////////////
void saveModelLevels(DgnModelRefP mrP)
{

	ScanCriteria* pScanCriteria;
	MSElementDescr* pXmlFragmentElement = NULL;
	XMLFragmentListP pCurrent = NULL;

	int status;

	int bDelete = TRUE;
	ReinPrm prm;


	wstring wstr = L"";

	// add level names including references
	// iterate ReinElms
	getLevelsString(curRMod, &wstr, NULL);


	// delete all prev. xml elements
	pScanCriteria = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(pScanCriteria, (PFScanElemDscrCallback)scanCheckReinLevelElement, &bDelete);
	status = mdlScanCriteria_setModel(pScanCriteria, mrP);
	mdlXML_addXMLFragmentElementScanTest(pScanCriteria, &appID, &appTypeReinLevels);
	status = mdlScanCriteria_scan(pScanCriteria, NULL, NULL, NULL);
	status = mdlScanCriteria_free(pScanCriteria);



	if (wstr.length() > 0)
	{
		MSWCH* wstrarr = new MSWCH[wstr.length() + 100];

		// attention
		memset(wstrarr, 0, sizeof(MSWCH) * (wstr.length() + 100));

		wcscpy(wstrarr, wstr.c_str());

		pCurrent = mdlXMLFragmentList_construct(wstrarr, NULL, appID, appTypeReinLevels);

		// create new one
		status = mdlXMLFragmentList_createXMLElementDescriptor(&pXmlFragmentElement, &pCurrent, FALSE);

		if (NULL != pXmlFragmentElement)
		{
			UInt32 fp;

			if (iDebug) sprintf(sLogMes, "     add xml fragment to file...\n"); writeLog(0, 0);

			fp = mdlElmdscr_addByModelRef(pXmlFragmentElement, mrP);
			mdlElmdscr_freeAll(&pXmlFragmentElement);

			mdlXMLFragmentList_free(&pCurrent);
		}

		delete[] wstrarr;
	}


}


///////////////////////////////////////////////////////////////////////////////////
void saveThisFileIsModel(DgnModelRefP mrInP, int iModType, bool bSyncToolBox)
{
	ScanCriteria    *pScanCriteria;
	MSElementDescr* pXmlFragmentElement = NULL; 
	int status;
	XMLFragmentListP pCurrent = NULL; 
	int bDelete = TRUE;
	MSWCH wstr[50];
	//char str[20];

	int iMT = iModType;
	if (iMT < 0) iMT = iModelType;

	DgnModelRefP mrP = mrInP;
	if (mrP == NULL) mrP = ACTIVEMODEL;


	// ======= STRING TO SAVE =======================
	_swprintf(wstr, L"%i;%i;%i", iModelVers, iNewRefNum, iMT);
	// ==============================================

	//mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 20);

	writeLogIn(__FUNCTION__, 0);

	// delete all prev. xml elements
	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckIsModel, &bDelete);
	status = mdlScanCriteria_setModel (pScanCriteria, mrP);
	mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeIsModel);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	//if (iModelType == 0) return;

	//====================================================

	pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeIsModel); 

	// create new one
	status = mdlXMLFragmentList_createXMLElementDescriptor  (&pXmlFragmentElement, &pCurrent, FALSE); 

	if (NULL != pXmlFragmentElement) 
	{ 
		UInt32 fp;

		if (iDebug) sprintf(sLogMes, "     add xml fragment to file...\n"); writeLog(0, 0);

		fp = mdlElmdscr_addByModelRef (pXmlFragmentElement, mrP); 
		mdlElmdscr_freeAll (&pXmlFragmentElement); 

		mdlXMLFragmentList_free(&pCurrent);
	} 

	if (bSyncToolBox) toolBoxComboSync();

	writeLogOut(__FUNCTION__, 0);

}

//////////////////////////////////////////////////////
int scanGetModelType(
	MSElementDescr* edP,
	int* iModTypeP,
	ScanCriteria* pScanCriteria
)
{
	ReinPrm prm;

	if (iModTypeP == NULL) return ERROR;

	if (getModelInfo(edP, &prm) == SUCCESS)
	{
		*iModTypeP = prm.ival[2];
	}
	else
		*iModTypeP = -1;

	/*
	int res;

	int iMType = -1;
	int iNRNum = 0;
	int iModVers = 0;
	XMLFragmentListP  oXMLFragmentList = NULL;

	MSWCH seps[] = L";";
	MSWCH* token;

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		MSWCH ctxt[50];
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);
		// mdlXMLFragment_getText(&wtxt, pXMLFragment);
		wcsncpy(ctxt, wtxt, 50);
		mdlXMLFragmentList_free(&oXMLFragmentList);

		token = wcstok(ctxt, seps);
		if (token != NULL)	iModVers = _wtoi(token);

		token = wcstok(NULL, seps);
		if (token != NULL)	iNRNum = _wtoi(token); else iNRNum = FALSE;

		token = wcstok(NULL, seps);
		if (token != NULL)	*iModTypeP = _wtoi(token); else *iModTypeP = -1;

	}
	*/

	return SUCCESS;
}



//////////////////////////
int getReinModelType(DgnModelRefP mrP)
{
	int iMT = -1;

	ScanCriteria* pScanCriteria;
	int status;

	pScanCriteria = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(pScanCriteria, (PFScanElemDscrCallback)scanGetModelType, &iMT);
	status = mdlScanCriteria_setModel(pScanCriteria, mrP);
	mdlXML_addXMLFragmentElementScanTest(pScanCriteria, &appID, &appTypeIsModel);
	status = mdlScanCriteria_scan(pScanCriteria, NULL, NULL, NULL);
	status = mdlScanCriteria_free(pScanCriteria);

	return iMT;
}

///////////////////////////////////////////////////////////////////////////////////
void checkThisFileIsModel(DgnModelRefP mrP)
{
	ScanCriteria    *pScanCriteria;
	int bDelete = FALSE;
	int status;

	iModelType = MODTYPE_COMMON;

	writeLogIn(__FUNCTION__, 0);

	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckIsModel, &bDelete);
	status = mdlScanCriteria_setModel (pScanCriteria, mrP);
	mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeIsModel);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	toolBoxComboSync();

	writeLogOut(__FUNCTION__, 0);

	

}

WCH sNote1[100];
WCH sNote2[100];

void ZeroWCH(WCH* ch, int cnt)
{
	for (int i = 0; ch && i < cnt; i++)
	{
		ch[i] = 0;
	}
}

////////////////////////////////////////////////////
void setReinNoteFromFmt(WCH* note, WCH* fmt)
{
	WCH n1[] = L("N1");	// pos number
	WCH n2[] = L("N2");
	WCH q1[] = L("Q1"); // quantity
	WCH q2[] = L("Q2");
	WCH sp1[] = L("S1"); // space
	WCH sp2[] = L("S2");
	WCH sk[] = L("[");
	WCH skk[] = L("]");

	WCH* s1 = NULL;
	WCH* s2 = NULL;
	WCH s3[100];
	WCH* s4 = NULL;

	int num1 = 0;
	int num2 = 0;
	int qty1 = 0;
	int qty2 = 0;
	int spc1 = 0;
	int spc2 = 0;

	SCPY(note, fmt);

	//num1 = reNoteP[0]->bel.pnum;
	//num2 = num1;
	//if (reNoteP[1]) num2 = reNoteP[1]->bel.pnum;

	map<long, ReinPos>::iterator it;
	if (curNote.mapNotePos.size() > 0)
	{
		it = curNote.mapNotePos.begin();

		qty1 = it->second.file_qty_p;
		qty2 = qty1;

		num1 = it->first;
		num2 = num1;

		spc1 = it->second.muft_qty[0];
		if (it->second.muft_qty[1] > 0)
			spc2 = it->second.muft_qty[1];
		else
			spc2 = spc1;
	}

	if (curNote.mapNotePos.size() > 1)
	{
		it++;
		qty2 = it->second.file_qty_p;
		num2 = it->first;
	}


	s1 = SSTR(note, n1);
	if (s1 != NULL)
	{
		s2 = s1;
		s2 += SLEN(n1);
		ZeroWCH(s3, 100);	SCPY(s3, s2);
		SPRN(s1, L("%i"), num1);
		SCAT(s1, s3);
	}

	s1 = SSTR(note, n2);
	if (s1 != NULL)
	{
		s2 = s1;
		s2 += SLEN(n2);
		ZeroWCH(s3, 100);	SCPY(s3, s2);
		SPRN(s1, L("%i"), num2);
		SCAT(s1, s3);
	}

	s1 = SSTR(note, q1);
	if (s1 != NULL)
	{
		s2 = s1;
		s2 += SLEN(q1);
		ZeroWCH(s3, 100);	SCPY(s3, s2);
		SPRN(s1, L("%i"), qty1);
		SCAT(s1, s3);
	}

	s1 = SSTR(note, q2);
	if (s1 != NULL)
	{
		s2 = s1;
		s2 += SLEN(q2);
		ZeroWCH(s3, 100);	SCPY(s3, s2);
		SPRN(s1, L("%i"), qty2);
		SCAT(s1, s3);
	}

	s1 = SSTR(note, sp1);
	if (s1 != NULL)
	{
		s2 = s1;
		s2 += SLEN(sp1);
		ZeroWCH(s3, 100);	SCPY(s3, s2);
		SPRN(s1, L("%i"), spc1);
		SCAT(s1, s3);
	}

	s1 = SSTR(note, sp2);
	if (s1 != NULL)
	{
		s2 = s1;
		s2 += SLEN(sp2);
		ZeroWCH(s3, 100);	SCPY(s3, s2);
		SPRN(s1, L("%i"), spc2);
		SCAT(s1, s3);
	}

	// квадратные скобки
	s1 = SSTR(note, sk);
	if (s1 != NULL)
	{
		s2 = s1;
		s2++;
		SCPY(s1, s2); // s1 - указатель на начало содержимого []

		s2 = SSTR(s1, skk);
		if (s2 != NULL)
		{
			s4 = s2;
			s4++;
			SCPY(s2, s4); // s2 - указатель на конец содержимого [] + 1
		}

		if (num1 == num2)
		{
			SCPY(s1, s2);
		}
	}

}

///////////////////
void setReinNoteText()
{


	//WCH snum[10];
	//WCH slen[10];

	//if (reNoteP[0] == NULL) return;

	setReinNoteFromFmt(sNote1, curNoteSet.sNoteUpFmt);
	setReinNoteFromFmt(sNote2, curNoteSet.sNoteDnFmt);

	SCPY(curNoteSet.sNoteUp, sNote1);
	SCPY(curNoteSet.sNoteDn, sNote2);

	MSDLGP dbP = findToolBox();

	if (dbP)
	{
		mdlDialog_itemSynchByTypeAndId(dbP, RTYPE_Text, TEXTID_NoteUp);
		mdlDialog_itemSynchByTypeAndId(dbP, RTYPE_Text, TEXTID_NoteDn);
	}



}




/////////////////////////////////
//func: place note
extern "C" DLLEXPORT void cmdReinNote(
char	*unparsedP
)
//cmdNumber   CMD_REIN_NOTE
{

	iAC = CMD_REIN_NOTE;
	iACStep = REIN_NOTE_STEP_P1;

	nSearchTypes = 3;
	searchType [0] = CMPLX_STRING_ELM;
	searchType [1] = TEXT_ELM;
	searchType [2] = DIMENSION_ELM;

    mdlLocate_init ();

	mdlLocate_noElemAllowLocked();
	//mdlLocate_noElemNoLocked();

    mdlLocate_setElemSearchMask (nSearchTypes, searchType);

	//mdlState_startModifyCommand(NULL, reinLocateNotePoint, NULL, reinLocateNoteShow, NULL, iAC, 0, FALSE, 0);

	curNote.clear();

	mdlState_startPrimitive(
		(StateFunc_DataPoint)reinLocateNotePoint, 
		(StateFunc_Reset)mdlState_startDefaultCommand, 
		0, 0);


	mdlOutput_prompt(L("Укажите первый стержень"));

	mdlLocate_setCursor();

	//syncToolbox();

}

////////////////////////
// create line between points and scan for bars, hilite
// fill curNote.vBars, curNote.mapNotePos
void processNoteBars(ReinNote* rnP)
{

	MSElementDescr* edP = NULL;
	mdlLine_create(&elTmp, &c0w0s2, rnP->arNotePts);
	//elTmp.line_3d.dhdr.props.b.invisible = 1;
	UInt32 fp = mdlElement_add(&elTmp);

	if (fp == 0) return;

	mdlElmdscr_read(&edP, fp, ACTIVEMODEL, 0, 0);

	if (edP)
	{

		ScanCriteria* scP = NULL;
		int status;
		ReinElm re;
		ReinBar rb;
		ReinSpace rs;
		DPoint3d prng[4];
		ScanRange sr;

		mdlElmdscr_computeRange(&prng[0], &prng[1], edP, NULL);

		levClash = 0;

		sr.xlowlim = (Int64)(prng[0].x - mdlCnv_masterUnitsToUors(dDupTol));
		sr.ylowlim = (Int64)(prng[0].y - mdlCnv_masterUnitsToUors(dDupTol));
		sr.zlowlim = (Int64)(prng[0].z - mdlCnv_masterUnitsToUors(dDupTol));

		sr.xhighlim = (Int64)(prng[1].x + mdlCnv_masterUnitsToUors(dDupTol));
		sr.yhighlim = (Int64)(prng[1].y + mdlCnv_masterUnitsToUors(dDupTol));
		sr.zhighlim = (Int64)(prng[1].z + mdlCnv_masterUnitsToUors(dDupTol));

		ReinPrm prm;
		prm.edP = edP;

		scP = mdlScanCriteria_create();
		status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
		status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanForDuplicate, &prm);
		//status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
		status = mdlScanCriteria_setDrawnElements(scP);
		status = mdlScanCriteria_setRangeTest(scP, &sr); // супер
		mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
		status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
		//==========================================
		status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
		//==========================================
		mdlScanCriteria_free(scP);


		// референсы
		{
			ModelRefIteratorP  iterator;
			DgnModelRefP	modelRef;

			mdlModelRefIterator_create(&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, -1); // nested

			while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
			{

				BINT isOn = FALSE;
				mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
				if (!isOn) continue;

				Transform tm;
				mdlTMatrix_masterToReference(&tm, modelRef);
				prng[2] = prng[0];
				prng[3] = prng[1];
				mdlTMatrix_transformRange(&prng[2], &prng[3], &tm);
				sr.xlowlim = (Int64)(prng[2].x - mdlCnv_masterUnitsToUors(dDupTol));
				sr.ylowlim = (Int64)(prng[2].y - mdlCnv_masterUnitsToUors(dDupTol));
				sr.zlowlim = (Int64)(prng[2].z - mdlCnv_masterUnitsToUors(dDupTol));
				sr.xhighlim = (Int64)(prng[3].x + mdlCnv_masterUnitsToUors(dDupTol));
				sr.yhighlim = (Int64)(prng[3].y + mdlCnv_masterUnitsToUors(dDupTol));
				sr.zhighlim = (Int64)(prng[3].z + mdlCnv_masterUnitsToUors(dDupTol));

				ReinPrm prm1;
				prm1.edP = edP;

				scP = mdlScanCriteria_create();
				status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
				status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanForDuplicate, &prm1);
				status = mdlScanCriteria_setDrawnElements(scP);
				status = mdlScanCriteria_setRangeTest(scP, &sr); // СУПЕР
				mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
				status = mdlScanCriteria_setModel(scP, modelRef);
				//==========================================
				status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
				//==========================================
				status = mdlScanCriteria_free(scP);

			}

			mdlModelRefIterator_free(&iterator);

		}


		mdlElmdscr_freeAll(&edP);

		mdlElmdscr_undoableDelete(0, fp, FALSE);
	}



}


/////////////////////////////////////////////
// func: place note - locate point
int	reinLocateNotePoint(
DVec3d    *pt,
int	    view)
{


	UInt32 fp = 0;
	DgnModelRefP mrP = NULL;
	MSElementDescr* edp = NULL;
	ReinElm relm;
	//ReinSpace rs;
	ReinElement relem;
	int sgm, v;
	ReinNote rn;
    
	fp = mdlLocate_findElement (pt, view, 0, ComponentMode_None, FALSE);

    if (fp == 0)
	{
		mdlOutput_printf (MSG_STATUS, L("Element not found"));
		return SUCCESS;
	}

	mrP = mdlLocate_getCurrModelRef ();

	ReinModel* rmP = curRM->getRM(mrP);

	if (rmP == NULL) return SUCCESS;

	if (mdlElmdscr_read(&edp, fp, mrP, 0, 0) == 0)
		return SUCCESS;

	if (readReinSpaceFromElmd(&relem, edp, FALSE) == SUCCESS)
	{
		iACStep = REIN_NOTE_STEP_P1;

		// находим два крайних элемента
		// рисуем между ними стрелки (createDim() между центрами тяжести, учитывая клип)
		// копируем крайний элемент в середину
		// ставим выноску от скопированного
		// все созданные элементы имеют атрибут для их автоудаления
	}
	// если указан ReinElm (вспомогательное построение)
	else if (readReinElmIso(&relm, edp, TRUE, TRUE) == SUCCESS)
	{
		

		if (iACStep == REIN_NOTE_STEP_P1)
		{
			reNoteP[0] = rmP->getReinElm(relm.bel.ffpos[REIN_ELEM_ISO]);
			reNoteP[0]->relmref = edp->h.elementRef;

			if (curNoteSet.noteopt[0]) reinSetBarInSpace(pt, fp, mrP, 1, 0); // func: reinSetBarInSpace() всегда виден, размер не ставить

			mdlLocate_getProjectedPoint(&curNote.arNotePts[0], &sgm, &v);
			iACStep++;

#if defined (MSVERSION) && (MSVERSION == 0xa00)
			StateCallback::SetDataPointFunction((StateFunc_DataPoint)reinLocateNotePoint);
#else
			mdlState_setFunction(STATE_DATAPOINT, reinLocateNotePoint);
#endif
			mdlOutput_prompt(L("Укажите второй стержень"));
			mdlLocate_hiliteElement(edp->h.elementRef, edp->h.dgnModelRef);
		}
		else if (iACStep == REIN_NOTE_STEP_P2)
		{
			reNoteP[1] = rmP->getReinElm(relm.bel.ffpos[REIN_ELEM_ISO]);
			reNoteP[1]->relmref = edp->h.elementRef;

			if (curNoteSet.noteopt[0]) reinSetBarInSpace(pt, fp, mrP, 1, 0); // func: reinSetBarInSpace() всегда виден, размер не ставить

			mdlLocate_getProjectedPoint(&curNote.arNotePts[1], &sgm, &v);
			iACStep++;

			mdlOutput_prompt(L("Укажите точку начала выноски"));
			mdlLocate_hiliteElement(reNoteP[0]->relmref, edp->h.dgnModelRef);
			mdlLocate_hiliteElement(reNoteP[1]->relmref, edp->h.dgnModelRef);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
			StateCallback::SetDataPointFunction((StateFunc_DataPoint)reinNotePoint);
#else
			mdlState_setFunction(STATE_DATAPOINT, reinNotePoint);
#endif

			//ELREF eref = dgnCache_findElemByFilePos (mdlModelRef_getCache(edp->h.dgnModelRef), reNote[0].bel.ffpos[REIN_ELEM_ISO], TRUE);
			//if (eref) mdlLocate_hiliteElement(eref, edp->h.dgnModelRef);

			curNote.bUpdate = false;

			processNoteBars(&curNote);

			/*

			MSElementDescr* edP = NULL;
			mdlLine_create(&elTmp, &c0w0s2, curNote.arNotePts);
			//elTmp.line_3d.dhdr.props.b.invisible = 1;
			UInt32 fp = mdlElement_add(&elTmp);

			mdlElmdscr_read(&edP, fp, ACTIVEMODEL, 0, 0);

			if (edP)
			{

				ScanCriteria* scP = NULL;
				int status;
				ReinElm re;
				ReinBar rb;
				ReinSpace rs;
				DPoint3d prng[4];
				ScanRange sr;

				mdlElmdscr_computeRange(&prng[0], &prng[1], edP, NULL);

				levClash = 0;

				sr.xlowlim = (Int64)(prng[0].x - mdlCnv_masterUnitsToUors(dDupTol));
				sr.ylowlim = (Int64)(prng[0].y - mdlCnv_masterUnitsToUors(dDupTol));
				sr.zlowlim = (Int64)(prng[0].z - mdlCnv_masterUnitsToUors(dDupTol));

				sr.xhighlim = (Int64)(prng[1].x + mdlCnv_masterUnitsToUors(dDupTol));
				sr.yhighlim = (Int64)(prng[1].y + mdlCnv_masterUnitsToUors(dDupTol));
				sr.zhighlim = (Int64)(prng[1].z + mdlCnv_masterUnitsToUors(dDupTol));


				scP = mdlScanCriteria_create();
				status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
				status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanForDuplicate, ...);
				//status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
				status = mdlScanCriteria_setDrawnElements(scP);
				status = mdlScanCriteria_setRangeTest(scP, &sr); // супер
				mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
				status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
				//==========================================
				status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
				//==========================================
				mdlScanCriteria_free(scP);


				// референсы
				{
					ModelRefIteratorP  iterator;
					DgnModelRefP	modelRef;

					mdlModelRefIterator_create(&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, -1); // nested

					while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
					{

						BINT isOn = FALSE;
						mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
						if (!isOn) continue;

						Transform tm;
						mdlTMatrix_masterToReference(&tm, modelRef);
						prng[2] = prng[0];
						prng[3] = prng[1];
						mdlTMatrix_transformRange(&prng[2], &prng[3], &tm);
						sr.xlowlim = (Int64)(prng[2].x - mdlCnv_masterUnitsToUors(dDupTol));
						sr.ylowlim = (Int64)(prng[2].y - mdlCnv_masterUnitsToUors(dDupTol));
						sr.zlowlim = (Int64)(prng[2].z - mdlCnv_masterUnitsToUors(dDupTol));
						sr.xhighlim = (Int64)(prng[3].x + mdlCnv_masterUnitsToUors(dDupTol));
						sr.yhighlim = (Int64)(prng[3].y + mdlCnv_masterUnitsToUors(dDupTol));
						sr.zhighlim = (Int64)(prng[3].z + mdlCnv_masterUnitsToUors(dDupTol));

						scP = mdlScanCriteria_create();
						status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
						status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanForDuplicate, ...);
						status = mdlScanCriteria_setDrawnElements(scP);
						status = mdlScanCriteria_setRangeTest(scP, &sr); // СУПЕР
						mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
						status = mdlScanCriteria_setModel(scP, modelRef);
						//==========================================
						status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
						//==========================================
						status = mdlScanCriteria_free(scP);

					}

					mdlModelRefIterator_free(&iterator);

				}


				mdlElmdscr_freeAll(&edP);

				mdlElmdscr_undoableDelete(0, fp, FALSE);
			}
			*/

		}
		
	}
	else if (readReinNoteFromElement(&rn, &edp->el) == SUCCESS)
	{
		fp = mdlLocate_findElement(&rn.arNotePts[0], tcb->lstvw, 0, ComponentMode_None, FALSE);
		mrP = mdlLocate_getCurrModelRef();
		rmP = curRM->getRM(mrP);
		if (rmP && fp) reNoteP[0] = rmP->getReinElm(fp);

		fp = mdlLocate_findElement(&rn.arNotePts[1], tcb->lstvw, 0, ComponentMode_None, FALSE);
		mrP = mdlLocate_getCurrModelRef();
		rmP = curRM->getRM(mrP);
		if (rmP && fp) reNoteP[1] = rmP->getReinElm(fp);

		iACStep = REIN_NOTE_STEP_NOTE1;

		ScanCriteria* scP = NULL;
		int status;
		int wzt = 1; // was zu tun - hilite note elements and read format strings


		curNote = rn;
		curNote.bUpdate = true;

		processNoteBars(&rn); // find bars, fill data and hilite

		// scan: update curNoteSet fmt strings and hilite note elements
		scP = mdlScanCriteria_create();
		status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
		status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanForReinNote, &wzt);
		//status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
		status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
		status = mdlScanCriteria_setDrawnElements(scP);
		status = mdlScanCriteria_setGraphicGroupTest(scP, rn.iNoteGGN); // GRAPHIC GROUP
		mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinNote);
		status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
		status = mdlScanCriteria_free(scP);

		syncToolbox(); // sync after update crNoteSet fmt strings

		iACStep = REIN_NOTE_STEP_UPDATE;

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		StateCallback::SetDataPointFunction((StateFunc_DataPoint)reinNotePoint);
#else
		mdlState_setFunction(STATE_DATAPOINT, reinNotePoint);
#endif

	}


	mdlElmdscr_freeAll(&edp);



	return SUCCESS;
}

int iNoteDynMode = 0;

/////////////////////////////////////////
// func: place note - dynamics
void reinNoteDynamics(
DVec3d*  ptP,  
int  view  
)
{

	MSElementDescr* edpDyn = NULL;
	mdlCell_create(&eCell, NULL, NULL, FALSE);
	mdlElmdscr_new (&edpDyn, NULL, &eCell);

	//int ispace = 0;
	double dspace = 0;
	int ipos = 0;
	int iqty = 0;

	DVec3d ptsln[3];
	int iVertNum = 0;

	curNote.arNotePts[3] = *ptP;

	if (curNoteSet.iNoteStyle == 1)
	{
		ptsln[0] = curNote.arNotePts[2];
		ptsln[1] = curNote.arNotePts[3];
		iVertNum = 2;
	}
	else if (curNoteSet.iNoteStyle == 0)
	{
		ptsln[0] = curNote.arNotePts[2];
		ptsln[1] = curNote.arNotePts[3];
		ptsln[2] = curNote.arNotePts[3];
		iVertNum = 3;
	}

	int iDynMode = 0;

	//======================================
	if (EQ(curNote.arNotePts[2].x, curNote.arNotePts[3].x))
	{
		if (iNoteDynMode == 0)
			iDynMode = 1;
		else
			iDynMode = iNoteDynMode;
	}
	else if (curNote.arNotePts[2].x < curNote.arNotePts[3].x)
		iDynMode = 1;
	else
		iDynMode = -1;

	iNoteDynMode = iDynMode;
	//======================================


	arPos.clear();
	arPos.resize(10);
	arPosCount.clear();
	arPosCount.resize(10);
	iPosCount = 0;


	if (reNoteP[0])
	{
		ELREF eref = getElemRefByID(reNoteP[0]->bel.modrefP, reNoteP[0]->bel.elemid);
		if (eref)
		{
			MSElementDescr* edp;
			ReinBar rb;
			//ReinSpace rs;
			ReinElement relem;

			mdlElmdscr_getByElemRef (&edp, eref, reNoteP[0]->bel.modrefP, FALSE, 0);

			if (edp)
			{

				if (readReinBarFromElement(&rb, edp, TRUE) == SUCCESS)
				{
					dspace = rb.spacef;
				}
				else if (readReinSpaceFromElmd(&relem, edp, FALSE) == SUCCESS)
				{
					dspace = relem.rs.spacef;
				}

				mdlElmdscr_freeAll(&edp);
			}
		}
	}




	ipos = 0; // брать сравнением



	arPos.clear();
	arPos.resize(10);
	arPosCount.clear();
	arPosCount.resize(10);
	iPosCount = 0;




	//Transform tm[2];
	//WCH txtPNum[50];
	//WCH txtDown[50];
	DVec3d ptsTxt[5];
	DVec3d pLeftOrg[2];
	DVec3d pSnapOrg;
	DVec3d pMove[2];
	DVec3d pMargin;
	MSTextSize ts;
	//TextParam tp;

	//tp.font = 0;
	//tp.just = 0;
	//tp.style = 0;
	//tp.viewIndependent = 0;

	if (arPos[0] == ipos) iqty = arPosCount[0];
	if (arPos[1] == ipos) iqty = arPosCount[1];
	if (arPos[2] == ipos) iqty = arPosCount[2]; //...

	dspace = dspace * iPosCount;


	setReinNoteText();
	//if (SLEN(curNoteSet.sNoteUp) > 0) SPRN(curNoteSet.sNoteUp, L("(%i)%i"), ipos, iqty);
	//if (SLEN(curNoteSet.sNoteDn) > 0) SPRN(curNoteSet.sNoteDn, L("%i"), ispace);


#if defined (MSVERSION) && (MSVERSION == 0xa00) // text

	WString wstr;

	if (SLEN(curNoteSet.sNoteUp) > 0)
	{
		mdlText_create(&elTxt[0], NULL, curNoteSet.sNoteUp, &curNote.arNotePts[3], &arViewPlanes[view].rm, NULL, NULL, NULL, NULL);
		mdlText_extract(&wstr, &pLeftOrg[0], &pSnapOrg, 0, &ts, 0, 0, &elTxt[0]);
	}

	if (SLEN(curNoteSet.sNoteDn) > 0)
	{
		mdlText_create(&elTxt[1], NULL, curNoteSet.sNoteDn, &curNote.arNotePts[3], &arViewPlanes[view].rm, NULL, NULL, NULL, NULL);
		mdlText_extract(&wstr, &pLeftOrg[1], &pSnapOrg, 0, &ts, 0, 0, &elTxt[1]);
	}

#else
	if (SLEN(curNoteSet.sNoteUp) > 0)
	{
		mdlText_create(&elTxt[0], NULL, curNoteSet.sNoteUp, &curNote.arNotePts[3], NULL, NULL/*&arViewRM[view]*/, NULL, NULL);
		mdlText_extract(&pLeftOrg[0], &pSnapOrg, 0, 0, 0, 0, 0, 0, 0, &ts, &elTxt[0]);
	}

	if (SLEN(curNoteSet.sNoteDn) > 0)
	{
		mdlText_create(&elTxt[1], NULL, curNoteSet.sNoteDn, &curNote.arNotePts[3], NULL, NULL/*&arViewRM[view]*/, NULL, NULL);
		mdlText_extract(&pLeftOrg[1], &pSnapOrg, 0, 0, 0, 0, 0, 0, 0, &ts, &elTxt[1]);
	}
#endif

	Transform tm;

	double dVynos = 0.;
	double dMargin = 0.;

	if (SLEN(curNoteSet.sNoteUp) > 0)
	{
		mdlText_extractShape(ptsTxt, 0, &elTxt[0], FALSE, 0);
		mdlVec_subtractPoint(&pMove[0], &pSnapOrg, &pLeftOrg[0]);
		mdlVec_subtractPointArray(ptsTxt, &ptsTxt[0], 5); // left lower
		//margin
		dMargin = ptsTxt[3].y * rDopInfo.dopval[6];
		mdlVec_scaleToLength(&pMargin, &ptsTxt[3], dMargin);
		pMargin.x = dMargin;
		mdlVec_addPoint(&pMove[0], &pMove[0], &pMargin);

		dVynos = ptsTxt[1].x + dMargin * 2.;
	}


	if (SLEN(curNoteSet.sNoteDn) > 0)
	{
		mdlText_extractShape(ptsTxt, 0, &elTxt[1], FALSE, 0);
		mdlVec_subtractPoint(&pMove[1], &pSnapOrg, &pLeftOrg[1]);
		mdlVec_subtractPointArray(ptsTxt, &ptsTxt[3], 5); // left upper
		//margin
		dMargin = ptsTxt[0].y * -rDopInfo.dopval[6];
		mdlVec_scaleToLength(&pMargin, &ptsTxt[0], dMargin);
		pMargin.x = dMargin;
		mdlVec_addPoint(&pMove[1], &pMove[1], &pMargin);
		//shift down
		mdlVec_addPoint(&pMove[1], &pMove[1], &ptsTxt[0]);

		if (dVynos < ptsTxt[1].x + dMargin * 2.)
		{
			dVynos = ptsTxt[1].x + dMargin * 2.;
		}

	}

	//shift dyn
	if (iDynMode == -1)
	{
		pMove[0].x -= dVynos;
		pMove[1].x -= dVynos;
	}

	if (SLEN(curNoteSet.sNoteUp) > 0)
	{
		//trans
		mdlTMatrix_getIdentity(&tm);
		mdlTMatrix_setTranslation(&tm, &pMove[0]);
		mdlElement_transform(&elTxt[0], &elTxt[0], &tm);
	}

	if (SLEN(curNoteSet.sNoteDn) > 0)
	{
		//trans
		mdlTMatrix_getIdentity(&tm);
		mdlTMatrix_setTranslation(&tm, &pMove[1]);
		mdlElement_transform(&elTxt[1], &elTxt[1], &tm);
	}

	//mdlVec_safeDivide(&ptsTxt[2], &ptsTxt[2], 0.5);



	ptsln[2].x += dVynos * iDynMode;
	if (iVertNum)
	{
		//mdlLineString_create(&elTmp, &c0w0s0, ptsln, iVertNum);
		createNote(&elTmp, ptsln, iVertNum, NULL, NULL);
	}



	if (iACStep == REIN_NOTE_STEP_NOTE_FINISH)
	{
		/*
		UInt32 ggn = mdlSystem_updateGraphicGroup();

		
		MSWCH levname[MAX_LEVEL_NAME_LENGTH];

		SCPM2W(levname, curNoteSet.sNoteLevel, MAX_LEVEL_NAME_LENGTH);

		if (wcslen(levname) == 0) // почему sNoteLevel пустой - непонятно
		{
			MSDLGP dbP = findToolBox();
			WCH v[100];
			if (dbP)
			{
				DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ComboBox, COMBOBOX_NoteLevels, 0);
				if (diP)
				{
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
					mdlDialog_rItemValueGet(0, 0, v, diP->rawItemP, 100);
					SCPM2W(levname, v, MAX_LEVEL_NAME_LENGTH);
#else
					MSValueDescr vv;
					mdlDialog_rItemValueGet(vv, diP->rawItemP);
					vv.GetWChar(levname, 100);
#endif
				}
			}
		}


		LEVID iLevelId = getOrCreateLevel(ACTIVEMODEL, levname, true);
*/
		//mdlDim_validate(&elTmp);

		if (iVertNum) mdlElement_setProperties(&elTmp, &curNote.iNoteLevID, &curNote.iNoteGGN, NULL, NULL, NULL, NULL, NULL, NULL);
		if (SLEN(curNoteSet.sNoteUp) > 0) mdlElement_setProperties(&elTxt[0], &curNote.iNoteLevID, &curNote.iNoteGGN, NULL, NULL, NULL, NULL, NULL, NULL);
		if (SLEN(curNoteSet.sNoteDn) > 0) mdlElement_setProperties(&elTxt[1], &curNote.iNoteLevID, &curNote.iNoteGGN, NULL, NULL, NULL, NULL, NULL, NULL);


		if (mdlElement_isEffectivelyVisible(&elTxt[0], ACTIVEMODEL, tcb->lstvw) == FALSE)
		{
			wcscpy(wss, L"Проверьте отображение слоя!");
			mdlOutput_messageCenterW(MESSAGE_INFO, wss, wss, MESSAGE_ALERT_BALLOON);
		}


		if (iVertNum) 
		{
			MSElementDescr* edP = NULL;
			mdlElmdscr_new(&edP, 0, &elTmp);
			xmlAddNoteInfo(&curNote, 0, &edP, 1);
			mdlElmdscr_add(edP);
			mdlElmdscr_freeAll(&edP);
			//mdlElement_add(&elTmp);
		}

		// todo повернуть текст выноски по линии
		//DVec3d vTxt;
		//mdlVec_subtract(&vTxt, &curNote.arNotePts[0])


		if (SLEN(curNoteSet.sNoteUp) > 0)
		{
			MSElementDescr* edP = NULL;
			mdlElmdscr_new(&edP, 0, &elTxt[0]);
			xmlAddNoteInfo(&curNote, curNoteSet.sNoteUpFmt, &edP, 2);
			mdlElmdscr_add(edP);
			mdlElmdscr_freeAll(&edP);
		}

		if (SLEN(curNoteSet.sNoteDn) > 0)
		{
			MSElementDescr* edP = NULL;
			mdlElmdscr_new(&edP, 0, &elTxt[1]);
			xmlAddNoteInfo(&curNote, curNoteSet.sNoteDnFmt, &edP, 3);
			mdlElmdscr_add(edP);
			mdlElmdscr_freeAll(&edP);
		}


		//mdlDialog_cmdNumberQueue(TRUE, CMD_REIN_NOTE, NULL, TRUE); // перезапуск команды
		cmdReinNote("");
	}
	else
	{


		if (iVertNum) mdlElmdscr_appendElement(edpDyn, &elTmp);


		mdlElmdscr_appendElement(edpDyn, &elTxt[0]);
		if (SLEN(curNoteSet.sNoteDn) > 0) mdlElmdscr_appendElement(edpDyn, &elTxt[1]);

		mdlDynamic_setElmDescr(edpDyn);
	}









}

/////////////////////////////////////////////
void	reinLocateNoteShow(void)
{
}


/////////////////////////////////
// find elements of the note (dimension, leader, text)
int scanForReinNote(
	MSElementDescr* edP,
	int* wzt, // was zu tun
	ScanCriteria* pScanCriteria
)
{
	ReinNote rnloc;

	int t = mdlElement_getType(&edP->el);
	UInt32 fp = mdlElmdscr_getFilePos(edP);

	

	if (readReinNoteFromElement(&rnloc, &edP->el) == SUCCESS)
	{

		if (wzt 
			//&& *wzt == 1
			) // hilite
		{

			if (rnloc.ielem == 0  // legacy (only up)
				|| rnloc.ielem == 2) // up
			{
				if (!curNoteSet.noteopt[1]) // iNoteUpFmt
					SCPY(curNoteSet.sNoteUpFmt, rnloc.sNoteFmt);
					
				setReinNoteFromFmt(curNoteSet.sNoteUp, curNoteSet.sNoteUpFmt);
			}
			else if (rnloc.ielem == 3) // down text
			{
				if (!curNoteSet.noteopt[2]) // iNoteDnFmt
					SCPY(curNoteSet.sNoteDnFmt, rnloc.sNoteFmt);
					
				setReinNoteFromFmt(curNoteSet.sNoteDn, curNoteSet.sNoteDnFmt);
			}

			mdlLocate_hiliteElement(edP->h.elementRef, mdlScanCriteria_getModel(pScanCriteria));
		}
		else
		if (t == TEXT_ELM)
		{
			//rnloc.sNoteFmt
			DPoint3d p[2];
			WCH snote[100];
			WCH* sfmt;
			MSWCH wnote[100];
			MSWideChar stext[500];
			MSWideChar stext2[500];
			MSTextSize ts;
			TextSizeParam tsp;
			TextParamWide tpw;
			RotMatrix rm;

			//mdlText_extract(&p[0], &p[1], 0, 0, stext, 0, 0, 0, 0, &ts, &elTxt[0]);
#if defined (MSVERSION) && (MSVERSION == 0xa00)
			WString wstext;
			mdlText_extract(&wstext, &p[0], &p[1], &rm, &tsp, &tpw, 0, &edP->el);
			wcscpy(stext, wstext.c_str());
#else
			mdlText_extractWide(stext, &p[0], &p[1], &rm, &tsp, &tpw, 0, &edP->el);
#endif
			// create text by rnloc.sNoteFmt and update if not equal...

			if (rnloc.ielem == 2
				|| rnloc.ielem == 0 // legacy
				)
			{
				sfmt = curNoteSet.sNoteUpFmt;
				rnloc.ielem = 2;
			}
			else if (rnloc.ielem == 3)
			{
				sfmt = curNoteSet.sNoteDnFmt;
				rnloc.ielem = 3;
			}
			else
				sfmt = rnloc.sNoteFmt;

			setReinNoteFromFmt(snote, sfmt);

			SCPM2W(wnote, snote, 100);

#if defined (MSVERSION) && (MSVERSION == 0x8b0)
			MSWCharStringToMSWideCharString(stext2, 500, wnote, 0x0419);
#else
			wcscpy(stext2, wnote);
#endif

			mdlText_createWide(&elTxt[0], &edP->el, stext2, &p[1], &rm, &tsp, &tpw, NULL
#if defined (MSVERSION) && (MSVERSION == 0xa00)
				, ACTIVEMODEL
#endif
			);

			MSElementDescr* edText = NULL;

			mdlElmdscr_new(&edText, 0, &elTxt[0]);

			xmlAddNoteInfo(&curNote, sfmt, &edText, rnloc.ielem, true);

			mdlElmdscr_rewrite(edText, 0, fp);

			mdlElmdscr_freeAll(&edText);
		}
			
	}

	//curNote

	//mdlText_create(&elTxt[0], NULL, curNoteSet.sNoteUp, &curNote.arNotePts[3], NULL, NULL/*&arViewRM[view]*/, NULL, NULL);


	//mdlText_create...

	return SUCCESS;
}

/////////////////////////////////////////////
// func: place note - point
int	reinNotePoint(
DVec3d    *pt,
int	    view)
{

	int sgm;

	//UInt32 fp = mdlLocate_findElement(pt, view, 0, ComponentMode_None, FALSE);

	if (iACStep == REIN_NOTE_STEP_NOTE1)
	{
		curNote.iNoteGGN = mdlSystem_updateGraphicGroup();

		MSWCH levname[MAX_LEVEL_NAME_LENGTH];

		SCPM2W(levname, curNoteSet.sNoteLevel, MAX_LEVEL_NAME_LENGTH);

		if (wcslen(levname) == 0) // почему sNoteLevel пустой - непонятно
		{
			MSDLGP dbP = findToolBox();
			WCH v[100];
			if (dbP)
			{
				DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ComboBox, COMBOBOX_NoteLevels, 0);
				if (diP)
				{
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
					mdlDialog_rItemValueGet(0, 0, v, diP->rawItemP, 100);
					SCPM2W(levname, v, MAX_LEVEL_NAME_LENGTH);
#else
					MSValueDescr vv;
					mdlDialog_rItemValueGet(vv, diP->rawItemP);
					vv.GetWChar(levname, 100);
#endif
				}
			}
		}

		curNote.iNoteLevID = getOrCreateLevel(ACTIVEMODEL, levname, true);


		//mdlLocate_getProjectedPoint(&curNote.arNotePts[2], &sgm, &v);
		curNote.arNotePts[2] = *pt;
		mdlState_setAccudrawContext(ACCUDRAW_SetOrigin, &curNote.arNotePts[2], 0, 0, 0, 0);

		if (curNoteSet.iNoteDim) createReinSign();

		iACStep++;

		mdlState_dynamicUpdate((StateFunc_SimpleDynamics)reinNoteDynamics, TRUE);

		mdlOutput_prompt(L("Укажите точку полки выноски"));

	}
	else if (iACStep == REIN_NOTE_STEP_NOTE2)
	{
		//createDim(&el, curNote.arNotePts, 2, TRUE);

		iACStep++;

		iACStep = REIN_NOTE_STEP_NOTE_FINISH;
	}
	else if (iACStep == REIN_NOTE_STEP_UPDATE)
	{
		// scan for text to update...

		ScanCriteria* scP = NULL;
		int status;

		scP = mdlScanCriteria_create();
		status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
		status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanForReinNote, NULL);
		//status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
		status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
		status = mdlScanCriteria_setDrawnElements(scP);
		status = mdlScanCriteria_setGraphicGroupTest(scP, curNote.iNoteGGN); // GRAPHIC GROUP
		mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinNote);
		status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
		status = mdlScanCriteria_free(scP);

		cmdReinNote("");

	}



	if (iACStep == REIN_NOTE_STEP_NOTE_FINISH)
		reinNoteDynamics(pt, view);

	return SUCCESS;
}


/////////////////////////////////////////////////////////////////////////////
int createReinSign(void)
{
	//ReinElm reNote[2]
	//DVec3d curNote.arNotePts[3];

	// рисуем между ними стрелки (createDim() между центрами тяжести, учитывая клип)
	// копируем крайний элемент в середину
	// ставим выноску от скопированного
	// все созданные элементы имеют атрибут для их автоудаления

	CLIPDESC clipP = NULL;

	MSElementDescr* edpFrst = NULL;
	MSElementDescr* edpScnd = NULL;
	MSElementDescr* edpClip1 = NULL;
	MSElementDescr* edpClip2 = NULL;
	MSElementDescr* edpBar = NULL;

	if (reNoteP[0] == NULL && reNoteP[1] == NULL) return SUCCESS;

	/*

	if (reNoteP[0]) mdlElmdscr_read(&edpFrst, reNoteP[0]->bel.ffpos[REIN_ELEM_ISO], reNoteP[0]->bel.mrP, FALSE, 0);
	if (reNoteP[1]) mdlElmdscr_read(&edpScnd, reNoteP[1]->bel.ffpos[REIN_ELEM_ISO], reNoteP[1]->bel.mrP, FALSE, 0);
	//mdlElmdscr_readToMaster(&edpFrst, reNote[0].bel.ffpos[REIN_ELEM_ISO], reNote[0].bel.mrP, FALSE, 0);
	//mdlElmdscr_readToMaster(&edpScnd, reNote[1].bel.ffpos[REIN_ELEM_ISO], reNote[1].bel.mrP, FALSE, 0);


	if (reNoteP[0] && edpFrst && mdlModelRef_isActiveModel(reNoteP[0]->bel.mrP) == FALSE)
	{
		int r = func_pma(mdlClip_getRefBoundary,clipP), reNoteP[0]->bel.mrP, 0);

		if (r == SUCCESS && NOTNULL(clipP))
		{
			int res = mdlClip_element(&edpClip1, NULL, edpFrst, reNoteP[0]->bel.mrP, GETPTR(clipP), 0);

			if (res == SUCCESS && edpClip1 != NULL)
			{
				if (edpClip1 != edpFrst) // edpClip1 dublicated from newEdP and clipped
				{
					edpFrst = edpClip1;
				}
			}

			myClip_free(clipP);
		}
	}


	if (reNoteP[1] && edpScnd && mdlModelRef_isActiveModel(reNoteP[1]->bel.mrP) == FALSE)
	{
		int r = func_pma(mdlClip_getRefBoundary,clipP), reNoteP[1]->bel.mrP, 0);

		if (r == SUCCESS && NOTNULL(clipP))
		{
			int res = mdlClip_element(&edpClip2, NULL, edpScnd, reNoteP[1]->bel.mrP, GETPTR(clipP), 0);

			if (res == SUCCESS && edpClip2 != NULL)
			{
				if (edpClip2 != edpScnd) // edpClip1 dublicated from newEdP and clipped
				{
					edpScnd = edpClip2;
				}
			}

			myClip_free(clipP);
		}
	}


	if (edpFrst) mdlMeasure_linearProperties(0, &curNote.arNotePts[0], 0, 0, 0, 0, 0, 0, edpFrst, -1);
	if (edpScnd) mdlMeasure_linearProperties(0, &curNote.arNotePts[1], 0, 0, 0, 0, 0, 0, edpScnd, -1);
	*/

	//if (edpFrst && edpScnd)
	{
		//mdlVec_interpolate(&curNote.arNotePts[1], &curNote.arNotePts[0], 0.5, &curNote.arNotePts[2]);

		createDim(&el, curNote.arNotePts, 3, TRUE);
		
	}




	/*

	DVec3d pDir;

	mdlVec_subtractPoint(&pDir, &curNote.arNotePts[1], &curNote.arNotePts[0]);
	
	// add bar copy to file
	mdlElmdscr_duplicate(&edpBar, edpFrst);

	Transform tm;
	mdlTMatrix_getIdentity(&tm);
	mdlTMatrix_setTranslation(&tm, &pDir);

	func_amp(mdlElmdscr_transform,edpBar), &tm);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	EditElementHandle eeeh(edpBar, false, true);
	callbackElmDscrCopy(eeeh, reNote[0].bel.mrP, ACTIVEMODEL, TRUE); // чтобы создать edCopyP
#else
	callbackElmDscrCopy(&edpBar, reNote[0].bel.mrP, ACTIVEMODEL, TRUE); // чтобы создать edCopyP
#endif

	mdlElmdscr_add(edpBar);
	*/


	if (edpFrst) mdlElmdscr_freeAll(&edpFrst);
	if (edpScnd) mdlElmdscr_freeAll(&edpScnd);

	return SUCCESS;
}


////////////////////////////////////////
int connectDB(int iMessage)
{
	WCH cfgvar[500];
	WCH sName[300];
	int res = SUCCESS;

	writeLogIn(__FUNCTION__, 0);


	if (getCfgVarEx(cfgvar, L"REIN_UDLPATH") != SUCCESS)
	{
		mdlOutput_messageCenter(MESSAGE_WARNING,
		L("Check REIN_UDLPATH"), 
		L("Error reading config variable REIN_UDLPATH"), 
		(OutputMessageAlert)iMessage);

		writeLog("error read REIN_UDLPATH", 0, 0, 1);

		writeLogOut(__FUNCTION__, 0);

		return 1;
	}
	else
	{
		SCPY(sName, cfgvar);
	}


	writeLog("try to connect database...", 0, 0, 1);

	res = mdlDB_changeDatabase(DATABASESERVERID_OLEDB, sName);


	if (res > 0)
	{
		WCH serr[1000];
		SPRN(serr, L("cannot connect database, name= %s, error= %i\n"), sName, res);
		mdlOutput_messageCenter(MESSAGE_WARNING, serr, serr, (OutputMessageAlert)iMessage);

		writeLog("error", 0, 0, 1);
	}
	else
	{
		writeLog("connected", 0, 0, 1);
	}


	writeLogOut(__FUNCTION__, 0);

	return res;
}

//////////////////////////////
ReinLap* getReinLap(int diam)
{
	//if (curCat.projID == 0) return NULL;

	
	for (vector<ReinLap>::iterator it = daBaseLaps.begin(); it != daBaseLaps.end(); ++it)
	//for (UInt32 i = 0; i < daBaseLaps.size(); i++)
	{
		if (it->diameter == diam && it->projID == curCat.projID)
		{
			return &(*it);
		}
	}

	// не найден, пытаемся использовать по умолчани (projID = 0)

	for (vector<ReinLap>::iterator it = daBaseLaps.begin(); it != daBaseLaps.end(); ++it)
	//for (UInt32 i = 0; i < daBaseLaps.size(); i++)
	{
		if (it->diameter == diam && it->projID == 0)
		{
			return &(*it);
		}
	}



	return NULL;

}

/////////////////////////////////////////////////
long getReinLapSrtmID(int diam, long defsrtmID)
{
	int locsrtmID = 0;

	UInt32 prjID = curCat.projID;

	if (iCfgVar_ProjectID_Override > 0) prjID = iCfgVar_ProjectID_Override;

	for (vector<ReinLap>::iterator it = daBaseLaps.begin(); it != daBaseLaps.end(); ++it)
	//for (UInt32 i = 0; i < daBaseLaps.size(); i++)
	{
		if (it->diameter == diam && it->projID == prjID)
		{
			locsrtmID = it->isrtmID;
			break;
		}
	}

	if (locsrtmID == 0)
		return defsrtmID;
	else
		return locsrtmID;

}

/////////////////////////////////////////////////
long getReinLapMatID(int diam, long defmatID)
{
	int locmatID = 0;

	UInt32 prjID = curCat.projID;

	if (iCfgVar_ProjectID_Override > 0) prjID = iCfgVar_ProjectID_Override;

	for (vector<ReinLap>::iterator it = daBaseLaps.begin(); it != daBaseLaps.end(); ++it)
	//for (UInt32 i = 0; i < daBaseLaps.size(); i++)
	{
		if (it->diameter == diam && it->projID == prjID)
		{
			locmatID = it->imatID;
			break;
		}
	}

	if (locmatID == 0)
		return defmatID;
	else
		return locmatID;

}


//////////////////////////////
int getReinLapBend(int diam, int index)
{
	//if (curCat.projID == 0) return NULL;

	int bend = 0;

	for (vector<ReinLap>::iterator it = daBaseLaps.begin(); it != daBaseLaps.end(); ++it)
	//for (UInt32 i = 0; i < daBaseLaps.size(); i++)
	{
		if (it->diameter == diam && it->projID == curCat.projID)
		{
			bend = it->bend[index];
			break;
		}
	}

	// не найден, пытаемся использовать по умолчани (projID = 0)

	for (vector<ReinLap>::iterator it = daBaseLaps.begin(); it != daBaseLaps.end(); ++it)
	//for (UInt32 i = 0; i < daBaseLaps.size(); i++)
	{
		if (it->diameter == diam && it->projID == 0)
		{
			bend = it->bend[index];
			break;
		}
	}

	if (bend == 0)
		return 12 * diam;
	else
		return bend;

}




/////////////////////////
void loadDBLaps(void)
{

	writeLogIn(__FUNCTION__, 0);

	CursorID ci;
	MS_sqlda    sqlda;

	UInt32 laps[100] = { 0 };
	//ZeroMemory(laps, sizeof(laps));

	daBaseLaps.clear();

	WCH sSQL[200];

	SCPY(sSQL, L("select lapID, projectID, diameter, lapValue, maxlen, bend_work, bend_free, muft, srtmID, matID, bendrad from rein_laps"));

	connectDB();

	int res = mdlDB_openCursorWithID  (&ci, sSQL);

	WCH  v[500];

	//REIN_BAR_LAP
	if (getCfgVar(v, L("REIN_BAR_LAP")) == SUCCESS)
	{
		WCH seps[] = L(",");
		WCH *token;

		token = STOK(v, seps);
		if (token) token = STOK(NULL, seps);

		for (int i = 1; token; i++)
		{
			laps[i] = STOUL(token, 0, 0);

			token = STOK(NULL, seps);
		}
	}

	if (res == SUCCESS)
	{
		ReinLap rl;
		ReinLap* rlP = &rl;

		while (mdlDB_fetchRowByID  (&sqlda, ci) != QUERY_FINISHED)
		{
			//rlP = (ReinLap*)mdlDArray_insertMembers(daBaseLaps, 0, 1, -1);

			rlP->lapID = STOL(sqlda.value[0]);
			rlP->projID = STOL(sqlda.value[1]);
			rlP->diameter = STOI(sqlda.value[2]);
			rlP->lapValue = STOI(sqlda.value[3]);
			rlP->maxlen = STOI(sqlda.value[4]);
			rlP->bend[0] = STOI(sqlda.value[5]); // bend_work
			rlP->bend[1] = STOI(sqlda.value[6]); // bend_free
			rlP->muft = STOI(sqlda.value[7]);
			rlP->isrtmID = STOL(sqlda.value[8]);
			rlP->imatID = STOL(sqlda.value[9]);
			rlP->bendrad = STOL(sqlda.value[10]); // bendrad

			if (laps[rlP->diameter] > 0) rlP->lapValue = laps[rlP->diameter];

			daBaseLaps.push_back(rl);

		}

		mdlDB_closeCursorByID (ci);
		mdlDB_freeSQLDADescriptor (&sqlda);

	}


	if (getCfgVar(v, L("REIN_DB_ID_OVERRIDE")) == SUCCESS)
		iCfgVar_ProjectID_Override = STOI(v);

	writeLogOut(__FUNCTION__, 0);


}


/////////////////////////////////////////////////////////////////////////
// func: set bar segment length
void setSegmLength(DVec3d* arPts, int numPts, int iSgm, double dSgmLen)
{
	DVec3d pVec;

	mdlVec_subtractPoint(&pVec, &arPts[iSgm], &arPts[iSgm + 1]);

	mdlVec_scaleToLengthInPlace(&pVec, mdlVec_distance(&arPts[iSgm], &arPts[iSgm + 1]) - dSgmLen);

	mdlVec_addPointArray(&arPts[iSgm + 1], &pVec, (numPts - iSgm + 1));

}


/////////////////////////////////////////
void barCalcComparePoints( // old use
						  ReinBar* rbP, 
						  int bUseRealPts, // rbP->nrm должна быть готова!
						  Transform* tmP // для переменных сегментов - вертикальные или горизонтальные
						  )
{
	if (rbP == NULL) return;
	//if (rbP->numpts <= 2) return;

	DVec3d pBeg;
	DVec3d pEnd;
	//DVec3d pMainReverse;

	double dVarSegmLen = 1000.;

	//int bOdd = !!(rbP->inum & 1);

//	if (rbP->pnum == 81)
//		printf("");


	//if (iCfgVar_PosCalc_Laps)
	//{
	//	if ((rbP->lap[0] && !rbP->lap[1]) || (!rbP->lap[0] && rbP->lap[1]))
	//	{
	//		if (rbP->lap[0]) dVarSegmLen *= 2;
	//		if (rbP->lap[1]) dVarSegmLen *= 3;
	//	}
	//}

	if (iCfgVar_PosCalc_Laps) dVarSegmLen += (double)rbP->lap[0] + (double)rbP->lap[1]; // для различия по четности


	DVec3d arTrPts[MAX_BAR_VERTICES];
	DVec3d arPts[MAX_BAR_VERTICES];
	DVec3d arCPts[MAX_BAR_VERTICES];
	DVec3d arCPta[MAX_BAR_VERTICES];
	int arF[MAX_BAR_VERTICES]; // флаги для переменных сегментов, 1 - гориз., 2 - верт.

	for (int i = 0; i < MAX_BAR_VERTICES; i++) arF[i] = 0;

	rbP->cnumpts = rbP->numpts;

	//DVec3d pNrm;
	//DVec3d pCent;

	// arCPta =============== сначала считаем альтернативные (с конца)

	//std::copy(rbP->rpts.begin(), rbP->rpts.end(), arTrPts);
	for (int i = 0; i < MAX_BAR_VERTICES; i++) arTrPts[i] = rbP->rpts[i];

	if (tmP)
		mdlTMatrix_transformPointArray(arTrPts, tmP, rbP->numpts);
		

	if (!bUseRealPts)
	{
		for (int i = 0; i < rbP->numpts; i++)
		//for (int i = 0; i < rbP->apts.size() && i < MAX_BAR_VERTICES; i++)
		{
			arCPta[i].x = rbP->apts[i].x;
			arCPta[i].y = rbP->apts[i].y;
			arCPta[i].z = rbP->apts[i].z;
		}
	}
	else
	{
		for (int b = 0; b < 15; b++)
			mdlVec_zero(&arPts[b]);

		DgnModelRefP mrP = NULL;
		if (rbP->modrefP) mrP = rbP->modrefP; else mrP = ACTIVEMODEL;

		if (rbP->numpts == 2)
		{
			

			if (coordIsEqual(arTrPts[0].z, arTrPts[1].z, FALSE)) 
			{
				arF[0] = 1;
			}

			if (coordIsEqual(arTrPts[0].x, arTrPts[1].x, FALSE) && coordIsEqual(arTrPts[0].y, arTrPts[1].y, FALSE))
			{
				arF[0] = 2;
			}

			arPts[1].x = mdlVec_distance(&rbP->rpts[0], &rbP->rpts[1]);
			mdlCnv_UORToMaster(&arPts[1].x, arPts[1].x, mrP);
		}
		else
		{
			
			// получаем точки
			for (int i = 0; i < rbP->numpts; i++) // numpts == cnumpts
			{
				if (rbP->rfa[i] & RFA_ARCP || rbP->rfa[i] & RFA_CIRP) // ставим центр дуги
					arPts[i] = rbP->cents[i];
				else
					arPts[i] = rbP->rpts[i];

				mdlCnv_UORToMaster(&arPts[i].x, arPts[i].x, mrP);
				mdlCnv_UORToMaster(&arPts[i].y, arPts[i].y, mrP);
				mdlCnv_UORToMaster(&arPts[i].z, arPts[i].z, mrP);

				// флаги для сегм. перем. длины
				if (i < rbP->numpts - 1 && 
					!(rbP->rfa[i] & RFA_ARCP || rbP->rfa[i] & RFA_CIRP) &&
					!(rbP->rfa[i + 1] & RFA_ARCP || rbP->rfa[i + 1] & RFA_CIRP)
					)
				{
					if (coordIsEqual(arTrPts[i].z, arTrPts[i + 1].z, FALSE)) 
					{// горизонтальная
						arF[i] = 1;
					}

					if (coordIsEqual(arTrPts[i].x, arTrPts[i + 1].x, FALSE) && coordIsEqual(arTrPts[i].y, arTrPts[i + 1].y, FALSE))
					{// вертикальная
						arF[i] = 2;
					}
				}
			}

			//if (rbP->noplanar) // получаем нормаль
			//{
			//	mdlVec_extractPolygonNormal(&rbP->nrm, 0, arPts, 3);
			//}

			getBarUnrotatedPoints(arPts, arPts, &rbP->v_enrm, rbP->numpts, 0, 0, NULL);
		}

		for (int i = 0; i < MAX_BAR_VERTICES; i++) arCPta[i] = arPts[i];
	}



	if (rbP->runmet == 2)
	{
		for (int i = 0; i < rbP->numpts; i++)
		{
			if (arF[i] == 1) // горизонтальный
				setSegmLength(arCPta, rbP->numpts, i, dVarSegmLen);
		}
	}

	if (rbP->runmet == 3)
	{
		for (int i = 0; i < rbP->numpts; i++)
		{
			if (arF[i] == 2) // верт
				setSegmLength(arCPta, rbP->numpts, i, dVarSegmLen);
		}
	}


	pEnd = arCPta[rbP->numpts - 1];

	mdlVec_subtractPointArray(arCPta, &pEnd, rbP->numpts);

	//reverse 
	//===============
	for (int i = 0; i < MAX_BAR_VERTICES; i++)
		arCPts[i] = arCPta[i];

	int j = rbP->numpts - 1;
	for (int i = 0; i < rbP->numpts; i++)
	{
		arCPta[i] = arCPts[j];
		j--;
	}
	//===============


	// arCPts =============== затем обычные (с начала)


	if (!bUseRealPts)
	{
		for (int i = 0; i < rbP->numpts; i++)
		{
			arCPts[i].x = rbP->apts[i].x;
			arCPts[i].y = rbP->apts[i].y;
			arCPts[i].z = rbP->apts[i].z;
		}
	}
	else
	{
		for (int i = 0; i < MAX_BAR_VERTICES; i++)
			arCPts[i] = arPts[i];
	}



	if (rbP->runmet == 2)
	{
		for (int i = 0; i < rbP->numpts; i++)
		{
			if (arF[i] == 1) // горизонтальный
				setSegmLength(arCPts, rbP->numpts, i, dVarSegmLen);
		}

	}

	if (rbP->runmet == 3)
	{
		for (int i = 0; i < rbP->numpts; i++)
		{
			if (arF[i] == 2) // горизонтальный
				setSegmLength(arCPts, rbP->numpts, i, dVarSegmLen);
		}

	}

	pBeg = arCPts[0];

	mdlVec_subtractPointArray(arCPts, &pBeg, rbP->numpts);
	//===============


	// rotate...

	// direction
	pBeg = arCPts[1];
	pEnd = arCPta[1];


	// angle
	double dang[2];
	dang[0] = mdlVec_angleXY(&pBeg);
	dang[1] = mdlVec_angleXY(&pEnd);



	for (int i = 0; i < rbP->numpts; i++)
	{
		mdlVec_rotateXYInPlace (&arCPts[i], -dang[0]);
	}

	for (int i = 0; i < rbP->numpts; i++)
	{
		mdlVec_rotateXYInPlace (&arCPta[i], -dang[1]);
	}




	for (int i = 0; i < rbP->numpts; i++)
	{
		rbP->cpxb[i].x = (int)roundex(arCPts[i].x);
		rbP->cpxb[i].y = (int)roundex(arCPts[i].y);
		rbP->cpxb[i].z = (int)roundex(arCPts[i].z);

		rbP->cpxe[i].x = (int)roundex(arCPta[i].x);
		rbP->cpxe[i].y = (int)roundex(arCPta[i].y);
		rbP->cpxe[i].z = (int)roundex(arCPta[i].z);
	}


}

///////////////////////////////////////////////
bool pointIsEqual(DVec3d* p1, DVec3d* p2, int bConvertToUors)
{

	return (coordIsEqual(p1->x, p2->x, bConvertToUors) &&
			coordIsEqual(p1->y, p2->y, bConvertToUors) &&
			coordIsEqual(p1->z, p2->z, bConvertToUors)
			);

}



///////////////////////////////////////////////
bool coordIsEqual(double v1, double v2, int bConvertToUors)
{
	double dTol = iCfgVar_ComparisonTol;

	if (bConvertToUors)
		dTol = mdlCnv_masterUnitsToUors(iCfgVar_ComparisonTol);

    double d = fabs(v1 - v2);
    
    if (!EQ(d, dTol) && d < dTol) 
		return true; 
	else 
		return false;

}


///////////////////////////////////////////////
bool coordIsEqual(int v1, int v2)
{
	//double dTol = mdlCnv_masterUnitsToUors(iCfgVar_ComparisonTol);

    int i = abs(v1 - v2);
    
    if (i < iCfgVar_ComparisonTol) 
		return true; 
	else 
		return false;

}

/////////////////////////////
int barsEqual(ReinBar* rbOneP, // from file
			  ReinBar* rbTwoP
			  )
{
	return barsEqual(rbOneP, rbTwoP, NULL);
}


//////////////////////////////////////////////////
int barsEqual(ReinBar* rbOneP, // from file
			  ReinBar* rbTwoP,
			  int* diroutP
			  )
{

	writeLogIn(__FUNCTION__, 0);

	int bGeomEq = FALSE;
	int bTermEq = FALSE;
	int bIsEq[8] = {0,0,0,0,0,0,0,0};
	long rfa_one_nrm[MAX_BAR_VERTICES];
	long rfa_one_alt[MAX_BAR_VERTICES];
	long rfa_two[MAX_BAR_VERTICES];

	for (int i = 0; i < MAX_BAR_VERTICES; i++)
	{
		rfa_one_nrm[i] = 0;
		rfa_one_alt[i] = 0;
		rfa_two[i] = 0;
	}


	//if (rbOneP->ffpos[REIN_ELEM_ISO] == 4002838 && rbTwoP->pnum == 123)
	//	int a = 0;

	//if (rbOneP->ffpos[REIN_ELEM_ISO] == 4001502 && rbTwoP->pnum == 123)
	//	int a = 0;



	if (rbOneP->ffpos[REIN_ELEM_ISO] == 4088402 && rbTwoP->pnum == 218)
	{
		int a = 0;
	}

	if (rbOneP->ffpos[REIN_ELEM_ISO] == 4802090)
	{
		if (rbTwoP->pnum == 861)
		{
			int a = 0;
		}
	}

					//if (rbTwoP->pnum == 149)
					//	__asm nop;

					//if (rbTwoP->pnum == 285)
					//	__asm nop;

	int bRet = TRUE;

	if (rbOneP->runmet != rbTwoP->runmet) bRet = FALSE;
	if (rbOneP->diam != rbTwoP->diam) bRet = FALSE;
	//if (rbOneP->poscalc != rbTwoP->poscalc) printf("%i %i\n", rbOneP->poscalc, rbTwoP->poscalc);
	if (rbOneP->poscalc != rbTwoP->poscalc) bRet = FALSE;
	if (rbOneP->noplanar != rbTwoP->noplanar) bRet = FALSE;

	if (rbOneP->cnumpts > 2 // fix: если на прямых стержнях разный радиус гиба - его не учитывать
		&& rbOneP->bendrad != rbTwoP->bendrad) bRet = FALSE;

	//if (rbOneP->noplanar
	//	//|| rbTwoP->noplanar
	//	) 
	//{
	//	return FALSE;
	//}

	//if (bPosSepByRefs)
	//{
	//	if (rbOneP->numRef != rbTwoP->numRef) bRet = FALSE;
	//}

	//if (rbOneP->runmet != 1) // not run met
	{
		if (rbOneP->cnumpts == 0 || rbTwoP->cnumpts == 0) bRet = FALSE;
		if (rbOneP->cnumpts != rbTwoP->cnumpts) bRet = FALSE;
	}

	if (bRet == FALSE)
	{
		writeLogOut(__FUNCTION__, "FALSE");
		return FALSE;
	}

	////' если по дуге
	//if (rbOneP->rad[0] > 0 && rbTwoP->rad[0] > 0)
	//{
	//	int isEq = FALSE;
	//    
	//	if (rbOneP->runmet)
	//	{
	//		if (rbOneP->rad[0] == rbTwoP->rad[0]) isEq = TRUE;
	//	}
	//	else
	//	{
	//		//if (rbOneP->rad[0] == rbTwoP->rad[0] && rbOneP->base_length == rbTwoP->base_length) isEq = TRUE;
	//		if (rbOneP->rad[0] == rbTwoP->rad[0] && coordIsEqual(rbOneP->length, rbTwoP->length)) isEq = TRUE;
	//	}
	//    
	//	if (isEq)
	//	{
	//		//Set Me.pointsDraw = New Collection
	//		//For I = 1 To br.pointsDraw.Count
	//		//    Me.pointsDraw.Add br.pointsDraw(I)
	//		//Next I
	//	}
	//    
	//	bGeomEq = isEq;
	//}
	////' если обычные элементы
	//else if (rbOneP->rad[0] == 0 && rbTwoP->rad[0] == 0)




	if (rbOneP->noplanar == 0)
	{

        if (rbOneP->cnumpts == 2 
			&& (rbOneP->runmet == 1
				//|| rbOneP->runmet == 2
			)) // rbOneP->cnumpts = 2 для прямого, rbOneP->cnumpts = 3 для арки
		{
			bGeomEq = TRUE;
		}
        else if (rbOneP->cnumpts == 3 
			&& (rbOneP->rfa[1] & RFA_ARCP || rbOneP->rfa[1] & RFA_CIRP) // if arcs 
			&& (rbTwoP->rfa[1] & RFA_ARCP || rbTwoP->rfa[1] & RFA_CIRP)
			&& rbOneP->runmet == 1)
		{
			if (coordIsEqual(rbOneP->cpxb[1].x, rbTwoP->cpxb[1].x))
				bGeomEq = TRUE;
		}
		else if (rbOneP->cnumpts == 3
			&& (rbOneP->rfa[1] & RFA_ARCP || rbOneP->rfa[1] & RFA_CIRP) // if arcs 
			&& (rbTwoP->rfa[1] & RFA_ARCP || rbTwoP->rfa[1] & RFA_CIRP)
			&& rbOneP->runmet == 0)
		{
			DPoint3d dp1[2];
			DPoint3d dp2[2];

			mdlCnv_IPointToDPointArray(dp1, rbOneP->cpxb, 2);
			mdlCnv_IPointToDPointArray(dp2, rbTwoP->cpxb, 2);

			long radi1 = roundExt(mdlVec_distance(&dp1[0], &dp1[1]), ROUND_LIN);
			long radi2 = roundExt(mdlVec_distance(&dp2[0], &dp2[1]), ROUND_LIN);

			long len1 = roundExt(rbOneP->length, ROUND_LIN);
			long len2 = roundExt(rbTwoP->length, ROUND_LIN);

			if (len1 == len2 && radi1 == radi2)
				bGeomEq = TRUE;
		}
		else
		{
            bIsEq[0] = TRUE;
            bIsEq[1] = TRUE;
            bIsEq[2] = TRUE;
            bIsEq[3] = TRUE;

            for (int i = 0; i < rbOneP->cnumpts; i++)
			{
				if (rbOneP->rfa[i] & RFA_ARCP || rbOneP->rfa[i] & RFA_CIRP) rfa_one_nrm[i] = RFA_ARCP;
			}

            for (int i = 0; i < rbTwoP->cnumpts; i++)
			{
				if (rbTwoP->rfa[i] & RFA_ARCP || rbTwoP->rfa[i] & RFA_CIRP) rfa_two[i] = RFA_ARCP;
			}

			int j = rbOneP->cnumpts - 1;
            for (int i = 0; i < rbOneP->cnumpts; i++)
			{
				if (rbOneP->rfa[i] & RFA_ARCP || rbOneP->rfa[i] & RFA_CIRP) rfa_one_alt[j] = RFA_ARCP;
				j--;
			}

			//===================== Y
            for (int i = 0; i < rbOneP->cnumpts; i++)
			{
                if (!(coordIsEqual(rbOneP->cpxb[i].x, rbTwoP->cpxb[i].x) 
					&& coordIsEqual(rbOneP->cpxb[i].y, rbTwoP->cpxb[i].y) 
					&& rfa_one_nrm[i] == rfa_two[i]))
				{
                    bIsEq[0] = FALSE;
                    break;
				}
			}

            for (int i = 0; i < rbOneP->cnumpts; i++)
			{
                if (!(coordIsEqual(rbOneP->cpxb[i].x, rbTwoP->cpxb[i].x) 
					&& coordIsEqual(rbOneP->cpxb[i].y, -rbTwoP->cpxb[i].y)
					&& rfa_one_nrm[i] == rfa_two[i]))
				{
                    bIsEq[1] = FALSE;
                    break;
				}
			}

            for (int i = 0; i < rbOneP->cnumpts; i++)
			{
                if (!(coordIsEqual(rbOneP->cpxe[i].x, rbTwoP->cpxb[i].x) 
					&& coordIsEqual(rbOneP->cpxe[i].y, rbTwoP->cpxb[i].y)
					&& rfa_one_alt[i] == rfa_two[i]))
				{
                    bIsEq[2] = FALSE;
                    break;
				}
			}

            for (int i = 0; i < rbOneP->cnumpts; i++)
			{
                if (!(coordIsEqual(rbOneP->cpxe[i].x, rbTwoP->cpxb[i].x) 
					&& coordIsEqual(rbOneP->cpxe[i].y, -rbTwoP->cpxb[i].y)
					&& rfa_one_alt[i] == rfa_two[i]))
				{
                    bIsEq[3] = FALSE;
                    break;
				}
			}

			if (diroutP && (bIsEq[0] || bIsEq[1])) *diroutP = 1;
			else if (diroutP && (bIsEq[2] || bIsEq[3])) *diroutP = -1;

            bGeomEq = bIsEq[0] | bIsEq[1] | bIsEq[2] | bIsEq[3];
        
		}

	}


	if (rbOneP->noplanar == 2)
	{

        bIsEq[0] = TRUE;
        bIsEq[1] = TRUE;

        for (int i = 0; i < rbOneP->cnumpts; i++)
		{
			if (rbOneP->rfa[i] & RFA_ARCP || rbOneP->rfa[i] & RFA_CIRP) rfa_one_nrm[i] = rbOneP->rfa[i];
		}

        for (int i = 0; i < rbTwoP->cnumpts; i++)
		{
			if (rbTwoP->rfa[i] & RFA_ARCP || rbTwoP->rfa[i] & RFA_CIRP) rfa_two[i] = rbOneP->rfa[i];
		}

		int j = rbOneP->cnumpts - 1;
        for (int i = 0; i < rbOneP->cnumpts; i++)
		{
			if (rbOneP->rfa[i] & RFA_ARCP || rbOneP->rfa[i] & RFA_CIRP) rfa_one_alt[j] = rbOneP->rfa[i];
			j--;
		}

		//===================== Y
        for (int i = 0; i < rbOneP->cnumpts; i++)
		{
            if (!(coordIsEqual(rbOneP->cpxb[i].x, rbTwoP->cpxb[i].x) 
				&& coordIsEqual(rbOneP->cpxb[i].y, rbTwoP->cpxb[i].y) 
				&& coordIsEqual(rbOneP->cpxb[i].z, rbTwoP->cpxb[i].z) 
				&& rfa_one_nrm[i] == rfa_two[i]))
			{
                bIsEq[0] = FALSE;
                break;
			}
		}


        for (int i = 0; i < rbOneP->cnumpts; i++)
		{
            if (!(coordIsEqual(rbOneP->cpxe[i].x, rbTwoP->cpxb[i].x) 
				&& coordIsEqual(rbOneP->cpxe[i].y, rbTwoP->cpxb[i].y)
				&& coordIsEqual(rbOneP->cpxe[i].z, rbTwoP->cpxb[i].z)
				&& rfa_one_alt[i] == rfa_two[i]))
			{
                bIsEq[1] = FALSE;
                break;
			}
		}

		if (diroutP && bIsEq[0]) *diroutP = 1;
		else if (diroutP && bIsEq[1]) *diroutP = -1;

        bGeomEq = bIsEq[0] | bIsEq[1];
        

	}



	bTermEq = TRUE;


	if (bGeomEq)
	{

					//if (rbTwoP->pnum == 149)
					//	__asm nop;
					//if (rbTwoP->pnum == 285)
					//	__asm nop;

		int iBeg[2];
		int iEnd[2];

		iBeg[0] = rbOneP->term[0];
		iBeg[1] = rbTwoP->term[0];

		iEnd[0] = rbOneP->term[1];
		iEnd[1] = rbTwoP->term[1];

        //' формируем значение для загиба
		if (rbOneP->term[0] == REIN_TERM_BEND) 
			iBeg[0] = rbOneP->term[0] | rbOneP->termPar[0][0]<<2 | rbOneP->termPar[1][0]<<4;
		if (rbTwoP->term[0] == REIN_TERM_BEND) 
			iBeg[1] = rbTwoP->term[0] | rbTwoP->termPar[0][0]<<2 | rbTwoP->termPar[1][0]<<4;
		if (rbOneP->term[1] == REIN_TERM_BEND) 
			iEnd[0] = rbOneP->term[1] | rbOneP->termPar[0][1]<<2 | rbOneP->termPar[1][1]<<4;
		if (rbTwoP->term[1] == REIN_TERM_BEND) 
			iEnd[1] = rbTwoP->term[1] | rbTwoP->termPar[0][1]<<2 | rbTwoP->termPar[1][1]<<4;

        //' допущение: резьбу с муфтой считаем как резьбу
		iBeg[0] = getTrueEnd(rbOneP, 0);
		iBeg[1] = getTrueEnd(rbTwoP, 0);
		iEnd[0] = getTrueEnd(rbOneP, 1);
		iEnd[1] = getTrueEnd(rbTwoP, 1);

        //' допущение: скобу/сварку не считаем, это просто обычный конец стержня
		iBeg[0] = getTrueEnd(rbOneP, 0);
		iBeg[1] = getTrueEnd(rbTwoP, 0);
		iEnd[0] = getTrueEnd(rbOneP, 1);
		iEnd[1] = getTrueEnd(rbTwoP, 1);
		iBeg[0] = getTrueEnd(rbOneP, 0);
		iBeg[1] = getTrueEnd(rbTwoP, 0);
		iEnd[0] = getTrueEnd(rbOneP, 1);
		iEnd[1] = getTrueEnd(rbTwoP, 1);

		if (rbOneP->runmet == 1 || rbOneP->cnumpts == 2) // если прямая (все равно как вертеть)
		{
			if ((iBeg[0] == iBeg[1] && iEnd[0] == iEnd[1]) || (iBeg[0] == iEnd[1] && iBeg[1] == iEnd[0]))
				bTermEq = TRUE;
			else
				bTermEq = FALSE;
		}
		else if ((bIsEq[0] == FALSE && bIsEq[1] == FALSE && (bIsEq[2] || bIsEq[3]))
			//|| (bIsEq[4] == FALSE && bIsEq[5] == FALSE && (bIsEq[6] || bIsEq[7]))
			) // если сработало одно из альтернативных сравнений
		{
			if (iBeg[0] != iEnd[1]) bTermEq = FALSE;
			if (iEnd[0] != iBeg[1]) bTermEq = FALSE;
		}
		else
		{
			if (iBeg[0] != iBeg[1]) bTermEq = FALSE;
			if (iEnd[0] != iEnd[1]) bTermEq = FALSE;
		}


//        If bRunMet Then
//            If (iBeg(0) = iBeg(1) And iEnd(0) = iEnd(1)) Or (iBeg(0) = iEnd(1) And iBeg(1) = iEnd(0)) Then
//                bTermEq = True
//            Else
//                bTermEq = False
//            End If
//        ElseIf bIsEq(1) = False And bIsEq(2) = False And (bIsEq(3) Or bIsEq(4)) Then
//            If iBeg(0) <> iEnd(1) Then bTermEq = False
//            If iBeg(0) <> iEnd(1) Then bTermEq = False
//        Else
//            If iBeg(0) <> iBeg(1) Then bTermEq = False
//            If iEnd(0) <> iEnd(1) Then bTermEq = False
//        End If

	}




	if (iDebug)
	{
		if (!bGeomEq)
		{

			for (int i = 0; i < rbOneP->cnumpts; i++)
			{
				sprintf(sLogMes, "%i x b%i e%i - b%i\n", i, rbOneP->cpxb[i].x, rbOneP->cpxe[i].x, rbTwoP->cpxb[i].x); writeLog(0, 0, 0, 1);
				sprintf(sLogMes, "%i y b%i e%i - b%i\n", i, rbOneP->cpxb[i].y, rbOneP->cpxe[i].y, rbTwoP->cpxb[i].y); writeLog(0, 0, 0, 1);
				sprintf(sLogMes, "%i z b%i e%i - b%i\n", i, rbOneP->cpxb[i].z, rbOneP->cpxe[i].z, rbTwoP->cpxb[i].z); writeLog(0, 0, 0, 1);
			}

		}

		sprintf(sLogMes, "bTermEq = %i  bGeomEq = %i\n", bTermEq, bGeomEq); writeLog(0, 0, 0, 1);
	}

	writeLogOut(__FUNCTION__, 0);


	return bTermEq & bGeomEq;

}

//////////////////////////////////////
int getTrueEnd(ReinBar* rbP, int ind)
{
	if (rbP == NULL) return REIN_TERM_NONE;

    //' допущение: резьбу с муфтой считаем как резьбу 
	if (rbP->term[ind] == REIN_TERM_MUFT && rbP->termPar[2][ind] == 3) // за исключением обжимных (3)
		return REIN_TERM_NONE;
	else if (rbP->term[ind] == REIN_TERM_MUFT) 
		return REIN_TERM_REZB;

    //' допущение: скобу/сварку не считаем, это просто обычный конец стержня
	if (rbP->term[ind] == REIN_TERM_SKOB) return REIN_TERM_NONE;
	if (rbP->term[ind] == REIN_TERM_SVAR) return REIN_TERM_NONE;

	return rbP->term[ind];
}

/*

///////////////////////////
int getTrueEnd(int iend)
{
    //' допущение: резьбу с муфтой считаем как резьбу
	if (iend == REIN_TERM_MUFT) return REIN_TERM_REZB;

    //' допущение: скобу/сварку не считаем, это просто обычный конец стержня
	if (iend == REIN_TERM_SKOB) return REIN_TERM_NONE;
	if (iend == REIN_TERM_SVAR) return REIN_TERM_NONE;

	return iend;
}

///////////////////////////////////////
int iterateForExclusivePos(
MSElementDescr  *edP,
int*        iShowP,
ScanCriteria    *pScanCriteria
)
{
	ReinElm relm;
	ReinPos* rpP = NULL;

	if (readReinElmIso(&relm, edP, TRUE, FALSE) == SUCCESS)
	{

		if (barsEqual(&relm.bel, &curPos.bar))
		{

			CatInfo ci;

			getCatInfo(&ci, edP->h.dgnModelRef, false);

			//if (curPos.pcatID == ci.catModID)
			{
				if (*iShowP == 1) // не отобр. поз
				{
					arID[iIDcount] = relm.bel.elemid;
					iIDcount++;
					arFP[iFPcount] = mdlElmdscr_getFilePos(edP);
					iFPcount++;
				}
				else if (*iShowP == 0) // отобр поз.
				{
					for (UInt32 i = 0; i < iIDcount; i++)
					{
						if (arID[i] == relm.bel.elemid) arID[i] = 0;
					}
					for (UInt32 i = 0; i < iFPcount; i++)
					{
						if (arFP[i] == mdlElmdscr_getFilePos(edP)) arFP[i] = 0;
					}
				}
			}

		}
	}

	int bFound = FALSE;

	for (UInt32 i = 0; i < iFPcount; i++)
	{
		if (arFP[i] > 0) 
		{
			bFound = TRUE;
			break;
		}
	}

	if (bFound == FALSE) iFPcount = 0;

	bFound = FALSE;

	for (UInt32 i = 0; i < iIDcount; i++)
	{
		if (arID[i] > 0) 
		{
			bFound = TRUE;
			break;
		}
	}

	if (bFound == FALSE) iIDcount = 0;




	return SUCCESS;
}
*/




////////////////////////////////////
// 
int iterateFindReinElm(
MSElementDescr  *edP,
ReinBar*        barP,
ScanCriteria    *pScanCriteria
)
{
	ReinElm relm;


	if (readReinElmIso(&relm, edP, TRUE, TRUE) == SUCCESS)
	{
		if (relm.bel.elemid == barP->elemid && edP->h.dgnModelRef == barP->modrefP)
		{
			curPos.clear();
			curPos.bar = relm.bel;
			rbFoundP = &(curPos.bar);
			elemCount++;
			//return 1;
		}
	}
	

	return 0;

}


////////////////////////////////////
int iterateSelectPos(
MSElementDescr  *edP,
void*        prm,
ScanCriteria    *pScanCriteria
)
{

	ReinElm relm;

	UInt32 fp = mdlElmdscr_getFilePos(edP);

	if (readReinElmIso(&relm, edP, TRUE, TRUE) == SUCCESS)
	{
		if (barsEqual(&relm.bel, &curPos.bar))
		{
			//mdlLocate_hiliteElement(edP->h.elementRef, edP->h.dgnModelRef);

			ELREF eref = getElemRefByID(edP->h.dgnModelRef, relm.bel.elemid);
			if (eref)
			{
				UInt32 fpos = elementRef_getFilePos(eref);

				if (!mdlSelect_isElementSelected(fpos, edP->h.dgnModelRef))
					mdlSelect_addElement(fpos, edP->h.dgnModelRef
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
						, 0, TRUE
#endif
					);
			}
		}
	}


	return SUCCESS;
}

////////////////////////////////////
int iterateHilitePos(
MSElementDescr  *edP,
CatInfo*        ciP,
ScanCriteria    *pScanCriteria
)
{
	ReinElm relm;
	ReinPos* rpP = NULL;

	if (readReinElmIso(&relm, edP, TRUE, TRUE) == SUCCESS)
	{

		if (mdlModelRef_isActiveModel(edP->h.dgnModelRef) == FALSE)
		{
			CLIPDESC clipP;
			MSElementDescr* edpOnce = NULL;
			MSElementDescr* edpClip = NULL;
			BINT bOverLap;
			BINT bInside = TRUE;
			int view = 0;
			Transform tm;

			//int r = func_pma(mdlClip_getRefBoundary,clipP), edP->h.dgnModelRef, view);
			int r = myClip_getRefBoundary(&clipP, edP->h.dgnModelRef, &edpClip, view);


			if (r == SUCCESS && NOTNULL(clipP))
			{
				mdlElmdscr_duplicate(&edpOnce, edP);

				mdlTMatrix_referenceToMaster (&tm, edP->h.dgnModelRef); // scale!

				func_amp(mdlElmdscr_transform,edpOnce), &tm);

				bInside = mdlClip_isElemInside(&bOverLap, edpOnce, GETPTR(clipP), view, true);

				mdlElmdscr_freeAll(&edpOnce);

				myClip_free(clipP, &edpClip);

			}


			if (bInside == FALSE) return SUCCESS;

		}


		//barCalcComparePoints(&relm.bel);

		if (barsEqual(&relm.bel, &curPos.bar)
			//&& ciP->catModID == curPos.pcatID
			)
		{
			mdlLocate_hiliteElement(edP->h.elementRef, edP->h.dgnModelRef);
		}
	}

	return SUCCESS;

}



/////////////////////////////////
int scanMuftCountExt(
MSElementDescr  *edDstP,
ReinVert  *rvP, // та муфта или скоба, для которой нужно определить - переходная она или нет
ScanCriteria    *pScanCriteria					
)
{

	ReinElm relm;
	DVec3d ppts[2];
	DVec3d pdts[2];
	double dan[2];

	double dTol = mdlCnv_masterUnitsToUors(iCfgVar_MuftTol);

	if (relm.getElmFromElement(&edDstP->el, mdlScanCriteria_getModel(pScanCriteria)) == SUCCESS)
	{

		mdlElmdscr_extractEndPoints (&ppts[0], &pdts[0], &ppts[1], &pdts[1], edDstP, ACTIVEMODEL);

		elemIterCount2++;

		tbi.percentComplete2 = (long)(((double)elemIterCount2 / (double)elemCount2) * 100.);
		//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
		//if (dlgProgressP) mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)tbi.percentComplete2);
		//WaitMessage();

		if (rvP->fps == mdlElmdscr_getFilePos(edDstP) &&
			rvP->mrp == edDstP->h.dgnModelRef
			) 
			return 0; // пропускаем того, на которого ищем

		if (rvP->isin == REIN_TERM_NONE) return 0; // дублирующаяся скоба (см. ниже)
		if (rvP->mblap) return 0; // при перехлесте нет переходной муфты


		if (mdlModelRef_isActiveModel(edDstP->h.dgnModelRef) == FALSE)
		{
			Transform tm;
			mdlTMatrix_referenceToMaster(&tm, edDstP->h.dgnModelRef); // scale?
			mdlTMatrix_transformPointArray(ppts, &tm, 2);

			RotMatrix rm;
			mdlRMatrix_fromTMatrix(&rm, &tm); // scale?

			mdlRMatrix_multiplyPointArray(pdts, &rm, 2);
		}

		dan[0] = mdlVec_angleBetweenVectors(&pdts[0], &rvP->rvv.tdir);
		dan[1] = mdlVec_angleBetweenVectors(&pdts[1], &rvP->rvv.tdir);


		//double dOtn = (double)relm.bel.diam / (double)rvP->mdiam[0];
		//if (dOtn > 1.) dOtn = (double)rvP->mdiam[0] / (double)relm.bel.diam;

		//==========================================

		if (rvP->isin == REIN_TERM_MUFT && relm.bel.term[0] == REIN_TERM_REZB &&
			mdlVec_equalTolerance(&rvP->torg, &ppts[0], dTol))
		{
			if (EQQ(dan[0], fc_pi, 0.01)) // направление противоположное
			{
				if (rvP->mdiam[1] != relm.bel.diam) rvP->pmqty++; // продублировано
				rvP->mdiam[1] = relm.bel.diam;
			}
			else
				rvP->errors++;

		}

		if (rvP->isin == REIN_TERM_MUFT && relm.bel.term[1] == REIN_TERM_REZB &&
			mdlVec_equalTolerance(&rvP->torg, &ppts[1], dTol))// направление еще!
		{
			if (EQQ(dan[1], fc_pi, 0.01)) // направление противоположное
			{
				if (rvP->mdiam[1] != relm.bel.diam) rvP->pmqty++;
				rvP->mdiam[1] = relm.bel.diam;
			}
			else
				rvP->errors++;
		}

		//==========================================

		if (rvP->isin == REIN_TERM_SKOB && (relm.bel.term[0] == REIN_TERM_SVAR || relm.bel.term[0] == REIN_TERM_SKOB) &&
			mdlVec_equalTolerance(&rvP->torg, &ppts[0], dTol))
		{
			if (EQQ(dan[0], fc_pi, 0.01)) // направление противоположное
			{
				if (rvP->mdiam[1] != relm.bel.diam) rvP->pmqty++;
				rvP->mdiam[1] = relm.bel.diam;
			}
			else
				rvP->errors++;
		}

		if (rvP->isin == REIN_TERM_SKOB && (relm.bel.term[1] == REIN_TERM_SVAR || relm.bel.term[1] == REIN_TERM_SKOB) &&
			mdlVec_equalTolerance(&rvP->torg, &ppts[1], dTol))
		{
			if (EQQ(dan[1], fc_pi, 0.01)) // направление противоположное
			{
				if (rvP->mdiam[1] != relm.bel.diam) rvP->pmqty++;
				rvP->mdiam[1] = relm.bel.diam;
			}
			else
				rvP->errors++;
		}

		//==========================================
		


	}

	return 0;

}



/////////////////////////////////
int scanMuftInArray(
MSElementDescr  *edP,
long            *elemCountP,
ScanCriteria    *pScanCriteria					
)
{
	ReinElm relm;

	//ModelRefIteratorP  iterator;
	//DgnModelRefP	modelRef;
	



	if (readReinElmIso(&relm, edP, FALSE, FALSE) == SUCCESS) 
	{
		rvMuftScan[0].clear();
		rvMuftScan[1].clear();

		mdlElmdscr_extractEndPoints (&rvMuftScan[0].torg, 
									&rvMuftScan[0].rvv.tdir, 
									&rvMuftScan[1].torg, 
									&rvMuftScan[1].rvv.tdir, 
									edP, ACTIVEMODEL);

		rvMuftScan[0].mdiam[0] = relm.bel.diam;
		rvMuftScan[0].mdiam[1] = relm.bel.diam;
		rvMuftScan[0].isin = relm.bel.term[0];
		rvMuftScan[0].mpar = relm.bel.termPar[2][0];
		rvMuftScan[0].fps = mdlElmdscr_getFilePos(edP);
		rvMuftScan[0].mrp = edP->h.dgnModelRef;

		rvMuftScan[1].mdiam[0] = relm.bel.diam;
		rvMuftScan[1].mdiam[1] = relm.bel.diam;
		rvMuftScan[1].isin = relm.bel.term[1];
		rvMuftScan[1].mpar = relm.bel.termPar[2][1];
		rvMuftScan[1].fps = mdlElmdscr_getFilePos(edP);
		rvMuftScan[1].mrp = edP->h.dgnModelRef;


		if (mdlModelRef_isActiveModel(edP->h.dgnModelRef) == FALSE)
		{
			Transform tm;
			RotMatrix rm;
			mdlTMatrix_referenceToMaster(&tm, edP->h.dgnModelRef); // scale?
			mdlTMatrix_transformPoint(&rvMuftScan[0].torg, &tm);
			mdlTMatrix_transformPoint(&rvMuftScan[1].torg, &tm);
			mdlRMatrix_fromTMatrix(&rm, &tm); // scale?
			mdlRMatrix_multiplyPoint(&rvMuftScan[0].rvv.tdir, &rm);
			mdlRMatrix_multiplyPoint(&rvMuftScan[1].rvv.tdir, &rm);
		}



		// check start points
		if (relm.bel.term[0] == REIN_TERM_MUFT || relm.bel.term[0] == REIN_TERM_SKOB)
		{
			ReinVert* rvP = &daMufts[elemCount];
			elemCount++;

			*rvP = rvMuftScan[0];
		}



		// check end points
		if (relm.bel.term[1] == REIN_TERM_MUFT || relm.bel.term[1] == REIN_TERM_SKOB)
		{
			ReinVert* rvP = &daMufts[elemCount];
			elemCount++;

			*rvP = rvMuftScan[1];

		}


		//elemIterCount++;

		//tbi.percentComplete1 = (long)(((double)elemIterCount / (double)elemCount) * 100.);
		//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
		//WaitMessage();

		ReinLap* rlP = getReinLap(relm.bel.diam);

		if (rlP && rlP->muft)
		{
			//MSBsplineCurve crv;
			
			double param;

			int dopqty = 0;
			dopqty = (int)floor((relm.bel.length - iCfgVar_MuftTol) / rlP->maxlen); // 11700.1


			if (mdlBspline_convertToCurve(&crv, edP) == SUCCESS)
			{

				for (int i = 1; i <= dopqty; i++)
				{
					ReinVert rv;

					rv.clear();
					
					rv.mdiam[0] = relm.bel.diam;
					rv.mdiam[1] = relm.bel.diam;
					rv.isin = REIN_TERM_MUFT;
					rv.mpar = iCfgVar_MuftLapType;
					rv.fps = mdlElmdscr_getFilePos(edP);
					rv.mrp = edP->h.dgnModelRef;
					rv.mblap = TRUE; // муфта по превышению длины

					param = (1.0 / (double)(dopqty + 1)) * i;

					mdlBspline_evaluateCurvePoint(&rv.torg, &rv.rvv.tdir, &crv, param);

					if (mdlModelRef_isActiveModel(edP->h.dgnModelRef) == FALSE)
					{
						Transform tm;
						RotMatrix rm;
						mdlTMatrix_referenceToMaster(&tm, edP->h.dgnModelRef); // scale?
						mdlTMatrix_transformPoint(&rv.torg, &tm);
						mdlRMatrix_fromTMatrix(&rm, &tm); // scale?
						mdlRMatrix_multiplyPoint(&rv.rvv.tdir, &rm);
					}

					ReinVert* rvP = &daMufts[elemCount];
					elemCount++;

					*rvP = rv;
				}
			}
		}
	}


	return SUCCESS;

}

///////////////////////////////////
//int checkBarPoints(ReinBar* rbP, ReinBar* rbSrc) // проверка на вершины в одной точке
//{
//	return checkBarPoints(rbP->rpts, rbP->cents, rbP->rfa, rbP->numpts, rbSrc);
//	//return checkBarPoints(rbP->rpts, rbP->cents, rbP->rfa, rbSrc);
//}

/*
///////////////////////////////////
int checkBarPoints(ReinBar* rbP, int bBends) // проверка на вершины в одной точке
{
	return checkBarPoints(rbP->rpts, rbP->cents, rbP->rfa, rbP->numpts, rbP, bBends);
	//return checkBarPoints(rbP->rpts, rbP->cents, rbP->rfa, rbP);
}

///////////////////////////////////////
int checkBarPoints(DVec3d* arPtsP, DVec3d* arCntP, long* arF, int cnt, ReinBar* rbSrc, int bBends) // проверка на вершины в одной точке
//int checkBarPoints(vector<DVec3d> &arPtsP, vector<DVec3d> &arCntP, vector<long> &arF, ReinBar* rbSrc) // проверка на вершины в одной точке
{


	//printf("======\n");

	int i;

	//size_t cnt = arPtsP.size();
	//size_t cntt = cnt;

	//if (cnt < 3) return cnt;

	vector<BarPoint> vPts(cnt);

	for (i = 0; i < cnt; i++)
	{
		vPts[i].pVrtx = arPtsP[i];
		if (arCntP) vPts[i].pArcCent = arCntP[i];
		if (arF) vPts[i].flg = arF[i]; else vPts[i].flg = 0;
		//vPts[i].pArcCent = arCntP[i];
		//vPts[i].flg = arF[i];
	}

	// уборка маленьких расстояний

	for (i = 0; i < vPts.size() - 1 && vPts.size() > 2;)
	{
		BarPoint* vP = &vPts[i];
		BarPoint* vPn = &vPts[i + 1];

		double dst = mdlCnv_uorsToMasterUnits(mdlVec_distance(&(vP->pVrtx), &(vPn->pVrtx)));

		if (dst < (double)iCfgVar_MinSegment)
		{
			vPts.erase(vPts.begin() + i + 1); // delete second point
		}
		else
		{
			i++;
		}

	}



	cnt = (int)vPts.size();

	// точки сложного дугового стержня

	//vector<BarPoint>::iterator vItP = vPts.begin();

	i = 0;


	//while (rbSrc && vItP < vPts.end() - 1)
	for (int a = 0; rbSrc && a < vPts.size() - 1;)
	{
		BarPoint* vP = &vPts[a];

		if (vP->flg & RFA_ARCB) // арка
		{
			if (rbSrc->noplanar == 0) // на плоских доп. точка не нужна
			{
				vPts.erase(vPts.begin() + a);
			}
			else
			{
				if ((a == 1) // arc start is clear
					|| (a == vPts.size() - 2)) // arc end is clear
				{
					vPts.erase(vPts.begin() + a);
				}
				else
				{
					a++;
				}
			}


			//DVec3d pNrm, pCnt;
			//DVec3d p[3];
			//BarPoint* vPn = vItP._Myptr;
			//BarPoint* vPp = vItP._Myptr;

			//vPp--;
			//vPn++;
			
			//p[0] = vPp->pVrtx;
			//p[1] = vP->pArcCent;
			//p[2] = vPn->pVrtx;

			//mdlVec_extractPolygonNormal(&pNrm, &pCnt, p, 3);
		}
		else
		{
			a++;
		}
	}

	// 
	if (iCfgVar_BendNewDraw == 2 && bBends)
	{
		if (rbSrc->axid == 0 // только для несозданных элементов
			&& rbSrc->term[0] == REIN_TERM_BEND)
		{
			// взамен Src->v_enrm
			// добавляем точку в начало arPtsP, rfa, cnt++

			//vPts.front() // first element in the vector
			//mdlProject_perpendicular

			if (vPts.size() > 2)
				vPts[0].pElPoint = vPts[2].pVrtx;

			//findReinElmsAroundPoint(&(vPts.front())); // <- rbSrc->pElPoint

			rbSrc->bent[0] = vPts.front();
			//rbSrc->bent[0].pVrtx = vPts[0].pVrtx; // уже есть
			rbSrc->bent[0].pVrtxNext = vPts[1].pVrtx;
			rbSrc->bent[0].bend_ang = rbSrc->termPar[0][0];
			rbSrc->bent[0].bend_len = rbSrc->termPar[1][0];
			if (rbSrc->bent[0].bend_len == 0) rbSrc->bent[0].bend_len = rbSrc->diam * 6; // ?

			//if (rbSrc->bent[0].bnd) ... если поймал элемент
			//bent[0].calcBend(diam);

			// вставку точек перенести в reinCreateComplexBarAxis2
			BarPoint bp;
			bp.pVrtx = rbSrc->bent[0].pArcPts[0];
			bp.flg = RFA_ARCP;
			vPts.insert(vPts.begin(), bp);
			bp.pVrtx = rbSrc->bent[0].pArcPts[1];
			bp.flg = 0;
			vPts.insert(vPts.begin(), bp);
			bp.pVrtx = rbSrc->bent[0].pEndPoint;
			bp.flg = 0;
			vPts.insert(vPts.begin(), bp);
		}
		if (rbSrc->axid == 0  // только для несозданных элементов
			&& rbSrc->term[1] == REIN_TERM_BEND)
		{
			// добавляем точку в конец  arPtsP, rfa, cnt++
			// ...
			//vPts.back() // last element in the vector

			if (vPts.size() > 2)
				vPts[vPts.size()-1].pElPoint = vPts[vPts.size()-3].pVrtx;

			//findReinElmsAroundPoint(&(vPts.back())); // <- rbSrc->pElPoint

			rbSrc->bent[1] = vPts.back();
			//rbSrc->bent[1].pVrtx = vPts[vPts.size() - 1].pVrtx; // уже есть
			rbSrc->bent[1].pVrtxNext = vPts[vPts.size() - 2].pVrtx;
			rbSrc->bent[1].bend_ang = rbSrc->termPar[0][1];
			rbSrc->bent[1].bend_len = rbSrc->termPar[1][1];
			if (rbSrc->bent[1].bend_len == 0) rbSrc->bent[1].bend_len = rbSrc->diam * 6;

			//if (rbSrc->bent[1].bnd) ... если поймал элемент
			//bent[1].calcBend(diam);

			//rbSrc->termPar[0][1] // угол - 90,135,180, м.б. со знаком
			//rbSrc->termPar[1][1] // длина загиба

			//добавляем точки для построения дуги+линии в bent
			//...

			BarPoint bp;
			bp.pVrtx = rbSrc->bent[1].pArcPts[0];
			bp.flg = RFA_ARCP;
			vPts.push_back(bp);
			bp.pVrtx = rbSrc->bent[1].pArcPts[1];
			bp.flg = 0;
			vPts.push_back(bp);
			bp.pVrtx = rbSrc->bent[1].pEndPoint;
			bp.flg = 0;
			vPts.push_back(bp);
		}
	}


	cnt = (int)vPts.size();

	for (i = 0; i < cnt; i++)
	{
		arPtsP[i] = vPts[i].pVrtx;
		if (arCntP) arCntP[i] = vPts[i].pArcCent;
		if (arF) arF[i] = vPts[i].flg;
	}


	//if (cntt > cnt)
	//{
	//	arPtsP.clear();
	//	arCntP.clear();
	//	arF.clear();
	//	for (i = 0; i < cnt; i++)
	//	{
	//		arPtsP.push_back(vPts[i].pVrtx);
	//		arCntP.push_back(vPts[i].pArcCent);
	//		arF.push_back(vPts[i].flg);
	//		//arPtsP[i] = vPts[i].pVrtx;
	//		//arCntP[i] = vPts[i].pArcCent;
	//		//arF[i] = vPts[i].flg;
	//	}
	//	cntt = cnt;
	//}


	//printf("%i  %i\n", cnt, vPts.size());


	return cnt;
	//return cntt;
}

*/

///////////////////
int elmFunc    ( // NU (bars in cells)
    MSElement       *element,     //=> element to act upon 
    int            *params,      //=> passed from original call 
    int             operation,    //=> why you were called 
    UInt32           offset,       //=> offset from header 
    MSElementDescr  *elemDscrP    //=> element descr 
    )
{

	iterateReloadBarsData(elemDscrP, params, 0); // use pIterScanCrit

	return SUCCESS;

}


///////////////////////////////////////////////////////////////////////////////////
void getCatInfo(CatInfo* ciP, DgnModelRefP mrP, BINT bSetTitle, bool bCheckDB, bool bSetParent)
{
	ScanCriteria    *pScanCriteria;
	int status;
	int bDelete = FALSE;
	int pwprojID = 0;

	if (ciP == NULL) return;

	writeLogIn(__FUNCTION__, 0);

	ciP->clear();

	//EMBDB_PROJECT_ID
	WCH v[500];
	if (getCfgVarEx(v, L"EMBDB_PROJECT_ID") == SUCCESS)
		pwprojID = STOI(v);

	if (iDebug) sprintf(sLogMes, "pwprojID = %i (EMBDB_PROJECT_ID)\n", pwprojID); writeLog(0, 0, 0, 1);

	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckCatInfo, ciP);
	status = mdlScanCriteria_setModel (pScanCriteria, mrP);
#if defined (MSVERSION) && (MSVERSION == 0xa00)
	mdlScanCriteria_setModelSections(pScanCriteria, DgnModelSections::Dictionary);
#else
	mdlScanCriteria_setElementCategory (pScanCriteria, ELEMENT_CATEGORY_NONMODEL);
#endif
	status = mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeCatInfo);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	MSWCH   wtxt[MAX_MODEL_NAME_LENGTH];
	WCH      ctxt[MAX_MODEL_NAME_LENGTH];
	mdlModelRef_getModelName(ACTIVEMODEL, wtxt);
	SCPW2M(ctxt, wtxt, MAX_MODEL_NAME_LENGTH);

	ciP->catModID = ciP->catID; // default
	SCPY(ciP->catmodname, ctxt);



	if (pwprojID > 0) 
	//if (ciP->projID == 0 && pwprojID > 0) 
	{
		ciP->projID = pwprojID;
	}

	// подмодели (каркасы)
	if (ciP->catID > 0 && bCheckDB &&
		(
			mdlModelRef_isDefault(ACTIVEMODEL) == FALSE // for cages
			|| (iCfgVar_PosListMerge && bSetParent)
		)
		)
	{
		WCH  sql[1000];

		CursorID ci;
		MS_sqlda    sqlda;


		if (iCfgVar_PosListMerge && bSetParent)
		{
			// get parent catalog
			SPRN(sql, L("select objectID from view_object_catalog where objID = 7 and catID = %u and deleted = 0"), ciP->catID);
		}
		else
		{
			// get catalog of cage by name and id
			SPRN(sql, L("select catID from view_object_catalog where catName = '%s' and objID = 7 and objectID = %u and deleted = 0"), ctxt, ciP->catID);
		}

		connectDB();

		int res = mdlDB_openCursorWithID (&ci, sql);


		if (res == SUCCESS)
		{
			while (mdlDB_fetchRowByID  (&sqlda, ci) != QUERY_FINISHED)
			{

				if (iCfgVar_PosListMerge)
				{
					ciP->catModID = ciP->catID; // catModID use for save positions
					ciP->catID = STOUL(sqlda.value[0], 0, 0); // use parent for manipulating
				}
				else
					ciP->catModID = STOUL(sqlda.value[0], 0, 0);
			}

			mdlDB_closeCursorByID (ci);
			mdlDB_freeSQLDADescriptor (&sqlda);

		}
	}


	//MSWindow* wP = mdlWindow_viewWindowGet(0);
	//if (bUpdateWindowTitle && wP)
	//{
	//	char 	strTitle[2000];
	//	mdlWindow_titleGet (strTitle, sizeof (strTitle), wP);
	//	strcpy(strTitle, ciP->catfullname);
	//	mdlWindow_titleSet (wP, strTitle);
	//}

	if (bSetTitle && iModelType) 
	{

		WCH  sql[1000];

		CursorID ci;
		MS_sqlda    sqlda;



		SPRN(sql, L("select dbo.getPath2(7,%u,0)"), ciP->catID);

		connectDB();

		int res = mdlDB_openCursorWithID (&ci, sql);


		if (res == SUCCESS)
		{
			while (mdlDB_fetchRowByID  (&sqlda, ci) != QUERY_FINISHED)
			{
				SCNPY(ciP->catfullname, sqlda.value[0], 1000);
				break;
			}

			mdlDB_closeCursorByID (ci);
			mdlDB_freeSQLDADescriptor (&sqlda);

		}



		//g_oViewMonitor.SetViewSuffix (0, ciP);
	}



	if (iDebug) sprintf(sLogMes, "projID = %u, catID = %u\n", ciP->projID, ciP->catID); writeLog(0, 0, 0, 1);


	writeLogOut(__FUNCTION__, 0);



}

///////////////////////////////////////////////////////////////////////////////////
//void getCatInfo(CatInfo* ciP, DgnModelRefP mrP, BINT bSetTitle)
//{
//	getCatInfo(ciP, mrP, bSetTitle
//		, false // каркасы временно отключены
//	);
//}


///////////////////////////////////////////////////////////////////////////////////
void saveCatInfo(DgnModelRefP mrInP)
{
	ScanCriteria    *pScanCriteria;
	MSElementDescr* pXmlFragmentElement = NULL; 
	int status;
	XMLFragmentListP pCurrent = NULL; 
	MSWCH wstr[1500];
	//WCH str[1500];


	writeLogIn(__FUNCTION__, 0);

	DgnModelRefP mrP = mrInP;
	if (mrP == NULL) mrP = ACTIVEMODEL;

	// delete all prev. xml elements
	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanJustDeleteElement, NULL);
	status = mdlScanCriteria_setModel (pScanCriteria, mrP);
	mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeCatInfo);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);


	_swprintf(wstr, L"%s|%u|%u|%s|%s|%i", 
				curCat.dbase, 
				curCat.projID, 
				curCat.catID, 
				curCat.catname, 
				curCat.catfullname, 
				curCat.bAutoCats
				);

	//SCPM2W(wstr, str, 1500);


	pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeCatInfo); 

	// create new one
	status = mdlXMLFragmentList_createXMLElementDescriptor  (&pXmlFragmentElement, &pCurrent, TRUE); 

	


	if (NULL != pXmlFragmentElement) 
	{ 
		UInt32 fp;

		if (iDebug) sprintf(sLogMes, ">>> add xml fragment to file...\n"); writeLog(0, 0);

		mdlXMLElement_setNonModelCategory (pXmlFragmentElement, curCat.bAutoCats);

		fp = mdlElmdscr_addByModelRef (pXmlFragmentElement, mrP); 
		mdlElmdscr_freeAll (&pXmlFragmentElement); 

		//g_oViewMonitor.SetViewSuffix (0, &curCat);


	} 

	writeLogOut(__FUNCTION__, 0);

}

///////////////////////
void deleteHidePosInfo(ReinPos* rpP)
{

	ScanCriteria    *pScanCriteria;
	MSElementDescr* pXmlFragmentElement = NULL; 
	int status;
	XMLFragmentListP pCurrent = NULL; 

	writeLogIn(__FUNCTION__, 0);


	// delete all prev. xml elements
	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanDeleteHidePos, rpP);
	status = mdlScanCriteria_setModel (pScanCriteria, MASTERFILE);
	mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeHidePos);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	writeLogOut(__FUNCTION__, 0);

}

///////////////////////
void deleteBarSetInfo(ReinPos* rpP, int bAllPosForRef, int bRemoveFromMap)
{

	writeLogIn(__FUNCTION__, 0);

	ScanCriteria    *pScanCriteria;
	MSElementDescr* pXmlFragmentElement = NULL; 
	int status;
	XMLFragmentListP pCurrent = NULL; 

	ReinPrm prm;
	
	prm.rpP = rpP;
	prm.ival[0] = bAllPosForRef;
	prm.ival[1] = bRemoveFromMap;

	// delete all prev. xml elements
	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanDeleteBarSet, &prm);
	status = mdlScanCriteria_setModel (pScanCriteria, MASTERFILE);
	mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeBarSet);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	writeLogOut(__FUNCTION__, 0);

}


///////////////////////////////////////////////////////////////////////////////////
void saveHidePosInfo(ReinPos* rpP)
{
	MSElementDescr* pXmlFragmentElement = NULL; 
	int status;
	XMLFragmentListP pCurrent = NULL; 
	MSWCH wstr[1500];
	//char str[1500];

	if (rpP == NULL) return;

	// предварительно удаляем
	deleteHidePosInfo(rpP);

	if (rpP->drawopt[DROPT_A] == FALSE &&
		rpP->drawopt[DROPT_V] == FALSE &&
		rpP->drawopt[DROPT_X] == FALSE &&
		rpP->drawopt[DROPT_O] == FALSE &&
		rpP->drawopt[DROPT_S] == FALSE)
	{
		// go to reload
	}
	else
	{
		writeLogIn(__FUNCTION__, 0);

		_swprintf(wstr, L"%i|%i|%s|%i|%i|%i|%i|%i", 
					rpP->bar.pnum, 
					curPos_rn,
					curPos_refpath.c_str(), // -curPos_rnn, // < 0 чтобы отличать от curPos.pcatID, кот. мог быть раньше
					rpP->drawopt[DROPT_A],
					rpP->drawopt[DROPT_V],
					rpP->drawopt[DROPT_X],
					rpP->drawopt[DROPT_O],
					rpP->drawopt[DROPT_S]
					);

		//status = mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 1500);


		pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeHidePos); 

		// create new one
		status = mdlXMLFragmentList_createXMLElementDescriptor  (&pXmlFragmentElement, &pCurrent, TRUE); 


		if (NULL != pXmlFragmentElement) 
		{ 
			UInt32 fp;

			if (iDebug) sprintf(sLogMes,"     add xml fragment to file...\n"); writeLog(0, 0, 0, 1);

			//mdlXMLElement_setNonModelCategory (pXmlFragmentElement, TRUE);

			fp = mdlElmdscr_add (pXmlFragmentElement); 
			mdlElmdscr_freeAll (&pXmlFragmentElement); 

		} 
	}


	reloadHidingPositions(true);

	writeLogOut(__FUNCTION__, 0);

}



///////////////////////////////////////////////////////////////////////////////////
void saveBarSetInfo(ReinPos* rpP, int bMapInsert)
{
	MSElementDescr* pXmlFragmentElement = NULL; 
	int status;
	XMLFragmentListP pCurrent = NULL; 
	MSWCH wstr[1500];
	//WCH str[1500];


	writeLogIn(__FUNCTION__, 0);

	UInt32 rn = 0;

	//if (!curPos.arefnum.empty())
	//	rn = curPos.arefnum.back(); // обратный массив

	//_swprintf(wstr, L"%i|%i|%u|%I64u", 
	//			curPos.drawmode, 
	//			curPos.bar.inum,
	//			//(UInt32)curPos.arefnum.size(), // not curPos_rn, rnn...
	//			rn, // ref path see below
	//			curPos.bar.elemid
	//			);

	//// add ref path to wstr
	//for (deque<UInt32>::iterator it = curPos.arefnum.begin(); it != curPos.arefnum.end(); ++it)
	//{
	//	{
	//		MSWCH locstr[50];
	//		_swprintf(locstr, L"|%u", *it);
	//		wcscat(wstr, locstr);
	//	}
	//}

	//SCPM2W(wstr, str, 1500);

	rpP->getIdentChars(wstr, TRUE);

	pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeBarSet);

	// create new one
	status = mdlXMLFragmentList_createXMLElementDescriptor  (&pXmlFragmentElement, &pCurrent, TRUE); 

	
	if (NULL != pXmlFragmentElement) 
	{ 
		UInt32 fp;

		if (iDebug) sprintf(sLogMes, "     add xml fragment to file...\n"); writeLog(0, 0);

		//mdlXMLElement_setNonModelCategory (pXmlFragmentElement, TRUE);

		fp = mdlElmdscr_add (pXmlFragmentElement); 
		mdlElmdscr_freeAll (&pXmlFragmentElement); 

		if (fp > 0 && bMapInsert)
		{
			rpP->getIdentChars(wstr, FALSE);

			wstring str = wstr;
			curRM->mapBarSet[str] = *rpP;
			/*
			// todo relmP->drwopt[0]
			for (map<UInt32, ReinElm>::iterator it = rmP->mapElms.begin(); it != rmP->mapElms.end(); ++it)
			{
				if (inum == it->second.bel.inum && eid == it->second.bel.elemid)
				{
					it->second.drwopt[0] = set + BARSET_GAP;
				}
			}
			*/
		}


	} 

	writeLogOut(__FUNCTION__, 0);

}



//////////////////////////////////
void hookOptionDiam(
		DialogItemMessage   *dimP	/* => a ptr to a dialog item message */
)
{
    dimP->msgUnderstood = TRUE;

    switch (dimP->messageType)
	{

	case DITEM_MESSAGE_STATECHANGED:
		{

			DialogItem* diP;

			if (rInfo.rsVal.trmPar[0][0] == 0) rInfo.rsVal.trmPar[0][0] = 180;
			if (rInfo.rsVal.trmPar[0][1] == 0) rInfo.rsVal.trmPar[0][1] = 180;

			//if (!rInfo.rsOpt.trmPar[0][0])
			{
				rInfo.rsVal.trmPar[1][0] = roundExt(getReinLapBend(rInfo.rsVal.diam, 0), -1, 10, -2);
				rInfo.rsOpt.trmPar[0][0] = 1; // fix

				diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_OptionButton, ITEMID_TERMBEG, 0);
				if (diP) mdlDialog_itemSynch(dimP->db, diP->itemIndex);
				diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_Text, ITEMID_TERMBEG, 0);
				if (diP) mdlDialog_itemSynch(dimP->db, diP->itemIndex);
				diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_ToggleButton, 16, 0);
				if (diP) mdlDialog_itemSynch(dimP->db, diP->itemIndex);
			}


			//if (!rInfo.rsOpt.trmPar[0][1])
			{
				rInfo.rsVal.trmPar[1][1] = roundExt(getReinLapBend(rInfo.rsVal.diam, 0), -1, 10, -2);
				rInfo.rsOpt.trmPar[0][1] = 1; // fix

				//diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_Text, 18, 0);
				diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_OptionButton, ITEMID_TERMEND, 0);
				if (diP) mdlDialog_itemSynch(dimP->db, diP->itemIndex);
				diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_Text, ITEMID_TERMEND, 0);
				if (diP) mdlDialog_itemSynch(dimP->db, diP->itemIndex);
				diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_ToggleButton, 18, 0);
				if (diP) mdlDialog_itemSynch(dimP->db, diP->itemIndex);
			}


			break;
		}
	case DITEM_MESSAGE_QUEUECOMMAND:
		{
			setToggleOn(dimP->db, dimP->dialogItemP->id);
			break;
		}
	default:
	    dimP->msgUnderstood = FALSE;
	    break;
	}


}


//////////////////////////////////
void hookOptionTerm(
		DialogItemMessage   *dimP	/* => a ptr to a dialog item message */
)
{
    dimP->msgUnderstood = TRUE;

	//printf("%i\n", dimP->messageType);

    switch (dimP->messageType)
	{
	case DITEM_MESSAGE_INIT:
		{
			if (dimP->dialogItemP->id == 16 || dimP->dialogItemP->id == 18)
			{
				if (iCfgVar_MuftTypeEnabled[0] == 0)
					mdlDialog_optionButtonSetEnabled(dimP->dialogItemP->rawItemP, 0, FALSE);

				if (iCfgVar_MuftTypeEnabled[1] == 0)
					mdlDialog_optionButtonSetEnabled(dimP->dialogItemP->rawItemP, 1, FALSE);

				if (iCfgVar_MuftTypeEnabled[2] == 0)
					mdlDialog_optionButtonSetEnabled(dimP->dialogItemP->rawItemP, 2, FALSE);
			}


			break;
		}
	case DITEM_MESSAGE_STATECHANGED:
	case DITEM_MESSAGE_SYNCHRONIZE:
		{
			checkOptionTermItems(dimP->db, FALSE);
			break;
		}
	case DITEM_MESSAGE_QUEUECOMMAND:
		{
			if (mdlDialog_itemGetType(dimP->dialogItemP) == RTYPE_ToggleButton) break;
			setToggleOn(dimP->db, dimP->dialogItemP->id);
			break;
		}
	default:
	    dimP->msgUnderstood = FALSE;
	    break;
	}


}


/////////////////////////////
void checkOptionTermItems(MSDLGP   dbP, int bSetTrem)
{
	DialogItem* diP = NULL;

	//diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, 16, 0);
	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, ITEMID_TERMBEG, 0);
	if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);

	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, ITEMID_TERMBEG, 0);
	if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);

	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, 16, 0);
	if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);


	//diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, 18, 0);
	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, ITEMID_TERMEND, 0);
	if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);

	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, ITEMID_TERMEND, 0);
	if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);

	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, 18, 0);
	if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);


	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, 16, 0);
	if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);

	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, 18, 0);
	if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);


	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, 51, 0);
	if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);


	//diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, 93, 0);
	//if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);

	//diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, 93, 0);
	//if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);


	if (rInfo.rsVal.trm[0] == REIN_TERM_BEND)
	{
		//diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, 16, 0);
		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, ITEMID_TERMBEG, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);

		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, ITEMID_TERMBEG, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);

		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, 16, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);
	}


	if (rInfo.rsVal.trm[1] == REIN_TERM_BEND)
	{
		//diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, 18, 0);
		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, ITEMID_TERMEND, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);

		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, ITEMID_TERMEND, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);

		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, 18, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);
	}


	if (rInfo.rsVal.trm[0] == REIN_TERM_MUFT)
	{
		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, 16, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);

		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, 16, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);
	}


	if (rInfo.rsVal.trm[1] == REIN_TERM_MUFT)
	{
		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, 18, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);

		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, 18, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);
	}


	if (rInfo.rsVal.bartype != BT_AXIS)
	{
		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, 51, 0);
		if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);
	}


	//if (rDopInfo.dopopt[9] == 1)
	//{
	//	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, 93, 0);
	//	if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);

	//	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ToggleButton, 93, 0);
	//	if (diP) mdlDialog_itemShow(dbP, diP->itemIndex);
	//}

	if (bSetTrem)
	{
		DialogItem* di2P;
		bool bSync[2][2] = { false,false,false,false };

		// check values
		if (rInfo.rsVal.trmPar[0][0] == 0) 
		{
			rInfo.rsVal.trmPar[0][0] = 180;
			bSync[0][0] = true; // sync angle of begin
		}

		if (rInfo.rsVal.trmPar[0][1] == 0)
		{
			rInfo.rsVal.trmPar[0][1] = 180;
			bSync[0][1] = true; // sync angle of end
		}

		if (rInfo.rsVal.trmPar[1][0] == 0)
		{
			rInfo.rsVal.trmPar[1][0] = getReinLapBend(rInfo.rsVal.diam, 0);
			bSync[1][0] = true; // sync length of begin
		}

		if (rInfo.rsVal.trmPar[1][1] == 0)
		{
			rInfo.rsVal.trmPar[1][1] = getReinLapBend(rInfo.rsVal.diam, 0);
			bSync[1][1] = true; // sync length of end
		}

		// check options
		if (rInfo.rsOpt.trmPar[0][0]) // angle of begin selected
			bSync[0][0] = false;

		if (rInfo.rsOpt.trmPar[0][1]) // angle of end selected
			bSync[0][1] = false;

		if (rInfo.rsOpt.trmPar[1][0]) // length of begin selected
			bSync[1][0] = false;

		if (rInfo.rsOpt.trmPar[1][1]) // length of end selected
			bSync[1][1] = false;

		// sync if need
		if (bSync[0][0]) // angle of begin
		{
			//diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, 16, 0);
			di2P = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, ITEMID_TERMBEG, 0);
			if (di2P) mdlDialog_itemSynch(dbP, di2P->itemIndex);
		}

		if (bSync[0][1]) // angle of end
		{
			//diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, 18, 0);
			di2P = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, ITEMID_TERMEND, 0);
			if (di2P) mdlDialog_itemSynch(dbP, di2P->itemIndex);
		}

		if (bSync[1][0]) // length of begin
		{
			di2P = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, ITEMID_TERMBEG, 0);
			if (di2P) mdlDialog_itemSynch(dbP, di2P->itemIndex);
		}

		if (bSync[1][1]) // length of end
		{
			di2P = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, ITEMID_TERMEND, 0);
			if (di2P) mdlDialog_itemSynch(dbP, di2P->itemIndex);
		}

	}




	mdlDialog_adjustPopDownHeight(dbP);

}

/////////////////////////////////////////////
ELID reinCreateBarAxisLine(
	MSElement* elP,
	ReinBar* rbP,
	BINT bVisible, // FALSE?
	LEVID iLev
			)
{
	ELID axid = 0;
	
	if (bRef) return axid;

	writeLogIn(__FUNCTION__, 0);

	MSElementDescr* edpAxis = NULL;
	ELID eid = 0;
	int inm = 0;

	if (elP) // never...
	{
		mdlElmdscr_new(&edpAxis, NULL, elP);
	}
	else if (rbP)
	{
		mdlComplexChain_createHeader(&eCell, 0, 0);
		mdlElmdscr_new(&edpAxis, 0, &eCell);
		rbP->numpts = reinCreateComplexBarAxis2(&edpAxis, NULL, rbP->rpts, rbP->rfa, rbP->numpts, -1, &c0w0s4, 0, 0);
		if (rbP->numpts < 2)
		{
			writeLogOut(__FUNCTION__, "rbP->numpts < 2");
			return 0;
		}
		eid = rbP->elemid;
		inm = rbP->inum;
	}


	if (edpAxis == NULL)
	{
		writeLogOut(__FUNCTION__, "edpAxis == NULL");
		return 0;
	}


	int status;
	XMLFragmentListP    pCurrent;
	int cl = 2;
	int* clP = &cl;

	mdlElmdscr_setVisible(edpAxis, bVisible);
	func_amp(mdlElmdscr_setProperties, edpAxis), &iLev, 0, (ELCLASS*)clP, 0, 0, 0, 0, 0);

	//char str[100];
	MSWCH wstr[100];

	_swprintf(wstr, L"REINAXIS;%I64u;%i", eid, inm);
	//mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 100);
	pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeReinAxis); 
	status = mdlXMLFragmentList_attachToElement(&pCurrent, &edpAxis, TRUE);

	if (status == SUCCESS) 
	{
		mdlElmdscr_add(edpAxis);
		axid = mdlElement_getID(&edpAxis->el);

	}

	mdlElmdscr_freeAll(&edpAxis);


	writeLogOut(__FUNCTION__, 0);

	return axid;


}


/*
///////////////////////////////
int extractLinear( //NU
MSElementDescr *elmdP ,
DVec3d* arPts
) 
{ 
	EmbeddedDPoint3dArray* pArray = NULL;
	int num = 0, res = 0, numGot = 0;

	pArray = jmdlEmbeddedDPoint3dArray_grab ();

	res = mdlElmdscr_extractCompositeLinear(pArray, elmdP->h.firstElem, elmdP->h.dgnModelRef, TRUE, FALSE);

	printf("mdlElmdscr_extractCompositeLinear res = %i mdlErrno = %i\n", res, mdlErrno);
		

	if (res == SUCCESS) num = jmdlEmbeddedDPoint3dArray_getCount (pArray);

	if (res == SUCCESS) res = jmdlEmbeddedDPoint3dArray_getDPoint3dArray (pArray, arPts, &numGot, 0, num);

	jmdlEmbeddedDPoint3dArray_drop (pArray);

	return numGot;
} 
*/

//////////////////////////////////
int getReducers2(ReinVert* rvP)
{

	UInt32 fp = mdlLocate_findElement(&rvP->torg, 0, FALSE, ComponentMode_None, FALSE);





	return 0;
}

//////////////////////////////////////////////////////
int scanCheckHidePos(
MSElementDescr  *edP,
int*         iterCountP,
ScanCriteria    *pScanCriteria
)
{

	if (iterCountP)
	{
		(*iterCountP)++;
		return SUCCESS;
	}


	XMLFragmentListP  oXMLFragmentList = NULL;

	UInt32 fp = mdlElmdscr_getFilePos(edP);

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	if (oXMLFragmentList)
	{
		long pn = 0;
		long rn = 0;
		UInt32 urn = 0;
		wstring rpth = L"";

		long dropt[10];

		dropt[DROPT_A] = FALSE;
		dropt[DROPT_V] = FALSE;
		dropt[DROPT_X] = FALSE;
		dropt[DROPT_O] = FALSE;
		dropt[DROPT_S] = FALSE;

		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		//WCH ctxt[1500];
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);

			mdlXMLFragmentList_free(&oXMLFragmentList);

			if (wstr.length() > 0)
			{
				setstr.clear();

				if (readFromString(__FUNCTION__, &setstr, wstr,
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//					L'|'
//#else
					L"|"
//#endif
				) == SUCCESS)
				{
					SETSTR_BEGIN_ITER;
					IF_IT
						pn = _wtol(it->c_str()); // pos num

					IF_IT_nxt
					IF_IT
						rn = _wtol(it->c_str()); // is ref or not

					if (rn < 0) rn = 0; // раньше rn = -1 если для всех референсов и акт.файла
					if (rn > 0) urn = (UInt32)rn;

					IF_IT_nxt // ref path
					IF_IT
						rpth = *it;

					IF_IT_nxt
					IF_IT
						dropt[DROPT_A] = _wtol(it->c_str());
					else
						dropt[DROPT_A] = TRUE; // для совместимости

					IF_IT_nxt
					IF_IT
						dropt[DROPT_V] = _wtol(it->c_str());

					IF_IT_nxt
					IF_IT
						dropt[DROPT_X] = _wtol(it->c_str());

					IF_IT_nxt
					IF_IT
						dropt[DROPT_O] = _wtol(it->c_str());

					IF_IT_nxt
					IF_IT
						dropt[DROPT_S] = _wtol(it->c_str());


				}
				else
					return SUCCESS; // continue scan
			}
			else
				return SUCCESS; // continue scan
		}
		else
			return SUCCESS; // continue scan

		//SCPW2M(ctxt, wtxt, 1500);

		//WCH seps[]   = L("|");
		//WCH *token;

		/*

		token = STOK( ctxt, seps );
		if (token != NULL)	pn = STOL(token);

		token = STOK( NULL, seps );
		if (token != NULL)	rn = STOL(token);
		if (rn < 0) rn = 0; // раньше rn = -1 если для всех референсов и акт.файла
		if (rn > 0) urn = rn; 

		token = STOK( NULL, seps );
		//if (token != NULL)	
		//{
		//	rnn = atol(token);

		//	if (rnn < 0) 
		//		rnn = -rnn;
		//	else
		//		rnn = 0; // pcatID давнишний
		//}

		token = STOK( NULL, seps );
		if (token != NULL)	dropt[0] = STOL(token);
		else dropt[0] = TRUE; // для совместимости

		token = STOK( NULL, seps );
		if (token != NULL)	dropt[1] = STOL(token);

		token = STOK( NULL, seps );
		if (token != NULL)	dropt[2] = STOL(token);

		token = STOK( NULL, seps );
		if (token != NULL)	dropt[3] = STOL(token);

		token = STOK( NULL, seps );
		if (token != NULL)	dropt[4] = STOL(token);

		*/

		ReinPos* rpBaseP = NULL;
		ReinPos* rpHideP = NULL;


		//if (arCurMrP[rn] == NULL) return ERROR;
		//if (arCurMrP[rn][rnn] == NULL) return ERROR;


		ReinModel* rmP = curRM->getRM(rpth);

		deque<UInt32> aref;

		if (rmP == NULL) 
			return SUCCESS; // continue scan

		rmP->getRefPath(&aref);

		for (map<long, ReinPos>::iterator it = rmP->getPosMap().begin(); it != rmP->getPosMap().end(); ++it)
		{
			ReinPos* rpItP = &it->second;

			if (rpItP->bar.pnum == 0) continue;

			if (rpItP->bar.pnum == pn
				//&& (cid == 0 || rpItP->pcatID == cid)
				)
			{
				rpBaseP = rpItP;
			}
		}

		if (rpBaseP == NULL) 
			return SUCCESS; // continue scan

		for (vector<ReinPos>::iterator rpItP = daCurPosHide.begin(); rpItP != daCurPosHide.end(); ++rpItP)
		//for (UInt32 i = 0; i < daCurPosHide.size(); i++)
		{

			if (rpItP->bar.pnum == pn &&
					(
						(rpItP->arefnum.empty() && urn == 0) ||
						//(!rpItP->arefnum.empty() && rpItP->arefnum.back() == urn) // обратный массив
						refPathsEQ(rpItP->arefnum, aref)
					)
				)
			{
				rpHideP = &(*rpItP);
				break;
			}
		}

		if (rpHideP == NULL 
			// elemIterCount2 < daCurPosHide.size()
			)
		{
			ReinPos rp;
			rp = *rpBaseP;
			//rp.arefnum.push_back(urn); // pn, cid уже есть
			rp.arefnum = aref;
			rp.drawopt[DROPT_A] = dropt[DROPT_A];
			rp.drawopt[DROPT_V] = dropt[DROPT_V];
			rp.drawopt[DROPT_X] = dropt[DROPT_X];
			rp.drawopt[DROPT_O] = dropt[DROPT_O];
			rp.drawopt[DROPT_S] = dropt[DROPT_S];
			daCurPosHide.push_back(rp);
			elemIterCount2++;

			//rpHideP = (ReinPos*)mdlDArray_insertMembers(daCurPosHide, 0, 1, -1);
			
		}

	}
	else // MDLERR_LINKAGENOTFOUND
		return SUCCESS; // continue scan

    return SUCCESS;
}



//////////////////////////////////////////////////////
int scanCheckBarSet(
MSElementDescr  *edP,
int*         iterCountP,
ScanCriteria    *pScanCriteria
)
{


	if (iterCountP)
	{
		(*iterCountP)++;
		return SUCCESS;
	}

	DgnModelRefP mrP = mdlScanCriteria_getModel(pScanCriteria);

	ReinModel* rmP = NULL;

	long set = 0;
	long inum = 0;
	UInt32 ref = 0;
	UInt32 refcnt = 0;
	ELID eid = 0;
	//UInt32 aref[MAX_REFNUM_PATH] = { 0 };
	deque<UInt32> aref;

	ReinPrm prm;

	if (getBarSetInfo(edP, &prm) == SUCCESS)
	{
		set = prm.lval[0];
		inum = prm.lval[1];
		ref = prm.cnt[0];
		refcnt = prm.cnt[1];
		eid = prm.prmid;

		aref = prm.uints;

	/*

	XMLFragmentListP  oXMLFragmentList = NULL;

	UInt32 fp = mdlElmdscr_getFilePos(edP);

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	wstring str = L"";

	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		//WCH ctxt[1500];
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);


		//vector<UInt32> aref;
		UInt32 aref[MAX_REFNUM_PATH] = { 0 };
		//ZeroMemory(aref, sizeof(aref));


		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);

			wstr = wtxt;
			mdlXMLFragmentList_free(&oXMLFragmentList);

			if (wstr.length() > 0)
			{
				setstr.clear();

				if (readFromString(__FUNCTION__, &setstr, wstr,
#if defined (MSVERSION) && (MSVERSION == 0xa00)
					L'|'
#else
					L"|"
#endif
				) == SUCCESS)
				{
					vector<wstring>::iterator it = setstr.begin();
					IF_IT
						set = _wtol(it->c_str());

					IF_IT_nxt
					IF_IT
						inum = _wtol(it->c_str());

					IF_IT_nxt
					IF_IT
						ref = wcstoul(it->c_str(), 0, 0); // ref number, new vers - is ref or not

					IF_IT_nxt
					IF_IT_end return SUCCESS;
					if (swscanf(it->c_str(), L"%I64u", &eid) != 1) return ERROR;

					// VERSION 2
					IF_IT_nxt
					while (it != setstr.end() && refcnt < MAX_REFNUM_PATH)
					{
						aref[refcnt] = _wtol(it->c_str());
						refcnt++;
						IF_IT_nxt
					}

				}
				else
					return SUCCESS; // continue scan
			}
			else
				return SUCCESS; // continue scan
		}
		else
			return SUCCESS; // continue scan

*/


		//SCPW2M(ctxt, wtxt, 1500);
		//str = wtxt;
		//printf("%s\n", ctxt);
		//mdlXMLFragmentList_free(&oXMLFragmentList);

		//WCH seps[]   = L("|");
		//WCH *token;

		/*

		token = STOK( ctxt, seps );
		if (token != NULL)	set = STOL(token);

		token = STOK( NULL, seps );
		if (token != NULL)	inum = STOL(token);

		token = STOK( NULL, seps );
		if (token != NULL)	ref = STOUL(token,0,0); // ref number, new vers - is ref or not

		token = STOK( NULL, seps );
		if (token == NULL) return ERROR;
		if (SSCAN(token, L("%I64u"), &eid) != 1) return ERROR;

		// VERSION 2
		token = STOK( NULL, seps );
		while(token && refcnt < MAX_REFNUM_PATH)
		{
			if (token != NULL)	
			{
				aref[refcnt] = STOL(token);
				refcnt++;
			}
			token = STOK( NULL, seps );
		}

		//while (token && aref.size() < MAX_REFNUM_PATH)
		//{
		//	if (token != NULL)
		//	{
		//		UInt32 v = STOUL(token,0,0);
		//		//aref.push_back(v);
		//		aref.insert(aref.begin(), v); // вставляем в начало -- для совместимости, так как традиционно родители были справа, и сохраняются тоже в таком порядке
		//	}
		//	token = STOK(NULL, seps);
		//}

		//if (aref[0] == 26)
		//	__asm nop;

		*/

		if (mdlModelRef_isActiveModel(mrP)) // барсет из текущей модели, берем по номерам
		{
			if (aref.size() > 0) // барсет сохранен для элемента из референса
				rmP = curRM->getRM(aref);
			else
				rmP = curRM; // барсет сохранен для элемента текущей модели
		}
		else // барсет в референсе, берем по mrP
		{
			rmP = curRM->getRM(mrP); 
			// случай когда барсет и элемент из разных референсов не проработан
			// надо брать путь модели, путь барсета и склеивать их
			//... ....
		}


		ReinElm* reP = NULL;

		if (rmP)
		{
			for (map<UInt32, ReinElm>::iterator it = rmP->mapElms.begin(); it != rmP->mapElms.end(); ++it)
			{
				if (inum == it->second.bel.inum && eid == it->second.bel.elemid)
				{
					//it->second.drwopt[0] = set + BARSET_GAP;

					reP = &(it->second);
				}
			}
		}



		// if element not found - no need to load? 
		//if (reP == NULL) return SUCCESS;
		// // грузим ВСЁ тк загрузка идет полностью при входе в модель и больше потом не пергружаем даже при reload
		// потому что функция reloadHidingPositions может отрабатывать очень долго (50тыщ элементов и более при использовании фенсы)

		//ReinPos* rpP = (ReinPos*)mdlDArray_insertMembers(daCurBarSet, 0, 1, -1);
		ReinPos rp;

		rp.drawmode = set;
		rp.bar.inum = inum;
		rp.bar.elemid = eid;

		// VERSION 2
		if (aref.size() > 0)
		{
			rp.arefnum = aref;
		}



		bool bFoumd = false;

		for (map <wstring, ReinPos>::iterator rpItP = curRM->mapBarSet.begin(); rpItP != curRM->mapBarSet.end(); ++rpItP)
		//for (UInt32 i = 0; i < elemIterCount2 || i < daCurBarSet.size(); i++)
		{
			//ReinPos* rpItP = &(daCurBarSet[i]);

			//if (
			//	rpItP->bar.elemid == 5319714 ||
			//	rpItP->bar.elemid == 1662426
			//	)
			//	__asm nop;


			if (
				//(aref.size() == 0 && // old vers
				//rpItP->bar.inum == rp.bar.inum && 
				//rpItP->bar.elemid == rp.bar.elemid &&
				//rpItP->arefnum[0] == rp.arefnum[0])
				//||
				(rpItP->second.bar.inum == rp.bar.inum &&
				rpItP->second.bar.elemid == rp.bar.elemid &&
				refPathsEQ(rpItP->second.arefnum, rp.arefnum))
				)
			{
				bFoumd = true;
				break;
			}
		}

		if (!bFoumd)
		{
			if (mdlModelRef_isActiveModel(mrP)) // барсет из текущей модели
			{
				elemIterCount2++;
			}
			else
			{
				if (rp.arefnum.empty())  // элемент и барсет из одной модели, даем номер
				{
					if (rmP)
						rmP->getRefPath(&rp.arefnum);
					else
						rp.arefnum.push_back(getRefNum(mrP)); // на всякий случай

					rp.bFromRef = true;

					elemIterCount2++;
				}
				else
				{
					// пока для случая когда барсет и элемент из разных референсов - алгоритм не разработан 
				}

			}

			//daCurBarSet.push_back(rp);

			wstring str = rp.getMapIdentString();

			curRM->mapBarSet[str] = rp;
		}



	}
	else // MDLERR_LINKAGENOTFOUND
		return ERROR;

    return SUCCESS;
}




/////////////////////////////
void reloadHidingPositions(bool onlyHidePos)
{
	ScanCriteria    *pScanCriteria;
	int status;

	writeLogIn(__FUNCTION__, 0);


	//if (daCurPosHide)
	//{
	//	mdlDArray_destroy(daCurPosHide);
	//	daCurPosHide = NULL;
	//}



	//daCurBarSet.clear(); // later

	
	

	int icnt = 0;
	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckHidePos, &icnt);
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	status = mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeHidePos);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	//if (icnt > 0) daCurPosHide = mdlDArray_create(sizeof (ArrayObjectHdr), sizeof(ReinPos), icnt, 0, 0); 
	daCurPosHide.clear();

	elemIterCount2 = 0;
	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckHidePos, NULL);
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	status = mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeHidePos);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);


	if (onlyHidePos)
	{
		writeLogOut(__FUNCTION__, 0);
		return;
	}

	// BAR SETTINGS

	icnt = 0;
	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckBarSet, &icnt);
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	status = mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeBarSet);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	// данные из референсов
	if (iCfgVar_BarSetRefNesting)
	{
		ModelRefIteratorP  iterator;
		DgnModelRefP	modelRef;
		int dpth = -1;
		if (iCfgVar_BarSetRefNesting > 0) dpth = iCfgVar_BarSetRefNesting - 1; // if 0 - iterate root modelRef, see mdl help

		mdlModelRefIterator_create (&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, dpth);

		while (NULL != (modelRef = mdlModelRefIterator_getNext (iterator)))
		{
			pScanCriteria= mdlScanCriteria_create ();
			status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckBarSet, &icnt);
			status = mdlScanCriteria_setModel (pScanCriteria, modelRef);
			status = mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeBarSet);
			status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
			status = mdlScanCriteria_free (pScanCriteria);
		}

		mdlModelRefIterator_free (&iterator);
	}



	//daCurBarSet.clear();
	//daCurBarSet.reserve(icnt);
	curRM->mapBarSet.clear();

	elemIterCount2 = 0;
	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckBarSet, NULL);
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	status = mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeBarSet);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	// данные из референсов
	if (iCfgVar_BarSetRefNesting)
	{
		ModelRefIteratorP  iterator;
		DgnModelRefP	modelRef;
		int dpth = -1;
		if (iCfgVar_BarSetRefNesting > 0) dpth = iCfgVar_BarSetRefNesting - 1; // if 0 - iterate root modelRef, see mdl help

		mdlModelRefIterator_create (&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, dpth);

		while (NULL != (modelRef = mdlModelRefIterator_getNext (iterator)))
		{
			pScanCriteria= mdlScanCriteria_create ();
			status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckBarSet, NULL);
			status = mdlScanCriteria_setModel (pScanCriteria, modelRef);
			status = mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeBarSet);
			status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
			status = mdlScanCriteria_free (pScanCriteria);
		}

		mdlModelRefIterator_free (&iterator);
	}

	writeLogOut(__FUNCTION__, 0);


}

////////////////////////////////////////////
ListModel* createListBoxRefs(
)
{
    ListModel   *pListModel;
    ListRow     *pRow;
	WCH v[500];

    pListModel = mdlListModel_create (2);


	//pRow = mdlListRow_create (pListModel);

	//{ // первая
	//	ListCell    *pCell;
	//	sprintf(v, "%i", -1);
	//	pCell = mdlListRow_getCellAtIndex (pRow, 0);
	//	mdlListCell_setStringValue (pCell,v,TRUE);
	//}

	//{ // вторая
	//	ListCell    *pCell;
	//	sprintf(v, "%s", "все");
	//	pCell = mdlListRow_getCellAtIndex (pRow, 1);
	//	mdlListCell_setStringValue (pCell,v,TRUE);
	//}

	//mdlListModel_addRow (pListModel,pRow);

	ListColumn* lclmn = mdlListModel_getColumnAtIndex(pListModel, 0);
	mdlListColumn_setInfoFieldCount(lclmn, 1);


	pRow = mdlListRow_create (pListModel);

	{ // первая
		ListCell    *pCell;
		SPRN(v, L("%i"), 0);
		pCell = mdlListRow_getCellAtIndex (pRow, 0);
		mdlListCell_setStringValue (pCell,v,TRUE);
		mdlListCell_setInfoFieldInt32(pCell, 0, 0);
	}

	{ // вторая
		ListCell    *pCell;
		SPRN(v, L("%s"), TXT_92);
		pCell = mdlListRow_getCellAtIndex (pRow, 1);
		mdlListCell_setStringValue (pCell,v,TRUE);
	}

	mdlListModel_addRow (pListModel,pRow);


	{
		ModelRefIteratorP  iterator;
		DgnModelRefP	modelRef;

		mdlModelRefIterator_create (&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, -1); // nested unlimited

		while (NULL != (modelRef = mdlModelRefIterator_getNext (iterator)))
		{
			MSWCH modelname[500];
			int st = mdlModelRef_getModelName(modelRef, modelname);
			if (st != SUCCESS) continue;

			ReinModel* rmP = curRM->getRM(modelRef);
			if (rmP == NULL) continue; //error?

			if (rmP->elcount == 0 
				//&& rmP->mrci.catID == 0 // show design that has no elements and catID>0 
				) continue;

			DgnAttachmentP rfP = mdlRefFile_getInfo(modelRef);
			if (rfP == NULL) continue;

			pRow = mdlListRow_create (pListModel);

			{ // первая
				ListCell    *pCell;
				wstring wrefpth = rmP->getRefPathString();
#if defined (MSVERSION) && (MSVERSION == 0xa00)				
				SPRN(v, L("%s"), wrefpth.c_str());
#else
				SPRN(v, L("%S"), wrefpth.c_str());
#endif
				//SPRN(v, L("%i"), getRefNum(modelRef));
				pCell = mdlListRow_getCellAtIndex (pRow, 0);
				mdlListCell_setStringValue (pCell,v,TRUE);
				//mdlListCell_setInfoField(pCell, 0, rmP->prnum); // ????
			}

			{ // вторая
				ListCell    *pCell;
#if defined (MSVERSION) && (MSVERSION == 0xa00)				
				SPRN(v, L("%s / %s"), modelname, REFLOGICAL(rfP));
#else
				SPRN(v, L("%S / %S"), modelname, REFLOGICAL(rfP));
#endif
				pCell = mdlListRow_getCellAtIndex (pRow, 1);
				mdlListCell_setStringValue (pCell,v,TRUE);
			}

		

			mdlListModel_addRow (pListModel,pRow);

		}

		mdlModelRefIterator_free (&iterator);

	}

	

    return pListModel;

}
/*
/////////////////////////////////////
int checkPos(ReinPos* rpP, int* bExP)
{

	int bFound = FALSE;

	for (int a = 0; a < rpP->refcnt; a++)
	{
		if (rpP->refs[a] == curPos_refnum) bFound = TRUE;
		if (bExP && rpP->refs[a] == 0) *bExP = TRUE;
	}

	return bFound;

}
*/
////////////////////////////////////
void posListAddRow(ListModel* pListModel, ReinPos* rpP, bool bRealPos, long ind, double dSortPosNum, bool bSaveBtn)
{

	WCH v[500];
	int res = 0;

	//int bExistInModel = FALSE;
	//int bFound = TRUE;

	//if (bRealPos)
	//{
	//	bFound = checkPos(rpP, &bExistInModel);
	//	//if (!bFound && curPos_refnum > 0) return;
	//	//if (!bExistInModel && curPos_refnum == 0) return;
	//}


	IcnRsc* icrsc[15][2];

	for (int a = 0; a < 15; a++)
	{
		for (int b = 0; b < 2; b++)
			icrsc[a][b] = NULL;
	}

	//ZeroMemory(icrsc, sizeof(icrsc));

	if (rfRein)
	{
		icrsc[REIN_TERM_NONE][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 6);
		icrsc[REIN_TERM_NONE][1] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 6);
		icrsc[REIN_TERM_BEND][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 5);
		icrsc[REIN_TERM_BEND][1] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 1);
		icrsc[REIN_TERM_REZB][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 2);
		icrsc[REIN_TERM_REZB][1] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 2);
		icrsc[REIN_TERM_MUFT][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 2);
		icrsc[REIN_TERM_MUFT][1] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 2);
		icrsc[REIN_TERM_SKOB][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 6);
		icrsc[REIN_TERM_SKOB][1] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 6);
		icrsc[REIN_TERM_SVAR][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 6);
		icrsc[REIN_TERM_SVAR][1] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 6);

		icrsc[REIN_TERM_TRMV][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 8);
		icrsc[REIN_TERM_TRMV][1] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 9);

		icrsc[REIN_TERM_TRMX][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 12);
		icrsc[REIN_TERM_TRMX][1] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 13);

		icrsc[REIN_TERM_TRMO][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 10);
		icrsc[REIN_TERM_TRMO][1] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 11);

		icrsc[REIN_TERM_TRMS][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 14);
		icrsc[REIN_TERM_TRMS][1] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 15);

		icrsc[REIN_TERM_SAVE][0] = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 16);
	}


	ListRow* pRow = mdlListRow_create (pListModel);




    {
		ListCell    *pCell;
		pCell = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_EXST);
		if (rpP->file_qty_p > 0)
		{
			mdlListCell_setIcon(pCell, 222, RTYPE_Icon, mdlSystem_getCurrMdlDesc());
			res = mdlListCell_setInfoFieldInt32(pCell, 0, 222);
		}
		else
			res = mdlListCell_setInfoFieldInt32(pCell, 0, 0);

		if (rpP->bar.noplanar == 1)
		{
			BSIColorDescr* clr   = mdlWindow_systemColorGet(SYSCOLOR_FIXED_YELLOW);
			mdlListCell_setBgColorDescr(pCell, clr);
		}

		if (rpP->bar.noplanar == 2)
		{
			BSIColorDescr* clr   = mdlWindow_systemColorGet(SYSCOLOR_FIXED_LGREY);
			mdlListCell_setBgColorDescr(pCell, clr);
		}
    }


	//if (rpP->bar.pnum == 20)
	//{
	//	int a = 0;
	//}

    {
		ListCell    *pCell;
		SPRN(v, L("%i"), rpP->bar.pnum);
		pCell = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_POSN);
		if (bRealPos)
		{
			mdlListCell_setDoubleValue (pCell, (double)(rpP->bar.pnum));
			if (rpP->bar.pnum) mdlListCell_setDisplayText(pCell, v);
			if (curPos_rn == 0) mdlListCell_setEditor (pCell, RTYPE_Text, TEXTID_Space, mdlSystem_getCurrMdlDesc(), FALSE, TRUE);
			res = mdlListCell_setInfoFieldInt32(pCell, 0, ind);
		}
		else
		{
			mdlListCell_setDoubleValue(pCell, dSortPosNum); // для сортировки
			mdlListRow_setStatus(pRow, LISTCELLATTR_DISABLED);
			mdlListModel_addRow (pListModel, pRow);
			// EMPTY POS ADDED, R E T U R N 
			return;
		}
    }


    {
		bool bExcl = false;
		ListCell    *pCell;
		pCell = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_EXCL);

		for (vector<ReinExcl>::iterator rexP = daCurPosExcl.begin(); rexP != daCurPosExcl.end(); ++rexP)
		//for (UInt32 i = 0; i < daCurPosExcl.size(); i++)
		{
			{
				if (rexP->ind == ind && rexP->ref == curPos_refpath)
				{
					bExcl = true;
					break;
				}
			}
		}

		if (bExcl)
			mdlListCell_setIcon(pCell, ICONID_ToggleOn14Pt, RTYPE_Icon, NULL);
		else
			mdlListCell_setIcon(pCell, ICONID_ToggleOff14Pt, RTYPE_Icon, NULL);

		res = mdlListCell_setInfoFieldInt32(pCell, 0, ind);
    }



	//int dropt[10] = {0};
	vector<int>dropt(10);

	//ZeroMemory(dropt, sizeof(dropt));

	for (vector<ReinPos>::iterator rpItP = daCurPosHide.begin(); rpItP != daCurPosHide.end(); ++rpItP)
	{
		wstring wrefstr = curRM->getRefPathString(&rpItP->arefnum);

		if (rpItP->bar.pnum == rpP->bar.pnum
			//&& !rpItP->arefnum.empty()
			//&& (rpItP->arefnum.back() == curPos_rn) // curPos_rnn...
			//&& (rpItP->arefnum[0] == curPos_rn) // curPos_rnn...
			&& (wrefstr == curPos_refpath) // curPos_rnn...
			)
		{
			dropt = rpItP->drawopt;
			break;
		}
	}









	ListCell    *pCell;
	pCell = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_SHOW);
	if (dropt[0])
		mdlListCell_setIcon(pCell, ICONID_ToggleOn14Pt, RTYPE_Icon, NULL);
	else
		mdlListCell_setIcon(pCell, ICONID_ToggleOff14Pt, RTYPE_Icon, NULL);


	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_TRMV);
		mdlListCell_setIconRsc(pCel, icrsc[REIN_TERM_TRMV][dropt[DROPT_V]]);
		res = mdlListCell_setInfoFieldInt32(pCel, 0, !dropt[DROPT_V]);
		//mdlListCell_setStatus(pCel, LISTCELLATTR_DISABLED);
	}
	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_TRMX);
		mdlListCell_setIconRsc(pCel, icrsc[REIN_TERM_TRMX][dropt[DROPT_X]]);
		res = mdlListCell_setInfoFieldInt32(pCel, 0, !dropt[DROPT_X]);
	}
	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_TRMO);
		mdlListCell_setIconRsc(pCel, icrsc[REIN_TERM_TRMO][dropt[DROPT_O]]);
		res = mdlListCell_setInfoFieldInt32(pCel, 0, !dropt[DROPT_O]);
	}
	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_TRMS);
		mdlListCell_setIconRsc(pCel, icrsc[REIN_TERM_TRMS][dropt[DROPT_S]]);
		res = mdlListCell_setInfoFieldInt32(pCel, 0, !dropt[DROPT_S]);
	}




	{
		ListCell    *pCel;
		SPRN(v, L("%i"), rpP->bar.diam);
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_DIAM);
		mdlListCell_setLongValue (pCel, rpP->bar.diam);
		if (rpP->bar.diam > 0) mdlListCell_setDisplayText(pCel, v);
	}

	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_TRM0);
		mdlListCell_setIconRsc(pCel, icrsc[rpP->bar.term[0]][0]);
		mdlListCell_setLongValue (pCel, getTrueEnd(&rpP->bar, 0));
	}

	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_TRM1);
		mdlListCell_setIconRsc(pCel, icrsc[rpP->bar.term[1]][1]);
		mdlListCell_setLongValue (pCel, getTrueEnd(&rpP->bar, 1));
	}

	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_RUNM);
		if (rpP->bar.runmet == 1)
		{
			mdlListCell_setIcon(pCel, 222, RTYPE_Icon, mdlSystem_getCurrMdlDesc());
			mdlListCell_setLongValue (pCel, 0);
		}
		else
		{
			mdlListCell_setLongValue (pCel, 1);
		}

	}

	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_VARL);
		if (rpP->bar.runmet > 1)
		{
			mdlListCell_setIcon(pCel, 222, RTYPE_Icon, mdlSystem_getCurrMdlDesc());
			mdlListCell_setLongValue (pCel, 0);
		}
		else
		{
			mdlListCell_setLongValue (pCel, 1);
		}

	}

	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_RADI);
		mdlListCell_setLongValue (pCel, 1);
		for (int i = 0; i < rpP->bar.cnumpts; i++)
		{
			if (rpP->bar.rfa[i] & RFA_ARCP || rpP->bar.rfa[i] & RFA_CIRP)
			{
				mdlListCell_setIcon(pCel, 222, RTYPE_Icon, mdlSystem_getCurrMdlDesc());
				mdlListCell_setLongValue (pCel, 0);
				break;
			}
		}
	}

	{
		ListCell    *pCel;
		SPRN(v, L("%i"), rpP->file_ms_mid);
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_LENG);
		if (curPos_rn == 0 && rpP->file_qty_p > 0 && rpP->bar.runmet != 1) 
		{
			mdlListCell_setLongValue (pCel, rpP->file_ms_mid);
			mdlListCell_setDisplayText(pCel, v);
		}
		else
		{
			mdlListCell_setLongValue (pCel, 0);
		}
	}

	//{
	//	ListCell    *pCel;
	//	if (rpP->bar.pnum > 0)
	//		sprintf(v, "%0*i", 3 , rpP->bar.pnum);
	//	pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_SORT); NOT USING
	//	mdlListCell_setStringValue (pCel,v,TRUE);
	//}

	if (curPos_rn == 0)
	{
		ListCell    *pCel;
		SPRN(v, L("%i"), rpP->file_qty_p);
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_QTYP);
		mdlListCell_setLongValue (pCel, rpP->file_qty_p);
		mdlListCell_setDisplayText(pCel, v);


		SPRN(v, L("%.1f"), rpP->file_qty_rm);
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_QTYR);
		mdlListCell_setDoubleValue (pCel, rpP->file_qty_rm);
		mdlListCell_setDisplayText(pCel, v);
	}

	{
		ListCell    *pCel;
		SPRN(v, L("%i"), rpP->lap_qty);
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_LAPA);
		mdlListCell_setLongValue (pCel, rpP->lap_qty);
		if (rpP->lap_qty) mdlListCell_setDisplayText(pCel, v);
	}

	{
		ListCell    *pCel;
		SPRN(v, L("%i/%i"), rpP->muft_qty[0], rpP->muft_qty[1]);
		rDopInfo.dopopt[7] += (rpP->muft_qty[0] + rpP->muft_qty[1]);
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_MUFT);
		mdlListCell_setLongValue (pCel, rpP->muft_qty[0] + rpP->muft_qty[1]);
		if (rpP->muft_qty[0] || rpP->muft_qty[1]) mdlListCell_setDisplayText(pCel, v);

		//mdlListCell_setEditor (pCel, RTYPE_OptionButton, 100, mdlSystem_getCurrMdlDesc(), FALSE, FALSE); // работает!
	}


  //  {
		//ListCell    *pCel;
		//sprintf(v, "%i", i);
		//pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_AROW);
		//mdlListCell_setStringValue (pCel,v,TRUE);
  //  }

	if (
			!EQ(rpP->base_qty, 0.) 
			&& !EQ(rpP->file_qty_rm, 0.) 
			&& rpP->file_qty_p != 0
			&& (
				rpP->bar.runmet == 1 && fabs(rpP->base_qty - rpP->file_qty_rm) > 0.1
				|| rpP->bar.runmet != 1 && (long)rpP->base_qty != rpP->file_qty_p
				|| rpP->bar.runmet > 1 && rpP->base_ms_max != rpP->file_ms_max
				|| rpP->bar.runmet > 1 && rpP->base_ms_min != rpP->file_ms_min
				|| rpP->bar_mem.diam > 0 && !barsEqual( &rpP->bar_mem, &rpP->bar)
			)
			&& bSaveBtn
		)
	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_SAVE);
		mdlListCell_setIconRsc(pCel, icrsc[REIN_TERM_SAVE][0]);
		res = mdlListCell_setInfoFieldInt32(pCel, 0, 1);
	}
	else
	{
		ListCell    *pCel;
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_SAVE);
		res = mdlListCell_setInfoFieldInt32(pCel, 0, 0);
	}


	if (rpP->bar.poscalc)
	{
		ListCell    *pCel;
		SPRN(v, L("%i"), rpP->bar.poscalc);
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_NONE);
		mdlListCell_setDisplayText(pCel, v);
	}

	if (rpP->bPosXml)
	{
		ListCell    *pCel;
		//SPRN(v, L("%i"), rpP->bar.poscalc);
		pCel = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_NONE);
		mdlListCell_setDisplayText(pCel, L("xml"));
	}
	

	

	mdlListModel_addRow (pListModel,pRow);
}

/////////////////
struct cmppos
{
	bool operator()(const ReinPos& p1, const ReinPos& p2) const
	{


		for (deque<STRING>::iterator it = possort.begin(); it != possort.end(); ++it)
		{
			if (it->compare(L("num")) == 0)
			{
				if (p1.bar.pnum != p2.bar.pnum)
					return  p1.bar.pnum < p2.bar.pnum;
			}

			if (it->compare(L("run")) == 0)
			{
				int runmet1 = 0;
				int runmet2 = 0;

				if (p1.bar.runmet == 1) { runmet1 = 0; }
				if (p1.bar.runmet == 0) { runmet1 = 1; }
				if (p1.bar.runmet == 2) { runmet1 = 1; } // если поставить 1 то перем. длина будет вперемежку с обычными

				if (p2.bar.runmet == 1) { runmet2 = 0; }
				if (p2.bar.runmet == 0) { runmet2 = 1; }
				if (p2.bar.runmet == 2) { runmet2 = 1; } // см выше

				if (runmet1 != runmet2)
					return  runmet1 < runmet2;
			}

			if (it->compare(L("diam")) == 0)
			{
				if (p1.bar.diam != p2.bar.diam)
					return  p1.bar.diam > p2.bar.diam; // DESC
			}

			if (it->compare(L("bends")) == 0)
			{
				if (p1.bar.numpts != p2.bar.numpts)
					return  p1.bar.numpts < p2.bar.numpts;
			}

			if (it->compare(L("term")) == 0)
			{
				if (p1.cmpopt[0] != p2.cmpopt[0])
					return  p1.cmpopt[0] < p2.cmpopt[0];

				if (p1.cmpopt[1] != p2.cmpopt[1])
					return  p1.cmpopt[1] < p2.cmpopt[1];

				if (p1.cmpopt[2] != p2.cmpopt[2])
					return  p1.cmpopt[2] < p2.cmpopt[2];
			}

			if (it->compare(L("length")) == 0)
			{
				if (p1.file_ms_mid != p2.file_ms_mid)
					return  p1.file_ms_mid < p2.file_ms_mid;
			}

			if (it->compare(L("posset")) == 0)
			{
				if (p1.bar.poscalc != p2.bar.poscalc)
					return  p1.bar.poscalc < p2.bar.poscalc;
			}


			if (it->compare(L("loc")) == 0)
			{
				if (p1.cmppt.x != p2.cmppt.x)
					return  p1.cmppt.x < p2.cmppt.x;

				if (p1.cmppt.y != p2.cmppt.y)
					return  p1.cmppt.y < p2.cmppt.y;

				if (p1.cmppt.z != p2.cmppt.z)
					return  p1.cmppt.z < p2.cmppt.z;
			}

			if (it->compare(L("locx")) == 0)
			{
				if (p1.cmppt.x != p2.cmppt.x)
					return  p1.cmppt.x < p2.cmppt.x;
			}

			if (it->compare(L("locy")) == 0)
			{
				if (p1.cmppt.y != p2.cmppt.y)
					return  p1.cmppt.y < p2.cmppt.y;
			}

			if (it->compare(L("locz")) == 0)
			{
				if (p1.cmppt.z != p2.cmppt.z)
					return  p1.cmppt.z < p2.cmppt.z;
			}



		}






		//if (p1.mapind != p2.mapind)
			return  p1.mapind < p2.mapind;

		//return (barsEqual((ReinBar*)&p1.bar, (ReinBar*)&p2.bar));
	}
};

//////////////////////////////////
ListModel* createListBoxPos(
								  int nCols
)
{
    ListModel   *pListModel = NULL;
    //ListRow     *pRow;
    //int		colIndex;
	//char v[500];
	//int res = 0;

    pListModel = mdlListModel_create (nCols);

	ReinModel* rmP = curRM->getRM(curPos_refpath);

	if (rmP == NULL) return pListModel;
	

	writeLogIn(__FUNCTION__, 0);




	ListColumn* lclmn = mdlListModel_getColumnAtIndex(pListModel, REIN_LISTB_POSN);
	mdlListColumn_setInfoFieldCount(lclmn, 1);

	lclmn = mdlListModel_getColumnAtIndex(pListModel, REIN_LISTB_EXCL);
	mdlListColumn_setInfoFieldCount(lclmn, 1);

	lclmn = mdlListModel_getColumnAtIndex(pListModel, REIN_LISTB_EXST);
	mdlListColumn_setInfoFieldCount(lclmn, 1);

	lclmn = mdlListModel_getColumnAtIndex(pListModel, REIN_LISTB_TRMV);
	mdlListColumn_setInfoFieldCount(lclmn, 1);
	lclmn = mdlListModel_getColumnAtIndex(pListModel, REIN_LISTB_TRMX);
	mdlListColumn_setInfoFieldCount(lclmn, 1);
	lclmn = mdlListModel_getColumnAtIndex(pListModel, REIN_LISTB_TRMO);
	mdlListColumn_setInfoFieldCount(lclmn, 1);
	lclmn = mdlListModel_getColumnAtIndex(pListModel, REIN_LISTB_TRMS);
	mdlListColumn_setInfoFieldCount(lclmn, 1);
	lclmn = mdlListModel_getColumnAtIndex(pListModel, REIN_LISTB_SAVE);
	mdlListColumn_setInfoFieldCount(lclmn, 1);


	rDopInfo.dopopt[7] = 0; // общее кол-во муфт

	int pnum = 0;
	ReinPos rpNull; // cleared in constr


	CatInfo& poscat = rmP->getCat();



	if (iCfgVar_SortPlus)
	{
		set<ReinPos, cmppos> setPos;

		// sorting...
		for (map<long, ReinPos>::iterator it = rmP->getPosMap().begin(); it != rmP->getPosMap().end(); ++it)
		{
			ReinPos* rpP = &(it->second);

			rpP->cmpopt[1] = getTrueEnd(&rpP->bar, 0);
			rpP->cmpopt[2] = getTrueEnd(&rpP->bar, 1);

			if (rpP->cmpopt[1]) rpP->cmpopt[0]++;
			if (rpP->cmpopt[2]) rpP->cmpopt[0]++;

			//// diameter (desc), vertex q-ty, terminators(q-ty,type1,type2), length
			//sprintf(pstr, "%05i-%05i-%05i-%05i-%05i-%05d", -rpP->bar.diam, rpP->bar.numpts, trmqty, trm[0], trm[1], rpP->file_ms_mid);

			rpP->mapind = it->first;

			setPos.insert(*rpP);

		}

		for (set<ReinPos, cmppos>::iterator it = setPos.begin(); it != setPos.end(); ++it)
		{
			ReinPos* rpP = (ReinPos*)&(*it);

			// для референсов пропускаем пустые позиции
			if (curPos_rn > 0 && rpP->bar.pnum == 0) continue;
			if (curPos_rn > 0 && rpP->file_qty_p == 0) continue;

			{
				// пустая строка
				if (abs(rpP->bar.pnum - pnum) > 1 && curPos_rn == 0 && pnum > 0)
				{
					double d;
					if (rpP->bar.pnum < pnum) d = (double)rpP->bar.pnum; else d = (double)pnum;
					posListAddRow(pListModel, &rpNull, false, -1, d + (double)(abs(rpP->bar.pnum - pnum) / 2), (poscat.iActive != -1));
				}

				posListAddRow(pListModel, rpP, true, rpP->mapind, (double)pnum, (poscat.iActive != -1));

				pnum = rpP->bar.pnum;
			}
		}

	}
	else
	{
		for (map<long, ReinPos>::iterator it = rmP->getPosMap().begin(); it != rmP->getPosMap().end(); ++it) 
		{
			ReinPos* rpP = &(it->second);

			// для референсов пропускаем пустые позиции
			if (curPos_rn > 0 && rpP->bar.pnum == 0) continue;
			if (curPos_rn > 0 && rpP->file_qty_p == 0) continue;

			rpP->mapind = it->first;

			{
				// пустая строка
				if (abs(rpP->bar.pnum - pnum) > 1 && curPos_rn == 0 && pnum > 0) 
				{
					double d;
					if (rpP->bar.pnum < pnum) d = (double)rpP->bar.pnum; else d = (double)pnum;
					posListAddRow(pListModel, &rpNull, false, -1, d + (double)(abs(rpP->bar.pnum - pnum) / 2), (poscat.iActive != -1));
				}

				posListAddRow(pListModel, rpP, true, rpP->mapind, (double)pnum, (poscat.iActive != -1));

				pnum = rpP->bar.pnum;
			}
		}
	}


	writeLogOut(__FUNCTION__, 0);


    return pListModel;
}

///////////////////////////////////////
long myListCell_getInfoFieldInt32(ListCell* pListCell, int index, StatusInt* gstP)
{
	StatusInt st = SUCCESS;
	long ind = 0;

	if (pListCell == NULL) return 0;

#if defined (MSVERSION) && (MSVERSION == 0xa00) // dialog items
	ind = mdlListCell_getInfoFieldInt32(pListCell, index, &st);
#else
	gst = mdlListCell_getInfoField(pListCell, index, &ind);
#endif

	*gstP = st;

	if (st != SUCCESS) ind = 0;

	return ind;
}

///////////////////////////
// func returns REIN_POSLIST_MODE_...
int getPosListMode()
{

//#define REIN_POSLIST_MODE_ENUM			0
//#define REIN_POSLIST_MODE_NUMSAVE			1
//#define REIN_POSLIST_MODE_DBSAVE			2
//#define REIN_POSLIST_MODE_CACHED			3
//#define REIN_POSLIST_MODE_DYNAMIC			4

	bool bNumsEmpty = true;

	for (map<long, ReinPos>::iterator it = curRM->getPosMap().begin(); it != curRM->getPosMap().end(); ++it)
	{
		if (it->second.bar.pnum > 0)
		{
			bNumsEmpty = false;
			break;
		}
	}


	int ret = REIN_POSLIST_MODE_ENUM;

	if (curPos_rn == 0) // active model
	{
		//if (curCat.catModID == 0)
		{
			if (enumCount)
			{
				// сохранение нумерации
				ret = REIN_POSLIST_MODE_NUMSAVE;
			}
			else
			{
				// нумерация
				ret = REIN_POSLIST_MODE_ENUM;
			}
		}
		//else // каталог определен
		//{
		//	if (enumCount)
		//	{
		//		// сохранение нумерации
		//		ret = REIN_POSLIST_MODE_NUMSAVE;
		//	}
		//	else // if (bNumsEmpty)
		//	{
		//		// нумерация
		//		ret = REIN_POSLIST_MODE_ENUM;
		//	}
		//	//else
		//	//{
		//	//	// слив в базу
		//	//	ret = REIN_POSLIST_MODE_DBSAVE;
		//	//}
		//}
	}
	else // reference
	{
		if (getReinCacheCount(&curPos_refpath) > 0)
		{
			// cached
			ret = REIN_POSLIST_MODE_CACHED;
		}
		else
		{
			// dynamic
			ret = REIN_POSLIST_MODE_DYNAMIC;
		}
	}

	return ret;


}

/////////////////////////////
void dialogPosList_checkButton(MSDLGP dbInP)
{
	MSDLGP dbP = dbInP;

	if (dbInP == NULL)	dbP = mdlDialog_find(DLG_POSLIST, NULL);

	if (dbP == NULL) return;

	char tct[100];
	WCH wtct[100];

	DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_PushButton, BUTTON_POSNUM, 0);
	DialogItem* diDbP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_PushButton, BUTTON_DBSAVE, 0);

	int imode = getPosListMode();

	if (diP)
	{

		if (imode == REIN_POSLIST_MODE_NUMSAVE)
		{
			strcpy(tct, TXT_18_00);
		}
		//else if (imode == REIN_POSLIST_MODE_DBSAVE)
		//{
		//	strcpy(tct, TXT_18);
		//}
		else if (imode == REIN_POSLIST_MODE_CACHED)
		{
			strcpy(tct, TXT_18_2);
		}
		else if (imode == REIN_POSLIST_MODE_DYNAMIC)
		{
			strcpy(tct, TXT_18_1);
		}
		else // if (imode == REIN_POSLIST_MODE_ENUM)
		{
			strcpy(tct, TXT_18_0);
		}

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		mdlCnv_convertMultibyteToUnicode(tct, -1, wtct, 100);
#else
		strcpy(wtct, tct);
#endif

		mdlDialog_itemSetLabel(dbP, diP->itemIndex, wtct);
	}


	if (diDbP)
	{
		int bEnable = FALSE;

		if (curPos_rn == 0) // active model
		{
			if (curCat.catModID > 0)
			{
				bEnable = TRUE;
			}
		}

		mdlDialog_itemSetEnabledState(dbP, diDbP->itemIndex, bEnable, TRUE);

	}

}


///////////////////////////////////
void hookComboRefShow(
	DialogItemMessage* dimP
)
{

	dimP->msgUnderstood = TRUE;

	ListModel* pListModel = NULL;

	switch (dimP->messageType)
	{

	case DITEM_MESSAGE_CREATE:
	{
		pListModel = (ListModel*)createListBoxRefs();
		mdlDialog_comboBoxSetListModelP(dimP->dialogItemP->rawItemP, pListModel);
		break;
	}

	case DITEM_MESSAGE_DESTROY:
	{
		pListModel = (ListModel*)mdlDialog_comboBoxGetListModelP(dimP->dialogItemP->rawItemP);
		mdlListModel_destroy(pListModel, TRUE);
		break;
	}
	case DITEM_MESSAGE_STATECHANGED:
	{
		syncShowInfo();

		//int          row, col;
		//RawItemHdr* rihP = mdlDialog_comboBoxGetListBoxP(dimP->dialogItemP->rawItemP);
		//if (rihP)
		//{
		//}

		break;
	}
	default:
		dimP->msgUnderstood = FALSE;
		break;
	}

	return;

}

/////////////////////////////////
wstring getCurRefShowPath()
{
	wstring refp = L"0";

	MSDLGP dbP = mdlDialog_find(DLG_PRESENT, NULL);

	if (dbP == NULL) return refp;

	DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ComboBox, COMBOBOX_SHOWPREF_REFS, 0);

	if (diP == NULL) return refp;

	int          row, col;

	RawItemHdr* rihP = mdlDialog_comboBoxGetListBoxP(diP->rawItemP);
	if (rihP)
	{
		ListModel* pListModel = NULL;
		ListCell* pListCell = NULL;

		if (SUCCESS == mdlDialog_listBoxLastCellClicked(&row, &col, rihP))
		{
			WCHCP_ v;
			pListModel = mdlDialog_listBoxGetListModelP(rihP);
			pListCell = mdlListModel_getCellAtIndexes(pListModel, row, 0); // get ref path
			if (mdlListCell_getStringValue(pListCell, &v) == SUCCESS)
			{
				long ind = myListCell_getInfoFieldInt32(pListCell, 0, &gst);
				if (gst == SUCCESS)
				{
					MSWCH str[100];
					SCPM2W(str, v, 100);

					refp = str;
				}
			}
		}
	}

	return refp;

}


///////////////////////////////////
void hookComboBoxItem(
DialogItemMessage   *dimP
)
{

    dimP->msgUnderstood= TRUE;

	ListModel   *pListModel = NULL;
	


    switch  (dimP->messageType)
    {

		case DITEM_MESSAGE_CREATE:
			{
			pListModel = (ListModel*)createListBoxRefs();
			mdlDialog_comboBoxSetListModelP (dimP->dialogItemP->rawItemP, pListModel);
			break;
			}

		case DITEM_MESSAGE_DESTROY:
			{
			pListModel = (ListModel*)mdlDialog_comboBoxGetListModelP (dimP->dialogItemP->rawItemP);
			mdlListModel_destroy (pListModel,TRUE);
			break;
			}
		case DITEM_MESSAGE_STATECHANGED:
			{
			int          row, col;

			RawItemHdr* rihP = mdlDialog_comboBoxGetListBoxP(dimP->dialogItemP->rawItemP);
			if (rihP) 
			{
				//ListModel*   pListModel = NULL;
				ListCell*    pListCell  = NULL;
				if (SUCCESS == mdlDialog_listBoxLastCellClicked (&row, &col, rihP))
				{
					WCHCP_ v;
					pListModel = mdlDialog_listBoxGetListModelP (rihP);
					pListCell  = mdlListModel_getCellAtIndexes (pListModel, row, 0); // get ref num
					if (mdlListCell_getStringValue(pListCell, &v) == SUCCESS)
					{
						if (mdlDialog_getID(dimP->db) == DLG_POSLIST)
						{
							long ind = myListCell_getInfoFieldInt32(pListCell, 0, &gst);
							if (gst == SUCCESS)
							{
								MSWCH str[100];
								SCPM2W(str, v, 100);
								curPos_refpath = str;
								curPos_rn = STOL(v);
								//curPos_rnn = ind;
								//if (arCurMrP[curPos_rn] && arCurMrP[curPos_rn][curPos_rnn])
								{
									ReinModel* rmP = curRM->getRM(curPos_refpath);
									if (rmP) rmP->reloadCurBars(
										false, // no elements scan
										false, // no update listbox (см ниже)
										iRefLvl, // nest depth
										iRefLvl, // load refs if > 0
										(rmP->mrci.catID == 0) // scan for saved positions if no link to catID
									);

									updateListBoxPos(FALSE);
								}

								dialogPosList_checkButton(dimP->db);

								//DialogItem* diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_PushButton, 4, 0);
								//if (diP) //mdlDialog_itemSetEnabledState(dimP->db, diP->itemIndex, (curCat.catModID != 0), TRUE);
								//{
								//	if (curPos_rn == 0)
								//		mdlDialog_itemSetLabel(dimP->db, diP->itemIndex, TXT_18);
								//	else
								//	{
								//		if (getReinCacheCount(curPos_rn) > 0)
								//			mdlDialog_itemSetLabel(dimP->db, diP->itemIndex, TXT_18_2);
								//		else
								//			mdlDialog_itemSetLabel(dimP->db, diP->itemIndex, TXT_18_1);
								//	}
								//}
							}
						}
					}
				}
			}

			break;
			}
		default:
			dimP->msgUnderstood=FALSE;
			break;
    }

    return ;
}



///////////////////////////////////
// func: hook pos list
void hookListBoxItem(
DialogItemMessage   *dimP
)
{

    dimP->msgUnderstood= TRUE;

	ListModel   *pListModel = NULL;
	
	ReinPos* rpP = NULL;
	ReinModel* rmP = NULL;

    switch  (dimP->messageType)
    {

		case DITEM_MESSAGE_CREATE:
			{
			curPos_rn = 0;
			//curPos_rnn = 0;

			int res = mdlResource_openFile(&rfRein, L("rein.rsc"), RSC_READONLY);
			if (res != SUCCESS)
			{
				mdlOutput_messageCenterW(MESSAGE_INFO, L"cannot open file rein.rsc", 
					L"cannot open file rein.rsc, check your configuration", MESSAGE_ALERT_BALLOON);
				rfRein = NULL;
			}

			pListModel = (ListModel*)createListBoxPos(iListColsNum);
			mdlDialog_listBoxSetListModelP (dimP->dialogItemP->rawItemP, pListModel, iListColsNum);
			break;
			}

		case DITEM_MESSAGE_DESTROY:
			{
			mdlLocate_clearHilited(TRUE);
			pListModel = (ListModel*)mdlDialog_listBoxGetListModelP (dimP->dialogItemP->rawItemP);
			mdlListModel_destroy (pListModel,TRUE);
			daCurPosExcl.clear();
			//iFPcount = 0;
			//iIDcount = 0;
			// erase vectors...
			curRM->vExIds.clear();
			curRM->vExFps.clear();

			if (rfRein)
			{
				mdlResource_closeFile(rfRein);
				rfRein = NULL;
			}

			//curPosP = NULL;
			break;
			}

		case DITEM_MESSAGE_BUTTON:

			if (BUTTONTRANS_UP == dimP->u.button.buttonTrans)
			{
				//ListModel*   pListModel = NULL;
				ListCell*    pListCell  = NULL;
				int          row, col;
				//	Get cell coordinate on single- or double-click
				if (SUCCESS == mdlDialog_listBoxLastCellClicked (&row, &col, dimP->dialogItemP->rawItemP))
				{
					pListModel = mdlDialog_listBoxGetListModelP (dimP->dialogItemP->rawItemP);
					pListCell  = mdlListModel_getCellAtIndexes (pListModel, row, REIN_LISTB_POSN);

					long i = myListCell_getInfoFieldInt32(pListCell, 0, &gst);
					if (gst != SUCCESS) break;
					//if (i == -1) break;

					rmP = curRM->getRM(curPos_refpath);

					if (rmP)
					{
						map<long, ReinPos>::iterator it = rmP->getPosMap().find(i);

						if (it != rmP->getPosMap().end()) // found
						{
							//rpP = &rmP->getPosMap()[i];
							
							curPos = it->second;
							curPos_ind = i;
							//curPosP = rpP;
						}
						else
							break;
					}
					else
						break;
				}
				else
					break;

				if ((dimP->u.button.upNumber == 1) && dimP->u.button.clicked)
				{  //	Action on single-click

					ListCell* lc;
					ListRow* lr;
					long i = -1;
					IcnRsc* icrsc1 = NULL;
					IcnRsc* icrsc2 = NULL;
					int bSaveInfo = FALSE;

					lc = mdlListModel_getCellAtIndexes(pListModel, row, col);
					lr = mdlListModel_getRowAtIndex(pListModel, row);

					// ===== SHIFT =====

					int rr[2];

					if (dimP->u.button.qualifierMask == 4) // shift
					{
						if (shift[0] == -1) shift[0] = row;
						shift[1] = row;
					}
					else
					{
						shift[0] = row;
						shift[1] = -1;
					}

					if (shift[0] > -1 && shift[1] > -1 && shift[0] != shift[1])
					{
						if (shift[0] < shift[1])
						{
							rr[0] = shift[0];
							rr[1] = shift[1];
						}
						else
						{
							rr[0] = shift[1];
							rr[1] = shift[0];
						}
					}
					else
					{
						rr[0] = row;
						rr[1] = row;
					}

					// =================


					// sync drawopt to curPos
					for (vector<ReinPos>::iterator rpItP = daCurPosHide.begin(); rpItP != daCurPosHide.end(); ++rpItP)
					{
						wstring str = curRM->getRefPathString(&rpItP->arefnum);

						if (rpItP->bar.pnum == curPos.bar.pnum
							//&& !rpItP->arefnum.empty()
							//&& rpItP->arefnum.back() == curPos_rn
							//&& (rpItP->arefnum[0] == curPos_rn)
							&& (str == curPos_refpath)
							)
						{
							curPos.drawopt = rpItP->drawopt;
							break;
						}
					}


					if (col == REIN_LISTB_SAVE && curPos.bar.pnum > 0)
					{
						i = myListCell_getInfoFieldInt32(lc, 0, &gst);
						if (gst == SUCCESS && 
							curPos_rn == 0)// сохраняем только в активной
						{
							if (i == 1) // save
							{
								if (savePosition(&curPos, TRUE, TRUE) == SUCCESS)
								{
									for (map<long, ReinPos>::iterator it = rmP->getPosMap().begin(); it != rmP->getPosMap().end(); ++it)
									{
										if (it->second.bar.pnum == curPos.bar.pnum)
										{
											curPos.bar_mem.clear();

											rmP->getPosMap()[it->first] = curPos;
										}
									}

									//loadFilePositions();
									//loadAllPositions();
									//reloadCurBars(ACTIVEMODEL, false);

									rmP->updateModelElmNumbers(true); // зачем обновлять номера?

									mdlListCell_setInfoFieldInt32(lc, 0, 0);
									mdlListCell_setIconRsc(lc, NULL);

								}
							}
						}
					}

					if (col == REIN_LISTB_TRMV && curPos.bar.pnum > 0)
					{
						i = myListCell_getInfoFieldInt32(lc, 0, &gst);
						if (gst != SUCCESS) i = -1;
						if (rfRein) icrsc1 = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 8);
						if (rfRein) icrsc2 = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 9);
						curPos.drawopt[DROPT_V] = i;
						bSaveInfo = TRUE;
					}

					if (col == REIN_LISTB_TRMX && curPos.bar.pnum > 0)
					{
						i = myListCell_getInfoFieldInt32(lc, 0, &gst);
						if (gst != SUCCESS) i = -1;
						if (rfRein) icrsc1 = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 12);
						if (rfRein) icrsc2 = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 13);
						curPos.drawopt[DROPT_X] = i;
						bSaveInfo = TRUE;
					}

					if (col == REIN_LISTB_TRMO && curPos.bar.pnum > 0)
					{
						i = myListCell_getInfoFieldInt32(lc, 0, &gst);
						if (gst != SUCCESS) i = -1;
						if (rfRein) icrsc1 = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 10);
						if (rfRein) icrsc2 = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 11);
						curPos.drawopt[DROPT_O] = i;
						bSaveInfo = TRUE;
					}

					if (col == REIN_LISTB_TRMS && curPos.bar.pnum > 0)
					{
						i = myListCell_getInfoFieldInt32(lc, 0, &gst);
						if (gst != SUCCESS) i = -1;
						if (rfRein) icrsc1 = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 14);
						if (rfRein) icrsc2 = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 15);
						curPos.drawopt[DROPT_S] = i;
						bSaveInfo = TRUE;
					}

					if (col == REIN_LISTB_SHOW && curPos.bar.pnum > 0)
					{
						RscId iIcon;
						RscType iIconType;

						ListCell* slc = mdlListModel_getCellAtIndexes(pListModel, row, REIN_LISTB_SHOW);
						mdlListCell_getIcon(slc, &iIcon, &iIconType, NULL);

						if (iIcon == ICONID_ToggleOn14Pt) 
							iIcon = ICONID_ToggleOff14Pt; 
						else if (iIcon == ICONID_ToggleOff14Pt) 
							iIcon = ICONID_ToggleOn14Pt; 

						for (int ii = rr[0]; ii <= rr[1]; ii++)
						{

							ListCell* pnlc  = mdlListModel_getCellAtIndexes (pListModel, ii, REIN_LISTB_POSN);
							ListCell* clc = mdlListModel_getCellAtIndexes(pListModel, ii, REIN_LISTB_SHOW);

							long iarpos = myListCell_getInfoFieldInt32(pnlc, 0, &gst);
							if (gst != SUCCESS) continue;
							//if (iarpos == -1) continue;

							//ReinModel* rmP = curRM->getRM(curPos_rn);

							if (rmP)
							{
								ReinPos* rppP = NULL;

								map<long, ReinPos>::iterator it = rmP->getPosMap().find(iarpos);

								if (it != rmP->getPosMap().end()) // found
								{
									//rppP = &rmP->getPosMap()[iarpos];
									rppP = &(it->second);
								}
								else
									continue;

								if (rppP)
								{
									if (iIcon == ICONID_ToggleOn14Pt) 
										rppP->drawopt[DROPT_A] = 1;
									else if (iIcon == ICONID_ToggleOff14Pt) 
										rppP->drawopt[DROPT_A] = 0;

									mdlListCell_setIcon(clc, iIcon, RTYPE_Icon, NULL);

									saveHidePosInfo(rppP);
								}
							}
						}
						mdlDialog_listBoxDrawContents(dimP->dialogItemP->rawItemP, -1, REIN_LISTB_SHOW);

						if (shift[0] > -1 && shift[1] > -1)
						{
							shift[0] = -1;
							shift[1] = -1;
						}

						//bSaveInfo = TRUE;

						i = -1;
					}

					if (col == REIN_LISTB_EXCL)
					{
						RscId  iIcon;
						RscType iIconType;
						int iShow;

						ListCell* clc = mdlListModel_getCellAtIndexes(pListModel, shift[0], REIN_LISTB_EXCL);

						mdlListCell_getIcon(clc, &iIcon, &iIconType, NULL);

						if (rr[0] == rr[1])
						{
							if (iIcon == ICONID_ToggleOn14Pt) 
							{
								iIcon = ICONID_ToggleOff14Pt; 
								iShow = 0;
							}
							else if (iIcon == ICONID_ToggleOff14Pt) 
							{
								iIcon = ICONID_ToggleOn14Pt; 
								iShow = 1;
							}
							else
								break;
						}
						else
						{
							if (iIcon == ICONID_ToggleOn14Pt)
								iShow = 1;
							else if (iIcon == ICONID_ToggleOff14Pt)
								iShow = 0;
							else
								break;
						}



						for (int ii = rr[0]; ii <= rr[1]; ii++)
						{
							RscId  iIcon2;

							clc = mdlListModel_getCellAtIndexes(pListModel, ii, REIN_LISTB_EXCL);

							mdlListCell_getIcon(clc, &iIcon2, &iIconType, NULL);

							if (!(iIcon2 == ICONID_ToggleOn14Pt || iIcon2 == ICONID_ToggleOff14Pt))
								continue;

							i = myListCell_getInfoFieldInt32(clc, 0, &gst);

							if (gst == SUCCESS)
							{
								//ReinModel* rmP = curRM->getRM(curPos_rn);

								mdlListCell_setIcon(clc, iIcon, RTYPE_Icon, NULL);

								if (rmP)
								{
									if (iShow)
									{
										ReinExcl rex;
										ReinExcl* rexP = &rex;
										rexP->ind = i;
										rexP->ref = curPos_refpath;
										daCurPosExcl.push_back(rex);
									}
									else
									{
										for (vector<ReinExcl>::iterator rexP = daCurPosExcl.begin(); rexP != daCurPosExcl.end();)
										{
											ReinExcl* exP = &*rexP;

											if (exP->ind == i && exP->ref == curPos_refpath)
											{
												daCurPosExcl.erase(rexP);
											}
											else
												++rexP;

										}
									}


									if (iShow)
									{
										for (map<UInt32, ReinElm>::iterator it = rmP->mapElms.begin(); it != rmP->mapElms.end(); ++it)
										{
											ReinElm* reP = &(it->second);
											if (reP && reP->arNum == i)
											{
												//rmP->vExIds.push_back(reP->bel.elemid);
												//rmP->vExFps.push_back(reP->bel.ffpos[REIN_ELEM_ISO]);

												rmP->vExIds[reP->bel.elemid] = true;
												rmP->vExFps[reP->bel.ffpos[REIN_ELEM_ISO]] = true;

												ELREF eref = getElemRefByID(reP->bel.modrefP, reP->bel.brid);
												if (eref)
												{
													UInt32 barfpos = elementRef_getFilePos(eref);
													//rmP->vExFps.push_back(barfpos);
													reP->bel.ffpos[REIN_ELEM_BAR] = barfpos;
													rmP->vExFps[reP->bel.ffpos[REIN_ELEM_BAR]] = true;
												}

											}
										}
									}
									else
									{
										for (map<UInt32, ReinElm>::iterator ite = rmP->mapElms.begin(); ite != rmP->mapElms.end(); ++ite)
										{
											ReinElm* reP = &(ite->second);

											if (reP && reP->arNum == i)
											{
												rmP->vExIds[reP->bel.elemid] = false;

												/*
												for (map<ELID,bool>::iterator it = rmP->vExIds.begin() ; it != rmP->vExIds.end();)
												{
													if (it->first == reP->bel.elemid)
														rmP->vExIds.erase(it);
													else
														++it;
												}*/


												rmP->vExFps[reP->bel.ffpos[REIN_ELEM_ISO]] = false;
												rmP->vExFps[reP->bel.ffpos[REIN_ELEM_BAR]] = false;

												/*
												for (vector<UInt32>::iterator it = rmP->vExFps.begin() ; it != rmP->vExFps.end();)
												{
													if (*it == reP->bel.ffpos[REIN_ELEM_ISO])
														rmP->vExFps.erase(it);
													else if (*it == reP->bel.ffpos[REIN_ELEM_BAR])
														rmP->vExFps.erase(it);
													else
														++it;
												}*/

											}
										}
									}
								}
							}

						}


						mdlDialog_listBoxDrawContents(dimP->dialogItemP->rawItemP, -1, col);


						//setExPos(iShow);


						i = -1;
					}

					if (bSaveInfo) saveHidePosInfo(&curPos);


					if (col != REIN_LISTB_SAVE && mdlListRow_getStatus(lr) != LISTCELLATTR_DISABLED)
					{
						if (i == 1) 
						{
							i = 0;
							mdlListCell_setIconRsc(lc, icrsc2);
						}
						else if (i == 0)
						{
							i = 1;
							mdlListCell_setIconRsc(lc, icrsc1);
						}

						if (i >= 0) mdlListCell_setInfoFieldInt32(lc, 0, i);
					}




					if (i >= 0) mdlDialog_listBoxDrawContents(dimP->dialogItemP->rawItemP, -1, col);
/*
					if (icrsc1) mdlResource_free(icrsc1);
					if (icrsc2) mdlResource_free(icrsc2);
*/

				}
				else if ((2 == dimP->u.button.upNumber) && dimP->u.button.clicked)
				{  //	Action on double-click

					ListRow* lr = mdlListModel_getRowAtIndex(pListModel, row);

					if (mdlListRow_getStatus(lr) != LISTCELLATTR_DISABLED)
					{

						if (col == REIN_LISTB_EXST && curPos_rn == 0)
						{
							UShort          typeMask[6];

							for (UShort a = 0; a < 6; a++) typeMask[a] = 0;

							typeMask[0] = TMSK0_LINE | 
											TMSK0_ARC | 
											//TMSK0_CELL_HEADER | // убрано, так как захватвает много лишних элементов
											TMSK0_LINE_STRING | 
											TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;

							mdlSelect_freeAll();


							ScanCriteria* scP = mdlScanCriteria_create();
							mdlScanCriteria_setReturnType (scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
							mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)iterateSelectPos, NULL);
							mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
							mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);
							mdlScanCriteria_setModel (scP, ACTIVEMODEL);
							mdlScanCriteria_scan (scP,NULL,NULL,NULL);
							mdlScanCriteria_free (scP);




						}
						else
							reinHilitePos(&curPos);
					}

				}
			}
			break;

        case DITEM_MESSAGE_USER:   
			//printf("DITEM_MESSAGE_USER\n");
			{
				//long row, col;
				//ListCell* lc;
				//char v[100];

				//pListModel = mdlDialog_listBoxGetListModelP (dimP->dialogItemP->rawItemP);
				//mdlDialog_listBoxGetLocationCursor(&row, &col, dimP->dialogItemP->rawItemP);

				//lc = mdlListModel_getCellAtIndexes(pListModel, row, col);

				//sprintf(v, "%i", elList.rs.space);

				//mdlListCell_setStringValue (lc,v,TRUE);


			}
			break;

		case DITEM_MESSAGE_STATECHANGED:
			{
				//char* str;
				int row, col;
				////int index;
				////int iSystem;
				//ELID elid;
				//ULong refNum;
				//int res;
				//DgnModelRefP mrP = MASTERFILE;

				////mdlSystem_enterDebug();

				//mdlLocate_clearHilited(TRUE);


				//ListModel*   pListModel = NULL;
				ListCell*    pListCell  = NULL;
				//	Get cell coordinate on single- or double-click
				if (SUCCESS == mdlDialog_listBoxGetLocationCursor(&row, &col, dimP->dialogItemP->rawItemP))
				{
					pListModel = mdlDialog_listBoxGetListModelP (dimP->dialogItemP->rawItemP);
					pListCell  = mdlListModel_getCellAtIndexes (pListModel, row, REIN_LISTB_POSN);
				}




				//lc = mdlListModel_getCellAtIndexes(pListModel, row, 10);
				//res = mdlListCell_getStringValue(lc, &str);
				//elid = atol(str);

				//lc = mdlListModel_getCellAtIndexes(pListModel, row, 0);
				//res = mdlListCell_getStringValue(lc, &str);
				//refNum = atol(str);

				//if (refNum > 0)
				//{
				//	ModelRefIteratorP  iterator;
				//	DgnModelRefP	modelRef;

				//	mdlModelRefIterator_create (&iterator, MASTERFILE, MRITERATE_PrimaryChildRefs, 0);

				//	while (NULL != (modelRef = mdlModelRefIterator_getNext (iterator)))
				//	{
				//		ReferenceFile* rfP;

				//		rfP = mdlRefFile_getInfo(modelRef);

				//		if (rfP == NULL) continue;

				//		if (refNum == rfP->file_id.referenceNum)
				//		{
				//			mrP = rfP->file_id.modelRef;
				//			break;
				//		}
				//	}
				//	mdlModelRefIterator_free (&iterator);
				//}






				long i;

				rmP = curRM->getRM(curPos_refpath);

				if (rmP)
				{
					i = myListCell_getInfoFieldInt32(pListCell, 0, &gst);
					if (gst != SUCCESS) break;
					//if (i == -1) break;

					rpP = &rmP->getPosMap()[i];

					curPos = *rpP;
					//curPosP = rpP;

					ipnsave = curPos.bar.pnum;

					DialogItem* diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_Generic, 2, 0);
					if (diP) mdlDialog_itemDraw(dimP->db, diP->itemIndex);

					{
						MSDLGP db7 = mdlDialog_find (DLG_SKETCH, NULL);
						if (db7)
						{
							diP = mdlDialog_itemGetByTypeAndId(db7, RTYPE_Generic, 3, 0);
							if (diP) mdlDialog_itemDraw(db7, diP->itemIndex);
						}
					}
					
					diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_Label, 1, 0);
					if (diP) 
					{
						WCH sv[2000] = L("");
						WCH svv[1000] = L("");

						//ZeroMemory(sv, sizeof(sv));

						if (rpP->bar.runmet == 1)
							SPRN(svv, L("%s %.1f / %s %.1f"), TXT_100, rpP->base_qty, TXT_101, rpP->file_qty_rm);
						else
							SPRN(svv, L("%s %.0f / %s %i"), TXT_100, rpP->base_qty, TXT_101, rpP->file_qty_p);

						SCPY(sv, svv);

						if (rpP->bar.runmet > 1)
						{
							SPRN(svv, L("     max %i / %i"), rpP->base_ms_max, rpP->file_ms_max);
							SCAT(sv, svv);
							SPRN(svv, L("     mid %i / %i"), rpP->base_ms_mid, rpP->file_ms_mid);
							SCAT(sv, svv);
							SPRN(svv, L("     min %i / %i"), rpP->base_ms_min, rpP->file_ms_min);
							SCAT(sv, svv);
						}

						if (rpP->bar_mem.diam > 0 && rpP->bar_mem.diam != rpP->bar.diam)
						{
							SPRN(svv, L("    diameter %i / %i"), rpP->bar_mem.diam, rpP->bar.diam);
							SCAT(sv, svv);
						}

						mdlDialog_itemSetLabel(dimP->db, diP->itemIndex, sv);
					}
/*
					diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_Label, 2, 0);
					if (diP) 
					{
						char sv[1000];

						strcpy(sv, "exist:\t");

						if (rpP->bar.runmet == 1)
							sprintf(s, "run %.1f", rpP->file_qty_rm);
						else
							sprintf(s, "pcs %i", rpP->file_qty_p);

						strcat(sv, s);

						if (rpP->bar.runmet > 1)
						{
							sprintf(s, "\tmax %i", rpP->file_ms_max);
							strcat(sv, s);
							sprintf(s, "\tmid %i", rpP->file_ms_mid);
							strcat(sv, s);
							sprintf(s, "\tmin %i", rpP->file_ms_min);
							strcat(sv, s);
						}

						mdlDialog_itemSetLabel(dimP->db, diP->itemIndex, sv);
					}
*/


					//reinHilitePos(&curPos);
				}



				break;
			}

		default:
			dimP->msgUnderstood=FALSE;
			break;
    }

    return ;
}

/*
///////////////////////
bool sortPosFunc(const ReinPos &arg1, const ReinPos &arg2)
{
	bool bret = false;

	writeLogIn(__FUNCTION__, 0);

	if (iDebug) sprintf(sLogMes, "pnums %i %i\n", arg1.bar.pnum, arg2.bar.pnum); writeLog(0, 0);

	if (arg1.bar.pnum > 0 || arg2.bar.pnum > 0)
	{
		if (arg1.bar.pnum < arg2.bar.pnum)
			bret = true;
		else
			bret = false;
	}
	else
	{
		if (arg1.bar.diam > arg2.bar.diam) // обратная по диаметру
			bret = true;
		else
			bret = false;
	}

	writeLogOut(__FUNCTION__, 0);

	return bret;
}
*/

//////////////////
// приведение информации позиций в соотвествие
void setPosArrayInfo(ReinModel* rmP, bool bScan)
{

	if (rmP == NULL) return;

	writeLogIn(__FUNCTION__, 0);


	ReinPos* rpItP = NULL;

	for (map<long, ReinPos>::iterator it = rmP->getPosMap().begin(); it != rmP->getPosMap().end(); ++it)
	{
		int doplen = 0;
		long aPerem[MAX_BAR_LENS] = { 0 };

		//ZeroMemory(aPerem, sizeof(aPerem));

		rpItP = &it->second;

		rpItP->file_ms_min = 0;
		rpItP->file_ms_mid = 0;
		rpItP->file_ms_max = 0;

		if (iCfgVar_BendNewDraw != 2)
		{
			if (rpItP->bar.term[0] == REIN_TERM_BEND) doplen += rpItP->bar.termPar[1][0];
			if (rpItP->bar.term[1] == REIN_TERM_BEND) doplen += rpItP->bar.termPar[1][1];
		}

		for (int j = 0; j < rpItP->bar.numlen; j++)
		{
			rpItP->file_ms_min += rpItP->bar.blen[j][0];
			rpItP->file_ms_mid += rpItP->bar.blen[j][1]; // rpItP->file_qty_p - делениме см ниже
			rpItP->file_ms_max += rpItP->bar.blen[j][2];

			if (rpItP->bar.runmet > 1 && rpItP->bar.blen[j][0] != rpItP->bar.blen[j][2])
				aPerem[j] = (rpItP->bar.blen[j][0] + rpItP->bar.blen[j][2]) / 2; // средняя длина на сегмент
		}

		if (rpItP->file_qty_p > 0 && rpItP->bar.runmet > 1) 
			rpItP->file_ms_mid = roundExt(((double)rpItP->file_ms_mid / (double)rpItP->file_qty_p), ROUND_LIN);

		rpItP->file_ms_min += doplen;
		rpItP->file_ms_mid += doplen;
		rpItP->file_ms_max += doplen;

		// приводим эскиз переменных в порядок
		for (int j = 0; j < rpItP->bar.numlen; j++)
		{ 
			if (aPerem[j])
			{
				setSegmLength(rpItP->bar.apts, rpItP->bar.cnumpts, j, (double)aPerem[j]);
				//DVec3d* ap = &rpItP->bar.apts[0];
				//setSegmLength(ap, rpItP->bar.apts.size(), j, (double)aPerem[j]);
			}
		}
	}

	if (bScan)
	{
		// расстановка номеров в массиве arCurElms
		writeLog("go to updateModelElmNumbers()...", 0, 0, 1);
		rmP->updateModelElmNumbers(false);

	}

	writeLogOut(__FUNCTION__, 0);


}
	


//////////////////////////////////
void updateListBoxPos(int bKeepSelection)
{

	MSDLGP pDb;
    DialogItem      *pListBoxItem;
	ListModel   *pListModel=NULL;
	int row, col;
	int rng[4] = {0};



	//ZeroMemory(rng, sizeof(rng));

    if (NULL == (pDb = mdlDialog_find (DLG_POSLIST, NULL)))
        return;
    if (NULL == (pListBoxItem = mdlDialog_itemGetByTypeAndId (pDb, RTYPE_ListBox, 1, 0)))
        return;
    if (NULL == (pListModel = mdlDialog_listBoxGetListModelP(pListBoxItem->rawItemP)))
        return;


	writeLogIn(__FUNCTION__, 0); // updateListBoxPos in


	if (bKeepSelection) 
	{
		mdlDialog_listBoxGetDisplayRange(&rng[0], &rng[1], &rng[2], &rng[3], pListBoxItem->rawItemP);
		mdlDialog_listBoxGetLocationCursor(&row, &col, pListBoxItem->rawItemP);
	}

	mdlListModel_destroy(pListModel, FALSE);

	pListModel = createListBoxPos(iListColsNum);


	mdlDialog_listBoxSetListModelP (pListBoxItem->rawItemP, pListModel, iListColsNum);

	//mdlDialog_listBoxSetLocationCursor(pListBoxItem->rawItemP, row, col);
	if (bKeepSelection) 
	{
		mdlDialog_listBoxMakeRowVisible(pListBoxItem->rawItemP, rng[1]);
		mdlDialog_listBoxSelectCells(pListBoxItem->rawItemP, row, row, col, col, TRUE, TRUE);
	}

	//{
	//	DialogItem* diP = mdlDialog_itemGetByTypeAndId(pDb, RTYPE_PushButton, 4, 0);
	//	if (diP) mdlDialog_itemSetEnabledState(pDb, diP->itemIndex, (curCat.catModID != 0), TRUE);
	//}

	mdlDialog_itemsSynch(pDb);

	writeLogOut(__FUNCTION__, 0); // updateListBoxPos out

}

/////////////////////////////////
ListModel* getPosListModel(RawItemHdr** rihP)
{
	MSDLGP pDb = NULL;
	DialogItem      *pListBoxItem;
	ListModel   *pListModel = NULL;

	if (NULL == (pDb = mdlDialog_find (DLG_POSLIST, NULL)))
		return NULL;
	if (NULL == (pListBoxItem = mdlDialog_itemGetByTypeAndId (pDb, RTYPE_ListBox, 1, 0)))
		return NULL;
	if (NULL == (pListModel = mdlDialog_listBoxGetListModelP(pListBoxItem->rawItemP)))
		return NULL;

	*rihP = pListBoxItem->rawItemP;

	return pListModel;

}

/////////////////////////////////
void setListBoxPosRow(ListModel* lmP, int ind, RawItemHdr* rihP)
{
	ListCell* pCell = NULL;
	IcnRsc* irsc = NULL;


	ListRow* lrP = mdlListModel_getRowAtIndex(lmP, ind);

	if (lrP) pCell = mdlListRow_getCellAtIndex (lrP, REIN_LISTB_EXST);


	if (rfRein) irsc = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 7);


	if (irsc && pCell)
	{
		mdlListCell_setIconRsc(pCell, irsc);
		mdlDialog_listBoxMakeRowVisible(rihP, ind);
	}

	if (irsc) mdlResource_free(irsc);

	
}

////////////////////////////////////////
BINT listModelSearchFunc
(
#if defined (MSVERSION) && (MSVERSION == 0xa00) // dialog items
ListModelP pModel,
MSValueDescrCP pValueDescr,
InfoField *pInfoFields,
ListRowP pRow,
int columnIndex
#else
 ListModel   *pModel,        // => The ListModel to process 
 ValueDescr  *pValueDescr,   // => Value of data to search for (if string, use value.charPFormat) 
 long        *pInfoFields,   // => InfoFields to search for 
 ListRow     *pRow,          // => ListRow in question 
 int         columnIndex     // => columnIndex passed from mdlListModel_search 
#endif
 )
 {

	 ListCell* pCell = mdlListRow_getCellAtIndex(pRow, columnIndex);

	 long info = myListCell_getInfoFieldInt32(pCell, 0, &gst);
	 if (pCell && gst == SUCCESS)
	 {
		 if (pInfoFields[0] == info) return TRUE;
	 }

	 return FALSE;
 }

/////////////////////////////////////////
 void updateListBoxColumn(ListModel* pListModel, int iColNum)
 {

	ListRow* pRow;
	ListCell    *pCell;
	long info;

	writeLogIn(__FUNCTION__, 0);

    for (pRow = mdlListModel_getFirstRow (pListModel); pRow; pRow = mdlListModel_getNextRow (pListModel, pRow))
    {

        pCell = mdlListRow_getCellAtIndex (pRow, REIN_LISTB_EXST);

		info = myListCell_getInfoFieldInt32(pCell, 0, &gst);
		if (gst == SUCCESS)
		{
			if (info > 0)
			{
				mdlListCell_setIcon(pCell, (int)info, RTYPE_Icon, mdlSystem_getCurrMdlDesc());
			}
		}
   }


	writeLogOut(__FUNCTION__, 0);

 }

//////////////////////////////////////////////////////////////////////
 int isReinElemInner(int barnum, int barqty, int lapbeg, int lapend, bool bgnd)
 {

	if (lapbeg || lapend)
	{
		if (barnum > 2 && barnum < barqty - 1)
			return !bgnd;
		else
			return FALSE;
	}
	else
	{
		if (barnum > 1 && barnum < barqty)
			return !bgnd;
		else
			return FALSE;
	}


 }

//////////////////////////////////////
 void reinHilitePos(ReinPos* rpP)
 {

	DgnModelRefP mrP = NULL;

	CatInfo ci;

	mdlLocate_clearHilited(TRUE);

	UShort          typeMask[6];

	for (UShort a = 0; a < 6; a++) typeMask[a] = 0;

	typeMask[0] = TMSK0_LINE | 
					TMSK0_ARC | 
					//TMSK0_CELL_HEADER | // убрано, так как захватвает много лишних элементов
					TMSK0_LINE_STRING | 
					TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;

	//mdlTMatrix_getIdentity (&tmFromRef);


	//curPos_rn, rnn - текущий референс списка (позиции разреза) = 0, 1, 2, 3, ...


	ReinModel* rmP = curRM->getRM(curPos_refpath);

	if (rmP)
	{
		//ModelRefIteratorP  iterator;
		//DgnModelRefP	modelRef;
		//mdlModelRefIterator_create (&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, 0);
		//while (NULL != (modelRef = mdlModelRefIterator_getNext (iterator)))
		//{
		//	if (curPos_refnum == getRefNum(modelRef)) 
		//	{
		//		mrP = modelRef;
		//		break;
		//	}
		//}
		//mdlModelRefIterator_free (&iterator);

		mrP = rmP->modelP;

	}


	if (mrP == NULL) return;

	getCatInfo(&ci, mrP, false);

	ScanCriteria* scP = mdlScanCriteria_create();
	mdlScanCriteria_setReturnType (scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)iterateHilitePos, &ci);
	mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
	mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);
	mdlScanCriteria_setModel (scP, mrP);
	mdlScanCriteria_scan (scP,NULL,NULL,NULL);
	mdlScanCriteria_free (scP);

/*
	if (curPos_refnum < 0) // was soll das heisst?
	{

		ModelRefIteratorP  iterator;
		DgnModelRefP	modelRef;

		mdlModelRefIterator_create (&iterator, MASTERFILE, MRITERATE_PrimaryChildRefs, 0);

		while (NULL != (modelRef = mdlModelRefIterator_getNext (iterator)))
		{

			int iselem = FALSE;
			mdlRefFile_getParameters(&iselem, REFERENCE_TREAT_AS_ELEMENT, modelRef);
			if (iselem == FALSE) // пропускаем каркасы
			{

				getCatInfo(&ci, modelRef, false);

				//mdlTMatrix_referenceToMaster (&tmFromRef, modelRef);

				ScanCriteria* scP = mdlScanCriteria_create();
				mdlScanCriteria_setReturnType (scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
				mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)iterateHilitePos, &ci);
				mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
				mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);
				mdlScanCriteria_setModel (scP, modelRef);
				mdlScanCriteria_scan (scP,NULL,NULL,NULL);
				mdlScanCriteria_free (scP);
			}
		}
		mdlModelRefIterator_free (&iterator);
	}
*/

 }

//////////////////////////////
 void reinSelectPosRow(int num)
 {

	{
		RawItemHdr* rihP = NULL;
		ListModel* lmP = getPosListModel(&rihP);

		writeLogIn(__FUNCTION__, 0);

		updateListBoxColumn(lmP, REIN_LISTB_EXST);

		if (lmP)
		{
			int ind = 0;
			InfoField  info = num;
			if (mdlListModel_searchUsingFunction(lmP, 
											NULL, &info, 
											0, -1, REIN_LISTB_POSN, 
											listModelSearchFunc, mdlSystem_getCurrMdlDesc(), 
											&ind) == SUCCESS)
			{
				setListBoxPosRow(lmP, ind, rihP);
			}

			mdlDialog_listBoxDrawContents(rihP, -1, REIN_LISTB_EXST);

		}

		writeLogOut(__FUNCTION__, 0);

	}

 }

///////////////////////////
void	hookPosition(
DialogItemMessage   *dimP
)
{
    dimP->msgUnderstood = TRUE;

    switch (dimP->messageType)
	{
	case DITEM_MESSAGE_CREATE:
	    {
	    dimP->dialogItemP->attributes.acceptsKeystrokes = FALSE;
	    dimP->dialogItemP->attributes.mouseSensitive    = FALSE;
	    break;
	    }

        case DITEM_MESSAGE_DRAW:
	    {
            BSIRect   clipRect;

			writeLogIn(__FUNCTION__, 0);

			BSIColorDescr   *bgColorP = NULL;

			clipRect = dimP->dialogItemP->rect;
			//mdlDialog_rectInset (&clipRect, -2, -2);
			mdlDialog_rectDrawBeveled (dimP->db, &clipRect, FALSE, TRUE);

			mdlColorDescr_setByMenuColor(bgColorP, LGREY_INDEX);
			mdlDialog_rectFillCD (dimP->db, &dimP->dialogItemP->rect, &dimP->dialogItemP->rect, bgColorP, NULL);

			reinListBoxDrawPos(dimP->db, dimP->dialogItemP);

			writeLogOut(__FUNCTION__, 0);

			break;
	    }
    
	default:
	    dimP->msgUnderstood = FALSE;
	    break;
	}
}

///////////////////////////////////////
void prepareSketchPoints(DVec3d* ptsh, int numpts, double prefWdt, double prefHgt, int bUnrot)
{

	writeLogIn(__FUNCTION__, 0);


	double dst = 0.;
	double dist = 0.;
	double dist_min = 1e+40;
	double dist_mid = 0.;
	double dist_max = 0.;
	double k = 1.0;

	double x[2] = {0.,0.};
	double y[2] = {0.,0.};

	double dXsc = 1.;
	double dYsc = 1.;

	double wdt = 0.;
	double hgt = 0.;

	DVec3d pBegin = pts[0];

	DVec3d ptss[MAX_BAR_VERTICES];

	for (int i = 0; i < MAX_BAR_VERTICES; i++)
		ptss[i] = ptsh[i];


	if (bUnrot) 
	{
		_DVector3d prng;
		prng.org.x = ptss[0].x;
		prng.org.y = ptss[0].y;
		prng.end.x = ptss[numpts-1].x;
		prng.end.y = ptss[numpts-1].y;
		for (int i = 0; i < numpts; i++)
		{
			if (ptss[i].x < prng.org.x) prng.org.x = ptss[i].x;
			if (ptss[i].y < prng.org.y) prng.org.y = ptss[i].y;
			if (ptss[i].x > prng.end.x) prng.end.x = ptss[i].x;
			if (ptss[i].y > prng.end.y) prng.end.y = ptss[i].y;
		}


		if (fabs(prng.end.x - prng.org.x) < fabs(prng.end.y - prng.org.y))
			getBarUnrotatedPoints(ptss, ptss, &pZ, numpts, 0, FALSE, NULL);
	}

	for (int i = 0; i < numpts - 1; i++)
	{
		dst = mdlVec_distance(&ptss[i], &ptss[i + 1]);
		if (dst > dist_max) dist_max = dst;
		if (dst < dist_min) dist_min = dst;

		dist += dst;
	}


	dist_mid = dist / (numpts - 1);


	for (int i = 0; i < numpts - 1; i++)
	{

		mdlVec_subtractPointArray(ptss, &ptss[i], numpts);

		dist = mdlVec_distance(&ptss[i], &ptss[i + 1]);

		if (dist < dist_mid)
		{
			DVec3d p = ptss[i + 1];
			DVec3d pSub;

			mdlVec_scaleToLengthInPlace(&p, (dist + dist_mid) / 2.);

			mdlVec_subtractPoint(&pSub, &p, &ptss[i + 1]);

			mdlVec_addPointArray(&ptss[i + 1], &pSub, numpts - i - 1);
		}


		if (dist > dist_mid)
		{
			DVec3d p = ptss[i + 1];
			DVec3d pSub;

			mdlVec_scaleToLengthInPlace(&p, (dist + dist_mid) / 2.);

			mdlVec_subtractPoint(&pSub, &p, &ptss[i + 1]);

			mdlVec_addPointArray(&ptss[i + 1], &pSub, numpts - i - 1);
		}


	}


	for (int i = 0; i < numpts; i++)
	{
		if (ptss[i].x < x[0]) x[0] = ptss[i].x;
		if (ptss[i].x > x[1]) x[1] = ptss[i].x;

		if (ptss[i].y < y[0]) y[0] = ptss[i].y;
		if (ptss[i].y > y[1]) y[1] = ptss[i].y;
	}

	pBegin.x = -(x[0] + x[1]) / 2.;
	pBegin.y = -(y[0] + y[1]) / 2.;

	//printf("%f %f\n", x[0], y[0]);

	mdlVec_addPointArray(ptss, &pBegin, numpts);


	wdt = x[1] - x[0];
	hgt = y[1] - y[0];

	if (wdt > 1. && prefWdt > 0.) dXsc = prefWdt / wdt;
	if (hgt > 1. && prefHgt > 0.) dYsc = prefHgt / hgt;

	if (dXsc < dYsc) dYsc = dXsc; else dXsc = dYsc;

	for (int i = 0; i < numpts; i++)
	{
		ptss[i].x *= dXsc;
		ptss[i].y *= dYsc;
	}


	for (int i = 0; i < MAX_BAR_VERTICES; i++)
		ptsh[i] = ptss[i];


	writeLogOut(__FUNCTION__, 0);

}

/// <summary>
/// функция отрисовки эскиза стержня
/// </summary>
/// <param name="dbP"></param>
/// <param name="diP"></param>
void reinListBoxDrawPos(MSDLGP dbP,  DialogItem* diP)
{
	//curPos.bar.apts
	// ...
	RotMatrix rm;
	_DVector3d ext;
	DVec3d org;
	DVec3d rng;
	int numLens = 0;
	int rad = 0;
	//MSElementDescr* edpDisplay = NULL;

	DVec3d ptsBarSk[MAX_BAR_VERTICES];
	//vector<DVec3d>ptsBarSk;

	int bFillet = FALSE;

	writeLogIn(__FUNCTION__, 0);



	MSElementDescr* edpChain = NULL;
	MSElementDescr* edpChainSk = NULL; // for sketch
	
	mdlRMatrix_getIdentity(&rm);

	mdlComplexChain_createHeader(&eCell, 0, 0);
	mdlElmdscr_new(&edpChain, 0, &eCell);

	mdlComplexChain_createHeader(&eCell, 0, 0);
	mdlElmdscr_new(&edpChainSk, 0, &eCell);

	ext.clear();

	for (int i = 0; i < curPos.bar.cnumpts; i++)
	{
		DVec3d p;

		p.x = mdlCnv_masterUnitsToUors(curPos.bar.apts[i].x); // построение арко по точке на элементе
		p.y = mdlCnv_masterUnitsToUors(curPos.bar.apts[i].y);
		p.z = mdlCnv_masterUnitsToUors(curPos.bar.apts[i].z);

		ptsBarSk[i] = p;
		//ptsBarSk.push_back(p);
	}

	if (curPos.bar.noplanar == 2) mdlRMatrix_multiplyPointArray(ptsBarSk, &rmIso, curPos.bar.cnumpts);

	if (curPos.bar.bendrad > 0)
		rad = curPos.bar.bendrad;
	else
		rad = getBendRadius(&curPos.bar, 0);

	reinCreateComplexBarAxis2(&edpChain, 0, ptsBarSk, curPos.bar.rfa, curPos.bar.cnumpts, rad, &c0w1s0, NULL, TRUE);

	//mdlElmdscr_computeRange(&ext.org, &ext.end, edpChain, 0);

	//rng.x = ext.end.x - ext.org.x;
	//rng.y = ext.end.y - ext.org.y;
	//rng.z = 0.;

	//org.x = ext.org.x;
	//org.y = ext.org.y;
	//org.z = 0.;



	prepareSketchPoints(ptsBarSk, curPos.bar.cnumpts, -1, -1, (curPos.bar.noplanar == 0));


	//if (ptsBarSk.size() != curPos.bar.cnumpts)
	//	return;

	// mdlElmdscr_computeRange in ms connect not working if element not saved in file
	for (int i = 0; i < curPos.bar.cnumpts; i++)
	{
		if (i == 0)
		{
			ext.org = ptsBarSk[i];
			ext.end = ptsBarSk[i];
		}
		else
		{
			if (ptsBarSk[i].x < ext.org.x) ext.org.x = ptsBarSk[i].x;
			if (ptsBarSk[i].y < ext.org.y) ext.org.y = ptsBarSk[i].y;
			if (ptsBarSk[i].z < ext.org.z) ext.org.z = ptsBarSk[i].z;

			if (ext.end.x < ptsBarSk[i].x) ext.end.x = ptsBarSk[i].x;
			if (ext.end.y < ptsBarSk[i].y) ext.end.y = ptsBarSk[i].y;
			if (ext.end.z < ptsBarSk[i].z) ext.end.z = ptsBarSk[i].z;
		}
	}

	reinCreateComplexBarAxis2(&edpChainSk, 0, ptsBarSk, curPos.bar.rfa, curPos.bar.cnumpts, rad, &c0w1s0, NULL, TRUE);


	//edpDisplay = edpChainSk;

	//MSElementDescr* edpBar = NULL;
	//if (curPos.bar.noplanar == 2)
	//{
	//	if (reinSweepBarByPath2(&curPos.bar, &edpBar, edpChainSk) == SUCCESS) 
	//		edpDisplay = edpBar;
	//}


	MSElementDescr* pComponent = NULL;

	iNumLens = 0;

	for (int i = 0; i < 100; i++)
	{
		arLineRads[i] = 0;
		arLineLens[i] = 0;
		arLineAngs[i] = 0.;
	}


	pComponent = edpChain->h.firstElem;
	while (pComponent)
	{
		double len;
		int typ = ROUND_LIN;
		XMLFragmentListP  oXMLFragmentList = NULL;

		int eltyp = mdlElement_getType(&pComponent->el);

		//bFillet = FALSE; // не сбрасывать, смотрим предыдущий!

		if (mdlElement_hasXMLFragmentAttachment(&pComponent->el, &appID, &appTypeSegment) &&
			mdlXMLFragmentList_extractFromElementByAppIDAndType (&oXMLFragmentList, &pComponent->el, 
			&appID, &appTypeSegment) == SUCCESS)
		{
			XMLFragmentP  pXMLFragment;
			MSWCH* wtxt;
			wstring wstr = L"";
			pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);
			if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
			{
				
				wstr = wtxt;
				mdlXMLFragmentList_free(&oXMLFragmentList);

				ReinPrm prm;
				if (readReinFilletFromString(&prm, wstr) == SUCCESS)
				{
					if (bFillet) // пропущен сегмент, два филлета рядом
					{
						arLineLens[iNumLens] = 0;
						arLineRads[iNumLens] = 0;
						arLineAngs[iNumLens] = 0.;
						iNumLens++;
					}

					//arLineLens[iNumLens] = prm.ival[0];
					//arLineRads[iNumLens] = prm.ival[1];
					arLineAngs[iNumLens] = prm.dval[0];

					typ = ROUND_ARC;
					bFillet = TRUE;
				}
				else
					bFillet = FALSE;
			}
			else
				bFillet = FALSE;
		}
		else
			bFillet = FALSE;

		MSElementDescr* edp = NULL;

		mdlElmdscr_duplicateSingle(&edp, pComponent);

		// длина сегмента (вообще-то можно брать из информации по token)
		if (mdlMeasure_linearProperties(&len, 0, 0, 0, 0, 0, 0, 0, edp, -1) == SUCCESS)
		{
			if (mdlCnv_UORToMaster(&len, len, ACTIVEMODEL) == SUCCESS)
				arLineLens[iNumLens] = roundExt(len, typ);
			else
				arLineLens[iNumLens] = -1;
		}
		else
		{
			arLineLens[iNumLens] = -1;
		}

		// радиус сегмента (вообще-то можно брать из информации по token)
		if ((eltyp == ARC_ELM || eltyp == ELLIPSE_ELM) && bFillet == FALSE)
		{
			double drad[2];

			mdlArc_extract(0, 0, 0, &drad[0], &drad[1], 0, 0, &edp->el);

			if (mdlCnv_UORToMaster(&len, (drad[0] + drad[1]) / 2., ACTIVEMODEL) == SUCCESS)
				arLineRads[iNumLens] = roundExt(len, ROUND_LIN);
		}

		iNumLens++;

		mdlElmdscr_freeAll(&edp);

		pComponent = pComponent->h.next;
	}


	iNumTxtPts = 0;
	//ZeroMemory(arLinPts, sizeof(arLinPts));

	pComponent = edpChainSk->h.firstElem;
	while (pComponent)
	{
		MSElementDescr* edp = NULL;

		mdlElmdscr_duplicateSingle(&edp, pComponent);

		//MSBsplineCurve crv;

		if (mdlBspline_convertToCurve(&crv, edp) == SUCCESS)
		{
			mdlBspline_evaluateCurvePoint(&arLinPts[iNumTxtPts], 0, &crv, 0.5);
			mdlBspline_freeCurve(&crv);
			iNumTxtPts++;
		}

		mdlElmdscr_freeAll(&edp);

		pComponent = pComponent->h.next;
	}





	//xmlAddReinElmdAttr(&edpChain, curPos.bar.elemid, REIN_ELEM_ISO, &curPos.bar, 0, FALSE, 0, TRUE, 0, TRUE, 0);

	//mdlElmdscr_displayToWindow

	//viewtool example




	ViewFlags	    viewflags;

	//ZeroMemory(&viewflags, sizeof(viewflags));

#if defined (MSVERSION) && (MSVERSION == 0x8b0) // view flags
    viewflags.points     = TRUE;
    viewflags.fast_curve = FALSE;
    viewflags.fast_font  = FALSE;
    viewflags.delay      = FALSE;	 
	//viewflags.accelerated = 1;
	//viewflags.noBackClip = 1;
	//viewflags.noFrontClip = 1;
#endif
    viewflags.patterns   = TRUE;
    viewflags.on_off     = TRUE;
    viewflags.constructs = TRUE;
    viewflags.dimens     = TRUE;
    viewflags.fast_text  = FALSE;
    viewflags.line_wghts = TRUE;
    viewflags.fast_cell  = FALSE;
    viewflags.text_nodes = TRUE;
    viewflags.ed_fields  = FALSE; 
    viewflags.grid       = FALSE;	 
    viewflags.lev_symb   = FALSE;	 
    viewflags.def        = FALSE;	


	//mdlElmdscr_computeRange(&ext.org, &ext.end, edpChain, NULL);



	//for (int i = 0; i < iNumLens; i++ )
	//{
	//	TextSizeParam tsp;

	//	sprintf(s, "%i", arLineLens[i]);

	//	tsp.mode = TXT_BY_TILE_SIZE;

	//	if (fabs(ext.org.x - ext.end.x) > fabs(ext.org.y - ext.end.y))
	//	{
	//		tsp.size.height = fabs(ext.org.x - ext.end.x) / 20.;
	//		tsp.size.width = fabs(ext.org.x - ext.end.x) / 20.;
	//	}
	//	else
	//	{
	//		tsp.size.height = fabs(ext.org.y - ext.end.y) / 25.;
	//		tsp.size.width = fabs(ext.org.y - ext.end.y) / 25.;
	//	}

	//	UInt32 clr = 255;
	//	UInt32 wgt = 5;

	//	mdlText_create(&elForTT, &c0w1s0, s, &arLinPts[i], &tsp, NULL, &txtParam[5], NULL);
	//	mdlElement_setSymbology(&elForTT, &clr, &wgt, 0);

	//	mdlElmdscr_appendElement(edpChain, &elForTT);

	//	clr = 0;
	//	wgt = 1;
	//	mdlElement_setSymbology(&elForTT, &clr, &wgt, 0);

	//	mdlElmdscr_appendElement(edpChain, &elForTT);

	//}

	//DVec3d rngE;

	// см выше
	//mdlElmdscr_computeRange(&ext.org, &ext.end, edpChainSk, NULL);

	rng.x = ext.end.x - ext.org.x;
	rng.y = ext.end.y - ext.org.y;
	rng.z = ext.end.z - ext.org.z;

	org.x = ext.org.x;
	org.y = ext.org.y;
	org.z = ext.org.z;


	BSIRect rect0 = diP->rect;


	rect0.origin.x += 20;
	rect0.origin.y += 20;

	rect0.corner.x -= 20;
	rect0.corner.y -= 20;



	for (int i = 0; i < iNumTxtPts; i++ )
	{
		if (arLineRads[i]) 
		{
			rect0.corner.y -= 20;
			break;
		}
	}



	BSIRect rect = rect0;

	double iRectH = rect.corner.y - rect.origin.y;
	double iRectW = rect.corner.x - rect.origin.x;
	double iRectHpoles = iRectH;
	double iRectWpoles = iRectW;

	double dOntX = iRectW / rng.x;
	double dOntY = iRectH / rng.y;



	double dOtnPic = iRectH / iRectW;
	double dOtnElm = rng.y / rng.x;

	double koefX = 1.;
	double koefY = 1.;

	if (dOtnPic > dOtnElm) // горизонтальные поля
	{
		double dRectHreal = iRectH / dOntX;
		koefY = rng.y / dRectHreal;
		iRectHpoles = iRectH * koefY;
		rect.origin.y += (Int32)((iRectH - iRectHpoles) / 2.);
		rect.corner.y -= (Int32)((iRectH - iRectHpoles) / 2.);

	}

	if (dOtnPic < dOtnElm) // верт. поля
	{
		double dRectWreal = iRectW / dOntY;
		koefX = rng.x / dRectWreal;
		iRectWpoles = iRectW * koefX;
		rect.origin.x += (Int32)((iRectW - iRectWpoles) / 2.);
		rect.corner.x -= (Int32)((iRectW - iRectWpoles) / 2.);
	}


	//UInt32 smb[2] = {0, 2};
	//mdlElmdscr_setSymbology(edpChainSk, &smb[0], 0, &smb[1], 0);
	mdlElement_setTransparency(&edpChainSk->el, 0.7);
	UInt32 clr[MAX_CMAPENTRIES];
	for (int i = 0; i < MAX_CMAPENTRIES; i++)	clr[i] = 0;


	mdlElmdscr_extendedDisplayToWindow ((MSWNDP) dbP, &rect0, &viewflags, edpChainSk, &rm,
						&org, &rng, TRUE, 1, clr, FALSE, NULL);


	//mdlElmdscr_displayToWindow ((GuiWindowP) dbP, &rect0,
	//				    &viewflags, edpChainSk, &rm,
	//				    &org, &rng, TRUE, 0 );


	mdlDialog_fontIndexSet(dbP, FONT_INDEX_TOOLTIP);

	WCH stxt[1000];

	for (int i = 0; i < iNumTxtPts; i++ )
	{
		Point2d p;
		Point2d pr;
		int bDraw[3] = {0,0,0};// уровни

		double otnx = (arLinPts[i].x - ext.org.x) / (rng.x);
		double otny = (arLinPts[i].y - ext.org.y) / (rng.y);

		otnx *= iRectWpoles;
		otny *= iRectHpoles;

		if (curPos.bar.runmet == 0 || 
			(curPos.bar.runmet > 1 && curPos.file_qty_p == 0) // сохр. позиция но нет таких в файле
			)
		{

			if (arLineLens[i] > 0)
			{
				SPRN(stxt, L(" %i "), arLineLens[i]);
				bDraw[0] = TRUE;
			}
			else if (arLineRads[i] > 0)
			{
				SPRN(stxt, L(" R%i "), arLineRads[i]);
				bDraw[1] = TRUE;
			}
			else if (!EQQ(arLineAngs[i], 0., 0.1) && !EQQ(arLineAngs[i], 90., 0.1))
			{
				SPRN(stxt, L(" %.1f° "), arLineAngs[i]);
				bDraw[2] = TRUE;
			}
		}
		else if (curPos.bar.runmet == 1)
		{
			if (arLineRads[i] > 0)
			{
				SPRN(stxt, L(" R%i "), arLineRads[i]);
				bDraw[1] = TRUE;
			}
			else if (!EQQ(arLineAngs[i], 0., 0.1) && !EQQ(arLineAngs[i], 90., 0.1))
			{
				SPRN(stxt, L(" %.1f° "), arLineAngs[i]);
				bDraw[2] = TRUE;
			}
		}
		else if (curPos.bar.runmet > 1) // переменная длина
		{
			if (curPos.bar.blen[i][0] > 0 && (curPos.bar.blen[i][0] != curPos.bar.blen[i][2]))
			{
				SPRN(stxt, L(" %i-%i "), curPos.bar.blen[i][0], curPos.bar.blen[i][2]);
				bDraw[0] = TRUE;
			}
			else if (curPos.bar.blen[i][0] > 0 && (curPos.bar.blen[i][0] == curPos.bar.blen[i][2]))
			{
				SPRN(stxt, L(" %i "), curPos.bar.blen[i][0]);
				bDraw[0] = TRUE;
			}
			else if (arLineRads[i] > 0)
			{
				SPRN(stxt, L(" R%i "), arLineRads[i]);
				bDraw[1] = TRUE;
			}
			else if (!EQQ(arLineAngs[i], 0., 0.1) && !EQQ(arLineAngs[i], 90., 0.1))
			{
				SPRN(stxt, L(" %.1f° "), arLineAngs[i]);
				bDraw[2] = TRUE;
			}

		}




		if (bDraw[0] || bDraw[1] || bDraw[2])
		{
			p.x = rect.origin.x + (Int32)(otnx) - mdlDialog_stringWidth(dbP, FONT_INDEX_TOOLTIP, stxt) / 2;
			p.y = rect.corner.y - (Int32)(otny) - mdlDialog_fontGetCurHeight(dbP) / 2;

			//BSIColorDescr* bgColor   = NULL;
			//mdlColorDescr_setByMenuColor(bgColorP, WHITE_INDEX);
			//BSIColorDescr* fgColor   = mdlWindow_systemColorGet(SYSCOLOR_FIXED_CYAN);

			//mdlWindow_textDrawCD((GuiWindowP)dbP, FONT_INDEX_TOOLTIP, &p, stxt, fgColor, bgColor, &diP->rect, 0);
			mdlDialog_textDraw(dbP, &p, &diP->rect, stxt, TRUE);
		
			p.y = rect.corner.y - (Int32)(otny) + mdlDialog_fontGetCurHeight(dbP) / 2;
		}



		if (bDraw[1] || bDraw[2]) continue;



		if (arLineRads[i] > 0)
		{
			SPRN(stxt, L(" R%i "), arLineRads[i]);
			bDraw[1] = TRUE;
		}
		else if (!EQQ(arLineAngs[i], 0., 0.1) && !EQQ(arLineAngs[i], 90., 0.1))
		{
			SPRN(stxt, L(" %.1f° "), arLineAngs[i]);
			bDraw[2] = TRUE;
		}



		if (bDraw[1] || bDraw[2])
		{
			mdlDialog_textDraw(dbP, &p, &diP->rect, stxt, TRUE);
		}


	}



	mdlElmdscr_freeAll(&edpChain);
	mdlElmdscr_freeAll(&edpChainSk);


	writeLogOut(__FUNCTION__, 0);


}

/////////////////////////////////////////////////////////////
int getBarEndsCount(DgnModelRefP mrP)
{

	ScanCriteria    *scP = NULL;
	UShort          typeMask[6];
	int status;
	
	for (UShort a = 0; a < 6; a++) typeMask[a] = 0;

	typeMask[0] = TMSK0_LINE | TMSK0_ARC | TMSK0_LINE_STRING | TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;


	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanBarEndsCount, NULL);
	status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
	mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);
	status = mdlScanCriteria_setModel (scP, mrP);
	status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
	status = mdlScanCriteria_free (scP);

	return SUCCESS;

}



/////////////////////////////////
int scanBarEndsCount(
MSElementDescr  *edDstP,
void  *arg,
ScanCriteria    *pScanCriteria					
)
{

	ReinElm relm;
	DVec3d ppts[2];
	DVec3d ptgs[2];

	double dTol = mdlCnv_masterUnitsToUors(iCfgVar_MuftTol);

	double dLev[2];

	dLev[0] = mdlCnv_masterUnitsToUors((double)rDopInfo.dopopt[2]);
	dLev[1] = mdlCnv_masterUnitsToUors((double)rDopInfo.dopopt[3]);

	if (relm.getElmFromElement(&edDstP->el, mdlScanCriteria_getModel(pScanCriteria)) == SUCCESS)
	{

		mdlElmdscr_extractEndPoints (&ppts[0], &ptgs[0], &ppts[1], &ptgs[1], edDstP, ACTIVEMODEL);

		elemIterCount2++;

		tbi.percentComplete1 = (long)(((double)elemIterCount2 / (double)elemCount2) * 100.);
		//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
		if (dlgProgressP) mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)tbi.percentComplete1);
		WaitMessage();

		if (relm.bel.term[0] == REIN_TERM_REZB) iBarCapsCount++;
		if (relm.bel.term[1] == REIN_TERM_REZB) iBarCapsCount++;

		if (mdlModelRef_isActiveModel(edDstP->h.dgnModelRef) == FALSE)
		{
			Transform tm;
			mdlTMatrix_referenceToMaster(&tm, edDstP->h.dgnModelRef);
			mdlTMatrix_transformPointArray(ppts, &tm, 2);
			mdlTMatrix_transformPointArray(ptgs, &tm, 2);
		}



		int bIsVyp[2];

		bIsVyp[0] = FALSE;
		bIsVyp[1] = FALSE;

		// start
		if (mdlVec_areParallel(&ptgs[0], &pZ))
		{
			if (
				(EQ(dLev[0], ppts[0].z) || dLev[0] < ppts[0].z) && 
				(EQ(dLev[1], ppts[0].z) || dLev[1] > ppts[0].z)
				)
				bIsVyp[0] = TRUE;
			else
				bIsVyp[0] = FALSE;

		}

		// end
		if (mdlVec_areParallel(&ptgs[1], &pZ))
		{
			if (
				(EQ(dLev[0], ppts[1].z) || dLev[0] < ppts[1].z) && 
				(EQ(dLev[1], ppts[1].z) || dLev[1] > ppts[1].z)
				)
				bIsVyp[1] = TRUE;
			else
				bIsVyp[1] = FALSE;
		}


		if (bIsVyp[0] || bIsVyp[1]) 
		{
			if (rDopInfo.dopopt[5]) mdlLocate_hiliteElement(edDstP->h.elementRef, edDstP->h.dgnModelRef);
			iBarEndsCount++;
		}


	}

	return 0;

}


///////////////////////////////////////
//func insert CurBars Member2
void insertCurBarsMember2(ReinElm* reToAddP, MSElementDescr* edP, UInt32 iBarFP, CatInfo* ciP, Int64 iCurElmIndex)
{
	if (bNoLoad) return;
	
	//double len;
	int step = 0;
	UInt32 fp = 0;
	CatInfo ci;
	ReinElm* reP = NULL;
	UInt32 index = 0;


	if (iBarFP == 0)
		fp = mdlElmdscr_getFilePos(edP);
	else
		fp = iBarFP;

	if (fp == 0) return;

	//if (fp < FILEPOS_LOC) return;
	//fp -= FILEPOS_LOC;


	//UInt32 rn = getModelRefNum(edP->h.dgnModelRef);

	ReinModel* rmP = curRM->getRM(edP->h.dgnModelRef);

	if (rmP == NULL) return;
	//if (rmP->arCurElms == NULL) return;

	writeLogIn(__FUNCTION__, 0);

	if (iDebug) sprintf(sLogMes, "( fp = %u )\n", fp); writeLog(0, 0, 0, 1);


	//File = 0, Pos = 4002838
	//File=8, Pos=4200696

	//if (fp == 4002838)
	//	__asm nop;

	//if (fp == 4200696)
	//	__asm nop;


	//if (!bNoLoad)
	{

		reP = rmP->getReinElm(fp);


		if (reP == NULL)
		{
			{
				if (iDebug) sprintf(sLogMes, "create new elm : rmP--arCurElms[%u] = new ReinElm\n", fp); writeLog(0, 0, 0, 1);
				//rmP->arCurElms[fp] = new ReinElm;
				//reP = rmP->arCurElms[fp];

				//ReinIndex ri;

				rmP->mapElms.insert(pair<UInt32, ReinElm>(fp, *reToAddP));

				//rmP->mapElms[fp].inplace = true;
				//rmP->mapElms[fp].rei = (UInt32)rmP->vecElms.size();

				//rmP->vecElms.push_back(*reToAddP);

				reP = &(rmP->mapElms[fp]);
			}

		}
		else
		{
			if (iDebug) sprintf(sLogMes, "got existing elm : rmP->mapElms[%u]\n", fp); writeLog(0, 0, 0, 1);

			reP->clear();

			*reP = *reToAddP;

		}

	}


	
	if (ciP == NULL)
	{
		getCatInfo(&ci, edP->h.dgnModelRef, false);
		ciP = &ci;
	}


	//reP->poscatID = ciP->catModID;


	//for (int i = 0; daCurPosBase && i < mdlDArray_nMembers(daCurPosBase); i++)
	//{

	//	ReinPos* rpItP = (ReinPos*)mdlDArray_getMemberP(daCurPosBase, i);
	//	if (rpItP <= 0) continue;

	//	if (barsEqual(&reP->bel, &rpItP->bar) && ciP->catModID == rpItP->pcatID)
	//	{
	//		reP->bel.pnum = rpItP->bar.pnum;
	//		break;
	//	}
	//}

	//=================================================

	ELID idr = 0;
	UInt32 rn = 0;
	bool bRnd = false;
	if (readRndFromElement(&idr, &rn, &edP->el) == SUCCESS)
		bRnd = true;

	ReinPos* rpP = NULL;
	int dirout = 0;

	if (iDebug) sprintf(sLogMes, "search for position... rmP--getPosMap().size() = %u\n", (UInt32)rmP->getPosMap().size()); writeLog(0, 0, 0, 1);

	//ReinModel* rmSrchP = rmP;
	//if (rmP->bRefPlus) rmSrchP = curRM;

	CatInfo& poscat = rmP->getCat(reP);


	for (map<long, ReinPos>::iterator it = poscat.arCurPos.begin(); it != poscat.arCurPos.end(); ++it)
	{
		ReinPos* rpItP = &it->second;

		if (barsEqual(&reP->bel, &rpItP->bar, &dirout))
		{
			rpP = rpItP;
			//rpP = &rmP->getPosMap()[i];
			reP->bel.pnum = rpP->bar.pnum;

			if (rpP->bar_mem.diam > 0)
				reP->elemflags |= REINEL_FLAG_CTCH;
			//else // only insert
			//	reP->elemflags &= !REINEL_FLAG_CTCH;

			if (iDebug) sprintf(sLogMes, "found pos number %i in map index %d\n", reP->bel.pnum, it->first); writeLog(0, 0, 0, 1);
			break;
		}
	}


	//=================================================

	reP->bel.ffpos[REIN_ELEM_ISO] = mdlElmdscr_getFilePos(edP);
	reP->bel.modrefP = edP->h.dgnModelRef;
	
/*	
	if (rmP->updb)
	{

		ups_record_t rec;
		ups_key_t key;

		//ZeroMemory(&key, sizeof(key));
		//ZeroMemory(&rec, sizeof(rec));

		key.data = &fp;
		key.size = sizeof(fp);

		rec.size = sizeof(ReinElm);
		rec.data = reP; // NEW ?????????????????? 

		upst = ups_db_insert(rmP->updb, 0, &key, &rec, UPS_OVERWRITE);
		if (upst != UPS_SUCCESS)
		{
			//...

		}

	}
*/
	int bClash = FALSE;
	if ((iCfgVar_Clash_Mode == 1) // check always
		|| (iCfgVar_Clash_Mode == 2 && iCurElmIndex == -1)) // only for manipulations 
		bClash = TRUE;


	if (!bRnd
		&& (
				iCfgVar_CheckDups 
				|| bClash
			)
		)
	{
		if (iDebug) sprintf(sLogMes, "check duplicates...\n"); writeLog(0, 0, 0, 1);

		ReinPrm prm;
		prm.ival[0] = bClash;

		scanCheckDuplicate(edP, &prm, 0);
	}


	if (ciP) 
	{
		if (iDebug) sprintf(sLogMes, "set position...\n"); writeLog(0, 0, 0, 1);
		setPosition(rpP, reP, rmP, dirout);
	}


	
	writeLogOut(__FUNCTION__, 0);

}

/////////////////////////////////
int scanBarOverFence(
	MSElementDescr* edInP,
	ReinElement* reP,
	ScanCriteria* pScanCriteria
)
{
	BINT bOver;
	CLIPDESC clipP = NULL;
	DgnModelRefP mrP = mdlScanCriteria_getModel(pScanCriteria);
	BINT bInside = FALSE;


	ReinModel* rmP = curRM->getRM(mrP);

	if (rmP == NULL) return SUCCESS;


	ReinElm relm;

	if (readReinElmIso(&relm, edInP, FALSE, FALSE) != SUCCESS)
		return SUCCESS;

	if (reP->idRS != relm.bel.elemid) // only this space
		return SUCCESS;

	writeLogIn(__FUNCTION__, 0);

	if (func_pma(mdlClip_getFence, clipP)) == SUCCESS)
		bInside = mdlClip_isElemInside(&bOver, edInP, GETPTR(clipP), tcb->lstvw, FALSE);
	else
		bInside = FALSE;

	if (bInside 
		//&& mdlElement_isEffectivelyVisible(&edP->el, mrP, tcb->lstvw)
		)
	{
		BarOver bo;

		bo.isdel = 1;
		bo.inum = relm.bel.inum;
		reP->mapOvers[bo.inum] = bo;
	}


	myClip_free(clipP, 0);

	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;

}


//////////////////////////////
//func in reinSetOverInSpace
void reinSetOverInSpace(int baract)
{
	ReinBar rb;
	//ReinData rd;
	ReinElement re;
	ReinElm relm;
	MSElementDescr* edp = NULL;
	MSElementDescr* edSpaceP = NULL;

	if (mdlElmdscr_readToMaster(&edp, filePosRein, curElemModelRef, 0, 0) == 0)
	{
		return;
	}

	writeLogIn(__FUNCTION__, 0);

	if (edp && readReinElmIso(&relm, edp, FALSE, FALSE) == SUCCESS)
	{
		mdlElmdscr_freeAll(&edp);

		ReinModel* rmP = curRM->getRM(curElemModelRef);

		if (rmP == NULL) return;

		ELREF eref = getElemRefByID(curElemModelRef, relm.bel.elemid);

		filePosReinSpace = elementRef_getFilePos(eref);

		mdlElmdscr_readToMaster(&edSpaceP, filePosReinSpace, curElemModelRef, 0, 0);

		if (edSpaceP == NULL) return;

	}
	else
	{
		edSpaceP = edp;
	}


	if (readReinSpaceFromElmd(&re, edSpaceP, FALSE) == SUCCESS)
	{
		prepareBarOver(&re, &relm.bel, baract);

		reinSpaceElmdCreate(filePosReinSpace, curElemModelRef, NULL, FALSE, &re);
	}
	else if (readReinBarFromElement(&rb, edSpaceP, TRUE) == SUCCESS)
	{
		filePosReinBar = filePosReinSpace;
		filePosReinSpace = 0;

		if (rb.bartype != BT_AXIS)
		{
			if (baract == BAROVER_ACTION_RESET)
			{
				MSElementDescr* edRdP = NULL;

				ELREF dref = getElemRefByID(ACTIVEMODEL, rb.elemid);
				if (dref)
				{
					UInt32 dfpos = elementRef_getFilePos(dref);

					mdlElmdscr_read(&edRdP, dfpos, ACTIVEMODEL, 0, 0);

					if (edRdP)
					{
						if (readReinDataFromElmd(&re, edRdP, &rb) == SUCCESS)
						{
							re.mapOvers.clear();

							rb.fromReinData(&re.rd);

							rb.elemid = rb.saveReinData(rb.elemid, &re);
						}


						mdlElmdscr_freeAll(&edRdP);

						mdlElmdscr_rewrite(edSpaceP, edSpaceP, mdlElmdscr_getFilePos(edSpaceP)); // touch element to regen

					}
				}
			}
		}


	}
	else if (readReinDataFromElmd(&re, edSpaceP, &relm.bel) == SUCCESS)
	{

		if (baract == BAROVER_ACTION_DELETE)
		{
			prepareBarOver(&re, &relm.bel, baract);

			relm.bel.fromReinData(&re.rd);

			relm.bel.saveReinData(relm.bel.elemid, &re);


			if (relm.bel.ffpos[REIN_ELEM_ISO])
			{
				int res = mdlElmdscr_undoableDelete(0, relm.bel.ffpos[REIN_ELEM_ISO], TRUE);

				ELREF bref = getElemRefByID(relm.bel.modrefP, relm.bel.brid);
				if (bref)
				{
					UInt32 barfpos = elementRef_getFilePos(bref);
					mdlElmdscr_undoableDelete(0, barfpos, TRUE);
				}
			}
			else if (relm.bel.ffpos[REIN_ELEM_BAR])
			{
				int res = mdlElmdscr_undoableDelete(0, relm.bel.ffpos[REIN_ELEM_BAR], TRUE);

				ReinElm* relmP = curRM->findReinElm(relm.bel.elemid, relm.bel.axid);

				if (relmP)
				{
					mdlElmdscr_undoableDelete(0, relmP->bel.ffpos[REIN_ELEM_ISO], TRUE);
				}
			}
		}
		else if (baract == BAROVER_ACTION_MOVE)
		{
			//...
		}
		else
		{
			//...
		}





	}




	if (edSpaceP) mdlElmdscr_freeAll(&edSpaceP);


	writeLogOut(__FUNCTION__, 0);

}

//////////////////////////////
void reinSetBarInSpace(DVec3d *ptP, UInt32 fp, DgnModelRefP mrP, int idrawmode, BINT bPlaceDim)
{
	ReinElm relm;


	MSElementDescr* edp = NULL;

	if (mdlElmdscr_readToMaster(&edp, fp, mrP, 0, 0) == 0)
	{
		return;
	}

	writeLogIn(__FUNCTION__, 0);

	if (readReinElmIso(&relm, edp, FALSE, FALSE) == SUCCESS)
	{
		ReinModel* rmP = curRM->getRM(mrP);

		if (rmP == NULL) return;

		rmP->getRefPath(&curPos.arefnum);
		//curPos.arefnum[0] = getRefNum(relm.bel.mrP);

		curPos.drawmode = idrawmode;
		curPos.bar.inum = relm.bel.inum;
		//curPos.refind = getModelRefNum(relm.bel.mrP);
		curPos.bar.elemid = relm.bel.elemid;

		deleteBarSetInfo(&curPos, FALSE, TRUE); // также удалить из массива

		if (curPos.drawmode > 0) 
			saveBarSetInfo(&curPos, TRUE);
		//else
		//	reloadHidingPositions(); // pushed after element save

		// размер
		if (rmP && curPos.drawmode > 0 && bPlaceDim)
		{

			ReinElm* reCurP = rmP->getReinElm(fp);
			ReinElm* reOneP = NULL;
			ReinElm* reTwoP = NULL;
			MSElementDescr* edOneP = NULL;
			MSElementDescr* edTwoP = NULL;

			int imax = 0;
			int imin = 10000;

			if (reCurP)
			{
				for (map<UInt32, ReinElm>::iterator it = rmP->mapElms.begin(); it != rmP->mapElms.end(); ++it)
				//for (UInt32 i = 0; i < rmP->vecElms.size(); i++)
				{
					ReinElm* reP = &(it->second);

					if (reP)
					{
						if (reCurP->bel.pnum == reP->bel.pnum && reCurP->bel.elemid == reP->bel.elemid)
						{
							if (reP->bel.inum < imin)
							{
								reOneP = reP;
								imin = reP->bel.inum;
							}

							if (reP->bel.inum > imax)
							{
								reTwoP = reP;
								imax = reP->bel.inum;
							}
						}

					}
				}
			}


			if (reOneP && reTwoP && reCurP)
			{
				mdlElmdscr_readToMaster(&edOneP, reOneP->bel.ffpos[REIN_ELEM_ISO], reOneP->bel.modrefP, 0, 0);
				mdlElmdscr_readToMaster(&edTwoP, reTwoP->bel.ffpos[REIN_ELEM_ISO], reTwoP->bel.modrefP, 0, 0);
			}

			if (edOneP && edTwoP)
			{

				//mdlProject_perpendicular(&curNote.arNotePts[0], 0, 0, edOneP, reOneP->bel.mrP, ptP, NULL, -1);
				//mdlProject_perpendicular(&curNote.arNotePts[1], 0, 0, edp, reCurP->bel.mrP, ptP, NULL, -1);
				//mdlProject_perpendicular(&curNote.arNotePts[2], 0, 0, edTwoP, reTwoP->bel.mrP, ptP, NULL, -1);

				mdlLocate_getProjectedPoint(&curNote.arNotePts[1], 0, 0);

				mdlProject_perpendicular(&curNote.arNotePts[0], 0, 0, edOneP, ACTIVEMODEL, &curNote.arNotePts[1], NULL, -1);
				//mdlProject_perpendicular(&curNote.arNotePts[1], 0, 0, edp, ACTIVEMODEL, ptP, NULL, -1);
				mdlProject_perpendicular(&curNote.arNotePts[2], 0, 0, edTwoP, ACTIVEMODEL, &curNote.arNotePts[1], NULL, -1);

				mdlElmdscr_freeAll(&edOneP);
				mdlElmdscr_freeAll(&edTwoP);

				createDim(&el, curNote.arNotePts, 3, TRUE);
			}
		}



	}

	mdlElmdscr_freeAll(&edp);

	writeLogOut(__FUNCTION__, 0);

}


///////////////////////////////////////////////////////////////////////////////////
int savePosition(ReinPos* rpP, int bOverwrite, int bUpdateBaseInfo)
{
	MSElementDescr* pXmlFragmentElement = NULL; 
	int status;
	XMLFragmentListP pCurrent = NULL; 


	if (rpP->bar.pnum <= 0) return ERROR;

	writeLogIn(__FUNCTION__, 0);

	int bPosExist = FALSE;

	if (bOverwrite)
	{
		bPosExist = checkFilePosition(rpP->bar.pnum);
	}

	//if (bPosExist)  // уже есть такая позиция, но в файле таких нет
	//{ здесь если нужно установить пересохранение пустой позиции без запроса то надо прочесывать daCurPosBase по номеру
	//	deleteFilePosition(rpP->bar.pnum);
	//}

	if (rpP->bPosXml)
	{
		writeLogOut(__FUNCTION__, "position has xml format");
		return ERROR;
	}

	if (bPosExist) // уже есть такая позиция
	{
		if (bOverwrite)
		{
			if (iDebug) sprintf(sLogMes, "pos exists, overwrite...\n"); writeLog(0, 0);
			deleteFilePosition(rpP->bar.pnum);
		}
		else
		{
			writeLogOut(__FUNCTION__, "pos exists");
			return ERROR;
		}
	}

	//=========================================

	if (bUpdateBaseInfo)
	{
		rpP->base_length = rpP->file_length;
		rpP->base_ms_max = rpP->file_ms_max;
		rpP->base_ms_mid = rpP->file_ms_mid;
		rpP->base_ms_min = rpP->file_ms_min;

		if (rpP->bar.runmet == 1)
			rpP->base_qty = rpP->file_qty_rm;
		else
			rpP->base_qty = rpP->file_qty_p;

		rpP->bar_mem.clear();
	}



	//rpP->file_length = 0;
	//rpP->file_ms_max = 0;
	//rpP->file_ms_mid = 0;
	//rpP->file_ms_min = 0;
	//rpP->file_qty_p = 0;
	//rpP->file_qty_rm = 0;
	//rpP->lap_qty = 0;
	//rpP->muft_qty = 0;
	//rpP->refcnt = 0;
	//rpP->bar.mrP = 0;

	//=========================================

	setPosString(rpP, FALSE, FALSE);

	SCPM2W(wss, sCurPos, 5000);

	pCurrent = mdlXMLFragmentList_construct (wss, NULL, appID, appTypeReinPos);

	// create new one
	status = mdlXMLFragmentList_createXMLElementDescriptor  (&pXmlFragmentElement, &pCurrent, TRUE); 

	//=========================================


	//mdlElmdscr_appendAttributes(&pXmlFragmentElement, atlen, ats);
	
	//=========================================

	xmlAddBarPoints(&rpP->bar, &pXmlFragmentElement);
	
	//=========================================

	status = ERROR;

	if (NULL != pXmlFragmentElement) 
	{ 
		UInt32 fp;

		//mdlXMLElement_setNonModelCategory (pXmlFragmentElement, TRUE);

		fp = mdlElmdscr_add (pXmlFragmentElement); 
		mdlElmdscr_freeAll (&pXmlFragmentElement); 

		status = SUCCESS;
	} 

	if (iDebug) sprintf(sLogMes, "return %i\n", status); writeLog(0, 0);
	writeLogOut(__FUNCTION__, 0);

	return status;

}


//////////////////////////////////////////////////////
int scanLoadFilePosCount( // not using
	MSElementDescr  *edP,
	ReinModel*        rmP,
	ScanCriteria    *pScanCriteria
)
{

	//rmP->iPosQty++;

	return SUCCESS;
}


//////////////////////////////////////////////////////
int scanLoadFilePos(
MSElementDescr  *edP,
ReinModel*        rmP,
ScanCriteria    *pScanCriteria
)
{
	ReinPos rp; // cleared in constr

	XMLFragmentListP  oXMLFragmentList = NULL;

	UInt32 fp = mdlElmdscr_getFilePos(edP);
	UInt32 rn = getRefNum(edP->h.dgnModelRef);

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);


	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			//SCPW2M(sCurPos, wtxt, 5000);
			wstring wstr(wtxt);
			mdlXMLFragmentList_free(&oXMLFragmentList);

			if (getPosFromString(&rp, wstr) == SUCCESS)
			{
				//sprintf(sLogMes, "%s\n", sCurPos); writeLog(0, 0);

				rp.bar.numpts = readBarPointsFromElement(&rp.bar, &edP->el);
				rp.bar.cnumpts = rp.bar.numpts;

				rp.clearCalc();

				if (rp.bar.pnum > 0)
				{
					// add to arCurPos, copy to mapCats after scan if needed
					rmP->mrci.arCurPos.insert(pair<long, ReinPos>(rp.bar.pnum, rp));

					if (iDebug) sprintf(sLogMes, "scanLoadFilePos() - added pos num %i\n", rp.bar.pnum); writeLog(0, 0);

					//rmP->getPosMap().insert(pair<long, ReinPos>(rp.bar.pnum, rp));

					//rmP->iPosQty++;

				}
			}
		}
		else
			return SUCCESS;

	}
	else // MDLERR_LINKAGENOTFOUND
		return SUCCESS;

    return SUCCESS;
}


//////////////////////////////////////////////////////
int scanProcFilePos(
MSElementDescr  *edP,
int*         posnumP, // pos num to check
ScanCriteria    *pScanCriteria
)
{
	ReinPos rp;

	XMLFragmentListP  oXMLFragmentList = NULL;

	UInt32 fp = mdlElmdscr_getFilePos(edP);

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		wstring wstr = L"";
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstr = wtxt;

			mdlXMLFragmentList_free(&oXMLFragmentList);
		}
		//SCPW2M(sCurPos, wtxt, 5000);

		if (getPosFromString(&rp, wstr) == SUCCESS)
		{
			if (
					posnumP && 
					(
						*posnumP == rp.bar.pnum || 
						*posnumP == 0
					)
				)
			{
				//sprintf(sLogMes, "delete elem %s\n", sCurPos); writeLog(0, 0);
				mdlElmdscr_undoableDelete(edP, mdlElmdscr_getFilePos(edP), TRUE);
				
				//map<long, ReinPos>::iterator it = curRM->getPosMap().find(rp.bar.pnum);
				//if (it != curRM->getPosMap().end()) // found
				//{
				//	//if (curRM->getPosMap()[rp.bar.pnum].file_qty_p == 0) 
				//		curRM->getPosMap().erase(rp.bar.pnum);
				//}
				
				elemCount++;
			}
			else if (posnumP && -rp.bar.pnum == *posnumP)
			{
				//if (rp.file_qty_p == 0)
				//	*posnumP = 0;
				//else
				//	*posnumP = 1;

				return ERROR;
			}
		}
	}
	else // MDLERR_LINKAGENOTFOUND
		return SUCCESS;

    return SUCCESS;
}

/////////////////////////////
void scanFilePositions(ReinModel* rmP, DgnModelRefP mrP, bool bClearCats, bool bCatInfo)
{
	ScanCriteria    *pScanCriteria;
	int status;

	if (rmP == NULL) return;

	writeLogIn(__FUNCTION__, 0);

	
	//rmP->mrci.clear();// above

	if (bCatInfo)
	{
		getCatInfo(&rmP->mrci, mrP, 
					mdlModelRef_isActiveModel(mrP),				// set title if active model
					true, // (mdlModelRef_isActiveModel(mrP) == TRUE),		// check db always (if active model)
					(							// set PARENT catalog catID from DB
						rmP->elcount == 0		// only if current model is empty
						//&& !rmP->arMrP.empty()	// and parent model exists (not here see below)
						)					  
					);


		if (iCfgVar_PosListMerge == 2) // new var?
		{
			wstring wstrlev = L"";
			wchar_t wsep[5] = L"|\0\0";

			wstrlev = getReinModelLevelsString(mrP);

			rmP->mrci.dqlvnm.clear();

			readFromString(0, &(rmP->mrci.dqlvnm), wstrlev, wsep);

		}


	}


	if (bClearCats && rmP->mrci.catID > 0)
	{
		map <UInt32, CatInfo>::iterator it = mapCats.find(rmP->mrci.catID);

		if (it != mapCats.end()) // found
			it->second.arCurPos.clear();
	}


	/*
	pScanCriteria = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(pScanCriteria, (PFScanElemDscrCallback)scanLoadFilePosCount, rmP); // count
	status = mdlScanCriteria_setModel(pScanCriteria, mrP);
	status = mdlXML_addXMLFragmentElementScanTest(pScanCriteria, &appID, &appTypeReinPos);
	status = mdlScanCriteria_scan(pScanCriteria, NULL, NULL, NULL);
	status = mdlScanCriteria_free(pScanCriteria);

	//rmP->getPosMap().reserve(rmP->iPosQty * 2);
	*/

	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanLoadFilePos, rmP); // load
	status = mdlScanCriteria_setModel (pScanCriteria, mrP);
	status = mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeReinPos);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);


	if (rmP->mrci.catID > 0)
	{
		UInt32 ctID = 0;

		if (rmP->arMrP.empty()) // if no parent model exists - set separate 
			ctID = rmP->mrci.catModID;
		else
			ctID = rmP->mrci.catID;

		map <UInt32, CatInfo>::iterator it = mapCats.find(ctID);

		if (it == mapCats.end()) // not found, add first one
		{
			// copy new to common
			//if (!rmP->mrci.arCurPos.empty()) // models without saved positions are also needed to fill them by elements

			mapCats[ctID] = rmP->mrci;
			mapCats[ctID].iActive = -1; // not active

			if (mdlModelRef_isActiveModel(mrP) && !rmP->mrci.arCurPos.empty())
				mapCats[ctID].iActive = 1;

			if (iDebug) sprintf(sLogMes, "cat %u redefined to common\n", rmP->mrci.catID); writeLog(0, 0, 0, 1);
		}
		else if (rmP->mrci.arCurPos.size() > 0 && it->second.arCurPos.empty()) // если есть сохраненные позиции для этого каталога
		{
			it->second.arCurPos = rmP->mrci.arCurPos;
		}
		else if (rmP->mrci.arCurPos.size() > 0 && !it->second.arCurPos.empty()) // сохраненные позиции в разных  файлах, принадлежащим одному каталогу
		{
			// объединять? флаг для подсветки?
			//...
		}
	}


	if (iDebug) sprintf(sLogMes, "rmP--getPosMap().size() = %u\n", (UInt32)rmP->getPosMap().size()); writeLog(0, 0, 0, 1);

	// inner models
	for (map<UInt32, ReinModel>::iterator it = rmP->arMrP.begin(); it != rmP->arMrP.end(); ++it)
	{
		scanFilePositions( &it->second
			, it->second.modelP
			, false // do not clear mapCats
			, true // load cat info
		);
	}


	writeLogOut(__FUNCTION__, 0);

}



/////////////////////////////
void deleteFilePosition(int num)
{
	ScanCriteria    *pScanCriteria;
	int status;

	writeLogIn(__FUNCTION__, 0);

	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanProcFilePos, &num); // delete if found
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	status = mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeReinPos);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	writeLogOut(__FUNCTION__, 0);

}

/////////////////////////////
int checkFilePosition(int num)
{
	ScanCriteria    *pScanCriteria;
	int status = 0;

	writeLogIn(__FUNCTION__, 0);

	num = -num;

	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanProcFilePos, &num); // check pos
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	status = mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeReinPos);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	mdlScanCriteria_free (pScanCriteria);

	if (status == BUFF_FULL)
		status = 1; // уже есть такая позиция
	else
		status = SUCCESS;

	if (iDebug) sprintf(sLogMes, "return %i\n", status); writeLog(0, 0);
	writeLogOut(__FUNCTION__, 0);

	return status;

}

///////////////////////////////////////////////////
int getPosFromString(ReinPos* rpP, wstring str)
{
	int trmp[4] = {0};

	if (rpP == NULL) return ERROR;
	rpP->clear();

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	IF_IT_end return ERROR;
	rpP->posID = _wtol(it->c_str());			// 0

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->srtmID = _wtol(it->c_str());				// 1

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->bar.diam = _wtoi(it->c_str());			// 2

	if (rpP->bar.diam == 0) return ERROR;

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->bar.runmet = _wtoi(it->c_str());			// 3

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->bar.mainPtsIndex = _wtoi(it->c_str());// 4

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->bar.transp = _wtoi(it->c_str());		// 5

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->bar.bendrad = _wtoi(it->c_str());		// 6

	IF_IT_nxt IF_IT_end return ERROR;
	// fillet radius...										// 7

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->bar.term[0] = _wtoi(it->c_str());		// 8

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->bar.term[1] = _wtoi(it->c_str());		// 9

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->bar.pnum = _wtoi(it->c_str());		// 10
	if (rpP->bar.pnum == 0) return ERROR;

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->base_qty = _wtof(it->c_str());		// 11

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->base_length = _wtol(it->c_str());		// 12

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->file_qty_p = 0;				// 13

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->file_qty_rm = 0.;				// 14

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->file_ms_min = 0;				// 15

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->file_ms_mid = 0;				// 16

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->file_ms_max = 0;				// 17

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->base_ms_min = _wtol(it->c_str());				// 18

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->base_ms_mid = _wtol(it->c_str());				// 19

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->base_ms_max = _wtol(it->c_str());				// 20

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->bar.length = _wtof(it->c_str());				// 21

	IF_IT_nxt IF_IT_end return SUCCESS;
	trmp[0] = _wtoi(it->c_str());				// 22

	IF_IT_nxt IF_IT_end return SUCCESS;
	trmp[1] = _wtoi(it->c_str());				// 23

	IF_IT_nxt IF_IT_end return SUCCESS;
	trmp[2] = _wtoi(it->c_str());				// 24

	IF_IT_nxt IF_IT_end return SUCCESS;
	trmp[3] = _wtoi(it->c_str());				// 25

	IF_IT_nxt IF_IT_end return SUCCESS;
	//if (token != NULL )	rpP->lap_qty = 0;				// 26

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->pdID = _wtoi(it->c_str());					// 27

	IF_IT_nxt IF_IT_end return SUCCESS;
	//if (token != NULL )	rpP->muft_qty = _wtoi(it->c_str());					// 28

	IF_IT_nxt IF_IT_end return SUCCESS;
	//if (token != NULL )	rpP->pcatID = _wtol(it->c_str());					// 29
	// далее pcatID = ci.catModID

	//ZeroMemory(rpP->bar.termPar, sizeof(rpP->bar.termPar));
	//rpP->bar.vecclear(true);
	//vecAllocInt(&rpP->bar.termPar, 2);
	for (int a = 0; a < 10; a++)
	{
		rpP->bar.termPar[a][0] = 0;
		rpP->bar.termPar[a][1] = 0;
	}

	setBarTermPar4to6(trmp, &rpP->bar);

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->bar.poscalc = _wtoi(it->c_str());					// 30

	IF_IT_nxt IF_IT_end return SUCCESS;
	rpP->bar.noplanar = _wtoi(it->c_str());					// 31













	/*




	WCH seps[]   = L(";");
	WCH *token;


	if (SLEN(ctxt) == 0) return ERROR;


					//rpP->posID,						// 00
					//rpP->srtmID, 					// 01
					//rpP->bar.diam, 					// 02
					//rpP->bar.runmet,				// 03
					//rpP->bar.mainPtsIndex,			// 04 // mainSgmIndex???
					//rpP->bar.transp,				// 05
					//rpP->bar.bendrad,				// 06
					//getBendRadius,	// 07
					//rpP->bar.term[0],				// 08
					//rpP->bar.term[1],				// 09
					//rpP->bar.pnum,					// 10
					//rpP->base_qty,					// 11 double
					//rpP->base_length,				// 12
					//rpP->file_qty_p,				// 13
					//rpP->file_qty_rm,				// 14 double
					//rpP->file_ms_min,				// 15
					//rpP->file_ms_mid,				// 16
					//rpP->file_ms_max,				// 17
					//rpP->base_ms_min,				// 18
					//rpP->base_ms_mid,				// 19
					//rpP->base_ms_max,				// 20
					//rpP->bar.length,				// 21 double
					//trmp[0],						// 22 param 0/2 beg
					//trmp[1],						// 23 param 0/2 end
					//trmp[2],						// 24 param 1 beg
					//trmp[3],						// 25 param 1 end
					//rpP->lap_qty,					// 26
					//rpP->pdID,						// 27
					//rpP->muft_qty,					// 28
					//rpP->pcatID						// 29
					//rpP->poscalc						// 30
					//rpP->noplanar						// 31



	//if (sscanf(token, "%I64u", &reP->bel.elemid) != 1) return ERROR;

	int trmp[4];

	token = STOK( ctxt, seps );
	if (token != NULL )	rpP->posID = STOL(token);			// 0

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->srtmID = STOL(token);			// 1

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.diam = STOI(token);		// 2

	if (rpP->bar.diam == 0) return ERROR;

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.runmet = STOI(token);		// 3

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.mainPtsIndex = STOI(token);// 4

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.transp = STOI(token);		// 5

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.bendrad = STOI(token);		// 6

	token = STOK( NULL, seps );
	// fillet radius...										// 7

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.term[0] = STOI(token);		// 8

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.term[1] = STOI(token);		// 9

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.pnum = STOI(token);		// 10

	if (rpP->bar.pnum == 0) return ERROR;

					//if (rpP->bar.pnum == 3)
					//{
					//	printf("");
					//}

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->base_qty = STOF(token);		// 11

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->base_length = STOL(token);		// 12

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->file_qty_p = 0;				// 13

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->file_qty_rm = 0.;				// 14

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->file_ms_min = 0;				// 15

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->file_ms_mid = 0;				// 16

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->file_ms_max = 0;				// 17

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->base_ms_min = STOL(token);				// 18

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->base_ms_mid = STOL(token);				// 19

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->base_ms_max = STOL(token);				// 20

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.length = STOF(token);				// 21

	token = STOK( NULL, seps );
	if (token != NULL )	trmp[0] = STOI(token);				// 22

	token = STOK( NULL, seps );
	if (token != NULL )	trmp[1] = STOI(token);				// 23

	token = STOK( NULL, seps );
	if (token != NULL )	trmp[2] = STOI(token);				// 24

	token = STOK( NULL, seps );
	if (token != NULL )	trmp[3] = STOI(token);				// 25

	token = STOK( NULL, seps );
	//if (token != NULL )	rpP->lap_qty = 0;				// 26

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->pdID = STOL(token);					// 27

	token = STOK( NULL, seps );
	//if (token != NULL )	rpP->muft_qty = STOI(token);					// 28

	token = STOK( NULL, seps );
	//if (token != NULL )	rpP->pcatID = STOL(token);					// 29
	// далее pcatID = ci.catModID

	//ZeroMemory(rpP->bar.termPar, sizeof(rpP->bar.termPar));

	setBarTermPar4to6(trmp, &rpP->bar);

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.poscalc = STOI(token);					// 30

	token = STOK( NULL, seps );
	if (token != NULL )	rpP->bar.noplanar = STOI(token);					// 31
	*/

	return SUCCESS;
}

//////////////////////////
void setBarTermPar6to4(int* trmp, ReinBar* rbP)
{


	if (rbP->term[0] == REIN_TERM_BEND)
	{
		if (rbP->termPar[0][0] == 0) trmp[0] =  180;	else trmp[0] = rbP->termPar[0][0];
		if (rbP->termPar[1][0] == 0) trmp[2] = getReinLapBend(rbP->diam, 0);	else trmp[2] = rbP->termPar[1][0];
	}

	if (rbP->term[1] == REIN_TERM_BEND)
	{
		if (rbP->termPar[0][1] == 0) trmp[1] = -180;	else trmp[1] = rbP->termPar[0][1];
		if (rbP->termPar[1][1] == 0) trmp[3] = getReinLapBend(rbP->diam, 0);	else trmp[3] = rbP->termPar[1][1];
	}

	if (rbP->term[0] == REIN_TERM_MUFT)
		trmp[0] = rbP->termPar[2][0];

	if (rbP->term[1] == REIN_TERM_MUFT)
		trmp[1] = rbP->termPar[2][1];

}

//////////////////////////////////////
void setBarTermPar4to6(int* trmp, ReinBar* rbP)
{

	if (rbP->term[0] == REIN_TERM_BEND)
	{
		if (trmp[0] == 0) rbP->termPar[0][0] = 180;	else rbP->termPar[0][0] = trmp[0];
		if (trmp[2] == 0) rbP->termPar[1][0] = getReinLapBend(rbP->diam, 0); else rbP->termPar[1][0] = trmp[2];
	}

	if (rbP->term[1] == REIN_TERM_BEND)
	{
		if (trmp[1] == 0) rbP->termPar[0][1] = -180; else rbP->termPar[0][1] = trmp[1];
		if (trmp[3] == 0) rbP->termPar[1][1] = getReinLapBend(rbP->diam, 0); else rbP->termPar[1][1] = trmp[3];
	}

	if (rbP->term[0] == REIN_TERM_MUFT)
		rbP->termPar[2][0] = trmp[0];

	if (rbP->term[1] == REIN_TERM_MUFT)
		rbP->termPar[2][1] = trmp[1];

}

///////////////////////
void setPosString(ReinPos* rpP, int bPoints, int bXml)
{

	int trmp[4] = { 0 };
	//ZeroMemory(trmp, sizeof(trmp));


	setBarTermPar6to4(trmp, &rpP->bar);

	WCH sCurPosFmt[5000];

	if (bXml)
	{
		//SCPY(sCurPosFmt, L(" posID=\"%i\""));				// 00
		//SCAT(sCurPosFmt, L(" srtmID=\"%i\""));				// 01
		SCAT(sCurPosFmt, L(" diam=\"%i\""));				// 02
		SCAT(sCurPosFmt, L(" runmet=\"%i\""));				// 03
		SCAT(sCurPosFmt, L(" mainPtsIndex=\"%i\""));		// 04
		SCAT(sCurPosFmt, L(" transp=\"%i\""));				// 05
		SCAT(sCurPosFmt, L(" bendrad=\"%i\""));				// 06
		//SCAT(sCurPosFmt, L(" bendrad2=\"%i\""));			// 07
		SCAT(sCurPosFmt, L(" term1=\"%i\""));				// 08
		SCAT(sCurPosFmt, L(" term2=\"%i\""));				// 09
		SCAT(sCurPosFmt, L(" pnum=\"%i\""));				// 10
		SCAT(sCurPosFmt, L(" base_qty=\"%.3f\""));			// 11
		SCAT(sCurPosFmt, L(" base_length=\"%i\""));			// 12
		//SCAT(sCurPosFmt, L(" file_qty_p=\"%i\""));			// 13
		//SCAT(sCurPosFmt, L(" file_qty_rm=\"%.3f\""));		// 14
		//SCAT(sCurPosFmt, L(" file_ms_min=\"%i\""));			// 15
		//SCAT(sCurPosFmt, L(" file_ms_mid=\"%i\""));			// 16
		//SCAT(sCurPosFmt, L(" file_ms_max=\"%i\""));			// 17
		SCAT(sCurPosFmt, L(" base_ms_min=\"%i\""));			// 18
		SCAT(sCurPosFmt, L(" base_ms_mid=\"%i\""));			// 19
		SCAT(sCurPosFmt, L(" base_ms_max=\"%i\""));			// 20
		SCAT(sCurPosFmt, L(" length=\"%.5f\""));			// 21
		SCAT(sCurPosFmt, L(" trmp1=\"%i\""));				// 22
		SCAT(sCurPosFmt, L(" trmp2=\"%i\""));				// 23
		SCAT(sCurPosFmt, L(" trmp3=\"%i\""));				// 24
		SCAT(sCurPosFmt, L(" trmp4=\"%i\""));				// 25
		//SCAT(sCurPosFmt, L(" lap_qty=\"%i\""));				// 26
		SCAT(sCurPosFmt, L(" pdID=\"%i\""));				// 27
		//SCAT(sCurPosFmt, L(" muft_qty=\"%i\""));			// 28
		SCAT(sCurPosFmt, L(" pcatID=\"%u\""));				// 29
		SCAT(sCurPosFmt, L(" poscalc=\"%i\""));				// 30
		SCAT(sCurPosFmt, L(" noplanar=\"%i\""));			// 31

	}
	else
		SCPY(sCurPosFmt, L("%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%i;%.3f;%i;%i;%.3f;%i;%i;%i;%i;%i;%i;%.5f;%i;%i;%i;%i;%i;%i;%i;%u;%i;%i")); // 0 - 31


	//printf("  %i  %i\n", i, rpP->posID);

	SPRN(sCurPos, sCurPosFmt,
					rpP->posID,						// 00
					rpP->srtmID, 					// 01
					rpP->bar.diam, 					// 02
					rpP->bar.runmet,				// 03
					rpP->bar.mainPtsIndex,			// 04 // mainSgmIndex???
					rpP->bar.transp,				// 05
					rpP->bar.bendrad,				// 06
					getBendRadius(&rpP->bar, 0),	// 07
					rpP->bar.term[0],				// 08
					rpP->bar.term[1],				// 09
					rpP->bar.pnum,					// 10
					rpP->base_qty,					// 11 double
					rpP->base_length,				// 12
					rpP->file_qty_p,				// 13
					rpP->file_qty_rm,				// 14 double
					rpP->file_ms_min,				// 15
					rpP->file_ms_mid,				// 16
					rpP->file_ms_max,				// 17
					rpP->base_ms_min,				// 18
					rpP->base_ms_mid,				// 19
					rpP->base_ms_max,				// 20
					rpP->bar.length,				// 21 double
					trmp[0],						// 22 param 0/2 beg
					trmp[1],						// 23 param 0/2 end
					trmp[2],						// 24 param 1 beg
					trmp[3],						// 25 param 1 end
					0, //rpP->lap_qty,				// 26
					rpP->pdID,						// 27
					0, //rpP->muft_qty,				// 28
					rpP->pcatID,					// 29
					rpP->bar.poscalc,				// 30
					rpP->bar.noplanar				// 31
					);

	//strcat(sCurPos, "!");
	//for (int a = 0; bPoints && a < rpP->bar.cnumpts; a++)
	//{
	//	sprintf(s, "|%.7f;%.7f;%.7f;%i;%i;%i;%i;%i;%i;%i"
	//		, rpP->bar.apts[a].x, rpP->bar.apts[a].y, 0. // , rpP->bar.apts[a].z for future use
	//		, rpP->bar.cpxb[a].x, rpP->bar.cpxb[a].y, 0 // , rpP->bar.cpxb[a].z for future use
	//		, rpP->bar.cpxe[a].x, rpP->bar.cpxe[a].y, 0 // , rpP->bar.cpxe[a].z for future use
	//		, rpP->bar.rfa[a]
	//		);
	//	//printf("%s\n",s);
	//	strcat(sCurPos, s);
	//}

	//strcat(sCurPos, "!");
	//for (int a = 0; rpP->file_qty_p > 0 && a < rpP->bar.numlen; a++)
	//{
	//	long mid = rpP->bar.blen[a][1] / rpP->file_qty_p;
	//	strcat(s, "|");
	//	sprintf(s, "%i;%i;%i;%i"
	//		, rpP->bar.blen[a][0], mid, rpP->bar.blen[a][2], rpP->bar.brad[a]
	//		);
	//	//printf("%i %i %i\n",rpP->bar.blen[a][0], mid, rpP->bar.blen[a][2]);
	//	strcat(sCurPos, s);
	//}


}

///////////////////////////////////////////////////////////////
double roundExtD(double val, int digs, double snap, int shft)
{

	double dv;

	dv = val * pow(snap, digs);

	dv = floor( dv + 0.55555555555555 - (0.111111111111111 * shft) );

	dv = dv / pow(snap, digs);

	return dv;
}



///////////////////////////////////////////////////////////////
long roundExt(double val, int digs, double snap, int shft)
{

	double dv;

	dv = val * pow(snap, digs);

	dv = floor( dv + 0.55555555555555 - (0.111111111111111 * shft) );

	dv = dv / pow(snap, digs);

	return (long)dv;
}

///////////////////////////////////////////////////////////////
long roundExt(double val, int typ)
{
	int digs = 0;
	double snap = 10.;
	int shft = 0;

	if (typ == ROUND_STD)
	{
		digs = 0;
		snap = 10.;
		shft = 0;
	}
	if (typ == ROUND_ARC)
	{
		digs = -1;
		snap = dCfgVar_BarBendLengthRoundSnap;
		shft = -2;
	}
	if (typ == ROUND_LIN)
	{
		digs = -1;
		snap = dCfgVar_BarLineLengthRoundSnap;
		shft = 0;
	}

	return roundExt(val, digs, snap, shft);

}


/////////////////////////////////////
// получение параметров сегментов - длины, радиусы, углы
void getSegms(MSElementDescr* edP, ReinBar* rbP, int* kosP)
{
	int bFillet = FALSE;

	writeLogIn(__FUNCTION__, 0);


	XMLFragmentListP  oXMLFragmentList = NULL;

	rbP->lenclear();
	//ZeroMemory(rbP->blen, sizeof(rbP->blen));
	//ZeroMemory(rbP->brad, sizeof(rbP->brad));
	//ZeroMemory(rbP->bang, sizeof(rbP->bang));
	//rbP->numlen = 0;

	MSElementDescr* pComponent = edP->h.firstElem;

	while (pComponent)
	{
		if (mdlElement_hasXMLFragmentAttachment(&pComponent->el, &appID, &appTypeSegment) &&
			mdlXMLFragmentList_extractFromElementByAppIDAndType (&oXMLFragmentList, &pComponent->el, 
			&appID, &appTypeSegment) == SUCCESS)
		{
			XMLFragmentP  pXMLFragment;
			MSWCH* wtxt;
			wstring wstr = L"";
			ReinPrm prm;

			pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

			if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
			{
				wstr = wtxt;

				mdlXMLFragmentList_free(&oXMLFragmentList);

				if (readReinFilletFromString(&prm, wstr) == SUCCESS)
				{
					if (bFillet) // два филлета рядом
					{
						rbP->numlen++; // добавляем нулевой сегмент
					}
					bFillet = TRUE;
				}
				else
					bFillet = FALSE;
			}
			else
				bFillet = -1;




			/*

			WCH seps[]   = L(";");
			WCH *token;

			token = STOK( s, seps );

			if (SCMP(token, L("FILLET")) == 0) // "FILLET", "ARC", "LINE"
			{
				if (bFillet) // два филлета рядом
				{
					rbP->numlen++; // добавляем нулевой сегмент
				}
				bFillet = TRUE;
			}
			else
			{
				bFillet = FALSE;
			}*/

			// todo: getSegms() fillet props
			// получение реальной длины загиба, т.к. при изменении параметра округления она может отличаться от той что созранена
			rbP->blen[rbP->numlen][0] = -1;

			if (bFillet == TRUE)
			{
				double dlen;
				MSElementDescr* edpF2 = NULL;
				mdlElmdscr_new(&edpF2, 0, &pComponent->el);

				if (edpF2 && mdlMeasure_linearProperties(&dlen, 0, 0, 0, 0, 0, 0, 0, edpF2, -1) == SUCCESS)
				{
					if (mdlCnv_UORToMaster(&dlen, dlen, edpF2->h.dgnModelRef) == SUCCESS)
						rbP->blen[rbP->numlen][0] = roundExt(dlen, ROUND_ARC);
				}

				if (edpF2) mdlElmdscr_freeAll(&edpF2);

				//=====

				if (rbP->blen[rbP->numlen][0] == -1) rbP->blen[rbP->numlen][0] = prm.ival[0];
				rbP->blen[rbP->numlen][1] = rbP->blen[rbP->numlen][0];
				rbP->blen[rbP->numlen][2] = rbP->blen[rbP->numlen][0];

				rbP->brad[rbP->numlen] = prm.ival[1];

				rbP->bang[rbP->numlen] = prm.dval[0];

				if (kosP) *kosP = prm.ival[2];
			}
			else // "ARC", "LINE"
				if (bFillet == FALSE && wstr.length() > 0) // todo: переделка strtok
			{
				WCH seps[] = L(";");
				WCH* token;
				WCH str[500];

				SCPW2M(str, wstr.c_str(), 500);

				token = STOK(str, seps);

				token = STOK( NULL, seps );
				if (token != NULL)
				{
					if (rbP->blen[rbP->numlen][0] == -1) rbP->blen[rbP->numlen][0] = STOL(token);
				}
				rbP->blen[rbP->numlen][1] = rbP->blen[rbP->numlen][0];
				rbP->blen[rbP->numlen][2] = rbP->blen[rbP->numlen][0];

				token = STOK( NULL, seps );
				if (token != NULL )	rbP->brad[rbP->numlen] = STOL(token);

				token = STOK( NULL, seps );
				if (token != NULL )	rbP->bang[rbP->numlen] = STOF(token);

				token = STOK( NULL, seps );
				if (token != NULL && kosP != NULL)	*kosP = STOI(token);

			}


			
			

			rbP->numlen++;

		}

		pComponent = pComponent->h.next;
	}


	// перевертыш (стержень буквой П)
	if (rbP->runmet > 1 
		&& rbP->numpts == 4 
		&& rbP->numlen == 5
		// переворачивать стержни можно только если совпадают окончания
		&& ((getTrueEnd(rbP, 0) == REIN_TERM_NONE && getTrueEnd(rbP, 1) == REIN_TERM_NONE) 
			|| (getTrueEnd(rbP, 0) != REIN_TERM_NONE && getTrueEnd(rbP, 1) != REIN_TERM_NONE))
		) 
	{
		if (
			/*(rbP->rpts[0].z == rbP->rpts[1].z) 
			&& (rbP->rpts[2].z == rbP->rpts[3].z) 
			&& */EQQ(rbP->bang[1], 90., 0.1) 
			&& EQQ(rbP->bang[3], 90., 0.1) 
			)
		{
			for (int i = 0; i < 3; i++) // rbP->blen[][2] ненадо, ткт это суммарная длина
			{
				if (rbP->blen[0][i] > rbP->blen[4][i])
				{
					long a = rbP->blen[0][i];
					rbP->blen[0][i] = rbP->blen[4][i];
					rbP->blen[4][i] = a;
				}
			}
		}
	}

	writeLogOut(__FUNCTION__, 0);


}



///////////////////////////////////////////////////
int getDataFromString(ReinData* rdP, wstring str, ReinBar* rbP)
{

	if (rdP == NULL) return ERROR;
	rdP->clear();

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	IF_IT_end return ERROR;
	rdP->datdiam = _wtoi(it->c_str());						// 0

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->datrunmet = _wtoi(it->c_str());					// 1

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->datlap[0] = _wtoi(it->c_str());			// 2

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->datlap[1] = _wtoi(it->c_str());			// 3

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->datlap[2] = _wtoi(it->c_str());			// 4

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->datbdrad = _wtoi(it->c_str());			// 5

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->dattrm[0] = _wtoi(it->c_str());			// 6

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->dattrm[1] = _wtoi(it->c_str());			// 7

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->dattrmPar[0][0] = _wtoi(it->c_str());		// 8

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->dattrmPar[0][1] = _wtoi(it->c_str());		// 9

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->dattrmPar[1][0] = _wtoi(it->c_str());		// 10

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->dattrmPar[1][1] = _wtoi(it->c_str());		// 11

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->dattrmPar[2][0] = _wtoi(it->c_str());		// 12

	IF_IT_nxt IF_IT_end return ERROR;
	rdP->dattrmPar[2][1] = _wtoi(it->c_str());		// 13

	IF_IT_nxt IF_IT
		rdP->dattype = _wtoi(it->c_str()); 
	else 
		rdP->dattype = BT_AUTO;		// 14

	IF_IT_nxt IF_IT
		rdP->datposcalc = _wtoi(it->c_str());			// 15

	IF_IT_nxt IF_IT
		rdP->datspacef = _wtof(it->c_str());
	else if (rbP)
		rdP->datspacef = rbP->spacef;			// 16

	if ((int)rdP->datspacef == 0) 
		rdP->datspacef = (double)iSpaceDefault;

	IF_IT_nxt IF_IT
		rdP->datoffset[0] = _wtoi(it->c_str());
	else if (rbP)
		rdP->datoffset[0] = rbP->offset[0];			// 17

	IF_IT_nxt IF_IT
	{
		rdP->datoffset[1] = _wtoi(it->c_str()); // минус поставить когда будет сделана отработка
		//if (rdP->datoffset[1] > 0) rdP->datoffset[1] = 0;
		//if (rdP->datoffset[1] < 0) rdP->datoffset[1] = -rdP->datoffset[1];
	}
	else if (rbP)
		rdP->datoffset[1] = rbP->offset[1];			// 18






	/*

	WCH seps[]   = L(";");
	WCH *token;


	if (ctxt == NULL) return ERROR;
	if (SLEN(ctxt) == 0) return ERROR;



	token = STOK( ctxt, seps );
	if (token != NULL )	rdP->datdiam = STOI(token);				// 0

	token = STOK( NULL, seps );
	if (token != NULL )	rdP->datrunmet = STOI(token);			// 1

	token = STOK( NULL, seps );
	if (token != NULL )	rdP->datlap[0] = STOI(token);			// 2

	token = STOK( NULL, seps );
	if (token != NULL )	rdP->datlap[1] = STOI(token);			// 3

	token = STOK( NULL, seps );
	if (token != NULL )	rdP->datlap[2] = STOI(token);			// 4

	token = STOK( NULL, seps );
	if (token != NULL )	rdP->datbdrad = STOI(token);			// 5

	token = STOK( NULL, seps );
	if (token != NULL )	rdP->dattrm[0] = STOI(token);			// 6

	token = STOK( NULL, seps );
	if (token != NULL )	rdP->dattrm[1] = STOI(token);			// 7

	token = STOK( NULL, seps );
	if( token != NULL )	rdP->dattrmPar[0][0] = STOI(token);		// 8

	token = STOK( NULL, seps );
	if( token != NULL )	rdP->dattrmPar[0][1] = STOI(token);		// 9

	token = STOK( NULL, seps );
	if( token != NULL )	rdP->dattrmPar[1][0] = STOI(token);		// 10

	token = STOK( NULL, seps );
	if( token != NULL )	rdP->dattrmPar[1][1] = STOI(token);		// 11

	token = STOK( NULL, seps );
	if( token != NULL )	rdP->dattrmPar[2][0] = STOI(token);		// 12

	token = STOK( NULL, seps );
	if( token != NULL )	rdP->dattrmPar[2][1] = STOI(token);		// 13

	token = STOK( NULL, seps );
	if( token != NULL )	rdP->dattype = STOI(token); else rdP->dattype = BT_AUTO;		// 14

	token = STOK( NULL, seps );
	if (token != NULL )	rdP->datposcalc = STOI(token);			// 15

	token = STOK( NULL, seps );
	if (token != NULL )	rdP->datspace = STOI(token); else rdP->datspace = rbP->space;			// 16
	if (rdP->datspace == 0) rdP->datspace = iSpaceDefault;

	token = STOK( NULL, seps );
	if (token != NULL )	rdP->datoffset[0] = STOI(token); else rdP->datoffset[0] = rbP->offset[0];			// 17

	token = STOK( NULL, seps );
	if (token != NULL )	
	{
		rdP->datoffset[1] = STOI(token); // минус поставить когда будет сделана отработка
		//if (rdP->datoffset[1] > 0) rdP->datoffset[1] = 0;
		//if (rdP->datoffset[1] < 0) rdP->datoffset[1] = -rdP->datoffset[1];
	}
	else 
		rdP->datoffset[1] = rbP->offset[1];			// 18


	*/

	return SUCCESS;
}


///////////////////////////////////////////////////////////////
int readReinDataFromElmd(
	ReinElement* relemP, // may be NULL
	//ReinData* rdP, 
	MSElementDescr  *edP, // element to get text from
	ReinBar* rbP // bar to get additional data, may be NULL
)
{
	//if (relemP == NULL) return ERROR;
	if (edP == NULL) return ERROR;

	int ret = ERROR;

	if (iDebug) writeLogIn(__FUNCTION__, 0); // readReinDataFromElmd in

	XMLFragmentListP  oXMLFragmentList = NULL;

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);
		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);
			mdlXMLFragmentList_free(&oXMLFragmentList);

			if (relemP)
			{
				ret = getDataFromString(&(relemP->rd), wstr, rbP);
			}
			else
			{
				ret = SUCCESS; // simply check ReinData element
			}


		}
		else
			ret = ERROR;

	}

	if (relemP && ret == SUCCESS)
	{
		readBarOversFromElement(relemP, (MSElementP)&edP->el);
	}


	if (iDebug) sprintf(sLogMes, "return %i\n", ret); writeLog(0, 0);
	if (iDebug) writeLogOut(__FUNCTION__, 0); // readReinDataFromElmd out

	return ret;
	
}

//////////////////////////////////////////////////////
int intersectDataBars2(
	MSElementDescr* edpShape,
	DVec3d* nrmP,
	ELID* elidP, 
	double doffs,
	int iDerivBarIndex
)
{

	DVec3d pOffs;
	Transform tm;
	RotMatrix rm;

	elemIterCount = 0;

	for (UInt32 i = 0; i < iDataElemCount; i++)
	{

		ELREF eref = getElemRefByID(ACTIVEMODEL, arDataPreps[i].elemid);

		if (eref)
		{
			MSElementDescr* edp = NULL;

			mdlElmdscr_getByElemRef(&edp, eref, ACTIVEMODEL, FALSE, 0);

			ReinBar rb;

			DVec3d pInt2;


			if (readReinBarFromElement(&rb, edp, FALSE) == SUCCESS)
			{
				if (
					rb.elemid == *elidP)
				{

					ReinBar* rbP = NULL;

					rbP = &arDataBars[arDataNums[elemIterCount]];

					//rbP->space = rb.space;
					rbP->spacef = rb.spacef;
					rbP->spacerad = rb.spacerad;
					rbP->offset[0] = rb.offset[0];
					rbP->offset[1] = rb.offset[1];
					rbP->bendrad = rb.bendrad;
					rbP->poscalc = rb.poscalc;


					ReinBar* rbArcP = NULL;

					if (i > 0 && arDataPreps[i].bartype == ARC_ELM && arDataPreps[i-1].bartype == ARC_ELM)
					{
						// один центр?
						//if (mdlVec_equal(&arDataPreps[i].cents[0], &arDataPreps[i - 1].cents[0]))

						rbArcP = rbP;

					}

					rbP->bartype = arDataPreps[i].bartype;

					mdlElmdscr_duplicate(&edpShapeForPoints, edpShape);

					mdlTMatrix_getIdentity(&tm);

					mdlVec_scaleToLength(&pOffs, nrmP, doffs);

					mdlTMatrix_setTranslation(&tm, &pOffs);

					func_amp(mdlElmdscr_transform, edpShapeForPoints), & tm);


					int numInt = 0;
					numInt = intersectElements(edp, edpShapeForPoints, &pInt2, rbArcP);

					if (iDebug) sprintf(sLogMes, "numInt = %i\n", numInt); writeLog(0, 0);

					if (numInt == 2
						|| (numInt == 1 && rbP->numpts) // пересечение арок только если уже есть точки от предыдущего пересечения
						)
					{
						//rbP->rpts.push_back(pInt2);
						//rbP->cents.push_back(pZero);
						//rbP->rfa.push_back(0);
						//rbP->numpts = rbP->rpts.size();
						rbP->rpts[rbP->numpts] = pInt2;
						rbP->numpts++;
						arDataNums[elemIterCount]++;
						elemIterCount++;
					}

					mdlElmdscr_freeAll(&edpShapeForPoints);

				}

			}

			mdlElmdscr_freeAll(&edp);
		}

	}

	return SUCCESS;
}


//////////////////////////////////////////////////////
int scanForCopyDataBars(
MSElementDescr  *edP,
ELID*         elidP,
ScanCriteria    *pScanCriteria
)
{

	writeLogIn(__FUNCTION__, 0);

	ReinBar rb;
	int res = SUCCESS;

	if (readReinBarFromElement(&rb, edP, FALSE) == SUCCESS)
	{
		if (rb.bartype != BT_AXIS && rb.elemid == *elidP)
		{

			ReinBar* rbP = &reCopyFrom.bel;

			//rbP->space = rb.space;
			rbP->spacef = rb.spacef;
			rbP->spacerad = rb.spacerad;
			rbP->offset[0] = rb.offset[0];
			rbP->offset[1] = rb.offset[1];
			rbP->bendrad = rb.bendrad;
			rbP->poscalc = rb.poscalc;

			if (iDebug) sprintf(sLogMes, "_scanForCopyDataBars() returns 1\n"); writeLog(0, 0);

			return 1; // только первый

		}
	}

	writeLogOut(__FUNCTION__, 0);

	return 0;
}


//////////////////////////////////////////////////////
int scanForPrepareDataBars(
MSElementDescr  *edP,
ELID*         elidP,
ScanCriteria    *pScanCriteria
)
{
	ReinBar rb;
	//ReinBar rbb;

	writeLogIn(__FUNCTION__, 0);

	if (readReinBarFromElement(&rb, edP, FALSE) == SUCCESS)
	{
		int typ = mdlElement_getType(&edP->el);

		if (rb.bartype != BT_AXIS && rb.elemid == *elidP)
		{
			//rbb.elemid = mdlElement_getID(&edP->el);
			arDataPreps[iDataElemCount].elemid = mdlElement_getID(&edP->el);

			//rbb.contnum = rb.contnum;
			arDataPreps[iDataElemCount].contnum = rb.contnum;

			//mdlElmdscr_extractEndPoints(&arDataPreps[iDataElemCount].nrm, 0, 0, 0, edP, edP->h.dgnModelRef);

			arDataPreps[iDataElemCount].bartype = typ;

			if (typ == ARC_ELM)
			{
				mdlArc_extract(0, 0, 0, 0, 0, 0, &arDataPreps[iDataElemCount].cents[0], &edP->el);
			}

			iBarTypeAuto |= typ;

			//arDataPreps.push_back(rbb);

			iDataElemCount++;

			if (iDebug) sprintf(sLogMes, "_scanForPrepareDataBars() iDataElemCount = %u\n", iDataElemCount); writeLog(0, 0);
			//sprintf(sLogMes, "_scanForPrepareDataBars() arDataPreps.size() = %u\n", arDataPreps.size()); writeLog(0, 0);
		}
	}

	writeLogOut(__FUNCTION__, 0);

	return SUCCESS;
}


//////////////////////////////////////////////////////
int calcDataBars(
MSElementDescr  *edP,
MSElementDescr  *edNxtP,
ELID*         elidP,
int iBarType
)
{

	ReinBar rb;
	double dspace = 0.;
	double doffs = 0.;
	int res = SUCCESS;

	writeLogIn(__FUNCTION__, 0);

	if (readReinBarFromElement(&rb, edP, FALSE) == SUCCESS)
	{

		// определение шага/отступа
		if ((int)rb.spacef > 0)
			dspace = mdlCnv_masterUnitsToUors(rb.spacef);
		else
			dspace = mdlCnv_masterUnitsToUors(iSpaceDefault);

		doffs = mdlCnv_masterUnitsToUors(rb.offset[0]);


		if (iBarType == BT_GIB && rb.elemid == *elidP)
		{

			while (res == SUCCESS)
			{
				double dsp = dspace;
				double dof = doffs;
				ReinBar* rbP = NULL;

				//if (arDataNums[elemCount] < arDataBars.size())
					rbP = &arDataBars[arDataNums[elemCount]];
				//else
				//{
				//	ReinBar rbb;
				//	arDataBars.push_back(rbb);
				//	rbP = &(arDataBars.back());
				//}

				//rbP->space = rb.space;
				rbP->spacef = rb.spacef;
				rbP->spacerad = rb.spacerad;
				rbP->offset[0] = rb.offset[0];
				rbP->offset[1] = rb.offset[1];
				rbP->bendrad = rb.bendrad;
				rbP->poscalc = rb.poscalc;

				if (mdlElement_getType(&edP->el) == ARC_ELM && rb.spacerad > 0)
				{
					double drad[2];
					if (mdlArc_extract(0, 0, 0, &drad[0], &drad[1], 0, 0, &edP->el) == SUCCESS)
					{
						dsp = dspace * (drad[0] + drad[1]) / 2. / mdlCnv_masterUnitsToUors(rb.spacerad);
						dof = doffs * (drad[0] + drad[1]) / 2. / mdlCnv_masterUnitsToUors(rb.spacerad);
					}
				}

				//DVec3d p;
				//res = mdlElmdscr_pointAtDistance(&p, 0, dof + dsp * arDataNums[elemCount], edP, 0);

				res = mdlElmdscr_pointAtDistance(&rbP->rpts[rbP->numpts], 0, dof + dsp * arDataNums[elemCount], edP, 0);

				if (res == SUCCESS) 
				{
					//rbP->rpts.push_back(p);
					//rbP->cents.push_back(pZero);
					//rbP->rfa.push_back(0);
					rbP->numpts++;
					arDataNums[elemCount]++;
				}

			}

			if (arDataNums[elemCount] > 0)
			{
				elemCount++;
			}
		}
		else if (iBarType == BT_SEC && rb.elemid == *elidP)
		{
			ReinBar* rbP = NULL; // &arDataBars[0];

			//if (arDataBars.empty())
			//{
			//	ReinBar rbb;
			//	arDataBars.push_back(rbb);
			//}

			rbP = &arDataBars[0]; //  arDataBars.data(); // pointer to array or first element

			//rbP->space = rb.space;
			rbP->spacef = rb.spacef;
			rbP->spacerad = rb.spacerad;
			rbP->offset[0] = rb.offset[0];
			rbP->offset[1] = rb.offset[1];
			rbP->bendrad = rb.bendrad;
			rbP->poscalc = rb.poscalc;

			//DVec3d p;

			if (mdlElmdscr_extractEndPoints(&rbP->rpts[rbP->numpts], 0, 0, 0, edP, edP->h.dgnModelRef) == SUCCESS)
			//if (mdlElmdscr_extractEndPoints(&p, 0, 0, 0, edP, edP->h.dgnModelRef) == SUCCESS)
			{
				//if (elemCount == 0)	
				//{
				//	DVec3d pCentroid;
				//	mdlMeasure_linearProperties(0, &pCentroid, 0, 0, 0, 0, 0, 0, edP, 0);
				//	mdlVec_subtractPoint(&rbP->nrm, &pCentroid, &rbP->rpts[rbP->numpts]);
				//	mdlVec_normalize2(&rbP->nrm);
				//	//mdlVec_negateInPlace(&rbP->nrm);
				//}

				if (elemCount == 0)	// для первого
				{
					DVec3d pv[4];
					mdlElmdscr_extractEndPoints(&pv[0], 0, &pv[1], 0, edP, 0);
					mdlElmdscr_extractEndPoints(&pv[2], 0, 0, 0, edNxtP, 0);
					mdlVec_crossProduct3Points(&pv[3], &pv[0], &pv[1], &pv[2]);
					mdlVec_normalize2(&pv[3]);
					mdlVec_subtractPoint(&pv[2], &pv[2], &pv[0]);
					mdlVec_normalize2(&pv[2]);
					mdlVec_crossProduct(&rbP->v_enrm, &pv[3], &pv[2]);
				}

				//rbP->rpts.push_back(p);
				//rbP->cents.push_back(pZero);
				//rbP->rfa.push_back(0);
				rbP->numpts++;
				elemCount++;

			}

		}
		else if (iBarType == BT_PAR && rb.elemid == *elidP)
		{
			DVec3d pLft[2];
			DVec3d pRgt[2];
			DVec3d pVecLft[2];
			DVec3d pVecRgt[2];
			DVec3d pVecTng[2];
			double dang[3] = {fc_piover2, fc_piover2, fc_piover2 };
			double dspc[2] = {dspace, dspace};
			double dofs[2] = {doffs, doffs};

			// вычисление угла

			if (edNxtP && edP)
			{
				mdlElmdscr_extractEndPoints(&pLft[0], &pVecTng[0], &pLft[1], 0, edP, ACTIVEMODEL);
				mdlElmdscr_extractEndPoints(&pRgt[0], &pVecTng[1], &pRgt[1], 0, edNxtP, ACTIVEMODEL);

				mdlVec_subtractPoint(&pVecLft[0], &pLft[1], &pLft[0]);
				mdlVec_subtractPoint(&pVecLft[1], &pRgt[0], &pLft[0]);

				mdlVec_subtractPoint(&pVecRgt[0], &pRgt[1], &pRgt[0]);
				mdlVec_subtractPoint(&pVecRgt[1], &pLft[0], &pRgt[0]);

				mdlVec_normalize2(&pVecLft[0]);
				mdlVec_normalize2(&pVecLft[1]);
				mdlVec_normalize2(&pVecRgt[0]);
				mdlVec_normalize2(&pVecRgt[1]);

				dang[0] = mdlVec_angleBetweenVectors(&pVecLft[0], &pVecLft[1]);
				dang[1] = mdlVec_angleBetweenVectors(&pVecRgt[0], &pVecRgt[1]);
				dang[2] = mdlVec_angleBetweenVectors(&pVecTng[0], &pVecTng[1]); // угол между направляющими (вектора начала)

				dspc[0] = dspace / sin(dang[0]); // сравнить с предыдущим (arDataSpaces[elemCount])
				dspc[1] = dspace / sin(dang[1]);

				dofs[0] = doffs / sin(dang[0]);
				dofs[1] = doffs / sin(dang[1]);

			}
			else
			{
				dspc[0] = arDataSpaces[elemCount].vals[0];
				dofs[0] = arDataSpaces[elemCount].vals[1];
			}

				
			double dOtn = 1.;

			if (elemCount > 0) 
			{
				dOtn = arDataSpaces[elemCount].vals[0] / dspc[0];
				dspc[0] = arDataSpaces[elemCount].vals[0];
				dofs[0] = arDataSpaces[elemCount].vals[1];
				dspc[1] = dspc[1] * dOtn;
				dofs[1] = dofs[1] * dOtn;
			}

			if (elemCount + 1 < MAX_BAR_VERTICES)
			{
				arDataSpaces[elemCount + 1].vals[0] = dspc[1];
				arDataSpaces[elemCount + 1].vals[1] = dofs[1];
			}

			while (res == SUCCESS)
			{
				//ReinBar* rbP = &arDataBars[arDataNums[elemCount]];

				ReinBar* rbP = NULL;

				//if (arDataNums[elemCount] < arDataBars.size())
					rbP = &arDataBars[arDataNums[elemCount]];
				//else
				//{
				//	ReinBar rbb;
				//	arDataBars.push_back(rbb);
				//	rbP = &(arDataBars.back());
				//}

				//rbP->space = rb.space;
				rbP->spacef = rb.spacef;
				rbP->spacerad = rb.spacerad;
				rbP->offset[0] = rb.offset[0];
				rbP->offset[1] = rb.offset[1];
				rbP->bendrad = rb.bendrad;
				rbP->poscalc = rb.poscalc;

				//DVec3d p;
				//res = mdlElmdscr_pointAtDistance(&p, 0, doffs + dsp[0] * arDataNums[elemCount], edP, 0);

				res = mdlElmdscr_pointAtDistance(&rbP->rpts[rbP->numpts], 0, dofs[0] + dspc[0] * arDataNums[elemCount], edP, 0);

				if (res == SUCCESS) 
				{
					//rbP->rpts.push_back(p);
					//rbP->cents.push_back(pZero);
					//rbP->rfa.push_back(0);
					rbP->numpts++;
					arDataNums[elemCount]++;
				}

			}


			if (arDataNums[elemCount] > 0)
			{
				elemCount++;
			}


		}


	}

	writeLogOut(__FUNCTION__, 0);

    return SUCCESS;
}


/////////////////////////
int sortBars(
ReinBar	arg1[],
ReinBar	arg2[]
)
{
	if (arg1->contnum < arg2->contnum)
		return -1;
	else if (arg1->contnum > arg2->contnum)
		return 1;
	else if (arg1->elemid < arg2->elemid)
		return -1;
	else if (arg1->elemid > arg2->elemid)
		return 1;
	else
		return 0;
}

///////////////////////
//bool sortBarsVec(ReinBar arg1, ReinBar arg2)
//{
//	if (arg1.contnum < arg2.contnum)
//		return true;
//	else if (arg1.contnum > arg2.contnum)
//		return false;
//	else if (arg1.elemid < arg2.elemid)
//		return true;
//	else if (arg1.elemid > arg2.elemid)
//		return false;
//	else
//		return false;
//}

/////////////////
// шинковка - пробежка шейпом с заданным шагом и пересечение с образующими
int processSec(ReinBar* rbP, MSElementDescr* edpShape, double doffs, double dspace)
{

	writeLogIn(__FUNCTION__, 0);

	int cnt = 0;
	int iNum = 0;

	//if (arDataBars.empty()) return 0;

	while (elemCount > 0 && cnt < 1000)
	{
		DVec3d nrmalt;

		mdlVec_negate(&nrmalt, &arDataBars[0].v_enrm); // для алтернативного направления

		// first try...
		intersectDataBars2(edpShape, &arDataBars[0].v_enrm, &rbP->elemid, doffs + dspace * iNum, iNum);


		if (elemIterCount == 0) // не в ту сторону? 
		{
			// second try...
			intersectDataBars2(edpShape, &nrmalt, &rbP->elemid, doffs + dspace * iNum, iNum);
		}
		
		if (elemIterCount > 0) iNum++;

		//if (cnt == 0 && elemCount == 0 && bInvert == FALSE) 
		//{
		//	doffs = -doffs;
		//	dspace = -dspace;
		//	iNum = 0;
		//	bInvert = TRUE;
		//	continue;
		//}

		if (cnt == 0 && elemIterCount == 0) break;

		cnt++;

	}

	if (iDebug) sprintf(sLogMes, "return %i\n", iNum); writeLog(0, 0);
	writeLogOut(__FUNCTION__, 0);

	return iNum;

}


//////////////////////////////////////////////////////////
// func in reinCreateDataBars
void reinCreateDataBars(
					int bAdd, 
					ReinElement* relemP, 
					ReinBar* rbP, 
					MSElementDescr* edP
)
{


	writeLogIn(__FUNCTION__, 0);

	ScanCriteria    *pScanCriteria;
	int status;

	if (relemP == NULL) return;

	ReinData* rdP = &(relemP->rd);
	
	int evencnt[2] = {0,0};
	evencnt[1] = rdP->datlap[2];

	iBarTypeAuto = 0;

	int iBarType = 0;

	elemCount = 0; // счетчик образующих элементов
	iDataElemCount = 0;

	//arDataBars.clear();
	//arDataBars.resize(1000);
	//ZeroMemory(arDataBars, sizeof(arDataBars));
	for (UInt32 i = 0; i < 1000; i++)	arDataBars[i].clear();

	//arDataNums.clear();
	//arDataNums.resize(MAX_BAR_VERTICES);
	for (int i = 0; i < MAX_BAR_VERTICES; i++)	arDataNums[i] = 0;


	//arDataPreps.clear();
	//arDataPreps.resize(MAX_BAR_VERTICES);
	//ZeroMemory(arDataPreps, 0, sizeof(arDataPreps));
	for (UInt32 i = 0; i < MAX_BAR_VERTICES; i++)	arDataPreps[i].clear();

	//arDataSpaces.clear();
	//arDataSpaces.resize(MAX_BAR_VERTICES);
	//ZeroMemory(arDataSpaces, sizeof(arDataSpaces));
	for (UInt32 i = 0; i < MAX_BAR_VERTICES; i++) { arDataSpaces[i].vals[0] = 0.; arDataSpaces[i].vals[1] = 0.;}

	writeLog("_scanForPrepareDataBars", 1);

	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanForPrepareDataBars, &rbP->elemid);
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	mdlXML_addXMLFragmentAttachmentScanTest (pScanCriteria, &appID, &appTypeReinBar);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	if (iDebug) sprintf(sLogMes, "iDataElemCount = %u\n", iDataElemCount); writeLog(0, 0);
	//sprintf(sLogMes, "arDataPreps.size() -= %u\n", arDataPreps.size()); writeLog(0, 0);

	writeLog("_scanForPrepareDataBars", -1);

	//if (arDataPreps.size() < 2)
	if (iDataElemCount < 2)
	{
		writeLogOut(__FUNCTION__, "if (iDataElemCount < 2) ");
		//writeLogOut(__FUNCTION__, "if (arDataPreps.size() < 2) ");
		return;
	}

	if (iDebug) sprintf(sLogMes, "sort arDataPreps\n"); writeLog(0, 0);
	mdlUtil_quickSort(arDataPreps, iDataElemCount, sizeof(ReinBar), (PFToolsSortCompare)sortBars);
	if (iDebug) sprintf(sLogMes, "sorted\n"); writeLog(0, 0);
	//sort(arDataPreps.begin(), arDataPreps.end(), sortBarsVec);

	if (iBarTypeAuto == LINE_ELM) iBarTypeAuto = BT_PAR;
	else if (iBarTypeAuto == ARC_ELM) iBarTypeAuto = BT_GIB;
	else iBarTypeAuto = BT_SEC;

	if (rdP->dattype == BT_AUTO)
		iBarType = iBarTypeAuto;
	else
		iBarType = rdP->dattype;

	writeLog("loop", 1, "for prepare create bars");

	//for (int i = 0; i < arDataPreps.size(); i++)
	for (UInt32 i = 0; i < iDataElemCount; i++)
	{
		ELREF eref[2] = {NULL,NULL};
		MSElementDescr* edp[2] = {NULL,NULL};

		eref[0] = getElemRefByID(ACTIVEMODEL, arDataPreps[i].elemid);
		eref[1] = getElemRefByID(ACTIVEMODEL, arDataPreps[i + 1].elemid);

		//edp[0] = NULL;
		//edp[1] = NULL;

		//if (i < arDataPreps.size()) 
		//	eref[0] = getElemRefByID(ACTIVEMODEL, arDataPreps[i].elemid);

		//if (i+1 < arDataPreps.size()) 
		//	eref[1] = getElemRefByID(ACTIVEMODEL, arDataPreps[i+1].elemid);

		if (eref[0]) mdlElmdscr_getByElemRef (&edp[0], eref[0], ACTIVEMODEL, FALSE, 0);
		if (eref[1]) mdlElmdscr_getByElemRef (&edp[1], eref[1], ACTIVEMODEL, FALSE, 0);

		if (eref[0])
		{

			elemCount = i;

			calcDataBars(edp[0], edp[1], &rbP->elemid, iBarType);

		}

		if (edp[0]) mdlElmdscr_freeAll(&edp[0]);
		if (edp[1]) mdlElmdscr_freeAll(&edp[1]);

	}
	writeLog("loop", -1);

	
	if (iBarType == BT_GIB || iBarType == BT_PAR)
	{
		int iMaxNum = 0;

		for (UInt32 i = 0; i < elemCount; i++)
		{
			if (iMaxNum < arDataNums[i]) iMaxNum = arDataNums[i];
		}

		writeLog("loop", 1, "for create bars");

		for (int i = 0; i < iMaxNum; i++)
		//for (UInt32 i = 0; i < iMaxNum && i < arDataBars.size(); i++)
		{
			arDataBars[i].elemid = rbP->elemid;

			arDataBars[i].fromReinData(rdP);

			evencnt[1] = !evencnt[1];
			evencnt[0] = !evencnt[1];

			if (arDataBars[i].numpts > 1) 
			{

				map<int, BarOver>::iterator it = relemP->mapOvers.begin();
				it = relemP->mapOvers.find(i+1); // inum is 1-based index

				if (!(							// not (exist and deleted)
					it != relemP->mapOvers.end()	// found
					&& it->second.isdel			// deleted
					))
				{
					arDataBars[i].createBar(edP, TRUE, TRUE, 0, 0, i + 1, iMaxNum,
						evencnt[0] * rdP->datlap[0], evencnt[1] * rdP->datlap[1]);
				}

			}
		}

		writeLog("loop", -1, "for create bars");

	}

	if (iBarType == BT_SEC && arDataBars[0].numpts > 1)
	//if (iBarType == BT_SEC && arDataBars.size() > 0 && arDataBars[0].numpts > 1)
	{
		Transform tm;
		DVec3d pCent;
		DVec3d pCentNeg;
		double dscale = dCfgVar_BarSecScale;
		MSElementDescr* edpShape = NULL;
		DVec3d pDlt[4];

		for (int b = 0; b < 4; b++)
			mdlVec_zero(&pDlt[b]);

		bool bLine = false;

		if (arDataBars[0].numpts == 2) // превращаем линию в шейп
		{
			bLine = true;
		}
		else if (arDataBars[0].numpts > 2) // проверяем не находятсяли точки на одной линии
		{
			bLine = true;

			// пока только проверка на координату z, надо проверять лежат ли точки на одной линии?
			for (int i = 1; i < arDataBars[0].numpts; i++)
			{
				double tol = 0.1;
				if (!EQQ(arDataBars[0].rpts[0].z, arDataBars[0].rpts[i].z, tol))
					bLine = false;
			}

		}


		if (bLine)
		{
			RotMatrix rm;
			mdlRMatrix_fromNormalVector(&rm, &arDataBars[0].v_enrm);

			for (int i = 0; i < MAX_BAR_VERTICES; i++)
				arDataBars[1].rpts[i] = arDataBars[0].rpts[i];

			//ReinBar rbb;
			//arDataBars.push_back(rbb); // arDataBars[1]

			//arDataBars[1].rpts = arDataBars[0].rpts;

			arDataBars[0].rpts[0] = arDataBars[1].rpts[0];
			arDataBars[0].rpts[1] = arDataBars[1].rpts[0];
			arDataBars[0].rpts[2] = arDataBars[1].rpts[1];
			arDataBars[0].rpts[3] = arDataBars[1].rpts[1];

			mdlVec_fromRotMatrixRow(&pDlt[0], &rm, 0);
			mdlVec_fromRotMatrixRow(&pDlt[1], &rm, 1);
			mdlVec_negate(&pDlt[2], &pDlt[0]);
			mdlVec_negate(&pDlt[3], &pDlt[1]);

			mdlVec_scaleToLengthInPlace(&pDlt[0], 1000.);
			mdlVec_scaleToLengthInPlace(&pDlt[1], 1000.);
			mdlVec_scaleToLengthInPlace(&pDlt[2], 1000.);
			mdlVec_scaleToLengthInPlace(&pDlt[3], 1000.);

			mdlVec_addPoint(&arDataBars[0].rpts[0], &arDataBars[0].rpts[0], &pDlt[0]);
			mdlVec_addPoint(&arDataBars[0].rpts[1], &arDataBars[0].rpts[1], &pDlt[1]);
			mdlVec_addPoint(&arDataBars[0].rpts[2], &arDataBars[0].rpts[2], &pDlt[2]);
			mdlVec_addPoint(&arDataBars[0].rpts[3], &arDataBars[0].rpts[3], &pDlt[3]);

			arDataBars[0].numpts = 4;

			//mdlLine_create(&elTmp, NULL, arDataBars[0].rpts);
			//mdlElmdscr_new(&edpShape, NULL, &elTmp);
		}

		//std::copy(arDataBars[0].rpts.begin(), arDataBars[0].rpts.end(), ptstmp);
		//mdlElmdscr_createFromVertices(&edpShape, &c0w0s0, ptstmp, arDataBars[0].rpts.size(), TRUE, 1);
		int res = mdlElmdscr_createFromVertices(&edpShape, &c0w0s0, arDataBars[0].rpts, arDataBars[0].numpts, TRUE, 1);

		//if (res != SUCCESS) // линия 3 точки возвр. SUCCESS
		//{
		//	writeLogOut(__FUNCTION__, "mdlElmdscr_createFromVertices not SUCCESS");
		//	return;
		//}

		Transform tmm;
		Transform tmmInv;
		DVec3d org;
		DVec3d end;

		mdlElmdscr_orientationExt(&tmm, edpShape, ACTIVEMODEL); // получаем ориентацию

		mdlTMatrix_getInverse(&tmmInv, &tmm); // обратная

		func_amp(mdlElmdscr_transform,edpShape), &tmmInv); // в нуль и без поворота

		// центроид
		mdlMeasure_linearProperties(0, &pCent, 0, 0, 0, 0, 0, 0, edpShape, 0);
		mdlVec_negate(&pCentNeg, &pCent);

		// в центр
		mdlTMatrix_getIdentity(&tm);
		mdlTMatrix_setTranslation(&tm, &pCentNeg);
		func_amp(mdlElmdscr_transform,edpShape), &tm);

		mdlElmdscr_computeRange(&org, &end, edpShape, NULL);

		mdlElmdscr_freeAll(&edpShape);

		// новый шейп
		pts[0] = org;
		pts[1] = org;
		pts[2] = end;
		pts[3] = end;

		//if (arDataBars[0].numpts == 2)
		//{
		//	pts[0].x -= 1000.;
		//	pts[0].y -= 1000.;
		//	pts[1].x -= 1000.;
		//	pts[1].y += 1000.;
		//	pts[2].x += 1000.;
		//	pts[2].y += 1000.;
		//	pts[3].x += 1000.;
		//	pts[3].y -= 1000.;
		//}

		pts[4] = pts[0];

		pts[1].y = pts[2].y;
		pts[3].y = pts[0].y;

		res = mdlElmdscr_createFromVertices(&edpShape, &c0w0s0, pts, 5, TRUE, 1);


		// масштабируем
		mdlTMatrix_getIdentity(&tm);
		mdlTMatrix_scale(&tm, &tm, dscale, dscale, dscale);
		func_amp(mdlElmdscr_transform,edpShape), &tm);

		// обратно
		func_amp(mdlElmdscr_transform,edpShape), &tmm);


		mdlElmdscr_extractNormal(&arDataBars[0].v_enrm, 0, edpShape, &pZ);
		mdlVec_normalize2(&arDataBars[0].v_enrm);

		
		int iNum = 0;

		//double dspace = mdlCnv_masterUnitsToUors(arDataBars[0].space);
		//double doffs = mdlCnv_masterUnitsToUors(rbP->offset[0]); // rbP->offset[0] исп. тк не хранится в ReinData

		double dspace = 0.;
		double doffs = 0.;
		
		//if (rdP->datspace < 0)
		//	dspace = mdlCnv_masterUnitsToUors(arDataBars[0].space);
		//else
			dspace = mdlCnv_masterUnitsToUors(rdP->datspacef);
		
		//if (rdP->datoffset[0] < 0)
		//	doffs = mdlCnv_masterUnitsToUors(rbP->offset[0]);
		//else
			doffs = mdlCnv_masterUnitsToUors(rdP->datoffset[0]);

		//int bInvert = FALSE;

		// очищаем предварительно созданные точки
		arDataBars[0].numpts = 0;
		//arDataBars[0].rpts.clear();
		//arDataBars[0].cents.clear();
		//arDataBars[0].rfa.clear();

		//=========================
		iNum = processSec(rbP, edpShape, doffs, dspace);
		//=========================

		//if (iNum == 0
		//	|| (iNum == 1 && EQ(doffs, 0.0))
		//	)
		//{
		//	if (iNum == 1) doffs = dspace;
		//	mdlVec_negateInPlace(&arDataBars[0].nrm);
		//	iNum = processSec(rbP, edpShape, doffs, dspace);
		//}


		mdlElmdscr_freeAll(&edpShape);



		writeLog("loop", 1, "for create bars");

		for (int i = 0; bAdd && i < iNum; i++)
		//for (UInt32 i = 0; i < iNum && i < arDataBars.size(); i++)
		{
			arDataBars[i].elemid = rbP->elemid;


			arDataBars[i].fromReinData(rdP);


			evencnt[1] = !evencnt[1];
			evencnt[0] = !evencnt[1];

			if (arDataBars[i].numpts > 1) 
			{
				map<int, BarOver>::iterator it = relemP->mapOvers.begin();
				it = relemP->mapOvers.find(i + 1); // inum is 1-based index

				if (!(							// not (exist and deleted)
					it != relemP->mapOvers.end()	// found
					&& it->second.isdel			// deleted
					))
				{
					arDataBars[i].createBar(edP, TRUE, TRUE, 0, 0, i + 1, iNum,
						evencnt[0] * rdP->datlap[0], evencnt[1] * rdP->datlap[1], bDropReinData);
				}
			}
		}

		writeLog("loop", -1, "for create bars");

		if (bAdd && bDropReinData)
		{
			ScanCriteria* pScanCrit;
			int st;

			pScanCrit = mdlScanCriteria_create();
			st = mdlScanCriteria_setReturnType(pScanCrit, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			st = mdlScanCriteria_setElmDscrCallback(pScanCrit, (PFScanElemDscrCallback)scanClearDataBars, &rbP->elemid);
			st = mdlScanCriteria_setModel(pScanCrit, ACTIVEMODEL);
			mdlXML_addXMLFragmentAttachmentScanTest(pScanCrit, &appID, &appTypeReinBar);
			st = mdlScanCriteria_scan(pScanCrit, NULL, NULL, NULL);
			st = mdlScanCriteria_free(pScanCrit);
		}
	}

	writeLogOut(__FUNCTION__, 0);


}

/////////////////////////////////////////////////////////////////////////
int intersectElements(MSElementDescr* edpLine, MSElementDescr* edpShape, DVec3d* pIntP, ReinBar* contP)
{

	writeLogIn(__FUNCTION__, 0);

	RotMatrix rot; 
	//mdlRMatrix_getIdentity(&rot); // intersections in XY plane 
	mdlRMatrix_fromXVector(&rot, &arDataBars[0].v_enrm);

	double tol = 0.1; 

	int ptsCount = 0; // number of intersections 


	if (contP && contP->bartype == ARC_ELM)
	{
		DVec3d pps;
		DPoint3d tng;
		DPoint3d prp;

		// проецируем предыдущую точку

		//if (mdlElmdscr_distanceAtPoint(0, 0, &tng, edpLine, &pts_Line[0], tol) == SUCCESS)
		if (mdlProject_perpendicular(&pps, &tng, &prp, edpLine, 0, &contP->rpts[contP->numpts-1],&rot, tol) == SUCCESS)
		{
			*pIntP = pps;
			ptsCount = 1;
		}
	}
	else
	{

		DVec3d pts_Line[5];
		DVec3d pts_Shape[5]; 

		ptsCount = mdlIntersect_allBetweenElms
		(
			pts_Line, // intersection points on the A element  
			pts_Shape, // intersection points on the B element  
			5,    // number of DPoint3d's that each array can hold. 
			edpLine,  // element descriptor for the A element 
			edpShape,  // element descriptor for the B element 
			&rot,   // coordinate system in which the intersections are calculated.  
			tol  // the maximum allowable error 
		);

		*pIntP = pts_Line[0];

	}




	writeLogOut(__FUNCTION__, 0);

	return ptsCount;

}

/*
/////////////////////////
int reinSweepBarByPath2(
ReinBar* rbP,
MSElementDescr** barPP,  //  => траектория
MSElementDescr  *elemDscrP  //  => траектория
)
{
	//MSBsplineCurve       curve;
	DVec3d pOrg, pTng;
	int ret;
	double rad;
	RotMatrix rm;
	//RotMatrix rmref;
	MSElementDescr* edpShape;
	Transform tm;
	DVec3d pTriad[3];

	writeLogIn(__FUNCTION__, 0);

	rad = mdlCnv_masterUnitsToUors(rbP->diam / 2);

	mdlElmdscr_pointAtDistance(&pOrg, &pTng, 0., elemDscrP, 0);

	mdlVec_getNormalizedTriad(&pTng, &pTriad[0], &pTriad[1], &pTriad[2]);

	mdlRMatrix_fromColumnVectors(&rm, &pTriad[0], &pTriad[1], &pTriad[2]);

	mdlTMatrix_fromRMatrix(&tm, &rm);

	mdlTMatrix_setTranslation(&tm, &pOrg);

	mdlEllipse_create(&elShape, 0, &pZero, rad, rad, 0, 0);

	mdlElement_transform(&elShape, 0, &tm);

	mdlElmdscr_new(&edpShape, 0, &elShape);

#if defined (MSVERSION) && (MSVERSION == 0xa00)

	BODY_TAG  kb_shape = NULL;
	BODY_TAG  kb_path = NULL;
	Transform tmOut;

	mdlSolid_beginCurrTrans (MASTERFILE);
	//=====================================================

	ret = mdlSolid_elementToBody(&kb_shape, &tmOut, edpShape, MASTERFILE);
	//if (ret > 0) printf("mdlSolid_elementToBody returns %i\n", ret);

	ret = mdlSolid_elementToBody(&kb_path, &tmOut, elemDscrP, MASTERFILE);
	//if (ret > 0) printf("mdlSolid_elementToBody returns %i\n", ret);

	ret = mdlSolid_sweepBodyWire(&kb_shape, kb_path, NULL, 0, true, MASTERFILE);
	//if (ret > 0) printf("mdlSolid_sweepBodyWire returns %i\n", ret);

	ret = mdlSolid_bodyToElement (barPP, kb_shape, true, 1, 4, SMART_ISO_Auto, NULL, MASTERFILE);

	if (ret == SUCCESS)
	{
		if (kb_shape != NULL) mdlSolid_freeBody (kb_shape);
		if (kb_path != NULL) mdlSolid_freeBody (kb_path);
	}

	//=====================================================
	mdlSolid_endCurrTrans ();
#else
	KIBODY  *kb_shape  = NULL;
	KIBODY  *kb_path  = NULL;

	mdlKISolid_beginCurrTrans (MASTERFILE);

	//=====================================================

	ret = mdlKISolid_elementToBody(&kb_shape, edpShape, MASTERFILE);
	//if (ret > 0) printf("mdlKISolid_elementToBody returns %i\n", ret);

	ret = mdlKISolid_elementToBody(&kb_path, elemDscrP, MASTERFILE);
	//if (ret > 0) printf("mdlKISolid_elementToBody returns %i\n", ret);

	ret = mdlKISolid_sweepBodyWire(&kb_shape, kb_path, NULL, 0, TRUE, MASTERFILE);
	//if (ret > 0) printf("mdlKISolid_sweepBodyWire returns %i\n", ret);



	ret = mdlKISolid_bodyToElement (barPP, kb_shape, 1, 4, NULL, MASTERFILE);

	if (ret == SUCCESS)
	{
		if (kb_shape != NULL) mdlKISolid_freeBody (kb_shape);
		if (kb_path != NULL) mdlKISolid_freeBody (kb_path);
	}

	//=====================================================
	mdlKISolid_endCurrTrans ();

#endif

	writeLogOut(__FUNCTION__, 0);

	return ret;
}
*/

////////////////////////////////
int iterElmdSavePlot(
    MSElement       *element,     //=> element to act upon
    ReinElm*            relmP,      //=> passed from original call
    int             operation,    //=> why you were called
    UInt32          offset,       //=> offset from header
    MSElementDescr  *elemDscrP    //=> element descr
)
{

	UInt32 fpos = mdlElmdscr_getFilePos(elemDscrP);

	if (mdlElement_isEffectivelyVisible(&elemDscrP->el, elemDscrP->h.dgnModelRef, tcb->lstvw) == FALSE) return 0;

	scanPlotProcessElmd(fpos, elemDscrP->h.dgnModelRef, relmP, tcb->lstvw, FALSE);

	return 0;
}


////////////////////////////////////
int scanPlotFile(
MSElementDescrCP  edP,
ReinModel*        rmP,
ScanCriteria    *pScanCriteria
)
{
	int ret = SUCCESS;

	UInt32 iBlock = 0;
	int iDrawMode = 0;
	int iSec = 0;
	ReinInfoRef* rirP = NULL;

	if (rmP == NULL) return SUCCESS;

	writeLogIn(__FUNCTION__, 0);


	ReinModel* rmCurP = rmP->getRM(edP->h.dgnModelRef);
	UInt32 rn = rmP->rnum; // parent if nested
	UInt32 rnCur = getRefNum(edP->h.dgnModelRef); // ref num of current elem
	UInt32 fpos = mdlElmdscr_getFilePos(edP);

	if (rmCurP == NULL) return SUCCESS;

	// если вложенный референс, то берем настройки из родительского - rmP
	rirP = rmP->getRefPrefs();

	//printf("%u  %u\n", rn, fpos);

	//if (rn == 1 && fpos == 4008365)
	//	__asm nop;


	//if (fpos == 4041806)
	//		__asm nop;


	ReinElm* relmP = rmCurP->getReinElm(fpos);

	// process only REIN_ELEM_ISO (reincache fix 08/2022)
	if (relmP == NULL) return 0;

	//if (relmP->bel.elemid == 7290467)
	//		__asm nop;

	iBlock = checkDrawElem(edP, true, NULL, (DrawPurpose)0, rmCurP, &iDrawMode, &relmP, mdlView_getViewport(tcb->lstvw), rirP);

	for (int i = 0; relmP && i < relmP->bel.numsgts; i++)
	{
		if (relmP->bel.sgts[i].bSec) iSec = 1;
	}


	int res = ERROR;
	lvlSaveID = 0;

	if (rn > 0)
	{
		WCH txt[500];
		UInt32 lvlID = 0;
		WCH lvlName[512];
		MSWCH wlvlName[512];

		mdlElmdscr_getProperties(&lvlID, 0, 0, 0, 0, 0, 0, 0, edP);

        mdlLevel_getName (wlvlName, 512, edP->h.dgnModelRef, lvlID);

		SCPW2M(lvlName, wlvlName, 512);

		SPRN(txt, L("[%u] %s"), rn, lvlName);

		SCPM2W(wlvlName, txt, 512);

		res = mdlLevel_getIdFromName(&lvlSaveID, mrPlot, LEVEL_NULL_ID, wlvlName);

		if (res != SUCCESS)
		{
			res = mdlLevel_create(&lvlSaveID, mrPlot, wlvlName, LEVEL_NULL_CODE);

			if (res == SUCCESS)
			{
				mdlLevel_copyLevelData(mrPlot, lvlSaveID, edP->h.dgnModelRef, lvlID);

				mdlLevelTable_rewrite(mrPlot);
			}
			else 
				lvlSaveID = 0;
		}

	}



	if (iBlock == BLOCK_NON 
		|| (iBlock == BLOCK_INN && iDrawMode == 1)
		|| (rmP && iBlock == BLOCK_INN && rmP->getRefPrefs()->riropt[17] && iSec == 1)
		)
	{

		if (relmP)
		{
			if (mdlElement_isEffectivelyVisible(&edP->el, edP->h.dgnModelRef, tcb->lstvw))
			{
				ret = scanPlotProcessElmd(fpos, edP->h.dgnModelRef, relmP, tcb->lstvw, TRUE);
			}
		}
		//else
		//{
		//	mdlElmdscr_operation(edP, iterElmdSavePlot, relmP, ELMD_ELEMENT); // mdlElement_isEffectivelyVisible inside
		//}


	}

	writeLogOut(__FUNCTION__, 0);

	return ret;
}



/////////////////////////////////////////
int savePlotFile(ReinModel* rmP)
{
	writeLogIn(__FUNCTION__, 0);

	WCH srcfname[300];
	WCH fname[300];
	WCH dev[MAXDEVICELENGTH];
	WCH dir[MAXDIRLENGTH];
	WCH nam[MAXNAMELENGTH];
	WCH ext[MAXEXTENSIONLENGTH];
	int status = ERROR;
	//int iCacheMode = 1;

	//WCH v[500];
	//if (getCfgVarEx(v, L"REIN_VIEW_CACHE_MODE") == SUCCESS)
	//	iCacheMode = STOI(v);
	//else
	//	iCacheMode = 0;

	mrPlot = ACTIVEMODEL;

	/*
	{
		//open...
		mdlModelRef_getFileName(ACTIVEMODEL, srcfname, 300);
		SCPY(fname, srcfname);

		mdlFile_parseName(fname, dev, dir, nam, ext);

		SPRN(fname, L("%s:%s"), dev, dir);

		SCAT(fname, L("reinplot\\"));

		if (mdlFile_mkdir(fname) != SUCCESS)
		{
			mdlDialog_dmsgsPrint(L("cannot create directory REINPLOT"));
			return ERROR;
		}

		SCAT(fname, nam);
		SCAT(fname, L("."));
		SCAT(fname, ext);

		//if (bWithRefs)
		//status = mdlWorkDgn_createFile(&mrPlot, fname, DGNFILE_FORMAT_V8, ACTIVEMODEL, SEED_CopyAllData, 0, 0, TRUE);
		//else
		//status = mdlWorkDgn_createFile(&mrPlot, fname, DGNFILE_FORMAT_V8, ACTIVEMODEL, SEED_CopyAllData & ~(SEED_CopyReferenceAttach), 0, 0, TRUE);
			

		mdlDialog_dmsgsPrint(fname);

		if (status != SUCCESS || mrPlot == NULL) 
		{
			mdlDialog_dmsgsPrint(L("reinplot does no work in this version"));
			return ERROR;
		}

		mdlModelRef_loadReferenceModels(mrPlot, TRUE, FALSE, FALSE);
	}
	*/



	//mdlDialog_dmsgsPrint(L("das Programm arbeitet... warten Sie bitte :)"));

	//scan elems
	//=================================



	ScanCriteria    *scP = NULL;



	//UShort          typeMask[6];
	//for (UShort a = 0; a < 6; a++) typeMask[a] = 0;
	//typeMask[2] = TMSK2_SHAREDCELL_DEF;

	//if (iCacheMode == 0)
	//{
	//	//scP = mdlScanCriteria_create();
	//	//status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	//	//status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanPlotSchCells, NULL);
	//	//status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
	//	//status = mdlScanCriteria_setModel (scP, ACTIVEMODEL);
	//	//status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
	//	//status = mdlScanCriteria_free (scP);
	//}
	
	


	// элементы кэша
	if (getReinCacheCount(&curPos_refpath) > 0)
	{
		ReinPrm prm;
		prm.ival[0] = -1; // delete cache
		prm.wstr = curPos_refpath;

		scP= mdlScanCriteria_create ();
		status = mdlScanCriteria_setReturnType (scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
		status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanReinCache, &prm);
		status = mdlScanCriteria_setDrawnElements(scP);
		status = mdlScanCriteria_setModel (scP, ACTIVEMODEL);
		status = mdlScanCriteria_scan (scP, NULL,NULL,NULL);
		status = mdlScanCriteria_free (scP);

		dialogPosList_checkButton(NULL);

		return SUCCESS;
	}

	// только если какие-то REIN элементы нарисованы в чертеже?
	//scP = mdlScanCriteria_create();
	//status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	//status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanPlotFile, NULL);
	//status = mdlScanCriteria_setDrawnElements(scP);
	//status = mdlScanCriteria_setModel (scP, ACTIVEMODEL);
	//status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
	//status = mdlScanCriteria_free (scP);


	// референсы
	{
		//ModelRefIteratorP  iterator;
		//DgnModelRefP	modelRef;

		//mdlModelRefIterator_create (&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, 1); // nested depth unlimited???

		//while (NULL != (modelRef = mdlModelRefIterator_getNext (iterator)))
		{

			BINT isOn = FALSE;
			mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, rmP->modelP);
			if (isOn == FALSE) return ERROR;

			UInt32 elCnt = rmP->getElemCount(-1);
			//getReinElmCount(TRUE, rmP->modelP, &elCnt);

			//if (elCnt > 0 || bWithRefs == FALSE)
			//if (elCnt > 0)
			if (rmP->mapElms.size() > 0)
			{
				scP = mdlScanCriteria_create();
				status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
				status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanPlotFile, rmP);
				status = mdlScanCriteria_setDrawnElements(scP);
				status = mdlScanCriteria_setModel (scP, rmP->modelP);
				status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
				status = mdlScanCriteria_free (scP);

				for (map<UInt32, ReinModel>::iterator it = rmP->arMrP.begin(); it != rmP->arMrP.end(); ++it)
				{
					mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, it->second.modelP);
					if (isOn == FALSE) continue;

					if (it->second.elcount > 0)
					{
						scP = mdlScanCriteria_create();
						status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
						status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanPlotFile, rmP);
						status = mdlScanCriteria_setDrawnElements(scP);
						status = mdlScanCriteria_setModel(scP, it->second.modelP);
						status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
						status = mdlScanCriteria_free(scP);
					}
				}

				isOn = FALSE;
				status = func_pma(mdlRefFile_setBooleanParameters,isOn), REFERENCE_DISPLAYFLAG, rmP->modelP); //(не фурычит если &isOn)
				mdlRefFile_writeAttachmentExtended(rmP->modelP, TRUE, TRUE, TRUE);


				// убираем референс
				//{
				//	ModelRefIteratorP  iterator2;
				//	DgnModelRefP	modelRef2;
				//	mdlModelRefIterator_create (&iterator2, mrPlot, MRITERATE_PrimaryChildRefs, 0); // nested depth unlimited
				//	while (NULL != (modelRef2 = mdlModelRefIterator_getNext (iterator2)))
				//	{
				//		if (getRefNum(modelRef2) == getRefNum(modelRef))
				//		{
				//			isOn = FALSE;
				//			status = mdlRefFile_setParameters ((void*)isOn, REFERENCE_DISPLAYFLAG, modelRef2); //(не фурычит если &isOn)
				//			mdlRefFile_writeAttachmentExtended(modelRef2, TRUE, TRUE, TRUE);
				//			//mdlRefFile_detach(modelRef2);
				//			break;
				//		}
				//	}
				//	mdlModelRefIterator_free (&iterator2);
				//}

			}
		}

		//mdlModelRefIterator_free (&iterator);

	}

	dialogPosList_checkButton(NULL);


	//=================================


	//if (mrPlot && iCacheMode == 0)
	//{
	//	//DgnModelRefP mrRef = NULL;
	//	//int st = mdlRefFile_beginAttachmentToModel (&mrRef, srcfname, NULL, L"исходный чертеж", NULL, mrPlot);
	//	//if (st == SUCCESS)
	//	//{
	//	//	int isOn = FALSE;
	//	//	mdlRefFile_setParameters ((void*)isOn, REFERENCE_DISPLAY, mrRef); // фурычит!
	//	//	mdlRefFile_completeAttachment(mrRef, REFATTACH_NEST_NONE, 0, FALSE);
	//	//} // убрано потому что реф.файл при нест левел=1 не отобр. скрытые стержни

	//	mdlWorkDgn_saveChanges(mrPlot);
	//	mdlWorkDgn_closeFile(mrPlot);
	//}

	//sprintf(s, "Файл %s создан", fname);
	//mdlDialog_openMessageBox (DIALOGID_MsgBoxOK, s, MSGBOX_ICON_INFORMATION);

	//mdlDialog_dmsgsPrint(L("fertig"));

	writeLogOut(__FUNCTION__, 0);



	return SUCCESS;
}


///////////////////////////////////
// func: check element way to draw
UInt32 checkDrawElem(MSElementDescrCP edp, 
					 bool bPlot, 
					 MSElementDescrH* newEdPPP,
					 DrawPurpose drawPurpose,
					 ReinModel* rmP,
					 int* bDrawModeP,
					 ReinElm** relmPP,
					 ViewportP vpP,
					 ReinInfoRef* rirP
					 )
{
	//ReinSpace rs;
	//ReinBar rb;

	int bDrawMode = 0;
	UInt32 iBlock = 0;

	ReinElm* relmP = *relmPP;

	MSElementDescrH newEdPP = NULL;

	if (newEdPPP) newEdPP = *newEdPPP;

	if (rirP == NULL) return iBlock;

	//ReinInfoRef* rirP = rmP->getRefPrefs();

	writeLogIn(__FUNCTION__, 0);

	if (readReinSpaceFromElmd(&urelem, edp, FALSE) == SUCCESS) // отображать ReinSpace
	{
		if (newEdPPP)
		{
			Int32 st = 3;
			UInt32 wt = 0;
			UInt32 cl = (UInt32)urelem.rs.diam;
			UInt32* clP = NULL;

			if (rirP->riropt[19]) clP = &cl;

			mdlElmdscr_duplicate(newEdPP, edp); //todo update symb onfly reinspace 
			func_ast(mdlElmdscr_setSymbology,newEdPP), clP, &st, &wt, 0); // пунктиром
		}

		// REIN_PLOT_SPC
		if (bPlot && arPlotCfgVar[REIN_PLOT_SPC] != 0)
		{
			if (arPlotCfgVar[REIN_PLOT_SPC] == -1) iBlock = BLOCK_CMN;
		}
		else
		{
			if (!rirP->riropt[2]) iBlock = BLOCK_CMN;
		}
			
	}

	if (readReinBarFromElement(&urelem, edp, FALSE) == SUCCESS) // отображать ReinBar
	{
		if (newEdPPP)
		{
			Int32 st = 0;
			UInt32 wt = 0;
			UInt32 cl = (UInt32)urelem.rb.diam;
			UInt32* clP = NULL;

			if (urelem.rb.bartype == BT_AXIS)
				st = 2;
			else 
				st = 4;

			if (rirP->riropt[19]) clP = &cl;

			mdlElmdscr_duplicate(newEdPP, edp); //todo update symb onfly reinbar
			func_ast(mdlElmdscr_setSymbology,newEdPP), clP, &st, &wt, 0); // пунктиром
		}

		// REIN_PLOT_BAR
		if (bPlot && arPlotCfgVar[REIN_PLOT_BAR] != 0)
		{
			if (arPlotCfgVar[REIN_PLOT_BAR] == -1) iBlock = BLOCK_CMN;
		}
		else
		{
			if (!rirP->riropt[4]) iBlock = BLOCK_CMN;
		}

	}


	//ReinElm crelm;
	deque <UInt32> aref;
	if (rmP) rmP->getRefPath(&aref);

	if (crelm.getElmFromElement(&edp->el, 0) == SUCCESS && rmP)
	{
		double transp = 0.0;
		double* transpP = NULL;
		Int32 st = 1;
		Int32* stP = NULL;
		UInt32 cl = (UInt32)crelm.bel.diam;
		UInt32* clP = NULL;
		UInt32 wght = iCfgVar_SymbWeight_Elm; // толщина производных элементов
		UInt32* wghtP = &wght; // толщина производных элементов

		//UInt32 aref[MAX_REFNUM_PATH];
		//UInt32 rn = getRefNum(edp->h.dgnModelRef);
		UInt32 fp = mdlElmdscr_getFilePos(edp);

		if (relmP == NULL)
		{
			relmP = &crelm;
			*relmPP = &crelm;
		}

		
		if (relmP->fpDup > 0)
		{
			wght = 9;
		}
		else if (relmP->elemflags & REINEL_FLAG_FKOS)
		{
			wght = 5; stP = &st;
		}
		else if (relmP->bel.grnd)
		{
			wght = iCfgVar_Ground_Wgt; // заземление (в настройки)
			cl = iCfgVar_Ground_Clr;
			clP = &cl;
		}
		else if (relmP->elemflags & REINEL_FLAG_NMCH) 
		{ 
			wght = 15; 
			cl = 3; 
			clP = &cl; 
		}
		else if (iCfgVar_SymbWeight_Elm < 0)
		{
			wghtP = NULL;
		}

		//Element ID : 4585806
		//Element ID : 4586430

		//86 drawmode = 2, inum = 17, ref = [12], elemid = 6402223, bFromRef = 0
		//87 drawmode = 2, inum = 17, ref = [12], elemid = 6407014, bFromRef = 0
		//88 drawmode = 2, inum = 18, ref = [12], elemid = 6405886, bFromRef = 0

		//if (rirP->riropt[19]) // временно цвет как опция для сравнения и поиска глюков
		{
			for (map <wstring, ReinPos>::iterator rpItP = curRM->mapBarSet.begin(); relmP && rpItP != curRM->mapBarSet.end(); ++rpItP)
			{
				//ReinPos* rpItP = &daCurBarSet[i];
				//if (rpItP <= 0) continue;

				if (relmP->bel.inum == 17 && relmP->bel.elemid== 6402223 && aref.front() ==12)
					int a = 0;

				if (rpItP->second.bar.inum == relmP->bel.inum && 
					rpItP->second.bar.elemid == relmP->bel.elemid &&
					refPathsEQ(rpItP->second.arefnum, aref) && rpItP->second.bFromRef) // bs from ref
				{
					if (bDrawModeP) *bDrawModeP = rpItP->second.drawmode;
					bDrawMode = rpItP->second.drawmode;
				}

				if (rpItP->second.bar.inum == relmP->bel.inum &&
					rpItP->second.bar.elemid == relmP->bel.elemid &&
					refPathsEQ(rpItP->second.arefnum, aref) && !rpItP->second.bFromRef) // bs not from ref
				{
					if (bDrawModeP) *bDrawModeP = rpItP->second.drawmode;
					bDrawMode = rpItP->second.drawmode;
					break;
				}
			}
		}
		/*
		else
		{
			if (relmP->drwopt[0] > 0)
			{
				int drpt = relmP->drwopt[0] - BARSET_GAP;
				if (bDrawModeP) *bDrawModeP = drpt;
				bDrawMode = drpt;
			}
		}*/




		if (rirP->riropt[19]) clP = &cl;



		if (bDrawMode == 1  // всегда показывать
			&& newEdPPP
			&& drawPurpose != DRAW_PURPOSE_Pick  // иначе не работает привязка на ReinElem
			)
		{
			//mdlElmdscr_duplicate(newEdPP, edp);
			//mdlElement_setTransparency(&((*newEdPP)->el), 0.0);
			transpP = &transp;

			//MSElementDescr* pComponent = (*newEdPP)->h.firstElem;
			//while (pComponent)
			//{
			//	mdlElement_setTransparency(&(pComponent->el), 0.0);
			//	pComponent = pComponent->h.next;
			//}
		}
		else
		{

			if (bDrawMode == 2 // не показывать
				//&& drawPurpose != DRAW_PURPOSE_Pick // иначе не работает привязка на ReinElem (?) - коммент. см. ниже
				// если разкомент. то при указании на два наложенных элемента если один из них невидим, то он мешается и не дает пикнуть на второй
				)
			{
				if (newEdPPP)
				{
					//Int32 st = 1;
					//mdlElmdscr_duplicate(newEdPP, edp);
					//mdlElmdscr_setSymbology(*newEdPP, 0, &st, 0, 0); // пунктиром
					stP = &st;

					if (rirP->riropt[18] == FALSE) iBlock = BLOCK_CMN; 
					if (bPlot && arPlotCfgVar[REIN_PLOT_BAR_INVIS] == -1) iBlock = BLOCK_CMN; 
				}
				else
					iBlock = BLOCK_CMN;
			}

			// REIN_PLOT_SPC_ELM
			if (relmP->bel.inum == 0) // from ReinBar
			{
				if (bPlot && arPlotCfgVar[REIN_PLOT_BAR_ELM] != 0)
				{
					if (arPlotCfgVar[REIN_PLOT_BAR_ELM] == -1) iBlock = BLOCK_CMN;
				}
				else
				{
					if (!rirP->riropt[5]) iBlock = BLOCK_CMN;
				}
			}
			else // from ReinSpace
			{

				if (bPlot && arPlotCfgVar[REIN_PLOT_SPC_ELM] != 0)
				{
					if (arPlotCfgVar[REIN_PLOT_SPC_ELM] == -1) iBlock = BLOCK_CMN;
				}
				else
				{
					if (!rirP->riropt[5]) iBlock = BLOCK_CMN;
				}

			}

			// REIN_PLOT_SPC_INNER
			if (iBlock == BLOCK_NON
				&& !(bDrawMode == 1 && drawPurpose == DRAW_PURPOSE_Pick)
				)
			{
				if (relmP->bel.transp == REIN_TRANSP_INN)
				{
					DVec3d ptn[2];
					bool bMustShow = false;

					//if (rn==2 && fp==4004821)
					//	int a = 0;

					//if (rn==2 && fp==4004216)
					//	int a = 0;

					if (rirP->riropt[17] && relmP) // отображение стержней, которые должны быть видны на сечениях
					{
						RotMatrixCP rmViewP = vpP->GetRotMatrix();
						mdlVec_fromRotMatrixRow (&ptn[0], rmViewP, 2);

						if (relmP->bel.noplanar == 0)
						{
							if (mdlVec_areParallel(&ptn[0], &relmP->bel.v_enrm)) bMustShow = true;
						}

						if (!bMustShow)
						{
							//ELREF eref = getElemRefByID(relmP->bel.modrefP, relmP->bel.elemid);

							//if (eref)
							//{
							//	MSElementDescr* edpPrnt = NULL;

							//	mdlElmdscr_readToMaster (&edpPrnt, elementRef_getFilePos(eref), relmP->bel.modrefP, 0, 0);
							//	if (edpPrnt)
							//	{
							//		if (mdlElmdscr_extractNormal(&ptn[1], 0, edpPrnt, &pZ) == SUCCESS)
							//		{
							//			if (mdlVec_arePerpendicular(&ptn[0], &ptn[1])) bMustShow = true;
							//		}

							//		mdlElmdscr_freeAll(&edpPrnt);
							//	}
							//}

							// заменено на одну строчку
							
							if (!mdlVec_equal(&relmP->bel.v_pnrm, &pZero)
								&& mdlVec_arePerpendicular(&ptn[0], &relmP->bel.v_pnrm)) bMustShow = true;
						}
					}

					if (!bMustShow)
					{
						if (bPlot && arPlotCfgVar[REIN_PLOT_SPC_INNER] != 0)
						{
							if (arPlotCfgVar[REIN_PLOT_SPC_INNER] == -1) iBlock = iBlock | BLOCK_INN;
						}
						else
						{
							if (!rirP->riropt[1]) iBlock = iBlock | BLOCK_INN;
						}
					}
				}
			}
		}


		if (rirP->riropt[3])
		{
			if (!relmP->bel.grnd)
			{
				if (rirP->riropt[6] == -1)
					iBlock = iBlock | BLOCK_GND;
				else
				{
					st = rirP->riropt[6];
					stP = &st;
				}
			}
		}


		if (newEdPP 
			&& drawPurpose != DRAW_PURPOSE_Pick
			//&& (transpP || stP || clP)
			)
		{
			mdlElmdscr_duplicate(newEdPP, edp);

			//if (relmP->bel.grnd) transpP = NULL;

			if (transpP) mdlElement_setTransparency(&((*newEdPP)->el), transp);
			func_ast(mdlElmdscr_setSymbology,newEdPP), clP, stP, wghtP, 0);

			MSElementDescr* pComponent = (*newEdPP)->h.firstElem;
			while (pComponent && transpP)
			{
				mdlElement_setTransparency(&(pComponent->el), transp);
				pComponent = pComponent->h.next;
			}
		}

	}


	if (relmP)
	{
		//relmP->drwopt[0] = FALSE;
		relmP->drwopt[1] = FALSE;
		relmP->drwopt[2] = FALSE;
		relmP->drwopt[3] = FALSE;
		relmP->drwopt[4] = FALSE;
	}

	for (vector<ReinPos>::iterator rpItP = daCurPosHide.begin(); relmP && rpItP != daCurPosHide.end(); ++rpItP)
	{

		if (rpItP->bar.pnum == relmP->bel.pnum 
			//&& !rpItP->arefnum.empty()
			//&& (rpItP->arefnum.back() == rmP->rnum)
			&& refPathsEQ(rpItP->arefnum, aref)
			//&& (rpItP->arefnum[0] == rmP->rnum)
			)
		{
			if (rpItP->drawopt[DROPT_A] == TRUE)	iBlock = iBlock | BLOCK_BAR;

			relmP->drwopt[DROPT_V] = rpItP->drawopt[DROPT_V];
			relmP->drwopt[DROPT_X] = rpItP->drawopt[DROPT_X];
			relmP->drwopt[DROPT_O] = rpItP->drawopt[DROPT_O];
			relmP->drwopt[DROPT_S] = rpItP->drawopt[DROPT_S];


			break;
		}
	}



	writeLogOut(__FUNCTION__, 0);

	return iBlock;
}



////////////////////////////////////
int scanPlotProcessElmd(UInt32 fpos, DgnModelRefP mrP, ReinElm* relmP, int view, int iBar)
{
	int ret = SUCCESS;

	Transform tm;
	Transform tmr;
	Transform* tmP = NULL;
	Transform* tmRevP = NULL;
	mrRefPlotFromP = mrP;

	writeLogIn(__FUNCTION__, 0);


	int bMustFree = FALSE;

	int iClip = 0;
	CLIPDESC clipP = NULL;

	MSElementDescr* edElmP = NULL;

	MSElementDescr* edCellP = NULL;
	MSElementDescr* edCell2dP = NULL;

	//MSElementDescr* edBar3dP = NULL;
	//MSElementDescr* edBar3dClipP = NULL;

	ReinInfoRef* rirP = NULL;


	ReinModel* rmP = curRM->getRM(mrP);


	if (rmP) rirP = rmP->getRefPrefs(); else rirP = &rInfoRef;

	/* moved below
	if (relmP)
	{
		MSWCH ws[10];
		SPRN(s, L("pos.%i"), relmP->bel.pnum);
		SCPM2W(ws, s, 10);
		mdlCell_create(&eCell, ws, NULL, FALSE);
		mdlElmdscr_new(&edCellP, NULL, &eCell);

		if (!mdlModelRef_is3D(mrPlot))
		{
			int res = mdlElmdscr_convertTo2D(&edCell2dP, edCellP, -1, 0, mrPlot, mrPlot, 0);
			if (res == SUCCESS)
			{
				mdlElmdscr_freeAll(&edCellP);
				edCellP = edCell2dP;
			}
		}
	}*/

	int r = SUCCESS;
	MSElementDescr* edpClip = NULL;

	if (mdlModelRef_isActiveModel(mrP) == FALSE)
	{
		//r = func_pma(mdlClip_getRefBoundary,clipP), mrP, view);
		r = myClip_getRefBoundary(&clipP, mrP, &edpClip, view);

		if (ISNULL(clipP)) r = ERROR;
		double* dScaleP = NULL;
		double dScale = 1.;

		mdlTMatrix_referenceToMaster(&tm, mrP); // scale!
		tmP = &tm;
		mdlTMatrix_masterToReference(&tmr, mrP); // scale!
		tmRevP = &tmr;

		RotMatrix rm;
		mdlRMatrix_fromTMatrix(&rm, &tmr);

		// return TRUE if the matrix is constructed of rotation and uniform scale. FALSE if non-uniform scale.
		if (mdlRMatrix_isXRotationYRotationZRotationScale(&rm, 0, 0, 0, &dScale) == FALSE)
		{
			mdlRefFile_getDoubleParameters(&dScale, REFERENCE_SCALE, mrP);
			dScale = 1. / dScale;
		}

		if (!EQ(dScale, 1.))
		{
			dScaleP = &dScale;
		}

	}
	else
	{
		mdlTMatrix_getIdentity(&tm);
		mdlTMatrix_getIdentity(&tmr);
	}



	if (relmP)
	{
		WCH txt[50];
		MSWCH ws[50];
		SPRN(txt, L("pos.%i"), relmP->bel.pnum);
		SCPM2W(ws, txt, 50);
		mdlCell_create(&eCell, ws, NULL, FALSE);
		mdlElmdscr_new (&edCellP, NULL, &eCell);
	}


	//mdlElmdscr_read(&edElmP, fpos, mrP, 0, 0);
	mdlElmdscr_readToMaster(&edElmP, fpos, mrP, 0, 0);

	mdlElmdscr_setVisible(edElmP, TRUE); // for hidden elems

	bMustFree = TRUE;


	if (r == SUCCESS || mdlModelRef_isActiveModel(mrP) == FALSE)
	{
		MSElementDescr* edpClip1 = NULL;

		if (NOTNULL(clipP))
		{
			mdlClip_element(&edpClip1, NULL, edElmP, mrP, GETPTR(clipP), view);

			if (edpClip1 != NULL)
			{
				//if (bFlag)
				//	{mdlElmdscr_show(edpClip1, "  ");bFlag=FALSE;}

				if (edpClip1 != edElmP)
				{
					mdlElmdscr_freeAll(&edElmP);
					edElmP = edpClip1;
					iClip = 1; // обрезан клипом
				}
				else
					iClip = 0; // полностью внутри
			}
			else
			{
				iClip = -1; // outside
			}



			// ==== 3d bar =====
			/*
			if (iBar && relmP && rirP && edpClip1 && relmP->bel.ffpos[REIN_ELEM_BAR] && rirP->riropt[10])
			{

				MSElementDescr* edBarP = NULL;
				ELID barid = (ELID)relmP->bel.ffpos[REIN_ELEM_BAR];
				ELREF barref = getElemRefByID(mrP, barid);
				if (barref)
				{
					UInt32 fp = elementRef_getFilePos(barref);

					scanPlotProcessElmd(fp, mrP, relmP, tcb->lstvw, FALSE);
				}
			}
			*/

			myClip_free(clipP, &edpClip);
		}
	}




	if  (iClip == -1)
	{
		mdlElmdscr_freeAll(&edElmP);
		writeLogOut(__FUNCTION__, "iClip == -1");
		return 0;
	}


	if (iClip == 1)
	{
		MSElementDescr*  edpNext = edElmP->h.next;
		while (edpNext != NULL) // обрезка получилась из нескольких частей
		{ 

			MSElementDescr  *edDupP = NULL;

			mdlElmdscr_duplicateSingle(&edDupP, edpNext);

			mdlXMLFragmentList_stripAllFromElement (NULL, &edDupP->el);

			savePlotCreateElem(0, edCellP, 0, 0, edDupP);

			edpNext = edpNext->h.next;
		}
	}

	UInt32 refnum = getRefNum(mrP);

	double dBarFace = dCfgVar_BarFace; // uors ниже
	if (rirP && rirP->bface > 0) dBarFace = rirP->bface;
	if (rmP && rmP->modelP) mdlCnv_masterToUOR(&dBarFace, dBarFace, rmP->modelP);

	//dBarFace /= rmP->refscale;

	double dBarSign = dBarFace * 2.;  // rmP->refscale; // два раза?
	//double dBarSign = dCfgVar_BarSign / rmP->refscale / rmP->refscale; // два раза
	//if (rmP->arRefPrefs->bface > 0) dBarSign = mdlCnv_masterUnitsToUors(rmP->arRefPrefs->bface) * 5.;


	//int dropt[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	vector<int> dropt(10);

	if (relmP)
	{

		for (vector<ReinPos>::iterator rpItP = daCurPosHide.begin(); rpItP != daCurPosHide.end(); ++rpItP)
		{
			wstring wrefstr = L"";

			if (!rpItP->arefnum.empty()) wrefstr = curRM->getRefPathString(&rpItP->arefnum);

			if (rpItP->bar.pnum == relmP->bel.pnum &&
				(
					(rpItP->arefnum.empty() && curPos_rn == 0) ||
					(!rpItP->arefnum.empty() && wrefstr == curPos_refpath)
					)
				)
			{
				dropt = rpItP->drawopt;
				break;
			}
		}

		if (rirP)
		{
			if (!rirP->ends) dropt[DROPT_V] = 1;
			if (!rirP->riropt[DISP_X]) dropt[DROPT_X] = 1;
			if (!rirP->riropt[DISP_O]) dropt[DROPT_O] = 1;
			if (!rirP->riropt[DISP_S]) dropt[DROPT_S] = 1;
		}

		for (int i = 0; i < relmP->bel.numsgts; i++)
		{
			RotMatrix rm0;
			RotMatrix rm;

			if (tmRevP
				&& !mdlModelRef_is3D(mrPlot) // 2D
				)
			{
				mdlRMatrix_fromTMatrix(&rm0, tmRevP);
				mdlRMatrix_normalize(&rm, &rm0); // убираем масштаб, нужен только поворот
				//mdlRMatrix_invert(&rm, &rm0);
			}
			else if (tmP)
			{
				mdlRMatrix_fromTMatrix(&rm0, tmP);
				mdlRMatrix_normalize(&rm0, &rm0);
				mdlRMatrix_invert(&rm, &rm0);
			}
			else
				rm = rmIdent;

			// ======== сечения ====================
			if (relmP->bel.sgts[i].bSec && !dropt[DROPT_S])
			{
				DVec3d p = relmP->bel.sgts[i].pSec;

				if (!mdlModelRef_is3D(mrPlot)) // reincache draw FIX 08/2022
					mdlTMatrix_transformPoint(&p, tmP);

				//mdlEllipse_create(&elTmp, &c0w1s0, &p, dBarFace* rmP->refscale, dBarFace* rmP->refscale, &rm, 1);
				mdlEllipse_create(&elTmp, &c0w1s0, &p, dBarFace, dBarFace, &rm, 1); //  FIX 10/2022

				savePlotCreateElem(0, edCellP, tmP);
			}
			//======================================

			// ======== объем ====================
			//if (edBar3dP && rirP->riropt[10])
			//{
			//	savePlotCreateElem(0, 0, 0, edBar3dP);
			//}
			//======================================

			DVec3d ppp[5];


			if (relmP->bel.sgts[i].rv[0].mblap == REIN_TERM_TRMI)
			{
				RotMatrix rmX;
				DVec3d pdir = relmP->bel.sgts[i].rv[0].rvv.tdir;
				mdlRMatrix_multiplyPoint(&pdir, &rm0);
				double dan = mdlVec_angleXY(&pdir);
				mdlRMatrix_fromAngle(&rmX, dan);

				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);

				ppp[0].x = 0.;
				ppp[1].x = dBarSign / 10.;
				ppp[2].x = 0.;
				ppp[3].x = 0.;
				ppp[4].x = dBarSign / 10.;

				ppp[0].y = dBarSign / 2.;
				ppp[1].y = dBarSign / 4.;
				ppp[2].y = 0.;
				ppp[3].y = -dBarSign / 4.;
				ppp[4].y = -dBarSign / 2.;

				mdlRMatrix_multiplyPointArray(ppp, &rmX, 5);
				mdlRMatrix_multiplyPointArray(ppp, &rm, 5);
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[0].torg, 5);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 5); // reincache draw FIX 08/2022
				mdlLineString_create(&elTmp, &c0w0s0, ppp, 5);

				savePlotCreateElem(0, edCellP, tmP);
			}
			if (relmP->bel.sgts[i].rv[1].mblap == REIN_TERM_TRMI)
			{
				RotMatrix rmX;
				DVec3d pdir = relmP->bel.sgts[i].rv[1].rvv.tdir;
				mdlRMatrix_multiplyPoint(&pdir, &rm0);
				double dan = mdlVec_angleXY(&pdir);
				mdlRMatrix_fromAngle(&rmX, dan);
				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);

				ppp[0].x = 0.;
				ppp[1].x = dBarSign / 10.;
				ppp[2].x = 0.;
				ppp[3].x = 0.;
				ppp[4].x = dBarSign / 10.;

				ppp[0].y = dBarSign / 2.;
				ppp[1].y = dBarSign / 4.;
				ppp[2].y = 0.;
				ppp[3].y = -dBarSign / 4.;
				ppp[4].y = -dBarSign / 2.;

				mdlRMatrix_multiplyPointArray(ppp, &rmX, 5);
				mdlRMatrix_multiplyPointArray(ppp, &rm, 5);
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[1].torg, 5);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 5); // reincache draw FIX 08/2022
				mdlLineString_create(&elTmp, &c0w0s0, ppp, 5);

				savePlotCreateElem(0, edCellP, tmP);
			}


			if (relmP->bel.sgts[i].rv[0].mblap == REIN_TERM_TRMX && !dropt[DROPT_X])
			{
				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);
				ppp[0].x -= dBarFace;
				ppp[0].y -= dBarFace;
				ppp[1].x += dBarFace;
				ppp[1].y += dBarFace;
				mdlRMatrix_multiplyPointArray(ppp, &rm, 2);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 2); // reincache draw FIX 08/2022
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[0].torg, 2);
				savePlotCreateElem(ppp, edCellP, tmP);

				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);
				ppp[0].x -= dBarFace;
				ppp[0].y += dBarFace;
				ppp[1].x += dBarFace;
				ppp[1].y -= dBarFace;
				mdlRMatrix_multiplyPointArray(ppp, &rm, 2);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 2); // reincache draw FIX 08/2022
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[0].torg, 2);
				savePlotCreateElem(ppp, edCellP, tmP);
			}

			if (relmP->bel.sgts[i].rv[1].mblap == REIN_TERM_TRMX && !dropt[DROPT_X])
			{
				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);
				ppp[0].x -= dBarFace;
				ppp[0].y -= dBarFace;
				ppp[1].x += dBarFace;
				ppp[1].y += dBarFace;
				mdlRMatrix_multiplyPointArray(ppp, &rm, 2);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 2); // reincache draw FIX 08/2022
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[1].torg, 2);
				savePlotCreateElem(ppp, edCellP, tmP);

				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);
				ppp[0].x -= dBarFace;
				ppp[0].y += dBarFace;
				ppp[1].x += dBarFace;
				ppp[1].y -= dBarFace;
				mdlRMatrix_multiplyPointArray(ppp, &rm, 2);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 2); // reincache draw FIX 08/2022
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[1].torg, 2);
				savePlotCreateElem(ppp, edCellP, tmP);
			}

			//relmP->bel.pnum
			if (relmP->bel.sgts[i].rv[0].mblap == REIN_TERM_TRMO && !dropt[DROPT_O])
			{
				DVec3d p = relmP->bel.sgts[i].rv[0].torg;
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPoint(&p, tmP); // reincache draw FIX 08/2022
				mdlEllipse_create(&elTmp, &c0w1s0, &p, dBarFace, dBarFace, &rm, 1);
				savePlotCreateElem(0, edCellP, tmP);
			}

			if (relmP->bel.sgts[i].rv[1].mblap == REIN_TERM_TRMO && !dropt[DROPT_O])
			{
				DVec3d p = relmP->bel.sgts[i].rv[1].torg;
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPoint(&p, tmP); // reincache draw FIX 08/2022
				mdlEllipse_create(&elTmp, &c0w1s0, &p, dBarFace, dBarFace, &rm, 1);
				savePlotCreateElem(0, edCellP, tmP);
			}

			if (relmP->bel.sgts[i].rv[0].mblap == REIN_TERM_TRMV && !dropt[DROPT_V])
			{
				RotMatrix rmX;
				DVec3d pdir = relmP->bel.sgts[i].rv[0].rvv.tdir;
				mdlRMatrix_multiplyPoint(&pdir, &rm0);
				double dan = mdlVec_angleXY(&pdir);
				mdlRMatrix_fromAngle(&rmX, dan);
				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);
				ppp[1].x += dBarSign * 2;
				ppp[1].y -= dBarSign;
				mdlRMatrix_multiplyPointArray(ppp, &rmX, 2);
				mdlRMatrix_multiplyPointArray(ppp, &rm, 2);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 2); // reincache draw FIX 08/2022
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[0].torg, 2);
				savePlotCreateElem(ppp, edCellP, tmP);
			}

			if (relmP->bel.sgts[i].rv[1].mblap == REIN_TERM_TRMV && !dropt[DROPT_V])
			{
				RotMatrix rmX;
				DVec3d pdir = relmP->bel.sgts[i].rv[1].rvv.tdir;
				mdlRMatrix_multiplyPoint(&pdir, &rm0);
				double dan = mdlVec_angleXY(&pdir);
				mdlRMatrix_fromAngle(&rmX, dan);
				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);
				ppp[1].x += dBarSign * 2;
				ppp[1].y -= dBarSign;
				mdlRMatrix_multiplyPointArray(ppp, &rmX, 2);
				mdlRMatrix_multiplyPointArray(ppp, &rm, 2);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 2); // reincache draw FIX 08/2022
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[1].torg, 2);
				savePlotCreateElem(ppp, edCellP, tmP);

			}


			if (rirP && relmP->bel.sgts[i].rv[0].mblap == REIN_TERM_BEND && rirP->riropt[8])
			{

				double vecang;
				DVec3d nrm;
				DVec3d vec;
				DVec3d ttdir;
				RotMatrix rmm[2];

				double diam = mdlCnv_masterUnitsToUors(relmP->bel.diam);
				double d = diam * 5 * SGN(relmP->bel.termPar[0][0]); //(R=2.5D) signed
				double dd = mdlCnv_masterUnitsToUors(relmP->bel.termPar[1][0]) - fabs(d); // д.б. 6D
				if (rmP) d /= rmP->refscale;

				RotMatrix rmX;
				DVec3d pdir = relmP->bel.sgts[i].rv[0].rvv.tdir;
				mdlRMatrix_multiplyPoint(&pdir, &rm0);
				double dan = mdlVec_angleXY(&pdir);
				mdlRMatrix_fromAngle(&rmX, dan);

				vecang = mdlVec_angleBetweenVectors(&relmP->bel.sgts[0].rv[0].rvv.tdir, 
													&relmP->bel.sgts[1].rv[0].rvv.tdir);

				mdlVec_crossProduct(&nrm, &relmP->bel.sgts[0].rv[0].rvv.tdir, 
													&relmP->bel.sgts[1].rv[0].rvv.tdir);

				mdlVec_crossProduct(&vec, &nrm, &relmP->bel.sgts[0].rv[0].rvv.tdir);

				ttdir = relmP->bel.sgts[0].rv[0].rvv.tdir;

				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);
				mdlVec_scaleToLength(&ppp[1], &vec, d);

				mdlRMatrix_multiplyPointArray(ppp, &rmX, 4);
				mdlRMatrix_multiplyPointArray(ppp, &rm, 4);
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[0].torg, 4);
				mdlLine_create(&elTmp, &edElmP->el, ppp);
				savePlotCreateElem(0, edCellP, tmP);


				double rtan = (180 - relmP->bel.termPar[0][0]) * fc_piover180;
				mdlRMatrix_fromRowVectors(&rmm[0], &ttdir, &vec, &nrm);
				mdlRMatrix_fromRotationAboutAxis(&rmm[1], &nrm, rtan);
				mdlRMatrix_multiply(&rmm[0], &rmm[0], &rmm[1]);
				mdlVec_fromRotMatrixRow(&vec, &rmm[0], 0);
				ppp[0] = ppp[1];
				mdlVec_scaleToLength(&vec, &vec, dd);
				mdlVec_addPoint(&ppp[1], &ppp[1], &vec);

				//mdlRMatrix_multiplyPointArray(ppp, &rmX, 4);
				//mdlRMatrix_multiplyPointArray(ppp, &rm, 4);
				//mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[0].torg, 4);
				mdlLine_create(&elTmp, &edElmP->el, ppp);
				savePlotCreateElem(0, edCellP, tmP);


			}

			if (rirP && relmP->bel.sgts[i].rv[1].mblap == REIN_TERM_BEND && rirP->riropt[8])
			{
				double vecang;
				DVec3d nrm;
				DVec3d vec;
				DVec3d ttdir;
				RotMatrix rmm[2];

				double diam = mdlCnv_masterUnitsToUors(relmP->bel.diam);
				double d = diam * 5 * SGN(relmP->bel.termPar[0][1]); //(R=2.5D) signed
				double dd = mdlCnv_masterUnitsToUors(relmP->bel.termPar[1][1]) - fabs(d); // д.б. 6D
				if (rmP) d /= rmP->refscale;

				RotMatrix rmX;
				DVec3d pdir = relmP->bel.sgts[i].rv[1].rvv.tdir;
				mdlRMatrix_multiplyPoint(&pdir, &rm0);
				double dan = mdlVec_angleXY(&pdir);
				mdlRMatrix_fromAngle(&rmX, dan);

				vecang = mdlVec_angleBetweenVectors(&relmP->bel.sgts[relmP->bel.numsgts-1].rv[1].rvv.tdir, 
													&relmP->bel.sgts[relmP->bel.numsgts-2].rv[1].rvv.tdir);

				mdlVec_crossProduct(&nrm, &relmP->bel.sgts[relmP->bel.numsgts-1].rv[1].rvv.tdir, 
													&relmP->bel.sgts[relmP->bel.numsgts-2].rv[1].rvv.tdir);

				mdlVec_crossProduct(&vec, &nrm, &relmP->bel.sgts[relmP->bel.numsgts-1].rv[1].rvv.tdir);

				mdlVec_negateInPlace(&vec); // в drawSegm этого нет
				
				ttdir = relmP->bel.sgts[relmP->bel.numsgts-1].rv[1].rvv.tdir;

				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);
				mdlVec_scaleToLength(&ppp[1], &vec, d);

				mdlRMatrix_multiplyPointArray(ppp, &rmX, 4);
				mdlRMatrix_multiplyPointArray(ppp, &rm, 4);
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[1].torg, 4);
				mdlLine_create(&elTmp, &edElmP->el, ppp);
				savePlotCreateElem(0, edCellP, tmP);


				double rtan = (180 - relmP->bel.termPar[0][1]) * fc_piover180;
				mdlRMatrix_fromRowVectors(&rmm[0], &ttdir, &vec, &nrm);
				mdlRMatrix_fromRotationAboutAxis(&rmm[1], &nrm, rtan);
				mdlRMatrix_multiply(&rmm[0], &rmm[0], &rmm[1]);
				mdlVec_fromRotMatrixRow(&vec, &rmm[0], 0);
				ppp[0] = ppp[1];
				mdlVec_scaleToLength(&vec, &vec, dd);
				mdlVec_addPoint(&ppp[1], &ppp[1], &vec);

				//mdlRMatrix_multiplyPointArray(ppp, &rmX, 4);
				//mdlRMatrix_multiplyPointArray(ppp, &rm, 4);
				//mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[0].torg, 4);
				mdlLine_create(&elTmp, &edElmP->el, ppp);
				savePlotCreateElem(0, edCellP, tmP);

			}


			if (rirP && relmP->bel.sgts[i].rv[0].mblap == REIN_TERM_MUFT
				|| (relmP->bel.sgts[i].rv[0].mblap == REIN_TERM_REZB && iCfgVar_NewMuftDraw && rirP->threads)
				)
			{
				RotMatrix rmX;
				DVec3d pdir = relmP->bel.sgts[i].rv[0].rvv.tdir;
				mdlRMatrix_multiplyPoint(&pdir, &rm0);
				double dan = mdlVec_angleXY(&pdir);
				mdlRMatrix_fromAngle(&rmX, dan);

				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);

				ppp[0].y += dBarSign * dCfgVar_MuftWdtKoef;
				ppp[1].y -= dBarSign * dCfgVar_MuftWdtKoef;

				ppp[2].y -= dBarSign * dCfgVar_MuftWdtKoef;
				ppp[3].y += dBarSign * dCfgVar_MuftWdtKoef;

				if (iCfgVar_NewMuftDraw)
				{
					ppp[0].x -= dBarSign * dCfgVar_MuftHgtKoef;
					ppp[1].x -= dBarSign * dCfgVar_MuftHgtKoef;
					ppp[2].x += dBarSign * dCfgVar_MuftHgtKoef;
					ppp[3].x += dBarSign * dCfgVar_MuftHgtKoef;
				}
				else
				{
					ppp[2].x += dBarSign * 3;
					ppp[3].x += dBarSign * 3;
				}

				Transform tmm;

				//mdlTMatrix_fromRMatrix(&tmm, &rm0);
				//mdlTMatrix_rotateByRMatrix(&tmm, &tmm, &rmX);
				//mdlTMatrix_setTranslation(&tmm, &relmP->bel.sgts[i].rv[1].torg);

				mdlRMatrix_multiplyPointArray(ppp, &rmX, 4);
				mdlRMatrix_multiplyPointArray(ppp, &rm, 4);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 4); // reincache draw FIX 08/2022
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[0].torg, 4);

				mdlShape_create(&elTmp, &c0w1s0_nofill, ppp, 4, 0);

				savePlotCreateElem(0, edCellP, tmP
					//, &tmm
				);

			}

			if (rirP && relmP->bel.sgts[i].rv[1].mblap == REIN_TERM_MUFT
				|| (relmP->bel.sgts[i].rv[1].mblap == REIN_TERM_REZB && iCfgVar_NewMuftDraw && rirP->threads)
				)
			{
				RotMatrix rmX;
				DVec3d pdir = relmP->bel.sgts[i].rv[1].rvv.tdir;
				mdlRMatrix_multiplyPoint(&pdir, &rm0);
				double dan = mdlVec_angleXY(&pdir);
				mdlRMatrix_fromAngle(&rmX, dan);

				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);

				ppp[0].y += dBarSign * dCfgVar_MuftWdtKoef;
				ppp[1].y -= dBarSign * dCfgVar_MuftWdtKoef;

				ppp[2].y -= dBarSign * dCfgVar_MuftWdtKoef;
				ppp[3].y += dBarSign * dCfgVar_MuftWdtKoef;

				if (iCfgVar_NewMuftDraw)
				{
					ppp[0].x -= dBarSign * dCfgVar_MuftHgtKoef;
					ppp[1].x -= dBarSign * dCfgVar_MuftHgtKoef;
					ppp[2].x += dBarSign * dCfgVar_MuftHgtKoef;
					ppp[3].x += dBarSign * dCfgVar_MuftHgtKoef;
				}
				else
				{
					ppp[2].x += dBarSign * 3;
					ppp[3].x += dBarSign * 3;
				}

				Transform tmm;

				//mdlTMatrix_fromRMatrix(&tmm, &rm0);
				//mdlTMatrix_rotateByRMatrix(&tmm, &tmm, &rmX);
				//mdlTMatrix_setTranslation(&tmm, &relmP->bel.sgts[i].rv[1].torg);

				mdlRMatrix_multiplyPointArray(ppp, &rmX, 4);
				mdlRMatrix_multiplyPointArray(ppp, &rm, 4);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 4); // reincache draw FIX 08/2022
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[1].torg, 4);

				mdlShape_create(&elTmp, &c0w1s0_nofill, ppp, 4, 0);

				savePlotCreateElem(0, edCellP, tmP
					//, &tmm
				);

			}

			double dkoef[3];
			if (iCfgVar_NewMuftDraw)
			{
				dkoef[0] = -dCfgVar_MuftHgtKoef;
				dkoef[1] = dCfgVar_MuftHgtKoef;
				dkoef[2] = dCfgVar_MuftWdtKoef;
			}
			else
			{
				dkoef[0] = 0.0;
				dkoef[1] = 3.0;
			}

			if (relmP->bel.sgts[i].rv[0].mblap == REIN_TERM_SKOB)
			{
				RotMatrix rmX;
				DVec3d pdir = relmP->bel.sgts[i].rv[0].rvv.tdir;
				mdlRMatrix_multiplyPoint(&pdir, &rm0);
				double dan = mdlVec_angleXY(&pdir);
				mdlRMatrix_fromAngle(&rmX, dan);
				for (int b = 0; b < 5; b++)	mdlVec_zero(&ppp[b]);

				ppp[0].x += dBarSign * dkoef[1];
				ppp[0].y += dBarSign * dkoef[2];

				ppp[1].x += dBarSign * dkoef[0];
				ppp[1].y += dBarSign * dkoef[2];

				ppp[2].x += dBarSign * dkoef[1];
				ppp[2].y -= dBarSign * dkoef[2];

				ppp[3].x += dBarSign * dkoef[0];
				ppp[3].y -= dBarSign * dkoef[2];

				mdlRMatrix_multiplyPointArray(ppp, &rmX, 4);
				mdlRMatrix_multiplyPointArray(ppp, &rm, 4);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 4); // reincache draw FIX 08/2022
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[0].torg, 4);

				savePlotCreateElem(&ppp[0], edCellP, tmP);
				savePlotCreateElem(&ppp[2], edCellP, tmP);

			}

			if (relmP->bel.sgts[i].rv[1].mblap == REIN_TERM_SKOB)
			{
				RotMatrix rmX;
				DVec3d pdir = relmP->bel.sgts[i].rv[1].rvv.tdir;
				mdlRMatrix_multiplyPoint(&pdir, &rm0);
				double dan = mdlVec_angleXY(&pdir);
				mdlRMatrix_fromAngle(&rmX, dan);

				for (int b = 0; b < 5; b++)
					mdlVec_zero(&ppp[b]);

				ppp[0].x += dBarSign * dkoef[1];
				ppp[0].y += dBarSign;

				ppp[1].x += dBarSign * dkoef[0];
				ppp[1].y += dBarSign;

				ppp[2].x += dBarSign * dkoef[1];
				ppp[2].y -= dBarSign;

				ppp[3].x += dBarSign * dkoef[0];
				ppp[3].y -= dBarSign;

				mdlRMatrix_multiplyPointArray(ppp, &rmX, 4);
				mdlRMatrix_multiplyPointArray(ppp, &rm, 4);
				if (!mdlModelRef_is3D(mrPlot)) 	mdlTMatrix_transformPointArray(ppp, tmP, 4); // reincache draw FIX 08/2022
				mdlVec_addPointArray(ppp, &relmP->bel.sgts[i].rv[1].torg, 4);

				savePlotCreateElem(&ppp[0], edCellP, tmP);
				savePlotCreateElem(&ppp[2], edCellP, tmP);

			}
		}
	}

	MSElementDescr  *edDupP = NULL;

	mdlElmdscr_duplicateSingle(&edDupP, edElmP);

	mdlXMLFragmentList_stripAllFromElement (NULL, &edDupP->el);

	savePlotCreateElem(0, edCellP, 0, 0, edDupP);



	if (!mdlModelRef_is3D(mrPlot))
	{
		int res = mdlElmdscr_convertTo2D(&edCell2dP, edCellP, -1, 0, mrP, mrPlot, 1);
		if (res == SUCCESS)
		{
			mdlElmdscr_freeAll(&edCellP);
			edCellP = edCell2dP;
		}
	}

	
	if (edCellP)  // add cell
	{
		if (lvlSaveID > 0) func_amp(mdlElmdscr_setProperties,edCellP), &lvlSaveID, 0, 0, 0, 0, 0, 0, 0);

		Int32 st = 0;
		UInt32 clr = 0;
		UInt32* clrP = NULL;
		Int32* stP = NULL;
		int iBlock = FALSE;

		if (rirP->riropt[3]) // special style
		{
			if (!relmP->bel.grnd)
			{
				if (rirP->riropt[6] == -1)
					iBlock = TRUE; // no display
				else
				{
					st = rirP->riropt[6];
					stP = &st;
				}
			}
		}

		if (rirP->riropt[19]) // color by diam
		{
			clr = (UInt32)relmP->bel.diam;
			clrP = &clr;
		}

		if (clrP || stP)
			func_amp(mdlElmdscr_setSymbology, edCellP), clrP, stP, 0, 0);

		mdlElmdscr_setTransparency(&edCellP, 0.0); // no transparency on cached

		if (iBlock)
			mdlElmdscr_setVisible(edCellP, iBlock);

		xmlAddCacheInfo(relmP, &edCellP);

		fpos = mdlElmdscr_addByModelRef(edCellP, mrPlot);

		if (fpos == 0) 
		{
			//SPRN(s, L("ошибка при добавлении элемента  ---  fpos %u   err %i\n"), mdlElmdscr_getFilePos(edElmP), mdlErrno); // zb mdlErrno=-222, -> MDLERR_2D3D_MISMATCH
			//mdlDialog_dmsgsPrint(s);
			ret = ERROR;
		}
	}

	//if (edBar3dP) mdlElmdscr_freeAll(&edBar3dP);

	if (bMustFree && edElmP) mdlElmdscr_freeAll(&edElmP);
	if (edCellP) mdlElmdscr_freeAll(&edCellP);


	writeLogOut(__FUNCTION__, 0);

	return ret;

}

/////////////////////////////
void savePlotCreateElem(DVec3d* ppp, MSElementDescr* edCellP, Transform* tmP, Transform* tmRevP, MSElementDescr  *edAddP)
{
	MSElementDescr*  edp = edAddP;
	MSElementDescr*  edp2d = NULL;
	UInt32* lvlP = NULL;
	BINT lck = FALSE;
	UInt32 fp = 0;
	int res = 0;

	if (edAddP == NULL)
	{
		// если линия
		if (ppp) mdlLine_create(&elTmp, &c0w1s0, ppp);

		// создание
		mdlElmdscr_new(&edp, 0, &elTmp);
	}

	if (tmRevP) func_amp(mdlElmdscr_transform,edp), tmRevP);

	
	if (!mdlModelRef_is3D(mrPlot))
	{
		//if (tmRevP) func_amp(mdlElmdscr_transform,edp), tmRevP);

		res = mdlElmdscr_convertTo2D(&edp2d, edp, 
			-1, // view number
			0, // transform
			ACTIVEMODEL,  // if cho use mrRefPlotFromP
			mrPlot, // also ACTIVEMODEL
			1);

		if (res == SUCCESS)
		{
			mdlElmdscr_freeAll(&edp);
			edp = edp2d;
		}
	}
	else 
	if (tmP) 
		func_amp(mdlElmdscr_transform,edp), tmP);


	if (lvlSaveID > 0) lvlP = &lvlSaveID;
	func_amp(mdlElmdscr_setProperties, edp), lvlP, 0, 0, &lck, 0, 0, 0, 0);



	if (edCellP) 
		res = mdlElmdscr_appendDscr(edCellP, edp);
	else
	{
		ReinElm re;
		xmlAddCacheInfo(&re, &edp);
		fp = mdlElmdscr_addByModelRef(edp, mrPlot);
		mdlElmdscr_freeAll(&edp);
	}
}

/////////////////////////////
//void savePlotCreateElem(DVec3d* ppp, MSElementDescr* edCellP, Transform* tmP)
//{
//	savePlotCreateElem(ppp, edCellP, tmP, NULL);
//}



/*
///////////////////////////////////
void hookComboBoxLineStyle(
DialogItemMessage   *dimP
)
{

    dimP->msgUnderstood= TRUE;

	ListModel   *pListModel = NULL;
	


    switch  (dimP->messageType)
    {

		case DITEM_MESSAGE_CREATE:
			{
			pListModel = (ListModel*)createListBoxLineStyle();
			mdlDialog_comboBoxSetListModelP (dimP->dialogItemP->rawItemP, pListModel);
			break;
			}

		case DITEM_MESSAGE_DESTROY:
			{
			pListModel = (ListModel*)mdlDialog_comboBoxGetListModelP (dimP->dialogItemP->rawItemP);
			mdlListModel_destroy (pListModel,TRUE);
			break;
			}
		case DITEM_MESSAGE_STATECHANGED:
			{
			int          row, col;
			RawItemHdr* rihP = mdlDialog_comboBoxGetListBoxP(dimP->dialogItemP->rawItemP);
			if (rihP) 
			{
				//ListModel*   pListModel = NULL;
				//ListCell*    pListCell  = NULL;
				//if (SUCCESS == mdlDialog_listBoxLastCellClicked (&row, &col, rihP))
				//{
				//	char* v;
				//	pListModel = mdlDialog_listBoxGetListModelP (rihP);
				//	pListCell  = mdlListModel_getCellAtIndexes (pListModel, row, 0); // get ref num
				//	if (mdlListCell_getStringValue(pListCell, &v) == SUCCESS)
				//	{
				//		curPos_refnum = atol(v);
				//		updateListBoxPos(FALSE);
				//	}
				//}
			}
			break;
			}
		default:
			dimP->msgUnderstood=FALSE;
			break;
    }

    return ;

}

////////////////////////////////////////////
ListModel* createListBoxLineStyle(
)
{

    ListModel   *pListModel;
    ListRow     *pRow;
	char v[500];
	int res = 0;

    pListModel = mdlListModel_create(1);

	pRow = mdlListRow_create (pListModel);
	{
		ListCell    *pCell;
		pCell = mdlListRow_getCellAtIndex (pRow, 0);
		res = mdlListCell_setIcon(pCell, ICONID_LineStyle0, RTYPE_IconCmdTinyIcon, mdlSystem_getCurrMdlDesc()); //mdlSystem_getCurrMdlDesc()
	}

	pRow = mdlListRow_create (pListModel);
	{
		ListCell    *pCell;
		pCell = mdlListRow_getCellAtIndex (pRow, 0);
		res = mdlListCell_setIcon(pCell, ICONID_LineStyle1, RTYPE_IconCmdTinyIcon, 0);
	}

	pRow = mdlListRow_create (pListModel);
	{
		ListCell    *pCell;
		pCell = mdlListRow_getCellAtIndex (pRow, 0);
		res = mdlListCell_setIcon(pCell, ICONID_LineStyle2, RTYPE_IconCmdTinyIcon, 0);
	}

	pRow = mdlListRow_create (pListModel);
	{
		ListCell    *pCell;
		pCell = mdlListRow_getCellAtIndex (pRow, 0);
		res = mdlListCell_setIcon(pCell, ICONID_LineStyle3, RTYPE_IconCmdTinyIcon, 0);
	}

	pRow = mdlListRow_create (pListModel);
	{
		ListCell    *pCell;
		pCell = mdlListRow_getCellAtIndex (pRow, 0);
		res = mdlListCell_setIcon(pCell, ICONID_LineStyle4, RTYPE_IconCmdTinyIcon, 0);
	}

	pRow = mdlListRow_create (pListModel);
	{
		ListCell    *pCell;
		pCell = mdlListRow_getCellAtIndex (pRow, 0);
		res = mdlListCell_setIcon(pCell, ICONID_LineStyle5, RTYPE_IconCmdTinyIcon, 0);
	}

	return pListModel;


}


*/

/*
//////////////////////////////////////////////////////
int scanCheckShowInfo(
MSElementDescr  *edP,
ReinInfo*       riP,
ScanCriteria    *pScanCriteria
)
{
	int res;

	if (riP == NULL)
	{
		res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos (edP->h.elementRef), FALSE);
	}
	else
	{
		XMLFragmentListP  oXMLFragmentList = NULL;

		UInt32 fp = mdlElmdscr_getFilePos(edP);

		oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

		if (oXMLFragmentList)
		{
			XMLFragmentP        pXMLFragment;
			MSWCH* wtxt;
			char ctxt[500];
			pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);
			// mdlXMLFragment_getText(&wtxt, pXMLFragment);
			mdlCnv_convertUnicodeToMultibyte(wtxt, -1, ctxt, 500);
			mdlXMLFragmentList_free(&oXMLFragmentList);

			char seps[]   = "|";
			char *token;

			token = strtok( ctxt, seps );	if (token != NULL)	riP->option[2] = atoi(token);	//1
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[4] = atoi(token);	//2
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[5] = atoi(token);	//3


			token = strtok( NULL, seps );	if (token != NULL)	riP->option[1] = atoi(token);	//4
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[17] = atoi(token);	//5
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[18] = atoi(token);	//6
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[11] = atoi(token);	//7
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[9] = atoi(token);	//8
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[10] = atoi(token);	//9
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[8] = atoi(token);	//10
			token = strtok( NULL, seps );	if (token != NULL)	riP->ends = atoi(token);		//11
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[14] = atoi(token);	//12
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[13] = atoi(token);	//13
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[15] = atoi(token);	//14
			token = strtok( NULL, seps );	if (token != NULL)	riP->option[19] = atoi(token);	//15
			token = strtok( NULL, seps );	if (token != NULL)	riP->threads = atoi(token);		//16
			token = strtok( NULL, seps );	if (token != NULL)	riP->bface = atoi(token);		//17

			riP->lim = 1;

		}
		else // MDLERR_LINKAGENOTFOUND
			return ERROR;	
	}

	return SUCCESS;
}
*/

/*
/////////////////////////////
int getShowInfo(ReinInfo* riP, DgnModelRefP mrP)
{

	ScanCriteria    *pScanCriteria;
	int status;

	riP->lim = 0;

	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckShowInfo, riP);
	status = mdlScanCriteria_setModel (pScanCriteria, mrP);
	mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeShowInfo);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	if (riP->lim == 1) // загружен ок
	{
		return SUCCESS;
	}

	return 1;

}
*/

/*
///////////////////////////////////////////////////////////////////////////////////
void saveShowInfo(ReinInfo* riP, ReinDopInfo* rdiP)
{
	MSElementDescr* pXmlFragmentElement = NULL; 
	XMLFragmentListP pCurrent = NULL; 
	MSWCH wstr[500];
	char str[500];


	ScanCriteria    *pScanCriteria;
	int status;

	// delete all prev. xml elements
	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckShowInfo, NULL);
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeShowInfo);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);



	//rInfo.option[2]	"Образующий элемент контура армирования"
	//rInfo.option[4]	"Образующий элемент отдельного стержня"
	//rInfo.option[5]	"Производный элемент (ось стержня)"


	sprintf(str, "%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i", 
				1,1,1,				// 1,2,3
				riP->option[1],		// 4	//rInfo.option[1]	"Внутренние (прозрачные) стержни контура"
				riP->option[17], 	// 5	//rInfo.option[17]	"Внутренние стержни для сечений"
				riP->option[18], 	// 6	//rInfo.option[18]	"Невидимые стержни пунктиром"
				riP->option[11], 	// 7	//rInfo.option[11]	"Сечения стержней"
				riP->option[9], 	// 8	//rInfo.option[9]	"Реальный диаметр сечения"
				riP->option[10], 	// 9	//rInfo.option[10]	"Контуры объёма стержня"
				riP->option[8], 	// 10	//rInfo.option[8]	"Загибы"
				riP->ends, 			// 11	//rInfo.ends		"Засечки"
				riP->option[14], 	// 12	//rInfo.option[14]	"Крестики"
				riP->option[13], 	// 13	//rInfo.option[13]	"Нолики"
				riP->option[15], 	// 14	//rInfo.option[15]	"Номера позиций"
				riP->option[19],	// 15	//rInfo.option[19]	"Цвет элемента по диаметру"
				riP->threads,		// 16	//rInfo.threads "Резьба"
				riP->bface			// 17	//rInfo.bface
				);

	status = mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 500);

	pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeShowInfo); 

	status = mdlXMLFragmentList_createXMLElementDescriptor  (&pXmlFragmentElement, &pCurrent, FALSE); 

	if (NULL != pXmlFragmentElement) 
	{ 
		UInt32 fp;

		fp = mdlElmdscr_add (pXmlFragmentElement); 
		mdlElmdscr_freeAll (&pXmlFragmentElement); 

		mdlXMLFragmentList_free(&pCurrent);
	} 
}
*/


/////////////////////////////
void loadComboList(long id)
{
	DialogItem* diP = NULL;
	MSDLGP dbP = findToolBox();
	RscFileHandle   userPrefsH;

	if (NULL != dbP)
	{
		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ComboBox, id, 0);
	}

	if (diP)
	{
		StringList* slP = NULL;
		
		int res = mdlDialog_userPrefFileOpen(&userPrefsH, TRUE);

		if (res = SUCCESS && userPrefsH)
		{
			slP = mdlStringList_loadResourceWithTypeAndAlias(userPrefsH, RTYPE_STRINGLIST, 1500 + id, mdlSystem_getCurrTaskID());
			mdlResource_closeFile(userPrefsH);
		}

		if (slP)
		{
			mdlDialog_comboBoxSetStrListP(diP->rawItemP, slP, 1);
			//mdlDialog_itemSynchByTypeAndId(dbP, RTYPE_ComboBox, id);

		}

	}

}

////////////////////
void saveComboList(long id)
{
	DialogItem* diP = NULL;
	MSDLGP dbP = findToolBox();
	RscFileHandle   userPrefsH;


	if (NULL != dbP)
	{
		diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ComboBox, id, 0);
	}

	if (diP)
	{
		StringList* slP = NULL;
		slP = mdlDialog_comboBoxGetStrListP(diP->rawItemP);

		if (slP)
		{

			long num = mdlStringList_size(slP);

			if (num > 5)
			{
				mdlStringList_deleteMember(slP, 5, num - 5);
			}
			
			int st = mdlDialog_userPrefFileOpen(&userPrefsH, TRUE);
			if (st == SUCCESS && userPrefsH)
			{
				mdlStringList_writeResourceWithTypeAndAlias(slP, userPrefsH, RTYPE_STRINGLIST, 1500 + id, mdlSystem_getCurrTaskID());
				mdlResource_closeFile(userPrefsH);
			}
		}
	}

}

///////////////////////////////////
void hookNoteCombo(
	DialogItemMessage* dimP
)
{

	dimP->msgUnderstood = TRUE;


	switch (dimP->messageType)
	{

	case DITEM_MESSAGE_CREATE:
	{
		loadComboList(dimP->dialogItemP->id);
		break;
	}

	case DITEM_MESSAGE_INIT:
	{
	//	mdlDialog_itemSynchByTypeAndId(dimP->db, RTYPE_ComboBox, dimP->dialogItemP->id);

		// приходится принудительно, если пустая строка то ставится последнее значение из листа комбобокса


		if (SLEN(curNoteSet.sNoteUpFmt) == 0 && dimP->dialogItemP->id == COMBOBOX_NoteUpFmt)
		{
			BINT bch;
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
			mdlDialog_rItemValueSet(&bch, 0, 0, curNoteSet.sNoteUpFmt, dimP->dialogItemP->rawItemP);
#else
			MSValueDescr vv;
			vv.GetWChar(curNoteSet.sNoteUpFmt, 100);
			mdlDialog_rItemValueSet(&bch, vv, dimP->dialogItemP->rawItemP);
#endif
		}

		if (SLEN(curNoteSet.sNoteDnFmt) == 0 && dimP->dialogItemP->id == COMBOBOX_NoteDnFmt)
		{
			BINT bch;
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
			mdlDialog_rItemValueSet(&bch, 0, 0, curNoteSet.sNoteDnFmt, dimP->dialogItemP->rawItemP);
#else
			MSValueDescr vv;
			vv.GetWChar(curNoteSet.sNoteDnFmt, 100);
			mdlDialog_rItemValueSet(&bch, vv, dimP->dialogItemP->rawItemP);
#endif
		}

		break;
	}

	case DITEM_MESSAGE_DESTROY:
	{
		saveComboList(dimP->dialogItemP->id);
		break;
	}
	case DITEM_MESSAGE_STATECHANGED:
	{
		setReinNoteText();

		break;
	}

	default:
		dimP->msgUnderstood = FALSE;
		break;
	}

	return;


}

/////////////////////////////////////
void hookLevelCombo(
	DialogItemMessage* dimP
)
{

	dimP->msgUnderstood = TRUE;

	switch (dimP->messageType)
	{

	case DITEM_MESSAGE_CREATE:
	{
		ListModel* lmP = NULL;
		lmP = mdlListModel_create(1);
		mdlDialog_comboBoxSetListModelP(dimP->dialogItemP->rawItemP, lmP);
		mdlLevelList_getLevelNamesListModel(lmP, ACTIVEMODEL
#if defined (MSVERSION) && (MSVERSION == 0xa00)
			,0,0
#endif
		);
		break;
	}

	case DITEM_MESSAGE_DESTROY:
	{
		ListModel* lmP = NULL;
		lmP = mdlDialog_comboBoxGetListModelP(dimP->dialogItemP->rawItemP);
		if (lmP) mdlListModel_destroy(lmP, TRUE);
		break;
	}

	case DITEM_MESSAGE_INIT:
	{
		//DialogItem* diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_ComboBox, COMBOBOX_NoteLevels, 0);
		//mdlDialog_itemSynchByTypeAndId(dimP->db, RTYPE_ComboBox, COMBOBOX_NoteLevels);
		//mdlDialog_itemsApply(dimP->db);
		break;
	}

	case DITEM_MESSAGE_STATECHANGED:
	{
		//DialogItem* diP = mdlDialog_itemGetByTypeAndId(dimP->db, RTYPE_ComboBox, COMBOBOX_NoteLevels, 0);
		//mdlDialog_itemSynchByTypeAndId(dimP->db, RTYPE_ComboBox, COMBOBOX_NoteLevels);
		//mdlDialog_itemsApply(dimP->db);
		break;
	}

	default:
		dimP->msgUnderstood = FALSE;
		break;
	}

	return;
}

//////////////////////////////////
// func: presentation options model option hook
void hookOptionPref(
		DialogItemMessage   *dimP	/* => a ptr to a dialog item message */
)
{
    dimP->msgUnderstood = TRUE;

	//printf("%i\n", dimP->messageType);



    switch (dimP->messageType)
	{

	case DITEM_MESSAGE_INIT:
		{
			createOptionShow();
			//syncShowInfo();

			break;
		}
	case DITEM_MESSAGE_STATECHANGED:
		{
			syncShowInfo();

			//updateAllViews();

			break;
		}
	case DITEM_MESSAGE_SYNCHRONIZE:
		{
			break;
		}
	default:
	    dimP->msgUnderstood = FALSE;
	    break;
	}


}

//////////////////////////////////
void removeClashByFP(UInt32 fp1, UInt32 fp2, BINT bDisplay)
{
	bool b1 = false;
	bool b2 = false;

	if (fp1 == 0) return;
	if (fp2 == 0) b2 = true;

	for (map<UInt32pair, ReinClash>::iterator it = mapClash.begin(); it != mapClash.end();)
	//for (auto& entry : mapClash)
	{
		//auto key_pair = entry.first;

		if (it->second.fpElem[0] == fp1 || it->second.fpElem[1] == fp1)
		{
			TransDescrP tedP = mdlTransientElemRef_getTDP(it->second.erefClsh);

			if (tedP) mdlTransient_free(&tedP, bDisplay);

			mapClash.erase(it);

			b1 = true;
		}
		else if (fp2 > 0 && (it->second.fpElem[0] == fp2 || it->second.fpElem[1] == fp2))
		{
			TransDescrP tedP = mdlTransientElemRef_getTDP(it->second.erefClsh);

			if (tedP) mdlTransient_free(&tedP, bDisplay);

			mapClash.erase(it);

			b2 = true;
		}
		//else .. при удалении на map все равно надо делать итерацию... %)
		{
			++it;
		}

		//if (b1 && b2) break; .. не останавливаемся, тк может быть много пересечений на одном стержне
	}
}

/////////////////////////////////
int scanForDuplicate(
MSElementDescr  *edP,
ReinPrm* prmP, // from param
ScanCriteria    *pScanCriteria					
)
{

	MSElementDescr* edSrcP = prmP->edP;

//#define COMPAREOPT_IGNORE_MODEL_DIFFS                       (1<<0)
//#define COMPAREOPT_IGNORE_SYMBOLOGY                         (1<<1)
//#define COMPAREOPT_IGNORE_IDS                               (1<<2)
//#define COMPAREOPT_IGNORE_LINKAGES                          (1<<3)
//#define COMPAREOPT_IGNORE_MODIFIED                          (1<<4)
//#define COMPAREOPT_IGNORE_DGNSTORE                          (1<<5)
//#define COMPAREOPT_IGNORE_ATTRIBUTE_VALUE                   (1<<6)
//#define COMPAREOPT_IGNORE_SINGLE_EDF_VALUES                 (1<<7)
//#define COMPAREOPT_IGNORE_CELL_RANGEDIAG                    (1<<8)
//#define COMPAREOPT_IGNORE_DGNDWGTEXTDIFFERENCES             (1<<9)
//#define COMPAREOPT_IGNORE_2D_RANGEZ                         (1<<10)
//#define COMPAREOPT_IGNORE_MULTISPANNINGSIBLINGBOUNDARIES    (1<<11)     // Set to compare en masse logical entities that may span multiple siblings of a complex header (e.g., B-spline surface boundary and
//                                                                        // matrix data elements).  Default (unset) enforces element-to-element comparison of such siblings.
//#define COMPAREOPT_IGNORE_UNORDEREDSIBLINGORDER             (1<<12)     // Set to compare sibling elements that may appear under a complex header in any order (e.g., matrix children of a mesh element).
//                                                                        // Default (unset) enforces ordered comparison of such siblings.
//#define COMPAREOPT_IGNORE_LINESTYLEDIRECTION                (1<<13)     // Ignore all but linestyle scale.
//#define COMPAREOPT_IGNORE_LEVEL                             (1<<14)
//#define COMPAREOPT_IGNORE_2D_ZRANGE                         (1<<15)
//#define COMPAREOPT_IGNORE_CELL_TRANSFORM                    (1<<16)
//#define COMPAREOPT_IGNORE_XATTRIBUTES                       (1<<17)
//#define COMPAREOPT_TEST_FACEMATERIALS                       (1<<18)
//#define COMPAREOPT_IGNORE_INVISIBLE_ELEMENTS                (1<<19)     //  If both elements are invisible say they are the same.
//#define COMPAREOPT_IGNORE_ELEMENT_CLASS                     (1<<20)
//#define COMPAREOPT_IGNORE_CELL_HEADER_ELM                   (1<<21) 
//
//#define COMPAREOPT_STANDARD_IGNORES             (COMPAREOPT_IGNORE_MODEL_DIFFS | 
												//COMPAREOPT_IGNORE_SYMBOLOGY | 
												//COMPAREOPT_IGNORE_IDS | 
												//COMPAREOPT_IGNORE_LINKAGES | 
												//COMPAREOPT_IGNORE_MODIFIED | 
												//COMPAREOPT_IGNORE_XATTRIBUTES)

	UInt32 fp[2];
	UInt32 lv[2];
	ReinElm* reP[2] = {NULL,NULL};
	bool bEq[2] = {false,false};
	ReinModel* amrp[2] = {NULL,NULL};

	fp[0] = mdlElmdscr_getFilePos(edP);
	fp[1] = mdlElmdscr_getFilePos(edSrcP);

	if (fp[0] == fp[1]) return SUCCESS;

	mdlElmdscr_getProperties(&lv[0], 0, 0, 0, 0, 0, 0, 0, edP);
	mdlElmdscr_getProperties(&lv[1], 0, 0, 0, 0, 0, 0, 0, edSrcP);

	//BINT ret = mdlElmdscr_areIdenticalToTolerance(edP, edSrcP, COMPAREOPT_IGNORE_CELL_TRANSFORM | COMPAREOPT_STANDARD_IGNORES, mdlCnv_masterUnitsToUors(dDupTol), 1.0E-8);

	amrp[0] = curRM->getRM(edP->h.dgnModelRef);
	amrp[1] = curRM->getRM(edSrcP->h.dgnModelRef);

	if (amrp[0] == NULL) return 0;
	if (amrp[1] == NULL) return 0;

	reP[0] = amrp[0]->getReinElm(fp[0]);
	reP[1] = amrp[1]->getReinElm(fp[1]);

	if (reP[0] && reP[1])
	{

		//if (reP[0]->tedP) // вылетает
		//{
		//	if (mdlTransient_isValid(reP[0]->tedP)) mdlTransient_free(&reP[0]->tedP, 1);
		//	reP[0]->tedP = NULL;
		//}

		//removeClashByFP(fp[0], fp[1], FALSE);

		UInt32pair m_pair;

		if (fp[0] < fp[1])
			m_pair = make_pair(fp[0], fp[1]);
		else
			m_pair = make_pair(fp[1], fp[0]);

		map<UInt32pair, ReinClash>::iterator it = mapClash.find(m_pair);


		// = = = = = C L A S H = = = = = 
		if (iCfgVar_Clash_Mode 
			&& it == mapClash.end() // not exist
			&& reP[1]->bTransientInProgress)
		{
			DVec3d p[2];
			double dist = 0.;
			double chdist = 0.;
			double dclsh = 0.;
			double dclshcor = 0.;

			int ret = mdlMinDist_betweenElms(&p[0], &p[1], &dist, edP, edSrcP, &reP[0]->bel.rpts[0], 0.);

			if (ret == SUCCESS)
			{
				//UInt32 idist = (UInt32)mdlCnv_uorsToMasterUnits(dist);
				
				// если не конечная точка edP
				if (!(pointIsEqual(&p[0], &reP[0]->tel.rpts[0], 1)
					|| pointIsEqual(&p[0], &reP[0]->tel.rpts[reP[0]->tel.numpts - 1], 1)))
					chdist = mdlCnv_masterUnitsToUors(fillets[reP[0]->bel.diam].diamrif / 2.);

				// если не конечная точка edSrcP
				if (!(pointIsEqual(&p[1], &reP[1]->tel.rpts[0], 1)
					|| pointIsEqual(&p[1], &reP[1]->tel.rpts[reP[1]->tel.numpts - 1], 1)))
					chdist += mdlCnv_masterUnitsToUors(fillets[reP[1]->bel.diam].diamrif / 2.);

				dclsh = chdist - dist; // in uors

				if (dclsh > 0.)
				{
					dclsh = mdlCnv_uorsToMasterUnits(dclsh);

					dclshcor = dclsh - (double)iCfgVar_Clash_Tol; // на это значение налезать можно -> REIN_BAR_CLASH_TOLERANCE
				}

				if (dclshcor > 0.)
				{
					UInt32 wgt = 5 + (UInt32)(((chdist - dist) / chdist) * 15.);
					DVec3d pp[2];

					mdlVec_interpolate(&pp[0], &p[0], fillets[reP[0]->bel.diam].diamrif / (fillets[reP[0]->bel.diam].diamrif + fillets[reP[1]->bel.diam].diamrif), &p[1]);
					pp[1] = pp[0];

					//if (dist < mdlCnv_masterUnitsToUors(dDupTol) / 5.) // короткие линии плохо видны, превращаем в точку
					//{
						//wgt = 20;
						//mdlVec_interpolate(&pp[0], &p[0], 0.5, &p[1]);
						//pp[1] = pp[0];
						
						//if (
						//	pointIsEqual(&reP[0]->tel.rpts[0], &reP[1]->tel.rpts[0], 1)
						//	|| pointIsEqual(&reP[0]->tel.rpts[0], &reP[1]->tel.rpts[reP[1]->tel.numpts - 1], 1)
						//	|| pointIsEqual(&reP[0]->tel.rpts[reP[0]->tel.numpts - 1], &reP[1]->tel.rpts[0], 1)
						//	|| pointIsEqual(&reP[0]->tel.rpts[reP[0]->tel.numpts - 1], &reP[1]->tel.rpts[reP[1]->tel.numpts - 1], 1)
						//	)
						//{
						//	wgt = 0;
						//}
					//}
					//else
					//{
					//	//pp[0] = p[0];
					//	//pp[1] = p[1];
					//}

					if (wgt > 0)
					{
						//mdlLine_create(&el, &c3w1s0, p);
						//if (levClash) mdlElement_setProperties(&el, &levClash, 0, 0, 0, 0, 0, 0, 0);
						////mdlXMLFragmentList_attachToElement
						//reP[1]->tedP = mdlTransient_addElement(reP[1]->tedP, &el, TRUE, 0x00ff, NORMALDRAW, 1, 0, 0);

						MSElementDescr* edLnP = NULL;
						mdlLine_create(&el, &c3w9s0, pp);
						mdlElement_setSymbology(&el, 0, &wgt, 0);
						if (levClash) mdlElement_setProperties(&el, &levClash, 0, 0, 0, 0, 0, 0, 0);
						mdlElmdscr_new(&edLnP, NULL, &el);
						//mdlXMLFragmentList_attachToElement
						//reP[1]->tedP = mdlTransient_addElement(reP[1]->tedP, &el, TRUE, 0x00ff, DRAW_MODE_Normal, 1, 0, 0);

						ReinClash rc;
						rc.fpElem[0] = fp[0];
						rc.fpElem[1] = fp[1];
						rc.idElem3d[0] = reP[0]->bel.brid;
						rc.idElem3d[1] = reP[1]->bel.brid;
						rc.lvID[0] = lv[0];
						rc.lvID[1] = lv[1];
						rc.cdiam[0] = fillets[reP[0]->bel.diam].diamrif;
						rc.cdiam[1] = fillets[reP[1]->bel.diam].diamrif;
						rc.idist = mdlCnv_roundDoubleToULong (dclsh);
						rc.pt = pp[0];

						xmlAddClash(&rc, &edLnP);

						TransDescrP tedP = mdlTransient_addElemDescr(NULL, edLnP, TRUE, 0x00ff, DRAW_MODE_Normal, 1, 0, 0);

						rc.erefClsh = mdlTransient_getLastElementRef(tedP);


						/*

#if defined (MSVERSION) && (MSVERSION == 0xa00)
						MSElementDescrCP edT = mdlTransient_returnElemDescr(tedP);
#else
						MSElementDescr* edT = NULL;
						mdlTransient_returnElemDescr(&edT, tedP);
#endif

						UInt32 fpp = mdlElmdscr_getFilePos(edT);
						
						//if (fpp == 21080)
						//	__asm nop;

						*/

						if (rc.erefClsh)
						{
							UInt32 fpp = elementRef_getFilePos(rc.erefClsh);
							
							mapClash[m_pair] = rc;
						}
					}
				}
			}
		}
		// = = = = = C L A S H = = = = = 

		if (iCfgVar_CheckDups)
		{
			if (reP[0]->bel.pnum == reP[1]->bel.pnum && reP[0]->bel.numpts == reP[1]->bel.numpts && reP[0]->bel.numpts > 1)
			{
				int j = reP[0]->bel.numpts - 1;

				// в одну сторону
				bEq[0] = true;
				for (int i = 0; i < reP[0]->bel.numpts; i++)
				{
					if (!(coordIsEqual(reP[0]->bel.rpts[i].x, reP[1]->bel.rpts[i].x, FALSE)
						&& coordIsEqual(reP[0]->bel.rpts[i].y, reP[1]->bel.rpts[i].y, FALSE)
						&& coordIsEqual(reP[0]->bel.rpts[i].z, reP[1]->bel.rpts[i].z, FALSE)))
					{
						bEq[0] = false;
						break;
					}
				}

				// в обратную сторону
				bEq[1] = true;
				for (int i = 0; bEq[0] == false && i < reP[0]->bel.numpts; i++)
				{
					if (!(coordIsEqual(reP[0]->bel.rpts[i].x, reP[1]->bel.rpts[j].x, FALSE)
						&& coordIsEqual(reP[0]->bel.rpts[i].y, reP[1]->bel.rpts[j].y, FALSE)
						&& coordIsEqual(reP[0]->bel.rpts[i].z, reP[1]->bel.rpts[j].z, FALSE)))
					{
						bEq[1] = false;
						break;
					}
					j--;
				}

			}

			if (bEq[0] || bEq[1])
			{
				reP[0]->fpDup = mdlElmdscr_getFilePos(edSrcP);
				reP[1]->fpDup = mdlElmdscr_getFilePos(edP);
				if (pScanCriteria) elemCount++;
			}
		}
	}
	else if (reP[0] && pScanCriteria 
				&& iAC == CMD_REIN_NOTE
				&& iACStep == REIN_NOTE_STEP_NOTE1
			) // сканирование для выноски...
	{

		DVec3d p[2];
		double dist = 0.;
		MSElementDescrP       edTrP = NULL;

		DgnModelRefP mrRefP = mdlScanCriteria_getModel(pScanCriteria);

		mdlElmdscr_readToMaster(&edTrP, fp[0], mrRefP, 0, 0);

		// чтобы не подхватывал стержни из других сечений
		BINT bInside = testVecInsideRefClip(mrRefP, &curNote.arNotePts[0], &curNote.arNotePts[1], tcb->lstvw);

		if (edTrP)
		{
			int ret = mdlMinDist_betweenElms(&p[0], &p[1], &dist, edTrP, edSrcP, &reP[0]->bel.rpts[0], 0.);

			if (ret == SUCCESS && dist < 100. 
				&& bInside
				)
			{
				//mdlLine_create(&el, &c3w9s0, p);
				//mdlTransient_addElement(0, &el, 1, 0x00ff, DRAW_MODE_Normal, 1, 1, 1);

				//if (mdlElement_isEffectivelyVisible(&edTrP->el, mdlScanCriteria_getModel(pScanCriteria), tcb->lstvw)) // видимость определяется местными переменными
				// hilite отключено при обновлении - если много стержней, долгая реакция
				if (!curNote.bUpdate)
					mdlLocate_hiliteElement(edTrP->h.elementRef, mrRefP);

				int space = 0;
				// get space from Reinspace
				ELREF eref = getElemRefByID(reP[0]->bel.modrefP, reP[0]->bel.elemid);
				if (eref)
				{
					MSElementDescr* edp = NULL;
					mdlElmdscr_getByElemRef(&edp, eref, reP[0]->bel.modrefP, FALSE, 0);
					if (edp)
					{
						ReinElement relem;
						if (readReinSpaceFromElmd(&relem, edp, FALSE) == SUCCESS) space = (int)relem.rs.space;
						mdlElmdscr_freeAll(&edp);
					}
				}

				ReinPos rp;
				rp.bar = reP[0]->bel; // include pnum, space

				rp.bar.brid = mdlModelRef_getAttachmentID(mrRefP);
				curNote.vBars.push_back(rp.bar);

				map<long, ReinPos>::iterator it = curNote.mapNotePos.find(reP[0]->bel.pnum);
				if (it != curNote.mapNotePos.end()) // found	
				{
					it->second.file_qty_p++;
					if (rp.muft_qty[0] != space)
						rp.muft_qty[1] = space;
				}
				else
				{
					rp.file_qty_p = 1;
					rp.muft_qty[0] = space;
					curNote.mapNotePos.insert(pair<long, ReinPos>(reP[0]->bel.pnum, rp));
				}



				//.. ...........
			}

			mdlElmdscr_freeAll(&edTrP);
		}


	}
	else if (prmP->wstr.compare(L"copy") == 0)
	{
		ReinElm retmp[2];
		if (
			readReinElmIso(&retmp[0], edP, 0, 0) == SUCCESS
			&& readReinElmIso(&retmp[1], edSrcP, 0, 0) == SUCCESS
			)
		{
			if (retmp[0].bel.elemid == retmp[1].bel.elemid)
			{
				// возвернуть элемент _ISO

				prmP->prmid = mdlElement_getID(&edP->el);

			}
		}
	}


	return SUCCESS;


}
///////////////////////
int scanCheckDuplicateCount(
	MSElementDescr* edP,
	int* bCheckClashP,
	ScanCriteria* pScanCriteria
)
{

	ReinModel* rmP = curRM->getRM(edP->h.dgnModelRef);
	if (rmP == NULL) return 0;
	ReinElm* reP = rmP->getReinElm(mdlElmdscr_getFilePos(edP));
	if (reP == NULL) return 0;

	elemCount3++;
	return SUCCESS;
}

///////////////////////
// command DUPS + check after insert mapElms
int scanCheckDuplicate(
MSElementDescr  *edP,
ReinPrm*  prmP,
ScanCriteria    *pScanCriteria		// if NULL - not from scan!	(insertCurBarsMember2)		
)
{
	int* bCheckClashP = NULL;
	
	if (prmP) bCheckClashP = &(prmP->ival[0]);


	ScanCriteria    *scP = NULL;
	int status;
	ReinElm re;
	ReinBar rb;
	ReinSpace rs;
	DPoint3d prng[2];
	ScanRange sr;
	int tp = mdlElement_getType(&edP->el);
	//DgnModelRefP mrP = mdlScanCriteria_getModel(pScanCriteria); pScanCriteria may be NULL
	DgnModelRefP mrP = edP->h.dgnModelRef;

	mdlElmdscr_computeRange(&prng[0], &prng[1], edP, NULL);

	if (bCheckClashP && *bCheckClashP)
		levClash = getOrCreateLevel(ACTIVEMODEL, L"_Коллизии", TRUE);

	//UInt32 fp = mdlElmdscr_getFilePos(edP);
	//ReinModel* rmP = curRM->getRM(edP->h.dgnModelRef);
	//ReinElm* reP = NULL;
	//if (rmP) reP = rmP->getReinElm(fp);
	//if (reP) reP->mapClash.clear();

	UInt32 fp = mdlElmdscr_getFilePos(edP);

	ReinModel* rmP = curRM->getRM(edP->h.dgnModelRef);
	if (rmP == NULL) return 0;
	ReinElm* reP = rmP->getReinElm(fp);
	if (reP == NULL) return 0;

	//if (reP->tedP) // always NULL
	//{
	//	if (mdlTransient_isValid(reP->tedP)) mdlTransient_free(&reP->tedP, 1);
	//	reP->tedP = NULL;
	//}
		
	if (bCheckClashP) reP->bTransientInProgress = *bCheckClashP;

	sr.xlowlim = (Int64)(prng[0].x - mdlCnv_masterUnitsToUors(dDupTol));
	sr.ylowlim = (Int64)(prng[0].y - mdlCnv_masterUnitsToUors(dDupTol));
	sr.zlowlim = (Int64)(prng[0].z - mdlCnv_masterUnitsToUors(dDupTol));

	sr.xhighlim = (Int64)(prng[1].x + mdlCnv_masterUnitsToUors(dDupTol));
	sr.yhighlim = (Int64)(prng[1].y + mdlCnv_masterUnitsToUors(dDupTol));
	sr.zhighlim = (Int64)(prng[1].z + mdlCnv_masterUnitsToUors(dDupTol));

	ReinPrm prm;
	prm.edP = edP;

	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanForDuplicate, &prm);
	//status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));

	mdlScanCriteria_addSingleElementTypeTest(scP, tp);

	status = mdlScanCriteria_setRangeTest(scP, &sr); // супер

	if (re.getElmFromElement(&edP->el, mrP) == SUCCESS)
		mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);

	//if (readReinBarFromElement(&rb, edP, FALSE) == SUCCESS)
	//	mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinBar);

	//if (readReinSpaceFromElmd(&rs, edP, FALSE) == SUCCESS)
	//	mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinSpace);

	status = mdlScanCriteria_setModel (scP, mrP);
	status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);

	mdlScanCriteria_free (scP);

	reP->bTransientInProgress = FALSE;

	if (pScanCriteria && dlgProgressP)
	{
		elemIterCount3++;
		mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)(((double)elemIterCount3 / (double)elemCount3) * 100.));
		WaitMessage();
	}


	return SUCCESS;
}

//////////////////////
// command DUPS
void checkDuplicates(int view)
{

	ScanCriteria    *scP = NULL;
	UShort          typeMask[6];
	int status;

	elemCount = 0;
	
	int bClash = TRUE;
	
	for (UShort a = 0; a < 6; a++) typeMask[a] = 0;
	//for (UShort a = 0; a < 6; a++) typeMask[a] = 0;
    typeMask[0] = TMSK0_LINE | TMSK0_ARC | TMSK0_LINE_STRING | TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;


	elemIterCount3 = 0;
	elemCount3 = 0;

	dlgProgressP = mdlDialog_completionBarOpen(L("Проверка на коллизии..."));

	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanCheckDuplicateCount, 0);
	status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
	mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
	status = mdlScanCriteria_setViewRangeTest(scP, view, ACTIVEMODEL);
	status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
	status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
	status = mdlScanCriteria_free(scP);

	ReinPrm prm;
	prm.ival[0] = bClash;

	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType (scP,MSSCANCRIT_ITERATE_ELMDSCR,FALSE,TRUE);
	status = mdlScanCriteria_setElmDscrCallback (scP, (PFScanElemDscrCallback)scanCheckDuplicate, &prm);
	status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
	mdlXML_addXMLFragmentAttachmentScanTest (scP, &appID, &appTypeReinElm);
	status = mdlScanCriteria_setViewRangeTest(scP, view, ACTIVEMODEL);
	status = mdlScanCriteria_setModel (scP, ACTIVEMODEL);
	status = mdlScanCriteria_scan (scP,NULL,NULL,NULL);
	status = mdlScanCriteria_free (scP);

	
	if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);

	WCH stxt[1000];
	SPRN(stxt, L("Завершено. Найдено коллизий: %I64u, дубликатов стержней: %u"), mapClash.size(), elemCount);
	mdlDialog_openMessageBox(DIALOGID_MsgBoxOK, stxt, MSGBOX_ICON_INFORMATION);


}


////////////////////////////////////
int scanPlotSchCells(
MSElementDescr  *edP,
void*        prm,
ScanCriteria    *pScanCriteria
)
{

	MSElementDescr* edp = NULL;

	mdlElmdscr_duplicate(&edp, edP);

	mdlElmdscr_addByModelRef(edp, mrPlot);

	mdlElmdscr_freeAll(&edp);

	return SUCCESS;
}

/////////////////////////
void checkBarsSetElem(
MSElementDescr*       edP)
{
	if (edP == NULL) return;


	UShort app[2];

	if (mdlXMLElement_getAppInfo(&app[0], &app[1], &edP->el) == SUCCESS)
	{
		if (app[0] == appID && (app[1] == appTypeBarSet))
		{
			//reloadHidingPositions();

			ELID eid = 0;
			UInt32 ref = 0;
			int refcnt = 0;
			//UInt32 aref[MAX_REFNUM_PATH];
			deque <UInt32> aref;
			int inum = 0;
			int set = 0;

			XMLFragmentListP oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

			if (oXMLFragmentList)
			{
				XMLFragmentP        pXMLFragment;
				MSWCH* wtxt;
				//char ctxt[1500];
				pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

				if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
				{
					wstring wstr(wtxt);

					setstr.clear();

					if (readFromString(__FUNCTION__, &setstr, wstr,
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//						L'|'
//#else
						L"|"
//#endif
					) == SUCCESS)
					{
						SETSTR_BEGIN_ITER;
						IF_IT
							set = _wtoi(it->c_str());

						IF_IT_nxt
						IF_IT
							inum = _wtoi(it->c_str());

						IF_IT_nxt
						IF_IT
							ref = wcstoul(it->c_str(), 0, 0);

						IF_IT_nxt
						IF_IT
						{
							if (swscanf(it->c_str(), L"%I64u", &eid) != 1) return;
						}

						// VERSION 2
						IF_IT_nxt
						while (it != setstr.end() && refcnt < MAX_REFNUM_PATH)
						{
							//aref[refcnt] = wcstoul(it->c_str(), 0, 0);
							//refcnt++;
							UInt32 rn = wcstoul(it->c_str(), 0, 0);
							aref.push_back(rn);
							++it;
						}
					}

					mdlXMLFragmentList_free(&oXMLFragmentList);
				}

				//mdlCnv_convertUnicodeToMultibyte(wtxt, -1, ctxt, 1500);

				/*

				char seps[]   = "|";
				char *token;

				token = strtok( ctxt, seps );
				if (token != NULL)	set = atol(token);

				token = strtok( NULL, seps );
				if (token != NULL)	inum = atol(token);

				token = strtok( NULL, seps );
				if (token != NULL)	ref = atol(token);

				token = strtok( NULL, seps );
				if (token == NULL) return;
				if (sscanf(token, "%I64u", &eid) != 1) return;

				// VERSION 2
				token = strtok( NULL, seps );
				while(token && refcnt < MAX_REFNUM_PATH)
				{
					if (token != NULL)	
					{
						aref[refcnt] = atol(token);
						refcnt++;
					}
					token = strtok( NULL, seps );
				}

				*/

				//while (token && aref.size() < MAX_REFNUM_PATH)
				//{
				//	if (token != NULL)
				//	{
				//		UInt32 v = atol(token);
				//		//aref.push_back(v);
				//		aref.insert(aref.begin(), v); // вставляем в начало -- для совместимости, так как традиционно родители были справа, и сохраняются тоже в таком порядке
				//	}
				//	token = strtok(NULL, seps);
				//}

				ReinModel* rmP = NULL;

				if (!aref.empty())
					rmP = curRM->getRM(aref);
				else
					rmP = curRM;


				for (map<UInt32, ReinElm>::iterator it = rmP->mapElms.begin(); it != rmP->mapElms.end(); ++it)
				//for (UInt32 i = 0; rmP && i < rmP->vecElms.size(); i++)
				{
					ReinElm* reP = &(it->second);

					if (reP)
					{
						if (inum == reP->bel.inum && eid == reP->bel.elemid)
						{
							//if (set > 0)
							//	reP->drwopt[0] = set + BARSET_GAP;
							//else
								reP->drwopt[0] = 0; // не совсем правильно, надо брать значение из предыдущего состояния элемента...

							MSElementDescr* edp = NULL;
							mdlElmdscr_read(&edp, reP->bel.ffpos[REIN_ELEM_ISO], reP->bel.modrefP, 0, 0);
							if (edp)
							{
								RedrawElems redr;
								redr.SetDrawMode (DRAW_MODE_Normal);
								redr.SetDrawPurpose (DRAW_PURPOSE_ForceRedraw);
								//redr.SetOneView(tcb->lstvw);
								//redr.SetSearchRefs((Bentley::Ustn::RedrawSearchRefs)2);
								redr.DoRedraw(edp);
								mdlElmdscr_freeAll(&edp);
							}
						}
					}
				}
			}
		}
	}

}




///////////////
// sync access strings in DLG_PRESENT according current ref
void syncShowInfo()
{
	//UInt32 rn = rDopInfo.dopopt[14];

	//if (rn < 0) return;

	wstring refpath = getCurRefShowPath();

	ReinModel* rmP = curRM->getRM(refpath);

	if (rmP == NULL)
	{
		//rDopInfo.dopopt[14] = 0;
		rmP = curRM;
		refpath = L"0";
		//rn = 0;
	}


	getShowInfo2();

	ReinInfoRef* rirP = rmP->getRefPrefs();

	if (rirP) copyRefPrefsFromRef(&rInfo, rirP);

	MSDLGP dbP = mdlDialog_find (DLG_PRESENT, NULL);
	if (dbP == NULL) return; 

	mdlDialog_itemsSynch(dbP);

	DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, OPTIONBUTTONID_LineStyles, 0);
	if (diP)
	{
		mdlDialog_itemSynchByTypeAndId(dbP, RTYPE_OptionButton, OPTIONBUTTONID_LineStyles);

		mdlDialog_itemSetEnabledState(dbP, diP->itemIndex, rInfo.option[3], TRUE);

		mdlDialog_itemDraw(dbP, diP->itemIndex);
	}


	diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_PushButton, 6, 0);
	if (diP == NULL) return; 

	//if (rDopInfo.dopopt[14] < 0) 
	//	mdlDialog_itemSetEnabledState(dbP, diP->itemIndex, FALSE, TRUE);


	if (refpath == L"0")
	{
		//if (rmP->arRefPrefs)
		//	mdlDialog_itemSetEnabledState(dbP, diP->itemIndex, TRUE, TRUE);
		//else
			mdlDialog_itemSetEnabledState(dbP, diP->itemIndex, FALSE, TRUE);
	}
	else
	{
		if (rmP->refPrefsP)
			mdlDialog_itemSetEnabledState(dbP, diP->itemIndex, TRUE, TRUE);
		else
			mdlDialog_itemSetEnabledState(dbP, diP->itemIndex, FALSE, TRUE);
	}


}


//////////////////////////////////////////////////////
int scanCheckShowInfo2(
MSElementDescr  *edP,
ReinPrm*       prmP,
ScanCriteria    *pScanCriteria
)
{
	int res;
	int refn = 0;
	wstring sRefPath = L"0";
	wstring sRefPathIn = L"0";

	bool bReport = false;
	bool bDelete = false;

	if (prmP)
	{
		sRefPathIn = prmP->wstr;

		if (prmP->ival[0]) bReport = true;
		//if (refnin == -2) // приоритет чтения активной модели, устар., см getShowInfo2
		if (prmP->bDel) bDelete = true; // reset show settings (ref > 0 or active == 0)
	}
	else
	{
		// прочитать настройки активной модели
	}



	XMLFragmentListP  oXMLFragmentList = NULL;

	UInt32 fp = mdlElmdscr_getFilePos(edP);

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);



	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		wstring wstr = L"";
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstr = wtxt;
			mdlXMLFragmentList_free(&oXMLFragmentList);
		}
		else
			return SUCCESS; // continue scan

		if (bReport) // only report
		{
			WCH ctxt[500];
			SCPW2M(ctxt, wstr.c_str(), 500);
			mdlDialog_dmsgsPrint(ctxt);
			return SUCCESS;
		}


		setstr.clear();


//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//		wchar_t wsep = L'|';
//#else
		wchar_t wsep[5] = L"|\0\0";
//#endif

		if (readFromString(__FUNCTION__, &setstr, wstr, wsep) == SUCCESS)
		{
			SETSTR_BEGIN_ITER; // 1

			IF_IT
			{
				refn = _wtoi(it->c_str());

				if (refn < 0) refn = -refn;	else refn = 0;
			}
			else
			{
				refn = 0;
			}

			IF_IT_nxt // token = STOK(NULL, seps); // 2

			IF_IT_nxt // token = STOK(NULL, seps); // 3
			IF_IT sRefPath = it->c_str();

			if (refn > 0 && sRefPath == L"0") // legacy
			{
				MSWCH srf[10];
				_swprintf(srf, L"%i", refn);
				sRefPath = srf;
			}

			//====================================
			ReinModel* rmP = curRM->getRM(sRefPath);
			//====================================

			// удаление (также перед сохранением)
			if (bDelete 
				&& sRefPath == sRefPathIn
				) 
			{
				res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos(edP->h.elementRef), FALSE);

				if (rmP && sRefPath != L"0") // не сбрасывать настройки референсов если изменение идет для активной модели
				{
					rmP->delRefPrefs(-1);
				}

				return SUCCESS;
			}

			if (rmP)
			{
				if (rmP->refPrefsP == NULL) rmP->refPrefsP = &rmP->refPrefs;
				rmP->refPrefsP->clear();

				copyRefPrefsToRef(rmP->refPrefsP, &rInfo);

				//rmP->refPrefsP->riropt[2] = TRUE;
				rmP->refPrefsP->riropt[4] = TRUE;
				rmP->refPrefsP->riropt[5] = TRUE;

				//IF_IT_nxt // token = STOK(NULL, seps); // 2
				//IF_IT_nxt // token = STOK(NULL, seps); // 3

				IF_IT_nxt IF_IT
					rmP->refPrefsP->riropt[1] = _wtoi(it->c_str()); // rmP->refPrefsP->riropt[1] = STOI(token);	//4

				IF_IT_nxt IF_IT
					rmP->refPrefsP->riropt[17] = _wtoi(it->c_str()); // rmP->refPrefsP->riropt[17] = STOI(token);	//5

				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[18] = _wtoi(it->c_str());	//6
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[DISP_S] = _wtoi(it->c_str());	//7
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[9] = _wtoi(it->c_str());	//8
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[10] = _wtoi(it->c_str());	//9
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[8] = _wtoi(it->c_str());	//10
				IF_IT_nxt IF_IT rmP->refPrefsP->ends = _wtoi(it->c_str());		//11
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[DISP_X] = _wtoi(it->c_str());	//12
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[DISP_O] = _wtoi(it->c_str());	//13
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[15] = _wtoi(it->c_str());	//14
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[19] = _wtoi(it->c_str());	//15
				IF_IT_nxt IF_IT rmP->refPrefsP->threads = _wtoi(it->c_str());		//16
				IF_IT_nxt IF_IT rmP->refPrefsP->bface = _wtoi(it->c_str());		//17
				IF_IT_nxt IF_IT rmP->refPrefsP->lim = _wtoi(it->c_str());			//18
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[12] = _wtoi(it->c_str());	//19
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[3] = _wtoi(it->c_str());	//20
				IF_IT_nxt IF_IT rmP->refPrefsP->riropt[6] = _wtoi(it->c_str());	//21

				//rmP->refPrefsP->prefrefn = refn; // rmP->rnum, rmP->prnum
			}
		}





		/*

		WCH seps[]   = L("|");
		WCH *token;

		token = STOK( ctxt, seps );	if (token != NULL)	refn = STOI(token);	//1

		if (refn < 0) refn = -refn;	else refn = 0;


		ReinModel* rmP = curRM->getRM(refn);

		if (prmP && *prmP == refn) // удаление (также перед сохранением)
		{
			res = mdlElmdscr_undoableDelete(edP, elementRef_getFilePos (edP->h.elementRef), FALSE);

			if (rmP) 
			{
				rmP->delRefPrefs(-1);
			}

			return SUCCESS;
		}


		if (rmP)
		{
			if (rmP->refPrefsP == NULL) rmP->refPrefsP = &rmP->refPrefs;
			rmP->refPrefsP->clear();
			
			copyRefPrefsToRef(rmP->refPrefsP, &rInfo);

			//rmP->refPrefsP->riropt[2] = TRUE;
			rmP->refPrefsP->riropt[4] = TRUE;
			rmP->refPrefsP->riropt[5] = TRUE;

			token = STOK( NULL, seps ); // 2
			token = STOK( NULL, seps ); // 3
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[1] = STOI(token);	//4
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[17] = STOI(token);	//5
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[18] = STOI(token);	//6
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[11] = STOI(token);	//7
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[9] = STOI(token);	//8
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[10] = STOI(token);	//9
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[8] = STOI(token);	//10
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->ends = STOI(token);		//11
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[14] = STOI(token);	//12
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[13] = STOI(token);	//13
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[15] = STOI(token);	//14
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[19] = STOI(token);	//15
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->threads = STOI(token);		//16
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->bface = STOI(token);		//17
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->lim = STOI(token);			//18
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[12] = STOI(token);	//19
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[3] = STOI(token);	//20
			token = STOK( NULL, seps );	if (token != NULL)	rmP->refPrefsP->riropt[6] = STOI(token);	//21

			rmP->refPrefsP->prefrefn = refn; // rmP->rnum, rmP->prnum
		}
		*/

		elemIterCount2++;

		// приоритет чтения активной модели, устар., см getShowInfo2
		//if (prmP && *prmP == -2 && refn == 0)
		//{
		//	return 1; // break scan
		//}


	}
	else // MDLERR_LINKAGENOTFOUND
		return SUCCESS; // continue scan

	return SUCCESS;
}


/////////////////////////////
int getShowInfo2()
{

	ScanCriteria    *pScanCriteria;
	int status;
	//int prm = -2; // для того чтобы сначала прочитать настройки активного файла, а потом референсов

	elemIterCount2 = 0;

	curRM->delRefPrefs(-1);

	curRM->refPrefsP = &curRM->refPrefs;
	curRM->refPrefsP->clear();

	copyRefPrefsToRef(curRM->refPrefsP, &rInfo);


	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckShowInfo2, NULL);
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeShowInfo);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);


	return SUCCESS;

}

////////////////////
void copyRefPrefsFromRef(ReinInfo* riP, ReinInfoRef* rirP)
{
	//for (int i = 0; i < 20; i++)
	//{
	//	riP->option[i] = rirP->riropt[i];
	//}

	if (riP == NULL) return;
	if (rirP == NULL) return;

	riP->option = rirP->riropt;

	//riP->option[1] = rirP->riropt[1];
	//riP->option[2] = rirP->riropt[2];
	//riP->option[3] = rirP->riropt[3];
	//riP->option[4] = rirP->riropt[4];
	//riP->option[5] = rirP->riropt[5];
	//riP->option[6] = rirP->riropt[6];
	////riP->option[7] = rirP->riropt[7];
	//riP->option[8] = rirP->riropt[8];
	//riP->option[9] = rirP->riropt[9];
	//riP->option[10] = rirP->riropt[10];
	//riP->option[DISP_S] = rirP->riropt[DISP_S];
	//riP->option[12] = rirP->riropt[12];
	//riP->option[DISP_O] = rirP->riropt[DISP_O];
	//riP->option[DISP_X] = rirP->riropt[DISP_X];
	//riP->option[15] = rirP->riropt[15];
	////riP->option[16] = rirP->riropt[16];
	//riP->option[17] = rirP->riropt[17];
	//riP->option[18] = rirP->riropt[18];
	//riP->option[19] = rirP->riropt[19];


	riP->ends = rirP->ends;
	riP->threads = rirP->threads;
	riP->bface = rirP->bface;
	riP->lim = rirP->lim;
}


////////////////////
void copyRefPrefsToRef(ReinInfoRef* rirP, ReinInfo* riP)
{

	if (riP == NULL) return;
	if (rirP == NULL) return;

	//for (int i = 0; i < 20; i++)
	//{
	//	rirP->riropt[i] = riP->option[i];
	//}

	rirP->riropt = riP->option;

	//rirP->riropt[1] = riP->option[1];
	//rirP->riropt[2] = riP->option[2];
	//rirP->riropt[3] = riP->option[3];
	//rirP->riropt[4] = riP->option[4];
	//rirP->riropt[5] = riP->option[5];
	//rirP->riropt[6] = riP->option[6];
	////rirP->riropt[7] = riP->option[7];
	//rirP->riropt[8] = riP->option[8];
	//rirP->riropt[9] = riP->option[9];
	//rirP->riropt[10] = riP->option[10];
	//rirP->riropt[DISP_S] = riP->option[DISP_S];
	//rirP->riropt[12] = riP->option[12];
	//rirP->riropt[DISP_O] = riP->option[DISP_O];
	//rirP->riropt[DISP_X] = riP->option[DISP_X];
	//rirP->riropt[15] = riP->option[15];
	////rirP->riropt[16] = riP->option[16];
	//rirP->riropt[17] = riP->option[17];
	//rirP->riropt[18] = riP->option[18];
	//rirP->riropt[19] = riP->option[19];

	rirP->ends = riP->ends;
	rirP->threads = riP->threads;
	rirP->bface = riP->bface;
	rirP->lim = riP->lim;
}


///////////////////////////////////////////////////////////////////////////////////
void saveShowInfo2(ReinInfo* riCopyFromP)
{

	writeLogIn(__FUNCTION__, 0);

	MSElementDescr* pXmlFragmentElement = NULL; 
	XMLFragmentListP pCurrent = NULL; 
	MSWCH wstr[500];
	//WCH str[500];

	wstring sRefPath = getCurRefShowPath();

	ReinModel* rmP = curRM->getRM(sRefPath);
	if (rmP == NULL) return;

	ScanCriteria    *pScanCriteria;
	int status;

	ReinPrm prm;
	prm.bDel = 1;
	prm.wstr = sRefPath;

	// удаление перед сохранением
	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria,MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanCheckShowInfo2, &prm);
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	mdlXML_addXMLFragmentElementScanTest (pScanCriteria, &appID, &appTypeShowInfo);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);



	if (rmP->refPrefsP == NULL)
	{
		rmP->refPrefsP = &rmP->refPrefs;
		rmP->refPrefsP->clear();
	}

	ReinInfoRef* rirP = rmP->refPrefsP;

	if (riCopyFromP) copyRefPrefsToRef(rmP->refPrefsP, riCopyFromP);

	//rInfo.option[2]	"Образующий элемент контура армирования"
	//rInfo.option[4]	"Образующий элемент отдельного стержня"
	//rInfo.option[5]	"Производный элемент (ось стержня)"


	_swprintf(wstr, L"%i|%i|%s|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i",
				0, // -refn,			// 1
				0, // -refnn,			// 2
				sRefPath.c_str(),		// 3
				rirP->riropt[1],		// 4	//rInfo.option[1]	"Внутренние (прозрачные) стержни контура"
				rirP->riropt[17], 		// 5	//rInfo.option[17]	"Внутренние стержни для сечений"
				rirP->riropt[18], 		// 6	//rInfo.option[18]	"Невидимые стержни пунктиром"
				rirP->riropt[DISP_S], 	// 7	//rInfo.option[11]	"Сечения стержней"
				rirP->riropt[9], 		// 8	//rInfo.option[9]	"Реальный диаметр сечения"
				rirP->riropt[10], 		// 9	//rInfo.option[10]	"Контуры объёма стержня"
				rirP->riropt[8], 		// 10	//rInfo.option[8]	"Загибы"
				rirP->ends, 			// 11	//rInfo.ends		"Засечки"
				rirP->riropt[DISP_X], 	// 12	//rInfo.option[14]	"Крестики"
				rirP->riropt[DISP_O], 	// 13	//rInfo.option[13]	"Нолики"
				rirP->riropt[15], 		// 14	//rInfo.option[15]	"Номера позиций"
				rirP->riropt[19],		// 15	//rInfo.option[19]	"Цвет элемента по диаметру"
				rirP->threads,			// 16	//rInfo.threads "Резьба"
				rirP->bface,			// 17	//rInfo.bface
				rirP->lim,				// 18	//rInfo.lim	"Стрелки"
				rirP->riropt[12],		// 19
				rirP->riropt[3],		// 20   // show only CCGG bars
				rirP->riropt[6]			// 21   // not CCGG line style
				);

	//status = mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 500);

	pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeShowInfo); 

	status = mdlXMLFragmentList_createXMLElementDescriptor  (&pXmlFragmentElement, &pCurrent, FALSE); 

	if (NULL != pXmlFragmentElement) 
	{ 
		UInt32 fp;

		fp = mdlElmdscr_add (pXmlFragmentElement); 
		mdlElmdscr_freeAll (&pXmlFragmentElement); 

		mdlXMLFragmentList_free(&pCurrent);
	} 

	writeLogOut(__FUNCTION__, 0);

}



////////////////////////////////////////////
void createOptionShow()
{

	MSDLGP dbP = mdlDialog_find (DLG_PRESENT, NULL);

	if (dbP == NULL) return;

	DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, OPTIONBUTTONID_PresOpt, 0);

	if (diP == NULL) return;


	mdlDialog_optionButtonDeleteAll(diP->rawItemP);

	//UInt32 val = -1;
	//mdlDialog_optionButtonInsertItem("общие настройки", 0, 0, 0, &val, 0, 0, 0, diP->rawItemP, -1);

	UInt32 val = 0;
	mdlDialog_optionButtonInsertItem(TXT_60, 0, 0, 0, &val, 0, 0, 0, diP->rawItemP, -1);

	{
		ModelRefIteratorP  iterator;
		DgnModelRefP	modelRef;

		mdlModelRefIterator_create (&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, -1); // nested unlimited

		while (NULL != (modelRef = mdlModelRefIterator_getNext (iterator)))
		{

			DgnAttachmentP rfP = mdlRefFile_getInfo(modelRef);
			if (rfP == NULL) continue;

			ReinModel* rmP = curRM->getRM(modelRef);
			if (rmP == NULL) continue;

			if (rmP->elcount == 0) continue;

			val = getRefNum(modelRef);

			WCH sref[1000];
			WCH sreftxt[1000];

			SCPW2M(sref, rmP->getRefPathString().c_str(), MAX_MODEL_NAME_LENGTH);

			SPRN(sreftxt, L("[%s] \0\0"), sref);

			SCPW2M(sref, REFLOGICAL(rfP), MAX_MODEL_NAME_LENGTH);

			SCAT(sreftxt, sref);

			mdlDialog_optionButtonInsertItem(sreftxt, 0, 0, 0, &val, 0, 0, 0, diP->rawItemP, -1);
		}

		mdlModelRefIterator_free (&iterator);

	}

	mdlDialog_itemSynchByTypeAndId(dbP, RTYPE_OptionButton, OPTIONBUTTONID_PresOpt);
	mdlDialog_itemDraw(dbP, diP->itemIndex);


}

////////////////////////////////////////////////////
void setPosition(ReinPos* rpP, ReinElm* relmP, ReinModel* rmP, int dirout)
{

	writeLogIn(__FUNCTION__, 0);

	double len_with_lap = relmP->bel.length;
	ReinLap* rlP = getReinLap(relmP->bel.diam);
	int lapqty = 0;
	int mqty[2] = {0,0};

	if (relmP->bel.term[0] == REIN_TERM_MUFT) mqty[0]++;
	if (relmP->bel.term[1] == REIN_TERM_MUFT) mqty[0]++;

	//if (relm.bel.term[0] == REIN_TERM_SKOB) mqty++;
	//if (relm.bel.term[1] == REIN_TERM_SKOB) mqty++;

		
	//if (relmP->bel.diam == 32)
	//{
	//	SPRN(s, L(""));
	//}

	//bool bSwap = rmP->bRefPlus;
	//if (rmP->bRefPlus) rmP = curRM; // swap models

	if (rlP)
	{
		if (rlP->muft)
		{
			mqty[1] += (int)floor((relmP->bel.length - iCfgVar_MuftTol) / (double)rlP->maxlen); // 11700.1
		}
		else
		{
			lapqty = (int)ceil((relmP->bel.length - (double)rlP->maxlen) / (double)(rlP->maxlen - rlP->lapValue));
			if (lapqty < 0) lapqty = 0;
			lapqty += relmP->bel.ilaps;
			len_with_lap += lapqty * rlP->lapValue;
		}
	}


	ReinPos rp;

	bool bSave = false;
		
	if (rpP == NULL) // новая позиция
	{
		// проверка на изменение
		if (iModePosCatch)
		{
			long pnum_save = 0;

			RelmPair m_pair = make_pair(relmP->bel.elemid, relmP->bel.inum);
			map<RelmPair, ReinPos>::iterator it = mapPosMem.find(m_pair);
			if (it != mapPosMem.end()) // found
			{
				ReinPos pos = it->second;

				for (map<long, ReinPos>::iterator itt = rmP->getPosMap().begin(); itt != rmP->getPosMap().end(); ++itt)
				{
					if (barsEqual(&pos.bar, &(itt->second.bar), &dirout))
					{
						itt->second.bar_mem = pos.bar; // запоминаем старый диаметр

						pnum_save = itt->second.bar.pnum; // must be == pnum

						itt->second.bar = relmP->bel; // назначаем в позицию
						itt->second.bar.pnum = pnum_save;

						bSave = true;

						rpP = &(itt->second);

						relmP->bel.pnum = rpP->bar.pnum;

						relmP->elemflags |= REINEL_FLAG_CTCH; // mark

						rpP->file_qty_p = 0;

						break;
					}
				}
			}

			if (rpP && bSave)
			{
				
				MSDLGP pDb = NULL;
				DialogItem* pListBoxItem = NULL;
				ListModel* pListModel = NULL;
				int rowI, colI;

				pDb = mdlDialog_find(DLG_POSLIST, NULL);
				if (pDb) pListBoxItem = mdlDialog_itemGetByTypeAndId(pDb, RTYPE_ListBox, 1, 0);
				if (pListBoxItem) pListModel = mdlDialog_listBoxGetListModelP(pListBoxItem->rawItemP);

				for (int i = 0; pListModel && i < mdlListModel_getRowCount(pListModel); i++)
				{
					ListRow* pListRow = mdlListModel_getRowAtIndex(pListModel, i);
					if (mdlListRow_getStatus(pListRow) == LISTCELLATTR_DISABLED)  continue;

					ListCell* pListCell = mdlListModel_getCellAtIndexes(pListModel, i, REIN_LISTB_POSN);
					long ii = myListCell_getInfoFieldInt32(pListCell, 0, &gst);

					if (gst != SUCCESS) continue;

					if (pnum_save == ii)
					{
						ListCell* pCell = NULL;
						IcnRsc* irsc = NULL;

						pCell = mdlListRow_getCellAtIndex(pListRow, REIN_LISTB_SAVE);

						if (rfRein) irsc = (IcnRsc*)mdlResource_load(rfRein, RTYPE_Icon, 16);

						if (irsc && pCell)
						{
							mdlListCell_setIconRsc(pCell, irsc);
							mdlListCell_setInfoFieldInt32(pCell, 0, 1); // 1 - flag to save for REIN_LISTB_SAVE
							//mdlDialog_listBoxMakeRowVisible(pListBoxItem->rawItemP, i);
							mdlDialog_listBoxDrawContents(pListBoxItem->rawItemP, i, REIN_LISTB_SAVE);
						}

						if (irsc) mdlResource_free(irsc);
					}
				}
				
				//savePosition(rpP, TRUE, TRUE);
			}

		}
	}


	if (rpP == NULL) // новая позиция
	{
		rpP = &rp;

		rpP->bar = relmP->bel;

		rpP->bar.term[0] = getTrueEnd(&rpP->bar, 0);
		rpP->bar.term[1] = getTrueEnd(&rpP->bar, 1);

		rpP->bar.pnum = 0; // сброс номеров которые уже проставлены на массиве arCurElms

		rpP->pdID = 1; // Арматура!

		if (iDebug) sprintf(sLogMes, "push new position...\n"); writeLog(0, 0, 0, 1);

		CatInfo& poscat = rmP->getCat();

		//===================================
		poscat.arCurPos.insert(pair<long, ReinPos>(poscat.iPosIndex, *rpP));
		//===================================

		rpP = &(poscat.arCurPos[poscat.iPosIndex]);

		poscat.iPosIndex--; // iPosIndex < 0

		if (iDebug) sprintf(sLogMes, "pos qty == %u\n", (UInt32)rmP->getPosMap().size()); writeLog(0, 0, 0, 1);

	}


	//if (rpP->bar.pnum == 25)
	//	int a = 0;

	rpP->file_qty_p++;

	if (iDebug) sprintf(sLogMes, "POSITION: number  %i,  file_qty_p == %i\n", rpP->bar.pnum, rpP->file_qty_p); writeLog(0, 0, 0, 1);

	//int i = 0;
	int i = relmP->bel.numpts - 1;

	rpP->cmppt.x = (Int32)roundExt( mdlCnv_uorsToMasterUnits(relmP->bel.rpts[i].x), ROUND_STD);
	rpP->cmppt.y = (Int32)roundExt( mdlCnv_uorsToMasterUnits(relmP->bel.rpts[i].y), ROUND_STD);
	rpP->cmppt.z = (Int32)roundExt( mdlCnv_uorsToMasterUnits(relmP->bel.rpts[i].z), ROUND_STD);

	if (mdlModelRef_isActiveModel(relmP->bel.modrefP)
		//|| bSwap
		)
	{
		rpP->file_qty_rm += len_with_lap / 1000.; // mm to m

		rpP->lap_qty += lapqty;
		rpP->muft_qty[0] += mqty[0];
		rpP->muft_qty[1] += mqty[1];
	}
	else
		rpP->file_qty_rm += relmP->bel.length / 1000.; // mm to m



	{
		if (relmP->bel.noplanar == 1) rpP->bar.noplanar = 1;

		// радиусы загибов
		rpP->bar.brad = relmP->bel.brad;

		// углы загибов
		rpP->bar.bang = relmP->bel.bang;

		if (rpP->bar.numlen == 0)
		{
			rpP->bar.numlen =  relmP->bel.numlen;

			int j = 0;
			if (dirout == -1) j = rpP->bar.numlen - 1;
			
			for (int ii = 0; ii < rpP->bar.numlen; ii++)
			{
				rpP->bar.blen[ii][0] = relmP->bel.blen[j][0]; // min
				rpP->bar.blen[ii][1] = relmP->bel.blen[j][1]; // mid
				rpP->bar.blen[ii][2] = relmP->bel.blen[j][2]; // max

				if (dirout == -1) j--; else j++;
			}
		}
		else if (rpP->bar.runmet > 1) // перем длина
		{
			int j = 0;
			if (dirout == -1) j = rpP->bar.numlen - 1;
			
			for (int ii = 0; ii < rpP->bar.numlen; ii++)
			{
				// минимальное значение
				if (rpP->bar.blen[ii][0] > relmP->bel.blen[j][0]) 
					rpP->bar.blen[ii][0] = relmP->bel.blen[j][0]; // min
				
				// добавление в сумму идет только со второго стержня
				if (rpP->file_qty_p > 1) 
					rpP->bar.blen[ii][1] += relmP->bel.blen[j][1];

				// максимальное значение
				if (rpP->bar.blen[ii][2] < relmP->bel.blen[j][2]) 
					rpP->bar.blen[ii][2] = relmP->bel.blen[j][2]; // max

				if (dirout == -1) j--; else j++;
			}
		}

	}

	writeLogOut(__FUNCTION__, 0);
}

//////////////////////////////////////////
int sortReinPos(ReinPos* rp1, ReinPos* rp2) // Not Using
{

	writeLogIn(__FUNCTION__, 0);

	if (rp1->bar.pnum < rp2->bar.pnum) 
		return -1;
	else if (rp1->bar.pnum > rp2->bar.pnum) 
		return 1;
	else
	{
		if (rp1->bar.diam < rp2->bar.diam)
			return -1;
		else if (rp1->bar.diam > rp2->bar.diam)
			return 1;
	}
	
	writeLogOut(__FUNCTION__, 0);

	return 0;

}

////////////////////////////////////////////
// func: get possitions map
map<long, ReinPos>& ReinModel::getPosMap(ReinElm* reP)
{

	//writeLogIn(__FUNCTION__, 0);

	CatInfo& poscat = getCat(reP);

	//if (!catPosXml.arCurPos.empty())
	//{
	//	return catPosXml.arCurPos;
	//}

	//if (iCfgVar_PosListMerge && mrci.catID > 0)
	//{
	//	map <UInt32, CatInfo>::iterator it = mapCats.find(mrci.catID);
	//	if (it != mapCats.end()) // found
	//	{
	//		return it->second.arCurPos;
	//	}
	//}


	return poscat.arCurPos;
}

////////////////////////////////////////////
// func: get possitions map
CatInfo& ReinModel::getCat(ReinElm* reP)
{

	//writeLogIn(__FUNCTION__, 0);

	if (!catPosXml.arCurPos.empty())
	{
		return catPosXml;
	}


	if (iCfgVar_PosListMerge && mrci.catID > 0)
	{

		if (reP && reP->relmLevName.length() > 0)
		{
			for (map <UInt32, CatInfo>::iterator itt = mapCats.begin(); itt != mapCats.end(); ++itt)
			{
				if (!itt->second.dqlvnm.empty() && itt->second.catID == mrci.catID)
				{
					for (deque <wstring>::iterator itstr = itt->second.dqlvnm.begin(); itstr != itt->second.dqlvnm.end(); ++itstr)
					{
						if (*itstr == reP->relmLevName)
						{
							MSWCH sspc[1000];

							SCPM2W(sspc, itt->second.catname, 1000);

							reP->relmSpecName = sspc;

							return itt->second;
							break;
						}
					}
				}
			}
		}
		else
		{
			map <UInt32, CatInfo>::iterator it = mapCats.find(mrci.catID);

			if (it != mapCats.end()) // found
			{
				//writeLogOut(__FUNCTION__, 0);

				return it->second;
			}

		}

	}

	//writeLogOut(__FUNCTION__, 0);

	return mrci;
}


///////////////////////////////////////
// func: update elements position numbers
void ReinModel::updateModelElmNumbers(bool bSkipIfLot, map<long, ReinPos>* arCurPosP)
{

	writeLogIn(__FUNCTION__, 0);

	bool bBarLoc = false;
	bool bRedir = false;


	long i = 0;
	if (dlgProgressP == NULL && mapElms.size() > 10000 
		//&& getPosMap().size() > 300
		)
	{
		if (bSkipIfLot) return;
			
		dlgProgressP = mdlDialog_completionBarOpen(L("Обновление номеров позиций в модели"));

		bBarLoc = true;
	}

	if (arCurPosP)
	{
		bBarLoc = false;
	}
	else // arCurPosP == NULL
	{
		//arCurPosP = &getPosMap();
		bRedir = true;
	}


	for (map<UInt32, ReinElm>::iterator it = mapElms.begin(); it != mapElms.end(); ++it)
	{
		ReinElm* reP = &(it->second);
		int dirout = 0;

		if (bRedir)
		{
			CatInfo& poscat = getCat(reP);
			arCurPosP = &(poscat.arCurPos);
		}

		for (map<long, ReinPos>::iterator itt = arCurPosP->begin(); itt != arCurPosP->end(); ++itt)
		{
			ReinPos* rpItP = &itt->second;

			if (barsEqual(&reP->bel, &rpItP->bar, &dirout))
			{
				reP->bel.pnum = rpItP->bar.pnum;
				reP->arNum = itt->first;

				if (rpItP->bar_mem.diam > 0 && arCurPosP == NULL)
					reP->elemflags |= REINEL_FLAG_CTCH;
				else
					reP->elemflags &= !REINEL_FLAG_CTCH;


				break;
			}
			else
			{
				reP->bel.pnum = 0;
				reP->arNum = 0;
			}
		}

		int sz = (int)mapElms.size();
		if (bBarLoc && dlgProgressP && sz)
		{
			mdlDialog_completionBarUpdate(dlgProgressP, 0, i * 100 / sz);
			WaitMessage();
			i++;
		}

	}


	//for (map<UInt32, ReinModel>::iterator it = arMrP.begin(); it != arMrP.end(); ++it)
	//{
	//	if (it->second.bRefPlus)
	//	{
	//		it->second.updateModelElmNumbers(bSkipIfLot, arCurPosP);
	//	}
	//}




	if (bBarLoc && dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);

	writeLogOut(__FUNCTION__, 0);


}


//////////////////////////////////////////////////////
int scanFindBars(
	MSElementDescr* edP,
	ReinPrm* prmP,
	ScanCriteria* pScanCriteria
)
{
	ReinBar rb;

	if (readReinBarFromElement(&rb, edP, FALSE) == SUCCESS)
	{
		if (rb.bartype != BT_AXIS && rb.elemid == prmP->prmid)
		{
			prmP->uints.push_back(mdlElmdscr_getFilePos(edP));
		}
	}


	return SUCCESS;
}


//////////////////////////////////////////////////////
int scanFindBarsSetContNum(
MSElementDescr  *edP,
ReinBar*         rbP,
ScanCriteria    *pScanCriteria
)
{
	ReinBar rb;
	

	if (readReinBarFromElement(&rb, edP, FALSE) == SUCCESS)
	{
		if (rb.bartype != BT_AXIS && rb.elemid == rbP->elemid)
		{
			if (rb.contnum > rbP->contnum) rbP->rfa[2] = rb.contnum; // max

			if (rb.contnum == rbP->contnum)
			{
				if (rbP->rfa[2] < -10000) rbP->rfa[2] = rb.contnum;
				if (rbP->rfa[0] < -10000) rbP->rfa[0] = rb.contnum;
				rbP->rfa[1] = rb.contnum; // min
			}

			if (rb.contnum < rbP->contnum) rbP->rfa[0] = rb.contnum; // min
		}
	}


	return SUCCESS;
}



/////////////////////////////////////////
long addConttNum(ReinBar* rbP)
{

	ScanCriteria    *pScanCriteria;
	int status;

	ReinBar rb = *rbP;

	rb.rfa[0] = -10010;
	rb.rfa[1] = -10010;
	rb.rfa[2] = -10010;

	pScanCriteria= mdlScanCriteria_create ();
	status = mdlScanCriteria_setReturnType (pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback (pScanCriteria, (PFScanElemDscrCallback)scanFindBarsSetContNum, &rb);
	status = mdlScanCriteria_setModel (pScanCriteria, ACTIVEMODEL);
	mdlXML_addXMLFragmentAttachmentScanTest (pScanCriteria, &appID, &appTypeReinBar);
	status = mdlScanCriteria_scan (pScanCriteria,NULL,NULL,NULL);
	status = mdlScanCriteria_free (pScanCriteria);

	if (rb.rfa[2] == rbP->contnum) // последний
	{
		rbP->contnum += 10;
		status = SUCCESS;
	}
	else if (rb.rfa[2] < rbP->contnum && rb.rfa[0] > rbP->contnum) // внутренний
	{
		rbP->contnum += 10;
		status = SUCCESS;
	}
	else if (rb.rfa[0] == rbP->contnum) // первый
	{
		rbP->contnum -= 10;
		status = SUCCESS;
	}
	else
		status = ERROR;

	return status;

}


/////////////////////////////////////////////////////////////////
int xmlAddCacheInfo(ReinElm* relmP, MSElementDescr** edpP, MSWCH* stadd, bool bClear, ReinModel* rmP)
{

	MSWCH wstr[2000];
	MSWCH* wsadd = L"";
	XMLFragmentListP    pCurrent = NULL;
	int status;
	MSElementDescr* edp;
	//ELID attid = 0;

	if (relmP == NULL) return 0;
	if (edpP == NULL) return 0;

	//if (relmP->bel.modrefP)
	//	attid = mdlModelRef_getAttachmentID(relmP->bel.modrefP);

	edp = *edpP;

	UInt32 rmid = 0;

	if (rmP) rmid = rmP->rmid;

	//_swprintf(wstr, L"REINCACHE;%i;%i",
	//	relmP->bel.diam,
	//	curPos_rn
	//);

	if (stadd != NULL)
		wsadd = stadd;

	_swprintf(wstr, L"REINCACHE;%i;%s;%d;%I64u;%u;%s",
		relmP->bel.diam,		
		curPos_refpath.c_str(),
		relmP->bel.pnum,
		relmP->bel.elemid,
		rmid,
		wsadd
		);

	//status = mdlCnv_convertMultibyteToUnicode(wstr, -1, wstr, 200);

	if (bClear) mdlXMLFragmentList_stripAllFromElement(NULL, &(edp->el));

	pCurrent = mdlXMLFragmentList_construct (wstr, NULL, appID, appTypeReinCache); 

	if (pCurrent)	status = mdlXMLFragmentList_attachToElement(&pCurrent, edpP, TRUE);

	return status;

}

//////////////////////////////////////////////////
//_swprintf(wstr, L"FILLET;%i;%i;%.5f;%i", ival[0]], ival[1], dval[0], ival[2]); // length, radius, angle, кривой
int readReinFilletFromString(ReinPrm* rpP, wstring str)
{

	if (rpP == NULL) return ERROR;

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	if (*it != L"FILLET") return ERROR;

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->ival[0] = _wtoi(it->c_str()); // length

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->ival[1] = _wtoi(it->c_str()); // radius

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->dval[0] = _wtof(it->c_str()); // angle

	IF_IT_nxt IF_IT_end return ERROR;
	rpP->ival[2] = _wtoi(it->c_str()); // кривой

	/*


	if (strncmp(str, "FILLET", 6) == 0)
	{

		char seps[] = ";";
		char* token;
		MSWCH wstr[200];

		token = strtok(str, seps);

		token = strtok(NULL, seps);
		if (token != NULL)	ilen = atol(token);

		token = strtok(NULL, seps);
		if (token != NULL)	irad = atol(token);

		token = strtok(NULL, seps);
		if (token != NULL)	dang = atof(token);

		sprintf(str, "\n\tзакругление:\n\tдлина %i\n\tрадиус %i\n\tугол %.1f", ilen, irad, dang);

		mdlCnv_convertMultibyteToUnicode(str, -1, wstr, 200);

		wcscpy(dopdescr, wstr);
		//wcscat(description, wstr);

		bFillet = TRUE;

	}
	*/



	return SUCCESS;
}


//////////////////////////////////////////////////
int readReinCacheFromString(ReinCache* rcP, wstring str)
{

	if (rcP == NULL) return ERROR;

	setstr.clear();

	if (readFromString(__FUNCTION__, &setstr, str) != SUCCESS) return ERROR;

	if (setstr.empty()) return ERROR;

	SETSTR_BEGIN_ITER;
	if (*it != L"REINCACHE") return ERROR;

	IF_IT_nxt IF_IT_end return ERROR;
	//= atoi(token);

	IF_IT_nxt IF_IT_end return ERROR;
	if (rcP) rcP->refpath = *it;

	IF_IT_nxt IF_IT_end return SUCCESS;
	rcP->pnum = wcstoul(it->c_str(), 0, 0);

	IF_IT_nxt IF_IT_end return SUCCESS;
	{
		if (swscanf(it->c_str(), L"%I64u", &rcP->elid) != 1) rcP->elid = 0;
	}

	IF_IT_nxt IF_IT_end return SUCCESS;
	{
		UInt32 rmid = wcstoul(it->c_str(), 0, 0);

		ReinModel* rmP = curRM->getRMbyID(rmid);

		if (rmP) rcP->mrP = rmP->modelP;

//		ELID atid;
//
//#if defined (MSVERSION) && (MSVERSION == 0xa00) // ref file
//		DgnAttachmentP rfP;
//#else
//		ReferenceFile* rfP;
//#endif
//
//		if (swscanf(it->c_str(), L"%I64u", &atid) != 1) atid = 0;
//
//		if (mdlRefFile_getFromAttachmentID(&rfP, &rcP->mrP, ACTIVEMODEL, atid) != SUCCESS)
//			rcP->mrP = NULL;
	}

	IF_IT_nxt IF_IT_end return SUCCESS;
	{
		wcsncpy(rcP->desc, it->c_str(), 500);
	}



/*



	WCH seps[] = L(";");
	WCH* token;

	if (str == NULL) return ERROR;
	if (SLEN(str) == 0) return ERROR;

	token = STOK(str, seps);
	if (token == NULL)	return ERROR;
	if (SCNP(token, L("REINCACHE"), SLEN(L("REINCACHE"))) != 0) return ERROR;

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	 //= atoi(token);

	token = STOK(NULL, seps);
	if (token == NULL)	return ERROR;
	if (rcP) rcP->irefnum = STOI(token);

	token = STOK(NULL, seps); // pos num
	if (token != NULL)
		rcP->pnum = STOUL(token,0,0);

	token = STOK(NULL, seps); // elem id
	if (token != NULL)
	{
		if (SSCAN(token, L("%I64u"), &rcP->elid) != 1) rcP->elid = 0;
	}

	token = STOK(NULL, seps); // att id
	if (token != NULL)
	{
		ELID atid;

#if defined (MSVERSION) && (MSVERSION == 0xa00) // ref file
		DgnAttachmentP rfP;
#else
		ReferenceFile* rfP;
#endif

		if (SSCAN(token, L("%I64u"), &atid) != 1) atid = 0;

		if (mdlRefFile_getFromAttachmentID(&rfP, &rcP->mrP, ACTIVEMODEL, atid) != SUCCESS)
			rcP->mrP = NULL;
	}

	token = STOK(NULL, seps); // desc
	if (token != NULL)
	{
		SCPM2W(rcP->desc, token, 500);
	}

	*/

	return SUCCESS;
}



////////////////////////////////////////////////////////////
int readReinCacheFromElement(
							 ReinCache* rcP, 
							 MSElement* elP
							 )
{
	XMLFragmentListP  oXMLFragmentList = NULL;

	if (!mdlElement_hasXMLFragmentAttachment(elP, &appID, &appTypeReinCache)) return ERROR;

	if (mdlXMLFragmentList_extractFromElementByAppIDAndType (
		&oXMLFragmentList, elP, &appID, &appTypeReinCache) == SUCCESS)
	{
		XMLFragmentP  pXMLFragment;
		MSWCH* wtxt;
		//WCH ctxt[500];
		wstring wstr = L"";

		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);
		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstr = wtxt;
			mdlXMLFragmentList_free(&oXMLFragmentList);

			if (readReinCacheFromString(rcP, wstr) == SUCCESS)
				return SUCCESS;
		}
		else
			return ERROR;
	}
	else
		return ERROR;

	return ERROR;
}

//////////////////////////////////////////////////////
int scanClearDataBars(
	MSElementDescr* edP,
	ELID* elidP,
	ScanCriteria* pScanCriteria
)
{

	ReinBar rb;
	int res = SUCCESS;

	if (readReinBarFromElement(&rb, edP, FALSE) == SUCCESS)
	{
		if (rb.bartype != BT_AXIS && rb.elemid == *elidP)
		{
			mdlXMLFragmentList_stripAllFromElement(NULL, &edP->el);
			mdlElmdscr_rewrite(edP, edP, mdlElmdscr_getFilePos(edP));
		}
	}



	return 0;
}


/////////////////////////////////
int scanReinElmsAroundPoint( // from findReinElmsAroundPoint(...)
	MSElementDescr* edDstP,
	//BarPoint* ptP,
	map <UInt32, DVec3d> &vptFound,
	ScanCriteria* pScanCriteria
)
{

	//*@description  Projects a point to an element on a perpendicular from the element.
	//	* The position of the perpendicular endpoint, direction, and the element perpendicular are returned.
	DVec3d pos;  //OUT  position of perpendicular end
	DVec3d tan;  //OUT  tangent direction
	DVec3d per;  //OUT  perpendicular direction
		//MSElementDescr* edP  IN  element
		//DgnModelRefP  modelRef  IN(for compounds elements only)
		//DPoint3d* inputPoint  IN  point to project
		//RotMatrix* inputRotMatrix  IN  rotation matrix
		//double  inputTolerance  IN  tolerance


	int res = mdlProject_perpendicular(&pos, &tan, &per, edDstP, mdlScanCriteria_getModel(pScanCriteria), &(vptFound[0]), NULL, -1);

	if (res == SUCCESS)
	{

		if (!mdlVec_equal(&pos, &(vptFound[0])))
		{
			UInt32 idist = (UInt32)mdlVec_distance(&pos, &(vptFound[0]));

			//DVec3d p;
			//mdlVec_subtract(&p, &(ptP->pVrtx), &pos);

			map<UInt32, DVec3d>::iterator it = vptFound.find(idist);

			while (it != vptFound.end()) // found
			{
				idist++;
				it = vptFound.find(idist);
			}

			vptFound[idist] = pos;

			//ptP->pElPoint = pos;
			//ptP->bnd = TRUE;

			return 0;
		}

	}


	return 0;
}

/////////////////////////////////
int findReinElmsAroundPoint(BarPoint* ptP)
{

	ScanCriteria* pScanCriteria;
	int status;

	ScanRange sr;

	map <UInt32, DVec3d> vptFound;
	//vptFound.reserve(5);

	vptFound[0] = (ptP->pVrtx);

	double dExt = mdlCnv_masterUnitsToUors(100.);

	sr.xlowlim = (Int64)(ptP->pVrtx.x - dExt);
	sr.ylowlim = (Int64)(ptP->pVrtx.y - dExt);
	sr.zlowlim = (Int64)(ptP->pVrtx.z - dExt);

	sr.xhighlim = (Int64)(ptP->pVrtx.x + dExt);
	sr.yhighlim = (Int64)(ptP->pVrtx.y + dExt);
	sr.zhighlim = (Int64)(ptP->pVrtx.z + dExt);


	pScanCriteria = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(pScanCriteria, (PFScanElemDscrCallback)scanReinElmsAroundPoint, &vptFound);
	status = mdlScanCriteria_setModel(pScanCriteria, ACTIVEMODEL);
	mdlXML_addXMLFragmentAttachmentScanTest(pScanCriteria, &appID, &appTypeReinElm);
	status = mdlScanCriteria_setRangeTest(pScanCriteria, &sr); // супер
	status = mdlScanCriteria_scan(pScanCriteria, NULL, NULL, NULL);
	status = mdlScanCriteria_free(pScanCriteria);

	if (vptFound.size() > 1) ptP->bnd = TRUE;

	map <UInt32, DVec3d>::iterator it = vptFound.begin();

	if (vptFound.size() == 2) // found one point
	{
		it++;
		ptP->pElPoint = it->second;
	}

	if (vptFound.size() > 2) // founs 2 or more points, get 2 closest
	{
		DVec3d pv[3];

		it++;
		mdlVec_subtract(&pv[0], &it->second, &ptP->pVrtx); // first point after [0]
		it++;
		mdlVec_subtract(&pv[1], &it->second, &ptP->pVrtx); // second point after [0]

		mdlVec_addInPlace(&pv[1], &pv[0]);
		mdlVec_addInPlace(&pv[1], &ptP->pVrtx);
		ptP->pElPoint = pv[1];
	}

	return 0;
}

//////////////////////////////////////////////////////
int scanMerge(
	MSElementDescr* edP,
	long* cntP,
	ScanCriteria* pSC
)
{
	//ReinBar rb;
	//ReinSpace rs;

	// view?
	//if (mdlElement_isEffectivelyVisible(&edP->el, mdlScanCriteria_getModel(pSC), tcb->lstvw) == FALSE)
	//	return 0;

	if ((*cntP) >= 0)
	{
		(*cntP)++;
	}
	else
	{

		//if ((*cntP) == -1 // REINBAR copy
		//	&& readReinBarFromElement(&rb, edP, TRUE)
		//	&& readReinSpaceFromElmd(&rs, edP, FALSE)
		//	)
		//{
		//	return 0; // попадался глюк что иногда на REINSPACE также сидит REINBAR
		//}

		MSElementDescr* newDescrP = NULL;

		mdlElmdscr_duplicate(&newDescrP, edP);

		//mdlElmdscr_addByModelRef(newDescrP, ACTIVEMODEL);

		if (mdlElmdscr_copy(&newDescrP, edP->h.dgnModelRef, ACTIVEMODEL, NULL) == SUCCESS)
		{
		}

		mdlElmdscr_freeAll(&newDescrP);

		elemIterCount3++;

		if (dlgProgressP) mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)(((double)elemIterCount3 / (double)elemCount3) * 100.));
		WaitMessage();
	}


	return 0;
}

/////////////////////////////////
// команда: копирует образующие элементы из референса в активную модель
// аргуметы: номер референса. если аргумента нет то должен быть выбран референс в списке позиций
// статус: work, notest
extern "C" DLLEXPORT void cmdReinMerge(
	char* unparsedP
)
//cmdNumber   CMD_REIN_MERGE
{

	int rn = 0;
	long cnt = 0;

	if (unparsedP != NULL && strlen(unparsedP) > 0)
		rn = atoi(unparsedP);
	//else
	//	rn = curPos_rn;

	if (rn > 0)
	{
		ReinModel* rmP = curRM->getRM(rn);

		if (rmP)
		{
			ScanCriteria* pSC;
			int status;

			pSC = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(pSC, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback(pSC, (PFScanElemDscrCallback)scanMerge, &cnt);
			status = mdlScanCriteria_setModel(pSC, rmP->modelP);
			mdlXML_addXMLFragmentAttachmentScanTest(pSC, &appID, &appTypeReinBar);
			status = mdlScanCriteria_scan(pSC, NULL, NULL, NULL);
			status = mdlScanCriteria_free(pSC);

			pSC = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(pSC, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback(pSC, (PFScanElemDscrCallback)scanMerge, &cnt);
			status = mdlScanCriteria_setModel(pSC, rmP->modelP);
			mdlXML_addXMLFragmentAttachmentScanTest(pSC, &appID, &appTypeReinSpace);
			status = mdlScanCriteria_scan(pSC, NULL, NULL, NULL);
			status = mdlScanCriteria_free(pSC);
		}

		if (cnt > 0)
		{
			ScanCriteria* pSC;
			int status;

			elemIterCount3 = 0;
			elemCount3 = cnt;

			dlgProgressP = mdlDialog_completionBarOpen(TXT_120);

			rn = -1; // bars
			pSC = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(pSC, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback(pSC, (PFScanElemDscrCallback)scanMerge, &rn);
			status = mdlScanCriteria_setModel(pSC, rmP->modelP);
			mdlXML_addXMLFragmentAttachmentScanTest(pSC, &appID, &appTypeReinBar);
			status = mdlScanCriteria_scan(pSC, NULL, NULL, NULL);
			status = mdlScanCriteria_free(pSC);

			rn = -2; // spaces
			pSC = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(pSC, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback(pSC, (PFScanElemDscrCallback)scanMerge, &rn);
			status = mdlScanCriteria_setModel(pSC, rmP->modelP);
			mdlXML_addXMLFragmentAttachmentScanTest(pSC, &appID, &appTypeReinSpace);
			status = mdlScanCriteria_scan(pSC, NULL, NULL, NULL);
			status = mdlScanCriteria_free(pSC);

			if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);

			BINT isOn = FALSE;
			status = func_pma(mdlRefFile_setBooleanParameters, isOn), REFERENCE_DISPLAYFLAG, rmP->modelP); //(не фурычит если &isOn)
			mdlRefFile_writeAttachmentExtended(rmP->modelP, TRUE, TRUE, TRUE);
		}


	}
	else
	{
		MessageBox(0, "Перед командой надо выбрать копируемый референс в окне списка позиций", "", MB_OK);
	}
}


///////////////////////////////////////////////
// расчет радиуса и центра дуги по трем точкам
// https://www.geeksforgeeks.org/equation-of-circle-when-three-points-on-the-circle-are-given/
double CalcRad2(DVec3d* pIn, DVec3d* pNrm, DVec3d* pCenterP)
{
	DVec3d Center;
	RotMatrix rm;

	DVec3d ptsIn[3];
	DVec3d p1;
	DVec3d p2;
	DVec3d p3;

	writeLogIn(__FUNCTION__, 0);

	ptsIn[0] = pIn[0];
	ptsIn[1] = pIn[1];
	ptsIn[2] = pIn[2];

	mdlRMatrix_fromNormalVector(&rm, pNrm);

	mdlRMatrix_multiplyPointArray(ptsIn, &rm, 3);

	p1 = ptsIn[0];
	p2 = ptsIn[1];
	p3 = ptsIn[2];

	//int x12 = x1 - x2;
	//int x13 = x1 - x3;

	//int y12 = y1 - y2;
	//int y13 = y1 - y3;

	//int y31 = y3 - y1;
	//int y21 = y2 - y1;

	//int x31 = x3 - x1;
	//int x21 = x2 - x1;

	double x12 = p1.x - p2.x;
	double x13 = p1.x - p3.x;

	double y12 = p1.y - p2.y;
	double y13 = p1.y - p3.y;

	double y31 = p3.y - p1.y;
	double y21 = p2.y - p1.y;

	double x31 = p3.x - p1.x;
	double x21 = p2.x - p1.x;

	//// x1^2 - x3^2
	//int sx13 = pow(x1, 2) - pow(x3, 2);

	//// y1^2 - y3^2
	//int sy13 = pow(y1, 2) - pow(y3, 2);

	//int sx21 = pow(x2, 2) - pow(x1, 2);
	//int sy21 = pow(y2, 2) - pow(y1, 2);

	// x1^2 - x3^2
	double sx13 = pow(p1.x, 2) - pow(p3.x, 2);

	// y1^2 - y3^2
	double sy13 = pow(p1.y, 2) - pow(p3.y, 2);

	double sx21 = pow(p2.x, 2) - pow(p1.x, 2);
	double sy21 = pow(p2.y, 2) - pow(p1.y, 2);

	/*
	int f = ((sx13) * (x12)
		+(sy13) * (x12)
		+(sx21) * (x13)
		+(sy21) * (x13))
		/ (2 * ((y31) * (x12)-(y21) * (x13)));
	int g = ((sx13) * (y12)
		+(sy13) * (y12)
		+(sx21) * (y13)
		+(sy21) * (y13))
		/ (2 * ((x31) * (y12)-(x21) * (y13)));
	*/

	double f = ((sx13) * (x12)
		+(sy13) * (x12)
		+(sx21) * (x13)
		+(sy21) * (x13))
		/ (2 * ((y31) * (x12)-(y21) * (x13)));
	double g = ((sx13) * (y12)
		+(sy13) * (y12)
		+(sx21) * (y13)
		+(sy21) * (y13))
		/ (2 * ((x31) * (y12)-(x21) * (y13)));

	//int c = -pow(x1, 2) - pow(y1, 2) - 2 * g * x1 - 2 * f * y1;

	double c = -pow(p1.x, 2) - pow(p1.y, 2) - 2 * g * p1.x - 2 * f * p1.y;

	// eqn of circle be x^2 + y^2 + 2*g*x + 2*f*y + c = 0
	// where centre is (h = -g, k = -f) and radius r
	// as r^2 = h^2 + k^2 - c
	Center.x = -g;
	Center.y = -f;
	Center.z = ptsIn[0].z;

	double sqr_of_r = Center.x * Center.x + Center.y * Center.y - c;

	// r is the radius
	double r = sqrt(sqr_of_r);



	mdlRMatrix_getInverse(&rm, &rm);
	mdlRMatrix_multiplyPoint(&Center, &rm);

	*pCenterP = Center;

	//double d = mdlVec_distance(&Center, &ptsIn[0]);		// calc. radius

	writeLogOut(__FUNCTION__, 0);

	return r;


}

//////////////////////
/*
int removeArcPoints()
{

	for (vector<ReinPoint>::iterator it = gvpt.begin(); it != gvpt.end(); ++it)
	{
		int i = distance(gvpt.begin(), it);

		if (it->rfa & RFA_ARCP && i > 1 && i < gvpt.size() - 2)
		{

			// спрямляем....
			DVec3d ptmp[5];

			vector<ReinPoint>::iterator it1 = it;
			it1--;
			ptmp[1] = it1->rpt;
			it1--;
			ptmp[0] = it1->rpt;

			// для удаления
			it1++;

			vector<ReinPoint>::iterator it2 = it;
			it2++;
			ptmp[2] = it2->rpt;
			it2++;
			ptmp[3] = it2->rpt;

			// для удаления
			it2--;

			if (mdlVec_intersectXYZLines(&ptmp[4], 0, 0, &ptmp[0], &ptmp[1], &ptmp[2], &ptmp[3], 0.) == SUCCESS)
			{
				ReinPoint p;
				p.set(ptmp[4]);
				gvpt[i] = p;
				gvpt.erase(it1); // it2 also shifted
				it2--; // turn back
				gvpt.erase(it2);
				return 1;
			}
		}
	}

	return 0;

}
*/

///////////////////////////////////
void hookComboBoxModel(
	DialogItemMessage* dimP
)
{

	dimP->msgUnderstood = TRUE;

	ListModel* pListModel = NULL;

	switch (dimP->messageType)
	{

	case DITEM_MESSAGE_CREATE:
	{
		break;
	}
	case DITEM_MESSAGE_DESTROY:
	{
		break;
	}
	case DITEM_MESSAGE_STATECHANGED:
	{
		break;
	}
	default:
		dimP->msgUnderstood = FALSE;
		break;
	}

	return;

}

////////////////////////
void toolBoxComboSync()
{

#if defined (STD_INTERFACE)

	writeLogIn(__FUNCTION__, 0);


	MSDLGP dbP = NULL;

	if (NULL != (dbP = mdlDialog_find(DIALOG_TOOLBOX, NULL)))
	{
		if (iDebug) sprintf(sLogMes, " dialog id=2 found, sync dialog items... (mdlDlg_itemsSynch)\n"); writeLog(0, 0);
		//mdlDialog_itemsSynch(dbP);

		//DialogItemP diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_IconPopup, ICONCMDID_ismodel2, 0);
		DialogItemP diP = mdlDialog_itemGetByIndex(dbP, 0);


		if (diP)
		{
			RawItemHdr* rihP = mdlDialog_rItemChildGetByTypeAndId(diP->rawItemP, RTYPE_IconPopup, ICONCMDID_ismodel2, 0, 0, TRUE);

			if (rihP)
			{

				StringList* slP = mdlStringList_loadResourceWithType(NULL, RTYPE_STRINGLIST, STRLIST_MODEL);

				if (slP)
				{

					if (iDebug) sprintf(sLogMes, "process string list of model types...\n"); writeLog(0, 0);

#if defined (MSVERSION) && (MSVERSION == 0x8b0) // V8i
					char* sval = NULL;
					if (mdlStringList_getMember(&sval, 0, slP, iModelType) == SUCCESS)
					{

						ValueDescr  valDescr;
						valDescr.formatType = FMT_STRING;
						valDescr.value.charPFormat = sval;
						int res = mdlDialog_iconPopupSetInsideLabel(rihP, &valDescr);
#else
					WCharCP sval = NULL;
					if (mdlStringList_getMember(&sval, 0, slP, iModelType) == SUCCESS)
					{
						int res = mdlDialog_iconPopupSetInsideLabel(rihP, sval);
#endif
						mdlDialog_rItemDraw(rihP);
					}
					else if (iModelType == MODTYPE_ASSEMBLY)
					{
#if defined (MSVERSION) && (MSVERSION == 0x8b0) // V8i
						ValueDescr  valDescr;
						valDescr.formatType = FMT_STRING;
						valDescr.value.charPFormat = "Assembly";
						int res = mdlDialog_iconPopupSetInsideLabel(rihP, &valDescr);
#else
						int res = mdlDialog_iconPopupSetInsideLabel(rihP, L"Assembly");
#endif
						mdlDialog_rItemDraw(rihP);
					}
//					else if (iModelType == MODTYPE_MASTER)
//					{
//#if defined (MSVERSION) && (MSVERSION == 0x8b0) // V8i
//						ValueDescr  valDescr;
//						valDescr.formatType = FMT_STRING;
//						valDescr.value.charPFormat = "Master";
//						int res = mdlDialog_iconPopupSetInsideLabel(rihP, &valDescr);
//#else
//						int res = mdlDialog_iconPopupSetInsideLabel(rihP, L"Master");
//#endif
//						mdlDialog_rItemDraw(rihP);
//					}

					mdlStringList_destroy(slP);
				}
			}
		}
	}

	writeLogOut(__FUNCTION__, 0);

#endif

}

///////////////////////////
LEVID getOrCreateLevel(DgnModelRefP mrP, MSWCHCP levName, bool bUseActiveIfNotSuccess)
{

	LEVID lid = LEVEL_NULL_ID;

	if (mdlLevel_getIdFromName(&lid, mrP, LEVEL_NULL_ID, levName) != SUCCESS)
	{
		int res = mdlLevel_create(&lid, mrP, levName, LEVEL_NULL_CODE);

		if (res == SUCCESS)
		{
			if (mdlLevelTable_rewrite(mrP) != SUCCESS)
			{
				lid = LEVEL_NULL_ID;
			}
		}
		else
		{
			if (bUseActiveIfNotSuccess)
			{
				mdlLevel_getActive(&lid);
			}
		}

	}

	if (lid == LEVEL_NULL_ID && bUseActiveIfNotSuccess) mdlLevel_getActive(&lid);

	return lid;

}


//////////////////////////////////
MSElementDescr* makePlate(
	double dHeight,
	double dWidth,
	double dLength,							  
	DPoint3d offset,
	DVec3d vdir
)
{

	BODY_TAG cuboid = NULL;
	MSElementDescr* edP = NULL;
	Transform tm;
	DPoint3d p3d_orient;
	DPoint3d p3d_offset;

	/* Begin current translation */
	mdlKISolid_beginCurrTrans(MASTERFILE);

	/* Convert master units to UORs */
	mdlCnv_masterToUOR(&dHeight, dHeight, MASTERFILE);
	mdlCnv_masterToUOR(&dWidth, dWidth, MASTERFILE);
	mdlCnv_masterToUOR(&dLength, dLength, MASTERFILE);

	/* Convert current units to Parasolid units */
	mdlCurrTrans_invScaleDoubleArray(&dHeight, &dHeight, 1);
	mdlCurrTrans_invScaleDoubleArray(&dWidth, &dWidth, 1);
	mdlCurrTrans_invScaleDoubleArray(&dLength, &dLength, 1);
	mdlCurrTrans_invScaleDoubleArray(&offset.x, &offset.x, 1);
	mdlCurrTrans_invScaleDoubleArray(&offset.y, &offset.y, 1);
	mdlCurrTrans_invScaleDoubleArray(&offset.z, &offset.z, 1);

	p3d_orient.x = dWidth;
	p3d_orient.y = dLength;
	p3d_orient.z = dHeight;

	p3d_offset.x = 0.;
	p3d_offset.y = 0.;
	p3d_offset.z = -dHeight / 2.;



	/* Make our tick mark */
	mdlKISolid_makeCuboid(&cuboid,
		p3d_orient.x,
		p3d_orient.y,
		p3d_orient.z
	);


	/* Convert the body to an element */
	mdlKISolid_bodyToElement(&edP, cuboid, TRUE, -1,
#if defined (MSVERSION) && (MSVERSION == 0xa00)
		-1, SMART_ISO_Auto,
#endif
		&c0w1s0, ACTIVEMODEL);

	mdlTMatrix_getIdentity(&tm);

	mdlTMatrix_setTranslation(&tm, &p3d_offset);

	func_amp(mdlElmdscr_transform, edP), & tm);


	RotMatrix rm;
	mdlRMatrix_fromNormalVector(&rm, &vdir);
	mdlRMatrix_invert(&rm, &rm);

	mdlTMatrix_fromRMatrix(&tm, &rm);
	//mdlTMatrix_getIdentity(&tm);

	mdlTMatrix_setTranslation(&tm, &offset);

	func_amp(mdlElmdscr_transform, edP), & tm);


	/* End current translation */
	mdlKISolid_endCurrTrans();
	/* Free memory */
	mdlKISolid_freeBody(cuboid);


	return edP;

}

///////////////////////////////////////////////////////
void makeAssemblyElem(
	ReinElm* crelmP, 
	MSElementDescr* edPathP, // path
	MSElementDescrP* edpToAddPP, // elem to return
	DgnModelRefP mrP, // if add to model
	bool bSolid
)
{
	MSWCH wstr[100];
	ReinElm* reP = NULL;
	ReinModel* rmP = curRM->getRM(edPathP->h.dgnModelRef);

	LEVID iLevID = 0;

	mdlElmdscr_getProperties(&iLevID, 0, 0, 0, 0, 0, 0, 0, edPathP);


	if (rmP)
		reP = rmP->getReinElm(mdlElmdscr_getFilePos(edPathP));

	if (reP == NULL) reP = crelmP;

	MSElementDescrP edpBarP = NULL;
	MSElementDescrP edpToAddP = NULL;

	if (bSolid)
	{
		UInt32 fpBar = reinSweepBarByPath(NULL, reP->bel.diam,
											1, // true radius without rif
											NULL, // no model ref
											edPathP, 0, &iLevID, &edpBarP, 0.0);
	}
	else
	{
		mdlElmdscr_duplicate(&edpBarP, edPathP);
	}


	if (reP->bel.term[0] == REIN_TERM_PLAT
		|| reP->bel.term[1] == REIN_TERM_PLAT)
	{
		mdlCell_create(&eCell, 0, 0, 0);
		mdlElmdscr_new(&edpToAddP, NULL, &eCell);
		if (edpBarP) mdlElmdscr_appendDscr(edpToAddP, edpBarP);

		if (reP->bel.term[0] == REIN_TERM_PLAT)
		{
			MSElementDescr* edPlate1 = makePlate(20, 90, 90, 
				reP->bel.rpts[0], 
				reP->bel.sgts[0].rv[0].rvv.tdir);

			if (edPlate1) mdlElmdscr_appendDscr(edpToAddP, edPlate1);
		}

		if (reP->bel.term[1] == REIN_TERM_PLAT)
		{
			MSElementDescr* edPlate1 = makePlate(20, 90, 90,
				reP->bel.rpts[reP->bel.numpts - 1],
				reP->bel.sgts[reP->bel.numsgts - 1].rv[1].rvv.tdir);

			if (edPlate1) mdlElmdscr_appendDscr(edpToAddP, edPlate1);
		}

	}
	else
		edpToAddP = edpBarP;


	if (reP->bel.term[0] == REIN_TERM_MUFT)
	{
		MSElementDescrP edpMuft = NULL;

		edpMuft = makeAssemblyMuft(reP->bel.diam, 
			reP->bel.sgts[0].rv[0].torg, 
			reP->bel.sgts[0].rv[0].rvv.tdir, mrP);

		BINT locked = TRUE;
		//mdlElmdscr_setProperties(edpMuft, 0, 0, 0, &locked, 0, 0, 0, 0);
		func_amp(mdlElmdscr_setProperties, edpMuft), &iLevID, 0, 0, &locked, 0, 0, 0, 0);

#if defined (OBD)
		Bentley::Building::Elements::BuildingEditElemHandle beeh(edpMuft->h.elementRef, mrP);
		beeh.GetCatalogCollection().InsertDataGroupCatalogInstance(L"Couplings", L"Coupling");
		beeh.GetCatalogCollection().UpdateInstanceDataDefaults(L"Couplings");
		// props, part def...
#else
		XMLFragmentListP pCurrent = makeXmlForMuft(reP, iLevID);
		mdlXMLFragmentList_attachToElement(&pCurrent, &edpMuft, TRUE);
#endif

		if (edpMuft)
		{
			if (mrP)
			{
				mdlElmdscr_addByModelRef(edpMuft, mrP);
				mdlElmdscr_freeAll(&edpMuft);
			}
			else if (edpToAddPP && *edpToAddPP)
				mdlElmdscr_appendDscr(*edpToAddPP, edpMuft);

		}
	}

	if (reP->bel.term[1] == REIN_TERM_MUFT)
	{
		MSElementDescrP edpMuft = NULL;

		edpMuft = makeAssemblyMuft(reP->bel.diam, 
			reP->bel.sgts[reP->bel.numsgts - 1].rv[1].torg,
			reP->bel.sgts[reP->bel.numsgts - 1].rv[1].rvv.tdir, mrP);

		BINT locked = TRUE;
		//mdlElmdscr_setProperties(edpMuft, 0, 0, 0, &locked, 0, 0, 0, 0);
		func_amp(mdlElmdscr_setProperties, edpMuft), &iLevID, 0, 0, &locked, 0, 0, 0, 0);

#if defined (OBD)
		Bentley::Building::Elements::BuildingEditElemHandle beeh(edpMuft->h.elementRef, mrP);
		beeh.GetCatalogCollection().InsertDataGroupCatalogInstance(L"Couplings", L"Coupling");
		beeh.GetCatalogCollection().UpdateInstanceDataDefaults(L"Couplings");
		// props, part def...
#else
		XMLFragmentListP pCurrent = makeXmlForMuft(reP, iLevID);
		mdlXMLFragmentList_attachToElement(&pCurrent, &edpMuft, TRUE);
#endif

		if (edpMuft)
		{
			if (mrP)
			{
				mdlElmdscr_addByModelRef(edpMuft, mrP);
				mdlElmdscr_freeAll(&edpMuft);
			}
			else if (edpToAddPP && *edpToAddPP)
				mdlElmdscr_appendDscr(*edpToAddPP, edpMuft);

		}

	}


	if (edpToAddP)
	{
		BINT locked = TRUE;
		//mdlElmdscr_setProperties(edpToAdd, 0, 0, 0, &locked, 0, 0, 0, 0);
		func_amp(mdlElmdscr_setProperties, edpToAddP), &iLevID, 0, 0, &locked, 0, 0, 0, 0);

#if defined (OBD)
		Bentley::Building::Elements::BuildingEditElemHandle beeh(edpToAdd->h.elementRef, mrP);
		beeh.GetCatalogCollection().InsertDataGroupCatalogInstance(L"Bars", L"Bar d36");
		beeh.GetCatalogCollection().UpdateInstanceDataDefaults(L"Bars");
		CCatalogSchemaItemT* pSchemaItem = NULL;
		if (NULL != (pSchemaItem = beeh.GetCatalogCollection().FindDataGroupSchemaItem(L"Bars/@BarDiam")))
			pSchemaItem->SetValue(L"36");
		// props, part def...
#else
		XMLFragmentListP pCurrent = makeXmlForElement(reP, iLevID);
		mdlXMLFragmentList_attachToElement(&pCurrent, &edpToAddP, TRUE);
#endif

		if (mrP)
		{
			mdlElmdscr_addByModelRef(edpToAddP, mrP);
			mdlElmdscr_freeAll(&edpToAddP);
		}
		else if (edpToAddPP && *edpToAddPP)
			mdlElmdscr_appendDscr(*edpToAddPP, edpToAddP);

	}



}

//////////////////////////////////
MSElementDescr* makeAssemblyMuft(
	int bardiam,
	DVec3d vorg,
	DVec3d vdir,
	DgnModelRefP mrP
)
{

	MSElementDescr* edP = NULL;

	double dMuftLen;
	double dShell;
	RotMatrix rm;
	DVec3d p[2];
	DVec3d ppp[2];
	MSElementDescrP edpPath = NULL;
	MSElementDescrP edpMuft = NULL;

	if (mrP == NULL) mrP = ACTIVEMODEL;

	mdlRMatrix_fromNormalVector(&rm, &vdir);

	mdlCnv_masterToUOR(&dMuftLen, (double)(bardiam * 2), mrP);
	dShell = -dMuftLen / 5.;

	mdlVec_fromRotMatrixRow(&ppp[0], &rm, 0);
	mdlVec_fromRotMatrixRow(&ppp[1], &rm, 1);

	mdlVec_scaleToLength(&p[0], &vdir, dMuftLen);
	mdlVec_scaleToLength(&p[1], &vdir, -dMuftLen);

	mdlVec_addPoint(&p[0], &vorg, &p[0]);
	mdlVec_addPoint(&p[1], &vorg, &p[1]);

	mdlLine_create(&el, 0, p);

	mdlElmdscr_new(&edpPath, 0, &el);

	if (edpPath) reinSweepBarByPath(NULL, bardiam * 2,
		1, // true radius without rif
		NULL, // no model ref
		edpPath, 0, 0, &edP, dShell);

	if (edpPath) mdlElmdscr_freeAll(&edpPath);

	return edP;

}

/////////////////////
void xmlAdd(MSWCH* wstr, XMLFragmentListP* pCurrentP)
{
	XMLFragmentP    pFrgm = NULL;
	XMLFragmentListP    pCurrentTmp = NULL;

	pCurrentTmp = mdlXMLFragmentList_construct(wstr, NULL, appID, appTypeReinAssem);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	pFrgm = mdlXMLFragmentList_getXMLFragment(pCurrentTmp);
	mdlXMLFragmentList_append(pCurrentP, pFrgm);
#else
	if (*pCurrentP)
		mdlXMLFragmentList_append(pCurrentP, pCurrentTmp);
	else
		*pCurrentP = pCurrentTmp;
#endif
}


/////////////////////////////////////////////
XMLFragmentListP makeXmlForCage(MSWCH* cagename, LEVID iLevID)
{
	MSWCH wstr[200];
	XMLFragmentListP    pCurrent = NULL;

	//_swprintf(wstr, L"<Level id=\"%u\" />", iLevID);
	//xmlAdd(wstr, &pCurrent);


	wcscpy(wstr, L"<Property name=\"Type\" value=\"Cage\" />");
	xmlAdd(wstr, &pCurrent);

	_swprintf(wstr, L"<Property name=\"Code Number\" value=\"%s\" />", cagename);
	xmlAdd(wstr, &pCurrent);


	return pCurrent;

}


/////////////////////////////////////////////
XMLFragmentListP makeXmlForElement(ReinElm* reP, LEVID iLevID)
{
	MSWCH wstr[200];
	XMLFragmentListP    pCurrent = NULL;

	//_swprintf(wstr, L"<Level id=\"%u\" />", iLevID);
	//xmlAdd(wstr, &pCurrent);


	wcscpy(wstr, L"<Property name=\"Type\" value=\"Bar\" />");
	xmlAdd(wstr, &pCurrent);

	_swprintf(wstr, L"<Property name=\"Code Number\" value=\"%d\" />", reP->bel.pnum);
	xmlAdd(wstr, &pCurrent);

	_swprintf(wstr, L"<Property name=\"Diameter\" value=\"%i\" />", reP->bel.diam);
	xmlAdd(wstr, &pCurrent);

	_swprintf(wstr, L"<Property name=\"Length\" value=\"%d\" />", roundExt(reP->bel.length, ROUND_LIN));
	xmlAdd(wstr, &pCurrent);




	return pCurrent;

}


/////////////////////////////////////////////
XMLFragmentListP makeXmlForMuft(ReinElm* reP, LEVID iLevID)
{
	MSWCH wstr[200];
	XMLFragmentListP    pCurrent = NULL;


	//_swprintf(wstr, L"<Level id=\"%u\" />", iLevID);
	//xmlAdd(wstr, &pCurrent);


	wcscpy(wstr, L"<Property name=\"Type\" value=\"Coupling\" />");
	xmlAdd(wstr, &pCurrent);

	_swprintf(wstr, L"<Property name=\"Diameter\" value=\"%i\" />", reP->bel.diam);
	xmlAdd(wstr, &pCurrent);

	//_swprintf(wstr, L"<Property name=\"Diameter 2\" value=\"%i\" />", reP->bel.diam);
	//xmlAdd(wstr, &pCurrent);


	return pCurrent;

}

////////////////////////////////
// long	set;	prmP->lval[0]
// long	inum;	prmP->lval[1]
// UInt32	ref;	prmP->cnt[0]
// ELID	eid;	prmP->prmid
// int	refcnt;	prmP->cnt[1]
// UInt32	aref[];	prmP->uival[]
int getBarSetInfo(MSElementDescr* edP, ReinPrm* prmP)
{
	prmP->clear();

	XMLFragmentListP  oXMLFragmentList = NULL;

	UInt32 fp = mdlElmdscr_getFilePos(edP);

	prmP->mrP = edP->h.dgnModelRef;

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	wstring str = L"";

	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);

			wstr = wtxt;
			mdlXMLFragmentList_free(&oXMLFragmentList);

			if (wstr.length() > 0)
			{
				prmP->wstr = wstr;

				setstr.clear();

				if (readFromString(__FUNCTION__, &setstr, wstr,
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//					L'|'
//#else
					L"|"
//#endif
				) == SUCCESS)
				{
					SETSTR_BEGIN_ITER;
					IF_IT
						prmP->lval[0] = _wtol(it->c_str()); // set

					IF_IT_nxt
					IF_IT
						prmP->lval[1] = _wtol(it->c_str()); // inum

					IF_IT_nxt
					IF_IT
						prmP->cnt[0] = wcstoul(it->c_str(), 0, 0); // ref number, new vers - is ref or not

					IF_IT_nxt
					IF_IT_end return SUCCESS;
					if (swscanf(it->c_str(), L"%I64u", &prmP->prmid) != 1) return ERROR; // eid

					// VERSION 2
					IF_IT_nxt
					while (it != setstr.end() && prmP->uints.size() < MAX_REFNUM_PATH)
					{
						//prmP->uival[prmP->cnt[1]] = _wtol(it->c_str());

						UInt32 rn = wcstoul(it->c_str(), 0, 0);
						prmP->uints.push_back(rn);

						//prmP->cnt[1]++;

						++it;
					}

				}
				else
					return ERROR;
			}
			else
				return ERROR;
		}
		else
			return ERROR;
	}
	else
		return ERROR;


	return SUCCESS;

}




////////////////////
int getModelInfo(MSElementDescr* edP, ReinPrm* prmP)
{
	prmP->clear();


	XMLFragmentListP  oXMLFragmentList = NULL;

	oXMLFragmentList = mdlXMLFragmentList_constructFromXMLFragmentElement(edP);

	if (oXMLFragmentList)
	{
		XMLFragmentP        pXMLFragment;
		MSWCH* wtxt;
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);

			mdlXMLFragmentList_free(&oXMLFragmentList);

			setstr.clear();

			if (readFromString(__FUNCTION__, &setstr, wstr) == SUCCESS)
			{
				SETSTR_BEGIN_ITER;
				IF_IT
					prmP->ival[0] = _wtoi(it->c_str());

				IF_IT_nxt
				IF_IT
					prmP->ival[1] = _wtoi(it->c_str());
				else
					prmP->ival[1] = FALSE;

				IF_IT_nxt
				IF_IT
					prmP->ival[2] = _wtoi(it->c_str());
				else
					prmP->ival[2] = MODTYPE_COMMON;
			}
			else
				return ERROR;
		}
		else
			return ERROR;
	}
	else
		return ERROR;

	return SUCCESS;

}

////////////////////////////////////////////////////////////
int readRndFromElement(ELID* idP, UInt32* refnumP, MSElementCP elP)
{
	XMLFragmentListP  oXMLFragmentList = NULL;

	int ret = ERROR;

	if (!mdlElement_hasXMLFragmentAttachment((MSElementP)elP, &appID, &appTypeRndResult))
		return ERROR;


	if (mdlXMLFragmentList_extractFromElementByAppIDAndType(&oXMLFragmentList, (MSElementP)elP,
		&appID, &appTypeRndResult) == SUCCESS)
	{
		XMLFragmentP  pXMLFragment;
		MSWCH* wtxt;
		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);
		if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
		{
			wstring wstr(wtxt);
			mdlXMLFragmentList_free(&oXMLFragmentList);

			setstr.clear();

			if (readFromString(__FUNCTION__, &setstr, wstr) != SUCCESS) return ERROR;

			if (setstr.empty()) return ERROR;

			SETSTR_BEGIN_ITER;
			if (*it != L"RONDOELEM") return ERROR;

			IF_IT_nxt IF_IT_end return ERROR;
			MSWCH stmp[50];
			wcscpy(stmp, it->c_str());
			if (swscanf(stmp, L"%I64u", idP) != 1) return ERROR;

			IF_IT_nxt IF_IT_end return SUCCESS;
			*refnumP = wcstoul(it->c_str(), 0, 0);

		}
		else
			return ERROR;
	}
	else
		return ERROR;

	return SUCCESS;

}


/////////////////////////////////
// func: save positions to xml file
void posSaveFileXml(
	char* unparsedP
)
{
#if defined (MSVERSION) && (MSVERSION == 0x8b0)

	string sline;
	int res;
	long partID = 0;
	long posID = 0;
	long propID = 0;


	ofstream f;
	char fname[300];

	char* hdr = "<?xml version=\"1.0\" encoding=\"Windows-1251\"?>\n";

	if (unparsedP && strlen(unparsedP) > 0)
	{
		strcpy(fname, unparsedP);
	}
	else
	{
		res = mdlDialog_fileCreate(fname, 0, 0, "", "*.xml", 0, "file to save");

		if (res != SUCCESS) return;
	}

	f.open(fname, ofstream::out);

	if (f.is_open())
		f.write(hdr, strlen(hdr));
	else
		return;


	sline = "<RHEIN>\n";
	f.write(sline.c_str(), sline.length());


	ReinLap* rlP = getReinLap(6);


	ZeroTrackBar(&tbi);
	tbi.update = UPDATE_Percent1 | UPDATE_Msg1;


	SCPY(tbi.msgText1, TXT_119);

	dlgProgressP = mdlDialog_completionBarOpen(TXT_119);
	//mdlDialog_trackBarStartProcessing(NULL, NULL, NULL, NULL, L("Отменено"), 0, &tbi, L(""));

	UInt32 i = 0;

	for (map<long, ReinPos>::iterator it = curRM->getPosMap().begin(); it != curRM->getPosMap().end(); ++it, i++)
	{

		WCH v[20];

		ReinPos* rpP = &it->second;

		long posnum = rpP->bar.pnum;

		if (posnum <= 0) continue;

		// save...

		setPosString(rpP, 1, 1);

		SPRN(s, L("\t<position %s>\n"), sCurPos);

		sline = s;
		f.write(sline.c_str(), sline.length());


		// точки
		{

			for (int a = 0; a < rpP->bar.cnumpts; a++)
			{

				int isMn = 0;
				int isCn = 0;

				if (a == rpP->bar.mainPtsIndex) isMn = 1;
				if (rpP->bar.runmet > 1) isCn = isMn;

				//SCPY(strSQL, L("INSERT INTO [r_part_reinpoints] (partID, xd,yd,zd, x,y,z, xa,ya,za, isMain, isOk, isCont, onArc) "));

				//int i_rfa = 0;
				//if (rpP->bar.rfa[a] & RFA_ARCP || rpP->bar.rfa[a] & RFA_CIRP) i_rfa = RFA_ARCP;


				SPRN(s, L("\t\t<point isMn=\"%i\" isCn=\"%i\" i_rfa=\"%i\">\n"), isMn, isCn, rpP->bar.rfa[a]);
				sline = s;
				f.write(sline.c_str(), sline.length());

				SPRN(s, L("\t\t\t<coords function=\"sketch\" x=\"%.2f\" y=\"%.2f\" z=\"%.2f\"/>\n"),
					rpP->bar.apts[a].x, rpP->bar.apts[a].y, rpP->bar.apts[a].z);
				sline = s;
				f.write(sline.c_str(), sline.length());

				SPRN(s, L("\t\t\t<coords function=\"compare1\" x=\"%i\" y=\"%i\" z=\"%i\"/>\n"),
					rpP->bar.cpxb[a].x, rpP->bar.cpxb[a].y, rpP->bar.cpxb[a].z);
				sline = s;
				f.write(sline.c_str(), sline.length());

				SPRN(s, L("\t\t\t<coords function=\"compare2\" x=\"%i\" y=\"%i\" z=\"%i\"/>\n"),
					rpP->bar.cpxe[a].x, rpP->bar.cpxe[a].y, rpP->bar.cpxe[a].z);
				sline = s;
				f.write(sline.c_str(), sline.length());

				SPRN(s, L("\t\t</point>\n"));
				sline = s;
				f.write(sline.c_str(), sline.length());

			}

		}

		SPRN(s, L("\t</position>\n"));

		sline = s;
		f.write(sline.c_str(), sline.length());


		/*

		if (rpP->bar.runmet == 1)
			rpP->base_qty = rpP->file_qty_rm;
		else
			rpP->base_qty = rpP->file_qty_p;

		int bSk = 1;

		if ((rpP->bar.runmet == 1 || rpP->bar.cnumpts <= 2) &&
			(rpP->bar.term[0] == REIN_TERM_NONE || rpP->bar.term[0] == REIN_TERM_SKOB) &&
			(rpP->bar.term[1] == REIN_TERM_NONE || rpP->bar.term[1] == REIN_TERM_SKOB)) bSk = 0;


		SPRN(s, L("length, lenmin, lenmax VALUES (%i,%i,%i,%i)"),
			posID, rpP->file_ms_mid, rpP->file_ms_min, rpP->file_ms_max);

		sline = s;
		f.write(sline.c_str(), sline.length());

		// окончания
		{

			int trmp[4] = { 0 };
			//ZeroMemory(trmp, sizeof(trmp));
			setBarTermPar6to4(trmp, &rpP->bar);

			//SPRN(strSQL, L("INSERT INTO [r_part_reinsketch] (partID, "));
			//SCAT(strSQL, L("sketchStartType, sketchStartAngle, sketchStartLength, "));
			//SCAT(strSQL, L("sketchEndType, sketchEndAngle, sketchEndLength) "));

			SPRN(s, L("term VALUES (%i,%i,%i,%i,%i,%i,%i)"),
				partID,
				rpP->bar.term[0], trmp[0], trmp[2],
				rpP->bar.term[1], trmp[1], trmp[3]
			);

			sline = s;
			f.write(sline.c_str(), sline.length());

		}


		*/

		tbi.percentComplete1 = (long)(((double)i / (double)curRM->getPosMap().size()) * 100.);

		if (dlgProgressP) mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)tbi.percentComplete1);
		WaitMessage();

	}


	if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);


	sline = "</RHEIN>\n";
	f.write(sline.c_str(), sline.length());


	f.close();

#endif

}


/////////////////////
void prepareBarOver(ReinElement* relemP, ReinBar* rbP, int baract)
{

	BarOver bo;
	bo.inum = rbP->inum;

	if (baract == BAROVER_ACTION_MOVE)
	{
		DPoint3d pMove;
		Transform tmMove;
		Transform tmMoveFirst;

		if (rBarOverInfo.dopopt[18]) pMove.x = mdlCnv_masterUnitsToUors(rBarOverInfo.dopopt[15]); else pMove.x = 0.;
		if (rBarOverInfo.dopopt[19]) pMove.y = mdlCnv_masterUnitsToUors(rBarOverInfo.dopopt[16]); else pMove.y = 0.;
		if (rBarOverInfo.dopopt[20]) pMove.z = mdlCnv_masterUnitsToUors(rBarOverInfo.dopopt[17]); else pMove.z = 0.;

		mdlTMatrix_getIdentity(&tmMove);
		mdlTMatrix_setTranslation(&tmMove, &pMove);

		map<int, BarOver>::iterator it = relemP->mapOvers.find(rbP->inum);
		if (it != relemP->mapOvers.end()) // found
		{
			tmMoveFirst = it->second.tmov;
			mdlTMatrix_multiply(&tmMove, &tmMoveFirst, &tmMove);
		}
		else
		{ // insert if not exist
			BarOver bo1;
			bo1.inum = rbP->inum;
			relemP->mapOvers[rbP->inum] = bo1;
		}

		relemP->mapOvers[rbP->inum].tmov = tmMove;

		relemP->mapOvers[rbP->inum].isgnd = rBarOverInfo.dopopt[22];

		if (mdlTMatrix_isIdentity(&tmMove))
			relemP->mapOvers[rbP->inum].btmov = FALSE;
		else
			relemP->mapOvers[rbP->inum].btmov = TRUE;

	}

	//if (baract == BAROVER_ACTION_GROUND)
	//{
	//	bo.isgnd = 1;
	//	relemP->mapOvers[bo.inum] = bo;
	//}

	if (baract == BAROVER_ACTION_DELETE)
	{

		// process fence if defined
		if (mdlFence_isDefined())
		{
			ScanCriteria* scP = NULL;
			UShort          typeMask[6];
			int status;

			for (UShort a = 0; a < 6; a++) typeMask[a] = 0;

			typeMask[0] = TMSK0_LINE | TMSK0_ARC | TMSK0_LINE_STRING | TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;

			scP = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanBarOverFence, relemP);
			status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
			status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
			mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
			status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
			status = mdlScanCriteria_free(scP);
		}
		else
		{
			bo.isdel = 1;
			relemP->mapOvers[bo.inum] = bo;
		}

	}

	if (baract == BAROVER_ACTION_RESET)
	{
		relemP->mapOvers.clear();
	}


}
