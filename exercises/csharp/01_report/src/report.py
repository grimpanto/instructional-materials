# @copyright 2018 Günter Kolousek

#!/usr/bin/python3

import sys
import csv


def convert_umlauts(s):
    for umlaut, converted in [("ä", "ae"), ("ö", "oe"), ("ü", "ue"),
                              ("Ä", "Ae"), ("ö", "Oe"), ("ü", "Ue"),
                              ("ß", "ss")]:
        s = s.replace(umlaut, converted)
    return s


class Sale:
    def __init__(self, product, salesclerk, price, quantity, month):
        self.product = product
        self.salesclerk = salesclerk
        self.price = int(price)
        self.quantity = int(quantity)
        self.month = int(month)


    def tocsv(self):
        return self.product, self.salesclerk, self.price,\
               self.quantity, self.month

    def __str__(self):
        return "Sale({}, {}, {}, {}, {})".format(
            convert_umlauts(self.product),
            convert_umlauts(self.salesclerk),
            self.price,
            self.quantity,
            self.month)


def usage(msg=None):
    print("""usage: report [--help|-h|-s] [FILE]
Print a sales statistics report ordered by product and salesclerk.

  --help|-h ... Help and exit!
  -s ... sort it before producing the report
  FILE ... file name or - (stdin). If FILE is missing read from stdin""")
    if msg:
        print()
        print(msg)
    sys.exit(1)


def parse_argv(argv):
    sortit = False
    filename = None
    for i in range(len(argv)):
        if argv[i].startswith("-"):
            if argv[i] in {"-h", "--help"}:
                usage()
            elif argv[i] == "-s":
                sortit = True
            else:
                usage("Unknown option: '" + argv[i] + "'")
        else:
            if i != len(argv) - 1:
                usage("Additional options or parameters past FILE")
            return argv[i], sortit
    else:
        return "-", sortit


def sortkey_product(sale):
    return sale.product


def sortkey_salesclerk(sale):
    return sale.salesclerk


def next_sale(sales_iter):
    try:
        sale = next(sales_iter)
        sale = Sale(*sale) if type(sale) == list else sale
        return sale
    except StopIteration:
        return None


def control_break(sales_iter):
    # Programmvorbereitung
    print("### Umsatzstatistik nach Produkten und Verkäufern ###")
    print("{:20} {:16} {}".format("Produkt", "Verkäufer", "Umsatzsumme"))

    total_sales = 0
    sale = next_sale(sales_iter)
    while sale:
        # Gruppenvorbereitung
        product_sales = 0
        print()
        curr_product = sale.product
        while sale and curr_product == sale.product:
            # Untergruppenvorbereitung
            salesclerk_sales = 0
            curr_salesclerk = sale.salesclerk
            while sale and curr_product == sale.product and\
                    curr_salesclerk == sale.salesclerk:
                # Einzelsatzverarbeitung
                salesclerk_sales += (sale.price * sale.quantity)
                sale = next_sale(sales_iter)
            # Untergruppennachbereitung
            print("{:20} {:16} {:6} *".format(curr_product,
                                          curr_salesclerk,
                                          salesclerk_sales))
            product_sales += salesclerk_sales
        # Gruppennachbereitung
        print("{:20} {:16} {:6} **".format(curr_product, "", product_sales))
        total_sales += product_sales
    # Programmnachbereitung
    print("{:20} {:16} {:6} ***".format("Gesamtumsatz", "", total_sales))


def process_file(f, sortit=False, writeback=False):
    reader = csv.reader(f)
    if sortit:
        sales_list = []

        for record in reader:
            try:
                sales_list.append(Sale(*record))
            except:
                # error creating Sale instance because of wrong
                # number of arguments
                print("Each line must consist of exactly 6 fields")
                sys.exit(1)

        sales_list.sort(key=sortkey_salesclerk)
        sales_list.sort(key=sortkey_product)

        control_break(iter(sales_list))

        if writeback:
            f.seek(0)
            f.truncate()
            writer = csv.writer(f)
            writer.writerows([s.tocsv() for s in sales_list])
    else:
        control_break(reader)


def process(filename, sortit):
    try:
        if filename == "-":
            process_file(sys.stdin, sortit=True)
        else:
            if sortit:
                with open(filename, "r+") as f:
                    process_file(f, sortit=True, writeback=True)
            else:
                with open(filename) as f:
                    process_file(f)
    except Exception as e:
        print(e)
        print("Es ist ein Fehler aufgetreten!")


def main(argv):
    filename, sortit = parse_argv(argv)
    process(filename, sortit)


if __name__ == '__main__':
    main(sys.argv[1:])
