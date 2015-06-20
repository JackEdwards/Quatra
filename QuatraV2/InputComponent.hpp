#ifndef INPUTCOMPONENT_HPP
#define INPUTCOMPONENT_HPP

#include <map>
#include "Component.hpp"

class InputComponent : public Component
{
public:
    ComponentType m_type;

    bool m_moveUpKeyPressed;
    bool m_moveDownKeyPressed;
    bool m_moveLeftKeyPressed;
    bool m_moveRightKeyPressed;
    bool m_fireKeyPressed;

public:
    InputComponent();
    void Init();
};

typedef std::shared_ptr<InputComponent> InputComponentPtr;

#endif
