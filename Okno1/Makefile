#Конфигурация
CC = gcc
RC = windres
CFLAGS = -Wall -Wextra -I utils
RFLAGS = -O coff
LDFLAGS = -mwindows -lgdi32
SRC_DIR = utils
RES_DIR = resource
RES = $(RES_DIR)/Source.resource
TARGET = app.exe
#Описание исходных файлов
APP_SRC = main.c
WIN_SRC = $(SRC_DIR)/WinProc.c
Win_HEADER = $(SRC_DIR)/WinProc.h
RC_SRC = $(RES_DIR)/Source.rc
#Объектные файлы
OBJ = $(APP_SRC:.c=.o) $(WIN_SRC:.c=.o) $(RES)
#Правила
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c $(Win_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(RES): $(RC_SRC)
	$(RC) $(RCFLAGS) $< -o $@

clean:
	del /Q /F $(TARGET) *.o
	del /Q /F $(SRC_DIR)\*.o	
	del /Q /F $(RES_DIR)\*.res
#Исключения
.PHONY:all,clean
