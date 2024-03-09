#ifndef ALCOHOL_HPP
#define ALCOHOL_HPP

#include "Cargo.hpp"

class Alcohol : public Cargo {
public:
    explicit Alcohol(const std::string& name, unsigned amount, unsigned price, unsigned alcoholContent);

    unsigned getAlcoholContent() const { return alcoholContent_; }

    bool operator==(const Cargo& other) const override
    {
        const Alcohol* otherAlcohol = dynamic_cast<const Alcohol*>(&other);
        if (otherAlcohol)
        {
            return name_ == otherAlcohol->getName() && 
                alcoholContent_ == otherAlcohol->getAlcoholContent();
        }

        return false;
    }

    virtual std::ostream& print(std::ostream& os) const override;

private:
    unsigned alcoholContent_;
    static const unsigned MAX_ALCOHOL_CONTENT = 96;
};

#endif
