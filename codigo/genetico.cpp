#include <bits/stdc++.h>
#include "genetico.h"

using namespace std;

const vector<Alimento> CAFE_CEREAIS = {
    {"Biscoito Recheado Chocolate", 6, 71, 20, 472, true, true},
    {"Biscoito Salgado Cream Cracker", 10, 69, 14, 432, true},
    {"Cereal Matinal", 7, 84, 1, 382, true},
    {"Pao Frances", 8, 59, 3, 300, true},
    {"Cuscuz de milho cozido", 2.2, 25.3, 0.7, 113},
    {"Tapioca (goma hidratada)", 0, 44, 0, 176},
    {"Biscoito de polvilho", 1.3, 80.5, 12.2, 438},
    {"Pao de queijo assado", 5.1, 34.2, 24.6, 363, false, true},
    {"Pao de forma integral", 9.4, 49.9, 3.7, 253, true},
    {"Aveia em flocos", 13.9, 66.6, 8.5, 394, true}
};

const vector<Alimento> CAFE_FRUTAS = {
    {"Abacate", 1, 6, 8, 96},
    {"Abacaxi", 1, 12, 0, 48},
    {"Banana prata", 1, 26, 0, 98},
    {"Coco", 4, 10, 0, 402},
    {"Goiaba vermelha", 1, 13, 0, 54},
    {"Laranja Pera", 1, 9, 0, 37},
    {"Maça Fuji", 0, 15, 0, 56},
    {"Maracujá", 2, 12, 2, 68},
    {"Melao", 1, 8, 0, 29},
    {"Morango", 1, 7, 0, 30},
    {"Mamao papaia", 0.5, 11.6, 0.1, 45},
    {"Manga Tommy", 0.4, 12.8, 0.2, 51},
    {"Uva Italia", 0.7, 13.6, 0.2, 53},
    {"Kiwi", 1.3, 11.5, 0.6, 51},
    {"Melancia", 0.9, 8.1, 0, 33}
};

const vector<Alimento> CAFE_BEBIDAS = {
    {"Cafe", 15, 66, 12, 419},
    {"Agua de coco", 0, 5.3, 0, 21.5},
    {"Suco Laranja Pera", 0.7, 7.6, 0.1, 32.7},
    {"Suco de uva nectar", 0, 29, 0, 115},
    {"Leite UHT integral", 6, 8.8, 4, 113, false, true},
    {"Iogurte natural", 4, 2, 3, 51, false, true},
    {"Leite sem lactose", 3.1, 4.6, 3, 60},
    {"Cha mate", 0, 0.3, 0, 1}
};

const vector<Alimento> REFEICAO_CEREAIS = {
    {"Arroz integral cozido", 2.6, 25.8, 0.3, 123.5},
    {"Arroz tipo 1", 2.5, 28.1, 0.2, 128.3},
    {"Macarrao Instantaneo", 9, 62, 17, 432, true},
    {"Feijao carioca", 20, 63, 1, 336},
    {"Lentilha", 23, 64, 1, 347},
    {"Feijao preto", 21.3, 58.8, 1.2, 324},
    {"Grao de bico", 21.2, 57.9, 5.4, 355},
    {"Macarrao espaguete cozido", 5.8, 30.9, 0.9, 158, true}
};

const vector<Alimento> REFEICAO_VERDURAS_HORTALICAS = {
    {"Abobrinha Italiana Refogada", 1.1, 4.2, 0.1, 24.4},
    {"Alface Lisa", 2, 2, 0, 14},
    {"Alho cru", 7, 24, 0, 113},
    {"Batata Doce Cozida", 0.6, 18.4, 0, 76.8},
    {"Beterraba Crua", 2, 11, 0, 49},
    {"Cará", 1.5, 18.9, 0, 77.6},
    {"Cenoura Cozida", 0.9, 6.7, 0.1, 29.9},
    {"Couve Crua", 3, 4, 1, 27},
    {"Espinafre Nova Zelândia Refogado", 2.7, 4.2, 0.9, 67.3},
    {"Mandioca Frita", 1.4, 50.3, 1.7, 300.1},
    {"Nabo cru", 1, 4, 0, 18},
    {"Tomate com semente cru", 1, 3, 0, 15},
    {"Vagem crua", 2, 5, 0, 25},
    {"Batata inglesa cozida", 1.2, 11.9, 0, 52},
    {"Chuchu cozido", 0.4, 4.8, 0, 19},
    {"Brocolis cozido", 2.1, 4.4, 0.6, 25},
    {"Couve-flor cozida", 1.2, 3.9, 0.3, 19},
    {"Abobora cabotia cozida", 1.7, 5.4, 0.7, 29},
    {"Repolho cru", 1.3, 5.8, 0.1, 25},
    {"Pepino cru", 0.9, 2, 0.1, 10},
    {"Quiabo cozido", 1.9, 6.4, 0.4, 32}
};

