/*
��׺����
*/
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=15000;
int str[MAXN+3];
int wa[MAXN+3],sa[MAXN+3],wb[MAXN+3],wv[MAXN+3],ws[MAXN+3],n;
int height[MAXN+3],rank[MAXN+3];
bool cmp(int *t,int a,int b,int l){
	return t[a]==t[b]&&t[a+l]==t[b+l];
}
void SuffixSort(int* str,int *sa,int n,int m){
	int *x=wa,*y=wb,i,j,p,*t;
	for(i=0;i<m;i++)ws[i]=0;
	for(i=0;i<n;i++)ws[x[i]=str[i]]++;
	for(i=1;i<m;i++)ws[i]+=ws[i-1];
	for(i=n-1;i>=0;i--)sa[--ws[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,m=p){
		for(p=0,i=n-j;i<n;i++)y[p++]=i;//���ڶ��ؼ��ֳ����߽�ģ�ֵΪ0����Ӧ����ǰ�� 
		for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;//sa[i]-j��������ڶ��ؼ�������Ӧ�ĵ�һ�ؽ��� 
		for(i=0;i<m;i++)ws[i]=0;
		for(i=0;i<n;i++)wv[i]=x[y[i]];//ע������ 
		for(i=0;i<n;i++)ws[wv[i]]++;
		for(i=1;i<m;i++)ws[i]+=ws[i-1];
		for(i=n-1;i>=0;i--)sa[--ws[wv[i]]]=y[i];//ע������ 
		swap(x,y);
		for(p=1,x[sa[0]]=0,i=1;i<n;i++)//x[sa[0]]=0�ȼ���rank[sa[0]]=0�����в�ͬ�� 
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;//x:sa��Ӧ������ 
		//rank��x������rank��һһ��Ӧ��x�Ƕ��һ��
		//��ĩβû��0����x[sa[0]]=0��ζ�Ŵ˳�����ΪSuffix(sa[0])������ӦΪ0���⵼�³�������ʱ��ΪSuffix(sa[0])�ͳ����߽�ȼۣ����»���
		//0�����壺�ַ����в����ڵ��ַ�������Ҫ���������϶���С�����������ַ�������int�ıȽϣ�ѡ<Min{�ַ���}�������ɣ�ע�ⲻҪ���˻������� 
	}
}
int main(){
	scanf("%d\n",&n);
	char c;
	for(int i=1;i<=n;i++){
		scanf("%c",&c);
		str[i]=c-'a'+1;
	}
	str[0]=0;
	SuffixSort(str,sa,n+1,27);
	//cout<<n<<endl; 
	for(int i=1;i<=n;i++)printf("%d\n",sa[i]);
	return 0;
}

