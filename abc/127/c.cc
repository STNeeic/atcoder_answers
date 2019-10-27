#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

struct LazySegmentTree {
	private:
		int n;
		vector<ll> node, lazy;
	public:
		LazySegmentTree(int N) {
			n = 1;
			while(n < N) n <<= 1;
			node.resize(2 * n - 1, 0);
			lazy.resize(2 * n - 1, 0);
		}

		LazySegmentTree(vector<ll> v) {
			int sz = (int) v.size();
			n = 1;
			while(n < sz) n <<= 1;
			node.resize(2 * n - 1);
			lazy.resize(2 * n - 1, 0);

			for(int i = 0; i < sz; i++) node[i + n - 1] = v[i];
			for(int i = n - 2; i >= 0; i--) node[i] = node[i * 2 + 1] + node[i * 2 + 2];
		}

		void eval(int k, int l, int r) {
			if(lazy[k] != 0) {
				//値の伝搬を行う
				node[k] += lazy[k];

				if(r - l > 1) {
					//子ノードへの伝搬を行う
					lazy[2*k+1] += lazy[k] / 2;
					lazy[2*k+2] += lazy[k] / 2;
				}

				lazy[k] = 0;
			}
		}

		//[a, b)に対してxをaddする
		//現在考えているrangeがk, [l,r)となる
		void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
			if(r < 0) r = n;
			eval(k, l, r);

			if(b <= l || r <= a) return;

			if(a <= l && r <= b) {
				lazy[k] += (r - l) * x;
				eval(k, l, r);
			}

			else {
				add(a, b, x, 2*k + 1, l, (l + r) / 2);
				add(a, b, x, 2*k + 2, (l + r) / 2, r);
				node[k] = node[2*k + 1] + node[2*k + 2];
			}

		}

		ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
			if(r < 0) r = n;
			if(b <= l || r <= a) return 0;

			eval(k, l, r);
			if(a <= l && r <= b) return node[k];
			ll vl = getsum(a, b, 2*k + 1, l, (l + r)/2);
			ll vr = getsum(a, b, 2*k + 2, (l + r)/2, r);
			return vl + vr;
		}

		int getmaxrange(int m, int nn) {
			int max = -1;
			int maxlen = 0;
			int len = 0;
			bool connected = true;
			//全ノードを評価する
			for(int i = 0; i < nn; i++) {
				int num = getsum(i, i + 1);
				if(max < num) {
					max = num;
					len = 1;
					maxlen = 1;
					connected = true;
				} else
				if(max == num) {
					if(connected) {
						len++;
						if(len > maxlen) maxlen = len;
					} else {
						len = 1;
						connected = true;
					}
				} else
				if(max > num) {
					len = 0;
					connected = false;
				}

			}
			if(m > max) return 0;
			return maxlen;
		}

		void catnode() {
			int deg = 1;
			for(int i = 0; i < 2 * n - 1; i++) {
				cout << node[i] << " ";
				if(i + 1 == 2 * deg - 1) {
					cout << endl;
					deg *= 2;
				}
			}
			cout << endl;
		}

		void catlazy() {
			int deg = 1;
			for(int i = 0; i < 2 * n - 1; i++) {
				cout << lazy[i] << " ";
				if(i + 1 == 2 * deg - 1) {
					cout << endl;
					deg *= 2;
				}
			}
			cout << endl;
		}
};


int main() {
	int N, M;
	cin >> N >> M;
	LazySegmentTree t(N);
	for(int i = 0; i < M; i++) {
		int L, R;
		cin >> L >> R;
		t.add(L - 1, R, 1);
	}
	cout << t.getmaxrange(M, N) << endl;
}
