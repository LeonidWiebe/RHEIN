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

#include    <FontManager.h>

#include    <msdisplaypath.h>

#include    <cmdlist.h>
#include    <accudraw.h>

#include    <msrsrc.fdf>
#include    <msscan.fdf>



#if !defined (mdl)
extern "C"
{
	//	Alias for ustnTaskId if compiling native code C or C++
	//	Link with mdlbltin.lib
	extern char* ustnTaskIdP;
}	//	extern C
#endif

#include    <deprecated8_9.fdf>

#include "reincmd.h"

#endif

using namespace std;


#pragma warning(disable:4101) // unreferenced local variable
#pragma warning(disable:4189) // local variable is initialized but not referenced
//#pragma warning(disable:4018) // signed/unsigned mismatch
//#pragma warning(disable:4267) // conversion from 'size_t' to 'int', possible loss of data


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

#include "rein.fdf"



static DialogHookInfo uHooks[] =
{
{HOOKID_TOGGLE_DRAW,		(PFDialogHook)hookToggleDraw},
//{HOOKID_LICENSE,			(PFDialogHook)hookLicenseButton},
{HOOKID_DIALOG,				(PFDialogHook)hookModifyDialog},
{HOOKID_ANKERDIALOG,		(PFDialogHook)hookAnkerDialog},
{HOOKID_LISTCELL,			(PFDialogHook)hookListCellEditor},
{HOOKID_ANKER_VAL,			(PFDialogHook)hookAnkerChange},
{HOOKID_ANKER_BTN,			(PFDialogHook)hookAnkerButton},
{HOOKID_OPTION_TERM,		(PFDialogHook)hookOptionTerm},
{HOOKID_OPTION_DIAM,		(PFDialogHook)hookOptionDiam},
{HOOKID_SHOWOPTIONS,		(PFDialogHook)hookShowOptions},
{HOOKID_LISTBOX,	        (PFDialogHook)hookListBoxItem},
{HOOKID_REFCOMBO,	        (PFDialogHook)hookComboBoxItem},
{HOOKID_SHOWREFCOMBO,	    (PFDialogHook)hookComboRefShow},
//{HOOKID_LINSTCOMBO,	    (PFDialogHook)hookComboBoxLineStyle},
//{HOOKID_Combo_Model,	    (PFDialogHook)hookComboBoxModel},
{HOOKID_POSITION,	        (PFDialogHook)hookPosition},
#if defined (STD_INTERFACE)
{HOOKID_TOOLBOX,	        (PFDialogHook)hookToolBox},
#endif
{HOOKID_OPTION_PREF,		(PFDialogHook)hookOptionPref},
{HOOKID_NOTECOMBO,			(PFDialogHook)hookNoteCombo},
{HOOKID_LEVELCOMBO,			(PFDialogHook)hookLevelCombo},
};



/////////////////////////////////
extern "C" DLLEXPORT void cmdLogOpen(
	char* unparsedP
)
//cmdNumber   CMD_REIN_LOGOPEN
{

	openLogFile(FALSE);

}


/////////////////////////////////
extern "C" DLLEXPORT void cmdLogClose(
	char* unparsedP
)
//cmdNumber   CMD_REIN_LOGCLOSE
{
	closeLogFile();
}


/////////////////////////////////
extern "C" DLLEXPORT void cmdReinFront(
	char* unparsedP
)
//cmdNumber   CMD_REIN_FRONT
{


	iAC = CMD_REIN_FRONT;


	nSearchTypes = 2;
	searchType[0] = SHAPE_ELM;
	searchType[1] = CMPLX_SHAPE_ELM;

	startModify();


}




/////////////////////////////////
extern "C" DLLEXPORT void cmdReinSide(
	char* unparsedP
)
//cmdNumber   CMD_REIN_SIDE
{


	iAC = CMD_REIN_SIDE;


	nSearchTypes = 4;
	searchType[0] = SHAPE_ELM;
	searchType[1] = LINE_STRING_ELM;
	searchType[2] = CMPLX_SHAPE_ELM;
	searchType[3] = CMPLX_STRING_ELM;

	startModify();


}

/////////////////////////////////
extern "C" DLLEXPORT void cmdReinDups(
	char* unparsedP
)
//cmdNumber   CMD_REIN_DUPS
{


	iAC = CMD_REIN_DUPS;

	iClashShtamp++;

	clearClash(tcb->lstvw); // удаляется полностью, итерация по виду - в будущем

	checkDuplicates(tcb->lstvw);



}


/////////////////////////////////
extern "C" DLLEXPORT void cmdBarOverride(
	char* unparsedP
)
//cmdNumber   CMD_REIN_BAROVER
{
	iAC = CMD_REIN_BAROVER;

	nSearchTypes = 3;
	//searchType[0] = ARC_ELM;
	//searchType[1] = CMPLX_STRING_ELM;
	//searchType[2] = ELLIPSE_ELM;

	// ReinElm & ReinSpace
	nSearchTypes = 9;
	searchType[0] = SHAPE_ELM;
	searchType[1] = CMPLX_SHAPE_ELM;
	searchType[2] = LINE_ELM;
	searchType[3] = LINE_STRING_ELM;
	searchType[4] = CMPLX_STRING_ELM;
	searchType[5] = ARC_ELM;
	searchType[6] = CELL_HEADER_ELM;
	searchType[7] = SURFACE_ELM;
	searchType[8] = ELLIPSE_ELM;


	startModify();

}

/////////////////////////////////
extern "C" DLLEXPORT void cmdBarSet(
	char* unparsedP
)
//cmdNumber   CMD_REIN_BARSET
{


	iAC = CMD_REIN_BARSET;


	curNote.clear();

	if (mdlFence_isDefined())
	{
		barSetFenceProcess(0);

	}
	else
	{
		nSearchTypes = 3;
		searchType[0] = ARC_ELM;
		searchType[1] = CMPLX_STRING_ELM;
		searchType[2] = ELLIPSE_ELM;

		startModify();
	}


}




/////////////////////////////////
extern "C" DLLEXPORT void cmdReinLoads(
	char* unparsedP
)
//cmdNumber   CMD_REIN_LOADS
{


	iAC = CMD_REIN_LOADS;

	nSearchTypes = 7;
	searchType[0] = SHAPE_ELM;
	searchType[1] = CMPLX_SHAPE_ELM;
	searchType[2] = LINE_ELM;
	searchType[3] = LINE_STRING_ELM;
	searchType[4] = CMPLX_STRING_ELM;
	searchType[5] = ARC_ELM;
	searchType[6] = ELLIPSE_ELM;

	startModify();


}

/*
/////////////////////////////////////////////
int	reinSidePoint(
DVec3d    *pt,
int	    view)
{
	reinSideDynamics(pt, view, DRAW_MODE_Normal);

	return SUCCESS;
}
*/


/////////////////////////////////
extern "C" DLLEXPORT void cmdReinPlane( // NU
	char* unparsedP
)
//cmdNumber   CMD_REIN_PLANE
{

	//iAC = CMD_REIN_PLANE;

	//nSearchTypes = 2;
	//searchType [0] = SHAPE_ELM;
	//searchType [1] = CMPLX_SHAPE_ELM;

	//startModify();

	//reloadCurBarsAll();


}





/////////////////////////////////
extern "C" DLLEXPORT void cmdReinUnGrab(
	char* unparsedP
)
//cmdNumber   CMD_REIN_UNGRAB
{

	iAC = CMD_REIN_UNGRAB;

	nSearchTypes = 4;
	searchType[0] = SHAPE_ELM;
	searchType[1] = CMPLX_SHAPE_ELM;
	searchType[2] = CMPLX_STRING_ELM;
	searchType[3] = CELL_HEADER_ELM;


	startModify();


	//rInfo.rsVal.pts_org_cnt = 0;
	//rInfo.rsVal.pts_end_cnt = 0;

	//syncBarWindow(FALSE, 0);

}

/////////////////////////////////
extern "C" DLLEXPORT void cmdSavePlot(
	char* unparsedP
)
//cmdNumber   CMD_REIN_SAVEPLOT, CMD_REIN_SAVEPLOT_REFS
{

	//mdlInput_sendSynchronizedKeyin(L("FIT VIEW EXTENDED 1"), 0, INPUTQ_EOQ, L("REIN"));
	//mdlInput_sendReset(MSINPUTQ_HEAD, 0);

	//savePlotFile(); // with refs

	//mdlInput_sendSynchronizedKeyin(L("VIEW PREVIOUS 1"), 0, INPUTQ_EOQ, L("REIN"));

}

/////////////////////////////////
extern "C" DLLEXPORT void cmdSavePlotClear(
	char* unparsedP
)
//cmdNumber   CMD_REIN_SAVEPLOT_CLEAR
{

	ScanCriteria* scP = NULL;
	int status;

	ReinPrm prm;
	prm.ival[0] = -1; // delete cache
	prm.wstr = curPos_refpath;

	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanReinCache, &prm);
	status = mdlScanCriteria_setDrawnElements(scP);
	status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
	status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
	status = mdlScanCriteria_free(scP);


}


/////////////////////////////////
extern "C" DLLEXPORT void cmdReinChLap(
	char* unparsedP
)
//cmdNumber   CMD_REIN_CHLAP
{

	iAC = CMD_REIN_CHLAP;

	rInfo.rsOpt.lap[0] = 0;
	rInfo.rsOpt.lap[1] = 0;
	rInfo.rsOpt.lap[2] = 0;

	nSearchTypes = 9;
	searchType[0] = SHAPE_ELM;
	searchType[1] = CMPLX_SHAPE_ELM;
	searchType[2] = LINE_ELM;
	searchType[3] = LINE_STRING_ELM;
	searchType[4] = CMPLX_STRING_ELM;
	searchType[5] = ARC_ELM;
	searchType[6] = CELL_HEADER_ELM;
	searchType[7] = SURFACE_ELM;
	searchType[8] = ELLIPSE_ELM;

	startModify();

}

/////////////////////////////////
extern "C" DLLEXPORT void cmdReinModify(
	char* unparsedP
)
//cmdNumber   CMD_REIN_MODIFY
{

	iAC = CMD_REIN_MODIFY;

	rInfo.bars = 0;

	MSDLGP dbP = findToolBox();

	// ========= LOAD SCHEMA ==========
	loadSchemaFile(true, L("ReinModel"));
	// ================================

	if (mdlSelect_isActive())
	{
		nSearchTypes = 0;

		int		numSelected;
		DgnModelRefP* fileNums;
		UInt32* filePositions;
		MSElementDescr* edP = NULL;
		//ReinSpace rs;
		ReinElement relem;
		ReinBar rb;
		//ReinElm re;
		//    
		////mdlSystem_enterDebug();

		//mdlSelect_returnPositions (&filePositions, &fileNums, &numSelected);

		//for (int i = 0; i < numSelected, i++) 
		//{
		//	mdlElmdscr_readToMaster (&edP, filePositions[i], fileNums[i], FALSE, NULL);
		//	if (edP)
		//	{
		//		//....
		//		mdlElmdscr_freeAll(&edP);
		//	}
		//}


		mdlSelect_returnPositions(&filePositions, &fileNums, &numSelected);

		if (numSelected == 0) return;

		mdlElmdscr_readToMaster(&edP, filePositions[0], fileNums[0], FALSE, NULL);
		if (edP)
		{
			if (readReinSpaceFromElmd(&relem, edP, FALSE) == SUCCESS)
			{
				rInfo.rsVal.runmet = relem.rs.runmet;
				rInfo.rsVal.diam = relem.rs.diam;
				rInfo.rsVal.space = relem.rs.space;
				//rInfo.rsVal.space2 = relem.rs.space2;
				rInfo.rsVal.offset[0] = relem.rs.offset[0];
				rInfo.rsVal.offset[1] = relem.rs.offset[1];
				rInfo.rsVal.bendrad = relem.rs.bendrad;
				rInfo.rsVal.poscalc = relem.rs.poscalc;
				rInfo.rsVal.lap[0] = relem.rs.lap[0];
				rInfo.rsVal.lap[1] = relem.rs.lap[1];
				rInfo.rsVal.lap[2] = relem.rs.lap[2];
				rInfo.rsVal.trm[0] = relem.rs.trm[0];
				rInfo.rsVal.trm[1] = relem.rs.trm[1];
				rInfo.rsVal.trmPar = relem.rs.trmPar;
				//rInfo.rsVal.trmPar[0][0] = relem.rs.trmPar[0][0];
				//rInfo.rsVal.trmPar[0][1] = relem.rs.trmPar[0][1];
				//rInfo.rsVal.trmPar[1][0] = relem.rs.trmPar[1][0];
				//rInfo.rsVal.trmPar[1][1] = relem.rs.trmPar[1][1];
				//rInfo.rsVal.trmPar[2][0] = relem.rs.trmPar[2][0];
				//rInfo.rsVal.trmPar[2][1] = relem.rs.trmPar[2][1];
			}

			if (readReinBarFromElement(&rb, edP, TRUE) == SUCCESS)
			{
				rInfo.rsVal.runmet = rb.runmet;
				rInfo.rsVal.diam = rb.diam;
				rInfo.rsVal.space = rb.space;
				////rInfo.rsVal.space2 = rb.space2;
				rInfo.rsVal.offset[0] = rb.offset[0];
				rInfo.rsVal.offset[1] = rb.offset[1];
				rInfo.rsVal.bendrad = rb.bendrad;
				rInfo.rsVal.poscalc = rb.poscalc;
				rInfo.rsVal.lap[0] = rb.lap[0];
				rInfo.rsVal.lap[1] = rb.lap[1];
				rInfo.rsVal.lap[2] = rb.lap[2];
				rInfo.rsVal.trm[0] = rb.term[0];
				rInfo.rsVal.trm[1] = rb.term[1];

				for (int i = 0; i < 10; i++)
				{
					rInfo.rsVal.trmPar[i][0] = rb.termPar[i][0];
					rInfo.rsVal.trmPar[i][1] = rb.termPar[i][1];
				}
				//rInfo.rsVal.trmPar[0][1] = rb.termPar[0][1];
				//rInfo.rsVal.trmPar[1][0] = rb.termPar[1][0];
				//rInfo.rsVal.trmPar[1][1] = rb.termPar[1][1];
				//rInfo.rsVal.trmPar[2][0] = rb.termPar[2][0];
				//rInfo.rsVal.trmPar[2][1] = rb.termPar[2][1];
			}


			mdlElmdscr_freeAll(&edP);

		}

		rInfo.rsOpt.clear();
		rInfo.bars = mdlSelect_numSelected();
		syncToolbox();

		mdlState_startModifyCommand(NULL, (MdlFunc_Accept)reinChangeSelected, NULL, NULL, NULL, 0, 0, TRUE, 1);

		mdlOutput_prompt(L("Укажите галкой параметры, подтвердите изменение"));
	}
	else
	{
		nSearchTypes = 9;
		searchType[0] = SHAPE_ELM;
		searchType[1] = CMPLX_SHAPE_ELM;
		searchType[2] = LINE_ELM;
		searchType[3] = LINE_STRING_ELM;
		searchType[4] = CMPLX_STRING_ELM;
		searchType[5] = ARC_ELM;
		searchType[6] = CELL_HEADER_ELM;
		searchType[7] = SURFACE_ELM;
		searchType[8] = ELLIPSE_ELM;


		if (NULL != dbP)
		{
			DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_Text, TEXTID_BarsForChange, 0);

			//if (diP) mdlDialog_itemHide(dbP, diP->itemIndex, TRUE);

			//mdlDialog_adjustPopDownHeight(dbP);


			if (iCfgVar_BarBendTypeAuto)
			{
				diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_OptionButton, 51, 0);
				if (diP) mdlDialog_optionButtonSetEnabled(diP->rawItemP, 2, FALSE);
				if (diP) mdlDialog_optionButtonSetEnabled(diP->rawItemP, 3, FALSE);
				if (diP) mdlDialog_optionButtonSetEnabled(diP->rawItemP, 4, FALSE);
			}


		}

		rInfo.rsVal.elid = 0; // создаем новый ReinData
		rInfo.rsVal.contnum = 0;

		// обнуление разбежки
		rInfo.rsVal.lap[0] = 0;
		rInfo.rsVal.lap[1] = 0;
		rInfo.rsVal.lap[2] = 0;

		rInfo.rsOpt.clear();
		syncToolbox();

		startModify();
	}

	checkOptionTermItems(dbP, TRUE);



}

/////////////////////////////////
// команда: разбивка линейного контура
// на основе производных стержней создает образуюший ReinBar
// снимает атрибут образующего элемента с образующих линий
// аргументы: нет
extern "C" DLLEXPORT void cmdReinDrop(
	char* unparsedP
)
//cmdNumber   CMD_REIN_DROP
{

	iAC = CMD_REIN_DROP;

	nSearchTypes = 5;
	searchType[0] = LINE_ELM;
	searchType[1] = LINE_STRING_ELM;
	searchType[2] = CMPLX_STRING_ELM;
	searchType[3] = ARC_ELM;
	searchType[4] = ELLIPSE_ELM;

	//nSearchTypes = 9;
	//searchType[0] = SHAPE_ELM;
	//searchType[1] = CMPLX_SHAPE_ELM;
	//searchType[2] = LINE_ELM;
	//searchType[3] = LINE_STRING_ELM;
	//searchType[4] = CMPLX_STRING_ELM;
	//searchType[5] = ARC_ELM;
	//searchType[6] = CELL_HEADER_ELM;
	//searchType[7] = SURFACE_ELM;
	//searchType[8] = ELLIPSE_ELM;


	startModify();


}


/////////////////////////////////
// команда: разбивка линейного контура
// показать скрытые элементы и обратно
// аргументы: нет
extern "C" DLLEXPORT void cmdReinVisit(
	char* unparsedP
)
//cmdNumber   CMD_REIN_VISIT
{


	//if (unparsedP)
	{
		ScanCriteria* scP = NULL;
		//UShort          typeMask[6];
		int status;

		//for (UShort a = 0; a < 6; a++) typeMask[a] = 0;
		//typeMask[0] = TMSK0_LINE | TMSK0_ARC | TMSK0_LINE_STRING | TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;

		//int a = atoi(unparsedP);

		//NamedGroupP ngP = NULL;

		//if (mdlNamedGroup_findByName(&ngP, 0, 0, L"__UNVISIBLE", ACTIVEMODEL) != SUCCESS)
		//{
		//	mdlNamedGroup_create(&ngP, L"__UNVISIBLE", L"", 
		//									0, // NGFLAG_ANONYMOUS 
		//									ACTIVEMODEL);
		//}

		if (unparsedP && strcmp(unparsedP, "check") == 0)
		{
			getCatInfo(&curCat, ACTIVEMODEL, false);

			if (curCat.catID == 0 || SLEN(curCat.catname) == 0)
			{
				mdlOutput_messageCenter(MESSAGE_WARNING, L("Для экспорта модели должен быть назначен каталог Offtake"), L(""), MESSAGE_ALERT_BALLOON);
				return;
			}
		}


		if (unparsedP && strcmp(unparsedP, "axes") == 0)
			bExportSolids = false;
		else
			bExportSolids = true;


		//SCPM2W(wss, curCat.catname, 200);
		DgnModelRefP mrP = getOrCreateModel(L"Export Assembly", ACTIVEMODEL);

		// todo: visit (export to assembly)

		if (mrP)
		{
			saveThisFileIsModel(mrP, MODTYPE_ASSEMBLY, false);

			if (!curCat.bAutoCats) // non model category
				saveCatInfo(mrP);

			//deleteReinElms(0, FALSE, NULL, mrP);

			//dlgProgressP = mdlDialog_completionBarOpen(L("Экспорт..."));


			scP = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanJustDeleteElement, NULL);
			//status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
			status = mdlScanCriteria_setDrawnElements(scP);
			status = mdlScanCriteria_setModel(scP, mrP);
			mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinAssem);
			status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
			status = mdlScanCriteria_free(scP);

			elemCount4 = 0;
			/*
			scP = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanElemCount, &elemCount4);
			//status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
			status = mdlScanCriteria_setDrawnElements(scP);
			status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
			mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
			status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
			status = mdlScanCriteria_free(scP);

			// референсы
			{
				ModelRefIteratorP  iterator;
				DgnModelRefP	modelRef;

				mdlModelRefIterator_create(&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, -1); // nested

				while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
				{
					BINT isOn = FALSE;
					mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
					if (isOn == FALSE) continue;

					if (getReinModelType(modelRef) == MODTYPE_CAGE)
					{
						scP = mdlScanCriteria_create();
						status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
						status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanElemCount, &elemCount4);
						//status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
						status = mdlScanCriteria_setDrawnElements(scP);
						status = mdlScanCriteria_setModel(scP, modelRef);
						//mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
						status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
						status = mdlScanCriteria_free(scP);
					}
					else
					{
						//...
					}
				}

				mdlModelRefIterator_free(&iterator);

			}
			*/
			elemIterCount4 = 0;

			scP = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanReinElmExport, mrP);
			//status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
			status = mdlScanCriteria_setDrawnElements(scP);
			status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
			mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
			status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
			status = mdlScanCriteria_free(scP);


			// референсы
			{
				ModelRefIteratorP  iterator;
				DgnModelRefP	modelRef;

				mdlModelRefIterator_create(&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, -1); // nested

				while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
				{
					BINT isOn = FALSE;
					mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
					if (isOn == FALSE) continue;

					if (getReinModelType(modelRef) == MODTYPE_CAGE)
					{
						MSWCH         mName[MAX_MODEL_NAME_LENGTH];

						mdlModelRef_getModelName(modelRef, mName);

						LEVID iLevID = getOrCreateLevel(mrP, L"Cages", true);

						MSElementDescr* edpCage = NULL;

						mdlCell_create(&eCell, NULL, NULL, FALSE);
						mdlElmdscr_new(&edpCage, NULL, &eCell);

						scP = mdlScanCriteria_create();
						status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
						status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanCageElmExport, &edpCage);
						status = mdlScanCriteria_setDrawnElements(scP);
						status = mdlScanCriteria_setModel(scP, modelRef);
						//mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm); // all elements include plates, angles itd (cages to cell!)
						status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
						status = mdlScanCriteria_free(scP);

						XMLFragmentListP pCurrent = makeXmlForCage(mName, iLevID);
						mdlXMLFragmentList_attachToElement(&pCurrent, &edpCage, TRUE);

						func_amp(mdlElmdscr_setProperties, edpCage), & iLevID, 0, 0, 0, 0, 0, 0, 0);

						Transform tm;
						mdlTMatrix_referenceToMaster(&tm, modelRef);
						func_amp(mdlElmdscr_transform, edpCage), & tm);


						UInt32 fp = mdlElmdscr_addByModelRef(edpCage, mrP);

						mdlElmdscr_freeAll(&edpCage);
					}
					else
					{
						//...
					}


				}

				mdlModelRefIterator_free(&iterator);

			}


			mdlModelRef_freeWorking(mrP);

			//if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);


			//mdlNamedGroup_writeToFile(ngP, TRUE);
			//mdlNamedGroup_free(&ngP);
		}



	}

}

/////////////////////////////////
extern "C" DLLEXPORT void cmdToolBox(
	char* unparsedP
)
//cmdNumber   CMD_REIN_TOOLBOX
{

#if defined (STD_INTERFACE)

	if (rfHandle) 
		mdlDialog_open(rfHandle, DIALOG_TOOLBOX);


	if (rfHandle) 
		mdlDialog_open(rfHandle, DLG_SKETCH);

#endif
}

/////////////////////////////////
extern "C" DLLEXPORT void cmdAnker(
	char* unparsedP
)
//cmdNumber   CMD_REIN_ANKER
{
	//if (rfHandle) 
		//mdlDialog_open(0, 5);
}

/////////////////////////////////
extern "C" DLLEXPORT void cmdConcrete(
	char* unparsedP
)
//cmdNumber   CMD_REIN_CONCRETE
{

	ReinPrm prm;
	//MSElementDescr* edP = NULL;
	DPoint3d prng[2];
	ScanRange sr;
	UInt32 cnt = 0;
	UInt32 cnts = 0;
	double dTol = 5.;

#if defined (AECOSIM)
#else
	mdlOutput_messageCenterW(MESSAGE_INFO, L"This command works only in Rhein version for AECOsim", L"", MESSAGE_ALERT_DIALOG);
	return;
#endif


#if defined (MSVERSION) && (MSVERSION == 0xa00)
	BeFileName   fileName;
#else
	WCH  fileName[MAXFILELENGTH];
#endif

	WCH  sfileName[MAXFILELENGTH];
	WCH  afileName[MAXFILELENGTH];

	mdlModelRef_getFileName(ACTIVEMODEL, afileName, MAXFILELENGTH);
	mdlFile_parseName(afileName, 0, 0, afileName, 0);

	SPRN(sfileName, L("%s%s"), afileName, L("_concrete_report.csv"));

	if (mdlDialog_fileCreate(fileName, 0, 0, sfileName, L("*.csv"), L("_DGNDIR"), L("select file"))) 
		return; // if Cancel button

	FILE* ff = FOPENW(fileName);

	if (ff == NULL)
	{
		mdlOutput_messageCenterW(MESSAGE_INFO, L"cannot create file", L"", MESSAGE_ALERT_DIALOG);
		return;
	}
	else
		FCLOSE(ff);


	mapSimPos.clear();

	dlgProgressP = mdlDialog_completionBarOpen(L("Process..."));

	for (MAP<UInt32, ReinElm>::iterator it = curRM->mapElms.begin(); it != curRM->mapElms.end(); ++it)
	{
		//prng[0] = it->second.bel.rpts[0];
		//prng[1] = it->second.bel.rpts[0];

		prm.reP = &(it->second);

		/*

		for (int i = 1; i < it->second.bel.numpts; i++)
		{
			if (it->second.bel.rpts[i].x < prng[0].x) prng[0].x = it->second.bel.rpts[i].x;
			if (it->second.bel.rpts[i].y < prng[0].y) prng[0].y = it->second.bel.rpts[i].y;
			if (it->second.bel.rpts[i].z < prng[0].z) prng[0].z = it->second.bel.rpts[i].z;

			if (it->second.bel.rpts[i].x > prng[1].x) prng[1].x = it->second.bel.rpts[i].x;
			if (it->second.bel.rpts[i].y > prng[1].y) prng[1].y = it->second.bel.rpts[i].y;
			if (it->second.bel.rpts[i].z > prng[1].z) prng[1].z = it->second.bel.rpts[i].z;
		}


		sr.xlowlim = (Int64)(prng[0].x - mdlCnv_masterUnitsToUors(dTol));
		sr.ylowlim = (Int64)(prng[0].y - mdlCnv_masterUnitsToUors(dTol));
		sr.zlowlim = (Int64)(prng[0].z - mdlCnv_masterUnitsToUors(dTol));

		sr.xhighlim = (Int64)(prng[1].x + mdlCnv_masterUnitsToUors(dTol));
		sr.yhighlim = (Int64)(prng[1].y + mdlCnv_masterUnitsToUors(dTol));
		sr.zhighlim = (Int64)(prng[1].z + mdlCnv_masterUnitsToUors(dTol));
*/

		prm.prmid = 0; // флаг для избежания повторного суммирования


		for (int i = 0; i < it->second.bel.numpts; i++)
		{
			sr.xlowlim = (Int64)(it->second.bel.rpts[i].x - mdlCnv_masterUnitsToUors(dTol));
			sr.ylowlim = (Int64)(it->second.bel.rpts[i].y - mdlCnv_masterUnitsToUors(dTol));
			sr.zlowlim = (Int64)(it->second.bel.rpts[i].z - mdlCnv_masterUnitsToUors(dTol));

			sr.xhighlim = (Int64)(it->second.bel.rpts[i].x + mdlCnv_masterUnitsToUors(dTol));
			sr.yhighlim = (Int64)(it->second.bel.rpts[i].y + mdlCnv_masterUnitsToUors(dTol));
			sr.zhighlim = (Int64)(it->second.bel.rpts[i].z + mdlCnv_masterUnitsToUors(dTol));

			prm.pVec = it->second.bel.rpts[i];

			// активный файл пропускаем, только референсы
			{
				int status = 0;
				ModelRefIteratorP  iterator;
				DgnModelRefP	modelRef;
				ScanCriteria* scP = NULL;

				UShort          typeMask[6];
				for (UShort a = 0; a < 6; a++) typeMask[a] = 0;
				typeMask[0] = TMSK0_CELL_HEADER;

				mdlModelRefIterator_create(&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, 0); // no nested

				while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
				{

					BINT isOn = FALSE;
					mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
					if (isOn == FALSE) continue;

					scP = mdlScanCriteria_create();
					status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
					//status = mdlScanCriteria_setElemRefCallback (scP, (PFScanElemRefCallback)scanSpaceCheckPoint, pAtrP);
					status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanElemPointInside, &prm);
					status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
					status = mdlScanCriteria_setModel(scP, modelRef);
					// !!!!!!!!!!!!!!!!!
					mdlScanCriteria_setRangeTest(scP, &sr);
					// !!!!!!!!!!!!!!!!!
					status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
					status = mdlScanCriteria_free(scP);

					//printf(".");

				}

				mdlModelRefIterator_free(&iterator);

			}
		}


		if (prm.prmid == 0) // висим в воздухе
		{ 
			STRING str(L("NoMatch;"));
			mapSimPos[str].mapprm[it->second.bel.pnum].uival[0]++; // file qty
			cnts++;

			ELREF eref = getElemRefByFPos(ACTIVEMODEL, it->second.bel.ffpos[REIN_ELEM_ISO], TRUE);
			//ELREF eref = dgnCache_findElemByFilePos(mdlModelRef_getCache(ACTIVEMODEL), it->second.bel.ffpos[REIN_ELEM_ISO], TRUE);
			if (eref)
			{
				ELID id = elementRef_getElemID(eref);

				//mapSimPos[str].mapprm[it->second.bel.pnum].sids.insert(id);

				//UInt32 iid = (UInt32)id;
				//curRM->vExFps.push_back(iid);

				it->second.elemflags |= REINEL_FLAG_NMCH;

				//MSElementDescr* edP = NULL;
				//mdlElmdscr_read(&edP, it->second.bel.ffpos[REIN_ELEM_ISO], ACTIVEMODEL, FALSE, 0);

				//if (edP)
				//{
				//	MSElementDescr* edLnP = NULL;
				//	mdlElmdscr_duplicate(&edLnP, edP);
				//	UInt32 clr = 3;
				//	UInt32 wgt = 15;
				//	mdlElmdscr_setSymbology(edLnP, &clr, 0, &wgt, 0);
				//	TransDescrP tedP = mdlTransient_addElemDescr(NULL, edLnP, TRUE, 0x00ff, DRAW_MODE_Normal, 1, 0, 0);
				//}

				mapSimPos[str].mapprm[it->second.bel.pnum].vsnaps.push_back(it->second.bel.rpts[0]);

			}


		}

		SPRN(s, L("%i, no match: %i"), cnt, cnts);

		cnt++;
		mdlDialog_completionBarUpdate(dlgProgressP, s, (int)(((double)cnt / (double)curRM->mapElms.size()) * 100.));
		WaitMessage();

		//if (cnt > 3000) break; // tmp
	}

	if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);




	FILE* f = FOPENW(fileName);

	if (f)
	{
		for (map <STRING, ReinPrm>::iterator it = mapSimPos.begin(); f && it != mapSimPos.end(); ++it)
		{
			WCH str[1000];

#if defined (MSVERSION) && (MSVERSION == 0xa00)	
			//mdlCnv_convertMultibyteToUnicode(it->first.c_str(), -1, str, 1000);
			wcscpy(str, it->first.c_str());
#else
			strcpy(str, it->first.c_str());
#endif
			mdlTextFile_putString(str, f, TEXTFILE_DEFAULT);
			SPRN(str, L("position;pieces;meters"));
			mdlTextFile_putString(str, f, TEXTFILE_DEFAULT);

			for (MAP<long, reinprm>::iterator itt = it->second.mapprm.begin(); itt != it->second.mapprm.end(); ++itt)
			{
				SPRN(str, L("%i;%u;%.3f"), itt->first, itt->second.uival[0], itt->second.dval[0] / 1000.);

				mdlTextFile_putString(str, f, TEXTFILE_DEFAULT);

				for (vector <DVec3d>::iterator its = itt->second.vsnaps.begin(); its != itt->second.vsnaps.end(); ++its)
				{
					//SPRN(str, L(";;;%I64u"), *its);
					SPRN(str, L(";;;%.0f,%.0f,%.0f"), mdlCnv_uorsToMasterUnits(its->x), mdlCnv_uorsToMasterUnits(its->y), mdlCnv_uorsToMasterUnits(its->z));
					mdlTextFile_putString(str, f, TEXTFILE_DEFAULT);
				}
			}
		}

		FCLOSE(f);

		//mdlOutput_messageCenterW(MESSAGE_INFO, L"file created", L"", MESSAGE_ALERT_BALLOON);

		//mdlCnv_convertMultibyteToUnicode(sss, 5000, wsss, 5000);


#if defined (MSVERSION) && (MSVERSION == 0xa00)	
		SPRN(sss, L("%%excel \"%s\""), fileName.c_str());
		mdlInput_sendSynchronizedKeyin(sss, false, MSInputQueuePos::INPUTQ_HEAD, 0);
#else
		sprintf(sss, "%%excel \"%s\"", fileName);
		MSCharCP wscp = (MSCharCP)sss;
		mdlInput_sendSynchronizedKeyin(wscp, 0, 0, 0);
#endif

	}
	else
	{
		mdlOutput_messageCenterW(MESSAGE_INFO, L"error create file", L"", MESSAGE_ALERT_BALLOON);
	}



}

