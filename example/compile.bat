:: Example script to compile final DLL
del *.obj
del *.dll
del *.exp
del *.lib
clang-cl /c /arch:AVX /clang:-Wno-c++17-extensions /Oy /O2 *.cpp
clang-cl /LD /Fe:xeo3_1364c05e_b07f172d_ca301585_cd1c07d5_b2ee9c30.dll *.obj