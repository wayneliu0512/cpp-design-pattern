#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

template<typename T>
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void FieldChanged(T& source, const std::string& field_name) = 0;
};

#endif // OBSERVER_H
