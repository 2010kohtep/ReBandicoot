#pragma once

#include <Common/TypeDefs.h>

// Looks like all classes (or not) in this game engine that were
// created with "InitObject" constructor (function that takes class name,
// I just named it like that) consists some data in the begin of itselfs 
// and it's size is 48 (30h), and only after that "__internalObjectBase" 
// classes are coming.

class NOVTABLE __internalObjectBase
{
private:
	/* +0 */ /* void *_vptr; */
	/* +8 */ int64 refCount;
public:
	virtual void Func1();                         // sub_E53520, kind of getInstance method?
	virtual void Func2(void *a2);                 // sub_DF4720
	NOBODY virtual void Func3();
	NOBODY virtual void Func4();
	NOBODY virtual void Func5();
	NOBODY virtual void Func6();
	NOBODY virtual void Func7(int8 a1);
	NOBODY virtual int64 Func8();
	NOBODY virtual void Func9();
	virtual void Func10();                        // sub_DFAA10
	NOBODY virtual void Func11();
	NOBODY virtual void Func12();
	NOBODY virtual void Func13();
	NOBODY virtual void Func14();
	NOBODY virtual void Func15();
	virtual void Func16(__int64 *a1, __int64 a2); // sub_DDC5A0
	virtual void Func17(__int64 a1);              // sub_DFE060
	virtual BOOL64 Func18(__int64 a1);            // sub_DFE490
	virtual void Func19();                        // sub_E54AE0, returns 1 in this class
	virtual void Func20();                        // sub_DD8030
};