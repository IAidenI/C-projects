using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tuto_1
{
    public partial class Form1 : Form
    {
        int verif = 0;
        public Form1()
        {
            InitializeComponent();
            timerAuto.Enabled = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Fermer_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void labelBonjour_Click(object sender, EventArgs e)
        {

        }

        private void buttonBonjour_Click(object sender, EventArgs e)
        {
            if (labelBonjour.Text == "Hello!" || labelBonjour.Text == "Au revoir")
            {
                labelBonjour.Text = "Bonjour";
            }
            else
            {
                labelBonjour.Text = "Au revoir";
            }
            
        }

        private void buttonTransfert_Click(object sender, EventArgs e)
        {
            labelTransfert.Text = textBoxTransfert.Text;
            listBoxMessages.Items.Add(labelTransfert.Text);
        }

        private void trackBarPosition_Scroll(object sender, EventArgs e)
        {
            progressBarPosition.Value = trackBarPosition.Value;
        }

        private void timerAuto_Tick(object sender, EventArgs e)
        {
            if (verif == 0)
            {
                if (progressBarAuto.Value == progressBarAuto.Maximum)
                {
                    verif = 1;
                }
                else
                {
                    progressBarAuto.Value++;
                    verif = 0;
                }
            }
            else
            {
                if (progressBarAuto.Value == progressBarAuto.Minimum)
                {
                    verif = 0;
                }
                else
                {
                    progressBarAuto.Value--;
                    verif = 1;
                }
            }
        }
    }
}
