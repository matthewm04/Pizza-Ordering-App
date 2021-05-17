// identification comments code block
// Programmer: Matthew Mahoney
// Programmer's ID: 1720167
#include "pch.h"
#include "Pizza.h"

ostream& roundTwo(ostream& out) {
    out.setf(ios::fixed);
    out.precision(2);
    return out;
}

ostream& roundOff(ostream& out) {
    out.unsetf(ios::fixed);
    out.precision(6);
    return out;
}

PizzaProperties::PizzaProperties(const string t, const string a) {
    type = t;
    amount = a;
    if (amount == "Light" || amount == "Regular")
        price = 0;
    else
        price = 0.5;
}

void Cheese::output(ostream& out) const {
    out << type << " (" << amount << "), ";
}

ostream& operator<<(ostream& out, const Cheese* const c) {
    c->output(out);
    return out;
}

void Sauce::output(ostream& out) const {
    out << type << " Sauce (" << amount << ")";
}

ostream& operator<<(ostream& out, const Sauce* const s) {
    s->output(out);
    return out;
}

void Toppings::output(ostream& out) const {
    out << type << " (" << amount << ")";
}

ostream& operator<<(ostream& out, const Toppings* const t) {
    t->output(out);
    return out;
}