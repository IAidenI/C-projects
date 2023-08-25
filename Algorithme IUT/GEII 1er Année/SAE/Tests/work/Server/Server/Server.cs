using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace Server //Serveur pas ouf
{
    public partial class Server : Form
    {
        delegate void showMessageInThread(string message);
        UdpClient listener = null;
        IPEndPoint endpoint = null;
        Thread listenThread = null;
        public Server()
        {
            InitializeComponent();
            Text = "Serveur";
        }
        private void button1_Click(object sender, EventArgs e)
        {
            startServer();
        }
        private void startServer()
        {
            endpoint = new IPEndPoint(IPAddress.Parse("192.168.0.99"), 1234);
            listener = new UdpClient(endpoint);
            label1.Text = "Waiting for a client!";

            listenThread = new Thread(new ThreadStart(Listening));
            listenThread.Start();
        }
        private void Listening()
        {
            while (true)
            {
                byte[] comingDataFromClient = listener.Receive(ref endpoint);
                ImageConverter convertData = new ImageConverter();
                Image image = (Image)convertData.ConvertFrom(comingDataFromClient);
                pictureBox1.Image = image;
            }
        }
    }
}