const vector<Alimento> REFEICAO_CARNES = {
    {"Carne bovina acem moida cozida", 26.7, 0, 10.9, 212.4},
    {"Carne bovina contra file sem gordura grelhado", 35.9, 0, 4.5, 193.7},
    {"Carne bovina costela assada", 28.8, 0, 27.7, 373},
    {"File mignon sem gordura grelhado", 33, 0, 9, 220},
    {"Carne bovina fraldinha com gordura cozida", 24, 0, 26, 338},
    {"Carne bovina lagarto cozida", 33, 0, 9, 221},
    {"Frango peito sem pele grelhado", 31.5, 0, 2.5, 159},
    {"Frango coxa sem pele cozida", 26.9, 0, 5.8, 160},
    {"Bife de patinho grelhado", 35.9, 0, 7.3, 219},
    {"Lombo de porco assado", 35.7, 0, 6.4, 210}
};

const vector<Alimento> JANTA_PROTEINAS = {
    {"Corimbata Assado", 19, 0, 4.8, 261.5},
    {"Pintado Grelhado", 30.8, 0, 1.1, 152.2},
    {"File de Merluza Frito", 26.9, 0, 1.4, 191.6, true},
    {"Atum conserva em oleo", 26.2, 0, 1, 165.9},
    {"Tilapia grelhada", 26.2, 0, 2.7, 128},
    {"Salmao grelhado", 22.1, 0, 12.4, 208},
    {"Camarao cozido", 24, 0.2, 0.3, 99},
    {"Frango peito sem pele grelhado", 31.5, 0, 2.5, 159},
    {"Frango coxa sem pele cozida", 26.9, 0, 5.8, 160},
    {"Ovo de galinha cozido", 13.3, 0.6, 9.5, 146}
};

const vector<Alimento> REFEICAO_BEBIDAS = {
    {"Refrigerante Guarana", 0, 10, 0, 38.7},
    {"Suco Laranja Pera", 0.7, 7.6, 0.1, 32.7},
    {"Suco de uva nectar", 0, 29, 0, 115},
    {"Agua de coco", 0, 5.3, 0, 21.5},
    {"Suco de abacaxi", 0.4, 13, 0.1, 53}
};

const double LIMITE_CEREAIS[] = {0.5, 1.5};
const double LIMITE_FRUTAS[] = {1.0, 1.5};
const double LIMITE_BEBIDAS[] = {1.0, 2.0};
const double LIMITE_CARNES[] = {0.8, 2.0};
const double LIMITE_PROTEINA_JANTA[] = {0.5, 2.0};
const double LIMITE_VERDURAS[] = {0.05, 0.2};

mt19937 gerador(random_device{}() ^ chrono::high_resolution_clock::now().time_since_epoch().count());

static Restricoes restricoes_ativas;

int sortear_inteiro(int minimo, int maximo) {
    return uniform_int_distribution<int>(minimo, maximo)(gerador);
}

double sortear_real(double minimo, double maximo) {
    return uniform_real_distribution<double>(minimo, maximo)(gerador);
}

const vector<Alimento>& obter_tabela(int refeicao, int posicao) {
    if(!(refeicao % 2)) {
        if(posicao == 0) {
            return CAFE_CEREAIS;
        } else if(posicao == 1) {
            return CAFE_FRUTAS;
        } else {
            return CAFE_BEBIDAS;
        }
    } else {
        if(posicao < 2) {
            return REFEICAO_CEREAIS;
        }

        if(posicao < 4) {
            return REFEICAO_VERDURAS_HORTALICAS;
        }

        if(posicao == 4) {
            if(refeicao == 1) {
                return REFEICAO_CARNES;
            } else {
                return JANTA_PROTEINAS;
            }
        }
    }

    return REFEICAO_BEBIDAS;
}

