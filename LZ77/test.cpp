#include "LZ77.hpp"

int main()
{
	LZ77 lz;
	lz.CompressFile("1.txt");

	lz.UNCompressfile("2.lzp");
	return 0;
}