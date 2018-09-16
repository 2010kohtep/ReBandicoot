#pragma once

#include <Windows.h>

#include "../Object.h"

// sizeof: 72
class NOVTABLE igMetaField : public igObject
{
private:
	/* +16 (10h) */ int16 _parentMetaObjectIndex;
	/* +18 (12h) */ int16 _typeIndex;
	/* +20 (14h) */ int16 _internalIndex;
	/* +22 (16h) */ int16 _size;
	/* +24 (18h) */ int16 _offset; // int64?
	/* +32 (20h) */ int64 _attributes;
	/* +40 (28h) */ int64 _properties;
	/* +48 (30h) */ int64 _fieldName;
	/* +56 (38h) */ int64 _default;

	/* +64 (40h) */ int64 __ALIGN;
public:

};