#include "LZ77.hpp"

int main()
{
	LZ77 lz;
	string compress;
	cout << "Ҫѹ�����ļ���" << endl;
	cin >> compress;
	lz.CompressFile(compress);

	string uncompress;
	cout << "Ҫ��ѹ�����ļ���" << endl;
	cin >> uncompress;

	lz.UNCompressfile(uncompress);
	return 0;
}