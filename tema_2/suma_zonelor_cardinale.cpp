#include <iostream>
int main(){
    int n, sNord=0, sSud=0, sVest=0, sEast=0;
    std::cout<<"n="; std::cin >> n;
    int** a = new int*[n];
    for (int i = 0; i<n; i++){
        a[i]=new int[n];
        for (int j = 0; j<n; j++){
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if(i<j && i+j<n-1){
                sNord=sNord+a[i][j];
            }
            if(i>j && i+j<n-1){
                sVest=sVest+a[i][j];
            }
            if(i>j && i+j>n-1){
                sSud=sSud+a[i][j];
            }
            if(i<j && i+j>n-1){
                sEast=sEast+a[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i){
        delete [] a[i];
    }
    delete [] a;
    
    std::cout << "suma elementelor din zona cardinală N este " << sNord << std::endl;
    std::cout << "suma elementelor din zona cardinală S este " << sSud << std::endl; 
    std::cout << "suma elementelor din zona cardinală V este " << sVest << std::endl;
    std::cout << "suma elementelor din zona cardinală E este " << sEast << std::endl;  

    return 0;
}
