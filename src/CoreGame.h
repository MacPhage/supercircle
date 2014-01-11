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

int windowX = 400;
int windowY = 400;
char currentKey;
int centerCircleRadius = windowX / 8;
int gameSpeed = 5;
int printOccurence = 0;

void heartbeat();
void sink();
void printAllValues();
void dropWall();

void heartbeat()
{
    //Recalculating occupations before refreshing the screen
    player.calcOccupationA1();
    player.calcOccupationA2();
    wall0.calcOccupationA1();
    wall0.calcOccupationA2();
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


    cleardevice();
    circle(windowX/2,windowY/2,centerCircleRadius); //CENTER CIRCLE
    arc(windowX/2,windowY/2,player.getOccupationA1(),player.getOccupationA2(),player.getRadius()); //THE PLAYER
    if(wall0.getState() == true)
    {
        arc(windowX/2,windowY/2,wall0.getOccupationA1(),wall0.getOccupationA2(),wall0.getRadius());
    }
}

void sink()
{
    //Reduce all wall radius by 1
}

void printAllValues()
{
    printOccurence++;
    cout<<"[ printOccurence = "<<printOccurence<<" ]"<<endl;
    cout<<"player.arcLength = "<<player.getLength()<<endl;
    cout<<"player.arcOffset = "<<player.getOffset()<<endl;
    cout<<"player.occupationA1 = "<<player.getOccupationA1()<<endl;
    cout<<"player.occupationA2 = "<<player.getOccupationA2()<<endl;
    cout<<"player.arcRadius = "<<player.getRadius()<<endl;
}

void dropWall(GameArc falling)
{
    falling.setLength(90);
    falling.setOffset(50); //RANDOM NUMBER BETWEEN 0 and 360
    falling.setRadius(200);
    falling.calcOccupationA1();
    falling.calcOccupationA2();
}
