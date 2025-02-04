#include "counter.h"
#include <iostream>
#include "MyBiDiCounter.hpp"
#include "ForwardCounter.hpp"
#include "BackwardCounter.hpp"
#include "MyAdvCounter.hpp"



MyCounter::~MyCounter()
{
std::cout << "Delete counter: " << this 
          << " ( " << counter << ", " << max << ")" 
          << std::endl;
}

ForwardCounter::~ForwardCounter()
{
std::cout << "Delete1"<< std::endl;
}

BackwardCounter::~BackwardCounter()
{
std::cout << "Delete2"<< std::endl;
}

MyBiDiCounter::~MyBiDiCounter()
{
std::cout << "Delete3"<< std::endl;
}

MyAdvCounter::~MyAdvCounter()
{
std::cout << "Delete4"<< std::endl;
}


unsigned  MyCounter :: getCounter() const {
    return counter;
  }

unsigned MyCounter :: getMax() const {
    return max;
  }

void ForwardCounter :: increment() {
    counter ++;
    if(counter > max)
      counter = 0;
  }
void MyCounter :: increment() {
    counter ++;
    if(counter > max)
      counter = 0;
  }

void MyCounter :: reset() {
    counter = 0;
  }

void MyCounter :: set(unsigned value){
    counter = (value <= max) ? value : counter;
  }

void MyCounter :: setMax(unsigned value) {
      if(counter >= value)
        counter = 0;
        max = value;;
  }

void MyBiDiCounter:: decrement(){
      if (counter > 0){
        counter = counter - 1;
      }
      else{
        counter = max;
      }
     
}

void MyCounter :: print() {
  std::cout << "Compteur:" << counter <<"/"<< max <<std::endl;
}

void MyBiDiCounter :: print() {
  std::cout << "Compteur(BiDi):" << counter <<"/"<< max <<std::endl;
}

void ForwardCounter :: print() {
  std::cout << "Compteur(Forward):" << counter <<"/"<< max <<std::endl;
}

void MyAdvCounter :: print() {
  std::cout << "Compteur1(Adv)" << counter <<"/"<< max <<std::endl;
}

void BackwardCounter :: backward(){
    counter = max;
    if ( max > 9)  
      for (int i = 9;i<=max;i++){
        std::cout << "Compteur(Back_maior):" << counter <<"/"<< max <<std::endl;
        counter = counter - 1;
      }
      counter = max;
    if (max < 9){
       for (int i = max;i<=9;i++){
        std::cout << "Compteur(Back_menor):" << counter <<"/"<< max <<std::endl;
        counter = counter + 1;
      }
      counter = max;
    }
}
     
void MyBiDiCounter :: increment(unsigned value) {
    if (counter + value <= max){
      counter = counter + value;
    }
    else{
      counter = (counter + value) % max;
    }
    
  }
 
void MyAdvCounter :: increment() {
    if (counter <= max){
      counter = counter + 1;
    }
    else{
      counter = max;
    }
    
  }
 

