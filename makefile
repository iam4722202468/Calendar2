IDIR = ./includes
CC = g++
CXXFLAGS += -I$(IDIR) -std=c++11 -g

ODIR = ./build
CPPDIR = ./src

_DEPS = timeObject.hxx event.hxx repeatTime.hxx stringStuff.hxx
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o timeObject.o event.o repeatTime.o stringStuff.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(CPPDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

calendar: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(INCDIR)/*~ rm calendar
