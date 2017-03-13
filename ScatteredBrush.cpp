//
// ScatteredBrush.cpp
//
// The implementation of Scatterred Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredbrush.h"
#include <random>
#include "math.h"

extern float frand();
extern int irand(int max);

ScatteredPointBrush::ScatteredPointBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void ScatteredPointBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();
	glPointSize( 1 );

	BrushMove( source, target );
}

void ScatteredPointBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "ScatteredPointBrush::BrushMove  document is NULL\n" );
		return;
	}
	int size = pDoc->getSize();
	//int altSize = 0;
	int i, p_x, p_y, j;
	glBegin( GL_POINTS );	
		
		for(p_x = target.x - (size >> 1), i = 0; i <= size; i++, p_x++) {

			for(p_y = target.y - (size >> 1), j = 0; j <= size; j++, p_y++) {

				if(!irand(5)) {

					SetColor( Point(p_x, p_y) );
					glVertex2d(p_x, p_y);

				}
			}
		}

	glEnd();
}

void ScatteredPointBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);
}

