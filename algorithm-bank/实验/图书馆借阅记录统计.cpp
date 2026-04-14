#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct student{
    int id;
    string name;
    string school;
}stu[1000];

struct book{
    int id;
    string name;
    string publisher;
}boo[1000];

struct borrow{
    student stu;
    book boo;
    string date;
}bor[1000];

student findStudentIndex(int id, int n){
    for(int i = 0; i < n; ++i){
        if(stu[i].id == id) return stu[i];
    }
    return {-1, "", ""};
}

book findBookIndex(int id, int n){
    for(int i = 0; i < n; ++i){
        if(boo[i].id == id) return boo[i];
    }
    return {-1, "", ""};
}

bool SortRule(const borrow &a, const borrow &b){
    if(a.stu.school != b.stu.school) return a.stu.school < b.stu.school;
    if(a.stu.id != b.stu.id) return a.stu.id < b.stu.id;
    return a.date < b.date;
}

int main(){
    int n, m, k;
    cin >> n; cin.ignore();
    for(int i = 0; i < n; ++i){
        string line;
        getline(cin, line);
        stringstream iss(line);
        iss >> stu[i].id >> stu[i].name >> stu[i].school;
    }

    cin >> m; cin.ignore();
    for(int i = 0; i < m; ++i){
        string line;
        getline(cin, line);
        stringstream iss(line);
        iss >> boo[i].id >> boo[i].name >> boo[i].publisher;
    }

    cin >> k; cin.ignore();
    for(int i = 0; i < k; ++i){
        string line;
        getline(cin, line);
        stringstream iss(line);
        iss >> bor[i].stu.id >> bor[i].boo.id >> bor[i].date;

        bor[i].stu = findStudentIndex(bor[i].stu.id, n);
        bor[i].boo = findBookIndex(bor[i].boo.id, m);
    }

    sort(bor, bor + k, SortRule);

    string currSchool = "", currStudent = "";
    for(int i = 0; i < k; ++i){
        if(bor[i].stu.school != currSchool){
            currSchool = bor[i].stu.school;
            cout << "学院:" << currSchool << endl;
        }
        if(bor[i].stu.name != currStudent){
            cout << bor[i].stu.id 
            << "\t" << bor[i].stu.name;
            currStudent = bor[i].stu.name;
        }else cout << "\t";
        cout << "\t" << bor[i].boo.name  
        << "\t" << bor[i].boo.publisher 
        << "\t" << bor[i].date << endl;
    }
    return 0;
}