#pragma once

#include "RefMetaField.h"
#include "..\DotNetMetaObject.h"

// sizeof: 88
class NOVTABLE igObjectRefMetaField : public igRefMetaField
{
private:
	/* +80 (50h) */ igDotNetMetaObject *_metaObject;
public:

};