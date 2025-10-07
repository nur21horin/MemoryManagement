#include "iostream"
#include <cmath>
using namespace std;

int main() {
  int n, m, a;
  cin >> n >> m >> a;

  long long tiles_lenght=ceil((double)n/a);
  long long tiles_width=ceil((double)m/a);

  cout << tiles_lenght*tiles_width << endl;
  return 0;
}