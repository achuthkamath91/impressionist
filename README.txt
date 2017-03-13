working of Impressionist

******************************************************BUild & debug**********************************

Build the impressionist file and then Debug it.

Cliclk file-> Load Image ,then choose an image
Cliclk Brush-> and choose the type of brush, start drawing using the selected type
Thickness is activated when you select lines and Scattered lines.


//////////////Implementation\\\\\\\\\\\\\\\\\\

Scatterd points has files 
Scatteredbrush.h
scatteredbrush.cpp

Major implemetation of the scattered brush is contatined inside scatteredbrush.cpp to create a scattered represenation of points randomly
random function is used to generate n random points near the cursor

** Scattered Lines **
ScatteredLinesBrush.h
ScatteredLinesBrush.cpp
Scattered lines is similar to points but this used GL_LINES to draw multiple random lines.

** Scattered Circles **
ScatteredCirclebrush.h
ScatteredCirclebrush.cpp
produces multiple circles with scattered effect

Gaussian implementation is used to blur the image with alpha and size slider.

** Sliders **
New sliders like line width,Angle and Alpha has been added
the sliders send the value to the required part of the code it is written in ImpressionistUI.cpp
Alpha sliders can be used in all brush types.

** choice for rightmouse click **
Right Mouse click is used to draw the lines with appropriate directions.


***********-----**********
Artifact Created from the implementation is Science_board.bmp
Image is clicked at Science Building 3rd Floor Notice board.
The image is impressioned with different types of brushed like line brush, Scattered points,scattered circles,and also with gausian filter,
Alpha(opacity)has been used in the image. 
***********-----**********