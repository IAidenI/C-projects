
namespace Tuto2
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
            this.buttonSimple = new System.Windows.Forms.Button();
            this.buttonChoix = new System.Windows.Forms.Button();
            this.labelChoix = new System.Windows.Forms.Label();
            this.buttonFichier = new System.Windows.Forms.Button();
            this.labelFichier = new System.Windows.Forms.Label();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.buttonPerso = new System.Windows.Forms.Button();
            this.labelPerso = new System.Windows.Forms.Label();
            this.buttonColor = new System.Windows.Forms.Button();
            this.buttonFont = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonSimple
            // 
            this.buttonSimple.Location = new System.Drawing.Point(16, 15);
            this.buttonSimple.Margin = new System.Windows.Forms.Padding(4);
            this.buttonSimple.Name = "buttonSimple";
            this.buttonSimple.Size = new System.Drawing.Size(181, 62);
            this.buttonSimple.TabIndex = 0;
            this.buttonSimple.Text = "Message Simple";
            this.buttonSimple.UseVisualStyleBackColor = true;
            this.buttonSimple.Click += new System.EventHandler(this.buttonSimple_Click);
            // 
            // buttonChoix
            // 
            this.buttonChoix.Location = new System.Drawing.Point(16, 124);
            this.buttonChoix.Margin = new System.Windows.Forms.Padding(4);
            this.buttonChoix.Name = "buttonChoix";
            this.buttonChoix.Size = new System.Drawing.Size(181, 62);
            this.buttonChoix.TabIndex = 1;
            this.buttonChoix.Text = "Choix Message";
            this.buttonChoix.UseVisualStyleBackColor = true;
            this.buttonChoix.Click += new System.EventHandler(this.buttonChoix_Click);
            // 
            // labelChoix
            // 
            this.labelChoix.AutoSize = true;
            this.labelChoix.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelChoix.Location = new System.Drawing.Point(229, 142);
            this.labelChoix.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelChoix.Name = "labelChoix";
            this.labelChoix.Size = new System.Drawing.Size(159, 25);
            this.labelChoix.TabIndex = 2;
            this.labelChoix.Text = "Retour Utilisateur";
            // 
            // buttonFichier
            // 
            this.buttonFichier.Location = new System.Drawing.Point(16, 238);
            this.buttonFichier.Margin = new System.Windows.Forms.Padding(4);
            this.buttonFichier.Name = "buttonFichier";
            this.buttonFichier.Size = new System.Drawing.Size(181, 62);
            this.buttonFichier.TabIndex = 3;
            this.buttonFichier.Text = "Ouvrir...";
            this.buttonFichier.UseVisualStyleBackColor = true;
            this.buttonFichier.Click += new System.EventHandler(this.buttonFichier_Click);
            // 
            // labelFichier
            // 
            this.labelFichier.AutoSize = true;
            this.labelFichier.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelFichier.Location = new System.Drawing.Point(229, 255);
            this.labelFichier.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelFichier.Name = "labelFichier";
            this.labelFichier.Size = new System.Drawing.Size(147, 25);
            this.labelFichier.TabIndex = 4;
            this.labelFichier.Text = "Nome du fichier";
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // buttonPerso
            // 
            this.buttonPerso.Location = new System.Drawing.Point(16, 345);
            this.buttonPerso.Name = "buttonPerso";
            this.buttonPerso.Size = new System.Drawing.Size(181, 62);
            this.buttonPerso.TabIndex = 5;
            this.buttonPerso.Text = "Message peronnalisé";
            this.buttonPerso.UseVisualStyleBackColor = true;
            this.buttonPerso.Click += new System.EventHandler(this.buttonPerso_Click);
            // 
            // labelPerso
            // 
            this.labelPerso.AutoSize = true;
            this.labelPerso.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelPerso.Location = new System.Drawing.Point(231, 368);
            this.labelPerso.Name = "labelPerso";
            this.labelPerso.Size = new System.Drawing.Size(193, 31);
            this.labelPerso.TabIndex = 6;
            this.labelPerso.Text = "Retour message";
            // 
            // buttonColor
            // 
            this.buttonColor.Location = new System.Drawing.Point(40, 442);
            this.buttonColor.Name = "buttonColor";
            this.buttonColor.Size = new System.Drawing.Size(127, 33);
            this.buttonColor.TabIndex = 7;
            this.buttonColor.Text = "Choisir la couleur";
            this.buttonColor.UseVisualStyleBackColor = true;
            this.buttonColor.Click += new System.EventHandler(this.buttonColor_Click);
            // 
            // buttonFont
            // 
            this.buttonFont.Location = new System.Drawing.Point(40, 481);
            this.buttonFont.Name = "buttonFont";
            this.buttonFont.Size = new System.Drawing.Size(127, 33);
            this.buttonFont.TabIndex = 8;
            this.buttonFont.Text = "Choisir la police";
            this.buttonFont.UseVisualStyleBackColor = true;
            this.buttonFont.Click += new System.EventHandler(this.buttonFont_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1067, 554);
            this.Controls.Add(this.buttonFont);
            this.Controls.Add(this.buttonColor);
            this.Controls.Add(this.labelPerso);
            this.Controls.Add(this.buttonPerso);
            this.Controls.Add(this.labelFichier);
            this.Controls.Add(this.buttonFichier);
            this.Controls.Add(this.labelChoix);
            this.Controls.Add(this.buttonChoix);
            this.Controls.Add(this.buttonSimple);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonSimple;
        private System.Windows.Forms.Button buttonChoix;
        private System.Windows.Forms.Label labelChoix;
        private System.Windows.Forms.Button buttonFichier;
        private System.Windows.Forms.Label labelFichier;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button buttonPerso;
        private System.Windows.Forms.Label labelPerso;
        private System.Windows.Forms.Button buttonColor;
        private System.Windows.Forms.Button buttonFont;
    }
}

