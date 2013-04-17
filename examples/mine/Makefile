all: runner_test

MRUBY_PATH=/home/tomita/programs/ruby/mruby

runner_test: runner_test.c
	gcc -Wall -I${MRUBY_PATH}/include -L${MRUBY_PATH}/build/host/lib -o runner_test runner_test.c -lmruby -lm

run:
	./runner_test

clean:
	rm runner_test
