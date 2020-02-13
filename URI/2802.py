n = int(input())
intersection = (n*(n-1)*(n-2)*(n-3))//24 #vertices no grafo
retas = n*(n-1)//2	#arestas no grafo
print(intersection+retas+1) #Vertice-Arestas+Faces=2

#veja isso https://www.youtube.com/watch?v=_gMRRS1wbj4