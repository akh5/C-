#include<stdio.h>
#include "FileCompressHuff.h"
#include "HuffmanTree.hpp"

int main(){
	FileCompressHuff fc;
	fc.CompressFile("1.txt");
	return 0;
}