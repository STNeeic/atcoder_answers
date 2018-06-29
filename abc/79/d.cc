#include <iostream>
#include <vector>

int main(void) {
  int m,n;
  std::cin >> m >> n;
  int c[10][10];
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      std::cin >> c[i][j];
    }
  }

  int a[m][n];
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }

  //ある数xを1にする最小コストを計算する。
  //変換経路は最長9のパスを通る
  //つまりこれはネットワークの最短経路問題とおんなじだ。

  //コストのMAXは1000なので、10000よりコストは小さい
  const int MAX = 10000;

  //ダイクストラ法を用いる。
  //経路は必要ないので求めない。

  bool visited[10] = {};
  int cost[11]; //1つMAXのコストを持つだけのcostを作った。
  for(auto &x : cost) x = MAX;

  for(int node_cnt = 0; node_cnt < 10; node_cnt++) {
    if(node_cnt == 0) {
      visited[1] = true;
      cost[1] = 0;
    } else {
      //最小コストのノードをカウントする。
      int min_id = 11;
      for(int i = 0; i < 10; i++) {
        if(!visited[i] && cost[i] < cost[min_id]) {
          min_id = i;
        }
      }
      if(min_id == 11) std::cout << "Err! min_id = 11" << std::endl;
      visited[min_id] = true;
    }

    //コスト情報の更新
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
        if(i == j) continue;
        cost[i] = std::min(cost[i], cost[j] + c[i][j]);
      }
    }
  }

  int output = 0;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] < 0) continue;
      output += cost[a[i][j]];
    }
  }

  std::cout << output << std::endl;

 }
