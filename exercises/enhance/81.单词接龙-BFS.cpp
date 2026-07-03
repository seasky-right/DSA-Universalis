#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    string beginWord, endWord;
    cin >> beginWord >> endWord;

    int n; cin >> n;

    unordered_set<string> wordSet;
    for(int i = 0; i < n; ++i) {
        string word; cin >> word;
        wordSet.insert(word);
    }

    if(wordSet.find(endWord) == wordSet.end()) {
        cout << 0 << endl;
        return 0;
    }

    queue<pair<string, int>> qu;
    qu.push({beginWord, 1});

    wordSet.erase(beginWord);

    while(!qu.empty()) {
        auto curr = qu.front();
        qu.pop();

        string word = curr.first;
        int step = curr.second;

        if(word == endWord) {
            cout << step << endl;
            return 0;
        }

        for(size_t i = 0; i < word.length(); ++i) {
            char origin = word[i];

            for(char c = 'a'; c <= 'z'; ++c) {
                if(c == origin) continue;
                word[i] = c;

                if(wordSet.count(word)) {
                    if(word == endWord) {
                        cout << step + 1 << endl;
                        return 0;
                    }

                    qu.push({word, step + 1});
                    wordSet.erase(word);
                }
            }

            word[i] = origin;
        }
    }

    cout << 0 << endl;
    return 0;
}