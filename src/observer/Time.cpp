#include <iostream>

#include "Time.hpp"

Time& Time::getInstance() {
    static Time instance;
    return instance;
}

void Time::addObserver(const std::shared_ptr<TimeDependentObject>& observer) {
    observers_.push_back(observer);
}

void Time::removeObserver(const std::shared_ptr<TimeDependentObject>& observer) {
    auto it = std::find(observers_.begin(), observers_.end(), observer);
    if (it != observers_.end())
        observers_.erase(it);
}

void Time::nextDay() {
    currentDay_++;
    for (const auto& observer : observers_) {
        if (observer)
            observer->updateOnNextDay();
    }
}
