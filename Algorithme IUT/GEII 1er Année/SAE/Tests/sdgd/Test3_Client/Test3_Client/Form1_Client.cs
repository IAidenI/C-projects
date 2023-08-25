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
        TcpClient tcpclnt = new TcpClient();
        IPAddress ipAd = IPAddress.Parse("192.168.0.99");
        int PortNumber = 32000;
        public Form1_Client()
        {
            InitializeComponent();
            Text = "Client";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            label1.Text = "Connecting.....";
            try
            {
                tcpclnt.Connect(ipAd, PortNumber);
                label1.Text += Environment.NewLine + "Connected";
                label1.Text += Environment.NewLine + "Enter the string to be transmitted";
            }
            catch { }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String str = textBox1.Text + "$";
            label2.Text = str;
            Stream stm = tcpclnt.GetStream();

            ASCIIEncoding asen = new ASCIIEncoding();
            byte[] ba = asen.GetBytes(str);

            label2.Text += Environment.NewLine + "Transmitting...";

            stm.Write(ba, 0, ba.Length);

            byte[] bb = new byte[100];
            int k = stm.Read(bb, 0, 100);

            string Response = Encoding.ASCII.GetString(bb);

            label2.Text += Environment.NewLine + "Response from server: " + Response;
        }
    }
}
