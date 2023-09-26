#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define dbg(a,b,c,d) cerr<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;
#define kill(a) {cout<<a<<endl;continue;}
#define KILL(a) {cout<<a<<endl;return 0;}
#define debug cerr<<"Error Found"<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define lcm(a, b) (a/__gcd(a,b))*b
#define w(t) cin>>t;while(t--)
#define pi  2 * acos(0.0)
#define ll long long int
#define endl "\n"
#define INF (1LL<<61)
int t,cs=0;
const int mxn=3e5+3,mod=1e9+7;
int id[mxn];
bool cmp(int a, int b)
{
    if(!id[a] and !id[b])return (a < b);
    if(!id[a])return false;
    if(!id[b])return true;
    return (id[a] < id[b]);
}
int main()
{
    int n;
    cin >> n;              // sort second array based on first array
    for(int i = 1, a; i <= n; i++)cin >> a, id[a] = i;
    cin >> n; int ar[n + 1];
    for(int i = 1; i <= n; i++)cin >> ar[i];
    sort(ar + 1, ar + n + 1, cmp);
    for(int i = 1; i <= n; i++)cout << ar[i] <<" ";cout << endl;
}

