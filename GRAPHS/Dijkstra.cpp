/**
  * @author Aws123
 **/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll eps=1e-9;
#define int ll
#define f first
#define s second
#define read(v,n) for(ll i=0;i<n;i++){cin>>v[i];}
#define aff(v) for(auto e:v) {cout<<e;cout<<endl;}
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
ll fact(ll x){return(x<2?1:x*fact(x-1));}
ll power(ll a,ll k){ll ans=1;while(k){if(k&1)ans=(ans*a)%MOD;a=(a*a)%MOD;k>>=1;}return ans;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

//print the shortest path between the vertex 1 and the vertex n
const ll INF = 1e18;
const int N = 1e5 + 5;
ll dist[N];
int par[N];
bool vis[N];
vector<pair<int, int>> adj[N];
int n, m;

void init()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        vis[i] = false;
        adj[i].clear();
    }
}

void dijkstra()
{
    set< pair<long , long >> pq;
    pq.insert({0, 1});
    while (!pq.empty())
    {
        int a = pq.begin()->second;
        pq.erase(pq.begin());
        if (vis[a]) continue;
        vis[a] = true;
        for (auto e : adj[a])
        {
            ll c = e.first;
            int b = e.second;
            if (dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
                par[b] = a;
                pq.insert({dist[b], b});
            }
        }
    }
}

void restore_path(int s, int t) {
    vector<int> path;

    for (int v = t; v != s; v = par[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    aff(path);
}


void solve()
{

    cin >> n >> m;
    init();

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    
    dist[1] = 0;
    dijkstra();
    if(dist[n]==INF)
         cout << -1 ;
    else 
        restore_path(1,n);
}
int32_t main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);cin.tie(0);
    
   // ll T;
    //cin>>T;
    //while(T--){
        solve();
    //}
    return 0;
}
