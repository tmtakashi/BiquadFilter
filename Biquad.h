enum class FilterType
{
    LowPass = 1,
    HighPass,
    BandPass,
    Notch,
    AllPass,
    Peaking,
    LowShelf,
    HighShelf,
};

struct Parameters
{
    FilterType filterType;
    double fs;
    double f0;
    double Q;
    double dBGain;
};

class Biquad
{
private:
    FilterType mfilterType;
    
    Parameters mparams;

    // coefficients
    double ma0, ma1, ma2, mb0, mb1, mb2;

    // buffers
    double mx_z1, mx_z2, my_z1, my_z2;
    
    void calculateCoeffs();
    
public:
    Biquad(){};
    ~Biquad(){};
    void setParams(const Parameters& params);
    Parameters getParams();
    double process(double x);
};
