main_routine: main_1 main_2 main_3
	@ echo "Running main_1..."
	@ ./main_1
	@ echo "\033[0;32mRunning main_1... DONE\033[0m"
	@ echo ""
	@ echo "Running main_2... "
	@ ./main_2
	@ echo "\033[0;32mRunning main_2... DONE\033[0m"
	@ echo ""
	@ echo "Running main_3... "
	@ ./main_3
	@ echo "\033[0;32mRunning main_3... DONE\033[0m"

main_1: main.cpp
	@ echo ""
	@ echo "Creating main_1..." 
	g++ main.cpp -o main_1
	@ echo "\033[0;32mCreating main_1... DONE\033[0m"

main_2: main.cpp
	@ echo "Creating main_2..."
	g++ main.cpp -O3 -o main_2
	@ echo "\033[0;32mCreating main_2... DONE\033[0m"

main_3: main.cpp
	@ echo "Creating main_3..."
	g++ main.cpp -O3 -fopenmp -DUSE_OPENMP -o main_3
	@ echo "\033[0;32mCreating main_3... DONE\033[0m"

