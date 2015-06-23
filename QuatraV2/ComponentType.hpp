#ifndef COMPONENTTYPE_HPP
#define COMPONENTTYPE_HPP

enum ComponentType
{
    Sprite       = 1 << 0,
    Velocity     = 1 << 1,
    Input        = 1 << 2,
    FaceCursor   = 1 << 3,
    Gun          = 1 << 4,
    Perishable   = 1 << 5,
    RigidBody    = 1 << 6,
    Health       = 1 << 7,
    ImpactDamage = 1 << 8
};

#endif
