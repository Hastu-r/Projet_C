build:
	gcc -std=c99 -Wall -Wextra -Werror -fstack-protector \
		-Imodele -Imodele/formes -Isvg \
		-o projet modele/*.c modele/formes/*.c cli/*.c svg/*.c

clean:
	rm -f projet

run: build
	./projet
	