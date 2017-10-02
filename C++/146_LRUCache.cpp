#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
  LRUCache(int capacity):_capacity(capacity) {}

  int get(int key) {
    auto it=m.find(key);
    if(it!=m.end()){
      // 将查到的pair移到队首并返回value
      cache.splice(cache.begin(),cache,it->second);
      return it->second->second;
    }
    return -1;
  }

  void put(int key, int value) {
    auto it=m.find(key);
    if(it!=m.end()){
      it->second->second=value;
      cache.splice(cache.begin(),cache,it->second);
      return;
    }
    auto p=make_pair(key,value);
    if(cache.size()==_capacity){
      // 移除队尾元素
      auto tmp=cache.back();
      m.erase(tmp.first);
      cache.pop_back();
    }
    cache.push_front(p);
    m.insert({key,cache.begin()});
  }
private:
  typedef pair<int,int> pp;
  int _capacity;
  list<pp> cache;  // pair.first:key  pair.second:value
  map<int,list<pp>::iterator> m;
};
