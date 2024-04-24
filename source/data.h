#define PRINT_CHARACTERISTICS // Comment if you don't want to print the characterization
#define PRINT_INJECT_LOADING // Comment if you don't want to wait for the injection to load

#define TITLE        skCrypt("Free DLL byte injector by hpp forever")
#define CHEAT_NAME   skCrypt("Furion v1.275")
#define CHEAT_AUTHOR skCrypt("hpp forever") // Comment if you don't want to print an author cheat

#define TITLE_COLOR                        Graphics::TextColor::Red
#define HEADER_COLOR                       Graphics::TextColor::Red
#define HEADER_ARGUMENT_COLOR              Graphics::TextColor::DarkYellow
#define UNDETECT_VAC_COLOR                 Graphics::TextColor::Green
#define QUALITY_OF_FUNCTION_PERFECT_COLOR  Graphics::TextColor::Green
#define QUALITY_OF_FUNCTION_NORMAL_COLOR   Graphics::TextColor::DarkYellow
#define QUALITY_OF_FUNCTION_ABSENT_COLOR   Graphics::TextColor::Red

#ifdef PRINT_INJECT_LOADING
#define INJECTION_COLOR                    Graphics::TextColor::DarkYellow
#endif

#define PROCESS_NAME  skCrypt(L"hl.exe")
#define PROCESS_NAME2 skCrypt(L"cstrike.exe")        // Comment out if you want to search only for the first process
#define GAME_NAME     skCrypt("Counter Strike 1.6") // Write your game name or out If you don't want a print of the name of the game

#ifdef GAME_NAME
#define GAME_BUILD Game_Build::Steam_NonSteam // Write your game build or comment this out if you don't want it printed in the console
#endif

#ifdef PRINT_CHARACTERISTICS
#define QUANTITY_OF_FUNCTIONS 8
#define QUALITY_OF_FUNCTIONS Normal, Normal, Perfect, Normal, Perfect, Normal, Absent, Perfect // 1 - RageBot, 2 - LegitBot, 3 - Kreedz, 4 - Visuals, 5 - Knifebot, 6 - FakeLatency, 7 - SpeedHack, 8 - SteamID spoofer
#endif

#define MAXIMUM_PERCENTAGE 100.0 // Maximum percentage of overall quality of functions and loading inject
#define DEFAULT_PRINT_VELOCITY 18

#ifdef GAME_BUILD
enum Game_Build // Write your builds or comment out the GAME_BUILD or PROCESS_NAME2 macro if you don't want to look for another process
{
	Steam_NonSteam,
	OnlySteam,
	OnlyNonSteam
};
#endif

#ifdef PRINT_CHARACTERISTICS
enum FunctionsIndex // You can change the names of the functions or add your own. Active if PRINT_CHARACTERISTICS macro is not commented out
{
	RageBot,
	LegitBot,
	Kreedz,
	Visuals,
	Knifebot,
	FakeLatency,
	SpeedHack,
	SteamID_spoofer
};

enum QualityFunction // You can change the names of the qualities or add your own. Active if PRINT_CHARACTERISTICS macro is not commented out
{
	Perfect,
	Normal,
	Absent
};
#endif