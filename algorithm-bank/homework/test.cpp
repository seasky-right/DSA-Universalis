#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, pair<string, double>> m;
    m.insert({1, {"张三", 90.0}});

    cout << m[1].first << " " << m[1].second << endl;
}
