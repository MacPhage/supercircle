//
//  CoreGame.h
//  Potent Game02
//
//  C++ Header File
//
//  Created by Austin Jackson,
//  Last modified on January 8, 2014.
//
//  http://www.ruthlessphysics.com/potent/
//

#include "GameArc.h"

using namespace std;

GameArc player;
GameArc wall0;
GameArc wall1;
GameArc wall2;
GameArc wall3;
GameArc wall4;
GameArc wall5;

int windowX = 600;
int windowY = 600;
char currentKey;
int keyTimer;
int centerCircleRadius = windowX / 8;
int gameSpeed = 5;
int printOccurence = 0;
int heartbeatCount = 0;
int selectedWall = 0;
bool invincible = false;

void heartbeat();
void sink();
void printAllValues();
bool checkCollision();
void dropWall0();
void dropWall1();
void dropWall2();
void dropWall3();
void dropWall4();
void dropWall5();

void heartbeat()
{
    heartbeatCount++;
    if(keyTimer > 0)
    {
        keyTimer--;
    }
    //Recalculating occupations before refreshing the screen
    /*
    player.calcOccupationA1();
    player.calcOccupationA2();
    wall0.calcOccupationA1();
    wall1.calcOccupationA1();
    wall1.calcOccupationA2();
    wall2.calcOccupationA1();
    wall2.calcOccupationA2();
    wall3.calcOccupationA1();
    wall3.calcOccupationA2();
    wall4.calcOccupationA1();
    wall4.calcOccupationA2();
    wall5.calcOccupationA1();
    wall5.calcOccupationA2();
    */


    cleardevice();
    circle(windowX/2,windowY/2,centerCircleRadius); //CENTER CIRCLE
    line(windowX/2,windowX/2,windowX,windowY/2); //BLOCKING LINE
    arc(windowX/2,windowY/2,player.getOccupationA1(),player.getOccupationA2(),player.getRadius()); //THE PLAYER
    outtextxy(0,40,"Current walls: ");
    if(wall0.getState() == true)
    {
        arc(windowX/2,windowY/2,wall0.getOccupationA1(),wall0.getOccupationA2(),wall0.getRadius());
        outtextxy(10,60,"wall0");
    }
    if(wall1.getState() == true)
    {
        arc(windowX/2,windowY/2,wall1.getOccupationA1(),wall1.getOccupationA2(),wall1.getRadius());
        outtextxy(10,80,"wall1");
    }
    if(wall2.getState() == true)
    {
        arc(windowX/2,windowY/2,wall2.getOccupationA1(),wall2.getOccupationA2(),wall2.getRadius());
        outtextxy(10,100,"wall2");
    }
    if(wall3.getState() == true)
    {
        arc(windowX/2,windowY/2,wall3.getOccupationA1(),wall3.getOccupationA2(),wall3.getRadius());
        outtextxy(10,120,"wall3");
    }
    if(wall4.getState() == true)
    {
        arc(windowX/2,windowY/2,wall4.getOccupationA1(),wall4.getOccupationA2(),wall4.getRadius());
        outtextxy(10,140,"wall4");
    }
    if(wall5.getState() == true)
    {
        arc(windowX/2,windowY/2,wall5.getOccupationA1(),wall5.getOccupationA2(),wall5.getRadius());
        outtextxy(10,160,"wall5");
    }
}

void sink()
{
    //Reduce all wall radius by 1
    if(wall0.getState() == true)
    {
        if(wall0.getRadius() > (centerCircleRadius - 1))
        {
            wall0.subtractRadius(1);
        }
        else
        {
            dropWall0();
        }
    }
    if(wall1.getState() == true)
    {
        if(wall1.getRadius() > (centerCircleRadius - 1))
        {
            wall1.subtractRadius(1);
        }
        else
        {
            dropWall1();
        }
    }
    if(wall2.getState() == true)
    {
        if(wall2.getRadius() > (centerCircleRadius - 1))
        {
            wall2.subtractRadius(1);
        }
        else
        {
            dropWall2();
        }
    }
    if(wall3.getState() == true)
    {
        if(wall3.getRadius() > (centerCircleRadius - 1))
        {
            wall3.subtractRadius(1);
        }
        else
        {
            dropWall3();
        }
    }
    if(wall4.getState() == true)
    {
        if(wall4.getRadius() > (centerCircleRadius - 1))
        {
            wall4.subtractRadius(1);
        }
        else
        {
            dropWall4();
        }
    }
    if(wall5.getState() == true)
    {
        if(wall5.getRadius() > (centerCircleRadius - 1))
        {
            wall5.subtractRadius(1);
        }
        else
        {
            dropWall5();
        }
    }
}

