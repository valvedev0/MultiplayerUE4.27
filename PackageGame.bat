@echo off
setlocal

:: ==========================================================
:: 1. PATH CONFIGURATION
:: ==========================================================

:: Path to the Automation Tool (RunUAT.bat) inside your Engine folder
set "UAT_PATH=C:\Program Files\Epic Games\UE_4.27\Engine\Build\BatchFiles\RunUAT.bat"

:: Automatically find the .uproject file in the current directory
for %%f in (*.uproject) do set "PROJECT_PATH=%~dp0%%f"

:: Output Directory (Will create a "Builds" folder inside your project folder)
set "ARCHIVE_PATH=%~dp0Builds"

:: ==========================================================
:: 2. PACKAGING SETTINGS
:: ==========================================================

:: Configuration: Development (Keeps logs/console enabled), Shipping (Removes logs, higher FPS)
set CONFIG=Development

:: Platform: Win64
set PLATFORM=Win64

echo ========================================================
echo   PACKAGING PROJECT: PuzzleMP
echo ========================================================
echo   Engine:   UE 4.27
echo   Config:   %CONFIG%
echo   Output:   %ARCHIVE_PATH%
echo ========================================================
echo.

:: ==========================================================
:: 3. EXECUTE UAT COMMAND
:: ==========================================================

:: This is the "Magic Command" that builds, cooks, stages, and packages the game.
call "%UAT_PATH%" BuildCookRun ^
-project="%PROJECT_PATH%" ^
-noP4 -clientconfig=%CONFIG% -serverconfig=%CONFIG% ^
-nocompileeditor -utf8output ^
-platform=%PLATFORM% -targetplatform=%PLATFORM% ^
-build -cook -stage -package -archive -archivedirectory="%ARCHIVE_PATH%"

:: ==========================================================
:: 4. FINISH
:: ==========================================================

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    echo   PACKAGING FAILED! CHECK LOGS ABOVE.
    echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo ========================================================
echo   SUCCESS! BUILD SAVED TO:
echo   %ARCHIVE_PATH%\WindowsNoEditor
echo ========================================================
echo.
pause