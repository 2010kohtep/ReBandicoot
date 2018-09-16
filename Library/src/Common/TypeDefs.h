#pragma once

#include <Windows.h>

typedef __int8  int8;
typedef __int16 int16;
typedef __int32 int32;
typedef __int64 int64;

typedef int64 BOOL64;

// non-pure, but just empty (body is {})
#define NOBODY

// no virtual table (for debug purposes)
#define NOVTABLE __declspec(novtable)

#ifdef DEBUG
	#define private public
#endif