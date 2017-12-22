/*
Exponentiation
题意：小数点后6位的数的幂的准确值
分析：转成整数，高精乘，小数点可以计算出来，注意末尾0
	  表示以下程序并不能过样例，但是却能AC 
*/
#include<iostream>
#include<cstring>
using namespace std;
char str[10];
int res[999999],a[999999],b[999999],len,lena,lenb,n,dot;
void mul(){
	memset(res,0,sizeof(res));
	for(int i=1;i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			res[i+j-1] += a[i] * b[j];
			if(res[i+j-1]>9){
				res[i+j]+=res[i+j-1]/10;
				res[i+j-1]%=10;
			}
		}
	}
	if(res[lena+lenb-1]>9){
		res[lena+lenb]+=res[lena+lenb-1]/10;
		res[lena+lenb-1]%=10;
	}
	lena=lena+lenb;
	for(int i=1;i<=lena;i++)a[i]=res[i];
}
int main(){
	int up, down;
	while(scanf("%s %d",str,&n)!=EOF){
		dot=-1;
		for(int i=5,j=1;i>=0;i--){
			if(str[i]!='.')a[j]=b[j++]=str[i]-'0';
			else dot=i;
		}
		if(dot==-1)lena=lenb=6;
		else lena=lenb=5;
		for(int i=1;i<n;i++)mul();
		if(dot==-1){
			for(int i=lena;i>=1;i--)printf("%d",a[i]);
			printf("\n");
		}
		else{
			dot=(5-dot)*n;
			for(int i=1;i<=lena;i++)
				if(a[i]!=0){down=i;break;}
			for(int j=lena;j>=1;j--)
				if(a[j]!=0){up=j;break;}
			int i=up,j=down;
			if(up<dot)i=dot;
			if(j>dot)j=dot+1;
			for(;i>=j;i--){
				if(i==dot)printf(".");
				printf("%d",a[i]);
			}
			puts("");
		}
	}
	return 0;
}
