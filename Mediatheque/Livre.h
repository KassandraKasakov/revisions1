#pragma once
#include "Document.h"
#include "IEmpruntable.h"

class Livre : public Document, public IEmpruntable
{
public:
	Livre(const std::string& titre, const std::string& auteur, const int& pages);

	void afficher() const override;

	bool emprunter() override;
	bool retourner() override;
	bool estDisponible() const override;
protected:
	std::string auteur_;
	int pages_;
	bool disponible_ = true;
};

