 /*
 * LeetCode 380. Insert Delete GetRandom O(1)
 * Language: C++
 * Time Complexity: O(1) average
 * Space Complexity: O(n)
 * 
 * Approach:
 *   Use a vector to store values for O(1) random access. 
 *   Maintain a hash map value->index for O(1) insert and remove. 
 *   To remove, swap with the last element and pop_back. 
 *   getRandom picks a random index from the vector.
 */
#include<vector>
#include <random>
#include <unordered_map>
using namespace std;

 class RandomizedSet {
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        else {
            data.push_back(val);
            mp[val]=data.size()-1;
            return true;
        }
        
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        else{
            auto it = mp.find(val);
            data[it->second] = data.back();
            data.pop_back();
            mp[data[it->second]] = it->second;
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return data[rand()%data.size()];
    }
private:
    vector<int> data;
    unordered_map<int,int> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */