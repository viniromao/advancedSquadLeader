BINARY=bin
CODEDIRS=. army creatures game utils map player hud eventManagers/producers eventManagers/observers openGL
INCDIRS=. ./include/ 

CC=g++
OPT=-O0
DEPFLAGS=-MP -MD
OPENGL=-lGL -lGLU -lglfw -lGLEW
SFML=-lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS=$(OPENGL) $(SFML)
CFLAGS=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS) 

CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))
OBJECTS=$(patsubst %.cpp,%.o,$(CFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

distribute: clean
	tar zcvf dist.tgz *

diff:
	$(info The status of the repository, and the volume of per-file changes:)
	@git status
	@git diff --stat

-include $(DEPFILES)

.PHONY: all clean distribute diff