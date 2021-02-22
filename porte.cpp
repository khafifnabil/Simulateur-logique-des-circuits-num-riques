#include <iostream>
#include "porte.h"

#include <string>


using namespace std;

 bool Porte:: get_value(string v) //methode du classe porte qui me permet de verifier si la valeur d'une entree de porte existe dans mon vecteur d'entree primaires en verifiant son nom et la retourner
{
     for(int i=0;i<tab.size();i++)
  {
      if(tab[i]==v)
     {
            k= tob[i];
      }

  }
  return k;
}
//----------------------------------------------------------------

//-------------------------------------------------------------
void Porte::print_info() //fonction qui me permet d'afficher le contenue de mon tableau primaire
{
      for(int i=0;i<tab.size();i++){cout << tab[i] << " "
             << tob[i] << endl <<endl;}
}

//-----------------------------------------------------------
 void Porte::set_input(string word , bool val ) //fonction qui me permet de stocker la valeur d'une entree ou sortie dans vecteur avec son nom dans un autre vecteur pour l'afficher
    {
tab.push_back(word); //vector contenant les noms des entrees primaires et sorties
tob.push_back(val); //vector contenant les valeurs des entrees et sorties
 //remplir tableau d'entrees primaires
    }
//---------------------------------------------------------------------


  bool Porte::calculate_output(string typ,bool x)//fonction qui me permet de calculer la sortie d'une porte en verifiant le type du porte
    {

if (typ=="and") {s=s and x;return s;}//je teste le type recus et je return la valur calculer
    else if(typ=="or"){h=h or x; return h;}
    else if(typ=="not"){y=not(x);return y;}
else if(typ=="xor"){b=b xor x;return b;}
    }

//---------------------------------------------------------------------------------------------------------------

void Porte::ecrirefichier() //fonction qui me permet d'ecrire un fichier avec les valeurs et noms des entrees et sorties dans mon vecteur
{
    std::string const nomFichier("resultats.txt");
    std::ofstream monFlux(nomFichier.c_str());//declaration d un flux qui me permet d ecrire dans un fichier

    if(monFlux)//monflux est utiliser comme cin
    {
        monFlux << "Bonjour, veuillez trouver les résultats ci-desous." << endl;
          for(int i=0;i<tab.size();i++)
        {
           monFlux << tab[i] << " "
             << tob[i] << endl;
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}





