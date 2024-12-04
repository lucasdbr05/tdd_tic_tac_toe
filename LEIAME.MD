# Tic Tac Toe with TDD

## Autor
<p>Lucas Gabriel de Oliveira Lima - 231003406<p>
<table>
  <tr>
    <td align="center"><a href="https://github.com/lucasdbr05" target="_blank"><img style="border-radius: 50%;" src="https://github.com/lucasdbr05.png" width="100px;" alt="Lucas Lima"/><br /><sub><b>Lucas Lima</b></sub></a><br /></td>
</table>


## Setup

```shell
sudo apt-get install g++
sudo apt-get install make
sudo apt-get install valgrind
sudo apt-get install cppcheck
sudo apt-get install clang-format-14

sudo apt-get install python3-pip
sudo pip install cpplint
```
ou
```shell
make setup
```


## Run

Para compilar os o arquivo principal, os testes, e rodar os testes:
```shell
make all
```

Para analisar a cobertura de código dos testes:
```shell
make gcov
```

Para analisar vazamentos de memória estático e dinâmico:
```shell
make valgrind
make cppcheck
```

Para verificar o padrão de formatação do código:
```shell
make cpplint
```


## Documentação

<h4>
Este trabalho desenvolve um verificador do resultado de uma partida de jogo da velha a, utilizando os princícios de Test Driven Development (TDD). Considerando 5 cenários:
</h4>

<ul>
    <li>Impossível: quando o jogo tem 2 jogadas ou mais de um jogador a mais que outro; quando o jogo tem mais de um vencedor; ou quando o perdedor jogou mais que o vencedor</li>
    <li>Indefinido: Quando ainda tem movimentos a se fazer (espaços vazios) e ninguém ganhou </li>
    <li>Empate:  Quando não se tem movimentos a se fazer (espaços vazios) e ninguém ganhou</li>
    <li>Vitória de X: Quando o X preenche uma linha, uma coluna ou uma diagonal com apenas seus elementos</li>
    <li>Vitória de O: Quando o O preenche uma linha, uma coluna ou uma diagonal com apenas seus elementos</li>
</ul>
 

## Resultados

Após compilar, e rodar os testes e a verificação de cobetura, eu alcancei estes resultados:
<img alt="results" src="./results.png">

