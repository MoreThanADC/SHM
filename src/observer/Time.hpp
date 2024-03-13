#ifndef TIME_HPP
#define TIME_HPP

#include <vector>
#include <memory>

#include "TimeDependentObject.hpp"

class Time {
public:
    static Time& getInstance();

    void addObserver(const std::shared_ptr<TimeDependentObject>& observer);
    void removeObserver(const std::shared_ptr<TimeDependentObject>& observer);
    void nextDay();

private:
    /* Class Time using Singleton pattern - it means only one instance of class may exist */
    Time() {};
    ~Time() {};

    Time(const Time&) = delete;
    Time& operator=(const Time&) = delete;

    std::vector<std::shared_ptr<TimeDependentObject>> observers_;
    unsigned currentDay_ = 0;
};

#endif