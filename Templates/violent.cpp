/*

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
void get_all_set(int n){
	for(int i=0;i<(1<<n+1);i++){//枚举n个元素的集合 
		for(int k=0;(1<<k)<=i;k++)printf("%d",i>>k&1);
		puts(":");
		for(int j=i;j;j=(j-1)&i){//枚举非空子集 
			for(int k=0;(1<<k)<=j;k++)printf("%d",j>>k&1);
			puts("");
		}
	}
}
namespace Dichotomy{
	int dichotomy(int l,int r,bool (*check)(int x)){//二分得到满足条件的最大解，函数单调性：先可行后不可行 
	//cout<<l<<" "<<r<<endl;
		int ans=l;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		return ans; 
	}
}
namespace Quick_IO_Func{
	int read(){
		int f=1,x=0;char c=getchar();
		while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
		while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
		return x*f; 
	}
	void write(int x){
		static int temp[15],len;
		if(x==0){putchar('0');return;}
		if(x<0){putchar('-');x=-x;}
		len=0;
		while(x>0){
			temp[len++]=x%10;
			x/=10;
		}
		for(int i=len-1;i>=0;i--)putchar('0'+temp[i]);
	}
};
namespace Discretization{
	int temp[MAXN+3];
	void discretization(int *a,int *ans,int l,int r){//solve [l..r)
		for(int i=l;i<r;i++)temp[i]=a[i];
		sort(temp+l,temp+r);
		int size=unique(temp+l,temp+r)-(temp+l);//size为离散化后元素个数
		for(int i=l;i<r;i++)
			ans[i]=lower_bound(temp+l,temp+l+size,a[i])-(temp+l)+l;//ans[i]为a[i]经离散化后对应的值
	}
}
using namespace Quick_IO_Func;
bool ch(int x){
	return x<-100;
}
int t=0,x,y,z;
int get(){
	return ++t;
}
int test(int a,int b,int c){
	cout<<a<<" "<<b<<" "<<c<<endl; 
}
int a[MAXN+3],b[MAXN+3],n;
int main(){
	scanf("%d",&n);
	int t=2;
	for(int i=t;i<n+t;i++)scanf("%d",&a[i]);
	Discretization::discretization(a,b,t,n+t);
	for(int i=t;i<n+t;i++)cout<<b[i]<<" ";
	//get_all_set(3);
	return 0;
}

