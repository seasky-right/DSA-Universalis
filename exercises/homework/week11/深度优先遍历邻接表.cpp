#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct EdgeNode{
    int adjvex;
    EdgeNode* next;
    EdgeNode(int v): adjvex(v), next(nullptr) {}
};

struct VNode{
    EdgeNode* firstedge;
    VNode(): firstedge(nullptr) {}
};

void DFS_Recursive(int v, vector<VNode>& adjlist,
    vector<bool>& visited, vector<int>& res){
    visited[v] = true;
    res.push_back(v);
    EdgeNode* p = adjlist[v].firstedge;
    while(p){
        if(!visited[p -> adjvex]){
            DFS_Recursive(p -> adjvex, adjlist, visited, res);
        }
        p = p -> next;
    }
}

void DFS_Iterative(int v, vector<VNode>& adjlist,
    vector<bool>& visited, vector<int>& res){
    stack<int> st;
    st.push(v);

    while(!st.empty()){
        int curr = st.top(); st.pop();

        if(!visited[curr]){
            visited[curr] = true;
            res.push_back(curr);

            vector<int> neighbors;
            EdgeNode* p = adjlist[curr].firstedge;
            while(p){
                neighbors.push_back(p -> adjvex);
                p = p -> next;
            }

            for(int i = neighbors.size() - 1; i >= 0; --i){
                if(!visited[neighbors[i]]){
                    st.push(neighbors[i]);
                }
            }
        }
    }
}

int main(){
    int n;
    if(!(cin >> n) || n <= 1) {
        cout << -1 << endl;
        return 0;
    }
    vector<VNode> adjlist(n);
    for(int i = 0; i < n; ++i){
        EdgeNode* r = nullptr;
        for(int j = 0; j < n; ++j){
            int edge = 0; if(!(cin >> edge)) {
                cout << -1 << endl;
                return 0;
            }
            if(edge == 1){
                EdgeNode* s = new EdgeNode(j); 
                if(!adjlist[i].firstedge){
                    adjlist[i].firstedge = s;
                }else{
                    r -> next = s;
                }
                r = s;
            }
        }
    }

    int startV;
    if(!(cin >> startV) || startV < 0 || startV >= n) {
        cout << -1 << endl;
        return 0;
    }

    if (adjlist[startV].firstedge == nullptr && n > 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> resIte;
    vector<bool> visited1(n, false);
    DFS_Iterative(startV, adjlist, visited1, resIte);

    for(int i = 0; i < resIte.size(); ++i){
        cout << resIte[i] << (i == resIte.size() - 1 ? "" : " ");
    }
    cout << endl;

    vector<int> resRec;
    vector<bool> visited2(n, false);
    DFS_Recursive(startV, adjlist, visited2, resRec);
    for(int i = 0; i < resRec.size(); ++i){
        cout << resRec[i] << (i == resRec.size() - 1 ? "" : " ");
    }

    cout << endl;
    return 0;
}