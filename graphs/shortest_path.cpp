#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class adjacency_node{
public:
	int value;
	adjacency_node* next;
};

int min_dist(int a, int b, adjacency_node** graph, int n){
	int* shortest= new int(n);
	bool* visited= new bool(n);

	for(int i=0;i<n;i++){
		if(i==a){
			shortest[i]= 0;
			visited[i]= true;
		}
		else{
			shortest[i]= INT_MAX;
			visited[i]= false;
		}
	}

	queue<adjacency_node*> q;

	q.push(graph[a]);
	while(!q.empty()){
		adjacency_node* iter= q.front();

		q.pop();
		int shortest_so_far= shortest[iter->value];
		while(iter!=NULL){
			if(!visited[iter->value]){
				shortest[iter->value]= shortest_so_far+1;
				visited[iter->value]= true;
				q.push(graph[iter->value]);
			}
			else{
				if(shortest_so_far+1 < shortest[iter->value])
					shortest[iter->value]= shortest_so_far+1;

			}
			iter= iter->next;
		}

	}

	return shortest[b];
}

int main(){
	int n;cin>>n;	//number of nodes in the graph numbered 0 to n-1
	adjacency_node** graph= new adjacency_node*[n];

	for(int i=0;i<n;i++){
		graph[i]= new adjacency_node;
		graph[i]->value= i;
		graph[i]->next= NULL;
	}
	int m;cin>>m;	//number of edges
	while(m--){
		int a;int b;cin>>a>>b;
		if(a>=0 && a<n && b>=0 && b<n){
			adjacency_node* temp1= graph[a];
			bool is_already= false;
			while(temp1->next!=NULL){
				if(temp1->next->value==b){
					is_already= true;
					break;
				}
				else
					temp1= temp1->next;
			}
			if(!is_already){
				adjacency_node* temp2= new adjacency_node;
				temp2->value = b;
				temp2->next= NULL;

				temp1->next= temp2;
			}

			temp1= graph[b];
			is_already= false;
			while(temp1->next!=NULL){
				if(temp1->next->value==a){
					is_already= true;
					break;
				}
				else
					temp1= temp1->next;
			}
			if(!is_already){
				adjacency_node* temp2= new adjacency_node;
				temp2->value = a;
				temp2->next= NULL;

				temp1->next= temp2;
			}
		}
	}
	for(int i=0;i<n;i++){
		adjacency_node* iter= graph[i];
		while(iter!=NULL){
			cout<<iter->value<<"->";
			iter= iter->next;
		}
		cout<<endl;
	}
	while(true){
		cout<<"Enter two vertices a and b to get min dist(enter -1 to exit): ";
		int a;cin>>a;if(a==-1) break;
		int b;cin>>b;
		cout<<min_dist(a, b, graph, n)<<endl;
	}
	
}