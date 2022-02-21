@echo off
@echo VICP Toolset: Generate target file in S19 format.
@echo Step #1:Clean old files...


cd ..\Tools

if not exist ".\SWPackage" goto NEXTSTEP
rmdir /S /Q  SWPackage

:NEXTSTEP
mkdir SWPackage

@echo Step #2:copy original file...

copy  ..\obj\vicp.elf  SWPackage
copy  ..\obj\vicp.map  SWPackage
REM  debug symbol table 
copy  ..\obj\vicp.dnm  SWPackage
REM  archive of the .dbo files associated with target which ocntains debug data
copy  ..\obj\vicp.dla  SWPackage

if not exist "..\obj\vicp.run" goto AFTER_GEN_TARGET
REM  copy s19 file 
@echo Step #3:Generate bin file and convert it to S19 format... 
copy  ..\obj\vicp.run  SWPackage\vicp.s19

:AFTER_GEN_TARGET
cd SWPackage

if not exist "..\..\OUT" goto CREATEFOLDER
goto COPYFILE


:CREATEFOLDER
mkdir ..\..\OUT
goto COPYFILE

:COPYFILE

copy /Y  *.*  ..\..\OUT

REM go back to tools
cd ..
rmdir /S /Q  SWPackage

@echo Step #4:Generate upgrade file
cd ..\OUT
del *.bin

s19_convert.exe vicp.s19 vicp.bin 255 190 0x00000
MD5_Checksum.exe 0x200000
s19_convert.exe vicp.s19 vic.bin 255 190 0x18000
MD5_Checksum.exe 0x1E8000

cd ../Tools
call FillS19.exe ..\OUT\vic.bin tmp.s19
call FillStr.bat
call Hexview\hexview.exe /s tmp.s19 /CS9:@append /XS:190:2 -o ..\OUT\vic_can.s19
del FillStr.bat
del tmp.S19

@echo SW package generation process is completed successfully!

goto END

:ABORT
@echo SW package generation process is aborted!

:END
@echo on



