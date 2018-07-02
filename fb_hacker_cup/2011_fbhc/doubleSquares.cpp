#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int a){
	double temp= sqrt(a);
	return (temp- floor(temp)==0);
}

int doubleSquares(int a){
	int count=0;

	int start= 0;
	int begin= start*start;
	while(a-begin >= begin){
		if(begin<=a && isPerfectSquare(a-begin))
			count++;

		start++;
		begin= start*start;
	}

	return count;
}

int main(){
	int n;cin>>n;
	//int count=1;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		cout<<doubleSquares(a)<<endl;
		//count++;
	}
}