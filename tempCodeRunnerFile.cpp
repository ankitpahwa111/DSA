#include <iostream>
using namespace std;
int subset(int input[], int n, int output[][20])
{
	// Write your code here
	if (n == 0)
	{
		output[0][0] = 0;
		return 1;
	}
	int res = subset(input + 1, n - 1, output);
	for (int i = 0, k = 0; i < res; i++)
	{
		int len = output[i][0];
		output[i + res][0] = output[i][0] + 1;
		output[i + res][1] = *input;
		for (int j = 1; j <= output[i][0]; j++)
		{
			output[i + res][j + 1] = output[i][j];
		}
	}
	return 2 * res;
}

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		int input[20], length, output[35000][20];
		cin >> length;
		for (int i = 0; i < length; i++)
			cin >> input[i];
		int size = subset(input, length, output);
		bool flag = 0;
		for (int i = 0; i < size; i++)
		{
			int sum = 0;
			for (int j = 1; j <= output[i][0]; j++)
			{
				cout<<output[i][j]<<" ";
				sum += output[i][j];
			}
			cout<<endl;
			if (sum == 0)
			{
				cout << "YES";
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "NO";
	}
}
