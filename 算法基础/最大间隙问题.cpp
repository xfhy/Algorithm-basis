

/*
2016年9月26日21:24:34
最大间隙问题 
  给定n个实数x1,x2,...,xn,求这n个实数在实轴上相邻2个数之间的最大差值,
  要求设计线性的时间算法
*/

#include <iostream>
#define FILENAMELENGTH 50
using namespace std;

//声明函数
template<class T>
int indexofmin(int n,T *x);

template<class T>
int indexofmax(int n,T *x);

//类
class CMaxGap
{
public:

    int m_nCount;        //数据的个数
    double m_dblMaxGap;    //最大间隙
    double *m_dblNumber;//存放数据的数组

    CMaxGap(const char *filename);
    ~CMaxGap();

    double GetMaxGap(int n,double *x);
    void Display();
};

//读入数据
CMaxGap::CMaxGap(const char *filename)
{
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("can not open file!");
        exit(0);
    }

    //读入数据个数
    fscanf(fp,"%d",&m_nCount);

    m_dblNumber=new double[m_nCount];
    //读入每个具体的数据
    for(int i=0;i<m_nCount;i++)
        fscanf(fp,"%lf",&m_dblNumber[i]);

    m_dblMaxGap=0;
    fclose(fp);
}

CMaxGap::~CMaxGap()
{
    delete[] m_dblNumber;
    m_dblNumber=NULL;
}

//获取n个数据的最大间隙,存放在以x为开始地址的单元中,数据下标为0,1,...,n-1
double CMaxGap::GetMaxGap(int n,double *x)
{
    //找到最大最小数据,考虑到浮点型数据在传递过程中可能会有微小的变化
    //故采取取其下标的方式,在直接读取
    int minindex=indexofmin(n,x);
    int maxindex=indexofmax(n,x);
    double minx=x[minindex];
    double maxx=x[maxindex];

    //用n-2个点等分区间[minx,maxx],产生n-1个桶,桶编号1,2,...,n-2,n-1
    //且桶i的上界和桶i+1的下届相同
    double dblAvrGap=(maxx-minx)/(n-1);    //每个等分区间大小,即每个桶的大小
    int *count=new int[n];        //实际分到每个桶的数据个数
    double *low=new double[n];    //实际分到每个桶的最小数据
    double *high=new double[n];    //实际分到每个桶的最大数据

    //初始化桶
    for(int i=0;i<n;i++)
    {
        count[i]=0;
        low[i]=maxx;
        high[i]=minx;
    }

    int index;    //桶编号
    //将n个数放入n-1个桶中
    for(int i=0;i<n;i++)
    {
        //按如下规则将x[i]分配到某个桶(编号index)中
        //若x[i]=minx,则被分到第1个桶中(minx即为桶1的下界)
        //若x[i]=桶j的下界(也是桶j-1的上界),则按如下公式被分到桶j中(j>=1)
        index=int((x[i]-minx)/dblAvrGap)+1;

        //若x[i]=maxx,则被分到桶n中(max为桶n的下界桶n-1的上界)
        //    但没有桶n,此时可人为将其移入桶n-1中,或者再加一个桶
        //该步操作不影响下面的求最大间隙
        if(index==n)
            index--;

        count[index]++;    
        //调整分到该桶的最大最小数据
        if(x[i]<low[index])
            low[index]=x[i];
        if(x[i]>high[index])
            high[index]=x[i];
    }

    //除最大最小数据maxx和minx以外的n-2个数据被放入n-1个桶中
    //  由抽屉原理可知至少有一个桶是空的
    //又因每个桶的大小相同,所以最大间隙不会在同一桶中出现
    //  一定是某个桶的上界(dblHigh)和其后某个桶的下界(dblLow)之间隙
    //      注意:该两桶之间的桶(即编号在该两桶编号之间的桶)一定是空桶
    //  即最大间隙在桶i的上界和桶j的下界之间产生(j>=i+1)
    double dblMaxGap=0,dblHigh=high[1],dblTempGap;
    for(int i=2;i<n;i++)
    {
        if(count[i])    //该桶非空才计算
        {
            dblTempGap=low[i]-dblHigh;
            if(dblMaxGap<dblTempGap)
                dblMaxGap=dblTempGap;
            dblHigh=high[i];
        }
    }

    //释放
    delete[] count;
    count=NULL;
    delete[] low;
    low=NULL;
    delete[] high;
    high=NULL;

    m_dblMaxGap=dblMaxGap;
    return dblMaxGap;
}

void CMaxGap::Display()
{
    printf("   %d numbers:   ",m_nCount);
    for(int i=0;i<m_nCount;i++)
    {
        printf("%.2f ",m_dblNumber[i]);
    }
    printf("   the max gap is: %.2f ",m_dblMaxGap);
}

//求数组中最小数据的下标
template<class T>
int indexofmin(int n,T *x)
{
    int index;
    T temp=x[0];
    for(int i=1;i<n;i++)
    {
        if(x[i]<temp)
        {
            temp=x[i];
            index=i;
        }
    }
    return index;
}

//求数组中最大数据的下标
template<class T>
int indexofmax(int n,T *x)
{
    int index;
    T temp=x[0];
    for(int i=1;i<n;i++)
    {
        if(x[i]>temp)
        {
            temp=x[i];
            index=i;
        }
    }
    return index;
}

//显示菜单
void show_menu()
{
    printf("--------------------------------------------- ");
    printf("input command to test the program ");
    printf("   i or I : input filename to test ");
    printf("   q or Q : quit ");
    printf("--------------------------------------------- ");
    printf("$ input command >");
}

int main()
{
    char sinput[10];
    char sfilename[FILENAMELENGTH];

    show_menu();

    scanf("%s",sinput);
    while(stricmp(sinput,"q")!=0)
    {
        if(stricmp(sinput,"i")==0)
        {
            printf("  please input a filename:");
            scanf("%s",sfilename);

            //求文件中数据的最大间隙
            CMaxGap gap(sfilename);
            double dblMaxGap=gap.GetMaxGap(gap.m_nCount,gap.m_dblNumber);
            gap.Display();
        }

        //输入命令
        printf("$ input command >");
        scanf("%s",sinput);
    }
    return 0;
}
