/*
Maximum repetition substring
���⣺ 
������ö�ٳ���ΪL��Ȼ�󿴳���ΪL���ַ�������������ּ��Ρ�
	  ��Ȼ����ΪL�Ĵ��ظ����֣���ôstr[0],str[l],str[2*l]�����п϶������������ĳ������ַ����У���Ϊ���Ҫ�ظ����֣����ִ���>1����ô�ͻ��������
	  ��ô��ö��������������Ȼ����������ַ�������ƥ�䣬�������ƥ���Զ����ʵ����ƥ���������ĺ�׺�������ǰ׺ 
	  ����str[i*l],str[i*l+l]ǰ��ƥ�䣬������ͨ����ѯsuffix(i*l),suffix(i*l+l)�������ǰ׺�� 
	  ͨ��rankֵ���ҵ�i*l,��i*l+l������������Ҫ��ѯ������������height����Сֵ��ͨ��RMQԤ�����ﵽ��ѯΪ0(1)�ĸ��Ӷȣ�
	  ��LCP����ΪM(��Ϊѭ����ε��ܳ���), �����ȻΪM / L + 1 �����POJ2406��+1����Ϊƥ�䳤�Ȼ�Ҫ�ټ�һ��i..i+l�������Ĵ𰸣����Ի���ͼ��, ���ⲻһ������õ�, 
	  ��Ϊ�𰸵���β��һ��������ö�ٵ�λ���ϣ�L������M�����M%L��. ���������, ���ǿ���M % L��ֵ������, ���ǿ�����Ϊ�Ǻ������M % L���ַ�, 
	  �������Ǹ��������ǰ������(L - M % L)���ַ�! �����������׺j * L - (L - M % L)���׺(j + 1) * L - (L - M % L)�������ǰ׺��
	    ����֮ǰ������ǰ׺L-M%L���ɡ�
	  Ȼ��ѿ���ȡ�����ֵ�ĳ���L���棬���� ��ĿҪ���ֵ�����С��ͨ��sa�������ö�٣�ȡ���ĵ�һ�飬�϶����ֵ�����С�ġ� 
	  ��ٳ��� L ��ʱ���� n��ÿ�μ����ʱ���� n/L����������������ʱ�临�Ӷ��� O(n/1+n/2+n/3+����+n/n)=O(nlogn)��
	  �Լ������һ�ַ����� 
		���POJ2406���൱����һ�Ӵ���ʹ���������ѭ��������󣨼�Ϊ2406�������ݣ�
		����ö��������˵�i����iɨ��n��ÿ�����һ��next[j]ֵ��������T=len/(j-next[j])����ѭ�����ָ�����ע�ⲻ����ѭ�������
		������O(n^2)�ģ����ǿ��Խ����Ż� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000+5;
int wa[MAXN+3],wb[MAXN+3],wt[MAXN+3],wv[MAXN+3];
bool cmp(int *str,int a,int b,int l){
	return str[a]==str[b] && str[a+l]==str[b+l];
}
void da(int* str,int* sa,int n,int m){//�����׺���� 
	int i,j,p,*x=wa,*y=wb;
	for(i=0;i<m;i++)wt[i]=0;
	for(i=0;i<n;i++)wt[x[i]=str[i]]++;
	for(i=1;i<m;i++)wt[i]+=wt[i-1];
	for(i=n-1;i>=0;i--)sa[--wt[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p){
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<m;i++)wt[i]=0;
		for(i=0;i<n;i++)wt[wv[i]=x[y[i]]]++;
		for(i=1;i<m;i++)wt[i]+=wt[i-1];
		for(i=n-1;i>=0;i--)sa[--wt[wv[i]]]=y[i];
		swap(x,y);
		for(p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++; //�������һ��y��д��str 
	}
}
int sa[MAXN+3],rank[MAXN+3],height[MAXN+3];
void calheight(int*str,int n){//����height���� 
	int i,j,k=0;
	for(i=0;i<=n;i++)rank[sa[i]]=i;
	for(i=0;i<n;i++){
		if(k)k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])k++;
		height[rank[i]]=k;
	}
}
int qmin[MAXN+3][18];
void rmqinit(int n,int* val){//Ԥ����rmq 
	for(int i=1;i<=n;i++)qmin[i][0]=val[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			qmin[i][j]=min(qmin[i][j-1],qmin[i+(1<<j-1)][j-1]);
}
int rmquery(int l,int r){//rmq��ѯ����ѯ��l��ͷ����r��ͷ�ĺ�׺�������ǰ׺ 
	l=rank[l],r=rank[r];
	if(l>r)swap(l,r); 
	l++;//ע������ 
	int m=floor(log10(r-l+1.0)/log10(2.0));
	return min(qmin[l][m],qmin[r-(1<<m)+1][m]);
}
char S[MAXN+3];
int cove[MAXN+3],n;
int ans[MAXN+3],tot,kase=0;
int main(){
	while(scanf("%s",S),S[0]!='#'){
		n=strlen(S);
		for(int i=0;i<n;i++)cove[i]=S[i]-'a'+1;
		//printf("%d\n",cove[0]);
		cove[n]=0;
		da(cove,sa,n+1,128);
		//puts("!!!");
		calheight(cove,n);
		rmqinit(n,height);
		int mx=0;tot=0;
		for(int l=1;l<n;l++){//ö��ѭ���ڳ��� 
			for(int i=0;i<n;i+=l){//ö�����������ǵ�����λ��i,i+l 
				int len=rmquery(i,i+l),tme=len/l+1,k=i-(l-len%l);//�������ȣ�ѭ�����ִ������Լ������ж� 
				if(k>=0)if(rmquery(k,k+l)>=len)tme++;//�����ж� 
				if(tme>mx){
					mx=tme;
					ans[(tot=0)++]=l;
				}
				else if(tme==mx){
					ans[tot++]=l;
				}
			}
		}
		int len=-1,st;
		for(int i=0;i<=n&&len==-1;i++){
			for(int j=0;j<tot;j++){
				int l=ans[j];
				if(rmquery(sa[i],sa[i]+l)>=(mx-1)*l){
					len=l;
					st=sa[i];
					break;
				}
			}
		}
		printf("Case %d: ",++kase);
		for(int i=0;i<len*mx;i++)putchar(S[st+i]);
		puts("");
	}
	return 0;
}

