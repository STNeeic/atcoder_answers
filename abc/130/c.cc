#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int W, H, x, y;
	cin >> W >> H >> x >> y;

	double s = (double) W * (double) H / 2.0;

	int res = 0;
	if(x * 2 == W && y * 2 == H) res = 1;
	cout << fixed << setprecision(9) << s << " " << res << endl;
}
