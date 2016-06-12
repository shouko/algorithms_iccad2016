CFLAGS = -g -Wall -std=c++11
OUTDIR = bin/release

###############
# Debug rules #
###############

ifdef DEBUG
OUTDIR = bin/debug
CFLAGS += -DDEBUG
endif

###############
# Libraries #
###############

UNAME_S := $(shell uname -s)
ifneq ($(UNAME_S),Darwin)
LIBFLAGS = -pthread
endif

###############
# PHONY rules #
###############
.PHONY: run_case1 run_case2 run_case3 run_case4 run_case5

all: client server

##############
# Executable #
##############
main: MAKEFLAGS = $(CFLAGS)
client: $(OUTDIR)/main_client.o
$(EXEC): $(OUTDIR)/util.o
	cd $(OUTDIR); g++ -o $@ $(MAKEFLAGS) main_$@.o util.o $(LIBFLAGS)
	strip $(OUTDIR)/$@

################
# Object files #
################

$(OUTDIR)/%.o: src/%.cpp
	@mkdir -p $(OUTDIR)
	cd src;	g++ -c $(MAKEFLAGS) $< -o $@

clean:
	rm -rf bin/*

ctags:
	ctags *.cpp *.h
