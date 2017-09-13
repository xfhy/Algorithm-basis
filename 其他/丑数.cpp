# include <iostream>

using namespace std;

/**
description
author xfhy
create at
*/

bool isUlgy(int a){
	if(a<1){
		return false;
	}
	if(a==1){
		return true;
	}
	
	while(a%2==0 ){
		a /= 2;
	}
	while(a%3==0){
		a /= 3;
	}
	while(a%5==0){
		a /= 5;
	}
	
	if(a==1){
		return true;
	} else {
		return false;
	}
	
}

int main(void)
{
	for(int i=0;i<20;i++){
		if(isUlgy(i)){
			cout<<i<<"ÊÇ³óÊý"<<endl; 
		}
	}
	return 0;
}

