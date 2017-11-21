#include <iostream>
#include<string>
#include<math.h>
#define prime 101
using namespace std;
/************brute force algorithm for string matching
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
*//////////////
/**************create hash function*/////////////////////
long hashOfString(string a,int start,int last)
{
    long has=0;
    for(int i=start;i<=last;i++)
    {

        has+=long(a[i])*pow(prime,i-start);
       // cout<<has<<endl;
    }
    return has;
}
int stringMatchingRabinKarp(string a,string b)
{
    long i=0,j,p,t,m=a.size(),n=b.size();
    p=hashOfString(a,0,m-1);
    t=hashOfString(b,0,m-1);
   // cout<<p<<" "<<t;
    for(i=0;i<=n-m;i++)
    {
        cout<<p<<" "<<t<<endl;
        j=0;
        if(p==t)
        {
           while(a[j]==b[i+j])
           j++;
           if(j==m)
            return i;
        }
        else
            if(i<n-m)
        {
            t=(t-long(b[i]))/prime;
            t+=(long(b[i+m])*pow(prime,m-1));

        }
        else
            return -1;
    }
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<stringMatchingRabinKarp(a,b);
    return 0;
}
