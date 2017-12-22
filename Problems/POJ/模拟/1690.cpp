/*
(Your)((Term)((Project)))
题意：简化表达式
分析：挺麻烦，不知道自己的代码错在哪。。 
*/
/*#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
const int MAXN=256;
struct data{
	int l,k;
};
char str[MAXN+3];
stack<data> st;
int len;
char getlast(int x){
	if(x<0)return '\0';
	while(str[x]=='\0')x--;
	return x<0?'\0':str[x];
}
char getnext(int x){
	while(str[x]=='\0')x++;
	return x>=len?'\0':str[x];
}
void solve(int l,int r){
	if(l>=r)return;
	for(int i=l;i<=r;i++){
		if(str[i]=='\0')continue;
		if(str[i]==' ')str[i]='\0';
		if(str[i]==40)st.push((data){i,getlast(i-1)=='-'});
		if(str[i]==41){
			data t=st.top();st.pop();
			if((t.k!=1)||getnext(t.l+1)==getlast(i-1))str[t.l]=str[i]=0;
			solve(t.l+1,i-1);
		}
	}
}
void output(){
	for(int i=0;i<len;i++)if(str[i]!='\0')cout<<str[i];
	cout<<endl;
}
int main(){
	int t;cin>>t;
	cin.getline(str,MAXN);
	while(t-->0){
		while(!st.empty())st.pop();
		cin.getline(str,MAXN);
		len=strlen(str);
		solve(0,len-1);
		output();
	}
	return 0;
}*/
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
stack<char> sk;
char s[256],result[256];
int i,j,t;
int main(){
	cin>>t;
	getchar();
	while(t--){
		cin.getline(s,256);
		for(i=0,j=0;s[i]!='\0';i++){//初步处理，先忽略（A）这种类型的括号 
			if(s[i]>='A'&&s[i]<='Z'||s[i]=='+'||s[i]=='-')result[j++]=s[i];
			else{
				switch(s[i]){
					case '(':
						if(j==0||result[j-1]!='-')sk.push('(');//只要括号前是'+'或括整条式，忽略 
						else{
							result[j++]='(';//括号前是'-' ，先保留，并做标记保留')' 
							sk.push('?');
						}
						break;
					case ')':
						if(sk.top()!='(')result[j++]=')';//有标记的保留 
						sk.pop();//吐掉前面压入的'('或标记 
						break;
				}
			}
		}
		result[j]='\0';
		for(i=0;i<j;i++){//单独处理(A)这种类型 
			if(result[i]!='*'){
				if(result[i]=='('&&result[i+2]==')'){//作标记 
					result[i+2]='*';continue;
				}
				cout<<result[i];
			}
		}
		cout<<endl;
		while(!sk.empty())sk.pop();
	}
	return 0;
}
