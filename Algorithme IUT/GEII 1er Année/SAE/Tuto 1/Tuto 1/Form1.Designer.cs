
namespace Tuto_1
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
            this.components = new System.ComponentModel.Container();
            this.Fermer = new System.Windows.Forms.Button();
            this.buttonBonjour = new System.Windows.Forms.Button();
            this.labelBonjour = new System.Windows.Forms.Label();
            this.buttonTransfert = new System.Windows.Forms.Button();
            this.labelTransfert = new System.Windows.Forms.Label();
            this.textBoxTransfert = new System.Windows.Forms.TextBox();
            this.listBoxMessages = new System.Windows.Forms.ListBox();
            this.trackBarPosition = new System.Windows.Forms.TrackBar();
            this.progressBarPosition = new System.Windows.Forms.ProgressBar();
            this.timerAuto = new System.Windows.Forms.Timer(this.components);
            this.progressBarAuto = new System.Windows.Forms.ProgressBar();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarPosition)).BeginInit();
            this.SuspendLayout();
            // 
            // Fermer
            // 
            this.Fermer.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(255)))));
            this.Fermer.Font = new System.Drawing.Font("Vladimir Script", 72F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Fermer.Location = new System.Drawing.Point(35, 15);
            this.Fermer.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Fermer.Name = "Fermer";
            this.Fermer.Size = new System.Drawing.Size(491, 257);
            this.Fermer.TabIndex = 0;
            this.Fermer.Text = "Fermer";
            this.Fermer.UseVisualStyleBackColor = false;
            this.Fermer.Click += new System.EventHandler(this.Fermer_Click);
            // 
            // buttonBonjour
            // 
            this.buttonBonjour.Location = new System.Drawing.Point(676, 305);
            this.buttonBonjour.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonBonjour.Name = "buttonBonjour";
            this.buttonBonjour.Size = new System.Drawing.Size(569, 121);
            this.buttonBonjour.TabIndex = 1;
            this.buttonBonjour.Text = "Bonjour";
            this.buttonBonjour.UseVisualStyleBackColor = true;
            this.buttonBonjour.Click += new System.EventHandler(this.buttonBonjour_Click);
            // 
            // labelBonjour
            // 
            this.labelBonjour.AutoSize = true;
            this.labelBonjour.Location = new System.Drawing.Point(1027, 358);
            this.labelBonjour.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelBonjour.Name = "labelBonjour";
            this.labelBonjour.Size = new System.Drawing.Size(43, 17);
            this.labelBonjour.TabIndex = 2;
            this.labelBonjour.Text = "Hello!";
            // 
            // buttonTransfert
            // 
            this.buttonTransfert.Location = new System.Drawing.Point(673, 54);
            this.buttonTransfert.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.buttonTransfert.Name = "buttonTransfert";
            this.buttonTransfert.Size = new System.Drawing.Size(535, 145);
            this.buttonTransfert.TabIndex = 3;
            this.buttonTransfert.Text = "Transférer";
            this.buttonTransfert.UseVisualStyleBackColor = true;
            this.buttonTransfert.Click += new System.EventHandler(this.buttonTransfert_Click);
            // 
            // labelTransfert
            // 
            this.labelTransfert.AutoSize = true;
            this.labelTransfert.Location = new System.Drawing.Point(1015, 117);
            this.labelTransfert.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.labelTransfert.Name = "labelTransfert";
            this.labelTransfert.Size = new System.Drawing.Size(46, 17);
            this.labelTransfert.TabIndex = 4;
            this.labelTransfert.Text = "label1";
            // 
            // textBoxTransfert
            // 
            this.textBoxTransfert.Location = new System.Drawing.Point(1083, 113);
            this.textBoxTransfert.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBoxTransfert.Name = "textBoxTransfert";
            this.textBoxTransfert.Size = new System.Drawing.Size(84, 22);
            this.textBoxTransfert.TabIndex = 5;
            // 
            // listBoxMessages
            // 
            this.listBoxMessages.FormattingEnabled = true;
            this.listBoxMessages.ItemHeight = 16;
            this.listBoxMessages.Location = new System.Drawing.Point(723, 89);
            this.listBoxMessages.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.listBoxMessages.Name = "listBoxMessages";
            this.listBoxMessages.Size = new System.Drawing.Size(119, 84);
            this.listBoxMessages.TabIndex = 6;
            // 
            // trackBarPosition
            // 
            this.trackBarPosition.Location = new System.Drawing.Point(47, 343);
            this.trackBarPosition.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.trackBarPosition.Maximum = 100;
            this.trackBarPosition.Name = "trackBarPosition";
            this.trackBarPosition.Size = new System.Drawing.Size(412, 56);
            this.trackBarPosition.TabIndex = 7;
            this.trackBarPosition.TickFrequency = 10;
            this.trackBarPosition.Scroll += new System.EventHandler(this.trackBarPosition_Scroll);
            // 
            // progressBarPosition
            // 
            this.progressBarPosition.Location = new System.Drawing.Point(47, 406);
            this.progressBarPosition.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.progressBarPosition.Name = "progressBarPosition";
            this.progressBarPosition.Size = new System.Drawing.Size(469, 94);
            this.progressBarPosition.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.progressBarPosition.TabIndex = 8;
            // 
            // timerAuto
            // 
            this.timerAuto.Interval = 200;
            this.timerAuto.Tick += new System.EventHandler(this.timerAuto_Tick);
            // 
            // progressBarAuto
            // 
            this.progressBarAuto.Location = new System.Drawing.Point(676, 500);
            this.progressBarAuto.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.progressBarAuto.Name = "progressBarAuto";
            this.progressBarAuto.Size = new System.Drawing.Size(569, 82);
            this.progressBarAuto.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.progressBarAuto.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(1299, 677);
            this.Controls.Add(this.progressBarAuto);
            this.Controls.Add(this.progressBarPosition);
            this.Controls.Add(this.trackBarPosition);
            this.Controls.Add(this.listBoxMessages);
            this.Controls.Add(this.textBoxTransfert);
            this.Controls.Add(this.labelTransfert);
            this.Controls.Add(this.buttonTransfert);
            this.Controls.Add(this.labelBonjour);
            this.Controls.Add(this.buttonBonjour);
            this.Controls.Add(this.Fermer);
            this.Cursor = System.Windows.Forms.Cursors.Arrow;
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "Form1";
            this.Text = "Tuto1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.trackBarPosition)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Fermer;
        private System.Windows.Forms.Button buttonBonjour;
        private System.Windows.Forms.Label labelBonjour;
        private System.Windows.Forms.Button buttonTransfert;
        private System.Windows.Forms.Label labelTransfert;
        private System.Windows.Forms.TextBox textBoxTransfert;
        private System.Windows.Forms.ListBox listBoxMessages;
        private System.Windows.Forms.TrackBar trackBarPosition;
        private System.Windows.Forms.ProgressBar progressBarPosition;
        private System.Windows.Forms.Timer timerAuto;
        private System.Windows.Forms.ProgressBar progressBarAuto;
    }
}

