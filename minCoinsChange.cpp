#include <iostream>
#include <limits.h>
#include <vector>
#include <map>
using namespace std;
//Given an anount V and coins change int an array find minimum coins that can be used
//to tender the exact change

//complexity exponential
int min_coins1(vector<int> values, int n, int v){
	if(v==0) return 0;

	int res= INT_MAX;
	for(int i=0;i<n;i++){
		if(values[i]<=v){
			int temp_res= min_coins1(values, n, v-values[i]);
			if(temp_res!= INT_MAX && temp_res+1 < res)
				res= temp_res+1;
		}
	}
	return res;
}

//better way is to use dynamic programming by avoiding overlapping
//we use map to do same(we can use simple array but it will consume space if v is large)
int min_coins2(vector<int> values, int n, int v, map<int, int> &mp){
	if(v==0){
		mp[0]= 0;
		return 0;
	}
	int res= INT_MAX;
	if(mp[v]!=0) return mp[v];
	else
		for(int i=0;i<n;i++){
			if(values[i]<=v){
				int temp_res= min_coins2(values, n, v-values[i], mp);
				if(temp_res!= INT_MAX && temp_res+1 < res){
					mp[v]= temp_res+1;
					res= temp_res+1;
				}
			}
		}
	return res;
}

int main(){
	int n;cin>>n;
	vector<int> values(n);
	for(int i=0;i<n;i++)
		cin>>values[i];
	int v;cin>>v;

	map<int, int> mp;
	cout<<min_coins1(values, n, v)<<endl;
	cout<<min_coins2(values, n, v, mp)<<endl;
}