#include "hough.h"

hough::hough()
{
    Name = "hough";
}

hough::~hough()
{
}

void hough::traitement(Mat* f)
{
    Mat gray, edges;

    cvtColor(*f, gray, COLOR_BGR2GRAY);
    
    // Flou léger pour lisser sans perdre les contours
    GaussianBlur(gray, gray, Size(3, 3), 1);
    
    // Seuils Canny plus bas pour attraper plus de contours
    Canny(gray, edges, 30, 90);

    vector<Vec4i> lines;
    HoughLinesP(
        edges,
        lines,
        1,
        CV_PI/180,
        40,       // seuil plus bas = plus de lignes détectées
        30,       // longueur min réduite
        15        // écart max augmenté = fusionne mieux les segments
    );

    for (const Vec4i& l : lines) {
        line(*f, Point(l[0], l[1]), Point(l[2], l[3]),
             Scalar(0, 0, 255), 2, LINE_AA);
    }
}

string hough::getterName()
{
    return Name;
}
