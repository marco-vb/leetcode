class RandomizedSet {
    unordered_set<int> s;
public:
    RandomizedSet() {
        s = unordered_set<int>();
    }
    
    bool insert(int val) {
        return s.insert(val).second;
    }
    
    bool remove(int val) {
        if (s.find(val) == s.end()) return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = s.size();
        int r = rand() % n;

        for (int x : s) {
            if (!r) return x;
            r--;
        }

        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
