template<typename T> struct CC {
    vector<T> coords;
    CC(): coords{} {}
    void add(T x) {
        coords.push_back(x);
    }
    void compress() {
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
    }
    int idxOf(T x) {
        return (int) (lower_bound(coords.begin(), coords.end(), x) - coords.begin()) + 1;
    }
};
