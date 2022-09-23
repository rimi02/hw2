#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include "util.h"
#include "product.h"
#include "user.h"
#include "review.h"

#include <set>
#include <map>

class MyDataStore : public DataStore {
public:
    MyDataStore();
    ~MyDataStore();
    void addProduct(Product* p);
    void addUser(User* u);
    vector<Product*> search(vector<string>& terms, int type);
    void dump(ostream& ofile);
    void addCart(string username, Product* p);
    void viewCart(string username);
    void buyCart(string username);
    void addReview(Review* r);
    
private:

    vector<Product*> products;
    vector<User*> users;
    map<string, set<Product*> > keywordMap;
    map<string, User*> userMap;
    map<string, vector<Review*> > reviewMap;
    map<string, vector<Product*> > cartMap;
};