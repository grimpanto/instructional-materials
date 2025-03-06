# ko

def isoperand(tok):
    try:
        float(tok)
    except:
        return False
    return True


def isoperator(tok):
    return tok in {"+", "-", "*", "/"}


def priority(tok):
    if tok in {"+", "-"}:
        return 1
    elif tok in {"*", "/"}:
        return 2
    else:
        raise ValueError("Not a operator")
    

def shunting_yard(stack, tokens):
    output = []
    for tok in tokens:
        if isoperand(tok):
            # append, damit auch mit Zahlen (nicht nur mit Ziffern)
            output.append(tok) # print
        elif isoperator(tok):
            while stack and stack[-1] != "(" and \
                    priority(stack[-1]) >= priority(tok):
                output += stack.pop()
            stack.append(tok) # push
        elif tok == "(":
            stack.append(tok)
        elif tok == ")":
            while stack[-1] != "(":
                output += stack.pop() # pop und print
            stack.pop() # linke Klammer ignorieren

    while stack:
        output += stack.pop() # pop und print

    return output


stack = []

expr = input("Ausdruck: ")

import re
tokens = re.split("(\d+|\(|\)| )", expr)
# print(tokens)
tokens = [tok for tok in tokens if tok != ""]
# print(tokens)

print(shunting_yard(stack, tokens))
