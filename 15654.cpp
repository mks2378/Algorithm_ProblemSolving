// 15654_N과 M(5)

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 9;
int arr[MAX];
int ans[MAX];
bool visited[MAX];
int n,m;

void func(int cnt){
	if(m==(cnt-1)){
		for(int i=1;i<=m;i++)
			cout<<ans[i]<<' ';
		cout<<'\n';
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			visited[i] = true;
			ans[cnt] = arr[i];
			func(cnt+1);
			visited[i] = false;
		}
	}
}


void SelectionSort(int* array){
	for(int i=1;i<=n;i++){
		int min = 10001;
		int index, temp;
		
		for(int j=i;j<=n;j++){
			if(arr[j]<min){
				min = arr[j];
				index = j;
			}
		}
		
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;		
	}
}


int main(){	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	
	SelectionSort(arr);
	//sort(arr+1, arr+n+1); //algorithm 라이브러리 내 sort 함수 이용  

	func(1);
	
	return 0;
}
