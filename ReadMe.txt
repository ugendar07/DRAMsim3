# Benchmarking and DRAMsim3 Simulation
This README provides instructions for compiling and running benchmark programs, updating the `allcache.cpp` file, generating trace files, and simulating the traces using DRAMsim3.

## Prerequisites
Before you begin, make sure you have the following installed:
- A C++ compiler (e.g., `g++` or `clang`)
- Make utility
- DRAMsim3 simulation environment
- Required benchmark programs

## Instructions

### 1. Compile and Run Benchmark Programs

To compile and execute the benchmark programs, follow these steps:

1. Navigate to the directory containing the benchmark programs.
2. Compile each benchmark program using the following command:
    ```bash
    g++ -o benchmark_name benchmark_name.cpp
    ```
    Replace `benchmark_name` with the actual name of the benchmark program file.
3. Execute the compiled program:
    ```bash
    ./benchmark_name
    ```

### 2. Update `allcache.cpp`

You need to update the `allcache.cpp` file according to the `allcache_updated.cpp` file. Follow these steps:

1. Open the `allcache.cpp` file in a text editor.
2. Make changes based on the contents of `allcache_updated.cpp`.
3. Save the changes.

### 3. Compile `allcache_updated.cpp`

Once you have updated the `allcache.cpp` file, compile the `allcache_updated.cpp` file using the Makefile:

1. Run the following command:
    ```bash
    make allcache_updated.cpp
    ```

### 4. Generate Trace Files for Benchmark Programs

To generate the trace files from each benchmark program:

1. Run each benchmark program and redirect the output to a trace file:
    ```bash
    ./benchmark_name > benchmark_tracefile.txt
    ```
    Do this for each benchmark program, ensuring you generate a corresponding trace file, e.g., `benchmark1_trace.txt`, `benchmark2_trace.txt`, etc.

### 5. Find the Last Line of Trace Files

Use the `last_line.c` program to extract the last line of each trace file and retrieve its timestamp.

1. Compile the `last_line.c` program:
    ```bash
    g++ -o last_line last_line.c
    ```
2. Run the program to find the last line of a trace file:
    ```bash
    ./last_line benchmark_tracefile.txt
    ```
    This will print the last line of the trace file. Extract the timestamp from this line for the next step.

### 6. Run DRAMsim3 Simulation

To simulate the trace files using DRAMsim3:

1. Run the following command, replacing `(last_line_timestamp)` with the timestamp obtained from step 5 and `(benchmark_tracefile)` with the corresponding trace file:
    ```bash
    ./build/dramsim3main configs/DDR4_8Gb_x8_3200.ini -c (last_line_timestamp) -t (benchmark_tracefile).txt
    ```

Repeat this command for each benchmark trace file.

## Commands Summary

```bash
# Compile benchmark program
g++ -o benchmark_name benchmark_name.cpp

# Generate trace file
./benchmark_name > benchmark_tracefile.txt

# Compile last_line.c program
g++ -o last_line last_line.c

# Extract the last line of the trace file
./last_line benchmark_tracefile.txt

# Simulate using DRAMsim3
./build/dramsim3main configs/DDR4_8Gb_x8_3200.ini -c (last_line_timestamp) -t (benchmark_tracefile).txt
