#pragma once

#include "MetaField.h"

// sizeof: 96
class NOVTABLE igStructMetaField : public igMetaField
{
private:
	int64 _typeSize;
	int64 _cppConstructor;
	int64 _cppDestructor;
public:

};