#include <iostream>
#include <cstdlib>
using namespace std;

int a[1001], b[1001], c[1001];
string s1, s2;
int main()
{
    cin >> s1 >> s2;

    if (s2.size() > s1.size()) {
        string t = s1;
        s1 = s2;
        s2 = t;
        cout << "-";
    } else if (s2.size() == s1.size()) {
        for (int i = 0; i < s1.size(); i++) {
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

    for (int i = 0; i < s1.size(); i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }

    for (int i = 0; i < s1.size(); i++) a[i] = atoi(s1.substr(s1.size() - i - 1, 1).c_str());
    for (int j = 0; j < s2.size(); j++) b[j] = atoi(s2.substr(s2.size() - j - 1, 1).c_str());

    for (int i = 0; i < s1.size(); i++) {
        c[i] += a[i] - b[i];

        if (c[i] < 0) {
            c[i] += 10;
            c[i + 1]--;
        }
    }

    int k = s1.size() - 1;
    while (c[k] == 0 && k > 0) k--;

    for (int j = k; k > -1; k--) cout << c[k];

    return 0;
}