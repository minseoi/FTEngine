//
//  Vector2.hpp
//  PraticeApp
#ifndef Vector2_h
#define Vector2_h
#include <cmath>
#include <string>

struct vector2
{
    float x, y;
    
    vector2(float x=0, float y=0);
    vector2(const vector2 &v);
    
    float magnitude();
    float dot(const vector2 &v2) const;
    void Normalize();
    
    static vector2 zero();
    static vector2 one();
    static vector2 forward();
    static vector2 right();
    
    std::string ToString();
    /*operator*/
    vector2 operator - (const vector2 &v2);
    vector2 operator + (const vector2 &v2);
};

#endif /* Vector2_h */
