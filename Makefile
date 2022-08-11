LIBS  = -lm
CFLAGS = -Wall

OBJ = main.o  \
	  lista.o \
	  tipos.o \

SRCS = $(OBJ:%.o=%.c)

main: $(SRCS)
	gcc -o $@  $(CFLAGS) $(LIBS) $(SRCS)