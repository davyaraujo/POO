#include "counter.h"
class MyAdvCounter : public MyCounter{
    public:
        MyAdvCounter() = default;
        MyAdvCounter(int initvalue,int valMax) : MyCounter(initvalue,valMax)
        {}
        MyAdvCounter(int valMax) : MyCounter(valMax) 
        {}

        MyAdvCounter(const MyAdvCounter&) = default;

        MyAdvCounter& operator=(const MyAdvCounter&)=default;

        using MyCounter :: increment;
        void increment();
    };