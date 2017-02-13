#include <iostream>

using namespace std;
/*
2016年9月22日12:36:34
棋盘覆盖 
在一个2^k×2^k 个方格组成的棋盘中，恰有一个方格与其他方格不同，
称该方格为一特殊方格，且称该棋盘为一特殊棋盘。在棋盘覆盖问题中，
要用图示的4种不同形态的L型骨牌覆盖给定的特殊棋盘上除特殊方格以外的所有方格，
且任何2个L型骨牌不得重叠覆盖。

实现：每次都对分割后的四个小方块进行判断，判断特殊方格是否在里面。
这里的判断的方法是每次先记录下整个大方块的左上角（top left coner）方格的行列坐标，
然后再与特殊方格坐标进行比较，就可以知道特殊方格是否在该块中。
如果特殊方块在里面，这直接递归下去求即可，如果不在，这根据分割的四个方块的不同位置，
把右下角、左下角、右上角或者左上角的方格标记为特殊方块，然后继续递归。在递归函数里，
还要有一个变量s来记录边的方格数，每次对方块进行划分时，边的方格数都会减半，
这个变量是为了方便判断特殊方格的位置。其次还要有一个变nCount来记录L型骨牌的数量。
*/

static int scale = 4;   //棋盘规模 

int tile = 0;  //L型骨牌的数量 

int **Board;   //二维数组,模拟棋盘 

//创建二维数组 
void Make2DArray(int ** &x,int rows,int cols){
	x = new int *[rows];   //横 
	for(int i=0; i<rows; i++){
		x[i] = new int[cols]; //竖 
	}
}

//棋盘覆盖  参数:左上角坐标(x,y) 特殊方格坐标(x,y)  棋盘大小 
void chessBoard(int tr,int tc,int dr,int dc,int size){
	if(size==1){
		return ;
	}
	int t = ++tile;   //L型骨牌 数量 
	int s = size/2;   //分割棋盘 
	
	//覆盖左上角子棋盘 
	if( dr <tr+s && dc < tc+s ) {
		//特殊方格在此棋盘中 
		chessBoard(tr,tc,dr,dc,s);
	} else { //次棋盘中无特殊方格 
		//用t号L型骨牌覆盖右下角 
		Board[tr+s-1][tc+s-1] = t;
		chessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	
	//覆盖右上角子棋盘 
	if(dr >= tr+s && dc < tc+s){
		chessBoard(tr+s,tc,dr,dc,s);
	} else {
		//用t号L型骨牌覆盖左下角
		Board[tr+s][tc+s-1] = t;
		chessBoard(tr+s,tc,tr+s,tc+s-1,s);
	}
	
	//左下角 
	if(dr < tr+s && dc >= tc+s){
		chessBoard(tr,tc+s,dc,dr,s);
	} else {
		//用t号L型骨牌覆盖右上角
		Board[tr+s-1][tc+s] = t;
		chessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}
	
	//右下角 
	if(dr >= tr+s && dc >= tc+s){
		chessBoard(tr+s,tc+s,dc,dr,s);
	} else {
		//用t号L型骨牌覆盖左上角
		Board[tr+s][tc+s] = t;
		chessBoard(tr+s,tc+s,tr+s,tc+s,s); 
	}
	
} 

int main(void)
{
	Make2DArray(Board,scale,scale);  //创建二维数组,棋盘 
	
	chessBoard(0,0,1,1,scale);       //覆盖棋盘 
	
	Board[1][1] = 0;                 //那个坏点.... 
	
	//输出棋盘 
	for(int i=0; i<scale; i++){
		for(int j=0; j<scale; j++){
			printf("%4d ",Board[i][j]);
		}
		printf("\n");
	} 
	
	return 0;
}
