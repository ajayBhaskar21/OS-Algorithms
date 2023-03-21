#!/bin/bash

# Read input from user
echo "Enter number of processes:"
read n

echo "Enter burst time for each process:"
for (( i=0; i<n; i++ )); do
    echo "p$((i+1)): "
    read bt[$i]
    p[$i]=$((i+1))
done

# Sort processes by burst time
for (( i=0; i<n; i++ )); do
    pos=$i
    for (( j=i+1; j<n; j++ )); do
        if (( bt[$j] < bt[$pos] )); then
            pos=$j
        fi
    done

    # Swap positions in arrays
    temp=${bt[$i]}
    bt[$i]=${bt[$pos]}
    bt[$pos]=$temp

    temp=${p[$i]}
    p[$i]=${p[$pos]}
    p[$pos]=$temp
done

wt[0]=0
total=0

# Calculate waiting time for each process
for (( i=1; i<n; i++ )); do
    wt[$i]=0
    for (( j=0; j<i; j++ )); do
        wt[$i]=$(( ${wt[$i]} + ${bt[$j]} ))
    done
    total=$(( total + ${wt[$i]} ))
done

avg_wt=$(bc -l <<< "$total / $n")

total=0

# Calculate turnaround time for each process
echo -e "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time"
for (( i=0; i<n; i++ )); do
    tat[$i]=$(( ${bt[$i]} + ${wt[$i]} ))
    total=$(( total + ${tat[$i]} ))
    echo -e "p${p[$i]}\t${bt[$i]}\t\t${wt[$i]}\t\t${tat[$i]}"
done

avg_tat=$(bc -l <<< "$total / $n")

# Print average waiting and turnaround time
echo -e "\nAverage Waiting Time: $avg_wt"
echo -e "Average Turnaround Time: $avg_tat"
