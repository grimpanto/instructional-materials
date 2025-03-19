# -*- coding: utf-8 -*-

# @copyright 2011 Günter Kolousek

"""
author: Günter Kolousek
matnr:  ko
file:   cities.py
desc:   Dieses Modul enthält...
date:   2011-03-01
"""

import csv
import math

def get_cities():
    cities_reader = csv.reader(open('cities.tab'), delimiter='\t')
    return list(cities_reader)


def distance(p1, p2):
    """
    Berechnet die Entfernung des Punktes p1 zum Punkt p2.

    p1 ist ein Tupel mit latitude und longitude
    p2 ist ein Tupel mit latitude und longitude
    """
    return _distance_on_unit_sphere(p1[0], p1[1], *p2) * 6373


# http://www.johndcook.com/python_longitude_latitude.html
def _distance_on_unit_sphere(lat1, long1, lat2, long2):
    # Convert latitude and longitude to
    # spherical coordinates in radians.
    degrees_to_radians = math.pi/180.0

    # phi = 90 - latitude
    phi1 = (90.0 - lat1)*degrees_to_radians
    phi2 = (90.0 - lat2)*degrees_to_radians

    # theta = longitude
    theta1 = long1*degrees_to_radians
    theta2 = long2*degrees_to_radians

    # Compute spherical distance from spherical coordinates.

    # For two locations in spherical coordinates
    # (1, theta, phi) and (1, theta, phi)
    # cosine( arc length ) =
    #    sin phi sin phi' cos(theta-theta') + cos phi cos phi'
    # distance = rho * arc length

    cos = (math.sin(phi1)*math.sin(phi2)*math.cos(theta1 - theta2) +
           math.cos(phi1)*math.cos(phi2))
    arc = math.acos( cos )

    # Remember to multiply arc by the radius of the earth
    # in your favorite set of units to get length.
    return arc


if __name__ == "__main__":
    lst = get_cities_data()
    print("Distanz zwischen Neunkirchen und Wr. Neustadt: {:.2f} km".format(
          distance((47.7166667, 16.0833333), (47.8000000, 16.2500000))))
