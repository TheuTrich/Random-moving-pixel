#include <windows.h>
#include <iostream>
#include <random>

using namespace std;


int main()
{
    int x = 0, y = 0, width = 1900, height = 1080;
    
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);





    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randxy(-1,1);
    std::uniform_int_distribution<> randcolor(0, 255);
    
    HDC hdc = GetDC(GetConsoleWindow());
    
    while (true) {
        SetPixel(hdc, x, y, RGB(randcolor(gen), randcolor(gen), randcolor(gen)));
        x = x + randxy(gen);
        y = y + randxy(gen);
        if (x < 0) {
            x = x + width;
        }
        if (x > (width - 1)) {
            x = x - width;
        }
        if (y < 0) {
            y = y + height;
        }
        if (y > (height - 1)) {
            y = y - height;
        }
    }
    
            
}