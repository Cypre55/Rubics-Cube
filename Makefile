solver:
	cc gen.c -o gen
	./gen
	python translator.py
	rm sols.txt