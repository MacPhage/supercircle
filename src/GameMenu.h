//
//  GameMenu.cpp
//  Potent Game02
//
//  C++ Header File
//
//  Created by Austin Jackson,
//  Last modified on January 8, 2014.
//
//  http://www.ruthlessphysics.com/potent/
//

#include "LibVenom.h"

using namespace std;

unsigned int selectedMenuItem = 0U;
int menuSizeX = 400;
int menuSizeY = 300;
int menuItemMax = 1;

void gameMenu();
void drawGameMenu();

void gameMenu()
{
	initwindow(menuSizeX,menuSizeY,"Potent \'Game02\' Menu");
	char currentKey;
    unsigned int keyTimer;
	for(;;)
	{
        if(keyTimer > 0U)
        {
            keyTimer--;
        }
        if(kbhit())
        {
            currentKey = getch();
            keyTimer = 1U;
        }
        delay(50);
        if(currentKey == KEY_ESC && keyTimer > 0U)
        {
            cout<<"(KEY_ESC)"<<endl;
            break;
        }
        else if(currentKey == KEY_LEFT && keyTimer > 0U)
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
        else if(currentKey == KEY_RIGHT && keyTimer > 0U)
        {
            cout<<"(KEY_RIGHT)"<<endl;
            selectedMenuItem++;
            if(selectedMenuItem > menuItemMax)
            {
                selectedMenuItem = menuItemMax;
            }
            cout<<selectedMenuItem<<endl;
        }
        else if(currentKey == KEY_SPACEBAR && keyTimer > 0U)
        {
            cout<<"(KEY_SPACEBAR)"<<endl;
            if(selectedMenuItem == 0)
            {
                cout<<"\nStarting...\n"<<endl;
                willQuit = false;
                break;
            }
            if(selectedMenuItem == 1)
            {
                cout<<"\nQuitting...\n"<<endl;
                willQuit = true;
                break;
            }
        }
        drawGameMenu();
	}
}

void drawGameMenu()
{
    outtextxy((menuSizeX/2)-30,menuSizeY/4,"Super Circle");
    outtextxy(0,menuSizeY-20,"Try using the arrow keys and the spacebar!");
    if(selectedMenuItem == 0)
    {
        setcolor(LIGHTGREEN);
    }
    rectangle(menuSizeX/4,menuSizeY/2,(menuSizeX/2)-30,(menuSizeY/2)+30);
    outtextxy(menuSizeX/4,menuSizeY/2,"START");
    setcolor(WHITE);
    
    if(selectedMenuItem == 1)
    {
        setcolor(LIGHTGREEN);
    }
    rectangle((menuSizeX/2)+30,menuSizeY/2,(int)(menuSizeX*0.75),(menuSizeY/2)+30);
    outtextxy((menuSizeX/2)+30,menuSizeY/2,"QUIT");
    setcolor(WHITE);
}
