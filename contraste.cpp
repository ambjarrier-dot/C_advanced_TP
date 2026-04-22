#include "contraste.h"

using namespace cv;

contraste::contraste() {
    Name = "contraste";
    alpha = 1.5; // Augmente le contraste de 50%
    beta = 10;   // Ajoute un peu de luminosité
}

void contraste::traitement(Mat * f) {
    if (f->empty()) return;

    // convertTo applique : dst = alpha * src + beta
    // C'est beaucoup plus rapide qu'une boucle for manuelle
    f->convertTo(*f, -1, alpha, beta);
}

std::string contraste::getterName() {
    return Name;
}
