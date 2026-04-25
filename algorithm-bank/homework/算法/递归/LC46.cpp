#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> path;
vector<bool> used;

void backtrack(){
    if(path.size() == nums.size()){
        for(size_t i = 0; i < path.size(); ++i){
            cout << (i != 0 ? " " : "") << path[i];
        }
        cout << endl;
        return;
    }

    for(size_t i = 0; i < nums.size(); ++i){
        if(!used[i]){
            path.push_back(nums[i]);
            used[i] = true;

            backtrack();

            path.pop_back();
            used[i] = false;
        }
    }
}

int main(){
    ifstream infile("in.txt");
    int n;
    while(infile >> n){
        nums.push_back(n);
    }

    used.assign(nums.size(), false);

    backtrack();

    cout << endl;
    return 0;
}