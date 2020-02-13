def win(arr):
	for i in arr:
		if(i==4):
			return True
	return False

def choose_card(arr):
	mn = -1
	for i in range(len(arr)):
		if(arr[i]!=0 and (mn==-1 or arr[i]<arr[mn])):
			mn = i
	return mn

dic = {'A':0,'2':1,'3':2,'4':3,'5':4,'6':5,'7':6,'8':7,'9':8,'D':9,'Q':10,'J':11,'K':12}
n, k  = [int(i) for i in input().split()]
k-=1
hands = []
for i in range(n):
	hands+=[[0]*13]
	s = input()
	for j in s:
		hands[i][dic[j]]+=1;
player = k
pass_joker = False
start = True

for i in range(n):
	if(win(hands[i]) and i!=k):
		player = i
		start = False
		break

while(start):
	next_player = (player+1)%n
	if(k==player and pass_joker==True):
		pass_joker = False
		k = next_player
	else:
		pass_joker = True
		card = choose_card(hands[player])
		hands[player][card]-=1
		hands[next_player][card]+=1
	if(win(hands[player]) and k != player):
		break
	player = next_player
print(player+1)
