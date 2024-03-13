#ifndef ALCOHOL_HPP
#define ALCOHOL_HPP

#include "Cargo.hpp"

class Alcohol : public Cargo {
public:
    explicit Alcohol(const std::string& name, unsigned amount, unsigned price, unsigned alcoholContent);
    virtual ~Alcohol() = default;

    void updateOnNextDay() override;
    unsigned getAlcoholContent() const { return alcoholContent_; }

    std::ostream& print(std::ostream& os) const override;

    bool operator==(const Cargo& other) const override;

private:
    unsigned alcoholContent_;
    static const unsigned MAX_ALCOHOL_CONTENT = 96u;
};

#endif
