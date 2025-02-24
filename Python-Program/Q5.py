import pandas as pd

def analyze_data(filename):
    try:
        data = pd.read_csv(filename)
    except FileNotFoundError:
        print("File not found.")
        return

    print("\nFirst 5 rows of data:")
    print(data.head())

    if "Score" not in data.columns:
        print("No 'Score' column found.")
        return

    avg_score = data["Score"].mean
    print("Average Score:", avg_score)

    print("\nFilling missing values with column mean...")
    data.fillna(data.mean, inplace=True)
    print("Updated data preview:")
    print(data.head())

filename = input("Enter CSV filename: ")
analyze_data(filename)