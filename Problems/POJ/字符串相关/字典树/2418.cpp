/*
Hardwood Species
分析：字典树，构建好后，dfs，沿字典序最小，注意题中有空格 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000,NS=128;
#define id(x) (x)
struct Trie{
	int ch[MAXN*NS+3][NS],tot,val[MAXN*NS+3];
	
	void init(){
		tot=0;
		memset(ch,0,sizeof(ch));
	}
	
	void insert(char* str){
		int cur=0;
		int len=strlen(str);
		for(int i=0;i<len;i++){
			//cout<<str[i]<<endl;
			if(ch[cur][id(str[i])]==0)ch[cur][id(str[i])]=++tot;
			cur=ch[cur][id(str[i])];
		}
		val[cur]++;
	}
}T;
char s[203],c[203];
int n=0;  
void find(int x,int k){  
    for(int i=0;i<NS;i++){  
        if(T.ch[x][i]){  
            int j=T.ch[x][i];  
            s[k]=i;  
            if(T.val[j]){  
                s[k+1]='\0';  
                printf("%s %.4lf\n",s,T.val[j]*100.0/n);  
            }  
            find(j,k+1);
        }  
    }  
}  
int main(){
	T.tot=0;
	while(gets(c)&&c[0]){
		n++;
		//cout<<"!!!"<<endl;
		T.insert(c); 
	} 
	find(0,0);
	return 0;
}
