#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
#include <string>
#include "porte.h"

using namespace std;

int main()
{
    Porte objet; //creation d un objet du classe porte

//Lecture fichier vecteurs
//les fichiers doivent etre dans le repertoire ou mon programme est situer
int nombredevecteurs=0;int cpt=0;vector <string> tab;ifstream vecteurs("vecteurs.txt");//ouverture du fichier en ecriture
    if(vecteurs) //si le fichier vecteur est ouvert on le traite ligne par ligne
   {
string line;
while(getline(vecteurs,line))//lire le fichier ligne par ligne
    {if(cpt>0){tab.push_back(line);} //le compteur me permet de savoir dans quelle ligne j en suis je stocke les vecteurs dans un vector tab et je les traite apres
else{nombredevecteurs=stoi(line);}cpt++;}} //je suis dans la première ligne je prend le nombre de vecteur et je change son type du string en int
else cout<<"cannot open file"; // si le fichier n'est pas ouvert


int f= tab[0].length();//f prend le nombre d element d un vecteur stocker dans le vector tab

for(int i=0;i<tab.size();i++) //je prend tout les vecteurs que je vais tester
{ //d'ici je prend le 1èr vecteur et je commence


char vecteur2[f]; //tableau de charactere qui contient les valuers du vecteur de taille (nombre de valeur)
strcpy(vecteur2, tab[i].c_str());//fonction qui me permet de decouper un string en des chars et je les stockes dans vecteur2
bool entrees2[f]; //tableau de bool pour stocker le vecteur choisi
for(int i=0;i<f;i++){entrees2[i]= vecteur2[i]-48;}//code ascii de 1 est 49 et 0 de 48 pour avoir soit la valeur 1 ou 0 de type bool


//--------------------------------------------------------------------------------
//Lecture fichier descriptif du circuit
ifstream fichier("fichier.txt");//ouverture du fichier en lecture
int dimensionentree=0;//dimension des valeurs d'entrees
int dimensionsortie=0;//dimension des valeurs de sorties
vector<string> v,t,n,s,e,vecteurentree,vecteursortie; //declaration des vectors ou je vais stocker tous les parametres du circuit
vector<bool> k;
string ligne;string word;string  type, nom, sortie, entree,entree1,entree2, nomduporte,mot;
   if(fichier) //ouverture du fichier texte et le traiter ligne par ligne
   {while(getline(fichier, ligne)){v.push_back(ligne);}} //Tant qu'on n'est pas a la fin, je lit le fichier et je stocke les lignes dans le vecteur v

stringstream ss(v[0]);while(ss >> word &&  word != ";"){vecteurentree.push_back(word);++dimensionentree;} //je traite la premiere ligne, je lie tous les entrees et je les stocke dans un vector

stringstream ss1(v[1]);while(ss1 >> word &&  word != ";"){vecteursortie.push_back(word);++dimensionsortie;} //je traite la deuxieme ligne je lie tous les sorties et je les stocke dans un vector

vecteurentree.erase(vecteurentree.begin());vecteursortie.erase(vecteursortie.begin()); //j'enleve la premiere case du vecteur qui contient soit "INPUT" , "OUTPUT"

for(int i=0;i<vecteurentree.size();i++)

{
    objet.set_input(vecteurentree[i],entrees2[i]); //je fais appel à la fonction qui initialise les entrees primaires(string) avec leurs valeurs des vecteurs

}
bool z,c;

for(int i=2;i<v.size();i++) //en traite les lignes à partir du troisieme ligne qui contient les entrees et sorties des portes logiques
{objet.s=1;// initialise la sortie du porte et a 1 dans la fonction
objet.h=0;// initialise la sortie du porte ou a 0 dans la fonction
objet.b=0;// initialise la sortie du porte xor a 0 dans la fonction

  stringstream ss2(v[i]);// avec cette fonction je peux lire les string issue du fichier mot par mot comme cin
getline(ss2, type, ' '); //je lie le premier mot qui indique le type
getline(ss2, nom, ' '); //je lie le deuxieme mot qui indique le nom
getline(ss2, sortie, ' '); //je lie le trosieme mot qui indique la sortie

//do{
while(getline(ss2, entree, ' '))//je lie les mots restant d une ligne jusqu'a ";" qui indique les entrees d'une porte

{
    if(entree!=";")
    {

 c=objet.get_value(entree); //appel à la fonction get_value qui permet d'obtenir l'état d'entree


z=objet.calculate_output(type, c); // calcule du sortie


    }

}
objet.set_input(sortie,z); // rajouter la valeur du sortie au tableau des entrees primaires pour l'utiliser comme entrée la prochaine fois


}
//while()

} //j'ai finis le test du premier vecteur et je refais le tous, les vecteurs se rajoute dans le tableau primaire après calcule des sorties
// et le calcule s'effectue en prenant la valeur du dernier vecteur dans le tableau primaire
objet.print_info(); //afficher le resultat
objet.ecrirefichier(); //ecrire le resultat dans un fichier

}


