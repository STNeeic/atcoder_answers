#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  char field [100][100];
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      if(i < 50) field[i][j] = '.';
      else field[i][j] = '#';
    }
  }

  // #.
  // .. という形のブロックを作ると、.の連結数を変えずに#の数だけ増やせる。
  //
  // それが、50 * 25 = 1250個作れるので、500 500の制約は余裕で対応出来る

  int white, black;
  cin >> white >> black;
  white--;
  black--;
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      if(i < 50 and black > 0) {
        if(i % 2 == 0 and j % 2 == 0) {
          field[i][j] = '#';
          black--;
        }
      } else if(i > 50 and white > 0) {
        if(i % 2 == 0 and j % 2 == 0) {
          field[i][j] = '.';
          white--;
        }
      }
    }
  }

  cout << "100 100" << endl;
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      cout << field[i][j];
    }
    cout << endl;
  }
  return 0;
}
