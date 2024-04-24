class Graphics
{
public:
	class TextColor
	{
	public:
		enum ColorList
		{
			DarkBlue = 1,
			DarkGreen,
			DarkCyan,
			DarkRed,
			DarkPurple,
			DarkYellow,
			DarkWhite,
			Grey,
			Blue,
			Green,
			Cyan,
			Red,
			Purple,
			Yellow,
			White
		};

		void static Set(int Color = DarkWhite);
		void static Reset();
	};

	class Print
	{
	public:
		void static TypeWriter(int Color = TextColor::ColorList::DarkWhite, const char* Str = "", int CountTransitions = NULL, int SpeedLoading = DEFAULT_PRINT_VELOCITY, int Color2 = TextColor::ColorList::DarkWhite, const char* Str2 = " ");
		void static Ordinary(int Color = TextColor::ColorList::DarkWhite, const char* Str = "", int CountTransitions = NULL, int Color2 = TextColor::ColorList::DarkWhite, const char* Str2 = " ");
	};
};