//
// LineBrush.cpp
//
// The implementation of Line Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "linebrush.h"
#include "math.h"
extern float frand();

LineBrush::LineBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void LineBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//int size = pDoc->getSize();
	int size = pDoc->getLineWidth();
	glLineWidth((float)size );
	
	//glPointSize( (float)size );
	m_cur = target;
	m_prev = target;
	BrushMove( source, target );
}

void LineBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "LineBrush::BrushMove  document is NULL\n" );
		return;
	}
	int size = pDoc->getSize();
	double angle = pDoc->getLineAngle()*2*M_PI/360.0;;
	m_prev = m_cur;
	m_cur = target;
	if (pDoc->m_pCurrentStroke == BRUSH_DIRECTION ) {
		angle = pDoc->calAngle(m_cur.x - m_prev.x, m_cur.y - m_prev.y);
	}


	int alpha = pDoc->getAlpha();
	glBegin( GL_LINES );
		SetColor( source );
		glVertex2d( target.x - size/2 * cos(angle), target.y - size/2 * sin(angle) );
		glVertex2d( target.x + size/2 * cos(angle), target.y + size/2 * sin(angle) );

	glEnd();
}

void LineBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);
}

