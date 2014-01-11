//
//  LibVenom.h
//  Potent "Venom" Helpful Header
//
//  C++ Header File
//
//  Created by Austin Jackson,
//  Last modified on January 10, 2014.
//
//  http://www.ruthlessphysics.com/potent/
//

#include <string>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>

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

//WINBGIm FILL STYLES
#define EMPTY_FILL 0 //Fill with background color
#define SOLID_FILL 1 //Solid fill
#define LINE_FILL 2 //Fill with ---
#define LTSLASH_FILL 3 //Fill with ///
#define SLASH_FILL 4  //Fill with ///, thick lines
#define BKSLASH_FILL 5 //Fill with \\\, thick lines
#define LTBKSLASH_FILL 6 //Fill with \\\
#define HATCH_FILL 7 //Light hatch fill
#define XHATCH_FILL 8 //Heavy cross-hatch fill
#define INTERLEAVE_FILL 9 //Interleaving line fill
#define WIDE_DOT_FILL 10 //Widely spaced dot fill
#define CLOSE_DOT_FILL 11 //Closely spaced dot fill

//KEYBOARD KEYS
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACEBAR 32
#define KEY_ESC 27

//MATH CONSTANTS
#define PI 3.14159265


using namespace std;

void pauseConsole()
{
    cout<<"Press any key to continue . . ."<<endl;
	getch();
}

string boolToString(bool A)
{
    if(A == true)
    {
        return "true";
    }
    else if(A == false)
    {
        return "false";
    }
    else
    {
        return "ERROR";
    }
}

bool charToBool(char A)
{
	if((A == 'Y' || A == 'y') || (A == 'T' || A == 't'))
	{
		return true;
	}
	else if((A == 'N' || A == 'n') || (A == 'F' || A == 'f'))
	{
		return false;
	}
	else
	{
		return false;
	}
}

int randIntBetween(int from, int to)
{
    return rand() % to + from;
}

string combineStrings(string A, string B)
{
    return A+B;
}
