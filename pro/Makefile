LINUXDIR=/home/u10511228/microtime/linux
#CFLAGS = -gdwarf-2 -O0
#CFLAGS = -O2
CC=arm-unknown-linux-gnu-gcc -I$(LINUXDIR)/include


EXEC = pro
OBJS = pro.o creator_lib.o 

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

romfs:
	$(ROMFSINST) /bin/$(EXEC)

clean:
	-rm -f $(EXEC) *.elf *.gdb *.o