/////////////////////////////////
extern "C" DLLEXPORT void cmdReinVersion(
	char* unparsedP
)
//cmdNumber   CMD_REIN_VERSION
{

	MSWCH wsapp[100];

#if defined (AECOSIM)
	wcscpy(wsapp, L"for AECOsim");
#else
	wcscpy(wsapp, L"for MicroStation");
#endif

	_swprintf(wss, L"RHEIN %s, version %u.%u.%u.%u (c) Wiebe apps  \nCompilation %s %s",
		wsapp, VERSAPP, VERSMAJ, VERSMID, VERSMIN, VERDATE, VERTIME);

	//#if defined (MSVERSION) && (MSVERSION == 0xa00)
	//	mdlOutput_messageCenter(MESSAGE_INFO, wss, wss, MESSAGE_ALERT_BALLOON);
	//#else
	mdlOutput_messageCenterW(MESSAGE_INFO, wss, wss, MESSAGE_ALERT_BALLOON);
	//#endif
}


/////////////////////////////////
extern "C" DLLEXPORT void cmdShowTooltip(
	char* unparsedP
)
//cmdNumber   CMD_REIN_TOOLTIP
{

	WCH v[500];

	//if (getCfgVarEx(v, L"REIN_VIEW_CACHE_SHOW") == SUCCESS)
	//	iCfgVar_ViewCacheWorkShow = STOI(v);
	//else
	//	iCfgVar_ViewCacheWorkShow = 1;


	saveThisFileIsModel();

	//if (iCfgVar_ViewCacheWorkShow == 0) updateAllViews();

}


/////////////////////////////////
extern "C" DLLEXPORT void cmdReload(
	char* unparsedP
)
//cmdNumber   CMD_REIN_RELOAD
{

	checkThisFileIsModel(ACTIVEMODEL);

	int iStep = 0;
	int bRegen = TRUE;

	if (unparsedP &&
		(strcmp(unparsedP, "NOREGEN") == 0
			|| strcmp(unparsedP, "3") == 0)
		)
	{
		bRegen = FALSE;
	}


	if (unparsedP && strcmp(unparsedP, "1") == 0)
	{
		iStep = 1; // only delete
	}

	if (unparsedP && strcmp(unparsedP, "2") == 0)
	{
		iStep = 2; // only build
	}

	if (unparsedP && strcmp(unparsedP, "axes") == 0)
	{
		iStep = 4; // only axes
	}

	if (unparsedP && strcmp(unparsedP, "axes delete") == 0)
	{
		iStep = 5; // only axes
	}


	reloadBarsData(0, bRegen, iStep);

	//mdlSystem_flushDesignFile();


}

/////////////////////////////////
//extern "C" DLLEXPORT void cmdMuftShow(
//char	*unparsedP
//)
////cmdNumber   CMD_REIN_MUFTSHOW
//{
//	//createTransMufts();
//}

/////////////////////////////////
extern "C" DLLEXPORT void cmdCages(
	char* unparsedP
)
//cmdNumber   CMD_REIN_CAGES
{
	mdlVBA_runMacro(L("arm"), L("main"), L("getCages"));
}


/////////////////////////////////
extern "C" DLLEXPORT void cmdBarEndsDialog(
	char* unparsedP
)
//cmdNumber   CMD_REIN_BARENDS_DIALOG
{



	if (rfHandle) 
		mdlDialog_open(rfHandle, DLG_BARENDS);
}


void ZeroTrackBar(TrackBarInfo* tbiP)
{

	//typedef struct trackbarinfo
	//{
	//	int		    update;
	//	long	    percentComplete1;
	//	long	    percentComplete2;
	//	char	    msgText1[256];
	//	char	    msgText2[256];
	//} TrackBarInfo;

	tbiP->update = 0;
	tbiP->percentComplete1 = 0;
	tbiP->percentComplete1 = 0;
	SCPY(tbiP->msgText1, L("\0\0\0"));
	SCPY(tbiP->msgText2, L("\0\0\0"));

}


/////////////////////////////////
extern "C" DLLEXPORT void cmdBarEnds(
	char* unparsedP
)
//cmdNumber   CMD_REIN_BARENDS
{

	elemCount2 = 0;
	elemIterCount2 = 0;
	iBarEndsCount = 0;
	iBarCapsCount = 0;

	ModelRefIteratorP  iterator;
	DgnModelRefP	modelRef;


	ZeroTrackBar(&tbi);

	tbi.update = UPDATE_Percent1 | UPDATE_Msg1;

	SCPY(tbi.msgText1, L("Определение количества выпусков"));
	SCPY(tbi.msgText2, L("Определение количества выпусков"));


	if (rDopInfo.dopopt[5]) mdlLocate_clearHilited(TRUE);


	getReinElmCount(TRUE, ACTIVEMODEL, &elemCount2); // >>>>>>>>>>>>>>>


	if (rDopInfo.dopopt[4])
	{
		mdlModelRefIterator_create(&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, 0);

		while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
		{
			BINT isOn = FALSE;
			mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
			if (isOn == FALSE) continue;

			getReinElmCount(FALSE, modelRef, &elemCount2); // >>>>>>>>>>>>>>>
		}


		mdlModelRefIterator_free(&iterator);
	}



	if (elemCount2 == 0) return;



	//=================================================
	//mdlDialog_trackBarStartProcessing(NULL, NULL, NULL, NULL, L("Отменено"), 0, &tbi, L(""));
	dlgProgressP = mdlDialog_completionBarOpen(L("Выпуски"));

	getBarEndsCount(ACTIVEMODEL);


	if (rDopInfo.dopopt[4])
	{
		mdlModelRefIterator_create(&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, 0);

		while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
		{
			BINT isOn = FALSE;
			mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
			if (isOn == FALSE) continue;

			getBarEndsCount(modelRef);
		}


		mdlModelRefIterator_free(&iterator);
	}


	//mdlDialog_trackBarStopProcessing();
	if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);
	//========================================================

	//sprintf(s, "%u выпусков", iBarEndsCount);
	//mdlDialog_openMessageBox(DIALOGID_MsgBoxOK, s, MSGBOX_ICON_INFORMATION);


	MSDLGP dbP;

	if (NULL != (dbP = mdlDialog_find(DLG_BARENDS, NULL)))
		mdlDialog_itemsSynch(dbP);





}

/////////////////////////////////
extern "C" DLLEXPORT void cmdHideposDel(
	char* unparsedP
)
//cmdNumber   CMD_REIN_HPDEL
{

	elemIterCount2 = 0;

	deleteBarSetInfo(TRUE);

	mdlDialog_dmsgsClear();
	SPRN(s, L("deleted %u bar set elems"), elemIterCount2);
	mdlDialog_dmsgsPrint(s);


	reloadHidingPositions();
}

/////////////////////////////////
extern "C" DLLEXPORT void cmdHidepos(
	char* unparsedP
)
//cmdNumber   CMD_REIN_HPINFO
{

	mdlDialog_dmsgsClear();


	CatInfo ci;
	getCatInfo(&ci, ACTIVEMODEL, false, false);

	SPRN(s, L("proj %i, cat %i"), ci.projID, ci.catModID);

	mdlDialog_dmsgsPrint(L("======= CATALOG INFO ======"));
	mdlDialog_dmsgsPrint(s);

	mdlDialog_dmsgsPrint(L("======= HIDING POSITIONS INFORMATION ======"));


	//int rn = -1;
	//if (strlen(unparsedP) > 0)
	//{
	//	rn = atoi(unparsedP);
	//	sprintf(s, "        FOR REFERENCE %i", rn);
	//	mdlDialog_dmsgsPrint(s);
	//}
	//else
	//{
	//	mdlDialog_dmsgsPrint(L"        FOR ALL REFERENCES (no arguments in hpinfo)\n");
	//}


	if (daCurPosHide.size() == 0) mdlDialog_dmsgsPrint(L("no hiding positions"));

	for (vector<ReinPos>::iterator rpItP = daCurPosHide.begin(); rpItP != daCurPosHide.end(); ++rpItP)
	{
		STRING sttr = L("");
		//SCPY(ss, L(""));

		for (deque<UInt32>::reverse_iterator it = rpItP->arefnum.rbegin(); it != rpItP->arefnum.rend(); ++it)
		//for (int i = MAX_REFNUM_PATH - 1; i >= 0; i--)
		{
			//if (rpItP->arefnum[i] > 0)
			{
				WCH locstr[50];
				SPRN(locstr, L("[%u]"), *it);
				//SCAT(ss, sss);
				sttr.append(locstr);
			}
		}

		//if (rn < 0 || rn == rpItP->arefnum[0])
		{
			SPRN(s, L("pos=%i ref=%s cat=%i    %i %i %i %i %i"), rpItP->bar.pnum, sttr.c_str(), rpItP->pcatID,
				rpItP->drawopt[DROPT_A],
				rpItP->drawopt[DROPT_V],
				rpItP->drawopt[DROPT_X],
				rpItP->drawopt[DROPT_O],
				rpItP->drawopt[DROPT_S]);
			mdlDialog_dmsgsPrint(s);
		}
	}


	if (mapBarSet.size() == 0) mdlDialog_dmsgsPrint(L("no barset positions"));
	else
	{

		SPRN(s, L("======= BARS SETTINGS INFORMATION ====== (%u elements)"), (UInt32)mapBarSet.size());
		mdlDialog_dmsgsPrint(s);

		barSetFenceProcess(-1);

		for (map <wstring, ReinPos>::iterator rpItP = mapBarSet.begin(); rpItP != mapBarSet.end(); ++rpItP)
		{
			//ReinPos* rpP = *rpItP;
			//ReinPos* rpItP = &(daCurBarSet[i]);
			{
				STRING sttr = L("");
				//SCPY(ss, L(""));
				for (deque<UInt32>::reverse_iterator it = rpItP->second.arefnum.rbegin(); it != rpItP->second.arefnum.rend(); ++it)
				//for (int i = MAX_REFNUM_PATH - 1; i >= 0; i--)
				{
					//if (rpItP->second.arefnum[i] > 0)
					{
						WCH locstr[50];
						SPRN(locstr, L("[%u]"), *it);
						//SCAT(ss, sss);
						sttr.append(locstr);
					}
				}

				SPRN(s, L("drawmode = %i, inum = %i, ref = %s, elemid = %I64u, bFromRef = %d"),
					rpItP->second.drawmode, rpItP->second.bar.inum, ss, rpItP->second.bar.elemid, rpItP->second.bFromRef);
				mdlDialog_dmsgsPrint(s);
			}
		}
	}



	mdlDialog_dmsgsPrint(L("======= SHOW SETTINGS INFORMATION ======"));

	ScanCriteria* pScanCriteria;
	int status;
	ReinPrm prm;
	prm.ival[0] = 1; // report

	pScanCriteria = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(pScanCriteria, (PFScanElemDscrCallback)scanCheckShowInfo2, &prm);
	status = mdlScanCriteria_setModel(pScanCriteria, ACTIVEMODEL);
	mdlXML_addXMLFragmentElementScanTest(pScanCriteria, &appID, &appTypeShowInfo);
	status = mdlScanCriteria_scan(pScanCriteria, NULL, NULL, NULL);
	status = mdlScanCriteria_free(pScanCriteria);


	mdlDialog_dmsgsPrint(L("======= BASE LAPS ======"));

	for (vector<ReinLap>::iterator rlP = daBaseLaps.begin(); rlP != daBaseLaps.end(); ++rlP)
	{
		if (rlP->projID == curCat.projID)
		{
			SPRN(s, L("projID = %i, diameter = %i, muft = %i, lapValue = %i, maxlen = %i, bendrad = %i (%i)"),
				rlP->projID, rlP->diameter, rlP->muft, rlP->lapValue, rlP->maxlen, rlP->bendrad, fillets[rlP->diameter].radius);
			mdlDialog_dmsgsPrint(s);
		}
	}

	mdlDialog_dmsgsPrint(L("======= ALLES ======"));


}


/////////////////////////////////
extern "C" DLLEXPORT void cmdMuft( //todo: муфты
	char* unparsedP
)
//cmdNumber   CMD_REIN_MUFT 
{

	//ZeroMemory(muftqtyext, sizeof(muftqtyext));
	//ZeroMemory(skobqtyext, sizeof(skobqtyext));
	//ZeroMemory(skobqtydop, sizeof(skobqtydop));

	for (int a = 0; a < 50; a++)
	{
		for (int b = 0; b < 50; b++)
		{
			for (int c = 0; c < 10; c++)
			{
				muftqtyext[a][b][c] = 0;
			}
			skobqtyext[a][b] = 0;
			skobqtydop[a][b] = 0;
		}
	}

	long muft_cmn_qty = 0;
	long skob_cmn_qty = 0;
	long vkld_cmn_qty = 0;

	elemIterCount = 0;
	elemIterCount2 = 0;

	//int bScanReducers = FALSE; // считать переходные муфты

	long iMuftCount = 0;
	long iMuftCountRefs = 0;

	ScanCriteria* scP = NULL;
	UShort          typeMask[6];
	int status;

	for (UShort a = 0; a < 6; a++) typeMask[a] = 0;
	typeMask[0] = TMSK0_LINE | TMSK0_ARC | TMSK0_LINE_STRING | TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;

	ZeroTrackBar(&tbi);
	tbi.update = UPDATE_Percent1 | UPDATE_Percent2 | UPDATE_Msg1 | UPDATE_Msg2;


	// первый проход - количество ReinElm в активной модели - количество муфт/скоб
	// второй проход - проверка стыков (переходная или нет) в активной модели и референсах

	// iMuftCount - количеств муфт без учета переходов в активной модели и видимых референсах
	// elemCount2 - количество элементов ReinElm, которые могут быть подсоединены к муфтам 
	// в активной модели и видимых референсах (для дальнейшей проверки и расчета переходных)

	// получаем iMuftCount (количество муфт), также считаем муфты при превышении длины стержня
	//=================================================

	iMuftCount = 0; // количество элементов муфт/скоб без учета превышения длины стержня
	elemCount2 = 0; // количество элементов ReinElm

	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanMuftCount, &iMuftCount);
	status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
	status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
	mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
	status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
	status = mdlScanCriteria_free(scP);


	iMuftCountRefs = iMuftCount;


	// референсы
	{
		ModelRefIteratorP  iterator;
		DgnModelRefP	modelRef;

		mdlModelRefIterator_create(&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, 0); // no nested

		while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
		{

			BINT isOn = FALSE;
			mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
			if (isOn == FALSE) continue;

			scP = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanMuftCount, &iMuftCountRefs);
			status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
			status = mdlScanCriteria_setModel(scP, modelRef);
			mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
			status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
			status = mdlScanCriteria_free(scP);

		}

		mdlModelRefIterator_free(&iterator);

	}


	if (strlen(unparsedP) == 0) // если с референсами
		iMuftCount = iMuftCountRefs;


	//SPRN(s, L("Считать переходные муфты?\nЭто может занять несколько десятков минут."));
	//int res = mdlDialog_openMessageBox (DIALOGID_MsgBoxYesNo, s, MSGBOX_ICON_INFORMATION);



	// создание массива вершин для расчета переходов
	//=================================================


	//if (daMufts) 
	//{
	//	mdlDArray_destroy (daMufts);
	//	daMufts = NULL;
	//}

	//daMufts = mdlDArray_create (sizeof (ArrayObjectHdr), sizeof(ReinVert), iMuftCount, 0, 0);  

	daMufts.clear();

	daMufts.resize(iMuftCount);

	// заполнение массива daMufts
	//=================================================

	elemCount = 0; // индекс заполнения daMufts

	scP = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
	status = mdlScanCriteria_setModel(scP, ACTIVEMODEL);
	status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanMuftInArray, NULL);
	mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
	status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
	status = mdlScanCriteria_free(scP);

	// референсы
	if (strlen(unparsedP) == 0)
	{
		ModelRefIteratorP  iterator;
		DgnModelRefP	modelRef;

		mdlModelRefIterator_create(&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, 0); // no nested

		while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
		{

			BINT isOn = FALSE;
			mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
			if (isOn == FALSE) continue;

			scP = mdlScanCriteria_create();
			status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
			status = mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
			status = mdlScanCriteria_setModel(scP, modelRef);
			status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanMuftInArray, NULL);
			mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
			status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
			status = mdlScanCriteria_free(scP);

		}

		mdlModelRefIterator_free(&iterator);

	}



	//====================================================================================

	//for (int i = 0; i < mdlDArray_nMembers(daMufts); i++)
	//{
	//	ReinVert* rvP = (ReinVert*)mdlDArray_getMemberP(daMufts, i);
	//	printf("%i  %.0f  %.0f  %.0f \n", rvP->isin, rvP->torg.x, rvP->torg.y, rvP->torg.z);
	//}


	//====================================================================================



	//if (res == ACTIONBUTTON_YES)
	{
		SCPY(tbi.msgText1, L("Общий подсчёт"));
		SCPY(tbi.msgText2, L("Определение переходных"));


		// поехали обнаруживать переходы
		//====================================================================================

		//mdlSystem_extendedAbortEnable(TRUE);

		//mdlDialog_busyBarStartProcessing(scanProcessing, NULL, NULL, scanCancel, "Отменено", 0, "Расчет муфт", "Муфты");
		//mdlDialog_trackBarStartProcessing(NULL, NULL, NULL, NULL, L("Отменено"), 1, &tbi, L("Муфты/скобы"));

		dlgProgressP = mdlDialog_completionBarOpen(L("Муфты/скобы"));
		//mdlDialog_trackBarStartProcessing(
		//	workFunc,
		//	NULL,
		//	completionFunc,
		//	cancelFunc,
		//	NULL, 
		//	1, 
		//	&tbi, 
		//	L("Муфты/скобы"));

		//=================================================
		for (vector<ReinVert>::iterator rvP = daMufts.begin(); rvP != daMufts.end(); ++rvP)
			//for (UInt32 i = 0; i < daMufts.size(); i++)
		{

			//if (elemCount == -1) // отмена не фурычит...
			//{
			//	mdlDialog_trackBarStopProcessing();
			//	//mdlDialog_busyBarStopProcessing();
			//	mdlDialog_openMessageBox(DIALOGID_MsgBoxOK, "Отменено", MSGBOX_ICON_INFORMATION);
			//	return;
			//}



			tbi.percentComplete1 = (long)(((double)distance(daMufts.begin(), rvP) / (double)daMufts.size()) * 100.);
			//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
			if (dlgProgressP) mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)tbi.percentComplete1);
			WaitMessage();

			//if (mdlSystem_abortRequested()) break;


			//========================================================

			//getReducers2(rvP);

			//========================================================


			ScanRange sr;

			sr.xlowlim = (Int64)(rvP->torg.x - mdlCnv_masterUnitsToUors(dDupTol * 10));
			sr.ylowlim = (Int64)(rvP->torg.y - mdlCnv_masterUnitsToUors(dDupTol * 10));
			sr.zlowlim = (Int64)(rvP->torg.z - mdlCnv_masterUnitsToUors(dDupTol * 10));

			sr.xhighlim = (Int64)(rvP->torg.x + mdlCnv_masterUnitsToUors(dDupTol * 10));
			sr.yhighlim = (Int64)(rvP->torg.y + mdlCnv_masterUnitsToUors(dDupTol * 10));
			sr.zhighlim = (Int64)(rvP->torg.z + mdlCnv_masterUnitsToUors(dDupTol * 10));


			elemIterCount2 = 0;
			getReducers(ACTIVEMODEL, &(*rvP), &sr); // >>>
			ModelRefIteratorP  iterator;
			DgnModelRefP	modelRef;
			mdlModelRefIterator_create(&iterator, ACTIVEMODEL, MRITERATE_PrimaryChildRefs, 0);
			while (NULL != (modelRef = mdlModelRefIterator_getNext(iterator)))
			{
				BINT isOn = FALSE;
				mdlRefFile_getBooleanParameters(&isOn, REFERENCE_DISPLAYFLAG, modelRef);
				if (isOn == FALSE) continue;
				getReducers(modelRef, &(*rvP), &sr); // >>>
			}

			mdlModelRefIterator_free(&iterator);

			//========================================================

			double dTol = mdlCnv_masterUnitsToUors(iCfgVar_MuftTol);

			// правим дублирующиеся скобы
			for (vector<ReinVert>::iterator rvPit2 = daMufts.begin(); rvPit2 != daMufts.end(); ++rvPit2)
				//for (UInt32 ii = 0; ii < daMufts.size(); ii++)
			{
				ptrdiff_t ptd = distance(rvP, rvPit2); // std::distance
				if (ptd == 0) continue;
				//if (i == ii) continue;

				if (rvPit2->isin == REIN_TERM_NONE) continue;

				if (rvP->isin == REIN_TERM_SKOB &&
					rvPit2->isin == REIN_TERM_SKOB &&
					mdlVec_equalTolerance(&rvP->torg, &rvPit2->torg, dTol))
				{
					double an = mdlVec_angleBetweenVectors(&rvP->rvv.tdir, &rvPit2->rvv.tdir);

					if EQ(an, fc_pi) // направление противоположное
						rvPit2->isin = REIN_TERM_NONE; // дублирующаяся скоба
				}

			}


			//========================================================

		}


		//mdlSystem_extendedAbortEnable(FALSE);
	}



	WCH sArg[500];
	int errs = 0;


	if (mdlVBA_runMacro(L("arm"), L("main"), L("showMuftInit")) != SUCCESS) mdlVBA_reportCurrentError();



	// анализируем полученные данные пересечений
	//==========================================================

	for (vector<ReinVert>::iterator it = daMufts.begin(); it != daMufts.end(); ++it)
		//for (UInt32 i = 0; i < daMufts.size(); i++)
	{
		int adiam[2];
		double dOtn = 1.;

		ReinVert* rvP = &(*it);

		if (rvP->isin == REIN_TERM_NONE) continue;

		adiam[0] = rvP->mdiam[0];
		adiam[1] = rvP->mdiam[1];

		if (rvP->mdiam[0] != rvP->mdiam[1])
		{
			dOtn = fillets[rvP->mdiam[1]].diamrif / fillets[rvP->mdiam[0]].diamrif;
			if (dOtn > 1.)
			{
				dOtn = fillets[rvP->mdiam[0]].diamrif / fillets[rvP->mdiam[1]].diamrif;
				adiam[0] = rvP->mdiam[1];
				adiam[1] = rvP->mdiam[0];
			}
		}


		//if (rvP->pmqty > 1) ERROR!!! // больше одного попадания на муфту, возможна ошибка
		if (rvP->pmqty > 1 || rvP->errors > 0) errs++;


		if (rvP->isin == REIN_TERM_MUFT)
		{
			muftqtyext[adiam[0]][adiam[1]][rvP->mpar]++;
			muft_cmn_qty++;
		}
		else if (rvP->isin == REIN_TERM_SKOB)
		{
			skobqtyext[adiam[0]][adiam[1]]++;
			skob_cmn_qty++;

			if (!EQ(dOtn, 0.8) && dOtn < 0.8)
			{
				skobqtydop[adiam[0]][adiam[1]]++;
				vkld_cmn_qty++;
			}
		}

		SPRN(sArg, L("%i;%i;%i;%i;%i;%i;%.0f;%.0f;%.0f;%i"), adiam[0],
			adiam[1],
			rvP->pmqty,
			rvP->isin,
			rvP->mpar,
			rvP->mblap, // muft by lap
			mdlCnv_uorsToMasterUnits(rvP->torg.x),
			mdlCnv_uorsToMasterUnits(rvP->torg.y),
			mdlCnv_uorsToMasterUnits(rvP->torg.z),
			rvP->errors
		);
		mdlVBA_setMacroArgument(sArg);
		if (mdlVBA_runMacro(L("arm"), L("main"), L("addMuftUnit")) != SUCCESS) mdlVBA_reportCurrentError();

		tbi.percentComplete2 = (long)(((double)distance(daMufts.begin(), it) / (double)daMufts.size()) * 100.);
		//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
		if (dlgProgressP) mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)tbi.percentComplete2);
		WaitMessage();
	}


	SPRN(sArg, L("%i;%i;%i;%i"), muft_cmn_qty, skob_cmn_qty, vkld_cmn_qty, errs);
	mdlVBA_setMacroArgument(sArg);
	if (mdlVBA_runMacro(L("arm"), L("main"), L("showMuftAll")) != SUCCESS) mdlVBA_reportCurrentError();



	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (muftqtyext[i][j][k] > 0)
				{
					SPRN(sArg, L("%i;%i;%i;%i;%i"), REIN_TERM_MUFT, i, j, muftqtyext[i][j][k], k);
					mdlVBA_setMacroArgument(sArg);
					if (mdlVBA_runMacro(L("arm"), L("main"), L("addMuftQty")) != SUCCESS) mdlVBA_reportCurrentError();
				}
			}

		}

		tbi.percentComplete2 = (long)(((double)i / 50.) * 100.);
		//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
		if (dlgProgressP) mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)tbi.percentComplete2);
		WaitMessage();
	}




	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (skobqtyext[i][j] > 0)
			{
				SPRN(sArg, L("%i;%i;%i;%i;%i"), REIN_TERM_SKOB, i, j, skobqtyext[i][j], 0);
				mdlVBA_setMacroArgument(sArg);
				if (mdlVBA_runMacro(L("arm"), L("main"), L("addMuftQty")) != SUCCESS) mdlVBA_reportCurrentError();
			}
		}

		tbi.percentComplete2 = (long)(((double)i / 50.) * 100.);
		//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
		if (dlgProgressP) mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)tbi.percentComplete2);
		WaitMessage();
	}




	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (skobqtydop[i][j] > 0)
			{
				SPRN(sArg, L("%i;%i;%i;%i;%i"), 0, i, j, skobqtydop[i][j], 0);
				mdlVBA_setMacroArgument(sArg);
				if (mdlVBA_runMacro(L("arm"), L("main"), L("addMuftQty")) != SUCCESS) mdlVBA_reportCurrentError();
			}
		}

		tbi.percentComplete2 = (long)(((double)i / 50.) * 100.);
		//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
		if (dlgProgressP) mdlDialog_completionBarUpdate(dlgProgressP, 0, (int)tbi.percentComplete2);
		WaitMessage();
	}

	if (dlgProgressP) mdlDialog_completionBarClose(dlgProgressP);
	//mdlDialog_trackBarStopProcessing();
	//mdlDialog_busyBarStopProcessing();


	mdlVBA_setMacroArgument(L(""));
	if (mdlVBA_runMacro(L("arm"), L("main"), L("showMuftQty")) != SUCCESS)
	{
		mdlVBA_reportCurrentError();
		//mdlDialog_openMessageBox(DIALOGID_MsgBoxOK, s, MSGBOX_ICON_INFORMATION);
	}

}


/////////////////////////////////
extern "C" DLLEXPORT void cmdDrawEnds(
	char* unparsedP
)
//cmdNumber   CMD_REIN_DRAWENDS
{

	//ViewportP vpP = mdlView_getViewport(0);

	//vpP->SetNeedsRefresh();

	//if (rDopInfo.dopopt[14] >= 0) 
	//{
	saveShowInfo2(&rInfo);
	//}
	//else
	//{
	//	rInfoPref = rInfo;
	//}

	syncShowInfo();

	updateAllViews();

	//reinUpdateBarFacesAllViews(NORMALDRAW, 0, 0);

}



