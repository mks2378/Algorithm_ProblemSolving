#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, Answer;
bool Alphabet[26];
vector<string> Words;

int Word_Count(){
   int NumOfWords=0;
   for(int i=0;i<Words.size();i++){
		bool completed = true;
		string str = Words[i];
        for(int j=0;j<str.length();j++){
        	int idx = str[j] - 'a';
        	if(!Alphabet[idx]){
            	completed = false;
            	break;
         	}
      	}
      	if(completed)
        	NumOfWords++;
   	}
   	return NumOfWords;
}

// �ð� ���� 1��: �ִ� ���� �� 1500�� �� ���� 
void dfs(int idx, int cnt){
   if(cnt==K){
   		// �ִ밪 ���� ��, �Լ� ���ϰ��� max�Լ� �ȿ� �־� �༭ ���ϴ� �ڵ� ��� 
      	Answer = max(Answer, Word_Count());
      	return;   
   }
   
   for(int i=idx;i<26;i++){
      	if(!Alphabet[i]){
         	Alphabet[i] = true;
         	dfs(i, cnt+1);
         	Alphabet[i] = false;
      	}
   	}
}

// 'a', 'n', 't', 'i', 'c' ���縵�� �׻� ���ԵǾ� �ִٴ� ������ ���ļ�
// ��� �ð��ʰ��� �߻��ϴ� ��� �߻� 
// ������ ������ ������ ����!  
int main(){
	cin>>N>>K;
	
	if(K<5){
		cout<<0;
		exit(0);
	}
   
	Alphabet['a' - 'a'] = true;
	Alphabet['n' - 'a'] = true;
	Alphabet['t' - 'a'] = true;
	Alphabet['i' - 'a'] = true;
	Alphabet['c' - 'a'] = true;
	K = K - 5;

    for(int i=0;i<N;i++){
		string s;
		cin>>s;
		Words.push_back(s);      
    }
   
	dfs(0, 0);
	cout<<Answer;
	return 0;
}
