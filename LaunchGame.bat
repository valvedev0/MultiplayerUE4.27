@echo off
setlocal

:: ==========================================================
:: CONFIGURATION
:: ==========================================================

:: 1. Engine Path (Using your specific path)
set "UE4_EXE=C:\Program Files\Epic Games\UE_4.27\Engine\Binaries\Win64\UE4Editor.exe"

:: 2. Project Path (Automatically gets the uproject file in the current folder)
::    This makes the script portable if you move the folder.
for %%f in (*.uproject) do set "PROJECT_PATH=%~dp0%%f"

:: If no uproject is found automatically, uncomment and set manually:
:: set "PROJECT_PATH=C:\Users\nitro v\work\GithubRepos\MultiplayerUE4.27\PuzzleMP.uproject"

:: 3. Window Settings
set "WINDOW_ARGS=-windowed -ResX=1280 -ResY=720"

:: ==========================================================
:: MENU SELECTION
:: ==========================================================
:MENU
cls
echo ========================================================
echo   UNREAL ENGINE 4.27 LAUNCHER - PuzzleMP
echo ========================================================
echo.
echo   SELECT LAUNCH MODE:
echo   1. Standalone Game (Steam Enabled)
echo   2. Standalone Game (NO STEAM / LAN Mode)
echo   3. Dedicated Server
echo   4. Client (Connect to Localhost)
echo.
set /p MODE="> Select Option (1-4): "

echo.
echo   SELECT LOGGING LEVEL:
echo   1. Default (Warnings Only)
echo   2. Network Debug (LogNet Verbose)
echo   3. Deep Steam Debug (Online + Steam Verbose)
echo.
set /p LOG="> Select Option (1-3): "

:: ==========================================================
:: LOGIC
:: ==========================================================

:: Set Log Arguments based on selection
if "%LOG%"=="1" set "LOG_CMD="
if "%LOG%"=="2" set "LOG_CMD=-LogCmds=\"LogNet Verbose, LogOnline Verbose\""
if "%LOG%"=="3" set "LOG_CMD=-LogCmds=\"LogOnline VeryVerbose, LogSteamShared Verbose, LogNet Verbose\""

:: Run the selected Mode
if "%MODE%"=="1" goto RUN_GAME
if "%MODE%"=="2" goto RUN_NOSTEAM
if "%MODE%"=="3" goto RUN_SERVER
if "%MODE%"=="4" goto RUN_CLIENT

goto MENU

:: ==========================================================
:: EXECUTION COMMANDS
:: ==========================================================

:RUN_GAME
echo Launching Standalone with Steam...
"%UE4_EXE%" "%PROJECT_PATH%" -game -log %WINDOW_ARGS% %LOG_CMD%
goto END

:RUN_NOSTEAM
echo Launching without Steam (LAN Mode)...
"%UE4_EXE%" "%PROJECT_PATH%" -game -log -NOSTEAM %WINDOW_ARGS% %LOG_CMD%
goto END

:RUN_SERVER
echo Launching Dedicated Server...
"%UE4_EXE%" "%PROJECT_PATH%" -server -log %LOG_CMD%
goto END

:RUN_CLIENT
echo Launching Client...
"%UE4_EXE%" "%PROJECT_PATH%" 127.0.0.1 -game -log %WINDOW_ARGS% %LOG_CMD%
goto END

:END
echo.
echo Launch command sent. Closing launcher...
timeout /t 3