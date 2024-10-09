@echo off
goto banner

:banner
echo.
echo  *****************************************
echo  *             Nebula Engine              *
echo  *            by Robert Randel            *
echo  *   10/07/2024 ^(c) All Rights Reserved   *
echo  *****************************************
echo.

:: Return to the main script
pushd "%~dp0\.."

if not exist "vendor\premake\premake5.exe" (
    color 0C
    echo Error: premake5.exe not found in vendor\premake.
    popd
    pause
    exit /b 1
)

echo Running premake5 to generate Visual Studio 2022 project files...
call "vendor\premake\premake5.exe" vs2022

if errorlevel 1 (
    color 0C
    echo Error: premake5 failed to generate project files.
) else (
    color 0A
    echo Success: Project files generated.
)

popd
pause
