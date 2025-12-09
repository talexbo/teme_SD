#include <iostream>
#include <queue>

std::queue<int> coadaSarpelui;

void citireMatricePatratica(int** mat, int n){
    for (int i = 0; i < n; i++) {
        mat[i] = new int[n];
            for (int j = 0; j<n; j++){
                std::cin >> mat[i][j];
        }
    }
}
void afisareMatrice(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void taieAltDiag(int** mat, int n) {
    for (int diagSecIter = 0; diagSecIter < 2 * n - 1; diagSecIter++) {
        // Loop cu diagonale SV-NE, care sunt 2n-1 la numar
        
        bool invers = (diagSecIter % 2 == 1); 
        
        // invers == false schimba direcția de la cea initiala, 
        // SV-NE pt diagonala 1 formata din elementul a_11 la 
        // directia specifica paritatii diagonalei

        int latime = 0;

        //i+j pe diagonale au val 0 1 2 ... max ... 2 1 0 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i + j == diagSecIter) {
                    latime++;
                    // parcurge matricea si creste dimensiunea 
                    // vectorului care stocheaza temporar matricile
                    // sau latimea diagonalei in iteratia respectiva.
                }
            }
        }

        int* diagonalaTmp = new int[latime];

        int ordine = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i + j == diagSecIter) {
                    diagonalaTmp[ordine] = mat[i][j];
                    ordine++;
                }
            }
        }

        // Push în coadă a elementelor in ordinea corecta
        // in functie de ordinea din vector
        if (invers) {
            // ordine spre SV
            for (int i = 0; i < latime; i++) {
                coadaSarpelui.push(diagonalaTmp[i]);
            }
        } else {
            // ordine spre NE
            for (int i = latime - 1; i >= 0; i--) {
                coadaSarpelui.push(diagonalaTmp[i]);
            }
        }
        delete[] diagonalaTmp;
    }
}
int main() {
    int n;
    std::cout << "n = ";
    std::cin >> n;
    int** mat = new int*[n];
    std::cout << "scrie matricea:\n";
    citireMatricePatratica(mat, n);
    std::cout << std::endl;
    taieAltDiag(mat, n);
    while (!coadaSarpelui.empty()) {
        std::cout << coadaSarpelui.front() << " ";
        coadaSarpelui.pop();
    }
    for (int i = 0; i < n; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
    std::cout << std::endl;
    
    return 0;
}