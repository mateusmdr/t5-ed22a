LIBS  = -lm
CFLAGS = -Wall

OBJ = main.o

SRCS = $(OBJ:%.o=%.c)

main: $(SRCS)
	gcc -o $@  $(CFLAGS) $(LIBS) $(SRCS)