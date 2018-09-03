#include <stddef.h>

typedef unsigned int UINT;
typedef char CHAR, *PCHAR;


UINT Hash_Meiyan(const char *str, size_t wrdlen);
UINT HashMurmur3(const CHAR* key, size_t len);
