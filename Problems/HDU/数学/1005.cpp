/*
Number Sequence
题意：数列a1=1,a2=1,an=A*a(n-1)+B*a(n-2)，求第n项
分析：可以矩阵快速幂，但是超时了TAT
	  由于Mod 7，所以可以找循环节 
*/
#include<iostream>
using namespace std;
int arr[10000]; 
int main(){
	int A,B,n;
	arr[1]=arr[2]=1;
	while(cin>>A>>B>>n,A||B||n){
		int i;
		for(i=3;i<10000;i++){
			arr[i]=(A*arr[i-1]+B*arr[i-2])%7;
			//如果有两个连着 =1，则后面的全部和前面相同，即出现了周期
			//这时就没必要再进行下去了，跳出循环, i-2为周期 
			if(arr[i]==1&&arr[i-1]==1)break;
		}
		n=n%(i-2);
		// 把n对周期求模，当n = i-2时, n=0,此时本来应该取arr[i-2]的，所以把arr[0]=arr[i-2] 
		//也可以这样：
		//if(n==0)n=i-2;  
		arr[0]=arr[i-2];
		cout<<arr[n]<<endl;
	}
	return 0;
}

/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000,MOD=7;
typedef int matrix[2][2];
int a,b,n;
matrix A,T,ans;
int f(int n){
	if(n==1||n==2)return 1;
	else return (a*f(n-1)+b*f(n-2))%MOD;
}
void multyply(matrix a,matrix b,matrix c){
	T[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	T[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	T[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	T[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];
	c[0][0]=T[0][0]>MOD?T[0][0]%MOD:T[0][0];
	c[0][1]=T[0][1]>MOD?T[0][1]%MOD:T[0][1];
	c[1][0]=T[1][0]>MOD?T[1][0]%MOD:T[1][0];
	c[1][1]=T[1][1]>MOD?T[1][1]%MOD:T[1][1];
}
void quickpow(int n){
	matrix t;
	t[0][0]=A[0][0];
	t[0][1]=A[0][1];
	t[1][0]=A[1][0];
	t[1][1]=A[1][1];
	//for(int i=1;i<=n;i++)multyply(ans,A,ans);
	while(n){
		if(n&1){
			multyply(ans,t,ans);
		}
		multyply(t,t,t);
		n>>=1;
	}
}
int main(){
	while(scanf("%d%d%d",&a,&b,&n),a+b+n>0){
		A[0][0]=0;
		A[0][1]=b;
		A[1][0]=1;
		A[1][1]=a;
		ans[0][0]=1;
		ans[0][1]=0;
		ans[1][0]=0;
		ans[1][1]=1;
		quickpow(n-2);
		//cout<<f(n)<<endl;
		printf("%d\n",(ans[0][1]+ans[1][1])%MOD);
	}
	return 0;
}
*/
