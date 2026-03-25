rate: main_rate.o rate.o processos.o
	gcc main_rate.o rate.o processos.o -o rate

edf: main_edf.o edf.o processos.o
	gcc main_edf.o edf.o processos.o -o edf

main_rate.o: source/main_rate.c source/biblioteca.h
	gcc -c source/main_rate.c

main_edf.o: source/main_edf.c source/biblioteca.h
	gcc -c source/main_edf.c

rate.o: source/rate.c source/biblioteca.h
	gcc -c source/rate.c

edf.o: source/edf.c source/biblioteca.h
	gcc -c source/edf.c

processos.o: source/processos.c source/biblioteca.h
	gcc -c source/processos.c

clean:
	rm -rf *.o rate edf rate_tmfc.out edf_tmfc.out