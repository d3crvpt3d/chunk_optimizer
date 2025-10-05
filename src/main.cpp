#include "header/chunk.hpp"
#include <cstring>

int main(){
	
	Chunk64_t original_data = {};

	std::memset(original_data.data(), 0b11100111, sizeof(Chunk64_t));

	optimize_chunk(original_data);
}
