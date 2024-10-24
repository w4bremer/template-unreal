
@Echo off
SET script_path=%~dp0
echo Script is in %script_path:~0,-1%

@REM Check for UAT
setlocal enableDelayedExpansion
for %%i in (RunUAT.bat) do (
    set "RunUAT_path=%%~$PATH:i" 
)
if not defined RunUAT_path (
	echo RunUAT.bat needs to be in the PATH environment variable
	exit /b 1
)
echo RunUAT.bat found at %RunUAT_path:~0,-11%

@REM Retrive UE path and test for plugins folder
set UE_path=%RunUAT_path:~0,-28%
if exist "%UE_path%\" (
	echo UE installation found at %UE_path%
) else (
	echo Was not able to find UE installation at %UE_path%
	exit /b 1
)
set UEplugins_path=%UE_path%\Plugins
if exist "%UEplugins_path%\" (
	echo UE plugins found at %UEplugins_path%
) else (
	echo Was not able to find UE plugins at %UEplugins_path%
	exit /b 1
)

@REM Check for existing ApiGear plugin
set ApiGearPluginTarget_path=%UEplugins_path%\Marketplace\ApiGear
set RestoreApiGearPlugin=0
if exist "%ApiGearPluginTarget_path%\" (
	echo Existing ApiGear plugin found at %ApiGearPluginTarget_path%
	move "%ApiGearPluginTarget_path%" "%UEplugins_path%\..\ApiGearBackUp" >nul
	if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
	set "RestoreApiGearPlugin=1"
)

@REM Build ApiGear plugin
call :buildUEplugin "%script_path%\Plugins\ApiGear\ApiGear.uplugin" , "%script_path%build\Plugins\ApiGear"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM copy ApiGear plugin to UE installation for use by other plugins
xcopy /E /Y "%script_path%build\Plugins\ApiGear" "%ApiGearPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 call :cleanup %ERRORLEVEL%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM Building and testing Testbed2 module
call :buildUEplugin "%script_path%\Plugins\Testbed2\Testbed2.uplugin" , "%script_path%build\Plugins\Testbed2"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing TbEnum module
call :buildUEplugin "%script_path%\Plugins\TbEnum\TbEnum.uplugin" , "%script_path%build\Plugins\TbEnum"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing TbSame1 module
call :buildUEplugin "%script_path%\Plugins\TbSame1\TbSame1.uplugin" , "%script_path%build\Plugins\TbSame1"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing TbSame2 module
call :buildUEplugin "%script_path%\Plugins\TbSame2\TbSame2.uplugin" , "%script_path%build\Plugins\TbSame2"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing TbSimple module
call :buildUEplugin "%script_path%\Plugins\TbSimple\TbSimple.uplugin" , "%script_path%build\Plugins\TbSimple"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing Testbed1 module
call :buildUEplugin "%script_path%\Plugins\Testbed1\Testbed1.uplugin" , "%script_path%build\Plugins\Testbed1"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!


call :cleanup 0
exit /b 0

@REM function implementations

@REM build UE plugin
:buildUEplugin
(
	"%RunUAT_path%" BuildPlugin -verbose -Rocket -Plugin=%~1 -TargetPlatforms=Win64 -StrictIncludes -Package=%~2
	set buildresult=!ERRORLEVEL!
)
exit /b %ERRORLEVEL%

@REM Clean up ApiGear plugin installation
:cleanup
if %RestoreApiGearPlugin% equ 1 (
	echo Restoring old ApiGear plugin in UE installation
	@RD /S /Q "%ApiGearPluginTarget_path%"
	move "%UEplugins_path%\..\ApiGearBackUp" "%ApiGearPluginTarget_path%" >nul
	if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
) else (
	echo Deleting temporary ApiGear plugin installation from UE
	@RD /S /Q "%ApiGearPluginTarget_path%"
	if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
)
exit /b %~1
