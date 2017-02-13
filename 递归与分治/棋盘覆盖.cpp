#include <iostream>

using namespace std;
/*
2016��9��22��12:36:34
���̸��� 
��һ��2^k��2^k ��������ɵ������У�ǡ��һ����������������ͬ��
�Ƹ÷���Ϊһ���ⷽ���ҳƸ�����Ϊһ�������̡������̸��������У�
Ҫ��ͼʾ��4�ֲ�ͬ��̬��L�͹��Ƹ��Ǹ��������������ϳ����ⷽ����������з���
���κ�2��L�͹��Ʋ����ص����ǡ�

ʵ�֣�ÿ�ζ��Էָ����ĸ�С��������жϣ��ж����ⷽ���Ƿ������档
������жϵķ�����ÿ���ȼ�¼�������󷽿�����Ͻǣ�top left coner��������������꣬
Ȼ���������ⷽ��������бȽϣ��Ϳ���֪�����ⷽ���Ƿ��ڸÿ��С�
������ⷽ�������棬��ֱ�ӵݹ���ȥ�󼴿ɣ�������ڣ�����ݷָ���ĸ�����Ĳ�ͬλ�ã�
�����½ǡ����½ǡ����Ͻǻ������Ͻǵķ�����Ϊ���ⷽ�飬Ȼ������ݹ顣�ڵݹ麯���
��Ҫ��һ������s����¼�ߵķ�������ÿ�ζԷ�����л���ʱ���ߵķ�����������룬
���������Ϊ�˷����ж����ⷽ���λ�á���λ�Ҫ��һ����nCount����¼L�͹��Ƶ�������
*/

static int scale = 4;   //���̹�ģ 

int tile = 0;  //L�͹��Ƶ����� 

int **Board;   //��ά����,ģ������ 

//������ά���� 
void Make2DArray(int ** &x,int rows,int cols){
	x = new int *[rows];   //�� 
	for(int i=0; i<rows; i++){
		x[i] = new int[cols]; //�� 
	}
}

//���̸���  ����:���Ͻ�����(x,y) ���ⷽ������(x,y)  ���̴�С 
void chessBoard(int tr,int tc,int dr,int dc,int size){
	if(size==1){
		return ;
	}
	int t = ++tile;   //L�͹��� ���� 
	int s = size/2;   //�ָ����� 
	
	//�������Ͻ������� 
	if( dr <tr+s && dc < tc+s ) {
		//���ⷽ���ڴ������� 
		chessBoard(tr,tc,dr,dc,s);
	} else { //�������������ⷽ�� 
		//��t��L�͹��Ƹ������½� 
		Board[tr+s-1][tc+s-1] = t;
		chessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	
	//�������Ͻ������� 
	if(dr >= tr+s && dc < tc+s){
		chessBoard(tr+s,tc,dr,dc,s);
	} else {
		//��t��L�͹��Ƹ������½�
		Board[tr+s][tc+s-1] = t;
		chessBoard(tr+s,tc,tr+s,tc+s-1,s);
	}
	
	//���½� 
	if(dr < tr+s && dc >= tc+s){
		chessBoard(tr,tc+s,dc,dr,s);
	} else {
		//��t��L�͹��Ƹ������Ͻ�
		Board[tr+s-1][tc+s] = t;
		chessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}
	
	//���½� 
	if(dr >= tr+s && dc >= tc+s){
		chessBoard(tr+s,tc+s,dc,dr,s);
	} else {
		//��t��L�͹��Ƹ������Ͻ�
		Board[tr+s][tc+s] = t;
		chessBoard(tr+s,tc+s,tr+s,tc+s,s); 
	}
	
} 

int main(void)
{
	Make2DArray(Board,scale,scale);  //������ά����,���� 
	
	chessBoard(0,0,1,1,scale);       //�������� 
	
	Board[1][1] = 0;                 //�Ǹ�����.... 
	
	//������� 
	for(int i=0; i<scale; i++){
		for(int j=0; j<scale; j++){
			printf("%4d ",Board[i][j]);
		}
		printf("\n");
	} 
	
	return 0;
}
