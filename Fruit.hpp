#ifndef FRUIT_HPP
#define FRUIT_HPP

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    explicit Fruit(const std::string& name, unsigned amount, unsigned price, unsigned daysToSpoil);

    bool operator==(const Fruit& rhs) const 
    {
        return name_ == rhs.getName() && 
            daysToSpoil_ == rhs.getDaysToSpoil();
    }

    bool operator==(const Cargo& other) const override
    {
        const Fruit* otherFruit = dynamic_cast<const Fruit*>(&other);
        if (otherFruit)
        {
            return name_ == otherFruit->getName() && 
                daysToSpoil_ == otherFruit->getDaysToSpoil();
        }

        return false;
    }
    
    std::ostream& print(std::ostream& os) const override;

    unsigned getDaysToSpoil() const { return daysToSpoil_; }

private:
    unsigned daysToSpoil_;
};

#endif