/////////////////////////////////
extern "C" DLLEXPORT void cmdRefPrefsDel( // сброс настроек файла/референса
	char* unparsedP
)
//cmdNumber   CMD_REIN_REFPDEL
{

	ScanCriteria* pScanCriteria;
	int status;



	ReinPrm prm;
	prm.bDel = 1;
	prm.wstr = getCurRefShowPath(); // sRefShow index

	// delete all prev. xml elements
	pScanCriteria = mdlScanCriteria_create();
	status = mdlScanCriteria_setReturnType(pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
	status = mdlScanCriteria_setElmDscrCallback(pScanCriteria, (PFScanElemDscrCallback)scanCheckShowInfo2, &prm);
	status = mdlScanCriteria_setModel(pScanCriteria, ACTIVEMODEL);
	mdlXML_addXMLFragmentElementScanTest(pScanCriteria, &appID, &appTypeShowInfo);
	status = mdlScanCriteria_scan(pScanCriteria, NULL, NULL, NULL);
	status = mdlScanCriteria_free(pScanCriteria);

	syncShowInfo();


}


/////////////////////////////////
extern "C" DLLEXPORT void cmdFileBars(
	char* unparsedP
)
//cmdNumber   CMD_REIN_FILEBARS // Реальные трёхмерные стержни
{



	//if (iCurBarsCount > 300)
	{
		int res = mdlDialog_openMessageBox(DIALOGID_MsgBoxYesNo,
			L("Будет произведена регенерация элементов\nЭто может занять много времени\nПродолжать?"),
			MSGBOX_ICON_WARNING);
		if (res == ACTIONBUTTON_NO) return;

	}


	reloadBarsData(0, TRUE);
}



/////////////////////////////////
extern "C" DLLEXPORT void cmdDrawCont( // NU
	char* unparsedP
)
//cmdNumber   CMD_REIN_DRAWCONT
{



	//displayReinMains(0, REIN_MAIN_SPACE, TRUE); // потом убрать
	// сделано чтобы не осталось невидимых контуров и осн. стержней

	updateAllViews();

}


/////////////////////////////////
extern "C" DLLEXPORT void cmdDrawBars( // NU
	char* unparsedP
)
//cmdNumber   CMD_REIN_DRAWBARS // элемент отдельного стержня
{



	//displayReinMains(0, REIN_MAIN_BAR, TRUE); // потом убрать
	// сделано чтобы не осталось невидимых контуров и осн. стержней

	updateAllViews();


}


/////////////////////////////////
extern "C" DLLEXPORT void cmdReinList(
	char* unparsedP
)
//cmdNumber   CMD_REIN_LIST
{



	{
		if (strlen(unparsedP) > 0)
		{
			if (strcmp(unparsedP, "reload") == 0)
			{
				curPos_rn = 0;
				curPos_refpath = L"0";
				//curPos_rnn = 0;
			}
		}

		curRM->reloadCurBars(false, true, iRefLvl, iRefLvl);


		MSDLGP dbP = NULL;

		if (NULL != (dbP = mdlDialog_find(DLG_POSLIST, NULL)))
		{
			//updateListBoxPos(TRUE); // see reloadCurBars
			updateModelElmNumbers(curRM, false);

			dialogPosList_checkButton(dbP); // проверка кнопок
		}
		else
		{
			
			if (rfHandle) 
				dbP = mdlDialog_open(rfHandle, DLG_POSLIST);

			if (rfHandle) // STD_INTERFACE
				mdlDialog_open(rfHandle, DLG_SKETCH);

			if (dbP) dialogPosList_checkButton(dbP);
		}


	}


}


/////////////////////////////////
extern "C" DLLEXPORT void cmdReinShow(
	char* unparsedP
)
//cmdNumber   CMD_REIN_FLAGS
{

	if (rfHandle) 
		mdlDialog_open(rfHandle, DLG_PRESENT);

}



/////////////////////////////////
extern "C" DLLEXPORT void cmdPosSave( // using?
	char* unparsedP
)
//cmdNumber   CMD_REIN_POS_SAVE
{
	CatInfo ci;
	int cnt = 0;

	//tbi.update = UPDATE_Percent1 | UPDATE_Msg1;
	//strcpy(tbi.msgText1, "Сохранение");

	int bForce = FALSE;
	int bUpdInfo = FALSE;

	if (unparsedP != NULL && (unparsedP[0] == 'f' || unparsedP[0] == 'F')) // FORCE
	{
		bForce = TRUE;
		bUpdInfo = TRUE;
	}


	getCatInfo(&ci, ACTIVEMODEL, false);

	mdlDialog_dmsgsPrint(L("begin to save positions..."));


	//mdlDialog_trackBarStartProcessing(scanProcessing, NULL, NULL, scanCancel, "Отменено", FALSE, &tbi, "");

	for (MAP<long, ReinPos>::iterator it = curRM->arCurPos.begin(); it != curRM->arCurPos.end(); ++it)
	{
		ReinPos* rpP = &it->second;

		if (rpP->bar.pnum == 0) continue;


		//if (ci.catModID > 0) rpP->pcatID = ci.catModID;

		if (savePosition(rpP, bForce, bUpdInfo) == SUCCESS)
		{
			SPRN(s, L(" ok. pos %i saved"), rpP->bar.pnum);
			mdlDialog_dmsgsPrint(s);
			cnt++;
		}
		else
		{
			SPRN(s, L(" !!! pos %i skipped"), rpP->bar.pnum);
			mdlDialog_dmsgsPrint(s);
		}

		//tbi.percentComplete1 = (long)(((double)cnt/(double)mdlDArray_nMembers(daCurPosBase))*100.);
		//mdlDialog_trackBarUpdateDisplayInfo(&tbi);
		//WaitMessage();


	}

	//mdlDialog_trackBarStopProcessing();

	SPRN(s, L(" saved %i positions"), cnt);
	mdlDialog_dmsgsPrint(s);

	//iCfgVar_DB = 0;

	//sprintf(s, "Сохранено %i записей для определения позиций", cnt);
	//mdlDialog_openMessageBox (DIALOGID_MsgBoxOK, s, MSGBOX_ICON_NOSYMBOL);

}

/////////////////////////////////
extern "C" DLLEXPORT void cmdPosClear(
	char* unparsedP
)
//cmdNumber   CMD_REIN_POS_CLEAR
{


	elemCount = 0;

	if (curPos_rn > 0) // reference
		return;

	MSDLGP dbP = mdlDialog_find(DLG_POSLIST, NULL);

	DialogItem* pListBoxItem = NULL;
	ListModel* pListModel = NULL;
	int row, col;
	RscId  iIcon;
	RscType iIconType;

	int iRowsSelected = 0;

	if (dbP)
	{

		if (NULL == (pListBoxItem = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ListBox, 1, 0)))
			return;

		if (NULL == (pListModel = mdlDialog_listBoxGetListModelP(pListBoxItem->rawItemP)))
			return;

		for (int i = 0; i < mdlListModel_getRowCount(pListModel); i++)
		{
			ListCell* pListCellch = mdlListModel_getCellAtIndexes(pListModel, i, REIN_LISTB_EXCL);
			mdlListCell_getIcon(pListCellch, &iIcon, &iIconType, NULL);


			//ListCell* pListCell = mdlListModel_getCellAtIndexes(pListModel, i, REIN_LISTB_POSN);
			//long ii = myListCell_getInfoFieldInt32(pListCell, 0, &gst);

			//if (ii <= 0) continue;

			if (iIcon == ICONID_ToggleOn14Pt)
				iRowsSelected++;
		}

	}



	if (iRowsSelected && dbP)
	{

		int res = mdlDialog_openMessageBox(DIALOGID_MsgBoxYesNo,
			L("Будут удалены номера выделеных позиций\nПродолжать?"),
			MSGBOX_ICON_WARNING);
		if (res == ACTIONBUTTON_NO) return;


		for (int i = 0; i < mdlListModel_getRowCount(pListModel); i++)
		{

			ListCell* pListCellch = mdlListModel_getCellAtIndexes(pListModel, i, REIN_LISTB_EXCL);
			mdlListCell_getIcon(pListCellch, &iIcon, &iIconType, NULL);

			if (iIcon != ICONID_ToggleOn14Pt)
				continue;

			mdlListCell_setIcon(pListCellch, ICONID_ToggleOff14Pt, RTYPE_Icon, NULL);

			ListRow* pListRow = mdlListModel_getRowAtIndex(pListModel, i);
			if (mdlListRow_getStatus(pListRow) == LISTCELLATTR_DISABLED)  continue;


			ListCell* pListCell = mdlListModel_getCellAtIndexes(pListModel, i, REIN_LISTB_POSN);

			long ii = myListCell_getInfoFieldInt32(pListCell, 0, &gst);


			if (gst != SUCCESS) continue;

			if (ii <= 0) continue;

			MAP<long, ReinPos>::iterator it = curRM->arCurPos.find(ii);

			if (it != curRM->arCurPos.end()) // found
			{
				deleteFilePosition(ii);

				ReinPos rp = it->second;

				curRM->arCurPos.erase(it);

				rp.bar.pnum = 0;

				rp.mapind = curRM->iPosIndex;
				
				curRM->arCurPos.insert(pair<long, ReinPos>(rp.mapind, rp));

				mdlListCell_setInfoFieldInt32(pListCell, 0, rp.mapind);
				mdlListCell_setDisplayText(pListCell, L(""));

				mdlListCell_setInfoFieldInt32(pListCellch, 0, rp.mapind);
				// см выше
				//mdlListCell_setIcon(pListCellch, ICONID_ToggleOff14Pt, RTYPE_Icon, NULL);

				curRM->iPosIndex--;

				elemCount++;
			}
		}

		daCurPosExcl.clear();
		curRM->vExFps.clear();
		curRM->vExIds.clear();

		mdlDialog_listBoxDrawContents(pListBoxItem->rawItemP, -1, REIN_LISTB_POSN);
		mdlDialog_listBoxDrawContents(pListBoxItem->rawItemP, -1, REIN_LISTB_EXCL);

	}
	else
	{

		int res = mdlDialog_openMessageBox(DIALOGID_MsgBoxYesNo,
			L("Будут удалены\nВСЕ номера ВСЕХ позиций\nв открытой модели\nПродолжать?"),
			MSGBOX_ICON_WARNING);
		if (res == ACTIONBUTTON_NO) return;

		deleteFilePosition(0);

		curRM->arCurPos.clear();

		curRM->iPosIndex = -100;

		curRM->reloadCurBars(false, true, iRefLvl, iRefLvl);
	}




	if (dbP == NULL)
	{
		SPRN(s, L("Удалено %i записей для определения позиций"), elemCount);

		mdlDialog_openMessageBox(DIALOGID_MsgBoxOK, s, MSGBOX_ICON_NOSYMBOL);
	}
	else
	{
		dialogPosList_checkButton(dbP);
	}


	updateModelElmNumbers(0, false);

}


/////////////////////////////////
extern "C" DLLEXPORT void cmdPosDraw(
	char* unparsedP
)
//cmdNumber   CMD_REIN_POS_DRAW
{

	setDefaultStyles();

	posCount = 0;

	drawBarsTable(NULL, &posCount);

	if (posCount == 0) return;

	mdlState_startPrimitive((StateFunc_DataPoint)reinSketchTable, (StateFunc_Reset)mdlState_startDefaultCommand, 0, NULL);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	StateCallback::SetComplexDynamicsFunction((StateFunc_ComplexDynamics)reinSketchDynamics);
#else
	mdlState_setFunction(STATE_COMPLEX_DYNAMICS, reinSketchDynamics);
#endif
	mdlAccuSnap_enableSnap(TRUE);

}

/////////////////////////////////
extern "C" DLLEXPORT void cmdPosLoadDB(
	char* unparsedP
)
//cmdNumber   CMD_REIN_POS_DBLOAD
{

	//loadDBPositions();

	//iCfgVar_DB = 1;

}



/////////////////////////////////
extern "C" DLLEXPORT void cmdPosSaveDB(
	char* unparsedP
)
//cmdNumber   CMD_REIN_POS_DBSAVE
{
	if (curPos_rn == 0) // кнопка "в базу"
		posSaveDB(unparsedP);
	else // кнопка кэщ/динамик
	{
		DgnModelRefP mrRefP = NULL;

		ReinModel* rmP = curRM->getRM(curPos_refpath);

		if (rmP)
		{
			savePlotFile(rmP);
		}

	}
}


/////////////////////////////////////////
#if defined (MSVERSION) && (MSVERSION == 0xa00)
bool callbackUnloadProgram(
	UnloadProgramReason	    	unloadType  	/* => SYSTEM_TERMINATED_SHUTDOWN */
#else
int callbackUnloadProgram(
	int unloadType
#endif
)
{
	RscFileHandle   userPrefsH = NULL;


	writeLogIn(__FUNCTION__, 0);

	//if ((rInfo.option[2] == 0 || rInfo.option[4]) && 
	//	unloadType != SYSTEM_TERMINATED_SHUTDOWN && 
	//	daCurElements)
	//{
	//	int i;
	//	rInfo.option[2] = 1; // отображать контуры
	//	rInfo.option[4] = 1;

	//	for (i = 0; i < mdlDArray_nMembers(daCurElements) ;i++)
	//	{
	//		ReinElement* reP = mdlDArray_getMemberP(daCurElements, i);

	//		if (mdlElement_read(&elTmp, reP->modelRef, reP->fpRS) == SUCCESS)
	//		{
	//			mdlElement_display(&elTmp, NORMALDRAW);
	//		}
	//	}
	//}


	//if (curRM) delete curRM;

	//for (int i = 0; i < MAX_REF_SLOT; i++)
	//{
	//	if (arCurMrP[i])
	//	{
	//		for (int j = 0; j < MAX_REF_SLOT; j++)
	//		{
	//			destroyModel(&arCurMrP[i][j], TRUE, TRUE, TRUE);
	//		}

	//		delete[] arCurMrP[i];
	//		arCurMrP[i] = NULL;
	//	}
	//}


	if (iDebug == 3) closeLogFile();


	//mdlDialog_openMessageBox(DIALOGID_MsgBoxOK, "0", MSGBOX_ICON_INFORMATION);

	//writeLogIn(__FUNCTION__, 0);
	//sprintf(sLogMes, "unloadType = %i\n", unloadType); writeLog(0, 0);

	//SYSTEM_TERMINATED_UNLOADING_APPDOMAIN = -6,
	//SYSTEM_TERMINATED_ENTERING_RESTRICTED_RIGHTS_MODE = -5,
	//SYSTEM_TERMINATED_UNLOAD_UI_SERVERS = -4,
	//SYSTEM_TERMINATED_LIBRARY_UNLOAD = -3,
	//SYSTEM_TERMINATED_SHUTDOWN = -2,
	//SYSTEM_TERMINATED_FATAL = -1,
	//SYSTEM_TERMINATED_COMMAND = 1,
	//SYSTEM_TERMINATED_EXIT = 2,
	//SYSTEM_TERMINATED_BY_APP = 3,
	//SYSTEM_TERMINATED_EXCEPTION = 4

	//mdlDialog_openMessageBox(DIALOGID_MsgBoxOK, "1", MSGBOX_ICON_INFORMATION);



#if defined (STD_INTERFACE)
	MSDLGP db_2 = mdlDialog_find(DIALOG_TOOLBOX, NULL);

	if (unloadType != SYSTEM_TERMINATED_SHUTDOWN)
	{
		if (db_2) rInfo.option[7] = TRUE; else rInfo.option[7] = FALSE;
	}

#endif

	MSDLGP db_7 = mdlDialog_find(DLG_SKETCH, NULL);

	if (unloadType != SYSTEM_TERMINATED_SHUTDOWN)
	{
		if (db_7) rInfo.ttip = TRUE; else rInfo.ttip = FALSE;
	}


#if defined (STD_INTERFACE)

	writeLog("mdlDialog_userPrefFileOpen", 0);

	 //Open userpref.rsc to hold our small pref resource 
	int st = ERROR;
	st = mdlDialog_userPrefFileOpen(&userPrefsH, TRUE);

	//delete and add resource in case the old resource format was in the file 
    if (st == SUCCESS && userPrefsH)
	{
		wstring wstr = L"";

		setReinInfoString(rInfo, &wstr);
		wcsncpy(strReinInfo, wstr.c_str(), 10000);
		wcscat(strReinInfo, L"\0\0");

		setReinInfoString(rDopInfo, &wstr);
		wcsncpy(strReinDopInfo, wstr.c_str(), 10000);
		wcscat(strReinDopInfo, L"\0\0");

		setReinInfoString(rBarOverInfo, &wstr);
		wcsncpy(strBarOverInfo, wstr.c_str(), 10000);
		wcscat(strBarOverInfo, L"\0\0");

		setReinInfoString(curNoteSet, &wstr);
		wcsncpy(strCurNoteSet, wstr.c_str(), 10000);
		wcscat(strCurNoteSet, L"\0\0");

			//
//		ReinInfo ri;
//		ReinDopInfo rdi1;
//		ReinDopInfo rdi2;
//		ReinNoteSet rns;
//		rInfo.setLegacy(&ri, false);
//		rDopInfo.setLegacy(&rdi1, false);
//		rBarOverInfo.setLegacy(&rdi2, false);
//		curNoteSet.setLegacy(&rns, false);
//
//		mdlResource_deleteByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinPrefs, mdlSystem_getCurrTaskID());
//		mdlResource_addByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinPrefs, &ri, sizeof(_ReinInfo), mdlSystem_getCurrTaskID());
//
//		mdlResource_deleteByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinDopPrefs, mdlSystem_getCurrTaskID());
//		mdlResource_addByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinDopPrefs, &rdi1, sizeof(_ReinDopInfo), mdlSystem_getCurrTaskID());
//
//		mdlResource_deleteByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinBarPrefs, mdlSystem_getCurrTaskID());
//		mdlResource_addByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinBarPrefs, &rdi2, sizeof(_ReinDopInfo), mdlSystem_getCurrTaskID());
//
//		mdlResource_deleteByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinNotePrefs, mdlSystem_getCurrTaskID());
//		mdlResource_addByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinNotePrefs, &rns, sizeof(_ReinNoteSet), mdlSystem_getCurrTaskID());
//
//

		writeLog("save settings...", 0);

		mdlResource_deleteByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinPrefs, mdlSystem_getCurrTaskID());
		mdlResource_addByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinPrefs, &strReinInfo, sizeof(strReinInfo), mdlSystem_getCurrTaskID());

		mdlResource_deleteByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinDopPrefs, mdlSystem_getCurrTaskID());
		mdlResource_addByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinDopPrefs, &strReinDopInfo, sizeof(strReinDopInfo), mdlSystem_getCurrTaskID());

		mdlResource_deleteByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinBarPrefs, mdlSystem_getCurrTaskID());
		mdlResource_addByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinBarPrefs, &strBarOverInfo, sizeof(strBarOverInfo), mdlSystem_getCurrTaskID());

		mdlResource_deleteByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinNotePrefs, mdlSystem_getCurrTaskID());
		mdlResource_addByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinNotePrefs, &strCurNoteSet, sizeof(strCurNoteSet), mdlSystem_getCurrTaskID());

		//Clean up 
		mdlResource_closeFile(userPrefsH);
	}


	if (rfHandle) mdlResource_closeFile(rfHandle);
	
#endif


	writeLogOut(__FUNCTION__, 0);

	writeLog("RHEIN", -1);

	closeLogFile();

#if defined (MSVERSION) && (MSVERSION == 0x8b0) 
	return (0);
#else
	return false;
#endif
}




///////////////////////////////////////////////////////////
// func: callback Update Element
SubstituteElemStatus callbackUpdateElement(
	MSElementDescrH newEdPP, // <= output if element being replaced
#if defined (MSVERSION) && (MSVERSION == 0xa00) // callbackUpdateElement
	ViewportP viewPortP,
	DgnPlatform::DrawPurpose drawPurpose,
	ViewContextP context,
	ElementHandleCP elemIterP
#else
	int* priorityP, // <= priority if element being defered
	ViewportP viewPortP,
	DrawPurpose drawPurpose,
	IViewContextP context, // => view context
	bool allowDefer, // => whether element can be defered
	ElemHandleCP elemIterP // => elem-iter for current element if descriptor is needed
#endif
)
{
	//MSWindow* wndP;
	//char sss[200];
	//UInt32 wt = 5;

	//ElementAgenda es;
	//ReinElm relm;

	//vector<DVec3d> arXreal;
	//vector<DVec3d> arOreal;
	//vector<DVec3d> arXview;
	//vector<DVec3d> arOview;

	//ReinSpace rs;
	//ReinBar rb;

	UInt32 iBlock = BLOCK_NON;

	//viewPortP->

	SubstituteElemStatus retVal = SUBSTELEM_STATUS_Normal;


	//return retVal;

	//ELREF erefClip = viewPortP->GetClipBoundElementRef();


	// если DRAW_PURPOSE_Pick и идет замена newEdPP, то привязка не срабатывает
	//if (drawPurpose == DRAW_PURPOSE_Pick) return retVal;

	bool bPlot = (drawPurpose == DRAW_PURPOSE_Plot || (iModelType == 0));



	//char s[100];
	//sprintf(s, "%i", drawPurpose);
	//mdlDialog_dmsgsPrint(s);

	/*
	search updevents
	REIN_UPDATE_ELEMENT_SKIP_EVENTS
typedef enum DrawPurpose
	{
	DRAW_PURPOSE_NotSpecified      = 0,
	DRAW_PURPOSE_Update            = 1,
	DRAW_PURPOSE_UpdateDynamic     = 2,
	DRAW_PURPOSE_UpdateHealing     = 3,
	DRAW_PURPOSE_Hilite            = 5,
	DRAW_PURPOSE_Unhilite          = 6,
	DRAW_PURPOSE_Created           = 7,
	DRAW_PURPOSE_Deleted           = 8,
	DRAW_PURPOSE_ChangedPre        = 9,
	DRAW_PURPOSE_ChangedPost       = 10,
	DRAW_PURPOSE_RestoredPre       = 11,
	DRAW_PURPOSE_RestoredPost      = 12,
	DRAW_PURPOSE_RestoredDeleted   = 13,
	DRAW_PURPOSE_RestoredUndeleted = 14,
	DRAW_PURPOSE_Dynamics          = 15,
	DRAW_PURPOSE_EraseBeforeHilite = 16,
	DRAW_PURPOSE_EraseBeforeModify = 17,
	DRAW_PURPOSE_GetDescr          = 18,
	DRAW_PURPOSE_Animation         = 19,
	DRAW_PURPOSE_RangeCalculation  = 20,
	DRAW_PURPOSE_Plot              = 21,
	DRAW_PURPOSE_Pick              = 22,
	DRAW_PURPOSE_Flash             = 23,
	DRAW_PURPOSE_TransientChanged  = 25,
	DRAW_PURPOSE_CaptureGeometry   = 26,
	DRAW_PURPOSE_GenerateThumbnail = 27,
	DRAW_PURPOSE_DrawFenceElement  = 28,
	DRAW_PURPOSE_ForceRedraw       = 29,
	DRAW_PURPOSE_FenceAccept       = 30,
	DRAW_PURPOSE_CreateSymbol      = 31,
	DRAW_PURPOSE_FitView           = 32,
	DRAW_PURPOSE_RasterProgressiveUpdate = 33,
	DRAW_PURPOSE_XGraphicsCreate   = 34,
	DRAW_PURPOSE_CaptureShadowList = 35,
	DRAW_PURPOSE_ExportVisibleEdges = 36,
	} DrawPurpose;	*/


	//MSElement* elp = NULL;
	MSElementDescrCP edp = NULL;
	DgnModelRefP mrP = NULL;

	int tp = elemIterP->GetElementType();

	edp = (MSElementDescr*)elemIterP->GETELDSCP();
	//elp = (MSElement*)elemIterP->GetElementCP();
	if (edp == NULL) return retVal;

	mrP = (DgnModelRefP)elemIterP->GetModelRef();
	if (mrP == NULL) return retVal;

	//if (readReinCacheFromElement(NULL, &edp->el) == SUCCESS && iModelType && iCfgVar_ViewCacheWorkShow == 0)
	//{
	//	return SUBSTELEM_STATUS_Block;
	//}

	ELREF eref = elemIterP->GETELREF();
	if (eref == NULL) return retVal;

	UInt32 fp = elementRef_getFilePos(eref);
	if (fp == 0) return retVal;

	ELID id = elementRef_getElemID(eref);


	//if (id == 4585806)
	//	int a = 0;

	//if (id == 4586430)
	//	int aa = 0;

	//if (fp == 4001062)
	//	__asm nop;


	ReinModel* rmP = curRM->getRM(mrP);
	if (rmP == NULL) return retVal;

	//Pos = 4000458
	//if (rmP->getRefPathString() ==L"2-1" &&  fp == 4000458)
	//	__asm nop;

	if (updevents[0]) updevents[0] = 2; // не вести лог в этой функции


	writeLogIn(__FUNCTION__, 0); // callbackUpdateElement in

	if (iDebug) sprintf(sLogMes, "drawPurpose == %i\n", drawPurpose); 

	writeLog(0, 0);

	ReinInfoRef* rirP = rmP->getRefPrefs();

	//context->CookElemDisplayParams(*elemIterP);

	// объемные стержни и опция их отображения
	if (crelm.getElmFromElement(&edp->el, 0) == SUCCESS)
	{
		if (crelm.type == REIN_ELEM_BAR && !rirP->riropt[10]
			&& !context->GetViewFlags()->refBoundaryDisplay
			)
		{
			writeLogOut(__FUNCTION__, 0, TRUE); // callbackUpdateElement out
			return SUBSTELEM_STATUS_Block;
		}

		//if (crelm.type == REIN_ELEM_BAR)
		//	__asm nop;
	}


	if (rmP->bCached)
	{
		if (readReinSpaceFromElmd(&rrelem, edp, FALSE) == SUCCESS)
		{
			writeLogOut(__FUNCTION__, "bCached", TRUE);
			return SUBSTELEM_STATUS_Block;
		}

		if (readReinBarFromElement(&rrb, edp, TRUE) == SUCCESS)
		{
			writeLogOut(__FUNCTION__, "bCached", TRUE);
			return SUBSTELEM_STATUS_Block;
		}

		if (crelm.getElmFromElement(&edp->el, 0) == SUCCESS)
		{
			writeLogOut(__FUNCTION__, "bCached", TRUE);
			return SUBSTELEM_STATUS_Block;
		}
	}




	if (readReinAxisFromElement(&raxis, &edp->el) == SUCCESS)
	{
		writeLogOut(__FUNCTION__, "readReinAxisFromElement", TRUE); // callbackUpdateElement out
		return SUBSTELEM_STATUS_Block;
	}


	if (updevents[(int)drawPurpose])
	{
		writeLogOut(__FUNCTION__, "go out by update events", TRUE);
		return retVal;
	}

	if (drawPurpose == DRAW_PURPOSE_FenceAccept)
	{
		writeLogOut(__FUNCTION__, "DRAW_PURPOSE_FenceAccept", TRUE);
		return retVal; // иначе не работает mdlClip_...
	}

	if (drawPurpose == DRAW_PURPOSE_GenerateThumbnail)
	{
		writeLogOut(__FUNCTION__, "DRAW_PURPOSE_GenerateThumbnail", TRUE);
		return retVal;
	}


	//if (drawPurpose == DRAW_PURPOSE_Pick && fp == 4037768)
	//	int a = 0;
	//if (fp == 4030727)
	//	int a = 0;

	int iDrawMode = 0;
	//ReinElm arelm;
	ReinElm* relmP = NULL;




	relmP = rmP->getReinElm(fp);

	 // развертка - надо переводить координаты стержня
	ELID elidRnd = 0;
	UInt32 refnum = 0;
	if (relmP && readRndFromElement(&elidRnd, &refnum, &edp->el) == SUCCESS)
	{
		deque <UInt32> aref;
		if (refnum > 0) aref.push_back(refnum);
		aref.push_back(1); // source rondo ref is always 1

		ReinModel* rmRndP = curRM->getRM(aref);
		//ReinModel* rmRndP = curRM->getRM(1);

		if (rmRndP)
		{
			ELREF erefRnd = getElemRefByID(rmRndP->modelP, elidRnd);

			if (erefRnd)
			{
				UInt32 fpRnd = elementRef_getFilePos(erefRnd);
				ReinElm* reTmp = rmRndP->getReinElm(fpRnd);
				if (reTmp)
				{
					relmP->bel.pnum = reTmp->bel.pnum;

					relmP->type = REIN_ELEM_RND;

					mdlElmdscr_extractEndPoints(&relmP->bel.sgts[0].rv[0].torg, 0, &relmP->bel.sgts[0].rv[1].torg, 0, (MSElementDescr*)edp, mrP);
					relmP->bel.numsgts = 1;
					//relmP->fpDup = 0;
				}
			}
		}
	}


	/*
	if (relmP)
	{
		if (relmP->type == REIN_ELEM_ISO
			&& (
				(relmP->bel.term[0] == REIN_TERM_BEND
					&& relmP->bel.term[1] == REIN_TERM_BEND) || // шпилька
				(relmP->bel.term[0] == REIN_TERM_PLAT
					&& relmP->bel.term[1] == REIN_TERM_PLAT && rirP->riropt[10]) // плашки при объемном отображении
				)
			)
		{
			writeLogOut(__FUNCTION__, 0, TRUE); // callbackUpdateElement out
			return retVal;
		}
	}
	*/

	//return retVal;

	//=================================================================
	iBlock = checkDrawElem(edp, bPlot, &newEdPP, drawPurpose, rmP, &iDrawMode, &relmP, viewPortP, rirP);
	//=================================================================


	//if (rmP && rmP->vExIds.size() > 0)
	//{
	//	for (vector<ELID>::iterator it = rmP->vExIds.begin() ; it != rmP->vExIds.end(); ++it)
	//	{
	//	}
	//}

	//if (rmP && rmP->vExFps.size() > 0)
	//{
	//	for (vector<UInt32>::iterator it = rmP->vExFps.begin() ; it != rmP->vExFps.end(); ++it)
	//	{
	//	}
	//}



	if ((curRM->getExFpCount(-1) > 0 || curRM->getExIdCount(-1) > 0))
	{
		if (arelm.getElmFromElement(&edp->el, 0) == SUCCESS)
		{
			UInt32 i;
			int bFound = TRUE;

			fp = mdlElmdscr_getFilePos(edp);

			if (relmP == NULL) relmP = &arelm;

			if (fp)
			{
				if (rmP && rmP->vExFps.size() > 0)
				{
					for (map<UInt32,bool>::iterator it = rmP->vExFps.begin(); it != rmP->vExFps.end(); ++it)
					{
						if (it->second) bFound = FALSE; // если хоть один есть
						if (fp == it->first && it->second) { bFound = TRUE; break; }
					}
				}
			}

			if (bFound == FALSE)
				iBlock = iBlock | BLOCK_EXC;
		}
		else if (readReinBarFromElement(&rrb, edp, TRUE) == SUCCESS)
		{
			ELID elid;
			UInt32 i;
			int bFound = TRUE;

			elid = mdlElement_getID(&edp->el);

			if (elid)
			{

				if (rmP && rmP->vExIds.size() > 0)
				{
					for (map<ELID,bool>::iterator it = rmP->vExIds.begin(); it != rmP->vExIds.end(); ++it)
					{
						if (it->second) bFound = FALSE; // если хоть один есть
						if (elid == it->first && it->second) { bFound = TRUE; break; }
					}
				}

				//for (i = 0; i < iIDcount; i++)
				//{
				//	if (arID[i] > 0) bFound = FALSE; // если хоть один есть
				//	if (elid == arID[i]) {bFound = TRUE; break;}
				//}
			}


			if (bFound == FALSE)
				iBlock = iBlock | BLOCK_EXC;

		}
		else if (readReinSpaceFromElmd(&rrelem, edp, FALSE) == SUCCESS)
		{
			ELID elid;
			UInt32 i;
			int bFound = TRUE;

			elid = mdlElement_getID(&edp->el);

			if (elid)
			{
				if (rmP && rmP->vExIds.size() > 0)
				{
					for (map<ELID,bool>::iterator it = rmP->vExIds.begin(); it != rmP->vExIds.end(); ++it)
					{
						if (it->second) bFound = FALSE; // если хоть один есть
						if (elid == it->first && it->second) { bFound = TRUE; break; }
					}
				}

				//for (i = 0; i < iIDcount; i++)
				//{
				//	if (arID[i] > 0) bFound = FALSE; // если хоть один есть
				//	if (elid == arID[i]) {bFound = TRUE; break;}
				//}
			}


			if (bFound == FALSE)
				iBlock = iBlock | BLOCK_EXC;
		}
		//else if (mdlModelRef_isActiveModel(edp->h.dgnModelRef)) // ОПЦИЯ???
		//{
		//	iBlock = iBlock | BLOCK_EXC; // все элементы активной модели не отображаются, если есть хоть одна галка "@"
		//}
	}



	//if (iBlock == BLOCK_NON && readReinBarFromElement(&rrb, edp, FALSE) == SUCCESS)
	if (!bPlot && iBlock == BLOCK_NON && arelm.getElmFromElement(&edp->el, 0) == SUCCESS && rirP->lim)
	{
		// рисуем конус-стрелку на конце
		RotMatrix rm;
		DVec3d p[2];
		DVec3d pp;
		DVec3d ppp[2];
		context->CookElemDisplayParams(*elemIterP);
		VIEWDRAW	output = context->GetIViewDraw();
		mdlElmdscr_extractEndPoints(0, 0, &p[0], &p[1], (MSElementDescr*)edp, edp->h.dgnModelRef);
		mdlVec_negateInPlace(&p[1]);
		mdlRMatrix_fromNormalVector(&rm, &p[1]);
		mdlVec_fromRotMatrixRow(&ppp[0], &rm, 0);
		mdlVec_fromRotMatrixRow(&ppp[1], &rm, 1);
		mdlVec_scaleToLength(&pp, &p[1], mdlCnv_masterUnitsToUors(dCfgVar_BarFace) * 3);
		mdlVec_addPoint(&pp, &p[0], &pp);
#if defined (MSVERSION) && (MSVERSION == 0xa00) // ???
		output.DrawCone(p[0], pp, 0., mdlCnv_masterUnitsToUors(dCfgVar_BarFace), true);
#else
		output->DrawCone(&ppp[0], &ppp[1], &p[0], &pp, 0., mdlCnv_masterUnitsToUors(dCfgVar_BarFace), true);
#endif
	}



	if (relmP
		//&& (drawPurpose == DRAW_PURPOSE_Update 
		//|| drawPurpose == DRAW_PURPOSE_Plot 
		//|| drawPurpose == DRAW_PURPOSE_Pick
		//|| drawPurpose == DRAW_PURPOSE_ForceRedraw
		//|| drawPurpose == DRAW_PURPOSE_UpdateHealing
		//|| drawPurpose == DRAW_PURPOSE_Hilite
		//)
		)
	{

		//printf("dp=%i   fp=%u  type=%i  ", drawPurpose, mdlElmdscr_getFilePos(edp), mdlElement_getType(elp));

		context->CookElemDisplayParams(*elemIterP);

		//if (rInfo.option[5]) 
		{
			VIEWDRAW	output = context->GetIViewDraw();

			//output.SetSymbology(0x00ffffff, 0x00ffffff, 5, 0);


			OvrMatSymbP ovrMatSymb = context->GetOverrideMatSymb();

			//ovrMatSymb->SetIndexedLineColor(0, 0);
			if (mdlModelRef_isActiveModel(edp->h.dgnModelRef) || iDrawMode == 1) // на референсах отрисовка окончаний с той-же прозрачностью
			{
				ovrMatSymb->SetTransparentLineColor(50);
				ovrMatSymb->SetTransparentFillColor(50);
			}
			//ovrMatSymb->SetWidth(5);

			PD(output)ActivateOverrideMatSymb(ovrMatSymb);

			//context->CookElemDisplayParams(*elemIterP); // убирает сдвиг свойств (прозрачность и т.д.)

			//ElemDisplayParamsP dpP = context->GetCurrentDisplayParams();
			//int typ1 = mdlElement_getType(&edp->el);
			//int typ2 = mdlElement_getType(elp);
			//printf("dp=%i  type %i %i   %u  tr=%.1f / %.1f\n", drawPurpose, typ1, typ2, mdlElmdscr_getFilePos(edp), mdlElement_getTransparency(&edp->el), dpP->m_transparency);

			drawReinElm(elemIterP, newEdPP, edp, rmP, relmP, viewPortP, context, iBlock, bPlot, NULL, iDrawMode, rirP, drawPurpose);
		}


	}


	writeLogOut(__FUNCTION__, 0, TRUE); // callbackUpdateElement out

	//for(int i = 0; (!arXview.empty && i < arXview.size() || !arOview.empty && i < arOview.size()); i++)
	//{
	//	if (arX[i].x == pView.x &&
	//		arX[i].y == pView.y &&
	//		arX[i].z == pView.z
	//}


	//SUBSTELEM_STATUS_Normal     = 0x00,
	//SUBSTELEM_STATUS_Block      = 0x01,
	//SUBSTELEM_STATUS_Defer      = 0x02,

	if (iBlock > 0) retVal = SUBSTELEM_STATUS_Block;



	return retVal;
}


