#include <iostream>
#include <cstdlib>
using namespace std;

int n, m, a[1001], b[1001], c[1001];
string s1, s2;
int main()
{
    cin >> s1 >> s2;

    n = s1.size();
    m = s2.size();
    
    if (m > n) {
        string t = s1;
        s1 = s2;
        s2 = t;
        n = s1.size();
        m = s2.size();
        cout << "-";
    } else if (n == m) {
        for (int i = 0; i < n; i++) {
            if (s2[i] != s1[i]) {
                if (s2[i] > s1[i]) {
                    string t = s1;
                    s1 = s2;
                    s2 = t;
                    cout << "-";
                }
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }

    for (int i = 0; i < n; i++) a[i] = atoi(s1.substr(n - i - 1, 1).c_str());
    for (int j = 0; j < m; j++) b[j] = atoi(s2.substr(m - j - 1, 1).c_str());

    for (int i = 0; i < n; i++) {
        c[i] += a[i] - b[i];

        if (c[i] < 0) {
            c[i] += 10;
            c[i + 1]--;
        }
    }

    n--;
    while (c[n] == 0 && n > 0) n--;

    for (; n > -1; n--) cout << c[n];

    return 0;
}
