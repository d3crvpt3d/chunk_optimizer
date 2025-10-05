#include "header/chunk.hpp"

int main(){
	
	Chunk64_t original_data = {{{0xCF}}};

	optimize_chunk(original_data);
}
