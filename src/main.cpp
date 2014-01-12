//
//  main.cpp
//  Potent Game02
//
//  C++ Source File
//
//  Created by Austin Jackson,
//  Last modified on January 8, 2014.
//
//  http://www.ruthlessphysics.com/potent/
//

#include "CoreGame.h"
#include "Game02_private.h"

using namespace std;

int release = VER_RELEASE;

POINT p;

int main()
{

    /*for(;;)
    {
        if(GetCursorPos(&p))
        {
            cout<<"("<<p.x<<","<<p.y<<")"<<endl;
        }

    }*/
    cout<<"Version: "<<VER_STRING<<endl;
    if(release == 0)
    {
        cout<<"THIS IS PRE-RELEASE SOFTWARE!"<<endl;
        system("PAUSE");
        cout<<"Please select the graphics window."<<endl;
    }
    menuScreen();
    if(willQuit == true)
    {
        return 0;
    }

	initwindow(windowX,windowY,"Potent \'Game02\'");
	
	player.setRadius(centerCircleRadius+20);
	player.setLength(30);
	player.setOffset(0);
	player.setState(true);
	
	for(;;)
	{
        if(kbhit())
        {
            currentKey = getch();
            keyTimer = 2;
        }
        delay(1);
        heartbeat();
        //Collision checking
        if(checkCollision() == true)
        {
            cout<<"\n** COLLISION OCCURED **"<<endl;
            setcolor(LIGHTRED);
            outtextxy(0,0,"** COLLISION OCCURED **");
            outtextxy(0,20,"Game will close in 5 seconds.");
            if(invincible == false)
            {
                delay(5000);
                break;
            }
            else
            {
                outtextxy(50,0,"INVINCIBILITY ACTIVE");
            }
            setcolor(WHITE);
        }
        sink();
        if(currentKey == KEY_ESC && keyTimer > 0)
        {
            cout<<"(KEY_ESC)"<<endl;
            break;
        }
        else if(currentKey == KEY_UP && keyTimer > 0)
        {
            cout<<"(KEY_UP)"<<endl;
            printAllValues();
        }
        else if(currentKey == KEY_DOWN && keyTimer > 0)
        {
            cout<<"(KEY_DOWN)"<<endl;
            wall0.setState(false);
            wall1.setState(false);
            wall2.setState(true);
            wall3.setState(false);
            wall4.setState(false);
            wall5.setState(false);
        }
        else if(currentKey == KEY_LEFT && keyTimer > 0)
        {
            cout<<"(KEY_LEFT)"<<endl;
            if(player.getOffset()+gameSpeed+(player.getLength()/2) > 360)
            {
                cout<<" [HIT]"<<endl;
                //This keeps offsets from going over 360 and past the line
            }
            
            else
            {
                player.addOffset(gameSpeed);
            }
            player.calcOccupationA1();
            player.calcOccupationA2();
            /* OLD CODE
            if(player.getOffset()+gameSpeed > 360)
            {
                player.setOffset(0);
                cout<<"player.arcOffset reset."<<endl;
                //This keeps offsets from going over 360 and therefore undetectable for collisions
            }
            */
        }
        else if(currentKey == KEY_RIGHT && keyTimer > 0)
        {
            cout<<"(KEY_RIGHT)"<<endl;
            if(player.getOffset()-gameSpeed-(player.getLength()/2) < 0)
            {
                cout<<" [HIT]"<<endl;
                //This keeps offsets from going over 360 and past the line
            }
            else
            {
                player.subtractOffset(gameSpeed);
            }
            player.calcOccupationA1();
            player.calcOccupationA2();
            /* OLD CODE
            if(player.getOffset()-gameSpeed < 0)
            {
                player.setOffset(360);
                //This keeps offsets from going under 0 and therefore undetectable for collisions
            }
            */
        }
	}
	return 0;
}
