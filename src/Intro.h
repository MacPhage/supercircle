//
//  Intro.h
//  Potent Intro
//
//  C++ Header File
//
//  Created by Austin Jackson,
//  Last modified on December 15, 2013.
//
//  http://www.ruthlessphysics.com/potent/
//

#include "MenuScreen.h"

//WINBGIm COLORS
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

using namespace std;

void potentIntro(int winSizeX, int winSizeY)
{
    initwindow(winSizeX, winSizeY, "POTENT Works");
    
    bool isDone = false;
    int A = 0; //Selected radius for drawing pieslices
    int B = 0; //Selected drawing color
    int C = winSizeX/5; //Default circle radius
    int D = -30; //X-intercept for drawing text
    int W = 15; //Independent drawing color
    int R = 25; //Radial extention
    int X1,Y1;
    int delayTime = 20; //Worldwide delay time
    bool P = false; //has the P been drawn?
    bool O = false; //has the O been drawn?
    bool T1 = false; //has the T been drawn?
    bool E = false; //has the E been drawn?
    bool N = false; //has the N been drawn?
    bool T2 = false; //has the T been drawn?
    setbkcolor(0);
    setcolor(15);
    while(isDone == false)
    {
        if(A >= 360)
        {
            B = 0;
            while(P == false)
            {
                B++;
                setcolor(B);
                setfillstyle(1,B);
                outtextxy((winSizeX/2)+D,(winSizeY/2)+(C-15),"P");
                X1 = (winSizeX/2)+(D*3);
                Y1 = (winSizeY/2)+(C+5);
                delay(delayTime);
                if(B >= 15)
                {
                    P = true;
                }
            }
            //cout<<"P = "<<boolToString(P)<<endl;
            D += 10;
            //cout<<"D: "<<D<<endl;
            B = 0;
            while(O == false)
            {
                B++;
                setcolor(B);
                setfillstyle(1,B);
                outtextxy((winSizeX/2)+D,(winSizeY/2)+(C-15),"O");
                delay(delayTime);
                if(B >= 15)
                {
                    O = true;
                }
            }
            //cout<<"O = "<<boolToString(O)<<endl;
            D += 10;
            //cout<<"D: "<<D<<endl;
            B = 0;
            while(T1 == false)
            {
                B++;
                setcolor(B);
                setfillstyle(1,B);
                outtextxy((winSizeX/2)+D,(winSizeY/2)+(C-15),"T");
                delay(delayTime);
                if(B >= 15)
                {
                    T1 = true;
                }
            }
            //cout<<"T1 = "<<boolToString(T1)<<endl;
            D += 10;
            //cout<<"D: "<<D<<endl;
            B = 0;
            while(E == false)
            {
                B++;
                setcolor(B);
                setfillstyle(1,B);
                outtextxy((winSizeX/2)+D,(winSizeY/2)+(C-15),"E");
                delay(delayTime);
                if(B >= 15)
                {
                    E = true;
                }
            }
            //cout<<"E = "<<boolToString(E)<<endl;
            D += 10;
            //cout<<"D: "<<D<<endl;
            B = 0;
            while(N == false)
            {
                B++;
                setcolor(B);
                setfillstyle(1,B);
                outtextxy((winSizeX/2)+D,(winSizeY/2)+(C-15),"N");
                delay(delayTime);
                if(B >= 15)
                {
                    N = true;
                }
            }
            //cout<<"N = "<<boolToString(N)<<endl;
            D += 10;
            //cout<<"D: "<<D<<endl;
            B = 0;
            while(T2 == false)
            {
                B++;
                setcolor(B);
                setfillstyle(1,B);
                outtextxy((winSizeX/2)+D,(winSizeY/2)+(C-15),"T");
                delay(delayTime);
                if(B >= 15)
                {
                    T2 = true;
                }
            }
            //cout<<"T2 = "<<boolToString(T2)<<endl;
            D += 10;
            //cout<<"D: "<<D<<endl;
            //cout<<"isDone = true"<<endl;
            isDone = true;
        }
        else
        {
            //red=4
			//blue=1
			//green=2
			//yellow=14
			if(A >= 40 && A <= 50)
            {
				W = 4;
				setcolor(W);
				setfillstyle(1,W);
				C += R;
			}
			else if(A >= 130 && A <= 140)
            {
                W = 1;
				setcolor(W);
				setfillstyle(1,W);
				C += R;
			}
			else if(A >= 220 && A <= 230)
            {
                W = 2;
				setcolor(W);
				setfillstyle(1,W);
				C += R;
			}
			else if(A >= 310 && A <= 320)
            {
                W = 14;
				setcolor(W);
				setfillstyle(1,W);
				C += R;
			}
            pieslice(winSizeX/2,(winSizeY/2)-(winSizeY/8),A,A+1,C);
            if(W != 15 || W != 7)
            {
				W = 15;
				C = winSizeX/5;
			}
            delay(2);
            if(W == 15)
            {
                setcolor(W);
                setfillstyle(1,W);
                W = 7;
            }
			else if(E == 7)
			{
				setcolor(W);
				setfillstyle(1,W);
				W = 15;
			}
            else
            {
                B = 0;
            }
            //cout<<"A: "<<A<<endl;
            A=A+1;
            
            
        }
    }
    setcolor(DARKGRAY);
    outtextxy(X1,Y1,"ruthlessphysics.com/potent/");
    delay(100);
    setcolor(LIGHTGRAY);
    outtextxy(X1,Y1,"ruthlessphysics.com/potent/");
    delay(100);
    setcolor(WHITE);
    outtextxy(X1,Y1,"ruthlessphysics.com/potent/");
    delay(3000);
    cleardevice();
    closegraph();
}
