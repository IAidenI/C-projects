using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.ServiceModel;
using System.ServiceModel.Channels;
using System.Net;
using System.Net.Sockets;
using System.IO;

namespace TestWCFServer
{
    public partial class FormServeur : Form
    {
        [ServiceBehavior(InstanceContextMode = InstanceContextMode.Single)]
        class ServiceImplementation : TestWCF.IService
        {
            FormServeur ihm;
            public ServiceImplementation(FormServeur f)
            {
                ihm = f;
            }

            public string Ping(string name)
            {
                string ip = (OperationContext.Current.IncomingMessageProperties[RemoteEndpointMessageProperty.Name] as RemoteEndpointMessageProperty).Address;
                ihm.listBox1.Items.Add(name + " is calling from " + ip);
                return "Hello, " + name;
                  
             }
        }

        public FormServeur()
        {
            InitializeComponent();

            byte[] buffer = new byte[1000];
            string data = null;

            IPAddress ipAddress = IPAddress.Parse("192.168.0.99");
            IPEndPoint localEndpoint = new IPEndPoint(ipAddress, 32000);
            Socket sock = new Socket(ipAddress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            sock.Bind(localEndpoint);
            sock.Listen(5);

            //listBox1.Items.Add("\nWaiting for clients..");
            Socket confd = sock.Accept();
            int b = confd.Receive(buffer);
            data += Encoding.ASCII.GetString(buffer, 0, b);
            listBox1.Items.Add("" + data);
            data = null;
            confd.Close();
            listBox1.Items.Add("Fin de transmition");
        }
    }
}
