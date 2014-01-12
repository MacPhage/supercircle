//
//  MenuScreen.cpp
//  Potent Game02
//
//  C++ Header File
//
//  Created by Austin Jackson,
//  Last modified on January 8, 2014.
//
//  http://www.ruthlessphysics.com/potent/
//

#include "HelpScreen.h"

using namespace std;

void menuScreen();
void drawMenuScreen();

void menuScreen()
{
	initwindow(menuSizeX,menuSizeY,"Potent \'Game02\' Menu");
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
        else if(currentKey == KEY_UP && keyTimer > 0U)
        {
            cout<<"(KEY_UP)"<<endl;
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
        else if(currentKey == KEY_DOWN && keyTimer > 0U)
        {
            cout<<"(KEY_DOWN)"<<endl;
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
                closegraph();
                helpScreen();
            }
            if(selectedMenuItem == 2)
            {
                cout<<"\nQuitting...\n"<<endl;
                willQuit = true;
                break;
            }
        }
        drawMenuScreen();
	}
}

void drawMenuScreen()
{
    outtextxy((int)(menuSizeX*0.05),(int)(menuSizeY*0.20),"Super Circle");
    outtextxy(0,menuSizeY-20,"Try using the arrow keys and the spacebar!");

    if(selectedMenuItem == 0)
    {
        setcolor(LIGHTGREEN);
    }
    rectangle((int)(menuSizeX*0.05),(int)(menuSizeY*0.4),(int)(menuSizeX*0.05)+100,(int)(menuSizeY*0.4)+25);
    outtextxy((int)(menuSizeX*0.05),(int)(menuSizeY*0.4),"START");
    setcolor(WHITE);

    if(selectedMenuItem == 1)
    {
        setcolor(LIGHTGREEN);
    }
    rectangle((int)(menuSizeX*0.05),(int)(menuSizeY*0.4)+30,(int)(menuSizeX*0.05)+100,(int)(menuSizeY*0.4)+55);
    outtextxy((int)(menuSizeX*0.05),(int)(menuSizeY*0.4)+30,"HELP");
    setcolor(WHITE);

}
