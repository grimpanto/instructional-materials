
import sys

if __name__ == "__main__":
    print(sys.argv, len(sys.argv))

    i = 1
    while i < len(sys.argv):
        print(sys.argv[i])
        i += 1
