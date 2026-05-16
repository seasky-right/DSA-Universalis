#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int max_h1 = 0;
int max_h2 = 0;

void solution(int curr_h1, int parent_h2, string& s, int& index) {
    if(index >= s.size()) return;
    int child = 0;

    while(index < s.size() && s[index] == 'd') {
        index++;
        child++;

        int curr_h2 = parent_h2 + child;
        max_h1 = max(max_h1, curr_h1 + 1);
        max_h2 = max(max_h2, curr_h2);

        solution(curr_h1 + 1, curr_h2, s, index);

        if(index < s.size() && s[index] == 'u') {
            index++; 
        }
    }
}

#include <stack>
void solution2(string& s){
    stack<pair<int, int>> st;
    int curr_h1 = 0;
    st.push({0, 0});

    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'd'){
            curr_h1++;
            st.top().second++;
            int parent_h2 = st.top().first;
            int curr_h2 = parent_h2 + st.top().second;
            max_h1 = max(max_h1, curr_h1);
            max_h2 = max(max_h2, curr_h2);
            st.push({curr_h2, 0});
        } else if(s[i] == 'u') {
            curr_h1--;
            st.pop();
        }
    }
}

int main() {
    int t = 0;
    while(true) {
        string line;
        getline(cin, line);
        if(line[0] == '#') break;
        t++;

        max_h1 = 0, max_h2 = 0;
        int index = 0;
        solution(0, 0, line, index);
        cout << "Tree " << t << ": " << max_h1 << " => " << max_h2 << endl;
    }

    return 0;
}