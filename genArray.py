with open("keycode.txt") as f:
    table = f.read().strip().split("\n")
t = ["["+t.split(",", 1)[1]+"]" for t in table]
eval(t[0])
allC = sum([eval(s) for s in t], [])
allC = set(allC)
allC = list(allC)
allC
print(f"static int stat[{len(allC)}] = {{}};")
print("static char * cTable[] = {"+ ",".join([f'"{f}"' for f in allC]) +"};")
