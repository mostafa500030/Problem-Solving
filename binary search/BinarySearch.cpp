#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[10] = { 2,5,3,7,8,4,1,6,10,9 };
	sort(arr, arr + 10);
	int start = 0, end = 9, mid, find;
	cin >> find;
	bool isExist = false;
	while (start <= end&&!isExist)
	{
		cout << "here";
		mid = (start + end) / 2;
		cout << mid << endl;
		if (arr[mid] > find)
		{
			end = mid - 1;
		}
		else if (arr[mid] < find)
		{
			start = mid + 1;
		}
		else
		{
			isExist = true;
		}
	}
	if (isExist)
	{
		cout << find << " is exist\n";
	}
	else
	{
		cout << find << " is not exist\n";
	}
}
