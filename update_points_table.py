from tabulate import tabulate
import json
import rlcompleter
import readline

def read_points_table():
    with open('docs/_data/scoreboard.json', 'r') as file:
        return json.load(file)

def write_points_table(points_table):
    with open('docs/_data/scoreboard.json', 'w') as file:
        json.dump(points_table, file)

print (tabulate(read_points_table, tablefmt='simple'))