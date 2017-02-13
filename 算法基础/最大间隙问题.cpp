

/*
2016��9��26��21:24:34
����϶���� 
  ����n��ʵ��x1,x2,...,xn,����n��ʵ����ʵ��������2����֮�������ֵ,
  Ҫ��������Ե�ʱ���㷨
*/

#include <iostream>
#define FILENAMELENGTH 50
using namespace std;

//��������
template<class T>
int indexofmin(int n,T *x);

template<class T>
int indexofmax(int n,T *x);

//��
class CMaxGap
{
public:

    int m_nCount;        //���ݵĸ���
    double m_dblMaxGap;    //����϶
    double *m_dblNumber;//������ݵ�����

    CMaxGap(const char *filename);
    ~CMaxGap();

    double GetMaxGap(int n,double *x);
    void Display();
};

//��������
CMaxGap::CMaxGap(const char *filename)
{
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("can not open file!");
        exit(0);
    }

    //�������ݸ���
    fscanf(fp,"%d",&m_nCount);

    m_dblNumber=new double[m_nCount];
    //����ÿ�����������
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

//��ȡn�����ݵ�����϶,�������xΪ��ʼ��ַ�ĵ�Ԫ��,�����±�Ϊ0,1,...,n-1
double CMaxGap::GetMaxGap(int n,double *x)
{
    //�ҵ������С����,���ǵ������������ڴ��ݹ����п��ܻ���΢С�ı仯
    //�ʲ�ȡȡ���±�ķ�ʽ,��ֱ�Ӷ�ȡ
    int minindex=indexofmin(n,x);
    int maxindex=indexofmax(n,x);
    double minx=x[minindex];
    double maxx=x[maxindex];

    //��n-2����ȷ�����[minx,maxx],����n-1��Ͱ,Ͱ���1,2,...,n-2,n-1
    //��Ͱi���Ͻ��Ͱi+1���½���ͬ
    double dblAvrGap=(maxx-minx)/(n-1);    //ÿ���ȷ������С,��ÿ��Ͱ�Ĵ�С
    int *count=new int[n];        //ʵ�ʷֵ�ÿ��Ͱ�����ݸ���
    double *low=new double[n];    //ʵ�ʷֵ�ÿ��Ͱ����С����
    double *high=new double[n];    //ʵ�ʷֵ�ÿ��Ͱ���������

    //��ʼ��Ͱ
    for(int i=0;i<n;i++)
    {
        count[i]=0;
        low[i]=maxx;
        high[i]=minx;
    }

    int index;    //Ͱ���
    //��n��������n-1��Ͱ��
    for(int i=0;i<n;i++)
    {
        //�����¹���x[i]���䵽ĳ��Ͱ(���index)��
        //��x[i]=minx,�򱻷ֵ���1��Ͱ��(minx��ΪͰ1���½�)
        //��x[i]=Ͱj���½�(Ҳ��Ͱj-1���Ͻ�),�����¹�ʽ���ֵ�Ͱj��(j>=1)
        index=int((x[i]-minx)/dblAvrGap)+1;

        //��x[i]=maxx,�򱻷ֵ�Ͱn��(maxΪͰn���½�Ͱn-1���Ͻ�)
        //    ��û��Ͱn,��ʱ����Ϊ��������Ͱn-1��,�����ټ�һ��Ͱ
        //�ò�������Ӱ�������������϶
        if(index==n)
            index--;

        count[index]++;    
        //�����ֵ���Ͱ�������С����
        if(x[i]<low[index])
            low[index]=x[i];
        if(x[i]>high[index])
            high[index]=x[i];
    }

    //�������С����maxx��minx�����n-2�����ݱ�����n-1��Ͱ��
    //  �ɳ���ԭ���֪������һ��Ͱ�ǿյ�
    //����ÿ��Ͱ�Ĵ�С��ͬ,��������϶������ͬһͰ�г���
    //  һ����ĳ��Ͱ���Ͻ�(dblHigh)�����ĳ��Ͱ���½�(dblLow)֮��϶
    //      ע��:����Ͱ֮���Ͱ(������ڸ���Ͱ���֮���Ͱ)һ���ǿ�Ͱ
    //  ������϶��Ͱi���Ͻ��Ͱj���½�֮�����(j>=i+1)
    double dblMaxGap=0,dblHigh=high[1],dblTempGap;
    for(int i=2;i<n;i++)
    {
        if(count[i])    //��Ͱ�ǿղż���
        {
            dblTempGap=low[i]-dblHigh;
            if(dblMaxGap<dblTempGap)
                dblMaxGap=dblTempGap;
            dblHigh=high[i];
        }
    }

    //�ͷ�
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

//����������С���ݵ��±�
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

//��������������ݵ��±�
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

//��ʾ�˵�
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

            //���ļ������ݵ�����϶
            CMaxGap gap(sfilename);
            double dblMaxGap=gap.GetMaxGap(gap.m_nCount,gap.m_dblNumber);
            gap.Display();
        }

        //��������
        printf("$ input command >");
        scanf("%s",sinput);
    }
    return 0;
}
