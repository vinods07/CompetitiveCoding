#include <iostream>
#include <vector>
using namespace std;

//problem is to find the maximum sum of any continuous subarray in an array
//note that if the numbers are negative then maximum sum will be 0

int largest_sum(vector<int> arr, int n){
	int largest_so_far, largest_current= 0;
	for(int i=0;i<n;i++){
		largest_current+= arr[i];

		if(largest_current < 0){
			largest_current= 0;
		}
		else{
			if(largest_current > largest_so_far)
				largest_so_far= largest_current;
		}
	}

	return largest_so_far;
}

int main(){
	int n;cin>>n;
	vector<int> arr(n);

	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<largest_sum(arr, n)<<endl;
}