//
// ScatteredCircleBrush.cpp
//
// The implementation of Scatterred Circle Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredcirclebrush.h"
#include "math.h"

extern float frand();
extern int irand(int max);

ScatteredCirclebrush::ScatteredCirclebrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
}

void ScatteredCirclebrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//int size = pDoc->getSize();
	glPointSize( 1 );
	BrushMove( source, target );
}

void ScatteredCirclebrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "ScatteredCircleBrush::BrushMove  document is NULL\n" );
		return;
	}

	int altSize = irand(4) + 1,i,j,size = pDoc->getSize();
	double rX,rY,Deg2rad = M_PI/180;
	float radius= size / 2;
	
	
	for(i = 0; i < altSize; i++) {
		rX = target.x - radius + irand(size);
		rY = target.y - radius + irand(size);
		glBegin(GL_LINE_LOOP);
		//SetColor(Point(target.x - rX, target.y - rY));
		SetColor(Point(rX, rY));
		for(j=0;j<360;j++){	
			double dInRad = j*Deg2rad;
			glVertex2f(cos(dInRad)*radius + rX,sin(dInRad)*radius + rY);
			glVertex2f(rX,rY);
		}	
	}

	glEnd();
}

void ScatteredCirclebrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);
}

