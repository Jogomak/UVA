#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int count_move_bootles(int bins[9], int bin1, int bin2, int bin3){ //bin - 0-b, 1-g, 2-c - bootles which stay in bin
	int bootles_moved = 0;
	
	for(int i = 0; i < 9; i++){
		bootles_moved += bins[i];
	}
	
	bootles_moved = bootles_moved - bins[bin1] - bins[3 + bin2] - bins[6 + bin3];
	
	return bootles_moved;
}

int main() {
	int bins[9];
	int min;
	int bootles_moved;
	string order;
	
	while(cin >> bins[0] >> bins[1] >> bins[2] >> bins[3] >> bins[4] >> bins[5] >> bins[6] >> bins[7] >> bins[8]){
		min = INT_MAX;
		order = "";
		
		bootles_moved =  count_move_bootles(bins, 0, 2, 1);
		if(bootles_moved < min){
			min = bootles_moved;
			order = "BCG";
		}
		
		bootles_moved =  count_move_bootles(bins, 0, 1, 2);
		if(bootles_moved < min){
			min = bootles_moved;
			order = "BGC";
		}
		
		bootles_moved =  count_move_bootles(bins, 2, 0, 1);
		if(bootles_moved < min){
			min = bootles_moved;
			order = "CBG";
		}
		
		bootles_moved =  count_move_bootles(bins, 2, 1, 0);
		if(bootles_moved < min){
			min = bootles_moved;
			order = "CGB";
		}
		
		bootles_moved =  count_move_bootles(bins, 1, 0, 2);
		if(bootles_moved < min){
			min = bootles_moved;
			order = "GBC";
		}
		
		bootles_moved =  count_move_bootles(bins, 1, 2, 0);
		if(bootles_moved < min){
			min = bootles_moved;
			order = "GCB";
		}
		
		cout << order << ' ' << min << '\n';
	}
	
    return 0;
}