#include <iostream>
#include <cstdlib>

using namespace std;

string s1, s2;
int k, n, m;

int main()
{
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();

    k = max(s1.size(), s2.size()) + 1;

    int c[k];
    int a[k];
    int b[k];

    for (int i = 0; i < k; i++) {
        c[i] = 0;
        a[i] = 0;
        b[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        a[n - i - 1] = atoi(s1.substr(i, 1).c_str());
    }

    for (int i = 0; i < m; i++) {
        b[m - i - 1] = atoi(s2.substr(i, 1).c_str());
    }

    for (int i = 0; i < k; i++) {
        c[i] = a[i] + b[i] + c[i];

        if (c[i] >= 10) {
            c[i + 1] = c[i + 1] + 1;
            c[i] = c[i] % 10;
        }
    }

    if (c[k - 1] == 0) {
        k -= 1;
    }

    for (int i = k - 1; i >= 0; i--) {
        cout << c[i];
    }

    return 0;
}