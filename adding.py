
# largest substring...
S = "aldshflasghdfasgfkhgasdfasdgvfyweofyewyrtyefgv"
l,l1=[],[]
s1=""
for i in range(len(S)):
    s1=S[i]

    for j in range(i+1,len(S)):
        if (S[j] not in s1):
            if (S[j]!=S[i]):
                s1+=S[j]
            else:
                break
        else:
            break
    l.append(s1)           
    continue
for i in l:
    l1.append(len(i))
print(max(l1))

    

