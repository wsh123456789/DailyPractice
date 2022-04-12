#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100010;

int n;
int a[maxn];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; i ++ )
        a[i] -= a[1];

    int d = a[2];
    for (int i = 3; i <= n; i ++ ) 
	d = gcd(d, a[i]);
    if (d) 
	cout << a[n] / d + 1 << endl;
    else cout << n << endl;
    return 0;
}
