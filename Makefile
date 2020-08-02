CXX      = g++
HOME     = .
BIN      = $(HOME)/bin
INC	   = $(HOME)/include
SRC      = $(HOME)/src
OBJ      = $(HOME)/obj

FLAGS = -std=c++17 -Wall -Wextra -Wfloat-equal -Wpedantic -lSDL2
MENSAJE = "Compilando\ usando\ C++17,\ con\ todos\ los\ warnings\ activados"

OBJETIVO = $(BIN)/main
OBJETOS = $(OBJ)/Game.o $(OBJ)/main.o

N := $(shell echo $(OBJETIVO) $(OBJETOS) | wc -w )
X := 0
SUMA = $(eval X=$(shell echo $$(($(X)+1))))


all: clean INICIO $(OBJETIVO) FIN

define compilar_objeto
	@$(SUMA)
	@printf "\e[31m[$(X)/$(N)] \e[32mCreando el objeto $(2) a partir de $(1)\n"
	@$(CXX) -c $(FLAGS) $(1) -I$(INC) -o $(2)
endef

define compilar_binario
	@$(SUMA)
	@printf "\e[31m[$(X)/$(N)] \e[32mCreando el binario $(2) a partir de $(1)\n"
	@$(CXX) $(1) -o $(2) -lSDL2
	@printf "\n\e[36mCompilación de $(BIN)/GA_P finalizada con exito.\n\n"
endef




INICIO:
	@printf "\e[36mComenzando compilación de $(OBJETIVO)\n\n"
	@printf "\e[94mCompilador: $(CXX)\n"
	@printf "\e[94mFlags del compilador: $(FLAGS)\n\n"
	@printf "\e[94m$(MENSAJE)\n\n"

$(OBJETIVO): $(OBJETOS)
	$(call compilar_binario,$^,$@)

$(OBJ)/Game.o: $(SRC)/Game.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/main.o: $(SRC)/main.cpp
	$(call compilar_objeto,$^,$@)




FIN:
	@printf "\n\e[36mCompilación finalizada con éxito\n"

clean:
	@printf "\e[36mLimpiando el directorio $(OBJ)\n"
	-@rm $(OBJ)/*.o 2> /dev/null || printf "\e[33mEl directorio $(OBJ) está vacio, nada que limpiar\n"
	@printf "\e[36mLimpiando el directorio $(BIN)\n"
	-@rm $(BIN)/* 2> /dev/null || printf "\e[33mEl directorio $(BIN) está vacio, nada que limpiar\n"
	@printf "\e[36mLimpieza completada\n"