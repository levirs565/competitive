import random
import matplotlib.pyplot as mp
import networkx as nx
import subprocess

tries = 1
while True:
    N = random.randint(1, 100)
    T = nx.random_labeled_tree(N, seed=random.seed(1024))
    t = random.randint(1, N * 100)
    K = random.randint(0, N);
    args = "{} {} {}".format(N, K, t)
    
    k = random.sample(range(1, N), K)
    args += "\n"
    args += " ".join(map(str, k))

    for (u, v, d) in T.edges(data=True):
        d['weight'] = random.randint(1, 100)
        args += "\n" + "{} {} {}".format(u + 1, v + 1, d['weight'])

    expected = subprocess.run("./A_Mencari_Bom", input=args, capture_output=True, text=True).stdout
    actual = subprocess.run("./A_Mencari_Bom_2", input=args, capture_output=True, text=True).stdout
    if expected != actual:
        print("Error. Tries {} Input: ".format(tries))
        print(args)
        print("Expected")
        print(expected)
        print("Actual")
        print(actual)
        break
    else: print("Tries {}".format(tries))
    tries += 1