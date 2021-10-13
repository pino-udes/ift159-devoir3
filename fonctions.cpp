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

vector<int> classerValeurs(float min, float max, int nbCategories, vector<float> valeurs)
{
    //cout << endl << "classerValeurs" << endl;
    float intervalleValeurs;
    float tailleIntervalle;
    vector<int> histogramme;

    intervalleValeurs =  max - min;
    tailleIntervalle = intervalleValeurs / nbCategories;

    histogramme.reserve(nbCategories);

    //cout << endl << "Taille intervalle " << tailleIntervalle << endl;

    vector<float> categories;

    /* debug */
    cout << "" << endl;
    cout << "Les intervalles sont: ";
    /* end debnug */

    for (int i = 1; i <= nbCategories; i++)
    {
        categories.push_back((tailleIntervalle * i)+min);
        cout << (tailleIntervalle * i)+min << " ";
    }

    /* debug */
    cout << endl;
    /* end debnug */

    if (nbCategories == 1)
    {
        histogramme.push_back(valeurs.size());
        return histogramme;
    }


    for (int i = 0; i < nbCategories; i++)
    {
        int compteur = 0;

        if (i == 0)
        {
            //cout << "\n if category is " << categories.at(i) << endl;
            for (float element : valeurs)
            {

                if (element < categories.at(i))
                    compteur += 1;
            }
        }

        else if (i == nbCategories-1)
        {
            //cout << "\n elesif category is " << categories.at(i) << endl;
            for (float element : valeurs)
            {

                if (element >= categories.at(i-1))
                    compteur += 1;
            }
        }
        else
        {
            //cout << "\n else category is " << categories.at(i) << endl;
            for (float element : valeurs)
            {

                if (element >= categories.at(i-1) && element < categories.at(i))
                    compteur += 1;
            }
        }

        histogramme.push_back(compteur);

    }

    /* debug */
    cout << endl << "Classement" << endl;
    for (int item : histogramme)
    {
        cout << item << endl;
    }
    /* end debug */

    return histogramme;
}

void afficherHisto(vector<int> histogramme)
{
    for (int nbValeurs : histogramme)
    {
        for (int i = 0; i < nbValeurs; i++)
        {
            cout << "*";
        }
        cout << endl;

    }
}