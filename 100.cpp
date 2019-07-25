#include <iostream>

using namespace std;

int main() {
	int start_number;
	int stop_number;
	int actual_number;
	int cycle_length;
	int max_cycle_length;
	int temp;
	int i;
	
	while(cin >> start_number >> stop_number){
		int add = 1;
		if(start_number > stop_number){
			add = -1;
		}
		max_cycle_length = 0;
		
		for(int i = start_number; i != stop_number + add; i += add){
			actual_number = i;
			cycle_length = 1;
			
			while(actual_number != 1){
				if(actual_number % 2){
					actual_number = actual_number * 3 + 1;
				}else{
					actual_number = actual_number / 2;
				}
				cycle_length++;
			}
			
			if(cycle_length > max_cycle_length){
				max_cycle_length = cycle_length;
			}
		}
		
		cout << start_number << ' ' << stop_number << ' ' << max_cycle_length << endl;
	}
	
    return 0;
}