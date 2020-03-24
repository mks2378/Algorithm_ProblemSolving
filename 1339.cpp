#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int N;
bool selected[26];
vector<int> alpha_idx;
vector<string> v;

int num[26];
int max_result;
int NumOfAlphabet;

int Calculation(){
	int total = 0;
	for(int i=0;i<N;i++){
		int sum=0;
		//cmath�� pow �Լ��� ������, �� �ڸ��� ó���� ���� 
		//���� ���� ū ���ں��� �ϳ��� ���� ��, 10�� ���ذ��� �������� ǥ�� ����  
		for(int j=0;j<v[i].size();j++){
			sum+=num[v[i][j]-'A'];
			sum*=10;
		}
		total += (sum/10);
	}
	return total;
}

void dfs(int cnt){
	if(cnt==NumOfAlphabet){
		max_result = max(max_result, Calculation());
		return;
	}
	
	// alpha_idx: ex) G C F A D E B 
	// ���� ���  
	for(int i=0;i<NumOfAlphabet;i++){
		if(!selected[alpha_idx[i]]){
			selected[alpha_idx[i]] = true;
			num[alpha_idx[i]] = 9-cnt; // �ִ밪�� ã���Ƿ� ���� ū 9���� Ž��  
			dfs(cnt+1);
			selected[alpha_idx[i]] = false;
		}
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		//������ ���ĺ��� ���Ͽ� üũ  
		for(int i=0;i<s.length();i++)
			if(!selected[s[i]-'A']){ // �ε����� ǥ�� 
				selected[s[i]-'A'] = true;
				alpha_idx.push_back(s[i]-'A');
			}
		v.push_back(s);
	}
	
	// cstring -> memset
	memset(selected,false,26);
	NumOfAlphabet = alpha_idx.size();
	dfs(0);
	cout<<max_result;
	
	return 0;
}
