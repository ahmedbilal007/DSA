#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
// Checking a prime number
string isprime(int n){
	for (int i=2;i*i<=n;i++){
		if (n%i==0) return "Not-Prime";
	}
	return "Prime";
}

// Counting prime numbers in a given range using
// Sieve of Eratosthenes

int countPrime(int n){
	vector<bool> isPrime(n+1, true);
	int total = 0;
	for (int i=2; i<n; i++){
		if (isPrime[i]){
			total++;
			for (int j=i*2; j<n; j+=i){
				isPrime[j] = false;
			}
		}
	}
	return total;
}

// Counting digits in a number
int countDigits(int n){
	int count;
	while (n!=0) {
		int digit = n % 10;
		count++;
		n /= 10;
	}
	return count;
}

// Checking whether a number is Armstrong or not
	// A number is Armstrong if it is equal to the sum of cubes of its digits
bool isArmstrong(int n) {
	int copyN = n;
	int sumOfDigits = 0;
	while (n!=0){
		int digit = n % 10;
		sumOfDigits += pow(digit,3);
		n/=10;
	}
	return sumOfDigits == copyN;
}

// Finding the Greatest Common Divisor of 2 numbers
int gcd(int a, int b){
	int gcd = 1;
	if (a == 0) return b;
	if (b == 0) return a;
	if (a == b) return a;
	for (int i = 1; i <= min(a,b); i++) {
		if ((a % i == 0) && (b % i ==0)) {
			gcd = i;
		}
	}
	return gcd;
}

// Finding the greatest common divisor using euclid algorithms
int euclid(int a, int b) {
	while (a > 0 && b > 0){
		(a > b) ? a = a % b : b = b % a;
	}
	if (a == 0) return b;
	else return a;
}

// Reversing a number
int reverseNumber(int n){
	int number = 0;
	while (n != 0){
		int dig = n%10;
		if (number > INT_MAX/10 || number < INT_MIN/10) return 0;
		number = number * 10 + dig;
		n = n/10;
	}
	return number;
}

int main(){
	int n;
	int a = 20;
	int b = 28;
	cout << gcd(a,b);
	cout << euclid(a,b);
	cout << reverseNumber(12432);
//	cout << "Enter a number: ";
//	cin >> n;
//	cout << countPrime(n) << endl;
//	cout << countDigits(n) << endl;
//	cout << (isArmstrong(n)? "is Armstrong Number":"Not an Armstrong Number");
	return 0;
}
