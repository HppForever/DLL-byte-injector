class Miscellaneous
{
public:
	class Strings
	{
	public:
		static void MoveTo_NewLine(int CountTransitions); // Announcement transition functions to move to a new line as many times as specified in the "CountTransitions" argument
		static void TypeWriter_Logic(const char* Str, int SpeedLoading); // Announcement the logic of the typewriter function

#ifdef PRINT_CHARACTERISTICS
		static const char* Get_GameBuild(int BuildIndex); // Announcement the method of obtaining the build name depending on its index
		static const char* Get_FunctionName(int FunctionIndex);// Announcement the method of obtaining the function name depending on its index
		static const char* Get_ColorName(int ColorIndex); // Announcement the method of obtaining the color name depending on its index
#endif
		static std::string ConvertWideStringToMultiByte(const std::wstring& WideStr); // Announcement convent function wstring/wchar_t to std::string/const char*
	};

static void MoveTo_NewLine_And_ResetColor(int CountTransitions);
static void TerminateConsole(); // Announcement press standby function and console shutdown
};