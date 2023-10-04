#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Structur point pour stocker les données de l'utilisateur
struct point {
    float x;
    float y;
};

// Liste chaîné pour manipuler la saisie utilisateur
struct Node {
    point element;
    struct Node* psuivant;
};


/*
Nom : Menu
Entrée : Vide
Entrée/Sortie : Vide
Sortie : Vide
Traitement : Affiche le Menu
*/
void Menu();


/*
Nom : Saisie
Entrée : Un pointeur de pointeur vers une liste
Entrée/Sortie : Vide
Sortie : Vide
Traitement : Permet d'attendre que l'utilisateur saisie ses données et le stock dans la liste chaîné
*/
void Saisie(Node** liste);


/*
Nom : Insert
Entrée : Un pointeur de pointeur vers la liste chaîné et le point à ajouter à cette liste
Entrée/Sortie : Vide
Sortie : Vide
Traitement : Permet d'ajouter un élement à la liste chaîné
*/
void Insert(Node** liste, point newData);


/*
Nom : Delete
Entrée : Pointeur de la liste chaîné à supprimer
Entrée/Sortie : Vide
Sortie : Vide
Traitement : Permet de suprimer tout les éléments de la liste chaîné
*/
void Delete(Node* liste);


/*
Nom : PrintList
Entrée : Pointeur de la liste chaîné à afficher
Entrée/Sortie : Vide
Sortie : Vide
Traitement : Permet d'afficher la liste chaîné
*/
void PrintList(Node* liste);


/*
Nom : SelectFile
Entrée : Vide
Entrée/Sortie : Vide
Sortie : Un string qui correspond au chemin d'accès absolu du fichier
Traitement : Récupère le chemin du fichier
*/
string SelectFile();


/*
Nom : ReadFile
Entrée : Un string le chemin d'accès du fichier et un pointeur de pointeur pour stocker les données dans la liste chaînée
Entrée/Sortie : Vide
Sortie : Vide
Traitement : Lis le contenu du fichier et le stock dans la liste chaînée
*/
void ReadFile(string fileName, Node** liste);


/*
Nom : WriteFile
Entrée : Vide
Entrée/Sortie : Vide
Sortie : Vide
Traitement : Ecris le contenu de la liste chaînée dans le fichier
*/
void WriteFile(string fileName, Node* liste);
