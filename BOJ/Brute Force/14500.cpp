//테트로미노
//Brute force
/*
  주어진 격자를 테트로미노 모양으로 커버했을 때 커버한 값들의 합의 최대값을 구하는 문제이다.
  모든 테트로미노를 전부 구현하면 된다...
*/

#include <iostream>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int n, m, a[501][501], res;
pii tet[21][4] = {
	//----모양
	{{0,0},{0,1},{0,2},{0,3}},
	{{0,0},{0,-1},{0,-2},{0,-3}},
	{{0,0},{1,0},{2,0},{3,0}},
	{{0,0},{-1,0},{-2,0},{-3,0}},

	//2*2정사각형
	{{0,0},{0,1},{1,0},{1,1}},

	//ㄴ자
	{{0,0},{1,0},{2,0},{2,1}},
	{{0,0},{0,1},{0,2},{-1,2}},
	{{0,0},{0,1},{1,1},{2,1}},
	{{0,0},{1,0},{0,1},{0,2}},

	{{0,0},{1,0},{2,0},{2,-1}},
	{{0,0},{0,1},{0,2},{-1,0}},
	{{0,0},{1,0},{2,0},{0,1}},
	{{0,0},{1,2},{0,1},{0,2}},

	//Z자
	{{0,0},{1,0},{1,1},{2,1}},
	{{0,0},{0,1},{-1,1},{-1,2}},

	{{0,0},{-1,0},{-1,1},{-2,1}},
	{{0,0},{0,1},{1,1},{1,2}},

	//ㅗ자
	{{0,0},{1,1},{0,1},{-1,1}},
	{{0,0},{0,1},{0,2},{-1,1}},
	{{0,0},{1,0},{2,0},{1,1}},
	{{0,0},{0,1},{0,2},{1,1}}
};


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 21; k++) {
				int tmp = 0;
				for (int l = 0; l < 4; l++) {
					int ni = i + tet[k][l].first, nj = j + tet[k][l].second;
					if (ni < 0 || ni >= n || nj < 0 || nj >= m) tmp -= 10000;
					else tmp += a[ni][nj];
				}
				res = max(res, tmp);
			}
		}
	}

	cout << res;
	return 0;
}
