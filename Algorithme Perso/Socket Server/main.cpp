#include"fonctions.h"

int main()
{
// V�rifie la distribution utilis�
#if defined (WIN32)
	// Initialisation de la biblioth�que Winsock 
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2, 2), &WSAData);
#else
	printf("La distribution utilis� n'est pas windows.");
	return 1;
#endif
	
	const unsigned int PORT = 5555;
	unsigned int sock_err;
	SOCKET sock_srv = NULL, sock_client = NULL;
	SOCKADDR_IN addr;
	int size = sizeof(addr);

	sock_srv = socket(AF_INET, SOCK_STREAM, 0);

	// V�rifie que le socket soit cr�e
	if (sock_srv == INVALID_SOCKET)
	{
		perror("Erreur lors de la cr�ation du socket");
		return 1;
	}

	addr.sin_addr.s_addr = htonl(INADDR_ANY);  // R�cup�ration de l'adresse IP automatiquement
	addr.sin_family = AF_INET;                 // Famille d'adresse utilis� (ici IPv4)
	addr.sin_port = htons(PORT);               // Listage du port
	sock_err = bind(sock_srv, (SOCKADDR*)&addr, size);

	// V�rifie que le socket soit fonctionel
	if (sock_err == SOCKET_ERROR)
	{
		perror("Erreur lors de la validation du socket");
		return 1;
	}

	// D�marage de l'�coute
	sock_err = listen(sock_srv, 1);
	printf("Ecoute sur le port %d ...\n", PORT);

	// V�rifie que l'�coute soit �tablie
	if (sock_err == SOCKET_ERROR)
	{
		perror("Erreur lors de l'�coute");
		return 1;
	}

	// On accepte la demande du client
	printf("En attente que le client se connecte...");
	sock_client = accept(sock_srv, (SOCKADDR*)&addr, &size);

	// V�rifie que la connection soit �tablie
	if (sock_client == SOCKET_ERROR)
	{
		perror("Erreur lors de la connection du client");
		return 1;
	}
	printf("Connection �tablie avec le client.");


	closesocket(sock_srv);
	return 0;
}