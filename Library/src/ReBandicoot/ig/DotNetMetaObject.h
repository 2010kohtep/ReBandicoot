#pragma once

#include <Windows.h>

#include "MetaObject.h"

// I'm not sure, but I think "__internalObjectBase" classes are
// exist in this class as subclass or something.

class NOVTABLE igDotNetMetaObject : public igMetaObject
{
private:
	/* +152 */ int64 _methods;
	/* +160 */ int64 _interfaces;
	/* +168 */ int64 _vTable;
	/* +176 */ int64 _boundMeta;
	/* +184 */ int64 _patchMeta;
	/* +192 */ int64 _dotNetFieldNames;

	/* +200 */ int64 _cppFieldNames;
	/* +208 */ int64 _exposedFieldCount;
	/* +216 */ int64 _cppMethods;
	/* +224 */ int64 _cppMethodNames;
	/* +232 */ int64 _cppMethodCount;
	/* +240 */ int64 _bindings;
public:

};