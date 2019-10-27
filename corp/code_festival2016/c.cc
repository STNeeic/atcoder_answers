#include <iostream>
#include <vector>

using namespace std;
struct UnionFind {
	vector<int> par;

	UnionFind(int N) : par(N) {
		for(int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) {
		if(par[x] == x) return x;
			//ここで併合処理も行なっている
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if(rx == ry) return;
		par[rx] = ry;
	}

	bool same(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}

};


int main() {
	int N;
	cin >> N;
	int M;
	cin >> M;
	UnionFind b(M);
	vector<bool> L(M, false);
	for(int i = 0; i < N; i++) {
		int ki;
		cin >> ki;
		int pre_l = -1;
		for(int j = 0; j < ki; j++) {
			int l;
			cin >> l;
			l--;
			L[l] = true;
			if(pre_l == -1) {
				pre_l = l;
				continue;
			}
			b.unite(pre_l, l);
		}
	}
	int f = -1;
	for(int i = 0; i < M; i++) {
		if(L[i] == false) continue;
		if(f == -1){
			f = i;
			continue;
		}
		if(b.same(f, i) == false) {
			cout << "NO" << endl;
			return 0;
		}
	}
		cout << "YES" << endl;
}
