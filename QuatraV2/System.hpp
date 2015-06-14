#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include "Entity.hpp"
#include "ComponentType.hpp"

class System
{
public:
    long _types;
public:
    virtual ~System() {};
    virtual void VUpdate(std::vector<Entity*> entities) = 0;
};

#endif
