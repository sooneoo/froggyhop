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
OBJS += $(CACHE)/game_manager.o
OBJS += $(CACHE)/game_state_menu.o
OBJS += $(CACHE)/game_state_game_control.o
OBJS += $(CACHE)/player_ted.o


$(CACHE)/main.o: src/froggyhop/main.c
	$(CC) $(CFLAGS) -c src/froggyhop/main.c -o $@


$(CACHE)/game_manager.o: src/froggyhop/game_manager.c
	$(CC) $(CFLAGS) -c src/froggyhop/game_manager.c -o $@


$(CACHE)/game_state_menu.o: src/froggyhop/game_state_menu.c
	$(CC) $(CFLAGS) -c src/froggyhop/game_state_menu.c -o $@


$(CACHE)/game_state_game_control.o: src/froggyhop/game_state_game_control.c
	$(CC) $(CFLAGS) -c src/froggyhop/game_state_game_control.c -o $@


$(CACHE)/player_ted.o: src/froggyhop/player/player_ted.c
	$(CC) $(CFLAGS) -c src/froggyhop/player/player_ted.c -o $@


$(RELEASE)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(RELEASE)/$(TARGET)


