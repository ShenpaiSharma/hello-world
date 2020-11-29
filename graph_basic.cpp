#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
const ll mod=1e9+7;
const ll N = 1e5 +1;
#define f first
#define s second
#define pii pair< ll, ll >
#define so(v) sort(v.begin(), v.end())
//#define tc int t; cin >> t; while(t--)
using namespace std;
#define deb1a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
        cout << it << " ";        \
    cout << endl;
#define deb2a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
    {                             \
        for (auto it1 : it)       \
        {                         \
            cout << it1 << " ";   \
        }                         \
        cout << endl;             \
    }
#define deb3a(v)                               \
    cout << #v << "-->" << endl;               \
    for (auto it : v)                          \
    {                                          \
        cout << it.fi << " " << it.se << endl; \
    }

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

/*void IO(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}*/

/*ll MOD(ll x){
    return ((x%mod + mod)%mod);
}

ll add(ll a,ll b){
    return MOD(MOD(a)+MOD(b));
}

ll mul(ll a, ll b){
    return MOD(MOD(a)*MOD(b));
}

bool prime(ll n){
	if( n< 2) return false;
	for(ll i=2;i*i<=n;i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

vector<ll> factors(ll n){
	vector<ll> fa;
	for(ll i=2;i*i<=n;i++){
		while(n%i == 0){
			fa.pb(i);
			n /= i;
		}
	}
	if(n > 1){
		fa.pb(n);
	}
	return fa;
}


vector<ll> Sieve(ll n){
	vector<ll> s;
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(ll p=2;p*p<=n;p++){
		if(prime[p]){
			for(ll i=2*p;i<=n;i+=p){
				prime[i] = false;
			}
		}
	}
	for(ll i=2;i<=n;i++){
		if(!prime[i]){
			s.pb(i);
			cout<<i<<" ";
		}
	}
	return s;
}

ll phi(ll n){
	ll result = n;
	for(ll p=2;p*p<=n;p++){
		if(n%p == 0){
			while(n%p == 0){
				n /= p;
			}
			result -= result/p;
		}
	}
	if(n >1){
		result -= result/n;
	}
	return result;
}

ll modexpo(ll x,ll n,ll mod){
	if(n == 0) return 1;
	else if(n%2 == 0){
		return modexpo((x*x)%mod,n/2,mod);
	}
	else return (x*modexpo((x*x)%mod,(n-1)/2,mod))%mod;
}

ll binary_search(ll arr[],ll l, ll r,ll x){
	if(r >= l){
		ll mid = l + (r-l)/2;
		if(x == arr[mid]){
			return x;
		}
		if(x < arr[mid]){
			return binary_search(arr,l,mid-1,x);
		}
		return binary_search(arr,mid+1,r,x);
	}
	return -1;
}*/

////////////////////////////////////////////////////////////////////////////////////////

class Graph{
	public:
	int V;
	list<int> *adj;
};

Graph* AdjList(int V)
{
	Graph* G = new Graph();
	G->V = V;
	G->adj = new list<int>[G->V];
	return G;
}

void addedge(Graph* G, int u, int v)
{
	G->adj[u].push_back(v);
}

void BFS(Graph* G, int s)
{
	bool* vis = new bool[G->V];
	rep(i,0,G->V)
	{
		vis[i] = false;
	}
	vis[s] = true;
	list<int> Q;
	Q.push_back(s);
	while(!Q.empty())
	{
		s = Q.front();
		cout<<s<<" ";
		Q.pop_front();
		for(auto it = G->adj[s].begin(); it != G->adj[s].end(); ++it)
		{
			if(!vis[*it])
			{
				vis[*it] = true;
				Q.push_back(*it);
			}
		}
	}
}

void DFSUtil(Graph* G, bool* vis, int s)
{
	vis[s] = true;
	cout<<s<<" ";
	for(auto it = G->adj[s].begin(); it != G->adj[s].end(); ++it)
	{
		if(!vis[*it])
		{
			DFSUtil(G,vis,*it);
		}
	}
}

