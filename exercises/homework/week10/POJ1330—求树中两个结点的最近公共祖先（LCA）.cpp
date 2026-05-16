#include <iostream>
#include <fstream>
using namespace std;

int tree[100005] = {0};
bool visited[100005] = {false};

int main(){
    ifstream infile("in.txt");

    int n; infile >> n;
    for(int i = 0; i < n - 1; ++i){
        int p, d; infile >> p >> d;
        tree[d] = p;
    }

    int a, b; infile >> a >> b;
    int i = a, j = b;

    while(i != 0){
        visited[i] = true;
        i = tree[i];
    }

    while(j != 0){
        if(visited[j] == true) break;
        j = tree[j];
    }

    cout << j << endl;
    return 0;
}
