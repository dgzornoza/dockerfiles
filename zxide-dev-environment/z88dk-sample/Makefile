# Name of final file (without the extension)
EXEC_OUTPUT=z88dk-sample

# Get .c and .asm source files
SOURCES = $(shell find . \( -name '*.c' -o -name '*.asm' \))

# constants
TOOLCHAIN=zcc
TARGET=+zx
VERBOSITY=-vn #(-v: show verbose, -vn: not show verbose)
OUT_DIR=build
PRAGMA_FILE=zpragma.inc

LDFLAGS=$(TARGET) $(VERBOSITY) $(C_OPT_FLAGS) $(CRT) $(COMPILER) $(CLIB) $(DEBUG) --list -m -s --c-code-in-asm  -pragma-include:$(PRAGMA_FILE) $(CREATE_SNA)
EXEC=$(OUT_DIR)/$(EXEC_OUTPUT).tap

# rule for building the project
all : clean $(EXEC) join_lis_files

# rule for compile and create executable
$(EXEC) : $(SOURCES)
	@echo "Compiling ..."
	$(TOOLCHAIN) $(LDFLAGS) $(SOURCES) -o $(OUT_DIR)/$(EXEC_OUTPUT) -create-app
	@echo "Compilation finished, output build in '$(EXEC)'"
	@echo

# rule for join lis files for debug asm in all project
.PHONY: join_lis_files
join_lis_files:
	$(eval LIS_FILES = $(shell find . \( -name '*.c.lis' -o -name '*.asm.lis' \)))

	@echo "Join .lis files to $(OUT_DIR)/$(EXEC_OUTPUT).source.lis"
	@cat $(LIS_FILES) > $(OUT_DIR)/$(EXEC_OUTPUT).source.lis
	@echo

# rule for cleaning output files
.PHONY: clean
clean:
	@echo "Clean workspace."
	rm -rf $(OUT_DIR) /tmp/tmpXX*
	find . \( -name "*.lis" -o -name "*.sym" -o -name "*.o" \) -type f -exec rm -f {} +
	mkdir -p $(OUT_DIR)
	@echo

