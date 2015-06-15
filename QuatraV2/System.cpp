#include "System.hpp"

bool System::KeyFitsLock(long key)
{
    return (key & m_lock) == m_lock;
}