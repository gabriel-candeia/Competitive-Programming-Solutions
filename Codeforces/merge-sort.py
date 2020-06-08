
def merge_sort(arr,l,r): #vai ordernar arr[l..r-1]
    if(r-l==1):
        return 0
    med = l + (r-l)//2
    
    na_esquerda = merge_sort(arr,l,med)
    na_direita = merge_sort(arr,med,r)

    dividido = combina(arr,l,med,r)

    return dividido+na_direita+na_esquerda

def combina(arr, l, med, r): #combina os arrays ordenados arr[l ... med-1] e arr[med ... r-1]
    topo1 = 0
    topo2 = 0
    topo3 = l
    inversoes = 0

    left = arr[l:med][::]
    right = arr[med:r][::]

    while(topo1<len(left) and topo2<len(right)):
        if(left[topo1]<=right[topo2]):
            arr[topo3] = left[topo1]
            topo1+=1
            topo3+=1

            inversoes+=topo2
        else:
            arr[topo3] = right[topo2]
            topo2+=1
            topo3+=1

    while(topo1<len(left)):
        inversoes+=topo2

        arr[topo3] = left[topo1]
        topo1+=1
        topo3+=1

    while(topo2<len(right)):
        arr[topo3] = right[topo2]
        topo2+=1
        topo3+=1
    return inversoes

arr = [1]
res = merge_sort(arr,0,len(arr))
print(res)

#o problema da contagem de inversões, (counting inversions)