/*
Musical Theme
���⣺��N(1 <= N <=20000)����������������ʾһ��������ÿ����������1..88��Χ�ڵ�����������Ҫ��һ���ظ������⡣�����⡱�������������е�һ���Ӵ�������Ҫ��������������
    	1.��������Ϊ5��������
    	2.���������ظ����֡�(���ܾ���ת������ת��������˼������������ÿ�������������ϻ��ȥ��ͬһ������ֵ)
    	3.�ظ����ֵ�ͬһ���ⲻ���й������֡� 
��������׺���顣����������������Ĳ�ֵ��Ȼ�������ת��Ϊ �����ص���ظ��Ӵ����ú�׺�����������ȶ��ִ𰸣�����Ŀ����ж������⣺�ж��Ƿ������������Ϊk���Ӵ�����ͬ�ģ��Ҳ��ص�������������Ĺؼ��������� height���顣�������ĺ�׺�ֳ������飬����ÿ��ĺ�׺֮���heightֵ����С��k��
	  ���׿�������ϣ����Ϊ�����ǰ׺��С�� k ��������׺һ����ͬһ�顣Ȼ�����ÿ���׺��ֻ���ж�ÿ����׺�� sa ֵ�����ֵ����Сֵ֮���Ƿ�С��k�������һ�����㣬��˵�����ڣ����򲻴��ڡ�����������ʱ�临�Ӷ�Ϊ
	  O(nlogn)������������ height ֵ�Ժ�׺���з���ķ����ܳ���
*/
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=20000+50;
int str[MAXN+3];
int wa[MAXN+3],sa[MAXN+3],wb[MAXN+3],wv[MAXN+3],wt[MAXN+3],n;
int height[MAXN+3],rank[MAXN+3];
bool cmp(int *t,int a,int b,int l){
	return t[a]==t[b]&&t[a+l]==t[b+l];
}
void da(int* str,int *sa,int n,int m){
	int *x=wa,*y=wb,i,j,p,*t;
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
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
}
void calheight(int* str,int n){
	int i,j,k=0;
	for(i=0;i<=n;i++)rank[sa[i]]=i;//ע������д�����뺬n����ʵi=0û���ã���Ϊrank[sa[0]]=n�����������ѭ�����ò���������i<n�����λ��rank[i]=0����������rank[i]-1�ͳ����� 
	for(i=0;i<n;i++){
		if(k)k--;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k])k++;
		height[rank[i]]=k;
	}
}
/*void calheight(int *r, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i ++]] = k)
    {
        for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++); 
    }
}*/
bool check(int k){
	int mx=-1,mn=INF,i=2;
	while(true){
		while(i<=n&&height[i]<k)i++;
		if(i>n)break;
		mx=mn=sa[i-1];//ע�⣬�������sa[i-1]����Ϊheight������i��i-1��ɵ�LCP 
		while(i<=n&&height[i]>=k){
			mx=max(mx,sa[i]);
			mn=min(mn,sa[i]);
			i++;
		}
		if(mx-mn>=k)return true;
	}
	return false;
}
int ef(int l,int r){
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	return l;
}
int main(){
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++)scanf("%d",&str[i]);
		if(n<10){puts("0");continue;}
		n--;
		for(int i=0;i<n;i++)str[i]=str[i+1]-str[i]+89;
		str[n]=0;
		da(str,sa,n+1,200);
		calheight(str,n);
		//puts("!!!");
		int ans=ef(4,(n-1)>>1);
		printf("%d\n",ans<4?0:ans+1);
	}
	return 0;
}

/*

int main()
{
    int i, ans;
    while(scanf("%d", &n) && n != 0)
    {
        for(i = 0; i < n; i ++)
        {
            scanf("%d", &str[i]);
        }
        if(n < 10) {
            printf("0\n");
            continue;
        }
        n --;
        for(i = 0; i < n; i ++)
        {
            str[i] = str[i+1] - str[i] + 89;
        }
        str[n] = 0;
        da(str ,n + 1, 200);
        calheight(str, n);
        
        int low = 4, high = (n-1)/2, mid;
        while(low < high)
        {
            mid = (low + high + 1) / 2;
            if(valid(mid)) {
                low = mid;
            }else {
                high = mid - 1;
            }
        }
        ans = low < 4 ? 0 : low + 1;
        printf("%d\n", ans);
    }
    return 0;
}*/

