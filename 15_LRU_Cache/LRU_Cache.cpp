#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) return -1;
        
        l.splice(l.begin(), l, m[key]);
        cout << "Get {" << key << "," << m[key]->second << "}" << endl;
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            cout << "Put {" << key << "," << value << "}"<< endl; 
            return;
        }
        if (l.size() == size) {
            auto d_key = l.back().first;
            cout << "Delete {" << l.back().first << "," << l.back().second << "}"<< endl;
            l.pop_back();
            m.erase(d_key);


        }
        l.push_front({key,value});
        m[key] = l.begin();
        cout << "Put {" << key << "," << value << "}"<< endl; 
    }
};

int main() {
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    int res = obj->get(1);
    obj->put(3,3);
    res = obj->get(2);
    obj->put(4,4);
    res = obj->get(1);
    res = obj->get(3);
    res = obj->get(4);
}