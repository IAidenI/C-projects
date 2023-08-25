using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

using System.Net;
using System.Net.Sockets;

namespace Test3
{
    public partial class Form_Server : Form
    {
        static IPAddress ipAd = IPAddress.Parse("192.168.0.99");
        static int PortNumber = 32000;

        TcpListener ServerListener = new TcpListener(ipAd, PortNumber);
        TcpClient clientSocket = default(TcpClient);
        public Form_Server()
        {
            InitializeComponent();
            Text = "Server";
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            Thread ThreadingServer = new Thread(StartServer);
            ThreadingServer.Start();
        }
        private void THREAD_MOD1(string teste)
        {
            label1.Text += Environment.NewLine + teste;
        }

        private void THREAD_MOD2(string teste)
        {
            label2.Text += Environment.NewLine + teste;
        }
        private void StartServer()
        {
            Action<string> DelegateTeste_ModifyText = THREAD_MOD1;
            Action<string> DelegateTeste2_ModifyText = THREAD_MOD2;
            ServerListener.Start();
            Invoke(DelegateTeste_ModifyText, "Server waiting connections!");
            clientSocket = ServerListener.AcceptTcpClient();
            Invoke(DelegateTeste_ModifyText, "Server ready!");

            while (true)
            {
                try
                {
                    NetworkStream networkStream = clientSocket.GetStream();
                    byte[] bytesFrom = new byte[20];
                    networkStream.Read(bytesFrom, 0, 20);
                    string dataFromClient = System.Text.Encoding.ASCII.GetString(bytesFrom);
                    dataFromClient = dataFromClient.Substring(0, dataFromClient.IndexOf("$"));
                    Invoke(DelegateTeste2_ModifyText, dataFromClient);
                    networkStream.Flush();
                }
                catch
                {
                    ServerListener.Stop();
                    ServerListener.Start();
                    Invoke(DelegateTeste_ModifyText, "Server waiting connections!");
                    clientSocket = ServerListener.AcceptTcpClient();
                    Invoke(DelegateTeste_ModifyText, "Server ready!");
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            NetworkStream networkStream = clientSocket.GetStream();
            string serverResponse = textBox1.Text;
            Byte[] sendBytes = Encoding.ASCII.GetBytes(serverResponse);
            networkStream.Write(sendBytes, 0, sendBytes.Length);
            networkStream.Flush();
        }
    }
}
