#include "../main.h"

void Graphics::Print::Ordinary(int Color, const char* Str, int CountTransitions, int Color2, const char* Str2) // Defining a method for printing colored text
{
    TextColor::Set(Color); // Set the color of the text using the "Color" argument
    printf(skCrypt("%s"), Str); // Print the first string "Str" argument

    if (Str2 != " ") // If the argument "Str2" is not equal to a space, it means that we passed the second string. Execute the body of the condition.
    {
        TextColor::Set(Color2); // Set the color of the text using the "Color2" argument
        printf(skCrypt("%s"), Str2); // Print the second string "Str2" argument
    }

    Miscellaneous::MoveTo_NewLine_And_ResetColor(CountTransitions); // Set default color (DarkWhite) after strings print and the transition to a new line occurs as many times as specified in the "CountTransitions" argument
}

void Graphics::Print::TypeWriter(int Color, const char* Str, int CountTransitions, int SpeedLoading, int Color2, const char* Str2) // Defining a method for printing color text with typewriter effect
{
    TextColor::Set(Color); // Set the color of the text using the "Color" argument
    Miscellaneous::Strings::TypeWriter_Logic(Str, SpeedLoading); // Call the typewriter logic to print string "Str" argument

    if (Str2 != " ") // If the argument "Str2" is not equal to a space, it means that we passed the second string. Execute the body of the condition.
    {
        TextColor::Set(Color2); // Set the color of the text using the "Color2" argument
        Miscellaneous::Strings::TypeWriter_Logic(Str2, SpeedLoading); // Call the typewriter logic to print string "Str2" argument
    }

    Miscellaneous::MoveTo_NewLine_And_ResetColor(CountTransitions); // Set default color (DarkWhite) after strings print and the transition to a new line occurs as many times as specified in the "CountTransitions" argument
}