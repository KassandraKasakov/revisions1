#include "Magazine.h"
#include <iostream>

Magazine::Magazine(const std::string& titre, const int& numero) : Document::Document(titre)
{
	numero_ = numero;
}

void Magazine::afficher() const
{
	std::cout << "Magazine : " << getTitre() << std::endl;
	std::cout << "Numero : " << numero_ << std::endl;
}
