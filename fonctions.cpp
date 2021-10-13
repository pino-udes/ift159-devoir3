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

vector<vector<float>> classerValeurs(float min, float max, int nbCategories, vector<float> valeurs)
{
    cout << endl << "classerValeurs" << endl;
    float intervalleValeurs;
    float tailleIntervalle;
    vector<vector<float>> histogramme;

    intervalleValeurs =  max - min;
    tailleIntervalle = intervalleValeurs / nbCategories;

    cout << endl << "Taille intervalle " << tailleIntervalle << endl;

    for (int i = 1; i < nbCategories+1; i++)
    {
        cout << endl << "Catégorie " << i << endl;

        vector<float> valeursIntervalle;

        if (i == 1)
        {
            for (int element : valeurs)
            {
                if (element < tailleIntervalle )
                    valeursIntervalle.push_back(element);
            }
        }
        else if (i == nbCategories)
        {
            for (int element : valeurs)
            {
                if (element >= (tailleIntervalle * i))
                    valeursIntervalle.push_back(element);
            }
        }
        else
        {
            for (int element : valeurs)
            {
                if (element >= tailleIntervalle * (i-1) && element < tailleIntervalle * (i +1))
                    valeursIntervalle.push_back(element);
            }
        }

        histogramme.push_back(valeursIntervalle);

    }

    for (vector<float> item : histogramme)
    {
        cout << endl;
        for (float item2 : item){
            cout << item2 << " ";
        }
    }

    return histogramme;
}