//
//  GameArc.h
//  Potent Game02
//
//  C++ Class Header File
//
//  Created by Austin Jackson,
//  Last modified on January 9, 2014.
//
//  http://www.ruthlessphysics.com/potent/
//

#include <iostream>
#include "Intro.h"

using namespace std;

class GameArc
{
	public:
		int arcOffset;
		int arcRadius;
		int arcLength;
		int occupationA1; //A1 occupation in degrees, used for collision checking
		int occupationA2; //A2 occupation in degrees, used for collision checking
		bool state;
		
		int getOffset()
		{
			return arcOffset;
		}
		void setOffset(int newOffset)
		{
			arcOffset = newOffset;
		}
		void addOffset(int inc)
		{
			arcOffset += inc;
		}
		void subtractOffset(int dec)
		{
			arcOffset -= dec;
		}
		
		int getRadius()
		{
			return arcRadius;
		}
		void setRadius(int newRadius)
		{
			arcRadius = newRadius;
		}
		void addRadius(int inc)
		{
			arcRadius += inc;
		}
		void subtractRadius(int dec)
		{
			arcRadius -= dec;
		}
		
		int getLength()
		{
			return arcLength;
		}
		void setLength(int newLength)
		{
			arcLength = newLength;
		}
		void addLength(int inc)
		{
			arcLength += inc;
		}
		void subtractLength(int dec)
		{
			arcLength -= dec;
		}
		
		int getOccupationA1()
		{
			return occupationA1;
		}
		void calcOccupationA1()
		{
			occupationA1 = (getLength()/2) * (-1) + getOffset();
		}
        void setOccupationA1(int newOccupation)
        {
            //In semi-rare cases, we may need to manually override occupation to insure collision
            occupationA1 = newOccupation;
        }
		
		int getOccupationA2()
		{
			return occupationA2;
		}
		void calcOccupationA2()
		{
			occupationA2 = (getLength()/2) + getOffset();
		}
		void setOccupationA2(int newOccupation)
		{
            //In semi-rare cases, we may need to manually override occupation to insure collision
            occupationA2 = newOccupation;
        }
		
        bool getState()
        {
            return state;
        }
        void setState(bool newState)
        {
            state = newState;
        }
};
