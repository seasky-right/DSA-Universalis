#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int NULLKEY = -1;
int table[200];

void CreateHash(int k) {
    int d = k % 199;
    while(table[d] != NULLKEY) d = (d + 1) % 200;

    table[d] = k;
}

void Search(int k, ofstream& out) {
    vector<int> record;
    int d = k % 199;

    bool found = false;
    while(table[d] != NULLKEY) {
        record.push_back(table[d]);
        if(table[d] == k) {
            found = true;
            break;
        }
        d = (d + 1) % 200;
    }

    if(found) out << "True" << endl;
    else out << "False" << endl;
    
    bool isFirst = true;
    for(int num : record) {
        if(!isFirst) out << " ";
        out << num;
        isFirst = false;
    }
    out << endl;
}

int main() {
    for(int i = 0; i < 200; ++i) table[i] = NULLKEY;

    ifstream in("in.txt");
    ofstream out("out.txt");
    int k; in >> k;

    int n;
    while(in >> n) {
        CreateHash(n);
    }

    Search(k, out);
    return 0;
}