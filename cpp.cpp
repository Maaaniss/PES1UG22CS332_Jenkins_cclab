/**
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　	　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/
  
 #include<bits/st
    //#include<ext/pb_ds/assoc_container.hpp>
    //#include<ext/pb_ds/tree_policy.hpp>
     
    using namespace std;
    //using namespace __gnu_pbds;
     
     
    #define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
    #define MOD 1000000007
    #define INF 1e18
    #define nline "\n"
    #define pb push_back
    #define ppb pop_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define PI 3.141592653589793238462
    #define set_bits __builtin_popcountll
    #define sz(x) ((int)(x).size())
    #define all(x) (x).begin(), (x).end()
     
    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double lld;
    //typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order-> finds position of xth element, order_of_key-> returns no of elements<x
     
     
    #ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
    #else
    #define debug(x)
    #endif
     
    void _print(ll t) {cerr << t;}
    void _print(int t) {cerr << t;}
    void _print(string t) {cerr << t;}
    void _print(char t) {cerr << t;}
    void _print(lld t) {cerr << t;}
    void _print(double t) {cerr << t;}
    void _print(ull t) {cerr << t;}
    //void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
     
    template <class T, class V> void _print(pair <T, V> p);
    template <class T> void _print(vector <T> v);
    template <class T> void _print(set <T> v);
    template <class T, class V> void _print(map <T, V> v);
    template <class T> void _print(multiset <T> v);
    template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
    template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
    template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
    template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
    template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    ll expo(ll a, ll b, ll M) // O(log(b))
    {
        ll ans = 1;
        while(b)
        {
            if(b & 1)
            {
                ans = (ans * a) % M;
            }
            a = (a * a) % M;
            b >>= 1;
        }
        return ans;
    }
    //----------------------------------------------------------------------------------------------------------------------------------------/
 
    bool is_prime(ll n) // faster than O(sqrt(n))
    {
        if(n == 1) return false;
        if(n==2 || n==3) return true;
        if(n%2==0 || n%3==0) return false;
        for(ll i=6;i*i<=n;i+=6){
            if(n%(i-1)==0 || n%(i+1)==0) return false;
        }   
        return true;
        // bool prime = true;
        // for (ll i = 2; i * i <= n; ++i)
        // {
        //     if(n % i == 0)
        //     {
        //         prime = false;
        //         break;
        //     }
        // }
        // return prime;
    }
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    void prime_factors(ll n, map<ll , ll> &m) // O(sqrt(n))
    {
        for (ll i = 2; i * i <= n; ++i)
        {
            while(n % i == 0)
            {
                ++m[i];
                n /= i;
            }
        }
        if(n > 1) ++m[n];
    }
    //----------------------------------------------------------------------------------------------------------------------------------------/
 
    void sieve(ll n , vector<ll> &v) // O(nlog(logn))
    {
        vector<bool> primes(n + 10, 1);
        primes[0] = primes[1] = false;
        for (ll i = 2; i <= n; ++i)
        {
            if(primes[i] == true)
            {
                v.pb(i);
                for(ll j = 2 * i; j <= n; j += i)
                {
                    primes[j] = false;
                }
            }
        }
    }
    //----------------------------------------------------------------------------------------------------------------------------------------/
 
    void ext_sieve(ll n, vector<ll> &v, vector<ll> &lp, vector<ll> &hp) // O(nlog(logn))
    {
        vector<bool> primes(n + 10, 1);
        for (ll i = 0; i < n + 10; ++i)
        {
            lp.pb(0);
            hp.pb(0);
        }
        primes[0] = primes[1] = false;
        for (ll i = 2; i <= n; ++i)
        {
            if(primes[i] == true)
            {
                v.pb(i);
                lp[i] = hp[i] = i;
                for(ll j = 2 * i; j <= n; j += i)
                {
                    primes[j] = false;
                    hp[j] = i;
                    if(lp[j] == 0)
                    {
                        lp[j] = i;
                    }
                }
            }
        }
    }
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    void ext_prime_factors(ll n, vector<ll> &lp ,map<ll , ll> &m) // O(logn)
    {
        //vector<ll> v,lp,hp;
        //ext_sieve(n , v , lp , hp); // O(nlog(logn))
 
        while(n > 1) // O(logn)
        {
            ll prime = lp[n];
            while(n % prime == 0)
            {
                n /= prime;
                ++m[prime];
            }
        }
    }
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    vector<vector<ll>> divisors(ll n) // O(nlogn)
    {
        vector<vector<ll>> v(n + 1);
        for(ll i = 1; i <= n; ++i)
        {
            for(ll j = i; j <= n; j += i)
            {
                v[j].pb(i);
            }
        }
        return v;
    }
 
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    ll gcd(ll a, ll b) // O(log(min(a , b)))
    {
        return (b == 0 ? a : gcd(b , a % b));
    }
 
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    ll lcm(ll a, ll b) // O(log(min(a , b)))
    {
        return ((a * b) / gcd(a , b));
    }
 
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    ll phi(ll n) // for n <= 1e7: O(logn) (prime factorisation using sieve), remaining larger n: O(sqrt(n))
    {
        ll result = n;
 
        for (ll i = 2; i * i <= n; ++i)
        {
            if(n % i == 0)
            {
                while(n % i == 0) n /= i;
                result -= result / i;
            }
        }
 
        if(n > 1) result -= result / n;
 
        return result;
    }
 
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    vector<ll> phi_1_to_n(ll n) // O(nlog(logn))
    {
        vector<ll> v(n + 1);
        for (ll i = 0; i <= n; ++i)
        {
            v[i] = i;
        }
 
        for (ll i = 2; i <= n; ++i)
        {
            if(v[i] == i)
            {
                for(ll j = i; j <= n; j += i)
                {
                    v[j] -= v[j] / i;
                }
            }
        }
        return v;
    }
 
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    ll mminvprime(ll a, ll m) {return expo(a, m - 2, m);} //only for prime m
    ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
    ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
    ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
    ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
 
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    ll combination(ll n, ll r, ll m, vector<ll> &fact, vector<ll> &ifact) // O(1)
    {
        return mod_mul(fact[n] , mod_mul(ifact[r] , ifact[n - r], m), m);
    }
 
    // precomputation of fact and ifact in O(N) for combination:
 
    /*
        ll N = 1e6;
        vector<ll> fact(N + 1);
        vector<ll> ifact(N + 1);
        fact[0] = 1
        for(ll i = 1; i <= N; ++i)
        {
            fact[i] = mod_mul(fact[i - 1] , i , mod);
        }
        ifact[N] = mminprime(fact[N] , MOD);
        for(ll i = N - 1; i >= 0; --i)
        {
            ifact[i] = mod_mul(ifact[i + 1] , i + 1, MOD);
        }
 
        example: cout<<combination(8 , 6, MOD, fact, ifact);
 
    */
 
    //---------------------------------------------------------------------------------------------------------------------------------------/
 
    ll ncr(ll n, ll r, ll m) //O(r)
    {
        ll num = 1, den = 1;
        for (ll i = n; i >= n - r + 1; --i)
        {
            num = (num * i) % m;
        }
        for (ll i = 1; i <= r; ++i)
        {
            den = (den * i) % m;
        }
        num %= m;
        den %= m;
        ll inv = expo(den, m - 2, m);
        return ((num * inv) % m);
    }
 
    //---------------------------------------------------------------------------------------------------------------------------------------/
 

    void solve(){
        ll a,b;
        cin>>a>>b;
        ll ans=0;
        if(b>a){
            cout<<1<<nline;
            return;
        }
        if(b==a){
            cout<<2<<nline;
            return;
        }
        
    }

    int main(){
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif
        fastio();
        // code begins here:
        ll T=1;
        cin>>T;
        while(T--){       	
          solve();
	      }
	}
