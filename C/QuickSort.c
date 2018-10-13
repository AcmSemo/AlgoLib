#include <stdio.h>
#include <stdlib.h>

/* Prototypes */

void quicksort(int* v, int p, int r);
int partition (int* v, int p, int r);
void printvetor(int v[], int size);

void printvetor(int v[], int size)
{
    int i;

    for (i=0; i < size; i++)

        printf("%d ", v[i]);

    printf("\n");
}


void quicksort(int* v, int p, int r) {

	if (p < r )
	{
		int q = partition(v, p, r); // middle
		quicksort(v, p, q-1);
		quicksort(v, q+1, r);
	}
}

int partition (int* v, int p, int r) {

	int x = v[r]; // pivot
	int i = p-1;  
	int j;

	for (j = p; i < r-1;)
	{
		if (v[j] <= x) 
		{
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
	}

			
			//swap(v[i+1], v[r]);
		int aux2 = v[r];
			v[r] = v[i+1];
			v[i+1] = aux2;


	return i+1;



}



