using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OscilloscopeGUI
{
    public partial class FrmMain : Form
    {
        public FrmMain()
        {
            InitializeComponent();
        }

        private void FrmMain_Load(object sender, EventArgs e)
        {
            cbResources.Items.Clear();
            cbResources.Items.AddRange(Oscilloscope.GetResources());
            cbResources.SelectedIndex = cbResources.Items.Count - 1;
        }
    }
}
