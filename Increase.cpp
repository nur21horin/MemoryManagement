#include <bits/stdc++.h>
#include <ios>
#include <unordered_set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    unordered_set<int> mamu(arr.begin(), arr.end());
    int m = mamu.size();
    int ans = 2 * m - 1;
    cout << ans << "\n";

    // for (int i = 0; i < n; i++) {
    //   if (arr[i] > 0)
    //     value.insert(arr[i]);
    // }
    // int count = 0;

    // if (arr.size() == 1)
    //   count = 0;
    // else {
    //   for (int i = 0; i < n; i++) {
    //     if (arr[i] < arr[i - 1]) {
    //       count++;
    //     }
    //   }
    // }
    // cout << value.size() + count << "\n";
  }
  return 0;
}