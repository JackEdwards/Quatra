#include "System.hpp"

bool System::KeyFitsLock(std::bitset<16> key)
{
    return (key & m_lock) == m_lock;
}