#include <string>

class Ship
{
public:
    explicit Ship(unsigned id, std::string name, unsigned speed, unsigned maxCrew, unsigned capacity)
    : id_(id)
    , name_(name)
    , speed_(speed)
    , maxCrew_(maxCrew)
    , capacity_(capacity)
{
};

void changeName(const std::string& newName)  { name_ = newName; }
void hireSailors(const unsigned crewToAdd);
void releaseSailors(const unsigned crewToFire);

std::string getName() { return name_; }
unsigned getActualCrew() { return actualCrew_; }

private:
    const unsigned id_;
    std::string name_;
    unsigned speed_;
    const unsigned maxCrew_;
    unsigned capacity_;
    unsigned actualCrew_ = 0;
};