#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long

const ll mod = (ll) 1e15 + 7;
using namespace std;
ll mul(ll a, ll b)
{
    if (b == 0) return 0;
    ll tmp = mul(a, b / 2) % mod;
    if (b % 2 != 0) return ((tmp + tmp) % mod + a % mod) % mod;
    return (tmp + tmp) % mod;
}
void nhan(ll a[2][2],ll b[2][2])
{
    ll res[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            res[i][j]=0;
            for (int k = 0; k < 2; k++)
            {
                res[i][j] = (res[i][j] + mul(a[i][k],b[k][j]))% mod;
            }
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = res[i][j];
        }
    }
}

ll power(ll n)
{
    ll res[2][2] = {{1,0},{0,1}};
    ll a[2][2] = {{1,1},{1,0}};
    while (n != 0)
    {
        if (n % 2 != 0)
        {
            nhan(res, a);
        }
        nhan(a, a);
        n /= 2;
    }
    return res[0][1];
}

int main()
{
    fast
    int t;
    cin >> t;
    ll n;
    while(t--)
    {
        cin >> n;
        cout << power(n + 2) - 1 << endl;
    }
}
 
