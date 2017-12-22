/*
Glass Beads
���⣺��һ���ַ�������С��ʾ�Ŀ�ʼ�±ꡣ
��������ʵ��һ��O(N)���㷨ר�������������⣬����ʵ�ַǳ��򵥣�
	  ������׺�Զ���ͬ���ܹ����������⡣���Ȱ�������ظ����Σ�Ȼ���ǰ����һһ���ַ����뵽��׺�Զ����У�
	  ���Ӹ���ʼ���±������ĳ��Ȳ㼴�ɡ�
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000,NS=26;
struct SAM{
	struct node{
		int pre,len,ch[NS];
		void init(){
			pre=-1;len=0;memset(ch,-1,sizeof(ch));
		}
	}ns[MAXN+3<<1];
	int tail,tot;
	void init(){
		tail=tot=0;
		ns[tot++].init();
	}
	int newnode(){
		ns[tot].init();
		return tot++;
	}
	void add(int c){
		int np=newnode(),nq,p,q;
		ns[np].len=ns[tail].len+1;
		for(p=tail;p!=-1&&ns[p].ch[c]==-1;p=ns[p].pre)ns[p].ch[c]=np;
		if(p==-1)ns[np].pre=0;
		else{
			q=ns[p].ch[c];
			if(ns[p].len+1==ns[q].len)ns[np].pre=q;
			else{
				ns[nq=newnode()]=ns[q];
				ns[nq].len=ns[p].len+1;
				ns[np].pre=ns[q].pre=nq;
				for(;p!=-1&&ns[p].ch[c]==q;p=ns[p].pre)ns[p].ch[c]=nq;
			}
		}
		tail=np;
	}
	void loadstring(int* str,int n){
		for(int i=0;i<n;i++)add(str[i]);
	}
}sam;
char s[MAXN+3<<1];
int str[MAXN+3<<1],len;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("\n%s",s);
		len=strlen(s);
		for(int i=0;i<len;i++){
			str[i]=s[i]-'a';
			str[len+i]=str[i];
		}
		sam.init();
		sam.loadstring(str,len<<1);
		int p=0;
		for(int i=0;i<len;i++){
			for(int j=0;j<NS;j++){
				if(sam.ns[p].ch[j]!=-1){
					p=sam.ns[p].ch[j];
					break;
				}
			}
		}
		printf("%d\n",sam.ns[p].len-len+1);
	}
	return 0;
}
/*
����������С��ʾ��
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define N 20200 
//����Сѭ��ͬ������� 
using namespace std;
char str[N];
int len;
inline int go(){
    scanf("%s",str);
    len=strlen(str);
    int i=0,j=1,k=0,pi,pj;
    while(1){
        if(k==len)return i;
        if(i==j)j++;//!!
        pi=(i+k)%len;pj=(j+k)%len;
        if(str[pi]>str[pj])i+=k+1,k=0;
        else if(str[pj]>str[pi])j+=k+1,k=0;
        else k++;
    }
}
int main(){
    int cas;scanf("%d",&cas);
    while(cas--)printf("%d\n",go()+1);
    return 0;
} 
*/