////////////////////////
void  callbackTimer(
	intptr_t timerArg,
	int timerHandle0

)
{
	mdlSystem_cancelTimer(timerHandle);
	hTimer = 0;
	iDblClickFP = 0;
}


//////////////////////////////////////////
StatusInt  callbackSelectUserFunction(
	SelectionSetAction* action,
	UInt32       filePos,
	DgnModelRefP       modelRef
)
{
	StatusInt ret = SUCCESS;

	//if (mdlElmdscr_getFilePos(edp) == 4001048 || mdlElmdscr_getFilePos(edp) == 4001049)
	//	printf("%u -> %i\n", mdlElmdscr_getFilePos(edp),  drawPurpose);

	writeLogIn(__FUNCTION__, 0);

	MSElementDescr* edp = NULL;

	mdlElmdscr_read(&edp, filePos, modelRef, FALSE, 0);

	UInt32 rn = getRefNum(modelRef);

	ReinModel* rmP = curRM->getRM(modelRef);

	if (edp && rmP)
	{
		ReinBar rb;
		//ReinSpace rs;
		ReinElement relem;
		ReinElm relm;

		if (readReinElmIso(&relm, edp, TRUE, TRUE) == SUCCESS)
		{
			//if (relm.bel.inum == 0)	ret = ERROR;

			if (hTimer == 0)
			{
				mdlSystem_setTimerFunction(&hTimer, 60, callbackTimer, 0, FALSE);
				iDblClickFP = filePos;
			}
			else
			{


				if (iDblClickFP == filePos)
				{

					//barCalcComparePoints(&relm.bel);

					long num = -1;

					for (MAP<long, ReinPos>::iterator it = rmP->arCurPos.begin(); it != rmP->arCurPos.end(); ++it)
					{

						ReinPos* rpItP = &it->second;

						if (barsEqual(&relm.bel, &rpItP->bar))
						{
							CatInfo ci;

							getCatInfo(&ci, edp->h.dgnModelRef, false);

							//if (rpItP->pcatID == ci.catModID)
							{
								num = it->first; // порядовый номер в массиве arCurPos
								break;
							}
						}
					}

					reinSelectPosRow(num);

				}


				mdlSystem_cancelTimer(hTimer);
				hTimer = 0;
				iDblClickFP = 0;


			}


			ret = ERROR; // юлокиреум выделение для всех производных элементов
		}
		else if (readReinBarFromElement(&rb, edp, TRUE) == SUCCESS)
		{
			// блокировка выделения неотображающихся
			if (iModelType == 0 && arPlotCfgVar[REIN_PLOT_BAR] != 0)
			{
				if (arPlotCfgVar[REIN_PLOT_BAR] == -1) ret = ERROR;
			}
			else
			{
				if (!rInfo.option[4]) ret = ERROR;
			}
		}
		else if (readReinSpaceFromElmd(&relem, edp, FALSE) == SUCCESS)
		{
			// блокировка выделения неотображающихся
			if (iModelType == 0 && arPlotCfgVar[REIN_PLOT_SPC] != 0)
			{
				if (arPlotCfgVar[REIN_PLOT_SPC] == -1) ret = ERROR;
			}
			else
			{
				if (!rInfo.option[2]) ret = ERROR;
			}
		}








		mdlElmdscr_freeAll(&edp);

		//printf("action = %i, iDataCopyCount = %i\n", *action, iDataCopyCount);


	}


	writeLogOut(__FUNCTION__, 0);

	return ret;
}



///////////////////////////////////
void   callbackReferencAttached(
	DgnModelRefP  modelRef,
	int  reason
)
{
	//reason = 
	//SYSTEM_REFATTACHED_NEW
	//SYSTEM_REFATTACHED_REATTACHED
	//SYSTEM_REFATTACHED_UNDONEDETACH
	//SYSTEM_REFATTACHED_REDONEATTACH
	//SYSTEM_REFATTACHED_RELOADED 

	//reloadBarsData(0, FALSE);

	//if (reason == SYSTEM_REFATTACHED_RELOADED)


	writeLogIn(__FUNCTION__, 0);

	bModelOutOfDate = FALSE;
	bModelCheckRefs = TRUE;

	elemIterCount = 0;
	elemCount = 0;


	// attach-reattach only for first level!

	UInt32 rn = getRefNum(modelRef);

	ReinModel* rmP = curRM->getRM(rn);

	if (rmP) curRM->arMrP.erase(rn);

	ReinModel rm(modelRef, -1);
	curRM->arMrP.insert(pair<UInt32, ReinModel>(rn, rm));

	curRM->arMrP[rn].reloadCurBars(true, true, 2, TRUE);

	//reloadHidingPositions(); // все уже загружено до нас


	//getReinElmCount(TRUE, modelRef, &arCurMrP[iModelRefCount].elcount);

	//if (arCurMrP[iModelRefCount].elcount > 0)
	//{
	//	arCurMrP[iModelRefCount].modelP = modelRef;
	//	reloadCurBars(modelRef, true, true);

	//	iModelRefCount++;

	//	if (bModelOutOfDate)
	//	{
	//		mdlOutput_messageCenter(MESSAGE_WARNING, "Model version of reference is out of date!\nThe regeneration of model in reference file is strongly recommended.", 
	//			"The version of attached reinforcement model is lower than current. It is strongly recommended that you regenerate the model of attached reference.", MESSAGE_ALERT_BALLOON);
	//	
	//		bModelOutOfDate = FALSE;
	//	}
	//}

	writeLogOut(__FUNCTION__, 0);

}


/////////////////////////////////
void   callbackReferenceModified  ( 
#if defined (MSVERSION) && (MSVERSION == 0xa00)
	DgnAttachmentCP pOldRef, 
	DgnAttachmentCP pNewRef, 
	DgnModelRefP modelRef, 
	bool changesWritten, 
	bool isUndo
#else
	ReferenceFile*  pOldRef,  
	ReferenceFile*  pNewRef,  
	DgnModelRefP  modelRef,  
	bool  changeWritten  
#endif
)
{

	writeLogIn(__FUNCTION__, 0);

	ReinModel* rmP = curRM->getRM(modelRef);

	if (rmP 
#if defined (MSVERSION) && (MSVERSION == 0xa00)
		&& !pOldRef->IsDisplayed()
		&& pNewRef->IsDisplayed()
#else
		&& !pOldRef->display.fd_opts.display
		&& pNewRef->display.fd_opts.display 
#endif
		&& rmP->mapElms.empty() // если при старте MS референс выключен то элементы тоже не загружены
		)
		rmP->reloadCurBars(true, true, 2, TRUE);


#if defined (MSVERSION) && (MSVERSION == 0x8b0)

	DVec3d ptmp[2];
	ptmp[0].x = pOldRef->display.mast_org.x;
	ptmp[0].y = pOldRef->display.mast_org.y;
	ptmp[0].z = pOldRef->display.mast_org.z;
	ptmp[1].x = pNewRef->display.mast_org.x;
	ptmp[1].y = pNewRef->display.mast_org.y;
	ptmp[1].z = pNewRef->display.mast_org.z;

	// если референс перемещен (команда move)
	if (!mdlVec_equal(&ptmp[0], &ptmp[1]))
	{
		if (rmP->tedSecP && mdlTransient_isValid(rmP->tedSecP))
		{
			mdlTransient_free(&rmP->tedSecP, TRUE);
			rmP->tedSecP = NULL;
		}

		//rmP->reloadCurBars(true, true, 2, TRUE);
	}

#endif

	writeLogOut(__FUNCTION__, 0);

}

//////////////////////////////////////
void callbackCommandCleanup()
{
	iDataCopyCount = 0;
	dataCopyNewElemID = 0;
}


///////////////////////////////////
void callbackWindowModify(
	MSWindow* window,         //=> window that event applies to 
	int             eventType,      //=> type of event 
	BSIRect* oldGlobalP      //=> old global rectangle 
)
{

	if (mdlWindow_isDialogBox(window) == FALSE) return;


	//  printf ("MDL window modify: window=%x event=%d oldRect=[(%d,%d),(%d,%d)]\n",
		  //window, eventType,
		  //oldGlobalP->origin.x, oldGlobalP->origin.y, 
		  //oldGlobalP->corner.x, oldGlobalP->corner.y);


}



///////////////////////////////////
void   callbackReferenceDetached(
	DgnModelRefP  modelRef,
#if defined (MSVERSION) && (MSVERSION == 0xa00)
	WCharCP fullFileSpec,
	DgnPlatform::DgnAttachmentDetachedReason reason
#else
	char* fullFileSpec,
	int  reason
#endif
)
{
	//reason = 
	//SYSTEM_REFDETACHED_DETACHED 
	//SYSTEM_REFDETACHED_UNDONEATTACH 
	//SYSTEM_REFDETACHED_REDONEDETACH 
	//SYSTEM_REFDETACHED_MODELDELETED 
	//SYSTEM_REFDETACHED_RELOADED 


	//if (reason == SYSTEM_REFDETACHED_RELOADED)

	UInt32 rn = getRefNum(modelRef);

	ReinModel* rmP = curRM->getRM(rn);

	if (rmP)
	{
		rmP->arMrP.erase(rn);
	}





	//UInt32 rn = getRefNum(modelRef);
	//for (int i = 0; arCurMrP[rn] && i < MAX_REF_SLOT; i++)
	//{
	//	destroyModel(&arCurMrP[rn][i], TRUE, TRUE, TRUE);
	//}

	//delete[] arCurMrP[rn];
	//arCurMrP[rn] = NULL;


}



///////////////////////////////////
void  callbackElmDscrCopy(
#if defined (MSVERSION) && (MSVERSION == 0xa00)
	EditElementHandleR eeeh,
#else
	MSElementDescr** edPP,
#endif
	DgnModelRefP       sourceModelRef,
	DgnModelRefP       destModelRef,
	bool       preCopy
)
{

#if defined (MSVERSION) && (MSVERSION == 0xa00)
	MSElementDescr* edP = eeeh.GetElementDescrP();
#else
	MSElementDescr* edP = *edPP;
#endif
	//ReinSpace rs;
	ReinElement relem;
	int bSrc = FALSE;


	writeLogIn(__FUNCTION__, 0);

	if (iDebug) sprintf(sLogMes, "mdlSelect_numSelected = %i\n", mdlSelect_numSelected()); writeLog(0, 0);

	if (preCopy)
	{
		ELREF eref;

		if (readReinElmIso(&reCopyFrom, edP, TRUE, TRUE) == SUCCESS)
		{
			if (reCopyFrom.type == REIN_ELEM_BAR)
			{
				//ищем соотв. REIN_ELEM_ISO

				ScanCriteria* scP = NULL;
				int status;
				ReinElm re;
				ReinBar rb;
				ReinSpace rs;
				DPoint3d prng[4];
				ScanRange sr;

				mdlElmdscr_computeRange(&prng[0], &prng[1], edP, NULL);

				sr.xlowlim = (Int64)(prng[0].x - mdlCnv_masterUnitsToUors(dDupTol));
				sr.ylowlim = (Int64)(prng[0].y - mdlCnv_masterUnitsToUors(dDupTol));
				sr.zlowlim = (Int64)(prng[0].z - mdlCnv_masterUnitsToUors(dDupTol));

				sr.xhighlim = (Int64)(prng[1].x + mdlCnv_masterUnitsToUors(dDupTol));
				sr.yhighlim = (Int64)(prng[1].y + mdlCnv_masterUnitsToUors(dDupTol));
				sr.zhighlim = (Int64)(prng[1].z + mdlCnv_masterUnitsToUors(dDupTol));

				ReinPrm prm;
				prm.edP = edP;
				prm.wstr = L"copy";

				scP = mdlScanCriteria_create();
				status = mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
				status = mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)scanForDuplicate, &prm);
				//status = mdlScanCriteria_setElementTypeTest (scP, typeMask, sizeof (typeMask));
				status = mdlScanCriteria_setDrawnElements(scP);
				status = mdlScanCriteria_setRangeTest(scP, &sr); // супер
				mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
				status = mdlScanCriteria_setModel(scP, sourceModelRef);
				//==========================================
				status = mdlScanCriteria_scan(scP, NULL, NULL, NULL);
				//==========================================
				mdlScanCriteria_free(scP);

				// returned elem id
				if (prm.prmid)
				{
					ELREF erf = getElemRefByID(sourceModelRef, prm.prmid);

					if (erf)
					{

						MSElementDescr* edp1 = NULL;

						mdlElmdscr_getByElemRef(&edp1, erf, sourceModelRef, FALSE, 0);

						if (edp1)
						{
							if (readReinElmIso(&reCopyFrom, edp1, TRUE, TRUE) != SUCCESS)
							{
								reCopyFrom.clear();
							}

							mdlElmdscr_freeAll(&edp1);
						}
					}
				}
			}
			
			if (reCopyFrom.type == REIN_ELEM_ISO)
			{
				reCopyFrom.bel.ffpos[reCopyFrom.type] = mdlElmdscr_getFilePos(edP);

				bCopyFromRef = !mdlModelRef_isActiveModel(sourceModelRef);

				mdlElmdscr_orientationExt(&tmCopySrc, edP, destModelRef);

				eref = getElemRefByID(sourceModelRef, reCopyFrom.bel.elemid);
				if (eref)
				{
					//printf("re.type = %i\n", re.type);
					mdlElmdscr_getByElemRef(&edCopyP, eref, sourceModelRef, FALSE, 0);
					if (iDebug) sprintf(sLogMes, "get edCopyP - source element\n"); writeLog(0, 0);

					ReinData rd;

					if (readReinDataFromElmd(&rd, edCopyP, &reCopyFrom.bel) == SUCCESS)
					{
						ScanCriteria* pScanCriteria;
						int status;

						pScanCriteria = mdlScanCriteria_create();
						status = mdlScanCriteria_setReturnType(pScanCriteria, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
						status = mdlScanCriteria_setElmDscrCallback(pScanCriteria, (PFScanElemDscrCallback)scanForCopyDataBars, &reCopyFrom.bel.elemid);
						status = mdlScanCriteria_setModel(pScanCriteria, ACTIVEMODEL);
						mdlXML_addXMLFragmentAttachmentScanTest(pScanCriteria, &appID, &appTypeReinBar);
						status = mdlScanCriteria_scan(pScanCriteria, NULL, NULL, NULL);
						status = mdlScanCriteria_free(pScanCriteria);

					}
				}
			}
		}
		else if (readReinBarFromElement(&reCopyFrom.bel, edP, TRUE) == SUCCESS)
		{
			//eref = getElemRefByID (sourceModelRef, reCopyFrom.bel.elemid);

			//if (eref)
			//{
			//	//printf("re.type = %i\n", re.type);
			//	mdlElmdscr_getByElemRef (&edCopyP, eref, sourceModelRef, FALSE, 0);
			//}

			bSrc = TRUE;
		}
		else if (readReinSpaceFromElmd(&relem, edP, FALSE) == SUCCESS)
		{
			bSrc = TRUE;
		}

		ELID elid = mdlElement_getID(&edP->el);

		if (elid)
		{
			if (curRM->vExIds[elid]) elidDisplayCopy = elid;
		}

		/*
		for (vector<ELID>::iterator it = curRM->vExIds.begin(); bSrc && it != curRM->vExIds.end(); ++it)
		{
			if (*it == mdlElement_getID(&edP->el))
			{
				elidDisplayCopy = *it;
				break;
			}
		}*/

		//for (UInt32 i = 0; bSrc && i < iIDcount; i++)
		//{
		//	if (arID[i] == mdlElement_getID(&edP->el))
		//	{
		//		elidDisplayCopy = arID[i];
		//		break;
		//	}
		//}

	}

	writeLogOut(__FUNCTION__, 0);

}

///////////////////////////////////
void vecAllocInt(vector<vector<int>>* vecP, int iSize)
{

	for (vector<vector<int>>::iterator it = vecP->begin(); it != vecP->end(); ++it)
	{
		it->clear();
		if (iSize) it->resize(iSize);
	}

}

///////////////////////////////////
void vecAllocLong(vector<vector<long>>* vecP, int iSize)
{

	for (vector<vector<long>>::iterator it = vecP->begin(); it != vecP->end(); ++it)
	{
		it->clear();
		if (iSize) it->resize(iSize);
	}

}


	/////////////////////////////////////////
	//func callback Provide Description
	void callbackProvideDescription(
#if defined (MSVERSION) && (MSVERSION == 0xa00)
		DisplayPathCP path,
		WStringR description
#else
		DisplayPathP    path,            //=> display path 
		MSWCH* description,     //<=> description 
		MSWCH* refStr           //=> Ref string 
#endif
	)
	{
		MSElementDescr* edP;
		ELREF  elmRef;
		//MSElement   el;
		int         elSize;
		ELID elid = 0;
		ELID elidRnd = 0;
		UInt32 refnum = 0;
		UInt32 elfp = 0;
		UInt32 barfp = 0;
		ReinElm* relmP = NULL;
		ReinElm relm;
		//ReinSpace rs;
		ReinElement relem;
		ReinBar rb;
		CatInfo ci;

		ReinSpace* rsP = NULL;
		ReinBar* rbP = NULL;

		MSWCH  dopdescr[200] = L"";
		MSWCH         levName[MAX_LEVEL_NAME_LENGTH] = L"";

		bool bProcess = false;
		bool bExtern = false; // rondo, transient, ...

		writeLogIn(__FUNCTION__, 0);

		ci.clear();

		// Get the element
		//elmRef = mdlDisplayPath_getCursorElem (path);
		elmRef = mdlDisplayPath_getElem(path, 0);
		//elSize = elementRef_getElement (elmRef, &el, sizeof el);

		//MSElementDescr* edptmp = NULL;
		//ElementRef  ereftmp = mdlDisplayPath_getCursorElem(path);
		//mdlElmdscr_getByElemRef (&edptmp, ereftmp, mdlDisplayPath_getPathRoot(path), FALSE, 0);

		if (elmRef == NULL)
		{
			writeLogOut(__FUNCTION__, "elmRef == NULL");
			return;
		}

		elid = elementRef_getElemID(elmRef);

		if (elid == 0)
		{
			writeLogOut(__FUNCTION__, "elid == 0");
			return;
		}

		elfp = elementRef_getFilePos(elmRef);

		int t = elementRef_getElemType(elmRef);

		//printf("%S\n", description);

		// Р А Б О Т А Е Т
		//{
		//	XMLFragmentListP  oXMLFragmentList = NULL;
		//	//mdlSystem_enterDebug();
		//	if (mdlXMLFragmentList_extractFromElementByAppIDAndType (&oXMLFragmentList, &el, &appID, &appTypeTrans) == SUCCESS)
		//	{
		//		XMLFragmentP  pXMLFragment;
		//		MSWCH* wtxt;
		//		char ctxt[500];
		//		pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);
		//		mdlXMLFragment_getText(&wtxt, pXMLFragment);
		//		mdlCnv_convertUnicodeToMultibyte(wtxt, -1, ctxt, 500);
		//		mdlXMLFragmentList_free(&oXMLFragmentList);
		//		printf("%s\n", ctxt);
		//	}
		//}

		DgnModelRefP mrP = mdlDisplayPath_getPathRoot(path);

		if (mdlModelRef_isTransient(mrP))
		{
			bProcess = true;
			bExtern = true;
		}

		if (elmRef)
		{
			MSElementDescr* edTmpP;

			mdlElmdscr_getByElemRef(&edTmpP, elmRef, mdlDisplayPath_getPathRoot(path), FALSE, 0);

			if (edTmpP)
			{

				if (mdlElement_hasXMLFragmentAttachment(&edTmpP->el, &appID, &appTypeReinElm)) // ReinElm
					bProcess = true;

				if (mdlElement_hasXMLFragmentAttachment(&edTmpP->el, &appID, &appTypeReinBar)) // ReinBar
					bProcess = true;

				if (mdlElement_hasXMLFragmentAttachment(&edTmpP->el, &appID, &appTypeReinSpace)) // ReinSpace
					bProcess = true;

				if (mdlElement_hasXMLFragmentAttachment(&edTmpP->el, &appID, &appTypeBarOver)) // ReinClash
					bProcess = true;

				if (mdlElement_hasXMLFragmentAttachment(&edTmpP->el, &appID, &appTypeReinCache)) // ReinCache
					bProcess = true;

				if (mdlElement_hasXMLFragmentAttachment(&edTmpP->el, &appID, &appTypeRndResult) // развертка
					&& t == BSPLINE_CURVE_ELM
					) // 
				{
					if (readRndFromElement(&elidRnd, &refnum, &edTmpP->el) == SUCCESS)
						bExtern = true;
				}

				mdlElmdscr_freeAll(&edTmpP);
			}
		}


		if (!bProcess)
		{
			writeLogOut(__FUNCTION__, "no elem to process, return");
			return;
		}


		bool bcalclen = true;
		double dbarlen = 0.;
		long rad = 0;

		//UInt32 rn = getRefNum(mdlDisplayPath_getPathRoot(path));

		ReinModel* rmP = curRM->getRM(mrP);

		if (rmP == NULL)
		{

			if (mdlModelRef_isTransient(mrP)) // TRANSIENT
			{
				ReinClash rc;
				int res = -2;

				elementRef_getElement(elmRef, &el, sizeof el);

				//UInt32 fptr = elementRef_getFilePos(elmRef);

				////printf("%u\n", fptr);

				//relmP = curRM->findElementByTransient(fptr);
				//
				//if (relmP)
				//{
				//	rmP = curRM->getRM(relmP->bel.modrefP);
				//}
				//else
					res = readReinClashFromElement(&rc, &el);


				//MAP<UInt32, ReinClash>::iterator it = mapClash.find(elfp);
				//if (it != mapClash.end()) // found
				if (res == SUCCESS && relmP == NULL)
				{
					MSWCH wstrdesc[500];
					MSWCH wstr[100];

					wcscpy(wstrdesc, L"Коллизия\n");

					_swprintf(wstr, L"Конфликт %u мм\n", rc.idist);
					wcscat(wstrdesc, wstr);

					_swprintf(wstr, L"для диаметров рифления %.1f и %.1f\n", rc.cdiam[0], rc.cdiam[1]);
					wcscat(wstrdesc, wstr);

					if (mdlLevel_getName(levName, 512, ACTIVEMODEL, rc.lvID[0]) == SUCCESS)
					{
						_swprintf(wstr, L"Слой: %s\n", levName);
						wcscat(wstrdesc, wstr);
					}

					if (mdlLevel_getName(levName, 512, ACTIVEMODEL, rc.lvID[1]) == SUCCESS)
					{
						_swprintf(wstr, L"Слой: %s\n", levName);
						wcscat(wstrdesc, wstr);
					}

#if defined (MSVERSION) && (MSVERSION == 0xa00)
					description = wstrdesc;
#else
					wcscpy(description, wstrdesc);
#endif

					if (tedBarsP)
					{
						mdlTransient_free(&tedBarsP, 1);
						tedBarsP = NULL;
					}

					if (rc.idElem3d[0] && rc.idElem3d[1]) // elem IDs
					{

						ELREF eref1 = getElemRefByID(ACTIVEMODEL, rc.idElem3d[0]);
						ELREF eref2 = getElemRefByID(ACTIVEMODEL, rc.idElem3d[1]);

						if (eref1 && eref2)
						{
							MSElementDescr* edp1 = NULL;
							MSElementDescr* edp2 = NULL;
							MSElementDescr* edpTr1 = NULL;
							MSElementDescr* edpTr2 = NULL;

							mdlElmdscr_getByElemRef(&edp1, eref1, ACTIVEMODEL, FALSE, 0);
							mdlElmdscr_getByElemRef(&edp2, eref2, ACTIVEMODEL, FALSE, 0);


							if (edp1 && edp2
								// && readReinElmFromElement()
								)
							{
								mdlElmdscr_duplicate(&edpTr1, edp1);
								mdlElmdscr_duplicate(&edpTr2, edp2);

								//mdlElmdscr_setProperties(edpTr1, &levClash, 0, 0, 0, 0, 0, 0, 0);
								//mdlElmdscr_setProperties(edpTr2, &levClash, 0, 0, 0, 0, 0, 0, 0);
								func_amp(mdlElmdscr_setProperties, edpTr1), & levClash, 0, 0, 0, 0, 0, 0, 0);
								func_amp(mdlElmdscr_setProperties, edpTr2), & levClash, 0, 0, 0, 0, 0, 0, 0);


								mdlXMLFragmentList_stripAllFromElement(NULL, &edpTr1->el);
								mdlXMLFragmentList_stripAllFromElement(NULL, &edpTr2->el);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
								DgnFileP dfP = ISessionMgr::GetActiveDgnFile();
								int ind = DisplayStyleManager::GetIndexForDisplayStyle(L"Transparent", dfP);
								mdlElement_setDisplayStyle(&edpTr1->el, ind);
								mdlElement_setDisplayStyle(&edpTr2->el, ind);
#else
								DgnCacheP dfP = Bentley::Ustn::ISessionMgr::GetActiveDgnCache();
								MSDgnFileP fileP = dfP->GetMSDgnFile();
								wstring dsname = L"Transparent";

								int ind = Bentley::Ustn::DisplayStyleManager::GetIndexForDisplayStyle(*dsname.c_str(), fileP);

								//DisplayStyleCP dsP = Bentley::Ustn::DisplayStyleManager::FindDisplayStyleByName(*dsname.c_str(), fileP);

								//DisplayStyleCP dsP = Bentley::Ustn::DisplayStyleManager::GetDisplayStyleByIndex(ind, *fileP);

								//Bentley::Ustn::DisplayStyleManager::EnsureDisplayStyleIsInFile(*dsP, *fileP);

								mdlElement_setDisplayStyle(&edpTr1->el, ind);
								mdlElement_setDisplayStyle(&edpTr2->el, ind);
#endif
								tedBarsP = mdlTransient_addElemDescr(tedBarsP, edpTr1, 1, 0x00ff, DRAW_MODE_Normal, 1, 0, 1);
								tedBarsP = mdlTransient_addElemDescr(tedBarsP, edpTr2, 1, 0x00ff, DRAW_MODE_Normal, 1, 0, 1);

								mdlElmdscr_freeAll(&edp1);
								mdlElmdscr_freeAll(&edp2);
							}
						}
					}
				}
				else if (relmP == NULL) // if not ReinClash
				{
					ReinCache rch;
					res = readReinCacheFromElement(&rch, &el);

					if (res == SUCCESS && wcsncmp(rch.desc, L"#####", 5) == 0) // section point
					{
						MSWCH* strfp = rch.desc;
						strfp += 5;
						UInt32 fpPnt = wcstoul(strfp, 0, 0);

						//ELREF erefPnt = getElemRefByID(rch.mrP, rch.elid);

						ReinModel* rmPntP = curRM->getRM(rch.mrP);

						if (rmPntP && fpPnt)
						{
							//UInt32 fpPnt = elementRef_getFilePos(erefPnt);
							relmP = rmPntP->getReinElm(fpPnt);
							if (relmP) rmP = rmPntP;
						}

					}
					else if (res == SUCCESS) // error mark element
					{

						MSWCH wstrdesc[2000];

						wcscpy(wstrdesc, L"Ошибка чтения\n");

						wcscat(wstrdesc, rch.desc);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
						description = wstrdesc;
#else
						wcscpy(description, wstrdesc);
#endif

					}
				}
			}


			if (relmP == NULL)
			{
				writeLogOut(__FUNCTION__, "transient element, return");

				return;
			}
		}

		// сначала пробуем развертку
		if (relmP == NULL && bExtern && elidRnd > 0)
		{
			deque <UInt32> aref;
			if (refnum > 0) aref.push_back(refnum);
			aref.push_back(1); // source rondo ref is always 1

			ReinModel* rmRndP = curRM->getRM(aref);
			//ReinModel* rmRndP = curRM->getRM(1);

			if (rmRndP)
			{
				ELREF erefRnd = getElemRefByID(rmRndP->modelP, elidRnd);

				if (erefRnd)
				{
					UInt32 fpRnd = elementRef_getFilePos(erefRnd);
					relmP = rmRndP->getReinElm(fpRnd);
					rmP = rmRndP;
				}
			}
		}
		

		if (relmP ==NULL)
		{
			relmP = rmP->getReinElm(elfp);
		}


		if (relmP)
		{
			relm = *relmP;
		}
		//else
		//{
		//}
			

		vecAllocLong(&arPosQty, 4);



		MSWCH  fpath[500] = L"";
		MSWCH  fName[1000];
		MSWCH         mName[MAX_MODEL_NAME_LENGTH];
		BINT iselem = FALSE;

		XMLFragmentListP  oXMLFragmentList = NULL;

		//vector <UInt32> aref;
		//UInt32 aref[MAX_REFNUM_PATH]; // обратный путь, для рефа 5->3->7 массив: [0] = 7, [1] = 3, [2] = 5
		deque<UInt32> aref;
		size_t refcnt = rmP->getRefPath(&aref);


		//for (vector<UInt32>::iterator it = aref.begin(); it != aref.end(); ++it)
		//for (UInt32 i = 0; i < aref.size(); i++)
		//{
		//	swprintf(fName, 300, L"[%u]", *it);
		//	if (wcslen(fpath) > 0) wcscat(fpath, L"->");
		//	wcscat(fpath, fName);
		//}
		for (deque<UInt32>::reverse_iterator it = aref.rbegin(); it != aref.rend(); ++it)
		//for (int i = refcnt - 1; i >= 0; i--)
		{
			_swprintf(fName, L"[%u]", *it);
			if (wcslen(fpath) > 0) wcscat(fpath, L"->");
			wcscat(fpath, fName);
		}

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		mdlModelRef_getFileName(rmP->modelP, fName, 300);
		mdlFile_parseName(fName, 0, 0, mName, 0);
#else
		mdlModelRef_getFileNameW(rmP->modelP, fName, 300);
		mdlFile_parseNameW(fName, 0, 0, mName, 0);
