#pragma once
#include "Document.h"
#include "IEmpruntable.h"

class DVD : public Document, public IEmpruntable
{
public:
	DVD(const std::string& titre, const std::string& realisateur, const int& duree);
	void afficher() const override;

	bool emprunter() override;
	bool retourner() override;
	bool estDisponible() const override;
protected:
	std::string realisateur_;
	int duree_;
	bool disponible_ = true;
};

