#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e9
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
#define case(k) cout<<"Case "<<++kk<<": ";
int t,kk=0,ans=0,tot=0;                      //problem link---> https://vjudge.net/problem/UVA-12347
bool fr=true;
const int mxN=1e5+4,mod=1e9+7;
int ar[mxN];
void dfs(int left,int right)
{
    if(left>right)return;
    int m=right+1;
    for(int i=left+1; i<=right; i++)
        if(ar[i]>ar[left])
        {
            m=i;
            break;
        }
    dfs(left+1,m-1);   //for left subtree
    dfs(m,right);      //for right subtree
    cout<<ar[left]<<endl;
}
signed main()
{
    // fast;
    //w(t)
    //{
    int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1=INT_MIN,mn1=INT_MIN;
    //string s,ss,sr,sss;
    bool f=false,ff=false;
    while(cin>>a and a)ar[tot++]=a;
    dfs(0,tot-1);
    tot=0;
    //}
    return 0;
}
