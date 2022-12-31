#include <iostream> //biblioteca usada para entrada e sa�da (cout e cin)
#include <cctype> //biblioteca usada para verifica��o de caracteres (isdigit e isalpha)
#include <algorithm> //biblioteca usada para apagar os espa�os em branco
#include <locale> //biblioteca usada para usarmos acentu��o
using namespace std;
 
int main()
{    
	setlocale(LC_ALL, "portuguese"); //comando para usarmos acentua��o
	
	//declara��o de vari�veis
	string end, num; //vari�veis para armazenar o endere�o e o numero
    int i, p; //contadores para auxiliar no tratamento dos dados
    char op; //caracter usado para responder se ir� realizar nova concatena��o de endere�o
    
    do
    {
    	//zerando as vari�veis
    	num = "            "; //espa�o em branco para que possa entrar numeros suficientes
    	p = 0; //zerando a vari�vel p
    	
    	cout << "Desafio de c�digo Pwc - Provedor de endere�os";
    	cout << "\nCandidato: Leonardo Marrocco Gon�alves Bezerra";
    	
    	//entrada de dados
    	cout << "\n\nInsira endere�o: ";
	    getline(cin, end); //comando usado para poder ler os espa�os
	    
	    //processamento de dados
	    for (i = 0; i < end.size(); i++) //la�o para trocar os espa�os em branco por '_'
	    {								//ser� necess�rio para endere�os com espa�os n�o ficarem tudo junto												
	    	if (end[i] == ' ')
	    	{
	    		if (isdigit(end[i - 1]))
	    			end[i] = ' ';
	    		else
	    			end[i] = '_';
			}
		}
	    
	    for (i = 0; i < end.size(); i++) //la�o para separar endere�o e n�mero
	    {
	    	if ((end[i] >= '0' ) && (end[i]<='9')) //verifica��o se o caracter � numero (poderia ser usado o camando isdigit tamb�m)
	    	{
	    		num[p] = end[i]; //separa��o de endere�o e n�mero
	    		end[i] = ' ';
	    		
	    		if (isalpha(end[i + 1])) //se o proximo caracter for uma letra, entende-se que essa letra � um complemento
			   	{
			   		num[p + 1] = end [i + 1];
		 			end[i + 1] = ' ';
				}
				
				p++;
			}
		}
		
		num.erase(remove(num.begin(), num.end(), ' '), num.end()); //removendo espa�os em branco da vari�vel num
		end.erase(remove(end.begin(), end.end(), ' '), end.end()); //removendo espa�os em branco da vari�vel end
		end.erase(remove(end.begin(), end.end(), ','), end.end()); //removendo v�rgulas da vari�vel end
		
		for (i = 0; i < end.size(); i++) //la�o para substitui��o de '_' pelos espa�os em branco necess�rios
	    {
	    	if (end[i] == '_')
	    	{
	    		end[i] = ' ';
			}
		}
		
		//sa�da de dados
		cout << endl << "Endere�o: " << end;
		cout << endl << "N�mero: " << num;
		
		cout << "\n\nDeseja inserir outro endere�o? Se sim digite \'S\' se n�o digite qualquer outra letra: ";
		cin >> op;
		fflush(stdin); //funcao para limpar o buffer do teclado
		
		system("cls");//limpa tela
	} while (op == 'S' || op == 's'); //se a resposta for 'S'/'s' ent�o o programa sera iniciado novamente
	
	return 0;
}
