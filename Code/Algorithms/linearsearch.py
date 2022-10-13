#Code to impement linear search

def ls(arr,l,x):
    for i in range(0,l):
        if(arr[i]==x):
            return i
    return -1


if __name__=="__main__":
    arr=[]
    y=int(input("Enter the number of elements:"))
    if(y!=0):
        print("Enter the numbers:")
    for a in range(0,y):
        b=int(input())
        arr.append(b)


    x=int(input("Enter the number to be searched:"))
    l=len(arr)

    z=ls(arr,l,x)
    if(z==-1):
        print("Number not found in the array")
    else:
        print("Number found at the position", z)
