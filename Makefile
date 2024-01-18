all:
	mkdir -p target
	cc src/CChess.c src/Valid.c -Wall -std=c11 -Isrc -o target/cchess -O2
clean:
	rm -rf target
