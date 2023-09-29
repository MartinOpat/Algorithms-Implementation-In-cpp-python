#!/bin/bash

# Set the maximum number of attempts
max_attempts=1000

# Initialize a counter
attempts=1

# Run the comparison script in a loop
while [ "$attempts" -le "$max_attempts" ]; do
    echo "Attempt $attempts:"
    ./compareFrog.sh

    # Check if the outputs match
    if diff -q python_output.txt c_output.txt; then
        echo "Outputs match! Running again..."
    else
        echo "Outputs do not match! Exiting..."
        break
    fi

    # Increment the counter
    ((attempts++))
done

# Clean up temporary files (if needed)
# rm python_output.txt c_output.txt
