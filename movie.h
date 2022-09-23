#include "product.h"
#include "util.h"
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
class Movie : public Product {
public:
    Movie(const string category, const string name, double price, int qty, string genre, string rating);
    ~Movie();
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;
private:
    string genre_;
    string rating_;
};