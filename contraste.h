#pragma once
#include "filtre.h"

class contraste : public filtre {
private:
    std::string Name;
    double alpha; // Facteur de contraste (1.0 - 3.0)
    int beta;     // Luminosité (0 - 100)

public:
    contraste();
    void traitement(cv::Mat * f) override;
    std::string getterName() override;
};
