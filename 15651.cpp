// 15651_N°ú M(3) 

#include <iostream>

using namespace std;

const int MAX = 8;
int arr[MAX];
int n,m;

void func(int cnt){
	if(m==(cnt-1)){
		for(int i=1;i<=m;i++)
			cout<<arr[i]<<' ';
		cout<<'\n';
		return;
	}
	
	for(int i=1;i<=n;i++){
		arr[cnt]=i;
		func(cnt+1);
	}
}

int main(){
	cin>>n>>m;
	func(1);
	
	return 0;
}
