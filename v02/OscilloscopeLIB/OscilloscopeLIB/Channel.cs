namespace OscilloscopeLIB
{
    public class Channel
    {
        uint _channelID;
        Oscilloscope _oscilloscope;

        public Channel(uint channelID, Oscilloscope oscilloscope)
        {
            _channelID = channelID;
            _oscilloscope = oscilloscope;
        }
    }
}
