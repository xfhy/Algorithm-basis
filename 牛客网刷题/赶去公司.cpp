# include<iostream>
# include<math.h>

/*
链接：https://www.nowcoder.com/questionTerminal/5c7657015d3d49369c49dd047e80b526
来源：牛客网

终于到周末啦！小易走在市区的街道上准备找朋友聚会，突然服务器发来警报,小易需要立即回公司修复这个紧急bug。假设市区是一个无限大的区域，每条街道假设坐标是(X，Y)，小易当前在(0，0)街道，办公室在(gx,gy)街道上。小易周围有多个出租车打车点，小易赶去办公室有两种选择，一种就是走路去公司，另外一种就是走到一个出租车打车点，然后从打车点的位置坐出租车去公司。每次移动到相邻的街道(横向或者纵向)走路将会花费walkTime时间，打车将花费taxiTime时间。小易需要尽快赶到公司去，现在小易想知道他最快需要花费多少时间去公司。 
输入描述:

输入数据包括五行:
 第一行为周围出租车打车点的个数n(1 ≤ n ≤ 50)
 第二行为每个出租车打车点的横坐标tX[i] (-10000 ≤ tX[i] ≤ 10000)
 第三行为每个出租车打车点的纵坐标tY[i] (-10000 ≤ tY[i] ≤ 10000)
 第四行为办公室坐标gx,gy(-10000 ≤ gx,gy ≤ 10000),以空格分隔
 第五行为走路时间walkTime(1 ≤ walkTime ≤ 1000)和taxiTime(1 ≤ taxiTime ≤ 1000),以空格分隔


输出描述:

输出一个整数表示，小易最快能赶到办公室的时间
示例1
输入

2 -2 -2 0 -2 -4 -2 15 3
输出

42
*/

using namespace std;

//计算街道的距离
int streetDistance(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int main(void){

	int n; //周围的打车点
	int walkTime;  //走路 移动到相邻的街道 需要花费的时间
	int taxiTime;  //打车 移动到相邻的街道 需要花费的时间
	int gx,gy;     //公司的坐标

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

	//先计算纯走路需要花费的时间walkAllTime
	int walkAllTime = streetDistance(0,0,gx,gy)*walkTime;

	//计算走路到打车点 加 打车
	int taxiTimeAll=2147483647;
	for(int i=0;i<n;i++){
		//到达某一个打车点  计算走路到打车点需要花费的时间taxiTimeF
		int tempTaxi = streetDistance(0,0,streetX[i],streetY[i])*walkTime;
		//再计算从打车点到公司需要花费的时间taxiTimeS
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