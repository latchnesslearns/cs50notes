#include "hash.h"
#include <stddef.h>
#include <windows.h>

#define _rotl(x, n) (((x) << (n)) | ((x) >> (32-(n))))

UINT Hash_Meiyan(const char *str, size_t wrdlen)
{
    const UINT PRIME = 709607;
    UINT hash32 = 2166136261;
    const char *p = str;

    for(; wrdlen >= 2*sizeof(DWORD); wrdlen -= 2*sizeof(DWORD), p += 2*sizeof(DWORD)) {
        hash32 = (hash32 ^ (_rotl(*(DWORD *)p,5) ^ *(DWORD *)(p+4))) * PRIME;
    }
    // Cases: 0,1,2,3,4,5,6,7
    if (wrdlen & sizeof(DWORD)) {
		hash32 = (hash32 ^ *(WORD*)p) * PRIME;
		p += sizeof(WORD);
		hash32 = (hash32 ^ *(WORD*)p) * PRIME;
		p += sizeof(WORD);
    }
    if (wrdlen & sizeof(WORD)) {
        hash32 = (hash32 ^ *(WORD*)p) * PRIME;
        p += sizeof(WORD);
    }
    if (wrdlen & 1)
        hash32 = (hash32 ^ *p) * PRIME;

    return hash32 ^ (hash32 >> 16);
}

// Murmur3 hash (32-bit), http://code.google.com/p/smhasher/
UINT HashMurmur3(const char* key, size_t len)
{
	const UCHAR * word = (const UCHAR*)key;
	const int nblocks = len / 4;
	UINT32 h1 = 1688943522; // a random seed
	const UINT32 c1 = 0xcc9e2d51, c2 = 0x1b873593;

	// body
	const UINT32 * blocks = (const UINT32 *)(word + nblocks*4);

	for(int i = -nblocks; i; i++) {
		UINT32 k1 = blocks[i];

		k1 *= c1;
		k1 = _rotl(k1,15);
		k1 *= c2;

		h1 ^= k1;
		h1 = _rotl(h1,13);
		h1 = h1*5+0xe6546b64;
	}

	// tail
	const UINT8 * tail = (const UINT8*)(word + nblocks*4);
	UINT32 k1 = 0;

	switch(len & 3)
	{
	case 3: k1 ^= tail[2] << 16;
	case 2: k1 ^= tail[1] << 8;
	case 1: k1 ^= tail[0];
			k1 *= c1; k1 = _rotl(k1,15); k1 *= c2; h1 ^= k1;
	};

	// finalization
	h1 ^= len;

	h1 ^= h1 >> 16;
	h1 *= 0x85ebca6b;
	h1 ^= h1 >> 13;
	h1 *= 0xc2b2ae35;
	h1 ^= h1 >> 16;
	return h1;
}