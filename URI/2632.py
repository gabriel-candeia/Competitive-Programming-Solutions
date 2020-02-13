def dist(x0,y0,x1,y1):
	return ((x1-x0)**2+(y1-y0)**2)**(1/2)

magias = {"fire":[200,20,30,50],"water":[300,10,25,40],"earth":[400,25,55,70],"air":[100,18,38,60]}

n = int(input())

for x in range(n):
	w, h, x0, y0 = [int(x) for x in input().split()]
	magia, nivel, x1, y1 = input().split()
	nivel = int(nivel)
	x1 = int(x1)
	y1 = int(y1)
	raio = magias[magia][nivel]
	if(0<x1-x0<w and 0<y1-y0<h):
		print(magias[magia][0])
	elif((0<x1-x0<w) and ((abs(y1-y0)<=raio) or (abs(y1-y0-h)<=raio))):
		print(magias[magia][0])
	elif((0<y1-y0<h) and ((abs(x1-x0)<=raio) or (abs(x1-x0-w)<=raio))):
		print(magias[magia][0])
	elif(dist(x0,y0,x1,y1)<=raio): #calcular distância aos vértices
		print(magias[magia][0])
	elif(dist(x0+w,y0,x1,y1)<=raio):
		print(magias[magia][0])
	elif(dist(x0,y0+h,x1,y1)<=raio):
		print(magias[magia][0])
	elif(dist(x0+w,y0+h,x1,y1)<=raio):
		print(magias[magia][0])
	else:
		print(0)
		