const double* obter_limite(int refeicao, int posicao) {
    if(!(refeicao % 2)) {
        if(posicao == 0) {
            return LIMITE_CEREAIS;
        }

        if (posicao == 1) {
            return LIMITE_FRUTAS;
        }
    } else {
        if(posicao < 2) {
            return LIMITE_CEREAIS;
        }

        if(posicao < 4) {
            return LIMITE_VERDURAS;
        }

        if(posicao == 4) {
            if(refeicao == 1) {
                return LIMITE_CARNES;
            } else {
                return LIMITE_PROTEINA_JANTA;
            }
        }
    }

    return LIMITE_BEBIDAS;
}

void definir_restricoes(const Restricoes& restricoes) {
    restricoes_ativas = restricoes;
}

bool permitido(const Alimento& alimento) {
    return !(restricoes_ativas.sem_gluten && alimento.gluten)
        && !(restricoes_ativas.sem_lactose && alimento.lactose);
}

bool validar_restricoes() {
    const vector<Alimento>* tabelas[] = {
        &CAFE_CEREAIS, &CAFE_FRUTAS, &CAFE_BEBIDAS, &REFEICAO_CEREAIS,
        &REFEICAO_VERDURAS_HORTALICAS, &REFEICAO_CARNES, &JANTA_PROTEINAS, &REFEICAO_BEBIDAS
    };

    for(const auto* tabela : tabelas) {
        if(none_of(tabela->begin(), tabela->end(), permitido)) {
            return false;
        }
    }

    return true;
}

int sortear_alimento(const vector<Alimento>& tabela) {
    int indice;

    do {
        indice = sortear_inteiro(0, tabela.size() - 1);
    } while(!permitido(tabela[indice]));

    return indice;
}

Dia gerar_dia() {
    Dia dia;

    for(int i = 0; i < NUM_REFEICOES; i++) {
        int tamanho = (i % 2 == 0) ? 3 : 6;

        for(int j = 0; j < tamanho; j++) {
            const auto& tabela = obter_tabela(i, j);
            const double* limite = obter_limite(i, j);
            Porcao porcao;

            porcao.alimento = sortear_alimento(tabela);
            porcao.quantidade = sortear_real(limite[0], limite[1]);
            dia.refeicoes[i].push_back(porcao);
        }
    }

    return dia;
}

Individuo gerar_individuo() {
    Individuo individuo;

    for(int d = 0; d < DIAS_SEMANA; d++) {
        individuo.dias[d] = gerar_dia();
    }

    return individuo;
}

Nutrientes calcular_nutrientes(const Dia& dia) {
    Nutrientes total;

    for(int i = 0; i < NUM_REFEICOES; i++) {
        for(int j = 0; j < dia.refeicoes[i].size(); j++) {
            const Porcao& porcao = dia.refeicoes[i][j];
            const Alimento& alimento = obter_tabela(i, j)[porcao.alimento];

            total.proteina += porcao.quantidade * alimento.proteina;
            total.carboidrato += porcao.quantidade * alimento.carboidrato;
            total.gordura += porcao.quantidade * alimento.gordura;
            total.calorias += porcao.quantidade * alimento.calorias;
        }
    }

    return total;
}

