#ifndef generic_sortHPP
#define generic_sortHPP
#include<vector>
#include<ostream>
#include<iostream>
#include<stdio.h>
#include<iostream>


namespace generic
{

template<typename T>
struct greater_traits
{
public:
    static bool is_greater(T aValue, T anotherValue) 
    {
    
        return aValue > anotherValue;

    }
};

template<typename T>
struct lower_traits
{
public:
    static bool is_lower(T aValue, T anotherValue) 
    {
    
        return aValue < anotherValue;

    }
};



template<typename T>
void populate_with_randoms(std::vector<T>& theVector,
    int theNumberOfValues, T theMinValue, T theMaxValue)
{
    std::srand(time(nullptr));
    T width = theMaxValue - theMinValue;

    for (int i =0; i<theNumberOfValues;i++){
        int width = theMaxValue - theMinValue;

        T value = theMinValue + (rand() % (width*1000))/(T) 1000;

        theVector.push_back(value);
    }
   
}

template<typename T>
void print_vector(const std::vector<T>& anArray){

    int tamanho = anArray.size();
    std::cout << "[ ";

    for (int i=0; i<tamanho;i++)
    {
        std::cout << anArray[i] << ", ";
    }    
    std::cout << "]\n";
}

template<typename T,typename gt = lower_traits<T>>

void simple_sort(std::vector<T>& theValues,gt* = NULL)
{
    for (int i = 0; i<theValues.size(); i++)
        {
            for (int j = i + 1; j< theValues.size(); j++)
            {
    

                // Compare si les deux elements sont dans le bon ordre.
                if (gt::is_lower(theValues[i],theValues[j]))
                {
                    // Procede a la permutation des deux elements
                    T Temp = theValues[i];
                    theValues[i] = theValues[j];
                    theValues[j] = Temp;
                }
            }
        }
    
}

}

#endif


// {
//     template<typename T>
// 	void populate_with_randoms(
//         std::vector<T>& theVector,
//       	T theNumberOfValues, T theMinValue, T theMaxValue);

//     template<typename T>
//     void print_vector(const std::vector<T>& anArray);

//     template<typename T>
//     void simple_sort(std::vector<T>& theValues);
// };
 
// #endif
 
// namespace monomorphic