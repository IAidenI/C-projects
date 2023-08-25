using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.ServiceModel;

namespace TestWCFServer
{
    public partial class FormServeur : Form
    {
        [ServiceBehavior(InstanceContextMode = InstanceContextMode.Single)]
        class ServiceImplementation : TestWCF.IService
        {
            FormServeur parent;
            public ServiceImplementation(FormServeur f)
            {
                parent = f;
            }

            public string Ping(string name)
            {
                parent.listBox1.Items.Add(name + " is calling");
                return "Hello, " + name;
            }
        }

        ServiceHost svh; 

        public FormServeur()
        {
            InitializeComponent();
            svh = new ServiceHost(typeof(TestWCF.ServiceImplementation2));
            //svh = new ServiceHost(new ServiceImplementation(this));
            svh.AddServiceEndpoint(
                typeof(TestWCF.IService),
                new NetTcpBinding(),
                "net.tcp://localhost:8000");
            svh.Open();
            

        }
    }
}
