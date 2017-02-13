/*
2016年11月4日13:15:16
旅行规划问题（贪心） 
G 先生想独自驾驶汽车从城市A到城市B。AB距离为Dist 千米，
油箱容量为C升，每升油行驶e千米，沿途有N个加油站，距A城的距离为Si，
油价分别为Pi。A点时，邮箱为空，起点油价为p。
求从A到B的最少费用。不能到达输出“No Solution !”
输入：Dsit C e p N
接下来N行输入每站的Si和Pi
输出：最少费用
Sample input
275.6 11.9 27.4 2.8 2
102.0 2.9
220.0 2.2
Sample output
26.946
*/
/*
float Dsit = 275.6;       //AB距离为Dist 千米
float c =  11.9;          //油箱容量为C升
float e = 27.4;           //每升油行驶e千米
float p = 2.8;            //起点油价 
int n = 2;                //加油站个数
float di[] = {102.0,220.0}; //距离A站距离
float pi[] = {2.9,2.2};     //每个加油站的油价 

float over[2]={0};    //表示第i站的余油量
float x[2]={0};       //表示第i站的加油量

void least()
{
	int i=0;
	float L = c*e;    //加满油能跑多远 
	do{
		if( (di[i+1]-di[i]) > L){
			cout<<"No Solution !"<<endl;
		}
		//在L内查找第1个低于i站油价的油站j;
		int j=0;
		while(j<n){
			if(pi[j]<pi[i]){
				break;
			}
		}
		
		if(j!=n){
			//over[i] 能到达j
			if( (over[i]*e) < (pi[j]-pi[i])){
				over[j] -= (di[j]-di[i])/e;
			} else {
				x[i] = (di[j]-di[i])/e-over[i];
			}
		} else {
			over[i] = c-over[i-1];
			over[i+1] = over[i]-(pi[i+1]-pi[i])/e;
		}
		i++;
	}while(i<n+1);
}*/

/*
算法描述
i=0;over[ ]=x[ ]=0;L=c*e;
do{  若（d[i+1]－d[i]>L） 输出无解，返回；
       在L内查找第1个低于i站油价的油站j;
	    if (j存在)
        	if (over[i] 能到达j)   计算到达j的余油over[j]
	   	else 在i站购买油x[i]，使其刚好到达j站
       else 在i站加满油,到达i+1站,并计算i+1站的余油
}while  i<n+1；
 
*/

#include<iostream>
using namespace std;
const int size=1000 ;
const double MAX=999999.0000 ;
struct STATION
{
       double s ;
       double p ;
}Station[size] ;
int N ;
double c, d, Dist ;
double cd ;
double Cost ;
bool CanReach ;
void Init()
{
     Station[0].s = 0.0 ;
  
     cd = c * d;
     Cost = 0.0;
     CanReach = true ;    
     for (int i = 1; i <= N; i++)
     {
     cin >> Station[i].s >> Station[i].p ;
    
     if ((Station[i].s - Station[i-1].s) > cd)
        CanReach = false ;
     }
     Station[N+1].p = 0.0 ;
     Station[N+1].s = Dist ;
}
int Find_MinStation(int be)
{
       double MinP = MAX;
       int Min_i = be + 1;
      
       for (int i=be+1; i<=N+1
            && (Station[i].s-Station[be].s) <= cd;
             i++)
       {
           if (Station[i].p < Station[be].p)
           {
           Min_i = i;
           break;
         }
          
           if (MinP > Station[i].p)
           {
           MinP=Station[i].p;
           Min_i=i;
           }
       }
      
       return Min_i;
}
void Done()
{
     double rest = 0.0 ;
     double dist = 0.0 ;
     double tmpCost = 0.0 ;   
     int k=0 ;
     int Next ;
    
     while (k <= N)
     {
            Next = Find_MinStation(k) ;
            dist = Station[Next].s - Station[k].s ;             
            if (Station[Next].p < Station[k].p)
            {               
               tmpCost = (dist / d - rest) * Station[k].p ;
               Cost += tmpCost ;
               rest = 0.0 ; // Next_rest
            }
            else
            {
               tmpCost = ( c - rest ) * Station[k].p ;//k_rest
               rest = c - dist / d ;// Next_rest
               Cost += tmpCost ;
            }    
   
            k = Next ;
     }      
}
int main()
{
    while (cin >> Dist >> c >> d >> Station[0].p >> N)
    {
          Init();
         
          if (CanReach == false)
          {
          cout << "No Solution!" << endl ;
          }
          else
          {
          Done();   
          cout << Cost << endl ;
          }
   
    }
    system("pause");
    return 0;
}