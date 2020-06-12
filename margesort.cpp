#include<bits/stdc++.h>
using namespace std;
#define ll long long
void marge(int arr[],int l,int mid,int r)
{
    int p=l,q=mid+1,j=0;
    int temp[r-l+1];
    for(int i=l; i<=r; i++)
    {
        if(p>mid)                    //if p out of bound then just copy second half
            temp[j++]=arr[q++];
        else if(q>r)                 //if q out of bound then just copy first half
            temp[j++]=arr[p++];
        else if(arr[p]<=arr[q])
            temp[j++]=arr[p++];
        else
            temp[j++]=arr[q++];
    }
    for(int i=0; i<j; i++)           //copy temp array to original array
        arr[l++]=temp[i];
}
void margesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        margesort(arr,l,mid);
        margesort(arr,mid+1,r);
        marge(arr,l,mid,r);
    }
}
int main()
{
    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int s[n];
        for(i=0; i<n; i++)cin>>s[i];
        margesort(s,0,n-1);
        for(i=0; i<n; i++)cout<<s[i]<<" ";
        cout<<endl;
    }
    return 0;
}
