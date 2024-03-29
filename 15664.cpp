// 15664_N�� M(10)

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 9;
int arr[MAX];
int ans[MAX];
bool visited[MAX];
int n,m;

void func(int cnt){
	if(m == (cnt-1)){
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
		cout<<'\n';
		return;
	}
	
	bool used[10001] = {false, };
	for(int i=1;i<=n;i++){
		if(!visited[i]&&!used[arr[i]]&&(arr[i]>=ans[cnt-1])){
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
