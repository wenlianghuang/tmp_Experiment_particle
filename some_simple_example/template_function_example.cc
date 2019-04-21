#include<iostream>
using namespace std;

template <class T,class U>
T getMin(T a,U b)
{
    return(a<b?a:b);
}

int main()
{
    int i = 5,l;
    long k = 10;
    l = getMin<int,long>(i,k);
    cout << l << endl;
}

