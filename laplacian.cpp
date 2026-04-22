#include "laplacian.h"

using namespace cv;
using namespace std;

laplacian::laplacian() {
    Name = "laplacian";
}

laplacian::~laplacian() {}

void laplacian::traitement(Mat * f) {
    if (f->empty()) return;

    Mat gray, edges;

    // 1. Conversion en niveaux de gris
    // Le Laplacien est beaucoup plus efficace sur une image à un seul canal
    cvtColor(*f, gray, COLOR_BGR2GRAY);

    // 2. Réduction du bruit avec un flou Gaussien
    // Cela évite de détecter des "faux" bords dus au grain de la vidéo
    GaussianBlur(gray, gray, Size(3, 3), 0);

    // 3. Application de l'opérateur Laplacien d'OpenCV
    // CV_16S permet de stocker des valeurs négatives lors du calcul des dérivées
    Laplacian(gray, edges, CV_16S, 3);

    // 4. Conversion du résultat en 8 bits (0-255)
    // Cette fonction prend la valeur absolue et sature le résultat
    convertScaleAbs(edges, edges);

    // 5. Conversion retour en BGR
    // IMPORTANT : On repasse en 3 canaux pour que tes autres filtres (rouge, bleu) 
    // ne plantent pas s'ils s'appliquent après celui-ci.
    cvtColor(edges, *f, COLOR_GRAY2BGR);
}

string laplacian::getterName() {
    return Name;
}