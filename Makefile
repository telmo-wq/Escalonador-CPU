rate: main.o rate.o processos.o
	gcc main.o rate.o processos.o -o rate

main.o: source/main.c source/biblioteca.h
	gcc -c source/main.c

rate.o: source/rate.c source/biblioteca.h
	gcc -c source/rate.c 

processos.o: source/processos.c source/biblioteca.h
	gcc -c source/processos.c

edf: main.o processos.o edf.o 
	gcc main.o edf.o processos.o -o edf

edf.o: source/edf.c source/biblioteca.h
	gcc -c source/edf.c 


clean:
	rm -rf *.o rate edf 

