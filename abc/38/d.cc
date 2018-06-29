#include <iostream>
#include <vector>
#include <utility>


int main() {
  using namespace std;

  int N;
  cin >> N;
  vector<pair <int, int> > box(N);
  for(auto &i: box) {
    cin >> i.first >> i.second;
  }

  sort(box.begin(), box.end());

  vector<int> len(N);

  int all_max_len = 0;
  for(int i = 0; i < N; i++) {
    int max_len = 0;
    for(int j = 0; j < i; j++) {
      if(box[j].first < box[i].first && box[j].second < box[i].second &&max_len < len[j]) {
        max_len = len[j];
      }
    }
    len[i] = max_len + 1;
    if(len[i] > all_max_len) {
      all_max_len = len[i];
    }
  }

  cout << all_max_len << endl;
}
