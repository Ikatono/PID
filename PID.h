class PID
{
    protected:
    float P;
    float I;
    float D;
    long last_t = 0;
    float last_err = 0;
    float integral = 0;
    bool first = true;
    
    public:
    PID(float, float, float)
    float update(float, long)
    void clear()
}