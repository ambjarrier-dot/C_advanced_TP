#include "gris.h"



gris::gris()
{
	Name = "gris";
}


gris::~gris()
{
}

void gris::traitement(Mat * f) {

	int lengthPicture = f->cols;
	int heightPicture = f->rows;

    size_t step = f->step;

	for (int y = 0; y < heightPicture; y++) {
		for (int x = 0; x < lengthPicture; x++) {
            
            int pixelIndex = y* step + x * 3;

            unsigned char b = f->data[pixelIndex + BLUE];
            unsigned char  v = f->data[pixelIndex + GREEN];
            unsigned char  r = f->data[pixelIndex + RED];
			
            unsigned char moyenne = (b+v+r)/3;

            f->data[pixelIndex + BLUE]  = moyenne ;
			f->data[pixelIndex + GREEN]  = moyenne ;
			f->data[pixelIndex + RED] = moyenne ;

		}
	}
}
string gris::getterName() {

	return Name;
}
