#include <iostream>
#include <cstdlib>

using namespace std;

/*
���ӣ�https://www.nowcoder.com/questionTerminal/79ed2f61eef7448aab10ef9677382e7e
��Դ��ţ����

С����һ��n*n�����̣����̵�ÿһ�����Ӷ�Ϊ��ɫ���߰�ɫ��С������Ҫ����ϲ���ĺ�ɫȥͿ�����̡�С�׻��ҳ�������ĳһ����ӵ����ͬ��ɫ����������ȥͿ��������С����������Ϳ�����ٸ���� 
��������:

�������ݰ���n+1�У�
 ��һ��Ϊһ������n(1 �� n �� 50),�����̵Ĵ�С
 ��������n��ÿ��һ���ַ�����ʾ��i�����̵���ɫ��'W'��ʾ��ɫ��'B'��ʾ��ɫ


�������:

���С�׻�Ϳ���������С
ʾ��1
����

3 BWW BBB BWB
���

3


˼·:ѭ������ÿһ��  ��һ�е��Ǹ��ַ��������ֵĴ������,����Ǵ��� 
*/

int main(int argc, char** argv) {
    int n;
    cin>>n;
    char a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    int max = 0;
    for(int i=0;i<n;i++){
        int temp = 0;
        char last = a[0][i];
        for(int j=1;j<n;j++){
            if(a[j][i]==last){
            	if(temp==0){
					temp = 2;
				} else {
					temp++;
				}
            } else {
				temp = 0;
			}
            if(temp>max){
                max = temp;
            }
            last = a[j][i];
        }
    }
    
    cout<<max;
    
    return 0;
}


