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
void drawHelpText();

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
    outtextxy((int)(menuSizeX*0.5)-10,(int)(menuSizeY*0.05),"Help");
    drawHelpText();
    if(selectedMenuItem == 0)
    {
        setcolor(LIGHTGREEN);
        rectangle((int)(menuSizeX*0.5)-49,(int)(menuSizeY*0.75)+1,(int)(menuSizeX*0.5)+49,(int)(menuSizeY*0.75)+29);
    }
    rectangle((int)(menuSizeX*0.5)-50,(int)(menuSizeY*0.75),(int)(menuSizeX*0.5)+50,(int)(menuSizeY*0.75)+30);
    outtextxy((int)(menuSizeX*0.5)-50,(int)(menuSizeY*0.75),"BACK");
    setcolor(WHITE);
}

void drawHelpText()
{
    int X = (int)(menuSizeX*0.05);
    int Y = (int)(menuSizeY*0.25);
    outtextxy(X,Y+0,"\'Super Circle\' is a remake of Terry Cavanagh's popular indie game");
    outtextxy(X,Y+17,"\'Super Hexagon,\' by high school freshman Austin Jackson.");
    outtextxy(X,Y+51,"To play, use the arrow keys to avoid incoming arcs.");
    outtextxy(X,Y+68,"Try to last as long as you can!");
    outtextxy(X,Y+102,"\'Super Hexagon\' is available on DistractionWare.com, be sure to check it out!");
    outtextxy(X,Y+119,"You can press ESC to close the game at any time,");
    outtextxy(X,Y+136,"and SPACEBAR to press the highlighted button below");
    outtextxy(X,Y+170,"Try to have fun! :)");
    outtextxy(X,Y+187,"-Austin");
}
