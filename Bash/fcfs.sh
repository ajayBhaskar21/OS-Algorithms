#!/bin/bash

sortBased() {
    local n=$1
    local a=("${!2}")
    local b=("${!3}")
    local c=("${!4}")

    for ((i=0; i<n-1; i++))
    do
        for ((j=i+1; j<n; j++))
        do
            if ((c[i] > c[j]))
            then
                t1=${c[i]}
                c[i]=${c[j]}
                c[j]=$t1
                t1=${a[i]}
                a[i]=${a[j]}
                a[j]=$t1
                t1=${b[i]}
                b[i]=${b[j]}
                b[j]=$t1
            fi
        done
    done
}

read -p "Enter number of processes: " n

for ((i=0; i<n; i++))
do
    read -p "Enter AT for P$((i+1)): " AT[i]
    read -p "Enter BT for P$((i+1)): " BT[i]

    PID[i]=$((i+1))
done

sortBased $n AT[@] BT[@] PID[@]

# Completion time.
st=${AT[0]}
for ((i=0; i<n; i++))
do
    if ((AT[i] > st))
    then
        st=${AT[i]}
    fi
    CT[i]=$((BT[i]+st))
    st=${CT[i]}
done

# Turn Around Time and Waiting Time
for ((i=0; i<n; i++))
do
    TAT[i]=$((CT[i]-AT[i]))
    WT[i]=$((TAT[i]-BT[i]))
done

# Avg TAT, Avg WT.
avgTat=0
avgWt=0
for ((i=0; i<n; i++))
do
    avgTat=$((avgTat+TAT[i]))
    avgWt=$((avgWt+WT[i]))
done
printf "PID\tAT\tBT\tCT\tTAT\tWT\n"
for ((i=0; i<n; i++))
do
    printf "%d\t%d\t%d\t%d\t%d\t%d\n" "${PID[i]}" "${AT[i]}" "${BT[i]}" "${CT[i]}" "${TAT[i]}" "${WT[i]}"
done

np=$(bc -l <<< "$n")
avgTat=$(bc -l <<< "$avgTat/$np")
avgWt=$(bc -l <<< "$avgWt/$np")
printf "%f %f" "$avgTat" "$avgWt"
