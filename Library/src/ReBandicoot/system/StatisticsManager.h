#pragma once

#include <ReBandicoot/ig/Object.h>

// This class is unfinished and probably incorrect.

enum ECrashGameCollectibles
{
	eCGC_Crash_Collectibles1 = 0,
	eCGC_Crash_Collectibles2 = 1,
	eCGC_Crash_Collectibles3 = 2,
	eCGC_Crash_Collectibles_All = 3,
};

class CStatisticsManager : public igObject
{
public:
	enum EConstants
	{
		kMaxLeaderboardWrites = 20,
		kMaxKeyArchiveWrites = 75,
		kMaxConcurrentTasks = 2,
	};
private:
	/* +16 */ int64 unk10;
	/* +24 */ int64 unk18;
	/* +32 */ int64 unk20;
	/* +40 */ int64 unk28;
	/* +48 */ int64 unk30;
	/* +56 */ int64 unk38;
public:
	virtual void Func1(); // sub_7C5580
};