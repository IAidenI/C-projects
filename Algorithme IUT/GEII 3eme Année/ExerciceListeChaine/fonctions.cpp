#include "fonctions.h"

void Menu(const string& fileName) {
    /* ==== AFFICHAGE DU MENU ==== */
    Node* liste = nullptr;
    string choix;

    Clear();
    // Récupère le choix de l'utilisateur
    while (true) {
        cout << ">";
        cin >> choix;
        cin.ignore(); // Pour ignorer le '\n'

        // Met la saisie de l'utilisateur en lowerCase
        for (unsigned int i = 0; choix[i] != '\0'; i++) {
            choix[i] = static_cast<char>(tolower(choix[i]));
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
            Help();
        } else if (choix == "search") {
            Search(SelectFile(fileName), liste);
        } else if (choix == "sort") {
            SortAbs(&liste);
        } else if (choix == "graph") {
            Graph(liste);
        } else if (choix == "clear") {
            Clear();
        } else if (choix == "exit") {
            Delete(liste);
            cout << "Au revoir." << endl;
            break;
        } else {
            cout << "[!] Erreur : Erreur de lors de la saisie, 'help' pour plus d'informations." << endl;
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
                choix[i] = static_cast<char>(tolower(choix[i]));
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

    cout << "[+] Liste supprimée avec succès." << endl;
}

void PrintList(Node* liste) {
    if (liste == nullptr) {
        cout << "[!] Erreur : Liste vide." << endl;
        return;
    }

    cout << "Contenu de la liste chaîné :" << endl;

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

string SelectFile(const string& fileName) {
    if (fileName.empty()) {
        string choix_fileName;
        cout << "Selectionner le chemin absolu d'un fichier." << endl;
        cout << ">";
        cin >> choix_fileName;
        cin.ignore();
        return choix_fileName;
    } else {
        return fileName;
    }
}

void ReadFile(const string& fileName, Node** liste) {
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

void WriteFile(const string& fileName, Node* liste) {
    // Ouvre le fichier en mode écriture en vidant son contenu
    ifstream file_check(fileName);

    if (!file_check.good()) {
        string choix;
        cout << "[!] Erreur : Le fichier seléctionné est introuvable." << endl;
        cout << "Voulez vous crée le fichier (yes/no) ?" << endl;
        cout << ">";
        cin >> choix;

        // Met la saisie de l'utilisateur en lowerCase
        for (unsigned int i = 0; choix[i] != '\0'; i++) {
            choix[i] = static_cast<char>(tolower(choix[i]));
        }

        if (choix == "yes" || choix == "y") {
            file_check.close();
            ofstream file(fileName, ios::trunc);

            // Place tout le contenu de la liste chaîné dans le fichier
            while (liste != nullptr) {
                file << liste->element.x << " " << liste->element.y << endl;
                liste = liste->psuivant;
            }

            cout << "[+] Contenu de la liste chaînée stocké dans " << fileName << endl;

            file.close();
        } else if (choix == "no" || choix == "n") {
            file_check.close();
            cout << "[-] Sortie." << endl;
            return;
        }
    } else {
        ofstream file(fileName, ios::trunc);

        // Place tout le contenu de la liste chaîné dans le fichier
        while (liste != nullptr) {
            file << liste->element.x << " " << liste->element.y << endl;
            liste = liste->psuivant;
        }

        cout << "[+] Contenu de la liste chaînée stocké dans " << fileName << endl;
        file_check.close();
    }
}


void Search(const string& fileName, Node* liste) {
    float x_raw = 0;
    float y_raw = 0;
    string choix;
    cout << "Saisir le couple de point à vérifier (pour entrer 10 et 23 saisir 10 23) : " << endl;
    cout << ">";
    getline(cin, choix); // Permet de lire la ligne complète à partir de la sortie standand. Pour pas que si l'utilisateur saisisse 10 23 le programme récupère juste 10

    /*
    Vu que l'utilisateur doit saisir par exempl 10 23, pour le stocker
    dans deux variables x = 10 et y = 23 on se sert de istringstream
     */

    istringstream iss(choix); // Crée un flux d'entrée à partir de la chaîne choix.
    // On extrait les données dans x et y. '>>' lit les données jusqu'à ce qu'il atteigne un espace ou un '\n'
    if (iss >> x_raw >> y_raw) {
        bool check = false;
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
                if (x == x_raw && y == y_raw) {
                    cout << "[*] Le couple de point existe dans le fichier : " << fileName << endl;
                    check = true;
                    break;
                } else {
                    check = false;
                }
            } else {
                cout << "[!] Erreur : La ligne contenant : " << ligne << " n'est pas valide." << endl;
            }
        }
        file.close();

        if (!check) {
            cout << "[-] Le point n'existe pas dans le fichier." << endl;
        }

        if (liste == nullptr) {
            cout << "[!] La liste est vide." << endl;
            return;
        }

        // Parcours la liste et affiche chaque élément sous le format (x;y) -> (x;y)
        while (liste != nullptr) {
            if (liste->element.x == x_raw && liste->element.y == y_raw) {
                cout << "[*] Le couple de point existe dans la liste chaîné." << endl;
                check = true;
                break;
            } else {
                check = false;
            }
            liste = liste->psuivant; // Passe au nœud suivant dans la liste
        }

        if (!check) {
            cout << "[-] Le point est introuvable dans la liste." << endl;
        }
    } else {
        cout << "[!] Erreur lors de la saisie." << endl;
    }
}


void SortAbs(struct Node** head) {
    // Vérifier si la liste est vide ou ne contient qu'un seul élément
    if (*head == nullptr || (*head)->psuivant == nullptr) {
        cout << "[!] Erreur : Liste vide ou avec un seul élément." << endl;
        return;
    }

    struct Node* sort = nullptr;

    // Parcourir la liste d'origine
    while (*head != nullptr) {
        struct Node* actuel = *head;  // Pointeur vers le nœud actuel
        *head = (*head)->psuivant;    // Avancer dans la liste d'origine

        // Insérer le noeud actuel dans la liste triée en fonction de la valeur x
        if (sort == nullptr || actuel->element.x < sort->element.x) {
            actuel->psuivant = sort;
            sort = actuel;
        } else {
            // Parcourir la liste triée pour trouver la position d'insertion
            struct Node* temp = sort;
            while (temp->psuivant != nullptr && temp->psuivant->element.x < actuel->element.x) {
                temp = temp->psuivant;
            }
            actuel->psuivant = temp->psuivant;
            temp->psuivant = actuel;
        }
    }

    *head = sort;
    cout << "[+] Liste triée. (Saisir 'print' pour afficher la liste)" << endl;
}


void Graph(struct Node* liste) {
    if (liste == nullptr) {
        cout << "[!] Erreur : Liste vide." << endl;
        return;
    }

    ofstream gnuplotPipe;
    gnuplotPipe.open("gnuplot_commands.txt");

    if (gnuplotPipe.is_open()) {
        gnuplotPipe << "plot '-' with linespoints title 'Graphique de la liste chaînée'\n";

        // Parcourez la liste pour extraire les points et les ajouter à la commande de tracé
        while (liste != nullptr) {
            gnuplotPipe << liste->element.x << " " << liste->element.y << "\n";
            liste = liste->psuivant;
        }

        gnuplotPipe << "e\n"; // Terminer la saisie des données

        gnuplotPipe << "pause mouse key\n"; // Mettez en pause pour afficher le tracé
        gnuplotPipe.close();

        system("gnuplot < gnuplot_commands.txt");
    } else {
        cout << "[!] Erreur : Création du fichier de commandes Gnuplot échoué." << endl;
    }
}


void Help() {
    cout << "Veillez saisir l'un des choix disponible." << endl;
    cout << "\t[enter]  - Saisir des couples de points à stocker" << endl;
    cout << "\t[print]  - Affiche les points stocké" << endl;
    cout << "\t[rfile]  - Affiche le contenu du fichier dans une liste chaînée" << endl;
    cout << "\t[wfile]  - Ecris le contenu de la liste chaînée dans le fichier" << endl;
    cout << "\t[search] - Cherche si le point existe" << endl;
    cout << "\t[sort]   - Trier par ordre croissant les abscisses" << endl;
    cout << "\t[graph]  - Affichage graphique" << endl;
    cout << "\t[clear]  - Efface l'affichage" << endl;
    cout << "\t[help]   - Affiche ce menu" << endl;
    cout << "\t[exit]   - Sort de l'application" << endl;
}


void Clear() {
#ifdef _WIN32 // Si c'est windows
    system("cls");
    Help();
#else // Si c'est UNIX
    system("clear");
    Help();
#endif
}