all: frequency_table decode

frequency_table : frequency_table.c file_size.o create_freqt.o letter_count.o offset.o
	gcc -ansi -Wall -o frequency_table frequency_table.c file_size.o create_freqt.o letter_count.o offset.o

decode : decode.c file_size.o letter_count.o create_freqt.o encode_shift.o to_decode.o encode.o chi_squared.o offset.o
	gcc -ansi -Wall -o decode decode.c file_size.o letter_count.o create_freqt.o encode_shift.o to_decode.o encode.o chi_squared.o offset.o

file_size.o : file_size.c
	gcc -ansi -Wall -c file_size.c

create_freqt.o : create_freqt.c
	gcc -ansi -Wall -c create_freqt.c

letter_count.o : letter_count.c
	gcc -ansi -Wall -c letter_count.c

encode_shift.o : encode_shift.c
	gcc -ansi -Wall -c encode_shift.c

to_decode.o : to_decode.c
	gcc -ansi -Wall -c to_decode.c

encode.o : encode.c
	gcc -ansi -Wall -c encode.c

chi_squared.o : chi_squared.c
	gcc -ansi -Wall -c chi_squared.c

offset.o : offset.c
	gcc -ansi -Wall -c offset.c

clean :
	rm frequency_table decode *.o