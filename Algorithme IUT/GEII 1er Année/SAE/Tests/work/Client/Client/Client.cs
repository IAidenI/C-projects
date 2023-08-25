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

namespace Client
{
    public partial class Client : Form
    {
        Socket server = null;
        MemoryStream ms;
        IPEndPoint endpoint = null;
        public Client()
        {
            InitializeComponent();
            Text = "Client";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            server = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            endpoint = new IPEndPoint(IPAddress.Parse("192.168.0.99"), 1234);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.ShowDialog();
            string path = openFileDialog1.FileName;
            pictureBox1.Image = Image.FromFile(path);
            label1.Text = path;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ms = new MemoryStream();
            Bitmap bmp = new Bitmap(this.openFileDialog1.FileName);
            bmp.Save(ms, System.Drawing.Imaging.ImageFormat.Jpeg);
            byte[] byteArray = ms.ToArray();

            server.Connect(endpoint);
            server.SendTo(byteArray, endpoint);
        }
    }
}
