template <class T>
bool Entity::HasComponent()
{
    if (m_components.count(typeid(T)) > 0) {
        return true;
    }
    
    return false;
}

template <class T>
std::shared_ptr<T> Entity::GetComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "T must extend Component");
    
    if (HasComponent<T>()) {
        return std::static_pointer_cast<T>(m_components[typeid(T)]);
    }
}

template <class T>
void Entity::AddComponent()
{
    static_assert(std::is_base_of<Component, T>::value, "T must extend Component");

    std::shared_ptr<T> component = std::make_shared<T>();
    m_types |= component->m_type;
    m_components.insert(std::pair<std::type_index, ComponentPtr>(typeid(T), std::move(component)));
}

template <class T>
void Entity::RemoveComponent()
{
    if (HasComponent<T>()) {
        std::shared_ptr<T> component = GetComponent<T>();
        m_types ^= component->m_type;
        m_components.erase(typeid(T));
    }
}