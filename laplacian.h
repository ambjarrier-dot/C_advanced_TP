#pragma once

#include "filtre.h"
#include <string>

class laplacian : public filtre
{
private:
    std::string Name;

public:
    laplacian();
    ~laplacian();

    // On utilise cv::Mat pour être explicite
    void traitement(cv::Mat * f) override;
    std::string getterName() override;
};