double avaliar_dia(const Dia& dia) {
    Nutrientes n = calcular_nutrientes(dia);
    double total = n.proteina + n.carboidrato + n.gordura;
    double fitness = 2.0 * abs(n.proteina / total * 100 - 25);

    fitness += abs(n.carboidrato / total * 100 - 50);
    fitness += 1.5 * abs(n.gordura / total * 100 - 25);
    fitness += 0.1 * (max(0.0, n.proteina - 0.25 * total)
                   + max(0.0, n.carboidrato - 0.50 * total)
                   + max(0.0, n.gordura - 0.25 * total));

    if(n.calorias > 2500) {
        fitness *= 10;
    }

    if(n.calorias < 2500) {
        fitness += 0.1 * (2500 - n.calorias);
    }

    for (int i = 1; i < 4; i += 2) {
        const auto& refeicao = dia.refeicoes[i];

        if(refeicao[0].alimento == refeicao[1].alimento) {
            fitness *= 20;
        }

        if(refeicao[2].alimento == refeicao[3].alimento) {
            fitness *= 3;
        }
    }

    for(int i = 1; i < 4; i += 2) {
        const auto& refeicao = dia.refeicoes[i];
        const string& cereal1 = REFEICAO_CEREAIS[refeicao[0].alimento].nome;
        const string& cereal2 = REFEICAO_CEREAIS[refeicao[1].alimento].nome;

        if(cereal1.find("Arroz") != cereal1.npos && cereal2.find("Arroz") != cereal2.npos) {
            fitness *= 50;
        }
    }

    // max(1.0, ...) evita que cereais sem gordura (ex.: tapioca) zerem o fitness
    for(int i = 0; i < 4; i += 2) {
        const Porcao& cereal = dia.refeicoes[i][0];
        fitness *= max(1.0, 20 * cereal.quantidade * CAFE_CEREAIS[cereal.alimento].gordura);
    }

    for(int i = 0; i < 4; i += 2) {
        const auto& cafe = dia.refeicoes[i];
        const string& bebida = CAFE_BEBIDAS[cafe[2].alimento].nome;

        if(bebida.find("Cafe") != bebida.npos) {
            fitness *= (i == 0 ? 0.6 : 0.8);
        }
    }

    for(int i = 0; i < 4; i += 2) {
        const auto& cafe = dia.refeicoes[i];
        const string& bebida = CAFE_BEBIDAS[cafe[2].alimento].nome;
        const string& fruta = CAFE_FRUTAS[cafe[1].alimento].nome;

        if(bebida.find("coco") != bebida.npos && fruta.find("Coco") == bebida.npos) {
            fitness *= (i == 0 ? 1.6 : 1.8);
        }
    }

    return fitness;
}

// Alimentos na mesma tabela (almoco/janta: slots 0-1 e 2-3) sao ordenados para que
// "Arroz + Feijao" e "Feijao + Arroz" contem como a mesma refeicao. Tabelas tem < 100 itens.
long long chave_refeicao(const vector<Porcao>& refeicao) {
    int alimentos[6];
    int n = refeicao.size();

    for(int i = 0; i < n; i++) {
        alimentos[i] = refeicao[i].alimento;
    }

    if(n == 6) {
        sort(alimentos, alimentos + 2);
        sort(alimentos + 2, alimentos + 4);
    }

    long long chave = 0;

    for(int i = 0; i < n; i++) {
        chave = chave * 100 + alimentos[i];
    }

    return chave;
}

// Grupos comparados: cafes (manha + tarde juntos) em [0], almoco em [1], janta em [3].
int contar_repeticoes(const Individuo& individuo) {
    long long chaves[NUM_REFEICOES][2 * DIAS_SEMANA];
    int quantidade[NUM_REFEICOES] = {0, 0, 0, 0};

    for(const Dia& dia : individuo.dias) {
        for(int i = 0; i < NUM_REFEICOES; i++) {
            int grupo = (i % 2 == 0) ? 0 : i;
            chaves[grupo][quantidade[grupo]++] = chave_refeicao(dia.refeicoes[i]);
        }
    }

    int repeticoes = 0;

    for(int g = 0; g < NUM_REFEICOES; g++) {
        sort(chaves[g], chaves[g] + quantidade[g]);

        for(int k = 1; k < quantidade[g]; k++) {
            if(chaves[g][k] == chaves[g][k - 1]) {
                repeticoes++;
            }
        }
    }

    return repeticoes;
}

double avaliar_individuo(const Individuo& individuo) {
    double total = 0;

    for(const Dia& dia : individuo.dias) {
        total += avaliar_dia(dia);
    }

    return total * (1 + PENALIDADE_REPETICAO * contar_repeticoes(individuo));
}

Individuo cruzar_individuos(const Individuo& pai1, const Individuo& pai2) {
    Individuo filho;

    for(int d = 0; d < DIAS_SEMANA; d++) {
        filho.dias[d] = sortear_inteiro(0, 1) ? pai1.dias[d] : pai2.dias[d];
    }

    return filho;
}

Individuo torneio(const vector<Individuo>& populacao) {
    int vencedor = sortear_inteiro(0, populacao.size() - 1);
    double melhor = avaliar_individuo(populacao[vencedor]);

    for(int i = 1; i < 5; i++) {
        int candidato = sortear_inteiro(0, populacao.size() - 1);
        double fitness = avaliar_individuo(populacao[candidato]);
        if (fitness < melhor) {
            vencedor = candidato;
            melhor = fitness;
        }
    }

    return populacao[vencedor];
}

