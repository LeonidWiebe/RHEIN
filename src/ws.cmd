rem rus code page - OEM 866

echo off


< reinvers.r (
  set /p VMAJ=
  set /p VMID=
  set /p VMIN=
)

if defined VS150COMNTOOLS GOTO m_v10
if defined VS160COMNTOOLS GOTO m_v10

:m_v8i

	set VAPP=8
	set VER_FILE_DESCR=Addin for AECOsim SELECTSeries 6 (x86)
	call reinvers.cmd %1
	
	echo +++++++++++++ AECOsim V8i ++++++++++++++++++++++
	
	if %1 == q (
	echo +++++++++++++ D  E  B  U  G +++++++++++++++++++++++
	bmake -ddebug reinsim8i -dAECOSIM
	echo +++++++++++++++++++++++++++++++
	) 
	
	if %1 == d (
	echo +++++++++++++ D  E  B  U  G +++++++++++++++++++++++
	bmake -a -ddebug reinsim8i -dAECOSIM
	echo +++++++++++++++++++++++++++++++
	) 
	
	if %1 == r (
	echo +++++++++++++ R E L E A S E  R U S ++++++++++++++++++
	bmake -a reinsim8i -dLANG_RU -dAECOSIM
	echo +++++++++++++++++++++++++++++++
	xcopy /y "%TF_PROGRAM_DIR%mdlapps\rein.dll" "..\bin\v8i (aecosim)\rus\rein.dll"
	xcopy /y "%TF_PROGRAM_DIR%mdlapps\rein.ma" "..\bin\v8i (aecosim)\rus\rein.ma"
	)
	
	if %1 == e (
	echo +++++++++++++ R E L E A S E  E N G ++++++++++++++++++
	bmake -a reinsim8i -dLANG_EN -dAECOSIM
	echo +++++++++++++++++++++++++++++++
	xcopy /y "%TF_PROGRAM_DIR%mdlapps\rein.dll" "..\bin\v8i (aecosim)\eng\rein.dll"
	xcopy /y "%TF_PROGRAM_DIR%mdlapps\rein.ma" "..\bin\v8i (aecosim)\eng\rein.ma"
	)
	
	echo +++++++++++++ 8.%VMAJ%.%VMID%.%VMIN% +++++++++++

	
	GOTO m_end
	
:m_v10
	
	set VAPP=10
	set VER_FILE_DESCR=Addin for OpenBuildings CONNECT (x64)
	call reinvers.cmd %1
	
if defined ABDSDK GOTO m_v10obd

echo *********** ABDSDK NOT DEFINED ***********
GOTO m_end

:m_v10obd

	set FDL="c:\Program Files\Bentley\OpenBuildings CONNECT Edition\OpenBuildingsDesigner\Mdlapps\rein.dll"
	set FMA="c:\Program Files\Bentley\OpenBuildings CONNECT Edition\OpenBuildingsDesigner\Mdlapps\rein.ma"

	echo @@@@@@@@@@@ OPENBUILDINGS CONNECT @@@@@@@@@@@@@@@@@@@
	
	if %1 == q (
	echo +++++++++++++ D  E  B  U  G +++++++++++++++++++++++
	bmake -ddebug reinsim -dAECOSIM
	echo +++++++++++++++++++++++++++++++
	) 
	
	if %1 == d (
	echo +++++++++++++ D  E  B  U  G +++++++++++++++++++++++
	bmake -a -ddebug reinsim -dAECOSIM
	echo +++++++++++++++++++++++++++++++
	) 
	
	if %1 == r (
	echo +++++++++++++ R E L E A S E  R U S ++++++++++++++++++
	bmake -a reinsim -dLANG_RU -dAECOSIM
	echo +++++++++++++++++++++++++++++++
	xcopy /y %FDL% "..\bin\v10 (obd)\rus\rein.dll"
	xcopy /y %FMA% "..\bin\v10 (obd)\rus\rein.ma"
	)
	
	if %1 == e (
	echo +++++++++++++ R E L E A S E  E N G ++++++++++++++++++
	bmake -a reinsim -dLANG_EN -dAECOSIM
	echo +++++++++++++++++++++++++++++++
	xcopy /y %FDL% "..\bin\v10 (obd)\eng\rein.dll"
	xcopy /y %FMA% "..\bin\v10 (obd)\eng\rein.ma"
	)
	
	echo @@@@@@@@@@@ 10.%VMAJ%.%VMID%.%VMIN% @@@@@@@@@@@@@
	
:m_end

