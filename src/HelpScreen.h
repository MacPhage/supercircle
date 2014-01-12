//
//  HelpScreen.h
//  Potent Game02
//
//  C++ Header File
//
//  Created by Austin Jackson,
//  Last modified on January 8, 2014.
//
//  http://www.ruthlessphysics.com/potent/
//

#include "Screen.h"

using namespace std;

void helpScreen();
void drawHelpScreen();

void helpScreen()
{
	initwindow(menuSizeX,menuSizeY,"Potent \'Game02\' Menu");
	for(;;)
	{
        if(keyTimer > 0)
        {
            keyTimer--;
        }
        if(kbhit())
        {
            currentKey = getch();
            keyTimer = 1;
        }
        delay(50);
        if(currentKey == KEY_ESC && keyTimer > 0)
        {
            cout<<"(KEY_ESC)"<<endl;
            break;
        }/*
        else if(currentKey == KEY_LEFT && keyTimer > 0)
        {
            cout<<"(KEY_LEFT)"<<endl;
            if(selectedMenuItem == 0U)
            {
                //
            }
            else
            {
                selectedMenuItem--;
            }
            cout<<selectedMenuItem<<endl;
        }
        else if(currentKey == KEY_RIGHT && keyTimer > 0)
        {
            cout<<"(KEY_RIGHT)"<<endl;
            selectedMenuItem++;
            if(selectedMenuItem > menuItemMax)
            {
                selectedMenuItem = menuItemMax;
            }
            cout<<selectedMenuItem<<endl;
        }*/
        else if(currentKey == KEY_SPACEBAR && keyTimer > 0)
        {
            cout<<"(KEY_SPACEBAR)"<<endl;
            if(selectedMenuItem == 0)
            {
                cleardevice();
                break;
            }
        }
        drawHelpScreen();
        selectedMenuItem = 0U;
	}
}

void drawHelpScreen()
{
    outtextxy((int)(menuSizeX*0.5)-10,menuSizeY/4,"Help");
    if(selectedMenuItem == 0)
    {
        setcolor(LIGHTGREEN);
    }
    rectangle((int)(menuSizeX*0.5)-50,(int)(menuSizeY*0.75),(int)(menuSizeX*0.5)+50,(int)(menuSizeY*0.75)+30);
    outtextxy((int)(menuSizeX*0.5)-50,(int)(menuSizeY*0.75),"BACK");
    setcolor(WHITE);
}
