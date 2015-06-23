#ifndef TRANSFORMCOMPONENT_HPP
#define TRANSFORMCOMPONENT_HPP

#include "Component.hpp"

class TransformComponent : public Component
{
public:
    sf::Vector2f m_position;
    float m_rotation;
    sf::Vector2f m_scale;
    sf::Vector2f m_origin;

public:
    TransformComponent();
    void Init(sf::Vector2f position);
};

typedef std::shared_ptr<TransformComponent> TransformComponentPtr;

#endif
