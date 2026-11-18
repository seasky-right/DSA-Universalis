#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<string> allWords, A, B;
    for(int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        for(size_t j = 0; j < word.size(); ++j) {
            if(word[j] >= 'A' && word[j] <= 'Z')
                word[j] = word[j] - 'A' + 'a';
        }
        A.insert(word);
        allWords.insert(word);
    }
    for(int i = 0; i < m; ++i) {
        string word;
        cin >> word;
        for(size_t j = 0; j < word.size(); ++j) {
            if(word[j] >= 'A' && word[j] <= 'Z')
                word[j] = word[j] - 'A' + 'a';
        }
        B.insert(word);
        allWords.insert(word);
    }

    int total = allWords.size();
    int common = A.size() + B.size() - total;
    cout << common << endl;
    cout << total << endl;

    return 0;
}