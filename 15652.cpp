// 15652_N°ú M(4)

#include <iostream>

using namespace std;

const int MAX = 9;
int arr[MAX];
int n,m;

void func(int cnt){
	if(m==(cnt-1)){
		for(int i=1;i<=m;i++)
			cout<<arr[i]<<' ';
		cout<<'\n';
		return;
	}
	
	for(int i=arr[cnt-1];i<=n;i++){
		arr[cnt]=i;
		func(cnt+1);
	}	
}

int main(){
	cin>>n>>m;
	arr[0]=1;
	func(1);
	
	return 0;
}
