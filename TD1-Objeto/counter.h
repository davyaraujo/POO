#ifndef CounterHPP
#define CounterHPP

struct MyCounter
{
    explicit MyCounter(int valMax): counter(), max(valMax)
    {}
    explicit MyCounter(int initvalue, int valMax): counter(initvalue), max(valMax) 
    {}

    MyCounter(): counter(0), max(0)
    {}

    MyCounter(const MyCounter& other):
        counter(other.counter),
        max(other.max)
    {}

    ~MyCounter();
    
    unsigned counter;
    unsigned max;

    unsigned getCounter() const;
    unsigned getMax() const;

    void print();
    void increment();
    void reset();
    void set(unsigned value);
    void setMax(unsigned value);
};

#endif
