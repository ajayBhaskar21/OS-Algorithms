#!/bin/bash

echo -n "Enter process number: "
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

WaitingTime[0]=0
TurnAroundTime+=(${BurstTime[0]})

TotalWaitingTime=0
TotalTurnAroundTime=${BurstTime[0]}

for i in $(seq 1 1 $((n1-1)))
do
    WaitingTime[$i]=$((${WaitingTime[$((i-1))]} + ${BurstTime[$((i-1))]}))
    TurnAroundTime[$i]=$((${WaitingTime[$i]} + ${BurstTime[$i]}))
    TotalWaitingTime=$(($TotalWaitingTime + ${WaitingTime[$i]}))
    TotalTurnAroundTime=$(($TotalTurnAroundTime + ${TurnAroundTime[$i]}))
done

AvgWaitingTime=$(($TotalWaitingTime / $n1))
AvgTurnAroundTime=$(($TotalTurnAroundTime / $n1))

echo "PROCESS BURSTTIME WAITINGTIME TURNAROUND TIME"
for(( i=0; i<$n1; i++))
do
    echo "p:${i} ${BurstTime[$i]} ${WaitingTime[$i]} ${TurnAroundTime[$i]}"
done

echo Average Waiting Time : $AvgWaitingTime
echo Average Turn Around Time : $AvgTurnAroundTime
