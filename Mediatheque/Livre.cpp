#include "Livre.h"
#include <iostream>

Livre::Livre(const std::string& titre, const std::string& auteur, const int& pages) : Document::Document(titre)
{
	auteur_ = auteur;
	pages_ = pages;
}

void Livre::afficher() const
{
	std::cout << "Livre : " << getTitre() << std::endl;
	std::cout << "Auteur : " << auteur_ << std::endl;
	std::cout << "Pages : " << pages_ << std::endl;
	std::cout << "Statut : ";
	if (estDisponible())
	{
		std::cout << "Disponible" << std::endl;
	}
	else
	{
		std::cout << "Indisponible" << std::endl;
	}
}

bool Livre::emprunter()
{
	if (estDisponible())
	{
		disponible_ = false;
		return true;
	}
	return false;
}

bool Livre::retourner()
{
	if (!estDisponible())
	{
		disponible_ = true;
		return true;
	}
	return false;
}

bool Livre::estDisponible() const
{
	return disponible_;
}
