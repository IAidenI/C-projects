﻿namespace TestWCFClient
{
    partial class FormClient
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
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.textBoxPing = new System.Windows.Forms.TextBox();
            this.buttonPing = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 16;
            this.listBox1.Location = new System.Drawing.Point(0, 44);
            this.listBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(389, 292);
            this.listBox1.TabIndex = 0;
            // 
            // textBoxPing
            // 
            this.textBoxPing.Location = new System.Drawing.Point(15, 11);
            this.textBoxPing.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBoxPing.Name = "textBoxPing";
            this.textBoxPing.Size = new System.Drawing.Size(132, 22);
            this.textBoxPing.TabIndex = 1;
            this.textBoxPing.Text = "BB";
            // 
            // buttonPing
            // 
            this.buttonPing.Location = new System.Drawing.Point(201, 7);
            this.buttonPing.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonPing.Name = "buttonPing";
            this.buttonPing.Size = new System.Drawing.Size(100, 28);
            this.buttonPing.TabIndex = 2;
            this.buttonPing.Text = "Ping";
            this.buttonPing.UseVisualStyleBackColor = true;
            this.buttonPing.Click += new System.EventHandler(this.buttonPing_Click);
            // 
            // FormClient
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(389, 336);
            this.Controls.Add(this.buttonPing);
            this.Controls.Add(this.textBoxPing);
            this.Controls.Add(this.listBox1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "FormClient";
            this.Text = "Client";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.FormClient_FormClosed);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.TextBox textBoxPing;
        private System.Windows.Forms.Button buttonPing;
    }
}

