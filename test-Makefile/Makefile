TARGET = out
OBJ = main.o

CC = g++
CFLAGS = -Wall

all: $(TARGET)

DEP := $(patsubst %.o, %.d, $(OBJ))
-include $(DEP)
DEPFLAGS = -MMD -MF $(@:.o=.d)


out: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)



clean: 
	rm -f $(TARGET) $(OBJ) $(DEP)