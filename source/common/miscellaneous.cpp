#include "../main.h"

void Miscellaneous::Strings::MoveTo_NewLine(int CountTransitions) // Defining transition functions to move to a new line as many times as specified in the "CountTransitions" argument
{
    for (int i = NULL; i < CountTransitions; i++) // Transitions to a new line as many times as we passed the value through the "CountTransitions" argument
        printf("\n");
}

void Miscellaneous::MoveTo_NewLine_And_ResetColor(int CountTransitions)
{
    Strings::MoveTo_NewLine(CountTransitions);
    Graphics::TextColor::Reset();
}

void Miscellaneous::Strings::TypeWriter_Logic(const char* Str, int SpeedLoading) // Defining the logic of the typewriter function
{
    for (size_t i = NULL; i < std::string(Str).length(); ++i) // The loop will run from the first character all the way to the last character
    {
        printf(skCrypt("%c"), std::string(Str)[i]); // Print one character
        std::this_thread::sleep_for(std::chrono::milliseconds(SpeedLoading)); // Wait as long as you specify in the "SpeedLoading" argument
    }
}

const char* Miscellaneous::Strings::Get_GameBuild(int BuildIndex) // Defining the method of obtaining the build name depending on its index
{
    switch (BuildIndex)
    {
        case Game_Build::Steam_NonSteam: return skCrypt("Steam/NonSteam"); break;
        case Game_Build::OnlySteam:      return skCrypt("Only steam");     break;
        case Game_Build::OnlyNonSteam:   return skCrypt("Only non steam"); break;
    }
}

#ifdef PRINT_CHARACTERISTICS
const char* Miscellaneous::Strings::Get_FunctionName(int FunctionIndex) // Defining the method of obtaining the function name depending on its index
{
    switch (FunctionIndex)
    {
        case FunctionsIndex::RageBot:         return skCrypt("RageBot");          break;
        case FunctionsIndex::LegitBot:        return skCrypt("LegitBot");         break;
        case FunctionsIndex::Kreedz:          return skCrypt("Kreedz");           break;
        case FunctionsIndex::Visuals:         return skCrypt("Visuals");          break;
        case FunctionsIndex::Knifebot:        return skCrypt("Knifebot");         break;
        case FunctionsIndex::FakeLatency:     return skCrypt("FakeLatency");      break;
        case FunctionsIndex::SpeedHack:       return skCrypt("SpeedHack");        break;
        case FunctionsIndex::SteamID_spoofer: return skCrypt("SteamID_spoofer");  break;
    }
}

const char* Miscellaneous::Strings::Get_ColorName(int ColorIndex) // Defining a method for obtaining a color name depending on its index
{
    switch (ColorIndex)
    {
        case Graphics::TextColor::DarkBlue:   return skCrypt("dark blue");     break;
        case Graphics::TextColor::DarkGreen:  return skCrypt("dark green");    break;
        case Graphics::TextColor::DarkCyan:   return skCrypt("dark cyan");     break;
        case Graphics::TextColor::DarkRed:    return skCrypt("dark red");      break;
        case Graphics::TextColor::DarkPurple: return skCrypt("dark purple");   break;
        case Graphics::TextColor::DarkYellow: return skCrypt("dark yellow");   break;
        case Graphics::TextColor::DarkWhite:  return skCrypt("dark white");    break;
        case Graphics::TextColor::Grey:       return skCrypt("grey");          break;
        case Graphics::TextColor::Blue:       return skCrypt("blue");          break;
        case Graphics::TextColor::Green:      return skCrypt("green");         break;
        case Graphics::TextColor::Cyan:       return skCrypt("cyan");          break;
        case Graphics::TextColor::Red:        return skCrypt("red");           break;
        case Graphics::TextColor::Purple:     return skCrypt("purple");        break;
        case Graphics::TextColor::Yellow:     return skCrypt("yellow");        break;
        case Graphics::TextColor::White:      return skCrypt("white");         break;
    }
}
#endif

std::string Miscellaneous::Strings::ConvertWideStringToMultiByte(const std::wstring& WideStr) // Defining convent function wstring/wchar_t to std::string/const char*
{
    std::string Result(WideCharToMultiByte(CP_UTF8, NULL, WideStr.c_str(), static_cast<int>(WideStr.length()), NULL, NULL, NULL, NULL), NULL);
    WideCharToMultiByte(CP_UTF8, NULL, WideStr.c_str(), static_cast<int>(WideStr.length()), &Result[NULL], WideCharToMultiByte(CP_UTF8, NULL, WideStr.c_str(), static_cast<int>(WideStr.length()), NULL, NULL, NULL, NULL), NULL, NULL);

    return Result;
}

void Miscellaneous::TerminateConsole() // Defining press standby function and console terminate
{
    _getch();
    exit(NULL);
}
