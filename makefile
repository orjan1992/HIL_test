# #Compiler
# CC=g++
# #Flags to compiler
# CFLAGS=-lwiringPi
# #No idea
# LDFLAGS=
# #source files
# SOURCES=test.cpp test3.cpp
# #object files(No changes)
# OBJECTS=$(SOURCES:.cpp=.o)
# #Name of executable file
# EXECUTABLE=test

# #code to run
# all: $(SOURCES) $(EXECUTABLE)

# $(EXECUTABLE): $(OBJECTS) 
	# $(CC) $(LDFLAGS) -c $(OBJECTS) -o $@ 

# .cpp.o:
	# $(CC) $(CFLAGS) $< -o $@
# clean:
	# rm *o $(EXECUTABLE)
CC=g++
#CFLAGS=
#-std=c99

ODIR=obj

LIBS=-lwiringPi

DEPS = I2Cmode.h STEVAL_mag.h STEVAL_gyr.h STEVAL_acc.h STEVAL_sensor.h

OBJ = main.o STEVAL_mag.o STEVAL_gyr.o STEVAL_acc.o STEVAL_sensor.o

NAME = proj


$(ODIR)/%.o: %.c
	$(CC) -c $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

debug: $(OBJ)
	$(CC) -g $^ $(CFLAGS) $(LIBS);xxgdb a.out
    

.PHONY: clean

clean:
	rm -f *.o *~ core *~ 
	