#include <iostream> //biblioteca usada para entrada e saída (cout e cin)
#include <cctype> //biblioteca usada para verificação de caracteres (isdigit e isalpha)
#include <algorithm> //biblioteca usada para apagar os espaços em branco
#include <locale> //biblioteca usada para usarmos acentução
using namespace std;
 
int main()
{    
	setlocale(LC_ALL, "portuguese"); //comando para usarmos acentuação
	
	//declaração de variáveis
	string end, num; //variáveis para armazenar o endereço e o numero
    int i, p; //contadores para auxiliar no tratamento dos dados
    char op; //caracter usado para responder se irá realizar nova concatenação de endereço
    
    do
    {
    	//zerando as variáveis
    	num = "            "; //espaço em branco para que possa entrar numeros suficientes
    	p = 0; //zerando a variável p
    	
    	cout << "Desafio de código Pwc - Provedor de endereços";
    	cout << "\nCandidato: Leonardo Marrocco Gonçalves Bezerra";
    	
    	//entrada de dados
    	cout << "\n\nInsira endereço: ";
	    getline(cin, end); //comando usado para poder ler os espaços
	    
	    //processamento de dados
	    for (i = 0; i < end.size(); i++) //laço para trocar os espaços em branco por '_'
	    {								//será necessário para endereços com espaços não ficarem tudo junto												
	    	if (end[i] == ' ')
	    	{
	    		if (isdigit(end[i - 1]))
	    			end[i] = ' ';
	    		else
	    			end[i] = '_';
			}
		}
	    
	    for (i = 0; i < end.size(); i++) //laço para separar endereço e número
	    {
	    	if ((end[i] >= '0' ) && (end[i]<='9')) //verificação se o caracter é numero (poderia ser usado o camando isdigit também)
	    	{
	    		num[p] = end[i]; //separação de endereço e número
	    		end[i] = ' ';
	    		
	    		if (isalpha(end[i + 1])) //se o proximo caracter for uma letra, entende-se que essa letra é um complemento
			   	{
			   		num[p + 1] = end [i + 1];
		 			end[i + 1] = ' ';
				}
				
				p++;
			}
		}
		
		num.erase(remove(num.begin(), num.end(), ' '), num.end()); //removendo espaços em branco da variável num
		end.erase(remove(end.begin(), end.end(), ' '), end.end()); //removendo espaços em branco da variável end
		end.erase(remove(end.begin(), end.end(), ','), end.end()); //removendo vírgulas da variável end
		
		for (i = 0; i < end.size(); i++) //laço para substituição de '_' pelos espaços em branco necessários
	    {
	    	if (end[i] == '_')
	    	{
	    		end[i] = ' ';
			}
		}
		
		//saída de dados
		cout << endl << "Endereço: " << end;
		cout << endl << "Número: " << num;
		
		cout << "\n\nDeseja inserir outro endereço? Se sim digite \'S\' se não digite qualquer outra letra: ";
		cin >> op;
		fflush(stdin); //funcao para limpar o buffer do teclado
		
		system("cls");//limpa tela
	} while (op == 'S' || op == 's'); //se a resposta for 'S'/'s' então o programa sera iniciado novamente
	
	return 0;
}
