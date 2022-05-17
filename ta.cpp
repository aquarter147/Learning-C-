#include <iostream>

using namespace std;

int main(){
	int k,a[7];
	cin >> k;
	for(int i=1;k-i>=0;i++){
		cin >> a[k-i];
	}
	for(int i =1;k+i<7;i++){
		cin >>a[k+i];
	}
	for(int i=0;i<7;i++){
		cout <<"\n"<<a[i];
	}
}