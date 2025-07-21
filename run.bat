@echo off
run.bat
IF %ERRORLEVEL% EQU 0 {
    build/KARTGAME.exe
}
