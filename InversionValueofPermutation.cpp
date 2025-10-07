
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int test = 0; test < t; test++) {
        int n;
        long long k;
        cin >> n >> k;
        long long T = (long long)n * (n - 1) / 2;
        if(k > T || k < 0) {
            cout << 0 << '\n';
            continue;
        }
        long long M = (long long)n * n - 2 * k;
        vector<vector<char>> dp(n + 1, vector<char>(n * n + 1, 0));
        dp[0][0] = 1;
        for(int curs = 0; curs < n; curs++) {
            for(int curq = 0; curq <= n * n; curq++) {
                if(dp[curs][curq]) {
                    for(int mi = 1; mi <= n - curs; mi++) {
                        int news = curs + mi;
                        int newq = curq + mi * mi;
                        if(news <= n && newq <= n * n) {
                            dp[news][newq] = 1;
                        }
                    }
                }
            }
        }
        if(!dp[n][M]) {
            cout << 0 << '\n';
            continue;
        }
        // reconstruct
        vector<int> runs;
        int curs = n;
        int curq = M;
        while(curs > 0) {
            for(int mi = curs; mi >= 1; mi--) {
                int prevs = curs - mi;
                int prevq = curq - mi * mi;
                if(prevs >= 0 && prevq >= 0 && dp[prevs][prevq]) {
                    runs.push_back(mi);
                    curs = prevs;
                    curq = prevq;
                    break;
                }
            }
        }
        // now build perm
        vector<int> perm(n);
        int pos = 0;
        int num = n;
        for(int len : runs) {
            vector<int> temp;
            for(int i = 0; i < len; i++) {
                temp.push_back(num--);
            }
            sort(temp.begin(), temp.end());
            for(int val : temp) {
                perm[pos++] = val;
            }
        }
        for(int i = 0; i < n; i++) {
            if(i > 0) cout << ' ';
            cout << perm[i];
        }
        cout << '\n';
    }
    return 0;
}