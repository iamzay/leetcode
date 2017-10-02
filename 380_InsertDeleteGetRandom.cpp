#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet():size(0) {  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if(m.find(val)!=m.end())
      return false;
    nums.push_back(val);
    m[val]=size++;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if(m.find(val)==m.end())
      return false;
    int index=m[val],back=nums.back();
    auto begin=nums.begin();
    iter_swap(begin+index,begin+size-1);
    nums.pop_back();
    --size;
    m[back]=index;
    m.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return nums[rand()%size];
  }

private:
  vector<int> nums;
  unordered_map<int,int> m;
  int size;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
