CC=gcc

PKGS=raylib


CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Isrc/include
CFLAGS += $$(pkg-config --cflags $(PKGS))

LIBS += -lm
LIBS += $$(pkg-config --libs $(PKGS))
LIBS += -lalloc

OBJS += $(CACHE)/main.o


$(CACHE)/main.o: src/froggyhop/main.c
	$(CC) $(CFLAGS) -c src/froggyhop/main.c -o $@


$(RELEASE)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(RELEASE)/$(TARGET)


