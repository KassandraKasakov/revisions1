#pragma once
#include "Document.h"

class Magazine : public Document
{
public:
	Magazine(const std::string& titre, const int& numero);
	void afficher() const override;
protected:
	int numero_;
};

