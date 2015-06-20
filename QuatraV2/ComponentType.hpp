#ifndef COMPONENTTYPE_HPP
#define COMPONENTTYPE_HPP

enum ComponentType
{
    Velocity   = 1 << 0,
    Sprite     = 1 << 1,
    Input      = 1 << 2,
    FaceCursor = 1 << 3,
    Gun        = 1 << 4,
    Perishable = 1 << 5,
    Solid      = 1 << 6
};

#endif
