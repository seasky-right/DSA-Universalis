#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Node{
    int addr;
    int value;
    int next;
}memory[100005];

int main() {
    int head, n;
    cin >> head >> n;

    for(int i = 0; i < n; ++i){
        int addr, value, next;
        cin >> addr >> value >> next;
        memory[addr] = {addr, value, next};
    }

    vector<Node> Linked;
    int current = head;
    while(current != -1){
        Linked.push_back(memory[current]);
        current = memory[current].next;
    }

    vector<Node> res;
    int i = 0, j = Linked.size() - 1;
    bool flag = false;
    while(i <= j){
        if(flag){
            res.push_back(Linked[i]);
            i++;
        }else{
            res.push_back(Linked[j]);
            j--;
        }
        flag = !flag;
    }

    for(size_t k = 0; k < res.size(); ++k){
        cout << setfill('0') << setw(5) << res[k].addr << " "
            << res[k].value << " ";
        
        if(k < res.size() - 1) cout << setfill('0') << setw(5) << res[k + 1].addr << endl;
        else cout << -1 << endl;
    }

    return 0;
}