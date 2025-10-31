from prettytable import PrettyTable

def create_table():
    table = PrettyTable()
    table.field_names = ["Iter", "Qab", "Qaj", "Qac", "Qak", "Qbc", "Qcd", "Qkd", "Qjk", "Qji", "Qki", "Qid", "Qhd", "Qih", "Qde", "Qhl", "Qhg", "Qle", "Qlg", "Qef", "Qgf"]
    return table

table = create_table()
r = 4 
Qab = 20; Qaj = 20; Qac = 20; Qak = 20; Qbc = 20; Qcd = 20; Qkd = 10
Qjk = 10; Qji = 10; Qki = 20; Qid = 10; Qhd = 20; Qih = 20
Qde = 20; Qhl = 20; Qhg = 20; Qle = 30; Qlg = 10; Qef = 50; Qgf = 10

Rab = 5; Raj = 3; Rac = 8; Rak = 7; Rbc = 6; Rcd = 8; Rkd = 5
Rjk = 2; Rji = 2; Rki = 5; Rid = 8; Rhd = 4; Rih = 6
Rde = 4; Rhl = 5; Rhg = 8; Rle = 6; Rlg = 5; Ref = 8; Rgf = 4

table.add_row([f"Iter{0}", round(Qab, r), round(Qaj, r), round(Qac, r), round(Qak, r), round(Qbc, r),
               round(Qcd, r), round(Qkd, r), round(Qjk, r), round(Qji, r), round(Qki, r), round(Qid, r),
               round(Qhd, r), round(Qih, r), round(Qde, r), round(Qhl, r), round(Qhg, r),
               round(Qle, r), round(Qlg, r), round(Qef, r), round(Qgf, r)])

loops = [
    (["Qab", "Qbc", "-Qac"], [Rab, Rbc, Rac]),          
    (["Qac", "-Qcd", "-Qkd", "-Qak"], [Rac, Rcd, Rkd, Rak]),
    (["Qak", "-Qjk", "-Qaj"], [Rak, Rjk, Raj]),         
    (["Qjk", "Qki", "-Qji"], [Rjk, Rki, Rji]),            
    (["-Qki", "Qkd", "-Qid"], [Rki, Rkd, Rid]),          
    (["Qid", "Qhd", "-Qih"], [Rid, Rhd, Rih]),            
    (["-Qhd", "-Qde", "Qle", "Qhl"], [Rhd, Rde, Rle, Rhl]),
    (["-Qhl", "Qlg", "Qhg"], [Rhl, Rlg, Rhg]),            
    (["-Qle", "-Qef", "Qgf", "-Qlg"], [Rle, Ref, Rgf, Rlg])
]

branch_flows = {
    "Qab": Qab, "Qaj": Qaj, "Qac": Qac, "Qak": Qak, "Qbc": Qbc, "Qcd": Qcd, "Qkd": Qkd,
    "Qjk": Qjk, "Qji": Qji, "Qki": Qki, "Qid": Qid, "Qhd": Qhd, "Qih": Qih, 
    "Qde": Qde, "Qhl": Qhl, "Qhg": Qhg, "Qle": Qle, "Qlg": Qlg, "Qef": Qef, "Qgf": Qgf
}

n = int(input("Enter the number of iterations: "))
print("\nStarting iterations...\n")

for i in range(n):
    dQ_corrections = {key: 0 for key in branch_flows.keys()}
    for loop, resistances in loops:
        Y1 = 0
        Y2 = 0
        for branch, resistance in zip(loop, resistances):
            direction = 1 if not branch.startswith("-") else -1
            branch_name = branch.replace("-", "")
            flow = branch_flows[branch_name]
            Y1 += resistance * abs(flow) * flow * direction
            Y2 += resistance * abs(flow) * 2
        dQ = Y1 / Y2
        for branch in loop:
            direction = 1 if not branch.startswith("-") else -1
            branch_name = branch.replace("-", "")
            dQ_corrections[branch_name] += dQ * direction
    for branch_name in branch_flows:
        branch_flows[branch_name] -= dQ_corrections[branch_name]
    table.add_row([f"Iter{i+1}"] + [round(branch_flows[name], r) for name in branch_flows])

print("\nFinal Flow Table after", n, "iterations:\n")
print(table)

