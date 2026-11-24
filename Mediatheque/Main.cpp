#include <iostream>
#include <memory>
#include <vector>

#include "Document.h"
#include "Livre.h"
#include "DVD.h"
#include "Magazine.h"


void testerEmprunt(IEmpruntable& objet)
{

    std::cout << objet.estDisponible() << std::endl;
    objet.emprunter();
    objet.emprunter();

    objet.retourner();

    std::cout << objet.estDisponible() << std::endl;
}



int main() {
    std::vector<Document*> documents;

    documents.push_back(new Livre("Theoreme sur la courbure de bananes", "Donkey Kong", 761824593));

    documents.push_back(new Livre("Ma vie, Mon combat", "Gabriel", 5000));

    documents.push_back(new DVD("La porte bleue sur la montagne rose pendant la pluie d'acide rouge", "Un francais random", 62));

    documents.push_back(new Magazine("Aprrendre l'alphabet chaque jour", 9));


    for (const auto& document : documents) {
        document->afficher();
        std::cout << std::endl;
    }

    Livre d("Ma vie, Mon combat", "Gabriel", 5000);
    testerEmprunt(d);
}