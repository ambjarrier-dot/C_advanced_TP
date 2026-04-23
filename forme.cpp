#include "forme.h"
#include <vector>

using namespace cv;
using namespace std;

forme::forme() { Name = "forme"; }

void forme::traitement(Mat * f) {
    if (f->empty()) return;

    Mat gray, thresh;
    // 1. Preprocessing (Gris + Seuil)
    cvtColor(*f, gray, COLOR_BGR2GRAY);
    threshold(gray, thresh, 127, 255, THRESH_BINARY);

    // 2. Trouver les contours
    vector<vector<Point>> contours;
    findContours(thresh, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    for (size_t i = 0; i < contours.size(); i++) {
        // On ne traite que les objets d'une certaine taille
        if (contourArea(contours[i]) > 1000) {
            
            vector<Point> approx;
            // Calcul de la précision (epsilon)
            // 0.02 est une valeur standard (2% du périmètre)
            double peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], approx, 0.02 * peri, true);

            // 3. Dessiner le contour simplifié
            // On crée un vecteur de vecteurs car drawContours attend une liste
            vector<vector<Point>> contoursToDraw = {approx};
            
            // Si on a 4 sommets, c'est probablement notre Kapla !
            Scalar color = (approx.size() == 4) ? Scalar(0, 255, 0) : Scalar(0, 0, 255);
            
            drawContours(*f, contoursToDraw, -1, color, 3);

            // 4. Petit bonus : afficher le nombre de sommets
            Point pos = approx[0];
            string label = "Sommets: " + to_string(approx.size());
            if(approx.size() == 4) label = "KAPLA (Rectangle)";
            
            putText(*f, label, pos, FONT_HERSHEY_SIMPLEX, 0.6, color, 2);
        }
    }
}

string forme::getterName() { return Name; }
