#pragma once

#include <ReBandicoot/ig/Object.h>

// TODO: Virtual table

enum EGameVariableLifetime : int32
{
	eGVL_Saved = 0,
	eGVL_Session = 1,
	eGVL_Level = 2,
};

class NOVTABLE CGameVariable : public igObject
{
private:
	/* +24 */ int32 _variableLifetime;
	/* +28 */ int8 _replicated;
	/* +29 */ int8 _triggerAutoSave;
public:
	
};