#endif
		_swprintf(fName, L"%s %s", fpath, mName);
		mdlModelRef_getModelName(rmP->modelP, mName);


		if (elmRef)
		{
			mdlElmdscr_getByElemRef(&edP, elmRef, mdlDisplayPath_getPathRoot(path), FALSE, 0);

			//mdlElmdscr_read(&edP, relmP->bel.ffpos[REIN_ELEM_ISO], relmP->bel.modrefP, 0, 0);

			if (edP)
			{
				UInt32 levID = 0;

				mdlElmdscr_getProperties(&levID, 0, 0, 0, 0, 0, 0, 0, edP);

				int st = mdlLevel_getName(levName, 512, mdlDisplayPath_getPathRoot(path), levID);

				
				if (relmP == NULL && readReinElmIso(&crelm, edP, 0, 0) == SUCCESS)
				{
					if (crelm.type == REIN_ELEM_BAR)
					{
						bcalclen = false;

						if (st != SUCCESS && edP->h.firstElem)
						{
							mdlElmdscr_getProperties(&levID, 0, 0, 0, 0, 0, 0, 0, edP->h.firstElem);
							mdlLevel_getName(levName, 512, mdlDisplayPath_getPathRoot(path), levID);
						}

						for (MAP<UInt32, ReinElm>::iterator it = rmP->mapElms.begin(); it != rmP->mapElms.end(); ++it)
						{
							if (it->second.bel.brid == elid)
							{
								elfp = it->second.bel.ffpos[REIN_ELEM_ISO];

								relmP = rmP->getReinElm(elfp);

								if (relmP)
								{
									relm = *relmP;

									MSElementDescrP edRelmP = NULL;
									mdlElmdscr_readToMaster(&edRelmP, elfp, mdlDisplayPath_getPathRoot(path), 0, 0);
									if (edRelmP)
									{
										mdlElmdscr_freeAll(&edP);
										edP = edRelmP;
										bcalclen = true;
									}

								}

								break;
							}
						}
					}
					else if (crelm.type == REIN_ELEM_ISO) // скорее всео в глубоком референсе
					{
						//relmP = &crelm;
						writeLogOut(__FUNCTION__, "relmP == NULL");
						return;
					}
					else
					{
						writeLogOut(__FUNCTION__, "relmP == NULL");
						return;
					}
				}


				//if (relmP && t == BSPLINE_CURVE_ELM) // для результата развертки
				//{
				//	rbP = &(relmP->bel);
				//}
				//else 
				if (relmP)
				{

					if (!bExtern)
					{
						relm.bel.ffpos[relm.type] = elementRef_getFilePos(elmRef);
						//relm.bel.mrP = mdlDisplayPath_getPathRoot(path);
						relm.bel.modrefP = edP->h.dgnModelRef;

						if (bcalclen) mdlMeasure_linearProperties(&dbarlen, 0, 0, 0, 0, 0, 0, 0, edP, -1);
						dbarlen = mdlCnv_uorsToMasterUnits(dbarlen);
					}

					//if (mdlElement_getType(&edP->el) == ARC_ELM)
					//{
					//	double drad[2];
					//	mdlArc_extract(0, 0, 0, &drad[0], &drad[1], 0, 0, &edP->el);
					//	relm.bel.rad[0] = (int) mdlCnv_uorsToMasterUnits(drad[0]);
					//	relm.bel.rad[1] = (int) mdlCnv_uorsToMasterUnits(drad[1]);
					//}

					if (mdlModelRef_isActiveModel(relm.bel.modrefP) == FALSE)
					{

						mdlRefFile_getBooleanParameters(&iselem, REFERENCE_TREAT_AS_ELEMENT, relm.bel.modrefP);
						if (iselem)
						{
							//mdlModelRef_getDisplayName(relm.bel.mrP, displayName, MAX_MODEL_DISPLAY_LENGTH, NULL);
							//mdlModelRef_getModelName(relm.bel.mrP, mName);
						}
						//else
						//{
						//	getCatInfo(&ci, relm.bel.mrP, false);
						//}
					}

					getCatInfo(&ci, relm.bel.modrefP, false);


					arPos.clear();
					arPos.resize(10);
					arPosCount.clear();
					arPosCount.resize(10);
					iPosCount = 0;


					//barCalcComparePoints(&relm.bel);


					UInt32 sfp = mdlSnap_getCurrElemFilePos();

					if (!bExtern && sfp > 0)
					{
						MSElementDescr* edpSgm = NULL;
						mdlElmdscr_read(&edpSgm, sfp, mdlSnap_getCurrModelRef(), 0, 0);
						if (edpSgm)
						{
							if (mdlElement_getType(&edpSgm->el) == ARC_ELM || mdlElement_getType(&edpSgm->el) == ELLIPSE_ELM)
							{
								double drad[2];
								mdlArc_extract(0, 0, 0, &drad[0], &drad[1], 0, 0, &edpSgm->el);
								rad = (long)roundex(mdlCnv_uorsToMasterUnits(drad[0]));
							}

							mdlElmdscr_freeAll(&edpSgm);
						}

					}

					// === показываем на эскизе =====
					{
						MSDLGP db7 = mdlDialog_find(DLG_SKETCH, NULL);
						if (db7)
						{
							curPos.clear();
							curPos.bar = relm.bel;
							//curPosP = NULL;
							DialogItem* diP = mdlDialog_itemGetByTypeAndId(db7, RTYPE_Generic, 3, 0);
							if (diP) mdlDialog_itemDraw(db7, diP->itemIndex);
						}
					}

					//rn = getRefNum(edP->h.dgnModelRef);

					for (MAP<long, ReinPos>::iterator it = rmP->arCurPos.begin(); it != rmP->arCurPos.end(); ++it)
					{

						ReinPos* rpItP = &it->second;

						if (rpItP->bar.pnum == 0) continue;

						if (barsEqual(&relm.bel, &rpItP->bar)
							//&& ci.catModID == rpItP->pcatID
							)
						{
							arPos[iPosCount++] = rpItP->bar.pnum;
						}
					}


					ELREF eref = getElemRefByID(relm.bel.modrefP, relm.bel.elemid);
					if (eref)
					{
						MSElementDescr* edp;

						mdlElmdscr_getByElemRef(&edp, eref, mdlDisplayPath_getPathRoot(path), FALSE, 0);

						if (edp)
						{
							ReinData rd;

							if (readReinBarFromElement(&rb, edp, TRUE) == SUCCESS)
							{
								rbP = &rb;
								//rb.rad[0] = relm.bel.rad[0];
								rbP->elemid = mdlElement_getID(&edp->el);
								rbP->modrefP = edp->h.dgnModelRef;
							}
							else if (readReinSpaceFromElmd(&relem, edp, FALSE) == SUCCESS)
							{
								rsP = &relem.rs;
								copySpaceData(rsP, &rb, TRUE, 0, 0);
								rbP = &rb;
								rbP->elemid = mdlElement_getID(&edp->el);
								rbP->modrefP = edp->h.dgnModelRef;
							}
							else if (readReinDataFromElmd(&rd, edp, &relm.bel) == SUCCESS)
							{
								rbP = &relm.bel;
								rbP->elemid = mdlElement_getID(&edp->el);
								rbP->modrefP = edp->h.dgnModelRef;
							}


							mdlElmdscr_freeAll(&edp);
						}
					}

				}
				else if (readReinBarFromElement(&rb, edP, TRUE) == SUCCESS)
				{
					if (rb.elemid == 0) rb.elemid = elid;
					rb.modrefP = mdlDisplayPath_getPathRoot(path);

					rbP = &rb;

					arPos.clear();
					arPos.resize(10);
					arPosCount.clear();
					arPosCount.resize(10);
					iPosCount = 0;


					if (rb.bartype != BT_AXIS && rb.elemid > 0) // образующая ось
					{
					}

					for (MAP<UInt32, ReinElm>::iterator it = rmP->mapElms.begin(); it != rmP->mapElms.end(); ++it)
						//for (UInt32 i = 0; rmP && i < rmP->vecElms.size(); i++)
					{
						ReinElm* rlmP = &(it->second);

						if (rlmP)
						{
							if (rlmP->bel.elemid == rb.elemid)
							{
								int bExist = FALSE;

								for (int j = 0; j < iPosCount; j++)
								{
									if (arPos[j] == rlmP->bel.pnum) bExist = TRUE;
								}

								if (bExist == FALSE) arPos[iPosCount++] = rlmP->bel.pnum;
								if (iPosCount == 9) break;
							}
						}
					}


				}
				else if (readReinSpaceFromElmd(&relem, edP, FALSE) == SUCCESS)
				{
					rb.elemid = elid;
					rb.modrefP = mdlDisplayPath_getPathRoot(path);

					rsP = &relem.rs;
					rbP = &rb;

					arPos.clear();
					arPos.resize(10);
					arPosCount.clear();
					arPosCount.resize(10);
					iPosCount = 0;

					ReinModel* rbmP = curRM->getRM(rb.modrefP);

					for (MAP<UInt32, ReinElm>::iterator it = rbmP->mapElms.begin(); it != rbmP->mapElms.end(); ++it)
						//for (UInt32 i = 0; rbmP && i < rbmP->vecElms.size(); i++)
					{
						ReinElm* rlmP = &(it->second);

						if (rlmP)
						{
							if (rlmP->bel.elemid == rb.elemid)
							{
								int bExist = FALSE;

								for (int j = 0; j < iPosCount; j++)
								{
									if (arPos[j] == rlmP->bel.pnum) bExist = TRUE;
								}

								if (bExist == FALSE && rlmP->bel.pnum > 0) arPos[iPosCount++] = rlmP->bel.pnum;
								if (iPosCount == 9) break;
							}

							//if (iPosCount > 0)
							//{
							//	if (rlmP->bel.elemid == mdlElement_getID(&edP->el) && rlmP->bel.pnum == arPos[0])
							//		arPosQty[0][0]++;

							//	if (rlmP->bel.pnum == arPos[0])
							//		arPosQty[0][1]++;
							//}
						}
					}
				}

				for (MAP<UInt32, ReinElm>::iterator it = rmP->mapElms.begin(); rbP && iPosCount > 0 && it != rmP->mapElms.end(); ++it)
					//for (UInt32 i = 0; rmP && rbP && iPosCount > 0 && i < rmP->vecElms.size(); i++)
				{
					ReinElm* rlmP = &(it->second);
					if (rlmP == NULL) continue;

					if (rlmP->bel.elemid == rbP->elemid && rlmP->bel.pnum == arPos[0])
						arPosQty[0][0]++;

					if (rlmP->bel.pnum == arPos[0])
						arPosQty[0][1]++;

					long len = roundExt(rlmP->bel.length, ROUND_LIN);


					if (rlmP->bel.elemid == rbP->elemid && rlmP->bel.pnum == arPos[0])
					{
						if (arPosQty[0][2] == 0) arPosQty[0][2] = len;
						if (arPosQty[0][3] == 0) arPosQty[0][3] = len;

						if (len < arPosQty[0][2]) arPosQty[0][2] = len;
						if (len > arPosQty[0][3]) arPosQty[0][3] = len;
					}


					if (iPosCount > 1)
					{
						if (rlmP->bel.elemid == rbP->elemid && rlmP->bel.pnum == arPos[1])
							arPosQty[1][0]++;

						if (rlmP->bel.pnum == arPos[1])
							arPosQty[1][1]++;

						if (rlmP->bel.elemid == rbP->elemid && rlmP->bel.pnum == arPos[1])
						{
							if (arPosQty[1][2] == 0) arPosQty[1][2] = len;
							if (arPosQty[1][3] == 0) arPosQty[1][3] = len;

							if (len < arPosQty[1][2]) arPosQty[1][2] = len;
							if (len > arPosQty[1][3]) arPosQty[1][3] = len;
						}
					}
				}


				mdlElmdscr_freeAll(&edP);
			}
		}


		int bFillet = FALSE;

		elmRef = mdlDisplayPath_getCursorElem(path);

		if (elmRef)
		{
			mdlElmdscr_getByElemRef(&edP, elmRef, mdlDisplayPath_getPathRoot(path), FALSE, 0);

			if (edP && mdlElement_hasXMLFragmentAttachment(&edP->el, &appID, &appTypeSegment))
			{
				if (mdlXMLFragmentList_extractFromElementByAppIDAndType(&oXMLFragmentList, &edP->el,
					&appID, &appTypeSegment) == SUCCESS)
				{
					XMLFragmentP  pXMLFragment;
					MSWCH* wtxt;
					//char str[200];
					pXMLFragment = mdlXMLFragmentList_getXMLFragment(oXMLFragmentList);

					if (pXMLFragment && mdlXMLFragment_getText(&wtxt, pXMLFragment) == SUCCESS)
					{
						wstring wstr(wtxt);
						//mdlCnv_convertUnicodeToMultibyte(ws, -1, str, 200);
						mdlXMLFragmentList_free(&oXMLFragmentList);

						ReinPrm prm;
						prm.clear();
						prm.dval[0] = -1.;
						if (readReinFilletFromString(&prm, wstr) == SUCCESS)
						{
							int ilen = prm.ival[0];
							int irad = prm.ival[1];
							double dang = prm.dval[0];

							_swprintf(dopdescr, L"\n\tзакругление:\n\tдлина %i\n\tрадиус %i\n\tугол %.1f", ilen, irad, dang);

							//wcscat(description, wstr);

							bFillet = TRUE;
						}
					}
				}

				mdlElmdscr_freeAll(&edP);

				//if (bFillet) return;

			}
		}



		//printf("%i\n", iPosCount);
		//mdlSystem_enterDebug();



#if defined (MSVERSION) && (MSVERSION == 0xa00)
		MSWCH wstrdesc[5000];
		if (setElemDescrTooltip(rbP, rsP, wstrdesc, dbarlen, iselem, fName, mName, levName, rad, dopdescr) == SUCCESS)
			description = wstrdesc;
#else
		setElemDescrTooltip(rbP, rsP, description, dbarlen, iselem, fName, mName, levName, rad, dopdescr);
#endif

		writeLogOut(__FUNCTION__, 0);

	}

	///////////////////////////////////////
	//void  callbackElementLocated  (
	//MSElement*       element , 
	//DgnModelRefP       modelRef , 
	//long       filePos , 
	//DVec3d*       point , 
	//int       viewNum  
	//)
	//{
	//
	//	//iReinBarSelectedQty
	//	printf("mdlSelect_numSelected = %i\n", mdlSelect_numSelected());
	//
	//}


	///////////////////////////////////////
	//LocateFilterStatus  callbackLocate  ( 
	//LOCATE_Action       action , 
	//MSElement*       pElement , 
	//DgnModelRefP       modelRef , 
	//UInt32       filePos , 
	//DVec3d*       pPoint , 
	//int       viewNumber , 
	//HitPathP       hitPath , 
	//char*       rejectReason  
	//)
	//{
	//	LocateFilterStatus ret =  LOCATE_FILTER_STATUS_Neutral;
	//
	//	printf("%i\n", mdlSelect_numSelected());
	//
	//	return ret;
	//}



///////////////////////////////////////
	LocateFilterStatus  callbackLocateFilter(
#if defined (MSVERSION) && (MSVERSION == 0xa00)
		DgnPlatform::LOCATE_Action  action,
		MSElementCP                 pElement,
		DgnModelRefP                modelRef,
		UInt32                      filePos,
		DPoint3dCP                  pPoint,
		int                         viewNumber,
		HitPathCP                   hitPath,
		WStringR                    rejectReason
#else
		LOCATE_Action       action,
		MSElementCP       pElement,
		DgnModelRefP       modelRef,
		UInt32       filePos,
		DVec3d* pPoint,
		int       viewNumber,
		HitPathCP       hitPath,
		char* rejectReason
#endif
	)
	{

		//GLOBAL_LOCATE_IDENTIFY       = 1 ,  
		//GLOBAL_LOCATE_SELECTIONSET       = 2 ,  
		//GLOBAL_LOCATE_FENCE       = 3 ,  
		//GLOBAL_LOCATE_FENCECLIP       = 4 ,  
		//GLOBAL_LOCATE_SNAP       = 5 ,  
		//GLOBAL_LOCATE_AUTOLOCATE       = 6 ,  


		filePosReinFrom = 0;


		//MSElementDescr* edP = NULL;
		////int res;
		LocateFilterStatus ret = LOCATE_FILTER_STATUS_Neutral;
		CommandNumber cnum;


		writeLogIn(__FUNCTION__, 0);
		if (iDebug) sprintf(sLogMes, "action = %i\n", action); writeLog(0, 0);

		////mdlSystem_enterDebug();

		////if (BRYS) return LOCATE_FILTER_STATUS_Neutral;

		////printf(" >>>>>>>>>>> %S\n", mdlState_getCurrentCommandName());

		if (action == GLOBAL_LOCATE_AUTOLOCATE)
		//if (action == LOCATE_Action::GLOBAL_LOCATE_AUTOLOCATE)
		{
			writeLogOut(__FUNCTION__, "GLOBAL_LOCATE_AUTOLOCATE, return");
			return LOCATE_FILTER_STATUS_Neutral;
		}


		if (mdlInput_commandState1(NULL, &cnum, NULL, NULL) == PRIMITIVE_COMMAND)
		{
			//if (cnum == CMD_REIN_MODIFY) return LOCATE_FILTER_STATUS_Neutral;
			//if (cnum == CMD_REIN_SIDE) return LOCATE_FILTER_STATUS_Neutral;
			//if (cnum == CMD_REIN_UNGRAB) return LOCATE_FILTER_STATUS_Neutral;

			if (cnum == CMD_REIN_NOTE || cnum == CMD_REIN_BARSET)
			{
				writeLogOut(__FUNCTION__, "CommandNumber REIN_..., return");
				return LOCATE_FILTER_STATUS_Neutral;
			}

		}


		//if (mdlElmdscr_getFilePos(edp) == 4001048 || mdlElmdscr_getFilePos(edp) == 4001049)
		//	printf("%u -> %i\n", mdlElmdscr_getFilePos(edp),  drawPurpose);


		////MSElementDescr* edLocP = NULL;
		////mdlElmdscr_readToMaster(&edLocP, filePos, modelRef, 0, 0);




		//UInt32 fp = mdlElmdscr_read(&edp, filePos, modelRef, FALSE, 0);
		//UInt32 fp = elementRef_getFilePos(eh.GetElementRef());

//		MSElementCP                 pElementLoc = NULL;
//
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//		pElementLoc = pElement;
//
//		ElementHandle eh(pElement, modelRef);
//		
//
//#else
//		if (mdlElement_read(&elLocate, modelRef, filePos) != SUCCESS) return LOCATE_FILTER_STATUS_Neutral;
//		pElementLoc = &elLocate;
//#endif

		/*
		
		mdlKISolid_beginCurrTrans(ACTIVEMODEL);
		//=====================================================

		MSElementDescr* edLocP = NULL;
		mdlElmdscr_readToMaster(&edLocP, filePos, modelRef, 0, 0);
		checkClosest(&edLocP);
		mdlElmdscr_freeAll(&edLocP);

		//=====================================================
		mdlKISolid_endCurrTrans();
*/


		MSElementDescr* edLocP = NULL;
		UInt32 fp = mdlElmdscr_readToMaster(&edLocP, filePos, modelRef, 0, 0);


		//__try
		//{

		if (fp && edLocP)
		{
			ReinElm relm;
			ReinBar rb;
			//ReinSpace rs;
			ReinElement relem;
			ReinAxis ra;

			if (relm.getElmFromElement(&edLocP->el, modelRef) == SUCCESS)
			{

				if (cnum == CMD_REIN_BAROVER && rBarOverInfo.dopopt[21] == BAROVER_ACTION_RESET)
					ret = LOCATE_FILTER_STATUS_Reject;
				else if (cnum == CMD_REIN_BAROVER)
					ret = LOCATE_FILTER_STATUS_Neutral;

				// блокируем операции для произв. эл-тов отдельных стержней
				if ((relm.bel.inum == 0 || relm.bel.bartype != BT_AXIS) &&
					rInfo.option[4] // если включено отображение ReinBar
					&& !(cnum == CMD_0x0e0300 && relm.bel.inum > 0)  // copy from contour
					&& !(cnum == CMD_0x0C0300 && relm.bel.inum > 0)  // move from contour
					&& !(cnum == CMD_0x010100 // common selection
						&& relm.bel.bartype != BT_AXIS // было убрано потому что не показывает эскиз когда щелкаешь на одиночный стержень 
														// вернули тк если щелкаешь на стержень - не выделяется ось
						)  // element selection for line contours (for iDblClickFP)
					&& !(cnum == CMD_0x010200)  // dimension
					)
				{
					ret = LOCATE_FILTER_STATUS_Reject;
				}

				if (relm.type == REIN_ELEM_BAR) // объемный стержень
				{
					/*
					mdlKISolid_beginCurrTrans(ACTIVEMODEL);
					//=====================================================

					MSElementDescr* edLocP = NULL;
					mdlElmdscr_readToMaster(&edLocP, filePos, modelRef, 0, 0);
					checkClosest(&edLocP);
					mdlElmdscr_freeAll(&edLocP);

					//=====================================================
					mdlKISolid_endCurrTrans();
					*/

					//ret = LOCATE_FILTER_STATUS_Reject;
				}

				//if (rInfo.option[4] == FALSE)
			}
			else if (readReinBarFromElem(&rb, &edLocP->el) == SUCCESS)
			{

				// ставить можно атрибут
				//if (cnum == CMD_REIN_BAROVER)
				//	ret = LOCATE_FILTER_STATUS_Reject;

				if (cnum == CMD_0x050101
					|| cnum == CMD_0x050102
					) // surface projection
				{
					rBarInfo = rb;
					filePosReinFrom = filePos;
				}

				// блокировка выделения неотображающихся
				if (iModelType == 0 && arPlotCfgVar[REIN_PLOT_BAR] != 0)
				{
					if (arPlotCfgVar[REIN_PLOT_BAR] == -1) ret = LOCATE_FILTER_STATUS_Reject;
				}
				else
				{
					if (!rInfo.option[4]) ret = LOCATE_FILTER_STATUS_Reject;
				}


				//printf("%i\n", mdlSelect_numSelected());
			}
			else if (readReinSpaceFromElement(&relem, &edLocP->el, FALSE) == SUCCESS)
			{

				if (cnum == CMD_REIN_BAROVER && rBarOverInfo.dopopt[21] != BAROVER_ACTION_RESET)
					ret = LOCATE_FILTER_STATUS_Reject;

				// блокировка выделения неотображающихся
				if (iModelType == 0 && arPlotCfgVar[REIN_PLOT_SPC] != 0)
				{
					if (arPlotCfgVar[REIN_PLOT_SPC] == -1) ret = LOCATE_FILTER_STATUS_Reject;
				}
				else
				{
					if (!rInfo.option[2]) ret = LOCATE_FILTER_STATUS_Reject;
				}

			}
			else if (readReinAxisFromElement(&ra, &edLocP->el) == SUCCESS)
			{
				ret = LOCATE_FILTER_STATUS_Reject;
			}
			else
			{
				if (cnum == CMD_REIN_BAROVER)
					ret = LOCATE_FILTER_STATUS_Reject;
			}


			mdlElmdscr_freeAll(&edLocP);
		}
		//}
		//__except (filterException(GetExceptionCode(), GetExceptionInformation()))
		//{
		//	//writeToLog(L(" ERROR - cannot display range"), 0, timer);
		//}



	//LOCATE_FILTER_STATUS_Reject       = 0 ,  
	//LOCATE_FILTER_STATUS_Neutral       = 1 ,  
	//LOCATE_FILTER_STATUS_Accept       = 2 ,  

		writeLogOut(__FUNCTION__, 0);

		return ret;

	}


	//DLLEXPORT void call_from();

	//DLLEXPORT void  call_from()
	//{
	//	int a = 0;
	//}

	/////////////////////////
	void  callbackUserInput_receive(
		Inputq_element* queueElementP
	)
	{


		if (queueElementP->hdr.source == 418)
		{
			writeLogIn(__FUNCTION__, 0);

			// queueElementP->u.fill - присланный стринг
			//printf("get message %s\n", queueElementP->u.fill);

			if (SCNP(queueElementP->u.fill, L("dp"), 2) == 0) // specification draw prepare
			{
				//if (daDrawLines) mdlDArray_destroy(daDrawLines);
				//daDrawLines = mdlDArray_create (sizeof (ArrayObjectHdr), sizeof(SpecLine), 0, 0, 0); 
				daDrawLines.clear();

				//if (daDrawTexts) mdlDArray_destroy(daDrawTexts);
				//daDrawTexts = mdlDArray_create (sizeof (ArrayObjectHdr), sizeof(SpecText), 0, 0, 0); 
				daDrawTexts.clear();

			}
			else if (SCNP(queueElementP->u.fill, L("dl"), 2) == 0) // specification draw line
			{
				{
					SpecLine sl;
					SpecLine* slP = &sl;
					WCH seps[] = L(";");
					WCH* token;

					//slP = (SpecLine*)mdlDArray_insertMembers(daDrawLines, 0, 1, -1);

					slP->clear();

					token = STOK(queueElementP->u.fill, seps);

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					slP->arp[0].x = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					slP->arp[0].y = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					slP->arp[1].x = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					slP->arp[1].y = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					slP->smb.color = STOUL(token, 0, 0);

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					slP->smb.weight = STOUL(token, 0, 0);

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					slP->smb.style = STOI(token);

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					slP->lev = STOUL(token, 0, 0);
					mdlLevel_getIdFromCode(&slP->lev, MASTERFILE, slP->lev);

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					slP->ggn = STOUL(token, 0, 0);

					daDrawLines.push_back(sl);

					//mdlSystem_enterDebug();

					if (mdlLine_create(&elSpec, NULL, slP->arp) == SUCCESS)
					{
						mdlElement_setSymbology(&elSpec, &slP->smb.color, &slP->smb.weight, &slP->smb.style);
						mdlElement_setProperties(&elSpec, &slP->lev, &slP->ggn, NULL, NULL, NULL, NULL, NULL, NULL);
						mdlElement_display(&elSpec, DRAW_MODE_Normal);
						mdlElement_add(&elSpec);
					}

				}
			}
			else if (SCNP(queueElementP->u.fill, L("dt"), 2) == 0) // specification draw text
			{
				{
					SpecText st;
					SpecText* stP = &st;
					WCH seps[] = L(";");
					WCH* token;
					int res;
					double width;
					//char* cDot;


					//typedef struct mstextsize
					//{
					//	double	width;
					//	double	height;
					//} MSTextSize;

					//typedef struct textSizeParam
					//{
					//	int		mode;
						//#define	    TXT_NO_TRANSFORM		0x8000
						//#define	    TXT_BY_TILE_SIZE		1
						//#define	    TXT_BY_MULT			2
						//#define	    TXT_BY_TEXT_SIZE		3
						//#define	    TXT_BY_WIDTH_ASPECT		4
					//	MSTextSize	size;
					//	double	aspectRatio;
					//} TextSizeParam;

					//typedef struct textParam
					//{
					//	UInt32	font;
					//	int		just;
						//#define	    TXTJUST_LT			0	/* Left Top */
						//#define	    TXTJUST_LC			1	/* Left Center */
						//#define	    TXTJUST_LB			2	/* Left Bottom */
						//#define	    TXTJUST_LMT			3	/* Left Margin Top */
						//#define	    TXTJUST_LMC			4	/* Left Margin Center */
						//#define	    TXTJUST_LMB			5	/* Left Margin Bottom */
						//#define	    TXTJUST_CT			6	/* Center Top */
						//#define	    TXTJUST_CC			7	/* Center Center */
						//#define	    TXTJUST_CB			8	/* Center Bottom */
						//#define	    TXTJUST_RMT			9	/* Right Margin Top */
						//#define	    TXTJUST_RMC			10	/* Right Margin Center */
						//#define	    TXTJUST_RMB			11	/* Right Margin Bottom */
						//#define	    TXTJUST_RT			12	/* Right Top */
						//#define	    TXTJUST_RC			13	/* Right Center */
						//#define	    TXTJUST_RB			14	/* Right Bottom */
					//	int		style;
					//	int		viewIndependent;
					//} TextParam;

					//printf("%s", queueElementP->u.fill);

					//stP = (SpecText*)mdlDArray_insertMembers(daDrawTexts, 0, 1, -1);

					stP->clear();

					//mdlTextStyle_getTextParamWideFromTCB(&stP->tp, 0, 0, 0, 0);

					//mdlText_setTextParamWideCodePage(&stP->tp, 0x0419);

					stP->tsp.mode = TXT_BY_TILE_SIZE;

#if defined (MSVERSION) && (MSVERSION == 0xa00) // text
					ActiveParams::GetValue(stP->tp.font, ActiveUInt32Params::ACTIVEPARAM_FONT);
#else
					mdlParams_getActive(&stP->tp.font, ACTIVEPARAM_FONT);// = 226;
#endif

					stP->tp.exFlags.acadLineSpacingType = TXTLINESPACING_EXACTFROMLINETOP;

					stP->smb.weight = 1;

					SCPY(s, queueElementP->u.fill);

					token = STOK(s, seps);

					token = STOK(NULL, seps); // TEXT
					if (token == NULL)	return;
					//cDot = strchr(token, '.');
					//if (cDot != NULL) cDot[0] = ',';

					SCPM2W(stP->txt, token, 200);
#if defined (MSVERSION) && (MSVERSION == 0x8b0)
					MSWCharStringToMSWideCharString((MSWideChar*)stP->txt, 200, stP->txt, 0x0419);
#endif


					token = STOK(NULL, seps); // POINT X
					if (token == NULL)	return;
					stP->p.x = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps); // POINT Y
					if (token == NULL)	return;
					stP->p.y = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps); // TEXT HEIGHT
					if (token == NULL)	return;
					stP->tsp.size.height = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps); // TEXT WIDTH
					if (token == NULL)	return;
					stP->tsp.size.width = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps); // LINE SPACING
					if (token == NULL)	return;
					stP->tp.lineSpacing = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps); // JUSTIFICATION
					if (token == NULL)	return;
					stP->tp.just = (TextElementJustification)STOI(token);

					token = STOK(NULL, seps); // UNDERLINE
					if (token == NULL)	return;
					stP->tp.flags.underline = STOI(token);

					token = STOK(NULL, seps); // OVERLINE
					if (token == NULL)	return;
					stP->tp.exFlags.overline = STOUL(token, 0, 0);

					token = STOK(NULL, seps); // UNDERLINE SPACING
					if (token == NULL)	return;
					stP->tp.underlineSpacing = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps); // OVERLINE SPACING
					if (token == NULL)	return;
					stP->tp.overlineSpacing = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps); // LEVEL
					if (token == NULL)	return;
					stP->lev = STOUL(token, 0, 0);
					mdlLevel_getIdFromCode(&stP->lev, MASTERFILE, stP->lev);

					token = STOK(NULL, seps); // COLOR
					if (token == NULL)	return;
					stP->smb.color = STOUL(token, 0, 0);

					token = STOK(NULL, seps); // MAX WIDTH
					if (token == NULL)	return;
					stP->maxwidth = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps); // GG NUMBER
					if (token == NULL)	return;
					stP->ggn = STOUL(token, 0, 0);

#if defined (MSVERSION) && (MSVERSION == 0xa00)
					res = mdlText_create(&elSpec, NULL, stP->txt, &stP->p, NULL, &stP->tsp, &stP->tp, NULL, ACTIVEMODEL);
#else
					res = mdlText_createWide(&elSpec, NULL, (MSWideChar*)stP->txt, &stP->p, NULL, &stP->tsp, &stP->tp, NULL);
