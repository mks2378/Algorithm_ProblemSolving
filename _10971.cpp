#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, start;
int Total=999999999;
int city[10][10];
bool visited[10];
vector<int> cost;

//그래프를 순회하려면 기본적인 전제가 순회 여행 경로 중   
//어느 하나 간선 비용이 0이 아니어야 한다.(0이면 갈 수 없다.)
//문제의 조건을 정확히 파악하지 못하여 해결하지 못함  
void dfs(int cnt,int prev_idx,int cur_idx){
	if(cnt==N-2){		
		int sum=0;
		
		if(city[cur_idx][start]==0)
			return;
		
		for(int i=0;i<cost.size();i++)
			sum+=cost[i];
		sum+=city[cur_idx][start];
		
		Total = min(Total, sum);
		return;
	}
	
	for(int i=0;i<N;i++){
		if(!visited[i]&&city[cur_idx][i]!=0){
			visited[i] = true;
			cost.push_back(city[cur_idx][i]);
			dfs(cnt+1,cur_idx,i);
			cost.pop_back();
			visited[i] = false;
		}		
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>city[i][j];
	
	for(int i=0;i<N;i++){
		start = i;
		visited[i] = true;
		for(int j=0;j<N;j++){
			if(i!=j&&city[i][j]!=0){
				visited[j] = true;
				cost.push_back(city[i][j]);	
				dfs(0,i,j);
				cost.pop_back();
				visited[j] = false;
			}
		}
		visited[i] = false;
	}
	
	cout<<Total;
	return 0;
}
