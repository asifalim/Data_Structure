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
const int mxn=1e5+3,mod=1e9+7;
int ar[mxn];
struct Node
{
    int64_t prefixsum,suffixsum,maxsubarraysum,sum;
};
Node tree[mxn*4];
Node merge(Node &node,Node &left,Node &right)
{
    node.prefixsum=max(left.prefixsum,right.prefixsum+left.sum);
    node.suffixsum=max(right.suffixsum,left.suffixsum+right.sum);
    node.maxsubarraysum=max(left.suffixsum+right.prefixsum,max(left.maxsubarraysum,right.maxsubarraysum));
    node.sum=left.sum+right.sum;
}
void build(int st,int ed,int node)
{
    if(st==ed)return void(tree[node].prefixsum=tree[node].suffixsum=tree[node].maxsubarraysum=tree[node].sum=ar[st]);
    int mid=(st+ed)>>1;
    build(st,mid,node*2);
    build(mid+1,ed,node*2+1);
    merge(tree[node],tree[node*2],tree[node*2+1]);
}
void update(int st,int ed,int idx,int node)
{
     if(st>idx or ed<idx)return;
     if(st>=idx and ed<=idx)return void(tree[node].prefixsum=tree[node].suffixsum=tree[node].maxsubarraysum=tree[node].sum=ar[st]);
     int mid=(st+ed)>>1;
     update(st,mid,idx,node*2);
     update(mid+1,ed,idx,node*2+1);
     merge(tree[node],tree[node*2],tree[node*2+1]);
}
Node query(int st,int ed,int l,int r,int node)
{
    if(st>r or ed<l)
    {
        Node nullnode;
        return nullnode;
    }
    if(st>=l and ed<=r)return tree[node];
    int mid=(st+ed)>>1;
    Node left=query(st,mid,l,r,node*2);
    Node right=query(mid+1,ed,l,r,node*2+1);
    Node res=merge(tree[node],tree[node*2],tree[node*2+1]);
    return res;
}
signed main()
{
    //fast;
    w(t)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)cin>>ar[i];
        build(1,n,1);
        Node res=query(1,n,1,n,1);
        cout<<"Case "<<++cs<<":"<<endl;
        cout<<max(0LL,res.maxsubarraysum)<<endl;
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            ar[a]=b;
            update(1,n,a,1);
            Node res=query(1,n,1,n,1);
            cout<<max(0LL,res.maxsubarraysum)<<endl;
        }

    }
}
