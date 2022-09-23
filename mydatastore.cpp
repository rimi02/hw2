#include "mydatastore.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>



using namespace std;

MyDataStore::MyDataStore() {
}

MyDataStore::~MyDataStore() {
    for (unsigned int i = 0; i < products.size(); i++) {
        delete products[i];
    }
    for (unsigned int i = 0; i < users.size(); i++) {
        delete users[i];
    }
}

void MyDataStore::addProduct(Product* p) {
    products.push_back(p);
    set<string> keywords = p->keywords();
    for (set<string>::iterator it = keywords.begin(); it != keywords.end(); ++it) {
        keywordMap[*it].insert(p);
    }
}

void MyDataStore::addUser(User* u) {
    users.push_back(u);
    userMap[u->getName()] = u;
}



vector<Product*> MyDataStore::search(vector<string>& terms, int type) {
    set<Product*> results;
    if (type == 0) {
        for (unsigned int i = 0; i < terms.size(); i++) {
            set<Product*> temp = keywordMap[terms[i]];
            results = setIntersection(results, temp);
        }
    }
    else if (type == 1) {
        for (unsigned int i = 0; i < terms.size(); i++) {
            set<Product*> temp = keywordMap[terms[i]];
            results = setUnion(results, temp);
        }
    }
    vector<Product*> finalResults;
    for (set<Product*>::iterator it = results.begin(); it != results.end(); ++it) {
        finalResults.push_back(*it);
    }
    return finalResults;
}

void MyDataStore::dump(ostream& ofile) {
    for (unsigned int i = 0; i < products.size(); i++) {
        ofile << products[i]->displayString() << endl;
    }
}

void MyDataStore::addCart(string username, Product* p) {
    cartMap[username].push_back(p);
}

void MyDataStore::viewCart(string username) {
    vector<Product*> cart = cartMap[username];
    for (unsigned int i = 0; i < cart.size(); i++) {
        cout << cart[i]->displayString() << endl;
    }
}

void MyDataStore::buyCart(string username) {
    vector<Product*> cart = cartMap[username];
    for (unsigned int i = 0; i < cart.size(); i++) {
        cart[i]->subtractQty(1);
    }
    cartMap[username].clear();
}

void MyDataStore::addReview(Review* r) {
    reviewMap[r->prodName].push_back(r);
}