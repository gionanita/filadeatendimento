#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 100

struct FilaVetor {
    int dados[MAX];
    int frente;
    int tras;
    int total;
};

void inicializarVetor(FilaVetor &f) {
    f.frente = 0;
    f.tras = 0;
    f.total = 0;
}

bool estaVaziaVetor(FilaVetor &f) {
    return f.total == 0;
}

bool estaCheiaVetor(FilaVetor &f) {
    return f.total == MAX;
}

void enfileirarVetor(FilaVetor &f, int senha) {
    if (estaCheiaVetor(f)) {
        return;
    }
    f.dados[f.tras] = senha;
    f.tras = (f.tras + 1) % MAX;
    f.total++;
}

int desenfileirarVetor(FilaVetor &f) {
    if (estaVaziaVetor(f)) {
        return -1;
    }
    int senha = f.dados[f.frente];
    f.frente = (f.frente + 1) % MAX;
    f.total--;
    return senha;
}

struct No {
    int senha;
    No *proximo;
};

struct FilaPonteiro {
    No *frente;
    No *tras;
    int total;
};

void inicializarPonteiro(FilaPonteiro &f) {
    f.frente = NULL;
    f.tras = NULL;
    f.total = 0;
}

bool estaVaziaPonteiro(FilaPonteiro &f) {
    return f.total == 0;
}

void enfileirarPonteiro(FilaPonteiro &f, int senha) {
    No *novo = new No();
    if (novo == NULL) {
        return;
    }
    novo->senha = senha;
    novo->proximo = NULL;

    if (estaVaziaPonteiro(f)) {
        f.frente = novo;
    } else {
        f.tras->proximo = novo;
    }
    f.tras = novo;
    f.total++;
}

int desenfileirarPonteiro(FilaPonteiro &f) {
    if (estaVaziaPonteiro(f)) {
        return -1;
    }
    No *aux = f.frente;
    int senha = aux->senha;

    f.frente = f.frente->proximo;
    delete aux;

    f.total--;
    if (f.frente == NULL) {
        f.tras = NULL;
    }
    return senha;
}

void limparFilaPonteiro(FilaPonteiro &f) {
    while (!estaVaziaPonteiro(f)) {
        desenfileirarPonteiro(f);
    }
}

int main() {
    FilaVetor senhasGeradasVetor, senhasAtendidasVetor;
    inicializarVetor(senhasGeradasVetor);
    inicializarVetor(senhasAtendidasVetor);

    FilaPonteiro senhasGeradasPont, senhasAtendidasPont;
    inicializarPonteiro(senhasGeradasPont);
    inicializarPonteiro(senhasAtendidasPont);

    int opcao;
    int controleSenha = 1;

    do {
        cout << "\n========================================" << endl;
        cout << "Senhas aguardando atendimento: " << senhasGeradasPont.total << endl;
        cout << "----------------------------------------" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Gerar senha" << endl;
        cout << "2. Realizar atendimento" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                enfileirarVetor(senhasGeradasVetor, controleSenha);
                enfileirarPonteiro(senhasGeradasPont, controleSenha);
                cout << "-> Senha " << controleSenha << " gerada com sucesso!" << endl;
                controleSenha++;
                break;

            case 2:
                if (estaVaziaPonteiro(senhasGeradasPont) || estaVaziaVetor(senhasGeradasVetor)) {
                    cout << "-> Nao ha senhas na fila para serem atendidas." << endl;
                } else {
                    int senhaVezVetor = desenfileirarVetor(senhasGeradasVetor);
                    enfileirarVetor(senhasAtendidasVetor, senhaVezVetor);

                    int senhaVezPont = desenfileirarPonteiro(senhasGeradasPont);
                    enfileirarPonteiro(senhasAtendidasPont, senhaVezPont);

                    cout << "-> Senha da vez: " << senhaVezPont << endl;
                }
                break;

            case 0:
                if (!estaVaziaPonteiro(senhasGeradasPont) || !estaVaziaVetor(senhasGeradasVetor)) {
                    cout << "-> Nao eh possivel encerrar o programa! Ainda existem senhas aguardando atendimento." << endl;
                    opcao = -1;
                } else {
                    cout << "\n=== SISTEMA ENCERRADO ===" << endl;
                    cout << "Quantidade de senhas atendidas (Vetor): " << senhasAtendidasVetor.total << endl;
                    cout << "Quantidade de senhas atendidas (Ponteiro): " << senhasAtendidasPont.total << endl;
                    limparFilaPonteiro(senhasAtendidasPont);
                }
                break;

            default:
                cout << "-> Opcao invalida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}