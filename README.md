# Sistema de Atendimento com Filas

Este projeto é um sistema simples de gerenciamento de senhas desenvolvido em C++. O objetivo principal é demonstrar a aplicação prática do conceito de **Fila (FIFO - First In, First Out)** utilizando duas abordagens distintas de alocação de memória rodando de forma simultânea: **Estática (via Vetores)** e **Dinâmica (via Ponteiros)**.

## 🚀 Funcionalidades

O sistema opera através de um seletor interativo com as seguintes opções:

* **1. Gerar senha:** Incrementa o controle de senhas, gerando e enfileirando uma nova senha nas filas `senhasGeradas`.
* **2. Realizar atendimento:** Consome a senha "da vez", exibindo-a na tela e movendo-a para as filas `senhasAtendidas`.
* **0. Sair:** Encerra o programa. 

### Regras de Negócio Implementadas:
* O seletor exibe em tempo real a quantidade de senhas que ainda estão aguardando atendimento.
* O programa possui uma trava de segurança que impede o encerramento se a fila `senhasGeradas` não estiver completamente vazia.
* Ao encerrar com sucesso, o sistema exibe o total de senhas atendidas em ambas as implementações.
