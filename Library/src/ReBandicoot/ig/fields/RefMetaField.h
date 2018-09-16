#pragma once

#include "MetaField.h"

// sizeof: 80
class NOVTABLE igRefMetaField : public igMetaField
{
private:
	/* +72 (48h) */ int8 _construct;
	/* +73 (49h) */ int8 _destruct;
	/* +74 (4Ah) */ int8 _reconstruct;
	/* +75 (4Bh) */ int8 _refCounted;
public:

};