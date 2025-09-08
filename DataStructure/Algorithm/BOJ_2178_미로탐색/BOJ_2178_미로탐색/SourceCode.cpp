#include<iostream>
#include<vector>
using namespace std;
int best;
void inputMap(int h, int w, auto&& at)//Dynamic Allocation
{
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			char ch; cin >> ch;
			at(i, j,0) = ch - '0';
		}
	}

}

void outputMap(int h, int w, auto&& at)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << at(i, j,1) ;
		}
		cout << endl;
	}
	cout << endl;
}
void searchRoad(int x, int y, int walk, int min, auto&& at, int lastX, int lastY)
{
	
	if (x == lastX && y == lastY)
	{
		if (walk < best)
		{
			best = walk;
		}
		return;
	}
		if ( at(x, y, 1) != 0&&at(x, y, 1) <= walk)
		{
			return;
		}
		if (x < lastX && at(x + 1, y,0) == 1 )
		{
			at(x, y,1) = walk;
			searchRoad(x + 1, y, walk+1 , min, at, lastX, lastY);
		}
		if (x > 0 &&  at(x - 1, y,0) == 1)
		{
			at(x, y,1) = walk;
			searchRoad(x - 1, y, walk+1 , min, at, lastX, lastY);
		}
		if (y < lastY &&  at(x, y + 1,0) == 1)
		{
			at(x, y,1) = walk;
			searchRoad(x, y + 1, walk+1, min, at, lastX, lastY);
		}
		if (y  > 0 &&  at(x, y - 1,0) == 1)
		{
			at(x, y,1) = walk;
			searchRoad(x, y - 1, walk+1, min, at, lastX, lastY);
		}
	
	return;
}

int main() //DFS
{
	int height = 0;
	int width = 0;
	int lev = 2;
	int min = 0;
	best = 10000;
	cin >> height >> width;
	min = height*width;
	vector<int> buf(height * width*lev, 0);
	auto at = [&](int x, int y,int z) -> int& { return buf[(size_t)x*width*lev+(size_t)y * lev + z]; };
	inputMap(height, width, at);
	if (at(0, 0,0) == 1 && at(height-1, width-1,0) == 1)
	{
		searchRoad(0, 0, 1, min, at, height - 1, width - 1);
	}
	cout << best;
	return 0;
}