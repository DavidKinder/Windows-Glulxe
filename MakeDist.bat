@echo off

"%ProgramFiles(x86)%\Zip\zip" -j \Temp\WinGlulxe.zip Release\*.*
"%ProgramFiles(x86)%\Zip\zip" -r \Temp\WinGlulxeSrc.zip Win Installer
"%ProgramFiles(x86)%\Zip\zip" \Temp\WinGlulxeSrc.zip Generic\*.c Generic\*.h

pushd Installer
"%ProgramFiles(x86)%\NSIS\makensis" WinGlulxe.nsi
move *.exe \Temp
popd
