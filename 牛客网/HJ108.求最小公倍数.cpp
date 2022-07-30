#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a; cin >> b;
    if (a == b) {
        cout << a; return 0;
    }
    if (a > b) swap(a, b);
    for (int i = 1; i <= a; ++i) {
        if (i * b % a == 0) {
            cout << i * b; return 0;
        }
    }
    cout << "something wrong!" << endl;
    return 0;
}
