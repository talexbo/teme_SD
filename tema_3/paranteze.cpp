//Se dă un şir de paranteze deschise şi închise de tip (, ), [, ], {, }. Să se
//verifice dacă şirul este corect. Pentru rezolvare folosiţi o stivă de catactere
//implementare proprie sau std::stack. Exemplu: şirul [()()] este corect, şirul
//([]) nu este corect, şirul ()]( nu este corect.
//
#include<iostream>
#include<stack>

int main(){
    std::string paranteze;
    std::stack<char> stiva;
    std::cout <<"sir de paranteze = ";
    std::cin >> paranteze;
    bool ok = true;
    int n = paranteze.size();
    
    for (int i = 0; i < n; i++) {
        // {[(
        if(i + 2 < n && paranteze[i] == '{' && paranteze[i+1] == '[' && paranteze[i+2] == '('){
            stiva.push('{');
            stiva.push('[');
            stiva.push('(');
            i += 2;
        }
        // [(
        else if(i + 1 < n && paranteze[i] == '[' && paranteze[i+1] == '(') {
            stiva.push('[');
            stiva.push('(');
            i += 1;
        }
        // (
        else if (paranteze[i] == '('){
            stiva.push('(');
        }
        // )]}
        else if(i + 2 < n && paranteze[i] == ')' && paranteze[i+1] == ']' && paranteze[i+2] == '}'){
            if(stiva.size() >= 3){
                stiva.pop();
                stiva.pop();
                stiva.pop();
                i += 2;
            }
            else{
                std::cout << "nu sunt închise )]} \n";
                ok = false;
                break;
            }
        }
        // )]
        else if(i + 1 < n && paranteze[i] == ')' && paranteze[i+1] == ']') {
            if(stiva.size() >= 2){
                stiva.pop();
                stiva.pop();
                i += 1;
            }
            else{
                std::cout << "nu sunt închise )] \n";
                ok = false;
                break;
            }
        }
        // )
        else if(paranteze[i] == ')'){
            if(!stiva.empty()){
                stiva.pop();
            }
            else{
                std::cout << "nu sunt închise ) \n";
                ok = false;
                break;
            }
        }
        else{
            std::cout << "Caracter invalid sau ordine gresita\n";
            ok = false;
            break;
        }
    }
    
    if(ok && stiva.empty()){
        std::cout << "e bun sirul";
    }
    else if(ok){
        std::cout << "paranteze neînchise";
    }
    
    return 0;
}