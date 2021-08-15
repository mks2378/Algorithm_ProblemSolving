// 15650_N°ú M(2)

#include <iostream>

using namespace std;

int n,m;

const int MAX = 9;
int arr[MAX];
bool visited[MAX];

void func(int cnt){
	if(m==(cnt-1)){
		for(int i=1;i<cnt;i++)
			cout<<arr[i]<<' ';
		cout<<'\n';
	}
	
	for(int i=1;i<=n;i++){
		if(!visited[i]&&(i>arr[cnt-1])){
			visited[i] = true;
			arr[cnt] = i;
			func(cnt+1);
			visited[i] = false;
		}			
	}	
}

int main(){
	
	cin>>n>>m;
	func(1);
		
	return 0;
}
