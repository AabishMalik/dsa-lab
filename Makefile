BUILD_DIR = ./bin
SOURCE_DIR = ./src
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
BINS = $(patsubst  %.c,%, $(patsubst $(SOURCE_DIR)/%,$(BUILD_DIR)/%, $(SOURCES)))


CC := $(CC)

FLAG_BASE := -Wall -Werror -std=c17 -pipe
LINKER_FLAGS := -lm
OPTIMIZATION_FLAGS := -march=x86-64 -mtune=native -O0

CFLAGS := $(FLAG_BASE) $(OPTIMIZATION_FLAGS) $(LINKER_FLAGS)


.PHONY: bins setup  clean format
bins: setup $(BINS)
	@echo "generated"

setup:
	@if [ ! -d $(BUILD_DIR) ]; \
	then \
		mkdir $(BUILD_DIR); \
	fi

clean:
	@if [ -d $(BUILD_DIR) ]; \
	then \
		rm -rf $(BUILD_DIR); \
	fi


format: $(SOURCES)
	@for file in $(SOURCES) ; \
	do \
		clang-format -i $$file ; \
	done


$(BUILD_DIR)/%: $(SOURCE_DIR)/%.c 
	@echo CC $@
	@$(CC) $(CFLAGS) $< -o $@



