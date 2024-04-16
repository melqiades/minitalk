#!/bin/bash

# Replace this with the actual path to your C program
program_to_run="./client"

# Prompt the user for arguments
read -p "Enter arguments for your program (separate by spaces): " program_args 

# Set the number of times to run the program
num_runs=20

# Specify the pause duration in seconds
pause_duration=1 

for (( i=1; i<=$num_runs; i++ )); do
  $program_to_run $program_args "The old lighthouse bathed the rugged coastline in its sweeping beam, a beacon against the stormy night."
  echo "Run $i complete. Pausing for $pause_duration seconds..."
  sleep $pause_duration 
done
