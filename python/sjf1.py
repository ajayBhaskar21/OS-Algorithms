
def pushing(readyQueue, AT, PID, st, exe):
    for i in PID:
        if i not in exe and i not in readyQueue:
            if AT[i] < st:
                readyQueue.append(i)
    

def sjf(readyQueue, PID, BT):
    m = 9999
    for i in readyQueue:
        if m > BT[i]:
            m = BT[i]
    for i in readyQueue:
        if m == BT[i]:
            m = i
            readyQueue.remove(i)
            break
    return m


n = 5
PID = [0, 1, 2, 3, 4]
AT = [1, 3, 6, 7 ,9]
BT = [7, 3, 2, 10, 8]

CT = [0] * n

CT[0] = AT[0] + BT[0]
readyQueue = []
st = CT[0]
exe = []
exe.append(0)

for i in range(n - 1):
    pushing(readyQueue, AT, PID, st, exe)
    nExe = sjf(readyQueue, PID, BT)
    CT[nExe] = BT[nExe] + st
    exe.append(nExe)
    st = CT[nExe]

print('CT = ', CT)







