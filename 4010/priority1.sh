#!/bin/bash

# Function to swap two variables
swap() {
    local temp=${!1}
    eval "$1=${!2}"
    eval "$2=$temp"
}

# Prompt user to enter number of processes
read -p "Enter Number of Processes: " n

# Declare arrays for burst time, priority and process id
declare -a burst_time
declare -a priority
declare -a process_id

# Prompt user to enter burst time and priority for each process
for (( i=0; i<n; i++ )); do
    read -p "Enter Burst Time and Priority Value for Process $((i+1)): " burst_time[$i] priority[$i]
    process_id[$i]=$((i+1))
done

# Sort processes by priority in descending order
for (( i=0; i<n; i++ )); do
    a=${priority[i]}
    m=$i

    for (( j=i; j<n; j++ )); do
        if (( priority[j] > a )); then
            a=${priority[j]}
            m=$j
        fi
    done

    # Swap processes
    swap "priority[$i]" "priority[$m]"
    swap "burst_time[$i]" "burst_time[$m]"
    swap "process_id[$i]" "process_id[$m]"
done

# T stores the starting time of process
t=0

# Print scheduled process
echo -e "Order of process execution is: \n"
for (( i=0; i<n; i++ )); do
    echo "P${process_id[$i]} is executed from $t to $((t+burst_time[$i]))"
    t=$((t+burst_time[$i]))
done

# Print process id, burst time, wait time and turnaround time
echo -e "\nProcess Id\tBurst Time\tWait Time\tTurnaround Time"
wait_time=0
for (( i=0; i<n; i++ )); do
    echo -e "P${process_id[$i]}\t\t${burst_time[$i]}\t\t$wait_time\t\t$((wait_time+burst_time[$i]))"
    wait_time=$((wait_time+burst_time[$i]))
done
