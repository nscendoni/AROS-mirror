CFLAGS = -O2 -DBNULL=NULL

PURE_FILES = Assign.c Dir.c Copy.c
FILES = Info.c

PURE_PROGS = $(PURE_FILES:.c=)
PROGS = $(FILES:.c=)

all: $(PURE_PROGS) $(PROGS)

$(PURE_PROGS): %: %.c
	gcc $(CFLAGS) $< -o $@ -nostartfiles -lrom
	Protect $@ +p

$(PROGS): %: %.c
	gcc $(CFLAGS) $< -o $@

Eval.o: evalParser.tab.c

evalParser.tab.c: evalParser.y
	$(YACC) $< -o $@

clean:
	Delete $(PURE_PROGS) $(PROGS)

install:
	Copy $(PURE_PROGS) $(PROGS) TO C:
