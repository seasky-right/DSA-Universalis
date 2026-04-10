#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Seqlist{
    int data[100005];
    int size = 0;
};

void insert(Seqlist& l, int x){
    l.data[++l.size] = x;
}

void insert(Seqlist& l, int k, int x){
    for(int i = l.size; i >= k; --i){
        l.data[i] = l.data[i - 1];
    }
    l.data[k - 1] = x;
    l.size++;
}

void erase(Seqlist& l, int k){
    for(int i = l.size; i >= k; --i){
        l.data[i - 1] = l.data[i];
    }
    l.size--;
}

void find(Seqlist& l, int k){
    cout << l.data[k - 1] << endl;
}

int main(){
    string line;
    Seqlist s;
    while(getline(cin, line)){
        istringstream iss(line);
        string op;
        iss >> op;
        if(op == "INSERT"){
            int a, b;
            if(iss >> a){
                if(iss >> b){
                    insert(s, a, b);
                }else{
                    insert(s, a);
                }
            }
        }else if(op == "DELETE"){
            int k;
            iss >> k;
            erase(s, k);
        }else if(op == "FIND"){
            int k;
            iss >> k;
            find(s, k);
        }
    }

    return 0;
}


/*利用vector实现
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void insert(vector<int>& l, int x){
    l.push_back(x);
}

void insertk(vector<int>& l, int k, int x){
    l.insert(l.begin() + k - 1, x);
}

void del(vector<int>& l, int k){
    l.erase(l.begin() + k - 1);
}

int find(vector<int> l, int k){
    if(k > l.size()) return -1;
    return l[k - 1];
}

int main(){
    int m;
    cin >> m;
    vector<int> vec;
    
    string line;
    while(getline(cin, line)){
        if(line.empty()) continue;

        istringstream iss(line);
        string op;
        iss >> op;

        if(op == "INSERT"){
            int a, b;
            if(iss >> a){
                if(iss >> b){
                    insertk(vec, a, b);
                }else{
                    insert(vec, a);
                }
            }
        }else if(op == "FIND"){
            int n;
            iss >> n;
            cout << find(vec, n) << endl;
        }else if(op == "DELETE"){
            int n;
            iss >> n;
            del(vec, n);
        }
    }

    return 0;
}*/