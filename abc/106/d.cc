#include <iostream>
#include <vector>

struct segtree {
  vector<int> data;
  int len;
  segtree(int num) {
    //[0,num)のsegtreeを作成
    len = num;

    for(int i = 0,l;;i++) {
      l = 1 << i;
      if(l > num) {
        //l = 2^(n+1) - 1
        data = vector<int>(l-1);
        return;
      }
    }
  }

  void set(int a, int b) {
    int n = (data.size() + 1) / 2;
    for(int i = 0; (1 << i) <= n; i++) {
      int start = (1 << i);
      int end = (1 << (i + 1)) - 1;
      //更新する最初の要素を決定する
      int update_start = a / (n / (1 << i));
      int update_end = b / (n / (1 << i));
      for(int j = start + update_start; j <= start + update_end; j++) {
        data[j]++;
      }
    }
  }

  int get(int a, int b, int l, int i) {
    int n = (data.size() + 1) / 2;
    int seg = n / (1 << l);
    int l_start = i * seg;
    int l_end = (i + 1) * seg - 1;
    
  }
}

int main() {
  
}
