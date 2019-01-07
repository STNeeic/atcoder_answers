#include <iostream>
#include <string>
 
using namespace std;
int main() {
  string s;
  cin >> s;
  if(s.compare(0,5,"MUJIN") == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
