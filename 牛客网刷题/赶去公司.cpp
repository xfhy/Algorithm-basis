# include<iostream>
# include<math.h>

/*
���ӣ�https://www.nowcoder.com/questionTerminal/5c7657015d3d49369c49dd047e80b526
��Դ��ţ����

���ڵ���ĩ����С�����������Ľֵ���׼�������ѾۻᣬͻȻ��������������,С����Ҫ�����ع�˾�޸��������bug������������һ�����޴������ÿ���ֵ�����������(X��Y)��С�׵�ǰ��(0��0)�ֵ����칫����(gx,gy)�ֵ��ϡ�С����Χ�ж�����⳵�򳵵㣬С�׸�ȥ�칫��������ѡ��һ�־�����·ȥ��˾������һ�־����ߵ�һ�����⳵�򳵵㣬Ȼ��Ӵ򳵵��λ�������⳵ȥ��˾��ÿ���ƶ������ڵĽֵ�(�����������)��·���Ứ��walkTimeʱ�䣬�򳵽�����taxiTimeʱ�䡣С����Ҫ����ϵ���˾ȥ������С����֪���������Ҫ���Ѷ���ʱ��ȥ��˾�� 
��������:

�������ݰ�������:
 ��һ��Ϊ��Χ���⳵�򳵵�ĸ���n(1 �� n �� 50)
 �ڶ���Ϊÿ�����⳵�򳵵�ĺ�����tX[i] (-10000 �� tX[i] �� 10000)
 ������Ϊÿ�����⳵�򳵵��������tY[i] (-10000 �� tY[i] �� 10000)
 ������Ϊ�칫������gx,gy(-10000 �� gx,gy �� 10000),�Կո�ָ�
 ������Ϊ��·ʱ��walkTime(1 �� walkTime �� 1000)��taxiTime(1 �� taxiTime �� 1000),�Կո�ָ�


�������:

���һ��������ʾ��С������ܸϵ��칫�ҵ�ʱ��
ʾ��1
����

2 -2 -2 0 -2 -4 -2 15 3
���

42
*/

using namespace std;

//����ֵ��ľ���
int streetDistance(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main(void){

	int n; //��Χ�Ĵ򳵵�
	int walkTime;  //��· �ƶ������ڵĽֵ� ��Ҫ���ѵ�ʱ��
	int taxiTime;  //�� �ƶ������ڵĽֵ� ��Ҫ���ѵ�ʱ��
	int gx,gy;     //��˾������

	cin>>n;
	int *streetX = new int[n];
	int *streetY = new int[n];

	for(int i=0;i<n;i++){
		cin>>streetX[i];
	}

	for(int i=0;i<n;i++){
		cin>>streetY[i];
	}

	cin>>gx>>gy>>walkTime>>taxiTime;

	//�ȼ��㴿��·��Ҫ���ѵ�ʱ��walkAllTime
	int walkAllTime = streetDistance(0,0,gx,gy)*walkTime;

	//������·���򳵵� �� ��
	int taxiTimeAll=2147483647;
	for(int i=0;i<n;i++){
		//����ĳһ���򳵵�  ������·���򳵵���Ҫ���ѵ�ʱ��taxiTimeF
		int tempTaxi = streetDistance(0,0,streetX[i],streetY[i])*walkTime;
		//�ټ���Ӵ򳵵㵽��˾��Ҫ���ѵ�ʱ��taxiTimeS
		int taxiTimeS=streetDistance(streetX[i],streetY[i],gx,gy)*taxiTime;
		if( (tempTaxi+taxiTimeS) < taxiTimeAll){
			taxiTimeAll = tempTaxi+taxiTimeS;
		}
	}

	if(walkAllTime>taxiTimeAll){
		cout<<taxiTimeAll;
	} else {
		cout<<walkAllTime;
	}

	return 0;
}