Individuo executar_algoritmo(vector<double>& melhores_fitnesses) {
    vector<Individuo> populacao;
    melhores_fitnesses.clear();

    for(int i = 0; i < TAM_POPULACAO; i++) {
        populacao.push_back(gerar_individuo());
    }

    Individuo melhor_individuo_global;
    double valor_melhor_fitness_global = 0;

    int id_melhor_individuo_geracao = 0;
    double valor_melhor_fitness_geracao = avaliar_individuo(populacao[0]);

    for(int i = 1; i < TAM_POPULACAO; i++) {
        double fitness = avaliar_individuo(populacao[i]);

        if(fitness < valor_melhor_fitness_geracao) {
            id_melhor_individuo_geracao = i;
            valor_melhor_fitness_geracao = fitness;
        }
    }

    melhores_fitnesses.push_back(valor_melhor_fitness_geracao);
    melhor_individuo_global = populacao[id_melhor_individuo_geracao];
    valor_melhor_fitness_global = valor_melhor_fitness_geracao;

    for(int geracao = 0; geracao < NUM_GERACOES; geracao++) {
        vector<Individuo> nova_populacao;
        nova_populacao.push_back(populacao[id_melhor_individuo_geracao]);

        for(int i = 0; i < TAM_POPULACAO - 1; i++) {
            Individuo pai1 = torneio(populacao);
            Individuo pai2 = torneio(populacao);
            nova_populacao.push_back(cruzar_individuos(pai1, pai2));
        }

        for(Individuo& individuo : nova_populacao) {
            for(Dia& dia : individuo.dias) {
                if (sortear_real(0, 1) < TAXA_MUTACAO) {
                    dia = gerar_dia();
                }
            }
        }

        populacao = nova_populacao;
        id_melhor_individuo_geracao = 0;
        valor_melhor_fitness_geracao = avaliar_individuo(populacao[0]);

        for(int i = 1; i < TAM_POPULACAO; i++) {
            double fitness = avaliar_individuo(populacao[i]);

            if(fitness < valor_melhor_fitness_geracao) {
                id_melhor_individuo_geracao = i;
                valor_melhor_fitness_geracao = fitness;
            }
        }

        melhores_fitnesses.push_back(valor_melhor_fitness_geracao);

        if(valor_melhor_fitness_geracao < valor_melhor_fitness_global) {
            melhor_individuo_global = populacao[id_melhor_individuo_geracao];
            valor_melhor_fitness_global = valor_melhor_fitness_geracao;
        }
    }

    return melhor_individuo_global;
}

void imprimir_dia(const Dia& dia) {
    const string nomes[] = {"Cafe da manha", "Almoco", "Cafe da tarde", "Janta"};

    cout << fixed << setprecision(0);

    for(int i = 0; i < NUM_REFEICOES; i++) {
        cout << "  " << nomes[i] << ": ";
        int tamanho = dia.refeicoes[i].size();

        for(int j = 0; j < tamanho; j++) {
            const Porcao& porcao = dia.refeicoes[i][j];
            cout << (j ? ", " : "") << obter_tabela(i, j)[porcao.alimento].nome
                 << " (" << porcao.quantidade * 100 << (j == tamanho - 1 ? " ml)" : " g)");
        }

        cout << "\n";
    }

    Nutrientes n = calcular_nutrientes(dia);
    cout << setprecision(1)
         << "  Total do dia: Proteina " << n.proteina << " g | Carboidrato " << n.carboidrato
         << " g | Gordura " << n.gordura << " g | " << n.calorias << " kcal\n";
}

void imprimir_cardapio(const Individuo& individuo) {
    const string nomes_dias[] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado", "Domingo"};
    string restricoes;

    if(restricoes_ativas.sem_gluten) {
        restricoes += "sem gluten";
    }

    if(restricoes_ativas.sem_lactose) {
        restricoes += string(restricoes.empty() ? "" : ", ") + "sem lactose";
    }

    if(restricoes.empty()) {
        restricoes = "nenhuma";
    }

    cout << "Restricoes: " << restricoes << "\n";

    for(int d = 0; d < DIAS_SEMANA; d++) {
        cout << "\n" << nomes_dias[d] << "\n";
        imprimir_dia(individuo.dias[d]);
    }

    cout << fixed << setprecision(2)
         << "\nRefeicoes repetidas: " << contar_repeticoes(individuo) << "\n"
         << "Fitness: " << avaliar_individuo(individuo) << "\n";
}
