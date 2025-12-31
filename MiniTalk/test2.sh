#!/bin/bash

# -------------------------------
# 42 Minitalk Testing Script
# -------------------------------

# Start server in background
./server &
SERVER_PID=$!
sleep 0.1  # small delay to let server start

echo "Server started with PID: $SERVER_PID"
echo "-------------------------------"

# Array of messages
MESSAGES=(
    "Hello"
    "42Minitalk"
    "This is a longer test message to check performance"
    "$(perl -e 'print "A"x1000')"  # long 1000-char message
)

# Sequential sending with timing
echo "Sequential sending tests:"
for MSG in "${MESSAGES[@]}"; do
    echo "Sending message: '$MSG'"
    START=$(date +%s%3N)   # milliseconds
    ./client "$SERVER_PID" "$MSG"
    END=$(date +%s%3N)
    ELAPSED=$((END-START))
    echo "Time elapsed: ${ELAPSED} ms"
    echo "-------------------------------"
done

# Simultaneous sending (optional)
echo "Simultaneous sending tests:"
for MSG in "${MESSAGES[@]}"; do
    (
        START=$(date +%s%3N)
        ./client "$SERVER_PID" "$MSG"
        END=$(date +%s%3N)
        ELAPSED=$((END-START))
        echo "Message '$MSG' elapsed: ${ELAPSED} ms"
    ) &
done
wait
echo "All simultaneous messages sent."

# Optional: stop the server
kill $SERVER_PID
echo "Server stopped."

