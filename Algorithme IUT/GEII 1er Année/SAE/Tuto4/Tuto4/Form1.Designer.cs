
namespace Tuto4
{
    partial class Form1
    {
        /// <summary>
        /// Variable nécessaire au concepteur.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Nettoyage des ressources utilisées.
        /// </summary>
        /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Code généré par le Concepteur Windows Form

        /// <summary>
        /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
        /// le contenu de cette méthode avec l'éditeur de code.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.buttonGris = new System.Windows.Forms.Button();
            this.buttonNormal = new System.Windows.Forms.Button();
            this.buttonNoirBlanc = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(3, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(794, 328);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.Filter = "Ficher images | *.bmp;*.png;*.gif;*.jp | Tous les fichiers | *.*";
            this.openFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.openFileDialog1_FileOk);
            // 
            // buttonGris
            // 
            this.buttonGris.Location = new System.Drawing.Point(614, 390);
            this.buttonGris.Name = "buttonGris";
            this.buttonGris.Size = new System.Drawing.Size(133, 32);
            this.buttonGris.TabIndex = 1;
            this.buttonGris.Text = "Gris";
            this.buttonGris.UseVisualStyleBackColor = true;
            this.buttonGris.Click += new System.EventHandler(this.buttonGris_Click);
            // 
            // buttonNormal
            // 
            this.buttonNormal.Location = new System.Drawing.Point(53, 390);
            this.buttonNormal.Name = "buttonNormal";
            this.buttonNormal.Size = new System.Drawing.Size(103, 32);
            this.buttonNormal.TabIndex = 2;
            this.buttonNormal.Text = "Normal";
            this.buttonNormal.UseVisualStyleBackColor = true;
            this.buttonNormal.Click += new System.EventHandler(this.buttonNormal_Click);
            // 
            // buttonNoirBlanc
            // 
            this.buttonNoirBlanc.Location = new System.Drawing.Point(304, 390);
            this.buttonNoirBlanc.Name = "buttonNoirBlanc";
            this.buttonNoirBlanc.Size = new System.Drawing.Size(137, 32);
            this.buttonNoirBlanc.TabIndex = 3;
            this.buttonNoirBlanc.Text = "Négatif";
            this.buttonNoirBlanc.UseVisualStyleBackColor = true;
            this.buttonNoirBlanc.Click += new System.EventHandler(this.buttonNoirBlanc_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.buttonNoirBlanc);
            this.Controls.Add(this.buttonNormal);
            this.Controls.Add(this.buttonGris);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Form1_KeyPress);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button buttonGris;
        private System.Windows.Forms.Button buttonNormal;
        private System.Windows.Forms.Button buttonNoirBlanc;
    }
}

