#include "ByteDance.h"



int st[100][100][100][100];
int x, y, bx, by, tx, ty;
int m, n;
vector<vector<char>> mm;

bool valid(int x, int y) {
	if (x >= 0 && x < m && y >= 0 && y < n && mm[x][y] != '#')return true;
	return false;
}

int ByteDancePushBox() 
{

	cin >> m >> n;
	mm = vector<vector<char>>(m, vector<char>(n));

	for (int i = 0; i < m; i++)
	for (int j = 0; j < n; j++) 
	{
		char t;
		cin >> t;
		if (t == 'S') 
		{
			x = i;
			y = j;
			// cout <<x<<" "<<y<<endl;
		}
		if (t == '0') 
		{
			bx = i;
			by = j;
		}
		if (t == 'E') 
		{
			tx = i;
			ty = j;
		}
		mm[i][j] = t;
	}

	vector<vector<int>> next = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
	queue<vector<int>> que;
	que.push({ x, y, bx, by });

	st[x][y][bx][by] = 1;
	while (!que.empty())
	{
		vector<int> t = (vector<int> &&) que.front();
		que.pop();
		x = t[0];
		y = t[1];
		bx = t[2];
		by = t[3];
		for (int i = 0; i < next.size(); i++) 
		{
			int nx = x + next[i][0], ny = y + next[i][1];
			int nnx = nx + next[i][0], nny = ny + next[i][1];
			if (valid(nx, ny) && (nx != bx || ny != by) && st[nx][ny][bx][by] == 0) 
			{
				st[nx][ny][bx][by] = st[x][y][bx][by] + 1;
				que.push({ nx, ny, bx, by });
				continue;
			}
			else if (nx == bx && ny == by && valid(nnx, nny) && st[nx][ny][nnx][nny] == 0) 
			{
				st[nx][ny][nnx][nny] = st[x][y][bx][by] + 1;
				if (mm[nnx][nny] == 'E') 
				{
					cout << st[nx][ny][nnx][nny] - 1;
					return 0;
				}
				que.push({ nx, ny, nnx, nny });
			}
		}
	}

	cout << -1;
	return 0;
}


//http://www.cnblogs.com/grandyang/p/5487815.html
int maxSubmatrixSum(std::vector<std::vector<int>>matrix, int n, int m)
{
	int base_sum = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			base_sum += matrix[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i<matrix.size(); i++)
	{
		if (i>0)
		{
			for (int y = 0; y<m; y++)
			{
				base_sum += matrix[i][y] - matrix[i - 1][y];
			}
		}
		int real_sum = base_sum;
		if (real_sum>result)
		{
			result = real_sum;
		}
		for (int j = 1; j<matrix.size(); j++)
		{
			for (int x = 0; x<n; x++)
			{
				real_sum += matrix[x][j] - matrix[x][j - 1];
			}
			if (real_sum>result)
			{
				result = real_sum;
			}
		}
	}
	return result;
}

int MaxSubArraySum_2(const vector<int> &arr)
{
	int n = arr.size();
	if (n == 0)
	{
		return 0;
	}
	int CurSum = 0;
	int max = 0x80000000;
	//vector<int> maxSub(n);
	//maxSub[0] = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (CurSum <= 0)
		{
			CurSum = arr[i];
		}
		else
		{
			CurSum += arr[i];
		}
		if (CurSum > max)
		{
			max = CurSum;
		}
	}
	return max;
}

int maxSubmatrixSum(const vector<vector<int>> &arr)
{
	int m = arr.size();
	int n = arr[0].size();
	vector<vector<int>> total(m, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		total[0][i] = arr[0][i];
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			total[i][j] = total[i - 1][j] + arr[i][j];
		}
	}
	int max = 0x8000;
	vector<int> result(n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int f = 0; f < n; f++)
			{
				if (i == 0)
				{
					result[f] = total[j][f];
				}
				else
				{
					result[f] = total[j][f] - total[i - 1][f];
				}
			}
			int maximal = MaxSubArraySum_2(result);
			if (maximal > max)
			{
				max = maximal;
			}
		}
	}
	return max;
}

int ByteDanceMain()
{
	vector<vector<int>> mat = { { 0, -2, -7, 2 }, { 9, 2, -6, 2 }, { -4, 1, -4, 1 }, { -1, 8, 0, -2 } };
	vector<vector<int>> matrix = { { 1, 2, -3 }, { 4, 5, -6 }, { -5, -6, -7 } };
	//cout << maxSubmatrixSum(matrix, 3, 3) << endl;
	cout << maxSubmatrixSum(matrix) << endl;
	/*
	*.S#..E
	*.#.0..
	*......
	*/
	ByteDancePushBox();
	return RET_OK;
}