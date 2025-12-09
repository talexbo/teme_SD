#include <climits>
#include <iostream>

int main (){
    int max1=INT_MIN+1;
    int max2=INT_MIN;
    bool continua=true;
    int i = 0;
    while(continua){
        int n;
        std::cout << "urmatorul numar este ";
        std::cin >> n;
        if(n>max1)
        {
            max2=max1;
            max1=n;
        }
        else if (n>max2){
            max2=n;
        }
        i++;
        std::cout << "Mai aveti numere? (1=da, 0=nu)" << std::endl;
        //aici daca inputul pentru continuare nu e bool se strica
        //dar nu stiu sa verific tipul variabilei ca sa ii cer
        //utilizatorului un input valid
        std::cin >> continua;
    }
    if(i==1)
    {
        std::cout << "nu ati inserat decat un singur numar, acesta este "<< max1;
        std::cout << std::endl;
    }
    else{
    std::cout << "primele doua maxime sunt " << max1;
    std::cout << " respectiv " << max2 << std::endl;
    }
}
