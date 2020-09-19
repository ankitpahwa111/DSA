#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define ll long long
ll modulexp(ll a, ll b, ll c)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % c;
        }
        a = (a * a) % c;
        b = b >> 1;
    }
    return ans;
}
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 
int main()
{

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int a = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int digit = stoi(s.substr(i, 1));
            ll prod = digit % n;
            ll mod = modulexp(10, s.length() - i - 1, n);
            prod *= mod;
            prod %= n;
            a += prod;
        }
        cout << gcd(a, n);
    }
    return 0;
}