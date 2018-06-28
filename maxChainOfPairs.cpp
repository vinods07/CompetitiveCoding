#include <iostream>
#include <vector>
using namespace std;

//given n pairs (a,b) -- a is always < b of numbers find the maximum subsequence of the pairs such that
//if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }, 
//then the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}

int max_len(vector<int> first, vector<int> second, int n){
	vector<int> temp(n);
	for(int i=0;i<n;i++){
		temp[i]=1;
		for(int j=0;j<i;j++){
			if(second[j]<first[i] && temp[j]+1>temp[i]){
				temp[i]= temp[j]+1;
			}
		}
	}
	int maximum= 0;
	for(int i=0;i<n;i++){
		if(temp[i]>maximum)
			maximum= temp[i];
	}

	return maximum;
}

int main(){
	int n;cin>>n;
	vector<int> first(n);
	vector<int> second(n);

	for(int i=0;i<n;i++){
		cin>>first[i]>>second[i];
	}

	cout<<max_len(first, second, n)<<endl;
}