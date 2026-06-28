#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const int MAXV = 105;
struct MGraph {
    int numberVertices, numEdges;
    char VerticesList[MAXV];
    int edge[MAXV][MAXV] = {0};
};
MGraph mg;

int findChar(char c, int n) {
    for(int i = 0; i < n; ++i) {
        if(mg.VerticesList[i] == c)
            return i;
    }
    return -1;
}

void CreateMGraph() {
    string line1;
    getline(cin, line1);
    istringstream iss1(line1);

    char v; int n = 0;
    while(iss1 >> v) {
        if(v == '{' || v == '}' || v == ',') continue;
        mg.VerticesList[n] = v;
        n++;
    }
    mg.numberVertices = n;

    string line2;
    getline(cin, line2);
    istringstream iss2(line2);

    char e; int m = 0;
    while(iss2 >> e) {
        if(e == '(') {
            char u, comma, next_v, close;
            if(iss2 >> u >> comma >> next_v >> close) {
                int a = findChar(u, n);
                int b = findChar(next_v, n);
                if(a != -1 && b != -1) {
                    mg.edge[a][b] = 1;
                    m++;
                }
            }
        }
    }
    mg.numEdges = m;
}

vector<char> list;
int printVertices(MGraph G) {
    int k = 0;
    int n = G.numberVertices;
    for(int i = 0; i < n; ++i) {
        int in = 0;
        for(int p = 0; p < n; ++p)
            if(G.edge[p][i] == 1) in++;

        int out = 0;
        for(int p = 0; p < n; ++p)
            if(G.edge[i][p] == 1) out++;

        if(out > in) {
            k++;
            list.push_back(G.VerticesList[i]);
        }
    }
    return k;
}

int main() {
    CreateMGraph();

    int k = printVertices(mg);

    cout << "K vertices: ";
    bool first = true;
    for(size_t i = 0; i < list.size(); ++i) {
        if(!first) cout << " ";
        cout << list[i];
        first = false;
    }
    cout << endl;

    cout << "Number of K vertices: " << k << endl;
    return 0;
}