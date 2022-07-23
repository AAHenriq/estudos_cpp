#include "../ch2/std_lib_facilities.h"

//Verifica se a string inserida é válida
//i.e. se possui exatamente 4 membros
//e apenas caracteres válidos.
// CONDIÇÃO: string de tamanho 4 com apenas números
bool is_string_val(const string s);

//Recebe a string com os digitos do chute
//e a converte em um vetor de inteiros para
//fazer a comparação
vector<int> input_conv(const string s);

//Recebe a resposta e o chute e os compara
//para fornecer o número de "bulls" e "cows", respectivamente
int n_bulls(const vector<int> answer, const vector<int> guess);
int n_cows(const vector<int> answer, const vector<int> guess);

//Printa o resultado.
//Se bulls = 4, fim de jogo.
bool result(int bulls, int cows);

//Resposta do jogo: OBSOLETO, DADO QUE AGORA É RANDOM
//const vector<int> RESPOSTA{9, 1, 8, 2};

int main()
try
{   

    cout << "Bem-vindo a \"bulls and cows\"!\n"
         << "Nesse jogo será pedido para você inserir números de"
         << " 4 digitos sem algarismos repetidos.\n"
         << "Cada \"cow\" indica que você acertou um dos números, porém "
         << "errou sua casa. \nCada \"bulls\" indica que você acertou um dos "
         << "números e sua casa.\nBoa sorte!\n\n";

    //Insere número para semente
    int seed{0};
    cout << "Favor, insira um número qualquer para gerar o jogo:\n";
    while(!(cin >> seed))
    {   cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Apenas aceito números...\n";
    }

    //Gera semente e resposta
    srand(seed);
    vector<int> resposta(4);
    for(int i = 0; i < resposta.size(); ++i){    
        resposta[i]=rand()%10;
        for(int j = 0; j < i; ++j)
            while(resposta[j] == resposta[i])
                resposta[i]=rand()%10;
    }

    string input{""};
    bool control{0};

    while(!control)
    {
        cout << "Entre com um número de 4 digitos não repetidos:\n";
        cin >> input;
        cout << '\n';
        if(is_string_val(input))
        {            
            control = result(n_bulls(resposta, input_conv(input)), n_cows(resposta, input_conv(input)));
        }else
            cout << '\n';
    }
    return 0;
}
catch(...)
{    
    return -1;
}

bool is_string_val(const string s)
{
    bool c = true;

    if("" == s)
        c = false;

    //Verificação de tamanho:
    if(s.size() != 4)
    {
        cerr << "Não é um número de 4 digitos.\n";
        c = false;
    }
    //Verificação de caracteres:
    for(char ch: s)
    {
        if(ch < '0' || ch > '9')
        {
            cerr << "Um ou mais caracteres não são números.\n";
            c = false;
        }
    }
    //Verificação de repetição de digitos:
    for(int i = 0; i < s.size(); ++i)
        for(int j = i+1; j < s.size(); ++j)
        {
            if(s[i] == s[j])
            {
                cerr << "Há números repetidos.\n";
                c = false;
            }
        }

    return c;
}

vector<int> input_conv(const string s)
{
    vector<int> conv;

    for(int i = 0; i < s.size(); ++i)
        conv.push_back(s[i] - '0');

    if(conv.size() != 4)
    {
        cerr << "???\n";
        throw 0;
    }

    return conv;
}

int n_bulls(const vector<int> answer, const vector<int> guess)
{
    //Verificação de valores irregulares
    //não deveria acontecer nunca, dado que answer é const em main
    //e guess já possui mecanismos que o fixam em tamanho 4 antes dessa
    //função. Mesmo assim, não custa nada fazer
    if(answer.size() != 4 || guess.size() != 4)
    {
        cerr << "O que caralhos você fez, irmão?\n";
        throw 0;
    }

    int bulls = 0; //Para contar

    for(int i = 0; i < guess.size(); ++i)
    {
        if(answer[i] == guess[i])
        {
            ++bulls;
        }
    }

    //Outra verificação de erro
    if(bulls < 0 || bulls > 4)
    {
        cerr << "O que caralhos você fez, irmão?\n";
        throw 0;
    }

    return bulls;
}

int n_cows(const vector<int> answer, const vector<int> guess)
{
    //Verificação de valores irregulares
    //não deveria acontecer nunca, dado que answer é const em main
    //e guess já possui mecanismos que o fixam em tamanho 4 antes dessa
    //função. Mesmo assim, não custa nada fazer
    if(answer.size() != 4 || guess.size() != 4)
    {
        cerr << "O que caralhos você fez, irmão?\n";
        throw 0;
    }

    int cows = 0; //Para contar

    for(int i = 0; i < guess.size(); ++i)           //guess
        for(int j = 0; j < answer.size(); ++j)      //answer
        {
            if(guess[i] == answer[j] && i != j)
                ++cows;
        }

    //Outra verificação de erro
    if(cows < 0 || cows > 4)
    {
        cerr << "O que caralhos você fez, irmão?\n";
        throw 0;
    }

    return cows;
}

bool result(int bulls, int cows)
{
    if(bulls > 0)
        cout << "Você encontrou " << bulls << " bulls.\n";
    if(cows > 0)
        cout << "Você encontrou " << cows << " cows\n";

    if(bulls == 4)
    {
        cout << "Você venceu!\n";
        return true;
    }

    return false;
}