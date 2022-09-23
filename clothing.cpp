#include "product.h"
#include "clothing.h"
#include "util.h"
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Clothing::Clothing(const string category, const string name, double price, int qty, string size, string brand) : Product(category, name, price, qty), size_(size), brand_(brand) {}
Clothing::~Clothing() {}
std::set<std::string> Clothing::keywords() const {
    set<string> keywords;
    string temp = name_;
    string temp2 = brand_;
    string temp3 = size_;
    string temp4 = category_;
    string temp5 = price_;
    string temp6 = qty_;
    string temp7 = temp + temp2 + temp3 + temp4 + temp5 + temp6;
    vector<string> temp8 = parseStringToWords(temp7);
    for (int i = 0; i < temp8.size(); i++) {
        keywords.insert(temp8[i]);
    }
    return keywords;
}
std::string Clothing::displayString() const {
    stringstream ss;
    ss << name_ << endl << "Size: " << size_ << " Brand: " << brand_ << endl << price_ << " " << qty_ << " left.";
    return ss.str();
}
void Clothing::dump(std::ostream& os) const {
    os << category_ << endl << name_ << endl << price_ << endl << qty_ << endl << size_ << endl << brand_ << endl;
}
