//
// GaussianBlurbrush.cpp
//
// The implementation of Gaussian blur Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "GaussianBlurbrush.h"
#include "math.h"

extern float frand();
//extern int irand(int max);

GaussianBlurbrush::GaussianBlurbrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
}

void GaussianBlurbrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//int size = pDoc->getSize();
	glPointSize( 1 );
	BrushMove( source, target );
}

void GaussianBlurbrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "GaussianBlurbrush::BrushMove  document is NULL\n" );
		return;
	}
	float alpha_value = pDoc->getAlpha();
	int size = pDoc->getSize(),i,j;
	glBegin(GL_POINTS);
	for (i = -size / 2; i <= size / 2; i++) {
		for (j = -size / 2; j <= size / 2; j++) {
			SetGaussianColor(Point(source.x + i, source.y + j),alpha_value);
			glVertex2d(target.x + i, target.y + j);
		}
	}
	glEnd();
}

void GaussianBlurbrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	//glDisable(GL_BLEND);
}

void GaussianBlurbrush::SetGaussianColor(const Point source ,float alpha) {

	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;
	GLdouble GaussianKernel[9] =
	{	0.0625, 0.125, 0.0625,
		0.125, 0.25, 0.125,
		0.0625, 0.125, 0.0625,
	};
	GLfloat red = 0.0;
	GLfloat green = 0.0;
	GLfloat blue = 0.0;
	int index = 0;
	GLubyte tempColor[3];
	GLubyte color[3];
	GLfloat color1[3];
	GLfloat tempColor1[3];
	for (int i = -1; i <= 1; i += 1)
	{
		for (int j = -1; j <= 1; j += 1)
		{
			memcpy(tempColor, pDoc->GetOriginalPixel(source.x + i, source.y + j), 3);
			for (int k = 0; k < 3; k++)
			{
				tempColor1[k] = (float)tempColor[k];
			}
			red = red + tempColor1[0] * GaussianKernel[index];
			green = green + tempColor1[1] * GaussianKernel[index];
			blue = blue + tempColor1[2] * GaussianKernel[index];
			index++;
			//printf("red is %d:",&red);
		}
	}
	//printf("tempColor is :%d",&tempColor);
	if (red > 255){
		red = 255;
	} 
	if (green > 255){
		green = 255;
	} 
	if (blue > 255){
		blue = 255;
	} 
	if (red < 0){
		 red = 0;
	}
	if (green < 0){
		green = 0;
	} 
	if (blue < 0){
		 blue = 0;
	}
	color1[0] = red;
	color1[1] = green;
	color1[2] = blue;
	
	//adding alpha to the generated colors
	color[0] = (GLubyte)color1[0] * alpha;
	color[1] = (GLubyte)color1[1] * alpha;
	color[2] = (GLubyte)color1[2] * alpha;
	glColor3ubv(color);
}