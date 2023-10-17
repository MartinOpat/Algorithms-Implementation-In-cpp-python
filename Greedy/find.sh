#!/bin/bash

# Define the directory where your .in and .ans files are located
input_dir="secret/"

# Iterate through all .in files in the directory
for infile in "$input_dir"/*.in; do
    # Extract the base name of the .in file (without the extension)
    base_name=$(basename "$infile" .in)
    
    # Define the path to the corresponding .ans file
    ans_file="$input_dir/$base_name.ans"
    
    # Run ./a.out with the .in file as input and capture the output
    output=$(./a.out < "$infile")
    
    # Compare the output with the content of the .ans file
    if [ "$output" != "$(cat "$ans_file")" ]; then
        echo "Mismatch found in: $infile"
    fi
done
