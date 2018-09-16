#pragma once

#include "RefMetaField.h"
#include "ObjectRefMetaField.h"

// sizeof: 88
class NOVTABLE igHandleMetaField : public igRefMetaField
{
private:
	/* +80 (50h) */ igObjectRefMetaField *_metaObject;
public:

};