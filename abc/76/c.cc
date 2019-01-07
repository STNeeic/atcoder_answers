#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canFill(string sub, string t) {
  for(int i = 0; i < t.size(); i++) {
    if(sub[i] == t[i] || sub[i] == '?') continue;
    else return false;
  }
  return true;
}

int main() {
  string S,T;
  cin >> S >> T;

  //Sは複数の?を持っている．それらのうち，Tを含む辞書順で最小のものを出力する．
  //辞書順で最小=aで置き換わってる
  //つまり最後尾から順にTを入れてみて，いけたら残りをaで埋めれば良い
  for(int i = 0; i <= (int) S.size() - (int) T.size(); i++) {
    string sub = S.substr(S.size() - T.size() - i, T.size());
    if(canFill(sub,T)) {
      S.replace(S.size() - T.size() - i, T.size(), T);
      for(auto& x: S) {
        if(x == '?') x = 'a';
      }

      cout << S << endl;
      return 0;
    }
  }

  cout << "UNRESTORABLE" << endl;
}
