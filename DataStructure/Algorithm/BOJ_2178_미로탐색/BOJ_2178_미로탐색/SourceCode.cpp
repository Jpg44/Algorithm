#include<iostream>
using namespace std;
void main() 
{
	int height = 0;
	int width = 0;
	cin >> height >> width;
	int **map = new int *[height];
	for (int i = 0;i < height;i++)
	{
		map[i] = new int[width];
	}
	for (int i = 0;i < height;i++)
	{
		delete[] map[i];
	}
	delete[]map;
}