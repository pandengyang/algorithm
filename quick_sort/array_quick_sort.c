#include <stdlib.h>
#include <string.h>

int array_quick_sort(void *arr, int size, int esize,
		     int (*comp) (void *e1, void *e2))
{
	void *tmp;

	if ((tmp = malloc(esize)) == NULL) {
		return -1;
	}

	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0; j--) {
			if (comp(arr + (j - 1) * esize, arr + j * esize) <=
			    0) {
				break;
			}

			memcpy(tmp, arr + j * esize, esize);
			memcpy(arr + j * esize, arr + (j - 1) * esize,
			       esize);
			memcpy(arr + (j - 1) * esize, tmp, esize);
		}
	}

	free(tmp);

	return 0;
}
