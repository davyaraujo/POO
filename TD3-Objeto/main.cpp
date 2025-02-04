#include<iostream>
#include"generic_sort.hpp"
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
 
int main()
{
    std::vector<float> array;
    generic::populate_with_randoms(array, 10.0f, 1.0f, 10.f);
    generic::print_vector(array);
    std::cout << "\n";
    generic::simple_sort(array);
    generic::print_vector(array);
    std::cout << "\n";
    generic::simple_sort<float, generic::lower_traits<float>>(array);
    generic::print_vector(array);
    return 0;
}
