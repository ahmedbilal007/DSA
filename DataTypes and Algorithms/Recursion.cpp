#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printNumbers(int n){	// printing numbers in reverse order using recursion
	if (n == 1){
		cout << n << endl;
		return;
	}
	cout << n << " ";
	printNumbers(n-1);
}

int factorial(int n){		// factorial of a number
	if (n==0) return 1;
	return n * factorial(n-1);
}

int sum(int n){				// calculating sum of n numbers
	if (n == 1) return 1;
	return n + sum(n-1);
}

int fibonacci(int n){
	if (n==0 || n==1)
		return n;
	return fibonacci(n-1) + fibonacci(n-2);
}


bool isSorted(int arr[], int n){
	if (n==0 || n==1)
		return true;
	return ((arr[n-1] >= arr[n-2]) && isSorted(arr, n-1));
}

void printSubsets(vector<int> arr, vector<int>& ans, int i){
	if (i == arr.size())
	{
		for (int v : ans)
			cout << v << " ";
		cout << endl;
		return;
	}
	ans.push_back(arr[i]);
	printSubsets(arr, ans, i+1);
	ans.pop_back();
	printSubsets(arr, ans, i+1);
}

void getAllSubsets(vector<int>&nums, vector<int>& ans, int i, vector<vector<int>>& allSub){
	if (i==nums.size()){
		allSub.push_back({ans});
		return;
	}
	ans.push_back(nums[i]);
	getAllSubsets(nums, ans, i+1, allSub);
	ans.pop_back();
	getAllSubsets(nums, ans, i+1, allSub);
}

vector<vector<int>> allSubsets(vector<int> nums){
	vector<vector<int>> allSubsets;
	vector<int> ans;
	getAllSubsets(nums, ans, 0, allSubsets);
	return allSubsets;
}

void duplicateSubsets(vector<int>&nums, vector<int>&ans, int i){
	sort(nums.begin(), nums.end());
	if (i==nums.size())
	{
		for (int val : ans)
			cout << val << " ";
		cout << endl;
		return;
	}

	ans.push_back(nums[i]);
	duplicateSubsets(nums, ans, i+1);
	ans.pop_back();
	int idx = i+1;
	while(idx < nums.size() && nums[idx] == nums[idx- 1])
		idx++;
	duplicateSubsets(nums, ans, idx);
}






int main(){
	cout << "---Recursion---" << endl;
	int arr[] = {1,2,3,4,5,4};
	vector<int> nums = {1,2,3};
	vector<int> subsets;
	vector<int> nums2 = {1,2,2};
	int n = 6;
//	printNumbers(4);
//	cout << "Factorial: " << factorial(5) << endl;
//	cout << "Sum: " << sum(5) << endl;
//	cout << "Fibonacci: " << fibonacci(6) << endl;
//	cout << "Is Array Sorted: " << isSorted(arr, n) << endl;
//	cout << "Subsets of Array:\n";
//	printSubsets(nums, subsets, 0);
//	cout << endl << endl;
//	vector<vector<int>> answers = allSubsets(nums);
//	for (vector v : answers){
//		for (int e : v)
//			cout << e  << " ";
//		cout << endl;
//	}
	duplicateSubsets(nums2, subsets, 0);
	return 0;
}
