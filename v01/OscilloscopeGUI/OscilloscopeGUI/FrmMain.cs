using OscilloscopeLIB;

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
            RefreshDevices();
        }

        private void RefreshDevices()
        {
            cmbResources.Items.Clear();
            cmbResources.Items.AddRange(Oscilloscope.GetResources());
            cmbResources.SelectedIndex = cmbResources.Items.Count - 1;
        }

        private string[] GetResources()
        {
            string[] results = new string[] { "Resource 1", "Resource 2", "Resource 3" };
            return results;
        }

        private void btnRefresh_Click(object sender, EventArgs e)
        {
            RefreshDevices();
        }
    }
}
