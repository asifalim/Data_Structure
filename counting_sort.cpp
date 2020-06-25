#include<bits/stdc++.h>
#define ll long long
using namespace std;
void countingsort(ll arr[],ll n,ll r)
{
    ll s[n],fre[r],i;
    memset(fre,0,sizeof(fre));
    for(i=0;i<n;i++)fre[arr[i]]++;
    for(i=1;i<r;i++)fre[i]=fre[i-1]+fre[i];
    for(i=0;i<n;i++)s[--fre[arr[i]]]=arr[i];
    for(i=0;i<n;i++)arr[i]=s[i];
}
int main()
{                              //complexity O(size+max_element)
                               //Restriction: element 0 to 10^6
    ll x,t,i,j;
    cin>>x;
    while(x--)
    {
        ll a,b,c,m=0;
        cin>>a;
        ll ss[a];
        for(i=0; i<a; i++)
        {
            cin>>ss[i];m=max(ss[i],m);
        }
        countingsort(ss,a,m+1);
        for(i=0;i<a;i++)cout<<ss[i]<<" ";
        cout<<endl;
    }
	return 0;
}
