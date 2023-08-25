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

namespace Test3_Client
{
    public partial class Form1_Client : Form
    {
        
        
        static int Port_erreur_connection = 1111;
        DateTime date;

        public Form1_Client()
        {
            InitializeComponent();
            date = DateTime.Now;
            label1.Text = date.ToString();
        }

        
        int Port = 9999;                       // Nombre du port
        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        /* Verifie qu'il n'y a pas eu d'erreur de connection */
        private void Envoie_Erreur()
        {
            IPAddress ip_joueur = IPAddress.Parse("192.168.1.76");
            TcpClient Serveur = new TcpClient();    // Crée un client tcp pour pouvoir envoyer l'ip du joueur
            Serveur.Connect(ip_joueur, Port_erreur_connection);   // Se connecte au serveur sur l'ip et le port donnée
            Stream flux_erreur = Serveur.GetStream();      // Définit un flux de données qui sera utilisé pour communiquer avec le client Tcp qui a été connecté à l'arbitre

            ASCIIEncoding ascii = new ASCIIEncoding();      // Encodage en caractère ASCII
            string data_to_send = "$" + "\0";               // Crée le signal d'envoie
            byte[] Ready = ascii.GetBytes(data_to_send);    // Met la signal sous le bon format pour l'envoie
            flux_erreur.Write(Ready, 0, Ready.Length);      // Envoie du signal
            Serveur.Close();                       // Arret du clienttcp
            flux_erreur.Close();                            // Arret du flux
        }
        /* Verifie qu'il n'y a pas eu d'erreur de connection */

        private void button1_Click(object sender, EventArgs e)
        {/*
            String str = textBox1.Text + "$";               // Ajoute le caractère '$' a la saisie de l'utilisateur
            Stream stm = Serveur.GetStream();               // Crée un stream qui va nous permettre d'envoyer la donnée

            ASCIIEncoding asen = new ASCIIEncoding();       // Encodage en caractère ASCII
            byte[] ba = asen.GetBytes(str);                 // Met la donnée sous le bon format

            stm.Write(ba, 0, ba.Length);                    // Envoie la donnée au serveur

            byte[] bb = new byte[100];                      // Création d'une variable pour récupérer la réponse du serveur
            int k = stm.Read(bb, 0, 100);                   // Récupère la réponse du serveur

            string Response = Encoding.ASCII.GetString(bb); // Convertit la réponse reçue en un string

            label2.Text += Environment.NewLine + Response;  // Afficher, sur une nouvelle ligne, la reponse du serveur */
            Envoie_Erreur();
        }
    }
}
