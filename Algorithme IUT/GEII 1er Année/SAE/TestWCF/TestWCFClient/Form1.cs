using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.ServiceModel;
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace TestWCFClient
{
    public partial class FormClient : Form
    {
        TestWCF.IService s;

        public FormClient()
        {
            InitializeComponent();
        }

        private void buttonPing_Click(object sender, EventArgs e)
        {
            IPAddress ipAdress = IPAddress.Parse("192.168.0.99");
            IPEndPoint ipEndpoint = new IPEndPoint(ipAdress, 32000);
            Socket client = new Socket(ipAdress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            byte[] data = new byte[10];

            client.Connect(ipEndpoint);
            
            listBox1.Items.Add("Socket created to {0}" + client.RemoteEndPoint.ToString());

            byte[] sendmsg = Encoding.ASCII.GetBytes("test");

            int n = client.Send(sendmsg);

            client.Shutdown(SocketShutdown.Both);
            client.Close();
        }

        private void FormClient_FormClosed(object sender, FormClosedEventArgs e)
        {
            (s as ICommunicationObject).Close();
        }
    }
}
