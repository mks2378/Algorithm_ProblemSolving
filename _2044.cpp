#include <iostream>

using namespace std;

// 20�� ���ڴ� long long Ÿ�� ��� 
// ���� 20���̸� O(n)�� �ð� �ʰ� ���´�  
// ���� ���� ����� unsigned long long �Ѿ�� 
// �� ���� ����� Ǫ�°� �ƴ϶� ����� ������ Ǫ�� ������� ��ȸ 
// nCm�� 2�� ������ �� ������ �ֱ� ������ 5,2 ���� �� ���� �� �� 

int count_5(long long num){
	int count=0;
	
	for(long long i=5;i<=num;i*=5)
		count+=(num/i);
	
	return count;	
}

int count_2(long long num){
	int count=0;
	
	for(long long i=2;i<=num;i*=2)
		count+=(num/i);	
	
	return count;
}

int main(){
	long long n, m;
	int cnt_5, cnt_2;
	int result;
	
	cin>>n; cin>>m;
	
	cnt_5 = count_5(n);
	cnt_5 -= (count_5(m)+count_5(n-m));
	
	cnt_2 = count_2(n);
	cnt_2 -= (count_2(m)+count_2(n-m));
	
	result = cnt_2<cnt_5?cnt_2:cnt_5;
	
	cout<<result;
	
	return 0;
}
