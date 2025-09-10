def fibonacci_with_limit(params):
    a, b, limit = params[0], params[1], params[2]

    if a > limit:
        return []

    sequence = fibonacci_with_limit([b, a + b, limit])
    sequence.insert(0, a)
    return sequence


def fibonacci_with_steps(params):
    a, b, steps = params[0], params[1], params[2]

    if steps <= 0:
        return []

    sequence = fibonacci_with_steps([b, a + b, steps - 1])
    sequence.insert(0, a)
    return sequence


if __name__ == "__main__":
    with open('input.txt', 'r') as file:
        lines = file.readlines()
        params_limit = list(map(int, lines[0].strip().split()))
        params_steps = list(map(int, lines[1].strip().split()))

    fib_limit = fibonacci_with_limit(params_limit)
    fib_steps = fibonacci_with_steps(params_steps)


    output_data = (f"Послідовність до ліміту:\n"
                    f"{fib_limit}\n\n"
                    f"Послідовність з кроками:\n"
                    f"{fib_steps}\n")

    with open('output.txt', 'w') as file:
        file.write(output_data)