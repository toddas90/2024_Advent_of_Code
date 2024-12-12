from functools import reduce
import re

def main():
    with open("input.txt", "r") as file:
        input = file.read()
        filtered = re.findall(r"\bmul\b\([\d)]+[,][\d]+\)", input)

        numbers = [re.findall(r"(\d+)", s) for s in filtered]
        
        total = reduce(lambda i, j: i + j, list(map(lambda a: reduce(lambda x, y: int(x) * int(y), a), numbers)))

        print(f"Total: ", total)

if __name__ == "__main__":
    main()

# if __name__ == "__main__":
#     with open("input.txt", "r") as file:
#         print("Total: ", reduce(lambda i, j: i + j, list(map(lambda a: reduce(lambda x, y: int(x) * int(y), a), [re.findall(r"(\d+)", s) for s in re.findall(r"\bmul\b\([\d)]+[,][\d]+\)", file.read())]))))