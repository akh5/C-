#include <iostream>
#include "common.h"
#include <string.h>

class LZHashTable
{
public:
	LZHashTable(USH size)
		:_pre(new USH[size * 2])
		, _head(_pre	 + size)
	{
		memset(_pre, 0, size * 2 * sizeof(USH));
	}

	~LZHashTable()
	{
		delete[] _pre;
		_pre = nullptr;
	}
	void Insert(USH &matchHead, UCH ch, USH pos, USH& hashAddr)
	{
		HashFunc(hashAddr, ch);
		matchHead = _head[hashAddr];
		_pre[pos&HASH_MASK] = _head[hashAddr];
		_head[hashAddr] = pos;
	}

	void HashFunc(USH& hashAddr, UCH ch)
	{
		hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
		
	}
	USH H_SHIFT()
	{
		return (HASH_BITS + MIN_MAT - 1) / MIN_MAT;
	}	USH hashAddr;

	USH GetNext(USH matchHead)
	{
		return _pre[matchHead&HASH_MASK];
	}
	void Update()
	{
		for (USH i = 0; i < WSIZE; ++i)
		{
			if (_head[i] >= WSIZE)
				_head[i] -= WSIZE;
			else
				_head[i] = 0;

			if (_pre[i] >= WSIZE)
				_pre[i] -= WSIZE;
			else
				_pre[i] = 0;
		}
	}
private:
	const USH HASH_BITS = 15;
	const USH HASH_SIZE = (1 << HASH_BITS);
	const USH HASH_MASK = HASH_SIZE - 1;
	USH *_pre;
	USH *_head;
	
};