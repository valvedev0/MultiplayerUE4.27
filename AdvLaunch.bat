@echo off
setlocal

:: ==========================================================
:: CONFIGURATION
:: ==========================================================

:: 1. Engine Path
set "UE4_EXE=C:\Program Files\Epic Games\UE_4.27\Engine\Binaries\Win64\UE4Editor.exe"

:: 2. Project Path (Auto-detect)
for %%f in (*.uproject) do set "PROJECT_PATH=%~dp0%%f"
:: set "PROJECT_PATH=C:\Users\nitro v\work\GithubRepos\MultiplayerUE4.27\PuzzleMP.uproject"

:: 3. Window Settings (Smaller windows for multi-instance view)
set "WIN_SINGLE=-windowed -ResX=1280 -ResY=720"
set "WIN_MULTI=-windowed -ResX=900 -ResY=600"

:: ==========================================================
:: MENU SELECTION
:: ==========================================================
:MENU
cls
echo ========================================================
echo   UNREAL ENGINE 4.27 LAUNCHER - PuzzleMP
echo ========================================================
echo.
echo   SINGLE PLAYER / UTILITY:
echo   1. Standalone Game (Steam Enabled)
echo   2. Standalone Game (NO STEAM / LAN Mode)
echo   3. Dedicated Server Only
echo   4. Client Only (Connect to Localhost)
echo.
echo   MULTI-INSTANCE TESTING (LAN ONLY):
echo   5. Host + 1 Client (Listen Server Test)
echo   6. Dedicated Server + 2 Clients
echo.
set /p MODE="> Select Option (1-6): "

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

if "%LOG%"=="1" set "LOG_CMD="
if "%LOG%"=="2" set "LOG_CMD=-LogCmds=\"LogNet Verbose, LogOnline Verbose\""
if "%LOG%"=="3" set "LOG_CMD=-LogCmds=\"LogOnline VeryVerbose, LogSteamShared Verbose, LogNet Verbose\""

:: Jump to option
if "%MODE%"=="1" goto RUN_GAME
if "%MODE%"=="2" goto RUN_NOSTEAM
if "%MODE%"=="3" goto RUN_SERVER
if "%MODE%"=="4" goto RUN_CLIENT
if "%MODE%"=="5" goto RUN_MULTI_LISTEN
if "%MODE%"=="6" goto RUN_MULTI_DEDICATED

goto MENU

:: ==========================================================
:: EXECUTION COMMANDS
:: ==========================================================

:RUN_GAME
echo Launching Standalone with Steam...
"%UE4_EXE%" "%PROJECT_PATH%" -game -log %WIN_SINGLE% %LOG_CMD%
goto END

:RUN_NOSTEAM
echo Launching without Steam (LAN Mode)...
"%UE4_EXE%" "%PROJECT_PATH%" -game -log -NOSTEAM %WIN_SINGLE% %LOG_CMD%
goto END

:RUN_SERVER
echo Launching Dedicated Server...
"%UE4_EXE%" "%PROJECT_PATH%" -server -log %LOG_CMD%
goto END

:RUN_CLIENT
echo Launching Client...
"%UE4_EXE%" "%PROJECT_PATH%" 127.0.0.1 -game -log %WIN_SINGLE% %LOG_CMD%
goto END

:RUN_MULTI_LISTEN
echo.
echo Starting HOST (Left Window)...
start "Host" "%UE4_EXE%" "%PROJECT_PATH%" /Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen -game -log -NOSTEAM %WIN_MULTI% -WinX=0 -WinY=50 %LOG_CMD%
timeout /t 4 >nul
echo Starting CLIENT (Right Window)...
start "Client" "%UE4_EXE%" "%PROJECT_PATH%" 127.0.0.1 -game -log -NOSTEAM %WIN_MULTI% -WinX=920 -WinY=50 %LOG_CMD%
goto END

:RUN_MULTI_DEDICATED
echo.
echo Starting DEDICATED SERVER...
start "Server" "%UE4_EXE%" "%PROJECT_PATH%" -server -log %LOG_CMD%
timeout /t 4 >nul
echo Starting CLIENT 1 (Left)...
start "Client1" "%UE4_EXE%" "%PROJECT_PATH%" 127.0.0.1 -game -log -NOSTEAM %WIN_MULTI% -WinX=0 -WinY=50 %LOG_CMD%
timeout /t 2 >nul
echo Starting CLIENT 2 (Right)...
start "Client2" "%UE4_EXE%" "%PROJECT_PATH%" 127.0.0.1 -game -log -NOSTEAM %WIN_MULTI% -WinX=920 -WinY=50 %LOG_CMD%
goto END

:END
echo.
echo Commands sent. Closing launcher...
timeout /t 3