@echo off

xcopy D:\SV\SV1\*.cpp D:\BaiNop
xcopy D:\SV\SV2\*.cpp D:\BaiNop
xcopy D:\SV\SV3\*.cpp D:\BaiNop
xcopy D:\SV\SV4\*.cpp D:\BaiNop
xcopy D:\SV\SV5\*.cpp D:\BaiNop
...
xcopy D:\SV\SV?\*.cpp D:\BaiNop

del D:\SV\SV1\*.cpp
del D:\SV\SV2\*.cpp
del D:\SV\SV3\*.cpp
del D:\SV\SV4\*.cpp
del D:\SV\SV5\*.cpp
...

del D:\SV\SV?\*.cpp
exit