CXXFLAGS= -Wall -std=c++03 


TARGET = pointer


SRC =  $(TARGET).cpp
OBJS = $(patsubst %.cpp ,%.o ,$(SRC))
.PHONY: all
all: $(TARGET)
$(TARGET) : $(OBJS)
	$(CXX)  $(CXXFLAGS) -o $@ $^ $(LDFLAGS) -lpthread -lrt
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(LDFLAGS)  -lpthread -lrt
clean:
	$(RM) *.o $(TARGET)
