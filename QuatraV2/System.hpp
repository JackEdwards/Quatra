#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include "Entity.hpp"
#include "ComponentType.hpp"

class System
{
public:
    long _lock;
public:
    virtual ~System() {};
    virtual void VUpdate(EntityPtrList entities) = 0;
    bool KeyFitsLock(long key);
};

#endif
