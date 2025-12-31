#!/bin/bash

make re || exit 1

./server > out.txt &
sleep 1

PID=$(awk '{print $3}' out.txt)

./client $PID "Hello"
./client $PID "42 Network"
./client $PID ""
./client $PID "abcdef"
./client $PID "1234567890"

LONG=$(printf 'A%.0s' {1..150})
./client $PID "$LONG"

for i in {1..5}
do
	./client $PID "Fast_$i"
done

sleep 1
kill $!
rm -f out.txt

