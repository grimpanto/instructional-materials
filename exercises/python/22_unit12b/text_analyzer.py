# @copyright 2011 Günter Kolousek

import copy


def input_sentences():
    print("Bitte geben Sie die zu analysierenden Sätze ein "
          "(CTRL-D bricht ab):")
    print()

    sentences = []
    try:
        while True:
            sentences.append(input("Satz: "))
    except EOFError:
        pass

    return sentences


def split_sentences(lst):
    for i in range(len(lst)):
        lst[i] = lst[i].replace('"', " ")
        lst[i] = lst[i].replace("'", " ")
        lst[i] = lst[i].replace(",", " ")
        lst[i] = lst[i].replace(";", " ")
        lst[i] = lst[i].replace(".", " ")
        lst[i] = lst[i].replace(":", " ")
        lst[i] = lst[i].replace("-", " ")
        lst[i] = lst[i].split()
    return lst


def purge_bad_words(lst):
    for sentence in lst:
        i = 0
        for word in copy.copy(sentence):
            if len(word) < 2 or not word.isalpha():
                del sentence[i]
            else:
                i += 1
    return lst


def analyze_words(lst):
    words = {}
    for sentence in lst:
        for w in sentence:
            w = w.lower()
            if w in words:
                words[w] += 1
            else:
                words[w] = 1
    return words


def analyze_letters(lst):
    letters = {}
    for sentence in lst:
        for w in sentence:
            for l in w:
                l = l.lower()
                if l in letters:
                    letters[l] += 1
                else:
                    letters[l] = 1
    return letters


def purge_analyzed_letters(dic):
    for k in {"ä", "ü", "ö"}:
        if k in dic:
            del dic[k]
    return dic


def sort_key(item):
    return item[1]


def sort_letters(dic):
    return sorted(dic.items(), key=sort_key, reverse=True)
