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
/**************create hash function
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
*/////////////////////
/****************rabin karp algorithm implementation
int stringMatchingRabinKarp(string a,string b)
{
    long i=0,j,p,t,m=a.size(),n=b.size();
    p=hashOfString(a,0,m-1);
    t=hashOfString(b,0,m-1);
   // cout<<p<<" "<<t;
    for(i=0;i<=n-m;i++)
    {
      //  cout<<p<<" "<<t<<endl;
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
**///////////
/*****************function to show an array*///////////
void printArray(int *arr,int n)
{
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
/**********************prefix table for kmp*//////////////
void prefixTable(int* &arr,string p)
{
    int i=1,j=0,n=p.size();
    arr=new int[n];
    arr[j]=0;
    while(i<n)
    {
        if(p[i]==p[j])
        {
            arr[i]=j+1;
            i++;
            j++;
        }
        else
            if(j>0)
        {
           j=arr[j-1];
        }
        else
        {
            arr[i]=0;
            i++;
        }
    }
    printArray(arr,n);
}
/********************kmp string matching alggorithm*//////////////////
int kmpStringMatchingAlgo(string s,string p)
{
    int *arr,sl=s.size(),pl=p.size(),i=0,j=0;
    prefixTable(arr,p);
    while(i<sl)
    {
        if(s[i]==p[j])
        {
            if(j==(pl-1))
                return i-j;
            j++;
            i++;
        }
        else
            if(j>0)
        {
            j=arr[j-1];
        }
        else
            i++;
    }
}
int main()
{
    string p,s;
    cin>>s>>p;
    cout<<kmpStringMatchingAlgo(s,p);
    return 0;
}
