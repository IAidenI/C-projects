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
using System.IO;
using System.Net.Sockets;
using System.Runtime.Serialization.Formatters.Binary;

namespace Test3
{
    public partial class Form_Server : Form
    {
        public Form_Server()
        {
            InitializeComponent();
            Text = "Server";
            reception();
        }

        public void reception()
        {
            IPAddress ipAddress = IPAddress.Parse("192.168.0.99");
            IPEndPoint localEndPoint = new IPEndPoint(ipAddress, 32000);
           
            Socket listener = new Socket(ipAddress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            listener.Bind(localEndPoint);
            listener.Listen(10);

            Socket handler = listener.Accept();

            string data = null;
            byte[] bytes = null;

            byte[] comingDataFromClient = listener.Receive(localEndPoint);
            ImageConverter convertData = new ImageConverter();
            Image image = (Image)convertData.ConvertFrom(comingDataFromClient);
            pictureBox1.Image = image;

            /*while (true)
            {
                bytes = new byte[1024];
                int bytesRec = handler.Receive(bytes);
                data += Encoding.ASCII.GetString(bytes, 0, bytesRec);
                if (data.IndexOf(".") > -1)
                {
                    break;
                }
            }
            label1.Text = data;*/

            byte[] msg = Encoding.ASCII.GetBytes("Salut bg.");
            label2.Text = System.Text.Encoding.UTF8.GetString(msg);
            handler.Send(msg);
            handler.Close();
        }
    }
}
