readarray fileDat < $1
quantum=${fileDat[${#fileDat[@
unset fileDat[${#fileDat[@]}-1]
processCount=${#fileDat[@]}
if [ $quantum -lt 3 ] || [ $quantum -gt 10 ] ; then
echo "ERROR: Quantum must be between 3 to 10"
exit
fi
function printProcess {
process=(${fileDat[$1]})
if [ -z $process ] ; then
return
fi
processName=${process[0]}
arrival=${process[1]}
burst=${process[2]}priority=${process[3]}
echo Process Name: $processName
echo Arrival Time: $arrival
echo Burst Time: $burst
echo Priority: $priority
echo
}
count=0
let end=processCount-1
until [ $count -gt $end ]; do
printProcess $count
let count=count+1
done
echo Quantum: $quantum
echo
echo "~~~ Shortest Job First (SJF) Scheduling ~~~"
echo
sjfDat=("${fileDat[@]}")
shortestBurstIdx=0
currentTime=0
totalTurnaroundTime=0
waitingTime=0
echo "Grantt Chart: "
echo -n $currentTime' '
while [ ${#sjfDat[@]} -gt 0 ] ; do
shortestBurst=99999
count=0
until [ $count -gt $processCount ]; do
process=(${sjfDat[$count]})
if [ -z $process ] ; then
let count=count+1
continue
fi
burst=${process[2]}
if [ $burst -lt $shortestBurst ]; then
shortestBurst=$burst

shortestBurstIdx=$count
filet count=count+1
done
chosenProcess=(${sjfDat[$
processName=${chosenProcess[0]
arrival=${process[1]}
burst=${chosenProcess[2]}
let currentTime=currentTime+burst
echo -n [$processName] $currentTime' '

let turnaroundTime=currentTime-
let waitingTime=waitingTime+

let totalTurnaroundTime=
unset sjfDat[$shortestBurstIdx]
done
let avgWaitingTime=waitingTime/
let avgTurnAroundTime=
echo "Total Turnaround Time :" $totalTurnaroundTime
echo "Average Turnaround Time :" $avgTurnAroundTime
echo "Total Waiting Time :" $waitingTime
echo "Average Waiting Time :" $avgWaitingTime