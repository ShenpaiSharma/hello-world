#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
#define um unordered_map
#define us unordered_set
#define vi vector<ll> 
#define vi2d vector<vector<ll>>
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
const ll N = 1e6 + 7;
#define f first
#define s second
#define pii pair< ll, ll >
#define so(v) sort(v.begin(), v.end())
#define tc int t; cin >> t; while(t--)
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

vector<vector<int>> v;
v.resize(n,vector<int>(m,0));

bool prime(ll n){
	if( n < 2) return false;
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

vector<vector<ll>> prefixSum(vector<vector<ll>> v, ll n, ll m) // 2D Prefix sum
{
	vector<vector<ll>> aux;
	aux.resize(n, vector<ll>(m,0));
	for(ll i=0;i<n;i++)
	{
		aux[0][i] = v[0][i];
	}
	for(ll i=1;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			aux[i][j] = v[i][j] + aux[i-1][j];
		}
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=1;j<m;j++)
		{
			aux[i][j] += aux[i][j-1];
		}
	}
	return aux;
}

ll pm[N];

void  Sieve()
{
    bool prime[N];
    set(prime,true);
    prime[0] = false;
    prime[1] = false;
    for(ll i=2;i*i<=N;i++)
    {
        if(prime[i])
        {
            for(ll p=i*i;p<=N;p+=i)
            {
                prime[p] = false;
            }
        }
    }                             // precompute all the prime
    pm[0] = 0;
    pm[1] = 0;
    rep(i,2,N)
    {
        if(prime[i])
        {
            pm[i] = pm[i-1] + 1;
        }
        else pm[i] = pm[i-1];
    }
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

const ll zero;

void buildtree(ll start, ll end, ll node)
{
    if(start == end)
    {
        tree[node] = arr[start];
        return;
    }
    ll mid = (start + end)/2;
    buildtree(start, mid, 2*node);
    buildtree(mid+1, end, 2*node +1);
    tree[node] = min(tree[2*node], tree[2*node + 1]);
}

void update(ll s, ll e, ll idx, ll val, ll node)
{
	if(s == e)
	{
		tree[node] = val;
		arr[idx] = val;
	}
	else
	{
		ll mid = (s+e)/2;
		if(idx >= s && idx <= mid)
		{
			update(s,mid,idx,val,2*node);
		}
		else
		{
			update(mid+1,e,idx,val,2*node+1);
		}
		tree[node] = min(tree[2*node], tree[2*node+1]);
	}
}

ll query(ll s,ll e,ll l,ll r, ll node)
{
	if(r < s || l > e) return zero;
	if(l <= s && r >= e)
	{
		return tree[node];
	}
	ll mid = (s+e)/2;
	ll p1 = query(s,mid,l,r,2*node);
	ll p2 = query(mid+1,e,l,r,2*node+1);
	return min(p1,p2);
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

// //Precompute factorial
// const ll MOD = 1e9 + 7; 
// vi inv(N+2), factorial(N+2);

// ll modexpo(ll x,ll n,ll MOD){
// 	if(n == 0) return 1;
// 	else if(n%2 == 0){
// 		return modexpo((x*x)%MOD,n/2,MOD);   
// 	}
// 	else return (x*modexpo((x*x)%MOD,(n-1)/2,MOD))%MOD;
// }

// ll bf(ll n, ll k) {
// 	if(k > n) return 0;
//     return factorial[n] * inv[k] % MOD * inv[n-k] % MOD;
// }

// //put this before tc
// factorial[0] = 1;
// for (ll i = 1; i <= N; i++) {
// 	factorial[i] = factorial[i - 1] * i % MOD;
// }

// // inv[1] = 1;
// // for(ll i = 2; i <= N; ++i) {                 
// // 	inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
// // }
// inv[0] = 1;
// inv[1] = 1;
// rep(i,2,N+1)
// {
// 	inv[i] = modexpo(factorial[i], MOD-2,MOD);
// }

//////////////////////////////////////////////////////////////////////////////////////////

vi a(N+1), bit(N+1), tot(N+1), gs(N+1);
ll n;

void precomp() 
{
	rep(i,1,N+1) tot[i] = i;
	rep(i,2,N+1)
	{
		if(tot[i] == i)
		{
			for(int j=i;j<=N;j+=i)
			{
				tot[j] -= tot[j]/i;
			}
		}
	}
	rep(i,1,N+1)
	{
		for(int j=i;j<=N;j+=i)
		{
			gs[j] += i*tot[j/i];
		}
	}
}

void update(ll i, ll x)
{
	x %= mod;
	for(;i<=N;i+=(i&-i))
	{
		bit[i] += x%mod;
		bit[i] %= mod;
	}
}

ll Sum(ll i)
{
	ll sum = 0;
	for(;i>0;i-=(i&-i))
	{
		sum += bit[i]%mod;
		sum %= mod;
	}
	return sum;
}

int main()
{
	optimizeIO();
	precomp();
	cin>>n;
	rep(i,1,n+1)
	{
		cin>>a[i];
		update(i, gs[a[i]]);
	}
	ll q, x, y;
	char c;
	cin>>q;
	while(q--)
	{
		cin>>c>>x>>y;
		if(c == 'U')
		{
			update(x, -gs[a[x]]);
			a[x] = y%mod;
			update(x, gs[y]);
		}
		else
		{
			ll ans = (Sum(y)%mod - Sum(x-1)%mod)%mod;
			if(ans < 0) ans += mod;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
