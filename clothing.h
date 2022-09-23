#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"
#include "util.h"
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

class Clothing : public Product {
public:
    Clothing(const string category, const string name, double price, int qty, string size, string brand);
    ~Clothing();
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;
private:
    string size_;
    string brand_;
};
