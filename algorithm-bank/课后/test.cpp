#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("in.txt",ios::in);
    int n;
    ifs >> n;
     vector<vector<int>> v(n,vector<int>(n));
    int num;
    for (int i = 0;i <n;i++)
    {
        for (int j = 0; j<n;j++)
        {
            ifs >> num;
            v[i][j] = num;
        }
    }
    for (int i = 0; i <n;i++)
    {
        for (int j = i; j < n;j++)
        {
            swap(v[i][j],v[j][i]);
        }
    }
    for (int i = 0; i <n;i++)
    {
        reverse(v[i].begin(),v[i].end());
    }
    for (int i = 0;i <n;i++)
    {
        for (int j = 0;j <n;j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    ifs.close();
    return 0;
}