# @copyright 2011 Günter Kolousek

import time
import math
import sys
import cities as cities_mod


city_name_index = 3


def cities_sort_key(item):
    return item[city_name_index]


def sorted_cities(cities):
    return sorted(cities, key=cities_sort_key)


def linear_search(cities, name):
    for line in cities[1:]:
        if line[3] == name:
            return line


def binary_search(cities, name):
    lower = 0
    upper = len(cities) - 1

    while lower <= upper:
        m = lower + int((upper - lower) / 2)
        curr_name = cities[m][city_name_index]

        if curr_name == name:
            return cities[m]
        elif name > curr_name:
            lower = m + 1
        else:
            upper = m - 1


if __name__ == "__main__":
    cities = cities_mod.get_cities()
    sorted_cities = sorted_cities(cities)
    # t1 = time.time()
    # linear_search(cities, "Neunkirchen")
    # t2 = time.time()
    # binary_search(sorted_cities, "Neunkirchen")
    # t3 = time.time()

    # delta_linear = t2 - t1
    # delta_binary = t3 - t2
    # print("Linear search benötigt: {}s".format(delta_linear))
    # print("Binary search benötigt: {}s\n".format(delta_binary))

    # print("Binary search benötigt nur {}% der Zeit von linear search".format(
    #         delta_binary / delta_linear * 100))
    # print("D.h., binary search ist {}-Mal schneller!".format(
    #         delta_linear / delta_binary))

    if len(sys.argv) >= 3:
        city1 = binary_search(sorted_cities, sys.argv[1])
        if city1:
            city2 = binary_search(sorted_cities, sys.argv[2])
            if city2:
                distance = cities_mod.distance(
                            (float(city1[7]), float(city1[8])),
                            (float(city2[7]), float(city2[8])))
                if (len(sys.argv) > 3):
                    last_city = city2
                    for i in range(3,len(sys.argv)):
                        curr_city = binary_search(sorted_cities, sys.argv[i])
                        if not curr_city:
                            print("Stadt {} wurde leider nicht gefunden!".
                                  format(sys.argv[i]))
                            break
                        distance += cities_mod.distance(
                            (float(last_city[7]), float(last_city[8])),
                            (float(curr_city[7]), float(curr_city[8])))
                        last_city = curr_city
                print("Die Entfernung von {} zu {} beträgt {:.2f}km".format(
                        sys.argv[1],
                        sys.argv[-1],
                        distance))
            else:
                print("Stadt {} wurde leider nicht gefunden!".format(
                        sys.argv[2]))
        else:
            print("Stadt {} wurde leider nicht gefunden!".format(sys.argv[1]))
    else:
        print("usage: python3 unit13.py city1 city2 {city}")
