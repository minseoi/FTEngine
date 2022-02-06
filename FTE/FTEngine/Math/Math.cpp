//
//  Math.cpp
//  FTE
//
//  Created by minseoi on 2022/02/06.
//

#include "Math.hpp"

int Math::IntigerClamp(int& num, int min, int max)
{
    if(num < min)
        num = min;
    else if(num > max)
        num = max;
    
    return num;
}

int Math::IntigerClamp(int num, int min, int max)
{
    if(num < min)
        return min;
    else if(num > max)
        return max;
    
    return num;
}
