#include <iostream>
#include <vector>
#include <queue>
#include <limits>


//Dinic 法
//最大フロー最小カット問題を解くためのアルゴリズム
//ベルマン=フォード法で残滓パスを探す際に、レベルグラフを用いるもの



struct Dinic {


  struct Edge {
    // Edge 構造体
    // グラフの隣接リストの構成要素

    int to;  //行き先
    int cost; //コスト
    int rev; //逆辺。G[to] vectorの何番目の辺が逆のEdgeなのかが記述してある。
    //残滓グラフを作るときに、逆向きの辺の容量を増やす作業が必要であるから、その時に検索をせずに済むように逆辺のリスト上の位置を記憶しておく。
  };

  // グラフ。隣接リストで表現している。
  std::vector<std::vector<Edge> > G;

  // レベルグラフ。Sから辺で何個分離れているかでラベルをつける。
  std::vector<int> level;

  // dfsをするときに、どの要素まで調べ終わっているかを記憶するイテレータ。これが無いとオーダーレベルで遅くなるらしい。
  std::vector<int> iter;

  Dinic(int n) {
    G.resize(n, std::vector<Edge>());
    level.resize(n, 0);
    iter.resize(n, 0);
  };

  void add_edge(int from, int to, int cost) {
    G[from].push_back((Edge){to, cost, (int) G[to].size()}); //連接リストの何番目が逆辺なのかをrevに記述する
    G[to].push_back((Edge){from, 0, (int) G[from].size() - 1}); //上の要素はG[from] vectorのG[from].size() - 1番目
  };

  void create_level_graph(int s) {
    //bfsでlevel graphを作成する
    std::queue<int> que;

    //stack overflowによると、-03でmemsetと同速らしいので最適化はコンパイラに任せる
    std::fill(level.begin(), level.end(), -1);
    level[s] = 0;

    que.push(s);
    while(!que.empty()) {
      int v = que.front();
      que.pop(); //popは返り値がvoidでただ要素を消すのみなのでここで行う

      for(auto& edge: G[v]) {
        if(edge.cost > 0 && level[edge.to] < 0) {
          //(cost0は繋がってないedgeとみなす)
          level[edge.to] = level[v] + 1;
          que.push(edge.to);
        }
      }
    }

    int remove_shortest_aug_path(int v, int t, int max_capacity) {
      //levelグラフを元に、dfsで最小の長さの増加パスを検索し、除去する。

      if(v == t) return max_capacity; //再起検索終了時

      for(int &i = iter[v]; i < G[v].size(); i++) {
        //iterで前回調べたパスを記憶しているので、そこから始める
        Edge &e = G[v][i];
        if(e.cost > 0 && level[v] < level[e.to]) {
          int d = remove_shortest_aug_path(e.to, t, std::min(e.cost, max_capacity));
          if(d > 0) {
            //aug pathを除去
            e.cost -= d;
            G[e.to][e.rev].cost += d;
            return d;
          }
        }
      }
      //パスがない時
      return 0;
    }
  }

  int max_flow(int s, int t) {
    //s->tの最大フローを求める。
    int flow = 0;
    const long long INF = std::numeric_limits<int>::max();

    while(true) {
      //無限ループのように見えるが、1ループごとに最短のaug pathの長さが必ず増加するので、高々グラフのノード数(|V|)分しかループしない。
      create_level_graph(s);

      if(level[t] < 0) return flow;
      //グラフが分割された
      std::fill(iter.begin(), iter.end(), 0);
      int f;
      while(f = remove_shortest_aug_path(s, t, INF)) {
        flow += f;
      }
    }
  }
}
