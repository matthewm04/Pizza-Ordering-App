#ifndef Pizza_h
#define Pizza_h

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream& roundTwo(ostream&);
ostream& roundOff(ostream&);

struct PizzaProperties {
protected:
    string type;
    string amount;
    double price;
public:
    PizzaProperties(const string, const string);
};

class Cheese : public PizzaProperties{
public:
    Cheese(const string t, const string a) : PizzaProperties(t, a) {}
    double getPrice() { return price; }
    void output(ostream&) const;
};
ostream& operator<<(ostream&, const Cheese* const);

class Sauce : public PizzaProperties{
public:
    Sauce(const string t, const string a) : PizzaProperties(t, a) {}
    double getPrice() { return price; }
    void output(ostream&) const;
};
ostream& operator<<(ostream&, const Sauce* const);

class Toppings : public PizzaProperties {
public:
    Toppings(const string t, const string a) : PizzaProperties(t, a) {}
    double getPrice() { return price; }
    string getType() { return type; }
    void output(ostream&) const;
};
ostream& operator<<(ostream&, const Toppings* const);

#endif
