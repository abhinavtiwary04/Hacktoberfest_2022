#Code to implement merge sort

def ms(arr):
    if len(arr)>1:
        mid=len(arr)//2   #finding the mid of the array and dividing it into 2 parts
        l=arr[:mid]
        r=arr[mid:]
        ms(l)
        ms(r)
        i=j=k=0
        while i<len(l) and j<len(r):
            if l[i]<=r[j]:
                arr[k]=l[i]
                i=i+1
            else:
                arr[k]=r[j]
                j=j+1
            k=k+1
        while i<len(l):
            arr[k]=l[i]
            i=i+1
            k=k+1
        while j<len(r):
            arr[k]=r[j]
            j=j+1
            k=k+1

def pl(arr):
    for i in range(len(arr)):
        print(arr[i],end=" ")
    print()


if __name__=="__main__":
    arr=[]
    y=int(input("Enter the number of elements:"))
    if(y!=0):
        print("Enter the numbers:")
    for a in range(0,y):
        b=int(input())
        arr.append(b)


    print("Given array:",end="\n")
    pl(arr)
    ms(arr)
    print("Sorted array:",end="\n")
    pl(arr)
