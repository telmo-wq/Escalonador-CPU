# 💾Simulador de um Escalonador de CPU


O código deste repositório tem como objetivo simular de maneira simplificada o funcionamento de uma CPU na manutenção e escalonamento de processos no computador. O simulador de escalonador funciona lendo um arquivo .txt com as tasks descritas pelo usuário (nome da task, período e burst de CPU), que é passado como parâmetro na linha de comando. O código irá gerar um log no final com os registros de todas as tasks executadas, especificando quantas vezes foram completadas, perdidas ou mortas.

Os códigos escritos aqui simulam dois algoritmos tradicionais de escalonamento: o Rate-Monothonic Scheduling (rate) e o Earliest-Deadline First (edf)


## 📖Conteúdos

Neste repositório estão contidos dois arquivos txt usados como exemplos na implementação do projeto e o Makefile da compilação. Dentro da pasta source, estão contidos:

- biblioteca.h: Arquivo header com todas as funções armazenadas na biblioteca

- processos.c: Um arquivo C separado para a função de adicionar novos processos com structs

- main_rate.c e main_edf.c: Dois arquivos C que contém uma função main em cada. Os dois leem um arquivo .txt passado e tratam com edf ou rate

- rate.c: Contém a função que executa o algoritmo de Rate-Monothonic

- edf.c: Contém a função que executa o algoritmo de Earliest-Deadline


## ✍️Instruções para execução

Primeiramente, é importante que tenha o make instalado

```
sudo apt-get install build-essential
```

Em seguida, clone o repositório e certifique-se de que está dentro da pasta

```
cd Escalonador-CPU
```

Caso queira executar o algoritmo de RMS, compile e execute:

```
make clean
make rate

./rate arquivo.txt
```

Ou caso queira executar o algoritmo edf:

```
make clean
make edf

./edf arquivo.txt
```

A execução de ambos os comandos vai gerar um log algoritmo_tmfc.out, onde estarão registrados os status de cada task e os resultados finais após o tempo total

Este repositório foi escrito e desenvolvido por Telmo Melo (telmo-wq) em um sistema CachyOS

