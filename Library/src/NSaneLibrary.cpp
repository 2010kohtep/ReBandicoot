#pragma message("If you don't, somebody will.")

#include <Windows.h>
#include <iostream>
#include <psapi.h>

#include <Common/TypeDefs.h>
#include <Common/Global.h>

enum ECrashSecretZones
{
	eCSZ_None = 0,
	eCSZ_C2_AirCrash = 1,
	eCSZ_C2_SnowGo = 2,
	eCSZ_C2_RoadToRuin = 3,
	eCSZ_C2_TotallyBear = 4,
	eCSZ_C2_TotallyFly = 5,
	eCSZ_C3_SkiCrazed = 6,
	eCSZ_C3_HangemHigh = 7,
	eCSZ_C3_Area51 = 8,
	eCSZ_C3_FutureFrenzy = 9,
	eCSZ_C3_RingsOfPower = 10,
	eCSZ_C3_HotCoco = 11,
	eCSZ_C3_EggipusRex = 12,
	eCSZ_C3_FutureTense = 13,

	eCSZ_Max,
};

struct VResult
{
	void *unk00;
	void *unk08;
	long unk16;
	long unk20_padding;
	void *unk24;
};

// All these functions returns 2.
struct V
{
	virtual void *get_AccoladeSystem(int, int, VResult *result) = 0;
	virtual void *get_StatisticsManager(int, int, VResult *result) = 0;
	virtual void *get_State(int, int, VResult *result) = 0;
	virtual void *get_CollectibleTrackerSystem(int, int, VResult *result) = 0;
	virtual void *get_QuestSystem(int, int, VResult *result) = 0;
};

struct VCrashBandicootSingleData
{

};

struct DCrashBandicootSingleData
{

};

// sizeof: 88
struct alignas(8) CCrashBandicootSingleVariable
{
	VCrashBandicootSingleData *_vptr; // off_17A4990?

	/* +8  */ int32 unk08;
	/* +12 */ int32 unk0C_align;
	/* +16 */ int16 unk10;
	/* +18 */ int16 unk12;
	/* +20 */ int16 unk14;

	/* magic start */
	
	/* +22 */ int16 unk16;
	/* +24 */ int32 unk18_align;

	/* magic end   */

	/* +32 */ int64 unk20; // pointer to igObjectList (&off_17A5248)
	/* +40 */ int32 unk28; // *(_DWORD *)(this + 0x28) & 0xFE0403FF | 0x403FF;
	/* +44 */ int32 unk2C_align;
	/* +48 */ char *unk30; // this variable name
	/* +56 */ int64 unk38;
	/* +64 */ int64 unk40; // real crap happens here (see sub_BC9980)
	/* +72 */ int32 unk48; // sets in 0x1000000 inside constructor
	/* +76 */ int32 unk4C_align;
	/* +80 */ int64 unk50; // pointer to igDotNetMetaObject
};

constexpr auto b = sizeof CCrashBandicootSingleVariable;
constexpr auto a = offsetof(CCrashBandicootSingleVariable, unk18_align);
constexpr auto c = offsetof(CCrashBandicootSingleVariable, unk50);

#include <ReBandicoot/system/SystemData.h>

class igCameraReferenceSettings : public igObject
{
private:

};

// CDebugNodes - hmmm... interesting... don't forget to check the field constructor, please

// Need to finish virtual tables in classes... or I just need to delete them,
// because I don't think they are going to be useful.

// To do:
//   Camera controls;
//   Game flags manipulator (double-jump, bazooka, ...);
//   Easy access to global engine variables list;


WNDPROC pfnOrgWndProc = nullptr;

LRESULT CALLBACK GUIWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_KEYUP)
	{
		if (wParam == VK_OEM_3)
		{
			MessageBoxA(0, "a", 0, MB_SYSTEMMODAL);
		}
	}

	return CallWindowProc(pfnOrgWndProc, hWnd, uMsg, wParam, lParam);
}

WNDPROC DetourWndProc(HWND hWnd, WNDPROC pfnWndProc)
{
	if (hWnd == INVALID_HANDLE_VALUE || !pfnWndProc)
		return nullptr;

	return (WNDPROC)SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)pfnWndProc);
}

HWND GetGameWindowHandle()
{
	return FindWindowW(NULL, L"Crash Bandicoot™ N. Sane Trilogy");
}

BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hinstDLL);

		//pfnOrgWndProc = DetourWndProc(GetGameWindowHandle(), GUIWndProc);
		
		GameInst = (unsigned char *)GetModuleHandleA(NULL);

		pbPlayerGodMode   = (bool *)&GameInst[0x1A73168];
		pbEnemiesUndying  = (bool *)&GameInst[0x1A7316B];
		pbShowEntityNames = (bool *)&GameInst[0x1A72CE5];

		pbPhysicsProperties = (bool *)&GameInst[0x1A72EFE];
		pbDisplayHealth     = (bool *)&GameInst[0x1A72EFF];

		bEnemiesUndying = true;
		bPlayerGodMode = true;
		bShowEntityNames = true;

		bPhysicsProperties = true;
		bDisplayHealth = true;

		// ...
	}

	return TRUE;
}