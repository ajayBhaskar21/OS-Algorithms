
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


def sjfBT(readyQueue, n):
    m = 9999
    for i in range(n):
        if readyQueue[i] != -1:
            if m > BT[i]:
                m = BT[i]
    
    for i in range(n):
        if BT[i] == m:
            readyQueue[i] = -1
            return i


n = 5
PID = [1, 2, 3, 4, 5]
AT = [2, 5, 1, 0, 4]
BT = [6, 2, 8, 3, 4]
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
minIndex = sjfBT(readyQueue, n)
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
    minIndex = sjfBT(readyQueue, n)
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
    
    print(PID[i],"\t",AT[i], "\t", BT[i], "\t", CT[i], "\t", TAT[i], "\t", WT[i])


