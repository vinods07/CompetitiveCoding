#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class joint{
public:
	int num;
	int len;
};


int largestRectangle(vector<int> arr, int n){
	stack<joint*> s;
	stack<joint*> s2;
	int curr_max=0;
	for(int i=0;i<n;i++){
		if(s.empty()){
			joint* temp= new joint;
			temp->num = arr[i];
			temp->len = 1;
			s.push(temp);
		}
		else{
			if(arr[i]>= s.top()->num){
				joint* temp= new joint;
				temp->num = arr[i];
				temp->len = 1;
				s.push(temp);
				s2=s;
				int curr_len2=0;
				while(!s2.empty()){
					curr_len2+=s2.top()->len;
					if(curr_len2* s2.top()->num > curr_max)
						curr_max= curr_len2* s2.top()->num;
					s2.pop();
				}
			}
			else{
				int curr_len=1;
				while(!s.empty() and s.top()->num >= arr[i]){
					curr_len+=s.top()->len;s.pop();
				}
				if(arr[i]*curr_len > curr_max)
					curr_max = arr[i]*curr_len;
				joint* temp= new joint;
				temp->num= arr[i];
				temp->len = curr_len;
				s.push(temp);
				
				s2=s;
				int curr_len2=0;
				while(!s2.empty()){
					curr_len2+=s2.top()->len;
					if(curr_len2* s2.top()->num > curr_max)
						curr_max= curr_len2* s2.top()->num;
					s2.pop();
				}
			}
		}
	}
	if(!s.empty()){
		int curr_len=0;
		while(!s.empty()){
			curr_len+=s.top()->len;
			if(s.top()->num * curr_len > curr_max)
				curr_max = s.top()->num*curr_len;
			s.pop();
		}
	}
	return curr_max;
}

int main(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		int temp;cin>>temp;
		arr[i]=temp;
	}
	int a=largestRectangle(arr, n);
	cout<<a<<endl;
}