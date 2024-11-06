namespace OscilloscopeGUI
{
    partial class FrmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            cbResources = new ComboBox();
            SuspendLayout();
            // 
            // cbResources
            // 
            cbResources.FormattingEnabled = true;
            cbResources.Location = new Point(12, 12);
            cbResources.Name = "cbResources";
            cbResources.Size = new Size(151, 28);
            cbResources.TabIndex = 0;
            // 
            // FrmMain
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(429, 157);
            Controls.Add(cbResources);
            Name = "FrmMain";
            Text = "Oscilloscope GUI v1.1";
            Load += FrmMain_Load;
            ResumeLayout(false);
        }

        #endregion

        private ComboBox cbResources;
    }
}