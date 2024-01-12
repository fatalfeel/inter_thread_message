TARGET = inter_thread_message

SRCDIR	= ./source
OBJDIR	= ./obj
BINDIR	= ./bin

CROSS_COMPILE =
#CROSS_COMPILE = /opt/toolchain/x86_64-asustor_x64_g3_2020.12.24-linux-gnu/bin/x86_64-asustor_x64_g3_2020.12.24-linux-gnu-
CC 	= $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++

CFLAGS		= -O0 -g -fPIC -pthread -fmessage-length=0
CXXFLAGS	= -O0 -g -fPIC -pthread -fmessage-length=0 -std=c++14
LDFLAGS		= -lpthread

CFILES		= $(notdir $(wildcard $(SRCDIR)/*.c))
CXXCFILES	= $(notdir $(wildcard $(SRCDIR)/*.cpp))

COBJS		= $(patsubst %.c, $(OBJDIR)/%.o, $(CFILES))
CXXOBJS		= $(patsubst %.cpp, $(OBJDIR)/%.o, $(CXXCFILES))

$(shell mkdir -p $(OBJDIR))
$(shell mkdir -p $(BINDIR))

#call by cpp need declare extern "C"
$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(TARGET): $(COBJS) $(CXXOBJS)
	$(CXX) $^ $(LDFLAGS) -o $(BINDIR)/$@

all: $(TARGET)
	@#sshpass -p "202302001" scp $(BINDIR)/$(TARGET) root@169.254.1.2:/volume1/$(TARGET)

clean:
	rm -rf $(OBJDIR) $(BINDIR)
