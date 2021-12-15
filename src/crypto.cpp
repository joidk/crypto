#include <cmath>
#include <vector>
#include <iostream>
/*
void changeBase (int n, int m, int* nmsg) {

int size = sizeof(nmsg)/sizeof(int);
int mmsg[size];
	if(n != 10) {
		std::vector< std::vector<int> > v_mmsg(size);
		for(int i = 0; i < size; ++i) {
			for (int j = 0; j > -1; ++j) {
				int rest = nmsg[i]%10;
				nmsg[i] = (int)nmsg[i]/10;
				mmsg[i] = pow(rest,j);
				if(nmsg[i]<1) break;
			}
		}
		std::cout << nmsg[0] << std::endl;
	}
}
*/
void decToTer(int* decmsg) {

	int size = sizeof(decmsg)/sizeof(int);
	int termsg[size][3]; 

	for(int j = 0; j < size; ++j) {
		int i = 2;
		do{
			if(decmsg[j] != 0){
				termsg[j][i] = decmsg[j]%3;
				decmsg[j] = (int)decmsg[j]/3;
			}
			else termsg[j][i] = 0;
			--i;
		} while(i > -1);
	}

}

int main() {
	int i[2] = {2,11};
	decToTer(i);
	return 0;
}