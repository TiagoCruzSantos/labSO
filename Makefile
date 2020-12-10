OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -lm -g -O2 -Wall -pedantic -Wextra -Wwrite-strings
EXE 	 := labso
PROJETO  := Funcionarios

# Cria objetos de todos os arquivos de código-fonte para então linká-los no programa final
main: $(OBJ)/MonitorBanheiro.o $(OBJ)/$(PROJETO).o
	gcc $(OBJ)/*.o -o $(EXE) $(CFLAGS)

$(OBJ)/MonitorBanheiro.o: $(SRC)/MonitorBanheiro.c $(INC)/MonitorBanheiro.h
	gcc -c $(CFLAGS) "$(SRC)/MonitorBanheiro.c" -o "$(OBJ)/MonitorBanheiro.o"

$(OBJ)/$(PROJETO).o: $(PROJETO).c
	gcc -c $(CFLAGS) $(PROJETO).c -o "$(OBJ)/$(PROJETO).o"

clean:
	rm -rf $(OBJ)/*
	rm $(EXE)