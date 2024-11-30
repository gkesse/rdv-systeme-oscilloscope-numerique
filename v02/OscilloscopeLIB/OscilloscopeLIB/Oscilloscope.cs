using System.Diagnostics;
using NationalInstruments.Visa;

namespace OscilloscopeLIB
{
    public class Oscilloscope
    {
        static ResourceManager _resManager = new ResourceManager();

        public static string[] GetResources()
        {
            string[] results = new string[] { };
            try
            {
                results = _resManager.Find("?*").ToArray();
            }
            catch (Exception ex)
            {
                Debug.WriteLine(ex);
            }
            return results;
        }
    }
}
