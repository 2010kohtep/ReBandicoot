#pragma once

#include "Object.h"

#include <Windows.h>

class NOVTABLE igComponentData : public igObject
{
private:
	struct
	{
		int64 _isEnabled : 1;
		int64 _isThreadSafe : 1;
	} _bitfield; // Is it correct implementation?

public:

};