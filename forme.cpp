#include "forme.h"
#include <vector>

using namespace cv;
using namespace std;

forme::forme() { Name = "forme"; }

void forme::traitement(Mat * f) {
    if (f->empty()) return;

    Mat gray, thresh;
    cvtColor(*f, gray, COLOR_BGR2GRAY);
    threshold(gray, thresh, 127, 255, THRESH_BINARY);

    vector<vector<Point>> contours;
    findContours(thresh, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    for (size_t i = 0; i < contours.size(); i++) {
        if (contourArea(contours[i]) > 1000) {
            
            vector<Point> approx;
            double peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], approx, 0.02 * peri, true);

            vector<vector<Point>> contoursToDraw = {approx};
            
            Scalar color = (approx.size() == 4) ? Scalar(0, 255, 0) : Scalar(0, 0, 255);
            
            drawContours(*f, contoursToDraw, -1, color, 3);

            Point pos = approx[0];
            string label = "Sommets: " + to_string(approx.size());
            if(approx.size() == 4) label = "KAPLA (Rectangle)";
            
            putText(*f, label, pos, FONT_HERSHEY_SIMPLEX, 0.6, color, 2);

            // AJOUT : calcul et affichage du centre via les moments
            if (approx.size() == 4) {
                Moments M = moments(approx);
                Point centre(M.m10 / M.m00, M.m01 / M.m00);
                circle(*f, centre, 5, Scalar(0, 255, 255), -1);
                putText(*f, "Centre", centre + Point(8, 0), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255), 1);
            }
        }
    }
}

string forme::getterName() { return Name; }
