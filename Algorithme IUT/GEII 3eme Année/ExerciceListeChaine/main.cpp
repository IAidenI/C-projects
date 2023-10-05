#include"fonctions.h"

int main(int argc,char** argv) {
    // Vérifie que l'utilisateur à saisi au maximum 1 argument au programme
    if (argc > 2) {
        cerr << "Usage: " << argv[0] << " [argument]" << endl;
        return 1;
    }

    string fileName = "";
    // Vérifie que le fichier séléctionné existe
    if (argc == 2) {
        fileName = argv[1];
        ifstream file(fileName);
        if (!file.is_open()) {
            cerr << "[!] Erreur : Le fichier seléctionné est introuvable." << endl;
            return 1;
        }
    }

    // Démarage de l'application
    Menu(fileName);

    return 0;
}
