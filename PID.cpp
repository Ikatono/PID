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
    PID(float P, float I, float D)
    {
        this.P = P;
        this.I = I;
        this.D = D;
    }
    float update(float err, long t)
    {
        if (first)
        {
            last_t = t;
            last_err = err;
            first = false;
            return err * P;
        }
        else
        {
            integral += (err + last_err) * (t - last_t);
            float der = (err - last_err) / (t - last_t);
            last_t = t;
            last_err = err;
            return P*err + I*integral + D*der;
        }
    }
    void clear()
    {
        first = false;
        integral = 0;
        last_t = 0;
        last_err = 0;
    }
}