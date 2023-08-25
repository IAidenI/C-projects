using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Threading;
using System.Drawing.Imaging;
using System.Diagnostics;

namespace Test3
{
    public partial class Form_Server : Form
    {
        //DateTime startTime;
        //static IPAddress ip_joueur = IPAddress.Parse("192.168.1.76");
        static int Port_erreur_connection = 1111;
        private string erreur = "";
        bool test = false;

        //TcpListener ServerListener = new TcpListener(ip_joueur, Port); // Crée un listener avec l'ip du joueur et le port choisi
        //TcpClient clientSocket = default(TcpClient);                   // Crée un client tcp pour pouvoir envoyer l'ip du joueur
        public Form_Server()
        {
            InitializeComponent();
            label2.Hide();
        }
        private void Form_Server_Load(object sender, EventArgs e)
        {
            Task.Run(() => Erreur_connection());
            Test();
        }

        private async Task Erreur_connection()
        {
            IPAddress ipAd = IPAddress.Parse("192.168.1.76");
            TcpListener ServerListener_erreur = new TcpListener(ipAd, Port_erreur_connection);   // Création d'un Listener pour écouter les connexions à l'aide de l'adresse IP et du numéro de port spécifiés
            TcpClient clientSocket_erreur = default(TcpClient);                     // Initialisation du client
            ServerListener_erreur.Start();                                          // Lancement de l'écoute
            clientSocket_erreur = ServerListener_erreur.AcceptTcpClient();              // Accepte une demande de connection en attente

            while (true) // Ecoute tant que qu'il n'as pas reçue le signal
            {
                NetworkStream networkStream_erreur = clientSocket_erreur.GetStream();   // Va permettre d'obtenir un flux de données à partir de la connexion TCP établie avec le client pour recevoir le signal
                byte[] signal = new byte[10];                                    // Crée un stockage pour récuperer le signal (la taille est de 3 car le signal envoyé est go + '\0')  
                networkStream_erreur.Read(signal, 0, 10);                            // Récupere le signal
                erreur = System.Text.Encoding.ASCII.GetString(signal);              // Convertit le signal reçue en un string
                erreur = erreur.Substring(0, erreur.IndexOf('\0'));                         // Récupère juste le signal
                networkStream_erreur.Flush();                                       // Efface la mémoire de networkStream_go

                if (erreur != "")
                {
                    ServerListener_erreur.Stop();   // Arret de l'écoute
                    clientSocket_erreur.Close();    // Arret du client
                    test = true;
                    break;                          // Sorti de la boucle
                }
                await Task.Delay(50);
            }
        }

        private async void Test()
        {
            while (true)
            {
                if (test == true)
                {
                    this.Close();
                }
                await Task.Delay(100);
            }
        }


        private void button1_Click(object sender, EventArgs e)
        {/*
            NetworkStream networkStream = clientSocket.GetStream();     // Cela va nous permettre d'envoyer et de recevoire des données
            string serverResponse = textBox1.Text;                      // Récupere le contenue de la textbox
            Byte[] sendBytes = Encoding.ASCII.GetBytes(serverResponse); // Convertit l'ip reçue en un string
            networkStream.Write(sendBytes, 0, sendBytes.Length);        // Envoie la réponse au client
            networkStream.Flush();                                      // Efface la mémoire de networkStream*/
            if (test == true)
            {
                label2.Text += Environment.NewLine + erreur;
                label2.Show();
            }
        }
    }
}
