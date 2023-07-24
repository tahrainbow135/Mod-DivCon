#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long

using namespace std;
const ll mod = (int)1e9 + 7;
map<ll, ll> mp;
ll fibo(ll n)
{
	if (mp.count(n)) return mp[n];
	ll k = n/2;
	if (n % 2 == 0)
    {
		return mp[n] = (fibo(k) * fibo(k) + fibo(k - 1) * fibo(k - 1)) % mod;
	}
    return mp[n] = (fibo(k) * fibo(k + 1) + fibo(k - 1) * fibo(k)) % mod;
}

main()
{
    int t;
    cin >> t;
    ll n;
    mp[0] = 1;
    mp[1] = 1;
    while(t--)
    {
        cin >> n;
        if (n != 0) cout << fibo(n - 1) << endl;
        else cout << 0 <<endl;
    }
}
