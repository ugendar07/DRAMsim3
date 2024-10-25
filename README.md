# Benchmarking and DRAMsim3 Simulation

This guide provides instructions for compiling and running benchmark programs, updating the `allcache.cpp` file, generating trace files, and simulating those traces using DRAMsim3.

## Prerequisites

Ensure that the following software is installed before proceeding:

- A C++ compiler (e.g., `g++` or `clang`)
- `make` utility
- DRAMsim3 simulation environment
- Benchmark programs

## Steps

### 1. Compile and Run Benchmark Programs

To compile and execute the benchmark programs, follow these steps:

1. Navigate to the directory containing the benchmark programs.
2. Compile each benchmark program:
    ```bash
    g++ -o benchmark_name benchmark_name.cpp
    ```
    Replace `benchmark_name` with the name of the benchmark program.
3. Run the compiled program:
    ```bash
    ./benchmark_name
    ```

### 2. Update `allcache.cpp`

1. Open the `allcache.cpp` file in a text editor.
2. Apply the necessary updates by referring to `allcache_updated.cpp`.
3. Save the changes.

### 3. Compile the Updated `allcache.cpp`

Once you've updated `allcache.cpp`, compile it using the provided `Makefile`:

1. Run the following command:
    ```bash
    make allcache_updated.cpp
    ```

### 4. Generate Trace Files

To generate trace files from the benchmark programs:

1. Run the benchmark program and redirect its output to a trace file:
    ```bash
    ./benchmark_name > benchmark_tracefile.txt
    ```
    Ensure that each benchmark program produces a unique trace file, such as `benchmark1_trace.txt`, `benchmark2_trace.txt`, etc.

### 5. Find the Last Line of the Trace Files

You can extract the last line of each trace file, which contains the timestamp, by using the `last_line.c` program.

1. Compile `last_line.c`:
    ```bash
    g++ -o last_line last_line.c
    ```
2. Run the program to print the last line of a trace file:
    ```bash
    ./last_line benchmark_tracefile.txt
    ```
    Make note of the timestamp from the output.

### 6. Run DRAMsim3 Simulations

To simulate the trace files using DRAMsim3:

1. Use the timestamp extracted from Step 5 and the respective trace file:
    ```bash
    ./build/dramsim3main configs/DDR4_8Gb_x8_3200.ini -c (last_line_timestamp) -t (benchmark_tracefile).txt
    ```

Repeat the simulation for each trace file.

## Commands Summary

```bash
# Compile benchmark program
g++ -o benchmark_name benchmark_name.cpp

# Run benchmark and generate trace file
./benchmark_name > benchmark_tracefile.txt

# Compile last_line.c program
g++ -o last_line last_line.c

# Extract the last line of the trace file
./last_line benchmark_tracefile.txt

# Simulate trace file using DRAMsim3
./build/dramsim3main configs/DDR4_8Gb_x8_3200.ini -c (last_line_timestamp) -t (benchmark_tracefile).txt
```


## Contact
For questions or inquiries, please contact [ugendar](mailto:ugendar07@gmail.com) .





