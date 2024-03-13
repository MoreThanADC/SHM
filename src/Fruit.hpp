#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    explicit Fruit(const std::string& name, unsigned amount, unsigned price, unsigned daysToSpoil);
    virtual ~Fruit() = default;

    bool operator==(const Cargo& other) const override;
    
    void updateOnNextDay() override;
    std::ostream& print(std::ostream& os) const override;

    unsigned getDaysToSpoil() const { return daysToSpoil_; }
    bool isRotten() const { return isRotten_; }

private:
    unsigned daysToSpoil_;
    bool isRotten_ = false;
};

#endif
