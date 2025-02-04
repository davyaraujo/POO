#include "counter.h"
class ForwardCounter : public MyCounter{
    public:
        ForwardCounter() = default;

        ForwardCounter(int valMax) : MyCounter(valMax) {}
        ForwardCounter(int initval, int valMax) : MyCounter(initval, valMax) {}
        ForwardCounter(const ForwardCounter&) = default;
        
        ~ForwardCounter();

        ForwardCounter& operator=(const ForwardCounter&)=default;
        
        using MyCounter :: increment;
        void increment();
        void print();
};