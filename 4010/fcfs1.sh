#!/bin/bash

echo -n "Enter number of processes : "
read n1

BurstTime=()
WaitingTime=()
TurnAroundTime=()

for i in $(seq 1 1 $n1)
do
    echo -n "Enter Burst Time for process $i: "
    read bt
    BurstTime+=($bt)
done

WaitingTime+=(${BurstTime[0]})
TurnAroundTime+=(${BurstTime[0]})

TotalWaitingTime=0
TotalTurnAroundTime=${BurstTime[0]}

for i in $(seq 0 1 $((n1-2)))
do
    WaitingTime+=($((${WaitingTime[$i]} + ${BurstTime[$i]})))
    TurnAroundTime+=($((${WaitingTime[$i+1]} + ${BurstTime[$i+1]})))
    TotalWaitingTime=$(($TotalWaitingTime + ${WaitingTime[$i]}))
    TotalTurnAroundTime=$(($TotalTurnAroundTime + ${TurnAroundTime[$i+1]}))
done

AvgWaitingTime=$(($TotalWaitingTime / $n1))
AvgTurnAroundTime=$(($TotalTurnAroundTime / $n1))

echo "PROCESS BURSTTIME WAITINGTIME TURNAROUND TIME"
for(( i=0; i<$n1; i++))
do
    echo "p:${i+1} ${BurstTime[$i]} ${WaitingTime[$i]} ${TurnAroundTime[$i]}"
done

echo Average Waiting Time : $AvgWaitingTime
echo Average Turn Around Time : $AvgTurnAroundTime
