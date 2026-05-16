//字典树
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int trie[250005][2];
bool is_end[250005];
int cnt = 0;

bool insert(string s){
    int u = 0;
    bool has_new_node = false;

    for(char c : s){
        int v = c - '0';
        if(!trie[u][v]){
            trie[u][v] = ++cnt;
            has_new_node = true;
        }

        u = trie[u][v];

        if(is_end[u]) return false;
    }

    is_end[u] = true;
    if(!has_new_node) return false;

    return true;
}

int main(){
    ifstream in("in.txt");
    bool flag = true;
    while(true){
        string line;
        getline(in, line);
        if(line[0] == '9') break;

        if(!insert(line)){
            flag = false;
            break;
        }
    }

    if(flag) cout << "Y" << endl;
    else cout << "N" << endl;

    return 0;
}

