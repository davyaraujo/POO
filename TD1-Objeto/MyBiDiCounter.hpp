#include "counter.h"
class MyBiDiCounter: public MyCounter{
    private:

    public: 
        MyBiDiCounter() = default;

        MyBiDiCounter(int initval, int valMax) : MyCounter(initval, valMax) {}
        MyBiDiCounter(int valMax) : MyCounter(valMax) {}
        
        MyBiDiCounter(const MyBiDiCounter&) = default;
        ~MyBiDiCounter();

        MyBiDiCounter& operator=(const MyBiDiCounter&)=default;
        using MyCounter :: increment;
        void increment(unsigned value);
        void decrement();
        void print();
};

