include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard [^_]*.c)

all: $(MODULE)

$(MODULE): $(SOURCES)
	$(GCC) $(GCCFLAGS) -T sampleCodeModule.ld _loader.c $(SOURCES) -o ../$(MODULE)
	$(GCC) $(GCCFLAGS) -T sampleCodeModuleElf.ld _loader.c $(SOURCES) -o ../0000-sampleCodeModule.elf

clean:
	rm -rf *.o

.PHONY: all clean print
