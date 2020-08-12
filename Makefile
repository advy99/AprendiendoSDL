CXX      = g++
HOME     = .
BIN      = $(HOME)/bin
INC	   = $(HOME)/include
SRC      = $(HOME)/src
OBJ      = $(HOME)/obj

FLAGS = -std=c++17 -O3 -Wall -Wextra -Wfloat-equal -Wpedantic
SDL_LINK = -lSDL2 -lSDL2_image
MENSAJE = "Compilando\ usando\ C++17,\ con\ máxima\ optimización\ \
			 y\ con\ todos\ los\ warnings\ activados"

OBJETIVO = $(BIN)/main
OBJETOS = $(OBJ)/TextureManager.o $(OBJ)/LoaderParams.o $(OBJ)/SDLGameObject.o \
			 $(OBJ)/Player.o $(OBJ)/Vector2D.o $(OBJ)/MainMenuState.o \
			 $(OBJ)/Enemy.o $(OBJ)/PlayState.o $(OBJ)/InputHandler.o \
			 $(OBJ)/Game.o $(OBJ)/PauseState.o $(OBJ)/GameStateMachine.o \
			 $(OBJ)/MenuButton.o $(OBJ)/GameOverState.o $(OBJ)/AnimatedGraphic.o \
			 $(OBJ)/tinyxml2.o $(OBJ)/GameObjectFactory.o $(OBJ)/StateParser.o \
			 $(OBJ)/main.o

N := $(shell echo $(OBJETIVO) $(OBJETOS) | wc -w )
X := 0
SUMA = $(eval X=$(shell echo $$(($(X)+1))))


all: INICIO $(OBJETIVO) FIN


debug: FLAGS = -std=c++17 -g -Wall -Wextra -Wfloat-equal -Wpedantic
debug: MENSAJE = "Compilando\ usando\ C++17,\ sin\ optimización,\ \
	con\ todos\ los\ warnings\ activados\ y\ con\ símbolos\ de\ deputación"
debug: all

define compilar_objeto
	@$(SUMA)
	@printf "\e[31m[$(X)/$(N)] \e[32mCreando el objeto $(2) a partir de $(1)\n"
	@$(CXX) -c $(FLAGS) $(SDL_LINK) $(1) -I$(INC) -o $(2)
endef

define compilar_binario
	@$(SUMA)
	@printf "\e[31m[$(X)/$(N)] \e[32mCreando el binario $(2) a partir de $(1)\n"
	@$(CXX) $(1) -o $(2) $(SDL_LINK)
	@printf "\n\e[36mCompilación de $(BIN)/GA_P finalizada con exito.\n\n"
endef




INICIO:
	@printf "\e[36mComenzando compilación de $(OBJETIVO)\n\n"
	@printf "\e[94mCompilador: $(CXX)\n"
	@printf "\e[94mFlags del compilador: $(FLAGS)\n\n"
	@printf "\e[94m$(MENSAJE)\n\n"

$(OBJETIVO): $(OBJETOS)
	$(call compilar_binario,$^,$@)

$(OBJ)/Player.o: $(SRC)/Player.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/Enemy.o: $(SRC)/Enemy.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/LoaderParams.o: $(SRC)/LoaderParams.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/SDLGameObject.o: $(SRC)/SDLGameObject.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/TextureManager.o: $(SRC)/TextureManager.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/Vector2D.o: $(SRC)/Vector2D.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/InputHandler.o: $(SRC)/InputHandler.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/Game.o: $(SRC)/Game.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/main.o: $(SRC)/main.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/PlayState.o: $(SRC)/PlayState.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/PauseState.o: $(SRC)/PauseState.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/StateParser.o: $(SRC)/StateParser.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/tinyxml2.o: $(SRC)/tinyxml2.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/MainMenuState.o: $(SRC)/MainMenuState.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/GameOverState.o: $(SRC)/GameOverState.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/GameObjectFactory.o: $(SRC)/GameObjectFactory.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/MenuButton.o: $(SRC)/MenuButton.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/AnimatedGraphic.o: $(SRC)/AnimatedGraphic.cpp
	$(call compilar_objeto,$^,$@)

$(OBJ)/GameStateMachine.o: $(SRC)/GameStateMachine.cpp
	$(call compilar_objeto,$^,$@)


FIN:
	@printf "\n\e[36mCompilación finalizada con éxito\n"

clean:
	@printf "\e[36mLimpiando el directorio $(OBJ)\n"
	-@rm $(OBJ)/*.o 2> /dev/null || printf "\e[33mEl directorio $(OBJ) está vacio, nada que limpiar\n"
	@printf "\e[36mLimpiando el directorio $(BIN)\n"
	-@rm $(BIN)/* 2> /dev/null || printf "\e[33mEl directorio $(BIN) está vacio, nada que limpiar\n"
	@printf "\e[36mLimpieza completada\n"
