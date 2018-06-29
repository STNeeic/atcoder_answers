#include <iostream>
#include <vector>

using namespace std;
int main(void) {
  int N;
  cin >> N;
  vector<pair<int, int> > red(N);
  vector<pair<int, int> > blue(N);

  for(auto& i: red) cin >> i.first >> i.second;
  for(auto& i: blue) cin >> i.first >> i.second;
  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end());
  
}
