//
// Rightmouseh.h
//
// The header file for Right Click line. 
//

#ifndef RIGHTMOUSE_H
#define RIGHTMOUSE_H

#include "ImpBrush.h"

class RightMouse : public ImpBrush
{
public:
	RightMouse( ImpressionistDoc* pDoc = NULL, char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
	Point* startCoord;
};

#endif