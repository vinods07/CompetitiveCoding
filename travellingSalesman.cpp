#include <bits/stdc++.h>
using namespace std;
//given set of n cities and distance between each of them find the distance of each city from the source
#define v 4	//number of vertices

int min_dist(int distances[][v], int source){
	vector<int> vertices(v);
	for(int i=0;i<v;i++)
		if(i!=source)
			vertices.push_back(i);

	int min_path_dist= INT_MAX;
	do{
		int curr_pathweight=0;
		int k=source;
		for(int i=0;i<vertices.size();i++){
			curr_pathweight+= distances[k][vertices[i]];
			k= vertices[i];
		}
		curr_pathweight+= distances[k][source];
		min_path_dist= min(curr_pathweight, min_path_dist);
	}while(next_permutation(vertices.begin(), vertices.end()));

	return min_path_dist;
}

int main(){
	int distances[][v]= { 	{ 0, 10, 15, 20 },
                			{ 10, 0, 35, 25 },
                			{ 15, 35, 0, 30 },
                			{ 20, 25, 30, 0 } };

    cout<<min_dist(distances, 0)<<endl;
}