#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

	int border[21][21] = {0};
	int res[21][21] = { 0 };
	int mx, my, hx, hy;long long cou = 0;
	void dp(int x,int y);
int main() {
	scanf("%d %d %d %d", &my, &mx, &hy, &hx);
	border[hx][hy] = 1;
	if (hy>=2)
	{
		if (hx - 1 >= 0)border[hx-1][hy - 2] = 1;
		if (hx + 1 <= mx)border[hx+1][hy-2] = 1;
	}
	if (hy>=1)
	{
		if (hx - 2 >= 0)border[hx - 2][hy - 1] = 1;
		if (hx + 2 <= mx)border[hx + 2][hy - 1] = 1;
	}	
	if (hy+2<=my)
	{
		if (hx -1 >= 0)border[hx - 1][hy +2] = 1;
		if (hx + 1 <= mx)border[hx +1][hy +2] = 1;

	}
	if (hy+1<=my)
	{
		if (hx -2 >= 0)border[hx - 2][hy + 1] = 1;
		if (hx + 2 <= mx)border[hx +2][hy + 1] = 1;

	}
	dp(mx,my);
	printf("%lld\n", cou);
	return 0;
}
void dp(int x,int y) {
	if (x == 0&&y == 0)
	{
		cou++;
		return;
	}
	if (x == 0&&border[x][y-1]||(x-1>=0&&y-1>=0&&border[x-1][y]&&border[x][y-1]) || (y == 0 && border[x - 1][y]))
	{
		border[x][y] = 1;
		return;
	}
	if (x-1>=0&&!border[x-1][y])
	{
		dp(x - 1, y);
	}
	if (y-1>=0&&!border[x][y-1])
	{
		dp(x, y - 1);
	}
	
}