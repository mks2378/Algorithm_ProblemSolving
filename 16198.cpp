#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10

int N, result, total;
bool visited[MAX];
int circle[MAX];

int GetNextRight(int idx){
	if(visited[idx])
		return GetNextRight(idx+1);
	else
		return circle[idx];
}

int GetNextLeft(int idx){
	if(visited[idx])
		return GetNextLeft(idx-1);
	else
		return circle[idx];	
	
}

void dfs(int cnt){
	if(cnt==N-2){
		total = max(total, result);
		return;	
	}
	
	for(int i=1;i<N-1;i++){
		if(!visited[i]){
			visited[i] = true;
			int w_left = GetNextLeft(i-1);
			int w_right = GetNextRight(i+1);
			result+=(w_left*w_right);
			
			dfs(cnt+1);
			visited[i] = false;
			result-=(w_left*w_right);
		}		
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>circle[i];
		
	dfs(0);
	cout<<total;

	return 0;
}
