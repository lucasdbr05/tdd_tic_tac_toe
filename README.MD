# Tic Tac Toe with TDD

## Author
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

To compile the main file, the tests, and run the tests:
```shell
make all
```

To analyze static and dynamic memory leaks:
```shell
make gcov
```

Para analisar vazamentos de memória estático e dinâmico:
```shell
make valgrind
make cppcheck
```

To check the code formatting standards:
```shell
make cpplint
```


## Documentation
<h4>
This work develops a verifier for the result of a Tic-Tac-Toe game using the principles of Test-Driven Development (TDD). It considers five scenarios:
</h4>

<ul>
    <li>Impossible: when the game has two or more moves ahead for one player; when the game has more than one winner; or when the loser made more moves than the winner.</li>
    <li>Undefined: When there are still moves to be made (empty spaces) and no one has won.</li>
    <li>Draw: When there are no moves left to be made (no empty spaces) and no one has won.</li>
    <li>Victory of X: When X fills a row, a column, or a diagonal with only their elements.</li>
    <li>Victory of O: When O fills a row, a column, or a diagonal with only their elements.</li>
</ul>


## Results

After compiling the code, running the tests, and analyzing the coverage, I obtained the following results::
<img alt="results" src="./results.png">

