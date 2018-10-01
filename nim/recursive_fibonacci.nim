proc fibonacci(n: int): int =
  if n == 0:
    return 1
  else:
    return n * fibonacci(n - 1)

for i in 1..10:
  echo i, " ", fibonacci(i)