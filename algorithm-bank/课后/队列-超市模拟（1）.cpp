#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int n; cin >> n;
    cin.ignore();
    vector<queue<string>> shop(n + 1);
    for(int i = 1; i <= n; ++i){
        string line, name;
        getline(cin, line);
        istringstream iss(line);
        while(iss >> name){
            shop[i].push(name);
        }
    }

    cout << "DEPARTS" << endl;

    string op;
    while(cin >> op){
        if(op == "ENTERS"){
            string name;
            int i;
            cin >> name >> i;
            if(!(i > 0 && i <= n)) continue;
            shop[i].push(name);
        }
        else if(op == "LEAVES"){
            int i; cin >> i;
            if(!(i > 0 && i <= n)) continue;
            if(shop[i].empty()) continue;
            cout << shop[i].front() << endl;
            shop[i].pop();
        }
    }

    cout << endl;
    cout << "FINAL CONTENTS" << endl;

    for(int i = 1; i <= n; ++i){
        bool isFirst = true;
        cout << "queue " << i << ": ";
        while(!shop[i].empty()){
            if(!isFirst) cout << " ";
            cout << shop[i].front();
            shop[i].pop();
            isFirst = false;
        }
        cout << endl;
    }

    return 0;
}