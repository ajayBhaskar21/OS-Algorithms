
def sortBasedonAT(PID, BT, AT, n):

    for i in range(n):
        for j in range(i + 1, n):
            if AT[i] > AT[j]:
                t1 = AT[i]
                AT[i] = AT[j]
                AT[j] = t1

                t1 = BT[i]
                BT[i] = BT[j]
                BT[j] = t1

                t1 = PID[i]
                PID[i] = PID[j]
                PID[j] = t1


def priority(readyQueue, exec, n):
    m = 9999
    for i in range(n):
        if exec[i] == 0 and readyQueue[i] != -1:
            if m > PRIORITY[i]:
                m = PRIORITY[i]
    
    for i in range(n):
        if exec[i] == 0 and PRIORITY[i] == m:
            readyQueue[i] = -1
            return i


n = 7
PID = [1, 2, 3, 4, 5, 6, 7]
PRIORITY = [3, 4, 4, 5, 2, 6, 1]
AT = [0, 1, 3, 4, 5, 6, 10]
BT = [8, 2, 4, 1, 6, 5, 1]

TAT = [0] * n
WT = [0] * n
readyQueue = [-1] * n
sortBasedonAT(PID, BT, AT, n)
end = 0
CT = [0] * n
m = AT[0]
exec = [0] * n

# Completion time for first process
for i in range(n):
    if AT[i] == m and exec[i] == 0:
        readyQueue[i] = AT[i]

minIndex = priority(readyQueue, exec, n)
CT[minIndex] = AT[minIndex] + BT[minIndex]
end = CT[minIndex]
print("readyqueue = ", readyQueue)
print("Ct = ", CT)
exec[minIndex] = 1

# Completion time for remaining processes
for j in range(n-1):
    for i in range(n):
        if AT[i] <= end and exec[i] == 0:
            readyQueue[i] = AT[i]
    print("readyqueue = ", readyQueue)
    minIndex = priority(readyQueue, exec, n)
    CT[minIndex] = end + BT[minIndex]
    end = CT[minIndex]
    print("readyqueue = ", readyQueue)
    print("Ct = ", CT)
    exec[minIndex] = 1

print("\nfinal Ct = ", CT)

for i in range(n):
    TAT[i] = CT[i] - AT[i]
    WT[i] = TAT[i] - BT[i]

print("PID\tAT\tBT\tCT\tTAT\tWT")
for i in range(n):

    print(PID[i], "\t", AT[i], "\t", BT[i],
          "\t", CT[i], "\t", TAT[i], "\t", WT[i])




