#include <iostream>
#include <cstdlib>

using namespace std;

int n, m, k, a[2502], b[2502], c[5003];
string s1, s2;
int main()
{
    cin >> s1 >> s2;

    n = s1.size();
    m = s2.size();
    k = m + n;

    for (int i = 1; i <= n; i++) a[i] = atoi(s1.substr(n - i, 1).c_str());
    for (int j = 1; j <= m; j++) b[j] = atoi(s2.substr(m - j, 1).c_str());

    for (int i = 1; i <= k; i++) c[i] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            c[i + j - 1] += a[j] * b[i];
        }
    }

    for (int i = 1; i <= k-1; i++) {
        c[i + 1] = c[i + 1] + c[i]/10;
        c[i] = c[i] % 10;
    }

    while (c[k] == 0 && k > 1) k--;

    for (int i = k; i > 0; i--) cout << c[i];

    return 0;
}