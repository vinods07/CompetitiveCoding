#include <iostream>
#include <vector>
#include <ctime>
#include <map>
using namespace std;

int fib(int n, map<int, int> &mp){
	if(mp[n]!=0)
		return mp[n];
	else{
		mp[n]=fib(n-1, mp)+fib(n-2, mp);
		return mp[n];
	}
}

int fib2(int n){
	if(n==0 || n==1)
		return 1;
	else
		return fib2(n-1)+fib2(n-2);
}

int main(){
	map<int, int> mp;
	mp[0]=1;
	mp[1]=1;
	clock_t start=clock();
	cout<<fib(42, mp)<<endl;
	clock_t end = clock();
	cout<<"time taken for 40th fib number with memoization:- "<<float( end - start ) /  CLOCKS_PER_SEC<<endl<<endl;

	start = clock();
	cout<<fib2(42)<<endl;
	end = clock();
	cout<<"time taken for 40th fib number without memoization:- "<<float( end - start ) /  CLOCKS_PER_SEC<<endl;
}