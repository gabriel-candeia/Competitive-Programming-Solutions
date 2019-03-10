i = [int(x) for x in input().split(':')]
f = [int(x) for x in input().split(':')]

t1 = i[0]*60 + i[1]
f1 = f[0]*60 + f[1]

tempo = (f1-t1)/2
horas = (tempo)//60 
minutos = (tempo)%60

if((minutos+i[1])>=60==0): horas = horas+1 

saida1 = str(int(i[0]+horas))
saida1 = saida1 if(len(saida1)>1) else '0'+ saida1
saida2 = str((int(i[1]+minutos))%60)
saida2 = saida2 if(len(saida2)>1) else '0'+ saida2

print(saida1,':',saida2,sep='') 	
