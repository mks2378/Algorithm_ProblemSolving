// 15663_N과 M(9)

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 9;
int n,m;
int arr[MAX];
int ans[MAX];
bool visited[MAX];


void func(int cnt){
	if(m==(cnt-1)){
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
		cout<<'\n';
		return;
	}
	
	bool used[10001] = {false, };
	for(int i=1;i<=n;i++){
		if(!visited[i]&&!used[arr[i]]){
			visited[i] = true;
			used[arr[i]] = true;
			ans[cnt] = arr[i];
			func(cnt+1);
			visited[i] = false;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	
	sort(arr+1,arr+n+1);
	func(1);
	
	return 0;
}

/*
1. 값이 곧 인덱스인 used 배열 이용하여 중복 제거
2. 같은 cnt에서 같은 값의 중복을 제거하는 것이 포인트 
used 배열 선언 위치를 결정하는 것이 어려웠다. 
*/
