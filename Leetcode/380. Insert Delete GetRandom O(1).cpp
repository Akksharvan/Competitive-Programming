static bool     _foo = ios::sync_with_stdio(0);
static ostream* _bar = cin.tie(0);

class RandomizedSet {
public:
    unordered_set<int> elements;

    RandomizedSet() { }
    
    bool insert (int val) {
        if (elements.count(val)) return 0;
        elements.insert(val); return 1;
    }
    
    bool remove (int val) {
        if (!elements.count(val)) return 0;
        elements.erase(val); return 1;
    }
    
    int getRandom() {
        unordered_set<int>::iterator it = begin(elements);
        advance(it, rand() % size(elements)); return *it;
    }
};