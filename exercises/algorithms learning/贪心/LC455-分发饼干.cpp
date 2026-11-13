#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> g, s;

    string gs, ss;
    getline(cin, gs);
    istringstream igs(gs);
    for(size_t i = 0; i < gs.size(); i++) {
        int x; igs >> x; g.push_back(x);
    }
       
    getline(cin, ss);
    istringstream iss(ss);
    for(size_t i = 0; i < gs.size(); i++) {
        int x; iss >> x; s.push_back(x); 
    }

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int ans = 0, k = 0;
    for(size_t i = 0; i < g.size(); i++) {
        for(size_t j = k; j < s.size(); ++j) {
            if(s[j] >= g[i])
                ans++; k = j;
        }
    }

    cout << ans << '\n';
    return 0;
}