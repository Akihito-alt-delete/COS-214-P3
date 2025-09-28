CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = petspace_test

SOURCES = *.cpp
OBJECTS = $(SOURCES:.cpp=.o)

GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m

all: clean build test


test: build
	@echo "$(BLUE)🚀 Running tests...$(NC)"
	./$(TARGET)
	@echo "$(GREEN)✅ Tests completed!$(NC)"


build:
	@echo "$(BLUE)🔨 Building...$(NC)"
	@$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)
	@echo "$(GREEN)✅ Build successful!$(NC)"


leak: build
	@echo "$(BLUE)🔍 Checking for memory leaks...$(NC)"
	@valgrind --leak-check=full --show-leak-kinds=all --quiet ./$(TARGET) 2>&1 | \
	if grep -q "no leaks are possible\|All heap blocks were freed"; then \
		echo "$(GREEN)✅ No memory leaks found!$(NC)"; \
	else \
		echo "$(RED)❌ Memory leaks detected!$(NC)"; \
		valgrind --leak-check=full ./$(TARGET); \
	fi


valgrind: build
	@echo "$(BLUE)🔍 Running detailed memory analysis...$(NC)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)


check: clean build test leak


run: build
	@echo "$(BLUE)🚀 Running program...$(NC)"
	./$(TARGET)


clean:
	@echo "$(YELLOW)🧹 Cleaning...$(NC)"
	@rm -f $(TARGET) *.o core.* valgrind_output.txt
	@echo "$(GREEN)✅ Cleaned!$(NC)"


help:
	@echo "$(BLUE)📋 Simple PetSpace Makefile Commands:$(NC)"
	@echo ""
	@echo "$(GREEN)make$(NC)          - Build and run tests (default)"
	@echo "$(GREEN)make test$(NC)     - Build and run tests"
	@echo "$(GREEN)make leak$(NC)     - Check for memory leaks (quick)"
	@echo "$(GREEN)make valgrind$(NC) - Detailed memory analysis"
	@echo "$(GREEN)make check$(NC)    - Full check (build + test + memory)"
	@echo "$(GREEN)make build$(NC)    - Just compile the program"
	@echo "$(GREEN)make run$(NC)      - Build and run"
	@echo "$(GREEN)make clean$(NC)    - Remove generated files"
	@echo ""
	@echo "$(YELLOW)💡 Most common: just type 'make' or 'make check'$(NC)"

.PHONY: all test build leak valgrind check run clean help