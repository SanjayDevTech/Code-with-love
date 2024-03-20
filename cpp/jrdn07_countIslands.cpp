#include<bits/stdc++.h>

using namespace std;

#define ROW 5
#define COL 5


int isSafe(int M[][COL], int row, int col, bool visited[][COL])
{
	return (row >=0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]); 
}


void DFS(int M[][COL], int row, int col, bool visited[][COL])
{
	static int rp[] = {-1,1,0,0};
	static int cp[] = {0,0,-1,1};

	visited[row][col] = true;

	for(int k=0;k<4;k++)
	{
		if(isSafe(M, row + rp[k], col + cp[k], visited))
		{
			DFS(M, row + rp[k], col + cp[k], visited);
		}
	}
}


int countIslands(int M[][COL])
{
	int count=0;
	bool visited[ROW][COL];
	memset(visited, 0, sizeof(visited));

	for(int i=0;i<ROW;++i)
	{
		for(int j=0;j<COL;++j)
		{
			if(M[i][j] && !visited[i][j])
			{
				DFS(M,i,j,visited);
				++count;
				//cout << count << "-" << endl;
			}
		}
	}
	return count;
}


int main()
{
	int M [][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 }};
    cout << countIslands(M) << endl;
	return 0;
}