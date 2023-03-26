#!/bin/bash

read -p "Enter the number of processes: " n

declare -a bt
declare -a at
declare -a ct
declare -a tat
declare -a wt
declare -a rem_bt

echo "Enter the burst time and arrival time for each process: "
for ((i=0;i<n;i++)); do
  read -p "Burst time for P$i: " bt[i]
  read -p "Arrival time for P$i: " at[i]
  rem_bt[i]=${bt[i]}
done

read -p "Enter the quantum: " quantum

t=0
while true; do
  done=true
  for ((i=0;i<n;i++)); do
    if ((rem_bt[i] > 0)); then
      done=false
      if ((rem_bt[i] > quantum)); then
        t=$((t + quantum))
        rem_bt[i]=$((rem_bt[i] - quantum))
      else
        t=$((t + rem_bt[i]))
        ct[i]=$t
        rem_bt[i]=0
      fi
    fi
  done
  if $done; then
    break
  fi
done

for ((i=0;i<n;i++)); do
  tat[i]=$((ct[i] - at[i]))
  wt[i]=$((tat[i] - bt[i]))
done

echo "Process   BT   AT   CT   TAT  WT"
for ((i=0;i<n;i++)); do
  echo "P$i        ${bt[i]}   ${at[i]}   ${ct[i]}   ${tat[i]}   ${wt[i]}"
done
