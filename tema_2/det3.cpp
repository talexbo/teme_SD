#include <iostream>

void dDealoc(double** mat, int n) {
    for (int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

void dAfisareMatrice(double** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double** minor(double** mat, int n, int xMin, int yMin) {
    
    double **minor = new double*[n-1];
    for (int i = 0; i < n-1; i++) {
        minor[i] = new double[n-1];
    }

    int linMinor = 0;
    for (int i = 0; i < n; i++) {
        if (i != xMin) {
            int colMinor = 0;        
            for (int j = 0; j < n; j++) {
                if (j != yMin) {
                    minor[linMinor][colMinor] = mat[i][j];
                    colMinor++;
                }
            }
            linMinor++;
        }
    }
    return minor;
}

double detDoi(double** mat) {
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

double determinant(double** mat, int n) {
    
    double det = 0;

    if (n == 1) {
        std::cout << "1x1 nu e o dimensiune pentru care ai nevoie de un program";
        return mat[0][0];
    }
    if (n == 2) {
        return detDoi(mat);
    }

    for (int j = 0; j < n; j++) {
        double** min = minor(mat, n, 0, j);
        int signatura;
        if (j % 2 == 0) {
            signatura = 1;
        }
        else {
            signatura = -1;
        }

        double deltaMinor = determinant(min, n - 1);
        
        det += signatura * mat[0][j] * deltaMinor;
        dDealoc(min, n - 1); // dealoca minorul
    }
  
    return det;
}

void minoriRecursivi(double** mat,int n){
    // functie de verificare care imi scrie minorii cu min[0][j] si signatura 
    // unii sub altii ca sa pot sa fac calculul de mana mai repede. 
    
    if (n == 1 || n==2) {
        return;
    }

    for (int j = 0; j < n; j++) {
        double** min = minor(mat, n, 0, j);

        int signatura;
        if (j % 2 == 0) {
            signatura = 1;
        }
        else {
            signatura = -1;
        }

        std::cout << signatura << " * " << mat[0][j] << std::endl;
        dAfisareMatrice(min, n - 1);
        std::cout << std::endl;

        dDealoc(min, n - 1);
    }
}

int main() {
    int n;
    std::cout << "n = ";
    std::cin >> n;

    double** a = new double*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    //minoriRecursivi(a, n);

    std::cout << "A=\n";
    dAfisareMatrice(a, n);
    std::cout << "det(A) = " << determinant(a, n) << std::endl;
    
    dDealoc(a, n);
    return 0;
}
