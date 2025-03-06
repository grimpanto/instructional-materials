#!/usr/bin/python

class Node:
    def __init__(self, letter, freq):
        self.letter = letter
        self.freq = freq
        self.left = None
        self.right = None

    def __str__(self):
        return "({}, {}, {}, {})".format(self.letter, self.freq,
                                         self.left, self.right)


def print_tree(trees):
    for x in trees:
        print(x)


def huffman(msg):
    length = len(msg)
    unique_letters = set(msg)
    trees = []
    code = {}
    for c in unique_letters:
        trees.append(Node(c, msg.count(c) / length))
        code[c] = ""

    trees.sort(key=lambda x: x.freq)

    while len(trees) > 1:
        # select trees
        selected_trees = trees[:2]

        # combine selected trees to new tree
        if len(selected_trees) >= 2:
            node = Node(selected_trees[0].letter + selected_trees[1].letter,
                        selected_trees[0].freq + selected_trees[1].freq)
            node.right = selected_trees[1]
            for letter in selected_trees[1].letter:
                code[letter] = "1" + code[letter]
        else:
            node = Node(selected_trees[0].letter,
                        selected_trees[0].freq)

        node.left = selected_trees[0]
        for letter in selected_trees[0].letter:
            code[letter] = "0" + code[letter]

        trees.remove(selected_trees[0])
        if len(selected_trees) >= 2:
            trees.remove(selected_trees[1])

        trees.append(node)
        trees.sort(key=lambda x: x.freq)

    return trees, code


if __name__ == "__main__":
    msg = input("Message: ")
    tree, code = huffman(msg)
    print_tree(tree)
    print("code:", code)

    output = ""
    for letter in msg:
        output += code[letter]
    print("coded message:", output)
    print("len of coded message:", len(output))
