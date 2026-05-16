#include <iostream>
#include <fstream>
using namespace std;

int nums[1000005] = { 0 };

void converse(int num, int i, int& index){
    if(num == 0) return;
    nums[index] = num % i;
    index++;
    converse(num / i, i, index);
}

int main(){
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    int num, i;
    infile >> num >> i;
    int index = 0;

    converse(num, i, index);

    bool isFirst = true;
    while(index > 0){
        if(!isFirst) outfile << " ";
        outfile << nums[--index];
        isFirst = false;
    }

    outfile << endl;
    return 0;
}
