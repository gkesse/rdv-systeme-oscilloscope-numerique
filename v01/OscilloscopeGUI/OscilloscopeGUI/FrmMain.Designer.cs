namespace OscilloscopeGUI
{
    partial class FrmMain
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FrmMain));
            cmbResources = new ComboBox();
            btnRefresh = new Button();
            btnConnect = new Button();
            grbAcquisition = new GroupBox();
            lblPointsValue = new Label();
            lblPoints = new Label();
            panel1 = new Panel();
            radNormalMemoryDepth = new RadioButton();
            radLongMemoryDepth = new RadioButton();
            radMaximumPointsMode = new RadioButton();
            radNormalPointsMode = new RadioButton();
            lblPointsMode = new Label();
            lblMemoryDepth = new Label();
            chbChannel2 = new CheckBox();
            chbChannel1 = new CheckBox();
            lblChannels = new Label();
            lblGnuPlotPath = new Label();
            txbGnuPlotPath = new TextBox();
            lblOutput = new Label();
            radGnuPlot = new RadioButton();
            radPngImage = new RadioButton();
            btnSave = new Button();
            grbAcquisition.SuspendLayout();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // cmbResources
            // 
            cmbResources.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            cmbResources.FormattingEnabled = true;
            cmbResources.Location = new Point(12, 12);
            cmbResources.Name = "cmbResources";
            cmbResources.Size = new Size(344, 28);
            cmbResources.TabIndex = 0;
            // 
            // btnRefresh
            // 
            btnRefresh.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnRefresh.Location = new Point(375, 12);
            btnRefresh.Name = "btnRefresh";
            btnRefresh.Size = new Size(94, 29);
            btnRefresh.TabIndex = 1;
            btnRefresh.Text = "&Refresh";
            btnRefresh.UseVisualStyleBackColor = true;
            btnRefresh.Click += btnRefresh_Click;
            // 
            // btnConnect
            // 
            btnConnect.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            btnConnect.Location = new Point(12, 56);
            btnConnect.Name = "btnConnect";
            btnConnect.Size = new Size(457, 29);
            btnConnect.TabIndex = 2;
            btnConnect.Text = "&Connect to selected device";
            btnConnect.UseVisualStyleBackColor = true;
            btnConnect.Click += btnConnect_Click;
            // 
            // grbAcquisition
            // 
            grbAcquisition.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            grbAcquisition.Controls.Add(lblPointsValue);
            grbAcquisition.Controls.Add(lblPoints);
            grbAcquisition.Controls.Add(panel1);
            grbAcquisition.Controls.Add(radMaximumPointsMode);
            grbAcquisition.Controls.Add(radNormalPointsMode);
            grbAcquisition.Controls.Add(lblPointsMode);
            grbAcquisition.Controls.Add(lblMemoryDepth);
            grbAcquisition.Controls.Add(chbChannel2);
            grbAcquisition.Controls.Add(chbChannel1);
            grbAcquisition.Controls.Add(lblChannels);
            grbAcquisition.Location = new Point(12, 102);
            grbAcquisition.Name = "grbAcquisition";
            grbAcquisition.Size = new Size(457, 192);
            grbAcquisition.TabIndex = 3;
            grbAcquisition.TabStop = false;
            grbAcquisition.Text = "Acquisition";
            // 
            // lblPointsValue
            // 
            lblPointsValue.AutoSize = true;
            lblPointsValue.Location = new Point(153, 156);
            lblPointsValue.Name = "lblPointsValue";
            lblPointsValue.Size = new Size(33, 20);
            lblPointsValue.TabIndex = 11;
            lblPointsValue.Text = "600";
            // 
            // lblPoints
            // 
            lblPoints.AutoSize = true;
            lblPoints.Location = new Point(78, 156);
            lblPoints.Name = "lblPoints";
            lblPoints.Size = new Size(48, 20);
            lblPoints.TabIndex = 10;
            lblPoints.Text = "Points";
            // 
            // panel1
            // 
            panel1.Controls.Add(radNormalMemoryDepth);
            panel1.Controls.Add(radLongMemoryDepth);
            panel1.Location = new Point(138, 65);
            panel1.Name = "panel1";
            panel1.Size = new Size(250, 38);
            panel1.TabIndex = 9;
            // 
            // radNormalMemoryDepth
            // 
            radNormalMemoryDepth.AutoSize = true;
            radNormalMemoryDepth.Checked = true;
            radNormalMemoryDepth.Location = new Point(15, 8);
            radNormalMemoryDepth.Name = "radNormalMemoryDepth";
            radNormalMemoryDepth.Size = new Size(80, 24);
            radNormalMemoryDepth.TabIndex = 4;
            radNormalMemoryDepth.TabStop = true;
            radNormalMemoryDepth.Text = "Normal";
            radNormalMemoryDepth.UseVisualStyleBackColor = true;
            // 
            // radLongMemoryDepth
            // 
            radLongMemoryDepth.AutoSize = true;
            radLongMemoryDepth.Location = new Point(130, 8);
            radLongMemoryDepth.Name = "radLongMemoryDepth";
            radLongMemoryDepth.Size = new Size(63, 24);
            radLongMemoryDepth.TabIndex = 5;
            radLongMemoryDepth.Text = "Long";
            radLongMemoryDepth.UseVisualStyleBackColor = true;
            // 
            // radMaximumPointsMode
            // 
            radMaximumPointsMode.AutoSize = true;
            radMaximumPointsMode.Location = new Point(268, 115);
            radMaximumPointsMode.Name = "radMaximumPointsMode";
            radMaximumPointsMode.Size = new Size(96, 24);
            radMaximumPointsMode.TabIndex = 8;
            radMaximumPointsMode.Text = "Maximum";
            radMaximumPointsMode.UseVisualStyleBackColor = true;
            // 
            // radNormalPointsMode
            // 
            radNormalPointsMode.AutoSize = true;
            radNormalPointsMode.Checked = true;
            radNormalPointsMode.Location = new Point(153, 115);
            radNormalPointsMode.Name = "radNormalPointsMode";
            radNormalPointsMode.Size = new Size(80, 24);
            radNormalPointsMode.TabIndex = 7;
            radNormalPointsMode.TabStop = true;
            radNormalPointsMode.Text = "Normal";
            radNormalPointsMode.UseVisualStyleBackColor = true;
            // 
            // lblPointsMode
            // 
            lblPointsMode.AutoSize = true;
            lblPointsMode.Location = new Point(35, 117);
            lblPointsMode.Name = "lblPointsMode";
            lblPointsMode.Size = new Size(91, 20);
            lblPointsMode.TabIndex = 6;
            lblPointsMode.Text = "Points Mode";
            // 
            // lblMemoryDepth
            // 
            lblMemoryDepth.AutoSize = true;
            lblMemoryDepth.Location = new Point(17, 75);
            lblMemoryDepth.Name = "lblMemoryDepth";
            lblMemoryDepth.Size = new Size(109, 20);
            lblMemoryDepth.TabIndex = 3;
            lblMemoryDepth.Text = "Memory Depth";
            // 
            // chbChannel2
            // 
            chbChannel2.AutoSize = true;
            chbChannel2.Location = new Point(268, 35);
            chbChannel2.Name = "chbChannel2";
            chbChannel2.Size = new Size(96, 24);
            chbChannel2.TabIndex = 2;
            chbChannel2.Text = "Channel 2";
            chbChannel2.UseVisualStyleBackColor = true;
            // 
            // chbChannel1
            // 
            chbChannel1.AutoSize = true;
            chbChannel1.Checked = true;
            chbChannel1.CheckState = CheckState.Checked;
            chbChannel1.Location = new Point(153, 35);
            chbChannel1.Name = "chbChannel1";
            chbChannel1.Size = new Size(96, 24);
            chbChannel1.TabIndex = 1;
            chbChannel1.Text = "Channel 1";
            chbChannel1.UseVisualStyleBackColor = true;
            // 
            // lblChannels
            // 
            lblChannels.AutoSize = true;
            lblChannels.Location = new Point(58, 35);
            lblChannels.Name = "lblChannels";
            lblChannels.Size = new Size(68, 20);
            lblChannels.TabIndex = 0;
            lblChannels.Text = "Channels";
            // 
            // lblGnuPlotPath
            // 
            lblGnuPlotPath.AutoSize = true;
            lblGnuPlotPath.Location = new Point(41, 307);
            lblGnuPlotPath.Name = "lblGnuPlotPath";
            lblGnuPlotPath.Size = new Size(97, 20);
            lblGnuPlotPath.TabIndex = 4;
            lblGnuPlotPath.Text = "Gnu Plot Path";
            // 
            // txbGnuPlotPath
            // 
            txbGnuPlotPath.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
            txbGnuPlotPath.Location = new Point(165, 307);
            txbGnuPlotPath.Name = "txbGnuPlotPath";
            txbGnuPlotPath.Size = new Size(304, 27);
            txbGnuPlotPath.TabIndex = 5;
            // 
            // lblOutput
            // 
            lblOutput.AutoSize = true;
            lblOutput.Location = new Point(83, 344);
            lblOutput.Name = "lblOutput";
            lblOutput.Size = new Size(55, 20);
            lblOutput.TabIndex = 6;
            lblOutput.Text = "Output";
            // 
            // radGnuPlot
            // 
            radGnuPlot.AutoSize = true;
            radGnuPlot.Location = new Point(165, 342);
            radGnuPlot.Name = "radGnuPlot";
            radGnuPlot.Size = new Size(86, 24);
            radGnuPlot.TabIndex = 7;
            radGnuPlot.Text = "Gnu Plot";
            radGnuPlot.UseVisualStyleBackColor = true;
            // 
            // radPngImage
            // 
            radPngImage.AutoSize = true;
            radPngImage.Checked = true;
            radPngImage.Location = new Point(280, 344);
            radPngImage.Name = "radPngImage";
            radPngImage.Size = new Size(105, 24);
            radPngImage.TabIndex = 8;
            radPngImage.TabStop = true;
            radPngImage.Text = "PNG Image";
            radPngImage.UseVisualStyleBackColor = true;
            // 
            // btnSave
            // 
            btnSave.Anchor = AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            btnSave.Location = new Point(12, 382);
            btnSave.Name = "btnSave";
            btnSave.Size = new Size(457, 29);
            btnSave.TabIndex = 9;
            btnSave.Text = "&Save CSV and output";
            btnSave.UseVisualStyleBackColor = true;
            // 
            // FrmMain
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(481, 423);
            Controls.Add(btnSave);
            Controls.Add(radPngImage);
            Controls.Add(radGnuPlot);
            Controls.Add(lblOutput);
            Controls.Add(txbGnuPlotPath);
            Controls.Add(lblGnuPlotPath);
            Controls.Add(grbAcquisition);
            Controls.Add(btnConnect);
            Controls.Add(btnRefresh);
            Controls.Add(cmbResources);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Icon = (Icon)resources.GetObject("$this.Icon");
            Name = "FrmMain";
            Text = "ReadyScope – Oscilloscope Numérique";
            Load += FrmMain_Load;
            grbAcquisition.ResumeLayout(false);
            grbAcquisition.PerformLayout();
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ComboBox cmbResources;
        private Button btnRefresh;
        private Button btnConnect;
        private GroupBox grbAcquisition;
        private Label lblChannels;
        private CheckBox chbChannel2;
        private CheckBox chbChannel1;
        private Label lblMemoryDepth;
        private RadioButton radNormalMemoryDepth;
        private RadioButton radLongMemoryDepth;
        private RadioButton radMaximumPointsMode;
        private RadioButton radNormalPointsMode;
        private Label lblPointsMode;
        private Panel panel1;
        private Label lblPoints;
        private Label lblPointsValue;
        private Label lblGnuPlotPath;
        private TextBox txbGnuPlotPath;
        private Label lblOutput;
        private RadioButton radGnuPlot;
        private RadioButton radPngImage;
        private Button btnSave;
    }
}
