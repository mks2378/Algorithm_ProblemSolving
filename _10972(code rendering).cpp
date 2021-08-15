#include <iostream>
#include <algorithm>
using namespace std;
int a[10000];
int N;

// N-1 인덱스부터 처음 a[i-1]<a[i]되는 기준으로 두 부분으로 나눈다. 
// 해당 a[i-1]과 그 아래 부분을 비교하여 a[i-1]<a[j] 되는 인덱스 중
// 가장 큰 인덱스 j와 swap 후, i부터 N-1까지 배열을 sorting  
int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>a[i];	
	
	int i = N-1;
	while(a[i-1]>a[i])
		--i;
		
	if(i==0){
		cout<<-1;
		return 0;
	}
	
	int idx;
	for(int j=i;j<N;j++)
		if(a[i-1]<a[j])
			idx = j;
	
	swap(a[i-1],a[idx]);
	sort(a+i,a+N);
	
	for(int i=0;i<N;i++)
		cout<<a[i]<<' ';
	
	return 0;
}
