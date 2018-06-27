#include <iostream>
#include <string>
using namespace std;

//given a string find longest common subsequence(non consecutive) such that it is a palindrome

int max(int a, int b){
	if(a>b)
		return a;
	else return b;
}

int l_palindrome(string str, int** arr, int start, int end){
	if(arr[start][end]!=0)
		return arr[start][end];

	if(str[start]==str[end] and start<end){
		arr[start][end]= l_palindrome(str, arr, start+1, end-1)+2;
		return arr[start][end];
	}
	else if(str[start]!=str[end] and start<end){
		arr[start][end]= max(l_palindrome(str, arr, start, end-1), l_palindrome(str, arr, start+1, end));
		return arr[start][end];
	}
	else if(start==end)
		return 1;
	else
		return 0;
}

int main(){
	string s;cin>>s;
	int len= s.length();
	int **arr= new int*[len];
	for(int i=0;i<len;i++){
		arr[i]= new int[len];
		for(int j=0;j<len;j++)
			arr[i][j]=0;
	}
	
	cout<<l_palindrome(s, arr, 0, len-1)<<endl;
}