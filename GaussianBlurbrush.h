//
// GaussianBlurbrush.h
//
// The header file for Gaussian Blur Brush. 
//

#ifndef GAUSSIANBLURBRUSH_H
#define GAUSSIANBLURBRUSH_H

#include "ImpBrush.h"

class GaussianBlurbrush : public ImpBrush
{
public:
	GaussianBlurbrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
	void SetGaussianColor(const Point source,float alpha);
};

#endif