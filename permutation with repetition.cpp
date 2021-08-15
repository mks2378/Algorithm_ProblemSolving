#include <iostream>
using namespace std;

#define MAX 5

int Arr[MAX] = {1,2,3,4,5};
int Select[MAX];

//permutation with repetition
void dfs(int cnt){
	if(cnt==3){
		for(int i=0;i<cnt;i++)
			cout<<Select[i]<<' ';
		cout<<'\n';
		return;
	}
	
	for(int i=0;i<MAX;i++){
		Select[cnt] = Arr[i];
		dfs(cnt+1);		
	}
}

int main(){
	dfs(0);
	
	return 0;
}
