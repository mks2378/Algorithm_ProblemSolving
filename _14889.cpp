#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, result=987654321;
int arr[20][20];
bool visited[20];

void dfs(int cnt,int idx){
	if(cnt==N/2){
		vector<int> Start, Link;
		int Start_sum=0, Link_sum=0;
		
		for(int i=0;i<N;i++){
			if(visited[i])
				Start.push_back(i);
			else
				Link.push_back(i);
		}
		
		for(int i=0;i<Start.size()-1;i++)
			for(int j=i+1;j<Start.size();j++){
				Start_sum+=arr[Start[i]][Start[j]];
				Start_sum+=arr[Start[j]][Start[i]];
			}
			
		for(int i=0;i<Link.size()-1;i++)
			for(int j=i+1;j<Link.size();j++){
				Link_sum+=arr[Link[i]][Link[j]];
				Link_sum+=arr[Link[j]][Link[i]];
			}
		
		result = min(result,abs(Start_sum-Link_sum));
	}
	
	for(int i=idx;i<N;i++){
		if(!visited[i]){
			visited[i] = true;
			dfs(cnt+1,i+1);
			visited[i] = false;		
		}		
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>arr[i][j];
			
	dfs(0,0);
	cout<<result;
	
	return 0;
}
