using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test3_Client
{
    public partial class Form1_Client : Form
    {
        MemoryStream ms;
        public Form1_Client()
        {
            InitializeComponent();
            Text = "Client";
        }

        private Socket Connexion()
        {
            IPAddress ipAddress = IPAddress.Parse("192.168.0.99");
            Socket sock = new Socket(ipAddress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            return sock;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            Socket sock;
            IPAddress ipAddress = IPAddress.Parse("192.168.0.99");
            IPEndPoint remoteEP = new IPEndPoint(ipAddress, 32000);
            sock = Connexion();

            byte[] bytes = new byte[1024];
            sock.Connect(remoteEP);

            label1.Text = "Socket connected to" + sock.RemoteEndPoint.ToString();
            //byte[] msg = Encoding.ASCII.GetBytes(textBox1.Text + '.');
            //sock.Send(msg);
            ms = new MemoryStream();
            Bitmap bmp = new Bitmap(this.openFileDialog1.FileName);
            bmp.Save(ms, System.Drawing.Imaging.ImageFormat.Jpeg);
            byte[] byteArray = ms.ToArray();

            sock.Connect(remoteEP);
            sock.SendTo(byteArray, remoteEP);

            int bytesRec = sock.Receive(bytes);
            label2.Text += Environment.NewLine + "Echoed test = " + Encoding.ASCII.GetString(bytes, 0, bytesRec);
            sock.Shutdown(SocketShutdown.Both);
            sock.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            openFileDialog1.ShowDialog();
            string path = openFileDialog1.FileName;
            pictureBox1.Image = Image.FromFile(path);
            label1.Text = Environment.NewLine + path;
        }
    }
}