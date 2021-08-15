#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100000;
long long arr[MAX];

long long gcd(int n, int m){
	int a = n>m?n:m;
	int b = n>m?m:n;
	
	while(b>0){
		if(a%b==0)
			return b;
			
		int temp;
		temp = a;
		a = b;
		b = temp%b;
	}	
}

int main(){
	long long S, D=0;
	int N;
	cin>>N; cin>>S;
	
	long long temp;
	for(int i=0;i<N;i++){
		cin>>temp;
		arr[i] = abs(temp-S);
	}
	
	// ���� ���� �ִ������� ó�� ������ 2�� �ִ������� 
	// �ٸ� ������ �ִ����� ��������� ���ϸ� �ȴ�.
	D = arr[0];
	for(int i=1;i<N;i++)  
		D = gcd(D, arr[i]);
	
	cout<<D;
	
	return 0;
}