#endif
					//printf("   ===>   %f %f \n", stP->p.x, stP->p.y);


					if (res == SUCCESS)
					{
						DVec3d ap[5];

						mdlElement_setSymbology(&elSpec, &stP->smb.color, &stP->smb.weight, &stP->smb.style);

						mdlText_extractShape(ap, NULL, &elSpec, FALSE, 0);

						width = ap[1].x - ap[0].x;

						//printf("%f  %f\n", width, stP->maxwidth);

						if (width > stP->maxwidth)
						{
							stP->tsp.mode = TXT_BY_TEXT_SIZE;
							stP->tsp.size.width = stP->maxwidth;
#if defined (MSVERSION) && (MSVERSION == 0xa00)
							mdlText_create(&elSpec, &elSpec, stP->txt, &stP->p, NULL, &stP->tsp, NULL, NULL, ACTIVEMODEL);
#else
							mdlText_createWide(&elSpec, &elSpec, (MSWideChar*)stP->txt, &stP->p, NULL, &stP->tsp, NULL, NULL);
#endif
						}

						mdlElement_setProperties(&elSpec, &stP->lev, &stP->ggn, NULL, NULL, NULL, NULL, NULL, NULL);
						mdlElement_display(&elSpec, DRAW_MODE_Normal);
						mdlElement_add(&elSpec);

						//printf("%f  %f  %f  %f  %f\n", ap[0].x, ap[1].x, ap[2].x, ap[3].x, ap[4].x);

						dTextRightX = mdlCnv_uorsToMasterUnits(stP->p.x + width);

						daDrawTexts.push_back(st);
					}

				}
			}
			else if (SCNP(queueElementP->u.fill, L("ds"), 2) == 0) // specification draw lines array (not using)
			{
				{
					int i;
					//SpecLine* slP;

					for (vector<SpecLine>::iterator slP = daDrawLines.begin(); slP != daDrawLines.end(); ++slP)
						//for (i = 0; i < daDrawLines.size(); i++)
					{
						//slP = &daDrawLines[i];

						// draw line...

						if (mdlLine_create(&elSpec, NULL, slP->arp) == SUCCESS)
						{
							mdlElement_setSymbology(&elSpec, &slP->smb.color, &slP->smb.weight, &slP->smb.style);
							mdlElement_setProperties(&elSpec, &slP->lev, &slP->ggn, NULL, NULL, NULL, NULL, NULL, NULL);
							mdlElement_display(&elSpec, DRAW_MODE_Normal);
							mdlElement_add(&elSpec);
						}
					}
				}
			}
			else if (SCNP(queueElementP->u.fill, L("conf"), 4) == 0)
			{
				WCH seps[] = L(";");
				WCH* token;
				int i;
				int p_org_cnt;
				int p_end_cnt;
				BarPoint p_org[MAX_BAR_VERTICES];
				BarPoint p_end[MAX_BAR_VERTICES];

				//printf("%s\n", queueElementP->u.fill);

				//mdlSystem_enterDebug();

				for (i = 0; i < MAX_BAR_VERTICES; i++) p_org[i].clear();
				for (i = 0; i < MAX_BAR_VERTICES; i++) p_end[i].clear();

				//==========================

				SCPY(s, queueElementP->u.fill);

				token = STOK(s, seps);
				if (token == NULL)	return;

				token = STOK(NULL, seps);
				if (token == NULL)	return;
				p_org_cnt = STOI(token);

				token = STOK(NULL, seps);
				if (token == NULL)	return;
				p_end_cnt = STOI(token);

				for (i = 0; i < p_org_cnt; i++)
				{
					token = STOK(NULL, seps);
					if (token == NULL)	return;
					p_org[i].pVrtx.x = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					p_org[i].pVrtx.y = mdlCnv_masterUnitsToUors(STOF(token));
				}

				for (i = 0; i < p_end_cnt; i++)
				{
					token = STOK(NULL, seps);
					if (token == NULL)	return;
					p_end[i].pVrtx.x = mdlCnv_masterUnitsToUors(STOF(token));

					token = STOK(NULL, seps);
					if (token == NULL)	return;
					p_end[i].pVrtx.y = mdlCnv_masterUnitsToUors(STOF(token));
				}

				//mdlSystem_enterDebug();

				rInfo.rsVal.pts_org_cnt = p_org_cnt;
				rInfo.rsVal.pts_end_cnt = p_end_cnt;

				for (i = 0; i < p_org_cnt; i++) rInfo.rsVal.pts_org[i] = p_org[i];

				for (i = 0; i < p_org_cnt; i++) rInfo.rsVal.pts_end[i] = p_end[i];

			}
			else if (SCNP(queueElementP->u.fill, L("curcat"), 6) == 0) // set catalog from offtake
			{

				WCH seps[] = L("|");
				WCH* token;

				curCat.clear();

				//mdlDialog_openMessageBox(DIALOGID_MsgBoxOK, queueElementP->u.fill, DIALOGID_LargeInfoBox);

				SCPY(s, queueElementP->u.fill);

				token = STOK(s, seps);
				if (token == NULL)	return;

				token = STOK(NULL, seps);
				if (token == NULL)	return;
				SCPY(curCat.dbase, token);

				token = STOK(NULL, seps);
				if (token == NULL)	return;
				curCat.projID = STOL(token);

				token = STOK(NULL, seps);
				if (token == NULL)	return;
				curCat.catID = STOL(token);

				token = STOK(NULL, seps);
				if (token == NULL)	return;
				SCPY(curCat.catname, token);

				token = STOK(NULL, seps);
				if (token == NULL)	return;
				SCPY(curCat.catfullname, token);

				token = STOK(NULL, seps);
				if (token == NULL)	return;

				curCat.bAutoCats = (STOI(token) != 0);

				//for (int i = 0; curCat.catID > 0 && daCurPosBase && i < mdlDArray_nMembers(daCurPosBase); i++)
				//{
				//	ReinPos* rpP = (ReinPos*)mdlDArray_getMemberP(daCurPosBase, i);
				//	if (rpP->pcatID > 0 && rpP->pcatID != curCat.catID)
				//	{
				//		//mdlDialog_openMessageBox...
				//		//rpP->pcatID = curCat.catID;
				//		//savePosition(rpP, FALSE);
				//	}
				//}

				SCPY(s, curCat.catfullname);

				// MessageBox
				if (mdlDialog_openMessageBox(DIALOGID_MsgBoxOKCancel,
					s, MSGBOX_ICON_QUESTION) != ACTIONBUTTON_CANCEL)
				{
					saveCatInfo();

					getCatInfo(&curCat, ACTIVEMODEL, false); // true
				}


			}

			writeLogOut(__FUNCTION__, 0);
		}



	}



	///////////////////////////////////////
	void  callbackLevelMaskChange(
		DgnModelRefP  modelRefIn,
		int  viewNumber
	)
	{


		writeLogIn(__FUNCTION__, 0);



		writeLogOut(__FUNCTION__, 0);

	}

	////////////////////////////////////////
	int callbackCommandFilter(
		Inputq_element* queueElementP
	)
	{

		writeLogIn(__FUNCTION__, 0);

		iDataCopyCount = 0;
		dataCopyNewElemID = 0;


		if (
			mdlSelect_isActive() &&
			SCMP(queueElementP->u.cmd.taskId, L("TRANSFRM")) == 0 &&
			(queueElementP->u.cmd.command == 0x0e030000 // copy
				|| queueElementP->u.cmd.command == 0x0d040000 // rotate
				|| queueElementP->u.cmd.command == 0x0f030000 // mirror
				)
			)
		{

			//UInt32* fps = NULL;
			//DgnModelRefP* mrs = NULL;
			//int sel = 0;


			//mdlSelect_returnPositions(&fps, &mrs, &sel);

			//for (int i = 0; i < sel; i++) 
			//{

			//	mdlElmdscr_read (&edP, fps[i], mrs[i], FALSE, NULL);
			//}

			//dlmSystem_mdlFree(fps);
			//dlmSystem_mdlFree(mrs);
			//free(fps);
			//free(mrs);





			int index;
			ELREF elemRef = NULL;
			DgnModelRefP modelRef = NULL;



			for (index = 0; index < mdlSelect_numSelected() && iDataCopyCount < 1; index++)
			{
				int status;

				status = mdlSelect_getElement(index, &elemRef, &modelRef);

				if (0 == status)
				{
					MSElementDescr* edP = NULL;

					mdlElmdscr_read(&edP, elementRef_getFilePos(elemRef), modelRef, FALSE, 0);

					if (edP)
					{
						//ReinBar rb; //этот кусок кода приводит к вылету при команде mdl load cellsel на кнопке
						//if (readReinBarFromElement(&rb, edP, TRUE, FALSE) == SUCCESS)
						{
							//arDataCopy[iDataCopyCount] = rb;
							iDataCopyCount++;
						}

						mdlElmdscr_freeAll(&edP);
					}
				}
			}

			//sprintf(sLogMes, "REIN - callbackCommandFilter() - iDataCopyCount = %i", iDataCopyCount);
			//mdlOutput_messageCenter(OutputMessagePriority::Warning, sLogMes, sLogMes, FALSE);

		}



		writeLogOut(__FUNCTION__, 0);

		return INPUT_COMMAND_ACCEPT;
	}




	///////////////////////////////////
	ElmDscrToFile_Status  callbackElmDscrToFile
	(
		ElmDscrToFile_Actions       action,
		DgnModelRefP       modelRef,
		UInt32       filePos,
		MSElementDescr* newEdP,
		MSElementDescr* oldEdP,
		MSElementDescr** replacementEdPP
	)
	{

		//typedef enum
		//    {
		//    ELMDTF_ACTION_APPEND    = 1,
		//    ELMDTF_ACTION_DELETE    = 2,
		//    ELMDTF_ACTION_REPLACE   = 3
		//    } ElmDscrToFile_Actions;



		ElmDscrToFile_Status ret = ELMDTF_STATUS_SUCCESS;

		//ReinSpace rs;
		ReinElement relem;
		ReinBar rb;
		ReinElm re;
		int res = SUCCESS;
		//int resExt = SUCCESS;
		//int resRev = SUCCESS;
		Transform tmMove;

		bool bRecreateBar = false;

		writeLogIn(__FUNCTION__, 0); 
		if (iDebug) sprintf(sLogMes, "bCopyFromRef = %i\n", bCopyFromRef); writeLog(0, 0);

		//if (oldEdP && newEdP == NULL)
		//{
		//	printf("");
		//}


		//if (newEdP == NULL && oldEdP && readReinElmIso(&re, oldEdP, FALSE, FALSE, modelRef) == SUCCESS )
		//	__asm nop;


		CommandNumber cnum;

		if (mdlInput_commandState1(NULL, &cnum, NULL, NULL) == PRIMITIVE_COMMAND)
		{
			if (cnum == CMD_REFERENCE_PRESENTATION) // REFERENCE MERGING
			{

				//if (newEdP && readReinSpaceFromElmd(&rs, newEdP, FALSE) == SUCCESS)
				//	return ELMDTF_STATUS_SUCCESS;
				//else if (newEdP && readReinBarFromElement(&rb, newEdP, TRUE) == SUCCESS)
				//	return ELMDTF_STATUS_SUCCESS;
				//if (newEdP && readReinElmIso(&re, newEdP, FALSE, FALSE) == SUCCESS)
				//	return ELMDTF_STATUS_ABORT;
				//else

				writeLogOut(__FUNCTION__, "cnum == CMD_REFERENCE_PRESENTATION");

				return ELMDTF_STATUS_SUCCESS;
			}
		}


		if (newEdP)
		{

			int tp = mdlElement_getType(&newEdP->el);
			//MSElementDescr* edpBar = NULL;
			//DVec3d pDir;
			//double dist;
			//double d = 0.;
			//DVec3d pCent;
			//DVec3d pAxis;
			//double swan = 0.;

			if (iDebug) sprintf(sLogMes, "newEdP != NULL, type = %i\n", tp); writeLog(0, 0);

			// если создается поверхность вытягиванием ReinBar
			if (tp == SURFACE_ELM && readReinSpaceFromElmd(&relem, newEdP, FALSE) != SUCCESS)
			{
				//resExt = mdlSurface_extractExtrusionExt(&edpBar, &pDir, &dist, newEdP, TRUE);
				//resRev = mdlSurface_extractRevolution2(&edpBar, &pCent, &pAxis, &swan, newEdP);

				//int resBar = readReinBarFromElement(&rb, edpBar, TRUE);

				//if ((resExt == SUCCESS || resRev == SUCCESS) && resBar == SUCCESS) 

				if (iDebug) sprintf(sLogMes, "create surface from reinspace...\n"); writeLog(0, 0);

				if (filePosReinFrom > 0)
				{
					copySpaceData(&relem.rs, &rBarInfo, FALSE, NULL, TRUE);

					createReinSpaceElement(&newEdP, &relem.rs, filePos, modelRef, FALSE, TRUE);

					//mdlElmdscr_freeAll(&edpBar);

					writeLogOut(__FUNCTION__, "if (filePosReinFrom > 0)");
					return ELMDTF_STATUS_ABORT;
				}
				else // if (resExt != SUCCESS && resRev != SUCCESS)
				{
					writeLogOut(__FUNCTION__, "if (resExt != SUCCESS && resRev != SUCCESS)");
					return ELMDTF_STATUS_SUCCESS;
				}
			}
		}





		// установки для исходного ReinSpace 
		if (newEdP && readReinSpaceFromElmd(&relem, newEdP, FALSE) == SUCCESS)
		{
			bool bChange = false;

			if (iDebug) sprintf(sLogMes, "the elem is reinspace\n"); writeLog(0, 0);

			//todo update symb onchange - reinspace 

			if (iCfgVar_Class_Spc >= 0)
			{
				ELCLASS iCurClass;
				mdlElmdscr_getProperties(0, 0, &iCurClass, 0, 0, 0, 0, 0, newEdP);
				if ((int)iCurClass != iCfgVar_Class_Spc)
				{
					if (iDebug) sprintf(sLogMes, "set class to %i\n", iCfgVar_Class_Spc); writeLog(0, 0);
					iCurClass = (ELCLASS)iCfgVar_Class_Spc;
					func_amp(mdlElmdscr_setProperties, newEdP), 0, 0, & iCurClass, 0, 0, 0, 0, 0);
					bChange = true;
				}
			}

			if (iCfgVar_SymbStyle_Spc >= 0) // -1 не менять
			{
				//UInt32 wt = 0;
				Int32 st = iCfgVar_SymbStyle_Spc;
				func_amp(mdlElmdscr_setSymbology, newEdP), 0, & st, 0, 0);
				bChange = true;
			}

			//double trn = mdlElement_getTransparency(&newEdP->el);
			//if (!EQ(trn, 0.))
			//{
			//	mdlElmdscr_setTransparency(&newEdP, 0.);
			//	bChange = true;
			//}

			if (bChange)
			{
				mdlElmdscr_duplicate(replacementEdPP, newEdP);
				if (iDebug) sprintf(sLogMes, "set return val to ELMDTF_STATUS_REPLACE\n"); writeLog(0, 0);
				ret = ELMDTF_STATUS_REPLACE;
			}
		}


		// установки для исходного ReinBar 
		if (newEdP && readReinBarFromElement(&rb, newEdP, TRUE) == SUCCESS)
		{
			bRecreateBar = true;

			if (iDebug) sprintf(sLogMes, "the elem is reinbar, rb.bartype = %i, rb.elemid = %I64u\n", rb.bartype, rb.elemid); writeLog(0, 0);

			//sprintf(sLogMes, "REIN - callbackElmDscrToFile() - iDataCopyCount = %i", iDataCopyCount);
			//mdlOutput_messageCenter(OutputMessagePriority::Warning, sLogMes, sLogMes, FALSE);
	/*
			if (iDataCopyCount > 0 && rb.elemid != dataCopyNewElemID)
			{
				MSElementDescr* edpBar = NULL;

				if (dataCopyNewElemID == 0)
				{
					dataCopyNewElemID = rb.saveReinData(dataCopyNewElemID);
				}

				rb.elemid = dataCopyNewElemID;
				mdlElmdscr_duplicate(&edpBar, newEdP);
				mdlXMLFragmentList_stripAllFromElement (NULL, &edpBar->el);
				rb.createReinBarElement(&edpBar, 0, 0, TRUE);

				ret = ELMDTF_STATUS_ABORT;
			}
			else if (iCfgVar_Class_Bar >= 0)
			{
				mdlElmdscr_setProperties(newEdP, 0, 0, &iCfgVar_Class_Bar, 0, 0, 0, 0, 0);
				mdlElmdscr_duplicate (replacementEdPP, newEdP);
				if (iDebug) sprintf(sLogMes, "set CLASS=%i to ReinBar element\n", iCfgVar_Class_Bar); writeLog(0, 0);
				ret = ELMDTF_STATUS_REPLACE;
			}*/

			if (rb.bartype != BT_AXIS && rb.elemid > 0)
			{
				UInt32 ggn = 0;
				//MSElementDescr* edpBar = NULL;

				//ElementRef eref = getElemRefByID (modelRef, rb.elemid);
				//if (eref)
				//	ggn = elementRef_getFilePos(eref);
				//else 
				//	ggn = 0;

				if (iDebug) sprintf(sLogMes, "start data copy heromantic...\n"); writeLog(0, 0);
				//sprintf(sLogMes, "tcb->fbfdcn.gglk = %u\n", tcb->fbfdcn.gglk); writeLog(0, 0);
				if (iDebug) sprintf(sLogMes, "ggn ~ fpos = %u\n", ggn); writeLog(0, 0);
				if (iDebug) sprintf(sLogMes, "iDataCopyCount = %i\n", iDataCopyCount); writeLog(0, 0);
				if (iDebug) sprintf(sLogMes, "dataCopyNewElemID = %I64u\n", dataCopyNewElemID); writeLog(0, 0);

				if (tcb->fbfdcn.gglk || iDataCopyCount > 0)
				{
					ReinData rd;
					MSElementDescr* edp = NULL;
					mdlElmdscr_getProperties(0, &ggn, 0, 0, 0, 0, 0, 0, newEdP);
					mdlElmdscr_read(&edp, ggn, modelRef, 0, 0);
					if (edp && readReinDataFromElmd(&rd, edp, &rb) == SUCCESS)
					{
						//mdlElmdscr_setProperties(newEdP, 0, &ggn, 0, 0, 0, 0, 0, 0);
						//mdlElmdscr_duplicate (replacementEdPP, newEdP);

						//if (rb.barflags & REINBAR_FLAG_CONT) 
						//{
							//if (addConttNum(&rb) == SUCCESS)
						//	mdlXMLFragmentList_stripAllFromElement (NULL, &(*replacementEdPP)->el);
						//	XMLFragmentListP    pCurrentOrg = rb.createReinBarElement();
						//	mdlXMLFragmentList_attachToElement(&pCurrentOrg, replacementEdPP, TRUE);
						//}

						//ret = ELMDTF_STATUS_REPLACE;
					}
					else
					{
						if (dataCopyNewElemID == 0)
							dataCopyNewElemID = rb.saveReinData(0);

						if (iDebug) sprintf(sLogMes, "after saveReinData() dataCopyNewElemID = %I64u\n", dataCopyNewElemID); writeLog(0, 0);

						rb.elemid = dataCopyNewElemID;
						mdlElmdscr_duplicate(replacementEdPP, newEdP);
						mdlXMLFragmentList_stripAllFromElement(NULL, &(*replacementEdPP)->el);

						ELREF eref = getElemRefByID(modelRef, rb.elemid);

						if (eref)
						{
							ggn = elementRef_getFilePos(eref);
							func_ast(mdlElmdscr_setProperties, replacementEdPP), 0, & ggn, 0, 0, 0, 0, 0, 0);
						}

						if (rb.barflags & REINBAR_FLAG_CONT)
						{
							if (iDebug) sprintf(sLogMes, "add cont num...\n"); writeLog(0, 0);
							addConttNum(&rb);
						}

						XMLFragmentListP    pCurrentOrg = rb.createReinBarXml();
						mdlXMLFragmentList_attachToElement(&pCurrentOrg, replacementEdPP, TRUE);

						ret = ELMDTF_STATUS_REPLACE;
					}
				}
				else
				{
					ELREF eref = getElemRefByID(modelRef, rb.elemid);
					if (eref)
					{
						ggn = elementRef_getFilePos(eref);
						func_amp(mdlElmdscr_setProperties, newEdP), 0, & ggn, 0, 0, 0, 0, 0, 0);
						mdlElmdscr_duplicate(replacementEdPP, newEdP);

						if (rb.barflags & REINBAR_FLAG_CONT)
						{
							if (addConttNum(&rb) == SUCCESS)
							{
								mdlXMLFragmentList_stripAllFromElement(NULL, &(*replacementEdPP)->el);
								XMLFragmentListP    pCurrentOrg = rb.createReinBarXml();
								mdlXMLFragmentList_attachToElement(&pCurrentOrg, replacementEdPP, TRUE);
							}
						}

						ret = ELMDTF_STATUS_REPLACE;
					}
				}

				if (iDebug) sprintf(sLogMes, "end data copy heromantic..., ret = %i\n", ret); writeLog(0, 0);

			}
		}


		if (newEdP)
		{
			if (edCopyP && bCopyFromRef)
			{
				res = readReinElmIso(&re, newEdP, TRUE, FALSE, edCopyP->h.dgnModelRef); // принадлежит активной модели
			}
			else
			{
				res = readReinElmIso(&re, newEdP, TRUE, FALSE); // принадлежит активной модели
			}
			if (res == SUCCESS) bRecreateBar = true;
		}
		else
			re.clear();


		if (bRecreateBar) 
		{ 
			if (iDebug) sprintf(sLogMes, "bRecreateBar = true\n"); writeLog(0, 0); 
		}


		// если идет копирование элемента
		if (newEdP
			// && res == SUCCESS - из референса будет ошибка, так как в новом файле нет оси, (ReinElm)re для копирования не исп.
			&& ret == ELMDTF_STATUS_SUCCESS // если еще не обработан
			&& action == ELMDTF_ACTION_APPEND
			&& bRecreateBar
			&& edCopyP)
		{
			int bTransform = FALSE;
			UInt32 fposCopy;

			if (iDebug) sprintf(sLogMes, "element copying...\n"); writeLog(0, 0);

			Transform tmRef;

			//DgnModelRefP mrP = edCopyP->h.dgnModelRef;
			fposCopy = reCopyFrom.bel.ffpos[reCopyFrom.type];

			if (iDebug) sprintf(sLogMes, "fposCopy = %u\n", fposCopy); writeLog(0, 0);

			mdlElmdscr_orientationExt(&tmCopyDst, newEdP, modelRef);

			mdlTMatrix_getInverse(&tmMove, &tmCopySrc);

			mdlTMatrix_multiply(&tmMove, &tmCopyDst, &tmMove);

			//printf("a = %i  fp = %i  new = %i  old = %i  repl = %i  \n", action, filePos, newEdP, oldEdP, replacementEdPP);


			MSElementDescr* edpBar = NULL; // стержень который будем создавать

			{
				ReinData rd;

				//if (readReinBarFromElement(&rb, edCopyP, TRUE) == SUCCESS) // не сработает никогда
				//{
				//	mdlElmdscr_duplicate(&edpBar, edCopyP);
				//	if (bCopyFromRef) mdlElmdscr_transform(edpBar, &tmRef);
				//	mdlElmdscr_transform(edpBar, &tmMove);
				//}
				//else 
				if (readReinSpaceFromElmd(&relem, edCopyP, TRUE) == SUCCESS)
				{
					if (iDebug) sprintf(sLogMes, "from reinspace\n"); writeLog(0, 0);

					{
						//mdlLineString_create(&elTmp, &edCopyP->el, reCopyFrom.bel.rpts, reCopyFrom.bel.numpts); // acht
						//elTmp.hdr.dhdr.props.b.s = 0; // make snappable
						//mdlElmdscr_new(&edpBar, 0, &elTmp);
						bTransform = TRUE;

						mdlComplexChain_createHeader(&eCell, 0, 0);
						eCell.hdr.dhdr.props.b.s = 0; // make snappable
						mdlElmdscr_new(&edpBar, 0, &eCell);

						if (iDebug) sprintf(sLogMes, "create axis... reCopyFrom.bel.numpts = %i\n", reCopyFrom.bel.numpts); writeLog(0, 0);

						reinCreateComplexBarAxis2(&edpBar, 0, reCopyFrom.bel.rpts, reCopyFrom.bel.rfa, reCopyFrom.bel.numpts, 0, &edCopyP->el, 0, FALSE);

					}


					if (iDebug) sprintf(sLogMes, "copy space data...\n"); writeLog(0, 0);
					if (mdlElement_getType(&edCopyP->el) == SURFACE_ELM)
						copySpaceData(&relem.rs, &rb, TRUE, NULL, TRUE);
					else
						copySpaceData(&relem.rs, &rb, TRUE, NULL, FALSE);

				}
				else if (readReinDataFromElmd(&rd, edCopyP, &reCopyFrom.bel) == SUCCESS)
				{
					bTransform = TRUE;

					if (iDebug) sprintf(sLogMes, "from reindata\n"); writeLog(0, 0);

					mdlComplexChain_createHeader(&eCell, 0, 0);
					eCell.hdr.dhdr.props.b.s = 0; // make snappable
					mdlElmdscr_new(&edpBar, 0, &eCell);

					MSElementDescr* edpTmpl = NULL;

					if (mdlElmdscr_read(&edpTmpl, reCopyFrom.bel.ffpos[REIN_ELEM_ISO], edCopyP->h.dgnModelRef, FALSE, NULL) != 0)
					{
						reCopyFrom.bel.bartype = BT_AXIS; // копируем ось

						if (iDebug) sprintf(sLogMes, "create axis... reCopyFrom.bel.numpts = %i\n", reCopyFrom.bel.numpts); writeLog(0, 0);

						reinCreateComplexBarAxis2(&edpBar, 0, reCopyFrom.bel.rpts, reCopyFrom.bel.rfa, reCopyFrom.bel.numpts, 0, &edpTmpl->el, 0, FALSE);

						rb = reCopyFrom.bel;
					}
				}


				if (edpBar)
				{

					if (iDebug) sprintf(sLogMes, "simplify bar...\n"); writeLog(0, 0);

					if (reCopyFrom.bel.numpts == 2) // simplify не фурычит
					{
						DVec3d* rpts = &reCopyFrom.bel.rpts[0];
						mdlLine_create(&elTmp, &edpBar->el, rpts);
						mdlElmdscr_freeAll(&edpBar);
						mdlElmdscr_new(&edpBar, 0, &elTmp);
					}
					else
						mdlElmdscr_simplifyComplexChainOrShape(&edpBar, ACTIVEMODEL);


					if (bCopyFromRef) // reference clip
					{
						if (iDebug) sprintf(sLogMes, "try to clip reference element...\n"); writeLog(0, 0);

						CLIPDESC clipP;
						MSElementDescr* edpClip = NULL;
						MSElementDescr* edpClip1 = NULL;
						//res = func_pma(mdlClip_getRefBoundary,clipP), edCopyP->h.dgnModelRef, 0);
						res = myClip_getRefBoundary(&clipP, edCopyP->h.dgnModelRef, &edpClip, 0);


						if (res == SUCCESS && NOTNULL(clipP))
						{
							res = mdlClip_element(&edpClip1, NULL, edpBar, ACTIVEMODEL, GETPTR(clipP), 0);
							if (res == SUCCESS && edpClip1 != NULL)
							{
								if (iDebug) sprintf(sLogMes, "clip processed\n"); writeLog(0, 0);

								if (edpClip1 != edpBar) // edpClip1 dublicated from newEdP and clipped
								{
									edpBar = edpClip1;
								}
							}
							myClip_free(clipP, &edpClip); // for v8i

							if (iDebug) sprintf(sLogMes, "clip processed\n"); writeLog(0, 0);

						}
						else
						{
							if (iDebug) sprintf(sLogMes, "no clip\n"); writeLog(0, 0);
						}

						//mdlTMatrix_masterToReference(&tmFromRef, edCopyP->h.dgnModelRef);
						//if (bTransform) mdlElmdscr_transform(edpBar, &tmFromRef);
					}


					if (bTransform) func_amp(mdlElmdscr_transform, edpBar), & tmMove);

					//rb.lap[0] = 0; // обнуление разбежки (убрано для того чтобы работало разбитие по позициям в контуре и для отдельных стержней)
					//rb.lap[1] = 0;
					//rb.lap[2] = 0;

					if (edCopyP) mdlElmdscr_freeAll(&edCopyP);

					if (iDebug) sprintf(sLogMes, "create rein bar...\n"); writeLog(0, 0);
					rb.createReinBarElement(&edpBar, 0, 0, TRUE); // COPY

					//ret = ELMDTF_STATUS_REPLACE; // почему-то не сохраняет XML атрибут (кстати может быть из-за исп. elem template )
					ret = ELMDTF_STATUS_ABORT;
				}
			}
		}
		else if (newEdP && res == SUCCESS) // установка свойств для производного элемента
		{
			//UInt32 wgt = WEIGHT_BYLEVEL;
			UInt32 clr = COLOR_BYLEVEL;
			UInt32* clrP = NULL;
			UInt32 wgt = iCfgVar_SymbWeight_Elm;
			UInt32* wgtP = NULL;
			UInt32 ggn = 0;
			int* classP = NULL;

			if (iCfgVar_SymbWeight_Elm != -1) // no change
				wgtP = &wgt;

			if (iCfgVar_SymbColor_Elm != -1) // no change
				clrP = &clr;

			if (iCfgVar_SymbColor_Elm >= 0) // set color index
				clr = iCfgVar_SymbColor_Elm;

			if (iCfgVar_Class_Elm >= 0) classP = &iCfgVar_Class_Elm;

			//if (re.bel.grnd) wgt = 4; // если надо, потом сделаем

			func_amp(mdlElmdscr_setSymbology, newEdP), clrP, 0, wgtP, 0);
			func_amp(mdlElmdscr_setProperties, newEdP), 0, & ggn, (ELCLASS*)classP, 0, 0, 0, 0, 0);

			mdlElmdscr_duplicate(replacementEdPP, newEdP);

			if (iDebug) sprintf(sLogMes, "set wieght = %u to ReinElm element\n", wgt); writeLog(0, 0);

			ret = ELMDTF_STATUS_REPLACE;
		}



		if (edCopyP) mdlElmdscr_freeAll(&edCopyP);



		if (newEdP && oldEdP
			&& action == ELMDTF_ACTION_REPLACE
			&& cnum == CMD_0x0C0300 // move, остальные команды тоже надо...
			)
		{
			writeLog("process", 0, "MOVE command");

			res = readReinElmIso(&re, oldEdP, TRUE, FALSE);

			if (res == SUCCESS)
			{
				mdlElmdscr_orientationExt(&tmCopySrc, oldEdP, modelRef);
				mdlElmdscr_orientationExt(&tmCopyDst, newEdP, modelRef);

				mdlTMatrix_getInverse(&tmMove, &tmCopySrc);
				mdlTMatrix_multiply(&tmMove, &tmCopyDst, &tmMove);

				MSElementDescr* edSpaceP = NULL;


				ELREF eref = getElemRefByID(modelRef, re.bel.elemid);

				UInt32 fp = elementRef_getFilePos(eref);

				mdlElmdscr_readToMaster(&edSpaceP, fp, modelRef, 0, 0);

				//ReinElement relem;
				Transform tmMoveFirst;

				if (edSpaceP && readReinSpaceFromElmd(&relem, edSpaceP, FALSE) == SUCCESS)
				{
					BarOver* boP = NULL;

					//bo.isdel = 1;
					//bo.inum = relm.bel.inum;

					//re.mapOvers[bo.inum] = bo;

					MAP<int, BarOver>::iterator it = relem.mapOvers.find(re.bel.inum);
					if (it != relem.mapOvers.end()) // found
					{
						tmMoveFirst = it->second.tmov;
						mdlTMatrix_multiply(&tmMove, &tmMoveFirst, &tmMove);
					}
					else
					{ // insert if not exist
						BarOver bo;
						bo.inum = re.bel.inum;
						relem.mapOvers[re.bel.inum] = bo;
					}

					boP = &(relem.mapOvers[re.bel.inum]);
					boP->tmov = tmMove;
					if (mdlTMatrix_isIdentity(&tmMove)) boP->btmov = FALSE; else boP->btmov = TRUE;

					createReinSpaceElement(&edSpaceP, &relem.rs, fp, modelRef, FALSE, TRUE, &relem);
				}

				if (edSpaceP) mdlElmdscr_freeAll(&edSpaceP);


				writeLogOut(__FUNCTION__, "move comtur element");
				return ELMDTF_STATUS_ABORT;
			}

		}

		if (iDebug)
		{
			if (ret == ELMDTF_STATUS_SUCCESS) { sprintf(sLogMes, "returning ELMDTF_STATUS_SUCCESS\n"); writeLog(0, 0); }
			if (ret == ELMDTF_STATUS_ABORT) { sprintf(sLogMes, "returning ELMDTF_STATUS_ABORT\n"); writeLog(0, 0); }
			if (ret == ELMDTF_STATUS_REPLACE) { sprintf(sLogMes, "returning ELMDTF_STATUS_REPLACE\n"); writeLog(0, 0); }
		}
		writeLogOut(__FUNCTION__, 0);



		//ELMDTF_STATUS_SUCCESS Proceed with operation unchanged. 
		//ELMDTF_STATUS_ABORT Do not allow operation. Command that initiated the write receives a "write failed" status. 
		//ELMDTF_STATUS_REPLACE Continue with the operation using the element descriptor pointed to by replacementEdPP. Not valid if action is ELMDTF_ACTION_DELETE. 
		return ret;
	}



	/////////////////////////////////
	void  callbackOpeningDgnFile(
#if defined (MSVERSION) && (MSVERSION == 0xa00)
		WCharCP fileP,
		NewDesignFileReason state
#else
		char* filenameP,         /* => name of file */
		int      state      /* => SYSTEM_NEWFILE_CLOSE, SYSTEM_NEWFILE_COMPLETE */
#endif
	)
	{

		writeLogIn(__FUNCTION__, 0);

		if (state == SYSTEM_NEWFILE_CLOSE)
		{

			if (iDebug) sprintf(sLogMes, "SYSTEM_NEWFILE_CLOSE\n"); writeLog(0, 0);

			// сохраняем настройки отображения референса???
			//if (rDopInfo.dopopt[14] >= 0) saveShowInfo2(rDopInfo.dopopt[14], 0, &rInfo);

			//printf("unloading file...\n");
			//clearBarsData(FALSE);

			//if (arTransNodes) {mdlTransient_free(&arTransNodes, 0); arTransNodes = NULL;}

			if (tedBarsP)
			{
				if (mdlTransient_isValid(tedBarsP))	mdlTransient_free(&tedBarsP, 0);
				tedBarsP = NULL;
			}

		}
		if (state == SYSTEM_NEWFILE_COMPLETE)
		{
			if (iDebug) sprintf(sLogMes, "SYSTEM_NEWFILE_COMPLETE\n"); writeLog(0, 0);

			// ВСЕ ПЕРЕНЕСЕНО в событие callbackModelChanged
			//==================================================

			//setDefaultStyles();

			//checkThisFileIsModel(ACTIVEMODEL);

			//reloadCurBarsAll();

			//mdlVBA_runMacro("arm", "main", "mdlGetCatID");

			//loadDBLaps();
			//loadDBPositions();

			//cmdDrawNodes(NULL);

		}




		if (state == SYSTEM_NEWFILE_CLOSE)
		{
			MSDLGP dbP = NULL;

#if defined (STD_INTERFACE)
			if (NULL != (dbP = mdlDialog_find(DIALOG_TOOLBOX, NULL)))
				rInfo.option[7] = TRUE;
			else
				rInfo.option[7] = FALSE;
#endif

			if (NULL != (dbP = mdlDialog_find(DLG_SKETCH, NULL)))
				rInfo.ttip = TRUE;
			else
				rInfo.ttip = FALSE;
		}
		if (state == SYSTEM_NEWFILE_COMPLETE)
		{

#if defined (STD_INTERFACE)

			if (rInfo.option[7]
				&& rfHandle
				) mdlDialog_open(rfHandle, DIALOG_TOOLBOX);
			if (rInfo.ttip
				&& rfHandle
				) mdlDialog_open(rfHandle, DLG_SKETCH);
#endif

			try
			{
				DItem_PulldownMenu* mnu = NULL;

				mnu = mdlDialog_menuBarFindMenu(mdlDialog_menuBarGetCmdWinP(),
					RTYPE_PulldownMenu, 8888);

				if (mnu == NULL)
				{
					mnu = mdlDialog_menuBarFindMenu(mdlDialog_menuBarGetCmdWinP(),
						RTYPE_PulldownMenu, PULLDOWNMENUID_Workspace);

					if (mnu)
					{
						mdlDialog_menuBarInsertMenu(mdlDialog_menuBarGetCmdWinP(),
							RTYPE_PulldownMenu, 8888,
							mnu);
					}
				}
			}
			catch (int e)
			{
				//SPRN(s, L("Error loading menu, err. number %i \n"), e);
				//mdlDialog_dmsgsPrint(s);
			}

		}


		writeLogOut(__FUNCTION__, 0);


	}


	///////////////////////////////
	void  callbackModelChanged(
		DgnModelRefP modelRef,
#if defined (MSVERSION) && (MSVERSION == 0xa00)
		ModelChangeType changeTypeId
#else
		int  changeTypeId
#endif
	)
	{

		//MODEL_CHANGE_Create - the model has been created.
		//MODEL_CHANGE_Delete - the model has been deleted.
		//MODEL_CHANGE_Name - the model's name has changed.
		//MODEL_CHANGE_Data - the model's data has changed.
		//MODEL_CHANGE_Active - the model has become the active model.
		//MODEL_CHANGE_BeforeDelete - the model is about to be deleted.

		// connect
		//MODEL_CHANGE_Create = 1,
		//MODEL_CHANGE_Delete = 2,
		//MODEL_CHANGE_Properties = 3,
		//MODEL_CHANGE_Settings = 4,
		//MODEL_CHANGE_Active = 5,
		//MODEL_CHANGE_BeforeDelete = 6,
		//MODEL_CHANGE_UnCreate = 7,
		//MODEL_CHANGE_UnDelete = 8,
		//MODEL_CHANGE_BeforeUnCreate = 9,
		//MODEL_CHANGE_Name = 10,
		//MODEL_CHANGE_BeforeActive = 11,
		//MODEL_CHANGE_BeforeName = 12,
		//MODEL_CHANGE_BeforeSettings = 13,
		//MODEL_CHANGE_BeforeProperties = 14,
		//MODEL_CHANGE_BeforeCreate = 15,
		//MODEL_CHANGE_BeforeUnDelete = 16,
		//MODEL_CHANGE_PropagateAnnotationScale = 17,
		//MODEL_CHANGE_BeforeCopy = 18,
		//MODEL_CHANGE_Copied = 19,
		//MODEL_CHANGE_BeforeUndoProperties = 20,
		//MODEL_CHANGE_UndoProperties = 21

		writeLogIn(__FUNCTION__, 0);


		if (changeTypeId == MODEL_CHANGE_Active)
		{
			getCatInfo(&curCat, ACTIVEMODEL, false);

			loadDBLaps();

			setDefaultStyles();

			checkThisFileIsModel(modelRef);

			//-----------------
			reloadCurBarsAll(iCfgVar_LoadRefsOnStart);
			//-----------------

			loadSchemaFile((elemCount > 0), L("ReinModel"));

			reloadHidingPositions();
			//updateHidePosArray(TRUE, -1);

			syncShowInfo();


			MSDLGP dbP = NULL;

			if (NULL != (dbP = mdlDialog_find(DLG_POSLIST, NULL)))
			{
				//loadAllPositions(FALSE); // _loadFilePositions выше
				updateListBoxPos(FALSE);

				DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ComboBox, 1, 0);

				if (diP)
				{
					ListModel* pListModel = (ListModel*)mdlDialog_comboBoxGetListModelP(diP->rawItemP);
					mdlListModel_destroy(pListModel, TRUE);

					pListModel = (ListModel*)createListBoxRefs();
					mdlDialog_comboBoxSetListModelP(diP->rawItemP, pListModel);

					mdlDialog_itemsSynch(dbP);
				}

			}

			//createOptionShow();
			if (NULL != (dbP = mdlDialog_find(DLG_PRESENT, NULL)))
			{
				DialogItem* diP = mdlDialog_itemGetByTypeAndId(dbP, RTYPE_ComboBox, 3, 0);

				if (diP)
				{
					ListModel* pListModel = (ListModel*)mdlDialog_comboBoxGetListModelP(diP->rawItemP);
					mdlListModel_destroy(pListModel, TRUE);

					pListModel = (ListModel*)createListBoxRefs();
					mdlDialog_comboBoxSetListModelP(diP->rawItemP, pListModel);

					mdlDialog_itemsSynch(dbP);
				}

			}



			if (iModelType && bModelOutOfDate)
			{
				mdlOutput_messageCenter(MESSAGE_WARNING, L("Model version is out of date!\nPlease regenerate the model!"),
					L("The version of current reinforcement model is out of date. It is strongly recommended that you regenerate the current model."), MESSAGE_ALERT_BALLOON);

				bModelOutOfDate = FALSE;
			}

			showLicense();
		}

		writeLogOut(__FUNCTION__, 0);

	}


	/////////////////////////////////////////
	int callbackViewUpdating(
#if defined (MSVERSION) && (MSVERSION == 0xa00) // callbackViewUpdating
		bool                        preUpdate,
		DgnPlatform::DgnDrawMode    eraseMode,
		DgnModelRefListP            modelList,
		int                         numRegions,
		Asynch_update_view          regions[],
		ViewContextP                context,
#else
		int                    preUpdate,  // preUpdate is TRUE if the call is before an update. Otherwise, it is FALSE.
		DRAWMODE             eraseMode,  // eraseMode is set to NORMALDRAW, ERASE or HILITE
		DgnModelRefListP   modelRefList,  // contains the list of models included in the view 
		int                    numberRegions,
		Asynch_update_view     regions[],
		BSIRect* coverLists[],
#endif
		int                    numCovers[], // cover list sizes 
		MSDisplayDescr* displayDescr[]
	)
	{


		writeLogIn(__FUNCTION__, 0);

		//printf("%i\n", numberRegions);

		if (preUpdate)
		{
			buildViewShape(regions[0].viewnum, eraseMode);
		}
		else
		{

			//buildViewShape(regions[0].viewnum, eraseMode);

			//printf("qwe AFTER\n");
			// ...
			iCurUpdateCount = 0;
		}

		writeLogOut(__FUNCTION__, 0);

		return 0;
	}




	////////////////////////////////////
	void  callbackDgnFileChanged(
		MSElementDescrP newDescr,
		MSElementDescrP oldDescr,
		ChangeTrackInfo* info,
		BINT* cantBeUndoneFlag
	)
	{
		int args[2]; // 0 - bAdd, добавляется или нет

		int tp;

		//struct ChangeTrackInfo 
		//{
		//	CHANGE_TRACK_Action       action ;  
		//		CHANGE_TRACK_Delete       = 1 ,  
		//		CHANGE_TRACK_Add       = 2 ,  
		//		CHANGE_TRACK_Modify       = 3 ,  
		//		CHANGE_TRACK_NewFPosModify       = 4 ,  
		//		CHANGE_TRACK_ModifyFence       = 5 ,  
		//		CHANGE_TRACK_Drop       = 6 ,  
		//		CHANGE_TRACK_Mark       = 7 ,  
		//		CHANGE_TRACK_AppData       = 8 ,  
		//		CHANGE_TRACK_ModelAdd       = 9 ,  
		//		CHANGE_TRACK_ModelDelete       = 10 ,  
		//	Int32       processNumber ;  
		//	Int16       funcname ;  
		//	Int32       idNumber ;  
		//};


			//if (mdlSystem_findMdlDesc("BATCHCONVERT") != NULL) return;
			/*
			enum class ChangeTrackAction
			{
				Delete = 1,  //!< An element was deleted from the file.
				Add = 2,  //!< An element was added to the file.
				Modify = 3,  //!< An existing element was changed and rewritten to the file in place.
				AddComplete = 4,  //!< An element (and its xattributes) were added to the file.
				ModifyFence = 5,  //!< The fence was modified.
				x
				Mark = 7,  //!< Used to delineate commands in undo buffer.
				x
				ModelAdd = 9,  //!< A model was added to the file.
				ModelDelete = 10, //!< A model was deleted from the file.
				XAttributeAdd = 11, //!< An XAttribute was addeed to an element.
				XAttributeDelete = 12, //!< An XAttribute was deleted from an element.
				XAttributeModify = 13, //!< some part of the XAttribute was modified.
				XAttributeReplace = 14, //!< An XAttribute was replaced.
				ModelPropModify = 15, //!< A model's properties were modified.
				[new]	CustomEntry = 16, //!< Application data held in the undo buffer (\em not an element-level change to the file).
				[new]	ModifyComplete = 17, //!< An existing element (and its xattributes) were changed and rewritten to the file in place.
				Last = ChangeTrackAction::ModifyComplete,
			};

			CHANGE_TRACK_Delete         = 1,
			CHANGE_TRACK_Add = 2,
			CHANGE_TRACK_Modify = 3,
			CHANGE_TRACK_NewFPosModify = 4,
			CHANGE_TRACK_ModifyFence = 5,
			x	CHANGE_TRACK_Drop = 6,
			CHANGE_TRACK_Mark = 7,
			x	CHANGE_TRACK_AppData = 8,
			CHANGE_TRACK_ModelAdd = 9,
			CHANGE_TRACK_ModelDelete = 10,
			CHANGE_TRACK_XAttributeAdd = 11,
			CHANGE_TRACK_XAttributeDelete = 12,
			CHANGE_TRACK_XAttributeModify = 13,
			CHANGE_TRACK_XAttributeReplace = 14,
			CHANGE_TRACK_ModelPropModify = 15,
			CHANGE_TRACK_Last = CHANGE_TRACK_ModelPropModify,
		*/

		if (iDebug)
		{
			ChangeTrackInfo       inf;
#if defined (MSVERSION) && (MSVERSION == 0xa00)
			inf.action = ChangeTrackAction::Delete;
#else
			inf.action = CHANGE_TRACK_Delete;
#endif
			inf.funcname = 0;
			inf.idNumber = 0;
			inf.processNumber = 0;

			if (info == NULL) info = &inf;

			writeLogIn(__FUNCTION__, 0);
			if (iDebug) sprintf(sLogMes, "BRYS = %i, action = %i\n", BRYS, info->action); writeLog(0, 0);
		}


		if (BRYS)
		{
			if (iDebug) writeLogOut(__FUNCTION__, "THERE IS A BRYS, return");
			return;
		}

		if (iDebug)
		{
			if (oldDescr) { sprintf(sLogMes, "oldDescr exists    \n");	writeLog(0, 0); }
			else { sprintf(sLogMes, "oldDescr == NULL    \n"); writeLog(0, 0); }

			if (newDescr) { sprintf(sLogMes, "newDescr exists    \n"); writeLog(0, 0); }
			else { sprintf(sLogMes, "newDescr == NULL    \n"); writeLog(0, 0); }
		}

#if defined (MSVERSION) && (MSVERSION == 0xa00)
		if (info && info->action == ChangeTrackAction::ModifyComplete)
		{
			if (iDebug) writeLogOut(__FUNCTION__, "info->action == ChangeTrackAction::ModifyComplete, RETURN");
			return;
		}
#endif

		if (oldDescr != NULL)
		{
			args[0] = FALSE; // add

			tp = mdlElement_getType(&oldDescr->el);

			writeLog("process", 1, "deleting elements");

			iterateReloadBarsData(oldDescr, args, 0);

			writeLog("process", -1, "deleting elements");

			checkBarsSetElem(oldDescr);

		}

		if (newDescr != NULL)
		{
			args[0] = TRUE; // add

			tp = mdlElement_getType(&newDescr->el);

			writeLog("process", 1, "adding elements");

			iterateReloadBarsData(newDescr, args, 0);

			writeLog("process", -1, "adding elements");

			ReinBar rb;
			ReinSpace rs;
			ReinElement relem;
			ReinElm relm;

			// отображение
			//===========================
			if (elidDisplayCopy && (
				(readReinBarFromElement(&rb, newDescr, TRUE) == SUCCESS) ||
				(readReinSpaceFromElmd(&relem, newDescr, FALSE) == SUCCESS)
				))
			{
				ELID id = mdlElement_getID(&newDescr->el);
				if (id) curRM->vExIds[id] = true;
				//curRM->vExIds.push_back();
				//arID[iIDcount] = mdlElement_getID(&newDescr->el);
				//iIDcount++;
				elidDisplayCopy = 0;
			}

			if (elidDisplayCopy && (
				(readReinElmIso(&relm, newDescr, FALSE, FALSE) == SUCCESS)
				))
			{
				UInt32 fp = mdlElmdscr_getFilePos(newDescr);
				if (fp) curRM->vExFps[fp] = true;
				//curRM->vExFps.push_back(mdlElmdscr_getFilePos(newDescr));
				//arFP[iFPcount] = mdlElmdscr_getFilePos(newDescr);
				//iFPcount++;
			}

			//===========================

		}


		//updateListBoxPos();

		if (iDebug) writeLogOut(__FUNCTION__, 0);


	}

	///////////////////////////////
	//void  callbackDgnFileUndoRedoFinished(	BoolInt       isUndo)
	//{
	//	__asm nop;
	//	//curRM->reloadCurBars(false, true, 2, 0);
	//}

	///////////////////////////////
	void  callbackDgnFileUndoRedo
	(
#if defined (MSVERSION) && (MSVERSION == 0xa00) // callbackDgnFileUndoRedo
		MSElementDescrP                     afterUndoRedo,      // the current state (after undo or redo has happened)
		MSElementDescrP                     beforeUndoRedo,     // the state immediately previous to undo/redo
		DgnPlatform::ChangeTrackAction    action,             // the action that happened
		bool                                isUndo,             // if true -> this is an undo, if false -> this is a redo
		DgnPlatform::ChangeTrackInfo const* info,               // info about command that cause original change. CAN BE NULL!!!
		DgnPlatform::ChangeTrackSource    source              // the source of the change (undo, restore, merge)
#else
		MSElementDescrP       afterUndoRedo,
		MSElementDescrP       beforeUndoRedo,
		CHANGE_TRACK_Action       action,
		BoolInt       isUndo,
		ChangeTrackInfo const* info,
		CHANGE_TRACK_Source       source
#endif
	)
	{

		writeLogIn(__FUNCTION__, 0);

		callbackDgnFileChanged(afterUndoRedo, beforeUndoRedo, 0, 0);

		writeLogOut(__FUNCTION__, 0);
	}


	/////////////////////////
	int iterateFindClose(
		MSElementDescr* edP,
		MSElementDescr** barPP,
		ScanCriteria* pScanCriteria
	)
	{
		//mdlKISolid_elementToBody

#if defined (MSVERSION) && (MSVERSION == 0x8b0)


		//mdlKISolid_minimumDistanceBetweenEntities

		KIBODY* kb_shape = NULL;
		KIBODY* kb_shape_bar = NULL;

		/*

		KIENTITY_LIST* k1 = NULL;
		KIENTITY_LIST* k2 = NULL;


		KIENTITY_LIST* listP = NULL, * transformListP = NULL;

		//Open a solids kernel->UORs transformation
		mdlKISolid_beginCurrTrans();

		if (SUCCESS == mdlKISolid_elementToBodyList(&listP, NULL,
			&transformListP, NULL, edP, modelRef, filePos, TRUE, TRUE, TRUE))
		{
			int    i = 0;
			KIBODY* bodyP = NULL;

			for (i = 0; SUCCESS == mdlKISolid_listNthEl(&bodyP, listP, i); i++)
			{
				Transform* transformP = NULL;
				if (NULL != bodyP &&
					NULL != transformListP &&
					SUCCESS == mdlKISolid_listNthEl(&transformP, transformListP, i) &&
					NULL != transformP
					)
				{
					mdlKISolid_applyTransform(bodyP, transformP);
					// Display this body
					//displayBody(bodyP, MASTERFILE, HILITE);
					mdlKISolid_free(bodyP);
					mdlKISolid_free(transformP);
				}
			}
		}
		if (NULL != listP)
			mdlKISolid_listDelete(&listP);
		if (NULL != transformListP)
			mdlKISolid_listDelete(&transformListP);


		*/








		Transform tm1;
		Transform tm2;



		int t1 = mdlElement_getType(&edP->el);
		int t2 = mdlElement_getType(&(*barPP)->el);


		ELID id1 = mdlElement_getID(&edP->el);
		ELID id2 = mdlElement_getID(&(*barPP)->el);

		//mdlKISolid_elementToBodyList(&k1)


		int ret1 = mdlKISolid_elementToBody2(&kb_shape, &tm1, edP, edP->h.dgnModelRef, 1L, 0);
		int ret2 = mdlKISolid_elementToBody2(&kb_shape_bar, &tm2, *barPP, (*barPP)->h.dgnModelRef, 1L, 0);
		int ret3 = ERROR;

		if (ret1 == SUCCESS && ret2 == SUCCESS && id1 != id2)
		{
			DPoint3d pPoint1[2];
			DPoint3d pPoint2[2];
			double distance = 0.;
			double distance1 = 0.;
			double distance2 = 0.;

			mdlKISolid_applyTransform(kb_shape, &tm1);
			mdlKISolid_applyTransform(kb_shape_bar, &tm2);

			mdlKISolid_getEntityBox(&pPoint1[0], &pPoint1[1], kb_shape);
			mdlKISolid_getEntityBox(&pPoint2[0], &pPoint2[1], kb_shape_bar);

			ret3 = mdlKISolid_minimumDistanceBetweenEntities(&pPoint1[0], &pPoint1[1], &distance, kb_shape, kb_shape_bar);

			if (ret3 == SUCCESS)
			{
				//mdlKISolid_debugEntity(kb_shape, s);
				//mdlKISolid_debugEntity(kb_shape_bar, ss);

				//mdlCurrTrans_transformPointArray(pPoint2, pPoint1, 2);

				//distance1 = mdlVec_distance(&pPoint2[0], &pPoint2[1]);

				//mdlCurrTrans_invtransPointArray(pPoint2, pPoint1, 2);

				//mdlCurrTrans_invScaleDoubleArray(&distance1, &distance, 1);
				mdlCurrTrans_scaleDoubleArray(&distance2, &distance, 1);

				//distance2 = mdlVec_distance(&pPoint2[0], &pPoint2[1]);

				printf("%I64u %I64u    %f  \n", id1, id2, mdlCnv_uorsToMasterUnits(distance2));
			}


		}

		if (ret1 == SUCCESS) mdlKISolid_freeBody(kb_shape);
		if (ret2 == SUCCESS) mdlKISolid_freeBody(kb_shape_bar);
#endif

		return 0;


	}

	///////////////////////////////////////////////////////////////////
	BINT  checkClosest(MSElementDescr**  edPP)
	{


		//ELREF  elmRef = NULL;
		//MSElement   elm;
		size_t         elSize;
		ELID elid;
		//ReinElm re;
		//ReinSpace rs;
		//ReinBar rb;



		writeLogIn(__FUNCTION__, 0);


		//if (edP)
		{
			//elid = elementRef_getElemID(elmRef);

			//mdlElmdscr_getByElemRef(&edP, elmRef, mdlLocate_getCurrModelRef(), FALSE, 0);


			{

				{

					DPoint3d prng[2];
					ScanRange sr;

					mdlElmdscr_computeRange(&prng[0], &prng[1], *edPP, NULL);

					sr.xlowlim = (Int64)(prng[0].x - mdlCnv_masterUnitsToUors(dDupTol));
					sr.ylowlim = (Int64)(prng[0].y - mdlCnv_masterUnitsToUors(dDupTol));
					sr.zlowlim = (Int64)(prng[0].z - mdlCnv_masterUnitsToUors(dDupTol));

					sr.xhighlim = (Int64)(prng[1].x + mdlCnv_masterUnitsToUors(dDupTol));
					sr.yhighlim = (Int64)(prng[1].y + mdlCnv_masterUnitsToUors(dDupTol));
					sr.zhighlim = (Int64)(prng[1].z + mdlCnv_masterUnitsToUors(dDupTol));



					ScanCriteria* scP = mdlScanCriteria_create();
					mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
					mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)iterateFindClose, edPP);
					mdlScanCriteria_setDrawnElements(scP);
					//mdlScanCriteria_setRangeTest(scP, &sr); // супер
					//mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
					mdlScanCriteria_setModel(scP, ACTIVEMODEL);
					mdlScanCriteria_scan(scP, NULL, NULL, NULL);
					mdlScanCriteria_free(scP);

				}


				//mdlElmdscr_freeAll(&edP);
			}
		}

		writeLogOut(__FUNCTION__, 0);


		return SUCCESS;
	}





	///////////////////////////////////////////////////////////////////
	BINT  callbackElemDoubleClick(DisplayPathP       path)
	{


		ELREF  elmRef = NULL;
		//MSElement   elm;
		size_t         elSize;
		ELID elid;
		//ReinElm re;
		//ReinSpace rs;
		//ReinBar rb;
		MSElementDescr* edP;


		MSDLGP pDb = NULL;
		if (NULL == (pDb = mdlDialog_find(DLG_POSLIST, NULL)))
			return SUCCESS;

		writeLogIn(__FUNCTION__, 0);

		elmRef = mdlDisplayPath_getElem(path, 0);
		//elSize = elementRef_getElement (elmRef, &elm, sizeof elm);

		elid = elementRef_getElemID(elmRef);


		arPos.clear();
		arPos.resize(10);
		arPosCount.clear();
		arPosCount.resize(10);
		iPosCount = 0;


		if (elmRef)
		{
			mdlElmdscr_getByElemRef(&edP, elmRef, mdlLocate_getCurrModelRef(), FALSE, 0);


			if (edP)
			{
				ReinBar rb;

				if (readReinBarFromElement(&rb, edP, TRUE) == SUCCESS)
				{

					DPoint3d prng[2];
					ScanRange sr;

					mdlElmdscr_computeRange(&prng[0], &prng[1], edP, NULL);

					sr.xlowlim = (Int64)(prng[0].x - mdlCnv_masterUnitsToUors(dDupTol));
					sr.ylowlim = (Int64)(prng[0].y - mdlCnv_masterUnitsToUors(dDupTol));
					sr.zlowlim = (Int64)(prng[0].z - mdlCnv_masterUnitsToUors(dDupTol));

					sr.xhighlim = (Int64)(prng[1].x + mdlCnv_masterUnitsToUors(dDupTol));
					sr.yhighlim = (Int64)(prng[1].y + mdlCnv_masterUnitsToUors(dDupTol));
					sr.zhighlim = (Int64)(prng[1].z + mdlCnv_masterUnitsToUors(dDupTol));


					rb.elemid = mdlElement_getID(&edP->el);
					rb.modrefP = edP->h.dgnModelRef;

					UInt32 rn = getRefNum(rb.modrefP);
					ReinModel* rmP = curRM->getRM(rb.modrefP);


					rbFoundP = NULL;

					UShort          typeMask[6];

					for (UShort a = 0; a < 6; a++) typeMask[a] = 0;

					typeMask[0] = TMSK0_LINE |
						TMSK0_ARC |
						TMSK0_CELL_HEADER |
						TMSK0_LINE_STRING |
						TMSK0_CMPLX_STRING | TMSK0_ELLIPSE;

					ScanCriteria* scP = mdlScanCriteria_create();
					mdlScanCriteria_setReturnType(scP, MSSCANCRIT_ITERATE_ELMDSCR, FALSE, TRUE);
					mdlScanCriteria_setElmDscrCallback(scP, (PFScanElemDscrCallback)iterateFindReinElm, &rb);
					mdlScanCriteria_setElementTypeTest(scP, typeMask, sizeof(typeMask));
					mdlScanCriteria_setRangeTest(scP, &sr); // супер
					mdlXML_addXMLFragmentAttachmentScanTest(scP, &appID, &appTypeReinElm);
					mdlScanCriteria_setModel(scP, ACTIVEMODEL);
					mdlScanCriteria_scan(scP, NULL, NULL, NULL);
					mdlScanCriteria_free(scP);

					if (rbFoundP)
					{
						long num = -1;


						for (MAP<long, ReinPos>::iterator it = rmP->arCurPos.begin(); it != rmP->arCurPos.end(); ++it)
						{

							ReinPos* rpItP = &it->second;

							if (barsEqual(rbFoundP, &rpItP->bar))
							{
								//CatInfo ci;
								//getCatInfo(&ci, edP->h.dgnModelRef, false);
								//if (rpItP->pcatID == ci.catModID)
								{
									num = it->first; // порядовый номер в массиве arCurPos
									break;
								}
							}
						}

						reinSelectPosRow(num);
					}
				}


				mdlElmdscr_freeAll(&edP);
			}
		}

		writeLogOut(__FUNCTION__, 0);


		return SUCCESS;
	}



	/////////////////////////////
	void callbackViewMotion(
		MSDLGP window, int xCoord, int yCoord
	)
	{
		//iDataCopyCount = 0; // ненадо сбрасывать
		dataCopyNewElemID = 0; // позволяет копировать контуры 
	}


	//int iDebug;
	//char sLogMes[5000];


