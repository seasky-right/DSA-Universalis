#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    int capacity, m;
    cin >> capacity >> m;

    unordered_map<int, int> value; // key -> value
    unordered_map<int, int> freq;  // key -> frequency
    unordered_map<int, int> tim;   // key -> last used time

    // ((freq, time), key)
    set<pair<pair<int, int>, int> > st;

    int timer = 0;

    while (m--) {
        string op;
        cin >> op;

        if (op == "GET") {
            int key;
            cin >> key;

            if (value.find(key) == value.end()) {
                cout << -1 << endl;
            } else {
                // 删除旧状态
                st.erase({{freq[key], tim[key]}, key});

                // 更新使用次数和时间
                freq[key]++;
                tim[key] = ++timer;

                // 插入新状态
                st.insert({{freq[key], tim[key]}, key});

                cout << value[key] << endl;
            }
        } else if (op == "PUT") {
            int key, val;
            cin >> key >> val;

            if (value.find(key) != value.end()) {
                // key 已存在：更新 value，并且访问次数 +1
                st.erase({{freq[key], tim[key]}, key});

                value[key] = val;
                freq[key]++;
                tim[key] = ++timer;

                st.insert({{freq[key], tim[key]}, key});
            } else {
                // key 不存在：如果满了，先淘汰
                if ((int)value.size() == capacity) {
                    int oldKey = st.begin()->second;

                    st.erase(st.begin());
                    value.erase(oldKey);
                    freq.erase(oldKey);
                    tim.erase(oldKey);
                }

                // 插入新 key，初始访问次数为 1
                value[key] = val;
                freq[key] = 1;
                tim[key] = ++timer;

                st.insert({{freq[key], tim[key]}, key});
            }
        }
    }

    return 0;
}