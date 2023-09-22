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

int main()
{
    txCreateWindow (1200, 700);

    HDC pic1 = txLoadImage ("pictures/ratusha.bmp");
    HDC pic2 = txLoadImage ("pictures/gun.bmp");
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
        //�����a
        Button(50, "������");
        Button(250, "�������� ������");

        if(Buttonclick(50))
        {
            pic1_menu_visible = true;
            pic2_menu_visible = true;
        }

        if(pic1_menu_visible)
        {
            Win32::TransparentBlt (txDC(), 20, 100, 80, 200, pic1, 0, 0, 240, 600, TX_WHITE);
        }

        if(pic2_menu_visible)
        {
            Win32::TransparentBlt (txDC(), 20, 300, 80, 200, pic2, 0, 0, 240, 600, TX_WHITE);
        }

        if(clickPictures(100))
        {
            pic1_central_visible = true;
        }

        if(pic1_central_visible)
        {
            Win32::TransparentBlt (txDC(), 20, 250, 150, 150, pic1, 0, 0, 225, 225, TX_WHITE);
        }

        if(clickPictures(250))
        {
            pic2_central_visible = true;
        }

        if(pic2_central_visible)
        {
            Win32::TransparentBlt(txDC(), 20, 100, 150, 150, pic2, 0, 0, 200, 200, TX_WHITE);
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
