/*
�����������������㣺 1.��hash�Ĺؼ����ڹ���������ͬ�Ĵ���Ӧ��hashֵ��ͬ�� 2.��u64�൱�ڶ�2^64�����ȡģ�� 
	  ���base��ż������ôa.........aaa(>64��a)��ba.......aa(a������Ϊǰ����ô��a������-1)����������������ͬ��hashֵ��ͬ����Ȼ���ǲ�ͬ�ģ������Ϳ����ˡ� 
	  ���base���������ͱȽ��鷳�ˡ� 
	  ��vfk�������ɣ� 
	  ���base�������Ļ�������ֻ����a��b������ĸ�� 
		a \ b��ʾa������b����orz ������ѧ�� 
		����ѧ�ϵĺ���not(S)��ʾ���ַ���S��ÿ��λ�õ�'a'���'b'����'b'���'a'���γɵ��ַ���������not("ababaa") = "bababb" 
 		strA . strB�����ַ�����������"��" . "����" = "�޹���" 
 		|str|��ʾ�ַ���str�ĳ��ȡ� 
 		���ַ�������{orzstr[i]}��orzstr[1] = "a", orzstr[i] = orzstr[i - 1] . not(orzstr[i - 1]) 
 		��ô|orzstr[i]| = |orzstr[i - 1]| * 2����Ȼ���ǵȱ����У��õ���|orzstr[i]| = |orzstr[1]| . 2 ^ (i - 1) = 2 ^ (i - 1) 
 		��hash(str)Ϊstr�Ĺ�ϣֵ�� 
 		�� 
 		hash(orzstr[i]) = hash(orzstr[i - 1]) * base ^ |not(orzstr[i - 1])| + hash(not(orzstr[i - 1])) 
                        = hash(orzstr[i - 1]) * base ^ (2 ^ (i - 2)) + hash(not(orzstr[i - 1])) 
 		hash(not(orzstr[i])) = hash(not(orzstr[i - 1])) * base ^ (2 ^ (i - 2)) + hash(orzstr[i - 1]) 
 		��ʽ����� 
   		hash(orzstr[i]) - hash(not(orzstr[i])) 
		= (hash(orzstr[i - 1]) * base ^ (2 ^ (i - 2)) + hash(not(orzstr[i - 1]))) - (hash(not(orzstr[i - 1])) * base ^ (2 ^ (i - 2)) + hash(orzstr[i - 1])) 
		= (hash(orzstr[i - 1]) - hash(not(orzstr[i - 1]))) * (base ^ (2 ^ (i - 2)) - 1) 
 		�������Ƿ��֣�hash(orzstr[i]) - hash(not(orzstr[i]))�ƺ��Ǹ�����Ķ����������ǵ�Ŀ��ʵ������Ҫ�������ַ���strA, strBʹ�� 
		hash(strA) % 2^64 = hash(strB) % 2^64 
 		�൱�� 
 		2^64 \ hash(strA) - hash(strB) 
 		������{f[i]}��f[i] = hash(orzstr[i]) - hash(not(orzstr[i])) 
 		�������У� 
 		f[i] = f[i - 1] * (base ^ (2 ^ (i - 2)) - 1) 
 		�����е㲻ˬ������������������{g[i]}��g[i] = base ^ (2 ^ (i - 1)) - 1 
 		������д�ɣ� 
 		f[i] = f[i - 1] * g[i - 1] 
 		��f[i] = f[1] * g[1] * g[2] * ... * g[i - 1] 
 		Ȼ����һ����������飿 
 		base����������base�������������η�Ҳһ�������������Զ��������i����g[i]Ϊż��������2 ^ (i - 1) \ f[i] 
 		�����ǲ��ǽ������ء�������û�С��������Ļ�����Ҫʹ2 ^ 64 \ f[i]�����ٵ���i = 65����Ȼ����|orzstr[65]|�Ǹ��������֡� 
 		�������Ǹղ���������̫�ӵ��ˡ��� 
 		i > 1ʱ�У� 
 		g[i] = base ^ (2 ^ (i - 1)) - 1 = (base ^ (2 ^ (i - 2)) - 1) * (base ^ (2 ^ (i - 2)) + 1) = g[i - 1] * һ��ż�� 
 		��g[1]��Ȼ��ż���ɡ��� 
 		��ô4 \ g[2]��8 \ g[3]... 
 		Ҳ����˵2 ^ i \ g[i] 
 		����f[i] ʵ�����У� 
 		(2 ^ 1) * (2 ^ 2) * (2 ^ 3) * ... * (2 ^ (i - 1)) \ f[i] 
 		2 ^ (i * (i - 1) / 2) \ f[i] 
 		��iȡ12ʱ������66��2��Ӵ�� 
 		����ǿ�baseΪ����ʱ�ķ�����orzstr[12]��not(orzstr[12])��Ϊ���� 
		��������base������������ż����ֱ��������������ַ��������64��a�Ϳ����ˡ� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1<<11,INF=0x3f3f3f3f;
char str[MAXN+3];
int main(){
	printf("%d %d\n",(1<<11)+65,(1<<10)); 
	str[1]='a';
	for(int i=1,cur=1;i<=11;i++,cur<<=1)
		for(int j=1;j<=cur;j++)str[cur+j]=str[j]=='a'?'b':'a';
	str[1<<11|1]='\0';
	printf("%s",str+1);
	for(int i=1;i<=65;i++)putchar('a');
	puts("");
	return 0;
}

