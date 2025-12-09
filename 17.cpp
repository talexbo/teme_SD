#include <iostream>

int putere (int b, int e){
    if (e==0){
        return 1;
    }
    else {
        if(e % 2 == 0){
            return putere(b, e/2)*putere(b, e/2);
        }
        else {
            return b*putere(b, e/2)*putere(b, e/2);
        }

    }
}

int main(){
    int n;
    std::cout << "numarul ales este ";
    std::cin >> n;
    if (n<1){
        std::cout << "numarul ales nu este un numar natural\n";
        return 0;
    }
    if (n>2147483646){
        std::cout << "numarul natural ales este prea mare pt. int de 32 bit \n";
        return 0;
    }
    int n2=n;
    int nFinal=0;
    int lungime=0;
    while (n2 != 0) {
        n2 /= 10;
        lungime++;
    }
    for(int i = 0; i<lungime;i++){
        int valLaPozitie;
        //Numarul final este o suma de de cifre (valLaPozitie) aflate
        //la ordinele lor de magnitudine. Logica de mai jos
        //schimba 0 urile in 1 pentru cifrele alea tinand cont
        //de ordinul lor de magnitudine. 
        valLaPozitie = (n/putere(10, i))%10;
        if (valLaPozitie == 0){
            nFinal=nFinal+putere(10, i);
        }
        else{
            nFinal = nFinal + valLaPozitie*putere(10, i);
        }
    }
    std::cout << n << " cu toate aparitiile cifrei 0 inlocuite cu cifra 1 este ";
    std::cout << nFinal << std::endl;
return 0;
}