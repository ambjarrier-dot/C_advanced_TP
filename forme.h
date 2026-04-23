#pragma once
#include "filtre.h"
#include <string>

class forme : public filtre {
private:
    std::string Name;

public:
    forme();
    void traitement(cv::Mat * f) override;
    std::string getterName() override;
};
