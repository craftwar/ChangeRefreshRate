#include <windows.h>
#include <cwchar>

void ChangeRefreshRate(DWORD newRate) {
	DEVMODE devMode = { 0 };
	devMode.dmSize = sizeof(DEVMODE);

	if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode)) {
		devMode.dmDisplayFrequency = newRate;
		devMode.dmFields = DM_DISPLAYFREQUENCY;

		LONG result = ChangeDisplaySettingsEx(NULL, &devMode, NULL, CDS_UPDATEREGISTRY, NULL);
	}
}

int wmain(int argc, wchar_t* __restrict argv[]) {
	DWORD newRate;
	if (argc >= 2) {
		newRate = std::wcstoul(argv[1], nullptr, 10);

		ChangeRefreshRate(newRate);
	}

	return 0;
}
