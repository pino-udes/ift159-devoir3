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

    // Declaration des variables
    float intervalleValeurs;    // Intervalle max-min des valeurs entrees
    float tailleIntervalle;     // La taille des intervalles l'histogramme
    vector<int> histogramme;    // Le nombre de valeurs par categorie
    vector<float> categories;   // Les seuils des categories

    // Determiner l'intervalle entre le max et le min de la liste des valeurs entrees
    intervalleValeurs =  max - min;
    // Calcul de la taille des intervalles de l'histogramme
    tailleIntervalle = intervalleValeurs / nbCategories;

    // Reserver de l'espace memoire pour l'histogramme
    histogramme.reserve(nbCategories);

    //cout << endl << "Taille intervalle " << tailleIntervalle << endl;


    /* debug */
    cout << "" << endl;
    cout << "Les intervalles sont: ";
    /* end debnug */

    // Calcul des seuils de classement
    for (int i = 1; i <= nbCategories; i++)
    {
        categories.push_back((tailleIntervalle * i)+min);
        cout << (tailleIntervalle * i)+min << " ";
    }

    /* debug */
    cout << endl;
    /* end debnug */

    // Si l'utilisateur specifie une seule categorie, l'ensemble des valeurs est contenu dans une seule categorie
    // donc on compte le nombre de valeurs entree
    if (nbCategories == 1)
    {
        histogramme.push_back(valeurs.size());
        return histogramme;
    }

    // Pour chaque categorie, on lit la liste des valeurs puis on compte le nombre de valeurs sont contenues dans
    // chacune des categories de l'histogramme
    for (int i = 0; i < nbCategories; i++)
    {
        // Initialisation du compteur du nombre de valeur pour une categorie de l'histogramme
        int compteur = 0;

        // S'il s'agit de la premiere categorie de l'histogramme
        if (i == 0)
        {
            //cout << "\n if category is " << categories.at(i) << endl;
            // Parcourir la liste des valeurs
            for (float element : valeurs)
            {
                // Si la valeur est contenue entre la valeur minimum et le seuil superieur de la premiere
                // categorie, incrementer le compteur du nombre de valeur
                if (element > min && element < categories.at(i))
                    compteur += 1;
            }
        }

        // S'il s'agit de la derniere categorie de l'histogramme
        else if (i == nbCategories-1)
        {
            //cout << "\n elesif category is " << categories.at(i) << endl;

            // Parcourir la liste des valeurs
            for (float element : valeurs)
            {
                // Si la valeur est contenue entre le seuil inferieur de la derniere categorie et la maximum des
                // valeurs, incrementer le compteur du nombre de valeur
                if (element >= categories.at(i-1))
                    compteur += 1;
            }
        }

        // S'il s'agit d'une categorie de l'histogramme autre que la premiere ou la derniere
        else
        {
            //cout << "\n else category is " << categories.at(i) << endl;

            // Parcourir la liste des valeurs
            for (float element : valeurs)
            {
                // Si la valeur est contenue entre le seuil inferieur de la categorie et le seuil inferieur de la
                // prochaine categorie, incrementer le compteur du nombre de valeur
                if (element >= categories.at(i-1) && element < categories.at(i))
                    compteur += 1;
            }
        }

        // Constituer l'histogramme en ajouter le nombre de valeurs contenues dans la categorie
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