#include <iostream>
#include <vector>
using namespace std;
#define MAX 5

int arr[5];
bool select[5];
vector<int> v;

void Print(){
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<'\n';
}

void dfs(int cnt){
	if(cnt==3){
		Print();
		return;	
	}
	
	for(int i=0;i<MAX;i++){
		if(select[i]==true)
			continue;
		select[i] = true;
		v.push_back(arr[i]);
		dfs(cnt+1);
		v.pop_back();
		select[i] = false;
	}	
}

int main(){
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	
	dfs(0);
	
	return 0;
}
