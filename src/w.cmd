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
	set VER_FILE_DESCR=Addin for MicroStation V8i (x86)
	call reinvers.cmd %1
	
	echo +++++++++++++ MICROSTATION V8i ++++++++++++++++++++++
	
	if %1 == q (
	echo +++++++++++++ D  E  B  U  G +++++++++++++++++++++++
	bmake -ddebug rein8i
	echo +++++++++++++++++++++++++++++++
	) 
	
	if %1 == d (
	echo +++++++++++++ D  E  B  U  G +++++++++++++++++++++++
	bmake -a -ddebug rein8i
	echo +++++++++++++++++++++++++++++++
	) 
	
	if %1 == dd (
	echo +++++++++++++ D  E  B  U  G +++++++++++++++++++++++
	bmake -ddebug rein8i
	echo +++++++++++++++++++++++++++++++
	) 
	
	if %1 == r (
	echo +++++++++++++ R E L E A S E  R U S ++++++++++++++++++
	bmake -a rein8i -dLANG_RU
	echo +++++++++++++++++++++++++++++++
	echo +++++ ŠŽˆŽ‚€ˆ… ‚ BIN +++++++
	echo +++++++++++++++++++++++++++++++
	xcopy /y "c:\Program Files (x86)\Bentley\MicroStation V8i (SELECTseries)\MicroStation\mdlapps\rein.dll" "..\bin\v8i\rus\rein.dll"
	xcopy /y "c:\Program Files (x86)\Bentley\MicroStation V8i (SELECTseries)\MicroStation\mdlapps\rein.ma" "..\bin\v8i\rus\rein.ma"
	)
	
	if %1 == e (
	echo +++++++++++++ R E L E A S E  E N G ++++++++++++++++++
	bmake -a rein8i -dLANG_EN
	echo +++++++++++++++++++++++++++++++
	echo +++++ COPYING TO BIN +++++++
	echo +++++++++++++++++++++++++++++++
	xcopy /y "c:\Program Files (x86)\Bentley\MicroStation V8i (SELECTseries)\MicroStation\mdlapps\rein.dll" "..\bin\v8i\eng\rein.dll"
	xcopy /y "c:\Program Files (x86)\Bentley\MicroStation V8i (SELECTseries)\MicroStation\mdlapps\rein.ma" "..\bin\v8i\eng\rein.ma"
	)
	
	echo +++++++++++++ 8.%VMAJ%.%VMID%.%VMIN% +++++++++++

	
	GOTO m_end
	
:m_v10
	
	set VAPP=10
	set VER_FILE_DESCR=Addin for MicroStation CONNECT (x64)
	call reinvers.cmd %1
	
if defined ABDSDK GOTO m_v10obd

	echo ============= MICROSTATION CONNECT ====================
	
	if %1 == q (
	echo ============= D   E   B   U   G =====================
	bmake -ddebug rein
	) 
	
	if %1 == d (
	echo ============= D   E   B   U   G =====================
	bmake -a -ddebug rein
	) 
	
	if %1 == dd (
	echo ============= D   E   B   U   G =====================
	bmake -ddebug rein
	) 
	
	if %1 == r (
	echo ============= R E L E A S E  R U S ==================
	bmake -a rein -dLANG_RU
	echo =================================
	echo ===== ŠŽˆŽ‚€ˆ… ‚ BIN =====
	echo =================================
	xcopy /y "c:\Program Files\Bentley\MicroStation CONNECT Edition\MicroStation\Mdlapps\rein.dll" "..\bin\v10\rus\rein.dll"
	xcopy /y "c:\Program Files\Bentley\MicroStation CONNECT Edition\MicroStation\Mdlapps\rein.ma" "..\bin\v10\rus\rein.ma"
	)
	
	if %1 == e (
	echo ============= R E L E A S E  E N G ==================
	bmake -a rein -dLANG_EN
	echo =================================
	echo ===== COPYING TO BIN =====
	echo =================================
	xcopy /y "c:\Program Files\Bentley\MicroStation CONNECT Edition\MicroStation\Mdlapps\rein.dll" "..\bin\v10\eng\rein.dll"
	xcopy /y "c:\Program Files\Bentley\MicroStation CONNECT Edition\MicroStation\Mdlapps\rein.ma" "..\bin\v10\eng\rein.ma"
	)
	
	echo =========== 10.%VMAJ%.%VMID%.%VMIN% =============
	GOTO m_end

:m_v10obd

	echo @@@@@@@@@@@ for OPENBUILDINGS CONNECT use command ws @@@@@@@@@@@@@@@@@@@
	


	
:m_end

