#include <iostream>
void divDoiCinci(int nrEl){
    int nrDivDoi=0, nrDivCinci=0, nrZero=0;
    bool zeroPrezent = false, nrNegativ=false;
    for (int i = 0; i<nrEl; i++) {
        int n, d=2, p;
        std::cout << "n" << i+1 << "=";
        std::cin >> n;
        if(n==0){
            zeroPrezent=true;
            i=nrEl;
            //Sa imi iasa din loop daca orcare dintre factori este 0
            //produsul atunci e 0 si am un if() mai jos pentru cazul
            //asta. Desi in enuntul problemei se cerea n natural, deci
            //as fi putut sa il pun in if()ul care exclude nr. intregi.
        }
        else if(n<0){
            nrNegativ=true;
            break;
        }
        else{
            while(n!=1)
            {
                p = 0;
                while(n%d==0)
                {
                    n = n/d;
                    p++;
                }
            if(p>0){
                if(d==5){nrDivCinci+=p;}
                if(d==2){nrDivDoi+=p;}
            }
            d++;
            }
        }
    }
    if(nrNegativ==true){
        std::cout<<"ultimul factor nu este numar natural. \n";
    }
    else if(zeroPrezent==false){
        if(nrDivDoi>nrDivCinci){nrZero=nrDivCinci;}
        else {nrZero=nrDivDoi;}
        std::cout<<"produsul numerelor se sfarseste cu "<< nrZero;
        std::cout << " zero(uri). \n";
    }
    else {
        std::cout << "produsul numerelor este 0, deci se termină într-un 0. \n";
    }
}
int main(){
    int nrEl;
    std::cout << "nr de factori = ";
    std::cin >> nrEl;
    divDoiCinci(nrEl);
    return 0;
}
