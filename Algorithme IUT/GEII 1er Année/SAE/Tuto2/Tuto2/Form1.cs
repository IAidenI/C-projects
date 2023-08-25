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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void buttonSimple_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Bonjour");
        }

        private void buttonChoix_Click(object sender, EventArgs e)
        {
            DialogResult retour =  MessageBox.Show("Voulez vous enregistrer avant de quitter ?", "Fermeture de l'application", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question);

            if (retour == DialogResult.Yes)
            {
                labelChoix.Text = "Sauvegarde et fermeture.";
            }
            else if (retour == DialogResult.No)
            {
                labelChoix.Text = " Fermeture sans sauvegarde";
            }
            else
            {
                labelChoix.Text = "ni sauvegarde, ni fermeture ";
            }
        }

        private void buttonFichier_Click(object sender, EventArgs e)
        {
            DialogResult retour = openFileDialog1.ShowDialog();

            if (retour == DialogResult.OK)
            {
                labelFichier.Text = openFileDialog1.SafeFileName;
            }
            else
            {
                labelFichier.Text = "";
            }
        }

        private void buttonPerso_Click(object sender, EventArgs e)
        {
            FormPerso fenetre = new FormPerso();
            DialogResult retour = fenetre.ShowDialog();

            if (retour == DialogResult.OK)
            {
                labelPerso.Text = fenetre.textBoxMessage.Text;
            }
            else
            {
                labelPerso.Text = "";
            }
        }

        private void buttonColor_Click(object sender, EventArgs e)
        {
            ColorDialog color = new ColorDialog();
            if (color.ShowDialog() == DialogResult.OK)
            {
                labelPerso.ForeColor = color.Color;
            }
        }

        private void buttonFont_Click(object sender, EventArgs e)
        {
            FontDialog police = new FontDialog();
            if (police.ShowDialog() == DialogResult.OK)
            {
                labelPerso.Font = police.Font;
            }
        }
    }
}
