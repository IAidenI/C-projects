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
Entrée : Un string qui va contenir le chemin du fichier
Entrée/Sortie : Vide
Sortie : Vide
Traitement : Affiche le Menu
*/
void Menu(const string& fileName);


/*
Nom : Saisie
Entrée : Vide
Entrée/Sortie : Un pointeur de pointeur vers une liste
Sortie : Vide
Traitement : Permet d'attendre que l'utilisateur saisie ses données et le stock dans la liste chaîné
*/
void Saisie(Node** liste);


/*
Nom : Insert
Entrée : Le point à ajouter à cette liste
Entrée/Sortie : Un pointeur de pointeur vers la liste chaîné
Sortie : Vide
Traitement : Permet d'ajouter un élement à la liste chaîné
*/
void Insert(Node** liste, point newData);


/*
Nom : Delete
Entrée : Vide
Entrée/Sortie : Pointeur de la liste chaîné à supprimer
Sortie : Vide
Traitement : Permet de suprimer tout les éléments de la liste chaîné
*/
void Delete(Node* liste);


/*
Nom : PrintList
Entrée : Vide
Entrée/Sortie : Pointeur de la liste chaîné à afficher
Sortie : Vide
Traitement : Permet d'afficher la liste chaîné
*/
void PrintList(Node* liste);


/*
Nom : SelectFile
Entrée : Un string qui va contenir le chemin du fichier si l'utiliseur l'as rentré au démarage
Entrée/Sortie : Vide
Sortie : Un string qui correspond au chemin d'accès absolu du fichier
Traitement : Récupère le chemin du fichier
*/
string SelectFile(const string& fileName);


/*
Nom : ReadFile
Entrée : Un string le chemin d'accès du fichier
Entrée/Sortie : Un pointeur de pointeur pour lire les données dans la liste chaînée
Sortie : Vide
Traitement : Lis le contenu du fichier et le stock dans la liste chaînée
*/
void ReadFile(const string& fileName, Node** liste);


/*
Nom : WriteFile
Entrée : Un string le chemin d'accès du fichier
Entrée/Sortie : Un pointeur de pointeur pour stocker les données dans la liste chaînée
Sortie : Vide
Traitement : Ecris le contenu de la liste chaînée dans le fichier
*/
void WriteFile(const string& fileName, Node* liste);


/*
Nom : Search
Entrée : Un string le chemin d'accès du fichier
Entrée/Sortie : Un pointeur de pointeur pour stocker les données dans la liste chaînée
Sortie : Vide
Traitement : Cherche dans la liste chaîné et dans le fichier si le couple de point est présent
*/
void Search(const string& fileName, Node* liste);


/*
Nom : SortAbs
Entrée : Vide
Entrée/Sortie : Un pointeur vers un pointeur vers la liste chaînée, représentant la tête de la liste chaînée à trier.
Sortie : Vide
Traitement : Trie la liste chaînée par ordre croissant des abscisses
*/
void SortAbs(struct Node** head);


/*
Nom : Graph
Entrée : Vide
Entrée/Sortie : Un pointeur vers un pointeur vers la liste chaînée, représentant la tête de la liste chaînée à trier.
Sortie : Vide
Traitement : Trie la liste chaînée par ordre croissant des abscisses
*/
void Graph(struct Node* liste);


/*
Nom : Help
Entrée : Vide
Entrée/Sortie : Vide
Sortie : Vide
Traitement : Affiche le menu d'aide
*/
void Help();


/*
Nom : Clear
Entrée : Vide
Entrée/Sortie : Vide
Sortie : Vide
Traitement : Efface l'écran
*/
void Clear();