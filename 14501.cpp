#include <iostream>
#include <algorithm>
using namespace std;

int result;
int N, sum;

int schedule[15][2];
bool selected[15];

void dfs(int idx){
	if(idx==N){
		result = max(result,sum);
		return;
	}
	for(int i=idx;i<N;i++){
		if(!selected[i]&&i+schedule[i][0]<=N){
			selected[i] = true;
			sum+=schedule[i][1];
			dfs(i+schedule[i][0]);
			sum-=schedule[i][1];
			selected[i] = false;
		}
	}
	result = max(result,sum);
}

int main(){
	cin>>N;	
	
	for(int i=0;i<N;i++)
		cin>>schedule[i][0]>>schedule[i][1];
	
	dfs(0);
	cout<<result;	
	
	return 0;
}
