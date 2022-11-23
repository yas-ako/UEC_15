@echo off
.\test.exe
cd D:\Works\Projects\117_C\UEC_15\img
D:\ProgramFile\ImageMagick-7.1.0-portable-Q16-HDRI-x64/convert.exe -delay 5 img*.ppm out.gif
@REM D:\ProgramFile\ImageMagick-7.1.0-portable-Q16-HDRI-x64/convert.exe -delay 3 D:\Works\Projects\117_C\UEC_15\img\img*.ppm out.mp4
copy /y out.gif ..\gif\
copy /y out.mp4 ..\gif\
code D:\Works\Projects\117_C\UEC_15\gif\out.gif
cd D:\Works\Projects\117_C\UEC_15\src
echo copied