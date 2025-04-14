import csv
import sys

def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    rows = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)

    # Extract STR list after reading the database
    STR_List = reader.fieldnames[1:]  # Skips the 'name' field

    # Read DNA sequence file into a variable
    with open(sys.argv[2], encoding="utf-8") as f:
        read_data = f.read()

    # Find longest match of each STR in DNA sequence
    DNA_Info = {}
    for STR in STR_List:
        DNA_Info[STR] = longest_match(read_data, STR)

    # Check database for matching profiles
    for person in rows:
        match = True
        for STR in STR_List:
            if person[STR] != str(DNA_Info[STR]):
                match = False
                break
        if match:
            print(person['name'])
            sys.exit(0)

    print("No match")

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run

main()
