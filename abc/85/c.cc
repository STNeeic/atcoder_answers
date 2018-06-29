#include <iostream>

int main(void) {
  int N, Y;
  int noguchi, higuchi, yukichi;
  std::cin >> N >> Y;
  //重複を許す組み合わせは，最大値がX，種類がYの場合
  //Y-1個のセパレーターがあると考えて
  //(X+Y-1)C(Y-1) で計算できる
  //つまり，　N=5の場合，しきりを|として
  // oo|oo|o
  //↑の|の位置を選ぶイメージ

  const int H = N + 2;
  for(int i = 0; i < H - 1; i++) {
    for(int j = i + 1; j < H; j++) {
      noguchi = i;
      higuchi = j - i - 1;
      yukichi = H - j - 1;

      if(noguchi * 1000 + higuchi * 5000 + yukichi * 10000 == Y) {
        goto end;
      }
    }
  }

  noguchi = higuchi = yukichi = -1;
 end:
     std::cout << yukichi << " " << higuchi << " " << noguchi << std::endl;
  return 0;
}
