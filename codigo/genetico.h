#ifndef GENETICO_H
#define GENETICO_H

#include <bits/stdc++.h>

using namespace std;

const int TAM_POPULACAO = 200;
const int NUM_GERACOES = 200;
const double TAXA_MUTACAO = 0.1;
const int DIAS_SEMANA = 7;
const int NUM_REFEICOES = 4;
const double PENALIDADE_REPETICAO = 100;

struct Alimento {
    string nome;
    double proteina;
    double carboidrato;
    double gordura;
    double calorias;
    bool gluten = false;
    bool lactose = false;
};

struct Restricoes {
    bool sem_gluten = false;
    bool sem_lactose = false;
};

struct Porcao {
    int alimento;
    double quantidade;
};

struct Dia {
    vector<Porcao> refeicoes[NUM_REFEICOES];
};

struct Individuo {
    Dia dias[DIAS_SEMANA];
};

struct Nutrientes {
    double proteina = 0;
    double carboidrato = 0;
    double gordura = 0;
    double calorias = 0;
};

void definir_restricoes(const Restricoes& restricoes);
bool validar_restricoes();
Dia gerar_dia();
Individuo gerar_individuo();
Nutrientes calcular_nutrientes(const Dia& dia);
double avaliar_dia(const Dia& dia);
int contar_repeticoes(const Individuo& individuo);
double avaliar_individuo(const Individuo& individuo);
Individuo cruzar_individuos(const Individuo& pai1, const Individuo& pai2);
Individuo torneio(const vector<Individuo>& populacao);
Individuo executar_algoritmo(vector<double>& melhores_fitnesses);
void imprimir_dia(const Dia& dia);
void imprimir_cardapio(const Individuo& individuo);

#endif
