//
// ScatteredLineBrush.cpp
//
// The implementation of Scatterred Line Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredlinebrush.h"
#include "math.h"

extern float frand();
extern int irand(int max);

ScatteredLineBrush::ScatteredLineBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void ScatteredLineBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//int size = pDoc->getSize();
	int size = pDoc->getLineWidth();
	glLineWidth((float)size);
	BrushMove( source, target );
}

void ScatteredLineBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "ScatteredLineBrush::BrushMove  document is NULL\n" );
		return;
	}

	int altSize = irand(4) + 1,i,size = pDoc->getSize();
	int rX,rY,pointX1,pointY1,pointX2,pointY2;
	double angle = pDoc->getLineAngle();
	
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable( GL_BLEND );
	glBegin( GL_LINES );
	
	for(i=0; i<altSize; i++) {
		rX = (frand() - 0.5) * size;
		rY = (frand() - 0.5) * size;
		SetColor(Point(target.x - rX, target.y - rY));
		pointX1 = (target.x - rX - size / 2 * cos(angle));
		pointY1 = (target.y - rY - size / 2 * sin(angle)); 
		pointX2 = (target.x - rX + size / 2 * cos(angle)); 
		pointY2 = (target.y - rY + size / 2 * sin(angle)); 
		glVertex2d( pointX1 , pointY1 );
		glVertex2d( pointX2 , pointY2 );
	}

	glEnd();
}

void ScatteredLineBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);
}

