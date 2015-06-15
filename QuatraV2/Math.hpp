#ifndef MATH_HPP
#define MATH_HPP

#include <math.h>
#include <SFML/Graphics.hpp>

inline float DegreesToRadians(float degrees)
{
    return (degrees * M_PI) / 180.0;
}

inline float RadiansToDegrees(float radians)
{
    return radians * (180.0 / M_PI);
}

inline sf::Vector2f RadiansToVector2f(float radians)
{
    return sf::Vector2f(cos(radians), sin(radians));
}

inline sf::Vector2f DegreesToVector2f(float degrees)
{
    return RadiansToVector2f(DegreesToRadians(degrees));
}

inline float Vector2fToRadians(sf::Vector2f vector2)
{
    return atan2f(vector2.y, vector2.x);
}

inline float Vector2fToDegrees(sf::Vector2f vector2)
{
    return RadiansToDegrees(atan2f(vector2.y, vector2.x));
}

#endif
