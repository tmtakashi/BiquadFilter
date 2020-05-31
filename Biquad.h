enum class FilterType
{
    LowPass,
    HighPass,
    BandPass,
    Notch,
    AllPass,
    Peaking,
    LowShelf,
    HighShelf,
};

class Biquad
{
private:
    FilterType mfilterType;

    // coefficients
    double ma0, ma1, ma2, mb0, mb1, mb2;
    // sampling frequency, center frequency (or corner frequency)
    double mfs, mf0;
    // for peaking and shelving filters
    double mdBGain, mQ;

    // buffers
    double mx_z1, mx_z2, my_z1, my_z2;

public:
    Biquad(FilterType filterType, double fs, double f0, double Q);
    Biquad(FilterType filterType, double fs, double f0, double Q, double dBGain);
    ~Biquad(){};
    double process(double x);
};