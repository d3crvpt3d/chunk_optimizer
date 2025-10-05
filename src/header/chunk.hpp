#ifndef CHUNK_HEADER
#define CHUNK_HEADER

#include <array>
#include <cstdint>
typedef	std::array<std::array<uint64_t, 64>, 64> Chunk64_t;

int optimize_chunk(Chunk64_t &in_chunk);

#endif
