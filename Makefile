rate: main.o rate.o
	gcc maino rate.o -o rate

main.o: source/main.c 
	gcc -c source/main.c

rate.o: source/rate.c 
	gcc -c source/rate.c 

edf: main.o edf.o
	gcc main.o edf.o -o edf

edf.o: source/edf.c 
	gcc -c source/edf.c 


clean:
	rm -rf *.o rate edf

