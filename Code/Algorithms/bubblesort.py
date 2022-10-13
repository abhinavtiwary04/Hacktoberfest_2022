#Code to implement bubble sort

def bs(arr):
    l=len(arr)
    for i in range(l):
        for j in range(0, l-i-1):
            if arr[j]>arr[j+1]:
                arr[j], arr[j+1]=arr[j+1],arr[j]   #Swapping the elements
if __name__=="__main__":
    arr=[]
    y=int(input("Enter the number of elements:"))
    if(y!=0):
        print("Enter the numbers:")
    for a in range(0,y):
        b=int(input())
        arr.append(b)
    bs(arr)
    print("Sorted array:")
    for i in range(len(arr)):
        print("%d" % arr[i], end=" ")
