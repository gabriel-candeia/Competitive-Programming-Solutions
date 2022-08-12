s = input()
a = s[0]
b = s[1]
s = input()
c = s[0]
d = s[1]

if((a=='#' and d=='#' and c=='.' and b=='.') or (a=='.' and d=='.' and c=='#' and b=='#')):
    print("No")
else:
    print("Yes")