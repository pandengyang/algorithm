#include <stdlib.h>
#include <string.h>

int array_bubble_sort(void *arr, int size, int esize,
		      int (*comp) (void *e1, void *e2))
{
	void *tmp;

	if ((tmp = malloc(esize)) == NULL) {
		return -1;
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (comp(arr + (j - 1) * esize, arr + j * esize) >
			    0) {
				memcpy(tmp, arr + (j - 1) * esize, esize);
				memcpy(arr + (j - 1) * esize,
				       arr + j * esize, esize);
				memcpy(arr + j * esize, tmp, esize);
			}
		}
	}

	free(tmp);

	return 0;
}
