#!/bin/bash

# Generate a random number between 1 and 20
n=$((1 + RANDOM % 8))

# Generate an array of random numbers between -20 and 20
array=()
for ((i=0; i<n; i++)); do
    array+=("$((RANDOM % 41 - 20))")
done

# Print the generated values for debugging (optional)
echo "n = $n"
echo "Array: ${array[*]}"

# Run the Python script with n and the array as input
{
    echo "$n"
    for num in "${array[@]}"; do
        echo -n "$num "
    done
    echo # Add a newline after the last number
} | python3 frogHard.py > python_output.txt

# Run the compiled C program with n and the array as input
{
    echo "$n"
    for num in "${array[@]}"; do
        echo -n "$num "
    done
    echo # Add a newline after the last number
} | ./a.out > c_output.txt

# Compare the outputs of the two programs using diff
if diff -q python_output.txt c_output.txt; then
    echo "Outputs match!"
else
    echo "Outputs do not match!"
fi

# Clean up temporary files
# rm python_output.txt c_output.txt
