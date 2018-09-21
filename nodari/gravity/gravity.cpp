/**
 * You can treat each column as it's own puzzle - all columns are independent 
 * of each other.
 * 
 * With that being said, I think the best way to go about this is to just 
 * iterate twice. Once to get the amount of apples and the obstacle, and 
 * the second iteration to print the column. This should then be O(n^2) runtime.
 * 
 * 
 * Lessons Learned:
 * When using 2D array, be very VERY careful about rows and columns. Be careful
 * to the point where if you're not 100% on it, just write it out. It'll save 
 * lots of time.
 * 
 * It took way to long to implement this. I don't know if it's a result of me not 
 * being that good at cpp, or the fact that this actually does take a while to 
 * implement.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print2DArray();

int main()
{
	int column, row;
	cin >> row >> column;

	char data[column][row];
	char data1[column][row];

	string temp;
	int x = 0;

	// add data to data
	cin.ignore();
	while (x < row)
	{
		getline(cin, temp);
		for (int i = 0; i < column; i++)
		{
			data[x][i] = temp[i];
		}
		x += 1;
	}

	// sort by row, and put to data1
	for (int i = 0; i < column; i++)
	{
		// get # of apples and where obstacle is
		int apple = 0;
		int obstacle = -1;
		for (int j = 0; j < row; j++)
		{
			if (data[j][i] == 'o')
			{
				apple += 1;
			}
			else if (data[j][i] == '#')
			{
				obstacle = j;
			}
		}

		// plug into new 2D arrayfrom bottom row going up.
		for (int j = row - 1; j >= 0; j--)
		{
			if (j == obstacle)
			{
				data1[j][i] = '#';
			}
			else if (apple != 0)
			{
				data1[j][i] = 'o';
				apple -= 1;
			}
			else
			{
				data1[j][i] = '.';
			}
		}
	}

	// print data
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << data1[i][j];
		}
		cout << endl;
	}
}
