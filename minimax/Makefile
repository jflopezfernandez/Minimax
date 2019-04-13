#==============================================================
#
#
#
# =============================================================

SOURCE_EXT = .c
HEADER_EXT = .h
OUTPUT_EXT = .exe

vpath %.c src
vpath %.h include

.SUFFIXES:
.SUFFIXES: $(SOURCE_EXT) $(HEADER_EXT)

CC            =  gcc
CXX           =  g++
# CFLAGS        = 
# CXXFLAGS      = 

SRC_HEADERS   = -I include
INCLUDE_DIRS  = $(SRC_HEADERS)

LANG_STANDARD = -std=c11
COMPILERWARN  = -Wall -Wextra -Wpedantic -Wno-format
OPTIMIZATIONS = -m64 -Ofast -mtune=intel -march=skylake -mavx2 -funroll-loops

BUILD_FLAGS   = $(LANG_STANDARD) $(COMPILERWARN) $(OPTIMIZATIONS)
COMP_FLAGS    = $(CFLAGS) $(CPPFLAGS) $(BUILD_FLAGS)
COMPILE       = $(CC) $(COMP_FLAGS) $(INCLUDE_DIRS) $(TARGET_ARCH) -c 

SOURCES_DIR   = src
INCLUDES_DIR  = include

SRCS          = main.c
HDRS          = $(patsubst %.c, %.hpp, $(SRCS))
OBJS          = $(patsubst %.c, %.o, $(SRCS))
TARGET        = minimax

OUTPUT_OPTION = -o $@
TARGET_ARCH   = 

# COMPILE.c     = $(CC)  $(COMPILATION_FLAGS) $(INCLUDEDIRS) $(TARGET_ARCH) -c
# LINK.c        = $(CC)  $(COMPILATION_FLAGS) $(INCLUDEDIRS) $(TARGET_ARCH) $(LDFLAGS)
# COMPILE.cpp   = $(CXX) $(COMPILATION_FLAGS) $(INCLUDEDIRS) $(TARGET_ARCH) -c
# LINK.o        = $(CXX) $(COMPILATION_FLAGS) $(INCLUDEDIRS) $(TARGET_ARCH) $(LDFLAGS)
LINK.o        = $(CC) $(COMP_FLAGS) $(INCLUDE_DIRS) $(TARGET_ARCH) $(LDFLAGS)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK.o) $(OUTPUT_OPTION) $^ $(REQLIBS)

%.o: %.c
	$(COMPILE) $(OUTPUT_OPTION) $^ 

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
