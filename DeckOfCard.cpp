#include <bits/stdc++.h>
#include <ios>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int count0 = 0, count1 = 0;
    for (char c : s) {
      if (c == '0') {
        count0++;
      } else if (c == '2') {
        count1++;
      }
    }

    long long minL = count0;
    long long maxL = count0 + count1;
    long long m = n - k;
    string res = "";
    for (int i = 1; i <= n; i++) {
      long long left = i - m;
      long long right = i - 1LL;
      if (left > right) {
        res += '-';
        continue;
      }
      bool always_remain = (minL >= left && maxL <= right);
      bool no_overlap = (maxL < left || minL > right);
      if (always_remain) {
        res += '+';
      } else if (no_overlap) {
        res += '-';
      } else {
        res += '?';
      }
    }
    cout << res << endl;
  }
  return 0;
}
