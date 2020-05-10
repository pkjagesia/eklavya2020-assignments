from tabulate import tabulate
import json
import rlcompleter
import readline
import pprint

def read_points_table():
    with open('docs/_data/scoreboard.json', 'r') as file:
        return sorted(json.load(file), key=lambda x: x["Score"], reverse=True)

def write_points_table(points_table):
    with open('docs/_data/scoreboard.json', 'w') as file:
        json.dump(points_table, file)

def print_table():
    points_table = read_points_table()
    points_list = []
    count = 0

    for i in points_table:
        count += 1
        points_list.append([count, i["TeamName"], i["Assignment1"], i["Assignment2"], i["Assignment3"], i["Assignment4"], i["Score"]])
    
    print(tabulate(points_list, headers=["S.No", "Team Name", "Assignment1", "Assignment2", "Assignment3", "Assignment4", "Score"], tablefmt='fancy_grid', numalign='center'))

def update_score():
    points_table = read_points_table()
    option = int(input("[?] Enter serial number of team whose marks need to be updated: "))

    ass1 = int(input("[*] Assignment 1 score: "))
    ass2 = int(input("[*] Assignment 2 score: "))
    ass3 = int(input("[*] Assignment 3 score: "))
    ass4 = int(input("[*] Assignment 4 score: "))

    points_table[option - 1]["Assignment1"] = ass1
    points_table[option - 1]["Assignment2"] = ass2
    points_table[option - 1]["Assignment3"] = ass3
    points_table[option - 1]["Assignment4"] = ass4
    points_table[option - 1]["Score"] = ass1 + ass2 + ass3 + ass4

    team = points_table[option - 1]
    print(tabulate([[team["TeamName"], team["Assignment1"], team["Assignment2"], team["Assignment3"], team["Assignment4"], team["Score"]]], headers=["Team Name", "Assignment1", "Assignment2", "Assignment3", "Assignment4", "Score"], tablefmt='fancy_grid', numalign='center'))
    
    write_points_table(points_table)

if __name__ == "__main__":
    print_table()
    update_score()