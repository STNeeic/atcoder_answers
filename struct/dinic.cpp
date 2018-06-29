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
