#include "TXLib.h"
void Button(int x, const char* name)
{
    txSetColor(TX_TRANSPARENT);
    txSetFillColor(TX_GREY);
    Win32::RoundRect (txDC(), x+5, 35, x+155, 75, 30, 30);
    txSetColor(TX_BLACK, 3);
    txSetFillColor(TX_WHITE);
    Win32::RoundRect (txDC(), x, 30, x+150, 70, 30, 30);
    txSetColor(TX_BLACK);
    txSelectFont("Arial", 24);
    txDrawText(x, 30, x+150, 70, name);
}
bool Buttonclick(int x)
{
    return(txMouseButtons() == 1 &&
            txMouseX()>= x && txMouseX()<=x+150 &&
            txMouseY()>= 35 && txMouseY()<=75);
}

bool clickPictures(int y)
{
    return( txMouseButtons() == 1 &&
            txMouseX() >= 20 && txMouseX() <= 100 &&
            txMouseY() >= y && txMouseY() <= y+200);
}
void DrawPicture(int x, int y, int width_scr, int height_scr, HDC pictures)
{
    Win32::TransparentBlt (txDC(), x, y, width_scr, height_scr, pictures, 0, 0, 225, 225, TX_WHITE);
}


int main()
{
    txCreateWindow (1200, 700);

    HDC pic1 = txLoadImage ("pictures/build/ratusha.bmp");
    HDC pic2 = txLoadImage ("pictures/defense/gun.bmp");
    bool pic1_menu_visible = false;
    bool pic2_menu_visible = false;
    bool pic1_central_visible = false;
    bool pic2_central_visible = false;

    while(!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin();
        txSetColor(TX_GREEN);
        txSetFillColor(TX_GREEN);
        txClear();
        Button(50, "обычные здания");
        Button(250, "защитные здания");

        if(Buttonclick(50))
        {
            pic1_menu_visible = true;
            pic2_menu_visible = true;
        }

        if(pic1_menu_visible)
        {
            DrawPicture(20, 100, 120, 120, pic1);
        }

        if(pic2_menu_visible)
        {
            DrawPicture(20, 300, 120, 120, pic2);
        }

        if(clickPictures(100))
        {
            pic1_central_visible = true;
        }

        if(pic1_central_visible)
        {
            DrawPicture(300, 300, 150, 150, pic1);
        }

        if(clickPictures(250))
        {
            pic2_central_visible = true;
        }

        if(pic2_central_visible)
        {
            DrawPicture(300, 500, 150, 150, pic2);
        }

        txSleep(50);
        txEnd();
    }

txDeleteDC(pic1);
txDeleteDC(pic2);

txDisableAutoPause();
txTextCursor (false);
return 0;
}
