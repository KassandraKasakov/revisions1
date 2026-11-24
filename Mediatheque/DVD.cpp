#include "DVD.h"
#include <iostream>

DVD::DVD(const std::string& titre, const std::string& realisateur, const int& duree) : Document::Document(titre)
{
	realisateur_ = realisateur;
	duree_ = duree;
}

void DVD::afficher() const
{
	std::cout << "DVD : " << getTitre() << std::endl;
	std::cout << "Realisateur : " << realisateur_ << std::endl;
	std::cout << "Duree : " << duree_ << " minutes" << std::endl;
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

bool DVD::emprunter()
{
	if (estDisponible())
	{
		disponible_ = false;
		return true;
	}
	return false;
}

bool DVD::retourner()
{
	if (!estDisponible())
	{
		disponible_ = true;
		return true;
	}
	return false;
}

bool DVD::estDisponible() const
{
	return disponible_;
}
