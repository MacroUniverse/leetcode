#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("test.txt");
    ofstream fout("out.txt");
    string full_name; int line_num;
    unordered_map<string, int> umap;
    
    while (1) {
    // for (int i = 0; i < 4; ++i) {
        fin >> full_name;
        if (fin.eof()) break;
        fin >> line_num;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        long long ind = full_name.rfind("\\");
        if (ind > 0)
            full_name = full_name.substr(ind+1);
        full_name += "?" + to_string(line_num);
        // cout << full_name << endl;
        ++umap[full_name];
    }
    // cout << "done reading" << endl;
    if (umap.size() > 8) {
        cerr << "more than 8!" << endl; exit(1);
    }
    vector<pair<int, string>> v;
    for (auto& it : umap)
        v.emplace_back(it.second, it.first);
    sort(v.begin(), v.end());

    for (int i = v.size()-1; i >= 0; --i) {s
        string &tmp = v[i].second;
        int ind = tmp.find_first_of("?");
        int start0, N0;
        if (ind > 16) {
            start0 = ind - 16; N0 = 16;
        }
        else {
            start0 = 0; N0 = ind;
        }
        // cout << tmp.substr(start0, N0) << " " << tmp.substr(ind+1) << " " <<  v[i].first << endl;
        fout << tmp.substr(start0, N0) << " " << tmp.substr(ind+1) << " " <<  v[i].first << endl;
    }
}
