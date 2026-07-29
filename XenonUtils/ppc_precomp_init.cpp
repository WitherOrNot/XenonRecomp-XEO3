#include "ppc_recomp_shared.h"
#include <windows.h>

#define VERSION 46

extern "C" IMAGE_DOS_HEADER __ImageBase;

__declspec(dllexport) extern "C" uintptr_t PrecompiledPointers[10] = {0};

__declspec(dllexport) extern "C" int InitPrecompiledDll(PPCFuncMapping** CodeMap, int64_t* ElemCount, uintptr_t** EmuSetupCallbacks, uint32_t* Info) {
    uintptr_t module_base = reinterpret_cast<uintptr_t>(&__ImageBase);

    for (int i = 0; i < HostFuncsCount; i++) {
        uintptr_t rva = reinterpret_cast<uintptr_t>(HostFuncs[i]) - module_base;
        PPCFuncMappings[i].host_rva = static_cast<uint32_t>(rva);
    }

    *CodeMap = PPCFuncMappings;
    *ElemCount = HostFuncsCount;
    Info[0] = 1;
    Info[1] = VERSION;

    // There is extra pointer setup blabla but not used? idk

    return VERSION;
}

__declspec(dllexport) extern "C" void CleanupPrecompiledDll() {

}
