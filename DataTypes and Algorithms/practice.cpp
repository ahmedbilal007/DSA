#include <iostream>
#include <vector>

using namespace std;

// Finding maximum sub-array sum
int maxSubArrSum(vector<int> nums){
    int maxSum = INT_MIN;
    for (int i=0; i<nums.size()-1; i++){
        int currentSum = 0;
        for (int j=i; j<nums.size()-1; j++){
            currentSum += nums[j];
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}

// Finding maximum Sub Array sum using Kadane's Algorithm
int kadaneAlgo(vector<int> nums){
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i=0; i<nums.size(); i++){
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}


int main(){
    vector<int> nums = {1,2,3,-4,7,3,7,-3,9};
    cout << "Maximum Sub Array Sum: " << maxSubArrSum(nums) << endl;    
    cout << "Maximum Sub Array Sum using Kadane's Algorithm: " << kadaneAlgo(nums) << endl;
    return 0;
}