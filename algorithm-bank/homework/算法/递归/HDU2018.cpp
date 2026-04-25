#include <iostream>
#include <fstream>
using namespace std;

int cow(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 3;
    return cow(n - 1) + cow(n - 3);
}

int main(){
    ifstream infile("in.txt");
    int n;
    infile >> n;
    cout << cow(n) << endl;

    return 0;
}