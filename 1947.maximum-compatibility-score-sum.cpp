template <class T>
inline void operator+=(vector<vector<T>> &v, const T &s)
{
    for (auto &v1 : v)
        for (auto &e : v1)
            e += s;
}

inline void minus_equals_vs(int *v, int s, int N)
{
    for (int i = 0; i < N; ++i)
        v[i] -= s;
}

inline void operator-=(vector<int> & v, int s)
    { minus_equals_vs(v.data(), s, v.size()); }

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size(), n = students[0].size();
        // cost matrix (negative)
        vector<vector<int>> cost(m, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                int sum = 0;
                for (int k = 0; k < n; ++k)
                    sum += (students[i][k] == mentors[j][k]);
                cost[i][j] = -sum;
            }
        }
        return hungarian(cost);
    }

    inline int min_v(int & ind, const int *v, int N, int step = 1)
    {
        const int *beg = v, *end = v + N, *p = v; v+=step;
        for (; v < end; ++v) if (*p > *v) p = v;
        ind = (p - beg)/step;
        return *p;
    }

    inline int min(int & ind, const vector<int> & v) { return min_v(ind, v.data(), v.size()); }
    
    inline int min_v(const int *v, int N, int step = 1)
    {
        const int *end = v + N*step, *p = v; v+=step;
        for (; v < end; v+=step) if (*p > *v) p = v;
        return *p;
    }

    inline int min(const vector<int> & v) { return min_v(v.data(), v.size()); }

    inline int min(const vector<vector<int>> & v) {
        int s = numeric_limits<int>::max(), s1;
        for (auto &v1 : v) { s1 = min(v1); if (s1 < s) s = s1; }
        return s;
    }

    inline void veccpy(int *v, const int *v1, int n)
    {
        for (int i = 0; i < n; ++i)
            v[i] = v1[i];
    }

    template <class T1, class T2>
    inline void copy(vector<vector<T1>> &v1, const vector<vector<T2>> &v2)
    {
    #ifdef SLS_CHECK_SHAPE
        int N = v1.size();
        SLS_ASSERT(N == v2.size());
        for (int i = 0; i < N; ++i)
            SLS_ASSERT(v1[i].size() == v2[i].size());
    #endif
        int j = 0;
        for (auto &v : v1) {
            veccpy(v.data(), v2[j].data(), v.size());
            ++j;
        }
    }

    inline void hungarian_handle_negatives(vector<vector<int>>& matrix, bool allowed = true)
    {
        int minval = min(matrix);
        if (minval < 0) {
            if (!allowed) { //throw
                throw std::runtime_error("Only non-negative values allowed");
            }
            else { // add abs(minval) to every element to create one zero
                minval = abs(minval);
                matrix += minval;
            }
        }
    }

    inline void hungarian_step1(vector<vector<int>>& matrix, int& step)
    {
        // process rows
        for (auto& row: matrix) {
            auto smallest = *std::min_element(begin(row), end(row));
            if (smallest > 0) row -= smallest;
        }
        // process cols
        int sz = matrix.size(); // square matrix is granted
        for (int j = 0; j < sz; ++j) {
            int minval = std::numeric_limits<int>::max();
            for (int i = 0; i < sz; ++i)
                minval = std::min(minval, matrix[i][j]);
            if (minval > 0)
                for (int i=0; i<sz; ++i)
                    matrix[i][j] -= minval;
        }
        step = 2;
    }

    inline void copy(vector<bool> & v, bool s)
    {
        v.assign(v.size(), s);
    }

    inline void hungarian_step2(const vector<vector<int>> & matrix, vector<vector<char>> & M, vector<bool> & RowCover,
            vector<bool> & ColCover, int& step)
    {
        int sz = matrix.size();
        for (int r=0; r<sz; ++r) 
            for (int c=0; c<sz; ++c) 
                if (matrix[r][c] == 0)
                    if (RowCover[r] == 0 && ColCover[c] == 0) {
                        M[r][c] = 1; RowCover[r] = 1; ColCover[c] = 1;
                    }
        copy(RowCover, false); copy(ColCover, false);
        step = 3;
    }

    inline void hungarian_step3(const vector<vector<char>> & M, vector<bool> & ColCover, int & step)
    {
        int sz = M.size(), colcount = 0;
        for (int r=0; r<sz; ++r)
            for (int c=0; c<sz; ++c)
                if (M[r][c] == 1)
                    ColCover[c] = 1;
        for (auto n : ColCover)
            if (n == 1)
                colcount++;
        if (colcount >= sz)
            step = 7; // solution found
        else
            step = 4;
    }

    inline void hungarian_find_a_zero(int& row, int& col,
                    const vector<vector<int>> & matrix, const vector<bool> & RowCover, const vector<bool> & ColCover)
    {
        int r = 0, c = 0, sz = matrix.size();
        bool done = false;
        row = col = -1;
        while (!done) {
            c = 0;
            while (true) {
                if (matrix[r][c] == 0 && !RowCover[r] && !ColCover[c]) {
                    row = r; col = c; done = true;
                }
                c += 1;
                if (c >= sz || done)
                    break;
            }
            r += 1;
            if (r >= sz)
                done = true;
        }
    }

    inline bool hungarian_star_in_row(int row, const vector<vector<char>> & M)
    {
        bool tmp = false;
        for (int c = 0; c < size(M); c++)
            if (M[row][c] == 1)
                tmp = true;
        return tmp;
    }

    inline void hungarian_step4(const vector<vector<int>> & matrix, vector<vector<char>> & M, vector<bool> & RowCover,
            vector<bool> & ColCover, int& path_row_0, int& path_col_0, int& step)
    {
        int row = -1, col = -1, sz = M.size();
        bool done = false;
        while (!done) {
            hungarian_find_a_zero(row, col, matrix, RowCover, ColCover);
            if (row == -1){
                done = true;
                step = 6;
            }
            else {
                M[row][col] = 2;
                if (hungarian_star_in_row(row, M)) {
                    // hungarian_find_star_in_row(row, col, M);
                    col = -1;
                    for (int c = 0; c < sz; c++)
                        if (M[row][c] == 1)
                            col = c;
                    RowCover[row] = 1; ColCover[col] = 0;
                }
                else {
                    done = true; step = 5;
                    path_row_0 = row;
                    path_col_0 = col;
                }
            }
        }
    }

    // Following functions to support step 5
    inline void hungarian_find_star_in_col(int c, int& r, const vector<vector<char>> & M)
    {
        r = -1;
        for (int i = 0; i < size(M); i++)
            if (M[i][c] == 1)
                r = i;
    }

    inline void hungarian_find_prime_in_row(int r, int& c, const vector<vector<char>> & M)
    {
        for (unsigned j = 0; j < M.size(); j++)
            if (M[r][j] == 2)
                c = j;
    }

    inline void hungarian_step5(vector<vector<int>>& path, int path_row_0, int path_col_0, 
            vector<vector<char>> & M, vector<bool> & RowCover, vector<bool> & ColCover, int& step)
    {
        int r = -1, c = -1;
        int path_count = 1;
        path[path_count - 1][0] = path_row_0;
        path[path_count - 1][1] = path_col_0;
        bool done = false;
        while (!done) {
            hungarian_find_star_in_col(path[path_count - 1][1], r, M);
            if (r > -1) {
                path_count += 1;
                path[path_count - 1][0] = r;
                path[path_count - 1][1] = path[path_count - 2][1];
            }
            else {done = true;}
            
            if (!done) {
                hungarian_find_prime_in_row(path[path_count - 1][0], c, M);
                path_count += 1;
                path[path_count - 1][0] = path[path_count - 2][0];
                path[path_count - 1][1] = c;
            }
        }
        // augment_path
        for (int p = 0; p < path_count; p++)
            if (M[path[p][0]][path[p][1]] == 1)
                M[path[p][0]][path[p][1]] = 0;
            else
                M[path[p][0]][path[p][1]] = 1;
        copy(RowCover, false); copy(ColCover, false);
        // erase primes
        for (auto& row: M)
            for (auto& val: row)
                if (val == 2)
                    val = 0;
        step = 3;
    }

    inline void hungarian_step6(vector<vector<int>>& matrix, const vector<bool> & RowCover, const vector<bool> & ColCover, int& step)
    {
        int sz = matrix.size(), minval = std::numeric_limits<int>::max();
        for (int r = 0; r < sz; r++)
            for (int c = 0; c < sz; c++)
                if (RowCover[r] == 0 && ColCover[c] == 0)
                    if (minval > matrix[r][c])
                        minval = matrix[r][c];
        for (int r = 0; r < sz; r++)
            for (int c = 0; c < sz; c++) {
                if (RowCover[r] == 1)
                    matrix[r][c] += minval;
                if (ColCover[c] == 0)
                    matrix[r][c] -= minval;
        }
        step = 4;
    }

    /* Main function of the algorithm */
    // `original` is the square cost matrix
    inline int hungarian(const vector<vector<int>> & cost, bool allow_negatives = true)
    {
        const int sz = cost.size();
    #ifdef SLS_CHECK_SHAPES
        if (cost.empty() || cost[0].size() != sz)
            SLS_ERR("wrong shape!");
    #endif
        vector<vector<int>> matrix(sz, vector<int>(sz));
        copy(matrix, cost);
        hungarian_handle_negatives(matrix, allow_negatives);

        vector<vector<char>> M(sz, vector<char>(sz, 0)); // The masked matrix M
        vector<bool> RowCover(sz, 0), ColCover(sz, 0); // "cover" the cost matrix
        int path_row_0, path_col_0; // temporary to hold the smallest uncovered value
        vector<vector<int>> path(2*sz, vector<int>(2, 0)); // Array for the augmenting path algorithm
        
        bool done = false;
        int step = 1;
        while (!done) {
            switch (step) {
                case 1:
                    hungarian_step1(matrix, step); break;
                case 2:
                    hungarian_step2(matrix, M, RowCover, ColCover, step); break;
                case 3:
                    hungarian_step3(M, ColCover, step); break;
                case 4:
                    hungarian_step4(matrix, M, RowCover, ColCover, path_row_0, path_col_0, step); break;
                case 5:
                    hungarian_step5(path, path_row_0, path_col_0, M, RowCover, ColCover, step); break;
                case 6:
                    hungarian_step6(matrix, RowCover, ColCover, step); break;
                case 7:
                    for (auto &vec: M) { vec.resize(sz); }
                    M.resize(sz); done = true; break;
                default:
                    done = true; break;
            }
        }
        // total cost
        int res = 0;
        for (int j = 0; j < sz; ++j)
            for (int i = 0; i < sz; ++i)
                if (M[i][j]) {
                    auto it1 = cost.begin();
                    std::advance(it1, i);
                    auto it2 = it1->begin();
                    std::advance(it2, j);
                    res += *it2;
                    continue;                
                }
        return -res;
    }
};
