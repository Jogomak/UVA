#include <iostream>
#include <string>

using namespace std;

void return_blocks_from(int positions[25][2], int piles[25][26], int block, int block_position){
	int i = positions[block][1] + 1;
	int temp_block = piles[block_position][i];
	while(temp_block != -1){
		piles[temp_block][0] = temp_block;
		piles[temp_block][1] = -1;
		positions[temp_block][0] = temp_block;
		positions[temp_block][1] = 0;
		i++;
		temp_block = piles[block_position][i];
	}
}

int main(){
	int number_of_blocks;
	int block1;
	int block2;
	int block1_position;
	int block2_position;
	int command;
	string what;
	string where;
	
	int j;
	int i;
	int temp_block;
	int temp_position;
	
	cin >> number_of_blocks;
	
	//int piles[number_of_blocks][number_of_blocks + 1];
	int piles[25][26];
	int positions[25][2];
	
	for(i = 0; i < number_of_blocks; i++){
		piles[i][0] = i;
		piles[i][1] = -1;
		positions[i][0] = i; //which pile
		positions[i][1] = 0; //which position in pile
	}
	
	while(1){
		cin >> what;
		if(what == "quit"){
			break;
		}
		
		cin >> block1 >> where >> block2;
		
		command = 0;
		if(what == "pile"){
			command += 2;
		}
		if(where == "over"){
			command += 1;
		}
		
		block1_position = positions[block1][0];
		block2_position = positions[block2][0];
		
		if(block1_position != block2_position){
			switch(command){
				case 0:
					return_blocks_from(positions, piles, block1, block1_position); //remove blocks from top of block1
					piles[block1_position][positions[block1][1]] = -1; //remove block1
					
					return_blocks_from(positions, piles, block2, block2_position);
					
					piles[block2_position][positions[block2][1] + 1] = block1;
					piles[block2_position][positions[block2][1] + 2] = -1;
					positions[block1][0] = block2_position;
					positions[block1][1] = positions[block2][1] + 1;
					
					break;
				case 1:
					return_blocks_from(positions, piles, block1, block1_position);
					piles[block1_position][positions[block1][1]] = -1;
					
					i = positions[block2][1] + 1;
					while(piles[block2_position][i] != -1){
						i++;
					}
					
					piles[block2_position][i] = block1;
					piles[block2_position][i + 1] = -1;
					positions[block1][0] = block2_position;
					positions[block1][1] = i;
					
					break;
				case 2:
					return_blocks_from(positions, piles, block2, block2_position);
					
					i = positions[block1][1];
					
					while(piles[block1_position][i] != -1){
						temp_block = piles[block1_position][i];
						temp_position = positions[block2][1] + 1 - positions[block1][1] + i;
						piles[block2_position][temp_position] = temp_block;
						positions[temp_block][0] = block2_position;
						positions[temp_block][1] = temp_position;
						i++;
					}
					
					piles[block2_position][positions[block2][1] + 1 - piles[block1_position][1] + i] = -1;
					piles[block1_position][positions[block1][1]] = -1;
			
					break;
				case 3:
					i = positions[block1][1] + 1;
					j = positions[block2][1];
					
					while(piles[block2_position][j] != -1){
						j++;
					}
					
					while(piles[block1_position][i] != -1){
						temp_block = piles[block1_position][i];// cout << temp_block << endl;
						temp_position = j - positions[block1][1] + i;
						piles[block2_position][temp_position] = temp_block;
						positions[temp_block][0] = block2_position;
						positions[temp_block][1] = temp_position;
						i++;
					}
					
					piles[block2_position][j - positions[block1][1] + i] = -1;
					piles[block1_position][positions[block1][1]] = -1;
					piles[block2_position][j] = block1;
					positions[block1][0] = block2_position;
					positions[block1][1] = j;

					break;
			}
		}
	}
	
	for(i = 0; i < number_of_blocks; i++){
		cout << i << ':';
		int j = 0;
		while(piles[i][j] != -1){
			cout << ' ' << piles[i][j];
			j++;
		}
		if(i != number_of_blocks - 1){
			cout << '\n';
		}
	}
}