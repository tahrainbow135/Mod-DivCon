#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

using namespace std;
const int mod = (int)1e9 + 7;
long long mul(long long a, long long b, long long c)
{
    if (b == 0)
        return 0;

    long long tmp = mul(a, b / 2, c) % c;

    if (b % 2 != 0)
        return ((tmp + tmp) % c + a % c) % c;
    return (tmp + tmp) % c;
}
long long power(long long a, long long b, long long c)
{
    if (b == 0) return 1;

    long long tmp = power(a, b / 2, c) % c;
    tmp = mul(tmp, tmp, c);

    if (b % 2 != 0)
        return mul(tmp, a, c);
    return tmp;
}
int main()
{
    fast
    int t;
    cin >> t;
    long long a,b,c;
    while(t--)
    {
        cin >> a >> b >> c;
        cout << power(a,b,c) << endl;
    }
}
