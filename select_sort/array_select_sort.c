#include <stdlib.h>
#include <string.h>

int array_select_sort(void *arr, int size, int esize,
		      int (*comp) (void *e1, void *e2))
{
	void *tmp;
	void *min;

	if ((tmp = malloc(esize)) == NULL) {
		return -1;
	}

	for (int i = 0; i < size - 1; i++) {
		min = arr + i * esize;
		for (int j = i + 1; j < size; j++) {
			if (comp(min, arr + j * esize) > 0) {
				min = arr + j * esize;
			}

		}

		memcpy(tmp, min, esize);
		memcpy(min, arr + i * esize, esize);
		memcpy(arr + i * esize, tmp, esize);
	}

	free(tmp);

	return 0;
}
