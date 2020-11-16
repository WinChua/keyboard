size = 8
print(f'''static char* charTable[][{size}] = {{''')
with open("keycode.txt1") as f:
    l = [(k, eval(v)) for k, v in [l.split("=") for l in f.read().strip().split("\n")]]
l = sorted(l, key=lambda x: x[1])
key = {k: v for k, v in [l.split(",", 1) for l in open("keycode.txt").read().strip().split("\n")]}
l = {k:v for k,v in l}
l = {v:k for k, v in l.items()}
for i in range(max(l) + 1):
    context = key.get(l.get(i, -1),"")
    if context == "":
        print("{"+",".join(['"unkown"']*size)+"},")
    else:
        print(f"{{{context}}},")

print('''
}''')
