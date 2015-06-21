#ifndef FACECURSORCOMPONENT_HPP
#define FACECURSORCOMPONENT_HPP

#include "Component.hpp"

class FaceCursorComponent : public Component
{
public:
    FaceCursorComponent();
    void Init();
};

typedef std::shared_ptr<FaceCursorComponent> FaceCursorComponentPtr;

#endif
