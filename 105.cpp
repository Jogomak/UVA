#include <iostream>

using namespace std;

int main(){
	int city_height[10001];
	int building_start;
	int building_end;
	int building_height;
	int city_end = 0;
	
	for(int i = 0; i < 10001; i++){
		city_height[i] = 0;
	}
	
	while(cin >> building_start >> building_height >> building_end){
		if(building_height != 0){
			for(int i = building_start; i < building_end; i++){
				if(city_height[i] < building_height){
					city_height[i] = building_height;
				}
			}
		
			if(building_end > city_end){
				city_end = building_end;
			}
		}
	}
	
	int current_height = 0;
	for(int i = 0; i < city_end; i++){
		if(city_height[i] > current_height){
			current_height = city_height[i];
			cout << i << ' ' << current_height << ' ';
		}else if(city_height[i] < current_height){
			current_height = city_height[i];
			cout << i << ' ' << current_height << ' ';
		}
	}
	cout << city_end << ' ' << city_height[city_end];
	
	return 0;
}