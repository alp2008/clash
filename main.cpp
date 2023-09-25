#include "TXLib.h"
struct Button
{
    int x;
    const char* name;

    void DrawButton()
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

    bool Buttonclick()
    {
        return(txMouseButtons() == 1 &&
        txMouseX()>= x && txMouseX()<=x+150 &&
        txMouseY()>= 35 && txMouseY()<=75);
    }
};

struct Picture
{
    int x;
    int y;
    HDC pic;
    int scr_w;
    int scr_h;
    int w;
    int h;
    bool visible;
};

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
    //инициализация кнопок
    Button btn[2];
    btn[0] = {50, "обычные здания"};
    btn[1] = {250, "защитные здания"};

    HDC pic1 = txLoadImage ("pictures/build/ratusha.bmp");
    HDC pic2 = txLoadImage ("pictures/defense/gun.bmp");
    int pic1_menu_x=20;
    int pic1_menu_y=100;
    int pic1_menu_w=120;
    int pic1_menu_h=120;
    int pic1_central_x=300;
    int pic1_central_y=300;
    int pic1_central_w=150;
    int pic1_central_h=150;
    bool pic1_menu_visible = false;
    bool pic2_menu_visible = false;
    bool pic1_central_visible = false;
    bool pic2_central_visible = false;
    int pic2_menu_x=20;
    int pic2_menu_y=300;
    int pic2_menu_w=120;
    int pic2_menu_h=120;
    int pic2_central_x=300;
    int pic2_central_y=500;
    int pic2_central_w=150;
    int pic2_central_h=150;

    while(!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin();
        txSetColor(TX_GREEN);
        txSetFillColor(TX_GREEN);
        txClear();

        for (int i=0; i<2; i++)
        {
            btn[i].DrawButton();
        }

        if(btn[0].Buttonclick())
        {
            pic1_menu_visible = true;
            pic2_menu_visible = true;
        }

        if(pic1_menu_visible)
        {
            DrawPicture(pic1_menu_x, pic1_menu_y, pic1_menu_w, pic1_menu_h, pic1);
        }

        if(pic2_menu_visible)
        {
            DrawPicture(pic2_menu_x, pic2_menu_y, pic2_menu_w, pic2_menu_h, pic2);
        }

        if(clickPictures(100))
        {
            pic1_central_visible = true;
        }

        if(pic1_central_visible)
        {
            DrawPicture(pic1_central_x, pic1_central_y, pic1_central_w, pic1_central_h, pic1);
        }

        if(clickPictures(250))
        {
            pic2_central_visible = true;
        }

        if(pic2_central_visible)
        {
            DrawPicture(pic2_central_x, pic2_central_y, pic2_central_w, pic2_central_h, pic2);
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
