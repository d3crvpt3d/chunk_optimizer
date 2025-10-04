default:
	g++ src/*.cpp -o build/main -g -O0

perf:
	g++ src/*.cpp -o build/main -pg -O0

fast:
	g++ src/*.cpp -o build/main -g -Ofast

clean:
	rm build/*
