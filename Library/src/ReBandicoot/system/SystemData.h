#pragma once

#include <ReBandicoot/ig/Singleton.h>
#include <ReBandicoot/game/GameBoolVariable.h>

class NOVTABLE CCrashBandicootSystemData : public igSingleton
{
private:
	/* +16 */  int64 _crash1Hub;
	/* +24 */  int64 _crash2Hub;
	/* +32 */  int64 _crash3Hub;

	/* +40 */  int32 _deathRatingOne;
	/* +44 */  int32 _deathRatingTwo;
	/* +48 */  int32 _deathRatingThree;

	/* +56  */ CGameBoolVariable *_superChargedBodySlamGameVariable;
	/* +64  */ CGameBoolVariable *_doubleJumpGameVariable;
	/* +72  */ CGameBoolVariable *_deathTornadoSpinGameVariable;
	/* +80  */ CGameBoolVariable *_fruitBazookaGameVariable;
	/* +88  */ CGameBoolVariable *_speedShoesGameVariable;
	/* +96  */ CGameBoolVariable *_speedShoesCrash2GameVariable;
	/* +104 */ CGameBoolVariable *_playableCocoGameVariable;
public:
	virtual void Func1(); // sub_8318B0

	virtual void Func7(int8 a1); // sub_833550
	virtual int64 Func8(); // sub_833590
};