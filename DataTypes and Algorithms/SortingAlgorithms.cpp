#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(int nums[], int n){
	for (int i=0; i<n; i++)
		cout << nums[i] << " ";
	cout << endl;
}

void bubbleSort(int nums[], int n){
	// Time Complexity --> O(n^2)

	for (int i=0; i<n-1; i++){	// n times

		bool isSwap = false;
		for (int j=0; j<n-i-1; j++){  // n times
			if (nums[j]>nums[j+1]){
				swap(nums[j], nums[j+1]);
				isSwap = true;
			}
		}

		if (!isSwap) return;
	}
}

void selectionSort(int nums[], int n){
	// Time Complexity --> O(n^2)

	for (int i=0; i<n-1; i++){
		int small = i;			// starting index of unsorted part
		for (int j=i+1; j<n; j++){
			if (nums[j]<nums[small])
				small = j;
		}
		swap(nums[i], nums[small]);
	}
}

void insertionSort(int nums[], int n){
	// Time Complexity --> O(n^2)

	for (int i=1; i<n; i++){
		int curr = nums[i];
		int prev = i - 1;
		while (prev >= 0 && nums[prev] > curr){
			nums[prev+1] = nums[prev];
			prev--;
		}
		nums[prev+1] = curr;
	}
}


int main(){
	int nums[] = {11,4,35,22,21,87,16};
	int n = 7;
//	bubbleSort(nums, n);
//	selectionSort(nums, n);
	insertionSort(nums, n);
//	cout << "Array after Bubble Sort: " << endl;
//	printArray(nums, n);
//	cout << "Array after Selection Sort: " << endl;
//	printArray(nums, n);
	cout << "Array after Insertion Sort: " << endl;
	printArray(nums,n);
	return 0;
}
