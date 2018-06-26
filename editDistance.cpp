#include <iostream>
#include <string>
using namespace std;

int min(int a, int b, int c){
	if(a<=b && a<=c)
		return a;
	else{
		if(b<=a && b<=c)
			return b;
		else return c;
	}
}

void editDist(string str1, string str2){
	int str1_length= str1.length();
	int str2_length= str2.length();

	int** arr= new int*[str1_length+1];
	for(int i=0;i<=str1_length;i++){
		arr[i]= new int[str2_length+1];
		arr[i][0]=i;
		arr[0][i]=i;
	}

	for(int i=1;i<=str1_length;i++){
		for(int j=1;j<=str2_length;j++){
			if(str1[i]==str2[j]){
				arr[i][j]= arr[i-1][j-1];
			}
			else{
				arr[i][j]= min(arr[i-1][j], arr[i][j-1], arr[i-1][j-1])+1;
			}
		}
	}

	cout<<"edit distance is:- "<< arr[str1_length][str2_length]<<endl;
}

int main(){
	string a,b;cin>>a>>b;
	editDist(a,b);
}