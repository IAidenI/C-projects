#include"fonctions.h"

int main()
{
// Vérifie la distribution utilisé
#if defined (WIN32)
	// Initialisation de la bibliothèque Winsock 
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2, 2), &WSAData);
#else
	printf("La distribution utilisé n'est pas windows.");
	return 1;
#endif
	
	const unsigned int PORT = 5555;
	unsigned int sock_err;
	SOCKET sock_srv = NULL, sock_client = NULL;
	SOCKADDR_IN addr;
	int size = sizeof(addr);

	sock_srv = socket(AF_INET, SOCK_STREAM, 0);

	// Vérifie que le socket soit crée
	if (sock_srv == INVALID_SOCKET)
	{
		perror("Erreur lors de la création du socket");
		return 1;
	}

	addr.sin_addr.s_addr = htonl(INADDR_ANY);  // Récupération de l'adresse IP automatiquement
	addr.sin_family = AF_INET;                 // Famille d'adresse utilisé (ici IPv4)
	addr.sin_port = htons(PORT);               // Listage du port
	sock_err = bind(sock_srv, (SOCKADDR*)&addr, size);

	// Vérifie que le socket soit fonctionel
	if (sock_err == SOCKET_ERROR)
	{
		perror("Erreur lors de la validation du socket");
		return 1;
	}

	// Démarage de l'écoute
	sock_err = listen(sock_srv, 1);
	printf("Ecoute sur le port %d ...\n", PORT);

	// Vérifie que l'écoute soit établie
	if (sock_err == SOCKET_ERROR)
	{
		perror("Erreur lors de l'écoute");
		return 1;
	}

	// On accepte la demande du client
	printf("En attente que le client se connecte...");
	sock_client = accept(sock_srv, (SOCKADDR*)&addr, &size);

	// Vérifie que la connection soit établie
	if (sock_client == SOCKET_ERROR)
	{
		perror("Erreur lors de la connection du client");
		return 1;
	}
	printf("Connection établie avec le client.");


	closesocket(sock_srv);
	return 0;
}