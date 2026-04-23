#pragma once
#include "filtre.h"
class hough : public filtre {
private:
public:
    string Name;
    void traitement(Mat *);
    string getterName();
    hough();
    ~hough();
};
