#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include "Entity.hpp"
#include "ComponentFlag.hpp"

class System
{
public:
    long _flags;
public:
    virtual ~System() {};
    virtual void VUpdate(std::vector<Entity*> entities) = 0;
};

#endif
