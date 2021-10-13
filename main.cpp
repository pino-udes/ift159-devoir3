/*
 * fichier : main.cpp
 * auteur.e : Marie-Flavie Auclair-Fortier
 * description : ... à compléter dans le document d'analyse
 * entrees :
 *      nombre de catégorie
 *      nombre de valeur à lire
 *      valeurs à classer
 * sorties :
 *      Histogramme affiché sous forme d'étoiles, chaque catégorie sur une ligne
 * date : 01/08/2019
 * modification : 04/10/2020, documentation du code
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // declaration des fonctions locales (les definitions sont dans le fichier modules.cpp)

    // lire toutes les valeurs et à déterminer en même temps la valeur minimale et la valeur maximale
    vector<float> lireValeurs(int, float&, float&);

    // classer des valeurs dans des catégories
    vector<int> classerValeurs(float, float, int, vector<float>);

    // affiche un histogramme à partir de données classées
    void afficherHisto( vector<int>);

    // declaration des variables localeslireValeurs(nbValeurs, min, max)
    int nbCategories;   // nombre de categories
    int nbValeurs;      // nombre de valeurs
    float min;          // valeur minimum entrée
    float max;          // valeur maximum entrée

    vector<float> valeurs;      // vecteur des valeurs
    vector<int> histogramme;    // vecteur des catégories

    // debut du traitement

    // Lecture des entrées
    // 1    Lecture du nombrelireValeurs(nbValeurs, min, max) de catégorie
    cout << "nombre de categories : ";
    cin >> nbCategories;

    // si le nb de categories est <1, fin du programme
    if (nbCategories>0)
    {
        // 2    Lecture du nombre de valeurs
        cout<<"nombre de valeurs : ";
        cin >> nbValeurs;

        // 3 Lire les valeurs dans un vecteur et déterminer le min et le max des valeurs
        valeurs = lireValeurs(nbValeurs, min, max);

        /* ne pas fournir aux étudiant.es */
        cout<<endl<<"** valeurs lues"<<endl;
        for (auto &valeurCourante : valeurs) {
            cout<<valeurCourante<<" - ";
        }
        cout<<endl<<"** min - max : "<<min<<" - "<<max<<endl;
        /* fin */

        // 4 Classer les valeurs lues
        histogramme = classerValeurs(min, max, nbCategories, valeurs);

        // 5 Afficher l’histogramme
        afficherHisto(histogramme);
    }

    cout<<"fin du prog"<<endl;

    return 0;
}