void printAllValues()
{
    printOccurence++;
    cout<<"[ printOccurence = "<<printOccurence<<" ]"<<endl;
    cout<<"heartbeatCount = "<<heartbeatCount<<endl;
    cout<<"selectedWall = "<<selectedWall<<endl;
    cout<<"player.state = "<<boolToString(player.getState())<<endl;
    cout<<"player.arcLength = "<<player.getLength()<<endl;
    cout<<"player.arcOffset = "<<player.getOffset()<<endl;
    cout<<"player.occupationA1 = "<<player.getOccupationA1()<<endl;
    cout<<"player.occupationA2 = "<<player.getOccupationA2()<<endl;
    cout<<"player.arcRadius = "<<player.getRadius()<<endl;
    cout<<endl;
    cout<<"wall0.state = "<<boolToString(wall0.getState())<<endl;
    cout<<"wall0.arcLength = "<<wall0.getLength()<<endl;
    cout<<"wall0.arcOffset = "<<wall0.getOffset()<<endl;
    cout<<"wall0.occupationA1 = "<<wall0.getOccupationA1()<<endl;
    cout<<"wall0.occupationA2 = "<<wall0.getOccupationA2()<<endl;
    cout<<"wall0.arcRadius = "<<wall0.getRadius()<<endl;
    cout<<endl;
    cout<<"wall1.state = "<<boolToString(wall1.getState())<<endl;
    cout<<"wall1.arcLength = "<<wall1.getLength()<<endl;
    cout<<"wall1.arcOffset = "<<wall1.getOffset()<<endl;
    cout<<"wall1.occupationA1 = "<<wall1.getOccupationA1()<<endl;
    cout<<"wall1.occupationA2 = "<<wall1.getOccupationA2()<<endl;
    cout<<"wall1.arcRadius = "<<wall1.getRadius()<<endl;
    cout<<endl;
    cout<<"wall2.state = "<<boolToString(wall2.getState())<<endl;
    cout<<"wall2.arcLength = "<<wall2.getLength()<<endl;
    cout<<"wall2.arcOffset = "<<wall2.getOffset()<<endl;
    cout<<"wall2.occupationA1 = "<<wall2.getOccupationA1()<<endl;
    cout<<"wall2.occupationA2 = "<<wall2.getOccupationA2()<<endl;
    cout<<"wall2.arcRadius = "<<wall2.getRadius()<<endl;
    cout<<endl;
    cout<<"wall3.state = "<<boolToString(wall3.getState())<<endl;
    cout<<"wall3.arcLength = "<<wall3.getLength()<<endl;
    cout<<"wall3.arcOffset = "<<wall3.getOffset()<<endl;
    cout<<"wall3.occupationA1 = "<<wall3.getOccupationA1()<<endl;
    cout<<"wall3.occupationA2 = "<<wall3.getOccupationA2()<<endl;
    cout<<"wall3.arcRadius = "<<wall3.getRadius()<<endl;
    cout<<endl;
    cout<<"wall4.state = "<<boolToString(wall4.getState())<<endl;
    cout<<"wall4.arcLength = "<<wall4.getLength()<<endl;
    cout<<"wall4.arcOffset = "<<wall4.getOffset()<<endl;
    cout<<"wall4.occupationA1 = "<<wall4.getOccupationA1()<<endl;
    cout<<"wall4.occupationA2 = "<<wall4.getOccupationA2()<<endl;
    cout<<"wall4.arcRadius = "<<wall4.getRadius()<<endl;
    cout<<endl;
    cout<<"wall5.state = "<<boolToString(wall5.getState())<<endl;
    cout<<"wall5.arcLength = "<<wall5.getLength()<<endl;
    cout<<"wall5.arcOffset = "<<wall5.getOffset()<<endl;
    cout<<"wall5.occupationA1 = "<<wall5.getOccupationA1()<<endl;
    cout<<"wall5.occupationA2 = "<<wall5.getOccupationA2()<<endl;
    cout<<"wall5.arcRadius = "<<wall5.getRadius()<<endl;
    cout<<endl;
}

