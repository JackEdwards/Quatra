#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include "Entity.hpp"
#include "ComponentType.hpp"

class System
{
public:
    long m_lock;
public:
    virtual ~System() = 0;
    bool KeyFitsLock(long key);
};

inline System::~System() {};

#endif
