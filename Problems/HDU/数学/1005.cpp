/*
Number Sequence
���⣺����a1=1,a2=1,an=A*a(n-1)+B*a(n-2)�����n��
���������Ծ�������ݣ����ǳ�ʱ��TAT
	  ����Mod 7�����Կ�����ѭ���� 
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
			//������������� =1��������ȫ����ǰ����ͬ��������������
			//��ʱ��û��Ҫ�ٽ�����ȥ�ˣ�����ѭ��, i-2Ϊ���� 
			if(arr[i]==1&&arr[i-1]==1)break;
		}
		n=n%(i-2);
		// ��n��������ģ����n = i-2ʱ, n=0,��ʱ����Ӧ��ȡarr[i-2]�ģ����԰�arr[0]=arr[i-2] 
		//Ҳ����������
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
