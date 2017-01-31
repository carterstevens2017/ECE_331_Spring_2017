#! /usr/bin/octave -qf

data = load("timing.dat");
bytes = data(:,1);
start_time_seconds = data(:,2);
start_time_nseconds = data(:,3);
end_time_seconds = data(:,4);
end_time_nseconds = data(:,5);
start_time = (1000000000.*start_time_seconds).+start_time_nseconds;
end_time = (1000000000.*end_time_seconds)+end_time_nseconds;
times_ns = end_time .- start_time;
times_s = times_ns./1000000000;
Mbytes = bytes./1000000;
speeds = Mbytes./times_s;

semilogx(bytes, speeds, ".r", "linestyle", "-")
title("Speed of Memory Access vs. Buffer Size")
xlabel("Data Size (Bytes)")
ylabel("Memory Speed (MB/s)")
pause()
