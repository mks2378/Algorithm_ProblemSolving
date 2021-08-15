#include <iostream>
#include <algorithm>
using namespace std;
int a[10000];
int N;

// N-1 �ε������� ó�� a[i-1]<a[i]�Ǵ� �������� �� �κ����� ������. 
// �ش� a[i-1]�� �� �Ʒ� �κ��� ���Ͽ� a[i-1]<a[j] �Ǵ� �ε��� ��
// ���� ū �ε��� j�� swap ��, i���� N-1���� �迭�� sorting  
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
