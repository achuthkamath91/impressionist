//
// RightMouse.cpp
//
// The implementation of Scatterred Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "RightMouse.h"


extern float frand();

RightMouse::RightMouse( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	startCoord = NULL;
}

void RightMouse::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	startCoord = new Point(target);
	int size = pDoc->getSize();
	glPointSize( 1);
	glLineWidth(1);

	BrushMove( source, target );
}

void RightMouse::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "RightMouse::BrushMove  document is NULL\n" );
		return;
	}
	int size = pDoc->getSize();
	//int i, p_x, p_y, j;
	glBegin( GL_LINES );	
		glVertex2d(startCoord->x, startCoord->y);
		glVertex2d(target.x, target.y);
		glColor3f(0.0,1.0,0.0);
	glEnd();
}

void RightMouse::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);
	delete startCoord;
	startCoord = NULL;
}

