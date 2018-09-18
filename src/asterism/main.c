#include <stdio.h>
#include <assert.h>
#ifdef WIN32
#define _CRTDBG_MAP_ALLOC
#include <windows.h>
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "test/asterism_test01.h"
#include "test/asterism_test02.h"

//target_link_libraries(uv advapi32 iphlpapi psapi userenv shell32 ws2_32)
int main(int argc, char const *argv[])
{
#ifdef WIN32
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
#endif
    assert(0 == asterism_test01());
    assert(0 == asterism_test02());
#if defined(WIN32)
    assert(_CrtDumpMemoryLeaks() == 0);
#endif
    return 0;
}