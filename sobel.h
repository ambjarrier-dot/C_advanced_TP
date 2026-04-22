#pragma once

#define BLUE 0
#define GREEN 1
#define RED 2

#include "filtre.h"
class sobel : public filtre
{
private:
	string Name;
public:
	void traitement(Mat *);
	string getterName();

	sobel();
	~sobel();
};
