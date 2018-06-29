#include <iostream>
#include <vector>
#include <queue>
#include <limits>

template<typename T>
struct Dinic {

  struct Edge {
    int to;
    T cost;
    int rev;
  };

  std::vector<std::vector<Edge> > G;

  std::vector<int> level;

  std::vector<int> iter;

  Dinic(int n) {
    G.resize(n, std::vector<Edge>());
    level.resize(n, 0);
    iter.resize(n, 0);
  };

  void add_edge(int from, int to, T cost) {
    G[from].push_back((Edge){to, cost, (int) G[to].size()});
    G[to].push_back((Edge){from, 0, (int) G[from].size() - 1});
  };

  void create_level_graph(int s) {

    std::queue<int> que;


    std::fill(level.begin(), level.end(), -1);
    level[s] = 0;

    que.push(s);
    while(!que.empty()) {
      int v = que.front();
      que.pop();

      for(auto& edge: G[v]) {
        if(edge.cost > 0 && level[edge.to] < 0) {
          level[edge.to] = level[v] + 1;
          que.push(edge.to);
        }
      }
    }
  }

    T remove_shortest_aug_path(int v, int t, T max_capacity) {
      if(v == t) return max_capacity;

      for(int &i = iter[v]; i < G[v].size(); i++) {
        Edge &e = G[v][i];
        if(e.cost > 0 && level[v] < level[e.to]) {
          T d = remove_shortest_aug_path(e.to, t, std::min(e.cost, max_capacity));
          if(d > 0) {
            e.cost -= d;
            G[e.to][e.rev].cost += d;
            return d;
          }
        }
      }
      return 0;
    }

  T max_flow(int s, int t) {
    T flow = 0;
    const T INF = std::numeric_limits<T>::max();
    while(true) {
      create_level_graph(s);

      if(level[t] < 0) return flow;

      std::fill(iter.begin(), iter.end(), 0);
      T f;
      while(f = remove_shortest_aug_path(s, t, INF)) {
        flow += f;
      }
    }
  }
};



int main(void) {
  //最小カット問題に帰着させる。
  //手順はnico_shindanさんの「燃やす埋める問題」についてのslideshareに載っている。

  //今回は、あるコストの宝石を「壊す」「壊さない」の小問題に、
  // 「i番目を壊したら必ずni番目も壊さなければならない」という制約が付いたタイプである。

  //従って、s-(壊さない)->(i番目の宝石)-(壊す)->t というパスを作った場合、
  //(i)->(ni) に向かって容量無限のパスを繋げれば良い

  //また最小カット問題の場合、グラフのコストが必ず正でなければならない。(負を含むとNP困難)
  //よって max_value = sum(min(0, (i番目の宝石のコスト))) とし、
  // max_valueからの損失をcostとしてパスを作る。
  // この時の各パスのコストは以下の通り
  //   壊さない | 壊す
  //i>0  0  | i
  //i<0  i  | 0
  int N;
  std::cin >> N;
  

  long long max_value = 0; //うまく壊せるときにもらえる最大の価値

  Dinic<long long> D(N+2);
  //sとtを含めて+2した。 sが0でtがN+1とする
  const int s = 0;
  const int t = N + 1;
  const long long INF = 1 << 30;
  if(INF < 0 && INF < 1000000000) std::cout << "INF < 0 :INF = " << INF << std::endl;

  for(int i = 1; i <= N; i++) {
    long long inp;
    std::cin >> inp;
    if(inp > 0) {
      D.add_edge(i, t, inp); //壊すと損失
      max_value += inp;
    } else {
      D.add_edge(s, i, -inp); //壊さないと損失
    }
    //iを壊すと倍数を叩き割らなければならない
    for(int j = 2 * i; j <= N; j += i) {
      D.add_edge(i, j, INF);
    }
  }

  long long flow = D.max_flow(s, t);
  /*
  for(auto x: D.G) {
    for(auto y: x) {
      std::cout << "to:" << y.to << "\tcost:" << y.cost << "\trev:" << y.rev << std::endl;
    }
  }
  */
  std::cout << max_value - flow << std::endl;
  return 0;
}
