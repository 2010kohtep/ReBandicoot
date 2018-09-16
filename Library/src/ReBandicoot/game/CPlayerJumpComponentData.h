#pragma once

#include "CEntityComponentData.h"

#include <Windows.h>

enum EPlayerJumpControl : int
{
	ePJC_Velocity = 0,
	ePJC_Curve = 1,
};

// I tried to understand how to activate double-jump ability,
// but all manipulation with this class have been unsuccessful.
// Maybe I'm missing something...

// sizeof: 1680
class CPlayerJumpComponentData : public CEntityComponentData
{
private:
	int8 align[1552];

	int64 _doubleJumpEnabled; // 21 from end (1576 offset)
};