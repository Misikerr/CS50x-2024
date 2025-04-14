from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

total_cents = int(change * 100)

quarters = int(total_cents / 25)
total_cents -= quarters * 25

dimes = int(total_cents / 10)
total_cents -= dimes * 10

nickels = int(total_cents / 5)
total_cents -= nickels * 5

pennies = total_cents
total_cents = quarters + dimes + nickels + pennies

print(total_cents)
