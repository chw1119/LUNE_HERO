#include "Class.h"

Class::Class()
{
    std::cout << "overrided";

}

Class::~Class()
{
    std::cout << GetClassId() << " deleted";
}

int Class::GetClassId() const
{
    return this->_id;
}

std::string Class::ToString()
{
    return "[OBJECT CLASS : CLASS]";
}
