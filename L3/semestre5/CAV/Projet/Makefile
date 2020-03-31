BIN=./bin
SRC=./src
EXEC=Projet

executable: messageCompil lesprints.o armes.o protection.o couleurs.o soins.o champions.o buffer.o equipe.o traitement.o partie2.o Projet.o messageCompilDone
	@gcc -o ./$(EXEC) $(BIN)/Projet.o $(BIN)/lesprints.o $(BIN)/protection.o $(BIN)/armes.o $(BIN)/couleurs.o $(BIN)/soins.o $(BIN)/champions.o $(BIN)/buffer.o $(BIN)/equipe.o $(BIN)/traitement.o $(BIN)/partie2.o

Projet.o: ./src/Projet.c ./src/lesprints.h ./src/armes.h ./src/protection.h ./src/couleurs.h ./src/champions.h ./src/equipe.h
	@gcc -pedantic -ansi -Wall -o $(BIN)/Projet.o -c $(SRC)/Projet.c

lesprints.o: ./src/lesprints.c
	@gcc -pedantic -ansi -Wall -o $(BIN)/lesprints.o -c $(SRC)/lesprints.c 

armes.o: ./src/armes.c
	@gcc -pedantic -ansi -Wall -o $(BIN)/armes.o -c $(SRC)/armes.c 

protection.o: ./src/protection.c
	@gcc -pedantic -ansi -Wall -o $(BIN)/protection.o -c $(SRC)/protection.c

couleurs.o: ./src/couleurs.c
	@gcc -pedantic -ansi -Wall -o $(BIN)/couleurs.o -c $(SRC)/couleurs.c

soins.o: ./src/soins.c
	@gcc -pedantic -ansi -Wall -o $(BIN)/soins.o -c $(SRC)/soins.c

champions.o: ./src/champions.c
	@gcc -pedantic -ansi -Wall -o $(BIN)/champions.o -c $(SRC)/champions.c

buffer.o: ./src/buffer.c
	@gcc -pedantic -ansi -Wall -o $(BIN)/buffer.o -c $(SRC)/buffer.c

equipe.o: ./src/equipe.c
	@gcc -pedantic -ansi -Wall -o $(BIN)/equipe.o -c $(SRC)/equipe.c

traitement.o: ./src/traitement.c
	@gcc --pedantic -ansi -Wall -o $(BIN)/traitement.o -c $(SRC)/traitement.c

partie2.o: ./src/partie2.c
	@gcc --pedantic -ansi -Wall -o $(BIN)/partie2.o -c $(SRC)/partie2.c

clean: 
	@echo -n "\033[33;32m=== DELETE in debug mode : "
	@rm Projet
	@rm ./bin/*
	@echo "\033[0m DONE"

messageCompil:
	@echo -n "\033[33;32m=== Compilation in debug mode : "

messageCompilDone:
	@echo "\033[0m DONE"

launch:
	@./Projet

claunch: executable launch
