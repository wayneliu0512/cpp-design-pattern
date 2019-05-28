#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <string>
#include <vector>
#include <algorithm>

template<typename T> class Observer;

template<typename T>
class Observable
{
    std::vector<Observer<T>*> observers_;
public:
    void Notify(T& source, const std::string& field_name) {
        for (auto observer : observers_)
            observer->FieldChanged(source, field_name);
    }

    void Subscribe(Observer<T>& observer) {
        observers_.push_back(&observer);
    }

    void UnSubscribe(Observer<T>& observer) {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), &observer),
                         observers_.end());
    }
};

#endif // OBSERVABLE_H