/*---------------------------------------------------------------------------------**//**
* @description  MdlMain
* @param 	argc      The number of command line parameters sent to the application.
* @param 	argv[]    The array of strings sent to the application on the command line.
+---------------+---------------+---------------+---------------+---------------+------*/
#if defined (MSVERSION) && (MSVERSION == 0xa00) // main
extern "C" DLLEXPORT void MdlMain
(
	int         argc,
	WCharCP     argv[]
)
#else
extern "C" DLLEXPORT  int MdlMain
(
	int         argc,
	char* argv[]
)
#endif
{

	SymbolSet* setP;
	RscFileHandle   userPrefsH = NULL;
	void* rscP = NULL;



//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//	unsigned long long rscSize = 0;
//#else
	ULong	     rscSize = 0;
//#endif

	/*
	time_t theTime = time(NULL);
	struct tm* aTime = localtime(&theTime);

	int day = aTime->tm_mday;
	int month = aTime->tm_mon + 1; // Month is 0 - 11, add 1 to get a jan-dec 1-12 concept
	int year = aTime->tm_year + 1000 + 900; // Year is # years since 1900

#if defined (REIN_TEST)
	{
		strcpy(s, "testonly");
		if (year > 2022) return 0;
	}
#endif
*/

	if (argc > 2 && SCMP(argv[2], L("x")) == 0) // no load ReinElms in mapElms
	{
		bNoLoad = true;
	}
	//map<UInt32, UInt32> mapElms;
	//mapElms.insert(pair<UInt32, UInt32>(456, 789));

	//arCurMrP = NULL;

	//mdlDialog_openMessageBox(DIALOGID_MsgBoxOK, "mdlResource_openFile", MSGBOX_ICON_INFORMATION);

	//===========================

	//ups
/*
	ups_parameter_t parameters[] = {
		{ UPS_PARAM_KEY_TYPE, UPS_TYPE_UINT32 },
		{ UPS_PARAM_RECORD_SIZE, sizeof(ReinElm) },
		{ 0, NULL }
	};

	upst = ups_env_create(&upenv, NULL, UPS_IN_MEMORY, 0, parameters);

	if (upst != UPS_SUCCESS) upenv = NULL;


	  ups_status_t st;

	  ups_env_t *env = NULL;
	  ups_db_t *db = NULL;
	  //ups_key_t key = { 0 };
	  //ups_record_t record = { 0 };
	  ups_parameter_t params[] = {
		 // { UPS_PARAM_KEY_TYPE, UPS_TYPE_UINT32},
		 // { UPS_PARAM_RECORD_SIZE, sizeof(uint32_t) },
		 // { 0, } };

	  st = ups_env_create(&env, NULL, UPS_IN_MEMORY, 0, 0);

	  if (st == UPS_SUCCESS)
	  {
		  st = ups_env_create_db(env, &db, 1, 0, 0);

		  if (st == UPS_SUCCESS)
		  {
			  st = ups_db_close(db, 0);

		  }

		  st = ups_env_close(env, 0);
	  }

	ReinClash rc;
	mapClash[make_pair(1, 2)] = rc;
	mapClash[make_pair(2, 1)] = rc;
	mapClash[make_pair(100, 200)] = rc;
	mapClash[make_pair(200, 100)] = rc;
	return 0; // NO SORT, все там

	// вектор итератор после erase автоматически смещается
	vector <int> vv;
	vv.push_back(1);
	vv.push_back(2);
	vv.push_back(3);
	vv.push_back(4);
	vv.push_back(5);
	vector<int>::iterator it = vv.begin();
	it++;
	it++;
	vv.erase(it);
	int a = *it;
	return 0;
*/

	arPos[0] = 10;
	arPos[1] = 11;
	arPos[2] = 12;
	arPos[3] = 13;


	arPos.clear();
	arPos.resize(10);




//===========================

//#if defined (STD_INTERFACE)

	if (SUCCESS != mdlResource_openFile(&rfHandle, NULL, RSC_READONLY))
	{
		WCH str[1000];
		SPRN(str, L("%s: unable to open resource file"), mdlSystem_getCurrTaskID());
		mdlOutput_messageCenter(MESSAGE_WARNING, str, str, MESSAGE_ALERT_NONE);
		mdlInput_sendCommand(CMD_MDL_UNLOAD, mdlSystem_getCurrTaskID(), INPUTQ_EOQ, 0, 0);
		rfHandle = NULL;

	}
	// Map key-in to function
//#endif

	//if (SUCCESS != mdlResource_openFile(&rfRein, L("rein.rsc"), RSC_READONLY))
	//	rfRein = NULL;

	static MdlCommandNumber cmdNumbers[] =
	{
		//{ (CmdHandler)cmdReinPlace,		CMD_REIN_PLACE				},
		{ (CmdHandler)cmdLogOpen,  		CMD_REIN_LOGOPEN			},
		{ (CmdHandler)cmdLogClose,  	CMD_REIN_LOGCLOSE			},
		//{(CmdHandler)cmdReinMirror,	CMD_REIN_MIRROR				},
		{ (CmdHandler)cmdReinFront,		CMD_REIN_FRONT				},
		{ (CmdHandler)cmdReinSide,		CMD_REIN_SIDE				},
		{ (CmdHandler)cmdReinNote,		CMD_REIN_NOTE				},
		{ (CmdHandler)cmdReinLoads,		CMD_REIN_LOADS				},
		{ (CmdHandler)cmdReinPlane,		CMD_REIN_PLANE				},
		{ (CmdHandler)cmdReinChLap,		CMD_REIN_CHLAP				},
		{ (CmdHandler)cmdReinDrop,		CMD_REIN_DROP				},
		{ (CmdHandler)cmdReinVisit,		CMD_REIN_VISIT				},
		{ (CmdHandler)cmdReinMerge,		CMD_REIN_MERGE				},
		{ (CmdHandler)cmdReinVersion,	CMD_REIN_VERSION			},
		{ (CmdHandler)cmdReinUnGrab,		CMD_REIN_UNGRAB				},
		{ (CmdHandler)cmdToolBox,		CMD_REIN_TOOLBOX			},
		{ (CmdHandler)cmdAnker,			CMD_REIN_ANKER				},
		{ (CmdHandler)cmdReinModify,		CMD_REIN_MODIFY				},
		{ (CmdHandler)cmdShowTooltip,	CMD_REIN_TOOLTIP			},
		{ (CmdHandler)cmdReload,			CMD_REIN_RELOAD				},
		{ (CmdHandler)cmdDrawEnds,		CMD_REIN_DRAWENDS			},
		{ (CmdHandler)cmdRefPrefsDel,	CMD_REIN_REFPDEL			},
		{ (CmdHandler)cmdFileBars,		CMD_REIN_FILEBARS			},
		{ (CmdHandler)cmdDrawCont,		CMD_REIN_DRAWCONT			},
		{ (CmdHandler)cmdDrawBars,		CMD_REIN_DRAWBARS			},
		{ (CmdHandler)cmdReinList,		CMD_REIN_LIST				},
		{ (CmdHandler)cmdReinShow,		CMD_REIN_FLAGS				},
		//{(CmdHandler)cmdDrawNodes,		CMD_REIN_NODES				},
		{ (CmdHandler)cmdMuft,			CMD_REIN_MUFT				},
		//{(CmdHandler)cmdMuftShow,		CMD_REIN_MUFTSHOW			},
		{ (CmdHandler)cmdCages,			CMD_REIN_CAGES				},
		{ (CmdHandler)cmdHidepos,		CMD_REIN_HPINFO				}, // hidepos info
		{ (CmdHandler)cmdBarEnds,		CMD_REIN_BARENDS			},
		{ (CmdHandler)cmdBarEndsDialog,	CMD_REIN_BARENDS_DIALOG		},
		{ (CmdHandler)cmdBarSet,		CMD_REIN_BARSET				},
		{ (CmdHandler)cmdBarOverride,	CMD_REIN_BAROVER			},
		{ (CmdHandler)cmdReinList,		CMD_REIN_POS				},
		{ (CmdHandler)cmdPosClear,		CMD_REIN_POS_CLEAR			},
		{ (CmdHandler)cmdPosSave,		CMD_REIN_POS_SAVE			},
		{ (CmdHandler)cmdPosLoadDB,		CMD_REIN_POS_DBLOAD			},
		{ (CmdHandler)cmdPosSaveDB,		CMD_REIN_POS_DBSAVE			},
		{ (CmdHandler)cmdPosDraw,		CMD_REIN_POS_DRAW			},
		{ (CmdHandler)cmdPosEnum,		CMD_REIN_POS_ENUM			},
		{ (CmdHandler)cmdPosCatch,		CMD_REIN_POS_CATCH			},
		{ (CmdHandler)cmdSavePlot,		CMD_REIN_SAVEPLOT			},
		{ (CmdHandler)cmdSavePlot,		CMD_REIN_SAVEPLOT_REFS		},
		{ (CmdHandler)cmdSavePlotClear,	CMD_REIN_SAVEPLOT_CLEAR		},
		{ (CmdHandler)cmdReinDups,		CMD_REIN_DUPS				},
		{ (CmdHandler)cmdHideposDel,	CMD_REIN_HPDEL				}, // bar sets info
		{ (CmdHandler)cmdConcrete,		CMD_REIN_CONCRETE			},
		0,
	};



	mdlSystem_registerCommandNumbers(cmdNumbers);



	if (NULL == mdlParse_loadCommandTable(NULL))
	{
		//char	msg	[512];
		mdlOutput_printf(MSG_MESSAGE, L("rein - error %i (loading commands)"), mdlErrno);
		//mdlInput_sendCommand (CMD_MDL_UNLOAD, mdlSystem_getCurrTaskID (), INPUTQ_EOQ, 0, 0);
	}



	//REIN_DEBUG = 0 // нет записи в лог
	//REIN_DEBUG = 1 // есть запись в лог
	//REIN_DEBUG = 2 // есть запись в лог, причем при каждой записи файл открывается и закрывается

	WCH v[500];

	SCPY(sFileLog, L("c:/temp/rein.log"));


	if (getCfgVarEx(v, L"REIN_DEBUG") == SUCCESS)
	{

		iDebug = STOI(v);

		if (iDebug)
		{
			if (iDebug == 3) openLogFile(FALSE);
		}
	}
	else
		iDebug = FALSE;



	openLogFile(FALSE);

	writeLog("RHEIN", 1);


	writeLogIn(__FUNCTION__, "================ MAIN ===============");



	mdlVec_zero(&pZero);
	mdlVec_fromXYZ(&pZ, 0., 0., 1.);

	DVec3d pIso;
	mdlVec_fromXYZ(&pIso, 1., 1., 1.);
	mdlRMatrix_fromNormalVector(&rmIso, &pIso);

	/* Prepare to read resource. The resource file was used to save
	   information the last time chngtxt was used. */
	rscP = NULL;
	userPrefsH = NULL;


/* 

пример из steel.cpp
--- load Section and Hatching Preferences --- 
	if (SUCCESS == mdlDialog_userPrefFileOpen(&userPrefsH, RSC_READWRITE))
	{
		SectInfo* sectRscP = NULL;

		if (NULL != (sectRscP = (SectInfo*)mdlResource_loadByAlias(userPrefsH, RTYPE_Stlp, RSCID_Stlp, mdlSystem_getCurrTaskID())))
		{
			ULong rscSize;

			mdlResource_query(&rscSize, sectRscP, RSC_QRY_SIZE);

			if ((sectRscP->version == STEEL_RESOURCE_VERSION) && (rscSize == sizeof(SectInfo)))
			{
				status = SUCCESS;
				sectionInfo = *sectRscP;
			}

			// --- Free the memory used by the rsc --- 
			mdlResource_free(sectRscP);
		}

		gSectionListP = mdlStringList_loadResource(userPrefsH, SECTIONTYPE_LIST_ID);

		mdlResource_closeFile(userPrefsH);
	}
*/


#if defined (STD_INTERFACE)


	//=======================================================================
	mdlDialog_userPrefFileOpen(&userPrefsH, TRUE);
	//==============================================

	if (userPrefsH)
	{
		rscP = mdlResource_loadByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinPrefs, mdlSystem_getCurrTaskID());
	}

	if (!rscP)
	{
		setRienInfoDefaults();
	}
	else
	{
		mdlResource_query(&rscSize, rscP, RSC_QRY_SIZE);
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//		if (rscSize == sizeof(_ReinInfo))
//		{
//			_ReinInfo ri;
//			ri = *(_ReinInfo*)rscP;
//			rInfo.setLegacy(&ri, true);
//		}
//#else
		if (rscSize == sizeof(strReinInfo))
		{
			MSWCH* str = (MSWCH*)rscP;
			getReinInfoFromString(rInfo, str);
		}
//#endif
		else
		{
			setRienInfoDefaults();
		}

		mdlResource_free(rscP);
	}

	//rInfo.lim = 0;
	//rInfoPref = rInfo; // запоминаем загруженное из сохр. сессии

	//==============================================

	rDopInfo.clear();

	if (userPrefsH)
	{
		rscP = mdlResource_loadByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinDopPrefs, mdlSystem_getCurrTaskID());
	}

	if (rscP)
	{
		mdlResource_query(&rscSize, rscP, RSC_QRY_SIZE);
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//		if (rscSize == sizeof(_ReinDopInfo))
//		{
//			_ReinDopInfo ri;
//			ri = *(_ReinDopInfo*)rscP;
//			rDopInfo.setLegacy(&ri, true);
//		}
//#else
		if (rscSize == sizeof(strReinDopInfo))
		{
			MSWCH* str = (MSWCH*)rscP;
			getReinInfoFromString(rDopInfo, str);
			//rDopInfo = *(ReinDopInfo*)rscP;
		}
//#endif
		else
		{
			rDopInfo.clear();
		}

		mdlResource_free(rscP);
	}

	//if (rDopInfo.dopopt[14] < 0) rDopInfo.dopopt[14] = 0; // совместимость

	rDopInfoPref = rDopInfo; // запоминаем загруженное из сохр. сессии

	//==============================================


	//==============================================

	rBarOverInfo.clear();

	if (userPrefsH)
	{
		rscP = mdlResource_loadByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinBarPrefs, mdlSystem_getCurrTaskID());
	}

	if (rscP)
	{
		mdlResource_query(&rscSize, rscP, RSC_QRY_SIZE);
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//		if (rscSize == sizeof(_ReinDopInfo))
//		{
//			_ReinDopInfo ri;
//			ri = *(_ReinDopInfo*)rscP;
//			rBarOverInfo.setLegacy(&ri, true);
//		}
//#else
		if (rscSize == sizeof(strBarOverInfo))
		{
			MSWCH* str = (MSWCH*)rscP;
			getReinInfoFromString(rBarOverInfo, str);
			//rBarOverInfo = *(ReinDopInfo*)rscP;
		}
//#endif
		else
		{
			rBarOverInfo.clear();
		}

		mdlResource_free(rscP);
	}

	//==============================================

	curNoteSet.clear();

	SCPY(curNoteSet.sNoteUpFmt, L("(N1)Q1[+(N2)Q2]"));

	if (userPrefsH)
	{
		rscP = mdlResource_loadByAlias(userPrefsH, RTYPE_REIN, RSCID_ReinNotePrefs, mdlSystem_getCurrTaskID());
	}

	if (rscP)
	{
		mdlResource_query(&rscSize, rscP, RSC_QRY_SIZE);
//#if defined (MSVERSION) && (MSVERSION == 0xa00)
//		if (rscSize == sizeof(_ReinNoteSet))
//		{
//			_ReinNoteSet ri;
//			ri = *(_ReinNoteSet*)rscP;
//			curNoteSet.setLegacy(&ri, true);
//		}
//#else
		if (rscSize == sizeof(strCurNoteSet))
		{
			MSWCH* str = (MSWCH*)rscP;
			getReinInfoFromString(curNoteSet, str);
			//curNoteSet = *(ReinNoteSet*)rscP;
		}
//#endif
		//else
		//{
		//	curNoteSet.clear();
		//}

		mdlResource_free(rscP);
	}

	//=======================================================================
	if (userPrefsH)
		mdlResource_closeFile(userPrefsH);
	//=======================================================================
	
