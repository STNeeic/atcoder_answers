#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
  using namespace std;
  vector<int> inp(3);
  for(auto& i: inp) {
    cin >> i;
  }
  sort(inp.begin(), inp.end());

  int N = inp[2] - inp[1];
  int M = inp[1] - inp[0];
  //a > b > cとしたとき
  // N = a - b
  // M = b - c
  //一回の操作で、
  //1.を行うと、 Nが1へる
  //2.を行うと、 Mが2へる
  //よって操作の回数は、 N + (M + 1) / 2 回
  //ただし、M % 2 > 0のとき、最後に1.をもう一度行う必要がある
  //従って、回数は以下の通りになる
  cout << N + (M + 1) / 2 + M % 2 << endl;
}
