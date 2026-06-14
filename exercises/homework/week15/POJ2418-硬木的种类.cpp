#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>  
using namespace std;

int main() {
    ifstream fin("in.txt");
    map<string, int> trees;
    string s;
    int total_trees = 0;

    while(getline(fin, s)) {
        if(s.empty()) continue;
        trees[s]++;
        total_trees++;
    }

    if(total_trees == 0) return 0;

    for(const auto& pair : trees) {
        double percentage = (double)pair.second / total_trees * 100;
        cout << pair.first << " " 
            << fixed << setprecision(4) << percentage << endl;
    }

    return 0;
}