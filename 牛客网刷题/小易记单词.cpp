# include <iostream>
# include <string>
# include <vector>

using namespace std;

/**

2017��9��25��17:50:14
xfhy
С�׼ǵ��� 

���ӣ�https://www.nowcoder.com/questionTerminal/0b821b5d214445388eade1d304b976b2
��Դ��ţ����

С�ײ�����һ���ǵ��ʵ�С��Ϸ����Ϸ��ʼϵͳ�ṩ��m����ͬ�ĵ��ʣ�С�׼���һ��ʱ��֮����Ҫ��ֽ��д������ס�ĵ��ʡ�С��һ��д����n�����ܼ�ס�ĵ��ʣ����С��д���ĵ�������ϵͳ�ṩ�ģ������������ʳ��ȵ�ƽ���ķ�����ע��С��д���ĵ��ʿ����ظ������Ƕ���ÿ����ȷ�ĵ���ֻ�ܼƷ�һ�Ρ� 
��������:

�������ݰ������У�
 ��һ��Ϊ��������n(1 �� n �� 50)��m(1 �� m �� 50)���Կո�ָ�
 �ڶ���Ϊn���ַ�������ʾС���ܼ�ס�ĵ��ʣ��Կո�ָ���ÿ�����ʵĳ���С�ڵ���50��
 ������Ϊm���ַ�����ϵͳ�ṩ�ĵ��ʣ��Կո�ָ���ÿ�����ʵĳ���С�ڵ���50��


�������:

���һ��������ʾС���ܻ�õķ���
ʾ��1
����

3 4 apple orange strawberry strawberry orange grapefruit watermelon
���

136

*/ 

/*
�ж������Ƿ�������ַ��� 
*/
bool isExist(vector<string> str,string temp){
	int length = str.size();
	for(int i=0;i<length;i++){
		if( str[i].compare(temp) == 0 ){
			return true;
		}
	}
	return false;
}

int main(void)
{
	int n,m;
	cin>>n>>m;
	vector<string> remes;    //�������ĵ��� 
	
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		remes.push_back(temp);
	}
	
	int sum = 0; 
	for(int i=0;i<m;i++){
		string temp;
		cin>>temp;
		if(isExist(remes,temp)){
			sum += temp.length() * temp.length();
		}
	}
	
	cout<<sum;
	return 0;
}

