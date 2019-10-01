#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int n = 2;

int findValB(string &t)
{
    int sum = 0;
    int l = t.length();
    for(int i = 0; i < l; i++)
        sum = sum + (t[i] - 48)*pow(2,i);
    return sum;

}

int findValA(string &t, int l, int h)
{
    int sum = 0;
    for(int i = l, j = 0; i <= h; i++, j++)
        sum = sum + (t[i] - 48)*pow(2,j);
    return sum;

}

int main()
{
    int lengthB, lengthA, valB, valA;
    int flag;
    string A[n], B[n];
    for(int i = 0; i < n; i++)
        cin >> A[i] >> B[i];


    for(int i = 0; i < n; i++)
    {
        flag = 0;
        lengthA = A[i].length();
        lengthB = B[i].length();
        valB = findValB(B[i]);
        for(int j = 0; j <= lengthA - lengthB; j++)
        {
            if(findValA(A[i],j,(j+lengthB)) == valB)
            {
                flag = 1;
                break;
            }
        }
        cout << flag << endl;
    }
}





