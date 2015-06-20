#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>
#include <vector>
#include "Entity.hpp"
#include "ComponentType.hpp"

class System
{
public:
    std::bitset<16> m_lock;
public:
    virtual ~System() = 0;
    bool KeyFitsLock(std::bitset<16> key);
};

inline System::~System() {};

#endif