#else

	setRienInfoDefaults();
	rDopInfo.clear();
	rBarOverInfo.clear();
	curNoteSet.clear();

#endif

	if (rInfo.rsVal.runmet > 3) rInfo.rsVal.runmet = 0; // погонные метры

	//rInfo.option[17] = TRUE;

	// размеры эскизов ведомости
	if (rDopInfo.dopval[4] < 10. || rDopInfo.dopval[4] > 90.) rDopInfo.dopval[4] = 70.;
	if (rDopInfo.dopval[5] < 10. || rDopInfo.dopval[5] > 90.) rDopInfo.dopval[5] = 65.;


	if (iDebug) sprintf(sLogMes, "_mdlCExpression_initializeSet()\n"); writeLog(0, 0);
	setP = mdlCExpression_initializeSet(VISIBILITY_DIALOG_BOX, 0, 0);

	if (iDebug) sprintf(sLogMes, "_mdlState_registerStringIds()\n"); writeLog(0, 0);
	mdlState_registerStringIds(1, 0);

	if (iDebug) sprintf(sLogMes, "_mdlDialog_publishBasicVariable() begin...\n"); writeLog(0, 0);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "rbartype", &rInfo.rsVal.bartype);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "runmet", &rInfo.rsVal.runmet);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "diam", &rInfo.rsVal.diam);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "space", &rInfo.rsVal.space);
	//mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "space2", &rInfo.rsVal.space2);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "spacerad", &rInfo.rsVal.spacerad);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "offset", &rInfo.rsVal.offset[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "offset2", &rInfo.rsVal.offset[1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "bendrad", &rInfo.rsVal.bendrad);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "poscalc", &rInfo.rsVal.poscalc);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "termbeg", &rInfo.rsVal.trm[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "termend", &rInfo.rsVal.trm[1]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "itermbeg", &rInfo.rsOpt.trm[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "itermend", &rInfo.rsOpt.trm[1]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "termAngBeg", &rInfo.rsVal.trmPar[0][0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "termLenBeg", &rInfo.rsVal.trmPar[1][0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "termAngEnd", &rInfo.rsVal.trmPar[0][1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "termLenEnd", &rInfo.rsVal.trmPar[1][1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "termMTpBeg", &rInfo.rsVal.trmPar[2][0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "termMTpEnd", &rInfo.rsVal.trmPar[2][1]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "itermPrmBeg", &rInfo.rsOpt.trmPar[0][0]);
	//mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "itermPrmBeg", &rInfo.rsOpt.trmPar[1][0]);// дублируется
	//mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "itermPrmBeg", &rInfo.rsOpt.trmPar[2][0]);// дублируется
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "itermPrmEnd", &rInfo.rsOpt.trmPar[0][1]);
	//mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "itermPrmEnd", &rInfo.rsOpt.trmPar[1][1]);// дублируется
	//mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "itermPrmEnd", &rInfo.rsOpt.trmPar[2][1]);// дублируется


	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "itermFree", &rDopInfo.dopopt[1]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "barendslow", &rDopInfo.dopopt[2]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "barendshigh", &rDopInfo.dopopt[3]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_U_LONG), "barendsqty", &iBarEndsCount);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_U_LONG), "barcapsqty", &iBarCapsCount);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "barendsrefs", &rDopInfo.dopopt[4]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "barendshil", &rDopInfo.dopopt[5]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "barsetdim", &rDopInfo.dopopt[6]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "drawvedrealbar", &rDopInfo.dopopt[10]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "saveinfo", &rDopInfo.dopopt[14]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "bmx", &rBarOverInfo.dopopt[15]); // move x value
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "bmy", &rBarOverInfo.dopopt[16]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "bmz", &rBarOverInfo.dopopt[17]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ibmx", &rBarOverInfo.dopopt[18]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ibmy", &rBarOverInfo.dopopt[19]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ibmz", &rBarOverInfo.dopopt[20]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "bact", &rBarOverInfo.dopopt[21]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "igrnd", &rBarOverInfo.dopopt[22]);

	//mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "", &rDopInfo.dopopt[15]); - license agree

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "lapbeg", &rInfo.rsVal.lap[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "lapend", &rInfo.rsVal.lap[1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "lapeven", &rInfo.rsVal.lap[2]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ilapbeg", &rInfo.rsOpt.lap[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ilapend", &rInfo.rsOpt.lap[1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ilapeven", &rInfo.rsOpt.lap[2]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "inewbars", &rInfo.rsOpt.bartype);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "irunmet", &rInfo.rsOpt.runmet);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "idiam", &rInfo.rsOpt.diam);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ispace", &rInfo.rsOpt.space);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ispacerad", &rInfo.rsOpt.spacerad);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ioffset", &rInfo.rsOpt.offset[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ioffset2", &rInfo.rsOpt.offset[1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ibendrad", &rInfo.rsOpt.bendrad);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "irepbend", &iCfgVar_BarBendRepair); // repair bend
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iposcalc", &rInfo.rsOpt.poscalc);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ilength", &rInfo.run);
	//mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "ilimits", &rInfo.lim);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowGnd", &rInfo.option[3]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "linestyle", &rInfo.option[6]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "lenmin", &rInfo.rcUnit.length[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "lenmax", &rInfo.rcUnit.length[1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "lencmn", &rInfo.rcUnit.lencmn);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "qty", &rInfo.rcUnit.qty);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "skhgt", &rDopInfo.dopval[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "skwdt1", &rDopInfo.dopval[1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "skwdt2", &rDopInfo.dopval[2]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "skgap", &rDopInfo.dopval[3]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "skperhgt", &rDopInfo.dopval[4]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "skperwdt", &rDopInfo.dopval[5]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "notetxtmrgn", &rDopInfo.dopval[6]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "skrows", &rDopInfo.dopopt[8]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iMuftQty", &rDopInfo.dopopt[7]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iSelBars", &rInfo.bars);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowAux_V", &rInfo.ends);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowAux_O", &rInfo.option[13]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowAux_X", &rInfo.option[14]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowAux_I", &rDopInfo.dopopt[12]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowPosNum", &rInfo.option[15]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "barface", &rInfo.bface);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShow3d", &rInfo.b3d);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowLoadNodes", &rInfo.nodes);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "barset", &rInfo.option[16]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowCont", &rInfo.option[2]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowBars", &rInfo.option[4]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iFileIso", &rInfo.option[5]);
	//mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "iFileBars", &rInfo.option[6]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowBends", &rInfo.option[8]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iSecRealDiam", &rInfo.option[9]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowBounds", &rInfo.option[10]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowSecs", &rInfo.option[11]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowSecsPerp", &rInfo.option[12]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowTransp", &rInfo.option[1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowInvisible", &rInfo.option[18]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowByColor", &rInfo.option[19]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowTranSec", &rInfo.option[17]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowThread", &rInfo.threads);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowArrows", &rInfo.lim);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iShowSketch", &rInfo.ttip);

	//mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "adiam", &rInfo.aInfo.diam);
	//mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "abet", &rInfo.aInfo.bet);
	//mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "aarm", &rInfo.aInfo.arm);
	//mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "awall", &rInfo.aInfo.wall);
	//mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "anklen", &rInfo.aInfo.anklen);
	//mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "applen", &rInfo.aInfo.applen);
	//mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "apprad", &rInfo.aInfo.apprad);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "mirorg", &optmir[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "mirend", &optmir[1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "mirdir", &optmir[2]);

	//mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "listpnum", &posList.pnum);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iSketchScaleHor", &iSketchScale[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iSketchScaleVer", &iSketchScale[1]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iSketchBarWeight", &iSketchBarWeight);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iSketchTxtWeight", &iSketchTxtWeight);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "isModel", &iModelType);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_U_LONG), "iOfftCatID", &curCat.catModID);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_U_LONG), "iOfftProjID", &curCat.projID);
	//mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "iLapMaxLen", &iLapMaxLen);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "bSketchPoint", &bSketchPoint);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "dSketchPointX", &dSketchPointX);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "dSketchPointY", &dSketchPointY);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "dSketchPointZ", &dSketchPointZ);

	//mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_CHAR), "sLineLens", sLineLens, sizeof(sLineLens));
	//mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_CHAR), "sArcLens", sArcLens, sizeof(sArcLens));

#if defined (MSVERSION) && (MSVERSION == 0xa00)

	//mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_UNICODE), "saveinfostr", sCurRef, sizeof(sCurRef));

	mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_UNICODE), "sNoteLevel", curNoteSet.sNoteLevel, sizeof(curNoteSet.sNoteLevel));
	mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_UNICODE), "sNoteUpFmt", curNoteSet.sNoteUpFmt, sizeof(curNoteSet.sNoteUpFmt));
	mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_UNICODE), "sNoteDnFmt", curNoteSet.sNoteDnFmt, sizeof(curNoteSet.sNoteDnFmt));
	mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_UNICODE), "sNoteUp", curNoteSet.sNoteUp, sizeof(curNoteSet.sNoteUp));
	mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_UNICODE), "sNoteDn", curNoteSet.sNoteDn, sizeof(curNoteSet.sNoteDn));

#else

	//mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_CHAR), "saveinfostr", sCurRef, sizeof(sCurRef));

	mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_CHAR), "sNoteLevel", curNoteSet.sNoteLevel, sizeof(curNoteSet.sNoteLevel));
	mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_CHAR), "sNoteUpFmt", curNoteSet.sNoteUpFmt, sizeof(curNoteSet.sNoteUpFmt));
	mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_CHAR), "sNoteDnFmt", curNoteSet.sNoteDnFmt, sizeof(curNoteSet.sNoteDnFmt));
	mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_CHAR), "sNoteUp", curNoteSet.sNoteUp, sizeof(curNoteSet.sNoteUp));
	mdlDialog_publishBasicArray(setP, mdlCExpression_getType(TYPECODE_CHAR), "sNoteDn", curNoteSet.sNoteDn, sizeof(curNoteSet.sNoteDn));

#endif

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iNoteStyle", &curNoteSet.iNoteStyle);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iNoteDim", &curNoteSet.iNoteDim);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iNoteBarSet", &curNoteSet.noteopt[0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iNoteUpFmt", &curNoteSet.noteopt[1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "iNoteDnFmt", &curNoteSet.noteopt[2]);


	//   mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_numb", &curPos.bar.pnum);
	//   mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_diam", &curPos.bar.diam);
	//   mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_runmet", &curPos.bar.runmet);
	//   mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_rad", &iEmpty);
	//   mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_numpts", &curPos.bar.cnumpts);
	//   mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_term_beg", &curPos.bar.term[0]);
	//   mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_term_end", &curPos.bar.term[1]);
	//   mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_DOUBLE), "curPos_length", &curPos.bar.length);
	//   mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_pcatid", &curPos.pcatID);
	   //mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_refnum", &curPos.refnum);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_term_par0_beg", &curPos.bar.termPar[0][0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_term_par1_beg", &curPos.bar.termPar[1][0]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_term_par0_end", &curPos.bar.termPar[0][1]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_term_par1_end", &curPos.bar.termPar[1][1]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_hide", &curPos.drawopt[DROPT_A]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_trm_v", &curPos.drawopt[DROPT_V]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_trm_x", &curPos.drawopt[DROPT_X]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_trm_o", &curPos.drawopt[DROPT_O]);
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "curPos_trm_s", &curPos.drawopt[DROPT_S]);

	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_LONG), "ipnsave", &ipnsave);

	//mdlDialog_publishBasicVariable (setP, mdlCExpression_getType(TYPECODE_U_LONG), "ggnum", &(tcb->fbfdcn.gglk));

	// параметры отрисовки спецификации
	mdlDialog_publishBasicVariable(setP, mdlCExpression_getType(TYPECODE_DOUBLE), "trx", &dTextRightX);

	if (iDebug) sprintf(sLogMes, "_mdlDialog_publishBasicVariable() end...\n"); writeLog(0, 0);

	if (iDebug) sprintf(sLogMes, "_mdlDialog_hookPublish()\n"); writeLog(0, 0);
	mdlDialog_hookPublish(sizeof(uHooks) / sizeof(DialogHookInfo), uHooks);


	if (getCfgVarEx(v, L"REIN_TREAT_UPDATE_ELEMENT") == SUCCESS)
		iCfgVar_CbUpdateElement = STOI(v);
	else
		iCfgVar_CbUpdateElement = 1;


	WCH  vv[500];
	if (getCfgVar(vv, L("REIN_UPDATE_ELEMENT_SKIP_EVENTS")) == SUCCESS)
	{
		WCH seps[] = L(";");
		WCH* token;

		token = STOK(vv, seps);

		while (token)
		{
			int ii = STOI(token);

			if (ii > -1 && ii < 100) updevents[ii] = TRUE; // updevents[0]=1 - не вести лог в callbackUpdateElement

			token = STOK(NULL, seps);
		}
	}


	if (getCfgVar(vv, L("REIN_POS_SORT_PARAMETERS")) == SUCCESS)
	{
		WCH seps[] = L(";");
		WCH* token;

		token = STOK(vv, seps);

		while (token)
		{
			STRING str(token);

			possort.push_back(str);

			token = STOK(NULL, seps);
		}
	}



	if (iDebug) sprintf(sLogMes, "setting callbacks...()\n"); writeLog(0, 0);

#if defined (MSVERSION) && (MSVERSION == 0xa00) // callbacks
	SystemCallback::SetUnloadProgramFunction((SystemFunc_UnloadProgram)callbackUnloadProgram);
	mdlDialog_sendMessagesOnUnload(mdlSystem_getCurrMdlDesc(), TRUE);

	SystemCallback::SetNewDesignFileFunction((SystemFunc_NewDesignFile)callbackOpeningDgnFile);
	SystemCallback::SetModelChangeFunction((SystemFunc_ModelChange)callbackModelChanged);
	//ViewCallback::SetUpdatePreFunction((ViewFunc_Update)callbackViewUpdating);
	ViewCallback::SetUpdatePostFunction((ViewFunc_Update)callbackViewUpdating);
	//#if !defined (OBD)	
	if (iCfgVar_CbUpdateElement) ViewCallback::SetSubstituteElemFunction((ViewFunc_SubstituteElem)callbackUpdateElement);
	//#endif
	SystemCallback::SetReferenceAttachedFunction((SystemFunc_ReferenceAttached)callbackReferencAttached);
	SystemCallback::SetReferenceDetachedFunction((SystemFunc_ReferenceDetached)callbackReferenceDetached);
	SystemCallback::SetReferenceModifiedFunction((SystemFunc_ReferenceModified)callbackReferenceModified);
	SystemCallback::SetElmDscrCopyFunction((SystemFunc_ElmDscrCopy)callbackElmDscrCopy);
	SystemCallback::SetElmDscrToFileFunction((SystemFunc_ElmDscrToFile)callbackElmDscrToFile);
	ChangeTrackCallback::AddChangedFunction(callbackDgnFileChanged);
	//ChangeTrackCallback::AddXAttributeChangedFunction(callbackAttrChanged); // ECX
	ChangeTrackCallback::AddUndoRedoFunction(callbackDgnFileUndoRedo);
	LocateCallback::SetOverridePathDescriptionFunction(callbackProvideDescription);
	LocateCallback::SetGlobalPreLocateFunction((LocateFunc_LocateFilter)callbackLocateFilter);
	LocateCallback::SetElementDoubleClickFunction((LocateFunc_ElementDoubleClick)callbackElemDoubleClick);
	LocateCallback::SetSelectCmdFunction((Select_UserFunction)callbackSelectUserFunction);
	ViewCallback::SetMotionFunction((ViewFunc_Motion)callbackViewMotion);
	InputCallback::SetMessageReceivedFunction(callbackUserInput_receive);
	InputCallback::SetCommandFilterFunction((InputFunc_CommandFilter)callbackCommandFilter);
#else
	mdlSystem_setFunction(SYSTEM_UNLOAD_PROGRAM, callbackUnloadProgram);
	mdlSystem_setFunction(SYSTEM_NEW_DESIGN_FILE, callbackOpeningDgnFile);
	mdlSystem_setFunction(SYSTEM_MODEL_CHANGE, callbackModelChanged);
	mdlView_setFunction(UPDATE_PRE, callbackViewUpdating);	
	mdlView_setFunction(UPDATE_POST, callbackViewUpdating);
	if (iCfgVar_CbUpdateElement) mdlView_setSubstituteElemFunc((ViewFunc_SubstituteElem)callbackUpdateElement);
	//mdlSystem_setFunction(SYSTEM_MONITOR_VIEW_CMDS, callbackViewCommands);
	mdlSystem_setFunction(SYSTEM_REFERENCE_ATTACHED, callbackReferencAttached);
	//mdlSystem_setFunction(SYSTEM_REFERENCE_BEFOREWRITE, callbackReferenceBefModified);
	mdlSystem_setFunction(SYSTEM_REFERENCE_MODIFIED, callbackReferenceModified);
	mdlSystem_setFunction(SYSTEM_REFERENCE_DETACHED, callbackReferenceDetached);
	//mdlSystem_setFunction(SYSTEM_LEVEL_MASK_CACHE_CHANGE, callbackLevelMaskChange);
	mdlSystem_setFunction(SYSTEM_ELMDSCR_COPY, callbackElmDscrCopy);
	mdlSystem_setFunction(SYSTEM_ELMDSCR_TO_FILE, callbackElmDscrToFile);
	//mdlSystem_setTimerFunction (&timerHandle, 60, timerExpired, 0, TRUE);
	mdlChangeTrack_setFunction(CHANGE_TRACK_FUNC_Changed, callbackDgnFileChanged);
	mdlChangeTrack_setFunction(CHANGE_TRACK_FUNC_UndoRedo, callbackDgnFileUndoRedo);
	//mdlChangeTrack_setFunction(CHANGE_TRACK_FUNC_UndoRedoFinished, callbackDgnFileUndoRedoFinished);
	//mdlWindow_setFunction(WINDOW_MODIFYEVENTS, callbackWindowModify);
	mdlLocate_setFunction(LOCATE_PROVIDE_PATH_DESCRIPTION, callbackProvideDescription);
	//mdlLocate_setFunction (LOCATE_POSTLOCATE, callbackLocateFilter);
	mdlLocate_setFunction(LOCATE_GLOBAL_PRELOCATE, callbackLocateFilter);
	mdlLocate_setFunction(LOCATE_ELEMENT_DOUBLECLICK, callbackElemDoubleClick);
	//mdlLocate_setFunction (LOCATE_POSTLOCATE, callbackLocate);
	//mdlLocate_setFunction (LOCATE_ELEMENT_LOCATED , callbackElementLocated);
	mdlLocate_setFunction(LOCATE_SELECT_CMD, callbackSelectUserFunction);
	//mdlState_setFunction(STATE_COMMAND_CLEANUP, callbackCommandCleanup);
	mdlView_setFunction(VIEW_MOTION, callbackViewMotion);
	mdlInput_setFunction(INPUT_MESSAGE_RECEIVED, callbackUserInput_receive);
	mdlInput_setFunction(INPUT_COMMAND_FILTER, callbackCommandFilter);
#endif



	//mdlState_setFunction(STATE_RESET, callbackSendReset);

	//mdlInput_setFunction(INPUT_COMMAND_FILTER, stateFunc);

	if (iDebug) sprintf(sLogMes, "setting callbacks ok\n"); writeLog(0, 0);

	for (int i = 0; i < 8; i++) arViewPlanes[i].clear();
	//for (int i = 0; i < 8; i++) arViewDepth[i] = 0.;

	gvpt.reserve(100);

	//Bentley::Ustn::IViewManager::GetManager ().AddViewMonitor (&g_oViewMonitor);

	int bLoadAtStart = TRUE;

	if (getCfgVarEx(v, L"REIN_LOAD_MODEL_ON_OPEN_FILE") == SUCCESS)
		bLoadAtStart = STOI(v);
	else
		bLoadAtStart = TRUE;



	if (mdlModelRef_getActive() != INVALID_MODELREF)
	{

		getCatInfo(&curCat, ACTIVEMODEL, false);

		loadDBLaps();

		setDefaultStyles();

		checkThisFileIsModel(ACTIVEMODEL);

		if (bLoadAtStart)
		{
			//-----------------
			if (!bNoLoad)
				reloadCurBarsAll(iCfgVar_LoadRefsOnStart);
			//-----------------

#if defined (MSVERSION) && (MSVERSION == 0xa00)
			loadSchemaFile((elemCount > 0), L("ReinModel"));
#endif

			reloadHidingPositions();
			//updateHidePosArray(TRUE, -1);
		}

		syncShowInfo();


		//cmdDrawNodes(NULL);

		showLicense();

#if defined (STD_INTERFACE)

		if (rfHandle)
			mdlDialog_open(rfHandle, DIALOG_TOOLBOX);

		if (rfHandle) 
			mdlDialog_open(rfHandle, DLG_SKETCH);
#endif
	}


	//if (iCfgVar_PlotCopy)
	//{
	//	mdlView_setFunction(PLOTUPDATE_PRE, callbackViewPlot);
	//	mdlView_setFunction(PLOTUPDATE_POST, callbackViewPlot);
	//	mdlView_setFunction(PLOTUPDATE_PREINIT, callbackViewPlot);
	//	mdlView_setFunction(PLOTUPDATE_FINISHED, callbackViewPlot);
	//}

	//printf("kuku\n");


	//{
	//	int i;
	//	DPoint3d pp[2];
	//	ZeroMemory(pp, sizeof(pp));
	//	
	//	sprintf(sLogMes, "begin\n"); writeLog(0, 0);
	//	
	//	for (i = 0; i < 1000000; i++)
	//	{
	//	mdlLine_create(&el1, NULL, pp);
	//	}

	//	sprintf(sLogMes, "end\n"); writeLog(0, 0);
	//}


	writeLogOut(__FUNCTION__, "================ MAIN ===============");


#if defined (MSVERSION) && (MSVERSION == 0x8b0) // end of main
	return SUCCESS;
#endif
}
