#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> v(N), steps(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    steps.back() = 1;
    int steps_max_global = 0;
    for (int i = N-2; i >= 0; --i) {
        int vi = v[i], j;
        int ind_max, steps_max = 0;
        for (j = i+1; j < N; ++j) {
            if (v[j] > vi) {
                if (steps[j] > steps_max) {
                    ind_max = j; steps_max = steps[j];
                }
            }
        }
        steps[i] = steps_max + 1;
        steps_max_global = max(steps_max_global, steps[i]);
    }
    cout << steps_max_global;
    return 0;
}
