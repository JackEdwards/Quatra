#ifndef FACECURSORCOMPONENT_HPP
#define FACECURSORCOMPONENT_HPP

#include "Component.hpp"

class FaceCursorComponent : public Component
{
public:
    FaceCursorComponent();
};

typedef std::shared_ptr<FaceCursorComponent> FaceCursorComponentPtr;

#endif
