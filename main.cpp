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
int main()
{
    txCreateWindow (1200, 700);


    while(!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin();
        txSetColor(TX_GREEN);
        txSetFillColor(TX_GREEN);
        txClear();
        //кнопкa
        Button(50, "кнопка, да?");
        Button(250, "понял, да?");

        if(txMouseButtons() == 1 &&
           txMouseX()>= 50 && txMouseX()<=200 &&
           txMouseY()>= 35 && txMouseY()<=75)
        {
            txSetColor(TX_BLACK);
            txSelectFont("Arial", 24);
            txDrawText(0, 50, 1200, 200, "нажал, да?");
        }

        txSleep(50);
        txEnd();
    }
txDisableAutoPause();
txTextCursor (false);
return 0;
}
