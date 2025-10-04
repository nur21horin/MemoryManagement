#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        // count distinct positive values
        unordered_set<int> distinct;
        for (int x : a) distinct.insert(x);

        // count decreases
        int decreases = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) decreases++;
        }

        cout << (distinct.size() + decreases) << "\n";
    }

    return 0;
}
