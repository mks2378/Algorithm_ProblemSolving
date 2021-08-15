#include <iostream>
#include <algorithm>
using namespace std;

int max_sum;
int sum;
int N,M;
int cnt;

bool visited[500][500];
int arr[500][500];

// 1*1 도형의 개수가 4개로 같아 dfs로 접근이 가능  
// 'ㅗ' 모형은 dfs고 접근 불가능하므로 예외케이스로 따로 구현  
void dfs(int i,int j){
	++cnt;
	visited[i][j] = true;
	sum+=arr[i][j];
	
	if(cnt==4){
		max_sum = max(max_sum,sum);
		--cnt;
		visited[i][j] = false;
		sum-=arr[i][j];
		
		return;
	}
	
	//up
	if(i-1>=0&&!visited[i-1][j])
		dfs(i-1,j);
	
	//right
	if(j+1<500&&!visited[i][j+1])
		dfs(i,j+1);
	
	//left
	if(j-1>=0&&!visited[i][j-1])
		dfs(i,j-1);
	
	//down
	if(i+1<500&&!visited[i+1][j])
		dfs(i+1,j);
		
	--cnt;
	visited[i][j] = false;
	sum-=arr[i][j];
}

void special(int i,int j){
	int sum;
	if(i-1>=0&&i+1<500&&j+1<500){
		sum = arr[i][j]+arr[i-1][j]+arr[i+1][j]+arr[i][j+1];
		max_sum = max(max_sum,sum);
		
		sum = arr[i][j]+arr[i][j+1]+arr[i-1][j+1]+arr[i+1][j+1];
		max_sum = max(max_sum,sum);		
	}
	
	if(i-1>=0&&j-1>=0&&j+1<500){
		sum = arr[i][j]+arr[i][j-1]+arr[i][j+1]+arr[i-1][j];
		max_sum = max(max_sum,sum);
	}
	if(i+1<500&&j-1>=0&&j+1<500){
		sum = arr[i][j]+arr[i][j-1]+arr[i][j+1]+arr[i+1][j];
		max_sum = max(max_sum,sum);
	}
}

int main(){
	cin>>N>>M;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>arr[i][j];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			dfs(i,j);
			special(i,j);
		}
	
	cout<<max_sum;
	
	return 0;
}
