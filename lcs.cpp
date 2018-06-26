#include <iostream>
#include <string>
#include <vector>
using namespace std;
//given two strings what is the length of the longest common subsequence

int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

void lcs(string s1, string s2){
	int s1_len= s1.length();
	int s2_len= s2.length();

	int** arr=new int*[s1_len+1];
	for(int i=0;i<=s1_len;i++){
		arr[i]= new int[s2_len+1];
	}

	for(int i=1;i<=s1_len;i++){
		for(int j=1;j<=s2_len;j++){
			if(s1[i-1]==s2[j-1]){
				arr[i][j]=arr[i-1][j-1]+1;
			}
			else
				arr[i][j]= max(arr[i-1][j], arr[i][j-1]);
		}
	}

	cout<<arr[s1_len][s2_len]<<endl;

}

int main(){
	string a,b;cin>>a>>b;

	lcs(a, b);	
}