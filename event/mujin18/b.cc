#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(auto c: s) {
    if(n == 0) {
      cout << "Yes" << endl;
      return 0;
    }
    if(c == '+') n++;
    else n--;
  }
  if(n == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
