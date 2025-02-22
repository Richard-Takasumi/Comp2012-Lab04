CPPFLAGS = -std=c++11 -Wall
CPPFLAGS_leak = -std=c++11 -fsanitize=address,leak,undefined -g

OBJ_DIR = obj
OBJ_DIR_leak = obj_leak

SRCS	= main.cpp container.cpp button.cpp textbox.cpp object.cpp
OBJS	= $(SRCS:.cpp=.o)
DEPS	= $(OBJS:.o=.d)

OBJECTS = $(addprefix $(OBJ_DIR)/,$(OBJS))
OBJECTS_leak = $(addprefix $(OBJ_DIR_leak)/,$(OBJS))

all: lab4.exe #lab4_leak.exe
# Remove the '#' in the above line to add lab4_leak.exe
# if you want to test memory leakage on your machine

lab4.exe: $(OBJECTS) 
	g++ $(CPPFLAGS) -o $@ $^

lab4_leak.exe: $(OBJECTS_leak)
	g++ -o $@ $(CPPFLAGS_leak) $^

# To include the .d dependency files
-include $(DEPS)

$(OBJ_DIR)/%.o: %.cpp
	g++ $(CPPFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR_leak)/%.o: %.cpp
	g++ $(CPPFLAGS_leak) -MMD -MP -c $< -o $@

clean:
	del $(OBJ_DIR)\* $(OBJ_DIR_leak)\* *.exe
# 	rm -rf $(OBJ_DIR)/* $(OBJ_DIR_leak)/* *.exe