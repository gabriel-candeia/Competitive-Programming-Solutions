en1 = input().split();
en2 = input().split();

signA = '' if(en1[0][0]!='-') else '-'
signB = '' if(en1[1][0]!='-') else '-'
signC = '' if(en2[0][0]!='-') else '-'
signD = '' if(en2[1][0]!='-') else '-'

a, b = [abs(float(x)) for x in en1]
c, d = [abs(float(x)) for x in en2]

print("A = ",signA,"%f, B = "%a,signB,"%f"%(b),sep='')
print("C = ",signC,"%f, D = "%c,signD,"%f"%(d),sep='')

print("A = ",signA,"%.1f, B = "%a,signB,"%.1f"%(b),sep='')
print("C = ",signC,"%.1f, D = "%c,signD,"%.1f"%(d),sep='')

print("A = ",signA,"%.2f, B = "%a,signB,"%.2f"%(b),sep='')
print("C = ",signC,"%.2f, D = "%c,signD,"%.2f"%(d),sep='')

print("A = ",signA,"%.3f, B = "%a,signB,"%.3f"%(b),sep='')
print("C = ",signC,"%.3f, D = "%c,signD,"%.3f"%(d),sep='')

s1 = ("A = "+signA+"%.3e, B = "%a+signB+"%.3e"%(b)).upper()
s2 = ("C = "+signC+"%.3e, D = "%c+signD+"%.3e"%(d)).upper()
print(s1)
print(s2)

print("A = ",signA,"%d, B = "%int(a),signB,"%d"%int(b),sep='')
print("C = ",signC,"%d, D = "%int(c),signD,"%d"%int(d),sep='')
