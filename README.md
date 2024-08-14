#include<iostream>
using namespace std;
int findFirstZero(int arr[], int n) 
{
    int low = 0, high = n - 1, first_Zero_Index = -1;
    while (low <= high) 
	{
        int mid = low + (high - low) / 2;
        if (arr[mid] == 0) 
		{
            first_Zero_Index = mid;   
            high = mid - 1;         
        } 
		else 
		{
            low = mid + 1;
        }
    }
    return first_Zero_Index; 
}
int count_Zeroes(int arr[], int n)
{
    int first_Zero_Index = findFirstZero(arr, n);
	if (first_Zero_Index == -1) 
	{
        return 0;
    }
    return n - first_Zero_Index;
}
int main() 
{
	int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array (1s followed by 0s): ";
    for (int i = 0; i < n; i++) 
	{
        cin >> arr[i];
    }
    cout << "Number of zeros: " << count_Zeroes(arr, n) << endl;
	return 0;
}
