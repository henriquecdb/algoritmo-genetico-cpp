#include "genetico.h"
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool perguntar(const string& pergunta) {
    string resposta;

    cout << pergunta << " (s/n): ";
    getline(cin, resposta);

    return !resposta.empty() && (resposta[0] == 's' || resposta[0] == 'S');
}

int main() {
    Restricoes restricoes;
    restricoes.sem_gluten = perguntar("Sem gluten?");
    restricoes.sem_lactose = perguntar("Sem lactose?");
    definir_restricoes(restricoes);

    if(!validar_restricoes()) {
        cerr << "Restricoes incompativeis com as tabelas de alimentos." << endl;
        return 1;
    }

    vector<double> melhores_fitnesses;
    Individuo melhor = executar_algoritmo(melhores_fitnesses);

    cout << "\nCARDAPIO SEMANAL" << endl;
    imprimir_cardapio(melhor);

    return 0;
}
