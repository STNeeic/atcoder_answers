#include <iostream>
#include <vector>

using namespace std;
int main(void) {
  int N;
  cin >> N;
  vector<int> spots(N+2);
  vector<int> costs(N+1);
  vector<int> rm_costs(N);
  int all_cost = 0;
  spots[0] = 0;
  spots[N+1] = 0;

  for(int i = 1; i < N + 2; i++) {
    if(i < N + 1)
      cin >> spots[i];

    costs[i-1] = abs(spots[i] - spots[i - 1]);
    all_cost += costs[i - 1];

    if(i > 1) {
      rm_costs[i - 2] = abs(spots[i] - spots[i - 2]);
    }
  }

  for(int i = 0; i < N; i++) {
    int out = all_cost;
    out -= costs[i] + costs[i + 1];
    out += rm_costs[i];
    cout << out << endl;
  }
  return 0;
}
