#pragma once

#include "Object.h"

class NOVTABLE igBaseMeta : public igObject
{
private:
	int64 _name;
public:
	virtual void Func1(); // sub_E50B80

	NOBODY virtual void Func21();
};