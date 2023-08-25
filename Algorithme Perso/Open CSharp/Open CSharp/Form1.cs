using System;
using System.Threading;
using WindowsInput;
using WindowsInput.Native;
using System.Windows.Forms;

namespace Open_CSharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Simule l'appui sur la touche windows
            var sim = new InputSimulator();
            sim.Keyboard.KeyPress(VirtualKeyCode.LWIN);

            // Tape "Bonjour, monde!"
            sim.Keyboard.TextEntry("salut");

            // Attend 200ms avant d'appuyer sur entrer (pour laisser le temps a l'ordinateur de faire la recherche)
            Thread.Sleep(200);
            sim.Keyboard.KeyPress(VirtualKeyCode.RETURN);
        }
    }
}
