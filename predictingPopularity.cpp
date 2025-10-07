
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n; // size (power of two)
    vector<int> sum;      // sum of b over segment
    vector<int> minPref;  // minimum prefix sum over segment

    SegTree(int size) {
        n = 1;
        while (n < size) n <<= 1;
        sum.assign(2 * n, 0);
        minPref.assign(2 * n, 0);
        // Initialize leaves [0..size-1] to -1 (b[x] = freq[x] - 1, start with freq=0)
        for (int i = 0; i < size; ++i) {
            sum[n + i] = -1;
            minPref[n + i] = -1;
        }
        // Leaves beyond size remain 0
        for (int i = n - 1; i >= 1; --i) pull(i);
    }

    inline void pull(int i) {
        sum[i] = sum[i << 1] + sum[i << 1 | 1];
        // min prefix over [L|R] = min(minPref(L), sum(L) + minPref(R))
        minPref[i] = min(minPref[i << 1], sum[i << 1] + minPref[i << 1 | 1]);
    }

    // add delta to position pos (0-based)
    void update(int pos, int delta) {
        int i = n + pos;
        sum[i] += delta;
        minPref[i] += delta;
        for (i >>= 1; i >= 1; i >>= 1) pull(i);
    }

    // Find the smallest index t where global prefix sum < 0.
    // Returns t in [0..n-1]. If never negative, returns n (but with our initialization, there will be a negative).
    int firstNegative() const {
        int i = 1;
        int pref = 0; // accumulated prefix sum before current node
        if (minPref[1] + pref >= 0) return n; // should not happen with -1 baseline, but keep safe
        // Walk down the tree
        while (i < n) {
            int left = i << 1, right = left | 1;
            if (minPref[left] + pref < 0) {
                i = left;
                // pref unchanged
            } else {
                pref += sum[left];
                i = right;
            }
        }
        return i - n; // leaf index
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ac, dr;
    if (!(cin >> ac >> dr)) return 0;

    int n;
    cin >> n;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> d[i];

    auto deficit = [&](int ai, int di) -> int {
        int da = ai - ac;
        if (da < 0) da = 0;
        int dd = di - dr;
        if (dd < 0) dd = 0;
        return da + dd;
    };

    // Max possible deficit is up to 2e6. Add small cushion.
    const int MAXV = 2'000'005;
    SegTree st(MAXV);

    vector<int> curDef(n);
    for (int i = 0; i < n; ++i) {
        curDef[i] = deficit(a[i], d[i]);
        // Increase freq[curDef] -> b[curDef] += 1
        st.update(curDef[i], +1);
    }

    int m;
    cin >> m;
    while (m--) {
        int k, na, nd;
        cin >> k >> na >> nd;
        --k; // 0-based index

        // Remove old deficit
        st.update(curDef[k], -1);

        // Update preferences and add new deficit
        a[k] = na;
        d[k] = nd;
        curDef[k] = deficit(a[k], d[k]);
        st.update(curDef[k], +1);

        // Popularity equals the first position where prefix sum of b becomes negative
        int pos = st.firstNegative();
        int p = (pos <= MAXV) ? pos : n; // safety cap (though pos should be within MAXV)
        cout << p << "\n";
    }
    return 0;
}