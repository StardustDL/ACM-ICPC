/*
Brackets Sequence
���⣺��һ��С�����������ŵ����У�������ٵ��ַ���ʹ�����б�Ϊ�Ϸ����У�����úϷ����С�
��������DP�������С��ֵ������¼·��Ȼ�󼴿ɵõ���
	  ����ģ�
	  	d[i][j]Ϊ�������д��±�i���±�j������Ҫ�Ӷ������Ų��ܳ�Ϊ�Ϸ����С�0<=i<=j<len (lenΪ�������еĳ���)��
		c[i][j]Ϊ�������д��±�i���±�j�ĶϿ�λ�ã����û�жϿ���Ϊ-1��
		��i==jʱ��d[i][j]Ϊ1
		��s[i]=='(' && s[j]==')' ���� s[i]=='[' && s[j]==']'ʱ��d[i][j]=d[i+1][j-1]
		����d[i][j]=min{d[i][k]+d[k+1][j]} i<=k<j ��  c[i][j]��¼�Ͽ���λ��k
		���õ��Ʒ�ʽ����d[i][j]
		������ʱ���õݹ鷽ʽ���print(0, len-1)
		�����������Ϊprint(int i, int j)����ʾ������±�i���±�j�ĺϷ�����
		��i>jʱ��ֱ�ӷ��أ�����Ҫ���
		��i==jʱ��d[i][j]Ϊ1������Ҫ��һ�����ţ����s[i]Ϊ'(' ����')'�����"()"���������"[]"
		��i>jʱ�����c[i][j]>=0��˵����i��j�Ͽ��ˣ���ݹ����print(i, c[i][j]);��print(c[i][j]+1, j);
		     ���c[i][j]<0��˵��û�жϿ������s[i]=='(' �����'('�� print(i+1, j-1); ��")"
             �������"[" print(i+1, j-1);��"]" 
      ����һ����ֵ����⣺��dp���ʼ��opt=INF,����DP�ڳ�ʼ���õ��𰸲�ͬ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=120;
char str[MAXN+3];
int opt[MAXN+3][MAXN+3],pa[MAXN+3][MAXN+3],n;
void output(int l,int r){
	if(l>r)return;
	if(l==r){
		if(str[l]=='('||str[l]==')')printf("()");
		else if(str[l]=='['||str[l]==']')printf("[]");
		return;
	}
	int c=pa[l][r];
	//cout<<endl<<l<<" "<<r<<" "<<c<<endl;getchar();
	if(c==-1){
		printf("%c",str[l]);
		output(l+1,r-1);
		printf("%c",str[r]);
	}
	else{
		output(l,c);
		output(c+1,r);
	} 
}
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	memset(pa,-1,sizeof(pa));
	//memset(opt,INF,sizeof(opt));Ϊʲô��������Ͳ��� 
	for(int i=1;i<=n;i++)opt[i][i]=1;
	for(int len=2;len<=n;len++){
		for(int i=1,j;i+len-1<=n;i++){
			j=i+len-1;
			int &t=opt[i][j];t=INF;
			if((str[i]=='('&&str[j]==')' || str[i]=='['&&str[j]==']'))t=opt[i+1][j-1],pa[i][j]=-1;
			for(int k=i,p;k<j;k++){
				if(t>(p=opt[i][k]+opt[k+1][j])){
					t=p;pa[i][j]=k;
				}
			}
		}
	}
	output(1,n);puts(""); 
	return 0;
}

