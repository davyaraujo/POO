#include <iostream>
#include "counter.h"
#include "MyBiDiCounter.hpp"
#include "ForwardCounter.hpp"
#include "BackwardCounter.hpp"
#include "MyAdvCounter.hpp"


void UseObjectA(){

    ForwardCounter Counter1(4);
    ForwardCounter Counter2(2);
    
    

    for(unsigned i=0;i<=5;i++){
        std::cout
            << "Valeur des compteurs ("
            << Counter1.counter
            << ", " << Counter2.counter
            << ")" << std::endl;
        Counter1.increment();
        Counter2.increment();
    }
}



void myfunctionA()
{
  MyCounter counter(1);
  std::cout << counter.getCounter() << std::endl;
  std::cout << counter.getMax() << std::endl;
}

void myfunctionB() 
{
  MyCounter* counter = new MyCounter(3);
  std::cout << counter->getCounter() << std::endl;
  std::cout << counter->getMax() << std::endl;
  delete counter;
}

void testMyBiDiCounter()
{
    MyCounter counterB(4);
    ForwardCounter fowardA(4);
    MyBiDiCounter counterA(4);
    BackwardCounter counterc(4);
    // forwardA.setMax(4);
    counterB.reset();
    counterA.print();
    for(int i=0; i <= counterB.getMax(); i++)
    {
        fowardA.increment();
        fowardA.print();
    }
    counterc.backward();
    
    for(int i=0; i <= counterB.getMax(); i++)
    {
        counterA.decrement();
        counterA.print();
    }
}
void testOldIncMethod() {
    MyBiDiCounter bidiCounter1(0, 5);
    for(unsigned i = 0; i <= 5; i++) 
    {
        bidiCounter1.increment(3);
        bidiCounter1.print();
    }
}

void testMyAdvCounter()
{
    MyAdvCounter incCounter(0, 4);
    for(int i=0; i < 6; i++)
    {
	incCounter.increment();
    incCounter.print();
    }
}



void testFamilyOfCounters()
{
    ForwardCounter incCounter(0, 4);
    BackwardCounter decCounter(0, 15);
    MyBiDiCounter biDiCounter(0, 5);
    for(int i=0; i < 6; i++)
    {
        incCounter.increment();
        incCounter.print();

    }
    decCounter.backward();
}







int main(){
  //UseObjectA();
  //myfunctionA();
  //myfunctionB();
  //testMyBiDiCounter();
  //testOldIncMethod();
  //testMyAdvCounter();
  testFamilyOfCounters();
  return 0;   
}


    