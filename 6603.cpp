#include <iostream>

using namespace std;

int k;
int arr[13];
bool visited[13];

void Print(){
	for(int i=0;i<k;i++)
		if(visited[i])
			cout<<arr[i]<<' ';
	cout<<'\n';	
}

void dfs(int cnt,int idx){
	if(cnt==6){
		Print();
		return;	
	}
	
	for(int i=idx;i<k;i++){
		if(!visited[i]){
			visited[i] = true;
			dfs(cnt+1,i+1);
			visited[i] = false;	
		}		
	}	
}

int main(){
	while(true){
		cin>>k;
		if(k==0)
			break;	
		
		for(int i=0;i<k;i++)
			cin>>arr[i];
			
		dfs(0,0);
		cout<<'\n';
		
		for(int i=0;i<k;i++){
			visited[i] = false;
			arr[i] = 0;	
		}	
	}	
	
	return 0;
}
