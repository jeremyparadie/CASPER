import json

def main():
    data = {}
    data["button_list"] = ["Button 1","Button 2","Button 3","Button 4","Button 5","Button 6","Button 7","Button 8","Button 9"]
    data["subject_fields"] = ["Example Field 1", "Example Field 2", "Example Field 3"]
    
    with open('data.txt', 'w') as outfile:
        json.dump(data, outfile)

main()
