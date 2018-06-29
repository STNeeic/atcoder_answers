#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
int main(void) {
  vector<int> p;
  //エラトステネスの篩
  bitset<5555555> n;
  n[0] = true;
  n[1] = true;
   for(int i = 2; i * i < 5555555; i++) {
    if(n[i]) continue;
    for(int j = i * 2; j <= 5555555; j += i) n[j] = true;
  }

  for(int i = 2; i <= 55555; i++) {
    if(n[i] == false) p.push_back(i);
  }

  //こっから、5つ足した時にかならず合成数になる

  vector<int> res;

  int N;
  cin >> N;
  while(res.size() <= N) {
    res.push_back(p.front());
    p.erase(p.begin());
  }

  for(int i = 0; i < res.size(); i++) {
    if(i == 0) cout << res[i];
    else cout << " " << res[i];
  }
  cout << endl;
  return 0;
}
