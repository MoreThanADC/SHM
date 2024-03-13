#ifndef TIMEDEPENDENTOBJECT_HPP
#define TIMEDEPENDENTOBJECT_HPP

class TimeDependentObject
{
public:
    virtual ~TimeDependentObject() = default;
    virtual void updateOnNextDay() = 0;
};

#endif