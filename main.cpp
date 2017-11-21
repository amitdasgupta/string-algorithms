#include <iostream>
#include<string>
using namespace std;
/************brute force algorithm for string matching*//////////////
int matchBrute(string a,string b)
{
    int m=a.size()-1,n=b.size()-1,j,res;
    for(int i=0;i<=n-m;i++)
    {
        j=0;
        res=i;
        while(j<=m&&a[j]==b[i+j])
        {
             j++;
        }
        if(j==m+1)
            return i;
    }
}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<endl<<matchBrute(a,b);
    return 0;
}
