using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tuto4
{
    public partial class Form1 : Form
    {
        int rgb;
        Bitmap image2;
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                pictureBox1.Load(openFileDialog1.FileName);
                Text = openFileDialog1.SafeFileName;
                image2 = pictureBox1.Image as Bitmap;
            }
        }

        private void buttonNormal_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                pictureBox1.Load(openFileDialog1.FileName);
                Bitmap image = pictureBox1.Image as Bitmap;
                for (int i = 0; i < image.Width; i++)
                {
                    for (int j = 0; j < image.Height; j++)
                    {
                        Color c = image.GetPixel(i, j);
                        image.SetPixel(i, j, Color.FromArgb(c.R, c.G, c.B));
                    }
                }
                pictureBox1.Refresh();
            }
        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {

        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            
        }

        private void buttonNoirBlanc_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                pictureBox1.Load(openFileDialog1.FileName);
                Bitmap image = pictureBox1.Image as Bitmap;
                for (int i = 0; i < image.Width; i++)
                {
                    for (int j = 0; j < image.Height; j++)
                    {
                        Color c = image.GetPixel(i, j);
                        image.SetPixel(i, j, Color.FromArgb(255 - c.R, 255 - c.G, 255 - c.B));
                    }
                }
                pictureBox1.Refresh();
            }
        }

        private void buttonGris_Click(object sender, EventArgs e)
        {
            if (pictureBox1.Image != null)
            {
                pictureBox1.Load(openFileDialog1.FileName);
                Bitmap image = pictureBox1.Image as Bitmap;
                for (int i = 0; i < image.Width; i++)
                {
                    for (int j = 0; j < image.Height; j++)
                    {
                        Color c = image.GetPixel(i, j);
                        rgb = (c.R + c.G + c.B) / 3;
                        image.SetPixel(i, j, Color.FromArgb(rgb, rgb, rgb));
                    }
                }
                pictureBox1.Refresh();
            }
        }
    }
}