bool checkCollision()
{
    if(player.getRadius() == wall0.getRadius() || player.getRadius()+1 == wall0.getRadius() || player.getRadius()-1 == wall0.getRadius())
    {
        if(player.getOccupationA1() > wall0.getOccupationA1() && player.getOccupationA1() < wall0.getOccupationA2())
        {
            return true;
        }
        else if(player.getOccupationA2() > wall0.getOccupationA1() && player.getOccupationA2() < wall0.getOccupationA2())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(player.getRadius() == wall1.getRadius() || player.getRadius()+1 == wall1.getRadius() || player.getRadius()-1 == wall1.getRadius())
    {
        if(player.getOccupationA1() > wall1.getOccupationA1() && player.getOccupationA1() < wall1.getOccupationA2())
        {
            return true;
        }
        else if(player.getOccupationA2() > wall1.getOccupationA1() && player.getOccupationA2() < wall1.getOccupationA2())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(player.getRadius() == wall2.getRadius() || player.getRadius()+1 == wall2.getRadius() || player.getRadius()-1 == wall2.getRadius())
    {
        if(player.getOccupationA1() > wall2.getOccupationA1() && player.getOccupationA1() < wall2.getOccupationA2())
        {
            return true;
        }
        else if(player.getOccupationA2() > wall2.getOccupationA1() && player.getOccupationA2() < wall2.getOccupationA2())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(player.getRadius() == wall3.getRadius() || player.getRadius()+1 == wall3.getRadius() || player.getRadius()-1 == wall3.getRadius())
    {
        if(player.getOccupationA1() > wall3.getOccupationA1() && player.getOccupationA1() < wall3.getOccupationA2())
        {
            return true;
        }
        else if(player.getOccupationA2() > wall3.getOccupationA1() && player.getOccupationA2() < wall3.getOccupationA2())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(player.getRadius() == wall4.getRadius() || player.getRadius()+1 == wall4.getRadius() || player.getRadius()-1 == wall4.getRadius())
    {
        if(player.getOccupationA1() > wall4.getOccupationA1() && player.getOccupationA1() < wall4.getOccupationA2())
        {
            return true;
        }
        else if(player.getOccupationA2() > wall4.getOccupationA1() && player.getOccupationA2() < wall4.getOccupationA2())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(player.getRadius() == wall5.getRadius() || player.getRadius()+1 == wall5.getRadius() || player.getRadius()-1 == wall5.getRadius())
    {
        if(player.getOccupationA1() > wall5.getOccupationA1() && player.getOccupationA1() < wall5.getOccupationA2())
        {
            return true;
        }
        else if(player.getOccupationA2() > wall5.getOccupationA1() && player.getOccupationA2() < wall5.getOccupationA2())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void dropWall0()
{
    wall0.setLength(90);
    wall0.setOffset(50); //RANDOM NUMBER BETWEEN 0 and 360-(arcLength/2)
    wall0.setRadius((windowX/2)+(windowX/4));
    wall0.calcOccupationA1();
    wall0.calcOccupationA2();
    while(wall0.getOccupationA2() > 360)
    {
        cout<<"wall0.occupationA2 is greater than 360: "<<wall0.getOccupationA2()<<endl;
        int i = wall0.getOccupationA2();
        wall0.setOccupationA2(i-360);
    }
    cout<<"while loop ended: "<<wall0.getOccupationA2()<<endl;
}

void dropWall1()
{
    wall1.setLength(135);
    wall1.setOffset(185); //RANDOM NUMBER BETWEEN 0 and 360-(arcLength/2)
    wall1.setRadius((windowX/2)+(windowX/4));
    wall1.calcOccupationA1();
    wall1.calcOccupationA2();
}

void dropWall2()
{
    wall2.setLength(180);
    wall2.setOffset(150); //RANDOM NUMBER BETWEEN 0 and 360-(arcLength/2)
    wall2.setRadius((windowX/2)+(windowX/4));
    wall2.calcOccupationA1();
    wall2.calcOccupationA2();
}

void dropWall3()
{
    wall3.setLength(270);
    wall3.setOffset(135); //RANDOM NUMBER BETWEEN 0 and 360-(arcLength/2)
    wall3.setRadius((windowX/2)+(windowX/4));
    wall3.calcOccupationA1();
    wall3.calcOccupationA2();
}

void dropWall4()
{
    wall4.setLength(270);
    wall4.setOffset(225); //RANDOM NUMBER BETWEEN 0 and 360-(arcLength/2)
    wall4.setRadius((windowX/2)+(windowX/4));
    wall4.calcOccupationA1();
    wall4.calcOccupationA2();
}

void dropWall5()
{
    wall5.setLength(330);
    wall5.setOffset(165); //RANDOM NUMBER BETWEEN 0 and 360-(arcLength/2)
    wall5.setRadius((windowX/2)+(windowX/4));
    wall5.calcOccupationA1();
    wall5.calcOccupationA2();
}
