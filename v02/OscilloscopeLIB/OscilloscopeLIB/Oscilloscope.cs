using System.Diagnostics;
using NationalInstruments.Visa;

namespace OscilloscopeLIB
{
    public class Oscilloscope
    {
        static ResourceManager _resManager = new ResourceManager();
        Channel[] _channels;
        uint _numChannels;
        MessageBasedSession _mbSession;
        string _model;
        string _serialNumber;
        string _swVersion;

        public Oscilloscope(string resource = "USB?*DS1E?*INSTR", uint channels = 2)
        {
            _numChannels = channels;
            _channels = new Channel[_numChannels];
            _mbSession = (MessageBasedSession)_resManager.Open(_resManager.Find(resource).First());
            _mbSession.TimeoutMilliseconds = 1000 * 60 * 5;

            for (uint i = 0; i < _numChannels; i++)
            {
                _channels[i] = new Channel(i + 1, this);
            }

            Write("*IDN?");
            string[] fields = ReadString().Split(',');
            _model = fields[1];
            _serialNumber = fields[2];
            _swVersion = fields[3];
        }

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

        private void Write(string str)
        {
            _mbSession.RawIO.Write(str);
            Thread.Sleep(50);
        }

        private string ReadString()
        {
            return _mbSession.RawIO.ReadString().TrimEnd('\r', '\n');
        }
    }
}
