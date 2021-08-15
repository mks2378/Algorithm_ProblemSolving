#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ������� ��� ����� ���� ���� ��, �ε�ȣ ������ 
// �����ϴ� ��츦 ã�� �� �� �ִ� �ּҸ� ���Ѵ�.  
// https://yabmoons.tistory.com/104
// cf) permutation �Լ� �̿�: https://jaimemin.tistory.com/758

int K;
char inequality[10];
bool selected[10];

vector<string> answer;
vector<char> v;

//�ε�ȣ �� ���  
bool Check(int idx, char c){
	if(c=='<'){
		if(v[idx]<v[idx+1]) return true;
		else return false;	
	}
	else if(c=='>'){
		if(v[idx]>v[idx+1]) return true;
		else return false;
	}
}

bool Calculate(){
	for(int i=0;i<K;i++)
		if(Check(i,inequality[i])==false)
			return false;	
	return true;
}

void dfs(int cnt){
	if(cnt==K+1){
		// if�ȿ��� �Լ� �̿��Ͽ� ���� ���� ���� �Ǵ�  
		if(Calculate()==true){ 
			string s_tmp="";
			for(int i=0;i<=K;i++)
				s_tmp+=v[i];
			answer.push_back(s_tmp);	
		}
		return;
	}
	
	for(int i=0;i<10;i++){
		if(!selected[i]){
			selected[i] = true;
			v.push_back(i+'0');
			dfs(cnt+1);
			v.pop_back();
			selected[i] =false;			
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>K;
	for(int i=0;i<K;i++)
		cin>>inequality[i];
	
	dfs(0);
	// string ���ڵ� sorting ����(���� �ϳ��� ���� ����)  
	sort(answer.begin(), answer.end());
	cout<<answer[answer.size()-1]<<'\n';
	cout<<answer[0];
	
	return 0;
}
