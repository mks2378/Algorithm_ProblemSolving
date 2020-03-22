#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, max_result = -1000000001, min_result = 1000000001;
int sum;
int num[11];
int remain[10];

bool visited[10];
vector<int> v;

void dfs(int cnt){
	if(cnt==N-1){
		max_result = max(max_result, sum);
		min_result = min(min_result, sum);
		return;
	}
	
	for(int i=0;i<v.size();i++){
		if(!visited[i]){
			visited[i] = true;
			if(v[i]==0)
				sum = sum + num[cnt+1];
			else if(v[i]==1)
				sum = sum - num[cnt+1];
			else if(v[i]==2)
				sum = sum * num[cnt+1];
			else if(v[i]==3){
				remain[cnt] = sum % num[cnt+1];
				sum = sum / num[cnt+1];
			}
			
			dfs(cnt+1);
			
			visited[i] = false;
			if(v[i]==0)
				sum = sum - num[cnt+1];
			else if(v[i]==1)
				sum = sum + num[cnt+1];
			else if(v[i]==2)
				sum = sum / num[cnt+1];
			else if(v[i]==3)
				sum = sum*num[cnt+1]+remain[cnt];
		}
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>num[i];
	
	for(int i=0;i<4;i++){
		int cal;
		cin>>cal;
		for(int j=0;j<cal;j++)
			v.push_back(i);		
	}
	
	sum = num[0];
	dfs(0);
	cout<<max_result<<'\n'<<min_result;
	return 0;
}
