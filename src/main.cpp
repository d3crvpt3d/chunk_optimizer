/**
 * Generate optimized Tensor
 *
 *
 * @param dense Tensor
 * @return optimized Tensor
 */

#include <array>
#include <cstdint>
#include <iostream>
#include <bitset>

#define CHUNK_SIZE 8 //and change uintX_t

void print_plane(const std::array<uint8_t, CHUNK_SIZE + 2>& data, const std::string& title) {
    std::cout << "--- " << title << " ---" << std::endl;
    // Wir drucken von oben nach unten (y = HEIGHT-1 bis 0), wie man es erwarten würde
    for (int y = CHUNK_SIZE + 1; y >= 0; --y) {
        // std::bitset wandelt unseren uint8_t direkt in eine 01-Zeichenkette um
        std::cout << "y=" << y << ": " << std::bitset<CHUNK_SIZE>(data[y]) << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
}

int main(){

	//x,y,z
	std::array<std::array<uint8_t, CHUNK_SIZE + 2>, 1> in_data; //padding for out of bounds

	in_data = {	0x00, 0xFF, 0xC6, 0x81, 0x81,
				0xC3, 0xC7, 0xFF, 0xFF, 0x00};

	std::array<std::array<uint8_t, CHUNK_SIZE + 2>, 1> out_data = {};

	print_plane(in_data[0], "in_data");

	for(uint8_t z = 0; z < 1; z++){
		for(uint8_t y = 1; y < CHUNK_SIZE; y++){
		
			//left visible -x
			out_data[y][z] |= in_data[y][z] & ~(in_data[y][z] << 1);

			//right visible +x
			out_data[y][z] |= in_data[y][z] & ~(in_data[y][z] >> 1);

			//top visible +y
			out_data[y][z] |= in_data[y][z] & ~in_data[y+1][z];

			//bottom visible -y
			out_data[y][z] |= in_data[y][z] & ~in_data[y-1][z];

			//far visible +1
			out_data[y][z] |= in_data[y][z] & ~in_data[y][z+1];

			//near visible -1
			out_data[y][z] |= in_data[y][z] & ~in_data[y][z-1];

		}
	}

	print_plane(out_data[0], "out_data");

}
