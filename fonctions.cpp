/*
 * fichier : fonctions.cpp
 * auteur.e : Anthony Jutras
 * auteur.e : Patrice Pineault
 * description : fichier contenant les fonctions du devoir 3 - Histogramme
 * date : 01/08/2019
 * modification : 04/10/2020, documentation du code
 * modification : 13/10/2021, ajout des fonctions lireValeurs, classerValeurs et afficherHisto
 */


#include <vector>
#include <iostream>
#include <climits>

using namespace std;

vector<float> lireValeurs(int nbValeurs, float &min, float &max)
{
    min = INT_MAX;
    max = INT_MIN;

    vector<float> valeurs;

    for (int nbValeursLues = 0; nbValeursLues <= nbValeurs-1; nbValeursLues++)
    {
        int valeur;
        cout << "Entrez une valeur: ";
        cin >> valeur;
        valeurs.push_back(valeur);

        if (valeur < min)
            min = valeur;

        if (valeur > max)
            max = valeur;
    }

    return valeurs;
}
