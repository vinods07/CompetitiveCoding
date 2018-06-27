#include <iostream>
#include <vector>
using namespace std;

//bitonic seq first increases and then decreases
//we need to find maximum length of such subsequence in an array

int lbs(vector<int> arr, int n){
	vector<int> lis(n);
	vector<int> lds(n);
	for(int i=0;i<n;i++){
		lis[i]=1;
		lds[i]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>= arr[j] && lis[j]+1>lis[i]){
				lis[i]=lis[j]+1;
			}
			if(arr[i]<=arr[j] && lds[j]+1>lds[i]){
				lds[i]=lds[j]+1;
			}
		}
	}
	int max_num=0;
	for(int i=0;i<n;i++){
		int temp= lis[i]+lds[i]-1;
		if(temp>max_num)
			max_num=temp;
	}

	return max_num;
}

int main(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<lbs(arr, n)<<endl;
}