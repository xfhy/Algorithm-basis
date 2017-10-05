# include <iostream>

using namespace std;

/**
description
author xfhy
create at
*/
int fishSize[1001]; 
int sum[1001] = {0};
int main(void)
{
	int minSize,maxSize,n;
	cin>>minSize>>maxSize>>n;
	int index=1;
	 while(index<=n){
	 	cin>>fishSize[index]; 
	 	for(int i=minSize;i<=maxSize;i++){
	 		//±»³ÔÁË 
		 	if( (i>=2*fishSize[index] && i<=10*fishSize[index]) || (i<=fishSize[index]/2.0 && i>=(fishSize[index]/10.0))){
			 	sum[i]=1;
			 } 
		 }
		 index++;
	 } 
	 
	 int result=0;
	 for(int i=minSize;i<=maxSize;i++){
	 	if(sum[i]==0){
		 	result++;
		 }
	 }
	 cout<<result;
	return 0;
}

