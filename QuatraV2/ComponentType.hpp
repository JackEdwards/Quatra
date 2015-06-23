#ifndef COMPONENTTYPE_HPP
#define COMPONENTTYPE_HPP

enum ComponentType
{
    Transform    = 1 << 0,
    Texture      = 1 << 1,
    Velocity     = 1 << 2,
    Input        = 1 << 3,
    FaceCursor   = 1 << 4,
    Gun          = 1 << 5,
    Perishable   = 1 << 6,
    RigidBody    = 1 << 7,
    Health       = 1 << 8,
    ImpactDamage = 1 << 9
};

#endif
