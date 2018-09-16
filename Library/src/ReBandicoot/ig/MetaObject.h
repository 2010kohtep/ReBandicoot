#pragma once

#include "BaseMeta.h"

// I don't like that fields offsets are not in sequential order in this class,
// but size of class is definitely correct. Variables order is needs to be
// carefully validated.

// sizeof: 152
class NOVTABLE igMetaObject : public igBaseMeta
{
private:
	/* + (18h) */ int64 _metaFields;

	/* + (20h) */ int64 __ALIGN[2];

	/* + (30h) */ int64 _instanceCount;
	/* + (38h) */ int64 _vTablePointer;
	/* + (40h) */ int64 _parent;
	/* + (48h) */ int64 _lastChild;
	/* + (50h) */ int64 _nextSibling;

	/* + (58h) */ int16 _index;
	/* + (5Ah) */ int16 _sizeofSize;
	/* + (5Ch) */ int16 _properties;
	/* + (5Eh) */ int16 _requiredAlignment;
	/* + (60h) */ int16 _dynamicFieldSize;

	/* + (62h) */ int64 _requiredDynamicFieldAlignment;
	/* + (68h) */ int64 _metaFunctions;
	/* + (80h) */ int64 _attributes;
	/* + (88h) */ int64 _library;
	/* + (90h) */ int64 _id;
public:
	virtual void Func1();    // sub_E50D10

	virtual int64 Func8();    // sub_E13100

	virtual void Func21();   // sub_E03380
	virtual BOOL64 Func22(); // sub_DD45A0
	virtual bool Func23();   // sub_DD7CF0
};