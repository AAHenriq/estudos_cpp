#include "../ch2/std_lib_facilities.h"

int main()
{
    vector<string> words;           //Vetor de palavras

    cout << "Insira todas as palavras desejadas:\n";

    for(string word; cin >> word; ) //Loop for para inserir palavras
        words.push_back(word);      //Insere a palavra digitada no vetor

    sort(words);                    //Organiza o vetor (necessário para verificar repetições)

    cout << endl << "As palavras inseridas foram:\n";

    for(int i = 0; i < words.size(); ++i)       //Loop for que corre o vetor inteiro
    {
        if(i == 0 || words[i-1] != words[i])    //Tira palavras repetidas
            cout << words[i] << endl;           //Imprime as palavras
    
    }

    return 0;
}