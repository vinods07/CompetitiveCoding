#include <iostream>
#include <vector>
using namespace std;

int lia(vector<int> arr, int n){
	int max_len= 0;
	vector<int> temp(n);
	for(int i=0;i<n;i++){
		temp[i]=1;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && temp[j]+1>temp[i]){
				temp[i]=temp[j]+1;
			}
		}
		//cout<<temp[i]<<endl;
		if(temp[i]>max_len)
			max_len= temp[i];
	}

	return max_len;
}

int main(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<lia(arr, n)<<endl;
}