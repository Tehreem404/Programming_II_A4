CC = gcc
CFLAGS = -Wall -std=c11 -Iinclude

OBJ_CHAR = Commands_Char.o Sorted_List_Char.o a4q1a_char.o
OBJ_INT = Commands_Int.o Sorted_List_Int.o a4q1a_int.o
OBJ_INTB = Commands_Int.o Sorted_List_Int.o a4q1b.o

# Add the other questions to this command as you go
all: a4q1a_int a4q1a_char a4q1b

# Compile this for the char tests
 a4q1a_char: $(OBJ_CHAR)
	$(CC) $(CFLAGS) -o a4q1a_char.out $(OBJ_CHAR)

# Compile this for the int tests
a4q1a_int: $(OBJ_INT)
	$(CC) $(CFLAGS) -o a4q1a_int.out $(OBJ_INT)

a4q1b: $(OBJ_INTB)
	$(CC) $(CFLAGS) -o a4q1b.out $(OBJ_INTB)

a4q1a_char.o:  a4q1a_char.c
	$(CC) $(CFLAGS) -c a4q1a_char.c -DCHAR -o a4q1a_char.o

a4q1a_int.o:  a4q1a_int.c
	$(CC) $(CFLAGS) -c a4q1a_int.c -DINT -o a4q1a_int.o

a4q1b.o:  a4q1b.c
	$(CC) $(CFLAGS) -c a4q1b.c -DINT -o a4q1b.o

Commands_Char.o: Commands.c
	$(CC) $(CFLAGS) -c Commands.c -DCHAR -o Commands_Char.o

Commands_Int.o: Commands.c
	$(CC) $(CFLAGS) -c Commands.c -DINT -o Commands_Int.o

Sorted_List_Char.o: Sorted_List.c
	$(CC) $(CFLAGS) -c Sorted_List.c -DCHAR -o Sorted_List_Char.o

Sorted_List_Int.o: Sorted_List.c
	$(CC) $(CFLAGS) -c Sorted_List.c -DINT -o Sorted_List_Int.o

clean:
	rm *.o *.out
