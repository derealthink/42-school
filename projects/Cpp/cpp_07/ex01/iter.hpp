
#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *arrayAddress, const int arrayLength, F func) 
{
    for (int i = 0; i < arrayLength; i++)
        func(arrayAddress[i]);
}


#endif
