
TARGET=q2

CSRCS= $(TARGET).c
CSRCS+= 

COBJS=$(CSRCS:.c=.o)

CC=gcc
CFLAGS=
LDFLAGS=-lpthread

# Rule 1 - for linking
$(TARGET).out: $(COBJS)
	$(CC) -o $@ $^ $(LDFLAGS) 

#Rule 2 - for compiling
%.o:%.c
	$(CC) $(CFLAGS) -c $<

# Rule 3 - for running
run:
	./$(TARGET).out

# Rule 4 - for cleanning
clean:
	rm -f $(TARGET).out $(COBJS)

.phony: run clean


