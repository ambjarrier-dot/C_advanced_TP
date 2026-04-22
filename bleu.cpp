#include "bleu.h"



bleu::bleu()
{
	Name = "bleu";
}


bleu::~bleu()
{
}

void bleu::traitement(Mat * f) {

	int lengthPicture = f->cols;
	int heightPicture = f->rows;
	for (int x = 0; x < lengthPicture; x++) {
		for (int y = 0; y < heightPicture; y++) {
		
			// colour filter rouge
			//f->setRed(y, x, 0);
			//f->setBlue(y, x, 0);
			//f->setGreen(y, x, 0);
			f->data[3 * (f->cols * y + x) + GREEN]  = 0 ;
			f->data[3 * (f->cols * y + x) + RED] = 0 ;

		}
	}
}
string bleu::getterName() {

	return Name;
}
