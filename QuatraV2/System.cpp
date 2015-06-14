#include "System.hpp"

bool System::KeyFitsLock(long key)
{
    return (key & _lock) == _lock;
}