#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include "util.h"
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>


class Book : public Product {
public:
    Book(const string category, const string name, double price, int qty, string isbn, string author);
    ~Book();
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;
private:
    string isbn_;
    string author_;
};