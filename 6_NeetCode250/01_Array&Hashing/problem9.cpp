// Design HashSet

#include<iostream>
#include<vector>
#include<set>
using namespace std;


// =============================================

// Bad way
class MyHashSet2 {
public:
    MyHashSet2() {}

    set<int> rrr;
    void add(int key) {
        rrr.insert(key);
    }
    
    void remove(int key) {
        rrr.erase(key);
    }
    
    bool contains(int key) {
        if(rrr.find(key) != rrr.end()) {
            return true;
        } else {
            return false;
        }

    }
};

//Boolean array
class MyHashSet {
private:
   vector<int> res;
public:
    MyHashSet() : res(1000001, false) {}
    
    void add(int key) {
        res[key]=true;
    }
    
    void remove(int key) {
        res[key]=false;
    }
    
    bool contains(int key) {
        return (res[key])?true:false;
    }
};



// ==========================================

int main() {
    
    // vector<int> nums = {3,2,3};
    vector<int> nums = {2,2,1,1,1,2,2};

    MyHashSet myHashSet;
    myHashSet.add(2);
    myHashSet.add(3);
    myHashSet.contains(2);
    
    myHashSet.add(1);
    
    return 0;
}