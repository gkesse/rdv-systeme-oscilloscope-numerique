using OscilloscopeLIB;

namespace OscilloscopeGUI
{
    public partial class FrmMain : Form
    {
        Oscilloscope _osc;

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

        private void btnConnect_Click(object sender, EventArgs e)
        {
            if (cmbResources.Items.Count == 0)
            {
                MessageBox.Show("Please connect an oscilloscope, then click Refresh");
                return;
            }
            if (string.IsNullOrWhiteSpace(cmbResources.Text))
            {
                MessageBox.Show("Please select a device");
                return;
            }

            _osc = new Oscilloscope();
        }
    }
}
