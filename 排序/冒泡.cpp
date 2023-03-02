#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		bool changed = false;
		for (size_t j = 0; j < arr.size() - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				changed = true;
			}
		}
//		cout << "Count: " << i << "  ->";
//		for (size_t k = 0; k < arr.size(); k++)
//		{
//			cout << arr[k] << "  ";
//		}
//		cout << endl;
		if (!changed)
		{
			break;
		}
	}
}

int main()
{
	cout << "输入数字数组长度:";
	int length = 0;
	cin >> length;
	cout << "\n输入数字:" << endl;
	vector<int> arr = vector<int>(length);
	for (int i = 0; i < length; i++)
	{
		cin >> arr[i];
	}
	BubbleSort(arr);
	
	cout << "Result: ";
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	
}
