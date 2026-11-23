#include <iostream>
#include <string>
#include <vector>

struct Joueur {
    int id;
    std::string nom;
    int score;
};

Joueur* trouverParId(std::vector<Joueur>& joueurs, int id)
{

    for (int i = 0;i < joueurs.size();++i)
    {
        if (joueurs[i].id == id)
        {
            return &joueurs[i];

        }
    }
    return nullptr;
}

void selectionnerJoueur(std::vector<Joueur>& joueurs, int &idSelectionne)
{
    int id;
    std::cin >> id;

    if (id == 0 or id > joueurs.size())
    {
        std::cout << "Aucun joueur selectionne!" << std::endl;
        return;
    }

    idSelectionne = trouverParId(joueurs, id)->id;
}

Joueur* trouverDernier(std::vector<Joueur>& joueurs)
{
    if (joueurs.size() == 0)
    {
        std::cout << "Il n'y a pas de joueurs dans le tournoi!" << std::endl;
        return nullptr;
    }
    else
    {
        Joueur* dernier = &joueurs[0];

        for (int i = 1;i < joueurs.size();++i)
        {
            if (joueurs[i].score < dernier->score)
            {
                dernier = &joueurs[i];
            }
        }
        return dernier;
    }
}

bool attribuerBonus(Joueur* joueur, int points)
{
    if (joueur == nullptr or points <= 0)
    {
        return false;
    }
    else
    {
        joueur->score += points;
        std::cout << joueur->nom << " recoit " << points << " points." << std::endl;
        return true;
    }
}

void afficherJoueurs(std::vector<Joueur>& joueurs)
{
    if (joueurs.size() == 0)
    {
        std::cout << "Il n'y a pas de joueurs dans le tournoi!" << std::endl;
    }
    else
    {
        for (int i = 0;i < joueurs.size();++i)
        {
            std::cout << joueurs[i].nom << " : " << joueurs[i].score << std::endl;
        }
    }

}

void inscrireJoueur(std::vector<Joueur>& joueurs, int &prochainId)
{
    std::string nom;
    std::cin >> nom;
    joueurs.push_back({ prochainId, nom, 0 });
    prochainId++;

    std::cout << nom << " est un nouveau joueur du tournoi" << std::endl;
}

int main()
{
    std::vector<Joueur> joueurs{
        {1, "Alice", 12},
        {2, "Bruno", 7},
        {3, "Chloe", 7}
    };
    int idSelectionne = 0;
    int prochainId = 4;
    int choix = -1;


    while (choix != 0)
    {
        std::cin >> choix;

        switch (choix)
        {
        case 1:
            afficherJoueurs(joueurs);
            break;
        case 2:
            inscrireJoueur(joueurs, prochainId);
            break;
        case 3:
            selectionnerJoueur(joueurs, idSelectionne);
            break;
        case 4:
            int points;
            std::cin >> points;
            attribuerBonus(trouverParId(joueurs, idSelectionne), points);
            break;
        case 5:
            attribuerBonus(trouverDernier(joueurs), 3);
        }
    }
    return 0;
}