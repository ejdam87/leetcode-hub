
def romance_subarray(arr: list[int]) -> bool:
    for i in range(0, len(arr), 2):
        arr[i] *= -1

    seen_sums = set()
    prefix_sum = None

    for val in arr:
        if prefix_sum is None:
            prefix_sum = val
        else:
            prefix_sum += val
            if prefix_sum == 0 or prefix_sum in seen_sums:
                return True

        seen_sums.add(prefix_sum)

    return False


def int_row():
    return list(map(int, input().split(" ")))

def main():
    n_tests = int(input())

    for _ in range(n_tests):
        size = int(input())
        glasses = int_row()
        if romance_subarray(glasses):
            print("yes")
        else:
            print("no")

if __name__ == "__main__":
    main()
