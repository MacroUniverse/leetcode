#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

template<class T>
inline void hash_combine(size_t &seed, const T &v) {
    seed ^= hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct hash2 {
    template<class T, class T1>
    size_t operator()(const pair<T,T1> &a) const {
        size_t h = hash<T>{}(a.first);
        hash_combine(h, a.second);
        return h;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    unordered_map<pair<string, int>, int, hash2> umap;
    umap[pair<string,int>("abc", 123)] = 1;
    umap[pair<string,int>("bcd", 123)] = 100;
    umap[pair<string,int>("cde", 234)] = 200;
    for (auto p:umap) {
        cout << p.first.first << ", " << p.first.second << " -> " << p.second << endl;
    }
    return 0;
}
