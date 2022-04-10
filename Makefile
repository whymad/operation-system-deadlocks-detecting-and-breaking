detect: detect.o utils.o tasks.o
	gcc -o detect detect.o utils.o tasks.o -Wall
detect.o: detect.c detect.h 
	gcc -c detect.c -o detect.o -Wall
utils.o: utils.c utils.h
	gcc -c utils.c -o utils.o -Wall
tasks.o: tasks.c tasks.h
	gcc -c tasks.c -o tasks.o -Wall
clean:
	rm -rf detect *.o