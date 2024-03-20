#include <iostream>
using namespace std;

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

bool paths(char maze[][10], int soln[][10], int M, int N, int i, int j) {

	// base case
	if (i == M and j == N) {
		soln[i][j] = 1;
		// Print the current path
		for (int i = 0; i <= M; i++) {
			for (int j = 0; j <= N; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}
	// rat should remain inside the maze
	if (i > M or j > N) {
		return false;
	}
	// the path of the rat should not be blocked
	if (maze[i][j] == 'X') {
		return false;
	}

	soln[i][j] = 1;

	// recursive case
	bool rightSuccess = paths(maze, soln, M, N, i, j + 1);
	bool downSuccess = paths(maze, soln, M, N, i + 1, j);

	// While backtracking ,it should explore all paths
	soln[i][j] = 0;

	if (rightSuccess or downSuccess) {
		return true;
	}
	return false;
}

int main() {
	init();
	int M, N;
	M = 4;
	N = 4;
	// X denotes the path is blocked
	char maze[10][10] = {
		"0000",
		"0X00",
		"000X",
		"0X00",
	};
	int soln[10][10] = {0};
	bool res = paths(maze, soln, M - 1, N - 1, 0, 0);

	if (res == false) {
		cout << "Path doesn't exists !" << endl;
	}
	return 0;
}
