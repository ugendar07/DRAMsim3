1) Run each of the benchmark programs and compile it.

2)Update the allcache.cpp file accordingly to allcache_updated.cpp file.

3)Perform make allcache_updated.cpp

4)Generate the traces files for each of the three benchmark programs.(i.e benchmark_traces.txt)

5)Use last_line.c to find the last line in traces.txt. Then take the timestamp of that line and attach that next to -c in below command.

6)Now run this command for simulating trace files on DRAMsim3.

./build/dramsim3main configs/DDR4_8Gb_x8_3200.ini -c (last_line_timestamp) -t (benchmark_tracefile).txt