#pragma once

#define Export
namespace hazel {
#ifdef Export
	__declspec(dllexport) void EntryTest();
#elif
	__declspec(dllimport) void EntryTest();
#endif

}