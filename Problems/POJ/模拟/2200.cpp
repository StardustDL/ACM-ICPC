/*
A Card Trick
���⣺��Ҫ�ǽ�5������ȫ���У�Ȼ���ҳ�����Ҫ���һ��������ɡ� 
�����������ջ��Ǽ����˶�next_permutaiton��������⡣
	  �ڴ����У����ǰ�ÿ���Ƴ������һ������������int value���ͻ�ɫ��char suit���Ľṹ�塣
	  �Խṹ������next_permutaiton������Ҫ�ر�ע�⣺
		��1��Ҫ�Զ�����һ���ȽϺ��������ַ�����ѡһ�֣�
			a.�ڽṹ�嶨����ֱ������<��==��>������
			b.����д���ȽϺ������ù�std::sort�����������İ����
		��2���������е�ȫ�������֮ǰ��һ��Ҫ�Խṹ�����飬��������˵������ȽϺ�����һ��������std::sort��ȽϷ��㣩����ʹ����������������next_permutaiton����Ϊ�����������prev_permutaiton�����򣬻���м������ȫ����������������ȱʧ��
	  ֵ��һ����ǣ��ڵ�ǰ�������е�Ԫ�ش�����һ˳��״̬�µ�ʱ��
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct card{
	int value;
	char suit;
	card(){}
	card(int v, char s):value(v),suit(s){}
	bool operator <(const card& other)const{
		return (value<other.value)||(value==other.value&&suit<other.suit);
	}
};
void initialize(card* cards){
	string tmp;
	for(int i=0;i<5;i++){
		cin>>tmp;
		if(tmp.length()==2){
			switch(tmp[0]){
				case 'A':cards[i].value=1;break;
				case 'J':cards[i].value=11;break;
				case 'Q':cards[i].value=12;break;
				case 'K':cards[i].value=13;break;
				default:cards[i].value=tmp[0]-'0';break;
			}
		}
		else if(tmp.length()==3)cards[i].value=10;
		cards[i].suit=tmp[tmp.length()-1];
	}
}
void printResult(int counter,card* cards){
	printf("Problem %d:",counter);
	for (int i=0;i<5;i++){
		putchar(' ');
		switch(cards[i].value){
			case 1:putchar('A');break;
			case 11:putchar('J');break;
			case 12:putchar('Q');break;
			case 13:putchar('K');break;
			default:printf("%d",cards[i].value);break;
		}
		printf("%c",cards[i].suit);
	}
	puts("");
}
int main(){
	int caseNum;
	cin>>caseNum;
	for(int counter=1;counter<=caseNum;counter++){
		card cards[5];
		initialize(cards);
		sort(cards, cards + 5);  //  �������򣡣���
		do{
			if(cards[0].suit!=cards[1].suit)continue;
			int sum=cards[1].value,minIndex;
			card min(20,'Z');
			vector<card> toBeCmped;
			for (int k=2;k<5;k++)
				if(cards[k]<min){
					min=cards[k];
					minIndex=k;
				}
			for(int k=2;k<5;k++)
				if(k!=minIndex)toBeCmped.push_back(cards[k]);
			if(toBeCmped[0]<toBeCmped[1])sum+=(minIndex-1);
			else sum+=(minIndex-1)+3;
			if(sum%13==cards[0].value){
				printResult(counter,cards);
				break;
			}
		}while(next_permutation(cards,cards+5));
	}
	return 0;
}
