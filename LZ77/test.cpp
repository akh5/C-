#include "LZ77.hpp"

int main()
{
	LZ77 lz;
	string compress;
	cout << "要压缩的文件名" << endl;
	cin >> compress;
	lz.CompressFile(compress);

	string uncompress;
	cout << "要解压缩的文件名" << endl;
	cin >> uncompress;

	lz.UNCompressfile(uncompress);
	return 0;
}