#include <iostream>
#include <climits>
using namespace std;

#define MAX 11

int max_result = -1000000001, min_result = 1000000001;
int N;
int Plus, Minus, Multiple, Divide;
int Arr[MAX];

// O(4^10) 
void DFS(int P, int Mi, int Mul, int D, int Sum, int N_Idx){
	if(N_Idx==N){
		if(Sum>max_result) max_result = Sum;
		if(Sum<min_result) min_result = Sum;
		return;		
	}
	
	if(P<Plus)
		DFS(P+1, Mi, Mul, D, Sum+Arr[N_Idx], N_Idx+1);
	if(Mi<Minus)
		DFS(P, Mi+1, Mul, D, Sum-Arr[N_Idx], N_Idx+1);
	if(Mul<Multiple)
		DFS(P, Mi, Mul+1, D, Sum*Arr[N_Idx], N_Idx+1);
	if(D<Divide)
		DFS(P, Mi, Mul, D+1, Sum/Arr[N_Idx], N_Idx+1);
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>Arr[i];
	cin>>Plus>>Minus>>Multiple>>Divide;
	
	DFS(0,0,0,0,Arr[0],1);
	cout<<max_result<<'\n'<<min_result;	

	return 0;
}

/* O(44P10) - 시간 초과 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, sum;
int num[11];
bool visited[44];
int remain[10];

vector<int> Operator;
vector<int> Selected;

int max_result = -1000000001, min_result = 1000000001;

void dfs(int cnt){
	if(cnt==N-1){
		int sum=num[0];
		for(int i=0;i<N-1;i++){
			if(Selected[i]==0)
				sum+=num[i+1];
			else if(Selected[i]==1)
				sum-=num[i+1];
			else if(Selected[i]==2)
				sum*=num[i+1];
			else if(Selected[i]==3)
				sum/=num[i+1];			
		}
		
		min_result = min(min_result,sum);
		max_result = max(max_result,sum);
		
		return;
	}
	
	for(int i=0;i<Operator.size();i++){
		if(!visited[i]){
			visited[i] = true;
			Selected.push_back(Operator[i]);
			dfs(cnt+1);
			Selected.pop_back();
			visited[i] = false;	
		}
	}	
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>num[i];
		
	for(int i=0;i<4;i++){
		int x;
		cin>>x;	
		for(int j=0;j<x;j++)
			Operator.push_back(i);
	}
	
	dfs(0);
	cout<<max_result<<'\n'<<min_result;

	return 0;
}
*/
