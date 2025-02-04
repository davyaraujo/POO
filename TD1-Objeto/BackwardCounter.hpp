#include "counter.h"
class BackwardCounter : public MyCounter{
    public:
        BackwardCounter() = default;
        BackwardCounter(int valMax) : MyCounter(valMax) {}
        BackwardCounter(int initval, int valMax) : MyCounter(initval, valMax) {}

        BackwardCounter(const BackwardCounter&) = default;
        ~BackwardCounter();

        BackwardCounter& operator=(const BackwardCounter&)=default;

        void backward();
};