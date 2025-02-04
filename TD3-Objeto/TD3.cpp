#include"TD3.hpp"
#include<iostream>
#include<stdlib.h>
 
namespace monomorphic
{

template<typename T>
void populate_with_randoms(std::vector<T>& theVector,
    T theNumberOfValues, T theMinValue, T theMaxValue)
{
    std::srand(time(nullptr));
    T width = theMaxValue - theMinValue;

    for (int i =0; i<theNumberOfValues;i++){
        int width = theMaxValue - theMinValue;

        int value = theMinValue + (rand() % width);

        theVector.push_back(value);
    }
   
}

template<typename T>
void print_vector(const std::vector<T>& anArray){

    int tamanho = anArray.size();

    for (int i=0; i<tamanho;i++)
    {
        printf("%d \n", anArray[i]);
    }    
}

template<typename T>
void simple_sort(std::vector<T>& theValues)
{
    for (int i = 0; i<theValues.size(); i++)
        {
            for (int j = i + 1; j< theValues.size(); j++)
            {
                // Compare si les deux elements sont dans le bon ordre.
                if (theValues[i] > theValues[j])
                {
                    // Procede a la permutation des deux elements
                    int Temp = theValues[i];
                    theValues[i] = theValues[j];
                    theValues[j] = Temp;
                }
            }
        }
    
}

}