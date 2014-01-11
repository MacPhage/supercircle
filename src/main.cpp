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

using namespace std;



int main()
{
	initwindow(windowX,windowY,"Potent \'Game02\'");
	
	player.setRadius(centerCircleRadius+20);
	player.setLength(30);
	player.setOffset(0);
	player.setState(true);
	
	wall0.setState(true);
	
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
            system("PAUSE");
            break;
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
            dropWall0();
        }
        else if(currentKey == KEY_LEFT && keyTimer > 0)
        {
            cout<<"(KEY_LEFT)"<<endl;
            if(player.getOffset()+gameSpeed > 360)
            {
                player.setOffset(0);
                //This keeps offsets from going over 360 and therefore undetectable for collisions
            }
            else
            {
                player.addOffset(gameSpeed);
            }
            player.calcOccupationA1();
            player.calcOccupationA2();
        }
        else if(currentKey == KEY_RIGHT && keyTimer > 0)
        {
            cout<<"(KEY_RIGHT)"<<endl;
            if(player.getOffset()-gameSpeed < 0)
            {
                player.setOffset(360);
                //This keeps offsets from going under 0 and therefore undetectable for collisions
            }
            else
            {
                player.subtractOffset(gameSpeed);
            }
            player.calcOccupationA1();
            player.calcOccupationA2();
        }
	}
	return 0;
}
