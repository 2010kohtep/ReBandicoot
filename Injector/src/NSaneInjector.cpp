#pragma message("If you don't, somebody will.")

#include <Windows.h>
#include <iostream>
#include <io.h>

#include <Utils/StrUtils/StrUtils.h>

#include <BlackBone/BlackBone/ManualMap/MMap.h>
#include <BlackBone/BlackBone/Process/Process.h>

using namespace blackbone;

int FileExists(const char *pszName)
{
	return _access(pszName, 0) != -1;
}

unsigned int GetGameProcessId()
{
	auto result = 0ul;

	auto hWnd = FindWindowW(NULL, L"Crash Bandicoot™ N. Sane Trilogy");
	GetWindowThreadProcessId(hWnd, &result);

	return result;
}

std::wstring AStrToWStr(const std::string &str)
{
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	return wstrTo;
}

int main(int argc, char **argv)
{
	printf(".:: Crash Bandicoot N. Sane Trilogy Injector ::.\n");
	printf("\n");

	printf("Searching process...\n");

	auto nPId = GetGameProcessId();
	if (!nPId)
	{
		printf("Could not find game process. Start the game first.\n");
		system("pause");

		return 0;
	}

	printf("Process found. ID: %d\n", nPId);

	printf("Attaching to process...\n");

	Process process;
	auto status = process.Attach(nPId);

	if (!NT_SUCCESS(status))
	{
		printf("Could not attach to game process. Code: %08X\n", status);
		system("pause");

		return 0;
	}

	printf("Successfully attached.\n");

	char szLibName[MAX_PATH + sizeof(char)];
	ExtractFileDir(argv[0], szLibName);
	strcat(szLibName, "Library.dll");

	if (!FileExists(szLibName))
	{
		printf("Could not find library for inject.\n");
		system("pause");

		return 0;
	}

	printf("Injecting library...\n");

	auto mod = process.modules().Inject(AStrToWStr(szLibName), nullptr);

	//auto mod = process.mmap().MapImage(L"C:\\Users\\Alex\\Desktop\\Library.dll",
	//	NoFlags, (MapCallback)nullptr, nullptr, nullptr);

	if (!mod)
	{
		printf("Could not inject module to game process.\n");
		system("pause");

		return 0;
	}

	process.Detach();

	printf("Module loaded. Use '~' key to open the engine controller menu.\n");
	system("pause");

	return 0;
}