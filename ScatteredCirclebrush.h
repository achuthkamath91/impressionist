//
// ScatteredCirclebrush.h
//
// The header file for Scattered Circle Brush. 
//

#ifndef SCATTEREDCIRCLEBRUSH_H
#define SCATTEREDCIRCLEBRUSH_H

#include "ImpBrush.h"

class ScatteredCirclebrush : public ImpBrush
{
public:
	ScatteredCirclebrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
};

#endif