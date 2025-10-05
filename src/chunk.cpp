#include "header/chunk.hpp"
#include <cstdint>

int optimize_chunk(Chunk64_t &chunk){

	Chunk64_t new_chunk = {{{0}}};

	for(uint8_t z = 0; z < 64; z++){

		for(uint8_t y = 0; y < 64; y++){

			
			//left+right no block
			new_chunk[z][y] |= chunk[z][y] & ~((chunk[z][y] << 1) & (chunk[z][y] >> 1));

			//bottom+top no block
			//set new_chunk[z][y] to chunk[z][y] if y border of chunk
			if(y == 0 | y == 63){
				new_chunk[z][y] |= chunk[z][y];
			}else{
				new_chunk[z][y] |= chunk[z][y] & ~((chunk[z][y-1]) & (chunk[z][y+1]));
			}

			//near+far no block
			//set new_chunk[z][y] to chunk[z][y] if z border of chunk
			if(z == 0 | z == 63){
				new_chunk[z][y] |= chunk[z][y];
			}else{
				new_chunk[z][y] |= chunk[z][y] & ~((chunk[z-1][y]) & (chunk[z+1][y]));
			}

		}
	
	}

	return 0;
}
