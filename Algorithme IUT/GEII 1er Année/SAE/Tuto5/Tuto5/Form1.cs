using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tuto5
{
    public partial class Form1 : Form
    {
        List<Point> tabRonds = new List<Point>();
        int xclic = -100, yclic = -100;
        Random num = new Random();
        int rand;
        string number;

        public Form1()
        {
            InitializeComponent();
            SetStyle(ControlStyles.OptimizedDoubleBuffer, true);
            SetStyle(ControlStyles.AllPaintingInWmPaint, true);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            rand = num.Next(1, 21);
            number = "" + rand;
            labelTest.Text = number;
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen stylo1 = new Pen(Brushes.Black);
            stylo1.Width = 2;
            e.Graphics.DrawRectangle(stylo1, (ClientRectangle.Width/2)-50, (ClientRectangle.Height/2)-50, 100, 100);
            /*SolidBrush pinceau = new SolidBrush(Color.Red);
            e.Graphics.FillEllipse(pinceau, xclic, yclic, 50, 50);*/
            SolidBrush pinceau2 = new SolidBrush(Color.Blue);
            foreach (Point p in tabRonds)
            {
                e.Graphics.FillEllipse(pinceau2, p.X -5, p.Y - 5, 10, 10);
            }
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            Refresh();
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == ' ')
            {
                timer1.Enabled = !timer1.Enabled;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            for (int i = 0; i < tabRonds.Count; i++)
            {
                Point p = tabRonds[i];
                p.Y += 5; //<=> p.Y += p.Y + 10
                if (p.Y >= ClientRectangle.Height)
                {
                    p.Y = 0;
                }
                tabRonds[i] = p;
            }
            Refresh();
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                xclic = e.X / 30 * 30;
                yclic = e.Y / 30 * 30;
                tabRonds.Add(new Point(xclic, yclic));
            }
            if (e.Button == MouseButtons.Middle)
            {
                tabRonds.Clear();
            }
            if (e.Button == MouseButtons.Right && tabRonds.Count != 0)
            {
                tabRonds.RemoveAt(tabRonds.Count - 1);
            }
            Refresh();
        }
    }
}
