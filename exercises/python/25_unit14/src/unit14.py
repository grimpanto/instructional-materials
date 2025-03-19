# @copyright 2011 Günter Kolousek

def mul(op1, op2):
    res = []
    for n1 in op1:
        res.append([])
        for n2 in op2:
            res[-1].append((n1 * n2))
    return res


def sum_row_col(table):
    sum_rows = []
    sum_cols = [0] * len(table[0])
    for row in table:
        sum_rows.append(sum(row))
        for i_col in range(len(row)):
            sum_cols[i_col] += row[i_col]
    return (sum_rows, sum_cols)
