#include <iostream>
#include <vector>

using namespace std;

void next(vector<int> &a, int K) {
  auto iter = find(a.begin(), a.end(), 0);
  if(iter == a.end()) {
    //全ての列が埋まっている。末尾を加算する
    int index = a.size() - 1;
    if(index >= 0)
      a[index]++;
    while(a[index] > K) {
      a[index] = 0;
      index--;
      a[index]++;
    }
  } else {
    //0の列が存在する。最初の0を1にする
    for(int &x: a) {
      if(x == 0) {
        x = 1;
        break;
      }
    }
  }
}

unsigned long long calc_x(int K, int N) {
  unsigned long long X = 0;
  for(int i = 1; i <= N; i++) {
    unsigned long long n = 1;
    for(int j = 0; j < i; j++) n *= K;
    X += n;
  }
  return X;
}

template <typename T>
void print_array(vector<T> a) {
  for(int i = 0; i < a.size(); i++) {
    cout << a[i];
    if(i < a.size() - 1) cout << " ";
  }
  cout << endl;
}

void get_array(vector<int> &a, int K, int N, unsigned long long index) {
  if(a.size() < N) {
    cerr << "array_size is incorrect" << endl;
    return;
  }

  unsigned long long target = 0;
  for(auto &x: a) x = 0;

  vector<unsigned long long> b(N+1);
  for(auto &x: b) x = 0;
  //(i)のパターンはK通り、(i,j)のパターンはK**2通りだが...
  //(i,j,k), (i,j,k+1)に変化するには何通り必要か
  //(i,j,k,(0,0,0...))となっている
  //末尾から0番目の変化に必要なのは1
  //末尾から1番目の変化に必要なのはK+1
  //末尾から2番目の変化に必要なのは(K+1)*K+1
  //末尾からi番目の変化に必要なのは、a_(i-1)*K + 1
  for(int i = N; i > 0; i--) {
    b[i - 1] = b[i] * K + 1;
  }
  //print_array<unsigned long long>(b);
  //index番目のarrayを検索する
  unsigned long long diff = index;
  while(diff > 0) {
    //0->1について
    //1で変化する
    auto zero_iter = find(a.begin(), a.end(), 0);
    if(zero_iter != a.end()) {
      int index = distance(a.begin(), zero_iter);
      a[index]++;
      diff--;
    } else {
      //1->2について
      //diffを超えない最大のbを出す。
      for(int i = 0; i < N; i++) {
        if(b[i] > diff) continue;
        else {
          a[i]++;

          //繰り上がり処理
          while(a[i] > K) {
            a[i] = 0;
            i--;
            a[i]++;
          }

          diff -= b[i];
          break;
        }
      }
    }
  }
  }

int main(void) {
  int K,N;
  cin >> K >> N;
  unsigned long long X = calc_x(K, N);
  //cout << X << endl;
  vector<int> a(N);
  get_array(a, K, N, X/2 + (X % 2));
  print_array<int>(a);
  return 0;
}
