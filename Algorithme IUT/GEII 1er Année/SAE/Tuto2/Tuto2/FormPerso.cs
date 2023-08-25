using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tuto2
{
    public partial class FormPerso : Form
    {
        public FormPerso()
        {
            InitializeComponent();
        }

        private void FormPerso_Click(object sender, EventArgs e)
        {

        }

        private void FormPerso_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (DialogResult == DialogResult.OK && textBoxMessage.TextLength < 4)
            {
                e.Cancel = true;
                MessageBox.Show("Message trop court");
            }
        }

        private void buttonOK_KeyPress(object sender, KeyPressEventArgs e)
        {

        }

        private void buttonAnnuler_KeyDown(object sender, KeyEventArgs e)
        {

        }

        private void buttonAnnuler_KeyPress(object sender, KeyPressEventArgs e)
        {

        }

        private void buttonOK_Click(object sender, EventArgs e)
        {

        }

        private void buttonOK_KeyDown(object sender, KeyEventArgs e)
        {

        }
    }
}
