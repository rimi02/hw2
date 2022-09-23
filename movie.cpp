#include "product.h"
#inlcude "movie.h"
#include "util.h"
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating) : Product(category, name, price, qty), genre_(genre), rating_(rating) {}
Movie::~Movie() {}
std::set<std::string> Movie::keywords() const {
    set<string> keywords;
    string temp = name_;
    string temp2 = genre_;
    string temp3 = rating_;
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
std::string Movie::displayString() const {
    stringstream ss;
    ss << name_ << endl << "Genre: " << genre_ << " Rating: " << rating_ << endl << price_ << " " << qty_ << " left.";
    return ss.str();
}
void Movie::dump(std::ostream& os) const {
    os << category_ << endl << name_ << endl << price_ << endl << qty_ << endl << genre_ << endl << rating_ << endl;
}