#include <iostream>
#include <vector>
#include <map>
using namespace std;
//knapsack problem
//given n weights and their corresponding values
//choose the weights such that total weight< W and total value is max

int max(int a, int b){
	if(a>b)
		return a;
	else return b;
}

int knapsack(int* weights, int* values,int* answers, int n, int w, int curr_w){
	if(n==1){
		return 0;
	}

	if(curr_w+weights[n-1]<=w){
		if(answers[n-1]!=0){
			cout<<answers[n-1]<<" ------------------- \n";
			return answers[n-1];
		}
		else{
			answers[n-1]=max(knapsack(weights, values, answers, n-1, w, curr_w+weights[n-1])+values[n-1], knapsack(weights, values, answers, n-1, w, curr_w));
			cout<<values[n-1]<<" "<<answers[n-1]<<" +++++++++++ \n";
			return answers[n-1];
		}
	}
	else{
		answers[n-1]= knapsack(weights, values, answers, n-1, w, curr_w);
		cout<<values[n-1]<<" "<<answers[n-1]<<" ................ \n";
		return answers[n-1];
	}
}

int main(){
	int n;cin>>n;
	int *weights= new int(n);
	int *values= new int(n);
	int *answers= new int(n);
	int w;cin>>w;
	for(int i=0;i<n;i++){
		cin>>weights[i];
		answers[i]=0;
	}
	for(int i=0;i<n;i++)
		cin>>values[i];

	cout<<knapsack(weights, values, answers, n, w, 0)<<endl;
}