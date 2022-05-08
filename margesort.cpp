#include<bits/stdc++.h>
using namespace std;
#define ll long long
void marge(int ar[],int l,int mid,int r)
{
    int temp[r-l+1],j=0;
    int leftst=l,lefted=mid,rightst=mid+1,righted=r;
    while(leftst<=lefted and rightst<=righted)
    {
        if(ar[leftst]<=ar[rightst])temp[j++]=ar[leftst++];
        else temp[j++]=ar[rightst++];
    }
    while(leftst<=lefted)temp[j++]=ar[leftst++];
    while(rightst<=righted)temp[j++]=ar[rightst++];
    for(int i=0;i<j;i++)ar[l++]=temp[i];
}
void margesort(int ar[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        margesort(ar,l,mid);
        margesort(ar,mid+1,r);
        marge(ar,l,mid,r);
    }
}
int main()
{
    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ar[n];
        for(i=0; i<n; i++)cin>>ar[i];
        margesort(ar,0,n-1);
        for(i=0; i<n; i++)cout<<ar[i]<<" ";
        cout<<endl;
    }
    return 0;
}
