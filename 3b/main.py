from functools import reduce
import re

def main():
    with open("input.txt", "r") as file:
        input = file.read()
        filtered = re.findall(r"\bmul\b\([\d)]+[,][\d]+\)|\bdo\(\)|\bdon\'t\(\)", input)

        print(filtered)

        sequence = []
        enabled = True

        for s in filtered:
            if "don't()" in s:
                enabled = False
                continue
            elif "do()" in s:
                enabled = True
                continue

            if enabled:
                sequence.append(s)

        numbers = [re.findall(r"(\d+)", s) for s in sequence]
        
        total = reduce(lambda i, j: i + j, list(map(lambda a: reduce(lambda x, y: int(x) * int(y), a), numbers)))

        print(f"Total: ", total)

if __name__ == "__main__":
    main()