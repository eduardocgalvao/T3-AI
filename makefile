# Verifica se o sistema é Windows  ou não
ifeq ($(OS),Windows_NT)
    EXE := jogo.exe
    RM := del /Q
    MKDIR := if not exist build mkdir build
else
    EXE := jogo
    RM := rm -f
    MKDIR := mkdir -p build
endif

# Organizando e listando diretorios
SRC_DIR := src
BUILD_DIR := build
INCLUDE := -Iheader

# Arquivos fonte e objetos
SRC := $(SRC_DIR)/main.c $(SRC_DIR)/funcoes.c
OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

# Compilador e flags
CC := gcc
CFLAGS := -Wall -O2 $(INCLUDE)

# Regra padrão
all: $(EXE)

# Linka os objetos no executável
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilação dos objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Garante que o diretório build existe
$(BUILD_DIR):
	$(MKDIR)

# Limpa os arquivos gerados
clean:
	$(RM) $(BUILD_DIR)/*.o $(EXE)