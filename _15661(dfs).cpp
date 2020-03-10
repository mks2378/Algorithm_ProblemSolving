#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int arr[21][21];
bool visited[21];
int total;

int N;
int result = 987654321;

void dfs(int cnt,int idx){
	if(cnt==total){
		vector<int> v1, v2;
		int sum1=0, sum2=0;
		
		for(int i=1;i<=N;i++){
			if(visited[i])
				v1.push_back(i);
			else
				v2.push_back(i);
		}
		
		for(int i=0;i<v1.size()-1;i++)
			for(int j=i+1;j<v1.size();j++){
				sum1+=arr[v1[i]][v1[j]];
				sum1+=arr[v1[j]][v1[i]];
			}
			
		for(int i=0;i<v2.size()-1;i++)
			for(int j=i+1;j<v2.size();j++){
				sum2+=arr[v2[i]][v2[j]];
				sum2+=arr[v2[j]][v2[i]];
			}
			
		result = min(result,abs(sum1-sum2));
	}
	
	for(int i=idx;i<=N;i++){
		if(!visited[i]){
			visited[i] = true;
			dfs(cnt+1,i+1);
			visited[i] = false;		
		}
	}
}

int main(){
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>arr[i][j];
			
	for(total=1;total<=N/2;total++)
		dfs(0,1);
	
	cout<<result;
	
	return 0;
}
