#include <vector>       // std::vector
#include <iostream>
#include <algorithm>
#include <stdio.h>
template <class inputInterator, class T>

inputInterator upper(inputInterator first , inputInterator end ,const T& value)
{

    for(; first!=end;first++){            
        if(*first > value){
            return first;
        }
    }
    return end;
}

void testSortAndUpper()
{
    std::vector<int> v{ 10, 20, 30, 30, 20, 10, 10, 20 };
    // Appel de la fonction "upper' sur le vecteur en commençant par le premier élément 
    // et en terminant avec le dernier.
    for(int i = 0;i<8;i++){
        std::printf(" %d ", v[i]);
    }
    std::vector<int>::iterator up = upper(v.begin(), v.end(), 20);
    std::cout << "First value greater than 20  at position "
              << (up - v.begin()) << std::endl;
    // Appel de la fonction de tri ''sort''
    std::sort(v.begin(), v.end());
    for(int i = 0;i<8;i++){
        std::printf(" %d ", v[i]);
    }

    // Appel ensuite de la fonction ''upper'' sur le vecteur.
    up = upper(v.begin(), v.end(), 20);
    std::cout << "First value greater than 20  at position "
              << (up - v.begin()) << std::endl;
}
 
 
void testSortHeapAndUpper()
{
    std::vector<int> v{ 10, 20, 30, 30, 20, 10, 10, 20 };
    std::make_heap(v.begin(), v.end());
    // Appel de la fonction "upper' sur le vecteur en commençant par le premier élément 
    // et en terminant avec le dernier.
    for(int i = 0;i<8;i++){
        std::printf(" %d ", v[i]);
    }
    std::vector<int>::iterator up = upper(v.begin(), v.end(), 20);
    std::cout << "First value greater than 20  at position "
              << (up - v.begin()) << std::endl;
    // Appel de la fonction de tri ''sort_heap''
    std::sort_heap(v.begin(), v.end());
    for(int i = 0;i<8;i++){
        std::printf(" %d ", v[i]);
    }
    // Appel ensuite de la fonction ''upper'' sur le vecteur.
    up = upper(v.begin(), v.end(), 20);
    std::cout << "First value greater than 20  at position "
              << (up - v.begin()) << std::endl;
}

int main() 
{
    testSortAndUpper();
    testSortHeapAndUpper();
    return 0;
}
