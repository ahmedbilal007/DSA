#include <iostream>
#include <vector>
using namespace std;
vector<int> bruteApproach(vector<int> nums){
	// Time Complexity O(n^2)
	// Space Complexity O(1) ---> Single variable 'product' is being declared inside the function

	int sz = nums.size();
	vector<int> ans(sz, 1);
	for (int i=0; i<sz; i++){
		for (int j=0; j<sz; j++){
			if (i!=j)
				ans[i] *= nums[j];
		}
	}
	return ans;
}

vector<int> optimalApproach(vector<int> nums){
	// Time Complexity O(n)
	// Space Complexity O(n) // can be optimized...
	// 2 extra vectors are being declared of 'n' size, That's why its time complexity is O(n)

	int sz = nums.size();
	vector<int> answer(sz, 1);
	vector<int> prefix(sz, 1);
	vector<int> suffix(sz, 1);

	for (int i=1; i<sz; i++)
		prefix[i] = prefix[i-1] * nums[i-1];

	for (int i=sz-2; i>=0; i--)
		suffix[i] = suffix[i+1] * nums[i+1];

	for (int i=0; i<sz; i++)
		answer[i] = prefix[i] * suffix[i];
	return answer;
}

vector<int> spaceOptimized(vector<int> nums){
	// Time Complexity -> O(n)
	// Space Complexity -> O(1) ---> Only a single variable "suffix" is being declared inside the function.
	// Answer-vector is not included in the space complexity
	int sz = nums.size();
	vector<int> answer(sz, 1);

	for (int i=1; i<sz; i++){
		answer[i] = answer[i-1] * nums[i-1];
	}
	int suffix = 1;
	for (int i=sz-2; i>=0; i--){
		suffix *= nums[i+1];
		answer[i] *= suffix;
		}
	return answer;
}


int main(){
	vector<int>nums = {1,2,3,4};
	vector<int>answer = bruteApproach(nums);
	vector<int>answer2 = optimalApproach(nums);
	vector<int>answer3 = spaceOptimized(nums);
	for (int v : answer)
		cout << v << " ";
	cout << endl;
	for (int v : answer2)
		cout << v << " ";
	cout << endl;
	for (int v : answer3)
		cout << v << " ";



	return 0;
}
