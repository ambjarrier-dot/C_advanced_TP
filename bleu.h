#pragma once

#define BLUE 0
#define GREEN 1
#define RED 2

#include "filtre.h"
class bleu : public filtre
{
private:
	string Name;
public:
	void traitement(Mat *);
	string getterName();

	bleu();
	~bleu();
};

