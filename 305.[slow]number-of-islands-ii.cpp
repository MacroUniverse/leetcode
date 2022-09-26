// ======= 30%, 30% =================

template <class T, class H = std::hash<T>>
struct disjoint_sets2
{
    // private:
    int Nset; // # of sets
    // parent of a node that leads to the set leader
    unordered_map<T, T, H> parent;
    // map non-isolated leaders to total # of children
    unordered_map<T, int, H> Nchild;

    // public:
    disjoint_sets2(): Nset(0) {};

    // push a new node to new set
    // do nothing if already exist
    void push(const T &node) {
        if(parent.count(node)) return;
        parent[node] = node;
        ++Nset;
    }

    // update and return the set leader of a node
    T find(const T &node)
    {
        T &p = parent[node];
        if (p != parent[p])
            p = find(p);
        return p;
    }

    // check node existence
    bool count(const T &node) { return parent.count(node); }

    // merge two sets. x, y are elements from each set
    // x, y can be in the same group, or non existent node
    void merge(const T &node1, const T &node2)
    {
        T l1, l2;
        if (!count(node1))
            push(node1), l1 = node1;
        else
            l1 = find(node1);
        if (!count(node2))
            push(node2), l2 = node2;
        else
            l2 = find(node2);
        if (l1 == l2) return; // same set
        int N1 = set_size(l1), N2 = set_size(l2);
        if (N1 >= N2) // set 2 join set 1
            parent[l2] = l1, Nchild[l1] += N2, Nchild.erase(l2);
        else // set 1 join set 2
            parent[l1] = l2, Nchild[l2] += N1, Nchild.erase(l1);
        --Nset;
    }

    // # of sets
    int num_set() { return Nset; }

    // # of nodes in each set
    int set_size(const T &leader)
    {
        return Nchild.count(leader) ? Nchild[leader]+1 : 1;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> ret; ret.reserve(positions.size());
        disjoint_sets2<int> s;
        for (auto &e : positions) {
            int e0 = e[0], e1 = e[1];
            int pr = e0+m*e1;
            if (e0 > 0) {
                int up = (e0-1)+m*e1;
                if (s.count(up))
                    s.merge(pr, up);
            }
            if (e0 < m-1) {
                int down = (e0+1)+m*e1;
                if (s.count(down))
                    s.merge(pr, down);
            }
            if (e1 > 0) {
                int left = e0+m*(e1-1);
                if (s.count(left))
                    s.merge(pr, left);
            }
            if (e1 < n-1) {
                int right = e0+m*(e1+1);
                if (s.count(right))
                    s.merge(pr, right);
            }
            s.push(pr);
            ret.push_back(s.num_set());
        }
        return ret;
    }
};
