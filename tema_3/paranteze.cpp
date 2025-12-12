//Se dă un şir de paranteze deschise şi închise de tip (, ), [, ], {, }. Să se
//verifice dacă şirul este corect. Pentru rezolvare folosiţi o stivă de catactere
//implementare proprie sau std::stack. Exemplu: şirul [()()] este corect, şirul
//([]) nu este corect, şirul ()]( nu este corect.
//
#include <iostream>
#include <stack>

std::string paranteze;
std::stack<char> stiva;
    int ok=1;

void rotundeInchise(std::string paranteze);

int main() {
    std::cout <<"sir de paranteze = ";
    std::cin >> paranteze;

	bool acolada, patrata;
    
	for (int i = 0; i < paranteze.size(); i++) {
		if (paranteze[i] == '{') {
			stiva.push('{');
		}
		else if (paranteze[i] == '[') {
			stiva.push('[');
		}
		else if (paranteze[i] == '(')
			stiva.push('(');

		else {
            if (paranteze[i] == ')' || paranteze[i] == ']' || paranteze[i] == '}') {
                if(!stiva.empty()){
                    stiva.pop();
                }
                else {
                    std::cout<<"prea multe paranteze deschise \n";
                    ok=0;
                    break;
                }
            }
        }
    }

    if (ok && stiva.empty()) {
        std::cout << "toate sunt închise";
    }
    else {
        std::cout << "nu sunt închise";
    }

	return 0;

}
