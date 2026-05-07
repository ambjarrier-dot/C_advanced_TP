#include "seuil.h"

using namespace cv;
using namespace std;

seuil::seuil() {
    Name = "seuil";
    valeurSeuil = 127; // On coupe à la moitié par défaut
}

seuil::~seuil() {}

void seuil::traitement(Mat * f) {
    if (f->empty()) return;

    Mat gray;

    // 1. On passe en Gris car cv::threshold travaille sur 1 seul canal
    // On vérifie quand même si l'image n'est pas déjà en gris
    if (f->channels() == 3) {
        cvtColor(*f, gray, COLOR_BGR2GRAY);
    } else {
        gray = *f;
    }

    // 2. Application du seuillage binaire
    // Si pixel > 127, il devient 255 (blanc), sinon 0 (noir)
    threshold(gray, gray, valeurSeuil, 255, THRESH_BINARY);

    // 3. On repasse en BGR (3 canaux)
    // Cela permet de ne pas casser tes filtres 'rouge' ou 'bleu' 
    // s'ils sont appliqués après dans la boucle.
    cvtColor(gray, *f, COLOR_GRAY2BGR);
}

string seuil::getterName() {
    return Name;
}
