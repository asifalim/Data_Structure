#include<bits/stdc++.h>
using namespace std;
int partition(int ss[],int s,int e)
{
    int pivot=ss[e],pidx=s,i;
    for(i=s; i<e; i++)
    {
        if(ss[i]<pivot)
        {
            int temp=ss[i];
            ss[i]=ss[pidx];
            ss[pidx]=temp;
            pidx++;
        }
    }
    int temp=ss[e];
    ss[e]=ss[pidx];
    ss[pidx]=temp;
    return pidx;
}
void quicksort(int ss[],int s,int e)
{
    if(s<e)
    {
        int p=partition(ss,s,e);
        quicksort(ss,s,(p-1));
        quicksort(ss,(p+1),e);
    }
}
int main()
{
    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(i=0; i<n; i++)cin>>arr[i];
        quicksort(arr,0,n-1);
        for(i=0; i<n; i++)cout<<arr[i]<<" ";
        cout<<endl;
    }
}
