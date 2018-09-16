#pragma once

#include "GameVariable.h"

// TODO: Delegates

using COnGameBoolVariableChangedDelegate = void *;
using COnGameBoolVariableChangeEventList = void *;

class CGameBoolVariable : public CGameVariable
{
private:
	/* +24 */ int64 _defaultValue;
	/* +32 */ COnGameBoolVariableChangedDelegate *_onGameBoolVariableChanged;
	/* +40 */ COnGameBoolVariableChangeEventList *_onGameBoolVariableChangedEventList;
};