#include <vector>       // std::vector
 
template <class T>
int upper(std::vector<T> aVector, const T& theValue)
{
	for (int i = 0; i < aVector.size(); i++)
	{
		if (aVector[i] > theValue)
			return i;
	}


	return -1;
}