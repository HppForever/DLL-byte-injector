#include "../main.h"

void Graphics::TextColor::Set(int Color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}

void Graphics::TextColor::Reset()
{
    TextColor::Set(ColorList::DarkWhite);
}