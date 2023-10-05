#include "fonctions.h"

void Menu(string fileName) {
    /* ==== AFFICHAGE DU MENU ==== */
    Node* liste = NULL;
    string choix;
    cout << "Veillez saisir l'un des choix disponible." << endl;
    cout << "[enter] - Saisir des coupes de points à stocker" << endl;
    cout << "[print] - Affiche les points stocké" << endl;
    cout << "[rfile] - Affiche le contenu du fichier dans une liste chaînée" << endl;
    cout << "[wfile] - Ecris le contenu de la liste chaînée dans le fichier" << endl;
    cout << "[help] - Affiche ce menu" << endl;
    cout << "[exit] - Sort de l'application" << endl;

    // Récupère le choix de l'utilisateur
    while (true) {
        cout << ">";
        cin >> choix;
        cin.ignore(); // Pour ignorer le '\n'

        // Met la saisie de l'utilisateur en lowerCase
        for (unsigned int i = 0; choix[i] != '\0'; i++) {
            choix[i] = tolower(choix[i]);
        }

        if (choix == "enter") {
            Saisie(&liste);
        } else if (choix == "print") {
            PrintList(liste);
        } else if (choix == "rfile") {
            ReadFile(SelectFile(fileName), &liste);
        } else if (choix == "wfile") {
            WriteFile(SelectFile(fileName), liste);
        } else if (choix == "help") {
            cout << "=== HELP MENU ===" << endl;
            cout << "[enter] - Saisir des coupes de points à stocker" << endl;
            cout << "[print] - Affiche les points stocké" << endl;
            cout << "[rfile] - Affiche le contenu du fichier" << endl;
            cout << "[wfile] - Ecris dans le fichier" << endl;
            cout << "[help] - Affiche ce menu" << endl;
            cout << "[exit] - Sort de l'application" << endl;
        } else if (choix == "exit") {
            Delete(liste);
            cout << "Au revoir." << endl;
            break;
        } else {
            cout << "[!] Erreur : Erreur de lors de la saisie, saisire 'help' pour plus d'informations." << endl;
        }
    }
}

void Saisie(Node** liste) {
    float x = 0;
    float y = 0;
    string choix;

    while (true) {
        cout << "Saisir un couple de points (pour entrer 10 et 23 saisir 10 23 - done pour terminer) : ";
        getline(cin, choix); // Permet de lire la ligne complète à partir de la sortie standand. Pour pas que si l'utilisateur saisisse 10 23 le programme récupère juste 10

        /*
        Vu que l'utilisateur doit saisir par exempl 10 23, pour le stocker
        dans deux variables x = 10 et y = 23 on se sert de istringstream
        */
        istringstream iss(choix); // Crée un flux d'entrée à partir de la chaîne choix.
        // On extrait les données dans x et y. '>>' lit les données jusqu'à ce qu'il atteigne un espace ou un '\n'
        if (iss >> x >> y) {
            Insert(liste, {x, y});
        } else {
            // Met la saisie de l'utilisateur en lowerCase
            for (unsigned int i = 0; choix[i] != '\0'; i++) {
                choix[i] = tolower(choix[i]);
            }

            if (choix == "done") {
                cout << "[*] Saisie terminé." << endl;
                break;
            } else {
                cout << "[!] Erreur lors de la saisie." << endl;
            }
        }
    }
}

void Insert(Node** liste, point newData) {
    // Crée un nouveau noeud
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == nullptr) {
        cerr << "[!] Erreur : Echec de la création d'un nouveau noeud." << endl;
        exit(EXIT_FAILURE);
    }

    // Initialise le nouveau noeud avec les données fournies et le pointe vers le début de la liste existante
    newNode->element = newData;
    newNode->psuivant = *liste;
    *liste = newNode; // Met à jour la tête de la liste pour pointer vers le nouveau noeud
}

void Delete(Node* liste) {
    if (liste == nullptr) {
        cout << "[!] Erreur : Liste déjà vide." <<endl;
        return;
    }

    // Parcours la liste et supprime chaque donnée
    while (liste->psuivant != nullptr) {
        Node* toDel = liste; // Stocke le nœud actuel à supprimer
        liste = liste->psuivant; // Passe au nœud suivant dans la liste
        delete toDel; // Supprime le nœud précédent
    }

    cout << "[+] Liste supprimé avec succès." << endl;
}

void PrintList(Node* liste) {
    if (liste == nullptr) {
        cout << "[!] Erreur : Liste vide." << endl;
        return;
    }

    cout << "Contenue de la liste chaîné :" << endl;

    // Parcours la liste et affiche chaque élément sous le format (x;y) -> (x;y)
    while (liste != nullptr) {
        cout << "(" << liste->element.x << ";" << liste->element.y << ")";
        if (liste->psuivant != nullptr) {
            cout << " -> ";
        }
        liste = liste->psuivant; // Passe au nœud suivant dans la liste
    }
    cout << endl;
}

string SelectFile(string fileName) {
    if (fileName == "") {
        string choix_fileName;
        cout << "Selectionner le chemin absolu d'un fichier." << endl << ">";
        cin >> choix_fileName;

        // Vérifie que le fichier existe
        ifstream file(choix_fileName);
        if (!file.is_open()) {
            cout << "[!] Erreur : Le fichier seléctionné est introuvable." << endl;
            return "";
        }
        return choix_fileName;
    } else {
        return fileName;
    }
}

void ReadFile(string fileName, Node** liste) {
    float x = 0;
    float y = 0;
    string ligne;
    // Ouvre un fichier en mode lecture
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "[!] Erreur : Impossible d'ouvrir le fichier." << endl;
        return;
    }

    // Place le contenu du fichier dans la liste chaîné
    while (getline(file, ligne)) {
        // Split 10 23 en x = 10 et y = 23
        istringstream iss(ligne);
        if (iss >> x >> y) {
            Insert(liste, {x, y});
        } else {
            cout << "[!] Erreur : La ligne contenant : " << ligne << " n'est pas valide." << endl;
        }
    }

    cout << "[+] Contenu du fichier " << fileName << " stocké. (saisir print pour afficher son contenu)" << endl;

    file.close();
}

void WriteFile(string fileName, Node* liste) {
    // Ouvre le fichier en mode écriture en vidant son contenu
    ofstream file(fileName, ios::trunc);

    if (!file.is_open()) {
        cout << "[!] Erreur : Impossible d'ouvrir le fichier." << endl;
        return;
    }

    // Place tout le contenu de la liste chaîné dans le fichier
    while (liste != nullptr) {
        file << liste->element.x << " " << liste->element.y << endl;
        liste = liste->psuivant;
    }

    cout << "[+] Contenu de la liste chaînée stocké dans " << fileName << endl;
}