#include "sobel.h"

sobel::sobel()
{
    Name = "sobel";
}

sobel::~sobel()
{
}

void sobel::traitement(Mat * f) {

    Mat gray, result;

    // Convertir la frame en niveaux de gris
    cvtColor(*f, gray, COLOR_BGR2GRAY);

    // Appliquer Sobel avec OpenCV
    Mat gradX, gradY, absGradX, absGradY;
    Sobel(gray, gradX, CV_16S, 1, 0, 3);
    Sobel(gray, gradY, CV_16S, 0, 1, 3);
    convertScaleAbs(gradX, absGradX);
    convertScaleAbs(gradY, absGradY);
    addWeighted(absGradX, 0.5, absGradY, 0.5, 0, result);

    // Remettre en BGR pour rester compatible avec le pipeline
    cvtColor(result, *f, COLOR_GRAY2BGR);
}

string sobel::getterName() {
    return Name;
}
