import java.util.*;
 
public class MergeSort {
     
    int vetor[];
    int vetorB[];
 
    public static void main(String[] args) {
        int v[] = {6, 8, 2, 234, 23, 90, 97, 5};
        mergeSort(v, 0, 7);
        for (int z = 0; z < v.length; z++) {
            System.out.print(v[z] + ", ");
        }
 
    }
 
    public static void mergeSort(int vetor[], int inicio, int fim) {
        int meio;
        if (inicio < fim) {
            meio = (inicio + fim) / 2;
            mergeSort(vetor, inicio, meio);
            mergeSort(vetor, meio + 1, fim);
            intercala(vetor, inicio, meio, fim);
        }
    }
 
    public static void intercala(int vetor[], int inicio, int meio, int fim) {
        int i, j, k;
        int vetorB[] = new int[vetor.length];
        for (i = inicio; i < meio; i++) {
            vetorB[i] = vetor[i];
        }
        for (j = meio + 1; j < fim; j++) {
            vetorB[fim + meio + 1 - j] = vetor[j];
        }
        i = inicio;
        j = fim;
        for (k = inicio; k < fim; k++) {
            if (vetorB[i] <= vetorB[j]) {
                vetor[k] = vetorB[i];
                i = i + 1;
            } else {
                vetor[k] = vetorB[j];
                j = j - 1;
            }
        }
    }
 
}