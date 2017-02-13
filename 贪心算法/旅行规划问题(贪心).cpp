/*
2016��11��4��13:15:16
���й滮���⣨̰�ģ� 
G ��������Լ�ʻ�����ӳ���A������B��AB����ΪDist ǧ�ף�
��������ΪC����ÿ������ʻeǧ�ף���;��N������վ����A�ǵľ���ΪSi��
�ͼ۷ֱ�ΪPi��A��ʱ������Ϊ�գ�����ͼ�Ϊp��
���A��B�����ٷ��á����ܵ��������No Solution !��
���룺Dsit C e p N
������N������ÿվ��Si��Pi
��������ٷ���
Sample input
275.6 11.9 27.4 2.8 2
102.0 2.9
220.0 2.2
Sample output
26.946
*/
/*
float Dsit = 275.6;       //AB����ΪDist ǧ��
float c =  11.9;          //��������ΪC��
float e = 27.4;           //ÿ������ʻeǧ��
float p = 2.8;            //����ͼ� 
int n = 2;                //����վ����
float di[] = {102.0,220.0}; //����Aվ����
float pi[] = {2.9,2.2};     //ÿ������վ���ͼ� 

float over[2]={0};    //��ʾ��iվ��������
float x[2]={0};       //��ʾ��iվ�ļ�����

void least()
{
	int i=0;
	float L = c*e;    //���������ܶ�Զ 
	do{
		if( (di[i+1]-di[i]) > L){
			cout<<"No Solution !"<<endl;
		}
		//��L�ڲ��ҵ�1������iվ�ͼ۵���վj;
		int j=0;
		while(j<n){
			if(pi[j]<pi[i]){
				break;
			}
		}
		
		if(j!=n){
			//over[i] �ܵ���j
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
�㷨����
i=0;over[ ]=x[ ]=0;L=c*e;
do{  ����d[i+1]��d[i]>L�� ����޽⣬���أ�
       ��L�ڲ��ҵ�1������iվ�ͼ۵���վj;
	    if (j����)
        	if (over[i] �ܵ���j)   ���㵽��j������over[j]
	   	else ��iվ������x[i]��ʹ��պõ���jվ
       else ��iվ������,����i+1վ,������i+1վ������
}while  i<n+1��
 
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