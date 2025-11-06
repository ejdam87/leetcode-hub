

def n_greetings(people: list[tuple[int, int]]) -> int:

    # when will person i reach its target
    target_times = []
    for a, b in people:
        target_times.append( b - a )

    n_greets = 0
    # when will other reach it
    for i in range(len(people)):
        for j in range( len(people) ):
            if i == j:
                continue

            ai, bi = people[i]
            aj, bj = people[j]

            # will i get to the j target ?
            if bi < bj:
                continue

            # when will i get to the j ?
            reaching_j = bj - ai

            # if I reach j's target after j, we will greet
            if reaching_j > target_times[j]:
                n_greets += 1

    return n_greets

def int_row():
    return list(map(int, input().split(" ")))

def main():
    n_tests = int(input())

    for _ in range(n_tests):
        size = int(input())
        people = []
        for _ in range(size):
            people.append( int_row() )

        print(n_greetings(people))

if __name__ == "__main__":
    main()
