# import requests
# import threading

# def request_to_server(number, operation):
#     try:
#         url = f"http://127.0.0.1:5000/operation?number={number}&operation={operation}"
#         response = requests.get(url)
#         data = response.json()

#         if 'error' in data:
#             print(f" Error for {number}: {data['error']}")
#         else:
#             print(f" Number: {data['number']}, Operation: {data['operation']}, Result: {data['result']}")
#     except Exception as e:
#         print(f"Client error: {e}")

# def main():
#     count = int(input("Enter how many clients you want to simulate: "))
#     threads = []

#     for i in range(count):
#         number = int(input(f"Enter number for client {i+1}: "))
#         operation = input(f"Enter operation for client {i+1} (square/cube/double): ").strip().lower()
#         t = threading.Thread(target=request_to_server, args=(number, operation))
#         t.start()
#         threads.append(t)

#     for t in threads:
#         t.join()

#     print("\n All clients finished processing.")

# if __name__ == "__main__":
#     main()

import webbrowser
import requests
import threading

def convert_currency(amount, currency):
    try:
        url = f"http://127.0.0.1:5000/convert?amount={amount}&currency={currency}"
        # Open each request in a browser tab
        webbrowser.open(url)
        response = requests.get(url)
        data = response.json()

        if 'error' in data:
            print(f"❌ Error for {amount} INR: {data['error']}")
        else:
            print(f"✅ {amount} INR = {data['Converted Value']} {data['Converted Currency']}")
    except Exception as e:
        print(f"⚠️ Client error: {e}")

def main():
    n = int(input("Enter number of clients to simulate: "))
    threads = []

    for i in range(n):
        amount = float(input(f"Enter amount in INR for client {i+1}: "))
        currency = input(f"Enter target currency (USD/EUR/GBP) for client {i+1}: ").strip().upper()
        t = threading.Thread(target=convert_currency, args=(amount, currency))
        t.start()
        threads.append(t)

    for t in threads:
        t.join()

    print("\n✅ All clients completed currency conversion requests.")

if __name__ == "__main__":
    main()
