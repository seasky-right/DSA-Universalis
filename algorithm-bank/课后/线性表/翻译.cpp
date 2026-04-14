#include <iostream>

using namespace std;

struct Node{
    int word;
    Node* next;
};

int main(){
    int m, n;
    cin >> m >> n;

    Node* head = new Node, *r = head;
    head -> next = nullptr;
    int count = 0, memory = 0;

    for(int i = 0; i < n; ++i){
        int w;
        cin >> w;

        Node* p = head -> next;
        bool found = false;
        while(p != nullptr){
            if(w == p -> word){
                found = true;
                break;
            }
            p = p -> next;
        }

        if(!found){
            count++;
            Node* s = new Node;
            s -> word = w;
            s -> next = nullptr;
            if(memory < m){
                r -> next = s;
                r = s;
                memory++;
            }else{
                Node* temp = head -> next;
                head -> next = head -> next -> next;
                delete temp;

                if(head -> next == nullptr){
                    r = head;
                }

                r -> next = s;
                r = s;
            }
        }
    }

    cout << count << endl;
    return 0;
}