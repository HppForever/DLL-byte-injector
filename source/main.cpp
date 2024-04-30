#include "main.h"

void main()
{
    DWORD PrevMode;

    GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &PrevMode);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (PrevMode & ~ENABLE_QUICK_EDIT_MODE));
    SetConsoleTitle(TEXT("Free DLL byte injector by hpp forever"));

    Graphics::Print::TypeWriter(TITLE_COLOR, TITLE, 2, DEFAULT_PRINT_VELOCITY, UNDETECT_VAC_COLOR, skCrypt(" (undetect vac)"));
    Graphics::Print::TypeWriter(HEADER_COLOR, skCrypt("Selected cheat: "), 1, DEFAULT_PRINT_VELOCITY, HEADER_ARGUMENT_COLOR, CHEAT_NAME);

#ifdef CHEAT_AUTHOR
    Graphics::Print::TypeWriter(HEADER_COLOR, skCrypt("Author: "), 1, DEFAULT_PRINT_VELOCITY, HEADER_ARGUMENT_COLOR, CHEAT_AUTHOR);
#endif
#ifdef GAME_NAME
    Graphics::Print::TypeWriter(HEADER_COLOR, skCrypt("Selected game: "), 1, DEFAULT_PRINT_VELOCITY, HEADER_ARGUMENT_COLOR, GAME_NAME);
#ifdef GAME_BUILD
    Graphics::Print::TypeWriter(HEADER_COLOR, skCrypt("Needed game build: "), 1, DEFAULT_PRINT_VELOCITY, Graphics::TextColor::ColorList::DarkYellow, Miscellaneous::Strings::Get_GameBuild(GAME_BUILD));
#endif
#endif

#ifdef PRINT_CHARACTERISTICS
    int All_QualityFunction[QUANTITY_OF_FUNCTIONS] = { QUALITY_OF_FUNCTIONS }; // Array of function qualities
    float Percentage = NULL; // Declare and initialize the variable "Percentage" with zero (if this is not done - there will be garbage), it will be print as the total quality of cheat functions

    Graphics::Print::Ordinary(Graphics::TextColor::ColorList::Yellow, skCrypt("\nQuality function: "), NULL, QUALITY_OF_FUNCTION_PERFECT_COLOR, Miscellaneous::Strings::Get_ColorName(QUALITY_OF_FUNCTION_PERFECT_COLOR));
    Graphics::Print::Ordinary(Graphics::TextColor::ColorList::DarkWhite, skCrypt(" - perfect, "), NULL, QUALITY_OF_FUNCTION_NORMAL_COLOR, Miscellaneous::Strings::Get_ColorName(QUALITY_OF_FUNCTION_NORMAL_COLOR));
    Graphics::Print::Ordinary(Graphics::TextColor::ColorList::DarkWhite, skCrypt(" - normal, "), NULL, QUALITY_OF_FUNCTION_ABSENT_COLOR, Miscellaneous::Strings::Get_ColorName(QUALITY_OF_FUNCTION_ABSENT_COLOR));
    Graphics::Print::Ordinary(Graphics::TextColor::ColorList::DarkWhite, skCrypt(" - no function at all"), 2);

    for (int i = NULL; i < QUANTITY_OF_FUNCTIONS; i++) // Cycle to print functions with the color of its quality and calculate the total percentage of quality of all functions
    {
        Percentage += All_QualityFunction[i] == Absent ? NULL : All_QualityFunction[i] == Perfect ? MAXIMUM_PERCENTAGE / QUANTITY_OF_FUNCTIONS : (MAXIMUM_PERCENTAGE / 2) / QUANTITY_OF_FUNCTIONS; // We add to the variable "Percentage" the percentage of quality of the function, thus at the end of the loop we get the final value

        Graphics::Print::TypeWriter(All_QualityFunction[i] == Perfect ? QUALITY_OF_FUNCTION_PERFECT_COLOR :
            All_QualityFunction[i] == Normal ? QUALITY_OF_FUNCTION_NORMAL_COLOR : QUALITY_OF_FUNCTION_ABSENT_COLOR,
            (std::string(skCrypt("[")) + Miscellaneous::Strings::Get_FunctionName(i) + std::string(skCrypt("]")).c_str()).c_str(),
            1, DEFAULT_PRINT_VELOCITY / 3); // Print the function name and its color depending on the quality (macro "QUALITY_OF_FUNCTIONS" from data.h)
    }

    Graphics::Print::TypeWriter(Graphics::TextColor::ColorList::Red, skCrypt("\nOverall quality of cheat - "), 1, DEFAULT_PRINT_VELOCITY, Graphics::TextColor::ColorList::DarkYellow, (std::to_string((int)Percentage) + std::string(skCrypt("%"))).c_str());
#endif

#ifdef PRINT_INJECT_LOADING
    Miscellaneous::Strings::MoveTo_NewLine(1);
    Graphics::TextColor::Set(INJECTION_COLOR);

    for (int i = NULL; i < (int)MAXIMUM_PERCENTAGE; i++)
    {
        printf(skCrypt("\rInjection... %c %d%%"), std::string(skCrypt("|/-\\"))[i % 4], i + 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(DEFAULT_PRINT_VELOCITY / 3));
    }

    Miscellaneous::MoveTo_NewLine_And_ResetColor(1);
#endif

    HANDLE ProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL); // Create a snapshot of the current processes
    HANDLE Process = NULL;
    PROCESSENTRY32W ProcessInfo;

    ProcessInfo.dwSize = sizeof(ProcessInfo);

    if (Process32FirstW(ProcessSnapshot, &ProcessInfo)) // Get the first process info
    {
        do
        {
#if defined(PROCESS_NAME2)
            if (!lstrcmpW(ProcessInfo.szExeFile, PROCESS_NAME) || !lstrcmpW(ProcessInfo.szExeFile, PROCESS_NAME2)) // Check if the process name matches
#else
            if (!lstrcmpW(ProcessInfo.szExeFile, PROCESS_NAME)) // Check if the process name matches
#endif
            {
                Process = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_CREATE_THREAD, FALSE, ProcessInfo.th32ProcessID); // Open the process with the required access rights
                break;
            }
        }

        while (Process32NextW(ProcessSnapshot, &ProcessInfo)); // Get the next process info
    }

    CloseHandle(ProcessSnapshot); // Close the process snapshot

#if defined(PRINT_CHARACTERISTICS) || defined(PRINT_INJECT_LOADING)
    Miscellaneous::Strings::MoveTo_NewLine(1);
#endif

    if (!Process)
    {
#ifdef GAME_BUILD
        const std::string Str = Miscellaneous::Strings::ConvertWideStringToMultiByte(std::wstring(PROCESS_NAME)) + (GAME_BUILD != OnlySteam ? (std::string(skCrypt(" or ")) + Miscellaneous::Strings::ConvertWideStringToMultiByte(std::wstring(PROCESS_NAME2))) : "");
#else
        const std::string Str = Miscellaneous::Strings::ConvertWideStringToMultiByte(std::wstring(PROCESS_NAME));
#endif
        Graphics::Print::Ordinary(Graphics::TextColor::Red, skCrypt("You didn't run "), NULL, Graphics::TextColor::Red, Str.c_str());
        Miscellaneous::TerminateConsole(); // Wait for any key to be pressed and then close the console
    }

    Graphics::Print::Ordinary(Graphics::TextColor::Green, skCrypt("Successfully injected!"));

    WinMain(GetModuleHandle(NULL), NULL, GetCommandLine(), SW_SHOW); // Inject
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), PrevMode);

    Miscellaneous::TerminateConsole(); // Wait for any key to be pressed and then close the console
}