void DFS(Graph* G, int s)
{
	bool* vis = new bool[G->V];
	rep(i,0,G->V)
	{
		vis[i] = false;
	}
	DFSUtil(G,vis,s);
}

void TopoUtil(Graph* G,bool* vis, int s, stack<int> &S)
{
	vis[s] = true;
	for(auto it = G->adj[s].begin(); it != G->adj[s].end(); ++it)
	{
		if(!vis[*it])
		{
			TopoUtil(G,vis,*it,S);
		}
	}
	S.push(s);
}

void TopoSort(Graph* G,int s)
{
	bool* vis = new bool[G->V];
	rep(i,0,G->V)
	{
		vis[i] = false;
	}
	stack<int> S;
	TopoUtil(G,vis,s,S);
	rep(i,0,G->V)
	{
		if(!vis[i]) TopoUtil(G,vis,i,S);
	}
	while(!S.empty())
	{
		cout<<S.top()<<" ";
		S.pop();
	}
}

int timer = 0;
vector<int> intime(10000);
vector<int> outime(10000);
void funUtil(Graph* G, bool* vis, int s)
{
	vis[s] = true;
	++timer;
	intime[s] = timer;
	for(auto it = G->adj[s].begin(); it != G->adj[s].end(); ++it)
	{
		if(!vis[*it])
		{
			funUtil(G,vis,*it);
		}
	}
	++timer;
	outime[s] = timer;
}

void fun(Graph* G, int s)
{
	bool* vis = new bool[G->V];
	rep(i,0,G->V)
	{
		vis[i] = false;
	}
	funUtil(G,vis,s);
}

bool query(int u,int v)
{
	return ((intime[u] < intime[v] && outime[u] > outime[v]) || (intime[u] > intime[v] && outime[u] < outime[v]));
}

bool cyclicUtil(Graph* G,int s, bool* vis, bool* recstack)
{
	if(!vis[s])
	{
		vis[s] = true;
		recstack[s] = true;
	}
	for(auto it = G->adj[s].begin(); it != G->adj[s].end(); ++it)
	{
		if(!vis[*it] && cyclicUtil(G,*it,vis,recstack)) return true;
		else if(recstack[*it]) return true;
	}
	recstack[s] = false;
	return false;
}

bool cyclic(Graph* G,int s)
{
	bool* vis = new bool[G->V];
	bool* recstack = new bool[G->V];
	set(vis,false);
	set(recstack,false);
	rep(i,0,G->V)
	{
		if(!vis[i])
		{
			if(cyclicUtil(G,i,vis,recstack)) return true;
		}
	}
	return false;
}

//for undirected

// bool isCyclicUtil(Graph* G,int s,bool* vis, int parent)
// {
// 	vis[s] = true;
// 	for(auto it = G->adj[s].begin(); it != G->adj[s].end(); ++it)
// 	{
// 		if(!vis[*it] && isCyclicUtil(G,*it,vis,s)) return true;
// 		else if(*it != parent) return true;
// 	}
// 	return false;
// }

// bool isCyclic(Graph* G,int s)
// {
// 	bool* vis = new bool[G->V];
// 	set(vis,false);
// 	rep(i,0,G->V)
// 	{
// 		if(!vis[i] && isCyclicUtil(G,i,vis,-1)) return true;
// 	}
// 	return false;
// }

void Print(Graph* G)
{
	for(int i=0;i<G->V;i++)
	{
		cout<<i<<"-->";
		for(auto it = G->adj[i].begin(); it != G->adj[i].end(); ++it)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}

int main(){
	//IO();
	optimizeIO();
	int V,E,u,v;
	cin>>V>>E;
	Graph* G = AdjList(V);
	rep(i,0,E)
	{
		cin>>u>>v;
		addedge(G,u,v);
	}
	//Print(G);
	//cout<<endl;
	BFS(G,5);
	cout<<endl;
	DFS(G,5);
	cout<<endl;
	TopoSort(G,5);
	cout<<endl;
	fun(G,5);
	if(query(5,1)) cout<<"Yes\n";
	else cout<<"No\n";
	if(cyclic(G,5)) cout<<"Cycle\n";
	else cout<<"No\n";
	return 0;
}
