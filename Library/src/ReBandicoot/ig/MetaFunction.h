#pragma once

#include "Object.h"

// sizeof: 80
class NOVTABLE igMetaFunction : public igObject
{
private:
	/* +16 (10h) */ int64 _functionName;
	/* +24 (18h) */ int64 _functionPointer;

	/* +32 (20h) */ int64 __ALIGN[3];

	/* +56 (38h) */ int64 _attributes;
	/* +64 (40h) */ int64 _parameters;
	/* +72 (48h) */ int64 _properties;
public:

};