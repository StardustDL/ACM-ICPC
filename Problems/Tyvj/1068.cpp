/*
STR
���������ȣ�����������Ҫ�����ÿ��λ�ÿ�ʼ���ִ���ƥ�䳤�ȣ���ôO(n^2)���ڵ��㷨Ӧ���Ǻ��ѵġ����ǣ������Ҫ��Ĳ����ǡ�ÿ��λ�õĳ��ȡ������ǡ������������ȵ�λ����������������ʹ��KMP�㷨����ƥ������ʣ����ܹ����������⡣
	  ������������ӣ�
		A����abbabbabababbababba
		B����abbabababba
		Ӧ��KMP�㷨�������׵õ�B��������ƥ����
		Ԫ�� a b b a b a b a b b  a
		λ�� 1 2 3 4 5 6 7 8 9 10 11
		���� 0 0 0 1 2 1 2 1 2 3  4
		��������Ϊkmp[λ��] = ƥ�䳤�ȡ�
		�ɴ���õ�A���ĸ���Ԫ��β����ƥ�䳤����
		a b b a b b a b a b a b b  a  b a b b a
		1 2 3 4 5 3 4 5 6 7 8 9 10 11 5 6 7 3 4
		ͳ�Ƴ��������ȵĳ���Ƶ��
		���� 0 1 2 3 4 5 6 7 8 9 10 11
		Ƶ�� 0 1 1 3 3 3 2 2 1 1 1  1
		����������cnt[����] = Ƶ����
		<�ص�>
		����KMP����ƥ����������ʣ������A��ĳ��Ԫ�ؽ�β��һ������Ϊ11���ִ�������B��ƥ��Ļ����Ը�Ԫ�ؽ�β�ĳ���Ϊkmp[11] = 4���ִ�Ҳ�ǿ���ƥ��ġ�����˵cnt[4] += cnt[11]��Ҳ����˵�����������Ĳ���
		for (i = N; i >= 1; i--)
		    cnt[kmp[i]] += cnt[i];
		
		֮��cnt[i]�б���ľ�Ӧ�������г���Ϊi��ƥ���ִ��ˡ���ʱcnt�����״̬��
		���� 0  1 2 3 4 5 6 7 8 9 10 11
		Ƶ�� 19 8 7 4 4 3 2 2 1 1 1  1
		
		Ȼ������Ҫ����ǡ�����ǡ��Ϊi�����Ӵ��ĸ�����Ҳ������Щ�ִ�����һ���ַ��ǲ���ƥ��ġ�Ȼ����cnt�����д洢��cnt[i]����Ȼ������cnt[i + 1]�����ϵ������Ȼ����ܼ򵥣�������ǡ��Ϊi�����ִ���������cnt[i] - cnt[i + 1]����Ϊcnt[i]�п�����չ���ִ���Ȼ��������cnt[i + 1]��
		
		ʱ�临�Ӷ�O(M + N)�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=200000,INF=0x3f3f3f3f;
int fail[MAXN+3],L,pt[MAXN+3];
char* str;
void load(char* s){//Ԥ����ģʽ��
	fail[0]=fail[1]=0;
	L=strlen(s);
	for(int i=1;i<L;i++){
		int j=fail[i];
		while(j&&s[i]!=s[j])j=fail[j];
		fail[i+1]=s[i]==s[j]?j+1:0;
	}
	str=s;
}
void kmp(char* t){
	int len=strlen(t),j=0;
	for(int i=0;i<len;i++){
		while(j&&t[i]!=str[j])j=fail[j];
		j+=t[i]==str[j];
		pt[i+1]=j;
		if(j==L)j=fail[j];
	}
}
char S[MAXN+3],T[MAXN+3];
int n,m,k,ans[MAXN+3],x;
int main(){
	cin>>n>>m>>k>>S>>T;
	load(T);
	//for(int i=1;i<=n;i++)cout<<fail[i]<<" ";cout<<endl;
	kmp(S);
	//for(int i=1;i<=n;i++)cout<<pt[i]<<" ";
	//cout<<endl;
	for(int i=1;i<=n;i++)ans[pt[i]]++;
	for(int i=n;i>=1;i--)ans[fail[i]]+=ans[i];//cout<<"!!!"<<endl;
	//for(int i=0;i<=n;i++)cout<<ans[i]<<" ";
	
	while(k--){
		cin>>x;
		cout<<ans[x]-ans[x+1]<<endl;
	}
	return 0;
}

